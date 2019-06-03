#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"

#include "view.h"

I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef SCL_SDA_confiq;

void init_view()
{
  __HAL_RCC_GPIOB_CLK_ENABLE();

  SCL_SDA_confiq.Pin = GPIO_PIN_8 | GPIO_PIN_9;
  SCL_SDA_confiq.Mode = GPIO_MODE_AF_OD;
  SCL_SDA_confiq.Pull = GPIO_PULLUP;
  SCL_SDA_confiq.Alternate = GPIO_AF4_I2C1;

  HAL_GPIO_Init(GPIOB, &SCL_SDA_confiq);

  __HAL_RCC_I2C1_CLK_ENABLE();

  uint8_t normal_mode = 0x20 | (1 << 0);
  uint8_t output_mode = 0xA0 | (0 << 0);
  uint8_t blinking_off = 0x80 | (1 << 0);

  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &normal_mode, sizeof(normal_mode), HAL_MAX_DELAY);
  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &output_mode, sizeof(normal_mode), HAL_MAX_DELAY);
  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &blinking_off, sizeof(normal_mode), HAL_MAX_DELAY);

  HAL_Delay(50);
}

void draw_matrix()
{
  uint8_t type1 = 0b11111111;
	uint8_t type2 = 0b00001100;

  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 0, 1, &type2, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 2, 1, &type2, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 4, 1, &type2, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 6, 1, &type1, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 8, 1, &type1, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 10, 1, &type2, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 12, 1, &type2, 1, 100);
  HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 14, 1, &type2, 1, 100);
}
