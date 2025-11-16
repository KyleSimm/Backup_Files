#include "spi_test.h"
#include <xc.h>
#include <string.h>

void spi_master2_init(void)
{
    SPI2CON1Lbits.SPIEN = 0;

    SPI2STATLbits.SPIROV = 0;
(   void)SPI2BUFL;

    SPI2BRGL = 5;

    SPI2CON1Lbits.MSTEN = 1;
    SPI2CON1Lbits.CKE   = 1;
    SPI2CON1Lbits.CKP   = 0;
    SPI2CON1Lbits.SMP   = 1;

    SPI2CON1Lbits.MODE16 = 0;
    SPI2CON1Lbits.MODE32 = 0;

    SPI2CON1Lbits.SPIEN = 1;
}

uint8_t spi_master2_transfer(uint8_t byte)
{
    while (SPI2STATLbits.SPITBF);
    SPI2BUFL = byte;

    while (SPI2STATLbits.SPIRBE);
    return SPI2BUFL;
}

void spi_master2_writeByte(uint8_t b)
{
    spi_master2_transfer(b);
}

void spi_master2_writeBytes(uint8_t *buf, uint16_t len)
{
    for (uint16_t i = 0; i < len; i++)
        spi_master2_transfer(buf[i]);
}

void spi_master2_sendMode(uint8_t mode)
{
    uint8_t packet[2] = { 0x01, mode };
    spi_master2_writeBytes(packet, 2);
}

void spi_master2_sendFrequency(float freq)
{
    uint8_t buf[5];
    buf[0] = 0x02;

    uint8_t *p = (uint8_t *)&freq;
    buf[1] = p[0];
    buf[2] = p[1];
    buf[3] = p[2];
    buf[4] = p[3];

    spi_master2_writeBytes(buf, 5);
}
