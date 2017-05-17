/*
 * MbMapMR771.h
 *
 *  Created on: 15.05.2017
 *      Author: sagok
 */

#ifndef MBMAPMR771_H_
#define MBMAPMR771_H_

#define _swREV			"MR771"

/*************************************************************************
 * MR771
 *************************************************************************/
#if defined (MR771)

#define MB_Speed				115200
#define MB_Slaveaddr   			1

// конфигурация ----------------------------------------------
#define MB_StartConfig		   	0x1000			// уставки


// конфигурация выключателя ----------------------------------------------
#define MB_StartConfigSW	   	0x28F0			// конфигурация выключателя
#define MB_Size_ConfSW			16				// 16 слов
#define MB_NumbConfigSW			16

#define	MB_rOffsetControlSW		0				// управление выключателем
#define	MB_bControlSW_Button	1<<0
#define	MB_bControlSW_Switch	1<<1
#define	MB_bControlSW_Extern	1<<2
#define	MB_bControlSW_SDTU		1<<3
#define	MB_bControlSW_CmdOFF	1<<4

#define	MB_rOffsetControlSW_ON		1			// вход положение включено
#define	MB_rOffsetControlSW_OFF		2			// вход положение вЫключено
#define	MB_rOffsetControlSW_ERROR	3			// вход неисправность выключателя

//----------------------------------------------------------------------------------------------
// Группы уставок
//----------------------------------------------------------------------------------------------
#define MB_StartUstavkiaddr0	0x1000			// группа уставок 1
#define MB_StartUstavkiaddr1	0x1428			// группа уставок 2
#define MB_StartUstavkiaddr2	0x1850			// группа уставок 3
#define MB_StartUstavkiaddr3	0x1C78			// группа уставок 4
#define MB_StartUstavkiaddr4	0x20A0			// группа уставок 5
#define MB_StartUstavkiaddr5	0x24C8			// группа уставок 6

#define MB_NumbUstavki			MB_StartUstavkiaddr1-MB_StartUstavkiaddr0			// размер блока уставок			0x1D5


// конфигурация АПВ  в группе уставок ----------------------------------------------
#define MB_StartConfigAPW	   	0x1264 - MB_StartConfig			// конфигурация АПВ
#define MB_NumbConfigAPW		10				// 10 слов

#define MB_offset_ConfAPW		0x00			// конфигурация АПВ
#define MB_offset_InBlok		0x01			// вход блокировки

#define MB_bOffset_APW_Config_Stat		0b11<<0

// конфигурация измерительного транса  в группе уставок------------------------------------------
#define MB_StartConfigTRMeas	   	0x1278 - MB_StartConfig				// конфигурация  измерительного транса
#define MB_NumbConfigTRMeas			16

#define MB_offset_Kttf			0				// Ittф
#define MB_offset_Kttn			1				// Ittn
#define MB_offset_Ktnf			8				// ТТНП
#define MB_offset_Ktnn			9				// ТТНHП

// конфигурация входных логических сигналов   в группе уставок-------------------------------------
#define MB_StartConfigVLSIn			0x1288 - MB_StartConfig
#define MB_NumbConfigVLSIn			96

// конфигурация выходных логических сигналов   в группе уставок-------------------------------------
#define MB_StartConfigVLSOut		0x12E8 - MB_StartConfig
#define MB_NumbConfigVLSOut			288

#define MB_offset_MTZ_I1		0x1004 - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_MTZ_I2		MB_offset_MTZ_I1+10
#define MB_offset_MTZ_I3		MB_offset_MTZ_I1+20
#define MB_offset_MTZ_I4		MB_offset_MTZ_I1+30
#define MB_offset_MTZ_I5		MB_offset_MTZ_I1+40
#define MB_offset_MTZ_I6		MB_offset_MTZ_I1+50
#define MB_offset_MTZ_I7		MB_offset_MTZ_I1+60

//конфигурациz ступени МТЗ защиты  I> I*>----------------------------------------------
#define MB_offset_MTZ_I_Config	0				// Конфигурация

// биты
#define MB_bOffset_MTZ_I_Config_Stat		0b11<<0						// состояние


#define MB_offset_Ig_I1		0x104A - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Ig_I2		MB_offset_Ig_I1+10
#define MB_offset_Ig_I3		MB_offset_Ig_I1+20
#define MB_offset_Ig_I4		MB_offset_Ig_I1+30
#define MB_offset_Ig_I5		MB_offset_Ig_I1+40
#define MB_offset_Ig_I6		MB_offset_Ig_I1+50
#define MB_offset_Ig_I7		MB_offset_Ig_I1+60
#define MB_offset_Ig_I8		MB_offset_Ig_I1+70

