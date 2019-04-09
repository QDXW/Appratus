/******************************************************************************/
#include "devices.h"

/******************************************************************************/
PUMP_NUM Pump;

/******************************************************************************/
void Devices_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOC |
			RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOD, ENABLE);
	

	/* pump1~20 */ 
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_1, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_1, PIN_PUMP_1);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_2, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_2, PIN_PUMP_2);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_3, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_3, PIN_PUMP_3);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_4, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_4, PIN_PUMP_4);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_5, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_5, PIN_PUMP_5);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_6, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_6, PIN_PUMP_6);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_7, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_7, PIN_PUMP_7);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_8, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_8, PIN_PUMP_8);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_9, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_9, PIN_PUMP_9);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_10, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_10, PIN_PUMP_10);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_11, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_11, PIN_PUMP_11);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_12, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_12, PIN_PUMP_12);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_13, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_13, PIN_PUMP_13);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_14, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_14, PIN_PUMP_14);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_15, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_15, PIN_PUMP_15);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_16;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_16, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_16, PIN_PUMP_16);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_17;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_17, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_17, PIN_PUMP_17);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_18;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_18, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_18, PIN_PUMP_18);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_19;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_19, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_19, PIN_PUMP_19);
	
	GPIO_InitStructure.GPIO_Pin = PIN_PUMP_20;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_PUMP_20, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_PUMP_20, PIN_PUMP_20);


	/* Heat Led 1-3 */ 
	GPIO_InitStructure.GPIO_Pin = PIN_LED_HEAT_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_LED_HEAT_1, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_LED_HEAT_1, PIN_LED_HEAT_1);
	
	GPIO_InitStructure.GPIO_Pin = PIN_LED_HEAT_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_LED_HEAT_2, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_LED_HEAT_2, PIN_LED_HEAT_2);
	
	GPIO_InitStructure.GPIO_Pin = PIN_LED_HEAT_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_LED_HEAT_3, &GPIO_InitStructure);
	GPIO_ResetBits(PORT_LED_HEAT_3, PIN_LED_HEAT_3);
	
	/* key */
	GPIO_InitStructure.GPIO_Pin = PIN_KEY_CTR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT_KEY_CTR, &GPIO_InitStructure);	
	GPIO_ResetBits(PORT_KEY_CTR, PIN_KEY_CTR);
}

/******************************************************************************/
void Pump_Set(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,FunctionalState status)
{
	if(ENABLE == status)
	{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}
	else
	{
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}

/******************************************************************************/
void Pump_Control(PUMP_NUM Pump,FunctionalState status)
{
	switch(Pump)
	{
		case PUMP1:Pump_Set(PORT_PUMP_1,PIN_PUMP_1,status);break;
		case PUMP2:Pump_Set(PORT_PUMP_2,PIN_PUMP_2,status);break;
		case PUMP3:Pump_Set(PORT_PUMP_3,PIN_PUMP_3,status);break;
		case PUMP4:Pump_Set(PORT_PUMP_4,PIN_PUMP_4,status);break;
		case PUMP5:Pump_Set(PORT_PUMP_5,PIN_PUMP_5,status);break;
		case PUMP6:Pump_Set(PORT_PUMP_6,PIN_PUMP_6,status);break;
		case PUMP7:Pump_Set(PORT_PUMP_7,PIN_PUMP_7,status);break;
		case PUMP8:Pump_Set(PORT_PUMP_8,PIN_PUMP_8,status);break;
		case PUMP9:Pump_Set(PORT_PUMP_9,PIN_PUMP_9,status);break;
		case PUMP10:Pump_Set(PORT_PUMP_10,PIN_PUMP_10,status);break;
		case PUMP11:Pump_Set(PORT_PUMP_11,PIN_PUMP_11,status);break;
		case PUMP12:Pump_Set(PORT_PUMP_12,PIN_PUMP_12,status);break;
		case PUMP13:Pump_Set(PORT_PUMP_13,PIN_PUMP_13,status);break;
		case PUMP14:Pump_Set(PORT_PUMP_14,PIN_PUMP_14,status);break;
		case PUMP15:Pump_Set(PORT_PUMP_15,PIN_PUMP_15,status);break;
		case PUMP16:Pump_Set(PORT_PUMP_16,PIN_PUMP_16,status);break;
		case PUMP17:Pump_Set(PORT_PUMP_17,PIN_PUMP_17,status);break;
		case PUMP18:Pump_Set(PORT_PUMP_18,PIN_PUMP_18,status);break;
		case PUMP19:Pump_Set(PORT_PUMP_19,PIN_PUMP_19,status);break;
		case PUMP20:Pump_Set(PORT_PUMP_20,PIN_PUMP_20,status);break;
		default:
			break;
	}
}

/******************************************************************************/
void Devices_Init_Status(void)
{
	Valve1_Lock_Warm(CLOSED);
	Valve2_Lock_Push_Reagent(CLOSED);
	Valve3_Lock_Press(CLOSED);
	Valve4_Lock_Scroll(CLOSED);
	Valve5_Lock(CLOSED);
	Valve6_Lock(CLOSED);
	Valve7_Lock(CLOSED);
	Valve8_Lock(CLOSED);

	/* 最大功率加热 */
	SetpwmValue(HOT1,50);
	SetpwmValue(HOT2,100);
	SetpwmValue(HOT3,0);

	/* 所有的气缸初始化状态 */
	Delay_ms_SW(4000);
	Pump_Press = 0;
	Push_Rreagent = 0;
	Scroll_Press_Open = 0;
	Scroll_Press_Closed = 0;
	Apparatus_Achieve = 0;
}

/******************************************************************************/
void Valve1_Lock_Warm (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP1,DISABLE);
		Pump_Control(PUMP2,ENABLE);
	}
	else
	{
		Pump_Control(PUMP1,ENABLE);
		Pump_Control(PUMP2,DISABLE);
	}
}

