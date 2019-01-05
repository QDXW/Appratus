/*
 * Global_variable.h
 *
 *  Created on: 2018Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef SYSTEM_GLOBAL_VARIABLE_H_
#define SYSTEM_GLOBAL_VARIABLE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
extern uint8 Valve_Lock,Temp_Switch,Heat_Status,Start_Temp,L100_Switch;
extern uint8 respBuffer[30],HostComm_RecBufAvailable,L100_Apparatus;
extern uint8 cmdType,cmdCode,recBuffer[30],cmdBuffer[30],contReceive;
extern uint8 Temp_Count,Send_Flag,Bump_Switch,APP_Status;

extern uint16 recCount,HostComm_RecBufSize,cmdLength,respLength,Fiber_Optic;
extern uint16 Warm_Time,Time_second,Control_Temperature;

extern float Temper,Temper_HOT1;

#endif /* SYSTEM_GLOBAL_VARIABLE_H_ */
