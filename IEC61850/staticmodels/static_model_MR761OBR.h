/*
 * static_model_76x.h
 *
 * automatically generated from simpleIO_direct_control.scd
 *
 * ������ ������ ��� ������� �� ��������� ������� � ����� ��� 61850-7-3.
 *
 * ����� ���������� ��� ���������� ����� (����������� �� ������ Common Logical Node Class)
 * Mod			INC			�����											������������ ��������
 * Beh			INS			���������										������������ ��������
 * Health		INS			���������										������������ ��������
 * NamPlt		LPL			���������� ������								������������ ��������
 * OpCntRs		INC			������������ ������� ������������				������������ ��������
 *
 * ���������� � ���������
 * Str			ACD			����											������������ ��������
 * Op			ACT			������������									������������ ��������
 * TmASt		CSD			�������� �����-������� ��������������			�������������� ��������
 *
 * �������
 * TmACrv		CURVE		��� �����-������� ��������������				�������������� ��������
 * StrVal		ASG			������� �� ����
 * TmMult					�������������� ������� �� �������
 * MinOpTmms	ING			����������� ����� ������������
 * MaxOpTmms	ING			������������ ����� ������������
 * OpDlTmms		ING			������� �� �������
 * TypRsCrv		ING			��� �������������� ��������
 * RsDlTmms		ING			������� ������� ��������
 * DirMod		ING			������������ �����
 *
 *
 *
 *
 *
 *
 */

#ifndef STATIC_MODEL_MR76x_H_
#define STATIC_MODEL_MR76x_H_

#include <stdlib.h>
#include "model.h"
#include "iec61850_server.h"
#include "iec61850_common.h"

#include "LDsModels/Defs_model.h"

extern IedServer iedServer;

extern IedModel 	iedModel;
extern LogicalDevice iedModel_Generic_LD0;
extern LogicalDevice iedModel_Generic_PROT;
extern LogicalDevice iedModel_Generic_CTRL;
extern LogicalDevice iedModel_Generic_MES;
extern LogicalDevice iedModel_Generic_GGIO;

extern SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0;

/***********************************************************************
 * ���������� ����
 ***********************************************************************/
// ---------------------------------------------------------------------------------------------------------
// 0    000    00
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 000  000    00
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LLN0;								// ���������� ���� ����. ���: LLN0
extern DataObject    iedModel_LD0_LLN0_Mod;							// Mod - �����
extern DataAttribute iedModel_LD0_LLN0_Mod_q;
extern DataAttribute iedModel_LD0_LLN0_Mod_t;
extern DataAttribute iedModel_LD0_LLN0_Mod_stVal;
extern DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;

extern DataObject    iedModel_LD0_LLN0_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_LD0_LLN0_Beh_stVal;
extern DataAttribute iedModel_LD0_LLN0_Beh_q;
extern DataAttribute iedModel_LD0_LLN0_Beh_t;

extern DataObject    iedModel_LD0_LLN0_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_LD0_LLN0_Health_stVal;
extern DataAttribute iedModel_LD0_LLN0_Health_q;
extern DataAttribute iedModel_LD0_LLN0_Health_t;

extern DataObject    iedModel_LD0_LLN0_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_d;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

// LPHD ----------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LPHD1;								// LPHD - ���������� � ���������� ����������. ������������: LPHD

extern DataObject    iedModel_LD0_LPHD1_PhyNam;						// PhyNam - ���������� �������� ����������� ����������
extern DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_LD0_LPHD1_PhyHealth;					// PhyHealth - ��������� ����������������� ����������� ����������
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_t;

extern DataObject    iedModel_LD0_LPHD1_Proxy;						// Proxy - ��������, ������ �� ������ LN �����������
extern DataAttribute iedModel_LD0_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_q;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_t;

// RDRE ----------------------------------------------------------------------------------------------------
extern LogicalNode iedModel_LD0_RDRE1;

extern DataObject iedModel_LD0_RDRE1_Mod;
extern DataAttribute iedModel_LD0_RDRE1_Mod_q;
extern DataAttribute iedModel_LD0_RDRE1_Mod_t;
extern DataAttribute iedModel_LD0_RDRE1_Mod_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Mod_ctlModel;
extern DataObject iedModel_LD0_RDRE1_Beh;
extern DataAttribute iedModel_LD0_RDRE1_Beh_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Beh_q;
extern DataAttribute iedModel_LD0_RDRE1_Beh_t;
extern DataObject iedModel_LD0_RDRE1_Health;
extern DataAttribute iedModel_LD0_RDRE1_Health_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Health_q;
extern DataAttribute iedModel_LD0_RDRE1_Health_t;
extern DataObject iedModel_LD0_RDRE1_NamPlt;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_vendor;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_swRev;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_d;

extern DataObject iedModel_LD0_RDRE1_RCBMade;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_stVal;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_q;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_t;

extern DataObject iedModel_LD0_RDRE1_FltNum;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_stVal;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_q;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_t;

// ---------------------------------------------------------------------------------------------------------
// 000   000    00   00000
// 0  0  0  0  0  0    0
// 0  0  0  0  0  0    0
// 000   000   0  0    0
// 0     0 0   0  0    0
// 0     0  0   00     0
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_LLN0;								// ���������� ���� ����. ���: LLN0
extern DataObject    iedModel_PROT_LLN0_Mod;							// Mod - �����
extern DataAttribute iedModel_PROT_LLN0_Mod_q;
extern DataAttribute iedModel_PROT_LLN0_Mod_t;
extern DataAttribute iedModel_PROT_LLN0_Mod_stVal;
extern DataAttribute iedModel_PROT_LLN0_Mod_ctlModel;

extern DataObject    iedModel_PROT_LLN0_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_PROT_LLN0_Beh_stVal;
extern DataAttribute iedModel_PROT_LLN0_Beh_q;
extern DataAttribute iedModel_PROT_LLN0_Beh_t;

extern DataObject    iedModel_PROT_LLN0_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_PROT_LLN0_Health_stVal;
extern DataAttribute iedModel_PROT_LLN0_Health_q;
extern DataAttribute iedModel_PROT_LLN0_Health_t;

extern DataObject    iedModel_PROT_LLN0_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_PROT_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_PROT_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_PROT_LLN0_NamPlt_d;
extern DataAttribute iedModel_PROT_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_PROT_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_PROT_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_PROT_LLN0_SGCB_q;
extern DataAttribute iedModel_PROT_LLN0_SGCB_t;
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_LPHD1;								// LPHD - ���������� � ���������� ����������. ������������: LPHD

extern DataObject    iedModel_PROT_LPHD1_PhyNam;						// PhyNam - ���������� �������� ����������� ����������
extern DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_PROT_LPHD1_PhyHealth;					// PhyHealth - ��������� ����������������� ����������� ����������
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_t;

extern DataObject    iedModel_PROT_LPHD1_Proxy;						// Proxy - ��������, ������ �� ������ LN �����������
extern DataAttribute iedModel_PROT_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_PROT_LPHD1_Proxy_q;
extern DataAttribute iedModel_PROT_LPHD1_Proxy_t;

//----------------------------------------------------------------------------
// IPTOC1
//----------------------------------------------------------------------------

extern LogicalNode   iedModel_PROT_IPTOC1;

extern DataObject    iedModel_PROT_IPTOC1_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC1_Beh_t;

extern DataObject    iedModel_PROT_IPTOC1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Health_q;
extern DataAttribute iedModel_PROT_IPTOC1_Health_t;

extern DataObject    iedModel_PROT_IPTOC1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC1_Str;
extern DataAttribute iedModel_PROT_IPTOC1_Str_general;
extern DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC1_Str_q;
extern DataAttribute iedModel_PROT_IPTOC1_Str_t;

extern DataObject    iedModel_PROT_IPTOC1_Op;
extern DataAttribute iedModel_PROT_IPTOC1_Op_general;
extern DataAttribute iedModel_PROT_IPTOC1_Op_q;
extern DataAttribute iedModel_PROT_IPTOC1_Op_t;

//----------------------------------------------------------------------------
// IPTOC2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC2;

extern DataObject    iedModel_PROT_IPTOC2_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC2_Beh_t;

extern DataObject    iedModel_PROT_IPTOC2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Health_q;
extern DataAttribute iedModel_PROT_IPTOC2_Health_t;

extern DataObject    iedModel_PROT_IPTOC2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC2_Str;
extern DataAttribute iedModel_PROT_IPTOC2_Str_general;
extern DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC2_Str_q;
extern DataAttribute iedModel_PROT_IPTOC2_Str_t;

extern DataObject    iedModel_PROT_IPTOC2_Op;
extern DataAttribute iedModel_PROT_IPTOC2_Op_general;
extern DataAttribute iedModel_PROT_IPTOC2_Op_q;
extern DataAttribute iedModel_PROT_IPTOC2_Op_t;

//----------------------------------------------------------------------------
// IPTOC3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC3;

extern DataObject    iedModel_PROT_IPTOC3_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC3_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC3_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC3_Beh_t;

extern DataObject    iedModel_PROT_IPTOC3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC3_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Health_q;
extern DataAttribute iedModel_PROT_IPTOC3_Health_t;

extern DataObject    iedModel_PROT_IPTOC3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC3_Str;
extern DataAttribute iedModel_PROT_IPTOC3_Str_general;
extern DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC3_Str_q;
extern DataAttribute iedModel_PROT_IPTOC3_Str_t;

extern DataObject    iedModel_PROT_IPTOC3_Op;
extern DataAttribute iedModel_PROT_IPTOC3_Op_general;
extern DataAttribute iedModel_PROT_IPTOC3_Op_q;
extern DataAttribute iedModel_PROT_IPTOC3_Op_t;

//----------------------------------------------------------------------------
// IPTOC4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC4;

extern DataObject    iedModel_PROT_IPTOC4_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC4_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC4_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC4_Beh_t;

extern DataObject    iedModel_PROT_IPTOC4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC4_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Health_q;
extern DataAttribute iedModel_PROT_IPTOC4_Health_t;

extern DataObject    iedModel_PROT_IPTOC4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC4_Str;
extern DataAttribute iedModel_PROT_IPTOC4_Str_general;
extern DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC4_Str_q;
extern DataAttribute iedModel_PROT_IPTOC4_Str_t;

extern DataObject    iedModel_PROT_IPTOC4_Op;
extern DataAttribute iedModel_PROT_IPTOC4_Op_general;
extern DataAttribute iedModel_PROT_IPTOC4_Op_q;
extern DataAttribute iedModel_PROT_IPTOC4_Op_t;

//----------------------------------------------------------------------------
// IPTOC5
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC5;

extern DataObject    iedModel_PROT_IPTOC5_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC5_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC5_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC5_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC5_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC5_Beh_t;

extern DataObject    iedModel_PROT_IPTOC5_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC5_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC5_Health_q;
extern DataAttribute iedModel_PROT_IPTOC5_Health_t;

extern DataObject    iedModel_PROT_IPTOC5_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC5_Str;
extern DataAttribute iedModel_PROT_IPTOC5_Str_general;
extern DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC5_Str_q;
extern DataAttribute iedModel_PROT_IPTOC5_Str_t;

extern DataObject    iedModel_PROT_IPTOC5_Op;
extern DataAttribute iedModel_PROT_IPTOC5_Op_general;
extern DataAttribute iedModel_PROT_IPTOC5_Op_q;
extern DataAttribute iedModel_PROT_IPTOC5_Op_t;

//----------------------------------------------------------------------------
// IPTOC6
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC6;

extern DataObject    iedModel_PROT_IPTOC6_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC6_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_stVal;
//extern DataAttribute iedModel_PROT_IPTOC6_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC6_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC6_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC6_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC6_Beh_t;

extern DataObject    iedModel_PROT_IPTOC6_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC6_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC6_Health_q;
extern DataAttribute iedModel_PROT_IPTOC6_Health_t;

extern DataObject    iedModel_PROT_IPTOC6_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC6_Str;
extern DataAttribute iedModel_PROT_IPTOC6_Str_general;
extern DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC6_Str_q;
extern DataAttribute iedModel_PROT_IPTOC6_Str_t;

extern DataObject    iedModel_PROT_IPTOC6_Op;
extern DataAttribute iedModel_PROT_IPTOC6_Op_general;
extern DataAttribute iedModel_PROT_IPTOC6_Op_q;
extern DataAttribute iedModel_PROT_IPTOC6_Op_t;

//----------------------------------------------------------------------------
// IPTOC7
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC7;

extern DataObject    iedModel_PROT_IPTOC7_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC7_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_stVal;
//extern DataAttribute iedModel_PROT_IPTOC7_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC7_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC7_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC7_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC7_Beh_t;

extern DataObject    iedModel_PROT_IPTOC7_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC7_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC7_Health_q;
extern DataAttribute iedModel_PROT_IPTOC7_Health_t;

extern DataObject    iedModel_PROT_IPTOC7_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC7_Str;
extern DataAttribute iedModel_PROT_IPTOC7_Str_general;
extern DataAttribute iedModel_PROT_IPTOC7_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC7_Str_q;
extern DataAttribute iedModel_PROT_IPTOC7_Str_t;

extern DataObject    iedModel_PROT_IPTOC7_Op;
extern DataAttribute iedModel_PROT_IPTOC7_Op_general;
extern DataAttribute iedModel_PROT_IPTOC7_Op_q;
extern DataAttribute iedModel_PROT_IPTOC7_Op_t;

//----------------------------------------------------------------------------
// IPTOC8
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC8;

