/*
 * MbMapMR76x.h
 *
 *  Created on: 24.05.2017
 *      Author: sagok
 *
 *      ��761���
 *      �������� IN42GGIO �� IN74GGIO.
 *      �������:
 *      ��� IPTOC IPTUC IARC PTOV PTUV PTOF PTUF PDPR PTTR RREC RSYN RBRF AVRGGIO NBLKGGIO RPSB PDIS.
 *      �������� � ���������� ���������� CTRL ���� GGIO2 � ������������ ������������ 32-� ������ ���������� (������� 1 � ������� 32) � �������������� SPCSO1� SPCSO32.
 *      ������� ���������� ���������� MES
 *      � ������ ��761��� � ��������� �� ��� ����� ��� ������� ���� �������: SSL32GGIO ��������� �� SSL48GGIO.
 *
 */

#ifndef MBMAPMR76x_H_
#define MBMAPMR76x_H_

//#define _REVISION_DEVICE	302		//3.02		������ ��� ����� 115200 ��� ������� ���������
//#define _REVISION_DEVICE	303		//3.03		������ �� �������� 115200
#define _REVISION_DEVICE	304		//3.04		������ �� �������� 2.343.750


#if defined (MR761) && defined (OLD)	// ��� �� ������ 3.02
#define _swREV			"MR761"
#define _swSubREV		""
#define _swREVverify	""
#define _REVISION_DEVICE	302			// ������ ��� 3.02
#endif
#if defined (MR761) && defined (T4N4)	// ������� � 3.03
#define _swREV			"MR761"
#define _swSubREV		"T4N4D42R36"
#define _swREVverify	""

	#if (_REVISION_DEVICE <= 302)
		#undef _REVISION_DEVICE
		#define _REVISION_DEVICE	303
	#endif
#endif
#if defined (MR761) && defined (T4N5) 	// ������� � 3.03
#define _swREV			"MR761"
#define _swREVverify	"T4N5D42R35"
	#if (_REVISION_DEVICE <= 302)
		#undef _REVISION_DEVICE
		#define _REVISION_DEVICE	303
	#endif
#endif
#if defined (MR761) && defined (OBR) 	// ������:
#define _swREV			"MR761OBR"
#define _swSubREV		"T0N0D74R35"
#define _swREVverify	""
	#if (_REVISION_DEVICE <= 302)
		#undef _REVISION_DEVICE
		#define 	_REVISION_DEVICE		305
		#define 	MB_Speed				5000000						//5000000(4687500)
		#define		_delayAfterResponse		0

	#endif
#endif
#if defined (MR762)
#define _swREV			"MR762"
#define _swSubREV		""
#define _swREVverify	""
#endif
#if defined (MR763)
#define _swREV			"MR763"
#define _swSubREV		""
#define _swREVverify	""
#endif


