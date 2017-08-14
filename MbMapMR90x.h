/*
 * MbMapMR801.h
 *
 *  Created on: 15.05.2017
 *      Author: sagok
 */

#ifndef MBMAPMR90x_H_
#define MBMAPMR90x_H_

#if defined (MR901)
#define _swREV			"MR901"
#endif
#if defined (MR902)
#define _swREV			"MR902"
#endif
/*************************************************************************
 * MR901 MR902
 *************************************************************************/
#if defined (MR901) || defined (MR902)
#define MB_Speed				115200
#define MB_Slaveaddr   			1

#define MB_StartOtherUstavkiaddr	0x1000
#define MB_NumbOtherUstavki			0x10A8 - MB_StartOtherUstavkiaddr + 1

#define MB_offset_Config_Pris1		0x1028 - MB_StartOtherUstavkiaddr
#define MB_offset_Config_Pris2		MB_offset_Config_Pris1 + 6
#define MB_offset_Config_Pris3		MB_offset_Config_Pris2 + 6
#define MB_offset_Config_Pris4		MB_offset_Config_Pris3 + 6
#define MB_offset_Config_Pris5		MB_offset_Config_Pris4 + 6
#define MB_offset_Config_Pris6		MB_offset_Config_Pris5 + 6
#if defined (MR901)
#define MB_offset_Config_Pris7		MB_offset_Config_Pris6 + 6
#define MB_offset_Config_Pris8		MB_offset_Config_Pris7 + 6
#define MB_offset_Config_Pris9		MB_offset_Config_Pris8 + 6
#define MB_offset_Config_Pris10		MB_offset_Config_Pris9 + 6
#define MB_offset_Config_Pris11		MB_offset_Config_Pris10 + 6
#define MB_offset_Config_Pris12		MB_offset_Config_Pris11 + 6
#define MB_offset_Config_Pris13		MB_offset_Config_Pris12 + 6
#define MB_offset_Config_Pris14		MB_offset_Config_Pris13 + 6
#define MB_offset_Config_Pris15		MB_offset_Config_Pris14 + 6
#define MB_offset_Config_Pris16		MB_offset_Config_Pris15 + 6
#endif

//конфигурациz дифф защиты
#define MB_offset_Config_Pris_Stat	0				// Конфигурация дифф защиты 1 слово состояние
#define MB_offset_KTT				1

// биты
#define MB_bOffset_Config_Pris_Stat		0b011			// состояние

// конфигурация измерительного транса ------------------------------------------
#define MB_StartConfigTRMeas	   	0x109C								// конфигурация  измерительного транса
#define MB_NumbConfigTRMeas			0x10A8 - MB_StartConfigTRMeas + 1		//
#define MB_offset_KTHL				0x106E - MB_StartConfigTRMeas
#define MB_offset_KTHX				0x106F - MB_StartConfigTRMeas

#define MB_offset_ConfigTT_SH1		0x109C - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_SH2		0x10A0 - MB_StartConfigTRMeas
#define MB_offset_ConfigTT_PO		0x10A4 - MB_StartConfigTRMeas


// конфигурация входных логических сигналов -------------------------------------
#define MB_StartConfigVLSIn			0x10A8
#define MB_NumbConfigVLSIn			0x10E8 - MB_StartConfigVLSIn + 1

// конфигурация выходных логических сигналов -------------------------------------
#define MB_StartConfigVLSOut		0x10E8
#define MB_NumbConfigVLSOut			0x1208 - MB_StartConfigVLSOut + 1

// Группы уставок ----------------------------------------------------------------
#define MB_StartUstavkiaddr0	0x1208			// Основная группа уставок
#define MB_StartUstavkiaddr1	0x13DC			// Резервная группа уставок
#define MB_NumbUstavki			MB_StartUstavkiaddr1 - MB_StartUstavkiaddr0 + 1			// размер блока уставок			0x1D5

// конфигурация дифф защиты ------------------------------------------------------
#define MB_offset_DIFFZ_1		0x1208 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты
#define MB_offset_DIFFZ_2		0x1216 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты
#define MB_offset_DIFFZ_3		0x1224 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты

#define MB_offset_DIFFZ_1m		0x1232 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты
#define MB_offset_DIFFZ_2m		0x1240 - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты
#define MB_offset_DIFFZ_3m		0x124E - MB_StartUstavkiaddr0		// адрес конфигурации дифф защиты

//конфигурациz дифф защиты
#define MB_offset_DIFFZ_Config_Stat			0				// Конфигурация дифф защиты 1 слово состояние

// биты
#define MB_bOffset_DIFFZ_Config_Stat		0b11			// состояние