extern DataObject    iedModel_PROT_IPTOC8_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC8_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_stVal;
//extern DataAttribute iedModel_PROT_IPTOC8_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC8_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTOC8_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC8_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC8_Beh_t;

extern DataObject    iedModel_PROT_IPTOC8_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTOC8_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC8_Health_q;
extern DataAttribute iedModel_PROT_IPTOC8_Health_t;

extern DataObject    iedModel_PROT_IPTOC8_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC8_Str;
extern DataAttribute iedModel_PROT_IPTOC8_Str_general;
extern DataAttribute iedModel_PROT_IPTOC8_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC8_Str_q;
extern DataAttribute iedModel_PROT_IPTOC8_Str_t;

extern DataObject    iedModel_PROT_IPTOC8_Op;
extern DataAttribute iedModel_PROT_IPTOC8_Op_general;
extern DataAttribute iedModel_PROT_IPTOC8_Op_q;
extern DataAttribute iedModel_PROT_IPTOC8_Op_t;

//----------------------------------------------------------------------------
// I20PTOC1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC1;

extern DataObject    iedModel_PROT_I20PTOC1_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC1_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC1_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC1_Mod_stVal;
//extern DataAttribute iedModel_PROT_I20PTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_I20PTOC1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC1_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC1_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC1_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC1_Health_t;

extern DataObject    iedModel_PROT_I20PTOC1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC1_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC1_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC1_Str;
extern DataAttribute iedModel_PROT_I20PTOC1_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC1_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC1_Str_t;

extern DataObject    iedModel_PROT_I20PTOC1_Op;
extern DataAttribute iedModel_PROT_I20PTOC1_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC1_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC1_Op_t;

//----------------------------------------------------------------------------
// I20PTOC2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC2;

extern DataObject    iedModel_PROT_I20PTOC2_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC2_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC2_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC2_Mod_stVal;
//extern DataAttribute iedModel_PROT_I20PTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_I20PTOC2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC2_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC2_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC2_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC2_Health_t;

extern DataObject    iedModel_PROT_I20PTOC2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC2_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC2_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC2_Str;
extern DataAttribute iedModel_PROT_I20PTOC2_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC2_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC2_Str_t;

extern DataObject    iedModel_PROT_I20PTOC2_Op;
extern DataAttribute iedModel_PROT_I20PTOC2_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC2_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC2_Op_t;

//----------------------------------------------------------------------------
// I20PTOC3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC3;

extern DataObject    iedModel_PROT_I20PTOC3_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC3_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC3_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC3_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC3_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC3_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC3_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC3_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC3_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC3_Health_t;

extern DataObject    iedModel_PROT_I20PTOC3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC3_Str;
extern DataAttribute iedModel_PROT_I20PTOC3_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC3_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC3_Str_t;

extern DataObject    iedModel_PROT_I20PTOC3_Op;
extern DataAttribute iedModel_PROT_I20PTOC3_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC3_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC3_Op_t;

//----------------------------------------------------------------------------
// I20PTOC4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC4;

extern DataObject    iedModel_PROT_I20PTOC4_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC4_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC4_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC4_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC4_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC4_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC4_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC4_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC4_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC4_Health_t;

extern DataObject    iedModel_PROT_I20PTOC4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC4_Str;
extern DataAttribute iedModel_PROT_I20PTOC4_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC4_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC4_Str_t;

extern DataObject    iedModel_PROT_I20PTOC4_Op;
extern DataAttribute iedModel_PROT_I20PTOC4_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC4_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC4_Op_t;

//----------------------------------------------------------------------------
// I20PTOC5
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC5;

extern DataObject    iedModel_PROT_I20PTOC5_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC5_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC5_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC5_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC5_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC5_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC5_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC5_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC5_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC5_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC5_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC5_Health_t;

extern DataObject    iedModel_PROT_I20PTOC5_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC5_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC5_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC5_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC5_Str;
extern DataAttribute iedModel_PROT_I20PTOC5_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC5_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC5_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC5_Str_t;

extern DataObject    iedModel_PROT_I20PTOC5_Op;
extern DataAttribute iedModel_PROT_I20PTOC5_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC5_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC5_Op_t;

//----------------------------------------------------------------------------
// I20PTOC6
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC6;

extern DataObject    iedModel_PROT_I20PTOC6_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC6_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC6_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC6_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC6_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC6_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC6_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC6_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC6_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC6_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC6_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC6_Health_t;

extern DataObject    iedModel_PROT_I20PTOC6_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC6_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC6_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC6_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC6_Str;
extern DataAttribute iedModel_PROT_I20PTOC6_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC6_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC6_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC6_Str_t;

extern DataObject    iedModel_PROT_I20PTOC6_Op;
extern DataAttribute iedModel_PROT_I20PTOC6_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC6_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC6_Op_t;

//----------------------------------------------------------------------------
// I20PTOC7
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC7;

extern DataObject    iedModel_PROT_I20PTOC7_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC7_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC7_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC7_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC7_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC7_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC7_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC7_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC7_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC7_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC7_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC7_Health_t;

extern DataObject    iedModel_PROT_I20PTOC7_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC7_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC7_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC7_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC7_Str;
extern DataAttribute iedModel_PROT_I20PTOC7_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC7_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC7_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC7_Str_t;

extern DataObject    iedModel_PROT_I20PTOC7_Op;
extern DataAttribute iedModel_PROT_I20PTOC7_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC7_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC7_Op_t;

//----------------------------------------------------------------------------
// I20PTOC8
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I20PTOC8;

extern DataObject    iedModel_PROT_I20PTOC8_Mod;					// �����
extern DataAttribute iedModel_PROT_I20PTOC8_Mod_q;
extern DataAttribute iedModel_PROT_I20PTOC8_Mod_t;
extern DataAttribute iedModel_PROT_I20PTOC8_Mod_stVal;

extern DataObject    iedModel_PROT_I20PTOC8_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I20PTOC8_Beh_stVal;
extern DataAttribute iedModel_PROT_I20PTOC8_Beh_q;
extern DataAttribute iedModel_PROT_I20PTOC8_Beh_t;

extern DataObject    iedModel_PROT_I20PTOC8_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I20PTOC8_Health_stVal;
extern DataAttribute iedModel_PROT_I20PTOC8_Health_q;
extern DataAttribute iedModel_PROT_I20PTOC8_Health_t;

extern DataObject    iedModel_PROT_I20PTOC8_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I20PTOC8_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I20PTOC8_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I20PTOC8_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I20PTOC8_Str;
extern DataAttribute iedModel_PROT_I20PTOC8_Str_general;
extern DataAttribute iedModel_PROT_I20PTOC8_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I20PTOC8_Str_q;
extern DataAttribute iedModel_PROT_I20PTOC8_Str_t;

extern DataObject    iedModel_PROT_I20PTOC8_Op;
extern DataAttribute iedModel_PROT_I20PTOC8_Op_general;
extern DataAttribute iedModel_PROT_I20PTOC8_Op_q;
extern DataAttribute iedModel_PROT_I20PTOC8_Op_t;

//----------------------------------------------------------------------------
// I2I1PTOC1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_I2I1PTOC1;

extern DataObject    iedModel_PROT_I2I1PTOC1_Mod;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Mod_q;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Mod_t;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Mod_stVal;

extern DataObject    iedModel_PROT_I2I1PTOC1_Beh;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Beh_q;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Beh_t;

extern DataObject    iedModel_PROT_I2I1PTOC1_Health;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Health_q;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Health_t;

extern DataObject    iedModel_PROT_I2I1PTOC1_NamPlt;
extern DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_d;

extern DataObject    iedModel_PROT_I2I1PTOC1_Str;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Str_general;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Str_q;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Str_t;

extern DataObject    iedModel_PROT_I2I1PTOC1_Op;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Op_general;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Op_q;
extern DataAttribute iedModel_PROT_I2I1PTOC1_Op_t;

//----------------------------------------------------------------------------
// IARCPTOC
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IARCPTOC;

extern DataObject    iedModel_PROT_IARCPTOC_Mod;
extern DataAttribute iedModel_PROT_IARCPTOC_Mod_q;
extern DataAttribute iedModel_PROT_IARCPTOC_Mod_t;
extern DataAttribute iedModel_PROT_IARCPTOC_Mod_stVal;

extern DataObject    iedModel_PROT_IARCPTOC_Beh;
extern DataAttribute iedModel_PROT_IARCPTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_IARCPTOC_Beh_q;
extern DataAttribute iedModel_PROT_IARCPTOC_Beh_t;

extern DataObject    iedModel_PROT_IARCPTOC_Health;
extern DataAttribute iedModel_PROT_IARCPTOC_Health_stVal;
extern DataAttribute iedModel_PROT_IARCPTOC_Health_q;
extern DataAttribute iedModel_PROT_IARCPTOC_Health_t;

extern DataObject    iedModel_PROT_IARCPTOC_NamPlt;
extern DataAttribute iedModel_PROT_IARCPTOC_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IARCPTOC_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IARCPTOC_NamPlt_d;

extern DataObject    iedModel_PROT_IARCPTOC_Str;
extern DataAttribute iedModel_PROT_IARCPTOC_Str_general;
extern DataAttribute iedModel_PROT_IARCPTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IARCPTOC_Str_q;
extern DataAttribute iedModel_PROT_IARCPTOC_Str_t;

extern DataObject    iedModel_PROT_IARCPTOC_Op;
extern DataAttribute iedModel_PROT_IARCPTOC_Op_general;
extern DataAttribute iedModel_PROT_IARCPTOC_Op_q;
extern DataAttribute iedModel_PROT_IARCPTOC_Op_t;

//----------------------------------------------------------------------------
// IPTUC1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTUC1;

extern DataObject    iedModel_PROT_IPTUC1_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTUC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTUC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTUC1_Mod_stVal;
//extern DataAttribute iedModel_PROT_IPTUC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTUC1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IPTUC1_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTUC1_Beh_q;
extern DataAttribute iedModel_PROT_IPTUC1_Beh_t;

extern DataObject    iedModel_PROT_IPTUC1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IPTUC1_Health_stVal;
extern DataAttribute iedModel_PROT_IPTUC1_Health_q;
extern DataAttribute iedModel_PROT_IPTUC1_Health_t;

extern DataObject    iedModel_PROT_IPTUC1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IPTUC1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IPTUC1_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTUC1_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTUC1_Str;
extern DataAttribute iedModel_PROT_IPTUC1_Str_general;
extern DataAttribute iedModel_PROT_IPTUC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTUC1_Str_q;
extern DataAttribute iedModel_PROT_IPTUC1_Str_t;

extern DataObject    iedModel_PROT_IPTUC1_Op;
extern DataAttribute iedModel_PROT_IPTUC1_Op_general;
extern DataAttribute iedModel_PROT_IPTUC1_Op_q;
extern DataAttribute iedModel_PROT_IPTUC1_Op_t;
//----------------------------------------------------------------------------
// UPTOV1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTOV1;

extern DataObject    iedModel_PROT_UPTOV1_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_stVal;

extern DataObject    iedModel_PROT_UPTOV1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTOV1_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV1_Beh_t;

extern DataObject    iedModel_PROT_UPTOV1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTOV1_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Health_q;
extern DataAttribute iedModel_PROT_UPTOV1_Health_t;

extern DataObject    iedModel_PROT_UPTOV1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV1_Str;
extern DataAttribute iedModel_PROT_UPTOV1_Str_general;
extern DataAttribute iedModel_PROT_UPTOV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV1_Str_q;
extern DataAttribute iedModel_PROT_UPTOV1_Str_t;

extern DataObject    iedModel_PROT_UPTOV1_Op;
extern DataAttribute iedModel_PROT_UPTOV1_Op_general;
extern DataAttribute iedModel_PROT_UPTOV1_Op_q;
extern DataAttribute iedModel_PROT_UPTOV1_Op_t;

//----------------------------------------------------------------------------
// UPTOV2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTOV2;

extern DataObject    iedModel_PROT_UPTOV2_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_stVal;

extern DataObject    iedModel_PROT_UPTOV2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTOV2_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV2_Beh_t;

extern DataObject    iedModel_PROT_UPTOV2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTOV2_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Health_q;
extern DataAttribute iedModel_PROT_UPTOV2_Health_t;

extern DataObject    iedModel_PROT_UPTOV2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV2_Str;
extern DataAttribute iedModel_PROT_UPTOV2_Str_general;
extern DataAttribute iedModel_PROT_UPTOV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV2_Str_q;
extern DataAttribute iedModel_PROT_UPTOV2_Str_t;

extern DataObject    iedModel_PROT_UPTOV2_Op;
extern DataAttribute iedModel_PROT_UPTOV2_Op_general;
extern DataAttribute iedModel_PROT_UPTOV2_Op_q;
extern DataAttribute iedModel_PROT_UPTOV2_Op_t;

//----------------------------------------------------------------------------
// UPTOV3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTOV3;

extern DataObject    iedModel_PROT_UPTOV3_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_stVal;

extern DataObject    iedModel_PROT_UPTOV3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTOV3_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV3_Beh_t;

extern DataObject    iedModel_PROT_UPTOV3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTOV3_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Health_q;
extern DataAttribute iedModel_PROT_UPTOV3_Health_t;

extern DataObject    iedModel_PROT_UPTOV3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV3_Str;
extern DataAttribute iedModel_PROT_UPTOV3_Str_general;
extern DataAttribute iedModel_PROT_UPTOV3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV3_Str_q;
extern DataAttribute iedModel_PROT_UPTOV3_Str_t;

