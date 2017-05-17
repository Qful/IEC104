/*
 * static_model.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */

#if defined (MR5_600)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR5_600.h"
#include "IEC850.h"

//IedModel iedModel;

static void initializeValues();

extern DataSet iedModelds_LD0_LLN0_dataset0;
extern DataSet iedModelds_LD0_LLN0_dataset1;
extern DataSet iedModelds_LD0_LLN0_dataset2;

extern DataSet iedModelds_LD0_LLN0_dataset3;
extern DataSet iedModelds_LD0_LLN0_dataset4;
extern DataSet iedModelds_LD0_LLN0_dataset5;
extern DataSet iedModelds_LD0_LLN0_dataset6;
extern DataSet iedModelds_LD0_LLN0_dataset7;
extern DataSet iedModelds_LD0_LLN0_dataset8;
extern DataSet iedModelds_LD0_LLN0_dataset9;
extern DataSet iedModelds_LD0_LLN0_dataset10;

extern ReportControlBlock iedModel_LD0_LLN0_report0;
extern ReportControlBlock iedModel_LD0_LLN0_report1;
extern ReportControlBlock iedModel_LD0_LLN0_report2;

extern ReportControlBlock iedModel_LD0_LLN0_report3;
extern ReportControlBlock iedModel_LD0_LLN0_report4;
extern ReportControlBlock iedModel_LD0_LLN0_report5;
extern ReportControlBlock iedModel_LD0_LLN0_report6;
extern ReportControlBlock iedModel_LD0_LLN0_report7;
extern ReportControlBlock iedModel_LD0_LLN0_report8;
extern ReportControlBlock iedModel_LD0_LLN0_report9;
extern ReportControlBlock iedModel_LD0_LLN0_report10;


extern GSEControlBlock iedModel_LD0_LLN0_gse0;
extern GSEControlBlock iedModel_LD0_LLN0_gse1;

//-----
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda0;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda1;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda2;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda3;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda4;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda5;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda6;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda7;


extern	DataSetEntry iedModelds_LD0_Events1_fcda4;
extern	DataSetEntry iedModelds_LD0_Events1_fcda5;
extern	DataSetEntry iedModelds_LD0_Events1_fcda6;
extern	DataSetEntry iedModelds_LD0_Events1_fcda7;
extern	DataSetEntry iedModelds_LD0_Events1_fcda8;
extern	DataSetEntry iedModelds_LD0_Events1_fcda9;
extern	DataSetEntry iedModelds_LD0_Events1_fcda10;


extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda11;

extern DataSetEntry iedModelds_LD0_LLN0_dataset_D4_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D4_fcda1;

extern DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda2;


// логические устройства в составе -------------------------------------iedModel_Generic_GGIO
LogicalDevice iedModel_Generic_LD0;
LogicalDevice iedModel_Generic_PROT;
LogicalDevice iedModel_Generic_CTRL;
LogicalDevice iedModel_Generic_MES;
LogicalDevice iedModel_Generic_GGIO;

// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_LD0_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_LD0_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_LD0_LLN0_Mod_q;
DataAttribute iedModel_LD0_LLN0_Mod_t;
DataAttribute iedModel_LD0_LLN0_Mod_stVal;
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;

DataObject    iedModel_LD0_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_LD0_LLN0_Beh_stVal;
DataAttribute iedModel_LD0_LLN0_Beh_q;
DataAttribute iedModel_LD0_LLN0_Beh_t;

DataObject    iedModel_LD0_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_LD0_LLN0_Health_stVal;
DataAttribute iedModel_LD0_LLN0_Health_q;
DataAttribute iedModel_LD0_LLN0_Health_t;

DataObject    iedModel_LD0_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;
DataAttribute iedModel_LD0_LLN0_NamPlt_d;
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;

DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
DataAttribute iedModel_LD0_LLN0_SGCB_q;
DataAttribute iedModel_LD0_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_PROT_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_PROT_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_PROT_LLN0_Mod_q;
DataAttribute iedModel_PROT_LLN0_Mod_t;
DataAttribute iedModel_PROT_LLN0_Mod_stVal;
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel;

DataObject    iedModel_PROT_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_PROT_LLN0_Beh_stVal;
DataAttribute iedModel_PROT_LLN0_Beh_q;
DataAttribute iedModel_PROT_LLN0_Beh_t;

DataObject    iedModel_PROT_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_PROT_LLN0_Health_stVal;
DataAttribute iedModel_PROT_LLN0_Health_q;
DataAttribute iedModel_PROT_LLN0_Health_t;

DataObject    iedModel_PROT_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor;
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev;
DataAttribute iedModel_PROT_LLN0_NamPlt_d;
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev;
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs;

DataObject    iedModel_PROT_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_PROT_LLN0_SGCB_ActSG;
DataAttribute iedModel_PROT_LLN0_SGCB_q;
DataAttribute iedModel_PROT_LLN0_SGCB_t;
// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_CTRL_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_CTRL_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_CTRL_LLN0_Mod_q;
DataAttribute iedModel_CTRL_LLN0_Mod_t;
DataAttribute iedModel_CTRL_LLN0_Mod_stVal;
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel;

DataObject    iedModel_CTRL_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_CTRL_LLN0_Beh_stVal;
DataAttribute iedModel_CTRL_LLN0_Beh_q;
DataAttribute iedModel_CTRL_LLN0_Beh_t;

DataObject    iedModel_CTRL_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_CTRL_LLN0_Health_stVal;
DataAttribute iedModel_CTRL_LLN0_Health_q;
DataAttribute iedModel_CTRL_LLN0_Health_t;

DataObject    iedModel_CTRL_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor;
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev;
DataAttribute iedModel_CTRL_LLN0_NamPlt_d;
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev;
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs;

