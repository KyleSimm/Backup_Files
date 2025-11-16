

//Tempature Sensor Calculations



//Infeon Chip

//Tempature Monitor using NTC. 
// R25 around 6.8 k Ohms?
// V_ADC = V_REF * RNTC/(TNTC+Rpullup))
//R_pullup = ? On Schematic?

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc1.h"
#include "mcc_generated_files/system/pins.h"

#include "sensor.h"

uint16_t sensorData[NUM_SENSORS] = {0};
enum ADC_CHANNEL channels[NUM_SENSORS] = {curU, CurV, CurW, Temp, ICRIP};

void sensor_init(void){
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC3 = 1;
    
    ANSELBbits.ANSELB2 = 1;
    ANSELBbits.ANSELB3 = 1;
    ANSELCbits.ANSELC1 = 1;
    ANSELCbits.ANSELC2 = 1;
    ANSELCbits.ANSELC3 = 1;

    ADC1_SharedCorePowerEnable();

}

static uint8_t currentSensor = 0;  // Tracks which sensor to convert next
static uint8_t sensorBusy = 0;     // Flag: conversion in progress
/*
     ADC1_ChannelSelect(curU);
    ADC1_SoftwareTriggerEnable();
    while(!ADC1_IsConversionComplete(curU));
    uint16_t val = ADC1_ConversionResultGet(curU);
    double volts = (val * 3.3) / 4095.0;
    printf("CurU = %u\r\n", val);
    printf("Calculated Result: %.3f V\r\n", volts);
 */
void updateSensorData(void)
{
    for (int i = 0; i < NUM_SENSORS; i++)
    {
        // Select the channel and start conversion
        ADC1_ChannelSelect(channels[i]);
        ADC1_SoftwareTriggerEnable();

        // Wait for conversion to complete
        while(!ADC1_IsConversionComplete(channels[i]));

        // Read raw ADC value
        uint16_t raw = ADC1_ConversionResultGet(channels[i]);
        //printf("Raw %d: %u\r\n", raw);
        // Convert to millivolts
        sensorData[i] = (uint16_t)(((uint32_t)raw * 3300) / 4095);
        //printf("Sensor %d: %u\r\n", i, sensorData[i]);

    }
}



void printSensorData(void)
{
    for (int i = 0; i < NUM_SENSORS; i++)
    {
        printf("Sensor %d: %u\r\n", i, sensorData[i]);
    }
}

