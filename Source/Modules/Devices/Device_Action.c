/*
 * HostProcess_Ation.c
 *
 *  Created on: 2018Äê11ÔÂ5ÈÕ
 *      Author: Administrator
 */
/******************************************************************************/
#include "Device_Action.h"

/******************************************************************************/
void Apparatus_Action (void)
{
	Valve1_Lock_Warm(OPEN);
	Start_Apparatus = 1;
	Buffer[0] = 1;
	HostComm_Cmd_Send_RawData(1, Buffer,CMD_CODE_APPARATUS);
}

/******************************************************************************/
void Apparatus_Devices (void)
{
	if(Push_Rreagent)
	{
		Delay_ms_SW(300);
		Valve2_Lock_Push_Reagent(OPEN);
		Push_Rreagent = 0;
	}

	if(Pump_Press)
	{
		Valve3_Lock_Press(OPEN);
		Pump_Press = 0;
	}

	if(Scroll_Press_Open)
	{
		Scroll_Press_Times++;
		if(Scroll_Press_Times > Scroll_Times)
		{
			Valve2_Lock_Push_Reagent(CLOSED);
			Valve3_Lock_Press(CLOSED);
			Valve4_Lock_Scroll(CLOSED);
			Scroll_Press_Times = 0;
		}
		else
		{
			Valve4_Lock_Scroll(OPEN);
		}
		Scroll_Press_Open = 0;
	}

	if(Scroll_Press_Closed)
	{
		Valve4_Lock_Scroll(CLOSED);
		Scroll_Press_Closed = 0;
	}

	if(Apparatus_Achieve)
	{
		Apparatus_Achieve = 0;
		Buffer[0] = 0;
		HostComm_Cmd_Send_RawData(1, Buffer,CMD_CODE_APPARATUS);
	}
}

/******************************************************************************/
void Scroll_Press (void)
{
	Delay_ms_SW(40);
	Scroll_Press_Times = 0;
	Scroll_Press_Open = (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5))?((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0))?1:0):(Valve3_Lock_Press(OPEN));
	Delay_ms_SW(10);
	Scroll_Press_Closed = (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))?1:0;
}