// конфигурация ступени МТЗ защиты -------------------------------------------------
#define MB_offset_MTZ_I1		0x125C - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_MTZ_I2		MB_offset_MTZ_I1+8
#define MB_offset_MTZ_I3		MB_offset_MTZ_I2+8
#define MB_offset_MTZ_I4		MB_offset_MTZ_I3+8
#define MB_offset_MTZ_I5		MB_offset_MTZ_I4+8
#define MB_offset_MTZ_I6		MB_offset_MTZ_I5+8
#define MB_offset_MTZ_I7		MB_offset_MTZ_I6+8
#define MB_offset_MTZ_I8		MB_offset_MTZ_I7+8

#define MB_offset_MTZ_I9		MB_offset_MTZ_I8+8
#define MB_offset_MTZ_I10		MB_offset_MTZ_I9+8
#define MB_offset_MTZ_I11		MB_offset_MTZ_I10+8
#define MB_offset_MTZ_I12		MB_offset_MTZ_I11+8
#define MB_offset_MTZ_I13		MB_offset_MTZ_I12+8
#define MB_offset_MTZ_I14		MB_offset_MTZ_I13+8
#define MB_offset_MTZ_I15		MB_offset_MTZ_I14+8
#define MB_offset_MTZ_I16		MB_offset_MTZ_I15+8
#define MB_offset_MTZ_I17		MB_offset_MTZ_I16+8
#define MB_offset_MTZ_I18		MB_offset_MTZ_I17+8
#define MB_offset_MTZ_I19		MB_offset_MTZ_I18+8
#define MB_offset_MTZ_I20		MB_offset_MTZ_I19+8
#define MB_offset_MTZ_I21		MB_offset_MTZ_I20+8
#define MB_offset_MTZ_I22		MB_offset_MTZ_I21+8
#define MB_offset_MTZ_I23		MB_offset_MTZ_I22+8
#define MB_offset_MTZ_I24		MB_offset_MTZ_I23+8
#define MB_offset_MTZ_I25		MB_offset_MTZ_I24+8
#define MB_offset_MTZ_I26		MB_offset_MTZ_I25+8
#define MB_offset_MTZ_I27		MB_offset_MTZ_I26+8
#define MB_offset_MTZ_I28		MB_offset_MTZ_I27+8
#define MB_offset_MTZ_I29		MB_offset_MTZ_I28+8
#define MB_offset_MTZ_I30		MB_offset_MTZ_I29+8
#define MB_offset_MTZ_I31		MB_offset_MTZ_I30+8
#define MB_offset_MTZ_I32		MB_offset_MTZ_I31+8

//конфигурациz ступени МТЗ защиты
#define MB_offset_MTZ_I_Config	0							// Конфигурация

// биты
#define MB_bOffset_MTZ_I_Config_Stat		0b11<<0			// состояние

// конфигурация внешние защиты -------------------------------------------------
#define MB_offset_Ext_1		0x135C - MB_StartUstavkiaddr0		// адрес конфигурации ступени МТЗ защиты
#define MB_offset_Ext_2		MB_offset_Ext_1+8
#define MB_offset_Ext_3		MB_offset_Ext_2+8
#define MB_offset_Ext_4		MB_offset_Ext_3+8
#define MB_offset_Ext_5		MB_offset_Ext_4+8
#define MB_offset_Ext_6		MB_offset_Ext_5+8
#define MB_offset_Ext_7		MB_offset_Ext_6+8
#define MB_offset_Ext_8		MB_offset_Ext_7+8
#define MB_offset_Ext_9		MB_offset_Ext_8+8
#define MB_offset_Ext_10	MB_offset_Ext_9+8
#define MB_offset_Ext_11	MB_offset_Ext_10+8
#define MB_offset_Ext_12	MB_offset_Ext_11+8
#define MB_offset_Ext_13	MB_offset_Ext_12+8
#define MB_offset_Ext_14	MB_offset_Ext_13+8
#define MB_offset_Ext_15	MB_offset_Ext_14+8
#define MB_offset_Ext_16	MB_offset_Ext_15+8

//конфигурация
#define MB_offset_Ext_Config			0			// Конфигурация
// биты
#define MB_bOffset_Ext_Config_Stat		0b11<<0		// состояние

// ----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x24			// 0x22

// ---------------------------------
#define MB_offset_SG			0x0D		// инфо по группе уставок
#define MB_bOffsetSG0			1<<0x0E		// Группа уставок основная
#define MB_bOffsetSG1			1<<0x0F		// Группа уставок резервная

//#define MB_offset_ErrorOFF		0x0D		// аварийное отключение
//#define MB_bOffsetErrorOFF		1<<0		// аварийное отключение

// ---------------------------------
#define MB_offset_Jurnals		0x10
#define MB_bOffsetSysNote		1<<5		// Новая запись журнала системы
#define MB_bOffsetErrorNote		1<<6		// Новая запись журнала аварий

#define MB_bOffsetError			1<<8		// Наличиенеисправности по журналу системы

