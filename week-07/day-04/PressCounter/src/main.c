#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_it.h"

volatile int press_count = 0;

void init_user_button()
{
  __HAL_RCC_GPIOI_CLK_ENABLE();

  GPIO_InitTypeDef user_button;

  user_button.Pin = GPIO_PIN_11;
  user_button.Mode = GPIO_MODE_IT_RISING;
  user_button.Pull = GPIO_NOPULL;
  user_button.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOI, &user_button);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 16, 0);
}

int main(void)
{

  HAL_Init();
  init_user_button();
  BSP_LED_Init(LED1);

  while (1) {
    if (press_count >= 5) {
      BSP_LED_On(LED1);
    }
  }
}

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  press_count++;
}
