#include <xc.h>
#include "vfd_Control_Loop.h"
#include <stdint.h>
#include <stdio.h>

// {index, stepSize, direction}
static PWM_State my_pwm_A = {0,.08,1};                      // 0   phase shift
static PWM_State my_pwm_B = {table_Size / 3, .08, 1};       // 120 phase shift
static PWM_State my_pwm_C = {2 * table_Size / 3, .08, 1};   // 240 Phase shift

/*
 Initialized PWM Channels.
 */
void vfd_Init(void)
{
    
    init_sine_table(); 

    //PWM Set to 5 Hz
    float initialFreq = 10.0f;
    vfd_SetFrequency(initialFreq); //Also Sets StepSize
    //setPWM_Cycle(1, 1);
    printf("after set freq command \n");

    // Register PWM EOC callback
    //IFS4bits.PWM1IF = 0; 
    PWM_GeneratorEOCEventCallbackRegister(MyPWMInterrupt);

    // Do all setup first
    PG1CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG3CONLbits.ON = 1;

    // Clear and then enable interrupt last
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;
    __builtin_enable_interrupts();
    printf("Leaving vfd_Init() \r\n");
}

/*
 *  Directly Changes the Duty Cycle Percentage when Needed. REF: MODE_OFF
 */
void vfd_setDutyCycle(float percent){
     // Optional: implement later
    setPWM_Cycle(1, percent);
    setPWM_Cycle(2, percent);
    setPWM_Cycle(3, percent);
}

/*
    Directly Changes the output PWM wave frequency. Does not change internal 16 KHz.
 */
void vfd_SetFrequency(float freq){
    pwm_UpdateFreq(&my_pwm_A,freq);
    pwm_UpdateFreq(&my_pwm_B,freq);
    pwm_UpdateFreq(&my_pwm_C,freq);
}

/*
    Changes the Direction of PWM Output
 */
void vfd_SetDirection(Direction direct){
    my_pwm_A.direction = direct;
    my_pwm_B.direction = direct;
    my_pwm_C.direction = direct;
}



/*
 Interrupt Logic for Updating Duty Cycle Every 16 KHz.
 */

void MyPWMInterrupt(enum PWM_GENERATOR genNum)
{   
    IFS4bits.PWM1IF = 0; 

    
    uint16_t dutyA; 
    uint16_t dutyB;
    uint16_t dutyC; 
    
    switch(currentMode){
        IFS4bits.PWM1IF = 0; 
        
        case MODE_ON: //Changes Duty Cycle when Turned ON
            dutyA = pwm_NextVal(&my_pwm_A);
            dutyB = pwm_NextVal(&my_pwm_B);
            dutyC = pwm_NextVal(&my_pwm_C);

            // Update PWM registers
            setPWM_Cycle(1, dutyA);
            setPWM_Cycle(2, dutyB);
            setPWM_Cycle(3, dutyC);
            
            break;
            
        default:
            //printf("Current State: %s\n", modeToString(currentMode));
            break;
    }
    
        
        IFS4bits.PWM1IF = 0; 
        
}




