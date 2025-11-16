#ifndef PWM_LOOKUP_H
#define PWM_LOOKUP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define TABLE_SIZE 512              // Must be power of 2
#define PWM_MAX    399
#define PWM_FREQ   10000.0f         // ISR frequency

typedef enum { FORWARD = 1, REVERSE = -1 } Direction;

typedef struct {
    uint32_t index;      // Fixed-point index (8-bit fractional)
    uint32_t step_size;  // Step increment per ISR
    Direction direction;
} PWM_State;

extern uint16_t sine_table[TABLE_SIZE];

//void init_sine_table(void);
uint16_t pwm_NextVal(PWM_State *state);
void pwm_UpdateFreq(PWM_State *state, float frequency);

#ifdef __cplusplus
}
#endif

#endif
