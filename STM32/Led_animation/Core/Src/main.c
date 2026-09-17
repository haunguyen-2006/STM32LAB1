#include "main.h"


/* =========================================================
 * Function prototypes
 * ========================================================= */

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void display7SEG(int num);


/* =========================================================
 * Exercise 4
 *
 * Display number 0 -> 9 on 7-segment
 *
 * Common Anode:
 * LOW  = segment ON
 * HIGH = segment OFF
 * ========================================================= */

void display7SEG(int num)
{
    /* Turn OFF all segments first */
    HAL_GPIO_WritePin(GPIOB,
                      GPIO_PIN_0 |
                      GPIO_PIN_1 |
                      GPIO_PIN_2 |
                      GPIO_PIN_3 |
                      GPIO_PIN_4 |
                      GPIO_PIN_5 |
                      GPIO_PIN_6,
                      GPIO_PIN_SET);


    switch (num)
    {
        /* =================================================
         * 0
         *
         * a b c d e f = ON
         * g             = OFF
         * ================================================= */
        case 0:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 1
         *
         * b c = ON
         * ================================================= */
        case 1:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_1 |
                              GPIO_PIN_2,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 2
         *
         * a b d e g = ON
         * ================================================= */
        case 2:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 3
         *
         * a b c d g = ON
         * ================================================= */
        case 3:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 4
         *
         * b c f g = ON
         * ================================================= */
        case 4:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 5
         *
         * a c d f g = ON
         * ================================================= */
        case 5:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 6
         *
         * a c d e f g = ON
         * ================================================= */
        case 6:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 7
         *
         * a b c = ON
         * ================================================= */
        case 7:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 8
         *
         * a b c d e f g = ON
         * ================================================= */
        case 8:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        /* =================================================
         * 9
         *
         * a b c d f g = ON
         * e             = OFF
         * ================================================= */
        case 9:

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_RESET);

            break;


        default:

            /* Invalid number -> all segments OFF */

            HAL_GPIO_WritePin(GPIOB,
                              GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6,
                              GPIO_PIN_SET);

            break;
    }
}


/* =========================================================
 * MAIN
 * ========================================================= */

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();


    /* =====================================================
     * Exercise 4
     *
     * Display:
     *
     * 0 -> 1 -> 2 -> ... -> 9 -> 0 -> ...
     *
     * One number per second
     * ===================================================== */

    int counter = 0;

    while (1)
    {
        /* Display current number */
        display7SEG(counter);

        /* Wait 1 second */
        HAL_Delay(1000);

        /* Next number */
        counter++;

        /* After 9 -> return to 0 */
        if (counter >= 10)
        {
            counter = 0;
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


    /* Enable GPIOB clock */
    __HAL_RCC_GPIOB_CLK_ENABLE();


    /* =====================================================
     * Turn OFF all 7 segments initially
     *
     * Common Anode:
     * HIGH = OFF
     * ===================================================== */

    HAL_GPIO_WritePin(GPIOB,
                      GPIO_PIN_0 |
                      GPIO_PIN_1 |
                      GPIO_PIN_2 |
                      GPIO_PIN_3 |
                      GPIO_PIN_4 |
                      GPIO_PIN_5 |
                      GPIO_PIN_6,
                      GPIO_PIN_SET);


    /* =====================================================
     * Configure PB0 -> PB6 as output
     * ===================================================== */

    GPIO_InitStruct.Pin =
                      GPIO_PIN_0 |
                      GPIO_PIN_1 |
                      GPIO_PIN_2 |
                      GPIO_PIN_3 |
                      GPIO_PIN_4 |
                      GPIO_PIN_5 |
                      GPIO_PIN_6;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;


    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
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
