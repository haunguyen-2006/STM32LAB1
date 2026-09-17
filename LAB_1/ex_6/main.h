#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"


/* =========================================================
 * Exercise 6
 *
 * 12 LEDs connected from PA4 to PA15
 *
 * LED 0  -> PA4
 * LED 1  -> PA5
 * LED 2  -> PA6
 * LED 3  -> PA7
 * LED 4  -> PA8
 * LED 5  -> PA9
 * LED 6  -> PA10
 * LED 7  -> PA11
 * LED 8  -> PA12
 * LED 9  -> PA13
 * LED 10 -> PA14
 * LED 11 -> PA15
 *
 * Active-Low:
 * LOW  -> ON
 * HIGH -> OFF
 * ========================================================= */

#define LED0_Pin        GPIO_PIN_4
#define LED0_GPIO_Port  GPIOA

#define LED1_Pin        GPIO_PIN_5
#define LED1_GPIO_Port  GPIOA

#define LED2_Pin        GPIO_PIN_6
#define LED2_GPIO_Port  GPIOA

#define LED3_Pin        GPIO_PIN_7
#define LED3_GPIO_Port  GPIOA

#define LED4_Pin        GPIO_PIN_8
#define LED4_GPIO_Port  GPIOA

#define LED5_Pin        GPIO_PIN_9
#define LED5_GPIO_Port  GPIOA

#define LED6_Pin        GPIO_PIN_10
#define LED6_GPIO_Port  GPIOA

#define LED7_Pin        GPIO_PIN_11
#define LED7_GPIO_Port  GPIOA

#define LED8_Pin        GPIO_PIN_12
#define LED8_GPIO_Port  GPIOA

#define LED9_Pin        GPIO_PIN_13
#define LED9_GPIO_Port  GPIOA

#define LED10_Pin       GPIO_PIN_14
#define LED10_GPIO_Port GPIOA

#define LED11_Pin       GPIO_PIN_15
#define LED11_GPIO_Port GPIOA


void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */