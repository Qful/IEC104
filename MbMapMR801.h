/*
 * MbMapMR801.h
 *
 *  Created on: 15.05.2017
 *      Author: sagok
 */

#ifndef MBMAPMR801_H_
#define MBMAPMR801_H_

#define _REVISION_DEVICE			207		//2.07		 ��������� ��� 13 �������

#define _swREV						"MR801"

#define _swREVverify				""
/*************************************************************************
 * MR801
 *************************************************************************/
#if defined (MR801)
#define MB_Speed					115200
#define MB_Slaveaddr   				1

#define		_delayAfterResponse		5				// ��� ������ 2.07 �� ���� 5��			// 2�� ������ �������� ��������

// ���������.
#define range_maxIphs				40		// �������� ����� �� �����
#define range_minIphs				0
#define range_maxI0					40
#define range_minI0					0
#define range_maxIn					40
#define range_minIn					0

#define range_P						(3*40*256)


#define range_maxU					256
#define range_minU					0

#define range_maxF					60
#define range_minF					40

#define range_maxCosF				1
#define range_minCosF				0

// --------------------------------------------------------
// �������
// ������ ������ �� 8
// --------------------------------------------------------
#define MB_WriteSysNoteaddr   		0x0600		//����� � ������� ����� ����� ��������� ��� ������
#define MB_StartSysNoteaddr   		0x0600
#define MB_EndSysNoteaddr   		0x0700
#define MB_NumbSysNote	   			9
#define MB_NumbSysNoteASCII			9
#define MB_SizeSysNote	   			256			// ����� ������� � �������

#define MB_OffsetSysNoteMessage	 	8			// ����� � ������� ��� ���������
// --------------------------------------------------------
#define MB_Code_SysNoteEndJurnal	0
// --------------------------------------------------------


#define MB_offset_Word				0
#define MB_offset_ASCII				8			// �� ������������, � ������� ������

#define MB_StartErrorNoteaddr  		0x0700
#define MB_EndErrorNoteaddr   		0x0800
#define MB_NumbErrorNote			54			// ����� ���� � ����� ������
#define MB_NumbErrorNoteASCII		48			//
#define MB_NextErrorNote			0			// ���������� �� �������

#define MB_OffsetErrorNoteMessage 	0			// ����� � ������� ��� ���������
// --------------------------------------------------------
#define MB_Code_ErrorNoteEndJurnal	0
// --------------------------------------------------------

#define MB_NumbErrorNoteTime		8			// ����� ���� ������� �������
#define MB_SizeErrorNote	   		61			// ����� ������� � �������

// ������ ������������ ---------
#define MB_StartOscNoteaddr			0x0800
#define MB_EndOscNoteaddr   		0x0D00
#define MB_NumbOscNote				20			// ������ ����� ������
#define MB_SizeOscNote	   			100			// ����� ������� � �������
//#define MB_SizeOscNote	   					(0x9000 - 0x8000)/MB_NumbOscNote			// ����� ������� � �������

#define MB_NumbOscNoteTime			8			// ����� ���� ������� �������

#define MB_OffsetOscNoteMessage	 	2			// ����� �� �������� ������ ��� ���� ������. ����� �����. �������� �� ������
// --------------------------------------------------------
#define MB_Code_OscNoteEndJurnal	0
#define MB_Code_OscNoteREADY		8

// ������������ -------------------------------------------
#define MB_StartOscaddr				0x0900
#define MB_SizeAllOsc				0x0D00

#define MB_SizeOscBlock				1024
#define MB_SizeOscFile		   		30000			// ������ �����

#define MB_Osc_POINT				10
#define MB_Osc_LEN					14
// --------------------------------------------------------



// ������ 28����
#define _LimitNoteSize				(MB_NumbErrorNote * 80)		// 64 ������� �� ������� ������	224 ������� �� ������� �������

// ������������ ����������� ----------------------------------------------
#define MB_StartConfigSW	   	0x1000			// ������������ �����������
#define MB_offset_ConfigSW 		0x00
#define MB_Size_ConfSW			15				// 14 ����
#define MB_NumbConfigSW			15

#define	MB_rOffsetControlSW		0				// ���������� ������������
#define	MB_bControlSW_Button	(1<<0)
#define	MB_bControlSW_Switch	(1<<1)
#define	MB_bControlSW_Extern	(1<<2)
#define	MB_bControlSW_SDTU		(1<<3)
#define	MB_bControlSW_CmdOFF	(1<<4)

#define	MB_rOffsetControlSW_ON		1				// ���� ��������� ��������
#define	MB_rOffsetControlSW_OFF		2				// ���� ��������� ���������
#define	MB_rOffsetControlSW_ERROR	3				// ���� ������������� �����������

//#define	MB_rOffsetControlSW_BlockSDTU		15			// ������ ������� �� ����

// ������������ ��� ----------------------------------------------
#define MB_StartConfigAPW	   	0x100E			// ������������ ���
#define MB_NumbConfigAPW		7				// 6 ����
#define MB_offset_ConfAPW		0x00			// ������������ ���
#define MB_offset_InBlok		0x01			// ���� ����������

#define MB_bOffset_APW_Config_Stat		(0b11<<0)

// ������������ ��� + ��� ------------------------------------------
#define MB_StartConfigAWR	   	0x1014			// ������������ ���
#define MB_NumbConfigAWR		13				// 10 ���� + 2 ����� ���
#define MB_offset_ConfAWR		0x00			// ������������ ���
#define MB_offset_InBlok		0x01			// ���� ����������

#define MB_offset_ConfLZSHAWR		(0x101E - MB_StartConfigAWR) 			// ������������ ���

#define MB_bOffset_AWR_Config_Stat		0b1111
#define MB_bOffset_LZSH_Config_Stat		0b11	// ����: 0-�����1, 1-�����2

// ������������ �������� ������ ------------------------------------------
#define MB_StartConfigTRPWR		   	0x1047			// ������������  �������� ������
#define MB_EndConfigTRPWR		   	0x105C
#define MB_NumbConfigTRPWR			(MB_EndConfigTRPWR - MB_StartConfigTRPWR)				// 21 �����
#define MB_offset_ConfigS1			(0x1048 - MB_StartConfigTRPWR)
#define MB_offset_ConfigS2			(0x104E - MB_StartConfigTRPWR)
#define MB_offset_ConfigS3			(0x1054 - MB_StartConfigTRPWR)

#define MB_offset_U_Obmotki			0
#define MB_offset_P_Obmotki			1
#define MB_offset_Type_Obmotki		2
#define MB_offset_Meas_Ground		4

