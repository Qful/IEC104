/*
 * MbMapMRMR5PO70.h
 *
 *  Created on: 07.06.2017
 *      Author: sagok
 */

#ifndef MBMAPMR5PO60_H_
#define MBMAPMR5PO60_H_

#if defined (MR5_600)
#define _swREV			"MR5 PO60"
#endif

/*************************************************************************
 * MR5PO60
 *************************************************************************/
#if defined (MR5_600)

// константы.
#define range_maxIphs				40		// диапазон токов по фазам
#define range_minIphs				0
#define range_maxI0					40
#define range_minI0					0
#define range_maxIn					5
#define range_minIn					0

#define range_maxU					256
#define range_minU					0

#define range_maxF					60
#define range_minF					40

#define range_maxCosF				1
#define range_minCosF				0




//Modbus  MR5-ПО70
#define MB_Speed					115200
#define MB_Slaveaddr   				1

// --------------------------------------------------------
// Журналы
// читать только по 8
// --------------------------------------------------------
#define MB_StartSysNoteaddr   		0x2000
#define MB_NumbSysNote	   			8
#define MB_NumbSysNoteASCII			8
#define MB_SizeSysNote	   			128			// число записей в журнале

#define MB_offset_Word				0
#define MB_offset_ASCII				8			// не использовать, в будущем уберут

#define MB_StartErrorNoteaddr  		0x2800
#define MB_NumbErrorNote			28			// число слов в одной аварии
#define MB_NumbErrorNoteASCII		48			//
#define MB_NextErrorNote			0x40		// приращение по журналу

#define MB_NumbErrorNoteTime		8			// число слов времени события
#define MB_SizeErrorNote	   		32			// число записей в журнале

// --------------------------------------------------------
// Общая группа уставок
// --------------------------------------------------------
#define MB_StartConfig		   		0x1000
#define MB_NumbUstavki				0x1020 - MB_StartConfig + 1

#define MB_offset_BlockSDTU			0x1018 - MB_StartConfig

#define MB_offset_ControlBits		0x3B
#define MB_bOffset_ControlButtons	1<<0			// управление от кнопок
#define MB_bOffset_ControlKey		1<<1			// управление от ключа
#define MB_bOffset_ControlExt		1<<2			// внешнее управление
#define MB_bOffset_ControlSDTU		1<<3			// управление от СДТУ

// первичный ток ТТ ---------------------------------------
//#define MB_offset_Itt			0x1001 - MB_StartConfig			//нет в 600
// первичный ток ТТНП -------------------------------------
//#define MB_offset_Ittnp			0x1002 - MB_StartConfig		//нет в 600
// коэффициент ТН -----------------------------------------
#define MB_offset_Ktn			0x1001 - MB_StartConfig
// коэффициент ТННП ---------------------------------------
#define MB_offset_Ktnnp			0x1004 - MB_StartConfig

// конфигурация ОМП ---------------------------------------
//#define MB_StartConfig_OMP			0x100D - MB_StartConfig
//конфигурация
//#define MB_offset_OMP_Config		0
//Удельное индуктивное сопротивление линии
//#define MB_offset_OMP_Rline			1
// биты
//#define MB_bOffset_OMP_Config_Stat	0b00001111

// конфигурация выключателя -------------------------------------
//#define MB_StartConfigSW	   	0x1032			// конфигурация выключателя
//#define MB_NumbConfigSW			0x103C - MB_StartConfigSW + 1

//#define	MB_rOffsetControlSW		0				// управление выключателем

//#define MB_offset_ConfigSW		0x103B - MB_StartConfigSW
//#define	MB_bControlSW_Button	1<<0
//#define	MB_bControlSW_Switch	1<<1
//#define	MB_bControlSW_Extern	1<<2
//#define	MB_bControlSW_SDTU		1<<3

//#define	MB_rOffsetControlSW_ON		0			// вход положение включено
//#define	MB_rOffsetControlSW_OFF		1			// вход положение вЫключено
//#define	MB_rOffsetControlSW_ERROR	2			// вход неисправность выключателя


