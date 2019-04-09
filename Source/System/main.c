/******************************************************************************/
#include "Project_File.h"

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

	/* ��ʼ״̬ */
	Devices_Init_Status();

	while(1)
	{
		HostComm_Process();
		Comm_Process();

		/* ��Ĥ���� */
		Apparatus_Devices();
	}
}