extern DataObject    iedModel_PROT_UPTOV3_Op;
extern DataAttribute iedModel_PROT_UPTOV3_Op_general;
extern DataAttribute iedModel_PROT_UPTOV3_Op_q;
extern DataAttribute iedModel_PROT_UPTOV3_Op_t;

//----------------------------------------------------------------------------
// UPTOV4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTOV4;

extern DataObject    iedModel_PROT_UPTOV4_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_stVal;

extern DataObject    iedModel_PROT_UPTOV4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTOV4_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV4_Beh_t;

extern DataObject    iedModel_PROT_UPTOV4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTOV4_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Health_q;
extern DataAttribute iedModel_PROT_UPTOV4_Health_t;

extern DataObject    iedModel_PROT_UPTOV4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV4_Str;
extern DataAttribute iedModel_PROT_UPTOV4_Str_general;
extern DataAttribute iedModel_PROT_UPTOV4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV4_Str_q;
extern DataAttribute iedModel_PROT_UPTOV4_Str_t;

extern DataObject    iedModel_PROT_UPTOV4_Op;
extern DataAttribute iedModel_PROT_UPTOV4_Op_general;
extern DataAttribute iedModel_PROT_UPTOV4_Op_q;
extern DataAttribute iedModel_PROT_UPTOV4_Op_t;

//----------------------------------------------------------------------------
// UPTUV1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTUV1;

extern DataObject    iedModel_PROT_UPTUV1_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_stVal;

extern DataObject    iedModel_PROT_UPTUV1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTUV1_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV1_Beh_t;

extern DataObject    iedModel_PROT_UPTUV1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTUV1_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Health_q;
extern DataAttribute iedModel_PROT_UPTUV1_Health_t;

extern DataObject    iedModel_PROT_UPTUV1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV1_Str;
extern DataAttribute iedModel_PROT_UPTUV1_Str_general;
extern DataAttribute iedModel_PROT_UPTUV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV1_Str_q;
extern DataAttribute iedModel_PROT_UPTUV1_Str_t;

extern DataObject    iedModel_PROT_UPTUV1_Op;
extern DataAttribute iedModel_PROT_UPTUV1_Op_general;
extern DataAttribute iedModel_PROT_UPTUV1_Op_q;
extern DataAttribute iedModel_PROT_UPTUV1_Op_t;

//----------------------------------------------------------------------------
// UPTUV2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTUV2;

extern DataObject    iedModel_PROT_UPTUV2_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_stVal;

extern DataObject    iedModel_PROT_UPTUV2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTUV2_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV2_Beh_t;

extern DataObject    iedModel_PROT_UPTUV2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTUV2_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Health_q;
extern DataAttribute iedModel_PROT_UPTUV2_Health_t;

extern DataObject    iedModel_PROT_UPTUV2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV2_Str;
extern DataAttribute iedModel_PROT_UPTUV2_Str_general;
extern DataAttribute iedModel_PROT_UPTUV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV2_Str_q;
extern DataAttribute iedModel_PROT_UPTUV2_Str_t;

extern DataObject    iedModel_PROT_UPTUV2_Op;
extern DataAttribute iedModel_PROT_UPTUV2_Op_general;
extern DataAttribute iedModel_PROT_UPTUV2_Op_q;
extern DataAttribute iedModel_PROT_UPTUV2_Op_t;

//----------------------------------------------------------------------------
// UPTUV3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTUV3;

extern DataObject    iedModel_PROT_UPTUV3_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_stVal;

extern DataObject    iedModel_PROT_UPTUV3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTUV3_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV3_Beh_t;

extern DataObject    iedModel_PROT_UPTUV3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTUV3_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Health_q;
extern DataAttribute iedModel_PROT_UPTUV3_Health_t;

extern DataObject    iedModel_PROT_UPTUV3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV3_Str;
extern DataAttribute iedModel_PROT_UPTUV3_Str_general;
extern DataAttribute iedModel_PROT_UPTUV3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV3_Str_q;
extern DataAttribute iedModel_PROT_UPTUV3_Str_t;

extern DataObject    iedModel_PROT_UPTUV3_Op;
extern DataAttribute iedModel_PROT_UPTUV3_Op_general;
extern DataAttribute iedModel_PROT_UPTUV3_Op_q;
extern DataAttribute iedModel_PROT_UPTUV3_Op_t;

//----------------------------------------------------------------------------
// UPTUV4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_UPTUV4;

extern DataObject    iedModel_PROT_UPTUV4_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_stVal;

extern DataObject    iedModel_PROT_UPTUV4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_UPTUV4_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV4_Beh_t;

extern DataObject    iedModel_PROT_UPTUV4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_UPTUV4_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Health_q;
extern DataAttribute iedModel_PROT_UPTUV4_Health_t;

extern DataObject    iedModel_PROT_UPTUV4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV4_Str;
extern DataAttribute iedModel_PROT_UPTUV4_Str_general;
extern DataAttribute iedModel_PROT_UPTUV4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV4_Str_q;
extern DataAttribute iedModel_PROT_UPTUV4_Str_t;

extern DataObject    iedModel_PROT_UPTUV4_Op;
extern DataAttribute iedModel_PROT_UPTUV4_Op_general;
extern DataAttribute iedModel_PROT_UPTUV4_Op_q;
extern DataAttribute iedModel_PROT_UPTUV4_Op_t;

//----------------------------------------------------------------------------
// PTOF1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTOF1;

extern DataObject    iedModel_PROT_PTOF1_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF1_Mod_q;
extern DataAttribute iedModel_PROT_PTOF1_Mod_t;
extern DataAttribute iedModel_PROT_PTOF1_Mod_stVal;

extern DataObject    iedModel_PROT_PTOF1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTOF1_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Beh_q;
extern DataAttribute iedModel_PROT_PTOF1_Beh_t;

extern DataObject    iedModel_PROT_PTOF1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTOF1_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Health_q;
extern DataAttribute iedModel_PROT_PTOF1_Health_t;

extern DataObject    iedModel_PROT_PTOF1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTOF1_Str;
extern DataAttribute iedModel_PROT_PTOF1_Str_general;
extern DataAttribute iedModel_PROT_PTOF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF1_Str_q;
extern DataAttribute iedModel_PROT_PTOF1_Str_t;

extern DataObject    iedModel_PROT_PTOF1_Op;
extern DataAttribute iedModel_PROT_PTOF1_Op_general;
extern DataAttribute iedModel_PROT_PTOF1_Op_q;
extern DataAttribute iedModel_PROT_PTOF1_Op_t;

//----------------------------------------------------------------------------
// PTOF2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTOF2;

extern DataObject    iedModel_PROT_PTOF2_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF2_Mod_q;
extern DataAttribute iedModel_PROT_PTOF2_Mod_t;
extern DataAttribute iedModel_PROT_PTOF2_Mod_stVal;

extern DataObject    iedModel_PROT_PTOF2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTOF2_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Beh_q;
extern DataAttribute iedModel_PROT_PTOF2_Beh_t;

extern DataObject    iedModel_PROT_PTOF2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTOF2_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Health_q;
extern DataAttribute iedModel_PROT_PTOF2_Health_t;

extern DataObject    iedModel_PROT_PTOF2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTOF2_Str;
extern DataAttribute iedModel_PROT_PTOF2_Str_general;
extern DataAttribute iedModel_PROT_PTOF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF2_Str_q;
extern DataAttribute iedModel_PROT_PTOF2_Str_t;

extern DataObject    iedModel_PROT_PTOF2_Op;
extern DataAttribute iedModel_PROT_PTOF2_Op_general;
extern DataAttribute iedModel_PROT_PTOF2_Op_q;
extern DataAttribute iedModel_PROT_PTOF2_Op_t;

//----------------------------------------------------------------------------
// PTOF3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTOF3;

extern DataObject    iedModel_PROT_PTOF3_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF3_Mod_q;
extern DataAttribute iedModel_PROT_PTOF3_Mod_t;
extern DataAttribute iedModel_PROT_PTOF3_Mod_stVal;

extern DataObject    iedModel_PROT_PTOF3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTOF3_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Beh_q;
extern DataAttribute iedModel_PROT_PTOF3_Beh_t;

extern DataObject    iedModel_PROT_PTOF3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTOF3_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Health_q;
extern DataAttribute iedModel_PROT_PTOF3_Health_t;

extern DataObject    iedModel_PROT_PTOF3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTOF3_Str;
extern DataAttribute iedModel_PROT_PTOF3_Str_general;
extern DataAttribute iedModel_PROT_PTOF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF3_Str_q;
extern DataAttribute iedModel_PROT_PTOF3_Str_t;

extern DataObject    iedModel_PROT_PTOF3_Op;
extern DataAttribute iedModel_PROT_PTOF3_Op_general;
extern DataAttribute iedModel_PROT_PTOF3_Op_q;
extern DataAttribute iedModel_PROT_PTOF3_Op_t;

//----------------------------------------------------------------------------
// PTOF4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTOF4;

extern DataObject    iedModel_PROT_PTOF4_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF4_Mod_q;
extern DataAttribute iedModel_PROT_PTOF4_Mod_t;
extern DataAttribute iedModel_PROT_PTOF4_Mod_stVal;

extern DataObject    iedModel_PROT_PTOF4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTOF4_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Beh_q;
extern DataAttribute iedModel_PROT_PTOF4_Beh_t;

extern DataObject    iedModel_PROT_PTOF4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTOF4_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Health_q;
extern DataAttribute iedModel_PROT_PTOF4_Health_t;

extern DataObject    iedModel_PROT_PTOF4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTOF4_Str;
extern DataAttribute iedModel_PROT_PTOF4_Str_general;
extern DataAttribute iedModel_PROT_PTOF4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF4_Str_q;
extern DataAttribute iedModel_PROT_PTOF4_Str_t;

extern DataObject    iedModel_PROT_PTOF4_Op;
extern DataAttribute iedModel_PROT_PTOF4_Op_general;
extern DataAttribute iedModel_PROT_PTOF4_Op_q;
extern DataAttribute iedModel_PROT_PTOF4_Op_t;

//----------------------------------------------------------------------------
// PTUF1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTUF1;

extern DataObject    iedModel_PROT_PTUF1_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF1_Mod_q;
extern DataAttribute iedModel_PROT_PTUF1_Mod_t;
extern DataAttribute iedModel_PROT_PTUF1_Mod_stVal;

extern DataObject    iedModel_PROT_PTUF1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTUF1_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Beh_q;
extern DataAttribute iedModel_PROT_PTUF1_Beh_t;

extern DataObject    iedModel_PROT_PTUF1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTUF1_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Health_q;
extern DataAttribute iedModel_PROT_PTUF1_Health_t;

extern DataObject    iedModel_PROT_PTUF1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTUF1_Str;
extern DataAttribute iedModel_PROT_PTUF1_Str_general;
extern DataAttribute iedModel_PROT_PTUF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF1_Str_q;
extern DataAttribute iedModel_PROT_PTUF1_Str_t;

extern DataObject    iedModel_PROT_PTUF1_Op;
extern DataAttribute iedModel_PROT_PTUF1_Op_general;
extern DataAttribute iedModel_PROT_PTUF1_Op_q;
extern DataAttribute iedModel_PROT_PTUF1_Op_t;

//----------------------------------------------------------------------------
// PTUF2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTUF2;

extern DataObject    iedModel_PROT_PTUF2_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF2_Mod_q;
extern DataAttribute iedModel_PROT_PTUF2_Mod_t;
extern DataAttribute iedModel_PROT_PTUF2_Mod_stVal;

extern DataObject    iedModel_PROT_PTUF2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTUF2_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Beh_q;
extern DataAttribute iedModel_PROT_PTUF2_Beh_t;

extern DataObject    iedModel_PROT_PTUF2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTUF2_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Health_q;
extern DataAttribute iedModel_PROT_PTUF2_Health_t;

extern DataObject    iedModel_PROT_PTUF2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTUF2_Str;
extern DataAttribute iedModel_PROT_PTUF2_Str_general;
extern DataAttribute iedModel_PROT_PTUF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF2_Str_q;
extern DataAttribute iedModel_PROT_PTUF2_Str_t;

extern DataObject    iedModel_PROT_PTUF2_Op;
extern DataAttribute iedModel_PROT_PTUF2_Op_general;
extern DataAttribute iedModel_PROT_PTUF2_Op_q;
extern DataAttribute iedModel_PROT_PTUF2_Op_t;

//----------------------------------------------------------------------------
// PTUF3
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTUF3;

extern DataObject    iedModel_PROT_PTUF3_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF3_Mod_q;
extern DataAttribute iedModel_PROT_PTUF3_Mod_t;
extern DataAttribute iedModel_PROT_PTUF3_Mod_stVal;

extern DataObject    iedModel_PROT_PTUF3_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTUF3_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Beh_q;
extern DataAttribute iedModel_PROT_PTUF3_Beh_t;

extern DataObject    iedModel_PROT_PTUF3_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTUF3_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Health_q;
extern DataAttribute iedModel_PROT_PTUF3_Health_t;

extern DataObject    iedModel_PROT_PTUF3_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTUF3_Str;
extern DataAttribute iedModel_PROT_PTUF3_Str_general;
extern DataAttribute iedModel_PROT_PTUF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF3_Str_q;
extern DataAttribute iedModel_PROT_PTUF3_Str_t;

extern DataObject    iedModel_PROT_PTUF3_Op;
extern DataAttribute iedModel_PROT_PTUF3_Op_general;
extern DataAttribute iedModel_PROT_PTUF3_Op_q;
extern DataAttribute iedModel_PROT_PTUF3_Op_t;

