#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"

#include "control.h"
#include "model.h"

char input;

UART_HandleTypeDef control;

void init_control()
{
  __HAL_RCC_USART1_CLK_ENABLE();

  control.Instance = USART1;
  control.Init.BaudRate = 115200;
  control.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  control.Init.Mode = UART_MODE_TX_RX;
  control.Init.Parity = UART_PARITY_NONE;
  control.Init.StopBits = UART_STOPBITS_1;
  control.Init.WordLength = UART_WORDLENGTH_8B;

  BSP_COM_Init(COM1, &control);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);

  // elesiti az interupt fogadast
  HAL_UART_Receive_IT(&control, (uint8_t *) &input, 1);
}

void USART1_IRQHandler (void)
{
  HAL_UART_IRQHandler(&control);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
  if (huart->Instance == USART1) {
    if (input == 'w') {
      snake.dir = UP;
      printf("%s\n", "UP");
    } else if (input == 'a'){
      snake.dir = LEFT;
      printf("%s\n", "LEFT");
    } else if (input == 's'){
      snake.dir = DOWN;
      printf("%s\n", "DOWN");
    } else if (input == 'd'){
      snake.dir = RIGHT;
      printf("%s\n", "RIGHT");
    }

    // ismet elesre teszi az interuptot
    HAL_UART_Receive_IT(&control, (uint8_t *) &input, 1);
  }
}

int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		HAL_UART_Transmit(&control, (uint8_t*) &ptr[DataIdx], 1, HAL_MAX_DELAY);
	}
	return len;
}