//конфигурациz ступени Ig защиты
#define MB_offset_Ig_I_Config	0				// Конфигурация
#define _bSideOffset			4				// привязка к стороне
#define _bLogicOffset			14				// логика

// биты
#define MB_bOffset_Ig_I_Config_Stat		0b11<<0						// состояние
#define MB_bOffset_Ig_I_Config_Logic	0b11<<_bLogicOffset			// логика


// конфигурация токовой защиты от обрыва провода  ----------------------------------------------
#define MB_offsetConfigI2I1	   	0x109A - MB_StartUstavkiaddr0			// конфигурация
#define MB_NumbConfigI2I1		10				// 10 слов
#define MB_offset_ConfI2I1		0x00			// конфигурация

#define MB_bOffset_I2I1_Config_Stat		0b11<<0

//----------------------------------------------------------------------------------------------
// база данных дискретных сигналов
//----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x27			// 0x22


#define MB_offset_ErrorOFF		0x14		// аварийное отключение
#define MB_bOffsetErrorOFF		1<<4		// аварийное отключение

#define MB_offset_SysNote		0x13		// Новая запись журнала системы
#define MB_bOffsetSysNote		1<<0xC		// Новая запись журнала системы

#define MB_offset_SysNote		0x13		// Новая запись журнала аварий
#define MB_bOffsetErrorNote		1<<0xD		// Новая запись журнала аварий

#define MB_offset_Jurnals		0x13		// Наличиенеисправности по журналу системы
#define MB_bOffsetError			1<<0xF		// Наличиенеисправности по журналу системы

// ---------------------------------

// --Discreet --
#define MB_offsetDiscreet_1_16	0x00
#define MB_offsetDiscreet_17_32	0x01
#define MB_offsetDiscreet_33_40	0x02

// -Relay --
#define MB_offsetRelay_1		0x10
#define MB_offsetRelay_2		0x10
#define MB_offsetRelay_3		0x10
#define MB_offsetRelay_4		0x10
#define MB_offsetRelay_5		0x10
#define MB_offsetRelay_6		0x10
#define MB_offsetRelay_7		0x10
#define MB_offsetRelay_8		0x10
#define MB_offsetRelay_9		0x10
#define MB_offsetRelay_10		0x10
#define MB_offsetRelay_11		0x10
#define MB_offsetRelay_12		0x10
#define MB_offsetRelay_13		0x10
#define MB_offsetRelay_14		0x10
#define MB_offsetRelay_15		0x10
#define MB_offsetRelay_16		0x10
#define MB_offsetRelay_17		0x11
#define MB_offsetRelay_18		0x11
#define MB_offsetRelay_19		0x11
#define MB_offsetRelay_20		0x11
#define MB_offsetRelay_21		0x11
#define MB_offsetRelay_22		0x11
#define MB_offsetRelay_23		0x11
#define MB_offsetRelay_24		0x11
#define MB_offsetRelay_25		0x11
#define MB_offsetRelay_26		0x11
#define MB_offsetRelay_27		0x11
#define MB_offsetRelay_28		0x11
#define MB_offsetRelay_29		0x11
#define MB_offsetRelay_30		0x11
#define MB_offsetRelay_31		0x11
#define MB_offsetRelay_32		0x11
#define MB_offsetRelay_33		0x12
#define MB_offsetRelay_34		0x12


#define MB_bOffset_Relay_1		1<<0
#define MB_bOffset_Relay_2		1<<1
#define MB_bOffset_Relay_3		1<<2
#define MB_bOffset_Relay_4		1<<3
#define MB_bOffset_Relay_5		1<<4
#define MB_bOffset_Relay_6		1<<5
#define MB_bOffset_Relay_7		1<<6
#define MB_bOffset_Relay_8		1<<7
#define MB_bOffset_Relay_9		1<<8
#define MB_bOffset_Relay_10		1<<9
#define MB_bOffset_Relay_11		1<<10
#define MB_bOffset_Relay_12		1<<11
#define MB_bOffset_Relay_13		1<<12
#define MB_bOffset_Relay_14		1<<13
#define MB_bOffset_Relay_15		1<<14
#define MB_bOffset_Relay_16		1<<15
#define MB_bOffset_Relay_17		1<<0
#define MB_bOffset_Relay_18		1<<1
#define MB_bOffset_Relay_19		1<<2
#define MB_bOffset_Relay_20		1<<3
#define MB_bOffset_Relay_21		1<<4
#define MB_bOffset_Relay_22		1<<5
#define MB_bOffset_Relay_23		1<<6
#define MB_bOffset_Relay_24		1<<7
#define MB_bOffset_Relay_25		1<<8
#define MB_bOffset_Relay_26		1<<9
#define MB_bOffset_Relay_27		1<<10
#define MB_bOffset_Relay_28		1<<11
#define MB_bOffset_Relay_29		1<<12
#define MB_bOffset_Relay_30		1<<13
#define MB_bOffset_Relay_31		1<<14
#define MB_bOffset_Relay_32		1<<15
#define MB_bOffset_Relay_33		1<<0
#define MB_bOffset_Relay_34		1<<1