// ������������ �������������� ������ ------------------------------------------
#define MB_StartTransMeas			0x105C
#define MB_StartConfigTRMeas	   	0x105C			// ������������  �������������� ������
#define MB_NumbConfigTRMeas			(0x1074 - MB_StartConfigTRMeas)
#define MB_offset_KTHL				(0x106E - MB_StartConfigTRMeas)
#define MB_offset_KTHX				(0x106F - MB_StartConfigTRMeas)

#define MB_offset_ConfigTT_L1		(0x105C - MB_StartConfigTRMeas)		// ���. ����. ���
#define MB_offset_ConfigTT_X1		(0x105D - MB_StartConfigTRMeas)		// ���. ����. ��� ������� ������������������
#define MB_offset_SideTT_CH1		(0x1060 - MB_StartConfigTRMeas)		// ��������

#define MB_offset_ConfigTT_L2		(0x1062 - MB_StartConfigTRMeas)
#define MB_offset_ConfigTT_X2		(0x1063 - MB_StartConfigTRMeas)
#define MB_offset_SideTT_CH2		(0x1066 - MB_StartConfigTRMeas)

#define MB_offset_ConfigTT_L3		(0x1068 - MB_StartConfigTRMeas)
#define MB_offset_ConfigTT_X3		(0x1069 - MB_StartConfigTRMeas)
#define MB_offset_SideTT_CH3		(0x106C - MB_StartConfigTRMeas)

#define MB_bOffset_SideTT_S1		(0b01)								// ���� ������������ ��������
#define MB_bOffset_SideTT_S2		(0b10)								// ���� ������������ ��������
#define MB_bOffset_SideTT			(0b11)								// ���� ������������ ��������



// ������������ ������� ���������� �������� -------------------------------------
#define MB_StartConfigVLSIn			0x1074
#define MB_NumbConfigVLSIn			(0x10B4 - MB_StartConfigVLSIn)

// ������������ �������� ���������� �������� -------------------------------------
#define MB_StartConfigVLSOut		0x10B4
#define MB_NumbConfigVLSOut			(0x11B4 - MB_StartConfigVLSOut)

// ������������ ----------------------------------------------
#define MB_StartConfig		   	0x1000			// �������
#define MB_NumbConfigall   		0x4E			// 7C ������ ������
#define MB_IncNumbOfConfig		0x428

#define MB_Config0		   		0x1000			// ������ ������� 1
#define MB_Config1		   		0x1428			// ������ ������� 2
#define MB_Config2		   		0x1850			// ������ ������� 3
#define MB_Config3		   		0x1C78			// ������ ������� 4
#define MB_Config4		   		0x20A0			// ������ ������� 5
#define MB_Config5		   		0x24C8			// ������ ������� 6

// ������ ������� -----------------------------------------------------------------------------------
#define MB_StartUstavkiaddr0	0x11B4			// �������� ������ �������
#define MB_StartUstavkiaddr1	0x1388			// ��������� ������ �������
#define MB_NumbUstavki			(MB_StartUstavkiaddr1 - MB_StartUstavkiaddr0)			// ������ ����� �������			0x1D5


#define MB_offset_DIFFZ			(0x11C0 - MB_StartUstavkiaddr0)		// ����� ������������ ���� ������
#define MB_offset_DIFFOts		(0x11CC - MB_StartUstavkiaddr0)		// ����� ������������ ���� �������
#define MB_offset_DIFF0_1		(0x11D2 - MB_StartUstavkiaddr0)		// ����� ������������ ������ ������� ������������������
#define MB_offset_DIFF0_2		(0x11DC - MB_StartUstavkiaddr0)		// ����� ������������ ������ ������� ������������������
#define MB_offset_DIFF0_3		(0x11E6 - MB_StartUstavkiaddr0)		// ����� ������������ ������ ������� ������������������

//�����������z ���� ������
#define MB_offset_DIFFZ_Config_Stat		0				// ������������ ���� ������ 1 ����� ���������
#define MB_offset_DIFFOts_Config		0
#define MB_offset_DIFF0_Config			0

// ����
#define MB_bOffset_DIFFZ_Config_Stat		0b11
#define MB_bOffset_DIFFOts_Config_Stat		0b11
#define MB_bOffset_DIFFOtsMgn_Config_Stat	0b1000

#define MB_bOffset_DIFF0_Config_Stat		(0b11<<0)						// ���������


#define MB_offset_MTZ_I1		(0x11F0 - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_MTZ_I2		(MB_offset_MTZ_I1+10)
#define MB_offset_MTZ_I3		(MB_offset_MTZ_I1+20)
#define MB_offset_MTZ_I4		(MB_offset_MTZ_I1+30)
#define MB_offset_MTZ_I5		(MB_offset_MTZ_I1+40)
#define MB_offset_MTZ_I6		(MB_offset_MTZ_I1+50)
#define MB_offset_MTZ_I7		(MB_offset_MTZ_I1+60)
#define MB_offset_MTZ_I8		(MB_offset_MTZ_I1+70)

//�����������z ������� ��� ������  I> I*>----------------------------------------------
#define MB_offset_MTZ_I_Config						0				// ������������

// ����
#define MB_bOffset_MTZ_I_Config_Stat				(0b11<<0)		// ���������

#define MB_bOffset_MTZ_I_Config_Napravl_up			(1<<6)			// ����������� ������ �� ���
#define MB_bOffset_MTZ_I_Config_Napravl_dn			(1<<7)			// ����������� �������� � �����

//�����������z ������� ��� ������
#define MB_offset_MTZ_I_Config	0				// ������������
#define _bSideOffset			4				// �������� � �������
// ����
#define MB_bOffset_MTZ_I_Config_Side				(0b11<<_bSideOffset)			// �������� � �������

#define MB_offset_Ig_I1								(0x1240 - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Ig_I2								(MB_offset_Ig_I1+10)
#define MB_offset_Ig_I3								(MB_offset_Ig_I1+20)
#define MB_offset_Ig_I4								(MB_offset_Ig_I1+30)
#define MB_offset_Ig_I5								(MB_offset_Ig_I1+40)
#define MB_offset_Ig_I6								(MB_offset_Ig_I1+50)

//�����������z ������� Ig ������
#define MB_offset_Ig_I_Config						0							// ������������
#define _bSideOffset								4							// �������� � �������
#define _bLogicOffset								14							// ������

// ����
#define MB_bOffset_Ig_I_Config_Stat					(0b11<<0)					// ���������
#define MB_bOffset_Ig_I_Config_Logic				(0b11<<_bLogicOffset)		// ������
#define MB_bOffset_Ig_I_Config_Side					(0b11<<_bSideOffset)		// �������� � �������

