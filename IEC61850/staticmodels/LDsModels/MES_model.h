/*
 * MES_model.h
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#ifndef MES_MODEL_H_
#define MES_MODEL_H_

extern LogicalDevice iedModel_Generic_MES;

// ---------------------------------------------------------------------------------------------------------
// 0     0  0000   000
// 00   00  0     0
// 0 0 0 0  0     0
// 0  0  0  0000   000
// 0     0  0         0
// 0     0  0         0
// 0     0  0000   000
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_MES_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_MES_LLN0_Mod_q;
extern DataAttribute iedModel_MES_LLN0_Mod_t;
extern DataAttribute iedModel_MES_LLN0_Mod_stVal;
extern DataAttribute iedModel_MES_LLN0_Mod_ctlModel;

extern DataObject    iedModel_MES_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_MES_LLN0_Beh_stVal;
extern DataAttribute iedModel_MES_LLN0_Beh_q;
extern DataAttribute iedModel_MES_LLN0_Beh_t;

extern DataObject    iedModel_MES_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_MES_LLN0_Health_stVal;
extern DataAttribute iedModel_MES_LLN0_Health_q;
extern DataAttribute iedModel_MES_LLN0_Health_t;

extern DataObject    iedModel_MES_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_MES_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_MES_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_d;
extern DataAttribute iedModel_MES_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_MES_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_MES_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_MES_LLN0_SGCB_q;
extern DataAttribute iedModel_MES_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

extern DataObject    iedModel_MES_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
extern DataAttribute iedModel_MES_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_MES_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_t;

extern DataObject    iedModel_MES_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
extern DataAttribute iedModel_MES_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_MES_LPHD1_Proxy_q;
extern DataAttribute iedModel_MES_LPHD1_Proxy_t;

// -----------------------------------------------------------------------------
// PQS1MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_PQS1MMXU1;
extern DataObject    iedModel_MES_PQS1MMXU1_Mod;
extern DataAttribute iedModel_MES_PQS1MMXU1_Mod_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_Mod_t;
extern DataAttribute iedModel_MES_PQS1MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_PQS1MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_PQS1MMXU1_Beh;
extern DataAttribute iedModel_MES_PQS1MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_PQS1MMXU1_Beh_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_Beh_t;
extern DataObject    iedModel_MES_PQS1MMXU1_Health;
extern DataAttribute iedModel_MES_PQS1MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_PQS1MMXU1_Health_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_Health_t;
extern DataObject    iedModel_MES_PQS1MMXU1_NamPlt;
extern DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_d;

// totW
extern DataObject    iedModel_MES_PQS1MMXU1_totW;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_mag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_mag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_instMag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_instMag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_t;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_db;
extern DataAttribute iedModel_MES_PQS1MMXU1_totW_zeroDb;

// totVAr
extern DataObject    iedModel_MES_PQS1MMXU1_totVAr;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_mag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_mag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_instMag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_instMag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_t;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_db;
extern DataAttribute iedModel_MES_PQS1MMXU1_totVAr_zeroDb;

// totPF
extern DataObject    iedModel_MES_PQS1MMXU1_totPF;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_mag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_mag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_instMag;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_instMag_f;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_q;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_t;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_db;
extern DataAttribute iedModel_MES_PQS1MMXU1_totPF_zeroDb;

// -----------------------------------------------------------------------------
// S1MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_S1MMXU1;
extern DataObject    iedModel_MES_S1MMXU1_Mod;
extern DataAttribute iedModel_MES_S1MMXU1_Mod_q;
extern DataAttribute iedModel_MES_S1MMXU1_Mod_t;
extern DataAttribute iedModel_MES_S1MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_S1MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_S1MMXU1_Beh;
extern DataAttribute iedModel_MES_S1MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_S1MMXU1_Beh_q;
extern DataAttribute iedModel_MES_S1MMXU1_Beh_t;
extern DataObject    iedModel_MES_S1MMXU1_Health;
extern DataAttribute iedModel_MES_S1MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_S1MMXU1_Health_q;
extern DataAttribute iedModel_MES_S1MMXU1_Health_t;
extern DataObject    iedModel_MES_S1MMXU1_NamPlt;
extern DataAttribute iedModel_MES_S1MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S1MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S1MMXU1_NamPlt_d;

extern DataObject iedModel_MES_S1MMXU1_A;
extern DataObject iedModel_MES_S1MMXU1_A_phsA;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsA_zeroDb;

extern DataObject iedModel_MES_S1MMXU1_A_phsB;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsB_zeroDb;

extern DataObject iedModel_MES_S1MMXU1_A_phsC;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_S1MMXU1_A_phsC_zeroDb;

extern DataObject iedModel_MES_S1MMXU1_A_neut;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_S1MMXU1_A_neut_zeroDb;

// -----------------------------------------------------------------------------
// S2MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_S2MMXU1;
extern DataObject    iedModel_MES_S2MMXU1_Mod;
extern DataAttribute iedModel_MES_S2MMXU1_Mod_q;
extern DataAttribute iedModel_MES_S2MMXU1_Mod_t;
extern DataAttribute iedModel_MES_S2MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_S2MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_S2MMXU1_Beh;
extern DataAttribute iedModel_MES_S2MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_S2MMXU1_Beh_q;
extern DataAttribute iedModel_MES_S2MMXU1_Beh_t;
extern DataObject    iedModel_MES_S2MMXU1_Health;
extern DataAttribute iedModel_MES_S2MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_S2MMXU1_Health_q;
extern DataAttribute iedModel_MES_S2MMXU1_Health_t;
extern DataObject    iedModel_MES_S2MMXU1_NamPlt;
extern DataAttribute iedModel_MES_S2MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S2MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S2MMXU1_NamPlt_d;

extern DataObject iedModel_MES_S2MMXU1_A;
extern DataObject iedModel_MES_S2MMXU1_A_phsA;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsA_zeroDb;

extern DataObject iedModel_MES_S2MMXU1_A_phsB;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsB_zeroDb;

extern DataObject iedModel_MES_S2MMXU1_A_phsC;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_S2MMXU1_A_phsC_zeroDb;

extern DataObject iedModel_MES_S2MMXU1_A_neut;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_S2MMXU1_A_neut_zeroDb;

// -----------------------------------------------------------------------------
// S3MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_S3MMXU1;
extern DataObject    iedModel_MES_S3MMXU1_Mod;
extern DataAttribute iedModel_MES_S3MMXU1_Mod_q;
extern DataAttribute iedModel_MES_S3MMXU1_Mod_t;
extern DataAttribute iedModel_MES_S3MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_S3MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_S3MMXU1_Beh;
extern DataAttribute iedModel_MES_S3MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_S3MMXU1_Beh_q;
extern DataAttribute iedModel_MES_S3MMXU1_Beh_t;
extern DataObject    iedModel_MES_S3MMXU1_Health;
extern DataAttribute iedModel_MES_S3MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_S3MMXU1_Health_q;
extern DataAttribute iedModel_MES_S3MMXU1_Health_t;
extern DataObject    iedModel_MES_S3MMXU1_NamPlt;
extern DataAttribute iedModel_MES_S3MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S3MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S3MMXU1_NamPlt_d;

extern DataObject iedModel_MES_S3MMXU1_A;
extern DataObject iedModel_MES_S3MMXU1_A_phsA;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsA_zeroDb;

extern DataObject iedModel_MES_S3MMXU1_A_phsB;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsB_zeroDb;

extern DataObject iedModel_MES_S3MMXU1_A_phsC;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_S3MMXU1_A_phsC_zeroDb;

extern DataObject iedModel_MES_S3MMXU1_A_neut;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_S3MMXU1_A_neut_zeroDb;
// -----------------------------------------------------------------------------
// S4MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_S4MMXU1;
extern DataObject    iedModel_MES_S4MMXU1_Mod;
extern DataAttribute iedModel_MES_S4MMXU1_Mod_q;
extern DataAttribute iedModel_MES_S4MMXU1_Mod_t;
extern DataAttribute iedModel_MES_S4MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_S4MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_S4MMXU1_Beh;
extern DataAttribute iedModel_MES_S4MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_S4MMXU1_Beh_q;
extern DataAttribute iedModel_MES_S4MMXU1_Beh_t;
extern DataObject    iedModel_MES_S4MMXU1_Health;
extern DataAttribute iedModel_MES_S4MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_S4MMXU1_Health_q;
extern DataAttribute iedModel_MES_S4MMXU1_Health_t;
extern DataObject    iedModel_MES_S4MMXU1_NamPlt;
extern DataAttribute iedModel_MES_S4MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S4MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S4MMXU1_NamPlt_d;

extern DataObject iedModel_MES_S4MMXU1_A;
extern DataObject iedModel_MES_S4MMXU1_A_phsA;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsA_zeroDb;

extern DataObject iedModel_MES_S4MMXU1_A_phsB;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsB_zeroDb;

extern DataObject iedModel_MES_S4MMXU1_A_phsC;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_S4MMXU1_A_phsC_zeroDb;

extern DataObject iedModel_MES_S4MMXU1_A_neut;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_S4MMXU1_A_neut_zeroDb;

/*******************************************************
 * U1MMXU1
 *******************************************************/