// ---------------------------------
#define MB_offsetLED_1g			0x12
#define MB_offsetLED_2g			0x12
#define MB_offsetLED_3g			0x12
#define MB_offsetLED_4g			0x12
#define MB_offsetLED_5g			0x12
#define MB_offsetLED_6g			0x12
#define MB_offsetLED_7g			0x12
#define MB_offsetLED_8g			0x13
#define MB_offsetLED_9g			0x13
#define MB_offsetLED_10g		0x13
#define MB_offsetLED_11g		0x13
#define MB_offsetLED_12g		0x13

#define MB_offsetLED_1r			0x12
#define MB_offsetLED_2r			0x12
#define MB_offsetLED_3r			0x12
#define MB_offsetLED_4r			0x12
#define MB_offsetLED_5r			0x12
#define MB_offsetLED_6r			0x12
#define MB_offsetLED_7r			0x12
#define MB_offsetLED_8r			0x13
#define MB_offsetLED_9r			0x13
#define MB_offsetLED_10r		0x13
#define MB_offsetLED_11r		0x13
#define MB_offsetLED_12r		0x13

#define MB_bOffset_LED_1g		1<<0x2
#define MB_bOffset_LED_2g		1<<0x4
#define MB_bOffset_LED_3g		1<<0x6
#define MB_bOffset_LED_4g		1<<0x8
#define MB_bOffset_LED_5g		1<<0xA
#define MB_bOffset_LED_6g		1<<0xC
#define MB_bOffset_LED_7g		1<<0xE
#define MB_bOffset_LED_8g		1<<0x0
#define MB_bOffset_LED_9g		1<<0x2
#define MB_bOffset_LED_10g		1<<0x4
#define MB_bOffset_LED_11g		1<<0x6
#define MB_bOffset_LED_12g		1<<0x8

#define MB_bOffset_LED_1r		1<<0x3
#define MB_bOffset_LED_2r		1<<0x5
#define MB_bOffset_LED_3r		1<<0x7
#define MB_bOffset_LED_4r		1<<0x9
#define MB_bOffset_LED_5r		1<<0xB
#define MB_bOffset_LED_6r		1<<0xD
#define MB_bOffset_LED_7r		1<<0xF
#define MB_bOffset_LED_8r		1<<0x1
#define MB_bOffset_LED_9r		1<<0x3
#define MB_bOffset_LED_10r		1<<0x5
#define MB_bOffset_LED_11r		1<<0x7
#define MB_bOffset_LED_12r		1<<0x9

// SSL -------------------------------
#define MB_offsetSSL_1			0x04
#define MB_offsetSSL_2			0x04
#define MB_offsetSSL_3			0x04
#define MB_offsetSSL_4			0x04
#define MB_offsetSSL_5			0x04
#define MB_offsetSSL_6			0x04
#define MB_offsetSSL_7			0x04
#define MB_offsetSSL_8			0x04
#define MB_offsetSSL_9			0x05
#define MB_offsetSSL_10			0x05
#define MB_offsetSSL_11			0x05
#define MB_offsetSSL_12			0x05
#define MB_offsetSSL_13			0x05
#define MB_offsetSSL_14			0x05
#define MB_offsetSSL_15			0x05
#define MB_offsetSSL_16			0x05
#define MB_offsetSSL_17			0x05
#define MB_offsetSSL_18			0x05
#define MB_offsetSSL_19			0x05
#define MB_offsetSSL_20			0x05
#define MB_offsetSSL_21			0x05
#define MB_offsetSSL_22			0x05
#define MB_offsetSSL_23			0x05
#define MB_offsetSSL_24			0x05
#define MB_offsetSSL_25			0x06
#define MB_offsetSSL_26			0x06
#define MB_offsetSSL_27			0x06
#define MB_offsetSSL_28			0x06
#define MB_offsetSSL_29			0x06
#define MB_offsetSSL_30			0x06
#define MB_offsetSSL_31			0x06
#define MB_offsetSSL_32			0x06

