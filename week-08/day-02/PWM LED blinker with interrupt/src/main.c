#include "stm32746g_discovery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"

static void SystemClock_Config(void);
volatile int dim = 0;
volatile int direction = 1;

TIM_HandleTypeDef timer2_handle;
TIM_HandleTypeDef timer3_handle;

TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef PA15_LED_config;

void init_LED() {
  __HAL_RCC_GPIOA_CLK_ENABLE();

  PA15_LED_config.Pin = GPIO_PIN_15;
  PA15_LED_config.Mode = GPIO_MODE_AF_PP;
  PA15_LED_config.Pull = GPIO_NOPULL;
  PA15_LED_config.Speed = GPIO_SPEED_HIGH;
  PA15_LED_config.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_timer() {
  __HAL_RCC_TIM3_CLK_ENABLE();

  timer3_handle.Instance = TIM3;
  timer3_handle.Init.Prescaler =
      10800 -
      1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
  timer3_handle.Init.Period = 100 - 1; // 100 x 0.1 ms = 10 ms
  timer3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  timer3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

  HAL_TIM_Base_Init(&timer3_handle);

  /* assign the highest priority to our interrupt line */
  HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);

  /* tell the interrupt handling unit to process our interrupts */
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void init_timerPWM() {
  __HAL_RCC_TIM2_CLK_ENABLE();

  timer2_handle.Instance = TIM2;
  timer2_handle.Init.Prescaler =
      108 -
      1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
  timer2_handle.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
  timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

  /* configuring the timer in PWM mode instead of calling
   * HAL_TIM_Base_Init(&timer2_handle) */
  HAL_TIM_PWM_Init(&timer2_handle);
}

void init_PWM() {
  pwm_config.Pulse = 50;
  pwm_config.OCMode = TIM_OCMODE_PWM1;
  pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
  pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

  HAL_TIM_PWM_ConfigChannel(&timer2_handle, &pwm_config, TIM_CHANNEL_1);
}

int main(void) {
  HAL_Init();
  SystemClock_Config();

  init_LED();
  init_timer();
  init_timerPWM();
  init_PWM();

  HAL_TIM_PWM_Start(&timer2_handle, TIM_CHANNEL_1);
  HAL_TIM_Base_Start_IT(&timer3_handle);

  while (1) {
    __HAL_TIM_SET_COMPARE(&timer2_handle, TIM_CHANNEL_1, dim);
  }
}

void Error_Handler(void) {}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
    Error_Handler();
  }
}

void TIM3_IRQHandler(void) { HAL_TIM_IRQHandler(&timer3_handle); }

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (direction) {
    dim++;
    if (dim == 100)
      direction = 0;
  } else {
    dim--;
    if (dim == 0)
      direction = 1;
  }
}
