
#include "Comm_CAN.h"
#include "Comm_CAN_FIFO.h"
#include "Comm.h"
#include "sensor.h"

/******************************************************************************/
uint8 Comm_dataBuffer[SIZE_CMD_BUFFER];
uint8 Comm_eventBuffer[SIZE_CMD_BUFFER];
uint8 Comm_respBuffer[SIZE_RESP_BUFFER];

/******************************************************************************/
static void Comm_CAN_FilterInit(void);
static void Comm_CAN_FilterNumInit(uint8 FilterNum,
							uint16 Filter0, uint16 Filter1,
							uint16 Filter2, uint16 Filter3);

/******************************************************************************/
void Comm_CAN_Init(void)
{
	GPIO_InitTypeDef 		GPIO_InitStructure;
	CAN_InitTypeDef        	CAN_InitStructure;
	NVIC_InitTypeDef  		NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	/* NVIC Priority Group Configuration */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
#ifdef CAN_PA11_PA12
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
#elif defined CAN_PD0_PD1
	GPIO_PinRemapConfig(GPIO_Remap2_CAN1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
#elif defined CAN_PB8_PB9
	GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
#endif

	/* Initialize pins */
	GPIO_InitStructure.GPIO_Pin = COMM_CAN_TX_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(COMM_CAN_TX_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = COMM_CAN_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(COMM_CAN_RX_PORT, &GPIO_InitStructure);

	/*  */
	NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/*  */
	CAN_InitStructure.CAN_TTCM = DISABLE;
	CAN_InitStructure.CAN_ABOM = DISABLE;
	CAN_InitStructure.CAN_AWUM = DISABLE;
	CAN_InitStructure.CAN_NART = DISABLE;
	CAN_InitStructure.CAN_RFLM = DISABLE;
	CAN_InitStructure.CAN_TXFP = DISABLE;
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
	CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStructure.CAN_BS1 = CAN_BS1_2tq;
	CAN_InitStructure.CAN_BS2 = CAN_BS2_3tq;
#if CAN_BAUDRATE == 1000 /* 1MBps */
	CAN_InitStructure.CAN_Prescaler =6;
#elif CAN_BAUDRATE == 500 /* 500KBps */
	CAN_InitStructure.CAN_Prescaler =12; /* 36/((1+2+3)*12) = 500KBps */
#elif CAN_BAUDRATE == 250 /* 250KBps */
	CAN_InitStructure.CAN_Prescaler =24;
#elif CAN_BAUDRATE == 125 /* 125KBps */
	CAN_InitStructure.CAN_Prescaler =48;
#elif  CAN_BAUDRATE == 100 /* 100KBps */
	CAN_InitStructure.CAN_Prescaler =60;
#elif  CAN_BAUDRATE == 50 /* 50KBps */
	CAN_InitStructure.CAN_Prescaler =120;
#elif  CAN_BAUDRATE == 20 /* 20KBps */
	CAN_InitStructure.CAN_Prescaler =300;
#elif  CAN_BAUDRATE == 10 /* 10KBps */
	CAN_InitStructure.CAN_Prescaler =600;
#endif
	CAN_Init(CAN1, &CAN_InitStructure);

	/* Set reception filter mechanism */
	Comm_CAN_FilterInit();
							  
	/* Enable CAN_IT_FMP0 interrupt */
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
}

/******************************************************************************/
static void Comm_CAN_FilterNumInit(uint8 FilterNum,
							uint16 Filter0, uint16 Filter1,
							uint16 Filter2, uint16 Filter3)
{
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
	
	CAN_FilterInitStructure.CAN_FilterNumber = FilterNum;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdList;
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_16bit;
	CAN_FilterInitStructure.CAN_FilterIdLow = (Filter0 << 5);
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = (Filter1 << 5);
	CAN_FilterInitStructure.CAN_FilterIdHigh = (Filter2 << 5);
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = (Filter3 << 5);
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
	CAN_FilterInit(&CAN_FilterInitStructure);
}

/******************************************************************************/
static void Comm_CAN_FilterInit(void)
{
	/* Set reception filter mechanism */
	Comm_CAN_FilterNumInit(0,
			STDID_RX_FILLING,
			STDID_RX_TEST,
			STDID_SEND_INJUCET_TIME,
			STDID_RX_INVALID);
		
	/* @TODO */

	Comm_CAN_FilterNumInit(1,
			STDID_START,
			STDID_INFUSION_PREPARE,
			STDID_FILL_END,
			STDID_RX_VALVE_LOCK);
	
	Comm_CAN_FilterNumInit(2,
			STDID_EXHAUST_AIR,
			STDID_RECYCLE_BEAD,
			STDID_SEND_BUMP,
			STDID_SEND_BUMP_VOL);


}

/******************************************************************************/
void USB_LP_CAN1_RX0_IRQHandler(void)
{
	CanRxMsg RxMessage;
	
	if (SET == CAN_GetITStatus(CAN1, CAN_IT_FMP0))
	{
		
		CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
		/* CAN获取到的数据入列 */
		if(Comm_CanRxData(&RxMessage) == SUCCESS)
			Comm_CAN_FIFO_RxDataPut(&RxMessage, &RxDataFIFO);
		
		CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
	}
}
