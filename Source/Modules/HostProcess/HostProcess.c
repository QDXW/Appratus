#include "HostProcess.h"

/******************************************************************************/
Judge DevicesInit_enable = FALSE;
LAMINATING Laminating;
/******************************************************************************/
HostComm_UartRxTypedef HostComm_UartRx;

/******************************************************************************/
void HostComm_Process(void)
{
	uint8 sBuffer[2] = {1};

	/* Command type */
	cmdType = cmdBuffer[OFFSET_CMD_TYPE];
	/* Command code */
	cmdCode = cmdBuffer[OFFSET_CMD_CODE];
	if ((cmdType == CMD_TYPE_APP) && HostComm_RecBufAvailable)
	{
		switch (cmdCode)
		{
		case CMD_CODE_CONNECT:
				HostComm_Cmd_Send_RawData(1, sBuffer,CMD_CODE_CONNECT);
			break;

		case CMD_CODE_APPARATUS:
			if(APP_Status & 0x02)
			{}
			else
			{
				APP_Status |= 1<<1;
				Heat_Status = 1;
				Valve5_Action();
				L100_Apparatus = cmdBuffer[5];
				HostComm_Cmd_Send_RawData(1, sBuffer,CMD_CODE_APPARATUS);
			}
			break;

		case CMD_CODE_WARM_TEMP:
			Control_Temperature = cmdBuffer[5];
			break;

		case CMD_CODE_WARM_TIME:
			Warm_Time = cmdBuffer[5];
			Warm_Time = Warm_Time*1000 - 1;
			break;

		case CMD_CODE_WARM_BLOCK1:
			Warm_Block1();
			break;

		case CMD_CODE_CARVE_RESET:
			if(APP_Status & 0x01)
			{}
			else
			{
				Carve_Action();
			}
			break;

//		case CMD_CODE_FACTION_RESET:
//			Faction_Information();
//			break;

		default:
			break;
		}

		HostComm_RecBufAvailable = 0;
		memset(cmdBuffer,0,30);
	}
}

/******************************************************************************/
static uint16 HostComm_Cmd_Respond_Common(uint16 cmdDataNum, uint8 cmdType,
		uint8 cmdCode)
{
	uint16 packageLength = 6 + cmdDataNum;
	uint16 crcCal = 0;

	/* Head */
	respBuffer[OFFSET_HEADER] = '$';

	/* Package length */
	respBuffer[OFFSET_LEN_LO] = Common_LoByte(packageLength);
	respBuffer[OFFSET_LEN_HI] = Common_HiByte(packageLength);

	/* Command type and code */
	respBuffer[OFFSET_CMD_TYPE] = cmdType;
	respBuffer[OFFSET_CMD_CODE] = cmdCode;

	/* Calculate CRC
	 * 1. &cmdBuffer[1]: because the first byte is '$' which is not included
	 *    in CRC calculation
	 * 2. cmdLength - 2: because cmdLength includes 2-byte CRC */
	crcCal = CRC16_Calculate(&respBuffer[1], packageLength - 2, 0xFFFF,
									0x0000);

	/* CRC */
	respBuffer[OFFSET_CMD_DATA + cmdDataNum] = Common_LoByte(crcCal);
	respBuffer[OFFSET_CMD_DATA + cmdDataNum + 1] = Common_HiByte(crcCal);

	/* Tail */
	respBuffer[OFFSET_CMD_DATA + cmdDataNum + 2] = '#';

	return packageLength;
}

/******************************************************************************/
uint8 HostComm_Cmd_Send_RawData(uint16 length, uint8 dataBuf[],OFFSET_HOSTCOMM CMD_CODE)
{
	uint16 totalPackageLength = 2; /* Include head and tail */
	uint16 cmdDataLength = 0;

	Send_Flag = 1;
	memcpy(&respBuffer[OFFSET_CMD_DATA], dataBuf, length);
	cmdDataLength = length;
	totalPackageLength += HostComm_Cmd_Respond_Common(cmdDataLength,
							CMD_TYPE_APP, CMD_CODE);
	HostComm_SendCommand(&respBuffer[0], totalPackageLength);
	HostComm_RecBufAvailable = 0;
	Send_Flag = 0;
	return 0;
}