#define MB_CTRL_OFF				0xFF00
// ---------------------------------
#define MB_offset_errorM1		0x12
#define MB_offset_errorM2		0x12
#define MB_offset_errorM3		0x12
#define MB_offset_errorM4		0x12
#define MB_offset_errorM5		0x12

#define MB_errorM1				1<<4		// 11R
#define MB_errorM2				1<<5		// 8D 8R
#define MB_errorM3				1<<6		// 16D
#define MB_errorM4				1<<7		// 16D 16R
#define MB_errorM5				1<<8		// 4I 5U

#define MB_offsetHardFaults		0x12			// неисправность устройства аппаратная
#define MB_bOffsetModule1		1<<4			// Наличие неисправности модуля 1
#define MB_bOffsetModule2		1<<5			// Наличие неисправности модуля 2
#define MB_bOffsetModule3		1<<6			// Наличие неисправности модуля 3
#define MB_bOffsetModule4		1<<7			// Наличие неисправности модуля 4 аналог только ТОК
#define MB_bOffsetModule5		1<<8			// Наличие неисправности модуля 5 аналог ТОК и НАПРЯЖЕНИЕ
#define MB_bOffsetUstavki		1<<9			// Наличие неисправности уставок

// ---------------------------------
#define MB_offsetHardFaults1	0x13			// неисправность

#define MB_bOffsetErrorSWAll	0b111100

#define MB_bOffsetErrorTT1		1<<4
#define MB_bOffsetErrorTT2		1<<5
#define MB_bOffsetErrorTT3		1<<6
#define MB_bOffsetErrorUROV1	1<<7

//#define MB_bOffsetErrorCtrl1	1<<6
//#define MB_bOffsetErrorCtrl2	1<<7

// ---------------------------------
// --Discreet --
#define MB_offsetDiscreet_1		0x0
#define MB_offsetDiscreet_2		0x0
#define MB_offsetDiscreet_3		0x0
#define MB_offsetDiscreet_4		0x0
#define MB_offsetDiscreet_5		0x0
#define MB_offsetDiscreet_6		0x0
#define MB_offsetDiscreet_7		0x0
#define MB_offsetDiscreet_8		0x0
#define MB_offsetDiscreet_9		0x0
#define MB_offsetDiscreet_10	0x0
#define MB_offsetDiscreet_11	0x0
#define MB_offsetDiscreet_12	0x0
#define MB_offsetDiscreet_13	0x0
#define MB_offsetDiscreet_14	0x0
#define MB_offsetDiscreet_15	0x0
#define MB_offsetDiscreet_16	0x0
#define MB_offsetDiscreet_17	0x1
#define MB_offsetDiscreet_18	0x1
#define MB_offsetDiscreet_19	0x1
#define MB_offsetDiscreet_20	0x1
#define MB_offsetDiscreet_21	0x1
#define MB_offsetDiscreet_22	0x1
#define MB_offsetDiscreet_23	0x1
#define MB_offsetDiscreet_24	0x1

#define MB_bOffset_Discreet_1		1<<0
#define MB_bOffset_Discreet_2		1<<1
#define MB_bOffset_Discreet_3		1<<2
#define MB_bOffset_Discreet_4		1<<3
#define MB_bOffset_Discreet_5		1<<4
#define MB_bOffset_Discreet_6		1<<5
#define MB_bOffset_Discreet_7		1<<6
#define MB_bOffset_Discreet_8		1<<7
#define MB_bOffset_Discreet_9		1<<8
#define MB_bOffset_Discreet_10		1<<9
#define MB_bOffset_Discreet_11		1<<10
#define MB_bOffset_Discreet_12		1<<11
#define MB_bOffset_Discreet_13		1<<12
#define MB_bOffset_Discreet_14		1<<13
#define MB_bOffset_Discreet_15		1<<14
#define MB_bOffset_Discreet_16		1<<15
#define MB_bOffset_Discreet_17		1<<0
#define MB_bOffset_Discreet_18		1<<1
#define MB_bOffset_Discreet_19		1<<2
#define MB_bOffset_Discreet_20		1<<3
#define MB_bOffset_Discreet_21		1<<4
#define MB_bOffset_Discreet_22		1<<5
#define MB_bOffset_Discreet_23		1<<6
#define MB_bOffset_Discreet_24		1<<7
// ---------------------------------
#define MB_offsetRelay_1		0x0E
#define MB_offsetRelay_2		0x0E
#define MB_offsetRelay_3		0x0E
#define MB_offsetRelay_4		0x0E
#define MB_offsetRelay_5		0x0E
#define MB_offsetRelay_6		0x0E
#define MB_offsetRelay_7		0x0E
#define MB_offsetRelay_8		0x0E
#define MB_offsetRelay_9		0x0E
#define MB_offsetRelay_10		0x0E
#define MB_offsetRelay_11		0x0E
#define MB_offsetRelay_12		0x0F
#define MB_offsetRelay_13		0x0F
#define MB_offsetRelay_14		0x0F
#define MB_offsetRelay_15		0x0F
#define MB_offsetRelay_16		0x0F
#define MB_offsetRelay_17		0x0F
#define MB_offsetRelay_18		0x0F

