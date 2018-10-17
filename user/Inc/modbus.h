/*
 * modbus.h
 *
 *  Created on: 25.08.2015
 *      Author: sagok
 *
 * ��������� ������ ���������� � ������������� ���������� ������, ������������� �� ����� 3,5 ��������.
 * �� ����� �������� ��������� �� ������ ���� ���� ������������� ����� 1,5 ��������.
 * ��� ��������� ����� 19200 ��� ����������� ������������ ��������� 1,75 � 0,75 ��, ��������������.
 *
 * ________________________________________________________________________________________________
 * ����� �������� (�����������) ����������	|	��� �������	|	������	|	���� ����������� ������
 * ------------------------------------------------------------------------------------------------
 * ����� �������� ���������� � ����� ����������� ����������, � �������� ��������� ������. ������� ���������� �������� ������ �� �������, ����������� � �� �����.
 * ����� ����� ���������� � ������ ����������� �������� ����������, ������� ����� ���������� �� 1 �� 247.
 * ����� 0 ������������ ��� ����������������� ��������, ��� ��������� ������ ����������, ������ � ��������� 248�255 � ���������������;
 *
 * ��� ������� � ��� ��������� ����������� ���� �����. ��� ������� �������� ����������, ����� ������ ��� ���������� ������ �������� ������� �� ���� ������� ����������;
 *
 * ������ � ���� �������� ����������, ����������� �������� ���������� ��� ���������� �������� �������� ������� ��� �������� ������, ������������ ������� �����������
 * � ����� �� ������ ��������. ����� � ������ ���� ������� �� ������ �������, ����� � ���� ������ ����� ���� ����������� ���� �������;
 *
 * ���� ����������� ������ � ����������� ����� ��� �������� ���������� ������ � �����.
 *
 * ������������ ������ ADU ��� ���������������� ����� RS232/RS485 � 256 ����, ��� ����� TCP � 260 ����.
 *
 * ������������ ��������� ���������� ������ ������� ������:
 * ���������� ����� (Discrete Inputs)		���� ���		������ ������
 * �������� ������ (Coils)					���� ���		������ � ������
 * �������� ����� (Input Registers)			16-�����������	������ ������
 * �������� �������� (Holding Registers)	16-�����������	������ � ������
 *
 * ������� ��������� Modbus:
 * 1 (0x01) � ������ �������� �� ���������� ��������� ������ (Read Coil Status).
 * 2 (0x02) � ������ �������� �� ���������� ���������� ������ (Read Discrete Inputs).
 * 3 (0x03) � ������ �������� �� ���������� ��������� �������� (Read Holding Registers).
 * 4 (0x04) � ������ �������� �� ���������� ��������� ����� (Read Input Registers).
 *
 * � ������ ���������� ����������� ������. ���������� ���� ������ ������� �� ����������
 * ����������� ���������. ����� ������� ���������� ���� ����, �������� �������� ����� ���������� ���� ������.
 * �������� ��������� �������� � ��������� ����� ���������� ������� � ���������� ������, �� ��� ����� �� �������, ������� ���� ������� �������� ��������� ������:
 *
 * ���� 1	���� 2	���� 3	���� 4	�	���� N-1	���� N
 * RA,1		RA,0	RA+1,1	RA+1,0	�	RA+Q-1,1	RA+Q-1,0
 *
 */



#ifndef MODBUS_H_
#define MODBUS_H_

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbconfig.h"
#include "mbframe.h"
#include "mbutils.h"

#include "stdbool.h"

#include "fsdata.h"

#include "queue.h"
/* ----------------------- Defines ------------------------------------------*/
#define	MB_SlaveAddres					1
#define	MB_MasterAddres					2

#define	_SizeModbusRX					250

/* ----------------------- Defines ------------------------------------------*/

#define MB_PDU_REQ_READ_ADDR_OFF                ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_READ_REGCNT_OFF              ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_READ_SIZE                    ( 4 )