extern LogicalNode iedModel_MES_U1MMXU1;

extern DataObject iedModel_MES_U1MMXU1_Mod;
extern DataAttribute iedModel_MES_U1MMXU1_Mod_q;
extern DataAttribute iedModel_MES_U1MMXU1_Mod_t;
extern DataAttribute iedModel_MES_U1MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_U1MMXU1_Mod_ctlModel;

extern DataObject iedModel_MES_U1MMXU1_Beh;
extern DataAttribute iedModel_MES_U1MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_U1MMXU1_Beh_q;
extern DataAttribute iedModel_MES_U1MMXU1_Beh_t;

extern DataObject iedModel_MES_U1MMXU1_Health;
extern DataAttribute iedModel_MES_U1MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_U1MMXU1_Health_q;
extern DataAttribute iedModel_MES_U1MMXU1_Health_t;

extern DataObject iedModel_MES_U1MMXU1_NamPlt;
extern DataAttribute iedModel_MES_U1MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_U1MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_U1MMXU1_NamPlt_d;

extern DataObject iedModel_MES_U1MMXU1_phV;
extern DataObject iedModel_MES_U1MMXU1_phV_phsA;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_q;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_t;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_db;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsA_zeroDb;

extern DataObject iedModel_MES_U1MMXU1_phV_phsB;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_q;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_t;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_db;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsB_zeroDb;