#define MB_bOffset_SSL_1		1<<0x8
#define MB_bOffset_SSL_2		1<<0x9
#define MB_bOffset_SSL_3		1<<0xA
#define MB_bOffset_SSL_4		1<<0xB
#define MB_bOffset_SSL_5		1<<0xC
#define MB_bOffset_SSL_6		1<<0xD
#define MB_bOffset_SSL_7		1<<0xE
#define MB_bOffset_SSL_8		1<<0xF
#define MB_bOffset_SSL_9		1<<0x0
#define MB_bOffset_SSL_10		1<<0x1
#define MB_bOffset_SSL_11		1<<0x2
#define MB_bOffset_SSL_12		1<<0x3
#define MB_bOffset_SSL_13		1<<0x4
#define MB_bOffset_SSL_14		1<<0x5
#define MB_bOffset_SSL_15		1<<0x6
#define MB_bOffset_SSL_16		1<<0x7
#define MB_bOffset_SSL_17		1<<0x8
#define MB_bOffset_SSL_18		1<<0x9
#define MB_bOffset_SSL_19		1<<0xA
#define MB_bOffset_SSL_20		1<<0xB
#define MB_bOffset_SSL_21		1<<0xC
#define MB_bOffset_SSL_22		1<<0xD
#define MB_bOffset_SSL_23		1<<0xE
#define MB_bOffset_SSL_24		1<<0xF
#define MB_bOffset_SSL_25		1<<0x0
#define MB_bOffset_SSL_26		1<<0x1
#define MB_bOffset_SSL_27		1<<0x2
#define MB_bOffset_SSL_28		1<<0x3
#define MB_bOffset_SSL_29		1<<0x4
#define MB_bOffset_SSL_30		1<<0x5
#define MB_bOffset_SSL_31		1<<0x6
#define MB_bOffset_SSL_32		1<<0x7

// VLS -------------------------------
#define MB_offsetVLS_1			0x03
#define MB_offsetVLS_2			0x03
#define MB_offsetVLS_3			0x03
#define MB_offsetVLS_4			0x03
#define MB_offsetVLS_5			0x03
#define MB_offsetVLS_6			0x03
#define MB_offsetVLS_7			0x03
#define MB_offsetVLS_8			0x03
#define MB_offsetVLS_9			0x04
#define MB_offsetVLS_10			0x04
#define MB_offsetVLS_11			0x04
#define MB_offsetVLS_12			0x04
#define MB_offsetVLS_13			0x04
#define MB_offsetVLS_14			0x04
#define MB_offsetVLS_15			0x04
#define MB_offsetVLS_16			0x04


#define MB_bOffset_VLS_1		1<<8
#define MB_bOffset_VLS_2		1<<9
#define MB_bOffset_VLS_3		1<<10
#define MB_bOffset_VLS_4		1<<11
#define MB_bOffset_VLS_5		1<<12
#define MB_bOffset_VLS_6		1<<13
#define MB_bOffset_VLS_7		1<<14
#define MB_bOffset_VLS_8		1<<15
#define MB_bOffset_VLS_9		1<<0
#define MB_bOffset_VLS_10		1<<1
#define MB_bOffset_VLS_11		1<<2
#define MB_bOffset_VLS_12		1<<3
#define MB_bOffset_VLS_13		1<<4
#define MB_bOffset_VLS_14		1<<5
#define MB_bOffset_VLS_15		1<<6
#define MB_bOffset_VLS_16		1<<7

// LS -------------------------------
#define MB_offsetLS_1			0x02
#define MB_offsetLS_2			0x02
#define MB_offsetLS_3			0x02
#define MB_offsetLS_4			0x02
#define MB_offsetLS_5			0x02
#define MB_offsetLS_6			0x02
#define MB_offsetLS_7			0x02
#define MB_offsetLS_8			0x02
#define MB_offsetLS_9			0x03
#define MB_offsetLS_10			0x03
#define MB_offsetLS_11			0x03
#define MB_offsetLS_12			0x03
#define MB_offsetLS_13			0x03
#define MB_offsetLS_14			0x03
#define MB_offsetLS_15			0x03
#define MB_offsetLS_16			0x03