/*************************************************************************
 * MR76x
 *************************************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763)

#if (_REVISION_DEVICE == 302)
#define MB_Speed					115200
#define		_delayAfterResponse		10//ms 						// ��� ������ 3.02 �� ���� 10��
#endif

#if (_REVISION_DEVICE == 303)
#define MB_Speed					115200
#define		_delayAfterResponse		10//ms 						// ��� ������ 3.03 �� ���� 10��
#endif

#if (_REVISION_DEVICE == 304)
#define MB_Speed					5000000						//5000000(4687500)
#define		_delayAfterResponse		0//ms 						// ��� ������ 3.04 - 0��
#endif

#define MB_Slaveaddr   				1

// ���������.
#define range_maxIphs				40		// �������� ����� �� ����� ����� �������� ��� �� I���
#define range_minIphs				0
#define range_maxI0					40
#define range_minI0					0
#define range_maxIn					40
#define range_minIn					0

#define range_P						(2*3*40*256)	//-W....+Wlim ����� �������� ��� �� I��� � �� K���

#define range_maxZ					256

#define range_maxU					256		// ���� �������� ��� �� K���
#define range_minU					0

#define range_maxF					60
#define range_minF					40

#define DifHz_max					0.5
#define DifAng_max					360


#define range_maxCosF				1
#define range_minCosF				-1

// --------------------------------------------------------
// �������
// ������ ������ �� 8
// --------------------------------------------------------
#define MB_WriteSysNoteaddr   		0x0600		//����� � ������� ����� ����� ��������� ��� ������
#define MB_Addr_SysNote   		0x0600
#define MB_EndSysNoteaddr   		0x0700
#define MB_Size_SysNote	   			9
#define MB_Size_SysNoteASCII			9
#define MB_SizeSysNote	   			256			// ����� ������� � �������

#define MB_OffsetSysNoteMessage	 	8			// ����� � ������� ��� ���������
// --------------------------------------------------------
#define MB_Code_SysNoteEndJurnal	0
// --------------------------------------------------------

#define MB_offset_Word				0
#define MB_offset_ASCII				8			// �� ������������, � ������� ������

// ErrorNote ----------------------------------------------
#define MB_Addr_ErrorNote  		0x0700
#define MB_EndErrorNoteaddr   		0x0800
#define MB_Size_ErrorNote			56			// ����� ���� � ����� ������
#define MB_Size_ErrorNoteASCII		48			//
#define MB_NextErrorNote			0			// ���������� �� �������

#define MB_OffsetErrorNoteMessage 	0			// ����� � ������� ��� ���������
#define MB_Code_ErrorNoteEndJurnal	0
// --------------------------------------------------------

#define MB_Size_ErrorNoteTime		8			// ����� ���� ������� �������
#define MB_SizeErrorNote	   		59			// ����� ������� � �������

// OscNote -----------------------------------------------
#define MB_Addr_OscNote			0x0800
#define MB_EndOscNoteaddr   		0x0D00
#define MB_Size_OscNote				20			// ������ ����� ������
#define MB_SizeOscNote	   			100			//((MB_EndOscNoteaddr - MB_Addr_OscNote)/MB_Size_OscNote)			// ����� ������� � �������

#define MB_Size_OscNoteTime			8			// ����� ���� ������� �������

#define MB_OffsetOscNoteMessage	 	2			// ����� �� �������� ������ ��� ���� ������. ����� �����. �������� �� ������
// --------------------------------------------------------
#define MB_Code_OscNoteEndJurnal	0
#define MB_Code_OscNoteREADY		8

// ������������ -------------------------------------------
#define MB_Addr_Osc				0x0900
#define MB_SizeAllOsc				0x0D00

#define MB_SizeOscBlock				1024
#define MB_SizeOscFile		   		30000			// ������ �����

#define MB_Osc_POINT				10
#define MB_Osc_LEN					14


// ������ 28����
#define _LimitNoteSize				(MB_Size_ErrorNote * 80)		// 64 ������� �� ������� ������	224 ������� �� ������� �������

// ������������ ----------------------------------------------
#define MB_StartConfig		   			0x1000			// �������

//----------------------------------------------------------------------------------------------
// ������ �������
//----------------------------------------------------------------------------------------------
#define MB_Addr_Ustavkiaddr0			0x1000			// ������ ������� 1
#define MB_StartUstavkiaddr1			0x1428			// ������ ������� 2
#define MB_StartUstavkiaddr2			0x1850			// ������ ������� 3
#define MB_StartUstavkiaddr3			0x1C78			// ������ ������� 4
#define MB_StartUstavkiaddr4			0x20A0			// ������ ������� 5
#define MB_StartUstavkiaddr5			0x24C8			// ������ ������� 6

#define MB_Size_Ustavki					(MB_StartUstavkiaddr1-MB_Addr_Ustavkiaddr0)			// ������ ����� �������			0x1D5


// ������������ ������ �� ������������� ----------------------------------------------
#define MB_StartConfig_Z	   			0x11B4 - MB_StartConfig			// ������������
#define MB_NumbConfigZ					72								// 72 ����

#define MB_offset_Z1_Conf				0x00							// ������������
#define MB_offset_Z2_Conf				(MB_offset_Z1_Conf + 12)			// ������������
#define MB_offset_Z3_Conf				(MB_offset_Z1_Conf + 24)			// ������������
#define MB_offset_Z4_Conf				(MB_offset_Z1_Conf + 36)			// ������������
#define MB_offset_Z5_Conf				(MB_offset_Z1_Conf + 48)			// ������������
#define MB_offset_Z6_Conf				(MB_offset_Z1_Conf + 60)			// ������������

#define MB_offset_Z1_InBlok				(MB_offset_Z1_Conf + 0x02)		// ���� ����������
#define MB_offset_Z2_InBlok				(MB_offset_Z2_Conf + 0x02)		// ���� ����������
#define MB_offset_Z3_InBlok				(MB_offset_Z3_Conf + 0x02)		// ���� ����������
#define MB_offset_Z4_InBlok				(MB_offset_Z4_Conf + 0x02)		// ���� ����������
#define MB_offset_Z5_InBlok				(MB_offset_Z5_Conf + 0x02)		// ���� ����������

#define MB_bOffset_Z_Config_Stat		(0b11<<0)

#define MB_bOffset_Z_Config_KachBlk		(1<<13)


#define MB_bits_Napravl					5				// ������� �����
#define MB_bOffset_Z_Config_Napravl		(0b11<<5)

#define MB_bOffset_Z_Config_Napravl_up	(1<<5)			// ����������� ������
#define MB_bOffset_Z_Config_Napravl_dn	(1<<6)			// ����������� ��������

#define MB_bOffset_Z_Config_kontur		(0b111<<8)		// ������

// ������������ ���  ---------------------------------------------
#define MB_Addr_ConfigAWR	   			(0x1220 - MB_StartConfig)			// ������������ ��� � ������ �������
#define MB_Size_ConfigAWR				0				// � �������� ������ �� ��������

#define MB_offset_ConfAWR				0x00			// ������������ ���
#define MB_offset_InBlok				0x01			// ���� ����������

#define MB_bOffset_AWR_Config_Stat		0b1111


// ������������ ���  � ������ ������� ----------------------------------------------
#define MB_Addr_ConfigAPW	   			(0x1264 - MB_StartConfig)			// ������������ ���
#define MB_Size_ConfigAPW				0				// � �������� ������ �� ��������				// 10 ����

#define MB_offset_ConfAPW				0x00			// ������������ ���
#define MB_offset_InBlok				0x01			// ���� ����������

#define MB_bOffset_APW_Config_Stat		0b111

// ������������ �������������� ������  � ������ �������------------------------------------------
#define MB_StartConfigTRMeas	   		(0x1278 - MB_StartConfig)				// ������������  �������������� ������
#define MB_NumbConfigTRMeas				0				// � �������� ������ �� ��������	//16

#define MB_offset_Kttf					0				// Itt�
#define MB_offset_Kttn					1				// Ittn
#define MB_offset_Kttn1					2				// Ittn1
#define MB_offset_Ktt					5				// ������������ ��

#define MB_offset_Ktnf					8				// ����
#define MB_offset_Ktnnp					9				// ���H�
#define MB_offset_Ktnnp1				10				// ���H�1

#define MB_bOffset_Ktt_I_Input			(1<<7)			// ������� ���� 0=1�, 1=5�

// ������������ ������������ ������� ��� ������ � ������ �������------------------------------------------
#define MB_StartConfigMTZ_SG0  			(0x1004 - MB_Addr_Ustavkiaddr0)
#define MB_NumbConfigMTZ				0

#define MB_offset_MTZ_I1				(0x1004 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_MTZ_I2				(MB_offset_MTZ_I1+10)
#define MB_offset_MTZ_I3				(MB_offset_MTZ_I1+20)
#define MB_offset_MTZ_I4				(MB_offset_MTZ_I1+30)
#define MB_offset_MTZ_I5				(MB_offset_MTZ_I1+40)
#define MB_offset_MTZ_I6				(MB_offset_MTZ_I1+50)
#define MB_offset_MTZ_I7				(MB_offset_MTZ_I1+60)

//�����������z ������� ��� ������  I> I*>----------------------------------------------
#define MB_offset_MTZ_I_Config						0				// ������������

// ����
#define MB_bOffset_MTZ_I_Config_Stat				((0b11<<0))						// ���������

#define MB_bOffset_MTZ_I_Config_Napravl_up			(1<<6)				// ����������� ������
#define MB_bOffset_MTZ_I_Config_Napravl_dn			(1<<7)				// ����������� ��������


#define MB_offset_Ig_I1					(0x104A - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Ig_I2					(MB_offset_Ig_I1+10)
#define MB_offset_Ig_I3					(MB_offset_Ig_I1+20)
#define MB_offset_Ig_I4					(MB_offset_Ig_I1+30)
#define MB_offset_Ig_I5					(MB_offset_Ig_I1+40)
#define MB_offset_Ig_I6					(MB_offset_Ig_I1+50)
#define MB_offset_Ig_I7					(MB_offset_Ig_I1+60)
#define MB_offset_Ig_I8					(MB_offset_Ig_I1+70)

//�����������z ������� Ig ������
#define MB_offset_Ig_I_Config						0							// ������������
#define _bSideOffset								4							// �������� � �������
#define _bLogicOffset								14							// ������

// ����
#define MB_bOffset_Ig_I_Config_Stat					(0b11<<0)					// ���������
#define MB_bOffset_Ig_I_Config_Logic				(0b11<<_bLogicOffset)		// ������

#define MB_bOffset_Ig_I_Config_Napravl_up			(1<<6)						// ����������� ������
#define MB_bOffset_Ig_I_Config_Napravl_dn			(1<<7)						// ����������� ��������

#define MB_bOffset_Ig_I_Config_src					(0b11<<12)					//
#define MB_bOffset_Ig_I_Config_src_move				12							//

#define MB_bOffset_Ig_I_Config_src_I0				0			//
#define MB_bOffset_Ig_I_Config_src_I2				1			//
#define MB_bOffset_Ig_I_Config_src_In				2			//
#define MB_bOffset_Ig_I_Config_src_Ig				3			//


// ������������ ������� ������ �� ������ �������  ----------------------------------------------MB_StartConfigTRMeas
#define MB_StartConfigI2I1	   						(0x109A - MB_Addr_Ustavkiaddr0)			// ������������
#define MB_NumbConfigI2I1							10				// 10 ����
#define MB_offset_ConfI2I1							0x00			// ������������

#define MB_bOffset_I2I1_Config_Stat					(0b11<<0)

// ���� ������� ������   ----------------------------------------------
#define MB_StartConfigARC	   						(0x10A0 - MB_Addr_Ustavkiaddr0)			// ������������
#define MB_NumbConfigARC							4				// 10 ����
#define MB_offset_ConfARC							0x00			// ������������

#define MB_bOffset_ARC_Config_Stat					0b11

// ������������ ������ �� ��������� ���������� -------------------------------------------------
// U
#define MB_offset_Uup_U1							(0x10A4 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������ ����������
#define MB_offset_Uup_U2							(MB_offset_Uup_U1+8)
#define MB_offset_Uup_U3							(MB_offset_Uup_U1+16)
#define MB_offset_Uup_U4							(MB_offset_Uup_U1+24)

#define MB_offset_Udn_U1							(0x10C4 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������ ����������
#define MB_offset_Udn_U2							(MB_offset_Udn_U1+8)
#define MB_offset_Udn_U3							(MB_offset_Udn_U1+16)
#define MB_offset_Udn_U4							(MB_offset_Udn_U1+24)

//������������ ����� �� ����������  -------------------------------------------------
#define MB_offset_Uup_U_Config						0							// ������������
#define MB_offset_Udn_U_Config						0
// ����
#define MB_bOffset_Uup_U_Config_Stat				(0b11<<0)				// ���������
#define MB_bOffset_Udn_U_Config_Stat				(0b11<<0)

// F
#define MB_offset_Fup_1								(0x10E4 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������ �������
#define MB_offset_Fup_2								(MB_offset_Fup_1+8)
#define MB_offset_Fup_3								(MB_offset_Fup_1+16)
#define MB_offset_Fup_4								(MB_offset_Fup_1+24)

#define MB_offset_Fdn_1								(0x1104 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������ ��� �������
#define MB_offset_Fdn_2								(MB_offset_Fdn_1+8)
#define MB_offset_Fdn_3								(MB_offset_Fdn_1+16)
#define MB_offset_Fdn_4								(MB_offset_Fdn_1+24)

//������������ ����� �� �������  -------------------------------------------------
#define MB_offset_Fup_Config						0							// ������������
#define MB_offset_Fdn_Config						0
// ����
#define MB_bOffset_Fup_Config_Stat					(0b11<<0)					// ���������
#define MB_bOffset_Fdn_Config_Stat					(0b11<<0)

//������������ �������� �����  -------------------------------------------------
#define MB_offset_Qup_1								(0x1124 - MB_Addr_Ustavkiaddr0)
#define MB_offset_Qup_2								(MB_offset_Qup_1 + 4)

#define MB_offset_Qup_Config						0						// ������������
// ����
#define MB_bOffset_Qup_Config_Stat					0b11					// ���������

//���������� �� �������� ������  -------------------------------------------------
#define MB_offset_BlkQ								(0x112C - MB_Addr_Ustavkiaddr0)

#define MB_offset_BlkQ_Config						0						// ������������
// ����
#define MB_bOffset_BlkQ_Config_Stat					0b11					// ���������

//���������� ����� ��������� �� ����� ������ -------------------------------------
#define MB_offset_BlkNStartMot						(0x1130 - MB_Addr_Ustavkiaddr0)

#define MB_offset_BlkNStartMot_Hot					0				// ������� �����
#define MB_offset_BlkNStartMot_Cold					1				// �������� ����� �����


//������������ ������� �����  -------------------------------------------------
#define MB_offset_Ext_1							(0x1134 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Ext_2							(MB_offset_Ext_1+8)
#define MB_offset_Ext_3							(MB_offset_Ext_2+8)
#define MB_offset_Ext_4							(MB_offset_Ext_3+8)
#define MB_offset_Ext_5							(MB_offset_Ext_4+8)
#define MB_offset_Ext_6							(MB_offset_Ext_5+8)
#define MB_offset_Ext_7							(MB_offset_Ext_6+8)
#define MB_offset_Ext_8							(MB_offset_Ext_7+8)
#define MB_offset_Ext_9							(MB_offset_Ext_8+8)
#define MB_offset_Ext_10						(MB_offset_Ext_9+8)
#define MB_offset_Ext_11						(MB_offset_Ext_10+8)
#define MB_offset_Ext_12						(MB_offset_Ext_11+8)
#define MB_offset_Ext_13						(MB_offset_Ext_12+8)
#define MB_offset_Ext_14						(MB_offset_Ext_13+8)
#define MB_offset_Ext_15						(MB_offset_Ext_14+8)
#define MB_offset_Ext_16						(MB_offset_Ext_15+8)

//������������
#define MB_offset_Ext_Config					0			// ������������
// ����
#define MB_bOffset_Ext_Config_Stat				(0b11<<0)						// ���������

//������������ ������ �� ��������  -------------------------------------------------
#define MB_offset_P_1							(0x1208 - MB_Addr_Ustavkiaddr0)
#define MB_offset_P_2							(0x1214 - MB_Addr_Ustavkiaddr0)

#define MB_offset_P_Config						0						// ������������
// ����
#define MB_bOffset_P_Config_Stat				0b11					// ���������


// ������������ C���������� ���� -------------------------------------------------
#define MB_StartConfigKS_UPPN					(0x1408 - MB_Addr_Ustavkiaddr0)		// ����� ������������ ������ ����������

//������������
#define MB_offset_KS_Config						0			// ������������
#define MB_offset_KS_Man_Config					8			// ������������ ��� ������� ���������
#define MB_offset_KS_Auto_Config				14			// ������������ ��� ��������������� ���������

// ����
#define MB_bOffset_KS_Config_Stat				(1<<0)		// ���������

// ��������� ������������� ��� ����������� ����� ����������� ---------------------------------------
#define MB_StartConfig_Z_CrashDetect			(0x141E - MB_Addr_Ustavkiaddr0)		// ����� ������������

#define MB_offset_Z_CrashDetect_X1f				(MB_StartConfig_Z_CrashDetect + 0)
#define MB_offset_Z_CrashDetect_X2f				(MB_StartConfig_Z_CrashDetect + 1)
#define MB_offset_Z_CrashDetect_X3f				(MB_StartConfig_Z_CrashDetect + 2)
#define MB_offset_Z_CrashDetect_X4f				(MB_StartConfig_Z_CrashDetect + 3)
#define MB_offset_Z_CrashDetect_X5f				(MB_StartConfig_Z_CrashDetect + 4)

#define MB_offset_Z_CrashDetect_L1				(MB_StartConfig_Z_CrashDetect + 5)
#define MB_offset_Z_CrashDetect_L2				(MB_StartConfig_Z_CrashDetect + 6)
#define MB_offset_Z_CrashDetect_L3				(MB_StartConfig_Z_CrashDetect + 7)
#define MB_offset_Z_CrashDetect_L4				(MB_StartConfig_Z_CrashDetect + 8)


//������������
#define MB_offset_Z_CrashDetect_Config			9			// ������������
// ����
#define MB_bOffset_Z_CrashDetect_Config_Stat	0b1111		// ������� �����������

//----------------------------------------------------------------------------------------------
// ���� ������ ���������� ��������
//----------------------------------------------------------------------------------------------
#define MB_Addr_Discreet	   					0x0D00			// ����� � ������ ��� ������� ������ (3,4)
#define MB_Size_Discreet   						0x27			// 0x22

#define MB_offset_ErrorOFF						0x14		// ��������� ����������
#define MB_bOffsetErrorOFF						(1<<4)		// ��������� ����������

#define MB_offset_SysNote						0x13		// ����� ������ ������� �������
#define MB_bOffsetSysNote						(1<<0x0C)	// ����� ������ ������� �������

#define MB_offset_ErrorNote						0x13		// ����� ������ ������� ������
#define MB_bOffsetErrorNote						(1<<0x0D)	// ����� ������ ������� ������

#define MB_offset_OscNote						0x13		// ����� ������  ������� ������������
#define MB_bOffsetOscNote						(1<<0x0E)	//

#define MB_offset_Jurnals						0x13		// ������� ������������� �� ������� �������
#define MB_bOffsetError							(1<<0x0F)	// ������� ������������� �� ������� �������

// ---------------------------------
#define MB_offset_LogicMod						0x14		// ������
#define MB_bOffsetLogicMod_ON					(0b1<<3)	// ������ ���������/���������

// ---------------------------------
#define MB_MaxNumbDiscreet			42
// --Discreet --
#define MB_offsetDiscreet_1			0x0
#define MB_offsetDiscreet_2			0x0
#define MB_offsetDiscreet_3			0x0
#define MB_offsetDiscreet_4			0x0
#define MB_offsetDiscreet_5			0x0
#define MB_offsetDiscreet_6			0x0
#define MB_offsetDiscreet_7			0x0
#define MB_offsetDiscreet_8			0x0
#define MB_offsetDiscreet_9			0x0
#define MB_offsetDiscreet_10		0x0
#define MB_offsetDiscreet_11		0x0
#define MB_offsetDiscreet_12		0x0
#define MB_offsetDiscreet_13		0x0
#define MB_offsetDiscreet_14		0x0
#define MB_offsetDiscreet_15		0x0
#define MB_offsetDiscreet_16		0x0
#define MB_offsetDiscreet_17		0x1
#define MB_offsetDiscreet_18		0x1
#define MB_offsetDiscreet_19		0x1
#define MB_offsetDiscreet_20		0x1
#define MB_offsetDiscreet_21		0x1
#define MB_offsetDiscreet_22		0x1
#define MB_offsetDiscreet_23		0x1
#define MB_offsetDiscreet_24		0x1
#define MB_offsetDiscreet_25		0x1
#define MB_offsetDiscreet_26		0x1
#define MB_offsetDiscreet_27		0x1
#define MB_offsetDiscreet_28		0x1
#define MB_offsetDiscreet_29		0x1
#define MB_offsetDiscreet_30		0x1
#define MB_offsetDiscreet_31		0x1
#define MB_offsetDiscreet_32		0x1
#define MB_offsetDiscreet_33		0x2
#define MB_offsetDiscreet_34		0x2
#define MB_offsetDiscreet_35		0x2
#define MB_offsetDiscreet_36		0x2
#define MB_offsetDiscreet_37		0x2
#define MB_offsetDiscreet_38		0x2
#define MB_offsetDiscreet_39		0x2
#define MB_offsetDiscreet_40		0x2

#define MB_offsetDiscreet_41		0x0E
#define MB_offsetDiscreet_42		0x0E

#define MB_bOffset_Discreet_1		(1<<0)
#define MB_bOffset_Discreet_2		(1<<1)
#define MB_bOffset_Discreet_3		(1<<2)
#define MB_bOffset_Discreet_4		(1<<3)
#define MB_bOffset_Discreet_5		(1<<4)
#define MB_bOffset_Discreet_6		(1<<5)
#define MB_bOffset_Discreet_7		(1<<6)
#define MB_bOffset_Discreet_8		(1<<7)
#define MB_bOffset_Discreet_9		(1<<8)
#define MB_bOffset_Discreet_10		(1<<9)
#define MB_bOffset_Discreet_11		(1<<10)
#define MB_bOffset_Discreet_12		(1<<11)
#define MB_bOffset_Discreet_13		(1<<12)
#define MB_bOffset_Discreet_14		(1<<13)
#define MB_bOffset_Discreet_15		(1<<14)
#define MB_bOffset_Discreet_16		(1<<15)
#define MB_bOffset_Discreet_17		(1<<0)
#define MB_bOffset_Discreet_18		(1<<1)
#define MB_bOffset_Discreet_19		(1<<2)
#define MB_bOffset_Discreet_20		(1<<3)
#define MB_bOffset_Discreet_21		(1<<4)
#define MB_bOffset_Discreet_22		(1<<5)
#define MB_bOffset_Discreet_23		(1<<6)
#define MB_bOffset_Discreet_24		(1<<7)
#define MB_bOffset_Discreet_25		(1<<8)
#define MB_bOffset_Discreet_26		(1<<9)
#define MB_bOffset_Discreet_27		(1<<10)
#define MB_bOffset_Discreet_28		(1<<11)
#define MB_bOffset_Discreet_29		(1<<12)
#define MB_bOffset_Discreet_30		(1<<13)
#define MB_bOffset_Discreet_31		(1<<14)
#define MB_bOffset_Discreet_32		(1<<15)
#define MB_bOffset_Discreet_33		(1<<0)
#define MB_bOffset_Discreet_34		(1<<1)
#define MB_bOffset_Discreet_35		(1<<2)
#define MB_bOffset_Discreet_36		(1<<3)
#define MB_bOffset_Discreet_37		(1<<4)
#define MB_bOffset_Discreet_38		(1<<5)
#define MB_bOffset_Discreet_39		(1<<6)
#define MB_bOffset_Discreet_40		(1<<7)

#define MB_bOffset_Discreet_41		(1<<0)
#define MB_bOffset_Discreet_42		(1<<1)

// ---------------------------------
#define MB_MaxNumbRelay				34
// -Relay --
#define MB_offsetRelay_1			0x10
#define MB_offsetRelay_2			0x10
#define MB_offsetRelay_3			0x10
#define MB_offsetRelay_4			0x10
#define MB_offsetRelay_5			0x10
#define MB_offsetRelay_6			0x10
#define MB_offsetRelay_7			0x10
#define MB_offsetRelay_8			0x10
#define MB_offsetRelay_9			0x10
#define MB_offsetRelay_10			0x10
#define MB_offsetRelay_11			0x10
#define MB_offsetRelay_12			0x10
#define MB_offsetRelay_13			0x10
#define MB_offsetRelay_14			0x10
#define MB_offsetRelay_15			0x10
#define MB_offsetRelay_16			0x10
#define MB_offsetRelay_17			0x11
#define MB_offsetRelay_18			0x11
#define MB_offsetRelay_19			0x11
#define MB_offsetRelay_20			0x11
#define MB_offsetRelay_21			0x11
#define MB_offsetRelay_22			0x11
#define MB_offsetRelay_23			0x11
#define MB_offsetRelay_24			0x11
#define MB_offsetRelay_25			0x11
#define MB_offsetRelay_26			0x11
#define MB_offsetRelay_27			0x11
#define MB_offsetRelay_28			0x11
#define MB_offsetRelay_29			0x11
#define MB_offsetRelay_30			0x11
#define MB_offsetRelay_31			0x11
#define MB_offsetRelay_32			0x11
#define MB_offsetRelay_33			0x12
#define MB_offsetRelay_34			0x12


#define MB_bOffset_Relay_1			(1<<0)
#define MB_bOffset_Relay_2			(1<<1)
#define MB_bOffset_Relay_3			(1<<2)
#define MB_bOffset_Relay_4			(1<<3)
#define MB_bOffset_Relay_5			(1<<4)
#define MB_bOffset_Relay_6			(1<<5)
#define MB_bOffset_Relay_7			(1<<6)
#define MB_bOffset_Relay_8			(1<<7)
#define MB_bOffset_Relay_9			(1<<8)
#define MB_bOffset_Relay_10			(1<<9)
#define MB_bOffset_Relay_11			(1<<10)
#define MB_bOffset_Relay_12			(1<<11)
#define MB_bOffset_Relay_13			(1<<12)
#define MB_bOffset_Relay_14			(1<<13)
#define MB_bOffset_Relay_15			(1<<14)
#define MB_bOffset_Relay_16			(1<<15)
#define MB_bOffset_Relay_17			(1<<0)
#define MB_bOffset_Relay_18			(1<<1)
#define MB_bOffset_Relay_19			(1<<2)
#define MB_bOffset_Relay_20			(1<<3)
#define MB_bOffset_Relay_21			(1<<4)
#define MB_bOffset_Relay_22			(1<<5)
#define MB_bOffset_Relay_23			(1<<6)
#define MB_bOffset_Relay_24			(1<<7)
#define MB_bOffset_Relay_25			(1<<8)
#define MB_bOffset_Relay_26			(1<<9)
#define MB_bOffset_Relay_27			(1<<10)
#define MB_bOffset_Relay_28			(1<<11)
#define MB_bOffset_Relay_29			(1<<12)
#define MB_bOffset_Relay_30			(1<<13)
#define MB_bOffset_Relay_31			(1<<14)
#define MB_bOffset_Relay_32			(1<<15)
#define MB_bOffset_Relay_33			(1<<0)
#define MB_bOffset_Relay_34			(1<<1)


#define MB_MaxNumbLED			16
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

#define MB_offsetLED_13			0x13
#define MB_offsetLED_14			0x13
#define MB_offsetLED_15			0x14
#define MB_offsetLED_16			0x14


#define MB_bOffset_LED_1g		(1<<0x2)
#define MB_bOffset_LED_2g		(1<<0x4)
#define MB_bOffset_LED_3g		(1<<0x6)
#define MB_bOffset_LED_4g		(1<<0x8)
#define MB_bOffset_LED_5g		(1<<0xA)
#define MB_bOffset_LED_6g		(1<<0xC)
#define MB_bOffset_LED_7g		(1<<0xE)
#define MB_bOffset_LED_8g		(1<<0x0)
#define MB_bOffset_LED_9g		(1<<0x2)
#define MB_bOffset_LED_10g		(1<<0x4)
#define MB_bOffset_LED_11g		(1<<0x6)
#define MB_bOffset_LED_12g		(1<<0x8)

#define MB_bOffset_LED_1r		(1<<0x3)
#define MB_bOffset_LED_2r		(1<<0x5)
#define MB_bOffset_LED_3r		(1<<0x7)
#define MB_bOffset_LED_4r		(1<<0x9)
#define MB_bOffset_LED_5r		(1<<0xB)
#define MB_bOffset_LED_6r		(1<<0xD)
#define MB_bOffset_LED_7r		(1<<0xF)
#define MB_bOffset_LED_8r		(1<<0x1)
#define MB_bOffset_LED_9r		(1<<0x3)
#define MB_bOffset_LED_10r		(1<<0x5)
#define MB_bOffset_LED_11r		(1<<0x7)
#define MB_bOffset_LED_12r		(1<<0x9)

#define MB_bOffset_LED_13		(1<<0x0A)
#define MB_bOffset_LED_14		(1<<0x0B)
#define MB_bOffset_LED_15		(1<<1)
#define MB_bOffset_LED_16		(1<<2)

#define MB_MaxNumbSSL			32
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

#define MB_bOffset_SSL_1		(1<<0x8)
#define MB_bOffset_SSL_2		(1<<0x9)
#define MB_bOffset_SSL_3		(1<<0xA)
#define MB_bOffset_SSL_4		(1<<0xB)
#define MB_bOffset_SSL_5		(1<<0xC)
#define MB_bOffset_SSL_6		(1<<0xD)
#define MB_bOffset_SSL_7		(1<<0xE)
#define MB_bOffset_SSL_8		(1<<0xF)
#define MB_bOffset_SSL_9		(1<<0x0)
#define MB_bOffset_SSL_10		(1<<0x1)
#define MB_bOffset_SSL_11		(1<<0x2)
#define MB_bOffset_SSL_12		(1<<0x3)
#define MB_bOffset_SSL_13		(1<<0x4)
#define MB_bOffset_SSL_14		(1<<0x5)
#define MB_bOffset_SSL_15		(1<<0x6)
#define MB_bOffset_SSL_16		(1<<0x7)
#define MB_bOffset_SSL_17		(1<<0x8)
#define MB_bOffset_SSL_18		(1<<0x9)
#define MB_bOffset_SSL_19		(1<<0xA)
#define MB_bOffset_SSL_20		(1<<0xB)
#define MB_bOffset_SSL_21		(1<<0xC)
#define MB_bOffset_SSL_22		(1<<0xD)
#define MB_bOffset_SSL_23		(1<<0xE)
#define MB_bOffset_SSL_24		(1<<0xF)
#define MB_bOffset_SSL_25		(1<<0x0)
#define MB_bOffset_SSL_26		(1<<0x1)
#define MB_bOffset_SSL_27		(1<<0x2)
#define MB_bOffset_SSL_28		(1<<0x3)
#define MB_bOffset_SSL_29		(1<<0x4)
#define MB_bOffset_SSL_30		(1<<0x5)
#define MB_bOffset_SSL_31		(1<<0x6)
#define MB_bOffset_SSL_32		(1<<0x7)

#define MB_MaxNumbVLS			16
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

#define MB_bOffset_VLS_1		(1<<8)
#define MB_bOffset_VLS_2		(1<<9)
#define MB_bOffset_VLS_3		(1<<10)
#define MB_bOffset_VLS_4		(1<<11)
#define MB_bOffset_VLS_5		(1<<12)
#define MB_bOffset_VLS_6		(1<<13)
#define MB_bOffset_VLS_7		(1<<14)
#define MB_bOffset_VLS_8		(1<<15)
#define MB_bOffset_VLS_9		(1<<0)
#define MB_bOffset_VLS_10		(1<<1)
#define MB_bOffset_VLS_11		(1<<2)
#define MB_bOffset_VLS_12		(1<<3)
#define MB_bOffset_VLS_13		(1<<4)
#define MB_bOffset_VLS_14		(1<<5)
#define MB_bOffset_VLS_15		(1<<6)
#define MB_bOffset_VLS_16		(1<<7)

#define MB_MaxNumbLS			16
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

#define MB_bOffset_LS_1			(1<<0x8)
#define MB_bOffset_LS_2			(1<<0x9)
#define MB_bOffset_LS_3			(1<<0xA)
#define MB_bOffset_LS_4			(1<<0xB)
#define MB_bOffset_LS_5			(1<<0xC)
#define MB_bOffset_LS_6			(1<<0xD)
#define MB_bOffset_LS_7			(1<<0xE)
#define MB_bOffset_LS_8			(1<<0xF)
#define MB_bOffset_LS_9			(1<<0)
#define MB_bOffset_LS_10		(1<<1)
#define MB_bOffset_LS_11		(1<<2)
#define MB_bOffset_LS_12		(1<<3)
#define MB_bOffset_LS_13		(1<<4)
#define MB_bOffset_LS_14		(1<<5)
#define MB_bOffset_LS_15		(1<<6)
#define MB_bOffset_LS_16		(1<<7)

// ---------------------------------

//  I> --
#define MB_offset_IO_I_1		0x07
#define MB_offset_IO_I_2		0x07
#define MB_offset_IO_I_3		0x08
#define MB_offset_IO_I_4		0x08
#define MB_offset_IO_I_5		0x08
#define MB_offset_IO_I_6		0x08
#define MB_offset_IO_I_7		0x08	// �0 I<7

#define MB_b_IO_I1				(1<<0xC)		// �0 I>1
#define MB_b_IO_I2				(1<<0xE)		// �0 I>2
#define MB_b_IO_I3				(1<<0x0)		// �0 I>3
#define MB_b_IO_I4				(1<<0x2)		// �0 I>4
#define MB_b_IO_I5				(1<<0x4)		// �0 I>5
#define MB_b_IO_I6				(1<<0x6)		// �0 I>6
#define MB_b_IO_I7				(1<<0x8)		// �0 I<7

#define MB_offset_SRAB_I_1		0x07
#define MB_offset_SRAB_I_2		0x07
#define MB_offset_SRAB_I_3		0x08
#define MB_offset_SRAB_I_4		0x08
#define MB_offset_SRAB_I_5		0x08
#define MB_offset_SRAB_I_6		0x08
#define MB_offset_SRAB_I_7		0x08	// ���� I<7

#define MB_b_SRAB_I1			(1<<0xD)		// ���� I>1
#define MB_b_SRAB_I2			(1<<0xF)		// ���� I>2
#define MB_b_SRAB_I3			(1<<0x1)		// ���� I>3
#define MB_b_SRAB_I4			(1<<0x3)		// ���� I>4
#define MB_b_SRAB_I5			(1<<0x5)		// ���� I>5
#define MB_b_SRAB_I6			(1<<0x7)		// ���� I>6
#define MB_b_SRAB_I7			(1<<0x9)		// ���� I<7

// I*> --
#define MB_offset_IO_Ig_1		0x08
#define MB_offset_IO_Ig_2		0x08
#define MB_offset_IO_Ig_3		0x08
#define MB_offset_IO_Ig_4		0x09
#define MB_offset_IO_Ig_5		0x09
#define MB_offset_IO_Ig_6		0x09
#define MB_offset_IO_Ig_7		0x09
#define MB_offset_IO_Ig_8		0x09

#define MB_b_IO_Ig1			(1<<0xA)		// �0 I*>1
#define MB_b_IO_Ig2			(1<<0xC)		// �0 I*>2
#define MB_b_IO_Ig3			(1<<0xE)		// �0 I*>3
#define MB_b_IO_Ig4			(1<<0x0)		// �0 I*>4
#define MB_b_IO_Ig5			(1<<0x2)		// �0 I*>5
#define MB_b_IO_Ig6			(1<<0x4)		// �0 I*>6
#define MB_b_IO_Ig7			(1<<0x6)		// �0 I*>7
#define MB_b_IO_Ig8			(1<<0x8)		// �0 I*>8

#define MB_offset_SRAB_Ig_1		0x08
#define MB_offset_SRAB_Ig_2		0x08
#define MB_offset_SRAB_Ig_3		0x08
#define MB_offset_SRAB_Ig_4		0x09
#define MB_offset_SRAB_Ig_5		0x09
#define MB_offset_SRAB_Ig_6		0x09
#define MB_offset_SRAB_Ig_7		0x09
#define MB_offset_SRAB_Ig_8		0x09

#define MB_b_SRAB_Ig1		(1<<0xB)		// ���� I*>1
#define MB_b_SRAB_Ig2		(1<<0xD)		// ���� I*>2
#define MB_b_SRAB_Ig3		(1<<0xF)		// ���� I*>3
#define MB_b_SRAB_Ig4		(1<<0x1)		// ���� I*>4
#define MB_b_SRAB_Ig5		(1<<0x3)		// ���� I*>5
#define MB_b_SRAB_Ig6		(1<<0x5)		// ���� I*>6
#define MB_b_SRAB_Ig7		(1<<0x7)		// ���� I*>7
#define MB_b_SRAB_Ig8		(1<<0x9)		// ���� I*>8

#define MB_offset_IO_I2I1		0x09
#define MB_offset_SRAB_I2I1		0x09
#define MB_b_IO_I2I1			(1<<0xA)		// ���� I*>1
#define MB_b_SRAB_I2I1			(1<<0xB)		// ���� I*>2

#define MB_offset_Pusk_ARC		0x0E
#define MB_b_Pusk_ARC			(1<<8)		// ���� �������

// I --
#define MB_offset_dirPTOC_Ia		0x26		// ����������� ��������, ������ ����������� ��������
#define MB_offset_dirPTOC_Ib		0x26
#define MB_offset_dirPTOC_Ic		0x26
#define MB_offset_dirPTOC_In		0x26
#define MB_offset_dirPTOC_I0		0x26
#define MB_offset_dirPTOC_I2		0x26

#define MB_offset_dirErrorPTOC_Ia	0x26		// ����������� ��������, ������ ����������� ��������
#define MB_offset_dirErrorPTOC_Ib	0x26
#define MB_offset_dirErrorPTOC_Ic	0x26
#define MB_offset_dirErrorPTOC_In	0x26
#define MB_offset_dirErrorPTOC_I0	0x26
#define MB_offset_dirErrorPTOC_I2	0x26

// ���� ����������� � ������������� ��������
#define MB_b_direction_In		(1<<0xA)		// �����������
#define MB_b_direction_Ia		(1<<0x0)
#define MB_b_direction_Ib		(1<<0x2)
#define MB_b_direction_Ic		(1<<0x4)
#define MB_b_direction_I0		(1<<0x6)
#define MB_b_direction_I2		(1<<0x8)

#define MB_b_dirError_In		(1<<0xB)		// ������ �����������
#define MB_b_dirError_Ia		(1<<0x1)
#define MB_b_dirError_Ib		(1<<0x3)
#define MB_b_dirError_Ic		(1<<0x5)
#define MB_b_dirError_I0		(1<<0x7)
#define MB_b_dirError_I2		(1<<0x9)

// Z ---
#define MB_offset_dirPTOC_Za		0x26	// �����������
#define MB_offset_dirPTOC_Zb		0x26
#define MB_offset_dirPTOC_Zc		0x27
#define MB_offset_dirErrorPTOC_Za	0x26	// ������ �����������
#define MB_offset_dirErrorPTOC_Zb	0x26
#define MB_offset_dirErrorPTOC_Zc	0x27

#define MB_offset_dirPTOC_Zab		0x27
#define MB_offset_dirPTOC_Zbc		0x27
#define MB_offset_dirPTOC_Zca		0x27
#define MB_offset_dirErrorPTOC_Zab	0x27
#define MB_offset_dirErrorPTOC_Zbc	0x27
#define MB_offset_dirErrorPTOC_Zca	0x27

// ���� ����������� � ������������� Z
#define MB_b_direction_Za		(1<<0xC)		// �����������
#define MB_b_direction_Zb		(1<<0xE)
#define MB_b_direction_Zc		(1<<0x0)
#define MB_b_dirError_Za		(1<<0xD)		// ������ �����������
#define MB_b_dirError_Zb		(1<<0xE)
#define MB_b_dirError_Zc		(1<<0x1)

#define MB_b_direction_Zab		(1<<0x2)
#define MB_b_direction_Zbc		(1<<0x4)
#define MB_b_direction_Zca		(1<<0x6)
#define MB_b_dirError_Zab		(1<<0x3)
#define MB_b_dirError_Zbc		(1<<0x5)
#define MB_b_dirError_Zca		(1<<0x7)


// U ---
#define MB_offset_IO_Uup_1		0x09
#define MB_offset_IO_Uup_2		0x09
#define MB_offset_IO_Uup_3		0x0A
#define MB_offset_IO_Uup_4		0x0A
#define MB_offset_SRAB_Uup_1	0x09
#define MB_offset_SRAB_Uup_2	0x09
#define MB_offset_SRAB_Uup_3	0x0A
#define MB_offset_SRAB_Uup_4	0x0A

#define MB_b_IO_Uup1			(1<<0xC)		// �0 U>1
#define MB_b_IO_Uup2			(1<<0xE)		// �0 U>2
#define MB_b_IO_Uup3			(1<<0x0)		// �0 U>3
#define MB_b_IO_Uup4			(1<<0x2)		// �0 U>4
#define MB_b_SRAB_Uup1			(1<<0xD)		// ���� U>1
#define MB_b_SRAB_Uup2			(1<<0xF)		// ���� U>2
#define MB_b_SRAB_Uup3			(1<<0x1)		// ���� U>3
#define MB_b_SRAB_Uup4			(1<<0x3)		// ���� U>4


#define MB_offset_IO_Udn_1		0x0A
#define MB_offset_IO_Udn_2		0x0A
#define MB_offset_IO_Udn_3		0x0A
#define MB_offset_IO_Udn_4		0x0A
#define MB_offset_SRAB_Udn_1	0x0A
#define MB_offset_SRAB_Udn_2	0x0A
#define MB_offset_SRAB_Udn_3	0x0A
#define MB_offset_SRAB_Udn_4	0x0A

#define MB_b_IO_Udn1			(1<<0x4)		// �0 U<1
#define MB_b_IO_Udn2			(1<<0x6)		// �0 U<2
#define MB_b_IO_Udn3			(1<<0x8)		// �0 U<3
#define MB_b_IO_Udn4			(1<<0xA)		// �0 U<4
#define MB_b_SRAB_Udn1			(1<<0x5)		// ���� U<1
#define MB_b_SRAB_Udn2			(1<<0x7)		// ���� U<2
#define MB_b_SRAB_Udn3			(1<<0x9)		// ���� U<3
#define MB_b_SRAB_Udn4			(1<<0xB)		// ���� U<4

// Q --
#define MB_offset_IO_Qup_1		0x0B
#define MB_offset_IO_Qup_2		0x0B

#define MB_b_IO_Qup_1			(1<<0xC)		// �0 Q>1
#define MB_b_IO_Qup_2			(1<<0xD)		// �0 Q>2

#define MB_offset_IO_BlkQ		0x0B
#define MB_b_IO_BlkQ			(1<<0xE)		// �0 Q>2

// N --									// ���������� �� ����� ������ ������
#define MB_offset_BlkN			0x0B
#define MB_b_BlkN				(1<<0xF)


// F --
#define MB_offset_IO_Fup_1		0x0A
#define MB_offset_IO_Fup_2		0x0A
#define MB_offset_IO_Fup_3		0x0B
#define MB_offset_IO_Fup_4		0x0B
#define MB_offset_SRAB_Fup_1	0x0A
#define MB_offset_SRAB_Fup_2	0x0A
#define MB_offset_SRAB_Fup_3	0x0B
#define MB_offset_SRAB_Fup_4	0x0B

#define MB_b_IO_Fup1			(1<<0xC)		// �0 F>1
#define MB_b_IO_Fup2			(1<<0xE)		// �0 F>2
#define MB_b_IO_Fup3			(1<<0x0)		// �0 F>3
#define MB_b_IO_Fup4			(1<<0x2)		// �0 F>4
#define MB_b_SRAB_Fup1			(1<<0xD)		// ���� F>1
#define MB_b_SRAB_Fup2			(1<<0xF)		// ���� F>2
#define MB_b_SRAB_Fup3			(1<<0x1)		// ���� F>3
#define MB_b_SRAB_Fup4			(1<<0x3)		// ���� F>4


#define MB_offset_IO_Fdn_1		0x0B
#define MB_offset_IO_Fdn_2		0x0B
#define MB_offset_IO_Fdn_3		0x0B
#define MB_offset_IO_Fdn_4		0x0B
#define MB_offset_SRAB_Fdn_1	0x0B
#define MB_offset_SRAB_Fdn_2	0x0B
#define MB_offset_SRAB_Fdn_3	0x0B
#define MB_offset_SRAB_Fdn_4	0x0B


#define MB_b_IO_Fdn1			(1<<0x4)		// �0 F<1
#define MB_b_IO_Fdn2			(1<<0x6)		// �0 F<2
#define MB_b_IO_Fdn3			(1<<0x8)		// �0 F<3
#define MB_b_IO_Fdn4			(1<<0xA)		// �0 F<4
#define MB_b_SRAB_Fdn1			(1<<0x5)		// ���� F<1
#define MB_b_SRAB_Fdn2			(1<<0x7)		// ���� F<2
#define MB_b_SRAB_Fdn3			(1<<0x9)		// ���� F<3
#define MB_b_SRAB_Fdn4			(1<<0xB)		// ���� F<4


#define MB_MaxNumbVZ			16
// �������
#define MB_offset_SRAB_ext_1	0x0F
#define MB_offset_SRAB_ext_2	0x0F
#define MB_offset_SRAB_ext_3	0x0F
#define MB_offset_SRAB_ext_4	0x0F
#define MB_offset_SRAB_ext_5	0x0F
#define MB_offset_SRAB_ext_6	0x0F
#define MB_offset_SRAB_ext_7	0x0F
#define MB_offset_SRAB_ext_8	0x0F
#define MB_offset_SRAB_ext_9	0x0F
#define MB_offset_SRAB_ext_10	0x0F
#define MB_offset_SRAB_ext_11	0x0F
#define MB_offset_SRAB_ext_12	0x0F
#define MB_offset_SRAB_ext_13	0x0F
#define MB_offset_SRAB_ext_14	0x0F
#define MB_offset_SRAB_ext_15	0x0F
#define MB_offset_SRAB_ext_16	0x0F

#define MB_b_SRAB_ext_1			(1<<0)
#define MB_b_SRAB_ext_2			(1<<1)
#define MB_b_SRAB_ext_3			(1<<2)
#define MB_b_SRAB_ext_4			(1<<3)
#define MB_b_SRAB_ext_5			(1<<4)
#define MB_b_SRAB_ext_6			(1<<5)
#define MB_b_SRAB_ext_7			(1<<6)
#define MB_b_SRAB_ext_8			(1<<7)
#define MB_b_SRAB_ext_9			(1<<8)
#define MB_b_SRAB_ext_10		(1<<9)
#define MB_b_SRAB_ext_11		(1<<10)
#define MB_b_SRAB_ext_12		(1<<11)
#define MB_b_SRAB_ext_13		(1<<12)
#define MB_b_SRAB_ext_14		(1<<13)
#define MB_b_SRAB_ext_15		(1<<14)
#define MB_b_SRAB_ext_16		(1<<15)

// ��������� �����������
#define MB_offset_SW_status		0x14
#define MB_b_SW_OFF				(1<<1)
#define MB_b_SW_ON				(1<<2)

// ���
#define MB_offset_SW_ON_APW		0x0C
#define MB_b_SW_ON_APW			(1<<0x0D)			// ���������� ����������� �� ���

//����
#define MB_offset_UROV1			0x0E			//���. ����1
#define MB_b_Rab_UROV1			(1<<0x02)

#define MB_offset_UROV2			0x0E			//���. ����2
#define MB_b_Rab_UROV2			(1<<0x03)

#define MB_offset_UROVBLK		0x0E			//���������� ����
#define MB_b_Blk_UROV			(1<<0x04)

//��� �� ��
#define MB_offset_UslOsUS		0x0D
#define MB_b_offset_UslOsUS		(0b11<<5)

//��� �� ��
#define MB_offset_Kach			0x0D			// �������
#define MB_b_offset_Kach		(1<<0xB)

//���
#define MB_offset_AWR			0x0E
#define MB_b_ON_AWR				(1<<0x05)
#define MB_b_OFF_AWR			(1<<0x06)
#define MB_b_Blok_AWR			(1<<0x07)


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

#define MB_Z1_IO				(1<<8)
#define MB_Z1					(1<<9)
#define MB_Z2_IO				(1<<10)
#define MB_Z2					(1<<11)
#define MB_Z3_IO				(1<<12)
#define MB_Z3					(1<<13)
#define MB_Z4_IO				(1<<14)
#define MB_Z4					(1<<15)
#define MB_Z5_IO				(1<<0)
#define MB_Z5					(1<<1)
#define MB_Z6_IO				(1<<2)
#define MB_Z6					(1<<3)
#define MB_Z7_IO				(1<<4)
#define MB_Z7					(1<<5)
#define MB_Z8_IO				(1<<6)
#define MB_Z8					(1<<7)
#define MB_Z9_IO				(1<<8)
#define MB_Z9					(1<<9)
#define MB_Z10_IO				(1<<10)
#define MB_Z10					(1<<11)

// P ----
#define MB_IO_offsetP_1			0x07
#define MB_IO_offsetP_2			0x07

#define MB_P1_IO				(1<<6)
#define MB_P1					(1<<7)
#define MB_P2_IO				(1<<8)
#define MB_P2					(1<<9)

// ---------------------------------
#define MB_offsetHardFaults		0x16			// ������������� ���������� ����������

#define MB_offset_errorM1		0x16
#define MB_offset_errorM2		0x16
#define MB_offset_errorM3		0x16
#define MB_offset_errorM4		0x16
#define MB_offset_errorM5		0x16
#define MB_offset_errorUstavki	0x16

#define MB_bOffset_errorM1		(1<<7)			// ������� ������������� ������ 1
#define MB_bOffset_errorM2		(1<<8)			// ������� ������������� ������ 2 8-����� 8-����
#define MB_bOffset_errorM3		(1<<9)			// ������� ������������� ������ 3 16 ���������
#define MB_bOffset_errorM4		(1<<10)			// ������� ������������� ������ 4 16-����� 16-����
#define MB_bOffset_errorM5		(1<<11)			// ������� ������������� ������ 5 ������
#define MB_bOffset_errorUstavki		(1<<12)			// ������� ������������� �������

#define MB_bOffset_errorALLModul		(0b111111<<7)	// ������� ����� �������������

// ---------------------------------
#define MB_offset_errorHard1	0x17			// ������������� �����������

#define MB_bOffset_errorSWAll	0b111111100
#define MB_bOffsetErrorSWExt1	(1<<2)
#define MB_bOffsetErrorBKExt1	(1<<3)
#define MB_bOffsetErrorSWctrl1	(1<<4)
#define MB_bOffsetErrorUROV1	(1<<5)
#define MB_bOffsetErrorCtrl1	(1<<6)
#define MB_bOffset_errorCtrl2	(1<<7)
#define MB_bOffset_errorCtrl3	(1<<8)


// ---------------------------------
#define MB_offset_LogicError		0x18			// ������ �� ������
#define MB_bOffsetALLLogicError		(0b11111<<7)		// ����� �� ������

// ---------------------------------
#define MB_offset_UstavkiModify		0x18		// ��������� � �������� ��� ������ �������� � ������
#define MB_bOffset_errorUstavkiModify		(1<<0x0E)		// ��������� � �������� ��� ������ �������� � ������

// ---------------------------------
#define MB_offset_SG				0x14		// ���� �� ������ �������
#define MB_bOffsetSG0				(1<<0x05)
#define MB_bOffsetSG1				(1<<0x06)
#define MB_bOffsetSG2				(1<<0x07)
#define MB_bOffsetSG3				(1<<0x08)
#define MB_bOffsetSG4				(1<<0x09)
#define MB_bOffsetSG5				(1<<0x0A)


// ----------------------------------------------------------------------------------------------
#define MB_Addr_Analog   	0x0E00		// ���� ������ ��������
#define MB_Size_Analog   		98			// 264 ����


#define MB_offset_Ia			0
#define MB_offset_Ib			1
#define MB_offset_Ic			2

#define MB_offset_I1			4
#define MB_offset_I2			5
#define MB_offset_In			6


#define MB_offset_Ua			11
#define MB_offset_Ub			12
#define MB_offset_Uc			13
#define MB_offset_Un			14
#define MB_offset_Un1			15
#define MB_offset_Uab			16
#define MB_offset_Ubc			17
#define MB_offset_Uca			18

#define MB_offset_U1			20
#define MB_offset_U2			21
#define MB_offset_I3I0			22
#define MB_offset_U3U0			23

#define MB_offset_Hz			24		// F

#define MB_offset_In1			25

#define MB_offset_TotW			26		// P 2�����
#define MB_offset_TotVAr		28		// Q 2�����
#define MB_offset_TotPF			30		// cos

#define MB_offset_OMP			31		// ���

#define MB_offset_Q_stats		94		// ��������� �������� ������
#define MB_offset_dU			95		// dU
#define MB_offset_dfi			96		// dfi
#define MB_offset_dF			97		// dF

// ----------------------------------------------------------------------------------------------
#define MB_Addr_Date		   	0x0200
#define MB_Size_Date	   		7

// ----------------------------------------------------------------------------------------------
#define MB_Addr_SG			0x0400
#define MB_addr_SG				0x0400
#define MB_Size_SG		   		1

#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001
#define MB_selectGroupe2		0x0002
#define MB_selectGroupe3		0x0003
#define MB_selectGroupe4		0x0004
#define MB_selectGroupe5		0x0005

// ������ ����������� ------------------------------------------------------------------------------
//#define MB_Sw_CNT				0x0410		//0x1A00 ��� 0x0410
//#define MB_NumbSw_CNT	   		8
//#define MB_NumbSWCrash   		8
#define MB_Addr_SWCrash			0x0410
#define MB_Size_SWCrash  		8

#define MB_offset_Oper_cnt		0		// ����� ����������� ������������
#define MB_offset_Error_cnt		1		// ����� ��������� ����������

/********************************************************************************
 * ������
 ********************************************************************************/

