/*
 * static_model.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */

#if defined	(MR771)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR771.h"
#include "IEC850.h"

//IedModel iedModel;

static void initializeValues();

extern DataSet iedModelds_GenericIO_LLN0_dataset0;
extern DataSet iedModelds_GenericIO_LLN0_dataset1;
extern DataSet iedModelds_GenericIO_LLN0_dataset2;

extern ReportControlBlock iedModel_GenericIO_LLN0_report0;
extern ReportControlBlock iedModel_GenericIO_LLN0_report1;
extern ReportControlBlock iedModel_GenericIO_LLN0_report2;

extern GSEControlBlock iedModel_GenericIO_LLN0_gse0;
extern GSEControlBlock iedModel_GenericIO_LLN0_gse1;

extern SettingGroupControlBlock iedModel_GenericIO_LLN0_sgcb0;

//-----
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda0;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda1;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda2;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda3;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda4;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda5;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda6;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda7;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda8;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda9;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda10;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda11;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda12;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda13;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda14;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda15;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda16;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda17;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda18;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda19;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda20;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda21;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda22;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda23;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda24;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda25;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda26;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda27;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda28;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda29;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda30;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda31;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda32;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda33;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda34;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda35;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda36;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda37;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda38;
extern	DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda39;

extern	DataSetEntry iedModelds_GenericIO_Events1_fcda0;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda1;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda2;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda3;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda4;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda5;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda6;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda7;
extern	DataSetEntry iedModelds_GenericIO_Events1_fcda8;

extern	DataSetEntry iedModelds_GenericIO_MMXU_fcda1;
extern	DataSetEntry iedModelds_GenericIO_MMXU_fcda2;
extern	DataSetEntry iedModelds_GenericIO_MMXU_fcda3;
extern	DataSetEntry iedModelds_GenericIO_MMXU_fcda4;


// логические устройства в составе -------------------------------------iedModel_Generic_GGIO
LogicalDevice iedModel_Generic_PROT;
//LogicalDevice iedModel_Generic_CTRL;
//LogicalDevice iedModel_Generic_MES;
//LogicalDevice iedModel_Generic_GGIO;


LogicalNode   iedModel_GenericIO_LLN0;								// Логический нуль узла. Имя: LLN0

DataObject    iedModel_GenericIO_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_GenericIO_LLN0_Mod_q;
DataAttribute iedModel_GenericIO_LLN0_Mod_t;
DataAttribute iedModel_GenericIO_LLN0_Mod_stVal;
DataAttribute iedModel_GenericIO_LLN0_Mod_ctlModel;

DataObject    iedModel_GenericIO_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_GenericIO_LLN0_Beh_stVal;
DataAttribute iedModel_GenericIO_LLN0_Beh_q;
DataAttribute iedModel_GenericIO_LLN0_Beh_t;

DataObject    iedModel_GenericIO_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_GenericIO_LLN0_Health_stVal;
DataAttribute iedModel_GenericIO_LLN0_Health_q;
DataAttribute iedModel_GenericIO_LLN0_Health_t;

DataObject    iedModel_GenericIO_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_GenericIO_LLN0_NamPlt_vendor;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_swRev;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_d;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_configRev;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_ldNs;

DataObject    iedModel_GenericIO_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_GenericIO_LLN0_SGCB_ActSG;
DataAttribute iedModel_GenericIO_LLN0_SGCB_q;
DataAttribute iedModel_GenericIO_LLN0_SGCB_t;


LogicalNode   iedModel_GenericIO_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_GenericIO_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_GenericIO_LPHD1_PhyNam_vendor;

DataObject    iedModel_GenericIO_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_q;
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_t;

DataObject    iedModel_GenericIO_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_GenericIO_LPHD1_Proxy_stVal;
DataAttribute iedModel_GenericIO_LPHD1_Proxy_q;
DataAttribute iedModel_GenericIO_LPHD1_Proxy_t;

LogicalNode   iedModel_GenericIO_GGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

DataObject    iedModel_GenericIO_GGIO1_Mod;							// Mod - Режим
DataAttribute iedModel_GenericIO_GGIO1_Mod_q;
DataAttribute iedModel_GenericIO_GGIO1_Mod_t;
DataAttribute iedModel_GenericIO_GGIO1_Mod_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Mod_ctlModel;

DataObject    iedModel_GenericIO_GGIO1_Beh;							// Beh - Режим работы
DataAttribute iedModel_GenericIO_GGIO1_Beh_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Beh_q;
DataAttribute iedModel_GenericIO_GGIO1_Beh_t;

DataObject    iedModel_GenericIO_GGIO1_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_GenericIO_GGIO1_Health_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Health_q;
DataAttribute iedModel_GenericIO_GGIO1_Health_t;

DataObject    iedModel_GenericIO_GGIO1_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_vendor;
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_swRev;
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_d;
/*
DataObject    iedModel_GenericIO_GGIO1_AnIn1;						//An Аналоговый
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_t;

DataObject    iedModel_GenericIO_GGIO1_AnIn2;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_t;

DataObject    iedModel_GenericIO_GGIO1_AnIn3;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_t;

DataObject    iedModel_GenericIO_GGIO1_AnIn4;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_t;
*/
DataObject    iedModel_GenericIO_GGIO1_SPCSO1;								//SPCSO Контролируемый выход статуса недублированного управления
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO2;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_q;
/*
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_ctlModel;
*/
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO3;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q;
/*
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_ctlModel;
*/
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO4;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q;
/*
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_ctlModel;
*/
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO5;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO6;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO7;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO8;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_t;
/***********************************************************************************
 *
 **********************************************************************************/

DataObject    iedModel_GenericIO_GGIO1_Ind1;							//Ind Индикация
DataAttribute iedModel_GenericIO_GGIO1_Ind1_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind1_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind1_t;

DataObject    iedModel_GenericIO_GGIO1_Ind2;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_t;

DataObject    iedModel_GenericIO_GGIO1_Ind3;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_t;

DataObject    iedModel_GenericIO_GGIO1_Ind4;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_t;

DataObject    iedModel_GenericIO_GGIO1_Ind5;
DataAttribute iedModel_GenericIO_GGIO1_Ind5_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind5_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind5_t;

DataObject    iedModel_GenericIO_GGIO1_Ind6;
DataAttribute iedModel_GenericIO_GGIO1_Ind6_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind6_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind6_t;

DataObject    iedModel_GenericIO_GGIO1_Ind7;
DataAttribute iedModel_GenericIO_GGIO1_Ind7_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind7_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind7_t;

DataObject    iedModel_GenericIO_GGIO1_Ind8;
DataAttribute iedModel_GenericIO_GGIO1_Ind8_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind8_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind8_t;

DataObject    iedModel_GenericIO_GGIO1_Ind9;
DataAttribute iedModel_GenericIO_GGIO1_Ind9_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind9_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind9_t;

DataObject    iedModel_GenericIO_GGIO1_Ind10;
DataAttribute iedModel_GenericIO_GGIO1_Ind10_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind10_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind10_t;

DataObject    iedModel_GenericIO_GGIO1_Ind11;
DataAttribute iedModel_GenericIO_GGIO1_Ind11_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind11_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind11_t;

DataObject    iedModel_GenericIO_GGIO1_Ind12;
DataAttribute iedModel_GenericIO_GGIO1_Ind12_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind12_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind12_t;

DataObject    iedModel_GenericIO_GGIO1_Ind13;
DataAttribute iedModel_GenericIO_GGIO1_Ind13_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind13_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind13_t;

DataObject    iedModel_GenericIO_GGIO1_Ind14;
DataAttribute iedModel_GenericIO_GGIO1_Ind14_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind14_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind14_t;

DataObject    iedModel_GenericIO_GGIO1_Ind15;
DataAttribute iedModel_GenericIO_GGIO1_Ind15_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind15_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind15_t;

DataObject    iedModel_GenericIO_GGIO1_Ind16;
DataAttribute iedModel_GenericIO_GGIO1_Ind16_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind16_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind16_t;

DataObject    iedModel_GenericIO_GGIO1_Ind17;
DataAttribute iedModel_GenericIO_GGIO1_Ind17_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind17_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind17_t;

DataObject    iedModel_GenericIO_GGIO1_Ind18;
DataAttribute iedModel_GenericIO_GGIO1_Ind18_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind18_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind18_t;

DataObject    iedModel_GenericIO_GGIO1_Ind19;
DataAttribute iedModel_GenericIO_GGIO1_Ind19_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind19_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind19_t;

DataObject    iedModel_GenericIO_GGIO1_Ind20;
DataAttribute iedModel_GenericIO_GGIO1_Ind20_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind20_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind20_t;

DataObject    iedModel_GenericIO_GGIO1_Ind21;
DataAttribute iedModel_GenericIO_GGIO1_Ind21_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind21_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind21_t;

DataObject    iedModel_GenericIO_GGIO1_Ind22;
DataAttribute iedModel_GenericIO_GGIO1_Ind22_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind22_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind22_t;

DataObject    iedModel_GenericIO_GGIO1_Ind23;
DataAttribute iedModel_GenericIO_GGIO1_Ind23_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind23_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind23_t;

DataObject    iedModel_GenericIO_GGIO1_Ind24;
DataAttribute iedModel_GenericIO_GGIO1_Ind24_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind24_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind24_t;

DataObject    iedModel_GenericIO_GGIO1_Ind25;
DataAttribute iedModel_GenericIO_GGIO1_Ind25_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind25_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind25_t;

DataObject    iedModel_GenericIO_GGIO1_Ind26;
DataAttribute iedModel_GenericIO_GGIO1_Ind26_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind26_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind26_t;

DataObject    iedModel_GenericIO_GGIO1_Ind27;
DataAttribute iedModel_GenericIO_GGIO1_Ind27_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind27_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind27_t;

DataObject    iedModel_GenericIO_GGIO1_Ind28;
DataAttribute iedModel_GenericIO_GGIO1_Ind28_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind28_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind28_t;

DataObject    iedModel_GenericIO_GGIO1_Ind29;
DataAttribute iedModel_GenericIO_GGIO1_Ind29_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind29_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind29_t;

DataObject    iedModel_GenericIO_GGIO1_Ind30;
DataAttribute iedModel_GenericIO_GGIO1_Ind30_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind30_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind30_t;

DataObject    iedModel_GenericIO_GGIO1_Ind31;
DataAttribute iedModel_GenericIO_GGIO1_Ind31_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind31_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind31_t;

DataObject    iedModel_GenericIO_GGIO1_Ind32;
DataAttribute iedModel_GenericIO_GGIO1_Ind32_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind32_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind32_t;

DataObject    iedModel_GenericIO_GGIO1_Ind33;
DataAttribute iedModel_GenericIO_GGIO1_Ind33_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind33_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind33_t;

