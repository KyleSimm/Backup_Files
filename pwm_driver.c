#include "pwm_driver.h"
#include <xc.h>
#include <stdint.h>

void setPWM_Cycle(PWM_Channel channel, uint16_t val) {
    switch(channel){
        case my_PWM_1:
            PG1DC = val;
            PG1STATbits.UPDREQ = 1;
            break;
        case my_PWM_2:
            PG2DC = val;
            PG2STATbits.UPDREQ = 1;
            break;
        case my_PWM_3:
            PG3DC = val;
            PG3STATbits.UPDREQ = 1;
            break;
    }
}

void setPWM_Phase(PWM_Channel channel, uint16_t val) {
    switch(channel){
        case my_PWM_1:
            PG1PHASE = val;
            PG1STATbits.UPDREQ = 1;
            break;
        case my_PWM_2:
            PG2PHASE = val;
            PG2STATbits.UPDREQ = 1;
            break;
        case my_PWM_3:
            PG3PHASE = val;
            PG3STATbits.UPDREQ = 1;
            break;
    }
}