DataObject    iedModel_CTRL_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG;
DataAttribute iedModel_CTRL_LLN0_SGCB_q;
DataAttribute iedModel_CTRL_LLN0_SGCB_t;
// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_MES_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_MES_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_MES_LLN0_Mod_q;
DataAttribute iedModel_MES_LLN0_Mod_t;
DataAttribute iedModel_MES_LLN0_Mod_stVal;
DataAttribute iedModel_MES_LLN0_Mod_ctlModel;

DataObject    iedModel_MES_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_MES_LLN0_Beh_stVal;
DataAttribute iedModel_MES_LLN0_Beh_q;
DataAttribute iedModel_MES_LLN0_Beh_t;

DataObject    iedModel_MES_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_MES_LLN0_Health_stVal;
DataAttribute iedModel_MES_LLN0_Health_q;
DataAttribute iedModel_MES_LLN0_Health_t;

DataObject    iedModel_MES_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_MES_LLN0_NamPlt_vendor;
DataAttribute iedModel_MES_LLN0_NamPlt_swRev;
DataAttribute iedModel_MES_LLN0_NamPlt_d;
DataAttribute iedModel_MES_LLN0_NamPlt_configRev;
DataAttribute iedModel_MES_LLN0_NamPlt_ldNs;

DataObject    iedModel_MES_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_MES_LLN0_SGCB_ActSG;
DataAttribute iedModel_MES_LLN0_SGCB_q;
DataAttribute iedModel_MES_LLN0_SGCB_t;
// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_GGIO_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_GGIO_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_GGIO_LLN0_Mod_q;
DataAttribute iedModel_GGIO_LLN0_Mod_t;
DataAttribute iedModel_GGIO_LLN0_Mod_stVal;
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel;

DataObject    iedModel_GGIO_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_GGIO_LLN0_Beh_stVal;
DataAttribute iedModel_GGIO_LLN0_Beh_q;
DataAttribute iedModel_GGIO_LLN0_Beh_t;

DataObject    iedModel_GGIO_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_GGIO_LLN0_Health_stVal;
DataAttribute iedModel_GGIO_LLN0_Health_q;
DataAttribute iedModel_GGIO_LLN0_Health_t;

DataObject    iedModel_GGIO_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor;
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev;
DataAttribute iedModel_GGIO_LLN0_NamPlt_d;
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev;
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs;

DataObject    iedModel_GGIO_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG;
DataAttribute iedModel_GGIO_LLN0_SGCB_q;
DataAttribute iedModel_GGIO_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_LD0_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_LD0_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor;

DataObject    iedModel_LD0_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q;
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t;

DataObject    iedModel_LD0_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal;
DataAttribute iedModel_LD0_LPHD1_Proxy_q;
DataAttribute iedModel_LD0_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_PROT_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_PROT_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor;

DataObject    iedModel_PROT_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q;
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t;

DataObject    iedModel_PROT_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal;
DataAttribute iedModel_PROT_LPHD1_Proxy_q;
DataAttribute iedModel_PROT_LPHD1_Proxy_t;
// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_CTRL_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_CTRL_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor;

DataObject    iedModel_CTRL_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q;
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t;

DataObject    iedModel_CTRL_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal;
DataAttribute iedModel_CTRL_LPHD1_Proxy_q;
DataAttribute iedModel_CTRL_LPHD1_Proxy_t;
// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_MES_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_MES_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_MES_LPHD1_PhyNam_vendor;

DataObject    iedModel_MES_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_MES_LPHD1_PhyHealth_q;
DataAttribute iedModel_MES_LPHD1_PhyHealth_t;

DataObject    iedModel_MES_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_MES_LPHD1_Proxy_stVal;
DataAttribute iedModel_MES_LPHD1_Proxy_q;
DataAttribute iedModel_MES_LPHD1_Proxy_t;
// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_GGIO_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_GGIO_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor;

DataObject    iedModel_GGIO_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q;
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t;

DataObject    iedModel_GGIO_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal;
DataAttribute iedModel_GGIO_LPHD1_Proxy_q;
DataAttribute iedModel_GGIO_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_GGIO_OUTGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

DataObject    iedModel_GGIO_OUTGGIO1_Mod;							// Mod - Режим
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t;
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel;

DataObject    iedModel_GGIO_OUTGGIO1_Beh;							// Beh - Режим работы
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t;

DataObject    iedModel_GGIO_OUTGGIO1_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t;

DataObject    iedModel_GGIO_OUTGGIO1_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;								//SPCSO Контролируемый выход статуса недублированного управления
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_Check;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;

DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
/***********************************************************************************
 *
 **********************************************************************************/

DataObject    iedModel_GGIO_OUTGGIO1_Ind1;							//Ind Индикация
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind2;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind3;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind4;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind5;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind6;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind7;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind8;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind9;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind10;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind11;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind12;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind13;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind14;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind15;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_t;

DataObject    iedModel_GGIO_OUTGGIO1_Ind16;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_t;

// ---------------------------------------------------------------------------------------------------------

LogicalNode   iedModel_GGIO_LEDGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

DataObject    iedModel_GGIO_LEDGGIO1_Mod;							// Mod - Режим
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel;

DataObject    iedModel_GGIO_LEDGGIO1_Beh;							// Beh - Режим работы
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t;

DataObject    iedModel_GGIO_LEDGGIO1_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t;

DataObject    iedModel_GGIO_LEDGGIO1_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d;

DataObject    iedModel_GGIO_LEDGGIO1_Ind1;							//Ind Индикация
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;

//SPCSO1
DataObject iedModel_GGIO_LEDGGIO1_SPCSO1;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_q;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_t;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_d;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Check;
//SPCSO2
DataObject iedModel_GGIO_LEDGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_t;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_d;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_ctlModel;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_origin;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_T;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_Test;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO2_Oper_Check;
//SPCSO3
DataObject iedModel_GGIO_LEDGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_t;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_d;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_ctlModel;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_origin;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_T;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_Test;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO3_Oper_Check;
//SPCSO4
DataObject iedModel_GGIO_LEDGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_t;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_d;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_ctlModel;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_origin;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_T;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_Test;
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO4_Oper_Check;
// ------------------------------------------------------------ SPC8GGIO
LogicalNode iedModel_GGIO_INGGIO1;