//----------------------------------------------------------------------------
// PTUF4
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PTUF4;

extern DataObject    iedModel_PROT_PTUF4_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF4_Mod_q;
extern DataAttribute iedModel_PROT_PTUF4_Mod_t;
extern DataAttribute iedModel_PROT_PTUF4_Mod_stVal;

extern DataObject    iedModel_PROT_PTUF4_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PTUF4_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Beh_q;
extern DataAttribute iedModel_PROT_PTUF4_Beh_t;

extern DataObject    iedModel_PROT_PTUF4_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PTUF4_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Health_q;
extern DataAttribute iedModel_PROT_PTUF4_Health_t;

extern DataObject    iedModel_PROT_PTUF4_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PTUF4_Str;
extern DataAttribute iedModel_PROT_PTUF4_Str_general;
extern DataAttribute iedModel_PROT_PTUF4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF4_Str_q;
extern DataAttribute iedModel_PROT_PTUF4_Str_t;

extern DataObject    iedModel_PROT_PTUF4_Op;
extern DataAttribute iedModel_PROT_PTUF4_Op_general;
extern DataAttribute iedModel_PROT_PTUF4_Op_q;
extern DataAttribute iedModel_PROT_PTUF4_Op_t;

// ����� ��� ����������� ����, ������� ������� �� 61805-7-4 ������ ��� �����

//----------------------------------------------------------------------------
// PDPR1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDPR1;

extern DataObject    iedModel_PROT_PDPR1_Mod;
extern DataAttribute iedModel_PROT_PDPR1_Mod_q;
extern DataAttribute iedModel_PROT_PDPR1_Mod_t;
extern DataAttribute iedModel_PROT_PDPR1_Mod_stVal;

extern DataObject    iedModel_PROT_PDPR1_Beh;
extern DataAttribute iedModel_PROT_PDPR1_Beh_stVal;
extern DataAttribute iedModel_PROT_PDPR1_Beh_q;
extern DataAttribute iedModel_PROT_PDPR1_Beh_t;

extern DataObject    iedModel_PROT_PDPR1_Health;
extern DataAttribute iedModel_PROT_PDPR1_Health_stVal;
extern DataAttribute iedModel_PROT_PDPR1_Health_q;
extern DataAttribute iedModel_PROT_PDPR1_Health_t;

extern DataObject    iedModel_PROT_PDPR1_NamPlt;
extern DataAttribute iedModel_PROT_PDPR1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDPR1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDPR1_NamPlt_d;

extern DataObject    iedModel_PROT_PDPR1_Str;
extern DataAttribute iedModel_PROT_PDPR1_Str_general;
extern DataAttribute iedModel_PROT_PDPR1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDPR1_Str_q;
extern DataAttribute iedModel_PROT_PDPR1_Str_t;

extern DataObject    iedModel_PROT_PDPR1_Op;
extern DataAttribute iedModel_PROT_PDPR1_Op_general;
extern DataAttribute iedModel_PROT_PDPR1_Op_q;
extern DataAttribute iedModel_PROT_PDPR1_Op_t;

//----------------------------------------------------------------------------
// PDPR2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDPR2;

extern DataObject    iedModel_PROT_PDPR2_Mod;
extern DataAttribute iedModel_PROT_PDPR2_Mod_q;
extern DataAttribute iedModel_PROT_PDPR2_Mod_t;
extern DataAttribute iedModel_PROT_PDPR2_Mod_stVal;

extern DataObject    iedModel_PROT_PDPR2_Beh;
extern DataAttribute iedModel_PROT_PDPR2_Beh_stVal;
extern DataAttribute iedModel_PROT_PDPR2_Beh_q;
extern DataAttribute iedModel_PROT_PDPR2_Beh_t;

extern DataObject    iedModel_PROT_PDPR2_Health;
extern DataAttribute iedModel_PROT_PDPR2_Health_stVal;
extern DataAttribute iedModel_PROT_PDPR2_Health_q;
extern DataAttribute iedModel_PROT_PDPR2_Health_t;

extern DataObject    iedModel_PROT_PDPR2_NamPlt;
extern DataAttribute iedModel_PROT_PDPR2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDPR2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDPR2_NamPlt_d;

extern DataObject    iedModel_PROT_PDPR2_Str;
extern DataAttribute iedModel_PROT_PDPR2_Str_general;
extern DataAttribute iedModel_PROT_PDPR2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDPR2_Str_q;
extern DataAttribute iedModel_PROT_PDPR2_Str_t;

extern DataObject    iedModel_PROT_PDPR2_Op;
extern DataAttribute iedModel_PROT_PDPR2_Op_general;
extern DataAttribute iedModel_PROT_PDPR2_Op_q;
extern DataAttribute iedModel_PROT_PDPR2_Op_t;


/***************************************
// ����� ��� ����������� ����, ������� ������� �� 61805-7-4 ������ ��� �����
//----------------------------------------------------------------------------
// PDOP1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDOP1;

extern DataObject    iedModel_PROT_PDOP1_Mod;					// �����
extern DataAttribute iedModel_PROT_PDOP1_Mod_q;
extern DataAttribute iedModel_PROT_PDOP1_Mod_t;
extern DataAttribute iedModel_PROT_PDOP1_Mod_stVal;

extern DataObject    iedModel_PROT_PDOP1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PDOP1_Beh_stVal;
extern DataAttribute iedModel_PROT_PDOP1_Beh_q;
extern DataAttribute iedModel_PROT_PDOP1_Beh_t;

extern DataObject    iedModel_PROT_PDOP1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PDOP1_Health_stVal;
extern DataAttribute iedModel_PROT_PDOP1_Health_q;
extern DataAttribute iedModel_PROT_PDOP1_Health_t;

extern DataObject    iedModel_PROT_PDOP1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PDOP1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PDOP1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PDOP1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PDOP1_Str;
extern DataAttribute iedModel_PROT_PDOP1_Str_general;
extern DataAttribute iedModel_PROT_PDOP1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDOP1_Str_q;
extern DataAttribute iedModel_PROT_PDOP1_Str_t;

extern DataObject    iedModel_PROT_PDOP1_Op;
extern DataAttribute iedModel_PROT_PDOP1_Op_general;
extern DataAttribute iedModel_PROT_PDOP1_Op_q;
extern DataAttribute iedModel_PROT_PDOP1_Op_t;
//----------------------------------------------------------------------------
// PDOP2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDOP2;

extern DataObject    iedModel_PROT_PDOP2_Mod;					// �����
extern DataAttribute iedModel_PROT_PDOP2_Mod_q;
extern DataAttribute iedModel_PROT_PDOP2_Mod_t;
extern DataAttribute iedModel_PROT_PDOP2_Mod_stVal;

extern DataObject    iedModel_PROT_PDOP2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PDOP2_Beh_stVal;
extern DataAttribute iedModel_PROT_PDOP2_Beh_q;
extern DataAttribute iedModel_PROT_PDOP2_Beh_t;

extern DataObject    iedModel_PROT_PDOP2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PDOP2_Health_stVal;
extern DataAttribute iedModel_PROT_PDOP2_Health_q;
extern DataAttribute iedModel_PROT_PDOP2_Health_t;

extern DataObject    iedModel_PROT_PDOP2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PDOP2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PDOP2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PDOP2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PDOP2_Str;
extern DataAttribute iedModel_PROT_PDOP2_Str_general;
extern DataAttribute iedModel_PROT_PDOP2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDOP2_Str_q;
extern DataAttribute iedModel_PROT_PDOP2_Str_t;

extern DataObject    iedModel_PROT_PDOP2_Op;
extern DataAttribute iedModel_PROT_PDOP2_Op_general;
extern DataAttribute iedModel_PROT_PDOP2_Op_q;
extern DataAttribute iedModel_PROT_PDOP2_Op_t;

//----------------------------------------------------------------------------
// PDUP1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDUP1;

extern DataObject    iedModel_PROT_PDUP1_Mod;					// �����
extern DataAttribute iedModel_PROT_PDUP1_Mod_q;
extern DataAttribute iedModel_PROT_PDUP1_Mod_t;
extern DataAttribute iedModel_PROT_PDUP1_Mod_stVal;

extern DataObject    iedModel_PROT_PDUP1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PDUP1_Beh_stVal;
extern DataAttribute iedModel_PROT_PDUP1_Beh_q;
extern DataAttribute iedModel_PROT_PDUP1_Beh_t;

extern DataObject    iedModel_PROT_PDUP1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PDUP1_Health_stVal;
extern DataAttribute iedModel_PROT_PDUP1_Health_q;
extern DataAttribute iedModel_PROT_PDUP1_Health_t;

extern DataObject    iedModel_PROT_PDUP1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PDUP1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PDUP1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PDUP1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PDUP1_Str;
extern DataAttribute iedModel_PROT_PDUP1_Str_general;
extern DataAttribute iedModel_PROT_PDUP1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDUP1_Str_q;
extern DataAttribute iedModel_PROT_PDUP1_Str_t;

extern DataObject    iedModel_PROT_PDUP1_Op;
extern DataAttribute iedModel_PROT_PDUP1_Op_general;
extern DataAttribute iedModel_PROT_PDUP1_Op_q;
extern DataAttribute iedModel_PROT_PDUP1_Op_t;
//----------------------------------------------------------------------------
// PDUP2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_PDUP2;

extern DataObject    iedModel_PROT_PDUP2_Mod;					// �����
extern DataAttribute iedModel_PROT_PDUP2_Mod_q;
extern DataAttribute iedModel_PROT_PDUP2_Mod_t;
extern DataAttribute iedModel_PROT_PDUP2_Mod_stVal;

extern DataObject    iedModel_PROT_PDUP2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_PDUP2_Beh_stVal;
extern DataAttribute iedModel_PROT_PDUP2_Beh_q;
extern DataAttribute iedModel_PROT_PDUP2_Beh_t;

extern DataObject    iedModel_PROT_PDUP2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_PDUP2_Health_stVal;
extern DataAttribute iedModel_PROT_PDUP2_Health_q;
extern DataAttribute iedModel_PROT_PDUP2_Health_t;

extern DataObject    iedModel_PROT_PDUP2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_PDUP2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_PDUP2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_PDUP2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_PDUP2_Str;
extern DataAttribute iedModel_PROT_PDUP2_Str_general;
extern DataAttribute iedModel_PROT_PDUP2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDUP2_Str_q;
extern DataAttribute iedModel_PROT_PDUP2_Str_t;

extern DataObject    iedModel_PROT_PDUP2_Op;
extern DataAttribute iedModel_PROT_PDUP2_Op_general;
extern DataAttribute iedModel_PROT_PDUP2_Op_q;
extern DataAttribute iedModel_PROT_PDUP2_Op_t;
*/
//----------------------------------------------------------------------------
// BLKPTTR1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_BLKPTTR1;

extern DataObject iedModel_PROT_BLKPTTR1_Mod;
extern DataAttribute iedModel_PROT_BLKPTTR1_Mod_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_Mod_t;
extern DataAttribute iedModel_PROT_BLKPTTR1_Mod_stVal;

extern DataObject iedModel_PROT_BLKPTTR1_Beh;
extern DataAttribute iedModel_PROT_BLKPTTR1_Beh_stVal;
extern DataAttribute iedModel_PROT_BLKPTTR1_Beh_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_Beh_t;

extern DataObject iedModel_PROT_BLKPTTR1_Health;
extern DataAttribute iedModel_PROT_BLKPTTR1_Health_stVal;
extern DataAttribute iedModel_PROT_BLKPTTR1_Health_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_Health_t;

extern DataObject iedModel_PROT_BLKPTTR1_NamPlt;
extern DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_d;

extern DataObject iedModel_PROT_BLKPTTR1_TmpRI;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_mag;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_mag_f;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_instMag;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_instMag_f;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_t;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_db;
extern DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_zeroDb;
/*
extern DataObject iedModel_PROT_BLKPTTR1_Str;
extern DataAttribute iedModel_PROT_BLKPTTR1_Str_general;
extern DataAttribute iedModel_PROT_BLKPTTR1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_BLKPTTR1_Str_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_Str_t;
*/
extern DataObject iedModel_PROT_BLKPTTR1_Op;
extern DataAttribute iedModel_PROT_BLKPTTR1_Op_general;
extern DataAttribute iedModel_PROT_BLKPTTR1_Op_q;
extern DataAttribute iedModel_PROT_BLKPTTR1_Op_t;

//----------------------------------------------------------------------------
// QPTTR1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_QPTTR1;

extern DataObject iedModel_PROT_QPTTR1_Mod;
extern DataAttribute iedModel_PROT_QPTTR1_Mod_q;
extern DataAttribute iedModel_PROT_QPTTR1_Mod_t;
extern DataAttribute iedModel_PROT_QPTTR1_Mod_stVal;

extern DataObject iedModel_PROT_QPTTR1_Beh;
extern DataAttribute iedModel_PROT_QPTTR1_Beh_stVal;
extern DataAttribute iedModel_PROT_QPTTR1_Beh_q;
extern DataAttribute iedModel_PROT_QPTTR1_Beh_t;

extern DataObject iedModel_PROT_QPTTR1_Health;
extern DataAttribute iedModel_PROT_QPTTR1_Health_stVal;
extern DataAttribute iedModel_PROT_QPTTR1_Health_q;
extern DataAttribute iedModel_PROT_QPTTR1_Health_t;

extern DataObject iedModel_PROT_QPTTR1_NamPlt;
extern DataAttribute iedModel_PROT_QPTTR1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_QPTTR1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_QPTTR1_NamPlt_d;

