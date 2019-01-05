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

	TIM4_Int_Init(999,7199);			/* 10Khz�ļ���Ƶ�ʣ�������1000Ϊ100ms */

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
	/* �¶�δ��180��ʱ��ִ�г���  */
	while(Start_Temp)
	{
		HostComm_Process();

		/* �¶ȼ�⴦��  */
		Start_Temp |= (Temper_HOT1 >= Control_Temperature)?(0<<0):(1<<0);
	}
}