#define MB_bOffset_Ig_I_Config_Napravl_up			(1<<6)						// ����������� ������
#define MB_bOffset_Ig_I_Config_Napravl_dn			(1<<7)						// ����������� ��������

#define MB_bOffset_Ig_I_Config_src_move				14							//
#define MB_bOffset_Ig_I_Config_src					(0b11<<MB_bOffset_Ig_I_Config_src_move)

#define MB_bOffset_Ig_I_Config_src_In				0			//
#define MB_bOffset_Ig_I_Config_src_I0				1			//
#define MB_bOffset_Ig_I_Config_src_I2				2			//

// I --
// ����������� ��������, ������ ����������� ��������
#define MB_offset_dirPTOC_Side1_In		0x20
#define MB_offset_dirPTOC_Side1_Ia		0x20
#define MB_offset_dirPTOC_Side1_Ib		0x20
#define MB_offset_dirPTOC_Side1_Ic		0x20
#define MB_offset_dirPTOC_Side1_I0		0x20
#define MB_offset_dirPTOC_Side1_I2		0x20
#define MB_offset_dirErrorPTOC_Side1_In	0x20
#define MB_offset_dirErrorPTOC_Side1_Ia	0x20
#define MB_offset_dirErrorPTOC_Side1_Ib	0x20
#define MB_offset_dirErrorPTOC_Side1_Ic	0x20
#define MB_offset_dirErrorPTOC_Side1_I0	0x20
#define MB_offset_dirErrorPTOC_Side1_I2	0x20

#define MB_offset_dirPTOC_Side2_In		0x20
#define MB_offset_dirPTOC_Side2_Ia		0x20
#define MB_offset_dirPTOC_Side2_Ib		0x21
#define MB_offset_dirPTOC_Side2_Ic		0x21
#define MB_offset_dirPTOC_Side2_I0		0x21
#define MB_offset_dirPTOC_Side2_I2		0x21
#define MB_offset_dirErrorPTOC_Side2_In	0x20
#define MB_offset_dirErrorPTOC_Side2_Ia	0x20
#define MB_offset_dirErrorPTOC_Side2_Ib	0x21
#define MB_offset_dirErrorPTOC_Side2_Ic	0x21
#define MB_offset_dirErrorPTOC_Side2_I0	0x21
#define MB_offset_dirErrorPTOC_Side2_I2	0x21

#define MB_offset_dirPTOC_Side3_In		0x21
#define MB_offset_dirPTOC_Side3_Ia		0x21
#define MB_offset_dirPTOC_Side3_Ib		0x21
#define MB_offset_dirPTOC_Side3_Ic		0x21
#define MB_offset_dirPTOC_Side3_I0		0x22
#define MB_offset_dirPTOC_Side3_I2		0x22
#define MB_offset_dirErrorPTOC_Side3_In	0x21
#define MB_offset_dirErrorPTOC_Side3_Ia	0x21
#define MB_offset_dirErrorPTOC_Side3_Ib	0x21
#define MB_offset_dirErrorPTOC_Side3_Ic	0x21
#define MB_offset_dirErrorPTOC_Side3_I0	0x22
#define MB_offset_dirErrorPTOC_Side3_I2	0x22

// ���� ����������� � ������������� ��������
#define MB_b_direction_Side1_In		(1<<0x0)		// �����������
#define MB_b_direction_Side1_Ia		(1<<0x2)
#define MB_b_direction_Side1_Ib		(1<<0x4)
#define MB_b_direction_Side1_Ic		(1<<0x6)
#define MB_b_direction_Side1_I0		(1<<0x8)
#define MB_b_direction_Side1_I2		(1<<0xA)
#define MB_b_dirError_Side1_In		(1<<0x1)		// ������ �����������
#define MB_b_dirError_Side1_Ia		(1<<0x3)
#define MB_b_dirError_Side1_Ib		(1<<0x5)
#define MB_b_dirError_Side1_Ic		(1<<0x7)
#define MB_b_dirError_Side1_I0		(1<<0x9)
#define MB_b_dirError_Side1_I2		(1<<0xB)

#define MB_b_direction_Side2_In		(1<<0xC)		// �����������
#define MB_b_direction_Side2_Ia		(1<<0xE)
#define MB_b_direction_Side2_Ib		(1<<0x0)
#define MB_b_direction_Side2_Ic		(1<<0x2)
#define MB_b_direction_Side2_I0		(1<<0x4)
#define MB_b_direction_Side2_I2		(1<<0x6)
#define MB_b_dirError_Side2_In		(1<<0xD)		// ������ �����������
#define MB_b_dirError_Side2_Ia		(1<<0xF)
#define MB_b_dirError_Side2_Ib		(1<<0x1)
#define MB_b_dirError_Side2_Ic		(1<<0x3)
#define MB_b_dirError_Side2_I0		(1<<0x5)
#define MB_b_dirError_Side2_I2		(1<<0x7)

#define MB_b_direction_Side3_In		(1<<0x8)		// �����������
#define MB_b_direction_Side3_Ia		(1<<0xA)
#define MB_b_direction_Side3_Ib		(1<<0xC)
#define MB_b_direction_Side3_Ic		(1<<0xE)
#define MB_b_direction_Side3_I0		(1<<0x0)
#define MB_b_direction_Side3_I2		(1<<0x2)
#define MB_b_dirError_Side3_In		(1<<0x9)		// ������ �����������
#define MB_b_dirError_Side3_Ia		(1<<0xB)
#define MB_b_dirError_Side3_Ib		(1<<0xD)
#define MB_b_dirError_Side3_Ic		(1<<0xF)
#define MB_b_dirError_Side3_I0		(1<<0x1)
#define MB_b_dirError_Side3_I2		(1<<0x3)

// U
#define MB_offset_Uup_U1		(0x127C - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Uup_U2		(MB_offset_Uup_U1+8)
#define MB_offset_Uup_U3		(MB_offset_Uup_U1+16)
#define MB_offset_Uup_U4		(MB_offset_Uup_U1+24)

#define MB_offset_Udn_U1		(0x129C - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Udn_U2		(MB_offset_Udn_U1+8)
#define MB_offset_Udn_U3		(MB_offset_Udn_U1+16)
#define MB_offset_Udn_U4		(MB_offset_Udn_U1+24)

//������������ ����� �� ����������
#define MB_offset_Uup_U_Config		0				// ������������
#define MB_offset_Udn_U_Config		0
// ����
#define MB_bOffset_Uup_U_Config_Stat		(0b11<<0)						// ���������
#define MB_bOffset_Udn_U_Config_Stat		(0b11<<0)

// F
#define MB_offset_Fup_1		(0x12BC - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Fup_2		(MB_offset_Fup_1+8)
#define MB_offset_Fup_3		(MB_offset_Fup_1+16)
#define MB_offset_Fup_4		(MB_offset_Fup_1+24)