#define MB_bOffset_Relay_1		1<<5
#define MB_bOffset_Relay_2		1<<6
#define MB_bOffset_Relay_3		1<<7
#define MB_bOffset_Relay_4		1<<8
#define MB_bOffset_Relay_5		1<<9
#define MB_bOffset_Relay_6		1<<10
#define MB_bOffset_Relay_7		1<<11
#define MB_bOffset_Relay_8		1<<12
#define MB_bOffset_Relay_9		1<<13
#define MB_bOffset_Relay_10		1<<14
#define MB_bOffset_Relay_11		1<<15
#define MB_bOffset_Relay_12		1<<0
#define MB_bOffset_Relay_13		1<<1
#define MB_bOffset_Relay_14		1<<2
#define MB_bOffset_Relay_15		1<<3
#define MB_bOffset_Relay_16		1<<4
#define MB_bOffset_Relay_17		1<<5
#define MB_bOffset_Relay_18		1<<6

// ---------------------------------
#define MB_offsetLED_1			0x0F
#define MB_offsetLED_2			0x0F
#define MB_offsetLED_3			0x0F
#define MB_offsetLED_4			0x0F
#define MB_offsetLED_5			0x0F
#define MB_offsetLED_6			0x0F
#define MB_offsetLED_7			0x0F
#define MB_offsetLED_8			0x0F
#define MB_offsetLED_9			0x0F
#define MB_offsetLED_10			0x10
#define MB_offsetLED_11			0x10
#define MB_offsetLED_12			0x10
#define MB_offsetLED_13			0x10
#define MB_offsetLED_14			0x10
#define MB_offsetLED_15			0x10
#define MB_offsetLED_16			0x10


#define MB_bOffset_LED_1		1<<7
#define MB_bOffset_LED_2		1<<8
#define MB_bOffset_LED_3		1<<9
#define MB_bOffset_LED_4		1<<10
#define MB_bOffset_LED_5		1<<11
#define MB_bOffset_LED_6		1<<12
#define MB_bOffset_LED_7		1<<13
#define MB_bOffset_LED_8		1<<14
#define MB_bOffset_LED_9		1<<15
#define MB_bOffset_LED_10		1<<0
#define MB_bOffset_LED_11		1<<1
#define MB_bOffset_LED_12		1<<2
#define MB_bOffset_LED_13		1<<3
#define MB_bOffset_LED_14		1<<4
#define MB_bOffset_LED_15		1<<10
#define MB_bOffset_LED_16		1<<11

// SSL -------------------------------
#define MB_offsetSSL_1			0x09
#define MB_offsetSSL_2			0x09
#define MB_offsetSSL_3			0x09
#define MB_offsetSSL_4			0x09
#define MB_offsetSSL_5			0x09
#define MB_offsetSSL_6			0x09
#define MB_offsetSSL_7			0x09
#define MB_offsetSSL_8			0x09
#define MB_offsetSSL_9			0x09
#define MB_offsetSSL_10			0x0A
#define MB_offsetSSL_11			0x0A
#define MB_offsetSSL_12			0x0A
#define MB_offsetSSL_13			0x0A
#define MB_offsetSSL_14			0x0A
#define MB_offsetSSL_15			0x0A
#define MB_offsetSSL_16			0x0A
#define MB_offsetSSL_17			0x0A
#define MB_offsetSSL_18			0x0A
#define MB_offsetSSL_19			0x0A
#define MB_offsetSSL_20			0x0A
#define MB_offsetSSL_21			0x0A
#define MB_offsetSSL_22			0x0A
#define MB_offsetSSL_23			0x0A
#define MB_offsetSSL_24			0x0A
#define MB_offsetSSL_25			0x0A
#define MB_offsetSSL_26			0x0B
#define MB_offsetSSL_27			0x0B
#define MB_offsetSSL_28			0x0B
#define MB_offsetSSL_29			0x0B
#define MB_offsetSSL_30			0x0B
#define MB_offsetSSL_31			0x0B
#define MB_offsetSSL_32			0x0B

