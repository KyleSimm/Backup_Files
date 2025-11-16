/* 
 * File:   spi_client.h
 * Author: School Coding
 *
 * Created on October 28, 2025, 2:23 PM
 */

#ifndef SPI_CLIENT_H
#define	SPI_CLIENT_H

#ifdef	__cplusplus
extern "C" {
#endif
    #include <stdbool.h>
    #include <stdint.h>

    #define SPI_RX_BUFFER_SIZE 5  // 1 command + up to 4 data bytes

    extern volatile bool spiReady;
    extern volatile uint8_t spiRxBuffer[SPI_RX_BUFFER_SIZE];
    extern volatile uint8_t spiRxCount;
    extern volatile uint8_t spiExpected;

    
    uint8_t spi_read(void);
    void spi_write(uint8_t data);
    uint8_t spi_transfer(uint8_t byteData);

    void spi_init();
    void spi_open();
    void spi_close();

    void spi_checkChannel();
    void spi_sendChannel();
    
    void __attribute__((interrupt, no_auto_psv)) _SPI1RXInterrupt(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* SPI_CLIENT_H */

