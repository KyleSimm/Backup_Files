/* 
 * File:   sensor.h
 * Author: School Coding
 *
 * Created on October 28, 2025, 2:23 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "mcc_generated_files/adc/adc1.h"
    
#define NUM_SENSORS 5

extern uint16_t sensorData[NUM_SENSORS];
extern enum ADC_CHANNEL channels[NUM_SENSORS];

void sensor_init(void);

void updateSensorData(void);

void printSensorData(void);



#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