DataObject    iedModel_GenericIO_GGIO1_Ind34;
DataAttribute iedModel_GenericIO_GGIO1_Ind34_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind34_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind34_t;

DataObject    iedModel_GenericIO_GGIO1_Ind35;
DataAttribute iedModel_GenericIO_GGIO1_Ind35_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind35_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind35_t;

DataObject    iedModel_GenericIO_GGIO1_Ind36;
DataAttribute iedModel_GenericIO_GGIO1_Ind36_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind36_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind36_t;

DataObject    iedModel_GenericIO_GGIO1_Ind37;
DataAttribute iedModel_GenericIO_GGIO1_Ind37_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind37_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind37_t;

DataObject    iedModel_GenericIO_GGIO1_Ind38;
DataAttribute iedModel_GenericIO_GGIO1_Ind38_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind38_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind38_t;

DataObject    iedModel_GenericIO_GGIO1_Ind39;
DataAttribute iedModel_GenericIO_GGIO1_Ind39_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind39_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind39_t;

DataObject    iedModel_GenericIO_GGIO1_Ind40;
DataAttribute iedModel_GenericIO_GGIO1_Ind40_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind40_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind40_t;
// ------------------------------------------------------------ SPC8GGIO
LogicalNode iedModel_GenericIO_GGIO2;

DataObject iedModel_GenericIO_GGIO2_Mod;
DataAttribute iedModel_GenericIO_GGIO2_Mod_q;
DataAttribute iedModel_GenericIO_GGIO2_Mod_t;
DataAttribute iedModel_GenericIO_GGIO2_Mod_stVal;
DataAttribute iedModel_GenericIO_GGIO2_Mod_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_Check;
//Beh
DataObject iedModel_GenericIO_GGIO2_Beh;
DataAttribute iedModel_GenericIO_GGIO2_Beh_stVal;
DataAttribute iedModel_GenericIO_GGIO2_Beh_q;
DataAttribute iedModel_GenericIO_GGIO2_Beh_t;
//Health
DataObject iedModel_GenericIO_GGIO2_Health;
DataAttribute iedModel_GenericIO_GGIO2_Health_stVal;
DataAttribute iedModel_GenericIO_GGIO2_Health_q;
DataAttribute iedModel_GenericIO_GGIO2_Health_t;
//NamPlt
DataObject iedModel_GenericIO_GGIO2_NamPlt;
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_vendor;
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_swRev;
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_d;

//SPCSO1
DataObject iedModel_GenericIO_GGIO2_SPCSO1;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_Check;
//SPCSO2
DataObject iedModel_GenericIO_GGIO2_SPCSO2;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_Check;
//SPCSO3
DataObject iedModel_GenericIO_GGIO2_SPCSO3;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_Check;
//SPCSO4
DataObject iedModel_GenericIO_GGIO2_SPCSO4;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_Check;
//SPCSO5
DataObject iedModel_GenericIO_GGIO2_SPCSO5;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_Check;
//SPCSO6
DataObject iedModel_GenericIO_GGIO2_SPCSO6;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_Check;
//SPCSO7
DataObject iedModel_GenericIO_GGIO2_SPCSO7;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_Check;
//SPCSO8
DataObject iedModel_GenericIO_GGIO2_SPCSO8;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_q;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_t;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_stVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_ctlModel;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_T;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_Check;

//****************************************************************************
LogicalNode   iedModel_GenericIO_MMXU1;

// Mod																// обязательные элементы -------------------------------------
DataObject    iedModel_GenericIO_MMXU1_Mod;					// РЕЖИМ
DataAttribute iedModel_GenericIO_MMXU1_Mod_q;
DataAttribute iedModel_GenericIO_MMXU1_Mod_t;
DataAttribute iedModel_GenericIO_MMXU1_Mod_stVal;
DataAttribute iedModel_GenericIO_MMXU1_Mod_ctlModel;

// Beh
DataObject    iedModel_GenericIO_MMXU1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_GenericIO_MMXU1_Beh_stVal;
DataAttribute iedModel_GenericIO_MMXU1_Beh_q;
DataAttribute iedModel_GenericIO_MMXU1_Beh_t;

// Health
DataObject    iedModel_GenericIO_MMXU1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_GenericIO_MMXU1_Health_stVal;
DataAttribute iedModel_GenericIO_MMXU1_Health_q;
DataAttribute iedModel_GenericIO_MMXU1_Health_t;

// NamPlt
DataObject    iedModel_GenericIO_MMXU1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN MMXU1.

DataObject iedModel_GenericIO_MMXU1_A;
DataObject iedModel_GenericIO_MMXU1_A_phsA;
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal;
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_q;
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_t;

DataObject iedModel_GenericIO_MMXU1_A_phsB;
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal;
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_q;
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_t;

DataObject iedModel_GenericIO_MMXU1_A_phsC;
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal;
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_q;
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_t;

DataObject iedModel_GenericIO_MMXU1_phV;
DataObject iedModel_GenericIO_MMXU1_phV_phsA;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_q;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_t;
DataObject iedModel_GenericIO_MMXU1_phV_phsB;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_q;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_t;
DataObject iedModel_GenericIO_MMXU1_phV_phsC;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_q;
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_t;
//-
DataObject iedModel_GenericIO_MMXU1_PPV;
DataObject iedModel_GenericIO_MMXU1_PPV_phsA;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_q;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_t;
DataObject iedModel_GenericIO_MMXU1_PPV_phsB;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_q;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_t;
DataObject iedModel_GenericIO_MMXU1_PPV_phsC;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_q;
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_t;
//-
DataObject    iedModel_GenericIO_MMXU1_totW;
DataAttribute iedModel_GenericIO_MMXU1_totW_mag;
DataAttribute iedModel_GenericIO_MMXU1_totW_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_totW_q;
DataAttribute iedModel_GenericIO_MMXU1_totW_t;
DataAttribute iedModel_GenericIO_MMXU1_totW_db;
DataAttribute iedModel_GenericIO_MMXU1_totW_zeroDb;

DataObject    iedModel_GenericIO_MMXU1_totVAr;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_mag;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_q;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_t;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_db;
DataAttribute iedModel_GenericIO_MMXU1_totVAr_zeroDb;

DataObject    iedModel_GenericIO_MMXU1_totPF;
DataAttribute iedModel_GenericIO_MMXU1_totPF_mag;
DataAttribute iedModel_GenericIO_MMXU1_totPF_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_totPF_q;
DataAttribute iedModel_GenericIO_MMXU1_totPF_t;
DataAttribute iedModel_GenericIO_MMXU1_totPF_db;
DataAttribute iedModel_GenericIO_MMXU1_totPF_zeroDb;

DataObject    iedModel_GenericIO_MMXU1_Hz;
DataAttribute iedModel_GenericIO_MMXU1_Hz_mag;
DataAttribute iedModel_GenericIO_MMXU1_Hz_mag_f;
DataAttribute iedModel_GenericIO_MMXU1_Hz_q;
DataAttribute iedModel_GenericIO_MMXU1_Hz_t;
DataAttribute iedModel_GenericIO_MMXU1_Hz_db;
DataAttribute iedModel_GenericIO_MMXU1_Hz_zeroDb;

//****************************************************************************
// LN PTOC
LogicalNode   iedModel_GenericIO_PTOC1;

// Mod														// обязательные элементы -------------------------------------
DataObject    iedModel_GenericIO_PTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_GenericIO_PTOC1_Mod_q;
DataAttribute iedModel_GenericIO_PTOC1_Mod_t;
DataAttribute iedModel_GenericIO_PTOC1_Mod_stVal;
DataAttribute iedModel_GenericIO_PTOC1_Mod_ctlModel;

// Beh
DataObject    iedModel_GenericIO_PTOC1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_GenericIO_PTOC1_Beh_stVal;
DataAttribute iedModel_GenericIO_PTOC1_Beh_q;
DataAttribute iedModel_GenericIO_PTOC1_Beh_t;

// Health
DataObject    iedModel_GenericIO_PTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_GenericIO_PTOC1_Health_stVal;
DataAttribute iedModel_GenericIO_PTOC1_Health_q;
DataAttribute iedModel_GenericIO_PTOC1_Health_t;

// NamPlt
DataObject    iedModel_GenericIO_PTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

// Str
DataObject    iedModel_GenericIO_PTOC1_Str;
DataAttribute iedModel_GenericIO_PTOC1_Str_general;
DataAttribute iedModel_GenericIO_PTOC1_Str_dirGeneral;
DataAttribute iedModel_GenericIO_PTOC1_Str_q;
DataAttribute iedModel_GenericIO_PTOC1_Str_t;

// Op
DataObject    iedModel_GenericIO_PTOC1_Op;
DataAttribute iedModel_GenericIO_PTOC1_Op_general;
DataAttribute iedModel_GenericIO_PTOC1_Op_q;
DataAttribute iedModel_GenericIO_PTOC1_Op_t;

//****************************************************************************
// LN CSWI
// -----------------------------------------------------------------------------


LogicalNode   iedModel_GenericIO_CSWI1;

// Mod																// обязательные элементы -------------------------------------
DataObject    iedModel_GenericIO_CSWI1_Mod;					// РЕЖИМ
DataAttribute iedModel_GenericIO_CSWI1_Mod_q;
DataAttribute iedModel_GenericIO_CSWI1_Mod_t;
DataAttribute iedModel_GenericIO_CSWI1_Mod_stVal;
DataAttribute iedModel_GenericIO_CSWI1_Mod_ctlModel;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_ctlVal;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_ctlNum;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_T;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_Test;
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_Check;


// Beh
DataObject    iedModel_GenericIO_CSWI1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_GenericIO_CSWI1_Beh_stVal;
DataAttribute iedModel_GenericIO_CSWI1_Beh_q;
DataAttribute iedModel_GenericIO_CSWI1_Beh_t;

// Health
DataObject    iedModel_GenericIO_CSWI1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_GenericIO_CSWI1_Health_stVal;
DataAttribute iedModel_GenericIO_CSWI1_Health_q;
DataAttribute iedModel_GenericIO_CSWI1_Health_t;

// NamPlt
DataObject    iedModel_GenericIO_CSWI1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN CSWI1.


DataObject iedModel_GenericIO_CSWI1_Pos;
DataAttribute iedModel_GenericIO_CSWI1_Pos_stVal;
DataAttribute iedModel_GenericIO_CSWI1_Pos_q;
DataAttribute iedModel_GenericIO_CSWI1_Pos_t;
DataAttribute iedModel_GenericIO_CSWI1_Pos_ctlModel;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_ctlVal;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_ctlNum;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_T;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_Test;
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_Check;
//****************************************************************************
// LN XCBR1
// -----------------------------------------------------------------------------
LogicalNode iedModel_GenericIO_XCBR1;
DataObject iedModel_GenericIO_XCBR1_Mod;
DataAttribute iedModel_GenericIO_XCBR1_Mod_q;
DataAttribute iedModel_GenericIO_XCBR1_Mod_t;
DataAttribute iedModel_GenericIO_XCBR1_Mod_stVal;
DataAttribute iedModel_GenericIO_XCBR1_Mod_ctlModel;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_ctlVal;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_ctlNum;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_T;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_Test;
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_Check;

