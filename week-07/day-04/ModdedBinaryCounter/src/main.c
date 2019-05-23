#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_it.h"

void init_led_pin()
{
  __HAL_RCC_GPIOF_CLK_ENABLE();

  GPIO_InitTypeDef led_config;

  led_config.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
  led_config.Mode = GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP;
  led_config.Pull = GPIO_NOPULL | GPIO_NOPULL | GPIO_NOPULL | GPIO_NOPULL;
  led_config.Speed = GPIO_SPEED_FAST | GPIO_SPEED_FAST | GPIO_SPEED_FAST | GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOF, &led_config);
}

void init_user_button()
{
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef button_config;

  button_config.Pin = GPIO_PIN_4;
  button_config.Mode = GPIO_MODE_INPUT;
  button_config.Pull = GPIO_NOPULL;
  button_config.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOB, &button_config);

}

int main(void){

  HAL_Init();
  init_led_pin();
  init_user_button();

  uint8_t counter = 0x00;

  while (1) {

    if (counter == 0x10) {
      counter = 0x00;
    }

    if (counter & (1 << 0)){
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
    } else {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    }

    if (counter & (1 << 1)){
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    } else {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
    }

    if (counter & (1 << 2)){
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
    } else {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
    }

    if (counter & (1 << 3)){
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
    } else {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
    }

    HAL_Delay(200); 

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 1) {
      counter++;
    }
  }
}
