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

#include "queue.h"
/* ----------------------- Defines ------------------------------------------*/

#define	MB_SlaveAddres							1

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

#define		MaxSizeBlok		0x7C						// �������� ��� ����� �������� � ����� ������

#define		SizeAddr		1
#define		SizeFunct		1
#define		SizeCRC			2
typedef struct					// ��� �������� ����� ������� ��������.
{
  uint8_t 	MBSlaveAddr;
  uint8_t 	MBFunct;
  uint16_t 	MBData[252];
//  uint16_t 	MBCRC;
} MBFrame;

BOOL	xModbus_Set_SizeAnswer( uint8_t Size );
BOOL	xModbus_Get_SizeAnswer( uint8_t * Size );

BOOL	Hal_setTimeFromMB_Date( uint16_t *MDateBuf );		// ������� ��������� ����� �� ������ ������
int8_t	Hal_setIPFromMB_Date( uint16_t * MDateBuf );		// ������� ��������� IP ������ �� ������ ������
int8_t	Hal_Verify_Rev( uint8_t * MDateBuf );				// ������� ��������� ������ ������� � ��������

BOOL	Hal_setConfSWFromMB_Date ( uint16_t * MDateBuf );	// ������� ��������� ������� ����������� � ������ ����� �� ������ ������

void     vMBMODBUSPortRxDisable( void );

void Modbus_SendCmd(uint8_t MB_SlaveAddr, uint8_t MB_Funct, uint16_t addr, uint16_t numb, uint16_t *Data, uint16_t len);


int8_t	AddToQueueMB(xQueueHandle SentQueue, uint16_t	MB_Rd_cmd, uint8_t	Slaveaddr);
eMBMasterReqErrCode	eMBMasterSendMessage(ModbusMessage*	Message);


void	ATCC_TapChg_Pos_Oper_Set(uint16_t newState, uint64_t timeStamp); // ���������� �������� 851
void	ATCC_ParOp_Pos_Oper(bool newState, uint64_t timeStamp);

void	CSWI_Pos_Oper_Set(bool newState, uint64_t timeStamp);
void	GGIO_LEDGGIO1_SPCSO1_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO1_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO2_Oper(bool newState, uint64_t timeStamp);
void	GGIO_SPCSO3_Oper(bool newState, uint64_t timeStamp);


#endif /* MODBUS_H_ */
