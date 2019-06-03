#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef UART_handle;

TIM_HandleTypeDef timer_handle;
static void Error_Handler(void);
static void SystemClock_Config(void);

I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef SCL_SDA_confiq;
#define TEMP_SENSOR_ADDR (0b1001000 << 1)
#define	DOT_MATRIX_ADDR (0b1110000 << 1)

void init_matrix()
{
  uint8_t normal_mode = 0x20 | (1 << 0);
  uint8_t output_mode = 0xA0 | (0 << 0);
  uint8_t blinking_off = 0x80 | (1 << 0);

  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &normal_mode, sizeof(normal_mode), HAL_MAX_DELAY);
  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &output_mode, sizeof(normal_mode), HAL_MAX_DELAY);
  HAL_I2C_Master_Transmit(&I2C_handle, DOT_MATRIX_ADDR, &blinking_off, sizeof(normal_mode), HAL_MAX_DELAY);
  HAL_Delay(50);
}

void init_uart()
{
  __HAL_RCC_USART1_CLK_ENABLE();

  UART_handle.Instance = USART1;
  UART_handle.Init.BaudRate = 115200;
  UART_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  UART_handle.Init.Mode = UART_MODE_TX_RX;
  UART_handle.Init.Parity = UART_PARITY_NONE;
  UART_handle.Init.StopBits = UART_STOPBITS_1;
  UART_handle.Init.WordLength = UART_WORDLENGTH_8B;

  BSP_COM_Init(COM1, &UART_handle);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

void init_timer(void)
{
  __HAL_RCC_TIM2_CLK_ENABLE();

  timer_handle.Instance = TIM2;
  timer_handle.Init.Prescaler = 10800 -1; // 0.1ms
  timer_handle.Init.Period = 10000 -1 ; // 1s
  timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  HAL_TIM_Base_Init(&timer_handle);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
  HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);

}

void init_temp_sensor()
{
  __HAL_RCC_GPIOB_CLK_ENABLE();

  SCL_SDA_confiq.Pin = GPIO_PIN_8 | GPIO_PIN_9;
  SCL_SDA_confiq.Mode = GPIO_MODE_AF_OD;
  SCL_SDA_confiq.Pull = GPIO_PULLUP;
  SCL_SDA_confiq.Alternate =GPIO_AF4_I2C1;

  HAL_GPIO_Init(GPIOB, &SCL_SDA_confiq);

  __HAL_RCC_I2C1_CLK_ENABLE();

  I2C_handle.Instance = I2C1;
  I2C_handle.Init.Timing = 0x40912732;
  I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

  HAL_I2C_Init(&I2C_handle);
}

int main (void)
{
  HAL_Init();
  SystemClock_Config();
  init_uart();
  init_temp_sensor();
  init_matrix();
  init_timer();
  HAL_TIM_Base_Start_IT(&timer_handle);

  uint8_t temp_reg;
  uint8_t temp_val;

  uint8_t column = 0b11111111;
	uint8_t clear = 0b00001100;

  while (1) {
    HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDR, &temp_reg, sizeof(temp_reg), HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDR, &temp_val, sizeof(temp_val), HAL_MAX_DELAY);
    printf("%d\n", temp_val);
    HAL_Delay(2000);

    HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 0, 1, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 2, 1, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 4, 1, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 6, 1, &column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 8, 1, &column, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 10, 1, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 12, 1, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, DOT_MATRIX_ADDR, 14, 1, &clear, 1, 100);
    HAL_Delay(1000);
  }
}

void TIM2_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2) {
  }
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&UART_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
  if (huart->Instance == USART1) {
    //dosomething
  }
}

int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		HAL_UART_Transmit(&UART_handle, (uint8_t*) &ptr[DataIdx], 1, HAL_MAX_DELAY);
	}
	return len;
}

void Error_Handler(void)
{}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
