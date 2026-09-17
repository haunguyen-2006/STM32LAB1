#include "main.h"


/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);


/* =========================================================
 * MAIN
 *
 * Exercise 6:
 * Test all 12 LEDs one by one.
 *
 * PA4 -> PA5 -> PA6 -> ... -> PA15
 * ========================================================= */
int main(void)
{
    /* Initialize HAL */
    HAL_Init();

    /* Configure system clock */
    SystemClock_Config();

    /* Initialize GPIO */
    MX_GPIO_Init();


    while (1)
    {
        /* =============================================
         * LED 0 - PA4
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);


        /* =============================================
         * LED 1 - PA5
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);


        /* =============================================
         * LED 2 - PA6
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);


        /* =============================================
         * LED 3 - PA7
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);


        /* =============================================
         * LED 4 - PA8
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);


        /* =============================================
         * LED 5 - PA9
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);


        /* =============================================
         * LED 6 - PA10
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);


        /* =============================================
         * LED 7 - PA11
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);


        /* =============================================
         * LED 8 - PA12
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);


        /* =============================================
         * LED 9 - PA13
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);


        /* =============================================
         * LED 10 - PA14
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);


        /* =============================================
         * LED 11 - PA15
         * ============================================= */
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    }
}


/* =========================================================
 * System Clock Configuration
 * ========================================================= */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


    /* HSI = 8 MHz */
    RCC_OscInitStruct.OscillatorType =
        RCC_OSCILLATORTYPE_HSI;

    RCC_OscInitStruct.HSIState =
        RCC_HSI_ON;

    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState =
        RCC_PLL_NONE;


    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }


    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource =
        RCC_SYSCLKSOURCE_HSI;

    RCC_ClkInitStruct.AHBCLKDivider =
        RCC_SYSCLK_DIV1;

    RCC_ClkInitStruct.APB1CLKDivider =
        RCC_HCLK_DIV1;

    RCC_ClkInitStruct.APB2CLKDivider =
        RCC_HCLK_DIV1;


    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct,
                            FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}


/* =========================================================
 * GPIO Initialization
 * ========================================================= */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};


    /* Enable GPIOA clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();


    /*
     * Enable AFIO because PA13, PA14, PA15
     * are related to debug functions.
     */
    __HAL_RCC_AFIO_CLK_ENABLE();


    /*
     * Disable JTAG/SWD function.
     *
     * This allows PA13, PA14 and PA15
     * to be used as normal GPIO.
     */
    __HAL_AFIO_REMAP_SWJ_DISABLE();


    /* =====================================================
     * Initially turn OFF all 12 LEDs
     *
     * Active-Low:
     * HIGH -> OFF
     * ===================================================== */
    HAL_GPIO_WritePin(GPIOA,
                      GPIO_PIN_4  |
                      GPIO_PIN_5  |
                      GPIO_PIN_6  |
                      GPIO_PIN_7  |
                      GPIO_PIN_8  |
                      GPIO_PIN_9  |
                      GPIO_PIN_10 |
                      GPIO_PIN_11 |
                      GPIO_PIN_12 |
                      GPIO_PIN_13 |
                      GPIO_PIN_14 |
                      GPIO_PIN_15,
                      GPIO_PIN_SET);


    /* =====================================================
     * Configure PA4 -> PA15 as Output
     * ===================================================== */
    GPIO_InitStruct.Pin =
                      GPIO_PIN_4  |
                      GPIO_PIN_5  |
                      GPIO_PIN_6  |
                      GPIO_PIN_7  |
                      GPIO_PIN_8  |
                      GPIO_PIN_9  |
                      GPIO_PIN_10 |
                      GPIO_PIN_11 |
                      GPIO_PIN_12 |
                      GPIO_PIN_13 |
                      GPIO_PIN_14 |
                      GPIO_PIN_15;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;


    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}


/* =========================================================
 * Error Handler
 * ========================================================= */
void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}