#define MB_PDU_FUNC_READ_REGCNT_MAX             ( 0x007D )
#define MB_PDU_FUNC_READ_BYTECNT_OFF            ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_READ_VALUES_OFF             ( MB_PDU_DATA_OFF + 1 )

#define MB_PDU_FUNC_READ_WORDCNT_OFF            ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_READ_MEMADDR_OFF           	( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_FUNC_READ_VALUES_W_MEM_OFF       ( MB_PDU_DATA_OFF + 4 )

#define MB_PDU_FUNC_READ_SIZE_MIN               ( 1 )

#define MB_PDU_REQ_WRITE_ADDR_OFF               ( MB_PDU_DATA_OFF + 0)
#define MB_PDU_REQ_WRITE_VALUE_OFF              ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_WRITE_SIZE                   ( 4 )
#define MB_PDU_FUNC_WRITE_ADDR_OFF              ( MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_WRITE_VALUE_OFF             ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_FUNC_WRITE_SIZE                  ( 4 )

#define MB_PDU_REQ_WRITE_MUL_ADDR_OFF           ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_WRITE_MUL_REGCNT_OFF         ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_WRITE_MUL_BYTECNT_OFF        ( MB_PDU_DATA_OFF + 4 )
#define MB_PDU_REQ_WRITE_MUL_VALUES_OFF         ( MB_PDU_DATA_OFF + 5 )
#define MB_PDU_REQ_WRITE_MUL_SIZE_MIN           ( 5 )
#define MB_PDU_REQ_WRITE_MUL_REGCNT_MAX         ( 0x0078 )
#define MB_PDU_FUNC_WRITE_MUL_ADDR_OFF          ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_WRITE_MUL_REGCNT_OFF        ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_FUNC_WRITE_MUL_SIZE              ( 4 )

#define MB_PDU_REQ_READWRITE_READ_ADDR_OFF      ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_REQ_READWRITE_READ_REGCNT_OFF    ( MB_PDU_DATA_OFF + 2 )
#define MB_PDU_REQ_READWRITE_WRITE_ADDR_OFF     ( MB_PDU_DATA_OFF + 4 )
#define MB_PDU_REQ_READWRITE_WRITE_REGCNT_OFF   ( MB_PDU_DATA_OFF + 6 )
#define MB_PDU_REQ_READWRITE_WRITE_BYTECNT_OFF  ( MB_PDU_DATA_OFF + 8 )
#define MB_PDU_REQ_READWRITE_WRITE_VALUES_OFF   ( MB_PDU_DATA_OFF + 9 )
#define MB_PDU_REQ_READWRITE_SIZE_MIN           ( 9 )
#define MB_PDU_FUNC_READWRITE_READ_BYTECNT_OFF  ( MB_PDU_DATA_OFF + 0 )
#define MB_PDU_FUNC_READWRITE_READ_VALUES_OFF   ( MB_PDU_DATA_OFF + 1 )
#define MB_PDU_FUNC_READWRITE_SIZE_MIN          ( 1 )

/* -----------------------Slave Defines -------------------------------------*/
#define S_DISCRETE_INPUT_START        0
#define S_DISCRETE_INPUT_NDISCRETES   16
#define S_COIL_START                  0
#define S_COIL_NCOILS                 64
#define S_REG_INPUT_START             0
#define S_REG_INPUT_NREGS             100
#define S_REG_HOLDING_START           0
#define S_REG_HOLDING_NREGS           100

/* salve mode: holding register's all address */
#define          S_HD_RESERVE                     0
#define          S_HD_CPU_USAGE_MAJOR             1
#define          S_HD_CPU_USAGE_MINOR             2
/* salve mode: input register's all address */
#define          S_IN_RESERVE                     0
/* salve mode: coil's all address */
#define          S_CO_RESERVE                     0
/* salve mode: discrete's all address */
#define          S_DI_RESERVE                     0