extern DataObject iedModel_MES_U1MMXU1_phV_phsC;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_q;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_t;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_db;
extern DataAttribute iedModel_MES_U1MMXU1_phV_phsC_zeroDb;

// PPV
extern DataObject iedModel_MES_U1MMXU1_PPV;
extern DataObject iedModel_MES_U1MMXU1_PPV_phsA;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_q;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_t;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_db;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_zeroDb;

extern DataObject iedModel_MES_U1MMXU1_PPV_phsB;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_q;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_t;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_db;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_zeroDb;

extern DataObject iedModel_MES_U1MMXU1_PPV_phsC;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_q;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_t;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_db;
extern DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_zeroDb;

/*******************************************************
 * U2MMXU1
 *******************************************************/
extern LogicalNode iedModel_MES_U2MMXU1;

extern DataObject iedModel_MES_U2MMXU1_Mod;
extern DataAttribute iedModel_MES_U2MMXU1_Mod_q;
extern DataAttribute iedModel_MES_U2MMXU1_Mod_t;
extern DataAttribute iedModel_MES_U2MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_U2MMXU1_Mod_ctlModel;

extern DataObject iedModel_MES_U2MMXU1_Beh;
extern DataAttribute iedModel_MES_U2MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_U2MMXU1_Beh_q;
extern DataAttribute iedModel_MES_U2MMXU1_Beh_t;

extern DataObject iedModel_MES_U2MMXU1_Health;
extern DataAttribute iedModel_MES_U2MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_U2MMXU1_Health_q;
extern DataAttribute iedModel_MES_U2MMXU1_Health_t;

extern DataObject iedModel_MES_U2MMXU1_NamPlt;
extern DataAttribute iedModel_MES_U2MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_U2MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_U2MMXU1_NamPlt_d;

extern DataObject iedModel_MES_U2MMXU1_phV;
extern DataObject iedModel_MES_U2MMXU1_phV_phsA;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_q;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_t;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_db;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsA_zeroDb;

extern DataObject iedModel_MES_U2MMXU1_phV_phsB;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_q;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_t;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_db;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsB_zeroDb;

extern DataObject iedModel_MES_U2MMXU1_phV_phsC;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_q;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_t;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_db;
extern DataAttribute iedModel_MES_U2MMXU1_phV_phsC_zeroDb;

// PPV
extern DataObject iedModel_MES_U2MMXU1_PPV;
extern DataObject iedModel_MES_U2MMXU1_PPV_phsA;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_q;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_t;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_db;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_zeroDb;

