#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"


/* =========================================================
 * Exercise 1
 *
 * RED    -> PA5
 * YELLOW -> PA6
 *
 * Active-Low:
 * LOW  -> LED ON
 * HIGH -> LED OFF
 * ========================================================= */

#define LED_RED_Pin        GPIO_PIN_5
#define LED_RED_GPIO_Port  GPIOA

#define LED_YELLOW_Pin        GPIO_PIN_6
#define LED_YELLOW_GPIO_Port  GPIOA


void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */