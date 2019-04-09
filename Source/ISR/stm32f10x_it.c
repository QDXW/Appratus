/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2018
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 

/******************************************************************************/
uint16 Display_second = 0;
uint16 Apparatus_Second = 0,Time_Millisecond = 0;
uint16 Touch_Interval_Millisecond = 0;

/******************************************************************************/
void SysTick_Handler(void)
{
	/* Decrease TimingDelay */
	TimingDelay_Decrement();
	millis++;

	/* 串口发送温度数据 */
	Display_second++;
	if(Display_second > 599)
	{
		Display_second = 0;

		/* 发送温度  */
		memcpy(&Buffer[0],&Temper_HOT1,4);

		if(!Get_Warm_Flag)
			HostComm_Cmd_Send_RawData(8, Buffer,CMD_CODE_TEMP);
	}

	if(Start_Apparatus)
	{
		Apparatus_Second++;
		if(Apparatus_Second > (Warm_Time-1))
		{
			Apparatus_Second = 0;
			Valve1_Lock_Warm(CLOSED);
			Start_Apparatus = 0;
			Push_Rreagent = 1;
		}
	}
	else
	{
		Apparatus_Second = 0;
	}
}

/******************************************************************************/
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  	//检查TIM4更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);  		//清除TIMx更新中断标志
		if(!Touch_Action)
		{
			Time_Millisecond++;
			if(Time_Millisecond > 4)
			{
				Time_Millisecond = 0;

				Get_Warm_Flag = 1;
				Get_Temp_Average(HOT1);
				Get_Warm_Flag = 0;

//				Temp_Monitor();
			}
		}
	}
}

/******************************************************************************/
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line10) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line10);
	}

	if(EXTI_GetITStatus(EXTI_Line11) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line11);
	}

	if(EXTI_GetITStatus(EXTI_Line12) != RESET)
	{
		Delay_ms_SW(50);
		Apparatus_Achieve = (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_12))?1:0;
		EXTI_ClearITPendingBit(EXTI_Line12);
	}

	if(EXTI_GetITStatus(EXTI_Line13) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line13);
	}

	if(EXTI_GetITStatus(EXTI_Line14) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line14);
	}

	if(EXTI_GetITStatus(EXTI_Line15) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

/******************************************************************************/
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line5);
	}

	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
	{
		Delay_ms_SW(50);
		Scroll_Press_Open = (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_7))?1:0;
		EXTI_ClearITPendingBit(EXTI_Line7);
	}

	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line8);
	}

	if(EXTI_GetITStatus(EXTI_Line9) != RESET)
	{
		Delay_ms_SW(50);
		Scroll_Press_Closed = (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_9))?1:0;
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}

/******************************************************************************/
void EXTI4_IRQHandler(void)
{
 	if(EXTI_GetITStatus(EXTI_Line4) != RESET)
	{
 		Delay_ms_SW(50);
		Pump_Press = (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4))?1:0;
 		EXTI_ClearITPendingBit(EXTI_Line4);
	}
}

/******************************************************************************/
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) != RESET)
	{
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

/******************************************************************************/
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		Delay_ms_SW(50);
		Scroll_Press_Open = (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0))?1:0;
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

/******************************************************************************/
void NMI_Handler(void)
{
}
 
/******************************************************************************/
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
/******************************************************************************/
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/******************************************************************************/
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
/******************************************************************************/
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
/******************************************************************************/
void SVC_Handler(void)
{
}
 
/******************************************************************************/
void DebugMon_Handler(void)
{
}
 
/******************************************************************************/
void PendSV_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