extern DataObject iedModel_MES_U2MMXU1_PPV_phsB;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_q;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_t;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_db;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_zeroDb;

extern DataObject iedModel_MES_U2MMXU1_PPV_phsC;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_q;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_t;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_db;
extern DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_zeroDb;

/*******************************************************
 * UNMMXN1
 *******************************************************/
extern LogicalNode iedModel_MES_UNMMXN1;

extern DataObject iedModel_MES_UNMMXN1_Mod;
extern DataAttribute iedModel_MES_UNMMXN1_Mod_q;
extern DataAttribute iedModel_MES_UNMMXN1_Mod_t;
extern DataAttribute iedModel_MES_UNMMXN1_Mod_stVal;
extern DataAttribute iedModel_MES_UNMMXN1_Mod_ctlModel;

extern DataObject iedModel_MES_UNMMXN1_Beh;
extern DataAttribute iedModel_MES_UNMMXN1_Beh_stVal;
extern DataAttribute iedModel_MES_UNMMXN1_Beh_q;
extern DataAttribute iedModel_MES_UNMMXN1_Beh_t;

extern DataObject iedModel_MES_UNMMXN1_Health;
extern DataAttribute iedModel_MES_UNMMXN1_Health_stVal;
extern DataAttribute iedModel_MES_UNMMXN1_Health_q;
extern DataAttribute iedModel_MES_UNMMXN1_Health_t;

extern DataObject iedModel_MES_UNMMXN1_NamPlt;
extern DataAttribute iedModel_MES_UNMMXN1_NamPlt_vendor;
extern DataAttribute iedModel_MES_UNMMXN1_NamPlt_swRev;
extern DataAttribute iedModel_MES_UNMMXN1_NamPlt_d;

extern DataObject iedModel_MES_UNMMXN1_Vol;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_cVal;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_cVal_mag;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_cVal_mag_f;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal_mag;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal_mag_f;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_q;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_t;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_db;
extern DataAttribute iedModel_MES_UNMMXN1_Vol_zeroDb;

/*******************************************************
 * FMMXN1
 *******************************************************/
extern LogicalNode iedModel_MES_FMMXN1;

extern DataObject iedModel_MES_FMMXN1_Mod;
extern DataAttribute iedModel_MES_FMMXN1_Mod_q;
extern DataAttribute iedModel_MES_FMMXN1_Mod_t;
extern DataAttribute iedModel_MES_FMMXN1_Mod_stVal;
extern DataAttribute iedModel_MES_FMMXN1_Mod_ctlModel;

extern DataObject iedModel_MES_FMMXN1_Beh;
extern DataAttribute iedModel_MES_FMMXN1_Beh_stVal;
extern DataAttribute iedModel_MES_FMMXN1_Beh_q;
extern DataAttribute iedModel_MES_FMMXN1_Beh_t;

extern DataObject iedModel_MES_FMMXN1_Health;
extern DataAttribute iedModel_MES_FMMXN1_Health_stVal;
extern DataAttribute iedModel_MES_FMMXN1_Health_q;
extern DataAttribute iedModel_MES_FMMXN1_Health_t;

extern DataObject iedModel_MES_FMMXN1_NamPlt;
extern DataAttribute iedModel_MES_FMMXN1_NamPlt_vendor;
extern DataAttribute iedModel_MES_FMMXN1_NamPlt_swRev;
extern DataAttribute iedModel_MES_FMMXN1_NamPlt_d;

extern DataObject    iedModel_MES_FMMXN1_Hz;
extern DataAttribute iedModel_MES_FMMXN1_Hz_mag;
extern DataAttribute iedModel_MES_FMMXN1_Hz_mag_f;
extern DataAttribute iedModel_MES_FMMXN1_Hz_instMag;
extern DataAttribute iedModel_MES_FMMXN1_Hz_instMag_f;
extern DataAttribute iedModel_MES_FMMXN1_Hz_q;
extern DataAttribute iedModel_MES_FMMXN1_Hz_t;
extern DataAttribute iedModel_MES_FMMXN1_Hz_db;
extern DataAttribute iedModel_MES_FMMXN1_Hz_zeroDb;


