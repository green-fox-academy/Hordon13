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

    while (1) {
        int n = 7;
        for (int i = 0; i < 4; ++i) {
            GPIOF->BSRR = (1 << n + i);
            HAL_Delay(100);
            GPIOF->BSRR = (1 << 16 + n + i);
        }
    }
}