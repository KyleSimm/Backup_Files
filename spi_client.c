#include "mcc_generated_files/spi_client/spi1.h"
#include "spi_client.h"
#include <xc.h>
#include <stdio.h>
#include "system_mode.h"
#include "sensor.h"
#include <stdbool.h>


    volatile uint8_t spiTxBuffer[64];
    volatile uint8_t spiTxLength = 0;
    volatile uint8_t spiTxIndex = 0;
    volatile bool spiTxReady = false;

    volatile uint8_t spiRxBuffer[SPI_RX_BUFFER_SIZE];
    volatile uint8_t spiRxCount = 0;
    volatile uint8_t spiExpected = 0;
    volatile bool spiReady = false;
    
    //Reads Single Byte of Data from Buffer
    uint8_t spi_read(void)
    {
        while (1U == SPI1STATLbits.SPIRBE){}

        return SPI1BUFL;
    }
    
    //Write Single Byte of Data to output buffer
    void spi_write(uint8_t data){
        while(1U == SPI1STATLbits.SPITBF){}
    
        SPI1BUFL = data;
    }
    
    uint8_t spi_transfer(uint8_t byteData){
        while(1U == SPI1STATLbits.SPITBF)
        {

        }

        SPI1BUFL = byteData;

        while (1U == SPI1STATLbits.SPIRBE)
        {

        }

        return SPI1BUFL;
    }
    
    void spi_init(){
        //Register Initialization
        SPI1CON1Lbits.SPIEN = 0;

         // Clear buffers and overflow
        SPI1STATLbits.SPIROV = 0;
        volatile uint16_t dummy = SPI1BUFL;
        dummy = dummy;
    
        // SPI configuration registers
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
        
        printf("Spi Initiated \r\n");
        printf("SPI1CON1Lbits.MSTEN=%d, SPI1CON1Lbits.SSEN=%d, SPI1STATLbits.SPITBF=%d\r\n",
       SPI1CON1Lbits.MSTEN, SPI1CON1Lbits.SSEN, SPI1STATLbits.SPITBF);

    }
    
    void spi_open(){
        bool connected;
        //Initializes SPI Client
        connected = SPI1_Open(0);
        
        if(connected == false){
            printf("Error: SPI Connection not Opened");
        }
    }
    
    void spi_close(){
        SPI1_Deinitialize();
        printf("SPI Connection Closed");
    }
    
    
    void spi_checkChannel(){
        // If host sent a byte, read it
        printf("Running function spi_checkChannel() \r\n");
        if(spiReady)
        {
            uint8_t command = spiRxBuffer[0];
            if(command == 0x01) {
                // mode change
                if(spiRxBuffer[1] == 0){
                    currentMode = MODE_OFF;
                } else if(spiRxBuffer[1] == 1){
                    currentMode = MODE_ON;
                }else{
                    printf("Error: Invalid mode value %d\r\n", spiRxBuffer[1]);
                }
            } else if(command == 0x02) {
                // convert 4 bytes to float
                float val;
                uint8_t *p = (uint8_t*)&val;
                p[0] = spiRxBuffer[1]; // LSB
                p[1] = spiRxBuffer[2];
                p[2] = spiRxBuffer[3];
                p[3] = spiRxBuffer[4]; // MSB


                printf("Float received: %f\r\n", val);
                
                if(val < 65 && val>=1){
                    vfd_SetFrequency(val);
                }
            }
        spiReady = false;
            
        }
    }
  

    void __attribute__((interrupt, no_auto_psv)) _SPI1RXInterrupt(void)
{
    uint8_t dummy = SPI1BUFL;  // read received byte (clears SPIRBF)
    uint8_t txByte = 0x00;
    
    if (spiTxReady && spiTxIndex < spiTxLength){
        txByte = spiTxBuffer[spiTxIndex++];
    } else {
        txByte = 0x00; // default if nothing ready
    }

    SPI1BUFL = txByte; // preload next byte for master
    IFS0bits.SPI1RXIF = 0; // clear interrupt flag
}

    
    void spi_sendChannel(void)
{
    printf("Running spi_SendChannel Function\r\n");
    
    updateSensorData();
    printSensorData();
    // Build TX buffer ? this happens even if master is disconnected
    uint8_t index = 0;
    spiTxBuffer[index++] = 0x10; // header
    for (int i = 0; i < NUM_SENSORS; i++)
        {
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
// For debug visibility even without SPI clock
    printf("SPI TX buffer prepared with %u bytes\r\n", spiTxLength);
    for (int i = 0; i < spiTxLength; i++)
        printf("%02X ", spiTxBuffer[i]);
    printf("\r\n");
}


    


