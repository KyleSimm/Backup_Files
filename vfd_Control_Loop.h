/*
 * File:   vfd_control_loop.h
 * Author: Kyle Simmons
 *
 * Created on October 16, 2025, 8:41 PM
 */

#ifndef VFD_CONTROL_LOOP_H
#define	VFD_CONTROL_LOOP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/pwm_hs/pwm.h"
#include "pwm_driver.h"     // must come BEFORE pwm_control functions
#include "pwm_Lookup.h"
#include <stdint.h>
#include <math.h>
#include "system_mode.h"
// Test pin macros
#define TEST_PIN_LAT LATDbits.LATD7
#define TEST_PIN_TRIS TRISDbits.TRISD7
    

// Initialize VFD control
void vfd_Init(void);

// Update the PWM step size for each phase according to new frequency
void vfd_SetFrequency(float freq);

// Set direction (FORWARD/REVERSE)
void vfd_SetDirection(Direction direct);
void vfd_setDutyCycle(float percent);

void MyPWMInterrupt(enum PWM_GENERATOR genNum);



#ifdef	__cplusplus
}
#endif

#endif	/* VFD_CONTROL_LOOP_H */

