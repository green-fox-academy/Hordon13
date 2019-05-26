#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

RNG_HandleTypeDef random_number;

volatile uint32_t start;
volatile uint32_t reaction;

void user_button_init() {
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef button_config;

  button_config.Pin = GPIO_PIN_4;
  button_config.Mode = GPIO_MODE_IT_RISING;
  button_config.Pull = GPIO_NOPULL;
  button_config.Speed = GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOB, &button_config);

  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
  HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);
}

void leds_init() {

  __HAL_RCC_GPIOF_CLK_ENABLE();

  GPIO_InitTypeDef led_config;

  led_config.Pin = GPIO_PIN_10 | GPIO_PIN_9;
  led_config.Mode = GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP;
  led_config.Pull = GPIO_NOPULL | GPIO_NOPULL;
  led_config.Speed = GPIO_SPEED_FAST | GPIO_SPEED_FAST;

  HAL_GPIO_Init(GPIOF, &led_config);
}

void random_init() {
  __HAL_RCC_RNG_CLK_ENABLE();

  random_number.Instance = RNG;
  HAL_RNG_Init(&random_number);
}

void LCD_init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(LCD_COLOR_BLACK);

  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
}

int main(void) {
  HAL_Init();
  SystemClock_Config();
  LCD_init();
  user_button_init();
  leds_init();
  random_init();

  uint32_t delay = (HAL_RNG_GetRandomNumber(&random_number) % 10000);

  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
  HAL_Delay(3000);
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);

  while (1) {
    HAL_Delay(delay);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    start = HAL_GetTick();
    HAL_Delay(1500);
    char score[50];
    sprintf(score, "Your reaction time is: %u ms", reaction);
    BSP_LCD_DisplayStringAt(20, 125, (uint8_t *) score, CENTER_MODE);
  }
}

void EXTI4_IRQHandler(void) { HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4); }

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  reaction = HAL_GetTick() - start;
}

static void Error_Handler(void) {}

static void SystemClock_Config(void) {
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