// конфигурация автоматики --------------------------------------
//#define MB_StartAutomat			0x103C
//#define MB_NumbAutomat			0x1050 - MB_StartAutomat + 1

// конфигурация АПВ ----------------------------------------------
//#define MB_offset_ConfAPW		0x103C - MB_StartAutomat
//#define MB_offset_InBlok		0x01			// вход блокировки

//#define MB_bOffset_APW_Config_Stat		0b111

// конфигурация АВР + ЛЗШ ------------------------------------------
//#define MB_offset_ConfAWR		0x1044 - MB_StartAutomat
// конфигурация ЛЗШ
//#define MB_offset_ConfLZSHAWR	0x104E - MB_StartAutomat

//#define MB_bOffset_AWR_Config_Stat		0b1111
//#define MB_bOffset_LZSH_Config_Stat		0b11	// биты: 0-схема1, 1-схема2


// конфигурация внешних защит -----------------------------------
#define MB_StartConfigExZ_SG0	0x1020
#define MB_NumbConfigExZ		0x1050 - MB_StartConfigExZ_SG0 + 1
#define MB_StartConfigExZ_SG1	0x1050

// внешние
#define MB_offset_Ext_1		0x1020 - MB_StartConfigExZ_SG0
#define MB_offset_Ext_2		MB_offset_Ext_1+6
#define MB_offset_Ext_3		MB_offset_Ext_2+6
#define MB_offset_Ext_4		MB_offset_Ext_3+6
#define MB_offset_Ext_5		MB_offset_Ext_4+6
#define MB_offset_Ext_6		MB_offset_Ext_5+6
#define MB_offset_Ext_7		MB_offset_Ext_6+6
#define MB_offset_Ext_8		MB_offset_Ext_7+6

//конфигурация
#define MB_offset_Ext_Config		0
// биты
#define MB_bOffset_Ext_Config_Stat		0b1111<<0			// состояние

// защиты по частоте ----------------------------------------------
#define MB_StartConfigF_SG0  		0x1180
#define MB_StartConfigF_SG1  		0x11C0
#define MB_NumbConfigF				MB_StartConfigF_SG1 - MB_StartConfigF_SG0 + 1

// -------------------------------
#define MB_offset_Fup				0x1180 - MB_StartConfigF_SG0
#define MB_offset_Fup2				MB_offset_Fup+6
#define MB_offset_Fup3				MB_offset_Fup2+6
#define MB_offset_Fup4				MB_offset_Fup3+6

// -------------------------------
#define MB_offset_Fdn				0x11A0 - MB_StartConfigF_SG0
#define MB_offset_Fdn2				MB_offset_Fdn+6
#define MB_offset_Fdn3				MB_offset_Fdn2+6
#define MB_offset_Fdn4				MB_offset_Fdn3+6

// Конфигурация
#define MB_offset_Fup_Config		0
#define MB_offset_Fdn_Config		0
// биты
#define MB_bOffset_Fup_Config_Stat	0b11
#define MB_bOffset_Fdn_Config_Stat	0b11

// защиты по напряжению -------------------------------------------
#define MB_StartConfigU_SG0  		0x1080
#define MB_StartConfigU_SG1  		0x1100
#define MB_NumbConfigU				MB_StartConfigU_SG1 - MB_StartConfigU_SG0 + 1

// -------------------------------
#define MB_offset_Uup				0x1080 - MB_StartConfigU_SG0
#define MB_offset_Uup2				MB_offset_Uup+6
#define MB_offset_Uup3				MB_offset_Uup2+6
#define MB_offset_Uup4				MB_offset_Uup3+6
// -------------------------------
#define MB_offset_Udn				0x10A0 - MB_StartConfigU_SG0
#define MB_offset_Udn2				MB_offset_Udn+6
#define MB_offset_Udn3				MB_offset_Udn2+6
#define MB_offset_Udn4				MB_offset_Udn3+6
// -------------------------------
#define MB_offset_U1dn				0x10F0 - MB_StartConfigU_SG0
#define MB_offset_U1dn2				MB_offset_U1dn+6
// -------------------------------
#define MB_offset_U2up				0x10E0 - MB_StartConfigU_SG0
#define MB_offset_U2up2				MB_offset_U2up+6
// -------------------------------
#define MB_offset_U0up				0x10C0 - MB_StartConfigU_SG0
#define MB_offset_U0up2				MB_offset_U0up+6
#define MB_offset_U0up3				MB_offset_U0up2+6
#define MB_offset_U0up4				MB_offset_U0up3+6

