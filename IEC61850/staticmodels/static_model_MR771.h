/*
 * static_model_771.h
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

#ifndef STATIC_MODEL_MR771_H_
#define STATIC_MODEL_MR771_H_

#include <stdlib.h>
#include "model.h"
#include "iec61850_server.h"
#include "iec61850_common.h"

extern IedServer iedServer;

extern IedModel 	iedModel;
extern LogicalDevice iedModel_Generic_LD0;
extern LogicalDevice iedModel_Generic_PROT;
extern LogicalDevice iedModel_Generic_CTRL;
extern LogicalDevice iedModel_Generic_MES;
extern LogicalDevice iedModel_Generic_GGIO;

extern SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0;
// -----------------------------------------------------------------------------
// LN LLN0 - ���������� ���� ����. ��. 61850-7-4 �.5.3.4
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LLN0;

// Mod ��. 61850-7-3 �.7.5.4
extern DataObject    iedModel_LD0_LLN0_Mod;					// �����
extern DataAttribute iedModel_LD0_LLN0_Mod_q;					// 		�������� ��������
extern DataAttribute iedModel_LD0_LLN0_Mod_t;					// 		����� �������
extern DataAttribute iedModel_LD0_LLN0_Mod_stVal;				// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;			//		������ ����������

// Beh ��. 61850-7-3 �.7.3.4
extern DataObject    iedModel_LD0_LLN0_Beh;					// ����� ������
extern DataAttribute iedModel_LD0_LLN0_Beh_stVal;				// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_LD0_LLN0_Beh_q;					// 		�������� ��������
extern DataAttribute iedModel_LD0_LLN0_Beh_t;					// 		����� �������

// Health ��. 61850-7-3 �.7.3.4
extern DataObject    iedModel_LD0_LLN0_Health;				// ��������� �����������������
extern DataAttribute iedModel_LD0_LLN0_Health_stVal;			// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_LD0_LLN0_Health_q;				// 		�������� ��������
extern DataAttribute iedModel_LD0_LLN0_Health_t;				// 		����� �������

// NamPlt ��. 61850-7-3 �.7.9.3
extern DataObject    iedModel_LD0_LLN0_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;			// 		��� ����������
extern DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_LD0_LLN0_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN.
extern DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;		//		���������� ���������� ������������ ���������� ����������� ���������� LD. (������ ������� ��� ����� ��������� ��������� ������ LD)
extern DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;			//		������������ ���� ����������� ����������. ��. 61850-7-1

extern DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

// -----------------------------------------------------------------------------
// LN LLN0 - ���������� ���� ����. ��. 61850-7-4 �.5.3.4
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_LLN0;

// Mod ��. 61850-7-3 �.7.5.4
extern DataObject    iedModel_PROT_LLN0_Mod;					// �����
extern DataAttribute iedModel_PROT_LLN0_Mod_q;					// 		�������� ��������
extern DataAttribute iedModel_PROT_LLN0_Mod_t;					// 		����� �������
extern DataAttribute iedModel_PROT_LLN0_Mod_stVal;				// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_PROT_LLN0_Mod_ctlModel;			//		������ ����������

// Beh ��. 61850-7-3 �.7.3.4
extern DataObject    iedModel_PROT_LLN0_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_LLN0_Beh_stVal;				// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_PROT_LLN0_Beh_q;					// 		�������� ��������
extern DataAttribute iedModel_PROT_LLN0_Beh_t;					// 		����� �������

// Health ��. 61850-7-3 �.7.3.4
extern DataObject    iedModel_PROT_LLN0_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_LLN0_Health_stVal;			// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_PROT_LLN0_Health_q;				// 		�������� ��������
extern DataAttribute iedModel_PROT_LLN0_Health_t;				// 		����� �������

// NamPlt ��. 61850-7-3 �.7.9.3
extern DataObject    iedModel_PROT_LLN0_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_LLN0_NamPlt_vendor;			// 		��� ����������
extern DataAttribute iedModel_PROT_LLN0_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_LLN0_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN.
extern DataAttribute iedModel_PROT_LLN0_NamPlt_configRev;		//		���������� ���������� ������������ ���������� ����������� ���������� LD. (������ ������� ��� ����� ��������� ��������� ������ LD)
extern DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs;			//		������������ ���� ����������� ����������. ��. 61850-7-1

extern DataObject    iedModel_PROT_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_PROT_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_PROT_LLN0_SGCB_q;
extern DataAttribute iedModel_PROT_LLN0_SGCB_t;
// -----------------------------------------------------------------------------
// LN LPHD1 - ���������� � ���������� ����������. ��. 61850-7-4 �.5.3.2
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LPHD1;

extern DataObject    iedModel_LD0_LPHD1_PhyNam;
extern DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_LD0_LPHD1_PhyHealth;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_t;
extern DataObject    iedModel_LD0_LPHD1_Proxy;
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

// -----------------------------------------------------------------------------

extern LogicalNode   iedModel_PROT_LPHD1;

// PhyNam ��. 61850-7-3 �.7.9.2
extern DataObject    iedModel_PROT_LPHD1_PhyNam;				// ���������� �������� ����������� ����������
extern DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor;		// 		��� ����������

// PhyHealth ��. 61850-7-3 �.7.3.4
extern DataObject    iedModel_PROT_LPHD1_PhyHealth;			// ��������� ����������������� ����������� ����������
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal;		// 		�������� ��������� ������ INT32
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_q;			// 		�������� ��������
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_t;			// 		����� �������

// Proxy ��. 61850-7-3 �.7.3.2
extern DataObject    iedModel_PROT_LPHD1_Proxy;				// ������ �� ������ ���� �����������
extern DataAttribute iedModel_PROT_LPHD1_Proxy_stVal;			// 		�������� ��������� ������ Boolean (��/���)
extern DataAttribute iedModel_PROT_LPHD1_Proxy_q;				// 		�������� ��������
extern DataAttribute iedModel_PROT_LPHD1_Proxy_t;				// 		����� �������

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
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LPHD1;

extern DataObject    iedModel_CTRL_LPHD1_PhyNam;
extern DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_CTRL_LPHD1_PhyHealth;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t;
extern DataObject    iedModel_CTRL_LPHD1_Proxy;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_q;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------
// 0     0  0000   000
// 00   00  0     0
// 0 0 0 0  0     0
// 0  0  0  0000   000
// 0     0  0         0
// 0     0  0         0
// 0     0  0000   000
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LLN0;								// ���������� ���� ����. ���: LLN0
extern DataObject    iedModel_MES_LLN0_Mod;							// Mod - �����
extern DataAttribute iedModel_MES_LLN0_Mod_q;
extern DataAttribute iedModel_MES_LLN0_Mod_t;
extern DataAttribute iedModel_MES_LLN0_Mod_stVal;
extern DataAttribute iedModel_MES_LLN0_Mod_ctlModel;

extern DataObject    iedModel_MES_LLN0_Beh;							// Beh - ����� ������
extern DataAttribute iedModel_MES_LLN0_Beh_stVal;
extern DataAttribute iedModel_MES_LLN0_Beh_q;
extern DataAttribute iedModel_MES_LLN0_Beh_t;

extern DataObject    iedModel_MES_LLN0_Health;						// Health - ��������� �����������������
extern DataAttribute iedModel_MES_LLN0_Health_stVal;
extern DataAttribute iedModel_MES_LLN0_Health_q;
extern DataAttribute iedModel_MES_LLN0_Health_t;

extern DataObject    iedModel_MES_LLN0_NamPlt;						// NamPIt - ���������� ��������
extern DataAttribute iedModel_MES_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_MES_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_d;
extern DataAttribute iedModel_MES_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_MES_LLN0_SGCB;							// SGCB - ���������� �������� �������
extern DataAttribute iedModel_MES_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_MES_LLN0_SGCB_q;
extern DataAttribute iedModel_MES_LLN0_SGCB_t;

// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LPHD1;

extern DataObject    iedModel_MES_LPHD1_PhyNam;
extern DataAttribute iedModel_MES_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_MES_LPHD1_PhyHealth;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_t;
extern DataObject    iedModel_MES_LPHD1_Proxy;
extern DataAttribute iedModel_MES_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_MES_LPHD1_Proxy_q;
extern DataAttribute iedModel_MES_LPHD1_Proxy_t;

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

// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LPHD1;

extern DataObject    iedModel_GGIO_LPHD1_PhyNam;
extern DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_GGIO_LPHD1_PhyHealth;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t;
extern DataObject    iedModel_GGIO_LPHD1_Proxy;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_q;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_t;

// -----------------------------------------------------------------------------
// LN GGIO1 - ����/����� ��� ����� ��������� ��. 61850-7-4 �.5.7.2
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_OUTGGIO1;

// Mod																// ������������ �������� -------------------------------------
extern DataObject    iedModel_GGIO_OUTGGIO1_Mod;					// �����
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel;

// Beh
extern DataObject    iedModel_GGIO_OUTGGIO1_Beh;					// ����� ������
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t;

// Health
extern DataObject    iedModel_GGIO_OUTGGIO1_Health;				// ��������� �����������������
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_t;

// NamPlt
extern DataObject    iedModel_GGIO_OUTGGIO1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN GGIO1.
																	// -----------------------------------------------------------
// ---------------------------------

// AnIn1 ��. 61850-7-3 �.7.4.2
extern DataObject    iedModel_GGIO_OUTGGIO1_AnIn1;				// ���������� ����				(�� ������������ ������)
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_mag;			// 		���������� �������� (�����������)
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_mag_f;			// 		->		���������� �������� Float32
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_q;				// 		�������� ��������
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_t;				// 		����� �������

// SPCSO1 ��. 61850-7-3 �.7.5.2
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;						// �������������� ����� ������� ���������������� ����������				(�� ������������ ������)
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;					// 		�������� ��������� ������
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;						// 		�������� ��������
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;						// 		����� �������.

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;

//SPCSO9
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;

//SPCSO10
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;

//SPCSO11
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;

//SPCSO12
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;

//SPCSO13
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;

//SPCSO14
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;

//SPCSO15
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;

//SPCSO16
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO16;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal;

//SPCSO17
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO17;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal;

//SPCSO18
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO18;
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

// ------------- ���������� ����� ------------------------------
// Ind1 ��. 61850-7-3 �.7.3.2
extern DataObject    iedModel_GGIO_OUTGGIO1_Ind1;								// ����� ���������(���� �������� ��������)				(�� ������������ ������)
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_stVal;						// 			�������� ��������� ������ BOOLEAN
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_q;							// 			�������� ��������
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_t;							// 			����� �������.

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_t;

//-----------------------------------------------------
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
//-----------------------------------------------------
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

extern DataObject    iedModel_GGIO_INGGIO1_Ind1;								// ����� ���������(���� �������� ��������)				(�� ������������ ������)
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal;						// 			�������� ��������� ������ BOOLEAN
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_q;							// 			�������� ��������
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_t;							// 			����� �������.

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

//-SSLGGIO1 -------------------------------------------------------
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

extern DataObject iedModel_GGIO_VLSGGIO1_Mod;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_VLSGGIO1_Beh;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Health;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_t;

extern DataObject iedModel_GGIO_VLSGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t;


extern DataObject iedModel_GGIO_VLSGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t;

//----------------------------------------------------------------------------

extern DataObject iedModel_GGIO_LSGGIO1_Mod;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_LSGGIO1_Beh;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_t;

extern DataObject iedModel_GGIO_LSGGIO1_Health;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_t;

extern DataObject iedModel_GGIO_LSGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_LSGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t;


extern DataObject iedModel_GGIO_LSGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t;

// -----------------------------------------------------------------------------
// LN MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU1;
extern DataObject    iedModel_MES_MMXU1_Mod;
extern DataAttribute iedModel_MES_MMXU1_Mod_q;
extern DataAttribute iedModel_MES_MMXU1_Mod_t;
extern DataAttribute iedModel_MES_MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU1_Beh;
extern DataAttribute iedModel_MES_MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU1_Beh_q;
extern DataAttribute iedModel_MES_MMXU1_Beh_t;
extern DataObject    iedModel_MES_MMXU1_Health;
extern DataAttribute iedModel_MES_MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_MMXU1_Health_q;
extern DataAttribute iedModel_MES_MMXU1_Health_t;
extern DataObject    iedModel_MES_MMXU1_NamPlt;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_d;

extern DataObject iedModel_MES_MMXU1_A;
extern DataObject iedModel_MES_MMXU1_A_phsA;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb;
extern DataObject iedModel_MES_MMXU1_A_phsB;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag_f;

extern DataAttribute iedModel_MES_MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb;
extern DataObject iedModel_MES_MMXU1_A_phsC;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag_f;

extern DataAttribute iedModel_MES_MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb;
extern DataObject iedModel_MES_MMXU1_A_neut;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_MMXU1_A_neut_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV;
extern DataObject iedModel_MES_MMXU1_phV_phsA;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_phsB;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_phsC;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_neut;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_q;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_t;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_db;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_neut1;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_q;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_t;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_db;
extern DataAttribute iedModel_MES_MMXU1_phV_neut1_zeroDb;

// PPV
extern DataObject iedModel_MES_MMXU1_PPV;
extern DataObject iedModel_MES_MMXU1_PPV_phsA;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb;

extern DataObject iedModel_MES_MMXU1_PPV_phsB;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb;

extern DataObject iedModel_MES_MMXU1_PPV_phsC;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb;

// totW
extern DataObject    iedModel_MES_MMXU1_totW;
extern DataAttribute iedModel_MES_MMXU1_totW_mag;
extern DataAttribute iedModel_MES_MMXU1_totW_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totW_instMag;
extern DataAttribute iedModel_MES_MMXU1_totW_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totW_q;
extern DataAttribute iedModel_MES_MMXU1_totW_t;
extern DataAttribute iedModel_MES_MMXU1_totW_db;
extern DataAttribute iedModel_MES_MMXU1_totW_zeroDb;

// totVAr
extern DataObject    iedModel_MES_MMXU1_totVAr;
extern DataAttribute iedModel_MES_MMXU1_totVAr_mag;
extern DataAttribute iedModel_MES_MMXU1_totVAr_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totVAr_instMag;
extern DataAttribute iedModel_MES_MMXU1_totVAr_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totVAr_q;
extern DataAttribute iedModel_MES_MMXU1_totVAr_t;
extern DataAttribute iedModel_MES_MMXU1_totVAr_db;
extern DataAttribute iedModel_MES_MMXU1_totVAr_zeroDb;

// totPF
extern DataObject    iedModel_MES_MMXU1_totPF;
extern DataAttribute iedModel_MES_MMXU1_totPF_mag;
extern DataAttribute iedModel_MES_MMXU1_totPF_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totPF_instMag;
extern DataAttribute iedModel_MES_MMXU1_totPF_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totPF_q;
extern DataAttribute iedModel_MES_MMXU1_totPF_t;
extern DataAttribute iedModel_MES_MMXU1_totPF_db;
extern DataAttribute iedModel_MES_MMXU1_totPF_zeroDb;

// HZ
extern DataObject    iedModel_MES_MMXU1_Hz;
extern DataAttribute iedModel_MES_MMXU1_Hz_mag;
extern DataAttribute iedModel_MES_MMXU1_Hz_mag_f;
extern DataAttribute iedModel_MES_MMXU1_Hz_instMag;
extern DataAttribute iedModel_MES_MMXU1_Hz_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_Hz_q;
extern DataAttribute iedModel_MES_MMXU1_Hz_t;
extern DataAttribute iedModel_MES_MMXU1_Hz_db;
extern DataAttribute iedModel_MES_MMXU1_Hz_zeroDb;

/*******************************************************
 * MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_MSQI1;

extern DataObject iedModel_MES_MSQI1_Mod;
extern DataAttribute iedModel_MES_MSQI1_Mod_q;
extern DataAttribute iedModel_MES_MSQI1_Mod_t;
extern DataAttribute iedModel_MES_MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_MSQI1_Beh;
extern DataAttribute iedModel_MES_MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_MSQI1_Beh_q;
extern DataAttribute iedModel_MES_MSQI1_Beh_t;

extern DataObject iedModel_MES_MSQI1_Health;
extern DataAttribute iedModel_MES_MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_MSQI1_Health_q;
extern DataAttribute iedModel_MES_MSQI1_Health_t;

extern DataObject iedModel_MES_MSQI1_NamPlt;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_MSQI1_SeqA;
extern DataObject iedModel_MES_MSQI1_SeqA_I1;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I1_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqA_I2;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_I2_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqA_3I0;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_3I0_zeroDb;

extern DataAttribute iedModel_MES_MSQI1_SeqA_SeqT;

// SeqU
extern DataObject iedModel_MES_MSQI1_SeqU;
extern DataObject iedModel_MES_MSQI1_SeqU_U1;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U1_zeroDb;


extern DataObject iedModel_MES_MSQI1_SeqU_U2;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U2_zeroDb;


extern DataObject iedModel_MES_MSQI1_SeqU_U3U0;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_U3U0_zeroDb;

extern DataAttribute iedModel_MES_MSQI1_SeqU_SeqT;

/*******************************************************
 * RFLO1
 *******************************************************/