#define MB_bOffset_SSL_1		1<<7
#define MB_bOffset_SSL_2		1<<8
#define MB_bOffset_SSL_3		1<<9
#define MB_bOffset_SSL_4		1<<10
#define MB_bOffset_SSL_5		1<<11
#define MB_bOffset_SSL_6		1<<12
#define MB_bOffset_SSL_7		1<<13
#define MB_bOffset_SSL_8		1<<14
#define MB_bOffset_SSL_9		1<<15
#define MB_bOffset_SSL_10		1<<0
#define MB_bOffset_SSL_11		1<<1
#define MB_bOffset_SSL_12		1<<2
#define MB_bOffset_SSL_13		1<<3
#define MB_bOffset_SSL_14		1<<4
#define MB_bOffset_SSL_15		1<<5
#define MB_bOffset_SSL_16		1<<6
#define MB_bOffset_SSL_17		1<<7
#define MB_bOffset_SSL_18		1<<8
#define MB_bOffset_SSL_19		1<<9
#define MB_bOffset_SSL_20		1<<10
#define MB_bOffset_SSL_21		1<<11
#define MB_bOffset_SSL_22		1<<12
#define MB_bOffset_SSL_23		1<<13
#define MB_bOffset_SSL_24		1<<14
#define MB_bOffset_SSL_25		1<<15
#define MB_bOffset_SSL_26		1<<0
#define MB_bOffset_SSL_27		1<<1
#define MB_bOffset_SSL_28		1<<2
#define MB_bOffset_SSL_29		1<<3
#define MB_bOffset_SSL_30		1<<4
#define MB_bOffset_SSL_31		1<<5
#define MB_bOffset_SSL_32		1<<6

// VLS -------------------------------
#define MB_offsetVLS_1			0x02
#define MB_offsetVLS_2			0x02
#define MB_offsetVLS_3			0x02
#define MB_offsetVLS_4			0x02
#define MB_offsetVLS_5			0x02
#define MB_offsetVLS_6			0x02
#define MB_offsetVLS_7			0x02
#define MB_offsetVLS_8			0x02
#define MB_offsetVLS_9			0x03
#define MB_offsetVLS_10			0x03
#define MB_offsetVLS_11			0x03
#define MB_offsetVLS_12			0x03
#define MB_offsetVLS_13			0x03
#define MB_offsetVLS_14			0x03
#define MB_offsetVLS_15			0x03
#define MB_offsetVLS_16			0x03


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
#define MB_offsetLS_1			0x01
#define MB_offsetLS_2			0x01
#define MB_offsetLS_3			0x01
#define MB_offsetLS_4			0x01
#define MB_offsetLS_5			0x01
#define MB_offsetLS_6			0x01
#define MB_offsetLS_7			0x01
#define MB_offsetLS_8			0x01
#define MB_offsetLS_9			0x02
#define MB_offsetLS_10			0x02
#define MB_offsetLS_11			0x02
#define MB_offsetLS_12			0x02
#define MB_offsetLS_13			0x02
#define MB_offsetLS_14			0x02
#define MB_offsetLS_15			0x02
#define MB_offsetLS_16			0x02


#define MB_bOffset_LS_1			1<<8
#define MB_bOffset_LS_2			1<<9
#define MB_bOffset_LS_3			1<<10
#define MB_bOffset_LS_4			1<<11
#define MB_bOffset_LS_5			1<<12
#define MB_bOffset_LS_6			1<<13
#define MB_bOffset_LS_7			1<<14
#define MB_bOffset_LS_8			1<<15
#define MB_bOffset_LS_9			1<<0
#define MB_bOffset_LS_10		1<<1
#define MB_bOffset_LS_11		1<<2
#define MB_bOffset_LS_12		1<<3
#define MB_bOffset_LS_13		1<<4
#define MB_bOffset_LS_14		1<<5
#define MB_bOffset_LS_15		1<<6
#define MB_bOffset_LS_16		1<<7

// ---------------------------------

//#define MB_offsetDiscreet13		0x13
//#define MB_offsetDiscreet14		0x14
//#define MB_OffsetLogic			0x00

// ---------------------------------
#define MB_offset_IO_I_1		0x04
#define MB_offset_IO_I_2		0x04
#define MB_offset_IO_I_3		0x04
#define MB_offset_IO_I_4		0x04
#define MB_offset_IO_I_5		0x04

#define MB_offset_IO_I_6		0x05
#define MB_offset_IO_I_7		0x05
#define MB_offset_IO_I_8		0x05
#define MB_offset_IO_I_9		0x05
#define MB_offset_IO_I_10		0x05
#define MB_offset_IO_I_11		0x05
#define MB_offset_IO_I_12		0x05
#define MB_offset_IO_I_13		0x05

#define MB_offset_IO_I_14		0x06
#define MB_offset_IO_I_15		0x06
#define MB_offset_IO_I_16		0x06
#define MB_offset_IO_I_17		0x06
#define MB_offset_IO_I_18		0x06
#define MB_offset_IO_I_19		0x06
#define MB_offset_IO_I_20		0x06
#define MB_offset_IO_I_21		0x06

