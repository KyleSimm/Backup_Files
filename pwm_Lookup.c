#include <xc.h>
#include "pwm_Lookup.h"
#include <stdint.h>
#include <math.h>

// Example table of frequency ? period values
//Change to 256++ Values
uint16_t sine_table[table_Size];

void init_sine_table(void) {
    for(int i = 0; i < table_Size; i++) {
        sine_table[i] = (uint16_t)((sin(2.0 * M_PI * i / table_Size) + 1.0) * 0.5 * pwm_Max + 0.5);
    }
}


//Duty Size?
#define TABLE_SIZE 256  // Must be a power of two
#define TABLE_MASK (TABLE_SIZE - 1)
#define TABLE_LIMIT (TABLE_SIZE << 8)

uint16_t pwm_NextVal(PWM_State *state)
{
    uint16_t i = (state->index >> 8) & TABLE_MASK;
    uint8_t frac = state->index & 0xFF;

    uint16_t s0 = sine_table[i];
    uint16_t s1 = sine_table[(i + 1) & TABLE_MASK];

    // Linear interpolation
    uint16_t value = s0 + (((uint32_t)(s1 - s0) * frac) >> 8);

    // Direction and wrapping combined
    state->index += (state->direction == FORWARD) ? state->step_size : -state->step_size;

    // Faster wrap using mask (assuming TABLE_LIMIT = TABLE_SIZE << 8)
    state->index &= (TABLE_LIMIT - 1);

    return value;
}




//Frequency
#define PWM_FREQ 16000.0f
void pwm_UpdateFreq(PWM_State *state, float frequency)
{
    // updateRate = how many times per second pwm_nextVal() is called
    state->step_size = frequency * table_Size / PWM_FREQ  ; //Currently 16KHz frequency
}

