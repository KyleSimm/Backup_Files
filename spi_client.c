#include "mcc_generated_files/spi_client/spi1.h"
#include "spi_client.h"
#include <xc.h>
#include <stdio.h>
#include "system_mode.h"
#include "sensor.h"
#include <stdbool.h>

/* --- SPI runtime buffers / flags --- */
volatile uint8_t spiTxBuffer[64];
volatile uint8_t spiTxLength = 0;
volatile uint8_t spiTxIndex = 0;
volatile bool    spiTxReady = false;

volatile uint8_t spiRxBuffer[SPI_RX_BUFFER_SIZE];
volatile uint8_t spiRxCount = 0;
volatile uint8_t spiExpected = 0;   // number of bytes expected for current packet
volatile bool    spiReady = false;  // set true when a full packet received

/* --- Helper primitives (kept as you had them) --- */

// Read single byte from SPI (blocking until data present)
uint8_t spi_read(void)
{
    while (1U == SPI1STATLbits.SPIRBE) { }
    return SPI1BUFL;
}

// Write single byte to SPI output buffer (blocking)
void spi_write(uint8_t data)
{
    while (1U == SPI1STATLbits.SPITBF) { }
    SPI1BUFL = data;
}

// Full-duplex transfer: write a byte and return received byte
uint8_t spi_transfer(uint8_t byteData)
{
    while (1U == SPI1STATLbits.SPITBF) { }
    SPI1BUFL = byteData;

    while (1U == SPI1STATLbits.SPIRBE) { }
    return SPI1BUFL;
}

/* --- Initialization / open / close --- */

void spi_init(void)
{
    // Register Initialization -- disable while configuring
    SPI1CON1Lbits.SPIEN = 0;

    // Clear overflow and read any garbage
    SPI1STATLbits.SPIROV = 0;
    volatile uint16_t dummy = SPI1BUFL;
    (void)dummy;

    // Reset configuration registers (you already did this)
    SPI1BRGL   = 0x0U;
    SPI1CON1H  = 0x0U;
    SPI1CON2L  = 0x0U;
    SPI1URDTL  = 0x0U;
    SPI1URDTH  = 0x0U;

    // Slave mode setup
    SPI1CON1Lbits.MSTEN = 0; // Slave
    SPI1CON1Lbits.SMP   = 0; // Sample in middle
    SPI1CON1Lbits.SSEN  = 1; // Enable SS pin
    SPI1CON1Lbits.CKE   = 1; // Clock edge

    // --- Interrupt setup ---
    IFS0bits.SPI1RXIF = 0;   // Clear RX interrupt flag
    IEC0bits.SPI1RXIE = 1;   // Enable RX interrupt
    IPC2bits.SPI1RXIP = 3;   // Set RX interrupt priority

    // Enable SPI module last
    SPI1CON1Lbits.SPIEN = 1;

    printf("[SLAVE] SPI1 Initiated\r\n");
    printf("[SLAVE] SPI1CON1Lbits.MSTEN=%d, SPI1CON1Lbits.SSEN=%d, SPI1STATLbits.SPITBF=%d\r\n",
           SPI1CON1Lbits.MSTEN, SPI1CON1Lbits.SSEN, SPI1STATLbits.SPITBF);
}

void spi_open(void)
{
    bool connected;
    connected = SPI1_Open(0);

    if (connected == false) {
        printf("[SLAVE] Error: SPI Connection not Opened\r\n");
    } else {
        printf("[SLAVE] SPI1 Opened via PLIB\r\n");
    }
}

void spi_close(void)
{
    SPI1_Deinitialize();
    printf("[SLAVE] SPI Connection Closed\r\n");
}

/* --- High-level channel handlers --- */

/*
 * Check if we have a complete RX packet (spiReady == true).
 * If so, decode it and act immediately.
 *
 * Packet formats:
 *  - Mode change:  [0x01][0x00 or 0x01]   (2 bytes)
 *  - Frequency:    [0x02][f0][f1][f2][f3] (5 bytes)  (float LSB..MSB)
 *
 * After processing, we call spi_sendChannel() to prepare telemetry and print
 * a clear "now sending" message so the UART shows RX->TX.
 */
