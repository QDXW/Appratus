/*
 * Global_variable.h
 *
 *  Created on: 2018年9月29日
 *      Author: Administrator
 */

#ifndef SYSTEM_GLOBAL_VARIABLE_H_
#define SYSTEM_GLOBAL_VARIABLE_H_

/******************************************************************************/
#include "Project_File.h"

/**************************USB 通信********************************************/
extern uint8 respBuffer[512],HostComm_RecBufAvailable;
extern uint8 cmdType,cmdCode,recBuffer[512],cmdBuffer[512],contReceive;

extern uint16 recCount,HostComm_RecBufSize,cmdLength,respLength;

/***************************覆膜***********************************************/
extern uint8 Start_Apparatus,Buffer[100],Scroll_Times;
extern uint8 Scroll_Press_Closed,Scroll_Press_Times,Push_Rreagent;
extern uint8 Apparatus_Achieve,Pump_Press,Scroll_Press_Open,Push_Rreagent;
extern uint8 Get_Warm_Flag;

extern uint16 Warm_Time,Control_Temperature,Touch_Action;

extern float Temper_HOT1;

#endif /* SYSTEM_GLOBAL_VARIABLE_H_ */