#define MB_offset_Fdn_1		(0x12DC - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Fdn_2		(MB_offset_Fdn_1+8)
#define MB_offset_Fdn_3		(MB_offset_Fdn_1+16)
#define MB_offset_Fdn_4		(MB_offset_Fdn_1+24)

//������������ ����� �� ����������
#define MB_offset_Fup_Config		0				// ������������
#define MB_offset_Fdn_Config		0
// ����
#define MB_bOffset_Fup_Config_Stat		(0b11<<0)						// ���������
#define MB_bOffset_Fdn_Config_Stat		(0b11<<0)

// �������
#define MB_offset_Ext_1		(0x1308 - MB_StartUstavkiaddr0)		// ����� ������������ ������� ��� ������
#define MB_offset_Ext_2		(MB_offset_Ext_1+8)
#define MB_offset_Ext_3		(MB_offset_Ext_2+8)
#define MB_offset_Ext_4		(MB_offset_Ext_3+8)
#define MB_offset_Ext_5		(MB_offset_Ext_4+8)
#define MB_offset_Ext_6		(MB_offset_Ext_5+8)
#define MB_offset_Ext_7		(MB_offset_Ext_6+8)
#define MB_offset_Ext_8		(MB_offset_Ext_7+8)
#define MB_offset_Ext_9		(MB_offset_Ext_8+8)
#define MB_offset_Ext_10	(MB_offset_Ext_9+8)
#define MB_offset_Ext_11	(MB_offset_Ext_10+8)
#define MB_offset_Ext_12	(MB_offset_Ext_11+8)
#define MB_offset_Ext_13	(MB_offset_Ext_12+8)
#define MB_offset_Ext_14	(MB_offset_Ext_13+8)
#define MB_offset_Ext_15	(MB_offset_Ext_14+8)
#define MB_offset_Ext_16	(MB_offset_Ext_15+8)

//������������
#define MB_offset_Ext_Config			0			// ������������
// ����
#define MB_bOffset_Ext_Config_Stat		(0b11<<0)						// ���������

// ----------------------------------------------------------------------------------------------
#define MB_StartDiscreetaddr   	0x0D00			// ����� � ������ ��� ������� ������ (3,4)
#define MB_NumbDiscreet   		0x23			// 0x22

#define MB_offset_ErrorOFF		0x0B		// ��������� ����������
#define MB_bOffsetErrorOFF		(1<<0x07)	// ��������� ����������

#define MB_offset_SysNote		0x0E		// ����� ������ ������� �������
#define MB_bOffsetSysNote		(1<<0x03)	// ����� ������ ������� �������

#define MB_offset_ErrorNote		0x0E		// ����� ������ ������� ������
#define MB_bOffsetErrorNote		(1<<0x04)	// ����� ������ ������� ������

#define MB_offset_OscNote		0x0E		// ����� ������  ������� ������������
#define MB_bOffsetOscNote		(1<<0x05)	//

#define MB_offset_Jurnals		0x0E		// ������� ������������� �� ������� �������
#define MB_bOffsetError			(1<<0x06)	// ������� ������������� �� ������� �������

#define MB_offset_SG			0x0B		// ���� �� ������ �������
#define MB_bOffsetSG0			1<<4		// ������ ������� ��������
#define MB_bOffsetSG1			1<<5		// ������ ������� ���������

// ---------------------------------
#define MB_offsetHardFaults		0x10			// ������������� ���������� ����������
#define MB_offset_errorM1		0x10
#define MB_offset_errorM2		0x10
#define MB_offset_errorM3		0x10
#define MB_offset_errorM4		0x10
#define MB_offset_errorM5		0x10
#define MB_offset_errorUstavki  0x10

#define MB_errorM1				(1<<7)		// 11R
#define MB_errorM2				(1<<8)		// 8D 8R
#define MB_errorM3				(1<<9)		// 16D
#define MB_errorM4				(1<<10)		// 16D 16R
#define MB_errorM5				(1<<11)		// 4I 5U
#define MB_bOffsetModule1		(1<<7)			// ������� ������������� ������ 1 ���� 8 + 2 ���� ���� + 1 ���� ������.		/ ���.�������� 2
#define MB_bOffsetModule2		(1<<8)			// ������� ������������� ������ 2 ���� 8 �����. 8
#define MB_bOffsetModule3		(1<<9)			// ������� ������������� ������ 3 �����. 16
#define MB_bOffsetModule4		(1<<10)			// ������� ������������� ������ 4 ������ ������ ���
#define MB_bOffsetModule5		(1<<11)			// ������� ������������� ������ 5 ������ ��� � ����������
#define MB_bOffsetUstavki		(1<<12)			// ������� ������������� �������

#define MB_bOffsetALLFaults		(0b111111<<7)	// ������� ����� �������������

// ---------------------------------
#define MB_offsetHardFaults1	(0x11)			// �������������

#define MB_bOffsetErrorSWAll	0b111100
#define MB_bOffsetErrorSWExt1	(1<<2)
#define MB_bOffsetErrorBKExt1	(1<<3)
#define MB_bOffsetErrorSWctrl1	(1<<4)
#define MB_bOffsetErrorUROV1	(1<<5)

#define MB_bOffsetErrorCtrl1	(1<<6)
#define MB_bOffsetErrorCtrl2	(1<<7)

// ---------------------------------
#define MB_offset_LogicError	0x12			// ������ �� ������
#define MB_bOffsetALLLogicError	(0b11111<<6)		// ����� �� ������

// ---------------------------------
#define MB_offset_LogicMod		0x0E			// ������
#define MB_bOffsetLogicMod_ON	(1<<0xA)		// ������ ���������/���������

// ---------------------------------
														#define MB_offsetDiscreet_1_16	0x00
														#define MB_offsetDiscreet_17_24	0x01
// ---------------------------------
#define MB_MaxNumbDiscreet		24
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

#define MB_MaxNumbRelay			18
// ---------------------------------
#define MB_offsetRelay_1		0x0C
#define MB_offsetRelay_2		0x0C
#define MB_offsetRelay_3		0x0C
#define MB_offsetRelay_4		0x0C
#define MB_offsetRelay_5		0x0C
#define MB_offsetRelay_6		0x0C
#define MB_offsetRelay_7		0x0C
#define MB_offsetRelay_8		0x0C
#define MB_offsetRelay_9		0x0C
#define MB_offsetRelay_10		0x0C
#define MB_offsetRelay_11		0x0C
#define MB_offsetRelay_12		0x0C
#define MB_offsetRelay_13		0x0C
#define MB_offsetRelay_14		0x0D
#define MB_offsetRelay_15		0x0D
#define MB_offsetRelay_16		0x0D
#define MB_offsetRelay_17		0x0D
#define MB_offsetRelay_18		0x0D