extern LogicalNode iedModel_MES_RFLO1;
extern DataObject iedModel_MES_RFLO1_Mod;
extern DataAttribute iedModel_MES_RFLO1_Mod_q;
extern DataAttribute iedModel_MES_RFLO1_Mod_t;
extern DataAttribute iedModel_MES_RFLO1_Mod_stVal;
extern DataAttribute iedModel_MES_RFLO1_Mod_ctlModel;

extern DataObject iedModel_MES_RFLO1_Beh;
extern DataAttribute iedModel_MES_RFLO1_Beh_stVal;
extern DataAttribute iedModel_MES_RFLO1_Beh_q;
extern DataAttribute iedModel_MES_RFLO1_Beh_t;

extern DataObject iedModel_MES_RFLO1_Health;
extern DataAttribute iedModel_MES_RFLO1_Health_stVal;
extern DataAttribute iedModel_MES_RFLO1_Health_q;
extern DataAttribute iedModel_MES_RFLO1_Health_t;

extern DataObject iedModel_MES_RFLO1_NamPlt;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_vendor;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_swRev;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_d;

extern DataObject    iedModel_MES_RFLO1_Fltz;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal ;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal_mag;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal_mag_f;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal_mag;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal_mag_f;
extern DataAttribute iedModel_MES_RFLO1_Fltz_q;
extern DataAttribute iedModel_MES_RFLO1_Fltz_t;
extern DataAttribute iedModel_MES_RFLO1_Fltz_db;
extern DataAttribute iedModel_MES_RFLO1_Fltz_zeroDb;

