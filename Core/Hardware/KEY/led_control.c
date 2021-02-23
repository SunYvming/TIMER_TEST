/*
 * led_control.c
 *
 *  Created on: 2021年2月1日
 *      Author: 孙禹铭
 */

#include "led_control.h"
#include "tim.h"

uint8_t old_tick=0;

//---------------------------------------------------------
/*
	函数名称: KeyControlIni
	编辑时间: 2021-2-1 20:01:01
	作者姓名: 孙禹铭
	参数说明:
	函数作用: 初始化按键控制参数
*/

// Function body
void KeyControlInit()
{
	old_tick=HAL_GetTick();
}

// End Function KeyControlIni
//---------------------------------------------------------

//---------------------------------------------------------
/*
	函数名称: KeyControl
	编辑时间: 2021-2-1 19:18:20
	作者姓名: 孙禹铭
	参数说明:
	函数作用: 阻塞式、非阻塞式 按键控制KEY_1
*/

// Function body
void KeyControl()
{
#if WORK_MODE ==0 //阻塞式
	if(HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)==KEY_PRESS)
	{
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)==KEY_PRESS)
		{
			while(HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)==KEY_PRESS);
			LED1_TOGGLE;
		}
	}
#elif WORK_MODE==1 //非阻塞式
	static uint8_t status=0;
	uint32_t new_tick;
	new_tick=HAL_GetTick();
	if(new_tick>(old_tick)+10)
	{
		old_tick=new_tick;
		if(HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)==KEY_PRESS)
		{
			if(status==0)	status=1;
			else if(status=1)
			{
				status=2;
				LED1_TOGGLE;
			}
		}
		else if(status==2)	status=0;
	}
#endif
}

// End Function KeyControl
//---------------------------------------------------------

//---------------------------------------------------------
/*
	函数名称: IRQKeyControl
	编辑时间: 2021-2-1 20:28:00
	作者姓名: 孙禹铭
	参数说明:
	函数作用: 中断方式按键控制
*/

// Function body
void IRQKeyControl()
{
	//HAL_TIM_Base_Stop_IT(&htim6);
	LED2_TOGGLE;
}

// End Function IRQKeyControl
//---------------------------------------------------------