#define MB_offset_IO_I_22		0x07
#define MB_offset_IO_I_23		0x07
#define MB_offset_IO_I_24		0x07
#define MB_offset_IO_I_25		0x07
#define MB_offset_IO_I_26		0x07
#define MB_offset_IO_I_27		0x07
#define MB_offset_IO_I_28		0x07
#define MB_offset_IO_I_29		0x07

#define MB_offset_IO_I_30		0x08
#define MB_offset_IO_I_31		0x08
#define MB_offset_IO_I_32		0x08

#define MB_b_IO_I1		1<<7		// И0 I>1
#define MB_b_IO_I2		1<<9		// И0 I>2
#define MB_b_IO_I3		1<<11		// И0 I>3
#define MB_b_IO_I4		1<<13		// И0 I>4
#define MB_b_IO_I5		1<<15		// И0 I>5
#define MB_b_IO_I6		1<<1		// И0 I>6
#define MB_b_IO_I7		1<<3		// И0 I>7
#define MB_b_IO_I8		1<<5		// И0 I>8

#define MB_b_IO_I9		1<<7		// И0 I>9
#define MB_b_IO_I10		1<<9		// И0 I>10
#define MB_b_IO_I11		1<<11		// И0 I>11
#define MB_b_IO_I12		1<<13		// И0 I>12
#define MB_b_IO_I13		1<<15		// И0 I>13
#define MB_b_IO_I14		1<<1		// И0 I>14
#define MB_b_IO_I15		1<<3		// И0 I>15
#define MB_b_IO_I16		1<<5		// И0 I>16

#define MB_b_IO_I17		1<<7		// И0 I>17
#define MB_b_IO_I18		1<<9		// И0 I>18
#define MB_b_IO_I19		1<<11		// И0 I>19
#define MB_b_IO_I20		1<<13		// И0 I>20
#define MB_b_IO_I21		1<<15		// И0 I>21
#define MB_b_IO_I22		1<<1		// И0 I>22
#define MB_b_IO_I23		1<<3		// И0 I>23
#define MB_b_IO_I24		1<<5		// И0 I>24

#define MB_b_IO_I25		1<<7		// И0 I>25
#define MB_b_IO_I26		1<<9		// И0 I>26
#define MB_b_IO_I27		1<<11		// И0 I>27
#define MB_b_IO_I28		1<<13		// И0 I>28
#define MB_b_IO_I29		1<<15		// И0 I>29
#define MB_b_IO_I30		1<<1		// И0 I>30
#define MB_b_IO_I31		1<<3		// И0 I>31
#define MB_b_IO_I32		1<<5		// И0 I>32


#define MB_offset_SRAB_I_1		0x04
#define MB_offset_SRAB_I_2		0x04
#define MB_offset_SRAB_I_3		0x04
#define MB_offset_SRAB_I_4		0x04

#define MB_offset_SRAB_I_5		0x05
#define MB_offset_SRAB_I_6		0x05
#define MB_offset_SRAB_I_7		0x05
#define MB_offset_SRAB_I_8		0x05
#define MB_offset_SRAB_I_9		0x05
#define MB_offset_SRAB_I_10		0x05
#define MB_offset_SRAB_I_11		0x05
#define MB_offset_SRAB_I_12		0x05

#define MB_offset_SRAB_I_13		0x06
#define MB_offset_SRAB_I_14		0x06
#define MB_offset_SRAB_I_15		0x06
#define MB_offset_SRAB_I_16		0x06
#define MB_offset_SRAB_I_17		0x06
#define MB_offset_SRAB_I_18		0x06
#define MB_offset_SRAB_I_19		0x06
#define MB_offset_SRAB_I_20		0x06

#define MB_offset_SRAB_I_21		0x07
#define MB_offset_SRAB_I_22		0x07
#define MB_offset_SRAB_I_23		0x07
#define MB_offset_SRAB_I_24		0x07
#define MB_offset_SRAB_I_25		0x07
#define MB_offset_SRAB_I_26		0x07
#define MB_offset_SRAB_I_27		0x07
#define MB_offset_SRAB_I_28		0x07

#define MB_offset_SRAB_I_29		0x08
#define MB_offset_SRAB_I_30		0x08
#define MB_offset_SRAB_I_31		0x08
#define MB_offset_SRAB_I_32		0x08


#define MB_b_SRAB_I1		1<<8		// СРАБ I>1
#define MB_b_SRAB_I2		1<<10		// СРАБ I>2
#define MB_b_SRAB_I3		1<<12		// СРАБ I>3
#define MB_b_SRAB_I4		1<<14		// СРАБ I>4
#define MB_b_SRAB_I5		1<<0		// СРАБ I>5
#define MB_b_SRAB_I6		1<<2		// СРАБ I>6
#define MB_b_SRAB_I7		1<<4		// СРАБ I>7
#define MB_b_SRAB_I8		1<<6		// СРАБ I>8