DataObject iedModel_GenericIO_XCBR1_Beh;
DataAttribute iedModel_GenericIO_XCBR1_Beh_stVal;
DataAttribute iedModel_GenericIO_XCBR1_Beh_q;
DataAttribute iedModel_GenericIO_XCBR1_Beh_t;

DataObject iedModel_GenericIO_XCBR1_Health;
DataAttribute iedModel_GenericIO_XCBR1_Health_stVal;
DataAttribute iedModel_GenericIO_XCBR1_Health_q;
DataAttribute iedModel_GenericIO_XCBR1_Health_t;

DataObject iedModel_GenericIO_XCBR1_NamPlt;
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_vendor;
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_swRev;
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_d;

DataObject iedModel_GenericIO_XCBR1_Pos;
DataAttribute iedModel_GenericIO_XCBR1_Pos_stVal;
DataAttribute iedModel_GenericIO_XCBR1_Pos_q;
DataAttribute iedModel_GenericIO_XCBR1_Pos_t;
DataAttribute iedModel_GenericIO_XCBR1_Pos_ctlModel;

DataObject iedModel_GenericIO_XCBR1_Loc;
DataAttribute iedModel_GenericIO_XCBR1_Loc_stVal;
DataAttribute iedModel_GenericIO_XCBR1_Loc_q;
DataAttribute iedModel_GenericIO_XCBR1_Loc_t;

DataObject iedModel_GenericIO_XCBR1_OpCnt;
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_stVal;
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_q;
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_t;

DataObject iedModel_GenericIO_XCBR1_CBOpCap;
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_stVal;
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_q;
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_t;

DataObject iedModel_GenericIO_XCBR1_BlkOpn;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_stVal;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_q;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_t;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_ctlModel;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlVal;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlNum;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_T;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_Test;
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_Check;

DataObject iedModel_GenericIO_XCBR1_BlkCls;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_stVal;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_q;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_t;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_ctlModel;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlVal;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlNum;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_T;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_Test;
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_Check;

//****************************************************************************
// LN PDIF1
// -----------------------------------------------------------------------------
LogicalNode iedModel_GenericIO_PDIF1;
DataObject iedModel_GenericIO_PDIF1_Mod;
DataAttribute iedModel_GenericIO_PDIF1_Mod_q;
DataAttribute iedModel_GenericIO_PDIF1_Mod_t;
DataAttribute iedModel_GenericIO_PDIF1_Mod_stVal;
DataAttribute iedModel_GenericIO_PDIF1_Mod_ctlModel;

DataObject iedModel_GenericIO_PDIF1_Beh;
DataAttribute iedModel_GenericIO_PDIF1_Beh_stVal;
DataAttribute iedModel_GenericIO_PDIF1_Beh_q;
DataAttribute iedModel_GenericIO_PDIF1_Beh_t;

DataObject iedModel_GenericIO_PDIF1_Health;
DataAttribute iedModel_GenericIO_PDIF1_Health_stVal;
DataAttribute iedModel_GenericIO_PDIF1_Health_q;
DataAttribute iedModel_GenericIO_PDIF1_Health_t;

DataObject iedModel_GenericIO_PDIF1_NamPlt;
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_vendor;
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_swRev;
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_d;

DataObject iedModel_GenericIO_PDIF1_Op;
DataAttribute iedModel_GenericIO_PDIF1_Op_general;
DataAttribute iedModel_GenericIO_PDIF1_Op_q;
DataAttribute iedModel_GenericIO_PDIF1_Op_t;

DataObject iedModel_GenericIO_PDIF1_DifACIc;
DataObject iedModel_GenericIO_PDIF1_DifACIc_phsA;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_q;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_t;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_db;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_zeroDb;

DataObject iedModel_GenericIO_PDIF1_DifACIc_phsB;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_q;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_t;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_db;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_zeroDb;

DataObject iedModel_GenericIO_PDIF1_DifACIc_phsC;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_q;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_t;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_db;
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_zeroDb;

DataObject iedModel_GenericIO_PDIF1_RstA;
DataObject iedModel_GenericIO_PDIF1_RstA_phsA;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_q;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_t;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_db;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_zeroDb;

DataObject iedModel_GenericIO_PDIF1_RstA_phsB;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_q;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_t;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_db;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_zeroDb;

DataObject iedModel_GenericIO_PDIF1_RstA_phsC;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag_f;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_q;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_t;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_db;
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_zeroDb;
//****************************************************************************
// LN PDIS1
// -----------------------------------------------------------------------------
LogicalNode iedModel_GenericIO_PDIS1;
DataObject iedModel_GenericIO_PDIS1_Mod;
DataAttribute iedModel_GenericIO_PDIS1_Mod_q;
DataAttribute iedModel_GenericIO_PDIS1_Mod_t;
DataAttribute iedModel_GenericIO_PDIS1_Mod_stVal;
DataAttribute iedModel_GenericIO_PDIS1_Mod_ctlModel;

DataObject iedModel_GenericIO_PDIS1_Beh;
DataAttribute iedModel_GenericIO_PDIS1_Beh_stVal;
DataAttribute iedModel_GenericIO_PDIS1_Beh_q;
DataAttribute iedModel_GenericIO_PDIS1_Beh_t;

DataObject iedModel_GenericIO_PDIS1_Health;
DataAttribute iedModel_GenericIO_PDIS1_Health_stVal;
DataAttribute iedModel_GenericIO_PDIS1_Health_q;
DataAttribute iedModel_GenericIO_PDIS1_Health_t;

DataObject iedModel_GenericIO_PDIS1_NamPlt;
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_vendor;
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_swRev;
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_d;

DataObject iedModel_GenericIO_PDIS1_Str;
DataAttribute iedModel_GenericIO_PDIS1_Str_general;
DataAttribute iedModel_GenericIO_PDIS1_Str_dirGeneral;
DataAttribute iedModel_GenericIO_PDIS1_Str_q;
DataAttribute iedModel_GenericIO_PDIS1_Str_t;

DataObject iedModel_GenericIO_PDIS1_Op;
DataAttribute iedModel_GenericIO_PDIS1_Op_general;
DataAttribute iedModel_GenericIO_PDIS1_Op_q;
DataAttribute iedModel_GenericIO_PDIS1_Op_t;
//****************************************************************************
// LN PDIS2
// -----------------------------------------------------------------------------
LogicalNode iedModel_GenericIO_PDIS2;
DataObject iedModel_GenericIO_PDIS2_Mod;
DataAttribute iedModel_GenericIO_PDIS2_Mod_q;
DataAttribute iedModel_GenericIO_PDIS2_Mod_t;
DataAttribute iedModel_GenericIO_PDIS2_Mod_stVal;
DataAttribute iedModel_GenericIO_PDIS2_Mod_ctlModel;

DataObject iedModel_GenericIO_PDIS2_Beh;
DataAttribute iedModel_GenericIO_PDIS2_Beh_stVal;
DataAttribute iedModel_GenericIO_PDIS2_Beh_q;
DataAttribute iedModel_GenericIO_PDIS2_Beh_t;

DataObject iedModel_GenericIO_PDIS2_Health;
DataAttribute iedModel_GenericIO_PDIS2_Health_stVal;
DataAttribute iedModel_GenericIO_PDIS2_Health_q;
DataAttribute iedModel_GenericIO_PDIS2_Health_t;

DataObject iedModel_GenericIO_PDIS2_NamPlt;
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_vendor;
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_swRev;
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_d;

DataObject iedModel_GenericIO_PDIS2_Str;
DataAttribute iedModel_GenericIO_PDIS2_Str_general;
DataAttribute iedModel_GenericIO_PDIS2_Str_dirGeneral;
DataAttribute iedModel_GenericIO_PDIS2_Str_q;
DataAttribute iedModel_GenericIO_PDIS2_Str_t;

DataObject iedModel_GenericIO_PDIS2_Op;
DataAttribute iedModel_GenericIO_PDIS2_Op_general;
DataAttribute iedModel_GenericIO_PDIS2_Op_q;
DataAttribute iedModel_GenericIO_PDIS2_Op_t;
//****************************************************************************
// LN PDIS3
// -----------------------------------------------------------------------------
LogicalNode iedModel_GenericIO_PDIS3;
DataObject iedModel_GenericIO_PDIS3_Mod;
DataAttribute iedModel_GenericIO_PDIS3_Mod_q;
DataAttribute iedModel_GenericIO_PDIS3_Mod_t;
DataAttribute iedModel_GenericIO_PDIS3_Mod_stVal;
DataAttribute iedModel_GenericIO_PDIS3_Mod_ctlModel;

DataObject iedModel_GenericIO_PDIS3_Beh;
DataAttribute iedModel_GenericIO_PDIS3_Beh_stVal;
DataAttribute iedModel_GenericIO_PDIS3_Beh_q;
DataAttribute iedModel_GenericIO_PDIS3_Beh_t;

DataObject iedModel_GenericIO_PDIS3_Health;
DataAttribute iedModel_GenericIO_PDIS3_Health_stVal;
DataAttribute iedModel_GenericIO_PDIS3_Health_q;
DataAttribute iedModel_GenericIO_PDIS3_Health_t;

DataObject iedModel_GenericIO_PDIS3_NamPlt;
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_vendor;
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_swRev;
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_d;

DataObject iedModel_GenericIO_PDIS3_Str;
DataAttribute iedModel_GenericIO_PDIS3_Str_general;
DataAttribute iedModel_GenericIO_PDIS3_Str_dirGeneral;
DataAttribute iedModel_GenericIO_PDIS3_Str_q;
DataAttribute iedModel_GenericIO_PDIS3_Str_t;

DataObject iedModel_GenericIO_PDIS3_Op;
DataAttribute iedModel_GenericIO_PDIS3_Op_general;
DataAttribute iedModel_GenericIO_PDIS3_Op_q;
DataAttribute iedModel_GenericIO_PDIS3_Op_t;

//****************************************************************************

IedModel iedModel = {
    "IED",
    &iedModel_Generic_PROT,
    &iedModelds_GenericIO_LLN0_dataset0,		// DataSet
    &iedModel_GenericIO_LLN0_report0,		// ReportControlBlock
    NULL,//&iedModel_GenericIO_LLN0_gse0,			// GSEControlBlock
    NULL,									// SVControlBlock
    &iedModel_GenericIO_LLN0_sgcb0,			// SettingGroupControlBlock
    NULL,									// lcbs
    NULL,									// log
    initializeValues
};

