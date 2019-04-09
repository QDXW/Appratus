/*
 * Global_variable.c
 *
 *  Created on: 2018年9月20日
 *      Author: Administrator
 */

/******************************************************************************/
#include "Global_variable.h"

/***************************USB 通信*******************************************/
uint8 cmdType = 0,cmdCode = 0,contReceive = 0,HostComm_RecBufAvailable = 0;
uint8 recBuffer[512] = {0},cmdBuffer[512] = {0},respBuffer[512] = {0};

uint16 HostComm_RecBufSize = 0,cmdLength = 0,respLength = 0,recCount = 0;

/***************************覆膜***********************************************/
uint8 Start_Apparatus = 0,Buffer[100] = {0};
uint8 Scroll_Times_L100 = 0,Push_Rreagent_L100 = 0,Pump_Press;
uint8 Scroll_Press_Closed = 0,Scroll_Press_Times = 0,Apparatus_Achieve = 0;
uint8 Scroll_Press_Open = 0,Push_Rreagent = 0,Scroll_Times = 2,Get_Warm_Flag = 0;

uint16 Warm_Time = 6999,Control_Temperature = 180;
uint16 Touch_Action = 0;

float Temper_HOT1 = 0;
