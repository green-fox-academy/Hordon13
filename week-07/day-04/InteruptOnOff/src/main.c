#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_it.h"

void init_user_button(){
  __HAL_RCC_GPIOI_CLK_ENABLE();

  GPIO_InitTypeDef button_config;

  button_config.Pin = GPIO_PIN_11;
  button_config.Mode = GPIO_MODE_IT_RISING;
  button_config.Pull = GPIO_NOPULL;
  button_config.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOI, &button_config);

  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 16, 0);

}

int main(void)
{

  HAL_Init();
  init_user_button();
  BSP_LED_Init(LED1);

  while (1) {
  }
}

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  BSP_LED_Toggle(LED1);
}
