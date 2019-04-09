/******************************************************************************/
#include "Project_File.h"

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

	/* 初始状态 */
	Devices_Init_Status();

	while(1)
	{
		HostComm_Process();
		Comm_Process();

		/* 覆膜流程 */
		Apparatus_Devices();
	}
}
