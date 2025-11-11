/* 
 * File:   pwm_lookup.h
 * Author: Kyle Simmons
 *
 * Created on October 16, 2025, 8:40 PM
 */

#ifndef PWM_LOOKUP_H
#define	PWM_LOOKUP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

#define table_Size 512
#define pwm_Max 400

typedef enum { FORWARD = 1, REVERSE = -1 } Direction;

typedef struct {
    uint32_t index;
    uint32_t step_size;
    Direction direction;
} PWM_State;

void init_sine_table(void);
uint16_t pwm_NextVal(PWM_State *state);
void pwm_UpdateFreq(PWM_State *state, float frequency);



#ifdef	__cplusplus
}
#endif

#endif	/* PWM_LOOKUP_H */

