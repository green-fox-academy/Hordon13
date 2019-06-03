#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef uart_handle;

void init_uart (void)
{
  __HAL_RCC_USART1_CLK_ENABLE();

  uart_handle.Instance = USART1;
  uart_handle.Init.BaudRate = 115200;
  uart_handle.Init.Mode = UART_MODE_TX_RX;
  uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uart_handle.Init.Parity = UART_PARITY_NONE;
  uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart_handle.Init.StopBits = UART_STOPBITS_1;

  BSP_COM_Init(COM1, &uart_handle);
}

int main (void)
{
  HAL_Init();
  init_uart();
  BSP_LED_Init(LED1);

  char command[3];
  uint8_t red;
  uint8_t green;
  uint8_t blue;

  while (1) {
    //HAL_UART_Receive(&uart_handle, (uint8_t *) command, 3, HAL_MAX_DELAY);
    HAL_UART_Transmit(&uart_handle, "RGB Confiq...", 13, HAL_MAX_DELAY);
    HAL_Delay(500);
  }
}