extern DataObject iedModel_PROT_QPTTR1_TmpRI;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_mag;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_mag_f;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_instMag;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_instMag_f;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_q;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_t;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_db;
extern DataAttribute iedModel_PROT_QPTTR1_TmpRI_zeroDb;

extern DataObject iedModel_PROT_QPTTR1_Str;
extern DataAttribute iedModel_PROT_QPTTR1_Str_general;
extern DataAttribute iedModel_PROT_QPTTR1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_QPTTR1_Str_q;
extern DataAttribute iedModel_PROT_QPTTR1_Str_t;

extern DataObject iedModel_PROT_QPTTR1_Op;
extern DataAttribute iedModel_PROT_QPTTR1_Op_general;
extern DataAttribute iedModel_PROT_QPTTR1_Op_q;
extern DataAttribute iedModel_PROT_QPTTR1_Op_t;

//----------------------------------------------------------------------------
// QPTTR2
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_QPTTR2;

extern DataObject iedModel_PROT_QPTTR2_Mod;
extern DataAttribute iedModel_PROT_QPTTR2_Mod_q;
extern DataAttribute iedModel_PROT_QPTTR2_Mod_t;
extern DataAttribute iedModel_PROT_QPTTR2_Mod_stVal;

extern DataObject iedModel_PROT_QPTTR2_Beh;
extern DataAttribute iedModel_PROT_QPTTR2_Beh_stVal;
extern DataAttribute iedModel_PROT_QPTTR2_Beh_q;
extern DataAttribute iedModel_PROT_QPTTR2_Beh_t;

extern DataObject iedModel_PROT_QPTTR2_Health;
extern DataAttribute iedModel_PROT_QPTTR2_Health_stVal;
extern DataAttribute iedModel_PROT_QPTTR2_Health_q;
extern DataAttribute iedModel_PROT_QPTTR2_Health_t;

extern DataObject iedModel_PROT_QPTTR2_NamPlt;
extern DataAttribute iedModel_PROT_QPTTR2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_QPTTR2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_QPTTR2_NamPlt_d;

extern DataObject iedModel_PROT_QPTTR2_TmpRI;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_mag;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_mag_f;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_instMag;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_instMag_f;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_q;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_t;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_db;
extern DataAttribute iedModel_PROT_QPTTR2_TmpRI_zeroDb;

extern DataObject iedModel_PROT_QPTTR2_Str;
extern DataAttribute iedModel_PROT_QPTTR2_Str_general;
extern DataAttribute iedModel_PROT_QPTTR2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_QPTTR2_Str_q;
extern DataAttribute iedModel_PROT_QPTTR2_Str_t;

extern DataObject iedModel_PROT_QPTTR2_Op;
extern DataAttribute iedModel_PROT_QPTTR2_Op_general;
extern DataAttribute iedModel_PROT_QPTTR2_Op_q;
extern DataAttribute iedModel_PROT_QPTTR2_Op_t;

/*
//----------------------------------------------------------------------------
// LZSHPTOC
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_LZSHPTOC;

extern DataObject    iedModel_PROT_LZSHPTOC_Mod;					// �����
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_t;
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_stVal;

extern DataObject    iedModel_PROT_LZSHPTOC_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_t;

extern DataObject    iedModel_PROT_LZSHPTOC_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_stVal;
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_t;

extern DataObject    iedModel_PROT_LZSHPTOC_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_LZSHPTOC_Str;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_general;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_t;

extern DataObject    iedModel_PROT_LZSHPTOC_Op;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_general;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_t;
*/
//----------------------------------------------------------------------------
// RREC1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_RREC1;

extern DataObject    iedModel_PROT_RREC1_Mod;
extern DataAttribute iedModel_PROT_RREC1_Mod_q;
extern DataAttribute iedModel_PROT_RREC1_Mod_t;
extern DataAttribute iedModel_PROT_RREC1_Mod_stVal;

extern DataObject    iedModel_PROT_RREC1_Beh;
extern DataAttribute iedModel_PROT_RREC1_Beh_stVal;
extern DataAttribute iedModel_PROT_RREC1_Beh_q;
extern DataAttribute iedModel_PROT_RREC1_Beh_t;

extern DataObject    iedModel_PROT_RREC1_Health;
extern DataAttribute iedModel_PROT_RREC1_Health_stVal;
extern DataAttribute iedModel_PROT_RREC1_Health_q;
extern DataAttribute iedModel_PROT_RREC1_Health_t;

extern DataObject    iedModel_PROT_RREC1_NamPlt;
extern DataAttribute iedModel_PROT_RREC1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_RREC1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_RREC1_NamPlt_d;

extern DataObject 	  iedModel_PROT_RREC1_AutoRecSt;
extern DataAttribute iedModel_PROT_RREC1_AutoRecSt_stVal;
extern DataAttribute iedModel_PROT_RREC1_AutoRecSt_q;
extern DataAttribute iedModel_PROT_RREC1_AutoRecSt_t;

extern DataObject    iedModel_PROT_RREC1_Op;
extern DataAttribute iedModel_PROT_RREC1_Op_general;
extern DataAttribute iedModel_PROT_RREC1_Op_q;
extern DataAttribute iedModel_PROT_RREC1_Op_t;

//----------------------------------------------------------------------------
// RSYN1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_RSYN1;

extern DataObject iedModel_PROT_RSYN1_Mod;
extern DataAttribute iedModel_PROT_RSYN1_Mod_q;
extern DataAttribute iedModel_PROT_RSYN1_Mod_t;
extern DataAttribute iedModel_PROT_RSYN1_Mod_stVal;

extern DataObject iedModel_PROT_RSYN1_Beh;
extern DataAttribute iedModel_PROT_RSYN1_Beh_stVal;
extern DataAttribute iedModel_PROT_RSYN1_Beh_q;
extern DataAttribute iedModel_PROT_RSYN1_Beh_t;

extern DataObject iedModel_PROT_RSYN1_Health;
extern DataAttribute iedModel_PROT_RSYN1_Health_stVal;
extern DataAttribute iedModel_PROT_RSYN1_Health_q;
extern DataAttribute iedModel_PROT_RSYN1_Health_t;

extern DataObject iedModel_PROT_RSYN1_NamPlt;
extern DataAttribute iedModel_PROT_RSYN1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_RSYN1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_RSYN1_NamPlt_d;

extern DataObject iedModel_PROT_RSYN1_Rel;
extern DataAttribute iedModel_PROT_RSYN1_Rel_stVal;
extern DataAttribute iedModel_PROT_RSYN1_Rel_q;
extern DataAttribute iedModel_PROT_RSYN1_Rel_t;

extern DataObject iedModel_PROT_RSYN1_DifVCIc;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_mag;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_mag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_instMag;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_instMag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_q;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_t;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_db;
extern DataAttribute iedModel_PROT_RSYN1_DifVCIc_zeroDb;

extern DataObject iedModel_PROT_RSYN1_DifHzCIc;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_mag;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_mag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_instMag;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_instMag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_q;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_t;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_db;
extern DataAttribute iedModel_PROT_RSYN1_DifHzCIc_zeroDb;

extern DataObject iedModel_PROT_RSYN1_DifAngCIc;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_mag;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_mag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_instMag;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_instMag_f;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_q;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_t;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_db;
extern DataAttribute iedModel_PROT_RSYN1_DifAngCIc_zeroDb;

//----------------------------------------------------------------------------
// RBRF1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_RBRF1;

extern DataObject    iedModel_PROT_RBRF1_Mod;					// �����
extern DataAttribute iedModel_PROT_RBRF1_Mod_q;
extern DataAttribute iedModel_PROT_RBRF1_Mod_t;
extern DataAttribute iedModel_PROT_RBRF1_Mod_stVal;

extern DataObject    iedModel_PROT_RBRF1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_RBRF1_Beh_stVal;
extern DataAttribute iedModel_PROT_RBRF1_Beh_q;
extern DataAttribute iedModel_PROT_RBRF1_Beh_t;

extern DataObject    iedModel_PROT_RBRF1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_RBRF1_Health_stVal;
extern DataAttribute iedModel_PROT_RBRF1_Health_q;
extern DataAttribute iedModel_PROT_RBRF1_Health_t;

extern DataObject    iedModel_PROT_RBRF1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_RBRF1_OpEx;
extern DataAttribute iedModel_PROT_RBRF1_OpEx_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx_t;

extern DataObject iedModel_PROT_RBRF1_OpIn;
extern DataAttribute iedModel_PROT_RBRF1_OpIn_general;
extern DataAttribute iedModel_PROT_RBRF1_OpIn_q;
extern DataAttribute iedModel_PROT_RBRF1_OpIn_t;
/*
//----------------------------------------------------------------------------
// RBRF2
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_RBRF2;

extern DataObject    iedModel_PROT_RBRF2_Mod;					// �����
extern DataAttribute iedModel_PROT_RBRF2_Mod_q;
extern DataAttribute iedModel_PROT_RBRF2_Mod_t;
extern DataAttribute iedModel_PROT_RBRF2_Mod_stVal;

extern DataObject    iedModel_PROT_RBRF2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_RBRF2_Beh_stVal;
extern DataAttribute iedModel_PROT_RBRF2_Beh_q;
extern DataAttribute iedModel_PROT_RBRF2_Beh_t;

extern DataObject    iedModel_PROT_RBRF2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_RBRF2_Health_stVal;
extern DataAttribute iedModel_PROT_RBRF2_Health_q;
extern DataAttribute iedModel_PROT_RBRF2_Health_t;

extern DataObject    iedModel_PROT_RBRF2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_RBRF2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_RBRF2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_RBRF2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_RBRF2_OpEx;
extern DataAttribute iedModel_PROT_RBRF2_OpEx_general;
extern DataAttribute iedModel_PROT_RBRF2_OpEx_q;
extern DataAttribute iedModel_PROT_RBRF2_OpEx_t;
*/
//----------------------------------------------------------------------------
// BLKRBRF
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_BLKRBRF;

extern DataObject    iedModel_PROT_BLKRBRF_Mod;					// �����
extern DataAttribute iedModel_PROT_BLKRBRF_Mod_q;
extern DataAttribute iedModel_PROT_BLKRBRF_Mod_t;
extern DataAttribute iedModel_PROT_BLKRBRF_Mod_stVal;

extern DataObject    iedModel_PROT_BLKRBRF_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_BLKRBRF_Beh_stVal;
extern DataAttribute iedModel_PROT_BLKRBRF_Beh_q;
extern DataAttribute iedModel_PROT_BLKRBRF_Beh_t;

extern DataObject    iedModel_PROT_BLKRBRF_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_BLKRBRF_Health_stVal;
extern DataAttribute iedModel_PROT_BLKRBRF_Health_q;
extern DataAttribute iedModel_PROT_BLKRBRF_Health_t;

extern DataObject    iedModel_PROT_BLKRBRF_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_BLKRBRF_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_BLKRBRF_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_BLKRBRF_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_BLKRBRF_OpEx;
extern DataAttribute iedModel_PROT_BLKRBRF_OpEx_general;
extern DataAttribute iedModel_PROT_BLKRBRF_OpEx_q;
extern DataAttribute iedModel_PROT_BLKRBRF_OpEx_t;

//----------------------------------------------------------------------------
// RPSB1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_RPSB1;

extern DataObject iedModel_PROT_RPSB1_Mod;
extern DataAttribute iedModel_PROT_RPSB1_Mod_q;
extern DataAttribute iedModel_PROT_RPSB1_Mod_t;
extern DataAttribute iedModel_PROT_RPSB1_Mod_stVal;

extern DataObject iedModel_PROT_RPSB1_Beh;
extern DataAttribute iedModel_PROT_RPSB1_Beh_stVal;
extern DataAttribute iedModel_PROT_RPSB1_Beh_q;
extern DataAttribute iedModel_PROT_RPSB1_Beh_t;

extern DataObject iedModel_PROT_RPSB1_Health;
extern DataAttribute iedModel_PROT_RPSB1_Health_stVal;
extern DataAttribute iedModel_PROT_RPSB1_Health_q;
extern DataAttribute iedModel_PROT_RPSB1_Health_t;

extern DataObject iedModel_PROT_RPSB1_NamPlt;
extern DataAttribute iedModel_PROT_RPSB1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_RPSB1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_RPSB1_NamPlt_d;

extern DataObject iedModel_PROT_RPSB1_Str;
extern DataAttribute iedModel_PROT_RPSB1_Str_general;
extern DataAttribute iedModel_PROT_RPSB1_Str_q;
extern DataAttribute iedModel_PROT_RPSB1_Str_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn1;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn1_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn1_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn1_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn2;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn2_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn2_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn2_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn3;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn3_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn3_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn3_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn4;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn4_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn4_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn4_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn5;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn5_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn5_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn5_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn6;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn6_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn6_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn6_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn7;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn7_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn7_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn7_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn8;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn8_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn8_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn8_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn9;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn9_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn9_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn9_t;

extern DataObject iedModel_PROT_RPSB1_BlkZn10;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn10_general;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn10_q;
extern DataAttribute iedModel_PROT_RPSB1_BlkZn10_t;
//----------------------------------------------------------------------------
// PDIS1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS1;

extern DataObject iedModel_PROT_PDIS1_Mod;
extern DataAttribute iedModel_PROT_PDIS1_Mod_q;
extern DataAttribute iedModel_PROT_PDIS1_Mod_t;
extern DataAttribute iedModel_PROT_PDIS1_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS1_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS1_Beh;
extern DataAttribute iedModel_PROT_PDIS1_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS1_Beh_q;
extern DataAttribute iedModel_PROT_PDIS1_Beh_t;

