#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

typedef enum {
  FREQUENCY,
  BRIGTHNESS,
} settings_t;

settings_t setting = BRIGTHNESS;

uint8_t last_data = 0;
uint8_t freq = 5;
uint8_t state = 0;
uint8_t counter = 0;

static void SystemClock_Config(void);
static void Error_Handler(void);

TIM_HandleTypeDef timerPWM_handle;
TIM_OC_InitTypeDef pwm_config;

GPIO_InitTypeDef adc_gpio_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

TIM_HandleTypeDef timerFREQ_handle;
GPIO_InitTypeDef led_config;
GPIO_InitTypeDef user_button_handle;
UART_HandleTypeDef uart_handle;

void init_uart()
{
  __HAL_RCC_USART1_CLK_ENABLE();

  uart_handle.Instance = USART1;
  uart_handle.Init.BaudRate = 115200;
  uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uart_handle.Init.Mode = UART_MODE_TX_RX;
  uart_handle.Init.Parity = UART_PARITY_NONE;
  uart_handle.Init.StopBits = UART_STOPBITS_1;
  uart_handle.Init.WordLength = UART_WORDLENGTH_8B;

  BSP_COM_Init(COM1, &uart_handle);
}

void init_timerFREQ()
{
  __HAL_RCC_TIM2_CLK_ENABLE();

  timerFREQ_handle.Instance = TIM2;
  timerFREQ_handle.Init.Prescaler = 10800;
  timerFREQ_handle.Init.Period = 1000; //100ms
  timerFREQ_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  timerFREQ_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  HAL_TIM_Base_Init(&timerFREQ_handle);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
  HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);
}

void init_timerPWM()
{
  __HAL_RCC_TIM1_CLK_ENABLE();

  timerPWM_handle.Instance = TIM1;
  timerPWM_handle.Init.Prescaler = 108 - 1;
  timerPWM_handle.Init.Period = 100 -1;
  timerPWM_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  timerPWM_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

  HAL_TIM_PWM_Init(&timerPWM_handle);
}

void init_pwm()
{
  pwm_config.Pulse = 0;
  pwm_config.OCMode = TIM_OCMODE_PWM1;
  pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
  pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

  HAL_TIM_PWM_ConfigChannel(&timerPWM_handle, &pwm_config, TIM_CHANNEL_1);
}

void init_adc()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  adc_gpio_pin.Pin = GPIO_PIN_0;
  adc_gpio_pin.Mode = GPIO_MODE_ANALOG;
  adc_gpio_pin.Pull = GPIO_NOPULL;
  adc_gpio_pin.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOA, &adc_gpio_pin);

  // ––––––––––––––––– //

  /* configuring ADC3, as it is the only ADC wired out to the headers */
  __HAL_RCC_ADC3_CLK_ENABLE();
  adc_handle.Instance = ADC3;
  adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

  /* these 5 settings are closely related */
  adc_handle.Init.ScanConvMode = DISABLE;
  adc_handle.Init.ContinuousConvMode = DISABLE;
  adc_handle.Init.DiscontinuousConvMode = DISABLE;
  adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  adc_handle.Init.NbrOfDiscConversion = 1;

  HAL_ADC_Init(&adc_handle);

  /* configuring a channel belonging to ADC3 */
  adc_channel_config.Channel = ADC_CHANNEL_0;
  adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

  HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void init_led()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  led_config.Pin = GPIO_PIN_8;
  led_config.Mode = GPIO_MODE_AF_PP;
  led_config.Pull = GPIO_NOPULL;
  led_config.Speed = GPIO_SPEED_FAST;
  led_config.Alternate = GPIO_AF1_TIM1;

  HAL_GPIO_Init(GPIOA, &led_config);
}

void init_user_button()
{
  __HAL_RCC_GPIOI_CLK_ENABLE();

  user_button_handle.Pin = GPIO_PIN_11;
  user_button_handle.Mode = GPIO_MODE_IT_RISING;
  user_button_handle.Pull = GPIO_NOPULL;
  user_button_handle.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOI, &user_button_handle);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  init_timerFREQ();
  init_timerPWM();
  init_pwm();
  init_adc();
  init_led();
  init_uart();
  init_user_button();

  BSP_LED_Init(LED1);

  HAL_TIM_Base_Start_IT(&timerFREQ_handle);
  HAL_TIM_PWM_Start(&timerPWM_handle, TIM_CHANNEL_1);

  int adc_val;
  float percent;

  while(1){
    HAL_ADC_Start(&adc_handle);
    if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
      adc_val = HAL_ADC_GetValue(&adc_handle);
      percent = (adc_val / 4095.0) * 100;

      if (setting == BRIGTHNESS && state) {
        __HAL_TIM_SET_COMPARE(&timerPWM_handle, TIM_CHANNEL_1, percent);
      } else if (setting == FREQUENCY && state){
        __HAL_TIM_SET_COMPARE(&timerPWM_handle, TIM_CHANNEL_1, last_data);
        freq = 20 - percent / 5;
      }
    }
  }
}

void TIM2_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&timerFREQ_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2){

    counter++;
    if (counter >= freq){
      counter = 0;
      state = !state;
    }

    if (!state){
      __HAL_TIM_SET_COMPARE(&timerPWM_handle, TIM_CHANNEL_1, 0);
    }
  }
}

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (setting == BRIGTHNESS){
      setting = FREQUENCY;
      last_data = (HAL_ADC_GetValue(&adc_handle) / 4095.0) * 100;
    } else if (setting == FREQUENCY){
      setting = BRIGTHNESS;
    }
}

void Error_Handler(void)
{}

void SystemClock_Config(void)
{
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

int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		HAL_UART_Transmit(&uart_handle, (uint8_t*) &ptr[DataIdx], 1, HAL_MAX_DELAY);
	}
	return len;
}