DataObject iedModel_GGIO_INGGIO1_Mod;
DataAttribute iedModel_GGIO_INGGIO1_Mod_q;
DataAttribute iedModel_GGIO_INGGIO1_Mod_t;
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Check;
//Beh
DataObject iedModel_GGIO_INGGIO1_Beh;
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Beh_q;
DataAttribute iedModel_GGIO_INGGIO1_Beh_t;
//Health
DataObject iedModel_GGIO_INGGIO1_Health;
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Health_q;
DataAttribute iedModel_GGIO_INGGIO1_Health_t;
//NamPlt
DataObject iedModel_GGIO_INGGIO1_NamPlt;
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d;

//SPCSO1
DataObject iedModel_GGIO_INGGIO1_SPCSO1;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_Check;
//SPCSO2
DataObject iedModel_GGIO_INGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_Check;
//SPCSO3
DataObject iedModel_GGIO_INGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_Check;
//SPCSO4
DataObject iedModel_GGIO_INGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_Check;
//SPCSO5
DataObject iedModel_GGIO_INGGIO1_SPCSO5;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_Check;
//SPCSO6
DataObject iedModel_GGIO_INGGIO1_SPCSO6;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_Check;
//SPCSO7
DataObject iedModel_GGIO_INGGIO1_SPCSO7;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_Check;
//SPCSO8
DataObject iedModel_GGIO_INGGIO1_SPCSO8;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_Check;

//SPCSO9
DataObject iedModel_GGIO_INGGIO1_SPCSO9;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_Check;
//SPCSO10
DataObject iedModel_GGIO_INGGIO1_SPCSO10;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_Check;
//SPCSO11
DataObject iedModel_GGIO_INGGIO1_SPCSO11;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_Check;
//SPCSO12
DataObject iedModel_GGIO_INGGIO1_SPCSO12;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_Check;
//SPCSO13
DataObject iedModel_GGIO_INGGIO1_SPCSO13;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_Check;
//SPCSO14
DataObject iedModel_GGIO_INGGIO1_SPCSO14;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_Check;
//SPCSO15
DataObject iedModel_GGIO_INGGIO1_SPCSO15;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_Check;

//SPCSO16
DataObject iedModel_GGIO_INGGIO1_SPCSO16;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_q;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_t;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_stVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_ctlModel;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlVal;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orCat;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orIdent;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlNum;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_T;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_Test;
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_Check;
//****************************************************************************
LogicalNode   iedModel_MES_MMXU1;

// Mod																// обязательные элементы -------------------------------------
DataObject    iedModel_MES_MMXU1_Mod;					// РЕЖИМ
DataAttribute iedModel_MES_MMXU1_Mod_q;
DataAttribute iedModel_MES_MMXU1_Mod_t;
DataAttribute iedModel_MES_MMXU1_Mod_stVal;
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel;

// Beh
DataObject    iedModel_MES_MMXU1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_MES_MMXU1_Beh_stVal;
DataAttribute iedModel_MES_MMXU1_Beh_q;
DataAttribute iedModel_MES_MMXU1_Beh_t;

// Health
DataObject    iedModel_MES_MMXU1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_MES_MMXU1_Health_stVal;
DataAttribute iedModel_MES_MMXU1_Health_q;
DataAttribute iedModel_MES_MMXU1_Health_t;

// NamPlt
DataObject    iedModel_MES_MMXU1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_MES_MMXU1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN MMXU1.

DataObject iedModel_MES_MMXU1_A;
DataObject iedModel_MES_MMXU1_A_phsA;
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal;
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsA_q;
DataAttribute iedModel_MES_MMXU1_A_phsA_t;
DataAttribute iedModel_MES_MMXU1_A_phsA_db;
DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_A_phsB;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsB_q;
DataAttribute iedModel_MES_MMXU1_A_phsB_t;
DataAttribute iedModel_MES_MMXU1_A_phsB_db;
DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_A_phsC;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsC_q;
DataAttribute iedModel_MES_MMXU1_A_phsC_t;
DataAttribute iedModel_MES_MMXU1_A_phsC_db;
DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb;

DataObject iedModel_MES_MMXU1_A_res;
DataAttribute iedModel_MES_MMXU1_A_res_cVal;
DataAttribute iedModel_MES_MMXU1_A_res_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_res_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_res_q;
DataAttribute iedModel_MES_MMXU1_A_res_t;
DataAttribute iedModel_MES_MMXU1_A_res_db;
DataAttribute iedModel_MES_MMXU1_A_res_zeroDb;

DataObject iedModel_MES_MMXU1_phV;
DataObject iedModel_MES_MMXU1_phV_phsA;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsA_q;
DataAttribute iedModel_MES_MMXU1_phV_phsA_t;
DataAttribute iedModel_MES_MMXU1_phV_phsA_db;
DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_phV_phsB;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsB_q;
DataAttribute iedModel_MES_MMXU1_phV_phsB_t;
DataAttribute iedModel_MES_MMXU1_phV_phsB_db;
DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_phV_phsC;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsC_q;
DataAttribute iedModel_MES_MMXU1_phV_phsC_t;
DataAttribute iedModel_MES_MMXU1_phV_phsC_db;
DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb;

DataObject iedModel_MES_MMXU1_phV_res;
DataAttribute iedModel_MES_MMXU1_phV_res_cVal;
DataAttribute iedModel_MES_MMXU1_phV_res_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_res_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_res_q;
DataAttribute iedModel_MES_MMXU1_phV_res_t;
DataAttribute iedModel_MES_MMXU1_phV_res_db;
DataAttribute iedModel_MES_MMXU1_phV_res_zeroDb;

