
#define CTRL_ENABLE   (1U << 0)
#define CTRL_TICKINT  (1U << 1)
#define CTRL_CLKSRC   (1U << 2)
#define CTRL_COUNTFLAG (1U << 16)
#include <stdint.h>
#include "stm32f7xx.h"


#define ONE_MSEC_LOAD 16000  // assuming 16 MHz CPU clock

void systick_msec_delay(uint32_t delay)
{
    SysTick->LOAD = ONE_MSEC_LOAD - 1;
    SysTick->VAL = 0;

    SysTick->CTRL = CTRL_CLKSRC;   // select CPU clock
    SysTick->CTRL |= CTRL_ENABLE;  // enable counter

    for (uint32_t i = 0; i < delay; i++)
    {
        while ((SysTick->CTRL & CTRL_COUNTFLAG) == 0) {}
    }

    SysTick->CTRL = 0; // disable SysTick
}
