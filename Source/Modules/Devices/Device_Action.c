/*
 * HostProcess_Ation.c
 *
 *  Created on: 2018Äê11ÔÂ5ÈÕ
 *      Author: Administrator
 */
/******************************************************************************/
#include "Device_Action.h"

/******************************************************************************/
uint8 sBuffer[2] = {1},fBuffer[2] = {0},Buffer[2] = {0};

/******************************************************************************/
void Warm_Block1 (void)
{
	if(cmdBuffer[5])
	{
		Temp_Count = 1;
		HostComm_Cmd_Send_RawData(1, sBuffer,CMD_CODE_WARM_BLOCK1);
	}
	else
	{
		Temp_Count = 0;
		HostComm_Cmd_Send_RawData(1, fBuffer,CMD_CODE_WARM_BLOCK1);

	}
}

/******************************************************************************/
void Carve_Action (void)
{
	APP_Status |= 1<<0;
	Valve1_Lock(CLOSED);
	Valve6_Lock(CLOSED);
	HostComm_Cmd_Send_RawData(1, fBuffer,CMD_CODE_CARVE_RESET);
}

/******************************************************************************/
void Faction_Information (void)
{
	uint8 Information_Data[1] = {0};
	Send_Flag = 1;
	Information_Data[0] = Control_Temperature;
	HostComm_Cmd_Send_RawData(1, Information_Data,CMD_CODE_WARM_TEMP);
	Delay_ms_SW(5);

	Information_Data[0] = (uint8) ((Warm_Time+1)/1000);
	HostComm_Cmd_Send_RawData(1, Information_Data,CMD_CODE_WARM_TIME);
	Delay_ms_SW(5);

	Information_Data[0] = (APP_Status & 0x02)?1:0;
	HostComm_Cmd_Send_RawData(1, Information_Data,CMD_CODE_APPARATUS);
	Delay_ms_SW(5);

	Information_Data[0] = (APP_Status & 0x01)?0:1;
	HostComm_Cmd_Send_RawData(1, Information_Data,CMD_CODE_CARVE_RESET);
	Delay_ms_SW(5);

	Information_Data[0] = Temp_Count;
	HostComm_Cmd_Send_RawData(1, Information_Data,CMD_CODE_WARM_BLOCK1);
	Send_Flag = 0;
}