#define MB_b_SRAB_I9		1<<8		// СРАБ I>9
#define MB_b_SRAB_I10		1<<10		// СРАБ I>10
#define MB_b_SRAB_I11		1<<12		// СРАБ I>11
#define MB_b_SRAB_I12		1<<14		// СРАБ I>12
#define MB_b_SRAB_I13		1<<0		// СРАБ I>13
#define MB_b_SRAB_I14		1<<2		// СРАБ I>14
#define MB_b_SRAB_I15		1<<4		// СРАБ I>15
#define MB_b_SRAB_I16		1<<6		// СРАБ I>16

#define MB_b_SRAB_I17		1<<8		// СРАБ I>17
#define MB_b_SRAB_I18		1<<10		// СРАБ I>18
#define MB_b_SRAB_I19		1<<12		// СРАБ I>19
#define MB_b_SRAB_I20		1<<14		// СРАБ I>20
#define MB_b_SRAB_I21		1<<0		// СРАБ I>21
#define MB_b_SRAB_I22		1<<2		// СРАБ I>22
#define MB_b_SRAB_I23		1<<4		// СРАБ I>23
#define MB_b_SRAB_I24		1<<6		// СРАБ I>24

#define MB_b_SRAB_I25		1<<8		// СРАБ I>25
#define MB_b_SRAB_I26		1<<10		// СРАБ I>26
#define MB_b_SRAB_I27		1<<12		// СРАБ I>27
#define MB_b_SRAB_I28		1<<14		// СРАБ I>28
#define MB_b_SRAB_I29		1<<0		// СРАБ I>29
#define MB_b_SRAB_I30		1<<2		// СРАБ I>30
#define MB_b_SRAB_I31		1<<4		// СРАБ I>31
#define MB_b_SRAB_I32		1<<6		// СРАБ I>32

// внешняя -----------------------------------------
#define MB_offset_SRAB_ext_1		0x08
#define MB_offset_SRAB_ext_2		0x08
#define MB_offset_SRAB_ext_3		0x08
#define MB_offset_SRAB_ext_4		0x08
#define MB_offset_SRAB_ext_5		0x08
#define MB_offset_SRAB_ext_6		0x08
#define MB_offset_SRAB_ext_7		0x08
#define MB_offset_SRAB_ext_8		0x08
#define MB_offset_SRAB_ext_9		0x08
#define MB_offset_SRAB_ext_10		0x09
#define MB_offset_SRAB_ext_11		0x09
#define MB_offset_SRAB_ext_12		0x09
#define MB_offset_SRAB_ext_13		0x09
#define MB_offset_SRAB_ext_14		0x09
#define MB_offset_SRAB_ext_15		0x09
#define MB_offset_SRAB_ext_16		0x09

#define MB_b_SRAB_ext_1			1<<7
#define MB_b_SRAB_ext_2			1<<8
#define MB_b_SRAB_ext_3			1<<9
#define MB_b_SRAB_ext_4			1<<10
#define MB_b_SRAB_ext_5			1<<11
#define MB_b_SRAB_ext_6			1<<12
#define MB_b_SRAB_ext_7			1<<13
#define MB_b_SRAB_ext_8			1<<14
#define MB_b_SRAB_ext_9			1<<15
#define MB_b_SRAB_ext_10		1<<0
#define MB_b_SRAB_ext_11		1<<1
#define MB_b_SRAB_ext_12		1<<2
#define MB_b_SRAB_ext_13		1<<3
#define MB_b_SRAB_ext_14		1<<4
#define MB_b_SRAB_ext_15		1<<5
#define MB_b_SRAB_ext_16		1<<6

// дифф -----------------------------------------
#define MB_offset_IO_I_d1		0x03
#define MB_offset_IO_I_d2		0x04
#define MB_offset_IO_I_d3		0x04
#define MB_offset_SRAB_I_d1		0x04
#define MB_offset_SRAB_I_d2		0x04
#define MB_offset_SRAB_I_d3		0x04

#define MB_offset_SRAB_I_d1m	0x03
#define MB_offset_SRAB_I_d2m	0x03
#define MB_offset_SRAB_I_d3m	0x03

#define MB_b_IO_I_d1			1<<0x0E
#define MB_b_IO_I_d2			1<<1
#define MB_b_IO_I_d3			1<<4

#define MB_b_SRAB_I_d1			1<<0
#define MB_b_SRAB_I_d2			1<<3
#define MB_b_SRAB_I_d3			1<<6

#define MB_b_SRAB_I_d1m			1<<9
#define MB_b_SRAB_I_d2m			1<<11
#define MB_b_SRAB_I_d3m			1<<13