// Конфигурация
#define MB_offset_Uup_U_Config		0
#define MB_offset_Udn_U_Config		0
// биты
#define MB_bOffset_Uup_U_Config_Stat	0b11
#define MB_bOffset_Udn_U_Config_Stat	0b11


// Параметры системы (они же IP адрес) ----------------------------
#define MB_StartSystemCfg			0x1277			//1277
#define MB_NumbSystemCfg			2
#define MB_offset_IP				0//2

// Выходные сигналы -----------------------------------------------
#define MB_StartConfigOut	   	0x1200
#define MB_NumbConfigOut		0x1274-MB_StartConfigOut + 1

// -----------------------------------
#define MB_StartDiscreetaddr   	0x1800			// адрес и размер для комманд чтения (3,4)
#define MB_NumbDiscreet   		0x1B			// перечисления в словах а ответ в байтах

#define MB_offset_adr0			0x00
#define MB_offset_SG			0x00

#define MB_bOffsetSettingGr		1<<3
#define MB_bOffsetError			1<<5
#define MB_bOffsetSysNote		1<<6
#define MB_bOffsetErrorNote		1<<7

// ---------------------------------
#define MB_offsetError_M1		0x05		// неисправность
#define MB_offsetError_M2		0x05		// неисправность
#define MB_offsetError_M3		0x05		// неисправность
#define MB_offsetError_Ustavki	0x05		// неисправность
#define MB_offsetError_Jurnals	0x05		// неисправность

#define MB_bOffsetErrModule1	0b1<<4		// Наличие неисправности модуля MCA
#define MB_bOffsetErrModule1a	0b1<<4		// Наличие неисправности модуля МСAU

#define MB_bOffsetErrModule2	0b11<<5		// Наличие неисправности модуля МРВ
#define MB_bOffsetErrModule2a	0b1<<5		// Наличие неисправности модуля МРВ1
#define MB_bOffsetErrModule2b	0b1<<6		// Наличие неисправности модуля МРВ2

#define MB_bOffsetErrModule3	0b1<<7		// Наличие неисправности модуля MCД
#define MB_bOffsetErrModule3a	0b1<<7		// Наличие неисправности модуля МСД1


#define MB_bOffsetErrUstavki	1<<8		// Наличие неисправности уставок
#define MB_bOffsetErrSysNote	1<<0xB		// Наличиенеисправности по журналу системы

// ---------------------------------
#define MB_offset_ErrorSDTU			0x00
#define MB_bOffsetErrorSDTU			1<<5	// Наличие неисправности СДТУ
// ---------------------------------
#define MB_offset_NewJurnalMs		0x00
#define MB_bOffsetNewJurnalMs		1<<6	// новая запись ЖС
// ---------------------------------
#define MB_offset_NewMsJurnalError	0x00
#define MB_bOffsetNewMsJurnalError	1<<7	// новая запись ЖА
// ---------------------------------
#define MB_offset_AllLEDs			0x02
#define MB_bOffsetLedsStats			0b111111110000

// неисправность выключателя -------
#define MB_offsetHardFaults1	0x06			// неисправность выключателя

#define MB_bOffsetErrorSWAll	0b111
#define MB_bOffsetErrorSWExt1	1<<0
#define MB_bOffsetErrorBKExt1	1<<1
#define MB_bOffsetErrorSWctrl1	1<<2

// Аварийное отключение ------------
#define MB_offset_ErrorOFF		0x08
#define MB_bOffsetErrorOFF		1<<3