#define MB_Addr_Rev		   							0x0500
#define MB_Size_Rev		   							16				// 16 ����

// ������ � ������
#define MB_offset_ModelDev		0x0			// ������ � ������� ����������
#define MB_Model_Size			10			// ������ ������

#define MB_offset_SerNumbDev	(MB_offset_ModelDev + MB_Model_Size)		// ������ � �������� �������
#define MB_SerNumb_Size			7			// ������ ������

#define MB_offset_VersionDev	(MB_offset_SerNumbDev + MB_SerNumb_Size)		// ������ � �������� �������
#define MB_Version_Size			15			// ������ ������

// - ������ � ������ -----------------------------
#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02
#define MB_addr_OscNote_OFF		0x0D03
#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_addr_SwOFF  			0x0D08		//����� ��������� off
#define MB_addr_SwON   			0x0D09		//����� �������� on

#define MB_Addr_UstavkiModify	0x0D12		//����� ����� ��������� �������

#define MB_Sw   				0xFF00		//on
#define MB_CTRL_OFF				0xFF00

// ����� ������� --------------------------------------------------------------------------------
#define MB_Addr_OtherUstavki	0x28F0
#define MB_Size_OtherUstavki			(0x2A93 - MB_Addr_OtherUstavki)

// ������������ ����������� -----
#define MB_offset_ConfigSW	   		(0x28F0 - MB_Addr_OtherUstavki)