/*******************************************************
 * S1MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_S1MSQI1;

extern DataObject iedModel_MES_S1MSQI1_Mod;
extern DataAttribute iedModel_MES_S1MSQI1_Mod_q;
extern DataAttribute iedModel_MES_S1MSQI1_Mod_t;
extern DataAttribute iedModel_MES_S1MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_S1MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_S1MSQI1_Beh;
extern DataAttribute iedModel_MES_S1MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_S1MSQI1_Beh_q;
extern DataAttribute iedModel_MES_S1MSQI1_Beh_t;

extern DataObject iedModel_MES_S1MSQI1_Health;
extern DataAttribute iedModel_MES_S1MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_S1MSQI1_Health_q;
extern DataAttribute iedModel_MES_S1MSQI1_Health_t;

extern DataObject iedModel_MES_S1MSQI1_NamPlt;
extern DataAttribute iedModel_MES_S1MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S1MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S1MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_S1MSQI1_SeqA;
extern DataObject iedModel_MES_S1MSQI1_SeqA_I1;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_q;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_t;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_db;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_zeroDb;

extern DataObject iedModel_MES_S1MSQI1_SeqA_I2;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_q;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_t;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_db;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_zeroDb;

extern DataObject iedModel_MES_S1MSQI1_SeqA_I0;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag_f;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_q;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_t;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_db;
extern DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_zeroDb;

extern DataAttribute iedModel_MES_S1MSQI1_SeqA_SeqT;

/*******************************************************
 * S2MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_S2MSQI1;

extern DataObject iedModel_MES_S2MSQI1_Mod;
extern DataAttribute iedModel_MES_S2MSQI1_Mod_q;
extern DataAttribute iedModel_MES_S2MSQI1_Mod_t;
extern DataAttribute iedModel_MES_S2MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_S2MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_S2MSQI1_Beh;
extern DataAttribute iedModel_MES_S2MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_S2MSQI1_Beh_q;
extern DataAttribute iedModel_MES_S2MSQI1_Beh_t;

extern DataObject iedModel_MES_S2MSQI1_Health;
extern DataAttribute iedModel_MES_S2MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_S2MSQI1_Health_q;
extern DataAttribute iedModel_MES_S2MSQI1_Health_t;

extern DataObject iedModel_MES_S2MSQI1_NamPlt;
extern DataAttribute iedModel_MES_S2MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S2MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S2MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_S2MSQI1_SeqA;
extern DataObject iedModel_MES_S2MSQI1_SeqA_I1;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_q;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_t;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_db;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_zeroDb;

extern DataObject iedModel_MES_S2MSQI1_SeqA_I2;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_q;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_t;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_db;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_zeroDb;

extern DataObject iedModel_MES_S2MSQI1_SeqA_I0;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag_f;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_q;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_t;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_db;
extern DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_zeroDb;

extern DataAttribute iedModel_MES_S2MSQI1_SeqA_SeqT;

/*******************************************************
 * S3MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_S3MSQI1;

extern DataObject iedModel_MES_S3MSQI1_Mod;
extern DataAttribute iedModel_MES_S3MSQI1_Mod_q;
extern DataAttribute iedModel_MES_S3MSQI1_Mod_t;
extern DataAttribute iedModel_MES_S3MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_S3MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_S3MSQI1_Beh;
extern DataAttribute iedModel_MES_S3MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_S3MSQI1_Beh_q;
extern DataAttribute iedModel_MES_S3MSQI1_Beh_t;

extern DataObject iedModel_MES_S3MSQI1_Health;
extern DataAttribute iedModel_MES_S3MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_S3MSQI1_Health_q;
extern DataAttribute iedModel_MES_S3MSQI1_Health_t;

extern DataObject iedModel_MES_S3MSQI1_NamPlt;
extern DataAttribute iedModel_MES_S3MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S3MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S3MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_S3MSQI1_SeqA;
extern DataObject iedModel_MES_S3MSQI1_SeqA_I1;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_q;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_t;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_db;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_zeroDb;

extern DataObject iedModel_MES_S3MSQI1_SeqA_I2;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_q;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_t;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_db;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_zeroDb;

extern DataObject iedModel_MES_S3MSQI1_SeqA_I0;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag_f;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_q;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_t;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_db;
extern DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_zeroDb;

extern DataAttribute iedModel_MES_S3MSQI1_SeqA_SeqT;

/*******************************************************
 * S4MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_S4MSQI1;

extern DataObject iedModel_MES_S4MSQI1_Mod;
extern DataAttribute iedModel_MES_S4MSQI1_Mod_q;
extern DataAttribute iedModel_MES_S4MSQI1_Mod_t;
extern DataAttribute iedModel_MES_S4MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_S4MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_S4MSQI1_Beh;
extern DataAttribute iedModel_MES_S4MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_S4MSQI1_Beh_q;
extern DataAttribute iedModel_MES_S4MSQI1_Beh_t;

extern DataObject iedModel_MES_S4MSQI1_Health;
extern DataAttribute iedModel_MES_S4MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_S4MSQI1_Health_q;
extern DataAttribute iedModel_MES_S4MSQI1_Health_t;

extern DataObject iedModel_MES_S4MSQI1_NamPlt;
extern DataAttribute iedModel_MES_S4MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_S4MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_S4MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_S4MSQI1_SeqA;
extern DataObject iedModel_MES_S4MSQI1_SeqA_I1;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_q;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_t;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_db;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_zeroDb;

extern DataObject iedModel_MES_S4MSQI1_SeqA_I2;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_q;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_t;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_db;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_zeroDb;

extern DataObject iedModel_MES_S4MSQI1_SeqA_I0;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag_f;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_q;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_t;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_db;
extern DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_zeroDb;

extern DataAttribute iedModel_MES_S4MSQI1_SeqA_SeqT;


/*******************************************************
 * U1MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_U1MSQI1;

extern DataObject iedModel_MES_U1MSQI1_Mod;
extern DataAttribute iedModel_MES_U1MSQI1_Mod_q;
extern DataAttribute iedModel_MES_U1MSQI1_Mod_t;
extern DataAttribute iedModel_MES_U1MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_U1MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_U1MSQI1_Beh;
extern DataAttribute iedModel_MES_U1MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_U1MSQI1_Beh_q;
extern DataAttribute iedModel_MES_U1MSQI1_Beh_t;

extern DataObject iedModel_MES_U1MSQI1_Health;
extern DataAttribute iedModel_MES_U1MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_U1MSQI1_Health_q;
extern DataAttribute iedModel_MES_U1MSQI1_Health_t;

extern DataObject iedModel_MES_U1MSQI1_NamPlt;
extern DataAttribute iedModel_MES_U1MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_U1MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_U1MSQI1_NamPlt_d;

// SeqU
extern DataObject iedModel_MES_U1MSQI1_SeqU;
extern DataObject iedModel_MES_U1MSQI1_SeqU_U1;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_q;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_t;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_db;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_zeroDb;


extern DataObject iedModel_MES_U1MSQI1_SeqU_U2;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_q;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_t;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_db;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_zeroDb;


extern DataObject iedModel_MES_U1MSQI1_SeqU_U0;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag_f;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_q;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_t;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_db;
extern DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_zeroDb;

extern DataAttribute iedModel_MES_U1MSQI1_SeqU_SeqT;

/*******************************************************
 * U2MSQI1
 *******************************************************/