/*
 *     char* name;
    LogicalDevice* firstChild;
    DataSet* dataSets;
    ReportControlBlock* rcbs;
    GSEControlBlock* gseCBs;
    SVControlBlock* svCBs;
    SettingGroupControlBlock* sgcbs;
    LogControlBlock* lcbs;
    Log* logs;
    void (*initializer) (void);
 */
/*
IedModel iedModel = {
    "MR771",													// имя электронного устройства
    &iedModel_Generic_PROT,									// первое логическое устройство LD в IED
    (DataSetPtr*)datasets,									// набор данных
    (ReportControlBlockPtr*)reportControlBlocks,			// блок отчетов
    (GSEControBlockPtr*)gseControlBlocks,					// блок гусов
    (SettingGroupControlBlock*)settingGroupControlBlocks,	// блок контроля групп настроек.
    initializeValues
};
*/

/*************************************************************************
 * Логические устройства LD
 *
 *************************************************************************/
LogicalDevice iedModel_Generic_PROT = {
    LogicalDeviceModelType,
    "MR771PROT",							// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    NULL,					// одноранговый следующий узел				// родитель
    &iedModel_GenericIO_LLN0				// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_CTRL = {
    LogicalDeviceModelType,
    "MR771CTRL",							// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    &iedModel_Generic_MES,					// одноранговый следующий узел				// родитель
    NULL									// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_MES = {
    LogicalDeviceModelType,
    "MR771MES",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    &iedModel_Generic_GGIO,					// одноранговый следующий узел				// родитель
    NULL									// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_GGIO = {
    LogicalDeviceModelType,
    "MR771GGIO",							// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    NULL,									// одноранговый следующий узел				// родитель
    NULL									// первый LN(логический узел)
};
/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_GenericIO_LLN0 = {
    LogicalNodeModelType,						// тип модели : LogicalNode,DataObject,DataAttribute
    "LLN0",										// имя узла
    &iedModel_Generic_PROT,						// родитель узла (LD (logical device))
    (ModelNode*) &iedModel_GenericIO_LPHD1,		// одноранговый следующий узел
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,	// первый наследник
};

DataObject iedModel_GenericIO_LLN0_Mod = {
    DataObjectModelType,
    "Mod",										// Режим
    (ModelNode*) &iedModel_GenericIO_LLN0,		// Родитель
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,	// одноранговый
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_q,// первый наследник
    0
};

DataAttribute iedModel_GenericIO_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_t,
    NULL,
    0,
    IEC61850_FC_CF,
    IEC61850_QUALITY,
    TRG_OPT_NO,
    NULL,
    0

};

DataAttribute iedModel_GenericIO_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_stVal,
    NULL,
    0,
    IEC61850_FC_CF,
    IEC61850_TIMESTAMP,
    TRG_OPT_NO,
    NULL,
    0
};


DataAttribute iedModel_GenericIO_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_ctlModel,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    NULL,
    NULL,
    0,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    TRG_OPT_NO,
    NULL,
    0
};

DataObject iedModel_GenericIO_LLN0_Beh = {
    DataObjectModelType,
    "Beh",												// Режим работы
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_stVal,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_q,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    TRG_OPT_NO,
    NULL,
    0
};

DataObject iedModel_GenericIO_LLN0_Health = {
    DataObjectModelType,
    "Health",												// Состояние работоспособности
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_stVal,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_q,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    TRG_OPT_NO,
    NULL,
    0
};

DataObject iedModel_GenericIO_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",													// 	Паспортная табличка
    (ModelNode*) &iedModel_GenericIO_LLN0,
    NULL,//(ModelNode*) &iedModel_GenericIO_LLN0_SGCB, //NULL,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_vendor,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_swRev,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_d,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_configRev,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_ldNs,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

//DataObject iedModel_GenericIO_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_GenericIO_LLN0,    NULL,  (ModelNode*) &iedModel_GenericIO_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_GenericIO_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_GenericIO_LLN0_SGCB, (ModelNode*) &iedModel_GenericIO_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_GenericIO_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел LN
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_LPHD1 = {
    LogicalNodeModelType,
    "LPHD",											// Информация о физическом устройстве LPHD
    &iedModel_Generic_PROT,
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
};

DataObject iedModel_GenericIO_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",												//Паспортная табличка физического устройства
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam_vendor,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    TRG_OPT_NO,
    NULL,
    0
};

DataObject iedModel_GenericIO_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",											// Состояние работоспособности физического устройства
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_stVal,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_q,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_INT32,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    TRG_OPT_NO,
    NULL,
    0
};

DataObject iedModel_GenericIO_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",													//Означает, служит ли данный LN посредником
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    NULL,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_stVal,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy, (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };

DataAttribute iedModel_GenericIO_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_t,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    TRG_OPT_NO,
    NULL,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    TRG_OPT_NO,
    NULL,
    0
};
/*************************************************************************
 * Логический узел LN
 *
 * 5.7.2 LN: Вход/выход для общих процессов. Имя: GGIO
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для моделирования общих способов
 * выполнения устройствами процессов, которые не определены в группах S, Т, X, Y или Z.
 * Все данные, перечисленные в разделе 6 настоящего стандарта,
 * могут быть использованы для соответствующих приложений логического узла GGIO.
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_GGIO1 			= { LogicalNodeModelType,   "SP40GGIO",    &iedModel_Generic_PROT,    (ModelNode*) &iedModel_GenericIO_GGIO2,    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod};

DataObject iedModel_GenericIO_GGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_q,0};
DataAttribute iedModel_GenericIO_GGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,(ModelNode*) &iedModel_GenericIO_GGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,(ModelNode*) &iedModel_GenericIO_GGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,(ModelNode*) &iedModel_GenericIO_GGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*)&iedModel_GenericIO_GGIO1_Ind1 /* &iedModel_GenericIO_GGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 *
 * Аналоговые входы ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/
// GGIO1_AnIn1
/*
DataObject iedModel_GenericIO_GGIO1_AnIn1 = { DataObjectModelType,"AnIn1", (ModelNode*) &iedModel_GenericIO_GGIO1,	(ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag, 0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag = {    DataAttributeModelType,    "mag",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_q,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag_f,    0,     IEC61850_FC_MX,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag_f = {    DataAttributeModelType,    "f",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag,    NULL,    NULL,    0,     IEC61850_FC_MX,    IEC61850_FLOAT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_t,    NULL,    0,     IEC61850_FC_MX,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,    NULL,    NULL,    0,     IEC61850_FC_MX,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_AnIn2 = {    DataObjectModelType,    "AnIn2",    (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag = {    DataAttributeModelType,    "mag",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_q,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag_f,    0,     IEC61850_FC_MX,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag_f = {    DataAttributeModelType,    "f",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,    NULL,    NULL,    0,     IEC61850_FC_MX,    IEC61850_FLOAT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_t,    NULL,    0,     IEC61850_FC_MX,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,    NULL,    NULL,    0,    IEC61850_FC_MX,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_AnIn3 = {    DataObjectModelType,    "AnIn3",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag = {    DataAttributeModelType,    "mag",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_q,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag_f,    0,    IEC61850_FC_MX,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag_f = {    DataAttributeModelType,    "f",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,    NULL,    NULL,    0,    IEC61850_FC_MX,    IEC61850_FLOAT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_t,    NULL,    0,     IEC61850_FC_MX,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,    NULL,    NULL,    0,    IEC61850_FC_MX,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_AnIn4 = {    DataObjectModelType,    "AnIn4",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag = {    DataAttributeModelType,    "mag",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_q,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag_f,    0,     IEC61850_FC_MX,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag_f = {    DataAttributeModelType,    "f",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,    NULL,    NULL,    0,     IEC61850_FC_MX,    IEC61850_FLOAT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_t,    NULL,    0,     IEC61850_FC_MX,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,    NULL,    NULL,    0,     IEC61850_FC_MX,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
*/
/***************************************************************************************************************************************************************
 *
 * Выходы ОБЩИХ ПРОЦЕССОВ (Реле)
 *
 ****************************************************************************************************************************************************************/
/*
DataObject iedModel_GenericIO_GGIO1_SPCSO1 = {    DataObjectModelType,    "R1",    (ModelNode*) &iedModel_GenericIO_GGIO1,  (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2, (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_q,    NULL,    0,   IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper = {    DataAttributeModelType,    "Oper",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_ctlModel,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal = {    DataAttributeModelType,    "ctlVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin = {    DataAttributeModelType,    "origin",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat = {    DataAttributeModelType,    "orCat",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent = {    DataAttributeModelType,    "orIdent",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum = {    DataAttributeModelType,    "ctlNum",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_T = {    DataAttributeModelType,    "T",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test = {    DataAttributeModelType,    "Test",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check = {    DataAttributeModelType,    "Check",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO2 = {    DataObjectModelType,    "R2",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO3 = {    DataObjectModelType,    "R3",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO4 = {    DataObjectModelType,    "R4",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5 ,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO5 = {    DataObjectModelType,    "R5",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO6 = {    DataObjectModelType,    "R6",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO7 = {    DataObjectModelType,    "R7",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO1_SPCSO8 = {    DataObjectModelType,    "R8",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*)&iedModel_GenericIO_GGIO1_Ind1 ,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8,    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_SPCSO8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
*/

/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_GenericIO_GGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