#define MB_bOffset_Relay_1		(1<<3)
#define MB_bOffset_Relay_2		(1<<4)
#define MB_bOffset_Relay_3		(1<<5)
#define MB_bOffset_Relay_4		(1<<6)
#define MB_bOffset_Relay_5		(1<<7)
#define MB_bOffset_Relay_6		(1<<8)
#define MB_bOffset_Relay_7		(1<<9)
#define MB_bOffset_Relay_8		(1<<10)
#define MB_bOffset_Relay_9		(1<<11)
#define MB_bOffset_Relay_10		(1<<12)
#define MB_bOffset_Relay_11		(1<<13)
#define MB_bOffset_Relay_12		(1<<14)
#define MB_bOffset_Relay_13		(1<<15)
#define MB_bOffset_Relay_14		(1<<0)
#define MB_bOffset_Relay_15		(1<<1)
#define MB_bOffset_Relay_16		(1<<2)
#define MB_bOffset_Relay_17		(1<<3)
#define MB_bOffset_Relay_18		(1<<4)

#define MB_MaxNumbLED			16
// ---------------------------------
#define MB_offsetLED_1			0x0D
#define MB_offsetLED_2			0x0D
#define MB_offsetLED_3			0x0D
#define MB_offsetLED_4			0x0D
#define MB_offsetLED_5			0x0D
#define MB_offsetLED_6			0x0D
#define MB_offsetLED_7			0x0D
#define MB_offsetLED_8			0x0D
#define MB_offsetLED_9			0x0D
#define MB_offsetLED_10			0x0D
#define MB_offsetLED_11			0x0D
#define MB_offsetLED_12			0x0E
#define MB_offsetLED_13			0x0E
#define MB_offsetLED_14			0x0E
#define MB_offsetLED_15			0x0E
#define MB_offsetLED_16			0x0E

#define MB_bOffset_LED_1		(1<<5)
#define MB_bOffset_LED_2		(1<<6)
#define MB_bOffset_LED_3		(1<<7)
#define MB_bOffset_LED_4		(1<<8)
#define MB_bOffset_LED_5		(1<<9)
#define MB_bOffset_LED_6		(1<<10)
#define MB_bOffset_LED_7		(1<<11)
#define MB_bOffset_LED_8		(1<<12)
#define MB_bOffset_LED_9		(1<<13)
#define MB_bOffset_LED_10		(1<<14)
#define MB_bOffset_LED_11		(1<<15)
#define MB_bOffset_LED_12		(1<<0)
#define MB_bOffset_LED_13		(1<<1)
#define MB_bOffset_LED_14		(1<<2)
#define MB_bOffset_LED_15		(1<<8)
#define MB_bOffset_LED_16		(1<<9)

#define MB_MaxNumbSSL			32
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
#define MB_offsetSSL_10			0x09
#define MB_offsetSSL_11			0x09
#define MB_offsetSSL_12			0x09
#define MB_offsetSSL_13			0x09
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
#define MB_offsetSSL_26			0x0A
#define MB_offsetSSL_27			0x0A
#define MB_offsetSSL_28			0x0A
#define MB_offsetSSL_29			0x0A
#define MB_offsetSSL_30			0x0B
#define MB_offsetSSL_31			0x0B
#define MB_offsetSSL_32			0x0B

#define MB_bOffset_SSL_1		(1<<3)
#define MB_bOffset_SSL_2		(1<<4)
#define MB_bOffset_SSL_3		(1<<5)
#define MB_bOffset_SSL_4		(1<<6)
#define MB_bOffset_SSL_5		(1<<7)
#define MB_bOffset_SSL_6		(1<<8)
#define MB_bOffset_SSL_7		(1<<9)
#define MB_bOffset_SSL_8		(1<<10)
#define MB_bOffset_SSL_9		(1<<11)
#define MB_bOffset_SSL_10		(1<<12)
#define MB_bOffset_SSL_11		(1<<13)
#define MB_bOffset_SSL_12		(1<<14)
#define MB_bOffset_SSL_13		(1<<15)
#define MB_bOffset_SSL_14		(1<<0)
#define MB_bOffset_SSL_15		(1<<1)
#define MB_bOffset_SSL_16		(1<<2)
#define MB_bOffset_SSL_17		(1<<3)
#define MB_bOffset_SSL_18		(1<<4)
#define MB_bOffset_SSL_19		(1<<5)
#define MB_bOffset_SSL_20		(1<<6)
#define MB_bOffset_SSL_21		(1<<7)
#define MB_bOffset_SSL_22		(1<<8)
#define MB_bOffset_SSL_23		(1<<9)
#define MB_bOffset_SSL_24		(1<<10)
#define MB_bOffset_SSL_25		(1<<11)
#define MB_bOffset_SSL_26		(1<<12)
#define MB_bOffset_SSL_27		(1<<13)
#define MB_bOffset_SSL_28		(1<<14)
#define MB_bOffset_SSL_29		(1<<15)
#define MB_bOffset_SSL_30		(1<<0)
#define MB_bOffset_SSL_31		(1<<1)
#define MB_bOffset_SSL_32		(1<<2)

#define MB_MaxNumbVLS			16
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

#define MB_bOffset_LS_1			(1<<8)
#define MB_bOffset_LS_2			(1<<9)
#define MB_bOffset_LS_3			(1<<10)
#define MB_bOffset_LS_4			(1<<11)
#define MB_bOffset_LS_5			(1<<12)
#define MB_bOffset_LS_6			(1<<13)
#define MB_bOffset_LS_7			(1<<14)
#define MB_bOffset_LS_8			(1<<15)
#define MB_bOffset_LS_9			(1<<0)
#define MB_bOffset_LS_10		(1<<1)
#define MB_bOffset_LS_11		(1<<2)
#define MB_bOffset_LS_12		(1<<3)
#define MB_bOffset_LS_13		(1<<4)
#define MB_bOffset_LS_14		(1<<5)
#define MB_bOffset_LS_15		(1<<6)
#define MB_bOffset_LS_16		(1<<7)

// ---------------------------------
#define MB_offsetDiscreet13		0x13
#define MB_offsetDiscreet14		0x14

#define MB_offsetSW_OFF			(1<<1)
#define MB_offsetSW_ON			(1<<2)

#define MB_rOffsetDiscreet16	0x16
#define MB_bOffsetErrorSW		(1<<4)