//-
DataObject iedModel_MES_MMXU1_PPV;
DataObject iedModel_MES_MMXU1_PPV_phsA;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_PPV_phsB;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_PPV_phsC;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb;

//-
DataObject    iedModel_MES_MMXU1_totW;
DataAttribute iedModel_MES_MMXU1_totW_mag;
DataAttribute iedModel_MES_MMXU1_totW_mag_f;
DataAttribute iedModel_MES_MMXU1_totW_q;
DataAttribute iedModel_MES_MMXU1_totW_t;
DataAttribute iedModel_MES_MMXU1_totW_db;
DataAttribute iedModel_MES_MMXU1_totW_zeroDb;

DataObject    iedModel_MES_MMXU1_totVAr;
DataAttribute iedModel_MES_MMXU1_totVAr_mag;
DataAttribute iedModel_MES_MMXU1_totVAr_mag_f;
DataAttribute iedModel_MES_MMXU1_totVAr_q;
DataAttribute iedModel_MES_MMXU1_totVAr_t;
DataAttribute iedModel_MES_MMXU1_totVAr_db;
DataAttribute iedModel_MES_MMXU1_totVAr_zeroDb;

DataObject    iedModel_MES_MMXU1_totPF;
DataAttribute iedModel_MES_MMXU1_totPF_mag;
DataAttribute iedModel_MES_MMXU1_totPF_mag_f;
DataAttribute iedModel_MES_MMXU1_totPF_q;
DataAttribute iedModel_MES_MMXU1_totPF_t;
DataAttribute iedModel_MES_MMXU1_totPF_db;
DataAttribute iedModel_MES_MMXU1_totPF_zeroDb;

DataObject    iedModel_MES_MMXU1_Hz;
DataAttribute iedModel_MES_MMXU1_Hz_mag;
DataAttribute iedModel_MES_MMXU1_Hz_mag_f;
DataAttribute iedModel_MES_MMXU1_Hz_q;
DataAttribute iedModel_MES_MMXU1_Hz_t;
DataAttribute iedModel_MES_MMXU1_Hz_db;
DataAttribute iedModel_MES_MMXU1_Hz_zeroDb;
//--------------------------------------
LogicalNode iedModel_MES_MSQI1;

DataObject iedModel_MES_MSQI1_Mod;
DataAttribute iedModel_MES_MSQI1_Mod_q;
DataAttribute iedModel_MES_MSQI1_Mod_t;
DataAttribute iedModel_MES_MSQI1_Mod_stVal;
DataAttribute iedModel_MES_MSQI1_Mod_ctlModel;

DataObject iedModel_MES_MSQI1_Beh;
DataAttribute iedModel_MES_MSQI1_Beh_stVal;
DataAttribute iedModel_MES_MSQI1_Beh_q;
DataAttribute iedModel_MES_MSQI1_Beh_t;

DataObject iedModel_MES_MSQI1_Health;
DataAttribute iedModel_MES_MSQI1_Health_stVal;
DataAttribute iedModel_MES_MSQI1_Health_q;
DataAttribute iedModel_MES_MSQI1_Health_t;

DataObject iedModel_MES_MSQI1_NamPlt;
DataAttribute iedModel_MES_MSQI1_NamPlt_vendor;
DataAttribute iedModel_MES_MSQI1_NamPlt_swRev;
DataAttribute iedModel_MES_MSQI1_NamPlt_d;

// SeqA
DataObject iedModel_MES_MSQI1_SeqA;
DataObject iedModel_MES_MSQI1_SeqA_c1;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_t;

DataObject iedModel_MES_MSQI1_SeqA_c2;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_t;

DataObject iedModel_MES_MSQI1_SeqA_c3;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_t;

DataAttribute iedModel_MES_MSQI1_SeqA_SeqT;

// SeqU
DataObject iedModel_MES_MSQI1_SeqU;
DataObject iedModel_MES_MSQI1_SeqU_c1;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_t;

DataObject iedModel_MES_MSQI1_SeqU_c2;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_t;

DataObject iedModel_MES_MSQI1_SeqU_c3;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_t;

DataAttribute iedModel_MES_MSQI1_SeqU_SeqT;
//--------------------------------------
LogicalNode iedModel_MES_RFLO1;
DataObject iedModel_MES_RFLO1_Mod;
DataAttribute iedModel_MES_RFLO1_Mod_q;
DataAttribute iedModel_MES_RFLO1_Mod_t;
DataAttribute iedModel_MES_RFLO1_Mod_stVal;
DataAttribute iedModel_MES_RFLO1_Mod_ctlModel;

DataObject iedModel_MES_RFLO1_Beh;
DataAttribute iedModel_MES_RFLO1_Beh_stVal;
DataAttribute iedModel_MES_RFLO1_Beh_q;
DataAttribute iedModel_MES_RFLO1_Beh_t;

DataObject iedModel_MES_RFLO1_Health;
DataAttribute iedModel_MES_RFLO1_Health_stVal;
DataAttribute iedModel_MES_RFLO1_Health_q;
DataAttribute iedModel_MES_RFLO1_Health_t;

DataObject iedModel_MES_RFLO1_NamPlt;
DataAttribute iedModel_MES_RFLO1_NamPlt_vendor;
DataAttribute iedModel_MES_RFLO1_NamPlt_swRev;
DataAttribute iedModel_MES_RFLO1_NamPlt_d;

DataObject    iedModel_MES_RFLO1_Fltz;
DataAttribute iedModel_MES_RFLO1_Fltz_mag;
DataAttribute iedModel_MES_RFLO1_Fltz_mag_f;
DataAttribute iedModel_MES_RFLO1_Fltz_q;
DataAttribute iedModel_MES_RFLO1_Fltz_t;
DataAttribute iedModel_MES_RFLO1_Fltz_db;
DataAttribute iedModel_MES_RFLO1_Fltz_zeroDb;

