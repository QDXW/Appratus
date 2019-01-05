/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
uint8 Temptertuer = 0;

/******************************************************************************/
int main(void)
{
	SysTick_Init();

	Devices_Init();

	HostComm_Init();

	TIM4_Int_Init(999,7199);			/* 10Khz的计数频率，计数到1000为100ms */

	Comm_Init();

	PosSensor_Init();

	TempControl_Init();

	Devices_Return_Zero();

	Judge_Temp();

	while(1)
	{
		HostComm_Process();
		Comm_Process();
	}
}

/******************************************************************************/
void Judge_Temp (void)
{
	/* 温度未到180°时不执行程序  */
	while(Start_Temp)
	{
		HostComm_Process();

		/* 温度检测处理  */
		Start_Temp |= (Temper_HOT1 >= Control_Temperature)?(0<<0):(1<<0);
	}
}
