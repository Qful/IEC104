/*
 * PROT_model.h
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#ifndef PROT_MODEL_H_
#define PROT_MODEL_H_

extern LogicalDevice iedModel_Generic_PROT;

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
extern LogicalNode iedModel_PROT_AVRGGIO;

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
// IDPDIF
extern LogicalNode iedModel_PROT_IDPDIF;

extern DataObject iedModel_PROT_IDPDIF_Mod;
extern DataAttribute iedModel_PROT_IDPDIF_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF_Mod_stVal;
extern DataAttribute iedModel_PROT_IDPDIF_Mod_ctlModel;

extern DataObject iedModel_PROT_IDPDIF_Beh;
extern DataAttribute iedModel_PROT_IDPDIF_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF_Beh_t;

extern DataObject iedModel_PROT_IDPDIF_Health;
extern DataAttribute iedModel_PROT_IDPDIF_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF_Health_t;

extern DataObject iedModel_PROT_IDPDIF_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF_NamPlt_d;

extern DataObject iedModel_PROT_IDPDIF_Op;
extern DataAttribute iedModel_PROT_IDPDIF_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF_Op_t;

extern DataObject iedModel_PROT_IDPDIF_Str;
extern DataAttribute iedModel_PROT_IDPDIF_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF_Str_t;

extern DataObject iedModel_PROT_IDPDIF_RstA;
extern DataObject iedModel_PROT_IDPDIF_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF_RstA_phsB;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF_RstA_phsC;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_zeroDb;

extern DataObject iedModel_PROT_IDPDIF_DifACIc;
extern DataObject iedModel_PROT_IDPDIF_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF_DifACIc_phsB;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF_DifACIc_phsC;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_zeroDb;
//----------------------------------------------------------------------------
// IDDPDIF
extern LogicalNode iedModel_PROT_IDDPDIF;

extern DataObject iedModel_PROT_IDDPDIF_Mod;
extern DataAttribute iedModel_PROT_IDDPDIF_Mod_q;
extern DataAttribute iedModel_PROT_IDDPDIF_Mod_t;
extern DataAttribute iedModel_PROT_IDDPDIF_Mod_stVal;
extern DataAttribute iedModel_PROT_IDDPDIF_Mod_ctlModel;

extern DataObject iedModel_PROT_IDDPDIF_Beh;
extern DataAttribute iedModel_PROT_IDDPDIF_Beh_stVal;
extern DataAttribute iedModel_PROT_IDDPDIF_Beh_q;
extern DataAttribute iedModel_PROT_IDDPDIF_Beh_t;

extern DataObject iedModel_PROT_IDDPDIF_Health;
extern DataAttribute iedModel_PROT_IDDPDIF_Health_stVal;
extern DataAttribute iedModel_PROT_IDDPDIF_Health_q;
extern DataAttribute iedModel_PROT_IDDPDIF_Health_t;

extern DataObject iedModel_PROT_IDDPDIF_NamPlt;
extern DataAttribute iedModel_PROT_IDDPDIF_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDDPDIF_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDDPDIF_NamPlt_d;

extern DataObject iedModel_PROT_IDDPDIF_Op;
extern DataAttribute iedModel_PROT_IDDPDIF_Op_general;
extern DataAttribute iedModel_PROT_IDDPDIF_Op_q;
extern DataAttribute iedModel_PROT_IDDPDIF_Op_t;

extern DataObject iedModel_PROT_IDDPDIF_Str;
extern DataAttribute iedModel_PROT_IDDPDIF_Str_general;
extern DataAttribute iedModel_PROT_IDDPDIF_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDDPDIF_Str_q;
extern DataAttribute iedModel_PROT_IDDPDIF_Str_t;

//----------------------------------------------------------------------------
// IDDMPDIF
extern LogicalNode iedModel_PROT_IDDMPDIF;

extern DataObject iedModel_PROT_IDDMPDIF_Mod;
extern DataAttribute iedModel_PROT_IDDMPDIF_Mod_q;
extern DataAttribute iedModel_PROT_IDDMPDIF_Mod_t;
extern DataAttribute iedModel_PROT_IDDMPDIF_Mod_stVal;
extern DataAttribute iedModel_PROT_IDDMPDIF_Mod_ctlModel;

extern DataObject iedModel_PROT_IDDMPDIF_Beh;
extern DataAttribute iedModel_PROT_IDDMPDIF_Beh_stVal;
extern DataAttribute iedModel_PROT_IDDMPDIF_Beh_q;
extern DataAttribute iedModel_PROT_IDDMPDIF_Beh_t;

extern DataObject iedModel_PROT_IDDMPDIF_Health;
extern DataAttribute iedModel_PROT_IDDMPDIF_Health_stVal;
extern DataAttribute iedModel_PROT_IDDMPDIF_Health_q;
extern DataAttribute iedModel_PROT_IDDMPDIF_Health_t;

extern DataObject iedModel_PROT_IDDMPDIF_NamPlt;
extern DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_d;

extern DataObject iedModel_PROT_IDDMPDIF_Op;
extern DataAttribute iedModel_PROT_IDDMPDIF_Op_general;
extern DataAttribute iedModel_PROT_IDDMPDIF_Op_q;
extern DataAttribute iedModel_PROT_IDDMPDIF_Op_t;

extern DataObject iedModel_PROT_IDDMPDIF_Str;
extern DataAttribute iedModel_PROT_IDDMPDIF_Str_general;
extern DataAttribute iedModel_PROT_IDDMPDIF_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDDMPDIF_Str_q;
extern DataAttribute iedModel_PROT_IDDMPDIF_Str_t;

//----------------------------------------------------------------------------
// ID0PDIF2
extern LogicalNode iedModel_PROT_ID0PDIF2;

extern DataObject iedModel_PROT_ID0PDIF2_Mod;
extern DataAttribute iedModel_PROT_ID0PDIF2_Mod_q;
extern DataAttribute iedModel_PROT_ID0PDIF2_Mod_t;
extern DataAttribute iedModel_PROT_ID0PDIF2_Mod_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF2_Mod_ctlModel;

extern DataObject iedModel_PROT_ID0PDIF2_Beh;
extern DataAttribute iedModel_PROT_ID0PDIF2_Beh_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF2_Beh_q;
extern DataAttribute iedModel_PROT_ID0PDIF2_Beh_t;

extern DataObject iedModel_PROT_ID0PDIF2_Health;
extern DataAttribute iedModel_PROT_ID0PDIF2_Health_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF2_Health_q;
extern DataAttribute iedModel_PROT_ID0PDIF2_Health_t;

extern DataObject iedModel_PROT_ID0PDIF2_NamPlt;
extern DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_d;

extern DataObject iedModel_PROT_ID0PDIF2_Op;
extern DataAttribute iedModel_PROT_ID0PDIF2_Op_general;
extern DataAttribute iedModel_PROT_ID0PDIF2_Op_q;
extern DataAttribute iedModel_PROT_ID0PDIF2_Op_t;

extern DataObject iedModel_PROT_ID0PDIF2_Str;
extern DataAttribute iedModel_PROT_ID0PDIF2_Str_general;
extern DataAttribute iedModel_PROT_ID0PDIF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_ID0PDIF2_Str_q;
extern DataAttribute iedModel_PROT_ID0PDIF2_Str_t;

//----------------------------------------------------------------------------
// ID0PDIF1
extern LogicalNode iedModel_PROT_ID0PDIF1;

extern DataObject iedModel_PROT_ID0PDIF1_Mod;
extern DataAttribute iedModel_PROT_ID0PDIF1_Mod_q;
extern DataAttribute iedModel_PROT_ID0PDIF1_Mod_t;
extern DataAttribute iedModel_PROT_ID0PDIF1_Mod_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF1_Mod_ctlModel;

extern DataObject iedModel_PROT_ID0PDIF1_Beh;
extern DataAttribute iedModel_PROT_ID0PDIF1_Beh_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF1_Beh_q;
extern DataAttribute iedModel_PROT_ID0PDIF1_Beh_t;

extern DataObject iedModel_PROT_ID0PDIF1_Health;
extern DataAttribute iedModel_PROT_ID0PDIF1_Health_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF1_Health_q;
extern DataAttribute iedModel_PROT_ID0PDIF1_Health_t;

extern DataObject iedModel_PROT_ID0PDIF1_NamPlt;
extern DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_d;

extern DataObject iedModel_PROT_ID0PDIF1_Op;
extern DataAttribute iedModel_PROT_ID0PDIF1_Op_general;
extern DataAttribute iedModel_PROT_ID0PDIF1_Op_q;
extern DataAttribute iedModel_PROT_ID0PDIF1_Op_t;

extern DataObject iedModel_PROT_ID0PDIF1_Str;
extern DataAttribute iedModel_PROT_ID0PDIF1_Str_general;
extern DataAttribute iedModel_PROT_ID0PDIF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_ID0PDIF1_Str_q;
extern DataAttribute iedModel_PROT_ID0PDIF1_Str_t;

//----------------------------------------------------------------------------
// ID0PDIF3
extern LogicalNode iedModel_PROT_ID0PDIF3;

extern DataObject iedModel_PROT_ID0PDIF3_Mod;
extern DataAttribute iedModel_PROT_ID0PDIF3_Mod_q;
extern DataAttribute iedModel_PROT_ID0PDIF3_Mod_t;
extern DataAttribute iedModel_PROT_ID0PDIF3_Mod_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF3_Mod_ctlModel;

extern DataObject iedModel_PROT_ID0PDIF3_Beh;
extern DataAttribute iedModel_PROT_ID0PDIF3_Beh_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF3_Beh_q;
extern DataAttribute iedModel_PROT_ID0PDIF3_Beh_t;

extern DataObject iedModel_PROT_ID0PDIF3_Health;
extern DataAttribute iedModel_PROT_ID0PDIF3_Health_stVal;
extern DataAttribute iedModel_PROT_ID0PDIF3_Health_q;
extern DataAttribute iedModel_PROT_ID0PDIF3_Health_t;

extern DataObject iedModel_PROT_ID0PDIF3_NamPlt;
extern DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_d;

extern DataObject iedModel_PROT_ID0PDIF3_Op;
extern DataAttribute iedModel_PROT_ID0PDIF3_Op_general;
extern DataAttribute iedModel_PROT_ID0PDIF3_Op_q;
extern DataAttribute iedModel_PROT_ID0PDIF3_Op_t;

extern DataObject iedModel_PROT_ID0PDIF3_Str;
extern DataAttribute iedModel_PROT_ID0PDIF3_Str_general;
extern DataAttribute iedModel_PROT_ID0PDIF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_ID0PDIF3_Str_q;
extern DataAttribute iedModel_PROT_ID0PDIF3_Str_t;


#endif /* PROT_MODEL_H_ */