#define MB_bOffset_LS_1			1<<0x8
#define MB_bOffset_LS_2			1<<0x9
#define MB_bOffset_LS_3			1<<0xA
#define MB_bOffset_LS_4			1<<0xB
#define MB_bOffset_LS_5			1<<0xC
#define MB_bOffset_LS_6			1<<0xD
#define MB_bOffset_LS_7			1<<0xE
#define MB_bOffset_LS_8			1<<0xF
#define MB_bOffset_LS_9			1<<0
#define MB_bOffset_LS_10		1<<1
#define MB_bOffset_LS_11		1<<2
#define MB_bOffset_LS_12		1<<3
#define MB_bOffset_LS_13		1<<4
#define MB_bOffset_LS_14		1<<5
#define MB_bOffset_LS_15		1<<6
#define MB_bOffset_LS_16		1<<7

// ---------------------------------

//  I> --
#define MB_offset_IO_I_1		0x07
#define MB_offset_IO_I_2		0x07
#define MB_offset_IO_I_3		0x08
#define MB_offset_IO_I_4		0x08
#define MB_offset_IO_I_5		0x08
#define MB_offset_IO_I_6		0x08

#define MB_b_IO_I1		1<<0xC		// И0 I>1
#define MB_b_IO_I2		1<<0xE		// И0 I>2
#define MB_b_IO_I3		1<<0x0		// И0 I>3
#define MB_b_IO_I4		1<<0x2		// И0 I>4
#define MB_b_IO_I5		1<<0x4		// И0 I>5
#define MB_b_IO_I6		1<<0x6		// И0 I>6

#define MB_offset_SRAB_I_1		0x07
#define MB_offset_SRAB_I_2		0x07
#define MB_offset_SRAB_I_3		0x08
#define MB_offset_SRAB_I_4		0x08
#define MB_offset_SRAB_I_5		0x08
#define MB_offset_SRAB_I_6		0x08

#define MB_b_SRAB_I1		1<<0xD		// СРАБ I>1
#define MB_b_SRAB_I2		1<<0xF		// СРАБ I>2
#define MB_b_SRAB_I3		1<<0x1		// СРАБ I>3
#define MB_b_SRAB_I4		1<<0x3		// СРАБ I>4
#define MB_b_SRAB_I5		1<<0x5		// СРАБ I>5
#define MB_b_SRAB_I6		1<<0x7		// СРАБ I>6

// I*> --
#define MB_offset_IO_Ig_1		0x08
#define MB_offset_IO_Ig_2		0x08
#define MB_offset_IO_Ig_3		0x08
#define MB_offset_IO_Ig_4		0x09
#define MB_offset_IO_Ig_5		0x09
#define MB_offset_IO_Ig_6		0x09
#define MB_offset_IO_Ig_7		0x09
#define MB_offset_IO_Ig_8		0x09

#define MB_b_IO_Ig1		1<<0xA		// И0 I*>1
#define MB_b_IO_Ig2		1<<0xC		// И0 I*>2
#define MB_b_IO_Ig3		1<<0xE		// И0 I*>3
#define MB_b_IO_Ig4		1<<0x0		// И0 I*>4
#define MB_b_IO_Ig5		1<<0x2		// И0 I*>5
#define MB_b_IO_Ig6		1<<0x4		// И0 I*>6
#define MB_b_IO_Ig7		1<<0x6		// И0 I*>7
#define MB_b_IO_Ig8		1<<0x8		// И0 I*>8

#define MB_offset_SRAB_Ig_1		0x08
#define MB_offset_SRAB_Ig_2		0x08
#define MB_offset_SRAB_Ig_3		0x08
#define MB_offset_SRAB_Ig_4		0x09
#define MB_offset_SRAB_Ig_5		0x09
#define MB_offset_SRAB_Ig_6		0x09
#define MB_offset_SRAB_Ig_7		0x09
#define MB_offset_SRAB_Ig_8		0x09

#define MB_b_SRAB_Ig1		1<<0xB		// СРАБ I*>1
#define MB_b_SRAB_Ig2		1<<0xD		// СРАБ I*>2
#define MB_b_SRAB_Ig3		1<<0xF		// СРАБ I*>3
#define MB_b_SRAB_Ig4		1<<0x1		// СРАБ I*>4
#define MB_b_SRAB_Ig5		1<<0x3		// СРАБ I*>5
#define MB_b_SRAB_Ig6		1<<0x5		// СРАБ I*>6
#define MB_b_SRAB_Ig7		1<<0x7		// СРАБ I*>7
#define MB_b_SRAB_Ig8		1<<0x9		// СРАБ I*>8

#define MB_offset_IO_I2I1		0x09
#define MB_offset_SRAB_I2I1		0x09
#define MB_b_IO_I2I1			1<<0xA		// СРАБ I*>1
#define MB_b_SRAB_I2I1			1<<0xB		// СРАБ I*>2


