#ifndef SOURCE_MODULES_HOSTPROCESS_H_
#define SOURCE_MODULES_HOSTPROCESS_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
#define HOSTCOMM_UART_DATA_LEN_MAX				(512)

#define STDID_DEVICES_PUMP_CONTROL				(0X1001)

/******************************************************************************/
typedef struct
{
	Judge isRecvSuccess;								/* 一帧数据接收完成 */
	uint8 length;									/* 接收到帧长度 */
	uint8 buf[HOSTCOMM_UART_DATA_LEN_MAX];			/* 帧缓存 */
	uint8 validBuf[HOSTCOMM_UART_DATA_LEN_MAX/8];	/* 提取的帧有效数据 */
} HostComm_UartRxTypedef;

/******************************************************************************/
typedef enum
{
	OFFSET_HEADER = 0,
	OFFSET_LEN_LO,
	OFFSET_LEN_HI,
	OFFSET_CMD_TYPE,
	OFFSET_CMD_CODE,
	OFFSET_CMD_DATA,
	CMD_TYPE_APP = 0x10,
	CMD_CODE_TEMP,
	CMD_CODE_SUCCESS,
	CMD_CODE_APPARATUS,
	CMD_CODE_CONNECT,
	CMD_CODE_WARM_TEMP,
	CMD_CODE_WARM_TIME,
	CMD_CODE_SCROLL_TIMES,
	CMD_CODE_SCROLL_PRESS,

} OFFSET_HOSTCOMM;

/******************************************************************************/
typedef struct{
	uint8 PumpControlSR;

} LAMINATING;

/******************************************************************************/
extern HostComm_UartRxTypedef HostComm_UartRx;
extern Judge DevicesInit_enable;
extern Judge TEMP_HEAT_START;
extern LAMINATING Laminating;

/******************************************************************************/
extern void HostComm_Process(void);
extern void Exhaust_Air_Process(void);
extern void Recycle_Bead_Process(void);
extern void HostComm_Cmd_Process (void);
extern uint8 HostComm_Cmd_Send_RawData(uint16 length, uint8 dataBuf[],OFFSET_HOSTCOMM CMD_CODE);

#endif
