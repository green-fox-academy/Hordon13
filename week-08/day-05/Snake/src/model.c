#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"

#include "model.h"

TIM_HandleTypeDef timer;
void init_timer();

void init_model()
{
  snake.length = 4;
  snake.dir = RIGHT;
  snake.posX = 3;
  snake.posY = 3;

  init_timer();
}

void init_timer()
{
  __HAL_RCC_TIM1_CLK_ENABLE();

  timer.Instance = TIM2;
  timer.Init.Prescaler = 10800;
  timer.Init.Period = 10000; //1000ms
  timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  timer.Init.CounterMode = TIM_COUNTERMODE_UP;

  HAL_TIM_Base_Init(&timer);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
  HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);

  HAL_TIM_Base_Start_IT(&timer);
}

void TIM2_IRQHandler (void)
{
  HAL_TIM_IRQHandler(&timer);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2) {
    switch (snake.dir) {
      case UP:
        if (snake.posY == 0)
          snake.posY = 7;
        else
          snake.posY -= 1;
        break;
      case DOWN:
        if (snake.posY == 7)
          snake.posY = 0;
        else
          snake.posY += 1;
        break;
      case RIGHT:
        if (snake.posX == 7)
          snake.posX = 0;
        else
          snake.posX += 1;
        break;
      case LEFT:
        if (snake.posX == 0)
          snake.posX = 7;
        else
          snake.posX -= 1;
        break;
    }
  }
}