#define MB_rOffsetDiscreet17	0x17
#define MB_bOffsetExtErrorSW	(1<<2)
#define MB_bOffsetErrorSWCtrl	(1<<3)
#define MB_bOffsetErrorSWCO		(1<<4)
#define MB_bOffsetErrorSWFail	(1<<5)
#define MB_bOffsetErrorSWLon	(1<<6)
#define MB_bOffsetErrorSWLoff	(1<<7)


#define MB_OffsetLogic			0x00

// ---------------------------------
#define MB_offset_IO_I_1		0x04
#define MB_offset_IO_I_2		0x04
#define MB_offset_IO_I_3		0x04
#define MB_offset_IO_I_4		0x04
#define MB_offset_IO_I_5		0x04
#define MB_offset_IO_I_6		0x04
#define MB_offset_IO_I_7		0x04
#define MB_offset_IO_I_8		0x05
#define MB_b_IO_I1				(1<<3)		// �0 I>1
#define MB_b_IO_I2				(1<<5)		// �0 I>2
#define MB_b_IO_I3				(1<<7)		// �0 I>3
#define MB_b_IO_I4				(1<<9)		// �0 I>4
#define MB_b_IO_I5				(1<<11)		// �0 I>5
#define MB_b_IO_I6				(1<<13)		// �0 I>6
#define MB_b_IO_I7				(1<<15)		// �0 I>7
#define MB_b_IO_I8				(1<<1)		// �0 I>8

#define MB_offset_SRAB_I_1		0x04
#define MB_offset_SRAB_I_2		0x04
#define MB_offset_SRAB_I_3		0x04
#define MB_offset_SRAB_I_4		0x04
#define MB_offset_SRAB_I_5		0x04
#define MB_offset_SRAB_I_6		0x04
#define MB_offset_SRAB_I_7		0x05
#define MB_offset_SRAB_I_8		0x05
#define MB_b_SRAB_I1			(1<<4)		// ���� I>1
#define MB_b_SRAB_I2			(1<<6)		// ���� I>2
#define MB_b_SRAB_I3			(1<<8)		// ���� I>3
#define MB_b_SRAB_I4			(1<<10)		// ���� I>4
#define MB_b_SRAB_I5			(1<<12)		// ���� I>5
#define MB_b_SRAB_I6			(1<<14)		// ���� I>6
#define MB_b_SRAB_I7			(1<<0)		// ���� I>7
#define MB_b_SRAB_I8			(1<<2)		// ���� I>8

#define MB_offset_IO_Ig_1		0x05
#define MB_offset_IO_Ig_2		0x05
#define MB_offset_IO_Ig_3		0x05
#define MB_offset_IO_Ig_4		0x05
#define MB_offset_IO_Ig_5		0x05
#define MB_offset_IO_Ig_6		0x05
#define MB_b_IO_Ig1				(1<<3)		// �0 I*>1
#define MB_b_IO_Ig2				(1<<5)		// �0 I*>2
#define MB_b_IO_Ig3				(1<<7)		// �0 I*>3
#define MB_b_IO_Ig4				(1<<9)		// �0 I*>4
#define MB_b_IO_Ig5				(1<<11)		// �0 I*>5
#define MB_b_IO_Ig6				(1<<13)		// �0 I*>6
#define MB_offset_SRAB_Ig_1		0x05
#define MB_offset_SRAB_Ig_2		0x05
#define MB_offset_SRAB_Ig_3		0x05
#define MB_offset_SRAB_Ig_4		0x05
#define MB_offset_SRAB_Ig_5		0x05
#define MB_offset_SRAB_Ig_6		0x05
#define MB_b_SRAB_Ig1			(1<<4)		// ���� I*>1
#define MB_b_SRAB_Ig2			(1<<6)		// ���� I*>2
#define MB_b_SRAB_Ig3			(1<<8)		// ���� I*>3
#define MB_b_SRAB_Ig4			(1<<10)		// ���� I*>4
#define MB_b_SRAB_Ig5			(1<<12)		// ���� I*>5
#define MB_b_SRAB_Ig6			(1<<14)		// ���� I*>6

// U
#define MB_offset_IO_Uup_1		0x05
#define MB_offset_IO_Uup_2		0x06
#define MB_offset_IO_Uup_3		0x06
#define MB_offset_IO_Uup_4		0x06
#define MB_offset_SRAB_Uup_1	0x06
#define MB_offset_SRAB_Uup_2	0x06
#define MB_offset_SRAB_Uup_3	0x06
#define MB_offset_SRAB_Uup_4	0x06

#define MB_offset_IO_Udn_1		0x06
#define MB_offset_IO_Udn_2		0x06
#define MB_offset_IO_Udn_3		0x06
#define MB_offset_IO_Udn_4		0x06
#define MB_offset_SRAB_Udn_1	0x06
#define MB_offset_SRAB_Udn_2	0x06
#define MB_offset_SRAB_Udn_3	0x06
#define MB_offset_SRAB_Udn_4	0x06

#define MB_b_IO_Uup1		(1<<15)		// �0 U>1
#define MB_b_IO_Uup2		(1<<1)		// �0 U>2
#define MB_b_IO_Uup3		(1<<3)		// �0 U>3
#define MB_b_IO_Uup4		(1<<5)		// �0 U>4

#define MB_b_SRAB_Uup1		(1<<0)		// ���� U>1
#define MB_b_SRAB_Uup2		(1<<2)		// ���� U>2
#define MB_b_SRAB_Uup3		(1<<4)		// ���� U>3
#define MB_b_SRAB_Uup4		(1<<6)		// ���� U>4

#define MB_b_IO_Udn1		(1<<7)		// �0 U<1
#define MB_b_IO_Udn2		(1<<9)		// �0 U<2
#define MB_b_IO_Udn3		(1<<11)		// �0 U<3
#define MB_b_IO_Udn4		(1<<13)		// �0 U<4

#define MB_b_SRAB_Udn1		(1<<8)		// ���� U<1
#define MB_b_SRAB_Udn2		(1<<10)		// ���� U<2
#define MB_b_SRAB_Udn3		(1<<12)		// ���� U<3
#define MB_b_SRAB_Udn4		(1<<14)		// ���� U<4

// F
#define MB_offset_IO_Fup_1		0x06
#define MB_offset_IO_Fup_2		0x07
#define MB_offset_IO_Fup_3		0x07
#define MB_offset_IO_Fup_4		0x07
#define MB_offset_SRAB_Fup_1	0x07
#define MB_offset_SRAB_Fup_2	0x07
#define MB_offset_SRAB_Fup_3	0x07
#define MB_offset_SRAB_Fup_4	0x07