// ------------------------------
#define MB_offsetHardFaults		0x05
#define MB_bOffsetUstavki		1<<8

// --Discreet --
#define MB_offsetDiscreet_1		0x08
#define MB_offsetDiscreet_2		0x08
#define MB_offsetDiscreet_3		0x08
#define MB_offsetDiscreet_4		0x08
#define MB_offsetDiscreet_5		0x08
#define MB_offsetDiscreet_6		0x08
#define MB_offsetDiscreet_7		0x08
#define MB_offsetDiscreet_8		0x08


#define MB_bOffset_Discreet_1		1<<8
#define MB_bOffset_Discreet_2		1<<9
#define MB_bOffset_Discreet_3		1<<10
#define MB_bOffset_Discreet_4		1<<11
#define MB_bOffset_Discreet_5		1<<12
#define MB_bOffset_Discreet_6		1<<13
#define MB_bOffset_Discreet_7		1<<14
#define MB_bOffset_Discreet_8		1<<15

// -Relay --
#define MB_offsetRelay_1		0x03
#define MB_offsetRelay_2		0x03
#define MB_offsetRelay_3		0x03
#define MB_offsetRelay_4		0x03
#define MB_offsetRelay_5		0x03
#define MB_offsetRelay_6		0x03
#define MB_offsetRelay_7		0x03
#define MB_offsetRelay_8		0x03
#define MB_offsetRelay_9		0x03
#define MB_offsetRelay_10		0x03
#define MB_offsetRelay_11		0x03
#define MB_offsetRelay_12		0x03
#define MB_offsetRelay_13		0x03
#define MB_offsetRelay_14		0x03
#define MB_offsetRelay_15		0x03
#define MB_offsetRelay_16		0x03

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

// ---------------------------------
#define MB_offsetLED_1			0x02
#define MB_offsetLED_2			0x02
#define MB_offsetLED_3			0x02
#define MB_offsetLED_4			0x02
#define MB_offsetLED_5			0x02
#define MB_offsetLED_6			0x02
#define MB_offsetLED_7			0x02
#define MB_offsetLED_8			0x02
#define MB_offsetLED_9			0x02
#define MB_offsetLED_10			0x02
#define MB_offsetLED_11			0x02
#define MB_offsetLED_12			0x02

#define MB_bOffset_LED_1		1<<8
#define MB_bOffset_LED_2		1<<9
#define MB_bOffset_LED_3		1<<10
#define MB_bOffset_LED_4		1<<11
#define MB_bOffset_LED_5		1<<12
#define MB_bOffset_LED_6		1<<13
#define MB_bOffset_LED_7		1<<14
#define MB_bOffset_LED_8		1<<15
#define MB_bOffset_LED_9		1<<5
#define MB_bOffset_LED_10		1<<4
#define MB_bOffset_LED_11		1<<7
#define MB_bOffset_LED_12		1<<6

// SSL -------------------------------
#define MB_offsetSSL_1			0x0D
#define MB_offsetSSL_2			0x0D
#define MB_offsetSSL_3			0x0D
#define MB_offsetSSL_4			0x0D
#define MB_offsetSSL_5			0x0D
#define MB_offsetSSL_6			0x0D
#define MB_offsetSSL_7			0x0D
#define MB_offsetSSL_8			0x0D
#define MB_offsetSSL_9			0x0E
#define MB_offsetSSL_10			0x0E
#define MB_offsetSSL_11			0x0E
#define MB_offsetSSL_12			0x0E
#define MB_offsetSSL_13			0x0E
#define MB_offsetSSL_14			0x0E
#define MB_offsetSSL_15			0x0E
#define MB_offsetSSL_16			0x0E
#define MB_offsetSSL_17			0x0E
#define MB_offsetSSL_18			0x0E
#define MB_offsetSSL_19			0x0E
#define MB_offsetSSL_20			0x0E
#define MB_offsetSSL_21			0x0E
#define MB_offsetSSL_22			0x0E
#define MB_offsetSSL_23			0x0E
#define MB_offsetSSL_24			0x0E

