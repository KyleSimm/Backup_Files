
#include "mcc_generated_files/timer/tmr1.h"

volatile uint32_t msTicks = 0;

void TMR1_TimeoutCallback(void)
{
    msTicks++;
}

uint32_t millis(void)
{
    return msTicks;
}