extern DataObject    iedModel_MES_RFLO1_FltDiskm;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_mag;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_mag_f;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_instMag;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_instMag_f;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_q;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_t;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_db;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_zeroDb;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC1;

extern DataObject    iedModel_PROT_IPTOC1_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC1_Str;
extern DataAttribute iedModel_PROT_IPTOC1_Str_general;
extern DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC1_Str_q;
extern DataAttribute iedModel_PROT_IPTOC1_Str_t;

extern DataObject    iedModel_PROT_IPTOC1_Op;
extern DataAttribute iedModel_PROT_IPTOC1_Op_general;
extern DataAttribute iedModel_PROT_IPTOC1_Op_q;
extern DataAttribute iedModel_PROT_IPTOC1_Op_t;

/****************************************************************
* LN iPTOC2
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC2;

extern DataObject    iedModel_PROT_IPTOC2_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC2_Str;
extern DataAttribute iedModel_PROT_IPTOC2_Str_general;
extern DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC2_Str_q;
extern DataAttribute iedModel_PROT_IPTOC2_Str_t;

extern DataObject    iedModel_PROT_IPTOC2_Op;
extern DataAttribute iedModel_PROT_IPTOC2_Op_general;
extern DataAttribute iedModel_PROT_IPTOC2_Op_q;
extern DataAttribute iedModel_PROT_IPTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC3;

extern DataObject    iedModel_PROT_IPTOC3_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC3_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC3_Str;
extern DataAttribute iedModel_PROT_IPTOC3_Str_general;
extern DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC3_Str_q;
extern DataAttribute iedModel_PROT_IPTOC3_Str_t;

extern DataObject    iedModel_PROT_IPTOC3_Op;
extern DataAttribute iedModel_PROT_IPTOC3_Op_general;
extern DataAttribute iedModel_PROT_IPTOC3_Op_q;
extern DataAttribute iedModel_PROT_IPTOC3_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC4;

extern DataObject    iedModel_PROT_IPTOC4_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC4_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC4_Str;
extern DataAttribute iedModel_PROT_IPTOC4_Str_general;
extern DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC4_Str_q;
extern DataAttribute iedModel_PROT_IPTOC4_Str_t;

extern DataObject    iedModel_PROT_IPTOC4_Op;
extern DataAttribute iedModel_PROT_IPTOC4_Op_general;
extern DataAttribute iedModel_PROT_IPTOC4_Op_q;
extern DataAttribute iedModel_PROT_IPTOC4_Op_t;



/****************************************************************
* LN IPTOC5
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC5;

extern DataObject    iedModel_PROT_IPTOC5_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC5_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC5_Str;
extern DataAttribute iedModel_PROT_IPTOC5_Str_general;
extern DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC5_Str_q;
extern DataAttribute iedModel_PROT_IPTOC5_Str_t;

extern DataObject    iedModel_PROT_IPTOC5_Op;
extern DataAttribute iedModel_PROT_IPTOC5_Op_general;
extern DataAttribute iedModel_PROT_IPTOC5_Op_q;
extern DataAttribute iedModel_PROT_IPTOC5_Op_t;


/****************************************************************
* LN IPTOC6
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC6;

extern DataObject    iedModel_PROT_IPTOC6_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC6_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC6_Str;
extern DataAttribute iedModel_PROT_IPTOC6_Str_general;
extern DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC6_Str_q;
extern DataAttribute iedModel_PROT_IPTOC6_Str_t;

extern DataObject    iedModel_PROT_IPTOC6_Op;
extern DataAttribute iedModel_PROT_IPTOC6_Op_general;
extern DataAttribute iedModel_PROT_IPTOC6_Op_q;
extern DataAttribute iedModel_PROT_IPTOC6_Op_t;


/****************************************************************
* LN IPTOC7
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC7;

extern DataObject    iedModel_PROT_IPTOC7_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC7_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC7_Str;
extern DataAttribute iedModel_PROT_IPTOC7_Str_general;
extern DataAttribute iedModel_PROT_IPTOC7_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC7_Str_q;
extern DataAttribute iedModel_PROT_IPTOC7_Str_t;

extern DataObject    iedModel_PROT_IPTOC7_Op;
extern DataAttribute iedModel_PROT_IPTOC7_Op_general;
extern DataAttribute iedModel_PROT_IPTOC7_Op_q;
extern DataAttribute iedModel_PROT_IPTOC7_Op_t;


/****************************************************************
* LN IPTOC8
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC8;

extern DataObject    iedModel_PROT_IPTOC8_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTOC8_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_ctlModel;

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
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

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


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_INPTOC1;

extern DataObject    iedModel_PROT_INPTOC1_Mod;					// �����
extern DataAttribute iedModel_PROT_INPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_INPTOC1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_INPTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Beh_q;
extern DataAttribute iedModel_PROT_INPTOC1_Beh_t;

extern DataObject    iedModel_PROT_INPTOC1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_INPTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Health_q;
extern DataAttribute iedModel_PROT_INPTOC1_Health_t;

extern DataObject    iedModel_PROT_INPTOC1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_INPTOC1_Str;
extern DataAttribute iedModel_PROT_INPTOC1_Str_general;
extern DataAttribute iedModel_PROT_INPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_INPTOC1_Str_q;
extern DataAttribute iedModel_PROT_INPTOC1_Str_t;

extern DataObject    iedModel_PROT_INPTOC1_Op;
extern DataAttribute iedModel_PROT_INPTOC1_Op_general;
extern DataAttribute iedModel_PROT_INPTOC1_Op_q;
extern DataAttribute iedModel_PROT_INPTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_INPTOC2;

extern DataObject    iedModel_PROT_INPTOC2_Mod;					// �����
extern DataAttribute iedModel_PROT_INPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_INPTOC2_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_INPTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Beh_q;
extern DataAttribute iedModel_PROT_INPTOC2_Beh_t;

extern DataObject    iedModel_PROT_INPTOC2_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_INPTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Health_q;
extern DataAttribute iedModel_PROT_INPTOC2_Health_t;

extern DataObject    iedModel_PROT_INPTOC2_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_INPTOC2_Str;
extern DataAttribute iedModel_PROT_INPTOC2_Str_general;
extern DataAttribute iedModel_PROT_INPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_INPTOC2_Str_q;
extern DataAttribute iedModel_PROT_INPTOC2_Str_t;

extern DataObject    iedModel_PROT_INPTOC2_Op;
extern DataAttribute iedModel_PROT_INPTOC2_Op_general;
extern DataAttribute iedModel_PROT_INPTOC2_Op_q;
extern DataAttribute iedModel_PROT_INPTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IGPTOC;

extern DataObject    iedModel_PROT_IGPTOC_Mod;					// �����
extern DataAttribute iedModel_PROT_IGPTOC_Mod_q;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_t;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_ctlModel;

extern DataObject    iedModel_PROT_IGPTOC_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_IGPTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Beh_q;
extern DataAttribute iedModel_PROT_IGPTOC_Beh_t;

extern DataObject    iedModel_PROT_IGPTOC_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_IGPTOC_Health_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Health_q;
extern DataAttribute iedModel_PROT_IGPTOC_Health_t;

extern DataObject    iedModel_PROT_IGPTOC_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_IGPTOC_Str;
extern DataAttribute iedModel_PROT_IGPTOC_Str_general;
extern DataAttribute iedModel_PROT_IGPTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IGPTOC_Str_q;
extern DataAttribute iedModel_PROT_IGPTOC_Str_t;

extern DataObject    iedModel_PROT_IGPTOC_Op;
extern DataAttribute iedModel_PROT_IGPTOC_Op_general;
extern DataAttribute iedModel_PROT_IGPTOC_Op_q;
extern DataAttribute iedModel_PROT_IGPTOC_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I2I1PTOC;

extern DataObject    iedModel_PROT_I2I1PTOC_Mod;					// �����
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_t;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_ctlModel;

extern DataObject    iedModel_PROT_I2I1PTOC_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_t;

extern DataObject    iedModel_PROT_I2I1PTOC_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_t;

extern DataObject    iedModel_PROT_I2I1PTOC_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

extern DataObject    iedModel_PROT_I2I1PTOC_Str;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_general;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_t;

extern DataObject    iedModel_PROT_I2I1PTOC_Op;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_general;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_t;

//----------------------------------------------------------------------------
// IPTUC1
//----------------------------------------------------------------------------

extern DataObject    iedModel_PROT_IPTUC1_Mod;					// �����
extern DataAttribute iedModel_PROT_IPTUC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTUC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTUC1_Mod_stVal;

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

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV1;

extern DataObject    iedModel_PROT_UPTOV1_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV2;

extern DataObject    iedModel_PROT_UPTOV2_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV3;

extern DataObject    iedModel_PROT_UPTOV3_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV4;

extern DataObject    iedModel_PROT_UPTOV4_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTOV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_ctlModel;

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

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV1;

extern DataObject    iedModel_PROT_UPTUV1_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV2;

extern DataObject    iedModel_PROT_UPTUV2_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV3;

extern DataObject    iedModel_PROT_UPTUV3_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_ctlModel;

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


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV4;

extern DataObject    iedModel_PROT_UPTUV4_Mod;					// �����
extern DataAttribute iedModel_PROT_UPTUV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_ctlModel;

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

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF1;

extern DataObject    iedModel_PROT_PTOF1_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF1_Mod_q;
extern DataAttribute iedModel_PROT_PTOF1_Mod_t;
extern DataAttribute iedModel_PROT_PTOF1_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Mod_ctlModel;

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


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF2;

extern DataObject    iedModel_PROT_PTOF2_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF2_Mod_q;
extern DataAttribute iedModel_PROT_PTOF2_Mod_t;
extern DataAttribute iedModel_PROT_PTOF2_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Mod_ctlModel;

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


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF3;

extern DataObject    iedModel_PROT_PTOF3_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF3_Mod_q;
extern DataAttribute iedModel_PROT_PTOF3_Mod_t;
extern DataAttribute iedModel_PROT_PTOF3_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Mod_ctlModel;

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

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF4;

extern DataObject    iedModel_PROT_PTOF4_Mod;					// �����
extern DataAttribute iedModel_PROT_PTOF4_Mod_q;
extern DataAttribute iedModel_PROT_PTOF4_Mod_t;
extern DataAttribute iedModel_PROT_PTOF4_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Mod_ctlModel;

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

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF1;

extern DataObject    iedModel_PROT_PTUF1_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF1_Mod_q;
extern DataAttribute iedModel_PROT_PTUF1_Mod_t;
extern DataAttribute iedModel_PROT_PTUF1_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Mod_ctlModel;

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


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF2;

extern DataObject    iedModel_PROT_PTUF2_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF2_Mod_q;
extern DataAttribute iedModel_PROT_PTUF2_Mod_t;
extern DataAttribute iedModel_PROT_PTUF2_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Mod_ctlModel;

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



/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF3;

extern DataObject    iedModel_PROT_PTUF3_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF3_Mod_q;
extern DataAttribute iedModel_PROT_PTUF3_Mod_t;
extern DataAttribute iedModel_PROT_PTUF3_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Mod_ctlModel;

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

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF4;

extern DataObject    iedModel_PROT_PTUF4_Mod;					// �����
extern DataAttribute iedModel_PROT_PTUF4_Mod_q;
extern DataAttribute iedModel_PROT_PTUF4_Mod_t;
extern DataAttribute iedModel_PROT_PTUF4_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Mod_ctlModel;

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

/****************************************************************
* BLKPTTR
*****************************************************************/

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