// I --
#define MB_offset_dirPTOC_Ia		0x26		// направления мощности, ошибка направления мощности
#define MB_offset_dirPTOC_Ib		0x26
#define MB_offset_dirPTOC_Ic		0x26
#define MB_offset_dirPTOC_In		0x26
#define MB_offset_dirPTOC_I0		0x26
#define MB_offset_dirPTOC_I2		0x26

#define MB_offset_dirErrorPTOC_Ia	0x26		// направления мощности, ошибка направления мощности
#define MB_offset_dirErrorPTOC_Ib	0x26
#define MB_offset_dirErrorPTOC_Ic	0x26
#define MB_offset_dirErrorPTOC_In	0x26
#define MB_offset_dirErrorPTOC_I0	0x26
#define MB_offset_dirErrorPTOC_I2	0x26

// биты направления и достоверности мощности
#define MB_b_direction_In		1<<0xA		// направления
#define MB_b_direction_Ia		1<<0x0
#define MB_b_direction_Ib		1<<0x2
#define MB_b_direction_Ic		1<<0x4
#define MB_b_direction_I0		1<<0x6
#define MB_b_direction_I2		1<<0x8

#define MB_b_dirError_In		1<<0xB		// ошибка направления
#define MB_b_dirError_Ia		1<<0x1
#define MB_b_dirError_Ib		1<<0x3
#define MB_b_dirError_Ic		1<<0x5
#define MB_b_dirError_I0		1<<0x7
#define MB_b_dirError_I2		1<<0x9

// Z ---
#define MB_offset_dirPTOC_Za		0x26	// направления
#define MB_offset_dirPTOC_Zb		0x26
#define MB_offset_dirPTOC_Zc		0x27
#define MB_offset_dirErrorPTOC_Za	0x26	// ошибка направления
#define MB_offset_dirErrorPTOC_Zb	0x26
#define MB_offset_dirErrorPTOC_Zc	0x27

#define MB_offset_dirPTOC_Zab		0x27
#define MB_offset_dirPTOC_Zbc		0x27
#define MB_offset_dirPTOC_Zca		0x27
#define MB_offset_dirErrorPTOC_Zab	0x27
#define MB_offset_dirErrorPTOC_Zbc	0x27
#define MB_offset_dirErrorPTOC_Zca	0x27

// биты направления и достоверности Z
#define MB_b_direction_Za		1<<0xC		// направления
#define MB_b_direction_Zb		1<<0xE
#define MB_b_direction_Zc		1<<0x0
#define MB_b_dirError_Za		1<<0xD		// ошибка направления
#define MB_b_dirError_Zb		1<<0xE
#define MB_b_dirError_Zc		1<<0x1

#define MB_b_direction_Zab		1<<0x2
#define MB_b_direction_Zbc		1<<0x4
#define MB_b_direction_Zca		1<<0x6
#define MB_b_dirError_Zab		1<<0x3
#define MB_b_dirError_Zbc		1<<0x5
#define MB_b_dirError_Zca		1<<0x7


// U ---
#define MB_offset_IO_Uup_1		0x09
#define MB_offset_IO_Uup_2		0x09
#define MB_offset_IO_Uup_3		0x0A
#define MB_offset_IO_Uup_4		0x0A

#define MB_offset_SRAB_Uup_1	0x09
#define MB_offset_SRAB_Uup_2	0x0A
#define MB_offset_SRAB_Uup_3	0x0A
#define MB_offset_SRAB_Uup_4	0x0A

#define MB_offset_IO_Udn_1		0x0A
#define MB_offset_IO_Udn_2		0x0A
#define MB_offset_IO_Udn_3		0x0A
#define MB_offset_IO_Udn_4		0x0A

#define MB_offset_SRAB_Udn_1	0x0A
#define MB_offset_SRAB_Udn_2	0x0A
#define MB_offset_SRAB_Udn_3	0x0A
#define MB_offset_SRAB_Udn_4	0x0A

#define MB_b_IO_Uup1		1<<0xD		// И0 U>1
#define MB_b_IO_Uup2		1<<0xF		// И0 U>2
#define MB_b_IO_Uup3		1<<0x1		// И0 U>3
#define MB_b_IO_Uup4		1<<0x3		// И0 U>4

#define MB_b_SRAB_Uup1		1<<0xE		// СРАБ U>1
#define MB_b_SRAB_Uup2		1<<0x0		// СРАБ U>2
#define MB_b_SRAB_Uup3		1<<0x2		// СРАБ U>3
#define MB_b_SRAB_Uup4		1<<0x4		// СРАБ U>4

