

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

void updateSensorData(void)
{
    for (int i = 0; i < NUM_SENSORS-1; i++)
    {
        sensorData[i] = ADC1_ConversionResultGet(channels[i]);
    }
}

void printSensorData(void)
{
    for (int i = 0; i < NUM_SENSORS-1; i++)
    {
        printf("Sensor %d: %u\r\n", i, sensorData[i]);
    }
}