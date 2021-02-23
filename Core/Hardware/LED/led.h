/*
 * led.h
 *
 *  Created on: 2021年2月1日
 *      Author: 孙禹铭
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

#define LED_CODE_MODE 1

#if LED_CODE_MODE==0
//库函数版
#define LED1_ON HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
#define LED1_OFF HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
#define LED1_TOGGLE HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);

#define LED2_ON HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
#define LED2_OFF HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
#define LED2_TOGGLE HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
#elif LED_CODE_MODE==1
//寄存器版
//GPIOF->BSRR 对低16位赋1为GPIO输出1 对高16位赋1为GPIO输出0
#define LED1_ON LED_1_GPIO_Port->BSRR=LED_1_Pin<<16
#define LED1_OFF LED_1_GPIO_Port->BSRR=LED_1_Pin
#define LED1_TOGGLE LED_1_GPIO_Port->ODR^=LED_1_Pin

#define LED2_ON LED_2_GPIO_Port->BSRR=LED_2_Pin<<16
#define LED2_OFF LED_2_GPIO_Port->BSRR=LED_2_Pin
#define LED2_TOGGLE LED_2_GPIO_Port->ODR^=LED_2_Pin

#endif

#endif /* INC_LED_H_ */