#define MB_bOffset_SSL_1		1<<8
#define MB_bOffset_SSL_2		1<<9
#define MB_bOffset_SSL_3		1<<10
#define MB_bOffset_SSL_4		1<<11
#define MB_bOffset_SSL_5		1<<12
#define MB_bOffset_SSL_6		1<<13
#define MB_bOffset_SSL_7		1<<14
#define MB_bOffset_SSL_8		1<<15
#define MB_bOffset_SSL_9		1<<0
#define MB_bOffset_SSL_10		1<<1
#define MB_bOffset_SSL_11		1<<2
#define MB_bOffset_SSL_12		1<<3
#define MB_bOffset_SSL_13		1<<4
#define MB_bOffset_SSL_14		1<<5
#define MB_bOffset_SSL_15		1<<6
#define MB_bOffset_SSL_16		1<<7
#define MB_bOffset_SSL_17		1<<8
#define MB_bOffset_SSL_18		1<<9
#define MB_bOffset_SSL_19		1<<10
#define MB_bOffset_SSL_20		1<<11
#define MB_bOffset_SSL_21		1<<12
#define MB_bOffset_SSL_22		1<<13
#define MB_bOffset_SSL_23		1<<14
#define MB_bOffset_SSL_24		1<<15

// VLS -------------------------------
#define MB_offsetVLS_1			0x09
#define MB_offsetVLS_2			0x09
#define MB_offsetVLS_3			0x09
#define MB_offsetVLS_4			0x09
#define MB_offsetVLS_5			0x09
#define MB_offsetVLS_6			0x09
#define MB_offsetVLS_7			0x09
#define MB_offsetVLS_8			0x09

#define MB_bOffset_VLS_1		1<<8
#define MB_bOffset_VLS_2		1<<9
#define MB_bOffset_VLS_3		1<<10
#define MB_bOffset_VLS_4		1<<11
#define MB_bOffset_VLS_5		1<<12
#define MB_bOffset_VLS_6		1<<13
#define MB_bOffset_VLS_7		1<<14
#define MB_bOffset_VLS_8		1<<15

// LS -------------------------------
#define MB_offsetLS_1			0x09
#define MB_offsetLS_2			0x09
#define MB_offsetLS_3			0x09
#define MB_offsetLS_4			0x09
#define MB_offsetLS_5			0x09
#define MB_offsetLS_6			0x09
#define MB_offsetLS_7			0x09
#define MB_offsetLS_8			0x09

#define MB_bOffset_LS_1			1<<0
#define MB_bOffset_LS_2			1<<1
#define MB_bOffset_LS_3			1<<2
#define MB_bOffset_LS_4			1<<3
#define MB_bOffset_LS_5			1<<4
#define MB_bOffset_LS_6			1<<5
#define MB_bOffset_LS_7			1<<6
#define MB_bOffset_LS_8			1<<7

// U -------------------------------
#define MB_offset_IO_Uup		0x0A
#define MB_offset_IO_Uup2		0x0A
#define MB_offset_IO_Uup3		0x0A
#define MB_offset_IO_Uup4		0x0A
#define MB_offset_SRAB_Uup		0x0A
#define MB_offset_SRAB_Uup2		0x0A
#define MB_offset_SRAB_Uup3		0x0A
#define MB_offset_SRAB_Uup4		0x0A

#define MB_offset_IO_Udn		0x0A
#define MB_offset_IO_Udn2		0x0A
#define MB_offset_IO_Udn3		0x0A
#define MB_offset_IO_Udn4		0x0A
#define MB_offset_SRAB_Udn		0x0A
#define MB_offset_SRAB_Udn2		0x0A
#define MB_offset_SRAB_Udn3		0x0A
#define MB_offset_SRAB_Udn4		0x0A

