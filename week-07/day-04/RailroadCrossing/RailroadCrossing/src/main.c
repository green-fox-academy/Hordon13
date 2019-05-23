#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_it.h"

void init_led_pin()
{
  __HAL_RCC_GPIOF_CLK_ENABLE();

  GPIO_InitTypeDef led_config;

  led_config.Pin = GPIO_PIN_10 | GPIO_PIN_9;
  led_config.Mode = GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP;
  led_config.Pull = GPIO_NOPULL | GPIO_NOPULL;
  led_config.Speed = GPIO_SPEED_FAST | GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOF, &led_config);
}

int main(void){

  HAL_Init();
  init_led_pin();

  while (1) {
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
  }
}
