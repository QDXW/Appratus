/******************************************************************************/
#include "Movement.h"

/******************************************************************************/
CHECK Check;

/******************************************************************************/
void Movement_Process(void)
{
	if(ExitFlag.PlaceLumpSR == TRUE)
	{
		ExitFlag.PlaceLumpSR = FALSE;
		PlaceLump_Action();
	}
	else if(ExitFlag.FillingPosSR == TRUE)
	{
		ExitFlag.FillingPosSR = FALSE;
		Filling_Action();
	}
	else if(ExitFlag.GotoHeatPosSR == TRUE)
	{
		ExitFlag.GotoHeatPosSR = FALSE;
		GotoHeat_Action();
	}
	else if(ExitFlag.CurrentHeatSR == TRUE)
	{
		Heat_Action();
	}
	else if(ExitFlag.ConpactionPosSR == TRUE)
	{
		Conpaction_Action();
	}
	else if(ExitFlag.IncisePosSR == TRUE)
	{
		Incise_Action();
	}
	else if(ExitFlag.InciseFinishSR == TRUE)
	{
		ExitFlag.InciseFinishSR = FALSE;
		InciseFinish_Action();
	}
	else if(ExitFlag.TrunPosSR == TRUE)
	{
		ExitFlag.TrunPosSR = FALSE;
		Trun_Action();
	}
	else if(ExitFlag.VibratingDiskSR == TRUE)
	{
		ExitFlag.VibratingDiskSR = FALSE;
		Trun_Action();
	}
}

/******************************************************************************/
/*�з��ÿ����*/
void PlaceLump_Action(void)
{		
/*��������,�����ÿ����뵽��װλ�ã��ȴ�����������*/
//	Pump_Control(PUMP1��DISABLE)		//��ֹ���Ʒ��ÿ���˵��˶�
//	Pump_Control(PUMP2��ENABLE)			//��ʼ���Ʒ��ÿ���ǰ���˶�
}

/******************************************************************************/
/*���ÿ鵽���װλ�ã���װ*/
void Filling_Action(void)
{
	/*ÿ�ζ���ǰ��Ҫ������һ����������������*/
//	Pump_Control(PUMP2��DISABLE)		//��ֹ���Ʒ��ÿ���ǰ���˶�
//	Pump_Control(PUMP1��ENABLE)			//��ʼ���Ʒ��ÿ���˵Ľ�ֹ

	//�������Լ�����ͨ��
	//���䷢�͸��˶���
	//�˶���ִ�й�װ����װ��ɺ�ظ�
	//����Can�жϣ��ǵý���װ��־λ�ı�
	//�ȴ��˶���ظ�֮��ǰ������λ��
}

/******************************************************************************/
/*��װ��ɣ�ǰ������λ��*/
void GotoHeat_Action(void)
{
		/*��������,�����ÿ��Ƶ�����λ�ã��ȴ�����������*/
//		Pump_Control(PUMP3��DISABLE)	
//		Pump_Control(PUMP4��ENABLE)	
}

/******************************************************************************/
/*��ǰλ�ü���λ�ã��ɼ���*/
void Heat_Action(void)
{
	/*�������λ��֮�����û�ȥ*/
//		Pump_Control(PUMP4��DISABLE)	
//		Pump_Control(PUMP3��ENABLE)	
	if(1)
	{
		//����¶ȣ��������Ŀ���¶ȵȴ�
	}
	else
	{
		/*��������,ʹ�����½�����Ĥ*/
//		Pump_Control(PUMP5��DISABLE)	
//		Pump_Control(PUMP6��ENABLE)	
		//����
		//if(����>time)
		//�ر����ã���ʹ�������˶�
//		Pump_Control(PUMP6��DISABLE)	
//		Pump_Control(PUMP5��ENABLE)
			ExitFlag.CurrentHeatSR = FALSE;
	}
}

/******************************************************************************/
void Conpaction_Action(void)
{
			/*��������,ʹ�����½�����Ĥ*/
//		Pump_Control(PUMP7��DISABLE)	
//		Pump_Control(PUMP8��ENABLE)	
		//����
		//if(����>time)
		//�ر����ã���ʹ�������˶�
//		Pump_Control(PUMP7��DISABLE)	
//		Pump_Control(PUMP8��ENABLE)
			ExitFlag.ConpactionPosSR = FALSE;
}

/******************************************************************************/
void Incise_Action(void)
{
					/*��������,ʹ�����½�����Ĥ*/
//		Pump_Control(PUMP11��DISABLE)	
//		Pump_Control(PUMP12��DISABLE)
//		Pump_Control(PUMP9��ENABLE)	
//		Pump_Control(PUMP10��ENABLE)	

		//����
		//if(����>time)
		//�ر����ã���ʹ�������˶�
//		Pump_Control(PUMP9��DISABLE)	
//		Pump_Control(PUMP10��DISABLE)
//		Pump_Control(PUMP11��ENABLE)	
//		Pump_Control(PUMP12��ENABLE)
			ExitFlag.IncisePosSR = TRUE;
}

/******************************************************************************/
void InciseFinish_Action(void)
{
			/*��������,�����ÿ��Ƶ�ת��λ�ã��ȴ�����������*/
//		Pump_Control(PUMP13��DISABLE)	
//		Pump_Control(PUMP14��ENABLE)	
}

/******************************************************************************/
void Trun_Action(void)
{
	/*��������13,14��ȥ*/
//		Pump_Control(PUMP14��DISABLE)	
//		Pump_Control(PUMP13��ENABLE)	
	/*��������,�����ÿ��Ƶ����÷�Ӧ��λ�ã��ȴ�����������*/
//		Pump_Control(PUMP16��DISABLE)	
//		Pump_Control(PUMP15��ENABLE)	
}

/******************************************************************************/
void VibratingDisk_Action(void)
{
		/*��������13,14��ȥ*/
//		Pump_Control(PUMP15��DISABLE)	
//		Pump_Control(PUMP16��ENABLE)	
}
