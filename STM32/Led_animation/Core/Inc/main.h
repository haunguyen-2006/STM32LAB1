#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"


/* =========================================================
 * 7-SEGMENT COMMON ANODE
 *
 * PB0 -> Segment A
 * PB1 -> Segment B
 * PB2 -> Segment C
 * PB3 -> Segment D
 * PB4 -> Segment E
 * PB5 -> Segment F
 * PB6 -> Segment G
 *
 * Common Anode:
 * LOW  -> ON
 * HIGH -> OFF
 * ========================================================= */

#define SEG_A_Pin        GPIO_PIN_0
#define SEG_A_GPIO_Port  GPIOB

#define SEG_B_Pin        GPIO_PIN_1
#define SEG_B_GPIO_Port  GPIOB

#define SEG_C_Pin        GPIO_PIN_2
#define SEG_C_GPIO_Port  GPIOB

#define SEG_D_Pin        GPIO_PIN_3
#define SEG_D_GPIO_Port  GPIOB

#define SEG_E_Pin        GPIO_PIN_4
#define SEG_E_GPIO_Port  GPIOB

#define SEG_F_Pin        GPIO_PIN_5
#define SEG_F_GPIO_Port  GPIOB

#define SEG_G_Pin        GPIO_PIN_6
#define SEG_G_GPIO_Port  GPIOB


void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