extern DataObject iedModel_PROT_PDIS1_Health;
extern DataAttribute iedModel_PROT_PDIS1_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS1_Health_q;
extern DataAttribute iedModel_PROT_PDIS1_Health_t;

extern DataObject iedModel_PROT_PDIS1_NamPlt;
extern DataAttribute iedModel_PROT_PDIS1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS1_NamPlt_d;

extern DataObject iedModel_PROT_PDIS1_Op;
extern DataAttribute iedModel_PROT_PDIS1_Op_general;
extern DataAttribute iedModel_PROT_PDIS1_Op_q;
extern DataAttribute iedModel_PROT_PDIS1_Op_t;

extern DataObject iedModel_PROT_PDIS1_Str;
extern DataAttribute iedModel_PROT_PDIS1_Str_general;
extern DataAttribute iedModel_PROT_PDIS1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS1_Str_q;
extern DataAttribute iedModel_PROT_PDIS1_Str_t;

//----------------------------------------------------------------------------
// PDIS1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS2;

extern DataObject iedModel_PROT_PDIS2_Mod;
extern DataAttribute iedModel_PROT_PDIS2_Mod_q;
extern DataAttribute iedModel_PROT_PDIS2_Mod_t;
extern DataAttribute iedModel_PROT_PDIS2_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS2_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS2_Beh;
extern DataAttribute iedModel_PROT_PDIS2_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS2_Beh_q;
extern DataAttribute iedModel_PROT_PDIS2_Beh_t;

extern DataObject iedModel_PROT_PDIS2_Health;
extern DataAttribute iedModel_PROT_PDIS2_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS2_Health_q;
extern DataAttribute iedModel_PROT_PDIS2_Health_t;

extern DataObject iedModel_PROT_PDIS2_NamPlt;
extern DataAttribute iedModel_PROT_PDIS2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS2_NamPlt_d;

extern DataObject iedModel_PROT_PDIS2_Op;
extern DataAttribute iedModel_PROT_PDIS2_Op_general;
extern DataAttribute iedModel_PROT_PDIS2_Op_q;
extern DataAttribute iedModel_PROT_PDIS2_Op_t;

extern DataObject iedModel_PROT_PDIS2_Str;
extern DataAttribute iedModel_PROT_PDIS2_Str_general;
extern DataAttribute iedModel_PROT_PDIS2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS2_Str_q;
extern DataAttribute iedModel_PROT_PDIS2_Str_t;

//----------------------------------------------------------------------------
// PDIS1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS3;

extern DataObject iedModel_PROT_PDIS3_Mod;
extern DataAttribute iedModel_PROT_PDIS3_Mod_q;
extern DataAttribute iedModel_PROT_PDIS3_Mod_t;
extern DataAttribute iedModel_PROT_PDIS3_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS3_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS3_Beh;
extern DataAttribute iedModel_PROT_PDIS3_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS3_Beh_q;
extern DataAttribute iedModel_PROT_PDIS3_Beh_t;

extern DataObject iedModel_PROT_PDIS3_Health;
extern DataAttribute iedModel_PROT_PDIS3_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS3_Health_q;
extern DataAttribute iedModel_PROT_PDIS3_Health_t;

extern DataObject iedModel_PROT_PDIS3_NamPlt;
extern DataAttribute iedModel_PROT_PDIS3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS3_NamPlt_d;

extern DataObject iedModel_PROT_PDIS3_Op;
extern DataAttribute iedModel_PROT_PDIS3_Op_general;
extern DataAttribute iedModel_PROT_PDIS3_Op_q;
extern DataAttribute iedModel_PROT_PDIS3_Op_t;

extern DataObject iedModel_PROT_PDIS3_Str;
extern DataAttribute iedModel_PROT_PDIS3_Str_general;
extern DataAttribute iedModel_PROT_PDIS3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS3_Str_q;
extern DataAttribute iedModel_PROT_PDIS3_Str_t;

//----------------------------------------------------------------------------
// PDIS4
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS4;

extern DataObject iedModel_PROT_PDIS4_Mod;
extern DataAttribute iedModel_PROT_PDIS4_Mod_q;
extern DataAttribute iedModel_PROT_PDIS4_Mod_t;
extern DataAttribute iedModel_PROT_PDIS4_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS4_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS4_Beh;
extern DataAttribute iedModel_PROT_PDIS4_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS4_Beh_q;
extern DataAttribute iedModel_PROT_PDIS4_Beh_t;

extern DataObject iedModel_PROT_PDIS4_Health;
extern DataAttribute iedModel_PROT_PDIS4_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS4_Health_q;
extern DataAttribute iedModel_PROT_PDIS4_Health_t;

extern DataObject iedModel_PROT_PDIS4_NamPlt;
extern DataAttribute iedModel_PROT_PDIS4_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS4_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS4_NamPlt_d;

extern DataObject iedModel_PROT_PDIS4_Op;
extern DataAttribute iedModel_PROT_PDIS4_Op_general;
extern DataAttribute iedModel_PROT_PDIS4_Op_q;
extern DataAttribute iedModel_PROT_PDIS4_Op_t;

extern DataObject iedModel_PROT_PDIS4_Str;
extern DataAttribute iedModel_PROT_PDIS4_Str_general;
extern DataAttribute iedModel_PROT_PDIS4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS4_Str_q;
extern DataAttribute iedModel_PROT_PDIS4_Str_t;

//----------------------------------------------------------------------------
// PDIS5
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS5;

extern DataObject iedModel_PROT_PDIS5_Mod;
extern DataAttribute iedModel_PROT_PDIS5_Mod_q;
extern DataAttribute iedModel_PROT_PDIS5_Mod_t;
extern DataAttribute iedModel_PROT_PDIS5_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS5_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS5_Beh;
extern DataAttribute iedModel_PROT_PDIS5_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS5_Beh_q;
extern DataAttribute iedModel_PROT_PDIS5_Beh_t;

extern DataObject iedModel_PROT_PDIS5_Health;
extern DataAttribute iedModel_PROT_PDIS5_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS5_Health_q;
extern DataAttribute iedModel_PROT_PDIS5_Health_t;

extern DataObject iedModel_PROT_PDIS5_NamPlt;
extern DataAttribute iedModel_PROT_PDIS5_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS5_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS5_NamPlt_d;

extern DataObject iedModel_PROT_PDIS5_Op;
extern DataAttribute iedModel_PROT_PDIS5_Op_general;
extern DataAttribute iedModel_PROT_PDIS5_Op_q;
extern DataAttribute iedModel_PROT_PDIS5_Op_t;

extern DataObject iedModel_PROT_PDIS5_Str;
extern DataAttribute iedModel_PROT_PDIS5_Str_general;
extern DataAttribute iedModel_PROT_PDIS5_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS5_Str_q;
extern DataAttribute iedModel_PROT_PDIS5_Str_t;
//----------------------------------------------------------------------------
// PDIS6
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PDIS6;

extern DataObject iedModel_PROT_PDIS6_Mod;
extern DataAttribute iedModel_PROT_PDIS6_Mod_q;
extern DataAttribute iedModel_PROT_PDIS6_Mod_t;
extern DataAttribute iedModel_PROT_PDIS6_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS6_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS6_Beh;
extern DataAttribute iedModel_PROT_PDIS6_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS6_Beh_q;
extern DataAttribute iedModel_PROT_PDIS6_Beh_t;

extern DataObject iedModel_PROT_PDIS6_Health;
extern DataAttribute iedModel_PROT_PDIS6_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS6_Health_q;
extern DataAttribute iedModel_PROT_PDIS6_Health_t;

extern DataObject iedModel_PROT_PDIS6_NamPlt;
extern DataAttribute iedModel_PROT_PDIS6_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS6_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS6_NamPlt_d;

extern DataObject iedModel_PROT_PDIS6_Op;
extern DataAttribute iedModel_PROT_PDIS6_Op_general;
extern DataAttribute iedModel_PROT_PDIS6_Op_q;
extern DataAttribute iedModel_PROT_PDIS6_Op_t;

extern DataObject iedModel_PROT_PDIS6_Str;
extern DataAttribute iedModel_PROT_PDIS6_Str_general;
extern DataAttribute iedModel_PROT_PDIS6_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS6_Str_q;
extern DataAttribute iedModel_PROT_PDIS6_Str_t;

//----------------------------------------------------------------------------
// VZGGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO1;

extern DataObject iedModel_PROT_VZGGIO1_Mod;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO1_Beh;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_t;

extern DataObject iedModel_PROT_VZGGIO1_Health;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_t;

extern DataObject iedModel_PROT_VZGGIO1_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO1_Alm;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO2
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO2;
extern DataObject iedModel_PROT_VZGGIO2_Mod;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO2_Beh;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_t;

extern DataObject iedModel_PROT_VZGGIO2_Health;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_t;

extern DataObject iedModel_PROT_VZGGIO2_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO2_Alm;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO3
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO3;

extern DataObject iedModel_PROT_VZGGIO3_Mod;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO3_Beh;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_t;

extern DataObject iedModel_PROT_VZGGIO3_Health;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_t;

extern DataObject iedModel_PROT_VZGGIO3_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO3_Alm;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO4
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO4;
extern DataObject iedModel_PROT_VZGGIO4_Mod;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO4_Beh;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_t;

extern DataObject iedModel_PROT_VZGGIO4_Health;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_t;

extern DataObject iedModel_PROT_VZGGIO4_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO4_Alm;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO5
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO5;
extern DataObject iedModel_PROT_VZGGIO5_Mod;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO5_Beh;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_t;

extern DataObject iedModel_PROT_VZGGIO5_Health;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_t;

extern DataObject iedModel_PROT_VZGGIO5_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO5_Alm;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO6
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO6;
extern DataObject iedModel_PROT_VZGGIO6_Mod;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO6_Beh;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_t;

extern DataObject iedModel_PROT_VZGGIO6_Health;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_t;

extern DataObject iedModel_PROT_VZGGIO6_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO6_Alm;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO7
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO7;
extern DataObject iedModel_PROT_VZGGIO7_Mod;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO7_Beh;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_t;

extern DataObject iedModel_PROT_VZGGIO7_Health;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_t;

extern DataObject iedModel_PROT_VZGGIO7_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO7_Alm;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO8
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO8;
extern DataObject iedModel_PROT_VZGGIO8_Mod;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO8_Beh;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_t;

extern DataObject iedModel_PROT_VZGGIO8_Health;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_t;

extern DataObject iedModel_PROT_VZGGIO8_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO8_Alm;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO9
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO9;

extern DataObject iedModel_PROT_VZGGIO9_Mod;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO9_Beh;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_t;

extern DataObject iedModel_PROT_VZGGIO9_Health;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_t;

extern DataObject iedModel_PROT_VZGGIO9_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO9_Alm;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO10
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO10;

extern DataObject iedModel_PROT_VZGGIO10_Mod;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO10_Beh;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_t;

extern DataObject iedModel_PROT_VZGGIO10_Health;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_t;

extern DataObject iedModel_PROT_VZGGIO10_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO10_Alm;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO11
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO11;

extern DataObject iedModel_PROT_VZGGIO11_Mod;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO11_Beh;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_t;

extern DataObject iedModel_PROT_VZGGIO11_Health;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_t;

extern DataObject iedModel_PROT_VZGGIO11_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO11_Alm;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO12
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO12;

extern DataObject iedModel_PROT_VZGGIO12_Mod;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO12_Beh;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_t;

extern DataObject iedModel_PROT_VZGGIO12_Health;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_t;

extern DataObject iedModel_PROT_VZGGIO12_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO12_Alm;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO13
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO13;

extern DataObject iedModel_PROT_VZGGIO13_Mod;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO13_Beh;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_t;

extern DataObject iedModel_PROT_VZGGIO13_Health;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_t;

extern DataObject iedModel_PROT_VZGGIO13_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO13_Alm;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO14
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO14;

extern DataObject iedModel_PROT_VZGGIO14_Mod;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO14_Beh;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_t;

extern DataObject iedModel_PROT_VZGGIO14_Health;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_t;

extern DataObject iedModel_PROT_VZGGIO14_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO14_Alm;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO15
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO15;

extern DataObject iedModel_PROT_VZGGIO15_Mod;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO15_Beh;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_t;

extern DataObject iedModel_PROT_VZGGIO15_Health;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_t;

extern DataObject iedModel_PROT_VZGGIO15_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO15_Alm;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO16
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO16;

extern DataObject iedModel_PROT_VZGGIO16_Mod;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal;

extern DataObject iedModel_PROT_VZGGIO16_Beh;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_t;

extern DataObject iedModel_PROT_VZGGIO16_Health;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_t;

extern DataObject iedModel_PROT_VZGGIO16_NamPlt;
extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO16_Alm;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_t;

//----------------------------------------------------------------------------

extern DataObject iedModel_PROT_AVRGGIO_Mod;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_stVal;

extern DataObject iedModel_PROT_AVRGGIO_Beh;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_t;

extern DataObject iedModel_PROT_AVRGGIO_Health;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_t;

extern DataObject iedModel_PROT_AVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_AVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_t;

//----------------------------------------------------------------------------
// NBLKGGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_NBLKGGIO1;

