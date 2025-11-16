#include <xc.h>
#include "vfd_Control_Loop.h"
#include <stdint.h>
#include <stdio.h>

// {index, stepSize, direction}
#define PHASE_SHIFT ((TABLE_SIZE + 1) / 3)  // rounds 512/3 ? 171

static PWM_State my_pwm_A = { .index = 0 << 8,            .step_size = 0, .direction = FORWARD };
static PWM_State my_pwm_B = { .index = PHASE_SHIFT << 8,  .step_size = 0, .direction = FORWARD };
static PWM_State my_pwm_C = { .index = (2 * PHASE_SHIFT) << 8, .step_size = 0, .direction = FORWARD };


/*
 Initialized PWM Channels.
 */
void vfd_Init(void)
{
    
    //init_sine_table(); 

    //PWM Set to 10 Hz
    float initialFreq = 1.0f;
    vfd_SetFrequency(initialFreq); //Also Sets StepSize
    
    //Set PHase
    PG1PHASE = 0x0;
    PG2PHASE = 0x0;
    PG3PHASE = 0x0;
    printf("after set freq command \n");

    // Register PWM EOC callback
    PWM_GeneratorEOCEventCallbackRegister(MyPWMInterrupt);

    
    // Clear and then enable interrupt last
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;
    __builtin_enable_interrupts();
    
    // Enable PWM
    PG1CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG3CONLbits.ON = 1;
    
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
    
    switch(currentMode){
        case MODE_ON: //Changes Duty Cycle when Turned ON
            PG1DC = pwm_NextVal(&my_pwm_A);
            PG2DC = pwm_NextVal(&my_pwm_B);
            PG3DC = pwm_NextVal(&my_pwm_C);
            PG1STATbits.UPDREQ = 1;
            PG2STATbits.UPDREQ = 1;
            PG3STATbits.UPDREQ = 1;
         
            break;
            
        default:
            //printf("Current State: %s\n", modeToString(currentMode));
            break;
    }
    
        
        IFS4bits.PWM1IF = 0; 
        
}