#define MB_b_IO_Udn1		1<<0x5		// И0 U<1
#define MB_b_IO_Udn2		1<<0x7		// И0 U<2
#define MB_b_IO_Udn3		1<<0x9		// И0 U<3
#define MB_b_IO_Udn4		1<<0xB		// И0 U<4

#define MB_b_SRAB_Udn1		1<<0x6		// СРАБ U<1
#define MB_b_SRAB_Udn2		1<<0x8		// СРАБ U<2
#define MB_b_SRAB_Udn3		1<<0xA		// СРАБ U<3
#define MB_b_SRAB_Udn4		1<<0xC		// СРАБ U<4

// F --
#define MB_offset_IO_Fup_1		0x0A
#define MB_offset_IO_Fup_2		0x0A
#define MB_offset_IO_Fup_3		0x0B
#define MB_offset_IO_Fup_4		0x0B

#define MB_offset_SRAB_Fup_1	0x0A
#define MB_offset_SRAB_Fup_2	0x0B
#define MB_offset_SRAB_Fup_3	0x0B
#define MB_offset_SRAB_Fup_4	0x0B

#define MB_offset_IO_Fdn_1		0x0B
#define MB_offset_IO_Fdn_2		0x0B
#define MB_offset_IO_Fdn_3		0x0B
#define MB_offset_IO_Fdn_4		0x0B
#define MB_offset_SRAB_Fdn_1	0x0B
#define MB_offset_SRAB_Fdn_2	0x0B
#define MB_offset_SRAB_Fdn_3	0x0B
#define MB_offset_SRAB_Fdn_4	0x0B

#define MB_b_IO_Fup1		1<<0xD		// И0 F>1
#define MB_b_IO_Fup2		1<<0xF		// И0 F>2
#define MB_b_IO_Fup3		1<<0x1		// И0 F>3
#define MB_b_IO_Fup4		1<<0x3		// И0 F>4

#define MB_b_SRAB_Fup1		1<<0xE		// СРАБ F>1
#define MB_b_SRAB_Fup2		1<<0x0		// СРАБ F>2
#define MB_b_SRAB_Fup3		1<<0x2		// СРАБ F>3
#define MB_b_SRAB_Fup4		1<<0x4		// СРАБ F>4

#define MB_b_IO_Fdn1		1<<0x5		// И0 F<1
#define MB_b_IO_Fdn2		1<<0x7		// И0 F<2
#define MB_b_IO_Fdn3		1<<0x9		// И0 F<3
#define MB_b_IO_Fdn4		1<<0xB		// И0 F<4

#define MB_b_SRAB_Fdn1		1<<0x6		// СРАБ F<1
#define MB_b_SRAB_Fdn2		1<<0x8		// СРАБ F<2
#define MB_b_SRAB_Fdn3		1<<0xA		// СРАБ F<3
#define MB_b_SRAB_Fdn4		1<<0xC		// СРАБ F<4

// внешняя
#define MB_offset_SRAB_ext_1		0x0F
#define MB_offset_SRAB_ext_2		0x0F
#define MB_offset_SRAB_ext_3		0x0F
#define MB_offset_SRAB_ext_4		0x0F
#define MB_offset_SRAB_ext_5		0x0F
#define MB_offset_SRAB_ext_6		0x0F
#define MB_offset_SRAB_ext_7		0x0F
#define MB_offset_SRAB_ext_8		0x0F
#define MB_offset_SRAB_ext_9		0x0F
#define MB_offset_SRAB_ext_10		0x0F
#define MB_offset_SRAB_ext_11		0x0F
#define MB_offset_SRAB_ext_12		0x0F
#define MB_offset_SRAB_ext_13		0x0F
#define MB_offset_SRAB_ext_14		0x0F
#define MB_offset_SRAB_ext_15		0x0F
#define MB_offset_SRAB_ext_16		0x1А

#define MB_b_SRAB_ext_1			1<<0
#define MB_b_SRAB_ext_2			1<<1
#define MB_b_SRAB_ext_3			1<<2
#define MB_b_SRAB_ext_4			1<<3
#define MB_b_SRAB_ext_5			1<<4
#define MB_b_SRAB_ext_6			1<<5
#define MB_b_SRAB_ext_7			1<<6
#define MB_b_SRAB_ext_8			1<<7
#define MB_b_SRAB_ext_9			1<<8
#define MB_b_SRAB_ext_10		1<<9
#define MB_b_SRAB_ext_11		1<<10
#define MB_b_SRAB_ext_12		1<<11
#define MB_b_SRAB_ext_13		1<<12
#define MB_b_SRAB_ext_14		1<<13
#define MB_b_SRAB_ext_15		1<<14
#define MB_b_SRAB_ext_16		1<<15