DataObject iedModel_GenericIO_GGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*)&iedModel_GenericIO_GGIO1_Ind6,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GenericIO_GGIO1,    (ModelNode*)&iedModel_GenericIO_GGIO1_Ind9,   (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_stVal,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind13 = { DataObjectModelType, "Ind13", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind14 = { DataObjectModelType, "Ind14", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind15 = { DataObjectModelType, "Ind15", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*)&iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind16 = { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind17, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------

DataObject iedModel_GenericIO_GGIO1_Ind17 = { DataObjectModelType, "Ind17", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind18, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind17_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind17_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind17_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind17, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind18 = { DataObjectModelType, "Ind18", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind19, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind18_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind18_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind18_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind18, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind19 = { DataObjectModelType, "Ind19", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind20, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind19_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind19_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind19_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind19, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind20 = { DataObjectModelType, "Ind20", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind21, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind20_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind20_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind20_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind20, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind21 = { DataObjectModelType, "Ind21", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind22, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind21_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind21_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind21_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind21, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind22 = { DataObjectModelType, "Ind22", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*) &iedModel_GenericIO_GGIO1_Ind23, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind22_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind22_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind22_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind22, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind23 = { DataObjectModelType, "Ind23", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind24, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind23_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind23_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind23_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind23, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind24 = { DataObjectModelType, "Ind24", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind25, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind24_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind24_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind24_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind24, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind25 = { DataObjectModelType, "Ind25", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind26, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind25_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind25_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind25_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind25, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind26 = { DataObjectModelType, "Ind26", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind27, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind26_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind26_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind26_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind26, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind27 = { DataObjectModelType, "Ind27", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind28, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind27_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind27_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind27_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind27, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind28 = { DataObjectModelType, "Ind28", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind29, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind28_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind28_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind28_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind28, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind29 = { DataObjectModelType, "Ind29", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind30, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind29_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind29_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind29_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind29, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind30 = { DataObjectModelType, "Ind30", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind31, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind30_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind30_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind30_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind30, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind31 = { DataObjectModelType, "Ind31", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind32, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind31_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind31_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind31_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind31, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind32 = { DataObjectModelType, "Ind32", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind33, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind32_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind32_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind32_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind32, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind33 = { DataObjectModelType, "Ind33", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind34, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind33_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind33_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind33_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind33, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind34 = { DataObjectModelType, "Ind34", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind35, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind34_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind34_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind34_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind34, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind35 = { DataObjectModelType, "Ind35", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind36, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind35_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind35_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind35_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind35, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind36 = { DataObjectModelType, "Ind36", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind37, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind36_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind36_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind36_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind36, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind37 = { DataObjectModelType, "Ind37", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind38, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind37_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind37_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind37_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind37, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind38 = { DataObjectModelType, "Ind38", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind39, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind38_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind38_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind38_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind38, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind39 = { DataObjectModelType, "Ind39", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)&iedModel_GenericIO_GGIO1_Ind40, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind39_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind39_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind39_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind39, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind40 = { DataObjectModelType, "Ind40", (ModelNode*) &iedModel_GenericIO_GGIO1,(ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40_stVal, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind40_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind40_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO1_Ind40_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind40, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};

/*************************************************************************
 * GGIO2 с управлением.
 ************************************************************************/
LogicalNode iedModel_GenericIO_GGIO2 						= { LogicalNodeModelType,   	"SPC8GGIO",   (ModelNode*) &iedModel_Generic_PROT,    (ModelNode*) &iedModel_GenericIO_MMXU1,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod};

DataObject iedModel_GenericIO_GGIO2_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GenericIO_GGIO2,    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_q,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod,(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod,(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GenericIO_GGIO2_Mod,(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod, (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod,   NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GenericIO_GGIO2_Beh 					= {    DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GenericIO_GGIO2,    (ModelNode*) &iedModel_GenericIO_GGIO2_Health,    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh_stVal,0};
DataAttribute iedModel_GenericIO_GGIO2_Beh_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Beh_q 				= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh,    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Beh_t 				= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GenericIO_GGIO2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//Health
DataObject iedModel_GenericIO_GGIO2_Health 					= {    DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GenericIO_GGIO2,    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO2_Health_stVal,0};
DataAttribute iedModel_GenericIO_GGIO2_Health_stVal 		= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_GGIO2_Health,    (ModelNode*) &iedModel_GenericIO_GGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Health_q 			= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GenericIO_GGIO2_Health,    (ModelNode*) &iedModel_GenericIO_GGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_Health_t 			= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GenericIO_GGIO2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//NamPlt
DataObject iedModel_GenericIO_GGIO2_NamPlt 					= {    DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GenericIO_GGIO2,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1,    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_vendor 		= {    DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_swRev 		= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt,    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_NamPlt_d 			= {    DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GenericIO_GGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GenericIO_GGIO2_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GenericIO_GGIO2,     		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1, 		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1, 		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1, 		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1, 		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1,   	NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO1_Oper, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*)  &iedModel_GenericIO_GGIO2_SPCSO3,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO2_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO3_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO4 						= {    DataObjectModelType,     "SPCSO4",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO4_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO4_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO5 						= {    DataObjectModelType,     "SPCSO5",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO5_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO5_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO6 						= {    DataObjectModelType,     "SPCSO6",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO6_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO6_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO7 						= {    DataObjectModelType,     "SPCSO7",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO7_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO7_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_GGIO2_SPCSO8 						= {    DataObjectModelType,     "SPCSO8",     		(ModelNode*) &iedModel_GenericIO_GGIO2,     			(ModelNode*) NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_q,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8, 			(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8,   		NULL,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_GGIO2_SPCSO8_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_GGIO2_SPCSO8_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел LN
 *
 * 5.10.7 LN: измерения Имя: MMXU
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для
 * получения значений CT VT трансформаторов и вычисления измеряемых величин.
 *
 *************************************************************************/								// iedModel_GenericIO_PTOC1
LogicalNode iedModel_GenericIO_MMXU1 = {    LogicalNodeModelType,    "MMXU",    &iedModel_Generic_PROT,   (ModelNode*) &iedModel_GenericIO_PTOC1,    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod};

DataObject iedModel_GenericIO_MMXU1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_MMXU1,    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh,    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod_q,0};
DataAttribute iedModel_GenericIO_MMXU1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod,    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod,    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod,    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GenericIO_MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_MMXU1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_MMXU1,    (ModelNode*) &iedModel_GenericIO_MMXU1_Health,    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_MMXU1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh,    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh,    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_MMXU1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_MMXU1,    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt,    (ModelNode*) &iedModel_GenericIO_MMXU1_Health_stVal,0};
DataAttribute iedModel_GenericIO_MMXU1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_MMXU1_Health,    (ModelNode*) &iedModel_GenericIO_MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_MMXU1_Health,    (ModelNode*) &iedModel_GenericIO_MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_MMXU1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_MMXU1,    (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt,    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt,    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GenericIO_MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_GenericIO_MMXU1_A 						= { DataObjectModelType, "A", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)&iedModel_GenericIO_MMXU1_phV, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA, 0 };
DataObject iedModel_GenericIO_MMXU1_A_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_A_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_q, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsA, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_A_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_A_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_q, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsB, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_A_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_q, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_A_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_A_phsC, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};


DataObject iedModel_GenericIO_MMXU1_phV 					= { DataObjectModelType, "PhV", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA, 0 };
DataObject iedModel_GenericIO_MMXU1_phV_phsA 				= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_phV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_q, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsA, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_phV_phsB 				= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_phV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_q, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsB, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_phV_phsC 				= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)NULL /*&iedModel_GenericIO_MMXU1_phV_phsC*/, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_q, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_phV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_phV_phsC, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

// PPV
DataObject iedModel_GenericIO_MMXU1_PPV 					= { DataObjectModelType, "PPV", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*) &iedModel_GenericIO_MMXU1_totW, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA, 0 };
DataObject iedModel_GenericIO_MMXU1_PPV_phsA 				= { DataObjectModelType, "phsAB", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_PPV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_q, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsA, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_PPV_phsB 				= { DataObjectModelType, "phsBC", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)&iedModel_GenericIO_MMXU1_PPV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_q, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsB, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_GenericIO_MMXU1_PPV_phsC 				= { DataObjectModelType, "phsCA", (ModelNode*) &iedModel_GenericIO_MMXU1_A, (ModelNode*)NULL /*&iedModel_GenericIO_MMXU1_PPV_phsC*/, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_cVal, 0 };
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_q, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_cVal, NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC, (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_PPV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_PPV_phsC, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};


DataObject    iedModel_GenericIO_MMXU1_totW 			= { DataObjectModelType, "TotW", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)&iedModel_GenericIO_MMXU1_totVAr, (ModelNode*) &iedModel_GenericIO_MMXU1_totW_mag, 0 };
DataAttribute iedModel_GenericIO_MMXU1_totW_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_totW,(ModelNode*)&iedModel_GenericIO_MMXU1_totW_q, (ModelNode*) &iedModel_GenericIO_MMXU1_totW_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totW_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_totW_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totW_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_totW, (ModelNode*) &iedModel_GenericIO_MMXU1_totW_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totW_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_totW, (ModelNode*) &iedModel_GenericIO_MMXU1_totW_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totW_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_MMXU1_totW, (ModelNode*) &iedModel_GenericIO_MMXU1_totW_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totW_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_MMXU1_totW, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

DataObject    iedModel_GenericIO_MMXU1_totVAr 			= { DataObjectModelType, "TotVAr", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)&iedModel_GenericIO_MMXU1_totPF, (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_mag, 0 };
DataAttribute iedModel_GenericIO_MMXU1_totVAr_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr,(ModelNode*)&iedModel_GenericIO_MMXU1_totVAr_q, (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totVAr_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totVAr_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr, (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totVAr_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr, (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totVAr_db 		= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr, (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totVAr_zeroDb 	= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_MMXU1_totVAr, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

DataObject    iedModel_GenericIO_MMXU1_totPF 			= { DataObjectModelType, "TotPF", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)&iedModel_GenericIO_MMXU1_Hz, (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_mag, 0 };
DataAttribute iedModel_GenericIO_MMXU1_totPF_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF,(ModelNode*)&iedModel_GenericIO_MMXU1_totPF_q, (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totPF_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totPF_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF, (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totPF_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF, (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totPF_db 		= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF, (ModelNode*) &iedModel_GenericIO_MMXU1_totPF_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_totPF_zeroDb 	= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_MMXU1_totPF, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

DataObject    iedModel_GenericIO_MMXU1_Hz 				= { DataObjectModelType, "Hz", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_mag, 0 };
DataAttribute iedModel_GenericIO_MMXU1_Hz_mag 			= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz,(ModelNode*)&iedModel_GenericIO_MMXU1_Hz_q, (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_MMXU1_Hz_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_MMXU1_Hz_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz, (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_MMXU1_Hz_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz, (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_MMXU1_Hz_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz, (ModelNode*) &iedModel_GenericIO_MMXU1_Hz_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_MMXU1_Hz_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_MMXU1_Hz, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * Логический узел LN
 *
 * 5.4.18 LN: измерения Имя: PTOC
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для моделирования направленной макс.
 * токовой защиты с выдержкой вренени.
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_PTOC1 = {    LogicalNodeModelType,    "PTOC",    &iedModel_Generic_PROT,  (ModelNode*)&iedModel_GenericIO_CSWI1,    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod};

DataObject iedModel_GenericIO_PTOC1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_PTOC1,    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh,    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod_q,0};
DataAttribute iedModel_GenericIO_PTOC1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod,    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod,    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod,    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GenericIO_PTOC1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PTOC1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_PTOC1,    (ModelNode*) &iedModel_GenericIO_PTOC1_Health,    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_PTOC1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh,    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh,    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_PTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PTOC1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_PTOC1,    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PTOC1_Health_stVal,0};
DataAttribute iedModel_GenericIO_PTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_PTOC1_Health,    (ModelNode*) &iedModel_GenericIO_PTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_PTOC1_Health,    (ModelNode*) &iedModel_GenericIO_PTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_PTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PTOC1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_PTOC1,    (ModelNode*) &iedModel_GenericIO_PTOC1_Str, (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GenericIO_PTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_GenericIO_PTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_GenericIO_PTOC1,  	(ModelNode*)&iedModel_GenericIO_PTOC1_Op, (ModelNode*) &iedModel_GenericIO_PTOC1_Str_general,0};
DataAttribute iedModel_GenericIO_PTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_GenericIO_PTOC1_Str,  (ModelNode*) &iedModel_GenericIO_PTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_GenericIO_PTOC1_Str,  (ModelNode*) &iedModel_GenericIO_PTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_GenericIO_PTOC1_Str,  (ModelNode*) &iedModel_GenericIO_PTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_GenericIO_PTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_GenericIO_PTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_GenericIO_PTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PTOC1_Op_general,0};
DataAttribute iedModel_GenericIO_PTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_GenericIO_PTOC1_Op,  (ModelNode*) &iedModel_GenericIO_PTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_GenericIO_PTOC1_Op,  (ModelNode*) &iedModel_GenericIO_PTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_GenericIO_PTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел LN
 *
 * 5.6.6 LN: Регулятор переключений Имя: CSWI
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для управления всеми состояниями
 * переключений
 *
 *************************************************************************/

LogicalNode iedModel_GenericIO_CSWI1 						= {    LogicalNodeModelType,    "CSWI1",   (ModelNode*) &iedModel_Generic_PROT,   (ModelNode*)&iedModel_GenericIO_XCBR1,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod};
//Mod
DataObject iedModel_GenericIO_CSWI1_Mod 					= {    DataObjectModelType,      "Mod",    (ModelNode*) &iedModel_GenericIO_CSWI1,    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_q,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_q 				= {    DataAttributeModelType,   "q",    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_t 				= {    DataAttributeModelType,   "t",    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_stVal 			= { DataAttributeModelType,		 "stVal",    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod, (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod,   NULL,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_origin,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_CSWI1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//Beh
DataObject iedModel_GenericIO_CSWI1_Beh 					= {    DataObjectModelType,       "Beh",    (ModelNode*) &iedModel_GenericIO_CSWI1,    (ModelNode*) &iedModel_GenericIO_CSWI1_Health,    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_CSWI1_Beh_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh,    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Beh_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh,    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Beh_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_CSWI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//MmsValue iedModel_GenericIO_CSWI1_Beh_stVal_MMS 			= { DataAttributeModelType, MMS_INTEGER, 0, (Asn1PrimitiveValue*)&stVal_MMS_1};
//Asn1PrimitiveValue	stVal_MMS_1								= { 1, 1,"1"};

//Health
DataObject iedModel_GenericIO_CSWI1_Health 					= {    DataObjectModelType,       "Health",    (ModelNode*) &iedModel_GenericIO_CSWI1,    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt,    (ModelNode*) &iedModel_GenericIO_CSWI1_Health_stVal,0};
DataAttribute iedModel_GenericIO_CSWI1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_CSWI1_Health,    (ModelNode*) &iedModel_GenericIO_CSWI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_CSWI1_Health,    (ModelNode*) &iedModel_GenericIO_CSWI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_CSWI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//NamPlt
DataObject iedModel_GenericIO_CSWI1_NamPlt 					= {    DataObjectModelType,       "NamPlt",    (ModelNode*) &iedModel_GenericIO_CSWI1,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos, (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_vendor 		= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt,    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_swRev 		= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt,    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GenericIO_CSWI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_GenericIO_CSWI1_Pos 					= {    DataObjectModelType,       "Pos",    (ModelNode*) &iedModel_GenericIO_CSWI1,    (ModelNode*) NULL, (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_stVal,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};//GENERIC_BITSTRING
DataAttribute iedModel_GenericIO_CSWI1_Pos_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_ctlModel 		= {   DataAttributeModelType,     "ctlModel",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos, (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper 			= {    DataAttributeModelType,    "Oper",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos,   NULL,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_ctlVal 		= {    DataAttributeModelType,    "ctlVal",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin 		= {    DataAttributeModelType,    "origin",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin_orCat = {    DataAttributeModelType,   "orCat",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_origin,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_origin_orIdent = {    DataAttributeModelType, "orIdent",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_ctlNum 		= {    DataAttributeModelType,    "ctlNum",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_T 			= {    DataAttributeModelType,    "T",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_Test 		= {    DataAttributeModelType,    "Test",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_CSWI1_Pos_Oper_Check 		= {    DataAttributeModelType,    "Check",    (ModelNode*) &iedModel_GenericIO_CSWI1_Pos_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


/*************************************************************************
 * Логический узел LN
 *
 *  5.12.1 LN: Выключатель  Имя: XCBR
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для моделирования коммутационных устройств
 *
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_XCBR1 							= {    LogicalNodeModelType,    "XCBR",    (ModelNode*) &iedModel_Generic_PROT,  (ModelNode*)&iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod};
//Mod
DataObject iedModel_GenericIO_XCBR1_Mod 						= {    DataObjectModelType,     "Mod",     (ModelNode*) &iedModel_GenericIO_XCBR1,     			(ModelNode*) &iedModel_GenericIO_XCBR1_Beh,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_q,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_q 					= {    DataAttributeModelType,  "q",       (ModelNode*) &iedModel_GenericIO_XCBR1_Mod, 			(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_t 					= {    DataAttributeModelType,  "t",       (ModelNode*) &iedModel_GenericIO_XCBR1_Mod, 			(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_stVal 				= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GenericIO_XCBR1_Mod, 			(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_ctlModel 			= {   DataAttributeModelType,   "ctlModel",(ModelNode*) &iedModel_GenericIO_XCBR1_Mod, 			(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod,         NULL,(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_origin,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_XCBR1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GenericIO_XCBR1_Beh 						= {    DataObjectModelType,     "Beh",      (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_Health,    (ModelNode*) &iedModel_GenericIO_XCBR1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_Beh_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_Beh,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Beh_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Beh,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Beh_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Beh, NULL, NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//Health
DataObject iedModel_GenericIO_XCBR1_Health 						= {    DataObjectModelType,     "Health",   (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt,    (ModelNode*) &iedModel_GenericIO_XCBR1_Health_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_Health_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_Health,    	(ModelNode*) &iedModel_GenericIO_XCBR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Health_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Health,    	(ModelNode*) &iedModel_GenericIO_XCBR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Health_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//NamPlt
DataObject iedModel_GenericIO_XCBR1_NamPlt 						= {    DataObjectModelType,     "NamPlt",   (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_Pos, (ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_vendor 			= {    DataAttributeModelType,  "vendor",   (ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt,    	(ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_swRev 			= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt,    	(ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_NamPlt_d 				= {    DataAttributeModelType,  "d",    	(ModelNode*) &iedModel_GenericIO_XCBR1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_GenericIO_XCBR1_Pos 						= {    DataObjectModelType,     "Pos",      (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*)&iedModel_GenericIO_XCBR1_Loc, (ModelNode*) &iedModel_GenericIO_XCBR1_Pos_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_Pos_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_Pos,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Pos_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Pos,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Pos_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Pos,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Pos_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_GenericIO_XCBR1_Pos,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//Loc
DataObject iedModel_GenericIO_XCBR1_Loc 						= {    DataObjectModelType,     "Loc",      (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt, (ModelNode*) &iedModel_GenericIO_XCBR1_Loc_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_Loc_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_Loc,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Loc_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Loc_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Loc,    		(ModelNode*) &iedModel_GenericIO_XCBR1_Loc_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_Loc_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_Loc,    		(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//OpCnt
DataObject iedModel_GenericIO_XCBR1_OpCnt 						= {    DataObjectModelType,     "OpCnt",    (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap, (ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt,    	(ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt,    	(ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_OpCnt_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_OpCnt,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//CBOpCap
DataObject iedModel_GenericIO_XCBR1_CBOpCap 					= {    DataObjectModelType,     "CBOpCap",  (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn, (ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_CBOpCap_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_CBOpCap,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//BlkOpn
DataObject iedModel_GenericIO_XCBR1_BlkOpn 						= {    DataObjectModelType,     "BlkOpn",   (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls, (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn,    	(ModelNode*)&iedModel_GenericIO_XCBR1_BlkOpn_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn,    	(ModelNode*)&iedModel_GenericIO_XCBR1_BlkOpn_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn,   NULL,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orCat = {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin_orIdent= {   DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_Test 		= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkOpn_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkOpn_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//BlkCls
DataObject iedModel_GenericIO_XCBR1_BlkCls 						= {    DataObjectModelType,     "BlkCls",   (ModelNode*) &iedModel_GenericIO_XCBR1,    			(ModelNode*) NULL, (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_stVal,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls,    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls,   NULL, (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlNum,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orCat = {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_origin,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_origin_orIdent= {   DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_Test 		= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_XCBR1_BlkCls_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GenericIO_XCBR1_BlkCls_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел LN
 *
 *   5.4.2 LN: Дифференциальная защита Имя: PDIF
 *
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_PDIF1 							= { LogicalNodeModelType,   "PDIF",     (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod};
DataObject iedModel_GenericIO_PDIF1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_PDIF1,    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod_q,0};
DataAttribute iedModel_GenericIO_PDIF1_Mod_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Mod_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel",    (ModelNode*) &iedModel_GenericIO_PDIF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIF1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_PDIF1,    (ModelNode*) &iedModel_GenericIO_PDIF1_Health,    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_PDIF1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Beh_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Beh_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIF1_Health 						= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_PDIF1,    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIF1_Health_stVal,0};
DataAttribute iedModel_GenericIO_PDIF1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIF1_Health,    (ModelNode*) &iedModel_GenericIO_PDIF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Health_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIF1_Health,    (ModelNode*) &iedModel_GenericIO_PDIF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Health_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIF1_NamPlt				 		= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_PDIF1,    (ModelNode*) &iedModel_GenericIO_PDIF1_Op, (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_swRev 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_NamPlt_d 				= { DataAttributeModelType, "d",    (ModelNode*) &iedModel_GenericIO_PDIF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_GenericIO_PDIF1_Op 	 						= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_GenericIO_PDIF1,  	(ModelNode*)&iedModel_GenericIO_PDIF1_DifACIc, (ModelNode*) &iedModel_GenericIO_PDIF1_Op_general,0};
DataAttribute iedModel_GenericIO_PDIF1_Op_general 				= { DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIF1_Op,  (ModelNode*) &iedModel_GenericIO_PDIF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIF1_Op,  (ModelNode*) &iedModel_GenericIO_PDIF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIF1_DifACIc 					= { DataObjectModelType,    "DifACIc", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)&iedModel_GenericIO_PDIF1_RstA, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, 0 };
DataObject iedModel_GenericIO_PDIF1_DifACIc_phsA 				= { DataObjectModelType,    "phsA", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc, (ModelNode*)&iedModel_GenericIO_PDIF1_DifACIc_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_q, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, (ModelNode*)&iedModel_GenericIO_PDIF1_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_GenericIO_PDIF1_DifACIc_phsB 				= { DataObjectModelType,    "phsB", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc, (ModelNode*)&iedModel_GenericIO_PDIF1_DifACIc_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_q, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_GenericIO_PDIF1_DifACIc_phsC 				= { DataObjectModelType,    "phsC", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc, (ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_q, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_DifACIc_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


DataObject iedModel_GenericIO_PDIF1_RstA 						= { DataObjectModelType,    "RstA", (ModelNode*) &iedModel_GenericIO_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, 0 };
DataObject iedModel_GenericIO_PDIF1_RstA_phsA 					= { DataObjectModelType,    "phsA", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA, (ModelNode*)&iedModel_GenericIO_PDIF1_RstA_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_q, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, (ModelNode*)&iedModel_GenericIO_PDIF1_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_GenericIO_PDIF1_RstA_phsB 					= { DataObjectModelType,    "phsB", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA, (ModelNode*)&iedModel_GenericIO_PDIF1_RstA_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_q, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_GenericIO_PDIF1_RstA_phsC 					= { DataObjectModelType,    "phsC", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA, (ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_cVal, 0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_q, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_cVal, NULL, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC, (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_GenericIO_PDIF1_RstA_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * Логический узел LN
 *
 *   5.4.4 LN: Расстояние Имя: PDIS
 *
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_PDIS1 							= {    LogicalNodeModelType,   "PDIS1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_GenericIO_PDIS2,    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod};
DataObject iedModel_GenericIO_PDIS1_Mod 						= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod_q,0};
DataAttribute iedModel_GenericIO_PDIS1_Mod_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Mod_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Mod_stVal 				= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Mod_ctlModel 			= {    DataAttributeModelType, "ctlModel",    (ModelNode*) &iedModel_GenericIO_PDIS1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS1_Beh 						= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_PDIS1_Health,    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh_stVal,0};
DataAttribute iedModel_GenericIO_PDIS1_Beh_stVal 				= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Beh_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Beh_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS1_Health 						= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS1_Health_stVal,0};
DataAttribute iedModel_GenericIO_PDIS1_Health_stVal 			= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS1_Health,    (ModelNode*) &iedModel_GenericIO_PDIS1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Health_q 				= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS1_Health,    (ModelNode*) &iedModel_GenericIO_PDIS1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Health_t 				= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS1_NamPlt				 		= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_PDIS1,    (ModelNode*) &iedModel_GenericIO_PDIS1_Str, (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_vendor 			= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_swRev 			= {    DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_NamPlt_d 				= {    DataAttributeModelType, "d",    (ModelNode*) &iedModel_GenericIO_PDIS1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_GenericIO_PDIS1_Str 	 					= {    DataObjectModelType,    "Str",  (ModelNode*) &iedModel_GenericIO_PDIS1,  	(ModelNode*)&iedModel_GenericIO_PDIS1_Op, (ModelNode*) &iedModel_GenericIO_PDIS1_Str_general,0};
DataAttribute iedModel_GenericIO_PDIS1_Str_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS1_Str,  (ModelNode*) &iedModel_GenericIO_PDIS1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Str_dirGeneral 			= {    DataAttributeModelType, "dirGeneral", (ModelNode*) &iedModel_GenericIO_PDIS1_Str,  (ModelNode*) &iedModel_GenericIO_PDIS1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Str_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS1_Str,  (ModelNode*) &iedModel_GenericIO_PDIS1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Str_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_GenericIO_PDIS1_Op 	 						= {    DataObjectModelType,    "Op",  (ModelNode*) &iedModel_GenericIO_PDIS1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIS1_Op_general,0};
DataAttribute iedModel_GenericIO_PDIS1_Op_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS1_Op,  (ModelNode*) &iedModel_GenericIO_PDIS1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Op_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS1_Op,  (ModelNode*) &iedModel_GenericIO_PDIS1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS1_Op_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// DIS2
LogicalNode iedModel_GenericIO_PDIS2 							= {    LogicalNodeModelType,   "PDIS2",   (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_GenericIO_PDIS3,    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod};
DataObject iedModel_GenericIO_PDIS2_Mod 						= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_PDIS2,    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod_q,0};
DataAttribute iedModel_GenericIO_PDIS2_Mod_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Mod_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Mod_stVal 				= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Mod_ctlModel 			= {    DataAttributeModelType, "ctlModel",    (ModelNode*) &iedModel_GenericIO_PDIS2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS2_Beh 						= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_PDIS2,    (ModelNode*) &iedModel_GenericIO_PDIS2_Health,    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh_stVal,0};
DataAttribute iedModel_GenericIO_PDIS2_Beh_stVal 				= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Beh_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Beh_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS2_Health 						= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_PDIS2,    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS2_Health_stVal,0};
DataAttribute iedModel_GenericIO_PDIS2_Health_stVal 			= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS2_Health,    (ModelNode*) &iedModel_GenericIO_PDIS2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Health_q 				= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS2_Health,    (ModelNode*) &iedModel_GenericIO_PDIS2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Health_t 				= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS2_NamPlt				 		= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_PDIS2,    (ModelNode*) &iedModel_GenericIO_PDIS2_Str, (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_vendor 			= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_swRev 			= {    DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_NamPlt_d 				= {    DataAttributeModelType, "d",    (ModelNode*) &iedModel_GenericIO_PDIS2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_GenericIO_PDIS2_Str 	 					= {    DataObjectModelType,    "Str",  (ModelNode*) &iedModel_GenericIO_PDIS2,  	(ModelNode*)&iedModel_GenericIO_PDIS2_Op, (ModelNode*) &iedModel_GenericIO_PDIS2_Str_general,0};
DataAttribute iedModel_GenericIO_PDIS2_Str_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS2_Str,  (ModelNode*) &iedModel_GenericIO_PDIS2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Str_dirGeneral 			= {    DataAttributeModelType, "dirGeneral", (ModelNode*) &iedModel_GenericIO_PDIS2_Str,  (ModelNode*) &iedModel_GenericIO_PDIS2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Str_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS2_Str,  (ModelNode*) &iedModel_GenericIO_PDIS2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Str_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_GenericIO_PDIS2_Op 	 						= {    DataObjectModelType,    "Op",  (ModelNode*) &iedModel_GenericIO_PDIS2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIS2_Op_general,0};
DataAttribute iedModel_GenericIO_PDIS2_Op_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS2_Op,  (ModelNode*) &iedModel_GenericIO_PDIS2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Op_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS2_Op,  (ModelNode*) &iedModel_GenericIO_PDIS2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS2_Op_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// DIS3
LogicalNode iedModel_GenericIO_PDIS3 							= {    LogicalNodeModelType,   "PDIS3",  (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)NULL,    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod};
DataObject iedModel_GenericIO_PDIS3_Mod 						= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_GenericIO_PDIS3,    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod_q,0};
DataAttribute iedModel_GenericIO_PDIS3_Mod_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Mod_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Mod_stVal 				= { DataAttributeModelType,	   "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod,    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Mod_ctlModel 			= {   DataAttributeModelType,  "ctlModel",    (ModelNode*) &iedModel_GenericIO_PDIS3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS3_Beh 						= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GenericIO_PDIS3,    (ModelNode*) &iedModel_GenericIO_PDIS3_Health,    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh_stVal,0};
DataAttribute iedModel_GenericIO_PDIS3_Beh_stVal 				= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Beh_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh,    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Beh_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS3_Health 						= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GenericIO_PDIS3,    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS3_Health_stVal,0};
DataAttribute iedModel_GenericIO_PDIS3_Health_stVal 			= {    DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GenericIO_PDIS3_Health,    (ModelNode*) &iedModel_GenericIO_PDIS3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Health_q 				= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS3_Health,    (ModelNode*) &iedModel_GenericIO_PDIS3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Health_t 				= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GenericIO_PDIS3_NamPlt				 		= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GenericIO_PDIS3,    (ModelNode*) &iedModel_GenericIO_PDIS3_Str, (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt_vendor,0};
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_vendor 			= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_swRev 			= {    DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt,    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_NamPlt_d 				= {    DataAttributeModelType, "d",    (ModelNode*) &iedModel_GenericIO_PDIS3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_GenericIO_PDIS3_Str 	 					= {    DataObjectModelType,    "Str",  (ModelNode*) &iedModel_GenericIO_PDIS3,  	(ModelNode*)&iedModel_GenericIO_PDIS3_Op, (ModelNode*) &iedModel_GenericIO_PDIS3_Str_general,0};
DataAttribute iedModel_GenericIO_PDIS3_Str_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS3_Str,  (ModelNode*) &iedModel_GenericIO_PDIS3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Str_dirGeneral 			= {    DataAttributeModelType, "dirGeneral", (ModelNode*) &iedModel_GenericIO_PDIS3_Str,  (ModelNode*) &iedModel_GenericIO_PDIS3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Str_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS3_Str,  (ModelNode*) &iedModel_GenericIO_PDIS3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Str_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_GenericIO_PDIS3_Op 	 						= {    DataObjectModelType,    "Op",  (ModelNode*) &iedModel_GenericIO_PDIS3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_GenericIO_PDIS3_Op_general,0};
DataAttribute iedModel_GenericIO_PDIS3_Op_general 				= {    DataAttributeModelType, "general", (ModelNode*) &iedModel_GenericIO_PDIS3_Op,  (ModelNode*) &iedModel_GenericIO_PDIS3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Op_q 					= {    DataAttributeModelType, "q",    (ModelNode*) &iedModel_GenericIO_PDIS3_Op,  (ModelNode*) &iedModel_GenericIO_PDIS3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GenericIO_PDIS3_Op_t 					= {    DataAttributeModelType, "t",    (ModelNode*) &iedModel_GenericIO_PDIS3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda0 = {"MR771PROT",false,"SP40GGIO$ST$Ind1", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda1 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda1 = {"MR771PROT",false,"SP40GGIO$ST$Ind2", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda2 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda2 = {"MR771PROT",false,"SP40GGIO$ST$Ind3", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda3 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda3 = {"MR771PROT",false,"SP40GGIO$ST$Ind4", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda4 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda4 = {"MR771PROT",false,"SP40GGIO$ST$Ind5", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda5 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda5 = {"MR771PROT",false,"SP40GGIO$ST$Ind6", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda6 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda6 = {"MR771PROT",false,"SP40GGIO$ST$Ind7", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda7 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda7 = {"MR771PROT",false,"SP40GGIO$ST$Ind8", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda8 };

DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda8 = {"MR771PROT",false,"SP40GGIO$ST$Ind9", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda9 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda9 = {"MR771PROT",false,"SP40GGIO$ST$Ind10", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda10 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda10 = {"MR771PROT",false,"SP40GGIO$ST$Ind11", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda11 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda11 = {"MR771PROT",false,"SP40GGIO$ST$Ind12", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda12 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda12 = {"MR771PROT",false,"SP40GGIO$ST$Ind13", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda13 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda13 = {"MR771PROT",false,"SP40GGIO$ST$Ind14", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda14 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda14 = {"MR771PROT",false,"SP40GGIO$ST$Ind15", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda15 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda15 = {"MR771PROT",false,"SP40GGIO$ST$Ind16", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda16 };

DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda16 = {"MR771PROT",false,"SP40GGIO$ST$Ind17", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda17 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda17 = {"MR771PROT",false,"SP40GGIO$ST$Ind18", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda18 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda18 = {"MR771PROT",false,"SP40GGIO$ST$Ind19", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda19 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda19 = {"MR771PROT",false,"SP40GGIO$ST$Ind20", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda20 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda20 = {"MR771PROT",false,"SP40GGIO$ST$Ind21", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda21 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda21 = {"MR771PROT",false,"SP40GGIO$ST$Ind22", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda22 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda22 = {"MR771PROT",false,"SP40GGIO$ST$Ind23", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda23 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda23 = {"MR771PROT",false,"SP40GGIO$ST$Ind24", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda24 };

DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda24 = {"MR771PROT",false,"SP40GGIO$ST$Ind25", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda25 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda25 = {"MR771PROT",false,"SP40GGIO$ST$Ind26", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda26 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda26 = {"MR771PROT",false,"SP40GGIO$ST$Ind27", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda27 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda27 = {"MR771PROT",false,"SP40GGIO$ST$Ind28", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda28 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda28 = {"MR771PROT",false,"SP40GGIO$ST$Ind29", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda29 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda29 = {"MR771PROT",false,"SP40GGIO$ST$Ind30", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda30 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda30 = {"MR771PROT",false,"SP40GGIO$ST$Ind31", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda31 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda31 = {"MR771PROT",false,"SP40GGIO$ST$Ind32", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda32 };

DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda32 = {"MR771PROT",false,"SP40GGIO$ST$Ind33", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda33 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda33 = {"MR771PROT",false,"SP40GGIO$ST$Ind34", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda34 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda34 = {"MR771PROT",false,"SP40GGIO$ST$Ind35", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda35 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda35 = {"MR771PROT",false,"SP40GGIO$ST$Ind36", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda36 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda36 = {"MR771PROT",false,"SP40GGIO$ST$Ind37", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda37 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda37 = {"MR771PROT",false,"SP40GGIO$ST$Ind38", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda38 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda38 = {"MR771PROT",false,"SP40GGIO$ST$Ind39", -1, NULL, NULL, &iedModelds_GenericIO_LLN0_dataset_fcda39 };
DataSetEntry iedModelds_GenericIO_LLN0_dataset_fcda39 = {"MR771PROT",false,"SP40GGIO$ST$Ind40", -1, NULL, NULL, NULL};


// --------------------------------------------------------
DataSetEntry iedModelds_GenericIO_Events1_fcda0 = {"MR771PROT",false, "MMXU$MX$A$phsA",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda1};
DataSetEntry iedModelds_GenericIO_Events1_fcda1 = {"MR771PROT",false, "MMXU$MX$A$phsB",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda2};
DataSetEntry iedModelds_GenericIO_Events1_fcda2 = {"MR771PROT",false, "MMXU$MX$A$phsC",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda3};

DataSetEntry iedModelds_GenericIO_Events1_fcda3 = {"MR771PROT",false, "MMXU$MX$PhV$phsA",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda4};
DataSetEntry iedModelds_GenericIO_Events1_fcda4 = {"MR771PROT",false, "MMXU$MX$PhV$phsB",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda5};
DataSetEntry iedModelds_GenericIO_Events1_fcda5 = {"MR771PROT",false, "MMXU$MX$PhV$phsC",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda6};

DataSetEntry iedModelds_GenericIO_Events1_fcda6 = {"MR771PROT",false, "MMXU$MX$PPV$phsAB",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda7};
DataSetEntry iedModelds_GenericIO_Events1_fcda7 = {"MR771PROT",false, "MMXU$MX$PPV$phsBC",-1,NULL,NULL,&iedModelds_GenericIO_Events1_fcda8};
DataSetEntry iedModelds_GenericIO_Events1_fcda8 = {"MR771PROT",false, "MMXU$MX$PPV$phsCA",-1,NULL,NULL,NULL};

DataSetEntry iedModelds_GenericIO_MMXU_fcda1 = {"MR771PROT",false, "MMXU$MX$TotW",-1,NULL,NULL,&iedModelds_GenericIO_MMXU_fcda2};
DataSetEntry iedModelds_GenericIO_MMXU_fcda2 = {"MR771PROT",false, "MMXU$MX$TotVAr",-1,NULL,NULL,&iedModelds_GenericIO_MMXU_fcda3};
DataSetEntry iedModelds_GenericIO_MMXU_fcda3 = {"MR771PROT",false, "MMXU$MX$TotPF",-1,NULL,NULL,&iedModelds_GenericIO_MMXU_fcda4};
DataSetEntry iedModelds_GenericIO_MMXU_fcda4 = {"MR771PROT",false, "MMXU$MX$Hz",-1,NULL,NULL,NULL};


DataSet iedModelds_GenericIO_LLN0_dataset0 = {
  "MR771PROT",
  "LLN0$DS0",			//LLN0$Events
  40,						// 16
  &iedModelds_GenericIO_LLN0_dataset_fcda0,
  &iedModelds_GenericIO_LLN0_dataset1
};

DataSet iedModelds_GenericIO_LLN0_dataset1 = {
  "MR771PROT",
  "LLN0$DS1",
  9,
  &iedModelds_GenericIO_Events1_fcda0,
  &iedModelds_GenericIO_LLN0_dataset2
};

DataSet iedModelds_GenericIO_LLN0_dataset2 = {
  "MR771PROT",
  "LLN0$DS2",				//LLN0$Events
  4,						// 16
  &iedModelds_GenericIO_MMXU_fcda1,
  NULL
};


ReportControlBlock iedModel_GenericIO_LLN0_report0 = {
	&iedModel_GenericIO_LLN0,
	"URCBdiscret",
	"DS0",
	false,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS0",				// ссылка на набор данных для отчета
	0,					// ревизия конфигурации
	TRG_OPT_DATA_CHANGED,// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	50,					// BufTm буферное время мс
	0,					// IntPrd - период целостности в мс (1000)
	&iedModel_GenericIO_LLN0_report1
};

ReportControlBlock iedModel_GenericIO_LLN0_report1 = {
	&iedModel_GenericIO_LLN0,
	"URCBanalog",
	"DS1",
	false,				//false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS1",
	0,					// ревизия конфигурации
	TRG_OPT_INTEGRITY,	// условия включения
	111,				// OptFlds
	100,				// BufTm буферное время
	5000,				// IntPrd - период целостности
	&iedModel_GenericIO_LLN0_report2
};


ReportControlBlock iedModel_GenericIO_LLN0_report2 = {
	&iedModel_GenericIO_LLN0,
	"BRCB",
	"DS2",
	true,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS2",				// ссылка на набор данных для отчета
	1,					// ревизия конфигурации
	TRG_OPT_INTEGRITY,	// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	3000,				// BufTm буферное время мс
	5000,				// IntPrd - период целостности в мс (1000)
	NULL
};


static PhyComAddress iedModel_GenericIO_LLN0_gse0_address = {  4,  1,  4096,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1} };
static PhyComAddress iedModel_GenericIO_LLN0_gse1_address = {  4,  1,  4096,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x2} };


GSEControlBlock iedModel_GenericIO_LLN0_gse0 = {
	&iedModel_GenericIO_LLN0,
	"gcbDiscret",
	"discret",
	"DS0",
	2,
	false,
	&iedModel_GenericIO_LLN0_gse0_address,
	1000,
	3000,
	&iedModel_GenericIO_LLN0_gse1
};

GSEControlBlock iedModel_GenericIO_LLN0_gse1 = {
	&iedModel_GenericIO_LLN0,
	"gcbAnalog",
	"analog",
	"DS1",
	2,
	false,
	&iedModel_GenericIO_LLN0_gse1_address,
	-1,
	-1,
	NULL,
	0
};

//extern SVControlBlock iedModel_MUnn_LLN0_smv0;
//extern SettingGroupControlBlock iedModel_GenericIO_LLN0_sgcb;

SettingGroupControlBlock iedModel_GenericIO_LLN0_sgcb0 = {&iedModel_GenericIO_LLN0, 1, 2, 0, false, 0, NULL,0};


/*************************************************************************
 * DataObject_hasFCData
 *
 *************************************************************************/
//__attribute__((__section__(".eb0rodata"))) const  uint8_t NamPlt_vendor[] = "BEMN_qwertyuiopasdfghjkl;zxcvbnm,./";

static void		initializeValues()
{

USART_TRACE("\n");
USART_TRACE("initializeValues -------------------------------------------\n");


iedModel_GenericIO_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("BEMN");
iedModel_GenericIO_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("0.0");
iedModel_GenericIO_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString("IEC 61850-7-4:2003");

//iedModel_GenericIO_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("");
//iedModel_GenericIO_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("00.01");
//iedModel_GenericIO_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("00.00");
//iedModel_GenericIO_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString("00");

iedModel_GenericIO_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString("BEMN");
iedModel_GenericIO_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_GenericIO_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);					// не будет прокси

//PTOC
iedModel_GenericIO_PTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("BEMN");
//iedModel_GenericIO_PTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("MR771 v0.00");

//CSWI1
iedModel_GenericIO_CSWI1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt16(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_CSWI1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt16(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_CSWI1_Pos_stVal.mmsValue = MmsValue_newBitString(2);
//iedModel_GenericIO_CSWI1_Pos_Oper_T.mmsValue = MmsValue_newUtcTime(0);

//XCBR1
iedModel_GenericIO_XCBR1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GenericIO_XCBR1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt16(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_XCBR1_BlkOpn_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GenericIO_XCBR1_BlkCls_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GenericIO_XCBR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("PltXCBR1");

//iedModel_GenericIO_GGIO1_Ind1_stVal.mmsValue = MmsValue_newIEC61850_BOOLEAN(0);
//iedModel_GenericIO_GGIO1_Ind2_stVal.mmsValue = MmsValue_newIEC61850_BOOLEAN(0);
//iedModel_GenericIO_GGIO1_Ind3_stVal.mmsValue = MmsValue_newIEC61850_BOOLEAN(0);
//iedModel_GenericIO_GGIO1_Ind4_stVal.mmsValue = MmsValue_newIEC61850_BOOLEAN(0);

iedModel_GenericIO_GGIO2_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GenericIO_GGIO2_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO5_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO6_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO7_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GenericIO_GGIO2_SPCSO8_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);

USART_TRACE("------------------------------------------------------------\n");

}
#endif
