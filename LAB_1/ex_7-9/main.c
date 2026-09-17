#include "main.h"

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);


/* =========================================================
 * Exercise 7
 * Turn OFF all 12 LEDs
 *
 * Active-Low:
 * LOW  -> ON
 * HIGH -> OFF
 * ========================================================= */
void clearAllClock(void)
{
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
}


/* =========================================================
 * Exercise 8
 *
 * num = 0  -> PA4
 * num = 1  -> PA5
 * ...
 * num = 11 -> PA15
 *
 * LOW -> LED ON
 * ========================================================= */
void setNumberOnClock(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            break;

        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
            break;

        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
            break;

        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
            break;

        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
            break;

        case 8:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
            break;

        case 9:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
            break;

        case 10:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET);
            break;

        case 11:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}


/* =========================================================
 * Exercise 9
 *
 * num = 0  -> PA4
 * num = 1  -> PA5
 * ...
 * num = 11 -> PA15
 *
 * HIGH -> LED OFF
 * ========================================================= */
void clearNumberOnClock(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            break;

        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
            break;

        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
            break;

        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
            break;

        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
            break;

        case 8:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
            break;

        case 9:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
            break;

        case 10:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
            break;

        case 11:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
            break;

        default:
            break;
    }
}


/* =========================================================
 * MAIN
 *
 * Test Exercise 7, 8, 9
 *
 * PA4 -> PA5 -> ... -> PA15
 * ========================================================= */
int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();

    int num = 0;

    while (1)
    {
        /* Turn OFF all LEDs */
        clearAllClock();

        /* Turn ON current LED */
        setNumberOnClock(num);

        /* Keep it ON for 1 second */
        HAL_Delay(1000);

        /* Turn OFF current LED */
        clearNumberOnClock(num);

        /* Next LED */
        num++;

        /* After PA15, return to PA4 */
        if (num >= 12)
        {
            num = 0;
        }
    }
}


/* =========================================================
 * System Clock Configuration
 * ========================================================= */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
     * PA13, PA14, PA15 are normally used by JTAG/SWD.
     * We release them so they can be used as GPIO.
     */
    __HAL_RCC_AFIO_CLK_ENABLE();

    __HAL_AFIO_REMAP_SWJ_DISABLE();


    /* Initially turn OFF all LEDs */
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


    /* Configure PA4 -> PA15 as output */
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

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull = GPIO_NOPULL;

    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

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