DataObject    iedModel_MES_RFLO1_FltDiskm;
DataAttribute iedModel_MES_RFLO1_FltDiskm_mag;
DataAttribute iedModel_MES_RFLO1_FltDiskm_mag_f;
DataAttribute iedModel_MES_RFLO1_FltDiskm_q;
DataAttribute iedModel_MES_RFLO1_FltDiskm_t;
DataAttribute iedModel_MES_RFLO1_FltDiskm_db;
DataAttribute iedModel_MES_RFLO1_FltDiskm_zeroDb;

//****************************************************************************
// LN CSWI
// -----------------------------------------------------------------------------

LogicalNode iedModel_CTRL_GGIO1;

//SPCSO1
DataObject iedModel_CTRL_GGIO1_SPCSO1;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check;

//SPCSO2
DataObject iedModel_CTRL_GGIO1_SPCSO2;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test;
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check;
//SPCSO3
DataObject iedModel_CTRL_GGIO1_SPCSO3;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test;
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check;
//****************************************************************************

IedModel iedModel = {
    "MR5",
    &iedModel_Generic_LD0,
    &iedModelds_LD0_LLN0_dataset0,		// DataSet
    &iedModel_LD0_LLN0_report0,		// ReportControlBlock
    NULL,//&iedModel_PROT_LLN0_gse0,			// GSEControlBlock
    NULL,									// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,			// SettingGroupControlBlock
    NULL,									// lcbs
    NULL,									// log
    initializeValues
};

/*************************************************************************
 * Логические устройства LD
 *
 *************************************************************************/