extern DataObject iedModel_PROT_NBLKGGIO1_Mod;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Mod_q;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Mod_t;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Mod_stVal;
extern DataObject iedModel_PROT_NBLKGGIO1_Beh;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Beh_stVal;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Beh_q;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Beh_t;
extern DataObject iedModel_PROT_NBLKGGIO1_Health;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Health_stVal;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Health_q;
extern DataAttribute iedModel_PROT_NBLKGGIO1_Health_t;
extern DataObject iedModel_PROT_NBLKGGIO1_NamPlt;

extern DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_d;

extern DataObject iedModel_PROT_NBLKGGIO1_IntIn;
extern DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_stVal;
extern DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_q;
extern DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_t;

//----------------------------------------------------------------------------
// EBLKAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_EBLKAVRGGIO;

extern DataObject iedModel_PROT_EBLKAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_EBLKAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_EBLKAVRGGIO_Health;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_Health_t;
extern DataObject iedModel_PROT_EBLKAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_EBLKAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_EBLKAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_EBLKAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// READYAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_READYAVRGGIO;

extern DataObject iedModel_PROT_READYAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_READYAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_READYAVRGGIO_Health;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_READYAVRGGIO_Health_t;
extern DataObject iedModel_PROT_READYAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_READYAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_READYAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_READYAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_READYAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_READYAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_READYAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_READYAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// TRIPAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_TRIPAVRGGIO;

extern DataObject iedModel_PROT_TRIPAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_TRIPAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_TRIPAVRGGIO_Health;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_Health_t;
extern DataObject iedModel_PROT_TRIPAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_TRIPAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_TRIPAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_TRIPAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// CLAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_CLAVRGGIO;

extern DataObject iedModel_PROT_CLAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_CLAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_CLAVRGGIO_Health;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_CLAVRGGIO_Health_t;
extern DataObject iedModel_PROT_CLAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_CLAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_CLAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_CLAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_CLAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_CLAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_CLAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_CLAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// RCLAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_RCLAVRGGIO;

extern DataObject iedModel_PROT_RCLAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_RCLAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_RCLAVRGGIO_Health;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_Health_t;
extern DataObject iedModel_PROT_RCLAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_RCLAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_RCLAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_RCLAVRGGIO_IntIn_t;

//----------------------------------------------------------------------------
// RTRIPAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_RTRIPAVRGGIO;

extern DataObject iedModel_PROT_RTRIPAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_RTRIPAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_RTRIPAVRGGIO_Health;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_Health_t;
extern DataObject iedModel_PROT_RTRIPAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_RTRIPAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_RTRIPAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// PRAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_PRAVRGGIO;

extern DataObject iedModel_PROT_PRAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_PRAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_PRAVRGGIO_Health;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_PRAVRGGIO_Health_t;
extern DataObject iedModel_PROT_PRAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_PRAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PRAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PRAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_PRAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_PRAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_PRAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_PRAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// COMAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_COMAVRGGIO;

extern DataObject iedModel_PROT_COMAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_COMAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_COMAVRGGIO_Health;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_COMAVRGGIO_Health_t;
extern DataObject iedModel_PROT_COMAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_COMAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_COMAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_COMAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_COMAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_COMAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_COMAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_COMAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// POWAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_POWAVRGGIO;

extern DataObject iedModel_PROT_POWAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_POWAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_POWAVRGGIO_Health;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_POWAVRGGIO_Health_t;
extern DataObject iedModel_PROT_POWAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_POWAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_POWAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_POWAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_POWAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_POWAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_POWAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_POWAVRGGIO_IntIn_t;
//----------------------------------------------------------------------------
// SELFAVRGGIO
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_SELFAVRGGIO;

extern DataObject iedModel_PROT_SELFAVRGGIO_Mod;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Mod_stVal;
extern DataObject iedModel_PROT_SELFAVRGGIO_Beh;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Beh_t;
extern DataObject iedModel_PROT_SELFAVRGGIO_Health;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_Health_t;
extern DataObject iedModel_PROT_SELFAVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_SELFAVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_SELFAVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_SELFAVRGGIO_IntIn_t;
// ---------------------------------------------------------------------------------------------------------
//  00  00000  000    0
// 0      0    0  0   0
// 0      0    0  0   0
// 0      0    000    0
// 0      0    0 0    0
//  00    0    0  0   0000
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LLN0;								// ���������� ���� ����. ���: LLN0
extern DataObject    iedModel_CTRL_LLN0_Mod;							// Mod - �����
extern DataAttribute iedModel_CTRL_LLN0_Mod_q;
extern DataAttribute iedModel_CTRL_LLN0_Mod_t;
extern DataAttribute iedModel_CTRL_LLN0_Mod_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel;

extern DataObject    iedModel_CTRL_LLN0_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_CTRL_LLN0_Beh_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Beh_q;
extern DataAttribute iedModel_CTRL_LLN0_Beh_t;

extern DataObject    iedModel_CTRL_LLN0_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_CTRL_LLN0_Health_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Health_q;
extern DataAttribute iedModel_CTRL_LLN0_Health_t;

extern DataObject    iedModel_CTRL_LLN0_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_d;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_CTRL_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_CTRL_LLN0_SGCB_q;
extern DataAttribute iedModel_CTRL_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LPHD1;								// LPHD - ���������� � ���������� ����������. ������������: LPHD

extern DataObject    iedModel_CTRL_LPHD1_PhyNam;						// PhyNam - ���������� �������� ����������� ����������
extern DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_CTRL_LPHD1_PhyHealth;					// PhyHealth - ��������� ����������������� ����������� ����������
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t;

extern DataObject    iedModel_CTRL_LPHD1_Proxy;						// Proxy - ��������, ������ �� ������ LN �����������
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_q;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_t;

//----------------------------------------------------------------------------
// CSWI1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_CSWI1;
extern DataObject    iedModel_CTRL_CSWI1_Mod;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_q;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_t;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check;

// Beh
extern DataObject    iedModel_CTRL_CSWI1_Beh;					// ����� ������
extern DataAttribute iedModel_CTRL_CSWI1_Beh_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Beh_q;
extern DataAttribute iedModel_CTRL_CSWI1_Beh_t;

// Health
extern DataObject    iedModel_CTRL_CSWI1_Health;				// ��������� �����������������
extern DataAttribute iedModel_CTRL_CSWI1_Health_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Health_q;
extern DataAttribute iedModel_CTRL_CSWI1_Health_t;

// NamPlt
extern DataObject    iedModel_CTRL_CSWI1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev;		// 		������� ����������� �����
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_d;			//		��������� �������� ������ ����� ��������� � ����������� ���� LN CSWI1.

extern DataObject iedModel_CTRL_CSWI1_Pos;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_q;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_t;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check;

//----------------------------------------------------------------------------
// XCBR1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_XCBR1;
extern DataObject iedModel_CTRL_XCBR1_Mod;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_q;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_t;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check;

extern DataObject iedModel_CTRL_XCBR1_Beh;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_q;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_t;

extern DataObject iedModel_CTRL_XCBR1_Health;
extern DataAttribute iedModel_CTRL_XCBR1_Health_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Health_q;
extern DataAttribute iedModel_CTRL_XCBR1_Health_t;

extern DataObject iedModel_CTRL_XCBR1_NamPlt;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_d;

extern DataObject iedModel_CTRL_XCBR1_Pos;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_q;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_t;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel;

extern DataObject iedModel_CTRL_XCBR1_Loc;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_q;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_t;

extern DataObject iedModel_CTRL_XCBR1_OpCnt;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_q;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_t;

extern DataObject iedModel_CTRL_XCBR1_CBOpCap;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t;

extern DataObject iedModel_CTRL_XCBR1_BlkOpn;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check;

extern DataObject iedModel_CTRL_XCBR1_BlkCls;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_q;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_t;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check;

//----------------------------------------------------------------------------
// PTRC
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_PTRC;

extern DataObject iedModel_CTRL_PTRC_Mod;
extern DataAttribute iedModel_CTRL_PTRC_Mod_q;
extern DataAttribute iedModel_CTRL_PTRC_Mod_t;
extern DataAttribute iedModel_CTRL_PTRC_Mod_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel;

extern DataObject iedModel_CTRL_PTRC_Beh;
extern DataAttribute iedModel_CTRL_PTRC_Beh_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Beh_q;
extern DataAttribute iedModel_CTRL_PTRC_Beh_t;

extern DataObject iedModel_CTRL_PTRC_Health;
extern DataAttribute iedModel_CTRL_PTRC_Health_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Health_q;
extern DataAttribute iedModel_CTRL_PTRC_Health_t;

extern DataObject iedModel_CTRL_PTRC_NamPlt;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_d;

extern DataObject iedModel_CTRL_PTRC_Op;
extern DataAttribute iedModel_CTRL_PTRC_Op_general;
extern DataAttribute iedModel_CTRL_PTRC_Op_q;
extern DataAttribute iedModel_CTRL_PTRC_Op_t;

//----------------------------------------------------------------------------
// GGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_GGIO1;

extern DataObject iedModel_CTRL_GGIO1_Mod;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_q;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_t;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel;

extern DataObject iedModel_CTRL_GGIO1_Beh;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_q;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_t;

extern DataObject iedModel_CTRL_GGIO1_Health;
extern DataAttribute iedModel_CTRL_GGIO1_Health_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Health_q;
extern DataAttribute iedModel_CTRL_GGIO1_Health_t;

extern DataObject iedModel_CTRL_GGIO1_NamPlt;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_d;

extern DataObject iedModel_CTRL_GGIO1_SPCSO1;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check;

//SPCSO2
extern DataObject iedModel_CTRL_GGIO1_SPCSO2;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check;
//SPCSO3
extern DataObject iedModel_CTRL_GGIO1_SPCSO3;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check;

extern DataObject iedModel_CTRL_GGIO1_SPCSO4;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check;
// ---------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------
// GGIO2
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_GGIO2;

extern DataObject iedModel_CTRL_GGIO2_Mod;
extern DataAttribute iedModel_CTRL_GGIO2_Mod_q;
extern DataAttribute iedModel_CTRL_GGIO2_Mod_t;
extern DataAttribute iedModel_CTRL_GGIO2_Mod_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_Mod_ctlModel;

extern DataObject iedModel_CTRL_GGIO2_Beh;
extern DataAttribute iedModel_CTRL_GGIO2_Beh_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_Beh_q;
extern DataAttribute iedModel_CTRL_GGIO2_Beh_t;

extern DataObject iedModel_CTRL_GGIO2_Health;
extern DataAttribute iedModel_CTRL_GGIO2_Health_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_Health_q;
extern DataAttribute iedModel_CTRL_GGIO2_Health_t;

extern DataObject iedModel_CTRL_GGIO2_NamPlt;
extern DataAttribute iedModel_CTRL_GGIO2_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_GGIO2_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_GGIO2_NamPlt_d;

extern DataObject iedModel_CTRL_GGIO2_SPCSO1;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Check;

//SPCSO2
extern DataObject iedModel_CTRL_GGIO2_SPCSO2;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Check;
//SPCSO3
extern DataObject iedModel_CTRL_GGIO2_SPCSO3;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO4;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO5;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO6;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO7;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO8;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO9;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO10;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO11;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Check;

//SPCSO12
extern DataObject iedModel_CTRL_GGIO2_SPCSO12;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Check;
//SPCSO13
extern DataObject iedModel_CTRL_GGIO2_SPCSO13;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO14;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO15;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO16;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO17;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO18;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO19;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO20;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Check;


extern DataObject iedModel_CTRL_GGIO2_SPCSO21;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Check;

//SPCSO22
extern DataObject iedModel_CTRL_GGIO2_SPCSO22;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Check;
//SPCSO23
extern DataObject iedModel_CTRL_GGIO2_SPCSO23;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO24;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO25;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO26;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO27;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO28;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO29;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO30;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO31;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Check;

extern DataObject iedModel_CTRL_GGIO2_SPCSO32;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_q;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_t;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_d;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_stVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Check;

// ---------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------
//   000   000  000   00
//  0     0      0   0  0
//  0     0      0   0  0
//  0     0      0   0  0
//  0  0  0  0   0   0  0
//   000   000  000   00
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LLN0;								// ���������� ���� ����. ���: LLN0
extern DataObject    iedModel_GGIO_LLN0_Mod;							// Mod - �����
extern DataAttribute iedModel_GGIO_LLN0_Mod_q;
extern DataAttribute iedModel_GGIO_LLN0_Mod_t;
extern DataAttribute iedModel_GGIO_LLN0_Mod_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel;

extern DataObject    iedModel_GGIO_LLN0_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_GGIO_LLN0_Beh_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Beh_q;
extern DataAttribute iedModel_GGIO_LLN0_Beh_t;

extern DataObject    iedModel_GGIO_LLN0_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_GGIO_LLN0_Health_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Health_q;
extern DataAttribute iedModel_GGIO_LLN0_Health_t;

extern DataObject    iedModel_GGIO_LLN0_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_d;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_GGIO_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_GGIO_LLN0_SGCB_q;
extern DataAttribute iedModel_GGIO_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
// LPHD1
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LPHD1;								// LPHD - ���������� � ���������� ����������. ������������: LPHD

extern DataObject    iedModel_GGIO_LPHD1_PhyNam;						// PhyNam - ���������� �������� ����������� ����������
extern DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_GGIO_LPHD1_PhyHealth;					// PhyHealth - ��������� ����������������� ����������� ����������
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t;

extern DataObject    iedModel_GGIO_LPHD1_Proxy;						// Proxy - ��������, ������ �� ������ LN �����������
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_q;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------
// OUT
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_OUTGGIO1;								// GGIO - ����/����� ��� ����� ���������. ���: GGIO

