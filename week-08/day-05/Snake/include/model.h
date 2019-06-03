#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include "stm32f7xx.h"
#include "control.h"

typedef struct {
  uint8_t length;
  direction dir;
  uint8_t posX;
  uint8_t posY;
} snake_t;

snake_t snake;

void init_model();

#endif