LogicalDevice iedModel_Generic_LD0 = {
    LogicalDeviceModelType,
    "PO60LD0",								// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_PROT,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_LD0_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_PROT = {
    LogicalDeviceModelType,
    "PO60PROT",								// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_CTRL,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_PROT_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_CTRL = {
    LogicalDeviceModelType,
    "PO60CTRL",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_MES,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_CTRL_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_MES = {
    LogicalDeviceModelType,
    "PO60MES",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_GGIO,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_MES_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_GGIO = {
    LogicalDeviceModelType,
    "PO60GGIO",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    NULL,									// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_GGIO_LLN0			// первый LN(логический узел)
};
/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_LD0_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_LD0,	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_LD0_LLN0,	    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_LD0_LLN0,    NULL,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_LD0_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_LD0_LLN0,    NULL,  (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_LD0_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_LD0_LLN0_SGCB, (ModelNode*) &iedModel_LD0_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_LD0_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_LD0_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_LD0_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_PROT_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_PROT,	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LLN0_Mod};

DataObject iedModel_PROT_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_PROT_LLN0,	    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Mod_q,    0};
DataAttribute iedModel_PROT_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Beh_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_Health_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_PROT_LLN0,    NULL,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_PROT_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_PROT_LLN0,    NULL,  (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_PROT_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_PROT_LLN0_SGCB, (ModelNode*) &iedModel_PROT_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_PROT_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,	   (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_CTRL_LLN0,    NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_CTRL_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_CTRL_LLN0,    NULL,  (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_CTRL_LLN0_SGCB, (ModelNode*) &iedModel_CTRL_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_CTRL_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
/************************************************************************
 * MES_LLN0
 *************************************************************************/
LogicalNode iedModel_MES_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_MES,	   (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LLN0_Mod,};

DataObject iedModel_MES_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_MES_LLN0,	    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Mod_q,    0};
DataAttribute iedModel_MES_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Beh_stVal,    0};
DataAttribute iedModel_MES_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_Health_stVal,    0};
DataAttribute iedModel_MES_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_MES_LLN0,    NULL,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_MES_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_MES_LLN0,    NULL,  (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_MES_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_MES_LLN0_SGCB, (ModelNode*) &iedModel_MES_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_MES_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_MES_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_MES_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
/************************************************************************
 * GGIO_LLN0
 *************************************************************************/
LogicalNode iedModel_GGIO_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_GGIO,	 (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LLN0_Mod,};

DataObject iedModel_GGIO_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_GGIO_LLN0,	    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_q,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_Health_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_GGIO_LLN0,    NULL,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_GGIO_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_GGIO_LLN0,    NULL,  (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_GGIO_LLN0_SGCB, (ModelNode*) &iedModel_GGIO_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_GGIO_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_LD0_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,  NULL,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    NULL,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_LD0_LPHD1_Proxy, (ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_PROT_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,    NULL,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

DataObject iedModel_PROT_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_PROT_LPHD1,    NULL,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_PROT_LPHD1_Proxy, (ModelNode*) &iedModel_PROT_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };
DataAttribute iedModel_PROT_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
/*************************************************************************
 * Логический узел CTRL_LPHD1
 *************************************************************************/
LogicalNode iedModel_CTRL_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_CTRL_LPHD1_Proxy, (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
/*************************************************************************
 * Логический узел MES_LPHD1
 *************************************************************************/
LogicalNode iedModel_MES_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};

DataObject iedModel_MES_LPHD1_PhyNam = 				{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_MES_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal = 	{    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_MES_LPHD1,    NULL,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_MES_LPHD1_Proxy, (ModelNode*) &iedModel_MES_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };
DataAttribute iedModel_MES_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};
/*************************************************************************
 * Логический узел GGIO_LPHD1
 *************************************************************************/
LogicalNode iedModel_GGIO_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

DataObject iedModel_GGIO_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_GGIO_LPHD1,    NULL,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LPHD1_Proxy, (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_NO, NULL };
DataAttribute iedModel_GGIO_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,    TRG_OPT_NO,    NULL,    0};


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
LogicalNode iedModel_GGIO_OUTGGIO1 			= { LogicalNodeModelType,   "SP8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};

DataObject iedModel_GGIO_OUTGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*)&iedModel_GGIO_OUTGGIO1_Ind1 /* &iedModel_GGIO_OUTGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_GGIO_OUTGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_OUTGGIO1,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*)&iedModel_GGIO_OUTGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_OUTGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    NULL,   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * INGGIO1 	 с управлением.
 ************************************************************************/
LogicalNode iedModel_GGIO_INGGIO1 						= { LogicalNodeModelType,   	"SPC16GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod, (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod,   NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GGIO_INGGIO1_Beh 					= {    DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q 				= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t 				= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//Health
DataObject iedModel_GGIO_INGGIO1_Health 					= {    DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal 		= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q 			= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t 			= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//NamPlt
DataObject iedModel_GGIO_INGGIO1_NamPlt 					= {    DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor 		= {    DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev 		= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d 			= {    DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_INGGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GGIO_INGGIO1,     		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1,   	NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO1_Oper, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*)  &iedModel_GGIO_INGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO2_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO3_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO4 						= {    DataObjectModelType,     "SPCSO4",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO4_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO4_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO5 						= {    DataObjectModelType,     "SPCSO5",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO5_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO5_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO6 						= {    DataObjectModelType,     "SPCSO6",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO6_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO6_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO7 						= {    DataObjectModelType,     "SPCSO7",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO7_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO7_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO8 						= {    DataObjectModelType,     "SPCSO8",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO8_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO8_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO9 						= {    DataObjectModelType,     "SPCSO9",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO9_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO9_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO10 						= {    DataObjectModelType,     "SPCSO10",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO10_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO10_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO11 						= {    DataObjectModelType,     "SPCSO11",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO11_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO11_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO12 						= {    DataObjectModelType,     "SPCSO12",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO12_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO12_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO13 						= {    DataObjectModelType,     "SPCSO13",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO13_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO13_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO14 						= {    DataObjectModelType,     "SPCSO14",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO14_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO14_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_SPCSO15 						= {    DataObjectModelType,     "SPCSO15",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO15_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO15_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_INGGIO1_SPCSO16 						= {    DataObjectModelType,     "SPCSO16",     		(ModelNode*) &iedModel_GGIO_INGGIO1,     			NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_q,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16,   		NULL,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_SPCSO16_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_INGGIO1_SPCSO16_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LEDGGIO1 			= { LogicalNodeModelType,   "LEDGGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    NULL,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

DataObject iedModel_GGIO_LEDGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind1 /* &iedModel_GGIO_LEDGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_GGIO_LEDGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_LEDGGIO1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GGIO_LEDGGIO1,     		NULL,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1,   	NULL,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1_Oper, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * Логический узел LN
 *
 * 5.10.7 LN: измерения Имя: MMXU
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для
 * получения значений CT VT трансформаторов и вычисления измеряемых величин.
 *
 *************************************************************************/
LogicalNode iedModel_MES_MMXU1 = {    LogicalNodeModelType,    "MMXU1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MMXU1_Mod};

DataObject iedModel_MES_MMXU1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Mod_q,0};
DataAttribute iedModel_MES_MMXU1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_MMXU1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*) &iedModel_MES_MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_MES_MMXU1_phV 					= { DataObjectModelType, "PhV", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, 0 };
DataObject iedModel_MES_MMXU1_phV_phsA 				= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*)&iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_phsB 				= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)&iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_phsC 				= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)&iedModel_MES_MMXU1_phV_res, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_res 				= { DataObjectModelType, "res", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL /*&iedModel_MES_MMXU1_phV_res*/, (ModelNode*) &iedModel_MES_MMXU1_phV_res_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_res_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_res, (ModelNode*) &iedModel_MES_MMXU1_phV_res_q, (ModelNode*) &iedModel_MES_MMXU1_phV_res_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_res_cVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_res_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_res_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_res_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_res_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_res_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_res, (ModelNode*) &iedModel_MES_MMXU1_phV_res_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_res_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_res,  (ModelNode*) &iedModel_MES_MMXU1_phV_res_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_res_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_res, (ModelNode*) &iedModel_MES_MMXU1_phV_res_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_res_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_res, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// PPV
DataObject iedModel_MES_MMXU1_PPV 					= { DataObjectModelType, "PPV", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, 0 };
DataObject iedModel_MES_MMXU1_PPV_phsA 				= { DataObjectModelType, "phsAB", (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*)&iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_PPV_phsB 				= { DataObjectModelType, "phsBC", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)&iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_PPV_phsC 				= { DataObjectModelType, "phsCA", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL /*&iedModel_MES_MMXU1_PPV_phsC*/, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject    iedModel_MES_MMXU1_Hz 				= { DataObjectModelType, "Hz", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_Hz_mag, 0 };
DataAttribute iedModel_MES_MMXU1_Hz_mag 			= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_Hz,(ModelNode*)&iedModel_MES_MMXU1_Hz_q, (ModelNode*) &iedModel_MES_MMXU1_Hz_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_Hz_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_Hz_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_Hz, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//--------------------------------------
LogicalNode iedModel_MES_MSQI1 = {    LogicalNodeModelType,    "MSQI1",    (ModelNode*)&iedModel_Generic_MES,   NULL,    (ModelNode*) &iedModel_MES_MSQI1_Mod};

DataObject iedModel_MES_MSQI1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Mod_q,0};
DataAttribute iedModel_MES_MSQI1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MSQI1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_MSQI1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MSQI1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_MSQI1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MSQI1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*) &iedModel_MES_MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// SeqU
DataObject iedModel_MES_MSQI1_SeqU 					= { DataObjectModelType, "SeqU", (ModelNode*) &iedModel_MES_MMXU1, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, 0 };

DataObject iedModel_MES_MSQI1_SeqU_c1 				= { DataObjectModelType, "c1", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*)&iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_MES_MSQI1_SeqU_c2 				= { DataObjectModelType, "c2", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*)&iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataObject iedModel_MES_MSQI1_SeqU_c3 				= { DataObjectModelType, "c3", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*) &iedModel_MES_MSQI1_SeqU_SeqT, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};

DataAttribute iedModel_MES_MSQI1_SeqU_SeqT 		= { DataAttributeModelType, "SeqT", (ModelNode*) &iedModel_MES_MSQI1_SeqU, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};


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

// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1 							= {    LogicalNodeModelType,    "GGIO1",    (ModelNode*) &iedModel_Generic_CTRL,  NULL ,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1};

DataObject iedModel_CTRL_GGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     		(ModelNode*) &iedModel_CTRL_GGIO1,     		(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_CTRL_GGIO1,     			(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_CTRL_GGIO1,     	NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda0 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda1 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda2 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda3 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda4 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda5 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda6 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda7 = {"PO60GGIO",false,"SP8GGIO1$ST$Ind8", -1, NULL, NULL, NULL };

// --------------------------------------------------------
DataSetEntry iedModelds_LD0_Events1_fcda4 = {"PO60MES",false, "MMXU1$MX$PhV$phsA",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda5};
DataSetEntry iedModelds_LD0_Events1_fcda5 = {"PO60MES",false, "MMXU1$MX$PhV$phsB",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda6};
DataSetEntry iedModelds_LD0_Events1_fcda6 = {"PO60MES",false, "MMXU1$MX$PhV$phsC",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda7};
DataSetEntry iedModelds_LD0_Events1_fcda7 = {"PO60MES",false, "MMXU1$MX$PhV$res",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda8};
DataSetEntry iedModelds_LD0_Events1_fcda8 = {"PO60MES",false, "MMXU1$MX$PPV$phsAB",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda9};
DataSetEntry iedModelds_LD0_Events1_fcda9 = {"PO60MES",false, "MMXU1$MX$PPV$phsBC",-1,NULL,NULL,&iedModelds_LD0_Events1_fcda10};
DataSetEntry iedModelds_LD0_Events1_fcda10 = {"PO60MES",false, "MMXU1$MX$PPV$phsCA",-1,NULL,NULL,NULL};

//LED
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda0 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda1 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda2 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda3 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda4 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda5 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda6 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda7 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda8};
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda8 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind9", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda9 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind10", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda10 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind11", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda11 = {"PO60GGIO",false,"LEDGGIO1$ST$Ind12", -1, NULL, NULL, NULL };
//CTRL
DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda0 = {"PO60CTRL",false,"GGIO1$ST$SPCSO1$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D5_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda1 = {"PO60CTRL",false,"GGIO1$ST$SPCSO2$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D5_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda2 = {"PO60CTRL",false,"GGIO1$ST$SPCSO3$stVal", -1, NULL, NULL, NULL };

// -------------------------------------------------------------------------
//DataSetEntry iedModelds_LD0_MMXU_fcda1 = {"PO60MES",false, "MMXU1$MX$TotW",-1,NULL,NULL,&iedModelds_LD0_MMXU_fcda2};


DataSet iedModelds_LD0_LLN0_dataset0 = {
  "PO60LD0",
  "LLN0$DS0",			//LLN0$Events
  8,						// 16
  &iedModelds_LD0_LLN0_dataset_fcda0,
  &iedModelds_LD0_LLN0_dataset1
};

DataSet iedModelds_LD0_LLN0_dataset1 = {
  "PO60LD0",
  "LLN0$DS1",
  7,
  &iedModelds_LD0_Events1_fcda4,
  &iedModelds_LD0_LLN0_dataset2
};

DataSet iedModelds_LD0_LLN0_dataset2 = {
  "PO60LD0",
  "LLN0$DS2",				//LLN0$Events
  12,						// 16
  &iedModelds_LD0_LLN0_dataset_D3_fcda0,
  &iedModelds_LD0_LLN0_dataset3
};

DataSet iedModelds_LD0_LLN0_dataset3 = {"PO60LD0", "LLN0$DS3",  0,  NULL ,&iedModelds_LD0_LLN0_dataset4};
DataSet iedModelds_LD0_LLN0_dataset4 = {"PO60LD0", "LLN0$DS4",  0,  NULL ,&iedModelds_LD0_LLN0_dataset5};
DataSet iedModelds_LD0_LLN0_dataset5 = {"PO60LD0", "LLN0$DS5",  0,  NULL ,&iedModelds_LD0_LLN0_dataset6};
DataSet iedModelds_LD0_LLN0_dataset6 = {"PO60LD0", "LLN0$DS6",  0,  NULL ,&iedModelds_LD0_LLN0_dataset7};
DataSet iedModelds_LD0_LLN0_dataset7 = {"PO60LD0", "LLN0$DS7",  0,  NULL ,&iedModelds_LD0_LLN0_dataset8};
DataSet iedModelds_LD0_LLN0_dataset8 = {"PO60LD0", "LLN0$DS8",  0,  NULL ,&iedModelds_LD0_LLN0_dataset9};
DataSet iedModelds_LD0_LLN0_dataset9 = {"PO60LD0", "LLN0$DS9",  0,  NULL ,&iedModelds_LD0_LLN0_dataset10};
DataSet iedModelds_LD0_LLN0_dataset10 = {"PO60LD0", "LLN0$DS10", 0,  NULL ,NULL};

ReportControlBlock iedModel_LD0_LLN0_report0 = {
	&iedModel_LD0_LLN0,
	"URCB_101",
	"URCB_1",
	false,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS0",				// ссылка на набор данных для отчета
	0,					// ревизия конфигурации
	TRG_OPT_DATA_CHANGED,// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	50,					// BufTm буферное время мс
	0,					// IntPrd - период целостности в мс (1000)
	&iedModel_LD0_LLN0_report1
};

ReportControlBlock iedModel_LD0_LLN0_report1 = {
	&iedModel_LD0_LLN0,
	"URCB_201",
	"URCB_2",
	false,				//false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS1",
	0,					// ревизия конфигурации
	TRG_OPT_INTEGRITY,	// условия включения
	111,				// OptFlds
	100,				// BufTm буферное время
	5000,				// IntPrd - период целостности
	&iedModel_LD0_LLN0_report2
};


ReportControlBlock iedModel_LD0_LLN0_report2 = {
	&iedModel_LD0_LLN0,
	"BRCB_101",
	"BRCB_1",
	true,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS0",				// ссылка на набор данных для отчета
	1,					// ревизия конфигурации
	TRG_OPT_INTEGRITY,	// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	3000,				// BufTm буферное время мс
	5000,				// IntPrd - период целостности в мс (1000)
	&iedModel_LD0_LLN0_report3
};

ReportControlBlock iedModel_LD0_LLN0_report3 = { &iedModel_LD0_LLN0, "BRCB_201", "BRCB_2", true, "DS1", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report4};
ReportControlBlock iedModel_LD0_LLN0_report4 = { &iedModel_LD0_LLN0, "BRCB_301", "BRCB_3", true, "DS2", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report5};
ReportControlBlock iedModel_LD0_LLN0_report5 = { &iedModel_LD0_LLN0, "BRCB_401", "BRCB_4", true, "DS3", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report6};
ReportControlBlock iedModel_LD0_LLN0_report6 = { &iedModel_LD0_LLN0, "BRCB_501", "BRCB_5", true, "DS4", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report7};
ReportControlBlock iedModel_LD0_LLN0_report7 = { &iedModel_LD0_LLN0, "BRCB_601", "BRCB_6", true, "DS5", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report8};
ReportControlBlock iedModel_LD0_LLN0_report8 = { &iedModel_LD0_LLN0, "BRCB_701", "BRCB_7", true, "DS6", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report9};
ReportControlBlock iedModel_LD0_LLN0_report9 = { &iedModel_LD0_LLN0, "BRCB_801", "BRCB_8", true, "DS7", 1, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report10};
ReportControlBlock iedModel_LD0_LLN0_report10 = { &iedModel_LD0_LLN0, "BRCB_901", "BRCB_9", true, "DS8", 1, TRG_OPT_NO, 111, 3000, 5000, NULL};


static PhyComAddress iedModel_LD0_LLN0_gse0_address = {  4,  1,  4096,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1} };
static PhyComAddress iedModel_LD0_LLN0_gse1_address = {  4,  1,  4096,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x2} };


GSEControlBlock iedModel_LD0_LLN0_gse0 = {
	&iedModel_LD0_LLN0,
	"gcbDiscret",
	"discret",
	"DS0",
	2,
	false,
	&iedModel_LD0_LLN0_gse0_address,
	1000,
	3000,
	&iedModel_LD0_LLN0_gse1
};

GSEControlBlock iedModel_LD0_LLN0_gse1 = {
	&iedModel_LD0_LLN0,
	"gcbAnalog",
	"analog",
	"DS1",
	2,
	false,
	&iedModel_LD0_LLN0_gse1_address,
	-1,
	-1,
	NULL,
	0
};

//extern SVControlBlock iedModel_MUnn_LLN0_smv0;
//extern SettingGroupControlBlock iedModel_PROT_LLN0_sgcb;
//
SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0 = {
	&iedModel_LD0_LLN0,		// родитель
	1,						// активная группа настроек
	2,						// число групп настроек
	0,						// editSG
	false,					// cnfEdit
	0,						// timestamp
	0,						// resvTms
	NULL					// следующий в списке
};


/*************************************************************************
 * DataObject_hasFCData
 *
 *************************************************************************/
//__attribute__((__section__(".eb0rodata"))) const  uint8_t NamPlt_vendor[] = "BEMN_qwertyuiopasdfghjkl;zxcvbnm,./";

static void		initializeValues()
{

USART_TRACE("\n");
USART_TRACE("initializeValues -------------------------------------------\n");

uint64_t currentTime = Hal_getTimeInMs();

iedModel_LD0_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);

iedModel_LD0_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_LD0_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
iedModel_LD0_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);

iedModel_PROT_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);

iedModel_PROT_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_PROT_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);					// не будет прокси

//INGGIO1
iedModel_GGIO_INGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO5_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO6_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO7_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO8_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO9_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO10_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO11_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO12_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO13_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO14_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO15_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_SPCSO16_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);

iedModel_CTRL_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the alarm log");//Сброс флага новой записи в журнале аварий

//LEDGGIO1
iedModel_GGIO_LEDGGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_GGIO_LEDGGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Сброс индикации");
iedModel_GGIO_LEDGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_GGIO_LEDGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_GGIO_LEDGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_GGIO_LEDGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LEDGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Mod_t, currentTime);
IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Beh_t, currentTime);
IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GGIO_LEDGGIO1_Health_t, currentTime);
IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Mod_q,0);
IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Beh_q,0);
IedServer_updateQuality(iedServer,IEDMODEL_GGIO_LEDGGIO1_Health_q,0);

//MSQI1
IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_Mod_t, currentTime);
IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MSQI1_Beh_t, currentTime);
iedModel_MES_MSQI1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_MES_MSQI1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Mod_q,0);
IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Mod_q,0);

iedModel_MES_MSQI1_SeqU_SeqT.mmsValue = MmsValue_newIntegerFromInt8(0);

iedModel_MES_MSQI1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_MSQI1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//MMXU1
iedModel_MES_MMXU1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_MMXU1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Mod_q,0);
IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Mod_t, currentTime);

iedModel_MES_MMXU1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Beh_q,0);
IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Beh_t, currentTime);

iedModel_MES_MMXU1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Health_q,0);
IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Health_t, currentTime);


iedModel_LD0_LLN0_sgcb0.timestamp = currentTime;

USART_TRACE("------------------------------------------------------------\n");

}

#endif
