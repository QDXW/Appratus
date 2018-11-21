#ifndef SOURCE_MODULES_MOVEMENT_MOVEMENT_H
#define SOURCE_MODULES_MOVEMENT_MOVEMENT_H

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct
{
	 uint8 PlaceLump_Flag;			//�Ӹ���־λ����ֹ������޷��ÿ�����жϱ��󴥷�
	 uint8 FillingPos_Flag;			//�Ӹ���־λ����ֹ��⵽���װλ���жϱ��󴥷�
	 uint8 GotoHeatPos_Flag;		//�Ӹ���־λ����ֹ��⵽����λ�ñ��󴥷�
	 uint8 CurrentHeatPos_Flag;	//�Ӹ���־λ����ֹ��⵽����λ�ñ��󴥷�
	 uint8 ConpactionPos_Flag;	//�Ӹ���־λ����ֹ��⵽�ٴ�ѹ�����󴥷�
	 uint8 IncisePos_Flag;			//�Ӹ���־λ����ֹ����и�󴥷�
	 uint8 InciseFinish_Flag;		
	 uint8 TrunPos_Flag;
	 uint8 VibratingDisk_Flag;
}CHECK;

/******************************************************************************/
extern CHECK Check;

/******************************************************************************/
void Movement_Process(void);
void PlaceLump_Action(void);
void Filling_Action(void);
void GotoHeat_Action(void);
void Heat_Action(void);
void Conpaction_Action(void);
void Incise_Action(void);
void InciseFinish_Action(void);
void Trun_Action(void);
void VibratingDisk_Action(void);


#endif