/****************************************************************
* QPTTR1
*****************************************************************/

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

/****************************************************************
* QPTTR2
*****************************************************************/

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
/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_RREC1;

extern DataObject    iedModel_PROT_RREC1_Mod;					// �����
extern DataAttribute iedModel_PROT_RREC1_Mod_q;
extern DataAttribute iedModel_PROT_RREC1_Mod_t;
extern DataAttribute iedModel_PROT_RREC1_Mod_stVal;
extern DataAttribute iedModel_PROT_RREC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_RREC1_Beh;					// ����� ������
extern DataAttribute iedModel_PROT_RREC1_Beh_stVal;
extern DataAttribute iedModel_PROT_RREC1_Beh_q;
extern DataAttribute iedModel_PROT_RREC1_Beh_t;

extern DataObject    iedModel_PROT_RREC1_Health;				// ��������� �����������������
extern DataAttribute iedModel_PROT_RREC1_Health_stVal;
extern DataAttribute iedModel_PROT_RREC1_Health_q;
extern DataAttribute iedModel_PROT_RREC1_Health_t;

extern DataObject    iedModel_PROT_RREC1_NamPlt;				// ���������� ��������
extern DataAttribute iedModel_PROT_RREC1_NamPlt_vendor;		// 		��� ����������
extern DataAttribute iedModel_PROT_RREC1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_PROT_RREC1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN PTOC1.

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
LogicalNode iedModel_PROT_RSYN1;

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
// PDIS2
//----------------------------------------------------------------------------

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
// PDIS3
//----------------------------------------------------------------------------

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
// PDIS7
//----------------------------------------------------------------------------

