/*
 * Global_variable.c
 *
 *  Created on: 2018��9��20��
 *      Author: Administrator
 */

/******************************************************************************/
#include "Global_variable.h"

/******************************************************************************/
uint8 cmdType = 0,cmdCode = 0,contReceive = 0,Exhaust_Air = 2,Recycle_Bead = 2;
uint8 recBuffer[30] = {0},cmdBuffer[30] = {0},respBuffer[30] = {0};
uint8  Valve_Lock = 0,Heat_Status = 0,Start_Temp = 1;
uint8 Temp_Count = 1,Send_Flag = 0,Bump_Switch = 255,APP_Status = 0;
uint8 L100_Switch = 0,L100_Apparatus = 0,HostComm_RecBufAvailable = 0;

uint16 HostComm_RecBufSize = 0,cmdLength = 0,respLength = 0,Fiber_Optic = 0;
uint16 recCount = 0,Warm_Time = 6999,Time_second = 0,Control_Temperature = 180;

float Temper_HOT1 = 0;