extern DataObject    iedModel_GGIO_OUTGGIO1_Mod;							// Mod - �����
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel;

extern DataObject    iedModel_GGIO_OUTGGIO1_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d;

//SPCSO1
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
//SPCSO2
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
//SPCSO3
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
//SPCSO4
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
//SPCSO5
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
//SPCSO6
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
//SPCSO7
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
//SPCSO8
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
//SPCSO9
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;
//SPCSO10
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;
//SPCSO11
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;
//SPCSO12
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;
//SPCSO13
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;
//SPCSO14
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;
//SPCSO15
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;
//SPCSO16
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO16;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal;
//SPCSO17
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO17;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal;
//SPCSO18
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO18;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal;
//SPCSO19
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO19;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_stVal;
//SPCSO20
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO20;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_stVal;
//SPCSO21
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO21;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_stVal;
//SPCSO22
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO22;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_stVal;
//SPCSO23
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO23;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_stVal;
//SPCSO24
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO24;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_stVal;
//SPCSO25
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO25;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_stVal;
//SPCSO26
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO26;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_stVal;
//SPCSO27
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO27;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_stVal;
//SPCSO28
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO28;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_stVal;
//SPCSO29
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO29;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_stVal;
//SPCSO30
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO30;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_stVal;
//SPCSO31
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO31;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_stVal;
//SPCSO32
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO32;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_stVal;
//SPCSO33
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO33;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_stVal;
//SPCSO34
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO34;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_stVal;
//SPCSO35
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO35;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_stVal;
//SPCSO36
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO36;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_stVal;
//SPCSO37
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO37;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_stVal;
//SPCSO38
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO38;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_stVal;
//SPCSO39
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO39;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_stVal;
//SPCSO40
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO40;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_stVal;
//SPCSO41
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO41;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_stVal;
//SPCSO42
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO42;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_stVal;
//SPCSO43
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO43;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_stVal;
//SPCSO44
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO44;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_stVal;
//SPCSO45
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO45;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_stVal;
//SPCSO46
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO46;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_stVal;
//SPCSO47
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO47;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_stVal;
//SPCSO48
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO48;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_stVal;
//SPCSO49
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO49;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_stVal;
//SPCSO50
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO50;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_stVal;
//SPCSO51
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO51;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_stVal;
//SPCSO52
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO52;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_stVal;
//SPCSO53
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO53;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_stVal;
//SPCSO54
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO54;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_stVal;
//SPCSO55
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO55;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_stVal;
//SPCSO56
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO56;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_stVal;
//SPCSO57
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO57;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_stVal;
//SPCSO58
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO58;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_stVal;
//SPCSO59
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO59;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_stVal;
//SPCSO60
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO60;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_stVal;
//SPCSO61
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO61;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_stVal;
//SPCSO62
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO62;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_stVal;
//SPCSO63
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO63;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_stVal;
//SPCSO64
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO64;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_stVal;
//SPCSO65
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO65;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_stVal;
//SPCSO66
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO66;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_stVal;
//SPCSO67
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO67;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_stVal;
//SPCSO68
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO68;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_stVal;
//SPCSO69
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO69;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_stVal;
//SPCSO70
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO70;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_stVal;
//SPCSO71
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO71;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_stVal;
//SPCSO72
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO72;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_stVal;
//SPCSO73
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO73;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_stVal;
//SPCSO74
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO74;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_stVal;
//SPCSO75
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO75;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_stVal;
//SPCSO76
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO76;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_stVal;
//SPCSO77
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO77;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_stVal;
//SPCSO78
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO78;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_stVal;
//SPCSO79
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO79;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_stVal;
//SPCSO80
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO80;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_stVal;

// ---------------------------------------------------------------------------------------------------------
// LED
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LEDGGIO1;								// GGIO - ����/����� ��� ����� ���������. ���: GGIO

extern DataObject    iedModel_GGIO_LEDGGIO1_Mod;							// Mod - �����
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel;

extern DataObject    iedModel_GGIO_LEDGGIO1_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind1;							//Ind ���������
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_dU;

// ------------------------------------------------------------
// IN
// ------------------------------------------------------------

extern LogicalNode iedModel_GGIO_INGGIO1;

extern DataObject iedModel_GGIO_INGGIO1_Mod;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_T;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Test;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Check;
//Beh
extern DataObject iedModel_GGIO_INGGIO1_Beh;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_t;
//Health
extern DataObject iedModel_GGIO_INGGIO1_Health;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_t;
//NamPlt
extern DataObject iedModel_GGIO_INGGIO1_NamPlt;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d;
extern DataObject    iedModel_GGIO_INGGIO1_Ind1;							//Ind ���������
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind17;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind18;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind19;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind20;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind21;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind22;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind23;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind24;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind25;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind25_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind25_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind26;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind26_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind26_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind27;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind27_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind27_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind28;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind28_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind28_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind29;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind29_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind29_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind30;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind30_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind30_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind31;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind31_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind31_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind32;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind32_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind32_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind33;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind33_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind33_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind34;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind34_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind34_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind35;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind35_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind35_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind36;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind36_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind36_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind37;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind37_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind37_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind38;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind38_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind38_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind39;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind39_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind39_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind40;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind40_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind40_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind41;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind41_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind41_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind41_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind42;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind42_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind42_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind42_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind43;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind43_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind43_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind43_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind44;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind44_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind44_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind44_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind45;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind45_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind45_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind45_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind46;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind46_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind46_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind46_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind47;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind47_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind47_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind47_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind48;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind48_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind48_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind48_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind49;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind49_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind49_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind49_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind50;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind50_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind50_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind50_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind51;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind51_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind51_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind51_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind52;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind52_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind52_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind52_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind53;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind53_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind53_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind53_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind54;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind54_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind54_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind54_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind55;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind55_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind55_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind55_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind56;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind56_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind56_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind56_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind57;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind57_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind57_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind57_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind58;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind58_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind58_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind58_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind59;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind59_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind59_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind59_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind60;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind60_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind60_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind60_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind61;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind61_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind61_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind61_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind62;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind62_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind62_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind62_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind63;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind63_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind63_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind63_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind64;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind64_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind64_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind64_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind65;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind65_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind65_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind65_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind66;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind66_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind66_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind66_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind67;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind67_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind67_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind67_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind68;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind68_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind68_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind68_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind69;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind69_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind69_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind69_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind70;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind70_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind70_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind70_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind71;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind71_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind71_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind71_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind72;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind72_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind72_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind72_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind73;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind73_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind73_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind73_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind74;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind74_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind74_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind74_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind75;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind75_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind75_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind75_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind76;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind76_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind76_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind76_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind77;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind77_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind77_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind77_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind78;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind78_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind78_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind78_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind79;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind79_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind79_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind79_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind80;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind80_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind80_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind80_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind81;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind81_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind81_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind81_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind82;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind82_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind82_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind82_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind83;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind83_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind83_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind83_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind84;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind84_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind84_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind84_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind85;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind85_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind85_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind85_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind86;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind86_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind86_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind86_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind87;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind87_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind87_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind87_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind88;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind88_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind88_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind88_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind89;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind89_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind89_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind89_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind90;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind90_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind90_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind90_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind91;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind91_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind91_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind91_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind92;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind92_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind92_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind92_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind93;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind93_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind93_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind93_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind94;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind94_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind94_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind94_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind95;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind95_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind95_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind95_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind96;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind96_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind96_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind96_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind97;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind97_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind97_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind97_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind98;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind98_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind98_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind98_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind99;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind99_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind99_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind99_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind100;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind100_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind100_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind100_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind101;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind101_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind101_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind101_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind102;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind102_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind102_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind102_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind103;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind103_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind103_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind103_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind104;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind104_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind104_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind104_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind105;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind105_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind105_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind105_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind106;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind106_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind106_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind106_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind107;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind107_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind107_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind107_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind108;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind108_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind108_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind108_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind109;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind109_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind109_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind109_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind110;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind110_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind110_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind110_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind111;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind111_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind111_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind111_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind112;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind112_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind112_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind112_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind113;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind113_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind113_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind113_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind114;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind114_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind114_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind114_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind115;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind115_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind115_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind115_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind116;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind116_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind116_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind116_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind117;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind117_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind117_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind117_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind118;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind118_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind118_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind118_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind119;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind119_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind119_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind119_t;

//----------------------------------------------------------------------------
// SSL
//----------------------------------------------------------------------------

extern LogicalNode iedModel_GGIO_SSLGGIO1;

extern DataObject iedModel_GGIO_SSLGGIO1_Mod;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_SSLGGIO1_Beh;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Health;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_t;

extern DataObject iedModel_GGIO_SSLGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t;


extern DataObject iedModel_GGIO_SSLGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t;


extern DataObject iedModel_GGIO_SSLGGIO1_Ind17;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind18;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind19;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind20;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind21;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind22;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind23;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind24;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind25;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind26;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind27;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind28;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind29;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind30;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind31;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind32;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind33;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind34;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind35;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind36;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind37;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind38;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind39;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind40;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind41;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind42;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind43;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind44;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind45;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind46;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind47;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind48;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_t;

//----------------------------------------------------------------------------
// VLS
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, VLSGGIO1);

ExternDataObjectInd(1, GGIO, VLSGGIO1);
ExternDataObjectInd(2, GGIO, VLSGGIO1);
ExternDataObjectInd(3, GGIO, VLSGGIO1);
ExternDataObjectInd(4, GGIO, VLSGGIO1);
ExternDataObjectInd(5, GGIO, VLSGGIO1);
ExternDataObjectInd(6, GGIO, VLSGGIO1);
ExternDataObjectInd(7, GGIO, VLSGGIO1);
ExternDataObjectInd(8, GGIO, VLSGGIO1);
ExternDataObjectInd(9, GGIO, VLSGGIO1);
ExternDataObjectInd(10, GGIO, VLSGGIO1);
ExternDataObjectInd(11, GGIO, VLSGGIO1);
ExternDataObjectInd(12, GGIO, VLSGGIO1);
ExternDataObjectInd(13, GGIO, VLSGGIO1);
ExternDataObjectInd(14, GGIO, VLSGGIO1);
ExternDataObjectInd(15, GGIO, VLSGGIO1);
ExternDataObjectInd(16, GGIO, VLSGGIO1);

//----------------------------------------------------------------------------
// LS
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, LSGGIO1);

ExternDataObjectInd(1, GGIO, LSGGIO1);
ExternDataObjectInd(2, GGIO, LSGGIO1);
ExternDataObjectInd(3, GGIO, LSGGIO1);
ExternDataObjectInd(4, GGIO, LSGGIO1);
ExternDataObjectInd(5, GGIO, LSGGIO1);
ExternDataObjectInd(6, GGIO, LSGGIO1);
ExternDataObjectInd(7, GGIO, LSGGIO1);
ExternDataObjectInd(8, GGIO, LSGGIO1);
ExternDataObjectInd(9, GGIO, LSGGIO1);
ExternDataObjectInd(10, GGIO, LSGGIO1);
ExternDataObjectInd(11, GGIO, LSGGIO1);
ExternDataObjectInd(12, GGIO, LSGGIO1);
ExternDataObjectInd(13, GGIO, LSGGIO1);
ExternDataObjectInd(14, GGIO, LSGGIO1);
ExternDataObjectInd(15, GGIO, LSGGIO1);
ExternDataObjectInd(16, GGIO, LSGGIO1);

//----------------------------------------------------------------------------
// RST
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, RSTGGIO1);

ExternDataObjectInd(1, GGIO, RSTGGIO1);
ExternDataObjectInd(2, GGIO, RSTGGIO1);
ExternDataObjectInd(3, GGIO, RSTGGIO1);
ExternDataObjectInd(4, GGIO, RSTGGIO1);
ExternDataObjectInd(5, GGIO, RSTGGIO1);
ExternDataObjectInd(6, GGIO, RSTGGIO1);
ExternDataObjectInd(7, GGIO, RSTGGIO1);
ExternDataObjectInd(8, GGIO, RSTGGIO1);
ExternDataObjectInd(9, GGIO, RSTGGIO1);
ExternDataObjectInd(10, GGIO, RSTGGIO1);
ExternDataObjectInd(11, GGIO, RSTGGIO1);
ExternDataObjectInd(12, GGIO, RSTGGIO1);
ExternDataObjectInd(13, GGIO, RSTGGIO1);
ExternDataObjectInd(14, GGIO, RSTGGIO1);
ExternDataObjectInd(15, GGIO, RSTGGIO1);
ExternDataObjectInd(16, GGIO, RSTGGIO1);


#endif /* STATIC_MODEL_H_ */