extern DataObject iedModel_PROT_PDIS7_Mod;
extern DataAttribute iedModel_PROT_PDIS7_Mod_q;
extern DataAttribute iedModel_PROT_PDIS7_Mod_t;
extern DataAttribute iedModel_PROT_PDIS7_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS7_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS7_Beh;
extern DataAttribute iedModel_PROT_PDIS7_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS7_Beh_q;
extern DataAttribute iedModel_PROT_PDIS7_Beh_t;

extern DataObject iedModel_PROT_PDIS7_Health;
extern DataAttribute iedModel_PROT_PDIS7_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS7_Health_q;
extern DataAttribute iedModel_PROT_PDIS7_Health_t;

extern DataObject iedModel_PROT_PDIS7_NamPlt;
extern DataAttribute iedModel_PROT_PDIS7_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS7_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS7_NamPlt_d;

extern DataObject iedModel_PROT_PDIS7_Op;
extern DataAttribute iedModel_PROT_PDIS7_Op_general;
extern DataAttribute iedModel_PROT_PDIS7_Op_q;
extern DataAttribute iedModel_PROT_PDIS7_Op_t;

extern DataObject iedModel_PROT_PDIS7_Str;
extern DataAttribute iedModel_PROT_PDIS7_Str_general;
extern DataAttribute iedModel_PROT_PDIS7_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS7_Str_q;
extern DataAttribute iedModel_PROT_PDIS7_Str_t;

