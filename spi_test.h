/* 
 * File:   spi_test.h
 * Author: School Coding
 *
 * Created on November 11, 2025, 2:13 PM
 */

#ifndef SPI_TEST_H
#define	SPI_TEST_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <stdint.h>

    void spi_master2_init();
    uint8_t spi_master2_transfer(uint8_t data);
    void spi_master2_writeByte(uint8_t b);
    void spi_master2_writeBytes(uint8_t *buf, uint16_t len);

    // High-level commands
    void spi_master2_sendMode(uint8_t mode);
    void spi_master2_sendFrequency(float freq);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_TEST_H */

