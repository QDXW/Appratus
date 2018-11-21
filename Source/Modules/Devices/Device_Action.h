/*
 * Device_Action.h
 *
 *  Created on: 2018��11��5��
 *      Author: Administrator
 */

#ifndef MODULES_DEVICES_DEVICE_ACTION_H_
#define MODULES_DEVICES_DEVICE_ACTION_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
extern void Start_Filling(void);
extern void Warm_Block1(void);
extern void Warm_Block2(void);
extern void Carve_Action(void);
extern void Warm_Bump(void);
extern void Carve_Bump(void);
extern void Valve2_Movement(void);
extern void Valve3_Movement(void);
extern void Valve4_Movement(void);
extern void Press_Plate_Movement(void);
extern void Injucet_Bump_Switch(void);
extern void Exhaus_Air_Act(void);
extern void Recycle_Bead_Act(void);

void Injucet_Volume1 (void);
void Injucet_Volume2 (void);
void Injucet_Volume3 (void);
void Injucet_Volume4 (void);
void Injucet_Volume5 (void);
void Injucet_Volume6 (void);
void Injucet_Volume7 (void);
void Injucet_Time (void);


#endif /* MODULES_DEVICES_DEVICE_ACTION_H_ */