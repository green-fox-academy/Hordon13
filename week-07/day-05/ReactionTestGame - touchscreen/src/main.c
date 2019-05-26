#include "ft5336.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"

volatile uint32_t startTime;
volatile uint32_t reactionTime;

RNG_HandleTypeDef random;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_LCD() {
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(1);
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetFont(&Font24);
}

void init_Random() {
  __HAL_RCC_RNG_CLK_ENABLE();
  random.Instance = RNG;
  HAL_RNG_Init(&random);
}

int main(void) {
  HAL_Init();
  SystemClock_Config();
  init_LCD();
  init_Random();
  BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
  TS_StateTypeDef touchScreen;

  BSP_LCD_DisplayStringAt(0, 124, "REACTION TEST GAME", CENTER_MODE);
  HAL_Delay(1000);

  touchScreen.touchDetected = 0;
  do {
    BSP_TS_GetState(&touchScreen);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(0, 225, "- hold to start -", CENTER_MODE);
    HAL_Delay(750);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(0, 125, "REACTION TEST GAME", CENTER_MODE);
    HAL_Delay(500);
  } while(!touchScreen.touchDetected);

  BSP_LCD_Clear(LCD_COLOR_BLACK);

  while (1) {
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt(0, 125, "TOUCH THE SCREEN WHEN IT TURNS GREEN", CENTER_MODE);
    HAL_Delay(2000);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    uint32_t delay = HAL_RNG_GetRandomNumber(&random) % 9000;
    HAL_Delay(1000 + delay);
    BSP_LCD_Clear(LCD_COLOR_GREEN);
    startTime = HAL_GetTick();
    touchScreen.touchDetected = 0;
    while(!touchScreen.touchDetected){
      BSP_TS_GetState(&touchScreen);
    }
    reactionTime = HAL_GetTick() - startTime;
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_DisplayStringAt(0, 25, "YOUR REACTION TIME IS:", CENTER_MODE);

    char result[40];
    BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGREEN);
    sprintf(result, "%u ms", reactionTime);
		BSP_LCD_DisplayStringAt(0, 125, (uint8_t *) result, CENTER_MODE);
    HAL_Delay(1000);

    BSP_LCD_SetFont(&Font12);
    BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
    BSP_LCD_DisplayStringAt(0, 225, "- TOUCH TO REPLAY -", CENTER_MODE);
    touchScreen.touchDetected = 0;
    while(!touchScreen.touchDetected){
      BSP_TS_GetState(&touchScreen);
    }
  }
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