//----------------------------------------------------------------------------
// PDIS8
//----------------------------------------------------------------------------

extern DataObject iedModel_PROT_PDIS8_Mod;
extern DataAttribute iedModel_PROT_PDIS8_Mod_q;
extern DataAttribute iedModel_PROT_PDIS8_Mod_t;
extern DataAttribute iedModel_PROT_PDIS8_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS8_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS8_Beh;
extern DataAttribute iedModel_PROT_PDIS8_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS8_Beh_q;
extern DataAttribute iedModel_PROT_PDIS8_Beh_t;

extern DataObject iedModel_PROT_PDIS8_Health;
extern DataAttribute iedModel_PROT_PDIS8_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS8_Health_q;
extern DataAttribute iedModel_PROT_PDIS8_Health_t;

extern DataObject iedModel_PROT_PDIS8_NamPlt;
extern DataAttribute iedModel_PROT_PDIS8_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS8_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS8_NamPlt_d;

extern DataObject iedModel_PROT_PDIS8_Op;
extern DataAttribute iedModel_PROT_PDIS8_Op_general;
extern DataAttribute iedModel_PROT_PDIS8_Op_q;
extern DataAttribute iedModel_PROT_PDIS8_Op_t;

extern DataObject iedModel_PROT_PDIS8_Str;
extern DataAttribute iedModel_PROT_PDIS8_Str_general;
extern DataAttribute iedModel_PROT_PDIS8_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS8_Str_q;
extern DataAttribute iedModel_PROT_PDIS8_Str_t;

