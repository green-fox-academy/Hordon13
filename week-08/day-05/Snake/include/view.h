#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "stm32f7xx.h"

#define	DOT_MATRIX_ADDR (0b1110000 << 1)

void init_view();
void draw_matrix();

#endif