#define MB_b_IO_Uup				1<<0		// И0 U>
#define MB_b_IO_Uup2			1<<2		// И0 U>>
#define MB_b_IO_Uup3			1<<4		// И0 U>>>
#define MB_b_IO_Uup4			1<<6		// И0 U>>>>
#define MB_b_SRAB_Uup			1<<1		// СРАБ U>
#define MB_b_SRAB_Uup2			1<<3		// СРАБ U>>
#define MB_b_SRAB_Uup3			1<<5		// СРАБ U>>>
#define MB_b_SRAB_Uup4			1<<7		// СРАБ U>>>>

#define MB_b_IO_Udn				1<<8		// И0 U<
#define MB_b_IO_Udn2			1<<10		// И0 U<<
#define MB_b_IO_Udn3			1<<12		// И0 U<<<
#define MB_b_IO_Udn4			1<<14		// И0 U<<<<

#define MB_b_SRAB_Udn			1<<9		// СРАБ U<
#define MB_b_SRAB_Udn2			1<<11		// СРАБ U<<
#define MB_b_SRAB_Udn3			1<<13		// СРАБ U<<<
#define MB_b_SRAB_Udn4			1<<15		// СРАБ U<<<<

// U2 -------------------------------
#define MB_offset_IO_U2up		0x0B
#define MB_offset_IO_U2up2		0x0B
#define MB_offset_SRAB_U2up		0x0B
#define MB_offset_SRAB_U2up2	0x0B

#define MB_b_IO_U2up			1<<8		// И0 U>
#define MB_b_IO_U2up2			1<<10		// И0 U>>
#define MB_b_SRAB_U2up			1<<9		// СРАБ U>
#define MB_b_SRAB_U2up2			1<<11		// СРАБ U>>

// U0 -------------------------------
#define MB_offset_IO_U0up		0x0B
#define MB_offset_IO_U0up2		0x0B
#define MB_offset_IO_U0up3		0x0B
#define MB_offset_IO_U0up4		0x0B
#define MB_offset_SRAB_U0up		0x0B
#define MB_offset_SRAB_U0up2	0x0B
#define MB_offset_SRAB_U0up3	0x0B
#define MB_offset_SRAB_U0up4	0x0B

#define MB_b_IO_U0up			1<<0		// И0 U>
#define MB_b_IO_U0up2			1<<2		// И0 U>>
#define MB_b_IO_U0up3			1<<4		// И0 U>>>
#define MB_b_IO_U0up4			1<<6		// И0 U>>>>

#define MB_b_SRAB_U0up			1<<1		// СРАБ U>
#define MB_b_SRAB_U0up2			1<<3		// СРАБ U>>
#define MB_b_SRAB_U0up3			1<<5		// СРАБ U>>>
#define MB_b_SRAB_U0up4			1<<7		// СРАБ U>>>>

// U1 -------------------------------
#define MB_offset_IO_U1dn		0x0B
#define MB_offset_IO_U1dn2		0x0B
#define MB_offset_SRAB_U1dn		0x0B
#define MB_offset_SRAB_U1dn2	0x0B

#define MB_b_IO_U1dn			1<<12		// И0 U<
#define MB_b_IO_U1dn2			1<<14		// И0 U<<
#define MB_b_SRAB_U1dn			1<<13		// СРАБ U<
#define MB_b_SRAB_U1dn2			1<<15		// СРАБ U<<

// F -------------------------------
#define MB_offset_IO_Fup		0x0C
#define MB_offset_IO_Fup2		0x0C
#define MB_offset_IO_Fup3		0x0C
#define MB_offset_IO_Fup4		0x0C

#define MB_offset_SRAB_Fup		0x0C
#define MB_offset_SRAB_Fup2		0x0C
#define MB_offset_SRAB_Fup3		0x0C
#define MB_offset_SRAB_Fup4		0x0C

#define MB_offset_IO_Fdn		0x0C
#define MB_offset_IO_Fdn2		0x0C
#define MB_offset_IO_Fdn3		0x0C
#define MB_offset_IO_Fdn4		0x0C
#define MB_offset_SRAB_Fdn		0x0C
#define MB_offset_SRAB_Fdn2		0x0C
#define MB_offset_SRAB_Fdn3		0x0C
#define MB_offset_SRAB_Fdn4		0x0C