void spi_checkChannel(void)
{
    if (!spiReady) return;

    // We have a complete packet in spiRxBuffer with length spiExpected
    uint8_t cmd = spiRxBuffer[0];

    if (cmd == 0x01 && spiExpected == 2) {
        uint8_t modeVal = spiRxBuffer[1];
        printf("[SLAVE RX] MODE command received: %u\r\n", modeVal);

        if (modeVal == 0) {
            currentMode = MODE_OFF;
            printf("[SLAVE RX] Applied MODE = OFF\r\n");
        } else if (modeVal == 1) {
            currentMode = MODE_ON;
            printf("[SLAVE RX] Applied MODE = ON\r\n");
        } else {
            printf("[SLAVE RX] Error: invalid MODE value %u\r\n", modeVal);
        }

        // Optionally prepare a short ACK transmit packet (example)
        // Here we just prepare telemetry to be sent immediately
        printf("[SLAVE RX] MODE processed ? preparing telemetry to send now\r\n");
        spi_sendChannel();
    }
    else if (cmd == 0x02 && spiExpected == 5) {
        // convert 4 bytes to float (LSB first)
        float val;
        uint8_t *p = (uint8_t*)&val;
        p[0] = spiRxBuffer[1];
        p[1] = spiRxBuffer[2];
        p[2] = spiRxBuffer[3];
        p[3] = spiRxBuffer[4];

        printf("[SLAVE RX] FREQ command received: %f Hz\r\n", val);

        if (val >= 1.0f && val < 65.0f) {
            vfd_SetFrequency(val);
            printf("[SLAVE RX] Applied frequency: %f Hz\r\n", val);
        } else {
            printf("[SLAVE RX] Ignored out-of-range frequency: %f\r\n", val);
        }

        printf("[SLAVE RX] FREQ processed ? preparing telemetry to send now\r\n");
        spi_sendChannel();
    }
    else {
        // Unknown header ? just print raw bytes for debugging
        printf("[SLAVE RX] Unknown packet header 0x%02X, bytes:", cmd);
        for (uint8_t i = 0; i < spiExpected && i < SPI_RX_BUFFER_SIZE; ++i) {
            printf(" %02X", spiRxBuffer[i]);
        }
        printf("\r\n");
    }

    // Reset receive state for next packet
    spiRxCount = 0;
    spiExpected = 0;
    spiReady = false;
}

/* SPI1 interrupt: assemble incoming bytes into packet and preload TX bytes
 *
 * Protocol handling:
 *  - On first byte (spiRxCount==0) decide expected length:
 *      0x01 => 2 bytes (mode)
 *      0x02 => 5 bytes (float frequency)
 *      otherwise => treat as single-byte command (expected=1)
 *
 *  - When we have received spiExpected bytes, set spiReady=true for main loop to process.
 *
 *  - The ISR always writes a TX byte (from spiTxBuffer if prepared) into SPI1BUFL so the
 *    master will clock out that byte on the next exchange.
 */
void __attribute__((interrupt, no_auto_psv)) _SPI1RXInterrupt(void)
{
    // Read received byte (clears SPIRBF)
    uint8_t rx = SPI1BUFL;

    // Store received byte into RX buffer if space
    if (spiRxCount < SPI_RX_BUFFER_SIZE) {
        spiRxBuffer[spiRxCount++] = rx;

        // If this is the first byte, decide how many bytes we expect
        if (spiRxCount == 1) {
            if (rx == 0x01) {
                spiExpected = 2;
            } else if (rx == 0x02) {
                spiExpected = 5;
            } else {
                // Unknown header -> treat as single byte command for safety
                spiExpected = 1;
            }
        }

        // If we've got all expected bytes, flag ready for the main loop
        if (spiExpected != 0 && spiRxCount >= spiExpected) {
            spiReady = true;
        }
    } else {
        // Buffer overflow ? reset to avoid lockup
        spiRxCount = 0;
        spiExpected = 0;
        spiReady = false;
        printf("[SLAVE RX] Warning: SPI RX buffer overflow - clearing buffer\r\n");
    }

    // Prepare transmit byte for next master clocking: if TX prepared, send next byte.
    uint8_t txByte = 0x00;
    if (spiTxReady && spiTxIndex < spiTxLength) {
        txByte = spiTxBuffer[spiTxIndex++];
    } else {
        txByte = 0x00;
    }

    // Write preload TX byte
    SPI1BUFL = txByte;

    // Clear the RX interrupt flag
    IFS0bits.SPI1RXIF = 0;
}

/* Build and mark the transmit buffer for the next master read.
 * This is the same sequence you used before; I added clearer prints
 * and a hex dump of the TX bytes.
 */
void spi_sendChannel(void)
{
    printf("[SLAVE TX] Running spi_sendChannel()\r\n");

    updateSensorData();
    printSensorData();

    // Build TX buffer
    uint8_t index = 0;
    spiTxBuffer[index++] = 0x10; // header

    for (int i = 0; i < NUM_SENSORS; i++) {
        uint16_t val = sensorData[i] & 0x0FFF;
        uint8_t high = (val >> 8) & 0x0F;
        uint8_t low  = val & 0xFF;
        spiTxBuffer[index++] = high;
        spiTxBuffer[index++] = low;
    }

    spiTxBuffer[index++] = 0xAA; // footer

    spiTxLength = index;
    spiTxIndex = 0;
    spiTxReady = true;

    // Debug prints: length and hex dump
    printf("[SLAVE TX] SPI TX buffer prepared with %u bytes\r\n", (unsigned)spiTxLength);
    printf("[SLAVE TX] Bytes:");
    for (int i = 0; i < spiTxLength; i++) {
        printf(" %02X", spiTxBuffer[i]);
    }
    printf("\r\n");
}
