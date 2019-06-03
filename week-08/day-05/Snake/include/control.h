#ifndef SNAKE_CONTROL_H
#define SNAKE_CONTROL_H

#include "stm32f7xx.h"

typedef enum {
  UP, DOWN, LEFT, RIGHT
} direction;

void init_control();
void USART1_IRQHandler (void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart);
int _write(int file, char *ptr, int len);

#endif
