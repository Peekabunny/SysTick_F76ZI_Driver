#include "gpio.h"

#define GPIOBEN (1U << 1)

// bit set and bit reset at pin 0 for led
#define LED_BS0 (1U << 0) //Bit set pin 0
#define LED_BR0 (1U << 16)//Bit reset pin 0

#define LED_PIN (1U << 0)

void led_init(void)
{
    /*Enable clock access to GPIOB*/
    RCC->AHB1ENR |= GPIOBEN;
    /*Set PA5 mode to output mode*/
    GPIOB->MODER |= (1U<<0);  //set
    GPIOB->MODER &= ~(1U<<1); // clear
}

void led_on(void)
{
    /*Set PA5 high*/
    GPIOB->BSRR |=LED_BS0;
}
void led_off(void)
{
    /*Set PA5 low*/
    GPIOB->BSRR |=LED_BR0;
}

void led_toggle(void)
{

    GPIOB->ODR ^=LED_PIN;
}
