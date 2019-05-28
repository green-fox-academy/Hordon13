#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "stm32746g_discovery.h"

void SystemClock_Config(void);

GPIO_InitTypeDef led_handle_A;
GPIO_InitTypeDef led_handle_B;

/* the timer's config structure */
TIM_HandleTypeDef timer2_handle;

void init_leds()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  led_handle_A.Pin = GPIO_PIN_8 | GPIO_PIN_15;
  led_handle_A.Mode = GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT_PP;
  led_handle_A.Pull = GPIO_NOPULL | GPIO_NOPULL;
  led_handle_A.Speed = GPIO_SPEED_HIGH | GPIO_SPEED_HIGH;

  led_handle_B.Pin = GPIO_PIN_15;
  led_handle_B.Mode = GPIO_MODE_OUTPUT_PP;
  led_handle_B.Pull = GPIO_NOPULL;
  led_handle_B.Speed = GPIO_SPEED_HIGH;

  HAL_GPIO_Init(GPIOA, &led_handle_A);
  HAL_GPIO_Init(GPIOB, &led_handle_B);

}

void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer2_handle.Instance = TIM2;
    timer2_handle.Init.Prescaler = 54000 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.5 ms
    timer2_handle.Init.Period = 24000 - 1; // 120000 x 0.5 ms = 12 second period
    timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer2_handle);
}

int main(void)
{
    HAL_Init();

    /* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
    SystemClock_Config();

    BSP_LED_Init(LED1);
    init_timer();
    init_leds();

    __HAL_TIM_SET_COUNTER(&timer2_handle, 0);

    /* starting the timers */
    HAL_TIM_Base_Start(&timer2_handle);


    uint32_t timer_value = 0;

    while (1) {
        timer_value = __HAL_TIM_GET_COUNTER(&timer2_handle);

        if (timer_value == 0){
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
        } else if (timer_value == 6000){
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
        } else if (timer_value == 12000){
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
        } else if (timer_value == 18000){
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
        }
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}