#define	MB_rOffsetControlSW			0				// ���������� ������������

#define	MB_bControlSW_Button			(1<<0)
#define	MB_bControlSW_Switch			(1<<1)
#define	MB_bControlSW_Extern			(1<<2)
#define	MB_bControlSW_SDTU				(1<<3)
#define	MB_bControlSW_CmdOFF			(1<<4)

#define	MB_rOffsetControlSW_ON				1			// ���� ��������� ��������
#define	MB_rOffsetControlSW_OFF				2			// ���� ��������� ���������
#define	MB_rOffsetControlSW_ERROR			3			// ���� ������������� �����������

#define	MB_rOffsetControlSW_BlockSDTU		15			// ������ ������� �� ����


// ��������� ���������� ---
#define MB_offset_Automat				(0x294E - MB_Addr_OtherUstavki)

// ��������� ���� ---
#define MB_offset_UROV					(0x2A8E - MB_Addr_OtherUstavki)

#define MB_bOffset_UROV_ModeI			(1<<0)
#define MB_bOffset_UROV_ModeSWctrl		(1<<1)

// ��������� ���������� -------------------------------------------------------------------------
//#define MB_Addr_Automat			0x294E
//#define MB_Size_Automat			0x29E8 - MB_Addr_Automat + 1

// ��������� ������� (��� �� IP �����) -----------------------------------------------------------
//#define MB_Addr_SystemCfg		0x2A00
//#define MB_Size_SystemCfg		12
//#define MB_offset_IP			4		// F
// ������������� ����� ��� ���� �������� 7x �����
#define MB_Addr_SystemCfg				0x05C0
#define MB_Size_SystemCfg				16
#define MB_offset_IP					0