#define MB_offset_IO_Fdn_1		0x07
#define MB_offset_IO_Fdn_2		0x07
#define MB_offset_IO_Fdn_3		0x07
#define MB_offset_IO_Fdn_4		0x07
#define MB_offset_SRAB_Fdn_1	0x07
#define MB_offset_SRAB_Fdn_2	0x07
#define MB_offset_SRAB_Fdn_3	0x07
#define MB_offset_SRAB_Fdn_4	0x07

#define MB_b_IO_Fup1		(1<<15)		// �0 F>1
#define MB_b_IO_Fup2		(1<<1)		// �0 F>2
#define MB_b_IO_Fup3		(1<<3)		// �0 F>3
#define MB_b_IO_Fup4		(1<<5)		// �0 F>4

#define MB_b_SRAB_Fup1		(1<<0)		// ���� F>1
#define MB_b_SRAB_Fup2		(1<<2)		// ���� F>2
#define MB_b_SRAB_Fup3		(1<<4)		// ���� F>3
#define MB_b_SRAB_Fup4		(1<<6)		// ���� F>4

#define MB_b_IO_Fdn1		(1<<7)		// �0 F<1
#define MB_b_IO_Fdn2		(1<<9)		// �0 F<2
#define MB_b_IO_Fdn3		(1<<11)		// �0 F<3
#define MB_b_IO_Fdn4		(1<<13)		// �0 F<4

#define MB_b_SRAB_Fdn1		(1<<8)		// ���� F<1
#define MB_b_SRAB_Fdn2		(1<<10)		// ���� F<2
#define MB_b_SRAB_Fdn3		(1<<12)		// ���� F<3
#define MB_b_SRAB_Fdn4		(1<<14)		// ���� F<4

#define MB_MaxNumbVZ			16

// �������
#define MB_offset_SRAB_ext_1		0x08
#define MB_offset_SRAB_ext_2		0x08
#define MB_offset_SRAB_ext_3		0x08
#define MB_offset_SRAB_ext_4		0x08
#define MB_offset_SRAB_ext_5		0x08
#define MB_offset_SRAB_ext_6		0x08
#define MB_offset_SRAB_ext_7		0x08
#define MB_offset_SRAB_ext_8		0x08
#define MB_offset_SRAB_ext_9		0x08
#define MB_offset_SRAB_ext_10		0x08
#define MB_offset_SRAB_ext_11		0x08
#define MB_offset_SRAB_ext_12		0x08
#define MB_offset_SRAB_ext_13		0x08
#define MB_offset_SRAB_ext_14		0x09
#define MB_offset_SRAB_ext_15		0x09
#define MB_offset_SRAB_ext_16		0x09

#define MB_b_SRAB_ext_1			(1<<3)
#define MB_b_SRAB_ext_2			(1<<4)
#define MB_b_SRAB_ext_3			(1<<5)
#define MB_b_SRAB_ext_4			(1<<6)
#define MB_b_SRAB_ext_5			(1<<7)
#define MB_b_SRAB_ext_6			(1<<8)
#define MB_b_SRAB_ext_7			(1<<9)
#define MB_b_SRAB_ext_8			(1<<10)
#define MB_b_SRAB_ext_9			(1<<11)
#define MB_b_SRAB_ext_10		(1<<12)
#define MB_b_SRAB_ext_11		(1<<13)
#define MB_b_SRAB_ext_12		(1<<14)
#define MB_b_SRAB_ext_13		(1<<15)
#define MB_b_SRAB_ext_14		(1<<0)
#define MB_b_SRAB_ext_15		(1<<1)
#define MB_b_SRAB_ext_16		(1<<2)

// ����
#define MB_offset_IO_Diffup_1		0x03
#define MB_offset_SRAB_Diffup_1		0x03
#define MB_offset_IO_Diffup_2		0x03
#define MB_offset_SRAB_Diffup_2		0x03
// ���� 0
#define MB_offset_IO_Diff0_1		0x03
#define MB_offset_SRAB_Diff0_1		0x03
#define MB_offset_IO_Diff0_2		0x03
#define MB_offset_SRAB_Diff0_2		0x04
#define MB_offset_IO_Diff0_3		0x04
#define MB_offset_SRAB_Diff0_3		0x04

#define MB_b_IO_Diffup_1			(1<<11)
#define MB_b_SRAB_Diffup_1			(1<<12)
#define MB_b_IO_Diffup_2			(1<<9)
#define MB_b_SRAB_Diffup_2			(1<<10)
#define MB_b_IO_Diff0_1				(1<<13)
#define MB_b_SRAB_Diff0_1			(1<<14)
#define MB_b_IO_Diff0_2				(1<<15)
#define MB_b_SRAB_Diff0_2			(1<<0)
#define MB_b_IO_Diff0_3				(1<<1)
#define MB_b_SRAB_Diff0_3			(1<<2)

#define MB_b_IO_Diffup_m			(1<<8)

// �����������
#define MB_offset_SW_ctl			0x0B
#define MB_offset_SW_status			0x0E
#define MB_b_SW_ON					(1<<9)
#define MB_b_SW_OFF					(1<<8)
// ���
#define MB_offset_SW_ON_APW			0x0B
#define MB_b_SW_ON_APW				(1<<15)
//���
#define MB_offset_AWR				0x0B
#define MB_b_ON_AWR					(1<<0x0A)
#define MB_b_OFF_AWR				(1<<0x0B)
#define MB_b_Blok_AWR				(1<<0x0C)
//���
#define MB_offset_LZSH				0x0B
#define MB_b_Rab_LZSH				(1<<0x0D)
//����
#define MB_offset_UROV				0x0B
#define MB_b_Rab_UROV				(1<<0x0E)



// Z ----
#define MB_IO_offsetZ_1			0x06
#define MB_IO_offsetZ_2			0x07
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
// ------
#define MB_IO_offDirZ_1			0x26
#define MB_IO_offDirZ_2			0x27

#define MB_PTOC_In				(1<<16)
#define MB_error_In				(1<<17)
#define MB_PTOC_Ia				(1<<6)
#define MB_error_Ia				(1<<7)
#define MB_PTOC_Ib				(1<<8)
#define MB_error_Ib				(1<<9)
#define MB_PTOC_Ic				(1<<10)
#define MB_error_Ic				(1<<11)
#define MB_PTOC_I0				(1<<12)
#define MB_error_I0				(1<<13)
#define MB_PTOC_I2				(1<<14)
#define MB_error_I2				(1<<15)

// ----------------------------------------------------------------------------------------------
#define MB_StartAnalogINaddr   	0x0E00		// ���� ������ ��������
#define MB_NumbAnalog   		58			// 57 ����

#define MB_offset_Ia_Diff		0
#define MB_offset_Ib_Diff		1
#define MB_offset_Ic_Diff		2

