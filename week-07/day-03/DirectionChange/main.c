#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    GPIOF->MODER |= (GPIO_MODER_MODER10_0);
    GPIOF->MODER |= (GPIO_MODER_MODER9_0);
    GPIOF->MODER |= (GPIO_MODER_MODER8_0);
    GPIOF->MODER |= (GPIO_MODER_MODER7_0);
}

int main(void)
{
    HAL_Init();
    init_pins();
    uint32_t user_button = (1 << 4);
    int n = 7;

    int direction = 1;

    while (1) {

        if (GPIOB->IDR & (user_button) && direction == 1) {
            direction = 0;
        } else if (GPIOB->IDR & (user_button) && direction == 0) {
            direction = 1;
        }

        if (direction) {
            if (n == 10) {
                n = 6;
            }
            n++;
        } else {
            if (n == 7) {
                n = 11;
            }
            n--;
        }

        GPIOF->BSRR = (1 << n);
        HAL_Delay(150);
        GPIOF->BSRR = (1 << (16 + n));
    }
}