#define MB_b_IO_Fup				1<<0		// И0 F>
#define MB_b_IO_Fup2			1<<2		// И0 F>>
#define MB_b_IO_Fup3			1<<4		// И0 F>>>
#define MB_b_IO_Fup4			1<<6		// И0 F>>>>

#define MB_b_SRAB_Fup			1<<1		// СРАБ F>
#define MB_b_SRAB_Fup2			1<<3		// СРАБ F>>
#define MB_b_SRAB_Fup3			1<<5		// СРАБ F>>>
#define MB_b_SRAB_Fup4			1<<7		// СРАБ F>>>>

#define MB_b_IO_Fdn				1<<8		// И0 F<
#define MB_b_IO_Fdn2			1<<10		// И0 F<<
#define MB_b_IO_Fdn3			1<<12		// И0 F<<<
#define MB_b_IO_Fdn4			1<<14		// И0 F<<<<

#define MB_b_SRAB_Fdn			1<<9		// СРАБ F<
#define MB_b_SRAB_Fdn2			1<<11		// СРАБ F<<
#define MB_b_SRAB_Fdn3			1<<13		// СРАБ F<<<
#define MB_b_SRAB_Fdn4			1<<15		// СРАБ F<<<<

// ------------------------------
// внешняя
#define MB_offset_SRAB_ext_1		0x0D
#define MB_offset_SRAB_ext_2		0x0D
#define MB_offset_SRAB_ext_3		0x0D
#define MB_offset_SRAB_ext_4		0x0D
#define MB_offset_SRAB_ext_5		0x0D
#define MB_offset_SRAB_ext_6		0x0D
#define MB_offset_SRAB_ext_7		0x0D
#define MB_offset_SRAB_ext_8		0x0D

#define MB_b_SRAB_ext_1			1<<0
#define MB_b_SRAB_ext_2			1<<1
#define MB_b_SRAB_ext_3			1<<2
#define MB_b_SRAB_ext_4			1<<3
#define MB_b_SRAB_ext_5			1<<4
#define MB_b_SRAB_ext_6			1<<5
#define MB_b_SRAB_ext_7			1<<6
#define MB_b_SRAB_ext_8			1<<7

// ------------------------------

#define MB_offsetPTOC			0x11
#define MB_bTotVAZ				1<<15
#define MB_bTotWZ				1<<14

#define MB_offsetDirGeneral		0x18

#define MB_offsetDiscreet4		0x04
#define MB_bOffsetErrorHard		1<<0
#define MB_bOffsetErrorLogic	1<<1
#define MB_bOffsetErrorData		1<<2
#define MB_bOffsetErrorOther	1<<3

#define MB_bOffsetErrorMeasU	1<<6
#define MB_bOffsetErrorMeasF	1<<7

// ------------------------------------------
#define MB_StartAnalogINaddr   	0x1900
#define MB_NumbAnalog   		12

#define MB_offset_Un			0x00
#define MB_offset_Ua			0x01
#define MB_offset_Ub			0x02
#define MB_offset_Uc			0x03
#define MB_offset_Uab			0x04
#define MB_offset_Ubc			0x05
#define MB_offset_Uca			0x06
#define MB_offset_NU0			0x07
#define MB_offset_NU1			0x08
#define MB_offset_NU2			0x09
#define MB_offset_Hz			0x0A

// ------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7

// ------------------------------------------
#define MB_addr_SG				0x0400
#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001

// -----------------------------------
#define MB_StartRevNaddr   		0x0500
#define MB_NumbWordRev	   		16

#define MB_addr_LEDS_OFF		0x1804
#define MB_addr_Error_OFF		0x1805
#define MB_addr_SysNote_OFF		0x1806
#define MB_addr_ErrorNote_OFF	0x1807
#define MB_CTRL_OFF				0xFF00

// -----------------------------------
#define MB_PerForSynchClock		1				// период пересинхронизации часов
#define MB_PerForReadMODBUS		100				// период опроса модбас в мс	150

#endif //#if defined (MR5_600)

#endif /*  */