#define MB_offset_I2a_Diff		3
#define MB_offset_I2b_Diff		4
#define MB_offset_I2c_Diff		5

#define MB_offset_I5a_Diff		6
#define MB_offset_I5b_Diff		7
#define MB_offset_I5c_Diff		8

#define MB_offset_Ita			9
#define MB_offset_Itb			10
#define MB_offset_Itc			11

#define MB_offset_Is1n			12
#define MB_offset_Is1a			13
#define MB_offset_Is1b			14
#define MB_offset_Is1c			15
#define MB_offset_Is1o			16
#define MB_offset_Is12			17

#define MB_offset_Is2n			20
#define MB_offset_Is2a			21
#define MB_offset_Is2b			22
#define MB_offset_Is2c			23
#define MB_offset_Is2o			24
#define MB_offset_Is22			25

#define MB_offset_Is3n			28
#define MB_offset_Is3a			29
#define MB_offset_Is3b			30
#define MB_offset_Is3c			31
#define MB_offset_Is3o			32
#define MB_offset_Is32			33


#define MB_offset_Un			36
#define MB_offset_Ua			37
#define MB_offset_Ub			38
#define MB_offset_Uc			39
#define MB_offset_Uab			40
#define MB_offset_Ubc			41
#define MB_offset_Ucd			42
#define MB_offset_U0			43
#define MB_offset_U2			44

#define MB_offset_Il1o			45
#define MB_offset_Il1a			46
#define MB_offset_Il1b			47
#define MB_offset_Il1c			48
#define MB_offset_Il2o			49
#define MB_offset_Il2a			50
#define MB_offset_Il2b			51
#define MB_offset_Il2c			52
#define MB_offset_Il3o			53
#define MB_offset_Il3a			54
#define MB_offset_Il3b			55
#define MB_offset_Il3c			56

#define MB_offset_Hz			57		// F

// --------------------------------------------------
#define MB_addr_SwOFF  			0x0D0B		//����� ��������� off
#define MB_addr_SwON   			0x0D0C		//����� �������� on
//#define MB_SwOFF  				0x0000		//off
#define MB_Sw   				0xFF00		//on

#define MB_NumbDate		   		7

#define MB_StartSW 				MB_StartConfig
// ----------------------------------------------------------------------------------------------
#define MB_StartDateNaddr   	0x0200
#define MB_NumbDate		   		7


#define MB_addr_SGroupe0		0x0D09
#define MB_addr_SGroupe1		0x0D0A

// ----------------------------------------------------------------------------------------------
#define MB_StartRevNaddr   		0x0500		// ������ 17 ����
#define MB_NumbWordRev	   		16			// 16

// ������ � ������
#define MB_offset_ModelDev		0x0			// ������ � ������� ����������
#define MB_Model_Size			10			// ������ ������

#define MB_offset_SerNumbDev	(MB_offset_ModelDev + MB_Model_Size)		// ������ � �������� �������
#define MB_SerNumb_Size			7			// ������ ������

#define MB_offset_VersionDev	(MB_offset_SerNumbDev + MB_SerNumb_Size)		// ������ � �������� �������
#define MB_Version_Size			15			// ������ ������

// ----------------------------------------------------------------------------------------------

#define MB_addr_SysNote_OFF		0x0D01
#define MB_addr_ErrorNote_OFF	0x0D02
#define MB_addr_OscNote_OFF		0x0D03
#define MB_addr_Error_OFF		0x0D04
#define MB_addr_LEDS_OFF		0x0D05

#define MB_addr_UstavkiModify	0x0D12		//����� ����� ��������� �������

#define MB_CTRL_OFF				0xFF00

// ��������� ���������� -------------------------------------------------------------------------
#define MB_StartAutomat			0x155C
#define MB_NumbAutomat			(0x15BE - MB_StartAutomat + 1)

// ��������� ������� (��� �� IP �����) -----------------------------------------------------------
#define MB_StartSystemCfg		0x15BE
#define MB_NumbSystemCfg		10
#define MB_offset_IP			4		// F

//#define MB_ConfigSystem	   		0x29E8			// ������������ �������
//#define MB_Size_ConfSysytem		121

// ������ IP �����  -----------------------------------------------------------------------------------
//#define MB_StartConfigNaddr   	0x05C0			// �������� ������ ������ IP ����� ����������. 0x05C0 - 2 �����
//#define MB_NumbConfigNaddr 		2


// -----------------------------------
#define MB_Startaddr_SG			0x0400
#define MB_addr_SG				0x0400
#define MB_NumbSG		   		1

#define MB_selectGroupe0		0x0000
#define MB_selectGroupe1		0x0001


// ������ ����������� ------------------------------------------------------------------------------
//#define MB_Sw_CNT				0x0410
//#define MB_NumbSw_CNT	   		8
#define MB_StartSWCrash			0x0410		// �������� 0x1A00
//#define MB_NumbSWCrash   		8
#define MB_Size_SWCrash  		8

#define MB_offset_Oper_cnt		0		// ����� ����������� ������������
#define MB_offset_Error_cnt		1		// ����� ��������� ����������

// ----------------------------------------------------------------------------------------------
#define MB_Startaddr_Goose		0x0D80
#define MB_NumbGoose	   		1

// ----------------------------------------------------------------------------------------------
// ��� ������� ����� ������
// ----------------------------------------------------------------------------------------------
#define MB_StartDUMP_Ustavki	0x01000
#define MB_NumbDUMP_Ustavki	   	(0x15C1+128 - MB_StartDUMP_Ustavki)
// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------

// ������ ----------------------------------------------------------------------------------------------
#define MB_Startaddr_SG_set_0	0
#define MB_Startaddr_SG_set_1	0

#define MB_addr_DRIVE_UP		0
#define MB_addr_DRIVE_DWN		0

#define MB_StartConfigF_SG0		0
#define MB_NumbConfigF			0

#define MB_StartConfigU_SG0		0
#define MB_NumbConfigU			0

#define MB_StartConfigOut		0
#define MB_NumbConfigOut		0

#define MB_StartConfigExZ_SG0  	0
#define MB_NumbConfigExZ		0

#define MB_StartConfigMTZ_SG0  	0
#define MB_NumbConfigMTZ		0

#define MB_StartConfigI2I1I0_SG0	0
#define MB_NumbConfigI2I1I0			0

#define MB_StartOtherUstavkiaddr	0
#define MB_NumbOtherUstavki			0

#define MB_NumbRPN				0
#define MB_StartRPNaddr			0

#define MB_addr_Set_ExtMode		0
#define MB_addr_Clr_ExtMode		0

#define MB_addr_BLK_OFF			0

#endif


#endif /* MBMAPMR801_H_ */