//----------------------------------------------------------------------------
// PDIS9
//----------------------------------------------------------------------------

extern DataObject iedModel_PROT_PDIS9_Mod;
extern DataAttribute iedModel_PROT_PDIS9_Mod_q;
extern DataAttribute iedModel_PROT_PDIS9_Mod_t;
extern DataAttribute iedModel_PROT_PDIS9_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS9_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS9_Beh;
extern DataAttribute iedModel_PROT_PDIS9_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS9_Beh_q;
extern DataAttribute iedModel_PROT_PDIS9_Beh_t;

extern DataObject iedModel_PROT_PDIS9_Health;
extern DataAttribute iedModel_PROT_PDIS9_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS9_Health_q;
extern DataAttribute iedModel_PROT_PDIS9_Health_t;

extern DataObject iedModel_PROT_PDIS9_NamPlt;
extern DataAttribute iedModel_PROT_PDIS9_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS9_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS9_NamPlt_d;

extern DataObject iedModel_PROT_PDIS9_Op;
extern DataAttribute iedModel_PROT_PDIS9_Op_general;
extern DataAttribute iedModel_PROT_PDIS9_Op_q;
extern DataAttribute iedModel_PROT_PDIS9_Op_t;

extern DataObject iedModel_PROT_PDIS9_Str;
extern DataAttribute iedModel_PROT_PDIS9_Str_general;
extern DataAttribute iedModel_PROT_PDIS9_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS9_Str_q;
extern DataAttribute iedModel_PROT_PDIS9_Str_t;

