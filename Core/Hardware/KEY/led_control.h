/*
 * led_control.h
 *
 *  Created on: 2021年2月1日
 *      Author: 孙禹铭
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_
#include "main.h"
#include "led.h"

#define WORK_MODE 0

#define KEY_PRESS 0
#define KEY_RELEASE 1

extern uint8_t old_tick;

void KeyControl();
void KeyControlInit();
void IRQKeyControl();


#endif /* INC_LED_CONTROL_H_ */