/******************************************************************************/
void Valve2_Lock_Push_Reagent (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP3,ENABLE);
		Pump_Control(PUMP4,DISABLE);
	}
	else
	{
		Pump_Control(PUMP3,DISABLE);
		Pump_Control(PUMP4,ENABLE);
	}
}

/******************************************************************************/
uint8 Valve3_Lock_Press (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP5,ENABLE);
		Pump_Control(PUMP6,DISABLE);
	}
	else
	{
		Pump_Control(PUMP5,DISABLE);
		Pump_Control(PUMP6,ENABLE);
	}
	return 0;
}

/******************************************************************************/
void Valve4_Lock_Scroll (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP7,DISABLE);
		Pump_Control(PUMP8,ENABLE);
	}
	else
	{
		Pump_Control(PUMP7,ENABLE);
		Pump_Control(PUMP8,DISABLE);
	}
}

/******************************************************************************/
void Valve5_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP9,DISABLE);
		Pump_Control(PUMP10,ENABLE);
	}
	else
	{
		Pump_Control(PUMP9,ENABLE);
		Pump_Control(PUMP10,DISABLE);
	}
}

/******************************************************************************/
void Valve6_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP11,DISABLE);
		Pump_Control(PUMP12,ENABLE);
	}
	else
	{
		Pump_Control(PUMP11,ENABLE);
		Pump_Control(PUMP12,DISABLE);
	}
}

/******************************************************************************/
void Valve7_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP13,DISABLE);
		Pump_Control(PUMP14,ENABLE);
	}
	else
	{
		Pump_Control(PUMP13,ENABLE);
		Pump_Control(PUMP14,DISABLE);
	}
}

/******************************************************************************/
void Valve8_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP15,DISABLE);
		Pump_Control(PUMP16,ENABLE);
	}
	else
	{
		Pump_Control(PUMP15,ENABLE);
		Pump_Control(PUMP16,DISABLE);
	}
}

/******************************************************************************/
void Valve9_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP17,DISABLE);
		Pump_Control(PUMP18,ENABLE);
	}
	else
	{
		Pump_Control(PUMP17,ENABLE);
		Pump_Control(PUMP18,DISABLE);
	}
}

/******************************************************************************/
void Valve10_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP19,ENABLE);
	}
	else
	{
		Pump_Control(PUMP19,DISABLE);
	}
}

/******************************************************************************/
void Valve11_Lock (uint8 status)
{
	if(status)
	{
		Pump_Control(PUMP20,ENABLE);
	}
	else
	{
		Pump_Control(PUMP20,DISABLE);
	}
}
