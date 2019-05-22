#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

    GPIOF->MODER |= (GPIO_MODER_MODER10_0);
    GPIOF->MODER |= (GPIO_MODER_MODER9_0);
    GPIOF->MODER |= (GPIO_MODER_MODER8_0);
    GPIOF->MODER |= (GPIO_MODER_MODER7_0);
}

int main(void)
{
    HAL_Init();
    init_pins();
    int n = 7;
    int direction = 0;

    while (1) {
        GPIOF->BSRR = (1 << n);
        HAL_Delay(150);
        GPIOF->BSRR = (1 << (16 + n));

        if (n == 7) {
            direction = 0;
        } else if (n == 10) {
            direction = 1;
        }

        if (direction) {
            n--;
        } else {
            n++;
        }
    }
}