//----------------------------------------------------------------------------
// PDIS10
//----------------------------------------------------------------------------

extern DataObject iedModel_PROT_PDIS10_Mod;
extern DataAttribute iedModel_PROT_PDIS10_Mod_q;
extern DataAttribute iedModel_PROT_PDIS10_Mod_t;
extern DataAttribute iedModel_PROT_PDIS10_Mod_stVal;
extern DataAttribute iedModel_PROT_PDIS10_Mod_ctlModel;

extern DataObject iedModel_PROT_PDIS10_Beh;
extern DataAttribute iedModel_PROT_PDIS10_Beh_stVal;
extern DataAttribute iedModel_PROT_PDIS10_Beh_q;
extern DataAttribute iedModel_PROT_PDIS10_Beh_t;

extern DataObject iedModel_PROT_PDIS10_Health;
extern DataAttribute iedModel_PROT_PDIS10_Health_stVal;
extern DataAttribute iedModel_PROT_PDIS10_Health_q;
extern DataAttribute iedModel_PROT_PDIS10_Health_t;

extern DataObject iedModel_PROT_PDIS10_NamPlt;
extern DataAttribute iedModel_PROT_PDIS10_NamPlt_vendor;
extern DataAttribute iedModel_PROT_PDIS10_NamPlt_swRev;
extern DataAttribute iedModel_PROT_PDIS10_NamPlt_d;

extern DataObject iedModel_PROT_PDIS10_Op;
extern DataAttribute iedModel_PROT_PDIS10_Op_general;
extern DataAttribute iedModel_PROT_PDIS10_Op_q;
extern DataAttribute iedModel_PROT_PDIS10_Op_t;

extern DataObject iedModel_PROT_PDIS10_Str;
extern DataAttribute iedModel_PROT_PDIS10_Str_general;
extern DataAttribute iedModel_PROT_PDIS10_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PDIS10_Str_q;
extern DataAttribute iedModel_PROT_PDIS10_Str_t;

//----------------------------------------------------------------------------
// VZGGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO1;

extern DataObject iedModel_PROT_VZGGIO1_Mod;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO2;

extern DataObject iedModel_PROT_VZGGIO2_Mod;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO3;

extern DataObject iedModel_PROT_VZGGIO3_Mod;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO4;

extern DataObject iedModel_PROT_VZGGIO4_Mod;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO5;

extern DataObject iedModel_PROT_VZGGIO5_Mod;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO6;

extern DataObject iedModel_PROT_VZGGIO6_Mod;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO7;

extern DataObject iedModel_PROT_VZGGIO7_Mod;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO8;

extern DataObject iedModel_PROT_VZGGIO8_Mod;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO9;

extern DataObject iedModel_PROT_VZGGIO9_Mod;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO10;

extern DataObject iedModel_PROT_VZGGIO10_Mod;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO11;

extern DataObject iedModel_PROT_VZGGIO11_Mod;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO12;

extern DataObject iedModel_PROT_VZGGIO12_Mod;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO13;

extern DataObject iedModel_PROT_VZGGIO13_Mod;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO14;

extern DataObject iedModel_PROT_VZGGIO14_Mod;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO15;

extern DataObject iedModel_PROT_VZGGIO15_Mod;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_ctlModel;


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
extern LogicalNode iedModel_PROT_VZGGIO16;

extern DataObject iedModel_PROT_VZGGIO16_Mod;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_ctlModel;


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

// -----------------------------------------------------------------------------
// LN CSWI
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_CSWI1;

// Mod																// ������������ �������� -------------------------------------
extern DataObject    iedModel_CTRL_CSWI1_Mod;					// �����
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
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev;			// 		������� ����������� �����
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_d;				//		��������� �������� ������ ����� ��������� � ����������� ���� LN CSWI1.

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
// -----------------------------------------------------------------------------
// LN XCBR1
// -----------------------------------------------------------------------------
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

//-PTRC --------------------------------------------------------------------------
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

//SPCSO1
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

// --------------------------------------------------------
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


#endif /* STATIC_MODEL_H_ */