//УРОВ -----------------------------------------
#define MB_offset_UROV_SH1		0x0B
#define MB_offset_UROV_SH2		0x0B
#define MB_offset_UROV_PO		0x0B
#define MB_offset_UROV_1		0x0B
#define MB_offset_UROV_2		0x0B
#define MB_offset_UROV_3		0x0B
#define MB_offset_UROV_4		0x0B
#define MB_offset_UROV_5		0x0B
#define MB_offset_UROV_6		0x0B
#define MB_offset_UROV_7		0x0C
#define MB_offset_UROV_8		0x0C
#define MB_offset_UROV_9		0x0C
#define MB_offset_UROV_10		0x0C
#define MB_offset_UROV_11		0x0C
#define MB_offset_UROV_12		0x0C
#define MB_offset_UROV_13		0x0C
#define MB_offset_UROV_14		0x0C
#define MB_offset_UROV_15		0x0C
#define MB_offset_UROV_16		0x0C

// 902
#define MB_offset_UROV_PRIn		MB_offset_UROV_6

#define MB_b_UROV_SH1		1<<7
#define MB_b_UROV_SH2		1<<8
#define MB_b_UROV_PO		1<<9
#define MB_b_UROV_1			1<<10
#define MB_b_UROV_2			1<<11
#define MB_b_UROV_3			1<<12
#define MB_b_UROV_4			1<<13
#define MB_b_UROV_5			1<<14
#define MB_b_UROV_6			1<<15
#define MB_b_UROV_7			1<<0
#define MB_b_UROV_8			1<<1
#define MB_b_UROV_9			1<<2
#define MB_b_UROV_10		1<<3
#define MB_b_UROV_11		1<<4
#define MB_b_UROV_12		1<<5
#define MB_b_UROV_13		1<<6
#define MB_b_UROV_14		1<<6
#define MB_b_UROV_15		1<<6
#define MB_b_UROV_16		1<<6

#define MB_b_UROV_PRIn		MB_b_UROV_6
// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00		// база данных аналогов
// размр разный 901 или 902
#if defined (MR901)
#define MB_NumbAnalog   		22			//

#define MB_offset_I1			0
#define MB_offset_I2			1
#define MB_offset_I3			2
#define MB_offset_I4			3
#define MB_offset_I5			4
#define MB_offset_I6			5
#define MB_offset_I7			6
#define MB_offset_I8			7
#define MB_offset_I9			8
#define MB_offset_I10			9
#define MB_offset_I11			10
#define MB_offset_I12			11
#define MB_offset_I13			12
#define MB_offset_I14			13
#define MB_offset_I15			14
#define MB_offset_I16			15

#define MB_offset_Id1			16
#define MB_offset_Id2			17
#define MB_offset_Id3			18

#define MB_offset_It1			19
#define MB_offset_It2			20
#define MB_offset_It3			21
#endif

#if defined (MR902)
#define MB_NumbAnalog   		34			// 51 слов


#define MB_offset_I1a			0
#define MB_offset_I1b			1
#define MB_offset_I1c			2

#define MB_offset_I2a			3
#define MB_offset_I2b			4
#define MB_offset_I2c			5

#define MB_offset_I3a			6
#define MB_offset_I3b			7
#define MB_offset_I3c			8

#define MB_offset_I4a			9
#define MB_offset_I4b			10
#define MB_offset_I4c			11

#define MB_offset_I5a			12
#define MB_offset_I5b			13
#define MB_offset_I5c			14

#define MB_offset_In			15

#define MB_offset_Id1a			16
#define MB_offset_Id2a			17
#define MB_offset_Id3a			18

#define MB_offset_It1a			19
#define MB_offset_It2a			20
#define MB_offset_It3a			21

#define MB_offset_Id1b			22
#define MB_offset_Id2b			23
#define MB_offset_Id3b			24

#define MB_offset_It1b			25
#define MB_offset_It2b			26
#define MB_offset_It3b			27

#define MB_offset_Id1c			28
#define MB_offset_Id2c			29
#define MB_offset_Id3c			30

#define MB_offset_It1c			31
#define MB_offset_It2c			32
#define MB_offset_It3c			33

#endif
// ----------------------------------------------------------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

// ----------------------------------------------------------------------------------------------
#define MB_StartRevNaddr   		0x0500		// версия 17 слов
#define MB_NumbWordRev	   		16			//

#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02

#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_addr_SGroupe0		0x0D06
#define MB_addr_SGroupe1		0x0D07

#define MB_CTRL_OFF				0xFF00

// Параметры автоматики -------------------------------------------------------------------------
#define MB_StartAutomat			0x15B0
#define MB_NumbAutomat			0x1612 - MB_StartAutomat + 1

// Параметры системы (они же IP адрес) -----------------------------------------------------------
#define MB_StartSystemCfg		0x1612
#define MB_NumbSystemCfg		10
#define MB_offset_IP			4		// F


#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150

#endif


#endif /* MBMAPMR90x_H_ */