/* -----------------------Master Defines -------------------------------------*/
#define M_DISCRETE_INPUT_START        0
#define M_DISCRETE_INPUT_NDISCRETES   16
#define M_COIL_START                  0
#define M_COIL_NCOILS                 16

#define M_REG_INPUT_START             0
#define M_REG_INPUT_NREGS             0x1F					// ������� �������� ������
#define M_REG_HOLDING_START           0
#define M_REG_HOLDING_NREGS           10					// �������� �������� ������

/* master mode: holding register's all address */
#define          M_HD_RESERVE                     0
/* master mode: input register's all address */
#define          M_IN_RESERVE                     0
/* master mode: coil's all address */
#define          M_CO_RESERVE                     0
/* master mode: discrete's all address */
#define          M_DI_RESERVE                     0

#define RT_WAITING_FOREVER              -1              /**< Block forever until get resource. */
#define RT_WAITING_NO                   0               /**< Non-block. */


#define		MaxSizeBlok		120//0x7C			// �������� ��� ����� �������� � ����� ������
#define		_MB_Tr_Limit	5					// ������������ ����� �������� ��� ������

#define		_GooseSpeedSize		31				// ������������ ������ �������� ��������� ��� �����

#define		SizeAddr		1
#define		SizeFunct		1
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500) || defined (MR741)
#define		SizeMemAddr		0
#else
#define		SizeMemAddr		2
#endif
#define		SizeNumbByte	1
#define		SizeNumbWord	2
#define		SizeCRC			2
typedef struct					// ��� �������� ����� ������� ��������.
{
  uint8_t 	MBSlaveAddr;
  uint8_t 	MBFunct;
  uint16_t 	MBData[252];
//  uint16_t 	MBCRC;
} MBFrame;


BOOL		Hal_setTimeFromMB_Date( uint16_t *MDateBuf );		// ������� ��������� ����� �� ������ ������
int8_t		Hal_setIPFromMB_Date( uint16_t * MDateBuf );		// ������� ��������� IP ������ �� ������ ������
int8_t		Hal_Verify_Rev( uint8_t * MDateBuf );				// ������� ��������� ������ ������� � ��������
BOOL		Hal_setConfSWFromMB_Date ( uint16_t * MDateBuf );	// ������� ��������� ������� ����������� � ������ ����� �� ������ ������
uint16_t	Hal_get_SizeMessageFromMB( uint8_t * MDateBuf );	// �������� ������ ��������� �� ������ ���������


BOOL		xModbus_Set_SizeAnswer( uint16_t Size, uint16_t Addr );
uint16_t	xModbus_Get_SizeAnswer( uint16_t * Size );
BOOL    	xModbus_Get_AddrAnswer( uint16_t * Addr );

void    vMBMODBUSPortRxDisable( void );
void    vMBMasterPortRecieverDMAStart(uint16_t	size);
void 	Modbus_SendCmd(uint8_t MB_SlaveAddr, uint8_t MB_Funct, uint16_t addr, uint16_t numb, uint16_t *Data, uint16_t len);

eMBMasterReqErrCode	eMBMasterSendMessage(ModbusMessage*	Message,LONG lTimeOut);
int8_t	AddToQueueMB(xQueueHandle SentQueue, uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr);
int8_t	AddToQueueMB_FS(const char* file, uint8_t* 	Data, uint16_t 		numb,uint8_t	mode, FSAfterHandler	handler, void*	parameter);

void 	QueueMB_GetPageOsc(void* parameter);

void	ReadAllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr);		// ������ ��� ���� ������
int8_t	Get_AllUstavki(xQueueHandle SentQueue, uint8_t	Slaveaddr);		// ������� ������ �� �������
int		changeAddrUstSG(int	SG);


void	ATCC_TapChg_Pos_Oper_Set(uint16_t newState, uint64_t timeStamp); // ���������� �������� 851
void	ATCC_ParOp_Pos_Oper(bool newState, uint64_t timeStamp);

void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp);
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp);


#endif /* MODBUS_H_ */