// состояние выключателя
#define MB_offset_SW_status			0x14
#define MB_b_SW_OFF					1<<1
#define MB_b_SW_ON					1<<2

// АПВ
#define MB_offset_SW_ON_APW			0x0C
#define MB_b_SW_ON_APW				1<<0x0D			// включенике выключателя по АПВ

//УРОВ
//#define MB_offset_UROV				0x0B
//#define MB_b_Rab_UROV				1<<0x0E

// Z ----
#define MB_IO_offsetZ_1			0x06
#define MB_IO_offsetZ_2			0x06
#define MB_IO_offsetZ_3			0x06
#define MB_IO_offsetZ_4			0x06
#define MB_IO_offsetZ_5			0x07
#define MB_IO_offsetZ_6			0x07
#define MB_IO_offsetZ_7			0x07
#define MB_IO_offsetZ_8			0x07
#define MB_IO_offsetZ_9			0x07
#define MB_IO_offsetZ_10		0x07


#define MB_Z1_IO				1<<8
#define MB_Z1					1<<9
#define MB_Z2_IO				1<<10
#define MB_Z2					1<<11
#define MB_Z3_IO				1<<12
#define MB_Z3					1<<13
#define MB_Z4_IO				1<<14
#define MB_Z4					1<<15
#define MB_Z5_IO				1<<0
#define MB_Z5					1<<1
#define MB_Z6_IO				1<<2
#define MB_Z6					1<<3
#define MB_Z7_IO				1<<4
#define MB_Z7					1<<5
#define MB_Z8_IO				1<<6
#define MB_Z8					1<<7
#define MB_Z9_IO				1<<8
#define MB_Z9					1<<9
#define MB_Z10_IO				1<<10
#define MB_Z10					1<<11


// ---------------------------------
#define MB_offsetHardFaults		0x16			// неисправность устройства аппаратная

#define MB_offset_errorM1		0x16
#define MB_offset_errorM2		0x16
#define MB_offset_errorM3		0x16
#define MB_offset_errorM4		0x16
#define MB_offset_errorM5		0x16

#define MB_bOffsetModule1		1<<7			// Наличие неисправности модуля 1
#define MB_bOffsetModule2		1<<8			// Наличие неисправности модуля 2
#define MB_bOffsetModule3		1<<9			// Наличие неисправности модуля 3
#define MB_bOffsetModule4		1<<10			// Наличие неисправности модуля 4 аналог
#define MB_bOffsetModule5		1<<11			// Наличие неисправности модуля 5 аналог
#define MB_bOffsetUstavki		1<<12			// Наличие неисправности уставок


// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00		// база данных аналогов
#define MB_NumbAnalog   		45			// 96 слов


#define MB_offset_Ia			0
#define MB_offset_Ib			1
#define MB_offset_Ic			2

#define MB_offset_In			6


#define MB_offset_Ua			11
#define MB_offset_Ub			12
#define MB_offset_Uc			13
#define MB_offset_Un			14
#define MB_offset_Un1			15

#define MB_offset_Uab			16
#define MB_offset_Ubc			17
#define MB_offset_Ucd			18

#define MB_offset_Hz			24		// F
#define MB_offset_TotW			26		// P 2слова
#define MB_offset_TotVAr		28		// Q 2слова
#define MB_offset_TotPF			30		// cos

// ----------------------------------------------------------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

// ----------------------------------------------------------------------------------------------
#define MB_Startaddr_SG			0x0400
#define MB_NumbSG		   		1

#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001
#define MB_selectGroupe2		0x0002
#define MB_selectGroupe3		0x0003
#define MB_selectGroupe4		0x0004
#define MB_selectGroupe5		0x0005

// ----------------------------------------------------------------------------------------------
#define MB_StartRevNaddr   		0x0500		// версия 17 слов
#define MB_NumbWordRev	   		17

// - запись в прибор -----------------------------
#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02

#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_addr_SwOFF  			0x0D08		//адрес выключеня off
#define MB_addr_SwON   			0x0D09		//адрес включеня on

#define MB_Sw   				0xFF00		//on
#define MB_CTRL_OFF				0xFF00

// Параметры автоматики -------------------------------------------------------------------------
#define MB_StartAutomat			0x294E
#define MB_NumbAutomat			0x29E8 - MB_StartAutomat + 1

// Параметры системы (они же IP адрес) -----------------------------------------------------------
#define MB_StartSystemCfg		0x2A00
#define MB_NumbSystemCfg		12
#define MB_offset_IP			4		// F


#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150

#endif

#endif /* MBMAPMR771_H_ */