// ----------------------------------------------------------------------------------------------
#define MB_Addr_Goose				0x0D80
#define MB_Size_Goose	   				9

// ----------------------------------------------------------------------------------------------
// ��� ������� ����� ������
// ----------------------------------------------------------------------------------------------
#define MB_Addr_DUMP_Ustavki			0x01000
#define MB_Size_DUMP_Ustavki	   			(0x2A93 - MB_Addr_DUMP_Ustavki)
// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------

// ������ -----------------------------
#define MB_Addr_ConfigVLSOut	0
#define MB_Size_ConfigVLSOut		0

#define MB_Addr_ConfigVLSIn		0
#define MB_Size_ConfigVLSIn		0

//#define MB_Addr_OtherUstavki	0
//#define MB_Size_OtherUstavki			0

#define MB_Addr_SG_set_0	0
#define MB_Addr_SG_set_1	0


#define MB_addr_DRIVE_UP		0
#define MB_addr_DRIVE_DWN		0

#define MB_Addr_ConfigF		0
#define MB_Size_ConfigF			0

#define MB_Addr_ConfigU		0
#define MB_Size_ConfigU			0

#define MB_Addr_ConfigOut		0
#define MB_Size_ConfigOut		0

#define MB_StartConfigExZ_SG0  	0
#define MB_NumbConfigExZ		0

#define MB_StartConfigI2I1I0_SG0	0
#define MB_NumbConfigI2I1I0			0


#define MB_Addr_ConfigTRPWR		0
#define MB_Size_ConfigTRPWR		0

#define MB_Size_RPN				0
#define MB_Addr_RPN			0

#define MB_addr_Set_ExtMode		0
#define MB_addr_Clr_ExtMode		0

#define MB_Addr_Automat			0		// � ��������
#define MB_Size_Automat			0

#define MB_Addr_ConfigSW	  	0		// � ��������
#define MB_Size_ConfigSW			0

#define MB_addr_BLK_OFF			0

#endif

#endif /* MBMAPMR_H_ */