extern LogicalNode iedModel_MES_U2MSQI1;

extern DataObject iedModel_MES_U2MSQI1_Mod;
extern DataAttribute iedModel_MES_U2MSQI1_Mod_q;
extern DataAttribute iedModel_MES_U2MSQI1_Mod_t;
extern DataAttribute iedModel_MES_U2MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_U2MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_U2MSQI1_Beh;
extern DataAttribute iedModel_MES_U2MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_U2MSQI1_Beh_q;
extern DataAttribute iedModel_MES_U2MSQI1_Beh_t;

extern DataObject iedModel_MES_U2MSQI1_Health;
extern DataAttribute iedModel_MES_U2MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_U2MSQI1_Health_q;
extern DataAttribute iedModel_MES_U2MSQI1_Health_t;

extern DataObject iedModel_MES_U2MSQI1_NamPlt;
extern DataAttribute iedModel_MES_U2MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_U2MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_U2MSQI1_NamPlt_d;

// SeqU
extern DataObject iedModel_MES_U2MSQI1_SeqU;
extern DataObject iedModel_MES_U2MSQI1_SeqU_U1;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_q;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_t;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_db;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_zeroDb;


extern DataObject iedModel_MES_U2MSQI1_SeqU_U2;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_q;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_t;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_db;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_zeroDb;


extern DataObject iedModel_MES_U2MSQI1_SeqU_U0;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag_f;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_q;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_t;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_db;
extern DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_zeroDb;

extern DataAttribute iedModel_MES_U2MSQI1_SeqU_SeqT;


#endif /* MES_MODEL_H_ */
