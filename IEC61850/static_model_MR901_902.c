/*
 * static_model_MR901_902.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */

#if defined (MR901) || defined (MR902)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR901_902.h"
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

//extern SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0;

//-----
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda0;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda1;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda2;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda3;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda4;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda5;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda6;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda7;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda8;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda9;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda10;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda11;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda12;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda13;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda14;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda15;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda16;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda17;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda18;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda19;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda20;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda21;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda22;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda23;
//extern	DataSetEntry iedModelds_LD0_LLN0_dataset_fcda24;


extern	DataSetEntry iedModelds_LD0_Events1_fcda0;
extern	DataSetEntry iedModelds_LD0_Events1_fcda1;
extern	DataSetEntry iedModelds_LD0_Events1_fcda2;
extern	DataSetEntry iedModelds_LD0_Events1_fcda3;
extern	DataSetEntry iedModelds_LD0_Events1_fcda4;
extern	DataSetEntry iedModelds_LD0_Events1_fcda5;
extern	DataSetEntry iedModelds_LD0_Events1_fcda6;
extern	DataSetEntry iedModelds_LD0_Events1_fcda7;
extern	DataSetEntry iedModelds_LD0_Events1_fcda8;
extern	DataSetEntry iedModelds_LD0_Events1_fcda9;
extern	DataSetEntry iedModelds_LD0_Events1_fcda10;


extern DataSetEntry iedModelds_LD0_MMXU1_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda5;

extern DataSetEntry iedModelds_LD0_MMXU2_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU2_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU2_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU2_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU2_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU2_fcda5;

extern DataSetEntry iedModelds_LD0_MMXU3_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU3_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU3_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU3_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU3_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU3_fcda5;

extern DataSetEntry iedModelds_LD0_MMXU4_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda5;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda6;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda7;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda8;

extern DataSetEntry iedModelds_LD0_MMXU5_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda5;


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
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda15;

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

//SPCSO1
DataObject iedModel_GGIO_OUTGGIO1_SPCSO1;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
//SPCSO2
DataObject iedModel_GGIO_OUTGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
//SPCSO3
DataObject iedModel_GGIO_OUTGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
//SPCSO4
DataObject iedModel_GGIO_OUTGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
//SPCSO5
DataObject iedModel_GGIO_OUTGGIO1_SPCSO5;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
//SPCSO6
DataObject iedModel_GGIO_OUTGGIO1_SPCSO6;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
//SPCSO7
DataObject iedModel_GGIO_OUTGGIO1_SPCSO7;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
//SPCSO8
DataObject iedModel_GGIO_OUTGGIO1_SPCSO8;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;

//SPCSO9
DataObject iedModel_GGIO_OUTGGIO1_SPCSO9;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;

//SPCSO10
DataObject iedModel_GGIO_OUTGGIO1_SPCSO10;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;

//SPCSO11
DataObject iedModel_GGIO_OUTGGIO1_SPCSO11;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;

//SPCSO12
DataObject iedModel_GGIO_OUTGGIO1_SPCSO12;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;

//SPCSO13
DataObject iedModel_GGIO_OUTGGIO1_SPCSO13;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;

//SPCSO14
DataObject iedModel_GGIO_OUTGGIO1_SPCSO14;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;

//SPCSO15
DataObject iedModel_GGIO_OUTGGIO1_SPCSO15;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;

//SPCSO16
DataObject iedModel_GGIO_OUTGGIO1_SPCSO16;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal;

//SPCSO17
DataObject iedModel_GGIO_OUTGGIO1_SPCSO17;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal;

//SPCSO18
DataObject iedModel_GGIO_OUTGGIO1_SPCSO18;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal;

//SPCSO19
DataObject iedModel_GGIO_OUTGGIO1_SPCSO19;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_stVal;

//SPCSO20
DataObject iedModel_GGIO_OUTGGIO1_SPCSO20;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_stVal;

//SPCSO21
DataObject iedModel_GGIO_OUTGGIO1_SPCSO21;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_stVal;

//SPCSO22
DataObject iedModel_GGIO_OUTGGIO1_SPCSO22;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_stVal;

//SPCSO23
DataObject iedModel_GGIO_OUTGGIO1_SPCSO23;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_stVal;

//SPCSO24
DataObject iedModel_GGIO_OUTGGIO1_SPCSO24;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_stVal;

//SPCSO25
DataObject iedModel_GGIO_OUTGGIO1_SPCSO25;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_stVal;

//SPCSO26
DataObject iedModel_GGIO_OUTGGIO1_SPCSO26;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_stVal;

//SPCSO27
DataObject iedModel_GGIO_OUTGGIO1_SPCSO27;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_stVal;

//SPCSO28
DataObject iedModel_GGIO_OUTGGIO1_SPCSO28;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_stVal;

//SPCSO29
DataObject iedModel_GGIO_OUTGGIO1_SPCSO29;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_stVal;

//SPCSO30
DataObject iedModel_GGIO_OUTGGIO1_SPCSO30;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_stVal;

//SPCSO31
DataObject iedModel_GGIO_OUTGGIO1_SPCSO31;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_stVal;

//SPCSO32
DataObject iedModel_GGIO_OUTGGIO1_SPCSO32;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_stVal;

//SPCSO33
DataObject iedModel_GGIO_OUTGGIO1_SPCSO33;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_stVal;

//SPCSO34
DataObject iedModel_GGIO_OUTGGIO1_SPCSO34;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_stVal;
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

DataObject    iedModel_GGIO_LEDGGIO1_Ind13;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind14;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind15;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind16;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t;

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
DataObject    iedModel_GGIO_INGGIO1_Ind1;							//Ind Индикация
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t;

DataObject    iedModel_GGIO_INGGIO1_Ind2;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t;

DataObject    iedModel_GGIO_INGGIO1_Ind3;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t;

DataObject    iedModel_GGIO_INGGIO1_Ind4;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t;

DataObject    iedModel_GGIO_INGGIO1_Ind5;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t;

DataObject    iedModel_GGIO_INGGIO1_Ind6;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t;

DataObject    iedModel_GGIO_INGGIO1_Ind7;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t;

DataObject    iedModel_GGIO_INGGIO1_Ind8;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t;

DataObject    iedModel_GGIO_INGGIO1_Ind9;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t;

DataObject    iedModel_GGIO_INGGIO1_Ind10;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t;

DataObject    iedModel_GGIO_INGGIO1_Ind11;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t;

DataObject    iedModel_GGIO_INGGIO1_Ind12;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t;

DataObject    iedModel_GGIO_INGGIO1_Ind13;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t;

DataObject    iedModel_GGIO_INGGIO1_Ind14;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t;

DataObject    iedModel_GGIO_INGGIO1_Ind15;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t;

DataObject    iedModel_GGIO_INGGIO1_Ind16;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t;

DataObject    iedModel_GGIO_INGGIO1_Ind17;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_t;

DataObject    iedModel_GGIO_INGGIO1_Ind18;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_t;

DataObject    iedModel_GGIO_INGGIO1_Ind19;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_t;

DataObject    iedModel_GGIO_INGGIO1_Ind20;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_t;

DataObject    iedModel_GGIO_INGGIO1_Ind21;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_t;

DataObject    iedModel_GGIO_INGGIO1_Ind22;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_t;

DataObject    iedModel_GGIO_INGGIO1_Ind23;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_t;

DataObject    iedModel_GGIO_INGGIO1_Ind24;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_t;

DataObject    iedModel_GGIO_INGGIO1_Ind25;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_t;

DataObject    iedModel_GGIO_INGGIO1_Ind26;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_t;

DataObject    iedModel_GGIO_INGGIO1_Ind27;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_t;

DataObject    iedModel_GGIO_INGGIO1_Ind28;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_t;

DataObject    iedModel_GGIO_INGGIO1_Ind29;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_t;

DataObject    iedModel_GGIO_INGGIO1_Ind30;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_t;

DataObject    iedModel_GGIO_INGGIO1_Ind31;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_t;

DataObject    iedModel_GGIO_INGGIO1_Ind32;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_t;

DataObject    iedModel_GGIO_INGGIO1_Ind33;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_t;

DataObject    iedModel_GGIO_INGGIO1_Ind34;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_t;

DataObject    iedModel_GGIO_INGGIO1_Ind35;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_t;

DataObject    iedModel_GGIO_INGGIO1_Ind36;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_t;

DataObject    iedModel_GGIO_INGGIO1_Ind37;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_t;

DataObject    iedModel_GGIO_INGGIO1_Ind38;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_t;

DataObject    iedModel_GGIO_INGGIO1_Ind39;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_t;

DataObject    iedModel_GGIO_INGGIO1_Ind40;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_t;


//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_SSLGGIO1;

DataObject iedModel_GGIO_SSLGGIO1_Mod;
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t;
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel;

DataObject iedModel_GGIO_SSLGGIO1_Beh;
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t;

DataObject iedModel_GGIO_SSLGGIO1_Health;
DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Health_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Health_t;

DataObject iedModel_GGIO_SSLGGIO1_NamPlt;

DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d;

DataObject iedModel_GGIO_SSLGGIO1_Ind1;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t;


DataObject iedModel_GGIO_SSLGGIO1_Ind2;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind3;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind4;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind5;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind6;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind7;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind8;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind9;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind10;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind11;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind12;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind13;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind14;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind15;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind16;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t;


DataObject iedModel_GGIO_SSLGGIO1_Ind17;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind18;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind19;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind20;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind21;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind22;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind23;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind24;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind25;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind26;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind27;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind28;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind29;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind30;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind31;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind32;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t;
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_VLSGGIO1;

DataObject iedModel_GGIO_VLSGGIO1_Mod;
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t;
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel;

DataObject iedModel_GGIO_VLSGGIO1_Beh;
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t;

DataObject iedModel_GGIO_VLSGGIO1_Health;
DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Health_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Health_t;

DataObject iedModel_GGIO_VLSGGIO1_NamPlt;

DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d;

DataObject iedModel_GGIO_VLSGGIO1_Ind1;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t;


DataObject iedModel_GGIO_VLSGGIO1_Ind2;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind3;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind4;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind5;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind6;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind7;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind8;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind9;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind10;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind11;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind12;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind13;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind14;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind15;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind16;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t;

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LSGGIO1;

DataObject iedModel_GGIO_LSGGIO1_Mod;
DataAttribute iedModel_GGIO_LSGGIO1_Mod_q;
DataAttribute iedModel_GGIO_LSGGIO1_Mod_t;
DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel;

DataObject iedModel_GGIO_LSGGIO1_Beh;
DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Beh_q;
DataAttribute iedModel_GGIO_LSGGIO1_Beh_t;

DataObject iedModel_GGIO_LSGGIO1_Health;
DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Health_q;
DataAttribute iedModel_GGIO_LSGGIO1_Health_t;

DataObject iedModel_GGIO_LSGGIO1_NamPlt;

DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor;
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev;
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d;

DataObject iedModel_GGIO_LSGGIO1_Ind1;
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t;


DataObject iedModel_GGIO_LSGGIO1_Ind2;
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t;

DataObject iedModel_GGIO_LSGGIO1_Ind3;
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t;

DataObject iedModel_GGIO_LSGGIO1_Ind4;
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t;

DataObject iedModel_GGIO_LSGGIO1_Ind5;
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t;

DataObject iedModel_GGIO_LSGGIO1_Ind6;
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t;

DataObject iedModel_GGIO_LSGGIO1_Ind7;
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t;

DataObject iedModel_GGIO_LSGGIO1_Ind8;
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t;

DataObject iedModel_GGIO_LSGGIO1_Ind9;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t;

DataObject iedModel_GGIO_LSGGIO1_Ind10;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t;

DataObject iedModel_GGIO_LSGGIO1_Ind11;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t;

DataObject iedModel_GGIO_LSGGIO1_Ind12;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t;

DataObject iedModel_GGIO_LSGGIO1_Ind13;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t;

DataObject iedModel_GGIO_LSGGIO1_Ind14;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t;

DataObject iedModel_GGIO_LSGGIO1_Ind15;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t;

DataObject iedModel_GGIO_LSGGIO1_Ind16;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t;
//****************************************************************************

#if defined (MR901)
// -----------------------------------------------------------------------------
// LN MMXN1
// -----------------------------------------------------------------------------
LogicalNode   iedModel_MES_MMXN1;
DataObject    iedModel_MES_MMXN1_Mod;
DataAttribute iedModel_MES_MMXN1_Mod_q;
DataAttribute iedModel_MES_MMXN1_Mod_t;
DataAttribute iedModel_MES_MMXN1_Mod_stVal;
DataAttribute iedModel_MES_MMXN1_Mod_ctlModel;
DataObject    iedModel_MES_MMXN1_Beh;
DataAttribute iedModel_MES_MMXN1_Beh_stVal;
DataAttribute iedModel_MES_MMXN1_Beh_q;
DataAttribute iedModel_MES_MMXN1_Beh_t;
DataObject    iedModel_MES_MMXN1_Health;
DataAttribute iedModel_MES_MMXN1_Health_stVal;
DataAttribute iedModel_MES_MMXN1_Health_q;
DataAttribute iedModel_MES_MMXN1_Health_t;
DataObject    iedModel_MES_MMXN1_NamPlt;
DataAttribute iedModel_MES_MMXN1_NamPlt_vendor;
DataAttribute iedModel_MES_MMXN1_NamPlt_swRev;
DataAttribute iedModel_MES_MMXN1_NamPlt_d;

// Amp1
DataObject    iedModel_MES_MMXN1_Amp1;
DataAttribute iedModel_MES_MMXN1_Amp1_mag;
DataAttribute iedModel_MES_MMXN1_Amp1_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp1_q;
DataAttribute iedModel_MES_MMXN1_Amp1_t;
DataAttribute iedModel_MES_MMXN1_Amp1_db;
DataAttribute iedModel_MES_MMXN1_Amp1_zeroDb;
// Amp2
DataObject    iedModel_MES_MMXN1_Amp2;
DataAttribute iedModel_MES_MMXN1_Amp2_mag;
DataAttribute iedModel_MES_MMXN1_Amp2_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp2_q;
DataAttribute iedModel_MES_MMXN1_Amp2_t;
DataAttribute iedModel_MES_MMXN1_Amp2_db;
DataAttribute iedModel_MES_MMXN1_Amp2_zeroDb;
// Amp3
DataObject    iedModel_MES_MMXN1_Amp3;
DataAttribute iedModel_MES_MMXN1_Amp3_mag;
DataAttribute iedModel_MES_MMXN1_Amp3_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp3_q;
DataAttribute iedModel_MES_MMXN1_Amp3_t;
DataAttribute iedModel_MES_MMXN1_Amp3_db;
DataAttribute iedModel_MES_MMXN1_Amp3_zeroDb;
// Amp4
DataObject    iedModel_MES_MMXN1_Amp4;
DataAttribute iedModel_MES_MMXN1_Amp4_mag;
DataAttribute iedModel_MES_MMXN1_Amp4_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp4_q;
DataAttribute iedModel_MES_MMXN1_Amp4_t;
DataAttribute iedModel_MES_MMXN1_Amp4_db;
DataAttribute iedModel_MES_MMXN1_Amp4_zeroDb;
// Amp5
DataObject    iedModel_MES_MMXN1_Amp5;
DataAttribute iedModel_MES_MMXN1_Amp5_mag;
DataAttribute iedModel_MES_MMXN1_Amp5_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp5_q;
DataAttribute iedModel_MES_MMXN1_Amp5_t;
DataAttribute iedModel_MES_MMXN1_Amp5_db;
DataAttribute iedModel_MES_MMXN1_Amp5_zeroDb;
// Amp6
DataObject    iedModel_MES_MMXN1_Amp6;
DataAttribute iedModel_MES_MMXN1_Amp6_mag;
DataAttribute iedModel_MES_MMXN1_Amp6_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp6_q;
DataAttribute iedModel_MES_MMXN1_Amp6_t;
DataAttribute iedModel_MES_MMXN1_Amp6_db;
DataAttribute iedModel_MES_MMXN1_Amp6_zeroDb;
// Amp7
DataObject    iedModel_MES_MMXN1_Amp7;
DataAttribute iedModel_MES_MMXN1_Amp7_mag;
DataAttribute iedModel_MES_MMXN1_Amp7_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp7_q;
DataAttribute iedModel_MES_MMXN1_Amp7_t;
DataAttribute iedModel_MES_MMXN1_Amp7_db;
DataAttribute iedModel_MES_MMXN1_Amp7_zeroDb;
// Amp8
DataObject    iedModel_MES_MMXN1_Amp8;
DataAttribute iedModel_MES_MMXN1_Amp8_mag;
DataAttribute iedModel_MES_MMXN1_Amp8_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp8_q;
DataAttribute iedModel_MES_MMXN1_Amp8_t;
DataAttribute iedModel_MES_MMXN1_Amp8_db;
DataAttribute iedModel_MES_MMXN1_Amp8_zeroDb;
// Amp9
DataObject    iedModel_MES_MMXN1_Amp9;
DataAttribute iedModel_MES_MMXN1_Amp9_mag;
DataAttribute iedModel_MES_MMXN1_Amp9_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp9_q;
DataAttribute iedModel_MES_MMXN1_Amp9_t;
DataAttribute iedModel_MES_MMXN1_Amp9_db;
DataAttribute iedModel_MES_MMXN1_Amp9_zeroDb;
// Amp10
DataObject    iedModel_MES_MMXN1_Amp10;
DataAttribute iedModel_MES_MMXN1_Amp10_mag;
DataAttribute iedModel_MES_MMXN1_Amp10_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp10_q;
DataAttribute iedModel_MES_MMXN1_Amp10_t;
DataAttribute iedModel_MES_MMXN1_Amp10_db;
DataAttribute iedModel_MES_MMXN1_Amp10_zeroDb;
// Amp11
DataObject    iedModel_MES_MMXN1_Amp11;
DataAttribute iedModel_MES_MMXN1_Amp11_mag;
DataAttribute iedModel_MES_MMXN1_Amp11_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp11_q;
DataAttribute iedModel_MES_MMXN1_Amp11_t;
DataAttribute iedModel_MES_MMXN1_Amp11_db;
DataAttribute iedModel_MES_MMXN1_Amp11_zeroDb;
// Amp12
DataObject    iedModel_MES_MMXN1_Amp12;
DataAttribute iedModel_MES_MMXN1_Amp12_mag;
DataAttribute iedModel_MES_MMXN1_Amp12_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp12_q;
DataAttribute iedModel_MES_MMXN1_Amp12_t;
DataAttribute iedModel_MES_MMXN1_Amp12_db;
DataAttribute iedModel_MES_MMXN1_Amp12_zeroDb;
// Amp13
DataObject    iedModel_MES_MMXN1_Amp13;
DataAttribute iedModel_MES_MMXN1_Amp13_mag;
DataAttribute iedModel_MES_MMXN1_Amp13_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp13_q;
DataAttribute iedModel_MES_MMXN1_Amp13_t;
DataAttribute iedModel_MES_MMXN1_Amp13_db;
DataAttribute iedModel_MES_MMXN1_Amp13_zeroDb;
// Amp14
DataObject    iedModel_MES_MMXN1_Amp14;
DataAttribute iedModel_MES_MMXN1_Amp14_mag;
DataAttribute iedModel_MES_MMXN1_Amp14_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp14_q;
DataAttribute iedModel_MES_MMXN1_Amp14_t;
DataAttribute iedModel_MES_MMXN1_Amp14_db;
DataAttribute iedModel_MES_MMXN1_Amp14_zeroDb;
// Amp15
DataObject    iedModel_MES_MMXN1_Amp15;
DataAttribute iedModel_MES_MMXN1_Amp15_mag;
DataAttribute iedModel_MES_MMXN1_Amp15_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp15_q;
DataAttribute iedModel_MES_MMXN1_Amp15_t;
DataAttribute iedModel_MES_MMXN1_Amp15_db;
DataAttribute iedModel_MES_MMXN1_Amp15_zeroDb;
// Amp16
DataObject    iedModel_MES_MMXN1_Amp16;
DataAttribute iedModel_MES_MMXN1_Amp16_mag;
DataAttribute iedModel_MES_MMXN1_Amp16_mag_f;
DataAttribute iedModel_MES_MMXN1_Amp16_q;
DataAttribute iedModel_MES_MMXN1_Amp16_t;
DataAttribute iedModel_MES_MMXN1_Amp16_db;
DataAttribute iedModel_MES_MMXN1_Amp16_zeroDb;
#endif

#if defined (MR902)
// -----------------------------------------------------------------------------
// LN MMXU1
// -----------------------------------------------------------------------------
LogicalNode   iedModel_MES_MMXU1;
DataObject    iedModel_MES_MMXU1_Mod;
DataAttribute iedModel_MES_MMXU1_Mod_q;
DataAttribute iedModel_MES_MMXU1_Mod_t;
DataAttribute iedModel_MES_MMXU1_Mod_stVal;
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel;
DataObject    iedModel_MES_MMXU1_Beh;
DataAttribute iedModel_MES_MMXU1_Beh_stVal;
DataAttribute iedModel_MES_MMXU1_Beh_q;
DataAttribute iedModel_MES_MMXU1_Beh_t;
DataObject    iedModel_MES_MMXU1_Health;
DataAttribute iedModel_MES_MMXU1_Health_stVal;
DataAttribute iedModel_MES_MMXU1_Health_q;
DataAttribute iedModel_MES_MMXU1_Health_t;
DataObject    iedModel_MES_MMXU1_NamPlt;
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor;
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev;
DataAttribute iedModel_MES_MMXU1_NamPlt_d;

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

// -----------------------------------------------------------------------------
// LN MMXU2
// -----------------------------------------------------------------------------
LogicalNode   iedModel_MES_MMXU2;
DataObject    iedModel_MES_MMXU2_Mod;
DataAttribute iedModel_MES_MMXU2_Mod_q;
DataAttribute iedModel_MES_MMXU2_Mod_t;
DataAttribute iedModel_MES_MMXU2_Mod_stVal;
DataAttribute iedModel_MES_MMXU2_Mod_ctlModel;
DataObject    iedModel_MES_MMXU2_Beh;
DataAttribute iedModel_MES_MMXU2_Beh_stVal;
DataAttribute iedModel_MES_MMXU2_Beh_q;
DataAttribute iedModel_MES_MMXU2_Beh_t;
DataObject    iedModel_MES_MMXU2_Health;
DataAttribute iedModel_MES_MMXU2_Health_stVal;
DataAttribute iedModel_MES_MMXU2_Health_q;
DataAttribute iedModel_MES_MMXU2_Health_t;
DataObject    iedModel_MES_MMXU2_NamPlt;
DataAttribute iedModel_MES_MMXU2_NamPlt_vendor;
DataAttribute iedModel_MES_MMXU2_NamPlt_swRev;
DataAttribute iedModel_MES_MMXU2_NamPlt_d;

DataObject iedModel_MES_MMXU2_A;
DataObject iedModel_MES_MMXU2_A_phsA;
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal;
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU2_A_phsA_q;
DataAttribute iedModel_MES_MMXU2_A_phsA_t;
DataAttribute iedModel_MES_MMXU2_A_phsA_db;
DataAttribute iedModel_MES_MMXU2_A_phsA_zeroDb;
DataObject iedModel_MES_MMXU2_A_phsB;
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal;
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU2_A_phsB_q;
DataAttribute iedModel_MES_MMXU2_A_phsB_t;
DataAttribute iedModel_MES_MMXU2_A_phsB_db;
DataAttribute iedModel_MES_MMXU2_A_phsB_zeroDb;
DataObject iedModel_MES_MMXU2_A_phsC;
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal;
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU2_A_phsC_q;
DataAttribute iedModel_MES_MMXU2_A_phsC_t;
DataAttribute iedModel_MES_MMXU2_A_phsC_db;
DataAttribute iedModel_MES_MMXU2_A_phsC_zeroDb;

// -----------------------------------------------------------------------------
// LN MMXU3
// -----------------------------------------------------------------------------
LogicalNode   iedModel_MES_MMXU3;
DataObject    iedModel_MES_MMXU3_Mod;
DataAttribute iedModel_MES_MMXU3_Mod_q;
DataAttribute iedModel_MES_MMXU3_Mod_t;
DataAttribute iedModel_MES_MMXU3_Mod_stVal;
DataAttribute iedModel_MES_MMXU3_Mod_ctlModel;
DataObject    iedModel_MES_MMXU3_Beh;
DataAttribute iedModel_MES_MMXU3_Beh_stVal;
DataAttribute iedModel_MES_MMXU3_Beh_q;
DataAttribute iedModel_MES_MMXU3_Beh_t;
DataObject    iedModel_MES_MMXU3_Health;
DataAttribute iedModel_MES_MMXU3_Health_stVal;
DataAttribute iedModel_MES_MMXU3_Health_q;
DataAttribute iedModel_MES_MMXU3_Health_t;
DataObject    iedModel_MES_MMXU3_NamPlt;
DataAttribute iedModel_MES_MMXU3_NamPlt_vendor;
DataAttribute iedModel_MES_MMXU3_NamPlt_swRev;
DataAttribute iedModel_MES_MMXU3_NamPlt_d;


DataObject iedModel_MES_MMXU3_A_In;
DataAttribute iedModel_MES_MMXU3_A_In_cVal;
DataAttribute iedModel_MES_MMXU3_A_In_cVal_mag;
DataAttribute iedModel_MES_MMXU3_A_In_cVal_mag_f;
DataAttribute iedModel_MES_MMXU3_A_In_q;
DataAttribute iedModel_MES_MMXU3_A_In_t;
DataAttribute iedModel_MES_MMXU3_A_In_db;
DataAttribute iedModel_MES_MMXU3_A_In_zeroDb;


#endif

//****************************************************************************
// LN iPTOC1
LogicalNode   iedModel_PROT_IPTOC1;

DataObject    iedModel_PROT_IPTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC1_Mod_q;
DataAttribute iedModel_PROT_IPTOC1_Mod_t;
DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;

DataObject    iedModel_PROT_IPTOC1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC1_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC1_Beh_q;
DataAttribute iedModel_PROT_IPTOC1_Beh_t;

DataObject    iedModel_PROT_IPTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC1_Health_stVal;
DataAttribute iedModel_PROT_IPTOC1_Health_q;
DataAttribute iedModel_PROT_IPTOC1_Health_t;

DataObject    iedModel_PROT_IPTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC1_Str;
DataAttribute iedModel_PROT_IPTOC1_Str_general;
DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC1_Str_q;
DataAttribute iedModel_PROT_IPTOC1_Str_t;

DataObject    iedModel_PROT_IPTOC1_Op;
DataAttribute iedModel_PROT_IPTOC1_Op_general;
DataAttribute iedModel_PROT_IPTOC1_Op_q;
DataAttribute iedModel_PROT_IPTOC1_Op_t;

// LN iPTOC1
LogicalNode   iedModel_PROT_IPTOC2;

DataObject    iedModel_PROT_IPTOC2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC2_Mod_q;
DataAttribute iedModel_PROT_IPTOC2_Mod_t;
DataAttribute iedModel_PROT_IPTOC2_Mod_stVal;

DataObject    iedModel_PROT_IPTOC2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC2_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC2_Beh_q;
DataAttribute iedModel_PROT_IPTOC2_Beh_t;

DataObject    iedModel_PROT_IPTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC2_Health_stVal;
DataAttribute iedModel_PROT_IPTOC2_Health_q;
DataAttribute iedModel_PROT_IPTOC2_Health_t;

DataObject    iedModel_PROT_IPTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC2_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC2_Str;
DataAttribute iedModel_PROT_IPTOC2_Str_general;
DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC2_Str_q;
DataAttribute iedModel_PROT_IPTOC2_Str_t;

DataObject    iedModel_PROT_IPTOC2_Op;
DataAttribute iedModel_PROT_IPTOC2_Op_general;
DataAttribute iedModel_PROT_IPTOC2_Op_q;
DataAttribute iedModel_PROT_IPTOC2_Op_t;

// LN iPTOC1
LogicalNode   iedModel_PROT_IPTOC3;

DataObject    iedModel_PROT_IPTOC3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC3_Mod_q;
DataAttribute iedModel_PROT_IPTOC3_Mod_t;
DataAttribute iedModel_PROT_IPTOC3_Mod_stVal;

DataObject    iedModel_PROT_IPTOC3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC3_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC3_Beh_q;
DataAttribute iedModel_PROT_IPTOC3_Beh_t;

DataObject    iedModel_PROT_IPTOC3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC3_Health_stVal;
DataAttribute iedModel_PROT_IPTOC3_Health_q;
DataAttribute iedModel_PROT_IPTOC3_Health_t;

DataObject    iedModel_PROT_IPTOC3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC3_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC3_Str;
DataAttribute iedModel_PROT_IPTOC3_Str_general;
DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC3_Str_q;
DataAttribute iedModel_PROT_IPTOC3_Str_t;

DataObject    iedModel_PROT_IPTOC3_Op;
DataAttribute iedModel_PROT_IPTOC3_Op_general;
DataAttribute iedModel_PROT_IPTOC3_Op_q;
DataAttribute iedModel_PROT_IPTOC3_Op_t;

// LN IPTOC4
LogicalNode   iedModel_PROT_IPTOC4;

DataObject    iedModel_PROT_IPTOC4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC4_Mod_q;
DataAttribute iedModel_PROT_IPTOC4_Mod_t;
DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;

DataObject    iedModel_PROT_IPTOC4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC4_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC4_Beh_q;
DataAttribute iedModel_PROT_IPTOC4_Beh_t;

DataObject    iedModel_PROT_IPTOC4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC4_Health_stVal;
DataAttribute iedModel_PROT_IPTOC4_Health_q;
DataAttribute iedModel_PROT_IPTOC4_Health_t;

DataObject    iedModel_PROT_IPTOC4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC4_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC4_Str;
DataAttribute iedModel_PROT_IPTOC4_Str_general;
DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC4_Str_q;
DataAttribute iedModel_PROT_IPTOC4_Str_t;

DataObject    iedModel_PROT_IPTOC4_Op;
DataAttribute iedModel_PROT_IPTOC4_Op_general;
DataAttribute iedModel_PROT_IPTOC4_Op_q;
DataAttribute iedModel_PROT_IPTOC4_Op_t;


// LN IPTOC5
LogicalNode   iedModel_PROT_IPTOC5;

DataObject    iedModel_PROT_IPTOC5_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC5_Mod_q;
DataAttribute iedModel_PROT_IPTOC5_Mod_t;
DataAttribute iedModel_PROT_IPTOC5_Mod_stVal;

DataObject    iedModel_PROT_IPTOC5_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC5_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC5_Beh_q;
DataAttribute iedModel_PROT_IPTOC5_Beh_t;

DataObject    iedModel_PROT_IPTOC5_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC5_Health_stVal;
DataAttribute iedModel_PROT_IPTOC5_Health_q;
DataAttribute iedModel_PROT_IPTOC5_Health_t;

DataObject    iedModel_PROT_IPTOC5_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC5_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC5_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC5_Str;
DataAttribute iedModel_PROT_IPTOC5_Str_general;
DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC5_Str_q;
DataAttribute iedModel_PROT_IPTOC5_Str_t;

DataObject    iedModel_PROT_IPTOC5_Op;
DataAttribute iedModel_PROT_IPTOC5_Op_general;
DataAttribute iedModel_PROT_IPTOC5_Op_q;
DataAttribute iedModel_PROT_IPTOC5_Op_t;


// LN IPTOC6
LogicalNode   iedModel_PROT_IPTOC6;

DataObject    iedModel_PROT_IPTOC6_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC6_Mod_q;
DataAttribute iedModel_PROT_IPTOC6_Mod_t;
DataAttribute iedModel_PROT_IPTOC6_Mod_stVal;

DataObject    iedModel_PROT_IPTOC6_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC6_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC6_Beh_q;
DataAttribute iedModel_PROT_IPTOC6_Beh_t;

DataObject    iedModel_PROT_IPTOC6_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC6_Health_stVal;
DataAttribute iedModel_PROT_IPTOC6_Health_q;
DataAttribute iedModel_PROT_IPTOC6_Health_t;

DataObject    iedModel_PROT_IPTOC6_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC6_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC6_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC6_Str;
DataAttribute iedModel_PROT_IPTOC6_Str_general;
DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC6_Str_q;
DataAttribute iedModel_PROT_IPTOC6_Str_t;

DataObject    iedModel_PROT_IPTOC6_Op;
DataAttribute iedModel_PROT_IPTOC6_Op_general;
DataAttribute iedModel_PROT_IPTOC6_Op_q;
DataAttribute iedModel_PROT_IPTOC6_Op_t;


// LN IPTOC7
LogicalNode   iedModel_PROT_IPTOC7;

DataObject    iedModel_PROT_IPTOC7_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC7_Mod_q;
DataAttribute iedModel_PROT_IPTOC7_Mod_t;
DataAttribute iedModel_PROT_IPTOC7_Mod_stVal;

DataObject    iedModel_PROT_IPTOC7_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC7_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC7_Beh_q;
DataAttribute iedModel_PROT_IPTOC7_Beh_t;

DataObject    iedModel_PROT_IPTOC7_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC7_Health_stVal;
DataAttribute iedModel_PROT_IPTOC7_Health_q;
DataAttribute iedModel_PROT_IPTOC7_Health_t;

DataObject    iedModel_PROT_IPTOC7_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC7_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC7_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC7_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC7_Str;
DataAttribute iedModel_PROT_IPTOC7_Str_general;
DataAttribute iedModel_PROT_IPTOC7_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC7_Str_q;
DataAttribute iedModel_PROT_IPTOC7_Str_t;

DataObject    iedModel_PROT_IPTOC7_Op;
DataAttribute iedModel_PROT_IPTOC7_Op_general;
DataAttribute iedModel_PROT_IPTOC7_Op_q;
DataAttribute iedModel_PROT_IPTOC7_Op_t;


//----------------------------------------------------------------------------
// IPTOC8
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC8;
DataObject    iedModel_PROT_IPTOC8_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC8_Mod_q;
DataAttribute iedModel_PROT_IPTOC8_Mod_t;
DataAttribute iedModel_PROT_IPTOC8_Mod_stVal;
DataObject    iedModel_PROT_IPTOC8_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC8_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC8_Beh_q;
DataAttribute iedModel_PROT_IPTOC8_Beh_t;
DataObject    iedModel_PROT_IPTOC8_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC8_Health_stVal;
DataAttribute iedModel_PROT_IPTOC8_Health_q;
DataAttribute iedModel_PROT_IPTOC8_Health_t;
DataObject    iedModel_PROT_IPTOC8_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC8_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC8_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC8_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC8_Str;
DataAttribute iedModel_PROT_IPTOC8_Str_general;
DataAttribute iedModel_PROT_IPTOC8_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC8_Str_q;
DataAttribute iedModel_PROT_IPTOC8_Str_t;
DataObject    iedModel_PROT_IPTOC8_Op;
DataAttribute iedModel_PROT_IPTOC8_Op_general;
DataAttribute iedModel_PROT_IPTOC8_Op_q;
DataAttribute iedModel_PROT_IPTOC8_Op_t;
//----------------------------------------------------------------------------
// IPTOC9
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC9;
DataObject    iedModel_PROT_IPTOC9_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC9_Mod_q;
DataAttribute iedModel_PROT_IPTOC9_Mod_t;
DataAttribute iedModel_PROT_IPTOC9_Mod_stVal;
DataObject    iedModel_PROT_IPTOC9_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC9_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC9_Beh_q;
DataAttribute iedModel_PROT_IPTOC9_Beh_t;
DataObject    iedModel_PROT_IPTOC9_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC9_Health_stVal;
DataAttribute iedModel_PROT_IPTOC9_Health_q;
DataAttribute iedModel_PROT_IPTOC9_Health_t;
DataObject    iedModel_PROT_IPTOC9_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC9_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC9_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC9_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC9_Str;
DataAttribute iedModel_PROT_IPTOC9_Str_general;
DataAttribute iedModel_PROT_IPTOC9_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC9_Str_q;
DataAttribute iedModel_PROT_IPTOC9_Str_t;
DataObject    iedModel_PROT_IPTOC9_Op;
DataAttribute iedModel_PROT_IPTOC9_Op_general;
DataAttribute iedModel_PROT_IPTOC9_Op_q;
DataAttribute iedModel_PROT_IPTOC9_Op_t;
//----------------------------------------------------------------------------
// IPTOC10
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC10;
DataObject    iedModel_PROT_IPTOC10_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC10_Mod_q;
DataAttribute iedModel_PROT_IPTOC10_Mod_t;
DataAttribute iedModel_PROT_IPTOC10_Mod_stVal;
DataObject    iedModel_PROT_IPTOC10_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC10_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC10_Beh_q;
DataAttribute iedModel_PROT_IPTOC10_Beh_t;
DataObject    iedModel_PROT_IPTOC10_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC10_Health_stVal;
DataAttribute iedModel_PROT_IPTOC10_Health_q;
DataAttribute iedModel_PROT_IPTOC10_Health_t;
DataObject    iedModel_PROT_IPTOC10_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC10_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC10_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC10_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC10_Str;
DataAttribute iedModel_PROT_IPTOC10_Str_general;
DataAttribute iedModel_PROT_IPTOC10_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC10_Str_q;
DataAttribute iedModel_PROT_IPTOC10_Str_t;
DataObject    iedModel_PROT_IPTOC10_Op;
DataAttribute iedModel_PROT_IPTOC10_Op_general;
DataAttribute iedModel_PROT_IPTOC10_Op_q;
DataAttribute iedModel_PROT_IPTOC10_Op_t;
//----------------------------------------------------------------------------
// IPTOC11
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC11;
DataObject    iedModel_PROT_IPTOC11_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC11_Mod_q;
DataAttribute iedModel_PROT_IPTOC11_Mod_t;
DataAttribute iedModel_PROT_IPTOC11_Mod_stVal;
DataObject    iedModel_PROT_IPTOC11_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC11_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC11_Beh_q;
DataAttribute iedModel_PROT_IPTOC11_Beh_t;
DataObject    iedModel_PROT_IPTOC11_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC11_Health_stVal;
DataAttribute iedModel_PROT_IPTOC11_Health_q;
DataAttribute iedModel_PROT_IPTOC11_Health_t;
DataObject    iedModel_PROT_IPTOC11_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC11_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC11_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC11_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC11_Str;
DataAttribute iedModel_PROT_IPTOC11_Str_general;
DataAttribute iedModel_PROT_IPTOC11_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC11_Str_q;
DataAttribute iedModel_PROT_IPTOC11_Str_t;
DataObject    iedModel_PROT_IPTOC11_Op;
DataAttribute iedModel_PROT_IPTOC11_Op_general;
DataAttribute iedModel_PROT_IPTOC11_Op_q;
DataAttribute iedModel_PROT_IPTOC11_Op_t;
//----------------------------------------------------------------------------
// IPTOC12
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC12;
DataObject    iedModel_PROT_IPTOC12_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC12_Mod_q;
DataAttribute iedModel_PROT_IPTOC12_Mod_t;
DataAttribute iedModel_PROT_IPTOC12_Mod_stVal;
DataObject    iedModel_PROT_IPTOC12_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC12_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC12_Beh_q;
DataAttribute iedModel_PROT_IPTOC12_Beh_t;
DataObject    iedModel_PROT_IPTOC12_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC12_Health_stVal;
DataAttribute iedModel_PROT_IPTOC12_Health_q;
DataAttribute iedModel_PROT_IPTOC12_Health_t;
DataObject    iedModel_PROT_IPTOC12_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC12_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC12_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC12_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC12_Str;
DataAttribute iedModel_PROT_IPTOC12_Str_general;
DataAttribute iedModel_PROT_IPTOC12_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC12_Str_q;
DataAttribute iedModel_PROT_IPTOC12_Str_t;
DataObject    iedModel_PROT_IPTOC12_Op;
DataAttribute iedModel_PROT_IPTOC12_Op_general;
DataAttribute iedModel_PROT_IPTOC12_Op_q;
DataAttribute iedModel_PROT_IPTOC12_Op_t;
//----------------------------------------------------------------------------
// IPTOC13
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC13;
DataObject    iedModel_PROT_IPTOC13_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC13_Mod_q;
DataAttribute iedModel_PROT_IPTOC13_Mod_t;
DataAttribute iedModel_PROT_IPTOC13_Mod_stVal;
DataObject    iedModel_PROT_IPTOC13_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC13_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC13_Beh_q;
DataAttribute iedModel_PROT_IPTOC13_Beh_t;
DataObject    iedModel_PROT_IPTOC13_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC13_Health_stVal;
DataAttribute iedModel_PROT_IPTOC13_Health_q;
DataAttribute iedModel_PROT_IPTOC13_Health_t;
DataObject    iedModel_PROT_IPTOC13_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC13_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC13_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC13_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC13_Str;
DataAttribute iedModel_PROT_IPTOC13_Str_general;
DataAttribute iedModel_PROT_IPTOC13_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC13_Str_q;
DataAttribute iedModel_PROT_IPTOC13_Str_t;
DataObject    iedModel_PROT_IPTOC13_Op;
DataAttribute iedModel_PROT_IPTOC13_Op_general;
DataAttribute iedModel_PROT_IPTOC13_Op_q;
DataAttribute iedModel_PROT_IPTOC13_Op_t;
//----------------------------------------------------------------------------
// IPTOC14
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC14;
DataObject    iedModel_PROT_IPTOC14_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC14_Mod_q;
DataAttribute iedModel_PROT_IPTOC14_Mod_t;
DataAttribute iedModel_PROT_IPTOC14_Mod_stVal;
DataObject    iedModel_PROT_IPTOC14_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC14_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC14_Beh_q;
DataAttribute iedModel_PROT_IPTOC14_Beh_t;
DataObject    iedModel_PROT_IPTOC14_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC14_Health_stVal;
DataAttribute iedModel_PROT_IPTOC14_Health_q;
DataAttribute iedModel_PROT_IPTOC14_Health_t;
DataObject    iedModel_PROT_IPTOC14_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC14_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC14_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC14_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC14_Str;
DataAttribute iedModel_PROT_IPTOC14_Str_general;
DataAttribute iedModel_PROT_IPTOC14_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC14_Str_q;
DataAttribute iedModel_PROT_IPTOC14_Str_t;
DataObject    iedModel_PROT_IPTOC14_Op;
DataAttribute iedModel_PROT_IPTOC14_Op_general;
DataAttribute iedModel_PROT_IPTOC14_Op_q;
DataAttribute iedModel_PROT_IPTOC14_Op_t;
//----------------------------------------------------------------------------
// IPTOC15
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC15;
DataObject    iedModel_PROT_IPTOC15_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC15_Mod_q;
DataAttribute iedModel_PROT_IPTOC15_Mod_t;
DataAttribute iedModel_PROT_IPTOC15_Mod_stVal;
DataObject    iedModel_PROT_IPTOC15_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC15_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC15_Beh_q;
DataAttribute iedModel_PROT_IPTOC15_Beh_t;
DataObject    iedModel_PROT_IPTOC15_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC15_Health_stVal;
DataAttribute iedModel_PROT_IPTOC15_Health_q;
DataAttribute iedModel_PROT_IPTOC15_Health_t;
DataObject    iedModel_PROT_IPTOC15_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC15_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC15_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC15_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC15_Str;
DataAttribute iedModel_PROT_IPTOC15_Str_general;
DataAttribute iedModel_PROT_IPTOC15_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC15_Str_q;
DataAttribute iedModel_PROT_IPTOC15_Str_t;
DataObject    iedModel_PROT_IPTOC15_Op;
DataAttribute iedModel_PROT_IPTOC15_Op_general;
DataAttribute iedModel_PROT_IPTOC15_Op_q;
DataAttribute iedModel_PROT_IPTOC15_Op_t;
//----------------------------------------------------------------------------
// IPTOC16
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC16;
DataObject    iedModel_PROT_IPTOC16_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC16_Mod_q;
DataAttribute iedModel_PROT_IPTOC16_Mod_t;
DataAttribute iedModel_PROT_IPTOC16_Mod_stVal;
DataObject    iedModel_PROT_IPTOC16_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC16_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC16_Beh_q;
DataAttribute iedModel_PROT_IPTOC16_Beh_t;
DataObject    iedModel_PROT_IPTOC16_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC16_Health_stVal;
DataAttribute iedModel_PROT_IPTOC16_Health_q;
DataAttribute iedModel_PROT_IPTOC16_Health_t;
DataObject    iedModel_PROT_IPTOC16_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC16_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC16_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC16_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC16_Str;
DataAttribute iedModel_PROT_IPTOC16_Str_general;
DataAttribute iedModel_PROT_IPTOC16_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC16_Str_q;
DataAttribute iedModel_PROT_IPTOC16_Str_t;
DataObject    iedModel_PROT_IPTOC16_Op;
DataAttribute iedModel_PROT_IPTOC16_Op_general;
DataAttribute iedModel_PROT_IPTOC16_Op_q;
DataAttribute iedModel_PROT_IPTOC16_Op_t;
//----------------------------------------------------------------------------
// IPTOC17
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC17;
DataObject    iedModel_PROT_IPTOC17_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC17_Mod_q;
DataAttribute iedModel_PROT_IPTOC17_Mod_t;
DataAttribute iedModel_PROT_IPTOC17_Mod_stVal;
DataObject    iedModel_PROT_IPTOC17_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC17_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC17_Beh_q;
DataAttribute iedModel_PROT_IPTOC17_Beh_t;
DataObject    iedModel_PROT_IPTOC17_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC17_Health_stVal;
DataAttribute iedModel_PROT_IPTOC17_Health_q;
DataAttribute iedModel_PROT_IPTOC17_Health_t;
DataObject    iedModel_PROT_IPTOC17_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC17_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC17_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC17_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC17_Str;
DataAttribute iedModel_PROT_IPTOC17_Str_general;
DataAttribute iedModel_PROT_IPTOC17_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC17_Str_q;
DataAttribute iedModel_PROT_IPTOC17_Str_t;
DataObject    iedModel_PROT_IPTOC17_Op;
DataAttribute iedModel_PROT_IPTOC17_Op_general;
DataAttribute iedModel_PROT_IPTOC17_Op_q;
DataAttribute iedModel_PROT_IPTOC17_Op_t;
//----------------------------------------------------------------------------
// IPTOC18
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC18;
DataObject    iedModel_PROT_IPTOC18_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC18_Mod_q;
DataAttribute iedModel_PROT_IPTOC18_Mod_t;
DataAttribute iedModel_PROT_IPTOC18_Mod_stVal;
DataObject    iedModel_PROT_IPTOC18_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC18_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC18_Beh_q;
DataAttribute iedModel_PROT_IPTOC18_Beh_t;
DataObject    iedModel_PROT_IPTOC18_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC18_Health_stVal;
DataAttribute iedModel_PROT_IPTOC18_Health_q;
DataAttribute iedModel_PROT_IPTOC18_Health_t;
DataObject    iedModel_PROT_IPTOC18_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC18_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC18_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC18_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC18_Str;
DataAttribute iedModel_PROT_IPTOC18_Str_general;
DataAttribute iedModel_PROT_IPTOC18_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC18_Str_q;
DataAttribute iedModel_PROT_IPTOC18_Str_t;
DataObject    iedModel_PROT_IPTOC18_Op;
DataAttribute iedModel_PROT_IPTOC18_Op_general;
DataAttribute iedModel_PROT_IPTOC18_Op_q;
DataAttribute iedModel_PROT_IPTOC18_Op_t;
//----------------------------------------------------------------------------
// IPTOC19
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC19;
DataObject    iedModel_PROT_IPTOC19_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC19_Mod_q;
DataAttribute iedModel_PROT_IPTOC19_Mod_t;
DataAttribute iedModel_PROT_IPTOC19_Mod_stVal;
DataObject    iedModel_PROT_IPTOC19_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC19_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC19_Beh_q;
DataAttribute iedModel_PROT_IPTOC19_Beh_t;
DataObject    iedModel_PROT_IPTOC19_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC19_Health_stVal;
DataAttribute iedModel_PROT_IPTOC19_Health_q;
DataAttribute iedModel_PROT_IPTOC19_Health_t;
DataObject    iedModel_PROT_IPTOC19_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC19_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC19_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC19_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC19_Str;
DataAttribute iedModel_PROT_IPTOC19_Str_general;
DataAttribute iedModel_PROT_IPTOC19_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC19_Str_q;
DataAttribute iedModel_PROT_IPTOC19_Str_t;
DataObject    iedModel_PROT_IPTOC19_Op;
DataAttribute iedModel_PROT_IPTOC19_Op_general;
DataAttribute iedModel_PROT_IPTOC19_Op_q;
DataAttribute iedModel_PROT_IPTOC19_Op_t;
//----------------------------------------------------------------------------
// IPTOC20
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC20;
DataObject    iedModel_PROT_IPTOC20_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC20_Mod_q;
DataAttribute iedModel_PROT_IPTOC20_Mod_t;
DataAttribute iedModel_PROT_IPTOC20_Mod_stVal;
DataObject    iedModel_PROT_IPTOC20_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC20_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC20_Beh_q;
DataAttribute iedModel_PROT_IPTOC20_Beh_t;
DataObject    iedModel_PROT_IPTOC20_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC20_Health_stVal;
DataAttribute iedModel_PROT_IPTOC20_Health_q;
DataAttribute iedModel_PROT_IPTOC20_Health_t;
DataObject    iedModel_PROT_IPTOC20_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC20_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC20_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC20_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC20_Str;
DataAttribute iedModel_PROT_IPTOC20_Str_general;
DataAttribute iedModel_PROT_IPTOC20_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC20_Str_q;
DataAttribute iedModel_PROT_IPTOC20_Str_t;
DataObject    iedModel_PROT_IPTOC20_Op;
DataAttribute iedModel_PROT_IPTOC20_Op_general;
DataAttribute iedModel_PROT_IPTOC20_Op_q;
DataAttribute iedModel_PROT_IPTOC20_Op_t;
//----------------------------------------------------------------------------
// IPTOC21
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC21;
DataObject    iedModel_PROT_IPTOC21_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC21_Mod_q;
DataAttribute iedModel_PROT_IPTOC21_Mod_t;
DataAttribute iedModel_PROT_IPTOC21_Mod_stVal;
DataObject    iedModel_PROT_IPTOC21_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC21_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC21_Beh_q;
DataAttribute iedModel_PROT_IPTOC21_Beh_t;
DataObject    iedModel_PROT_IPTOC21_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC21_Health_stVal;
DataAttribute iedModel_PROT_IPTOC21_Health_q;
DataAttribute iedModel_PROT_IPTOC21_Health_t;
DataObject    iedModel_PROT_IPTOC21_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC21_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC21_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC21_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC21_Str;
DataAttribute iedModel_PROT_IPTOC21_Str_general;
DataAttribute iedModel_PROT_IPTOC21_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC21_Str_q;
DataAttribute iedModel_PROT_IPTOC21_Str_t;
DataObject    iedModel_PROT_IPTOC21_Op;
DataAttribute iedModel_PROT_IPTOC21_Op_general;
DataAttribute iedModel_PROT_IPTOC21_Op_q;
DataAttribute iedModel_PROT_IPTOC21_Op_t;
//----------------------------------------------------------------------------
// IPTOC22
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC22;
DataObject    iedModel_PROT_IPTOC22_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC22_Mod_q;
DataAttribute iedModel_PROT_IPTOC22_Mod_t;
DataAttribute iedModel_PROT_IPTOC22_Mod_stVal;
DataObject    iedModel_PROT_IPTOC22_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC22_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC22_Beh_q;
DataAttribute iedModel_PROT_IPTOC22_Beh_t;
DataObject    iedModel_PROT_IPTOC22_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC22_Health_stVal;
DataAttribute iedModel_PROT_IPTOC22_Health_q;
DataAttribute iedModel_PROT_IPTOC22_Health_t;
DataObject    iedModel_PROT_IPTOC22_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC22_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC22_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC22_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC22_Str;
DataAttribute iedModel_PROT_IPTOC22_Str_general;
DataAttribute iedModel_PROT_IPTOC22_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC22_Str_q;
DataAttribute iedModel_PROT_IPTOC22_Str_t;
DataObject    iedModel_PROT_IPTOC22_Op;
DataAttribute iedModel_PROT_IPTOC22_Op_general;
DataAttribute iedModel_PROT_IPTOC22_Op_q;
DataAttribute iedModel_PROT_IPTOC22_Op_t;
//----------------------------------------------------------------------------
// IPTOC23
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC23;
DataObject    iedModel_PROT_IPTOC23_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC23_Mod_q;
DataAttribute iedModel_PROT_IPTOC23_Mod_t;
DataAttribute iedModel_PROT_IPTOC23_Mod_stVal;
DataObject    iedModel_PROT_IPTOC23_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC23_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC23_Beh_q;
DataAttribute iedModel_PROT_IPTOC23_Beh_t;
DataObject    iedModel_PROT_IPTOC23_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC23_Health_stVal;
DataAttribute iedModel_PROT_IPTOC23_Health_q;
DataAttribute iedModel_PROT_IPTOC23_Health_t;
DataObject    iedModel_PROT_IPTOC23_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC23_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC23_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC23_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC23_Str;
DataAttribute iedModel_PROT_IPTOC23_Str_general;
DataAttribute iedModel_PROT_IPTOC23_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC23_Str_q;
DataAttribute iedModel_PROT_IPTOC23_Str_t;
DataObject    iedModel_PROT_IPTOC23_Op;
DataAttribute iedModel_PROT_IPTOC23_Op_general;
DataAttribute iedModel_PROT_IPTOC23_Op_q;
DataAttribute iedModel_PROT_IPTOC23_Op_t;
//----------------------------------------------------------------------------
// IPTOC24
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC24;
DataObject    iedModel_PROT_IPTOC24_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC24_Mod_q;
DataAttribute iedModel_PROT_IPTOC24_Mod_t;
DataAttribute iedModel_PROT_IPTOC24_Mod_stVal;
DataObject    iedModel_PROT_IPTOC24_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC24_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC24_Beh_q;
DataAttribute iedModel_PROT_IPTOC24_Beh_t;
DataObject    iedModel_PROT_IPTOC24_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC24_Health_stVal;
DataAttribute iedModel_PROT_IPTOC24_Health_q;
DataAttribute iedModel_PROT_IPTOC24_Health_t;
DataObject    iedModel_PROT_IPTOC24_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC24_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC24_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC24_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC24_Str;
DataAttribute iedModel_PROT_IPTOC24_Str_general;
DataAttribute iedModel_PROT_IPTOC24_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC24_Str_q;
DataAttribute iedModel_PROT_IPTOC24_Str_t;
DataObject    iedModel_PROT_IPTOC24_Op;
DataAttribute iedModel_PROT_IPTOC24_Op_general;
DataAttribute iedModel_PROT_IPTOC24_Op_q;
DataAttribute iedModel_PROT_IPTOC24_Op_t;
//----------------------------------------------------------------------------
// IPTOC25
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC25;
DataObject    iedModel_PROT_IPTOC25_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC25_Mod_q;
DataAttribute iedModel_PROT_IPTOC25_Mod_t;
DataAttribute iedModel_PROT_IPTOC25_Mod_stVal;
DataObject    iedModel_PROT_IPTOC25_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC25_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC25_Beh_q;
DataAttribute iedModel_PROT_IPTOC25_Beh_t;
DataObject    iedModel_PROT_IPTOC25_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC25_Health_stVal;
DataAttribute iedModel_PROT_IPTOC25_Health_q;
DataAttribute iedModel_PROT_IPTOC25_Health_t;
DataObject    iedModel_PROT_IPTOC25_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC25_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC25_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC25_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC25_Str;
DataAttribute iedModel_PROT_IPTOC25_Str_general;
DataAttribute iedModel_PROT_IPTOC25_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC25_Str_q;
DataAttribute iedModel_PROT_IPTOC25_Str_t;
DataObject    iedModel_PROT_IPTOC25_Op;
DataAttribute iedModel_PROT_IPTOC25_Op_general;
DataAttribute iedModel_PROT_IPTOC25_Op_q;
DataAttribute iedModel_PROT_IPTOC25_Op_t;
//----------------------------------------------------------------------------
// IPTOC26
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC26;
DataObject    iedModel_PROT_IPTOC26_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC26_Mod_q;
DataAttribute iedModel_PROT_IPTOC26_Mod_t;
DataAttribute iedModel_PROT_IPTOC26_Mod_stVal;
DataObject    iedModel_PROT_IPTOC26_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC26_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC26_Beh_q;
DataAttribute iedModel_PROT_IPTOC26_Beh_t;
DataObject    iedModel_PROT_IPTOC26_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC26_Health_stVal;
DataAttribute iedModel_PROT_IPTOC26_Health_q;
DataAttribute iedModel_PROT_IPTOC26_Health_t;
DataObject    iedModel_PROT_IPTOC26_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC26_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC26_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC26_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC26_Str;
DataAttribute iedModel_PROT_IPTOC26_Str_general;
DataAttribute iedModel_PROT_IPTOC26_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC26_Str_q;
DataAttribute iedModel_PROT_IPTOC26_Str_t;
DataObject    iedModel_PROT_IPTOC26_Op;
DataAttribute iedModel_PROT_IPTOC26_Op_general;
DataAttribute iedModel_PROT_IPTOC26_Op_q;
DataAttribute iedModel_PROT_IPTOC26_Op_t;
//----------------------------------------------------------------------------
// IPTOC27
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC27;
DataObject    iedModel_PROT_IPTOC27_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC27_Mod_q;
DataAttribute iedModel_PROT_IPTOC27_Mod_t;
DataAttribute iedModel_PROT_IPTOC27_Mod_stVal;
DataObject    iedModel_PROT_IPTOC27_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC27_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC27_Beh_q;
DataAttribute iedModel_PROT_IPTOC27_Beh_t;
DataObject    iedModel_PROT_IPTOC27_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC27_Health_stVal;
DataAttribute iedModel_PROT_IPTOC27_Health_q;
DataAttribute iedModel_PROT_IPTOC27_Health_t;
DataObject    iedModel_PROT_IPTOC27_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC27_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC27_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC27_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC27_Str;
DataAttribute iedModel_PROT_IPTOC27_Str_general;
DataAttribute iedModel_PROT_IPTOC27_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC27_Str_q;
DataAttribute iedModel_PROT_IPTOC27_Str_t;
DataObject    iedModel_PROT_IPTOC27_Op;
DataAttribute iedModel_PROT_IPTOC27_Op_general;
DataAttribute iedModel_PROT_IPTOC27_Op_q;
DataAttribute iedModel_PROT_IPTOC27_Op_t;
//----------------------------------------------------------------------------
// IPTOC28
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC28;
DataObject    iedModel_PROT_IPTOC28_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC28_Mod_q;
DataAttribute iedModel_PROT_IPTOC28_Mod_t;
DataAttribute iedModel_PROT_IPTOC28_Mod_stVal;
DataObject    iedModel_PROT_IPTOC28_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC28_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC28_Beh_q;
DataAttribute iedModel_PROT_IPTOC28_Beh_t;
DataObject    iedModel_PROT_IPTOC28_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC28_Health_stVal;
DataAttribute iedModel_PROT_IPTOC28_Health_q;
DataAttribute iedModel_PROT_IPTOC28_Health_t;
DataObject    iedModel_PROT_IPTOC28_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC28_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC28_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC28_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC28_Str;
DataAttribute iedModel_PROT_IPTOC28_Str_general;
DataAttribute iedModel_PROT_IPTOC28_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC28_Str_q;
DataAttribute iedModel_PROT_IPTOC28_Str_t;
DataObject    iedModel_PROT_IPTOC28_Op;
DataAttribute iedModel_PROT_IPTOC28_Op_general;
DataAttribute iedModel_PROT_IPTOC28_Op_q;
DataAttribute iedModel_PROT_IPTOC28_Op_t;
//----------------------------------------------------------------------------
// IPTOC29
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC29;
DataObject    iedModel_PROT_IPTOC29_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC29_Mod_q;
DataAttribute iedModel_PROT_IPTOC29_Mod_t;
DataAttribute iedModel_PROT_IPTOC29_Mod_stVal;
DataObject    iedModel_PROT_IPTOC29_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC29_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC29_Beh_q;
DataAttribute iedModel_PROT_IPTOC29_Beh_t;
DataObject    iedModel_PROT_IPTOC29_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC29_Health_stVal;
DataAttribute iedModel_PROT_IPTOC29_Health_q;
DataAttribute iedModel_PROT_IPTOC29_Health_t;
DataObject    iedModel_PROT_IPTOC29_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC29_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC29_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC29_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC29_Str;
DataAttribute iedModel_PROT_IPTOC29_Str_general;
DataAttribute iedModel_PROT_IPTOC29_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC29_Str_q;
DataAttribute iedModel_PROT_IPTOC29_Str_t;
DataObject    iedModel_PROT_IPTOC29_Op;
DataAttribute iedModel_PROT_IPTOC29_Op_general;
DataAttribute iedModel_PROT_IPTOC29_Op_q;
DataAttribute iedModel_PROT_IPTOC29_Op_t;
//----------------------------------------------------------------------------
// IPTOC30
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC30;
DataObject    iedModel_PROT_IPTOC30_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC30_Mod_q;
DataAttribute iedModel_PROT_IPTOC30_Mod_t;
DataAttribute iedModel_PROT_IPTOC30_Mod_stVal;
DataObject    iedModel_PROT_IPTOC30_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC30_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC30_Beh_q;
DataAttribute iedModel_PROT_IPTOC30_Beh_t;
DataObject    iedModel_PROT_IPTOC30_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC30_Health_stVal;
DataAttribute iedModel_PROT_IPTOC30_Health_q;
DataAttribute iedModel_PROT_IPTOC30_Health_t;
DataObject    iedModel_PROT_IPTOC30_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC30_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC30_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC30_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC30_Str;
DataAttribute iedModel_PROT_IPTOC30_Str_general;
DataAttribute iedModel_PROT_IPTOC30_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC30_Str_q;
DataAttribute iedModel_PROT_IPTOC30_Str_t;
DataObject    iedModel_PROT_IPTOC30_Op;
DataAttribute iedModel_PROT_IPTOC30_Op_general;
DataAttribute iedModel_PROT_IPTOC30_Op_q;
DataAttribute iedModel_PROT_IPTOC30_Op_t;
//----------------------------------------------------------------------------
// IPTOC31
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC31;
DataObject    iedModel_PROT_IPTOC31_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC31_Mod_q;
DataAttribute iedModel_PROT_IPTOC31_Mod_t;
DataAttribute iedModel_PROT_IPTOC31_Mod_stVal;
DataObject    iedModel_PROT_IPTOC31_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC31_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC31_Beh_q;
DataAttribute iedModel_PROT_IPTOC31_Beh_t;
DataObject    iedModel_PROT_IPTOC31_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC31_Health_stVal;
DataAttribute iedModel_PROT_IPTOC31_Health_q;
DataAttribute iedModel_PROT_IPTOC31_Health_t;
DataObject    iedModel_PROT_IPTOC31_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC31_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC31_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC31_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC31_Str;
DataAttribute iedModel_PROT_IPTOC31_Str_general;
DataAttribute iedModel_PROT_IPTOC31_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC31_Str_q;
DataAttribute iedModel_PROT_IPTOC31_Str_t;
DataObject    iedModel_PROT_IPTOC31_Op;
DataAttribute iedModel_PROT_IPTOC31_Op_general;
DataAttribute iedModel_PROT_IPTOC31_Op_q;
DataAttribute iedModel_PROT_IPTOC31_Op_t;
//----------------------------------------------------------------------------
// IPTOC32
//----------------------------------------------------------------------------
LogicalNode   iedModel_PROT_IPTOC32;
DataObject    iedModel_PROT_IPTOC32_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC32_Mod_q;
DataAttribute iedModel_PROT_IPTOC32_Mod_t;
DataAttribute iedModel_PROT_IPTOC32_Mod_stVal;
DataObject    iedModel_PROT_IPTOC32_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IPTOC32_Beh_stVal;
DataAttribute iedModel_PROT_IPTOC32_Beh_q;
DataAttribute iedModel_PROT_IPTOC32_Beh_t;
DataObject    iedModel_PROT_IPTOC32_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IPTOC32_Health_stVal;
DataAttribute iedModel_PROT_IPTOC32_Health_q;
DataAttribute iedModel_PROT_IPTOC32_Health_t;
DataObject    iedModel_PROT_IPTOC32_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IPTOC32_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IPTOC32_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_IPTOC32_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IPTOC32_Str;
DataAttribute iedModel_PROT_IPTOC32_Str_general;
DataAttribute iedModel_PROT_IPTOC32_Str_dirGeneral;
DataAttribute iedModel_PROT_IPTOC32_Str_q;
DataAttribute iedModel_PROT_IPTOC32_Str_t;
DataObject    iedModel_PROT_IPTOC32_Op;
DataAttribute iedModel_PROT_IPTOC32_Op_general;
DataAttribute iedModel_PROT_IPTOC32_Op_q;
DataAttribute iedModel_PROT_IPTOC32_Op_t;

/****************************************************************
* BUSRBRF1
*****************************************************************/
LogicalNode   iedModel_PROT_BUSRBRF1;

DataObject    iedModel_PROT_BUSRBRF1_Mod;
DataAttribute iedModel_PROT_BUSRBRF1_Mod_q;
DataAttribute iedModel_PROT_BUSRBRF1_Mod_t;
DataAttribute iedModel_PROT_BUSRBRF1_Mod_stVal;
DataObject    iedModel_PROT_BUSRBRF1_Beh;
DataAttribute iedModel_PROT_BUSRBRF1_Beh_stVal;
DataAttribute iedModel_PROT_BUSRBRF1_Beh_q;
DataAttribute iedModel_PROT_BUSRBRF1_Beh_t;
DataObject    iedModel_PROT_BUSRBRF1_Health;
DataAttribute iedModel_PROT_BUSRBRF1_Health_stVal;
DataAttribute iedModel_PROT_BUSRBRF1_Health_q;
DataAttribute iedModel_PROT_BUSRBRF1_Health_t;
DataObject    iedModel_PROT_BUSRBRF1_NamPlt;
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_vendor;
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_swRev;
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_d;

DataObject    iedModel_PROT_BUSRBRF1_OpEx;
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_general;
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_q;
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_t;
/****************************************************************
* BUSRBRF2
*****************************************************************/
LogicalNode   iedModel_PROT_BUSRBRF2;

DataObject    iedModel_PROT_BUSRBRF2_Mod;
DataAttribute iedModel_PROT_BUSRBRF2_Mod_q;
DataAttribute iedModel_PROT_BUSRBRF2_Mod_t;
DataAttribute iedModel_PROT_BUSRBRF2_Mod_stVal;
DataObject    iedModel_PROT_BUSRBRF2_Beh;
DataAttribute iedModel_PROT_BUSRBRF2_Beh_stVal;
DataAttribute iedModel_PROT_BUSRBRF2_Beh_q;
DataAttribute iedModel_PROT_BUSRBRF2_Beh_t;
DataObject    iedModel_PROT_BUSRBRF2_Health;
DataAttribute iedModel_PROT_BUSRBRF2_Health_stVal;
DataAttribute iedModel_PROT_BUSRBRF2_Health_q;
DataAttribute iedModel_PROT_BUSRBRF2_Health_t;
DataObject    iedModel_PROT_BUSRBRF2_NamPlt;
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_vendor;
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_swRev;
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_d;

DataObject    iedModel_PROT_BUSRBRF2_OpEx;
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_general;
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_q;
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_t;
/****************************************************************
* FRBRF1
*****************************************************************/
LogicalNode   iedModel_PROT_FRBRF1;

DataObject    iedModel_PROT_FRBRF1_Mod;
DataAttribute iedModel_PROT_FRBRF1_Mod_q;
DataAttribute iedModel_PROT_FRBRF1_Mod_t;
DataAttribute iedModel_PROT_FRBRF1_Mod_stVal;
DataObject    iedModel_PROT_FRBRF1_Beh;
DataAttribute iedModel_PROT_FRBRF1_Beh_stVal;
DataAttribute iedModel_PROT_FRBRF1_Beh_q;
DataAttribute iedModel_PROT_FRBRF1_Beh_t;
DataObject    iedModel_PROT_FRBRF1_Health;
DataAttribute iedModel_PROT_FRBRF1_Health_stVal;
DataAttribute iedModel_PROT_FRBRF1_Health_q;
DataAttribute iedModel_PROT_FRBRF1_Health_t;
DataObject    iedModel_PROT_FRBRF1_NamPlt;
DataAttribute iedModel_PROT_FRBRF1_NamPlt_vendor;
DataAttribute iedModel_PROT_FRBRF1_NamPlt_swRev;
DataAttribute iedModel_PROT_FRBRF1_NamPlt_d;

DataObject    iedModel_PROT_FRBRF1_OpEx;
DataAttribute iedModel_PROT_FRBRF1_OpEx_general;
DataAttribute iedModel_PROT_FRBRF1_OpEx_q;
DataAttribute iedModel_PROT_FRBRF1_OpEx_t;
/****************************************************************
* FRBRF2
*****************************************************************/
LogicalNode   iedModel_PROT_FRBRF2;

DataObject    iedModel_PROT_FRBRF2_Mod;
DataAttribute iedModel_PROT_FRBRF2_Mod_q;
DataAttribute iedModel_PROT_FRBRF2_Mod_t;
DataAttribute iedModel_PROT_FRBRF2_Mod_stVal;
DataObject    iedModel_PROT_FRBRF2_Beh;
DataAttribute iedModel_PROT_FRBRF2_Beh_stVal;
DataAttribute iedModel_PROT_FRBRF2_Beh_q;
DataAttribute iedModel_PROT_FRBRF2_Beh_t;
DataObject    iedModel_PROT_FRBRF2_Health;
DataAttribute iedModel_PROT_FRBRF2_Health_stVal;
DataAttribute iedModel_PROT_FRBRF2_Health_q;
DataAttribute iedModel_PROT_FRBRF2_Health_t;
DataObject    iedModel_PROT_FRBRF2_NamPlt;
DataAttribute iedModel_PROT_FRBRF2_NamPlt_vendor;
DataAttribute iedModel_PROT_FRBRF2_NamPlt_swRev;
DataAttribute iedModel_PROT_FRBRF2_NamPlt_d;

DataObject    iedModel_PROT_FRBRF2_OpEx;
DataAttribute iedModel_PROT_FRBRF2_OpEx_general;
DataAttribute iedModel_PROT_FRBRF2_OpEx_q;
DataAttribute iedModel_PROT_FRBRF2_OpEx_t;
/****************************************************************
* FRBRF3
*****************************************************************/
LogicalNode   iedModel_PROT_FRBRF3;

DataObject    iedModel_PROT_FRBRF3_Mod;
DataAttribute iedModel_PROT_FRBRF3_Mod_q;
DataAttribute iedModel_PROT_FRBRF3_Mod_t;
DataAttribute iedModel_PROT_FRBRF3_Mod_stVal;
DataObject    iedModel_PROT_FRBRF3_Beh;
DataAttribute iedModel_PROT_FRBRF3_Beh_stVal;
DataAttribute iedModel_PROT_FRBRF3_Beh_q;
DataAttribute iedModel_PROT_FRBRF3_Beh_t;
DataObject    iedModel_PROT_FRBRF3_Health;
DataAttribute iedModel_PROT_FRBRF3_Health_stVal;
DataAttribute iedModel_PROT_FRBRF3_Health_q;
DataAttribute iedModel_PROT_FRBRF3_Health_t;
DataObject    iedModel_PROT_FRBRF3_NamPlt;
DataAttribute iedModel_PROT_FRBRF3_NamPlt_vendor;
DataAttribute iedModel_PROT_FRBRF3_NamPlt_swRev;
DataAttribute iedModel_PROT_FRBRF3_NamPlt_d;

DataObject    iedModel_PROT_FRBRF3_OpEx;
DataAttribute iedModel_PROT_FRBRF3_OpEx_general;
DataAttribute iedModel_PROT_FRBRF3_OpEx_q;
DataAttribute iedModel_PROT_FRBRF3_OpEx_t;
/****************************************************************
* FRBRF4
*****************************************************************/
LogicalNode   iedModel_PROT_FRBRF4;

DataObject    iedModel_PROT_FRBRF4_Mod;
DataAttribute iedModel_PROT_FRBRF4_Mod_q;
DataAttribute iedModel_PROT_FRBRF4_Mod_t;
DataAttribute iedModel_PROT_FRBRF4_Mod_stVal;
DataObject    iedModel_PROT_FRBRF4_Beh;
DataAttribute iedModel_PROT_FRBRF4_Beh_stVal;
DataAttribute iedModel_PROT_FRBRF4_Beh_q;
DataAttribute iedModel_PROT_FRBRF4_Beh_t;
DataObject    iedModel_PROT_FRBRF4_Health;
DataAttribute iedModel_PROT_FRBRF4_Health_stVal;
DataAttribute iedModel_PROT_FRBRF4_Health_q;
DataAttribute iedModel_PROT_FRBRF4_Health_t;
DataObject    iedModel_PROT_FRBRF4_NamPlt;
DataAttribute iedModel_PROT_FRBRF4_NamPlt_vendor;
DataAttribute iedModel_PROT_FRBRF4_NamPlt_swRev;
DataAttribute iedModel_PROT_FRBRF4_NamPlt_d;

DataObject    iedModel_PROT_FRBRF4_OpEx;
DataAttribute iedModel_PROT_FRBRF4_OpEx_general;
DataAttribute iedModel_PROT_FRBRF4_OpEx_q;
DataAttribute iedModel_PROT_FRBRF4_OpEx_t;
/****************************************************************
* FRBRF5
*****************************************************************/
LogicalNode   iedModel_PROT_FRBRF5;

DataObject    iedModel_PROT_FRBRF5_Mod;
DataAttribute iedModel_PROT_FRBRF5_Mod_q;
DataAttribute iedModel_PROT_FRBRF5_Mod_t;
DataAttribute iedModel_PROT_FRBRF5_Mod_stVal;
DataObject    iedModel_PROT_FRBRF5_Beh;
DataAttribute iedModel_PROT_FRBRF5_Beh_stVal;
DataAttribute iedModel_PROT_FRBRF5_Beh_q;
DataAttribute iedModel_PROT_FRBRF5_Beh_t;
DataObject    iedModel_PROT_FRBRF5_Health;
DataAttribute iedModel_PROT_FRBRF5_Health_stVal;
DataAttribute iedModel_PROT_FRBRF5_Health_q;
DataAttribute iedModel_PROT_FRBRF5_Health_t;
DataObject    iedModel_PROT_FRBRF5_NamPlt;
DataAttribute iedModel_PROT_FRBRF5_NamPlt_vendor;
DataAttribute iedModel_PROT_FRBRF5_NamPlt_swRev;
DataAttribute iedModel_PROT_FRBRF5_NamPlt_d;

DataObject    iedModel_PROT_FRBRF5_OpEx;
DataAttribute iedModel_PROT_FRBRF5_OpEx_general;
DataAttribute iedModel_PROT_FRBRF5_OpEx_q;
DataAttribute iedModel_PROT_FRBRF5_OpEx_t;

/****************************************************************
* FINRBRF1
*****************************************************************/
LogicalNode   iedModel_PROT_FINRBRF1;

DataObject    iedModel_PROT_FINRBRF1_Mod;
DataAttribute iedModel_PROT_FINRBRF1_Mod_q;
DataAttribute iedModel_PROT_FINRBRF1_Mod_t;
DataAttribute iedModel_PROT_FINRBRF1_Mod_stVal;
DataObject    iedModel_PROT_FINRBRF1_Beh;
DataAttribute iedModel_PROT_FINRBRF1_Beh_stVal;
DataAttribute iedModel_PROT_FINRBRF1_Beh_q;
DataAttribute iedModel_PROT_FINRBRF1_Beh_t;
DataObject    iedModel_PROT_FINRBRF1_Health;
DataAttribute iedModel_PROT_FINRBRF1_Health_stVal;
DataAttribute iedModel_PROT_FINRBRF1_Health_q;
DataAttribute iedModel_PROT_FINRBRF1_Health_t;
DataObject    iedModel_PROT_FINRBRF1_NamPlt;
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_vendor;
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_swRev;
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_d;

DataObject    iedModel_PROT_FINRBRF1_OpEx;
DataAttribute iedModel_PROT_FINRBRF1_OpEx_general;
DataAttribute iedModel_PROT_FINRBRF1_OpEx_q;
DataAttribute iedModel_PROT_FINRBRF1_OpEx_t;


/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO1;

DataObject iedModel_PROT_VZGGIO1_Mod;
DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;

DataObject iedModel_PROT_VZGGIO1_Beh;
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO1_Beh_q;
DataAttribute iedModel_PROT_VZGGIO1_Beh_t;

DataObject iedModel_PROT_VZGGIO1_Health;
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO1_Health_q;
DataAttribute iedModel_PROT_VZGGIO1_Health_t;

DataObject iedModel_PROT_VZGGIO1_NamPlt;

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d;

DataObject iedModel_PROT_VZGGIO1_Alm;
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO1_Alm_q;
DataAttribute iedModel_PROT_VZGGIO1_Alm_t;



/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO2;

DataObject iedModel_PROT_VZGGIO2_Mod;
DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;


DataObject iedModel_PROT_VZGGIO2_Beh;
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO2_Beh_q;
DataAttribute iedModel_PROT_VZGGIO2_Beh_t;

DataObject iedModel_PROT_VZGGIO2_Health;
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO2_Health_q;
DataAttribute iedModel_PROT_VZGGIO2_Health_t;

DataObject iedModel_PROT_VZGGIO2_NamPlt;

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d;

DataObject iedModel_PROT_VZGGIO2_Alm;
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO2_Alm_q;
DataAttribute iedModel_PROT_VZGGIO2_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO3;

DataObject iedModel_PROT_VZGGIO3_Mod;
DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;

DataObject iedModel_PROT_VZGGIO3_Beh;
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO3_Beh_q;
DataAttribute iedModel_PROT_VZGGIO3_Beh_t;

DataObject iedModel_PROT_VZGGIO3_Health;
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO3_Health_q;
DataAttribute iedModel_PROT_VZGGIO3_Health_t;

DataObject iedModel_PROT_VZGGIO3_NamPlt;

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d;

DataObject iedModel_PROT_VZGGIO3_Alm;
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO3_Alm_q;
DataAttribute iedModel_PROT_VZGGIO3_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO4;

DataObject iedModel_PROT_VZGGIO4_Mod;
DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;

DataObject iedModel_PROT_VZGGIO4_Beh;
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO4_Beh_q;
DataAttribute iedModel_PROT_VZGGIO4_Beh_t;

DataObject iedModel_PROT_VZGGIO4_Health;
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO4_Health_q;
DataAttribute iedModel_PROT_VZGGIO4_Health_t;

DataObject iedModel_PROT_VZGGIO4_NamPlt;

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d;

DataObject iedModel_PROT_VZGGIO4_Alm;
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO4_Alm_q;
DataAttribute iedModel_PROT_VZGGIO4_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO5;

DataObject iedModel_PROT_VZGGIO5_Mod;
DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;

DataObject iedModel_PROT_VZGGIO5_Beh;
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO5_Beh_q;
DataAttribute iedModel_PROT_VZGGIO5_Beh_t;

DataObject iedModel_PROT_VZGGIO5_Health;
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO5_Health_q;
DataAttribute iedModel_PROT_VZGGIO5_Health_t;

DataObject iedModel_PROT_VZGGIO5_NamPlt;

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d;

DataObject iedModel_PROT_VZGGIO5_Alm;
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO5_Alm_q;
DataAttribute iedModel_PROT_VZGGIO5_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO6;

DataObject iedModel_PROT_VZGGIO6_Mod;
DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;

DataObject iedModel_PROT_VZGGIO6_Beh;
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO6_Beh_q;
DataAttribute iedModel_PROT_VZGGIO6_Beh_t;

DataObject iedModel_PROT_VZGGIO6_Health;
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO6_Health_q;
DataAttribute iedModel_PROT_VZGGIO6_Health_t;

DataObject iedModel_PROT_VZGGIO6_NamPlt;

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d;

DataObject iedModel_PROT_VZGGIO6_Alm;
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO6_Alm_q;
DataAttribute iedModel_PROT_VZGGIO6_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO7;

DataObject iedModel_PROT_VZGGIO7_Mod;
DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;

DataObject iedModel_PROT_VZGGIO7_Beh;
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO7_Beh_q;
DataAttribute iedModel_PROT_VZGGIO7_Beh_t;

DataObject iedModel_PROT_VZGGIO7_Health;
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO7_Health_q;
DataAttribute iedModel_PROT_VZGGIO7_Health_t;

DataObject iedModel_PROT_VZGGIO7_NamPlt;

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d;

DataObject iedModel_PROT_VZGGIO7_Alm;
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO7_Alm_q;
DataAttribute iedModel_PROT_VZGGIO7_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO8;

DataObject iedModel_PROT_VZGGIO8_Mod;
DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;


DataObject iedModel_PROT_VZGGIO8_Beh;
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO8_Beh_q;
DataAttribute iedModel_PROT_VZGGIO8_Beh_t;

DataObject iedModel_PROT_VZGGIO8_Health;
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO8_Health_q;
DataAttribute iedModel_PROT_VZGGIO8_Health_t;

DataObject iedModel_PROT_VZGGIO8_NamPlt;

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d;

DataObject iedModel_PROT_VZGGIO8_Alm;
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO8_Alm_q;
DataAttribute iedModel_PROT_VZGGIO8_Alm_t;


/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO9;

DataObject iedModel_PROT_VZGGIO9_Mod;
DataAttribute iedModel_PROT_VZGGIO9_Mod_q;
DataAttribute iedModel_PROT_VZGGIO9_Mod_t;
DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal;

DataObject iedModel_PROT_VZGGIO9_Beh;
DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Beh_q;
DataAttribute iedModel_PROT_VZGGIO9_Beh_t;

DataObject iedModel_PROT_VZGGIO9_Health;
DataAttribute iedModel_PROT_VZGGIO9_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Health_q;
DataAttribute iedModel_PROT_VZGGIO9_Health_t;

DataObject iedModel_PROT_VZGGIO9_NamPlt;

DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d;

DataObject iedModel_PROT_VZGGIO9_Alm;
DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Alm_q;
DataAttribute iedModel_PROT_VZGGIO9_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO10;

DataObject iedModel_PROT_VZGGIO10_Mod;
DataAttribute iedModel_PROT_VZGGIO10_Mod_q;
DataAttribute iedModel_PROT_VZGGIO10_Mod_t;
DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal;

DataObject iedModel_PROT_VZGGIO10_Beh;
DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Beh_q;
DataAttribute iedModel_PROT_VZGGIO10_Beh_t;

DataObject iedModel_PROT_VZGGIO10_Health;
DataAttribute iedModel_PROT_VZGGIO10_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Health_q;
DataAttribute iedModel_PROT_VZGGIO10_Health_t;

DataObject iedModel_PROT_VZGGIO10_NamPlt;

DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d;

DataObject iedModel_PROT_VZGGIO10_Alm;
DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Alm_q;
DataAttribute iedModel_PROT_VZGGIO10_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO11;

DataObject iedModel_PROT_VZGGIO11_Mod;
DataAttribute iedModel_PROT_VZGGIO11_Mod_q;
DataAttribute iedModel_PROT_VZGGIO11_Mod_t;
DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal;

DataObject iedModel_PROT_VZGGIO11_Beh;
DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Beh_q;
DataAttribute iedModel_PROT_VZGGIO11_Beh_t;

DataObject iedModel_PROT_VZGGIO11_Health;
DataAttribute iedModel_PROT_VZGGIO11_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Health_q;
DataAttribute iedModel_PROT_VZGGIO11_Health_t;

DataObject iedModel_PROT_VZGGIO11_NamPlt;

DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d;

DataObject iedModel_PROT_VZGGIO11_Alm;
DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Alm_q;
DataAttribute iedModel_PROT_VZGGIO11_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO12;

DataObject iedModel_PROT_VZGGIO12_Mod;
DataAttribute iedModel_PROT_VZGGIO12_Mod_q;
DataAttribute iedModel_PROT_VZGGIO12_Mod_t;
DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal;

DataObject iedModel_PROT_VZGGIO12_Beh;
DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Beh_q;
DataAttribute iedModel_PROT_VZGGIO12_Beh_t;

DataObject iedModel_PROT_VZGGIO12_Health;
DataAttribute iedModel_PROT_VZGGIO12_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Health_q;
DataAttribute iedModel_PROT_VZGGIO12_Health_t;

DataObject iedModel_PROT_VZGGIO12_NamPlt;

DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d;

DataObject iedModel_PROT_VZGGIO12_Alm;
DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Alm_q;
DataAttribute iedModel_PROT_VZGGIO12_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO13;

DataObject iedModel_PROT_VZGGIO13_Mod;
DataAttribute iedModel_PROT_VZGGIO13_Mod_q;
DataAttribute iedModel_PROT_VZGGIO13_Mod_t;
DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal;

DataObject iedModel_PROT_VZGGIO13_Beh;
DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Beh_q;
DataAttribute iedModel_PROT_VZGGIO13_Beh_t;

DataObject iedModel_PROT_VZGGIO13_Health;
DataAttribute iedModel_PROT_VZGGIO13_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Health_q;
DataAttribute iedModel_PROT_VZGGIO13_Health_t;

DataObject iedModel_PROT_VZGGIO13_NamPlt;

DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d;

DataObject iedModel_PROT_VZGGIO13_Alm;
DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Alm_q;
DataAttribute iedModel_PROT_VZGGIO13_Alm_t;


/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO14;

DataObject iedModel_PROT_VZGGIO14_Mod;
DataAttribute iedModel_PROT_VZGGIO14_Mod_q;
DataAttribute iedModel_PROT_VZGGIO14_Mod_t;
DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal;

DataObject iedModel_PROT_VZGGIO14_Beh;
DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Beh_q;
DataAttribute iedModel_PROT_VZGGIO14_Beh_t;

DataObject iedModel_PROT_VZGGIO14_Health;
DataAttribute iedModel_PROT_VZGGIO14_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Health_q;
DataAttribute iedModel_PROT_VZGGIO14_Health_t;

DataObject iedModel_PROT_VZGGIO14_NamPlt;

DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d;

DataObject iedModel_PROT_VZGGIO14_Alm;
DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Alm_q;
DataAttribute iedModel_PROT_VZGGIO14_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO15;

DataObject iedModel_PROT_VZGGIO15_Mod;
DataAttribute iedModel_PROT_VZGGIO15_Mod_q;
DataAttribute iedModel_PROT_VZGGIO15_Mod_t;
DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal;

DataObject iedModel_PROT_VZGGIO15_Beh;
DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Beh_q;
DataAttribute iedModel_PROT_VZGGIO15_Beh_t;

DataObject iedModel_PROT_VZGGIO15_Health;
DataAttribute iedModel_PROT_VZGGIO15_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Health_q;
DataAttribute iedModel_PROT_VZGGIO15_Health_t;

DataObject iedModel_PROT_VZGGIO15_NamPlt;

DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d;

DataObject iedModel_PROT_VZGGIO15_Alm;
DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Alm_q;
DataAttribute iedModel_PROT_VZGGIO15_Alm_t;

/****************************************************************
* VZGGIO
*****************************************************************/
LogicalNode iedModel_PROT_VZGGIO16;

DataObject iedModel_PROT_VZGGIO16_Mod;
DataAttribute iedModel_PROT_VZGGIO16_Mod_q;
DataAttribute iedModel_PROT_VZGGIO16_Mod_t;
DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal;

DataObject iedModel_PROT_VZGGIO16_Beh;
DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Beh_q;
DataAttribute iedModel_PROT_VZGGIO16_Beh_t;

DataObject iedModel_PROT_VZGGIO16_Health;
DataAttribute iedModel_PROT_VZGGIO16_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Health_q;
DataAttribute iedModel_PROT_VZGGIO16_Health_t;

DataObject iedModel_PROT_VZGGIO16_NamPlt;

DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d;

DataObject iedModel_PROT_VZGGIO16_Alm;
DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Alm_q;
DataAttribute iedModel_PROT_VZGGIO16_Alm_t;


#if defined (MR902)
//----------------------------------------------------------------------------
// IDPDIF1
LogicalNode iedModel_PROT_IDPDIF1;

DataObject iedModel_PROT_IDPDIF1_Mod;
DataAttribute iedModel_PROT_IDPDIF1_Mod_q;
DataAttribute iedModel_PROT_IDPDIF1_Mod_t;
DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal;
//DataAttribute iedModel_PROT_IDPDIF1_Mod_ctlModel;

DataObject iedModel_PROT_IDPDIF1_Beh;
DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF1_Beh_q;
DataAttribute iedModel_PROT_IDPDIF1_Beh_t;

DataObject iedModel_PROT_IDPDIF1_Health;
DataAttribute iedModel_PROT_IDPDIF1_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF1_Health_q;
DataAttribute iedModel_PROT_IDPDIF1_Health_t;

DataObject iedModel_PROT_IDPDIF1_NamPlt;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF1_Op;
DataAttribute iedModel_PROT_IDPDIF1_Op_general;
DataAttribute iedModel_PROT_IDPDIF1_Op_q;
DataAttribute iedModel_PROT_IDPDIF1_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF1_Str;
DataAttribute iedModel_PROT_IDPDIF1_Str_general;
DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF1_Str_q;
DataAttribute iedModel_PROT_IDPDIF1_Str_t;

DataObject iedModel_PROT_IDPDIF1_RstA;
DataObject iedModel_PROT_IDPDIF1_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF1_RstA_phsB;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_q;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_t;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_db;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF1_RstA_phsC;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_q;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_t;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_db;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_zeroDb;

DataObject iedModel_PROT_IDPDIF1_DifACIc;
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsB;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_q;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_t;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_db;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsC;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_q;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_t;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_db;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_zeroDb;

//----------------------------------------------------------------------------
// IDPDIF2
LogicalNode iedModel_PROT_IDPDIF2;

DataObject iedModel_PROT_IDPDIF2_Mod;
DataAttribute iedModel_PROT_IDPDIF2_Mod_q;
DataAttribute iedModel_PROT_IDPDIF2_Mod_t;
DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal;
//DataAttribute iedModel_PROT_IDPDIF2_Mod_ctlModel;

DataObject iedModel_PROT_IDPDIF2_Beh;
DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF2_Beh_q;
DataAttribute iedModel_PROT_IDPDIF2_Beh_t;

DataObject iedModel_PROT_IDPDIF2_Health;
DataAttribute iedModel_PROT_IDPDIF2_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF2_Health_q;
DataAttribute iedModel_PROT_IDPDIF2_Health_t;

DataObject iedModel_PROT_IDPDIF2_NamPlt;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF2_Op;
DataAttribute iedModel_PROT_IDPDIF2_Op_general;
DataAttribute iedModel_PROT_IDPDIF2_Op_q;
DataAttribute iedModel_PROT_IDPDIF2_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF2_Str;
DataAttribute iedModel_PROT_IDPDIF2_Str_general;
DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF2_Str_q;
DataAttribute iedModel_PROT_IDPDIF2_Str_t;

DataObject iedModel_PROT_IDPDIF2_RstA;
DataObject iedModel_PROT_IDPDIF2_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF2_RstA_phsB;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_q;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_t;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_db;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF2_RstA_phsC;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_q;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_t;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_db;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_zeroDb;

DataObject iedModel_PROT_IDPDIF2_DifACIc;
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsB;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_q;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_t;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_db;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsC;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_q;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_t;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_db;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_zeroDb;

//----------------------------------------------------------------------------
// IDPDIF3
LogicalNode iedModel_PROT_IDPDIF3;

DataObject iedModel_PROT_IDPDIF3_Mod;
DataAttribute iedModel_PROT_IDPDIF3_Mod_q;
DataAttribute iedModel_PROT_IDPDIF3_Mod_t;
DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal;
//DataAttribute iedModel_PROT_IDPDIF3_Mod_ctlModel;

DataObject iedModel_PROT_IDPDIF3_Beh;
DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF3_Beh_q;
DataAttribute iedModel_PROT_IDPDIF3_Beh_t;

DataObject iedModel_PROT_IDPDIF3_Health;
DataAttribute iedModel_PROT_IDPDIF3_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF3_Health_q;
DataAttribute iedModel_PROT_IDPDIF3_Health_t;

DataObject iedModel_PROT_IDPDIF3_NamPlt;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF3_Op;
DataAttribute iedModel_PROT_IDPDIF3_Op_general;
DataAttribute iedModel_PROT_IDPDIF3_Op_q;
DataAttribute iedModel_PROT_IDPDIF3_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF3_Str;
DataAttribute iedModel_PROT_IDPDIF3_Str_general;
DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF3_Str_q;
DataAttribute iedModel_PROT_IDPDIF3_Str_t;

DataObject iedModel_PROT_IDPDIF3_RstA;
DataObject iedModel_PROT_IDPDIF3_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF3_RstA_phsB;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_q;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_t;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_db;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF3_RstA_phsC;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_q;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_t;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_db;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_zeroDb;

DataObject iedModel_PROT_IDPDIF3_DifACIc;
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb;
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsB;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_q;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_t;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_db;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_zeroDb;
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsC;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_q;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_t;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_db;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_zeroDb;

#endif
#if defined (MR901)
/****************************************************************
* IDPDIF1
*****************************************************************/
LogicalNode iedModel_PROT_IDPDIF1;

DataObject iedModel_PROT_IDPDIF1_Mod;
DataAttribute iedModel_PROT_IDPDIF1_Mod_q;
DataAttribute iedModel_PROT_IDPDIF1_Mod_t;
DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal;
DataObject iedModel_PROT_IDPDIF1_Beh;
DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF1_Beh_q;
DataAttribute iedModel_PROT_IDPDIF1_Beh_t;
DataObject iedModel_PROT_IDPDIF1_Health;
DataAttribute iedModel_PROT_IDPDIF1_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF1_Health_q;
DataAttribute iedModel_PROT_IDPDIF1_Health_t;
DataObject iedModel_PROT_IDPDIF1_NamPlt;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF1_Op;
DataAttribute iedModel_PROT_IDPDIF1_Op_general;
DataAttribute iedModel_PROT_IDPDIF1_Op_q;
DataAttribute iedModel_PROT_IDPDIF1_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF1_Str;
DataAttribute iedModel_PROT_IDPDIF1_Str_general;
DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF1_Str_q;
DataAttribute iedModel_PROT_IDPDIF1_Str_t;

DataObject iedModel_PROT_IDPDIF1_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb;

DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb;

/****************************************************************
* IDPDIF2
*****************************************************************/
LogicalNode iedModel_PROT_IDPDIF2;

DataObject iedModel_PROT_IDPDIF2_Mod;
DataAttribute iedModel_PROT_IDPDIF2_Mod_q;
DataAttribute iedModel_PROT_IDPDIF2_Mod_t;
DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal;
DataObject iedModel_PROT_IDPDIF2_Beh;
DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF2_Beh_q;
DataAttribute iedModel_PROT_IDPDIF2_Beh_t;
DataObject iedModel_PROT_IDPDIF2_Health;
DataAttribute iedModel_PROT_IDPDIF2_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF2_Health_q;
DataAttribute iedModel_PROT_IDPDIF2_Health_t;
DataObject iedModel_PROT_IDPDIF2_NamPlt;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF2_Op;
DataAttribute iedModel_PROT_IDPDIF2_Op_general;
DataAttribute iedModel_PROT_IDPDIF2_Op_q;
DataAttribute iedModel_PROT_IDPDIF2_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF2_Str;
DataAttribute iedModel_PROT_IDPDIF2_Str_general;
DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF2_Str_q;
DataAttribute iedModel_PROT_IDPDIF2_Str_t;

DataObject iedModel_PROT_IDPDIF2_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb;

DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb;

/****************************************************************
* IDPDIF3
*****************************************************************/
LogicalNode iedModel_PROT_IDPDIF3;

DataObject iedModel_PROT_IDPDIF3_Mod;
DataAttribute iedModel_PROT_IDPDIF3_Mod_q;
DataAttribute iedModel_PROT_IDPDIF3_Mod_t;
DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal;
DataObject iedModel_PROT_IDPDIF3_Beh;
DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal;
DataAttribute iedModel_PROT_IDPDIF3_Beh_q;
DataAttribute iedModel_PROT_IDPDIF3_Beh_t;
DataObject iedModel_PROT_IDPDIF3_Health;
DataAttribute iedModel_PROT_IDPDIF3_Health_stVal;
DataAttribute iedModel_PROT_IDPDIF3_Health_q;
DataAttribute iedModel_PROT_IDPDIF3_Health_t;
DataObject iedModel_PROT_IDPDIF3_NamPlt;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev;
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDPDIF3_Op;
DataAttribute iedModel_PROT_IDPDIF3_Op_general;
DataAttribute iedModel_PROT_IDPDIF3_Op_q;
DataAttribute iedModel_PROT_IDPDIF3_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDPDIF3_Str;
DataAttribute iedModel_PROT_IDPDIF3_Str_general;
DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral;
DataAttribute iedModel_PROT_IDPDIF3_Str_q;
DataAttribute iedModel_PROT_IDPDIF3_Str_t;

DataObject iedModel_PROT_IDPDIF3_RstA_phsA;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db;
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb;

DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db;
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb;
#endif

/****************************************************************
* IDMPDIF1
*****************************************************************/
LogicalNode iedModel_PROT_IDMPDIF1;

DataObject iedModel_PROT_IDMPDIF1_Mod;
DataAttribute iedModel_PROT_IDMPDIF1_Mod_q;
DataAttribute iedModel_PROT_IDMPDIF1_Mod_t;
DataAttribute iedModel_PROT_IDMPDIF1_Mod_stVal;

DataObject iedModel_PROT_IDMPDIF1_Beh;
DataAttribute iedModel_PROT_IDMPDIF1_Beh_stVal;
DataAttribute iedModel_PROT_IDMPDIF1_Beh_q;
DataAttribute iedModel_PROT_IDMPDIF1_Beh_t;

DataObject iedModel_PROT_IDMPDIF1_Health;
DataAttribute iedModel_PROT_IDMPDIF1_Health_stVal;
DataAttribute iedModel_PROT_IDMPDIF1_Health_q;
DataAttribute iedModel_PROT_IDMPDIF1_Health_t;

DataObject iedModel_PROT_IDMPDIF1_NamPlt;
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_vendor;
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_swRev;
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDMPDIF1_Op;
DataAttribute iedModel_PROT_IDMPDIF1_Op_general;
DataAttribute iedModel_PROT_IDMPDIF1_Op_q;
DataAttribute iedModel_PROT_IDMPDIF1_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDMPDIF1_Str;
DataAttribute iedModel_PROT_IDMPDIF1_Str_general;
DataAttribute iedModel_PROT_IDMPDIF1_Str_dirGeneral;
DataAttribute iedModel_PROT_IDMPDIF1_Str_q;
DataAttribute iedModel_PROT_IDMPDIF1_Str_t;

/****************************************************************
* IDMPDIF2
*****************************************************************/
LogicalNode iedModel_PROT_IDMPDIF2;

DataObject iedModel_PROT_IDMPDIF2_Mod;
DataAttribute iedModel_PROT_IDMPDIF2_Mod_q;
DataAttribute iedModel_PROT_IDMPDIF2_Mod_t;
DataAttribute iedModel_PROT_IDMPDIF2_Mod_stVal;

DataObject iedModel_PROT_IDMPDIF2_Beh;
DataAttribute iedModel_PROT_IDMPDIF2_Beh_stVal;
DataAttribute iedModel_PROT_IDMPDIF2_Beh_q;
DataAttribute iedModel_PROT_IDMPDIF2_Beh_t;

DataObject iedModel_PROT_IDMPDIF2_Health;
DataAttribute iedModel_PROT_IDMPDIF2_Health_stVal;
DataAttribute iedModel_PROT_IDMPDIF2_Health_q;
DataAttribute iedModel_PROT_IDMPDIF2_Health_t;

DataObject iedModel_PROT_IDMPDIF2_NamPlt;
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_vendor;
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_swRev;
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDMPDIF2_Op;
DataAttribute iedModel_PROT_IDMPDIF2_Op_general;
DataAttribute iedModel_PROT_IDMPDIF2_Op_q;
DataAttribute iedModel_PROT_IDMPDIF2_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDMPDIF2_Str;
DataAttribute iedModel_PROT_IDMPDIF2_Str_general;
DataAttribute iedModel_PROT_IDMPDIF2_Str_dirGeneral;
DataAttribute iedModel_PROT_IDMPDIF2_Str_q;
DataAttribute iedModel_PROT_IDMPDIF2_Str_t;

/****************************************************************
* IDMPDIF3
*****************************************************************/
LogicalNode iedModel_PROT_IDMPDIF3;

DataObject iedModel_PROT_IDMPDIF3_Mod;
DataAttribute iedModel_PROT_IDMPDIF3_Mod_q;
DataAttribute iedModel_PROT_IDMPDIF3_Mod_t;
DataAttribute iedModel_PROT_IDMPDIF3_Mod_stVal;

DataObject iedModel_PROT_IDMPDIF3_Beh;
DataAttribute iedModel_PROT_IDMPDIF3_Beh_stVal;
DataAttribute iedModel_PROT_IDMPDIF3_Beh_q;
DataAttribute iedModel_PROT_IDMPDIF3_Beh_t;

DataObject iedModel_PROT_IDMPDIF3_Health;
DataAttribute iedModel_PROT_IDMPDIF3_Health_stVal;
DataAttribute iedModel_PROT_IDMPDIF3_Health_q;
DataAttribute iedModel_PROT_IDMPDIF3_Health_t;

DataObject iedModel_PROT_IDMPDIF3_NamPlt;
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_vendor;
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_swRev;
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IDMPDIF3_Op;
DataAttribute iedModel_PROT_IDMPDIF3_Op_general;
DataAttribute iedModel_PROT_IDMPDIF3_Op_q;
DataAttribute iedModel_PROT_IDMPDIF3_Op_t;

// информация о статусе ПУСК
DataObject iedModel_PROT_IDMPDIF3_Str;
DataAttribute iedModel_PROT_IDMPDIF3_Str_general;
DataAttribute iedModel_PROT_IDMPDIF3_Str_dirGeneral;
DataAttribute iedModel_PROT_IDMPDIF3_Str_q;
DataAttribute iedModel_PROT_IDMPDIF3_Str_t;

//****************************************************************************
//
//****************************************************************************

/****************************************************************
* PTRC
*****************************************************************/
LogicalNode iedModel_CTRL_PTRC;

DataObject iedModel_CTRL_PTRC_Mod;
DataAttribute iedModel_CTRL_PTRC_Mod_q;
DataAttribute iedModel_CTRL_PTRC_Mod_t;
DataAttribute iedModel_CTRL_PTRC_Mod_stVal;
DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel;
DataObject iedModel_CTRL_PTRC_Beh;
DataAttribute iedModel_CTRL_PTRC_Beh_stVal;
DataAttribute iedModel_CTRL_PTRC_Beh_q;
DataAttribute iedModel_CTRL_PTRC_Beh_t;
DataObject iedModel_CTRL_PTRC_Health;
DataAttribute iedModel_CTRL_PTRC_Health_stVal;
DataAttribute iedModel_CTRL_PTRC_Health_q;
DataAttribute iedModel_CTRL_PTRC_Health_t;
DataObject iedModel_CTRL_PTRC_NamPlt;
DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor;
DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev;
DataAttribute iedModel_CTRL_PTRC_NamPlt_d;

DataObject iedModel_CTRL_PTRC_Op;
DataAttribute iedModel_CTRL_PTRC_Op_general;
DataAttribute iedModel_CTRL_PTRC_Op_q;
DataAttribute iedModel_CTRL_PTRC_Op_t;


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
	_swREV,//"MR901",
    &iedModel_Generic_LD0,
    &iedModelds_LD0_LLN0_dataset0,				// DataSet
    &iedModel_LD0_LLN0_report0,					// ReportControlBlock
    NULL,//&iedModel_PROT_LLN0_gse0,			// GSEControlBlock
    NULL,										// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,					// SettingGroupControlBlock
    NULL,										// lcbs
    NULL,										// log
    initializeValues
};

/*************************************************************************
 * Логические устройства LD
 *
 *************************************************************************/

LogicalDevice iedModel_Generic_LD0 = {
    LogicalDeviceModelType,
    "LD0",									// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_PROT,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_LD0_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_PROT = {
    LogicalDeviceModelType,
    "PROT",									// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_CTRL,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_PROT_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_CTRL = {
    LogicalDeviceModelType,
    "CTRL",									// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_MES,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_CTRL_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_MES = {
    LogicalDeviceModelType,
    "MES",									// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_GGIO,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_MES_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_GGIO = {
    LogicalDeviceModelType,
    "GGIO",									// имя нашего логического устройства		//"simpleIOGenericIO"
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

/*************************************************************************
 * Логический узел LD0_LPHD1
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
LogicalNode iedModel_PROT_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

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
LogicalNode iedModel_CTRL_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

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
#if defined (MR901)
LogicalNode iedModel_MES_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_MMXN1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};
#endif
#if defined (MR902)
LogicalNode iedModel_MES_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};
#endif
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
LogicalNode iedModel_GGIO_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

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
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN24GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1 /* &iedModel_GGIO_INGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_GGIO_INGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind13 = { DataObjectModelType, "Ind13", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind14 = { DataObjectModelType, "Ind14", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind15 = { DataObjectModelType, "Ind15", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind16 = { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind17 , (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind17 = { DataObjectModelType, "Ind17", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind18 = { DataObjectModelType, "Ind18", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind19 = { DataObjectModelType, "Ind19", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind20 = { DataObjectModelType, "Ind20", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind21 = { DataObjectModelType, "Ind21", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind22 = { DataObjectModelType, "Ind22", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind23 = { DataObjectModelType, "Ind23", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind24 = { DataObjectModelType, "Ind24", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)NULL, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
/*
DataObject iedModel_GGIO_INGGIO1_Ind25 = { DataObjectModelType, "Ind25", (ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*)&iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind26 = { DataObjectModelType, "Ind26", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind27 = { DataObjectModelType, "Ind27", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind28 = { DataObjectModelType, "Ind28", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind29 = { DataObjectModelType, "Ind29", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind30 = { DataObjectModelType, "Ind30", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind31 = { DataObjectModelType, "Ind31", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind32 = { DataObjectModelType, "Ind32", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind33 = { DataObjectModelType, "Ind33", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind34 = { DataObjectModelType, "Ind34", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind35 = { DataObjectModelType, "Ind35", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind36 = { DataObjectModelType, "Ind36", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind37 = { DataObjectModelType, "Ind37", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind38 = { DataObjectModelType, "Ind38", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind39 = { DataObjectModelType, "Ind39", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind40 = { DataObjectModelType, "Ind40", (ModelNode*) &iedModel_GGIO_INGGIO1, NULL, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
*/
/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/
LogicalNode iedModel_GGIO_OUTGGIO1 						= { LogicalNodeModelType,   	"OUT18GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};

DataObject iedModel_GGIO_OUTGGIO1_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod, (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
/*
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,   NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_origin,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
*/
//Beh
DataObject iedModel_GGIO_OUTGGIO1_Beh 					= {    DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q 				= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t 				= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//Health
DataObject iedModel_GGIO_OUTGGIO1_Health 					= {    DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal 		= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q 			= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t 			= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//NamPlt
DataObject iedModel_GGIO_OUTGGIO1_NamPlt 					= {    DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor 		= {    DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev 		= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d 			= {    DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_OUTGGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*)  &iedModel_GGIO_OUTGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO4 						= {    DataObjectModelType,     "SPCSO4",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO5 						= {    DataObjectModelType,     "SPCSO5",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO6 						= {    DataObjectModelType,     "SPCSO6",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO7 						= {    DataObjectModelType,     "SPCSO7",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO8 						= {    DataObjectModelType,     "SPCSO8",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO9 						= {    DataObjectModelType,     "SPCSO9",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO10 						= {    DataObjectModelType,     "SPCSO10",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO11 						= {    DataObjectModelType,     "SPCSO11",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO12 						= {    DataObjectModelType,     "SPCSO12",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO13 						= {    DataObjectModelType,     "SPCSO13",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO14 						= {    DataObjectModelType,     "SPCSO14",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO15 						= {    DataObjectModelType,     "SPCSO15",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO16 						= {    DataObjectModelType,     "SPCSO16",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO17 						= {    DataObjectModelType,     "SPCSO17",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO18 						= {    DataObjectModelType,     "SPCSO18",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
/*
DataObject iedModel_GGIO_OUTGGIO1_SPCSO19 						= {    DataObjectModelType,     "SPCSO19",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO20 						= {    DataObjectModelType,     "SPCSO20",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO21 						= {    DataObjectModelType,     "SPCSO21",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO22 						= {    DataObjectModelType,     "SPCSO22",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO23 						= {    DataObjectModelType,     "SPCSO23",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO24 						= {    DataObjectModelType,     "SPCSO24",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO25 						= {    DataObjectModelType,     "SPCSO25",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO26 						= {    DataObjectModelType,     "SPCSO26",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO27 						= {    DataObjectModelType,     "SPCSO27",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO28 						= {    DataObjectModelType,     "SPCSO28",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO29 						= {    DataObjectModelType,     "SPCSO29",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO30 						= {    DataObjectModelType,     "SPCSO30",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO31 						= {    DataObjectModelType,     "SPCSO31",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO32 						= {    DataObjectModelType,     "SPCSO32",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO33 						= {    DataObjectModelType,     "SPCSO33",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO34 						= {    DataObjectModelType,     "SPCSO34",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_NO, NULL,0};
*/
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LEDGGIO1 			= { LogicalNodeModelType,   "LED16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

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
DataObject iedModel_GGIO_LEDGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind13 = { DataObjectModelType, "Ind13", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind14 = { DataObjectModelType, "Ind14", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind15 = { DataObjectModelType, "Ind15", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind16 = { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_SPCSO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


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

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_SSLGGIO1 			= { LogicalNodeModelType,   "SSL32GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod};

DataObject iedModel_GGIO_SSLGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*)&iedModel_GGIO_SSLGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind17 = {DataObjectModelType,"Ind17",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind18 = {DataObjectModelType,"Ind18",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind19 = {DataObjectModelType,"Ind19",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind20 = {DataObjectModelType,"Ind20",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind21 = {DataObjectModelType,"Ind21",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind22 = {DataObjectModelType,"Ind22",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind23 = {DataObjectModelType,"Ind23",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind24 = {DataObjectModelType,"Ind24",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind25 = {DataObjectModelType,"Ind25",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind26 = {DataObjectModelType,"Ind26",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind27 = {DataObjectModelType,"Ind27",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind28 = {DataObjectModelType,"Ind28",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind29 = {DataObjectModelType,"Ind29",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind30 = {DataObjectModelType,"Ind30",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind31 = {DataObjectModelType,"Ind31",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind32 = {DataObjectModelType,"Ind32",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_VLSGGIO1 			= { LogicalNodeModelType,   "VLS16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod};

DataObject iedModel_GGIO_VLSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*)&iedModel_GGIO_VLSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LSGGIO1 			= { LogicalNodeModelType,   "LS16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod};

DataObject iedModel_GGIO_LSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*)&iedModel_GGIO_LSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};

/*************************************************************************
 * 5.10.7 LN: измерения Имя: MMXN1
 *************************************************************************/
#if defined (MR901)
LogicalNode iedModel_MES_MMXN1 							= { LogicalNodeModelType,    "MMXN1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)NULL,    (ModelNode*) &iedModel_MES_MMXN1_Mod};

DataObject iedModel_MES_MMXN1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MMXN1,    (ModelNode*) &iedModel_MES_MMXN1_Beh,    (ModelNode*) &iedModel_MES_MMXN1_Mod_q,0};
DataAttribute iedModel_MES_MMXN1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXN1_Mod,    (ModelNode*) &iedModel_MES_MMXN1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXN1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXN1_Mod,    (ModelNode*) &iedModel_MES_MMXN1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXN1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXN1_Mod,    (ModelNode*) &iedModel_MES_MMXN1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXN1_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXN1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXN1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXN1,    (ModelNode*) &iedModel_MES_MMXN1_Health,    (ModelNode*) &iedModel_MES_MMXN1_Beh_stVal,0};
DataAttribute iedModel_MES_MMXN1_Beh_stVal		 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXN1_Beh,    (ModelNode*) &iedModel_MES_MMXN1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXN1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXN1_Beh,    (ModelNode*) &iedModel_MES_MMXN1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXN1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXN1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXN1_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXN1,    (ModelNode*) &iedModel_MES_MMXN1_NamPlt,    (ModelNode*) &iedModel_MES_MMXN1_Health_stVal,0};
DataAttribute iedModel_MES_MMXN1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXN1_Health,    (ModelNode*) &iedModel_MES_MMXN1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXN1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXN1_Health,    (ModelNode*) &iedModel_MES_MMXN1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXN1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXN1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXN1_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXN1,    (ModelNode*) &iedModel_MES_MMXN1_Amp1, (ModelNode*) &iedModel_MES_MMXN1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXN1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXN1_NamPlt,    (ModelNode*) &iedModel_MES_MMXN1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXN1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXN1_NamPlt,    (ModelNode*) &iedModel_MES_MMXN1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXN1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXN1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// Amp1
DataObject    iedModel_MES_MMXN1_Amp1 					= { DataObjectModelType, 	"Amp1", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp2, (ModelNode*) &iedModel_MES_MMXN1_Amp1_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp1_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp1,(ModelNode*)&iedModel_MES_MMXN1_Amp1_q, (ModelNode*) &iedModel_MES_MMXN1_Amp1_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp1_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp1_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp1_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp1, (ModelNode*) &iedModel_MES_MMXN1_Amp1_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp1_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp1, (ModelNode*) &iedModel_MES_MMXN1_Amp1_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp1_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp1, (ModelNode*) &iedModel_MES_MMXN1_Amp1_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp1_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp1, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp2
DataObject    iedModel_MES_MMXN1_Amp2 					= { DataObjectModelType, 	"Amp2", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp3, (ModelNode*) &iedModel_MES_MMXN1_Amp2_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp2_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp2,(ModelNode*)&iedModel_MES_MMXN1_Amp2_q, (ModelNode*) &iedModel_MES_MMXN1_Amp2_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp2_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp2_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp2_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp2, (ModelNode*) &iedModel_MES_MMXN1_Amp2_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp2_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp2, (ModelNode*) &iedModel_MES_MMXN1_Amp2_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp2_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp2, (ModelNode*) &iedModel_MES_MMXN1_Amp2_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp2_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp2, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp3
DataObject    iedModel_MES_MMXN1_Amp3 					= { DataObjectModelType, 	"Amp3", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp4, (ModelNode*) &iedModel_MES_MMXN1_Amp3_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp3_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp3,(ModelNode*)&iedModel_MES_MMXN1_Amp3_q, (ModelNode*) &iedModel_MES_MMXN1_Amp3_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp3_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp3_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp3_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp3, (ModelNode*) &iedModel_MES_MMXN1_Amp3_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp3_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp3, (ModelNode*) &iedModel_MES_MMXN1_Amp3_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp3_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp3, (ModelNode*) &iedModel_MES_MMXN1_Amp3_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp3_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp3, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp4
DataObject    iedModel_MES_MMXN1_Amp4 					= { DataObjectModelType, 	"Amp4", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp5, (ModelNode*) &iedModel_MES_MMXN1_Amp4_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp4_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp4,(ModelNode*)&iedModel_MES_MMXN1_Amp4_q, (ModelNode*) &iedModel_MES_MMXN1_Amp4_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp4_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp4_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp4_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp4, (ModelNode*) &iedModel_MES_MMXN1_Amp4_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp4_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp4, (ModelNode*) &iedModel_MES_MMXN1_Amp4_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp4_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp4, (ModelNode*) &iedModel_MES_MMXN1_Amp4_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp4_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp4, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp5
DataObject    iedModel_MES_MMXN1_Amp5 					= { DataObjectModelType, 	"Amp5", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp6, (ModelNode*) &iedModel_MES_MMXN1_Amp5_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp5_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp5,(ModelNode*)&iedModel_MES_MMXN1_Amp5_q, (ModelNode*) &iedModel_MES_MMXN1_Amp5_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp5_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp5_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp5_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp5, (ModelNode*) &iedModel_MES_MMXN1_Amp5_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp5_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp5, (ModelNode*) &iedModel_MES_MMXN1_Amp5_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp5_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp5, (ModelNode*) &iedModel_MES_MMXN1_Amp5_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp5_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp5, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp6
DataObject    iedModel_MES_MMXN1_Amp6 					= { DataObjectModelType, 	"Amp6", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp7, (ModelNode*) &iedModel_MES_MMXN1_Amp6_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp6_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp6,(ModelNode*)&iedModel_MES_MMXN1_Amp6_q, (ModelNode*) &iedModel_MES_MMXN1_Amp6_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp6_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp6_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp6_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp6, (ModelNode*) &iedModel_MES_MMXN1_Amp6_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp6_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp6, (ModelNode*) &iedModel_MES_MMXN1_Amp6_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp6_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp6, (ModelNode*) &iedModel_MES_MMXN1_Amp6_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp6_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp6, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp7
DataObject    iedModel_MES_MMXN1_Amp7 					= { DataObjectModelType, 	"Amp7", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp8, (ModelNode*) &iedModel_MES_MMXN1_Amp7_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp7_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp7,(ModelNode*)&iedModel_MES_MMXN1_Amp7_q, (ModelNode*) &iedModel_MES_MMXN1_Amp7_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp7_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp7_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp7_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp7, (ModelNode*) &iedModel_MES_MMXN1_Amp7_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp7_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp7, (ModelNode*) &iedModel_MES_MMXN1_Amp7_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp7_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp7, (ModelNode*) &iedModel_MES_MMXN1_Amp7_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp7_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp7, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp8
DataObject    iedModel_MES_MMXN1_Amp8 					= { DataObjectModelType, 	"Amp8", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp9, (ModelNode*) &iedModel_MES_MMXN1_Amp8_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp8_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp8,(ModelNode*)&iedModel_MES_MMXN1_Amp8_q, (ModelNode*) &iedModel_MES_MMXN1_Amp8_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp8_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp8_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp8_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp8, (ModelNode*) &iedModel_MES_MMXN1_Amp8_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp8_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp8, (ModelNode*) &iedModel_MES_MMXN1_Amp8_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp8_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp8, (ModelNode*) &iedModel_MES_MMXN1_Amp8_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp8_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp8, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp9
DataObject    iedModel_MES_MMXN1_Amp9 					= { DataObjectModelType, 	"Amp9", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp10, (ModelNode*) &iedModel_MES_MMXN1_Amp9_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp9_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp9,(ModelNode*)&iedModel_MES_MMXN1_Amp9_q, (ModelNode*) &iedModel_MES_MMXN1_Amp9_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp9_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp9_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp9_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp9, (ModelNode*) &iedModel_MES_MMXN1_Amp9_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp9_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp9, (ModelNode*) &iedModel_MES_MMXN1_Amp9_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp9_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp9, (ModelNode*) &iedModel_MES_MMXN1_Amp9_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp9_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp9, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp10
DataObject    iedModel_MES_MMXN1_Amp10 					= { DataObjectModelType, 	"Amp10", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp11, (ModelNode*) &iedModel_MES_MMXN1_Amp10_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp10_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp10,(ModelNode*)&iedModel_MES_MMXN1_Amp10_q, (ModelNode*) &iedModel_MES_MMXN1_Amp10_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp10_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp10_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp10_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp10, (ModelNode*) &iedModel_MES_MMXN1_Amp10_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp10_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp10, (ModelNode*) &iedModel_MES_MMXN1_Amp10_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp10_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp10, (ModelNode*) &iedModel_MES_MMXN1_Amp10_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp10_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp10, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp11
DataObject    iedModel_MES_MMXN1_Amp11 					= { DataObjectModelType, 	"Amp11", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp12, (ModelNode*) &iedModel_MES_MMXN1_Amp11_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp11_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp11,(ModelNode*)&iedModel_MES_MMXN1_Amp11_q, (ModelNode*) &iedModel_MES_MMXN1_Amp11_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp11_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp11_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp11_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp11, (ModelNode*) &iedModel_MES_MMXN1_Amp11_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp11_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp11, (ModelNode*) &iedModel_MES_MMXN1_Amp11_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp11_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp11, (ModelNode*) &iedModel_MES_MMXN1_Amp11_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp11_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp11, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp12
DataObject    iedModel_MES_MMXN1_Amp12 					= { DataObjectModelType, 	"Amp12", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp13, (ModelNode*) &iedModel_MES_MMXN1_Amp12_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp12_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp12,(ModelNode*)&iedModel_MES_MMXN1_Amp12_q, (ModelNode*) &iedModel_MES_MMXN1_Amp12_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp12_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp12_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp12_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp12, (ModelNode*) &iedModel_MES_MMXN1_Amp12_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp12_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp12, (ModelNode*) &iedModel_MES_MMXN1_Amp12_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp12_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp12, (ModelNode*) &iedModel_MES_MMXN1_Amp12_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp12_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp12, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp13
DataObject    iedModel_MES_MMXN1_Amp13 					= { DataObjectModelType, 	"Amp13", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp14, (ModelNode*) &iedModel_MES_MMXN1_Amp13_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp13_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp13,(ModelNode*)&iedModel_MES_MMXN1_Amp13_q, (ModelNode*) &iedModel_MES_MMXN1_Amp13_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp13_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp13_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp13_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp13, (ModelNode*) &iedModel_MES_MMXN1_Amp13_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp13_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp13, (ModelNode*) &iedModel_MES_MMXN1_Amp13_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp13_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp13, (ModelNode*) &iedModel_MES_MMXN1_Amp13_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp13_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp13, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp14
DataObject    iedModel_MES_MMXN1_Amp14 					= { DataObjectModelType, 	"Amp14", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp15, (ModelNode*) &iedModel_MES_MMXN1_Amp14_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp14_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp14,(ModelNode*)&iedModel_MES_MMXN1_Amp14_q, (ModelNode*) &iedModel_MES_MMXN1_Amp14_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp14_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp14_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp14_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp14, (ModelNode*) &iedModel_MES_MMXN1_Amp14_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp14_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp14, (ModelNode*) &iedModel_MES_MMXN1_Amp14_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp14_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp14, (ModelNode*) &iedModel_MES_MMXN1_Amp14_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp14_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp14, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp15
DataObject    iedModel_MES_MMXN1_Amp15 					= { DataObjectModelType, 	"Amp15", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)&iedModel_MES_MMXN1_Amp16, (ModelNode*) &iedModel_MES_MMXN1_Amp15_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp15_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp15,(ModelNode*)&iedModel_MES_MMXN1_Amp15_q, (ModelNode*) &iedModel_MES_MMXN1_Amp15_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp15_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp15_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp15_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp15, (ModelNode*) &iedModel_MES_MMXN1_Amp15_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp15_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp15, (ModelNode*) &iedModel_MES_MMXN1_Amp15_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp15_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp15, (ModelNode*) &iedModel_MES_MMXN1_Amp15_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp15_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp15, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
// Amp16
DataObject    iedModel_MES_MMXN1_Amp16 					= { DataObjectModelType, 	"Amp16", (ModelNode*) &iedModel_MES_MMXN1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXN1_Amp16_mag, 0 };
DataAttribute iedModel_MES_MMXN1_Amp16_mag 				= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXN1_Amp16,(ModelNode*)&iedModel_MES_MMXN1_Amp16_q, (ModelNode*) &iedModel_MES_MMXN1_Amp16_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp16_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXN1_Amp16_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp16_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXN1_Amp16, (ModelNode*) &iedModel_MES_MMXN1_Amp16_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXN1_Amp16_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXN1_Amp16, (ModelNode*) &iedModel_MES_MMXN1_Amp16_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp16_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXN1_Amp16, (ModelNode*) &iedModel_MES_MMXN1_Amp16_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXN1_Amp16_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXN1_Amp16, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
#endif

#if defined (MR902)
/*************************************************************************
 * 5.10.7 LN: измерения Имя: MMXU1
 *
 *************************************************************************/
LogicalNode iedModel_MES_MMXU1 							= {    LogicalNodeModelType,    "MMXU1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_MMXU2,    (ModelNode*) &iedModel_MES_MMXU1_Mod};

DataObject iedModel_MES_MMXU1_Mod 						= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Mod_q,0};
DataAttribute iedModel_MES_MMXU1_Mod_q 					= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_t 					= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Beh 						= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU1_Beh_stVal		 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_q 					= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_t 					= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Health 					= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_MMXU1_Health_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_NamPlt 					= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*) &iedModel_MES_MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor 			= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev 			= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_d 				= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// MMXU1 A
DataObject iedModel_MES_MMXU1_A 						= { DataObjectModelType, "A", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsA, 0 };
DataObject iedModel_MES_MMXU1_A_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_MES_MMXU1_A_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*)&iedModel_MES_MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_MES_MMXU1_A_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_q, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


/*************************************************************************
 * 5.10.7 LN: измерения Имя: MMXU2
 *
 *************************************************************************/
LogicalNode iedModel_MES_MMXU2 = {    LogicalNodeModelType,    "MMXU2",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_MMXU3,    (ModelNode*) &iedModel_MES_MMXU2_Mod};

DataObject iedModel_MES_MMXU2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MMXU2,    (ModelNode*) &iedModel_MES_MMXU2_Beh,    (ModelNode*) &iedModel_MES_MMXU2_Mod_q,0};
DataAttribute iedModel_MES_MMXU2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU2_Mod,    (ModelNode*) &iedModel_MES_MMXU2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU2_Mod,    (ModelNode*) &iedModel_MES_MMXU2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU2_Mod,    (ModelNode*) &iedModel_MES_MMXU2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU2,    (ModelNode*) &iedModel_MES_MMXU2_Health,    (ModelNode*) &iedModel_MES_MMXU2_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU2_Beh,    (ModelNode*) &iedModel_MES_MMXU2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU2_Beh,    (ModelNode*) &iedModel_MES_MMXU2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU2,    (ModelNode*) &iedModel_MES_MMXU2_NamPlt,    (ModelNode*) &iedModel_MES_MMXU2_Health_stVal,0};
DataAttribute iedModel_MES_MMXU2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU2_Health,    (ModelNode*) &iedModel_MES_MMXU2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU2_Health,    (ModelNode*) &iedModel_MES_MMXU2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU2,    (ModelNode*) &iedModel_MES_MMXU2_A, (ModelNode*) &iedModel_MES_MMXU2_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU2_NamPlt,    (ModelNode*) &iedModel_MES_MMXU2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU2_NamPlt,    (ModelNode*) &iedModel_MES_MMXU2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// MMXU2 A
DataObject iedModel_MES_MMXU2_A 						= { DataObjectModelType, "A", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU2_A_phsA, 0 };
DataObject iedModel_MES_MMXU2_A_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU2_A_phsB, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU2_A_phsA, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_q, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU2_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU2_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU2_A_phsA, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU2_A_phsA, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU2_A_phsA, (ModelNode*) &iedModel_MES_MMXU2_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU2_A_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU2_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_MES_MMXU2_A_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU2_A_phsC, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU2_A_phsB, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_q, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU2_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU2_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU2_A_phsB, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU2_A_phsB, (ModelNode*)&iedModel_MES_MMXU2_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU2_A_phsB, (ModelNode*) &iedModel_MES_MMXU2_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU2_A_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU2_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_MES_MMXU2_A_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU2_A_phsC, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_q, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU2_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU2_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU2_A_phsC, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU2_A_phsC,  (ModelNode*) &iedModel_MES_MMXU2_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU2_A_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU2_A_phsC, (ModelNode*) &iedModel_MES_MMXU2_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU2_A_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU2_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// MMXU3
LogicalNode iedModel_MES_MMXU3 = {    LogicalNodeModelType,    "MMXU3",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)NULL,    (ModelNode*) &iedModel_MES_MMXU3_Mod};

DataObject iedModel_MES_MMXU3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MMXU3,    (ModelNode*) &iedModel_MES_MMXU3_Beh,    (ModelNode*) &iedModel_MES_MMXU3_Mod_q,0};
DataAttribute iedModel_MES_MMXU3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU3_Mod,    (ModelNode*) &iedModel_MES_MMXU3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU3_Mod,    (ModelNode*) &iedModel_MES_MMXU3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_MES_MMXU3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU3_Mod,    (ModelNode*) &iedModel_MES_MMXU3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU3,    (ModelNode*) &iedModel_MES_MMXU3_Health,    (ModelNode*) &iedModel_MES_MMXU3_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU3_Beh,    (ModelNode*) &iedModel_MES_MMXU3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU3_Beh,    (ModelNode*) &iedModel_MES_MMXU3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU3,    (ModelNode*) &iedModel_MES_MMXU3_NamPlt,    (ModelNode*) &iedModel_MES_MMXU3_Health_stVal,0};
DataAttribute iedModel_MES_MMXU3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU3_Health,    (ModelNode*) &iedModel_MES_MMXU3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU3_Health,    (ModelNode*) &iedModel_MES_MMXU3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU3,    (ModelNode*) &iedModel_MES_MMXU3_A, (ModelNode*) &iedModel_MES_MMXU3_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU3_NamPlt,    (ModelNode*) &iedModel_MES_MMXU3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU3_NamPlt,    (ModelNode*) &iedModel_MES_MMXU3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU3_A 						= { DataObjectModelType, "A", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU3_A_In, 0 };

DataObject iedModel_MES_MMXU3_A_In 					= { DataObjectModelType, "In", (ModelNode*) &iedModel_MES_MMXU3_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU3_A_In_cVal, 0 };
DataAttribute iedModel_MES_MMXU3_A_In_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU3_A_In, (ModelNode*) &iedModel_MES_MMXU3_A_In_q, (ModelNode*) &iedModel_MES_MMXU3_A_In_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU3_A_In_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU3_A_In_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU3_A_In_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU3_A_In_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU3_A_In_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU3_A_In_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU3_A_In, (ModelNode*) &iedModel_MES_MMXU3_A_In_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU3_A_In_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU3_A_In, (ModelNode*) &iedModel_MES_MMXU3_A_In_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU3_A_In_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU3_A_In, (ModelNode*) &iedModel_MES_MMXU3_A_In_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU3_A_In_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU3_A_In, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


#endif
/*************************************************************************
 *   5.4.2 LN: Дифференциальная защита Имя: PDIF
 *
 *************************************************************************/
#if defined (MR902)
//-IDPDIF1--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF1 					= {    LogicalNodeModelType,    "IDPDIF1",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod};

DataObject iedModel_PROT_IDPDIF1_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Op, (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF1,  	(ModelNode*)&iedModel_PROT_IDPDIF1_Str, (ModelNode*) &iedModel_PROT_IDPDIF1_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDPDIF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDPDIF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_Str 	 			= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF1,  (ModelNode*)&iedModel_PROT_IDPDIF1_RstA, (ModelNode*) &iedModel_PROT_IDPDIF1_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_general 		= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral 	= {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_q 			= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_t 			= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_RstA 						= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF1, (ModelNode*)&iedModel_PROT_IDPDIF1_DifACIc, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, 0 };
DataObject iedModel_PROT_IDPDIF1_RstA_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA, (ModelNode*)&iedModel_PROT_IDPDIF1_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF1_RstA_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA, (ModelNode*)&iedModel_PROT_IDPDIF1_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB, (ModelNode*)&iedModel_PROT_IDPDIF1_RstA_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF1_RstA_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF1_DifACIc 					= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF1, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, 0 };
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA 				= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF1_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsB 				= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF1_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB, (ModelNode*)&iedModel_PROT_IDPDIF1_DifACIc_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF1_DifACIc_phsC 				= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//-IDPDIF2--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF2 					= {    LogicalNodeModelType,    "IDPDIF2",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod};

DataObject iedModel_PROT_IDPDIF2_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Op, (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF2,  	(ModelNode*)&iedModel_PROT_IDPDIF2_Str, (ModelNode*) &iedModel_PROT_IDPDIF2_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDPDIF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDPDIF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_Str 	 			= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF2,  (ModelNode*)&iedModel_PROT_IDPDIF2_RstA, (ModelNode*) &iedModel_PROT_IDPDIF2_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_general 		= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral 	= {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_q 			= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_t 			= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_RstA 						= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF2, (ModelNode*)&iedModel_PROT_IDPDIF2_DifACIc, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, 0 };
DataObject iedModel_PROT_IDPDIF2_RstA_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA, (ModelNode*)&iedModel_PROT_IDPDIF2_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF2_RstA_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA, (ModelNode*)&iedModel_PROT_IDPDIF2_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB, (ModelNode*)&iedModel_PROT_IDPDIF2_RstA_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF2_RstA_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF2_DifACIc 					= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF2, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, 0 };
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA 				= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF2_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsB 				= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF2_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB, (ModelNode*)&iedModel_PROT_IDPDIF2_DifACIc_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF2_DifACIc_phsC 				= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//-IDPDIF3--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF3 					= {    LogicalNodeModelType,    "IDPDIF3",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod};

DataObject iedModel_PROT_IDPDIF3_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Op, (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF3,  	(ModelNode*)&iedModel_PROT_IDPDIF3_Str, (ModelNode*) &iedModel_PROT_IDPDIF3_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDPDIF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDPDIF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_Str 	 			= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF3,  (ModelNode*)&iedModel_PROT_IDPDIF3_RstA, (ModelNode*) &iedModel_PROT_IDPDIF3_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_general 		= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral 	= {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_q 			= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_t 			= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_RstA 						= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF3, (ModelNode*)&iedModel_PROT_IDPDIF3_DifACIc, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, 0 };
DataObject iedModel_PROT_IDPDIF3_RstA_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA, (ModelNode*)&iedModel_PROT_IDPDIF3_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF3_RstA_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA, (ModelNode*)&iedModel_PROT_IDPDIF3_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB, (ModelNode*)&iedModel_PROT_IDPDIF3_RstA_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF3_RstA_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF3_DifACIc 					= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF3, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, 0 };
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA 				= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF3_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsB 				= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF3_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB, (ModelNode*)&iedModel_PROT_IDPDIF3_DifACIc_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataObject iedModel_PROT_IDPDIF3_DifACIc_phsC 				= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

#endif

#if defined (MR901)
//-IDPDIF1--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF1 							= { LogicalNodeModelType,    "IDPDIF1",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod};

DataObject iedModel_PROT_IDPDIF1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Mod_ctlModel 			= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF1_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDPDIF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF1_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF1_Op, (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF1,  	(ModelNode*)&iedModel_PROT_IDPDIF1_Str, (ModelNode*) &iedModel_PROT_IDPDIF1_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_general 				= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDPDIF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDPDIF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF1_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF1,  (ModelNode*)&iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral 			= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDPDIF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF1_RstA_phsA 					= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF1, (ModelNode*)&iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA 				= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF1, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db 		= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb 	= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF1_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


//-IDPDIF2--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF2 							= { LogicalNodeModelType,    "IDPDIF2",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod};

DataObject iedModel_PROT_IDPDIF2_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF2_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF2_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDPDIF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF2_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF2,    (ModelNode*) &iedModel_PROT_IDPDIF2_Op, (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF2,  	(ModelNode*)&iedModel_PROT_IDPDIF2_Str, (ModelNode*) &iedModel_PROT_IDPDIF2_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_general 				= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDPDIF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDPDIF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF2_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF2,  (ModelNode*)&iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral 			= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDPDIF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF2_RstA_phsA 					= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF2, (ModelNode*)&iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA 				= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF2, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db 		= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb 	= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF2_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


//-IDPDIF3--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDPDIF3 							= { LogicalNodeModelType,    "IDPDIF3",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod};

DataObject iedModel_PROT_IDPDIF3_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Mod_ctlModel 			= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF3_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF3_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDPDIF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF3_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF3,    (ModelNode*) &iedModel_PROT_IDPDIF3_Op, (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF3,  	(ModelNode*)&iedModel_PROT_IDPDIF3_Str, (ModelNode*) &iedModel_PROT_IDPDIF3_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_general 				= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDPDIF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDPDIF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IDPDIF3_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF3,  (ModelNode*)&iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral 			= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDPDIF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF3_RstA_phsA 					= { DataObjectModelType, "RstA", (ModelNode*) &iedModel_PROT_IDPDIF3, (ModelNode*)&iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA 				= { DataObjectModelType, "DifACIc", (ModelNode*) &iedModel_PROT_IDPDIF3, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal 		= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db 		= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb 	= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF3_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

#endif

//-IDMPDIF1--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDMPDIF1 							= { LogicalNodeModelType,    "IDMPDIF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IDMPDIF2,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod};

DataObject iedModel_PROT_IDMPDIF1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod_q,0};
DataAttribute iedModel_PROT_IDMPDIF1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF1_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF1_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF1_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDMPDIF1,    (ModelNode*) &iedModel_PROT_IDMPDIF1_Op, (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDMPDIF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF1_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDMPDIF1,  	(ModelNode*)&iedModel_PROT_IDMPDIF1_Str, (ModelNode*) &iedModel_PROT_IDMPDIF1_Op_general,0};
DataAttribute iedModel_PROT_IDMPDIF1_Op_general 			= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDMPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF1_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDMPDIF1,  NULL, (ModelNode*) &iedModel_PROT_IDMPDIF1_Str_general,0};
DataAttribute iedModel_PROT_IDMPDIF1_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDMPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Str_dirGeneral 		= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDMPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF1_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDMPDIF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//-IDMPDIF2--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDMPDIF2 							= { LogicalNodeModelType,    "IDMPDIF2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IDMPDIF3,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod};

DataObject iedModel_PROT_IDMPDIF2_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDMPDIF2,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod_q,0};
DataAttribute iedModel_PROT_IDMPDIF2_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF2_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDMPDIF2,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF2_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF2_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDMPDIF2,    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF2_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF2_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDMPDIF2,    (ModelNode*) &iedModel_PROT_IDMPDIF2_Op, (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDMPDIF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF2_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDMPDIF2,  	(ModelNode*)&iedModel_PROT_IDMPDIF2_Str, (ModelNode*) &iedModel_PROT_IDMPDIF2_Op_general,0};
DataAttribute iedModel_PROT_IDMPDIF2_Op_general 			= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDMPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF2_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDMPDIF2,  NULL, (ModelNode*) &iedModel_PROT_IDMPDIF2_Str_general,0};
DataAttribute iedModel_PROT_IDMPDIF2_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDMPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Str_dirGeneral 		= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDMPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF2_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDMPDIF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//-IDMPDIF3--------------------------------------------------------------------------
LogicalNode iedModel_PROT_IDMPDIF3 							= { LogicalNodeModelType,    "IDMPDIF3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod};

DataObject iedModel_PROT_IDMPDIF3_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDMPDIF3,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod_q,0};
DataAttribute iedModel_PROT_IDMPDIF3_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF3_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDMPDIF3,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF3_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF3_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDMPDIF3,    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health_stVal,0};
DataAttribute iedModel_PROT_IDMPDIF3_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF3_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDMPDIF3,    (ModelNode*) &iedModel_PROT_IDMPDIF3_Op, (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDMPDIF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF3_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDMPDIF3,  	(ModelNode*)&iedModel_PROT_IDMPDIF3_Str, (ModelNode*) &iedModel_PROT_IDMPDIF3_Op_general,0};
DataAttribute iedModel_PROT_IDMPDIF3_Op_general 			= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDMPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Op,  (ModelNode*) &iedModel_PROT_IDMPDIF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDMPDIF3_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDMPDIF3,  NULL, (ModelNode*) &iedModel_PROT_IDMPDIF3_Str_general,0};
DataAttribute iedModel_PROT_IDMPDIF3_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDMPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Str_dirGeneral 		= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDMPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Str,  (ModelNode*) &iedModel_PROT_IDMPDIF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDMPDIF3_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDMPDIF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


/*******************************************************
 * IPTOC1
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC1 				= {    LogicalNodeModelType,    "IPTOC1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod};

DataObject iedModel_PROT_IPTOC1_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC1_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC1_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC1_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Str, (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC1,  	(ModelNode*)&iedModel_PROT_IPTOC1_Op, (ModelNode*) &iedModel_PROT_IPTOC1_Str_general,0};
DataAttribute iedModel_PROT_IPTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC1_Op_general,0};
DataAttribute iedModel_PROT_IPTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC1_Op,  (ModelNode*) &iedModel_PROT_IPTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC1_Op,  (ModelNode*) &iedModel_PROT_IPTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


LogicalNode iedModel_PROT_IPTOC2 = {    LogicalNodeModelType,    "IPTOC2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod};

DataObject iedModel_PROT_IPTOC2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Str, (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)&iedModel_PROT_IPTOC2_Op, (ModelNode*) &iedModel_PROT_IPTOC2_Str_general,0};
DataAttribute iedModel_PROT_IPTOC2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC2_Op_general,0};
DataAttribute iedModel_PROT_IPTOC2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

LogicalNode iedModel_PROT_IPTOC3 = {    LogicalNodeModelType,    "IPTOC3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod};

DataObject iedModel_PROT_IPTOC3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Str, (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)&iedModel_PROT_IPTOC3_Op, (ModelNode*) &iedModel_PROT_IPTOC3_Str_general,0};
DataAttribute iedModel_PROT_IPTOC3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC3_Op_general,0};
DataAttribute iedModel_PROT_IPTOC3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// ------- IPTOC4 -------------------
LogicalNode iedModel_PROT_IPTOC4 = {    LogicalNodeModelType,    "IPTOC4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod};

DataObject iedModel_PROT_IPTOC4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Str, (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)&iedModel_PROT_IPTOC4_Op, (ModelNode*) &iedModel_PROT_IPTOC4_Str_general,0};
DataAttribute iedModel_PROT_IPTOC4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC4_Op_general,0};
DataAttribute iedModel_PROT_IPTOC4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// ------- IPTOC5 -------------------
LogicalNode iedModel_PROT_IPTOC5 = {    LogicalNodeModelType,    "IPTOC5",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod};

DataObject iedModel_PROT_IPTOC5_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC5_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC5_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC5_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC5_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Str, (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC5_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC5,  	(ModelNode*)&iedModel_PROT_IPTOC5_Op, (ModelNode*) &iedModel_PROT_IPTOC5_Str_general,0};
DataAttribute iedModel_PROT_IPTOC5_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC5_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC5_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC5,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC5_Op_general,0};
DataAttribute iedModel_PROT_IPTOC5_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC5_Op,  (ModelNode*) &iedModel_PROT_IPTOC5_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC5_Op,  (ModelNode*) &iedModel_PROT_IPTOC5_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC5_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// ------- IPTOC6 -------------------
LogicalNode iedModel_PROT_IPTOC6 = {    LogicalNodeModelType,    "IPTOC6",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC7,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod};

DataObject iedModel_PROT_IPTOC6_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC6_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC6_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC6_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC6_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC6_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Str, (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC6_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC6,  	(ModelNode*)&iedModel_PROT_IPTOC6_Op, (ModelNode*) &iedModel_PROT_IPTOC6_Str_general,0};
DataAttribute iedModel_PROT_IPTOC6_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC6_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC6_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC6,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC6_Op_general,0};
DataAttribute iedModel_PROT_IPTOC6_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC6_Op,  (ModelNode*) &iedModel_PROT_IPTOC6_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC6_Op,  (ModelNode*) &iedModel_PROT_IPTOC6_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC6_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


// ------- IPTOC7 -------------------
LogicalNode iedModel_PROT_IPTOC7 = {    LogicalNodeModelType,    "IPTOC7",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC8,    (ModelNode*) &iedModel_PROT_IPTOC7_Mod};

DataObject iedModel_PROT_IPTOC7_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC7,    (ModelNode*) &iedModel_PROT_IPTOC7_Beh,    (ModelNode*) &iedModel_PROT_IPTOC7_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC7_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC7_Mod,    (ModelNode*) &iedModel_PROT_IPTOC7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC7_Mod,    (ModelNode*) &iedModel_PROT_IPTOC7_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC7_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_IPTOC7_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC7_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC7_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC7,    (ModelNode*) &iedModel_PROT_IPTOC7_Health,    (ModelNode*) &iedModel_PROT_IPTOC7_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC7_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC7_Beh,    (ModelNode*) &iedModel_PROT_IPTOC7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC7_Beh,    (ModelNode*) &iedModel_PROT_IPTOC7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC7_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC7_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC7,    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC7_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC7_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC7_Health,    (ModelNode*) &iedModel_PROT_IPTOC7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC7_Health,    (ModelNode*) &iedModel_PROT_IPTOC7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC7_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC7_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC7,    (ModelNode*) &iedModel_PROT_IPTOC7_Str, (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC7_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC7_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC7,  	(ModelNode*)&iedModel_PROT_IPTOC7_Op, (ModelNode*) &iedModel_PROT_IPTOC7_Str_general,0};
DataAttribute iedModel_PROT_IPTOC7_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC7_Str,  (ModelNode*) &iedModel_PROT_IPTOC7_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC7_Str,  (ModelNode*) &iedModel_PROT_IPTOC7_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC7_Str,  (ModelNode*) &iedModel_PROT_IPTOC7_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC7_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC7_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC7,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC7_Op_general,0};
DataAttribute iedModel_PROT_IPTOC7_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC7_Op,  (ModelNode*) &iedModel_PROT_IPTOC7_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC7_Op,  (ModelNode*) &iedModel_PROT_IPTOC7_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC7_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC7_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//-------------------------------------------------------
// IPTOC8
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC8 				= {    LogicalNodeModelType,    "IPTOC8",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC9,    (ModelNode*) &iedModel_PROT_IPTOC8_Mod};

DataObject iedModel_PROT_IPTOC8_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC8,    (ModelNode*) &iedModel_PROT_IPTOC8_Beh,    (ModelNode*) &iedModel_PROT_IPTOC8_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC8_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC8_Mod,    (ModelNode*) &iedModel_PROT_IPTOC8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC8_Mod,    (ModelNode*) &iedModel_PROT_IPTOC8_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC8_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC8_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC8,    (ModelNode*) &iedModel_PROT_IPTOC8_Health,    (ModelNode*) &iedModel_PROT_IPTOC8_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC8_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC8_Beh,    (ModelNode*) &iedModel_PROT_IPTOC8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC8_Beh,    (ModelNode*) &iedModel_PROT_IPTOC8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC8_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC8_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC8,    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC8_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC8_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC8_Health,    (ModelNode*) &iedModel_PROT_IPTOC8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC8_Health,    (ModelNode*) &iedModel_PROT_IPTOC8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC8_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC8_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC8,    (ModelNode*) &iedModel_PROT_IPTOC8_Str, (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC8_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC8_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC8,  	(ModelNode*)&iedModel_PROT_IPTOC8_Op, (ModelNode*) &iedModel_PROT_IPTOC8_Str_general,0};
DataAttribute iedModel_PROT_IPTOC8_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC8_Str,  (ModelNode*) &iedModel_PROT_IPTOC8_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC8_Str,  (ModelNode*) &iedModel_PROT_IPTOC8_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC8_Str,  (ModelNode*) &iedModel_PROT_IPTOC8_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC8_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC8_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC8,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC8_Op_general,0};
DataAttribute iedModel_PROT_IPTOC8_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC8_Op,  (ModelNode*) &iedModel_PROT_IPTOC8_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC8_Op,  (ModelNode*) &iedModel_PROT_IPTOC8_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC8_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC8_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC9
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC9 				= {    LogicalNodeModelType,    "IPTOC9",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC10,    (ModelNode*) &iedModel_PROT_IPTOC9_Mod};

DataObject iedModel_PROT_IPTOC9_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC9,    (ModelNode*) &iedModel_PROT_IPTOC9_Beh,    (ModelNode*) &iedModel_PROT_IPTOC9_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC9_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC9_Mod,    (ModelNode*) &iedModel_PROT_IPTOC9_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC9_Mod,    (ModelNode*) &iedModel_PROT_IPTOC9_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC9_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC9_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC9,    (ModelNode*) &iedModel_PROT_IPTOC9_Health,    (ModelNode*) &iedModel_PROT_IPTOC9_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC9_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC9_Beh,    (ModelNode*) &iedModel_PROT_IPTOC9_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC9_Beh,    (ModelNode*) &iedModel_PROT_IPTOC9_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC9_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC9_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC9,    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC9_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC9_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC9_Health,    (ModelNode*) &iedModel_PROT_IPTOC9_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC9_Health,    (ModelNode*) &iedModel_PROT_IPTOC9_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC9_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC9_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC9,    (ModelNode*) &iedModel_PROT_IPTOC9_Str, (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC9_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC9_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC9_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC9,  	(ModelNode*)&iedModel_PROT_IPTOC9_Op, (ModelNode*) &iedModel_PROT_IPTOC9_Str_general,0};
DataAttribute iedModel_PROT_IPTOC9_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC9_Str,  (ModelNode*) &iedModel_PROT_IPTOC9_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC9_Str,  (ModelNode*) &iedModel_PROT_IPTOC9_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC9_Str,  (ModelNode*) &iedModel_PROT_IPTOC9_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC9_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC9_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC9,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC9_Op_general,0};
DataAttribute iedModel_PROT_IPTOC9_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC9_Op,  (ModelNode*) &iedModel_PROT_IPTOC9_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC9_Op,  (ModelNode*) &iedModel_PROT_IPTOC9_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC9_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC9_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC10
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC10 				= {    LogicalNodeModelType,    "IPTOC10",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC11,    (ModelNode*) &iedModel_PROT_IPTOC10_Mod};

DataObject iedModel_PROT_IPTOC10_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC10,    (ModelNode*) &iedModel_PROT_IPTOC10_Beh,    (ModelNode*) &iedModel_PROT_IPTOC10_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC10_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC10_Mod,    (ModelNode*) &iedModel_PROT_IPTOC10_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC10_Mod,    (ModelNode*) &iedModel_PROT_IPTOC10_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC10_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC10_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC10,    (ModelNode*) &iedModel_PROT_IPTOC10_Health,    (ModelNode*) &iedModel_PROT_IPTOC10_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC10_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC10_Beh,    (ModelNode*) &iedModel_PROT_IPTOC10_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC10_Beh,    (ModelNode*) &iedModel_PROT_IPTOC10_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC10_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC10_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC10,    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC10_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC10_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC10_Health,    (ModelNode*) &iedModel_PROT_IPTOC10_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC10_Health,    (ModelNode*) &iedModel_PROT_IPTOC10_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC10_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC10_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC10,    (ModelNode*) &iedModel_PROT_IPTOC10_Str, (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC10_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC10_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC10_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC10,  	(ModelNode*)&iedModel_PROT_IPTOC10_Op, (ModelNode*) &iedModel_PROT_IPTOC10_Str_general,0};
DataAttribute iedModel_PROT_IPTOC10_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC10_Str,  (ModelNode*) &iedModel_PROT_IPTOC10_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC10_Str,  (ModelNode*) &iedModel_PROT_IPTOC10_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC10_Str,  (ModelNode*) &iedModel_PROT_IPTOC10_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC10_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC10_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC10,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC10_Op_general,0};
DataAttribute iedModel_PROT_IPTOC10_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC10_Op,  (ModelNode*) &iedModel_PROT_IPTOC10_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC10_Op,  (ModelNode*) &iedModel_PROT_IPTOC10_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC10_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC10_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC11
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC11 				= {    LogicalNodeModelType,    "IPTOC11",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC12,    (ModelNode*) &iedModel_PROT_IPTOC11_Mod};

DataObject iedModel_PROT_IPTOC11_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC11,    (ModelNode*) &iedModel_PROT_IPTOC11_Beh,    (ModelNode*) &iedModel_PROT_IPTOC11_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC11_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC11_Mod,    (ModelNode*) &iedModel_PROT_IPTOC11_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC11_Mod,    (ModelNode*) &iedModel_PROT_IPTOC11_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC11_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC11_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC11,    (ModelNode*) &iedModel_PROT_IPTOC11_Health,    (ModelNode*) &iedModel_PROT_IPTOC11_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC11_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC11_Beh,    (ModelNode*) &iedModel_PROT_IPTOC11_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC11_Beh,    (ModelNode*) &iedModel_PROT_IPTOC11_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC11_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC11_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC11,    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC11_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC11_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC11_Health,    (ModelNode*) &iedModel_PROT_IPTOC11_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC11_Health,    (ModelNode*) &iedModel_PROT_IPTOC11_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC11_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC11_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC11,    (ModelNode*) &iedModel_PROT_IPTOC11_Str, (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC11_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC11_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC11_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC11,  	(ModelNode*)&iedModel_PROT_IPTOC11_Op, (ModelNode*) &iedModel_PROT_IPTOC11_Str_general,0};
DataAttribute iedModel_PROT_IPTOC11_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC11_Str,  (ModelNode*) &iedModel_PROT_IPTOC11_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC11_Str,  (ModelNode*) &iedModel_PROT_IPTOC11_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC11_Str,  (ModelNode*) &iedModel_PROT_IPTOC11_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC11_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC11_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC11,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC11_Op_general,0};
DataAttribute iedModel_PROT_IPTOC11_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC11_Op,  (ModelNode*) &iedModel_PROT_IPTOC11_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC11_Op,  (ModelNode*) &iedModel_PROT_IPTOC11_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC11_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC11_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC12
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC12 				= {    LogicalNodeModelType,    "IPTOC12",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC13,    (ModelNode*) &iedModel_PROT_IPTOC12_Mod};

DataObject iedModel_PROT_IPTOC12_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC12,    (ModelNode*) &iedModel_PROT_IPTOC12_Beh,    (ModelNode*) &iedModel_PROT_IPTOC12_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC12_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC12_Mod,    (ModelNode*) &iedModel_PROT_IPTOC12_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC12_Mod,    (ModelNode*) &iedModel_PROT_IPTOC12_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC12_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC12_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC12,    (ModelNode*) &iedModel_PROT_IPTOC12_Health,    (ModelNode*) &iedModel_PROT_IPTOC12_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC12_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC12_Beh,    (ModelNode*) &iedModel_PROT_IPTOC12_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC12_Beh,    (ModelNode*) &iedModel_PROT_IPTOC12_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC12_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC12_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC12,    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC12_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC12_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC12_Health,    (ModelNode*) &iedModel_PROT_IPTOC12_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC12_Health,    (ModelNode*) &iedModel_PROT_IPTOC12_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC12_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC12_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC12,    (ModelNode*) &iedModel_PROT_IPTOC12_Str, (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC12_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC12_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC12_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC12,  	(ModelNode*)&iedModel_PROT_IPTOC12_Op, (ModelNode*) &iedModel_PROT_IPTOC12_Str_general,0};
DataAttribute iedModel_PROT_IPTOC12_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC12_Str,  (ModelNode*) &iedModel_PROT_IPTOC12_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC12_Str,  (ModelNode*) &iedModel_PROT_IPTOC12_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC12_Str,  (ModelNode*) &iedModel_PROT_IPTOC12_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC12_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC12_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC12,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC12_Op_general,0};
DataAttribute iedModel_PROT_IPTOC12_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC12_Op,  (ModelNode*) &iedModel_PROT_IPTOC12_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC12_Op,  (ModelNode*) &iedModel_PROT_IPTOC12_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC12_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC12_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC13
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC13 				= {    LogicalNodeModelType,    "IPTOC13",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC14,    (ModelNode*) &iedModel_PROT_IPTOC13_Mod};

DataObject iedModel_PROT_IPTOC13_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC13,    (ModelNode*) &iedModel_PROT_IPTOC13_Beh,    (ModelNode*) &iedModel_PROT_IPTOC13_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC13_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC13_Mod,    (ModelNode*) &iedModel_PROT_IPTOC13_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC13_Mod,    (ModelNode*) &iedModel_PROT_IPTOC13_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC13_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC13_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC13,    (ModelNode*) &iedModel_PROT_IPTOC13_Health,    (ModelNode*) &iedModel_PROT_IPTOC13_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC13_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC13_Beh,    (ModelNode*) &iedModel_PROT_IPTOC13_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC13_Beh,    (ModelNode*) &iedModel_PROT_IPTOC13_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC13_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC13_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC13,    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC13_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC13_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC13_Health,    (ModelNode*) &iedModel_PROT_IPTOC13_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC13_Health,    (ModelNode*) &iedModel_PROT_IPTOC13_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC13_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC13_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC13,    (ModelNode*) &iedModel_PROT_IPTOC13_Str, (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC13_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC13_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC13_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC13,  	(ModelNode*)&iedModel_PROT_IPTOC13_Op, (ModelNode*) &iedModel_PROT_IPTOC13_Str_general,0};
DataAttribute iedModel_PROT_IPTOC13_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC13_Str,  (ModelNode*) &iedModel_PROT_IPTOC13_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC13_Str,  (ModelNode*) &iedModel_PROT_IPTOC13_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC13_Str,  (ModelNode*) &iedModel_PROT_IPTOC13_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC13_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC13_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC13,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC13_Op_general,0};
DataAttribute iedModel_PROT_IPTOC13_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC13_Op,  (ModelNode*) &iedModel_PROT_IPTOC13_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC13_Op,  (ModelNode*) &iedModel_PROT_IPTOC13_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC13_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC13_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC14
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC14 				= {    LogicalNodeModelType,    "IPTOC14",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC15,    (ModelNode*) &iedModel_PROT_IPTOC14_Mod};

DataObject iedModel_PROT_IPTOC14_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC14,    (ModelNode*) &iedModel_PROT_IPTOC14_Beh,    (ModelNode*) &iedModel_PROT_IPTOC14_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC14_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC14_Mod,    (ModelNode*) &iedModel_PROT_IPTOC14_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC14_Mod,    (ModelNode*) &iedModel_PROT_IPTOC14_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC14_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC14_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC14,    (ModelNode*) &iedModel_PROT_IPTOC14_Health,    (ModelNode*) &iedModel_PROT_IPTOC14_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC14_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC14_Beh,    (ModelNode*) &iedModel_PROT_IPTOC14_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC14_Beh,    (ModelNode*) &iedModel_PROT_IPTOC14_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC14_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC14_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC14,    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC14_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC14_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC14_Health,    (ModelNode*) &iedModel_PROT_IPTOC14_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC14_Health,    (ModelNode*) &iedModel_PROT_IPTOC14_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC14_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC14_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC14,    (ModelNode*) &iedModel_PROT_IPTOC14_Str, (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC14_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC14_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC14_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC14,  	(ModelNode*)&iedModel_PROT_IPTOC14_Op, (ModelNode*) &iedModel_PROT_IPTOC14_Str_general,0};
DataAttribute iedModel_PROT_IPTOC14_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC14_Str,  (ModelNode*) &iedModel_PROT_IPTOC14_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC14_Str,  (ModelNode*) &iedModel_PROT_IPTOC14_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC14_Str,  (ModelNode*) &iedModel_PROT_IPTOC14_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC14_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC14_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC14,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC14_Op_general,0};
DataAttribute iedModel_PROT_IPTOC14_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC14_Op,  (ModelNode*) &iedModel_PROT_IPTOC14_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC14_Op,  (ModelNode*) &iedModel_PROT_IPTOC14_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC14_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC14_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC15
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC15 				= {    LogicalNodeModelType,    "IPTOC15",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC16,    (ModelNode*) &iedModel_PROT_IPTOC15_Mod};

DataObject iedModel_PROT_IPTOC15_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC15,    (ModelNode*) &iedModel_PROT_IPTOC15_Beh,    (ModelNode*) &iedModel_PROT_IPTOC15_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC15_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC15_Mod,    (ModelNode*) &iedModel_PROT_IPTOC15_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC15_Mod,    (ModelNode*) &iedModel_PROT_IPTOC15_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC15_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC15_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC15,    (ModelNode*) &iedModel_PROT_IPTOC15_Health,    (ModelNode*) &iedModel_PROT_IPTOC15_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC15_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC15_Beh,    (ModelNode*) &iedModel_PROT_IPTOC15_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC15_Beh,    (ModelNode*) &iedModel_PROT_IPTOC15_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC15_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC15_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC15,    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC15_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC15_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC15_Health,    (ModelNode*) &iedModel_PROT_IPTOC15_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC15_Health,    (ModelNode*) &iedModel_PROT_IPTOC15_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC15_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC15_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC15,    (ModelNode*) &iedModel_PROT_IPTOC15_Str, (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC15_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC15_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC15_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC15,  	(ModelNode*)&iedModel_PROT_IPTOC15_Op, (ModelNode*) &iedModel_PROT_IPTOC15_Str_general,0};
DataAttribute iedModel_PROT_IPTOC15_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC15_Str,  (ModelNode*) &iedModel_PROT_IPTOC15_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC15_Str,  (ModelNode*) &iedModel_PROT_IPTOC15_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC15_Str,  (ModelNode*) &iedModel_PROT_IPTOC15_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC15_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC15_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC15,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC15_Op_general,0};
DataAttribute iedModel_PROT_IPTOC15_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC15_Op,  (ModelNode*) &iedModel_PROT_IPTOC15_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC15_Op,  (ModelNode*) &iedModel_PROT_IPTOC15_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC15_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC15_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC16
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC16 				= {    LogicalNodeModelType,    "IPTOC16",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC17,    (ModelNode*) &iedModel_PROT_IPTOC16_Mod};

DataObject iedModel_PROT_IPTOC16_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC16,    (ModelNode*) &iedModel_PROT_IPTOC16_Beh,    (ModelNode*) &iedModel_PROT_IPTOC16_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC16_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC16_Mod,    (ModelNode*) &iedModel_PROT_IPTOC16_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC16_Mod,    (ModelNode*) &iedModel_PROT_IPTOC16_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC16_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC16_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC16,    (ModelNode*) &iedModel_PROT_IPTOC16_Health,    (ModelNode*) &iedModel_PROT_IPTOC16_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC16_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC16_Beh,    (ModelNode*) &iedModel_PROT_IPTOC16_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC16_Beh,    (ModelNode*) &iedModel_PROT_IPTOC16_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC16_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC16_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC16,    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC16_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC16_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC16_Health,    (ModelNode*) &iedModel_PROT_IPTOC16_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC16_Health,    (ModelNode*) &iedModel_PROT_IPTOC16_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC16_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC16_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC16,    (ModelNode*) &iedModel_PROT_IPTOC16_Str, (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC16_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC16_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC16_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC16,  	(ModelNode*)&iedModel_PROT_IPTOC16_Op, (ModelNode*) &iedModel_PROT_IPTOC16_Str_general,0};
DataAttribute iedModel_PROT_IPTOC16_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC16_Str,  (ModelNode*) &iedModel_PROT_IPTOC16_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC16_Str,  (ModelNode*) &iedModel_PROT_IPTOC16_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC16_Str,  (ModelNode*) &iedModel_PROT_IPTOC16_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC16_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC16_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC16,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC16_Op_general,0};
DataAttribute iedModel_PROT_IPTOC16_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC16_Op,  (ModelNode*) &iedModel_PROT_IPTOC16_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC16_Op,  (ModelNode*) &iedModel_PROT_IPTOC16_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC16_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC16_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC17
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC17 				= {    LogicalNodeModelType,    "IPTOC17",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC18,    (ModelNode*) &iedModel_PROT_IPTOC17_Mod};

DataObject iedModel_PROT_IPTOC17_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC17,    (ModelNode*) &iedModel_PROT_IPTOC17_Beh,    (ModelNode*) &iedModel_PROT_IPTOC17_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC17_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC17_Mod,    (ModelNode*) &iedModel_PROT_IPTOC17_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC17_Mod,    (ModelNode*) &iedModel_PROT_IPTOC17_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC17_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC17_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC17,    (ModelNode*) &iedModel_PROT_IPTOC17_Health,    (ModelNode*) &iedModel_PROT_IPTOC17_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC17_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC17_Beh,    (ModelNode*) &iedModel_PROT_IPTOC17_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC17_Beh,    (ModelNode*) &iedModel_PROT_IPTOC17_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC17_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC17_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC17,    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC17_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC17_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC17_Health,    (ModelNode*) &iedModel_PROT_IPTOC17_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC17_Health,    (ModelNode*) &iedModel_PROT_IPTOC17_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC17_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC17_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC17,    (ModelNode*) &iedModel_PROT_IPTOC17_Str, (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC17_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC17_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC17_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC17,  	(ModelNode*)&iedModel_PROT_IPTOC17_Op, (ModelNode*) &iedModel_PROT_IPTOC17_Str_general,0};
DataAttribute iedModel_PROT_IPTOC17_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC17_Str,  (ModelNode*) &iedModel_PROT_IPTOC17_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC17_Str,  (ModelNode*) &iedModel_PROT_IPTOC17_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC17_Str,  (ModelNode*) &iedModel_PROT_IPTOC17_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC17_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC17_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC17,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC17_Op_general,0};
DataAttribute iedModel_PROT_IPTOC17_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC17_Op,  (ModelNode*) &iedModel_PROT_IPTOC17_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC17_Op,  (ModelNode*) &iedModel_PROT_IPTOC17_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC17_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC17_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC18
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC18 				= {    LogicalNodeModelType,    "IPTOC18",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC19,    (ModelNode*) &iedModel_PROT_IPTOC18_Mod};

DataObject iedModel_PROT_IPTOC18_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC18,    (ModelNode*) &iedModel_PROT_IPTOC18_Beh,    (ModelNode*) &iedModel_PROT_IPTOC18_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC18_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC18_Mod,    (ModelNode*) &iedModel_PROT_IPTOC18_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC18_Mod,    (ModelNode*) &iedModel_PROT_IPTOC18_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC18_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC18_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC18,    (ModelNode*) &iedModel_PROT_IPTOC18_Health,    (ModelNode*) &iedModel_PROT_IPTOC18_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC18_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC18_Beh,    (ModelNode*) &iedModel_PROT_IPTOC18_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC18_Beh,    (ModelNode*) &iedModel_PROT_IPTOC18_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC18_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC18_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC18,    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC18_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC18_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC18_Health,    (ModelNode*) &iedModel_PROT_IPTOC18_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC18_Health,    (ModelNode*) &iedModel_PROT_IPTOC18_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC18_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC18_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC18,    (ModelNode*) &iedModel_PROT_IPTOC18_Str, (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC18_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC18_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC18_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC18,  	(ModelNode*)&iedModel_PROT_IPTOC18_Op, (ModelNode*) &iedModel_PROT_IPTOC18_Str_general,0};
DataAttribute iedModel_PROT_IPTOC18_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC18_Str,  (ModelNode*) &iedModel_PROT_IPTOC18_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC18_Str,  (ModelNode*) &iedModel_PROT_IPTOC18_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC18_Str,  (ModelNode*) &iedModel_PROT_IPTOC18_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC18_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC18_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC18,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC18_Op_general,0};
DataAttribute iedModel_PROT_IPTOC18_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC18_Op,  (ModelNode*) &iedModel_PROT_IPTOC18_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC18_Op,  (ModelNode*) &iedModel_PROT_IPTOC18_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC18_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC18_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC19
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC19 				= {    LogicalNodeModelType,    "IPTOC19",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC20,    (ModelNode*) &iedModel_PROT_IPTOC19_Mod};

DataObject iedModel_PROT_IPTOC19_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC19,    (ModelNode*) &iedModel_PROT_IPTOC19_Beh,    (ModelNode*) &iedModel_PROT_IPTOC19_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC19_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC19_Mod,    (ModelNode*) &iedModel_PROT_IPTOC19_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC19_Mod,    (ModelNode*) &iedModel_PROT_IPTOC19_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC19_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC19_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC19,    (ModelNode*) &iedModel_PROT_IPTOC19_Health,    (ModelNode*) &iedModel_PROT_IPTOC19_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC19_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC19_Beh,    (ModelNode*) &iedModel_PROT_IPTOC19_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC19_Beh,    (ModelNode*) &iedModel_PROT_IPTOC19_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC19_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC19_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC19,    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC19_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC19_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC19_Health,    (ModelNode*) &iedModel_PROT_IPTOC19_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC19_Health,    (ModelNode*) &iedModel_PROT_IPTOC19_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC19_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC19_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC19,    (ModelNode*) &iedModel_PROT_IPTOC19_Str, (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC19_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC19_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC19_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC19,  	(ModelNode*)&iedModel_PROT_IPTOC19_Op, (ModelNode*) &iedModel_PROT_IPTOC19_Str_general,0};
DataAttribute iedModel_PROT_IPTOC19_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC19_Str,  (ModelNode*) &iedModel_PROT_IPTOC19_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC19_Str,  (ModelNode*) &iedModel_PROT_IPTOC19_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC19_Str,  (ModelNode*) &iedModel_PROT_IPTOC19_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC19_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC19_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC19,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC19_Op_general,0};
DataAttribute iedModel_PROT_IPTOC19_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC19_Op,  (ModelNode*) &iedModel_PROT_IPTOC19_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC19_Op,  (ModelNode*) &iedModel_PROT_IPTOC19_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC19_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC19_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC20
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC20 				= {    LogicalNodeModelType,    "IPTOC20",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC21,    (ModelNode*) &iedModel_PROT_IPTOC20_Mod};

DataObject iedModel_PROT_IPTOC20_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC20,    (ModelNode*) &iedModel_PROT_IPTOC20_Beh,    (ModelNode*) &iedModel_PROT_IPTOC20_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC20_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC20_Mod,    (ModelNode*) &iedModel_PROT_IPTOC20_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC20_Mod,    (ModelNode*) &iedModel_PROT_IPTOC20_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC20_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC20_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC20,    (ModelNode*) &iedModel_PROT_IPTOC20_Health,    (ModelNode*) &iedModel_PROT_IPTOC20_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC20_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC20_Beh,    (ModelNode*) &iedModel_PROT_IPTOC20_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC20_Beh,    (ModelNode*) &iedModel_PROT_IPTOC20_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC20_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC20_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC20,    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC20_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC20_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC20_Health,    (ModelNode*) &iedModel_PROT_IPTOC20_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC20_Health,    (ModelNode*) &iedModel_PROT_IPTOC20_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC20_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC20_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC20,    (ModelNode*) &iedModel_PROT_IPTOC20_Str, (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC20_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC20_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC20_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC20,  	(ModelNode*)&iedModel_PROT_IPTOC20_Op, (ModelNode*) &iedModel_PROT_IPTOC20_Str_general,0};
DataAttribute iedModel_PROT_IPTOC20_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC20_Str,  (ModelNode*) &iedModel_PROT_IPTOC20_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC20_Str,  (ModelNode*) &iedModel_PROT_IPTOC20_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC20_Str,  (ModelNode*) &iedModel_PROT_IPTOC20_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC20_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC20_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC20,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC20_Op_general,0};
DataAttribute iedModel_PROT_IPTOC20_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC20_Op,  (ModelNode*) &iedModel_PROT_IPTOC20_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC20_Op,  (ModelNode*) &iedModel_PROT_IPTOC20_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC20_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC20_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC21
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC21 				= {    LogicalNodeModelType,    "IPTOC21",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC22,    (ModelNode*) &iedModel_PROT_IPTOC21_Mod};

DataObject iedModel_PROT_IPTOC21_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC21,    (ModelNode*) &iedModel_PROT_IPTOC21_Beh,    (ModelNode*) &iedModel_PROT_IPTOC21_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC21_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC21_Mod,    (ModelNode*) &iedModel_PROT_IPTOC21_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC21_Mod,    (ModelNode*) &iedModel_PROT_IPTOC21_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC21_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC21_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC21,    (ModelNode*) &iedModel_PROT_IPTOC21_Health,    (ModelNode*) &iedModel_PROT_IPTOC21_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC21_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC21_Beh,    (ModelNode*) &iedModel_PROT_IPTOC21_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC21_Beh,    (ModelNode*) &iedModel_PROT_IPTOC21_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC21_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC21_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC21,    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC21_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC21_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC21_Health,    (ModelNode*) &iedModel_PROT_IPTOC21_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC21_Health,    (ModelNode*) &iedModel_PROT_IPTOC21_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC21_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC21_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC21,    (ModelNode*) &iedModel_PROT_IPTOC21_Str, (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC21_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC21_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC21_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC21,  	(ModelNode*)&iedModel_PROT_IPTOC21_Op, (ModelNode*) &iedModel_PROT_IPTOC21_Str_general,0};
DataAttribute iedModel_PROT_IPTOC21_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC21_Str,  (ModelNode*) &iedModel_PROT_IPTOC21_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC21_Str,  (ModelNode*) &iedModel_PROT_IPTOC21_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC21_Str,  (ModelNode*) &iedModel_PROT_IPTOC21_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC21_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC21_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC21,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC21_Op_general,0};
DataAttribute iedModel_PROT_IPTOC21_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC21_Op,  (ModelNode*) &iedModel_PROT_IPTOC21_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC21_Op,  (ModelNode*) &iedModel_PROT_IPTOC21_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC21_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC21_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC22
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC22 				= {    LogicalNodeModelType,    "IPTOC22",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC23,    (ModelNode*) &iedModel_PROT_IPTOC22_Mod};

DataObject iedModel_PROT_IPTOC22_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC22,    (ModelNode*) &iedModel_PROT_IPTOC22_Beh,    (ModelNode*) &iedModel_PROT_IPTOC22_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC22_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC22_Mod,    (ModelNode*) &iedModel_PROT_IPTOC22_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC22_Mod,    (ModelNode*) &iedModel_PROT_IPTOC22_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC22_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC22_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC22,    (ModelNode*) &iedModel_PROT_IPTOC22_Health,    (ModelNode*) &iedModel_PROT_IPTOC22_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC22_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC22_Beh,    (ModelNode*) &iedModel_PROT_IPTOC22_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC22_Beh,    (ModelNode*) &iedModel_PROT_IPTOC22_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC22_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC22_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC22,    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC22_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC22_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC22_Health,    (ModelNode*) &iedModel_PROT_IPTOC22_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC22_Health,    (ModelNode*) &iedModel_PROT_IPTOC22_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC22_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC22_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC22,    (ModelNode*) &iedModel_PROT_IPTOC22_Str, (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC22_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC22_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC22_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC22,  	(ModelNode*)&iedModel_PROT_IPTOC22_Op, (ModelNode*) &iedModel_PROT_IPTOC22_Str_general,0};
DataAttribute iedModel_PROT_IPTOC22_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC22_Str,  (ModelNode*) &iedModel_PROT_IPTOC22_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC22_Str,  (ModelNode*) &iedModel_PROT_IPTOC22_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC22_Str,  (ModelNode*) &iedModel_PROT_IPTOC22_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC22_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC22_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC22,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC22_Op_general,0};
DataAttribute iedModel_PROT_IPTOC22_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC22_Op,  (ModelNode*) &iedModel_PROT_IPTOC22_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC22_Op,  (ModelNode*) &iedModel_PROT_IPTOC22_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC22_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC22_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC23
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC23 				= {    LogicalNodeModelType,    "IPTOC23",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC24,    (ModelNode*) &iedModel_PROT_IPTOC23_Mod};

DataObject iedModel_PROT_IPTOC23_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC23,    (ModelNode*) &iedModel_PROT_IPTOC23_Beh,    (ModelNode*) &iedModel_PROT_IPTOC23_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC23_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC23_Mod,    (ModelNode*) &iedModel_PROT_IPTOC23_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC23_Mod,    (ModelNode*) &iedModel_PROT_IPTOC23_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC23_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC23_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC23,    (ModelNode*) &iedModel_PROT_IPTOC23_Health,    (ModelNode*) &iedModel_PROT_IPTOC23_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC23_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC23_Beh,    (ModelNode*) &iedModel_PROT_IPTOC23_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC23_Beh,    (ModelNode*) &iedModel_PROT_IPTOC23_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC23_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC23_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC23,    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC23_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC23_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC23_Health,    (ModelNode*) &iedModel_PROT_IPTOC23_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC23_Health,    (ModelNode*) &iedModel_PROT_IPTOC23_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC23_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC23_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC23,    (ModelNode*) &iedModel_PROT_IPTOC23_Str, (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC23_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC23_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC23_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC23,  	(ModelNode*)&iedModel_PROT_IPTOC23_Op, (ModelNode*) &iedModel_PROT_IPTOC23_Str_general,0};
DataAttribute iedModel_PROT_IPTOC23_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC23_Str,  (ModelNode*) &iedModel_PROT_IPTOC23_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC23_Str,  (ModelNode*) &iedModel_PROT_IPTOC23_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC23_Str,  (ModelNode*) &iedModel_PROT_IPTOC23_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC23_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC23_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC23,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC23_Op_general,0};
DataAttribute iedModel_PROT_IPTOC23_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC23_Op,  (ModelNode*) &iedModel_PROT_IPTOC23_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC23_Op,  (ModelNode*) &iedModel_PROT_IPTOC23_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC23_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC23_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC24
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC24 				= {    LogicalNodeModelType,    "IPTOC24",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC25,    (ModelNode*) &iedModel_PROT_IPTOC24_Mod};

DataObject iedModel_PROT_IPTOC24_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC24,    (ModelNode*) &iedModel_PROT_IPTOC24_Beh,    (ModelNode*) &iedModel_PROT_IPTOC24_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC24_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC24_Mod,    (ModelNode*) &iedModel_PROT_IPTOC24_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC24_Mod,    (ModelNode*) &iedModel_PROT_IPTOC24_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC24_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC24_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC24,    (ModelNode*) &iedModel_PROT_IPTOC24_Health,    (ModelNode*) &iedModel_PROT_IPTOC24_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC24_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC24_Beh,    (ModelNode*) &iedModel_PROT_IPTOC24_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC24_Beh,    (ModelNode*) &iedModel_PROT_IPTOC24_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC24_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC24_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC24,    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC24_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC24_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC24_Health,    (ModelNode*) &iedModel_PROT_IPTOC24_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC24_Health,    (ModelNode*) &iedModel_PROT_IPTOC24_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC24_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC24_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC24,    (ModelNode*) &iedModel_PROT_IPTOC24_Str, (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC24_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC24_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC24_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC24,  	(ModelNode*)&iedModel_PROT_IPTOC24_Op, (ModelNode*) &iedModel_PROT_IPTOC24_Str_general,0};
DataAttribute iedModel_PROT_IPTOC24_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC24_Str,  (ModelNode*) &iedModel_PROT_IPTOC24_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC24_Str,  (ModelNode*) &iedModel_PROT_IPTOC24_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC24_Str,  (ModelNode*) &iedModel_PROT_IPTOC24_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC24_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC24_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC24,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC24_Op_general,0};
DataAttribute iedModel_PROT_IPTOC24_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC24_Op,  (ModelNode*) &iedModel_PROT_IPTOC24_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC24_Op,  (ModelNode*) &iedModel_PROT_IPTOC24_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC24_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC24_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC25
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC25 				= {    LogicalNodeModelType,    "IPTOC25",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC26,    (ModelNode*) &iedModel_PROT_IPTOC25_Mod};

DataObject iedModel_PROT_IPTOC25_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC25,    (ModelNode*) &iedModel_PROT_IPTOC25_Beh,    (ModelNode*) &iedModel_PROT_IPTOC25_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC25_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC25_Mod,    (ModelNode*) &iedModel_PROT_IPTOC25_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC25_Mod,    (ModelNode*) &iedModel_PROT_IPTOC25_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC25_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC25_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC25,    (ModelNode*) &iedModel_PROT_IPTOC25_Health,    (ModelNode*) &iedModel_PROT_IPTOC25_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC25_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC25_Beh,    (ModelNode*) &iedModel_PROT_IPTOC25_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC25_Beh,    (ModelNode*) &iedModel_PROT_IPTOC25_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC25_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC25_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC25,    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC25_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC25_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC25_Health,    (ModelNode*) &iedModel_PROT_IPTOC25_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC25_Health,    (ModelNode*) &iedModel_PROT_IPTOC25_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC25_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC25_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC25,    (ModelNode*) &iedModel_PROT_IPTOC25_Str, (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC25_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC25_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC25_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC25,  	(ModelNode*)&iedModel_PROT_IPTOC25_Op, (ModelNode*) &iedModel_PROT_IPTOC25_Str_general,0};
DataAttribute iedModel_PROT_IPTOC25_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC25_Str,  (ModelNode*) &iedModel_PROT_IPTOC25_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC25_Str,  (ModelNode*) &iedModel_PROT_IPTOC25_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC25_Str,  (ModelNode*) &iedModel_PROT_IPTOC25_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC25_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC25_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC25,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC25_Op_general,0};
DataAttribute iedModel_PROT_IPTOC25_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC25_Op,  (ModelNode*) &iedModel_PROT_IPTOC25_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC25_Op,  (ModelNode*) &iedModel_PROT_IPTOC25_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC25_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC25_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC26
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC26 				= {    LogicalNodeModelType,    "IPTOC26",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC27,    (ModelNode*) &iedModel_PROT_IPTOC26_Mod};

DataObject iedModel_PROT_IPTOC26_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC26,    (ModelNode*) &iedModel_PROT_IPTOC26_Beh,    (ModelNode*) &iedModel_PROT_IPTOC26_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC26_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC26_Mod,    (ModelNode*) &iedModel_PROT_IPTOC26_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC26_Mod,    (ModelNode*) &iedModel_PROT_IPTOC26_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC26_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC26_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC26,    (ModelNode*) &iedModel_PROT_IPTOC26_Health,    (ModelNode*) &iedModel_PROT_IPTOC26_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC26_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC26_Beh,    (ModelNode*) &iedModel_PROT_IPTOC26_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC26_Beh,    (ModelNode*) &iedModel_PROT_IPTOC26_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC26_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC26_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC26,    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC26_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC26_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC26_Health,    (ModelNode*) &iedModel_PROT_IPTOC26_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC26_Health,    (ModelNode*) &iedModel_PROT_IPTOC26_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC26_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC26_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC26,    (ModelNode*) &iedModel_PROT_IPTOC26_Str, (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC26_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC26_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC26_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC26,  	(ModelNode*)&iedModel_PROT_IPTOC26_Op, (ModelNode*) &iedModel_PROT_IPTOC26_Str_general,0};
DataAttribute iedModel_PROT_IPTOC26_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC26_Str,  (ModelNode*) &iedModel_PROT_IPTOC26_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC26_Str,  (ModelNode*) &iedModel_PROT_IPTOC26_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC26_Str,  (ModelNode*) &iedModel_PROT_IPTOC26_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC26_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC26_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC26,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC26_Op_general,0};
DataAttribute iedModel_PROT_IPTOC26_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC26_Op,  (ModelNode*) &iedModel_PROT_IPTOC26_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC26_Op,  (ModelNode*) &iedModel_PROT_IPTOC26_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC26_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC26_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC27
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC27 				= {    LogicalNodeModelType,    "IPTOC27",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC28,    (ModelNode*) &iedModel_PROT_IPTOC27_Mod};

DataObject iedModel_PROT_IPTOC27_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC27,    (ModelNode*) &iedModel_PROT_IPTOC27_Beh,    (ModelNode*) &iedModel_PROT_IPTOC27_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC27_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC27_Mod,    (ModelNode*) &iedModel_PROT_IPTOC27_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC27_Mod,    (ModelNode*) &iedModel_PROT_IPTOC27_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC27_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC27_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC27,    (ModelNode*) &iedModel_PROT_IPTOC27_Health,    (ModelNode*) &iedModel_PROT_IPTOC27_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC27_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC27_Beh,    (ModelNode*) &iedModel_PROT_IPTOC27_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC27_Beh,    (ModelNode*) &iedModel_PROT_IPTOC27_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC27_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC27_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC27,    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC27_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC27_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC27_Health,    (ModelNode*) &iedModel_PROT_IPTOC27_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC27_Health,    (ModelNode*) &iedModel_PROT_IPTOC27_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC27_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC27_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC27,    (ModelNode*) &iedModel_PROT_IPTOC27_Str, (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC27_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC27_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC27_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC27,  	(ModelNode*)&iedModel_PROT_IPTOC27_Op, (ModelNode*) &iedModel_PROT_IPTOC27_Str_general,0};
DataAttribute iedModel_PROT_IPTOC27_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC27_Str,  (ModelNode*) &iedModel_PROT_IPTOC27_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC27_Str,  (ModelNode*) &iedModel_PROT_IPTOC27_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC27_Str,  (ModelNode*) &iedModel_PROT_IPTOC27_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC27_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC27_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC27,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC27_Op_general,0};
DataAttribute iedModel_PROT_IPTOC27_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC27_Op,  (ModelNode*) &iedModel_PROT_IPTOC27_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC27_Op,  (ModelNode*) &iedModel_PROT_IPTOC27_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC27_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC27_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC28
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC28 				= {    LogicalNodeModelType,    "IPTOC28",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC29,    (ModelNode*) &iedModel_PROT_IPTOC28_Mod};

DataObject iedModel_PROT_IPTOC28_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC28,    (ModelNode*) &iedModel_PROT_IPTOC28_Beh,    (ModelNode*) &iedModel_PROT_IPTOC28_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC28_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC28_Mod,    (ModelNode*) &iedModel_PROT_IPTOC28_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC28_Mod,    (ModelNode*) &iedModel_PROT_IPTOC28_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC28_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC28_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC28,    (ModelNode*) &iedModel_PROT_IPTOC28_Health,    (ModelNode*) &iedModel_PROT_IPTOC28_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC28_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC28_Beh,    (ModelNode*) &iedModel_PROT_IPTOC28_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC28_Beh,    (ModelNode*) &iedModel_PROT_IPTOC28_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC28_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC28_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC28,    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC28_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC28_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC28_Health,    (ModelNode*) &iedModel_PROT_IPTOC28_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC28_Health,    (ModelNode*) &iedModel_PROT_IPTOC28_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC28_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC28_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC28,    (ModelNode*) &iedModel_PROT_IPTOC28_Str, (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC28_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC28_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC28_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC28,  	(ModelNode*)&iedModel_PROT_IPTOC28_Op, (ModelNode*) &iedModel_PROT_IPTOC28_Str_general,0};
DataAttribute iedModel_PROT_IPTOC28_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC28_Str,  (ModelNode*) &iedModel_PROT_IPTOC28_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC28_Str,  (ModelNode*) &iedModel_PROT_IPTOC28_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC28_Str,  (ModelNode*) &iedModel_PROT_IPTOC28_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC28_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC28_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC28,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC28_Op_general,0};
DataAttribute iedModel_PROT_IPTOC28_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC28_Op,  (ModelNode*) &iedModel_PROT_IPTOC28_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC28_Op,  (ModelNode*) &iedModel_PROT_IPTOC28_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC28_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC28_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC29
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC29 				= {    LogicalNodeModelType,    "IPTOC29",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC30,    (ModelNode*) &iedModel_PROT_IPTOC29_Mod};

DataObject iedModel_PROT_IPTOC29_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC29,    (ModelNode*) &iedModel_PROT_IPTOC29_Beh,    (ModelNode*) &iedModel_PROT_IPTOC29_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC29_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC29_Mod,    (ModelNode*) &iedModel_PROT_IPTOC29_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC29_Mod,    (ModelNode*) &iedModel_PROT_IPTOC29_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC29_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC29_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC29,    (ModelNode*) &iedModel_PROT_IPTOC29_Health,    (ModelNode*) &iedModel_PROT_IPTOC29_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC29_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC29_Beh,    (ModelNode*) &iedModel_PROT_IPTOC29_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC29_Beh,    (ModelNode*) &iedModel_PROT_IPTOC29_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC29_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC29_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC29,    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC29_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC29_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC29_Health,    (ModelNode*) &iedModel_PROT_IPTOC29_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC29_Health,    (ModelNode*) &iedModel_PROT_IPTOC29_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC29_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC29_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC29,    (ModelNode*) &iedModel_PROT_IPTOC29_Str, (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC29_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC29_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC29_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC29,  	(ModelNode*)&iedModel_PROT_IPTOC29_Op, (ModelNode*) &iedModel_PROT_IPTOC29_Str_general,0};
DataAttribute iedModel_PROT_IPTOC29_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC29_Str,  (ModelNode*) &iedModel_PROT_IPTOC29_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC29_Str,  (ModelNode*) &iedModel_PROT_IPTOC29_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC29_Str,  (ModelNode*) &iedModel_PROT_IPTOC29_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC29_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC29_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC29,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC29_Op_general,0};
DataAttribute iedModel_PROT_IPTOC29_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC29_Op,  (ModelNode*) &iedModel_PROT_IPTOC29_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC29_Op,  (ModelNode*) &iedModel_PROT_IPTOC29_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC29_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC29_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC30
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC30 				= {    LogicalNodeModelType,    "IPTOC30",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC31,    (ModelNode*) &iedModel_PROT_IPTOC30_Mod};

DataObject iedModel_PROT_IPTOC30_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC30,    (ModelNode*) &iedModel_PROT_IPTOC30_Beh,    (ModelNode*) &iedModel_PROT_IPTOC30_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC30_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC30_Mod,    (ModelNode*) &iedModel_PROT_IPTOC30_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC30_Mod,    (ModelNode*) &iedModel_PROT_IPTOC30_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC30_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC30_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC30,    (ModelNode*) &iedModel_PROT_IPTOC30_Health,    (ModelNode*) &iedModel_PROT_IPTOC30_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC30_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC30_Beh,    (ModelNode*) &iedModel_PROT_IPTOC30_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC30_Beh,    (ModelNode*) &iedModel_PROT_IPTOC30_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC30_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC30_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC30,    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC30_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC30_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC30_Health,    (ModelNode*) &iedModel_PROT_IPTOC30_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC30_Health,    (ModelNode*) &iedModel_PROT_IPTOC30_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC30_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC30_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC30,    (ModelNode*) &iedModel_PROT_IPTOC30_Str, (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC30_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC30_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC30_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC30,  	(ModelNode*)&iedModel_PROT_IPTOC30_Op, (ModelNode*) &iedModel_PROT_IPTOC30_Str_general,0};
DataAttribute iedModel_PROT_IPTOC30_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC30_Str,  (ModelNode*) &iedModel_PROT_IPTOC30_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC30_Str,  (ModelNode*) &iedModel_PROT_IPTOC30_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC30_Str,  (ModelNode*) &iedModel_PROT_IPTOC30_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC30_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC30_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC30,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC30_Op_general,0};
DataAttribute iedModel_PROT_IPTOC30_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC30_Op,  (ModelNode*) &iedModel_PROT_IPTOC30_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC30_Op,  (ModelNode*) &iedModel_PROT_IPTOC30_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC30_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC30_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC31
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC31 				= {    LogicalNodeModelType,    "IPTOC31",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC32,    (ModelNode*) &iedModel_PROT_IPTOC31_Mod};

DataObject iedModel_PROT_IPTOC31_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC31,    (ModelNode*) &iedModel_PROT_IPTOC31_Beh,    (ModelNode*) &iedModel_PROT_IPTOC31_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC31_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC31_Mod,    (ModelNode*) &iedModel_PROT_IPTOC31_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC31_Mod,    (ModelNode*) &iedModel_PROT_IPTOC31_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC31_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC31_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC31,    (ModelNode*) &iedModel_PROT_IPTOC31_Health,    (ModelNode*) &iedModel_PROT_IPTOC31_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC31_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC31_Beh,    (ModelNode*) &iedModel_PROT_IPTOC31_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC31_Beh,    (ModelNode*) &iedModel_PROT_IPTOC31_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC31_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC31_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC31,    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC31_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC31_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC31_Health,    (ModelNode*) &iedModel_PROT_IPTOC31_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC31_Health,    (ModelNode*) &iedModel_PROT_IPTOC31_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC31_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC31_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC31,    (ModelNode*) &iedModel_PROT_IPTOC31_Str, (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC31_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC31_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC31_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC31,  	(ModelNode*)&iedModel_PROT_IPTOC31_Op, (ModelNode*) &iedModel_PROT_IPTOC31_Str_general,0};
DataAttribute iedModel_PROT_IPTOC31_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC31_Str,  (ModelNode*) &iedModel_PROT_IPTOC31_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC31_Str,  (ModelNode*) &iedModel_PROT_IPTOC31_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC31_Str,  (ModelNode*) &iedModel_PROT_IPTOC31_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC31_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC31_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC31,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC31_Op_general,0};
DataAttribute iedModel_PROT_IPTOC31_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC31_Op,  (ModelNode*) &iedModel_PROT_IPTOC31_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC31_Op,  (ModelNode*) &iedModel_PROT_IPTOC31_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC31_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC31_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
//-------------------------------------------------------
// IPTOC32
//-------------------------------------------------------
LogicalNode iedModel_PROT_IPTOC32 				= {    LogicalNodeModelType,    "IPTOC32",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_IPTOC32_Mod};

DataObject iedModel_PROT_IPTOC32_Mod 			= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC32,    (ModelNode*) &iedModel_PROT_IPTOC32_Beh,    (ModelNode*) &iedModel_PROT_IPTOC32_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC32_Mod_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC32_Mod,    (ModelNode*) &iedModel_PROT_IPTOC32_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Mod_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC32_Mod,    (ModelNode*) &iedModel_PROT_IPTOC32_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC32_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC32_Beh 			= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC32,    (ModelNode*) &iedModel_PROT_IPTOC32_Health,    (ModelNode*) &iedModel_PROT_IPTOC32_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC32_Beh_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC32_Beh,    (ModelNode*) &iedModel_PROT_IPTOC32_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Beh_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC32_Beh,    (ModelNode*) &iedModel_PROT_IPTOC32_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Beh_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC32_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC32_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC32,    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC32_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC32_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC32_Health,    (ModelNode*) &iedModel_PROT_IPTOC32_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Health_q 	= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC32_Health,    (ModelNode*) &iedModel_PROT_IPTOC32_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Health_t 	= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC32_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC32_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC32,    (ModelNode*) &iedModel_PROT_IPTOC32_Str, (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC32_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_NamPlt_d 	= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC32_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC32_Str 	 		= {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC32,  	(ModelNode*)&iedModel_PROT_IPTOC32_Op, (ModelNode*) &iedModel_PROT_IPTOC32_Str_general,0};
DataAttribute iedModel_PROT_IPTOC32_Str_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC32_Str,  (ModelNode*) &iedModel_PROT_IPTOC32_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC32_Str,  (ModelNode*) &iedModel_PROT_IPTOC32_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Str_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC32_Str,  (ModelNode*) &iedModel_PROT_IPTOC32_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Str_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC32_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataObject iedModel_PROT_IPTOC32_Op 	 			= {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC32,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC32_Op_general,0};
DataAttribute iedModel_PROT_IPTOC32_Op_general 	= {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC32_Op,  (ModelNode*) &iedModel_PROT_IPTOC32_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Op_q 		= {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC32_Op,  (ModelNode*) &iedModel_PROT_IPTOC32_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC32_Op_t 		= {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC32_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};



//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO1 			= { LogicalNodeModelType,   "VZGGIO1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod};

DataObject iedModel_PROT_VZGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*)&iedModel_PROT_VZGGIO1_Alm , (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO1,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO2 			= { LogicalNodeModelType,   "VZGGIO2",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod};

DataObject iedModel_PROT_VZGGIO2_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*)&iedModel_PROT_VZGGIO2_Alm , (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO2,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO3 			= { LogicalNodeModelType,   "VZGGIO3",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod};

DataObject iedModel_PROT_VZGGIO3_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*)&iedModel_PROT_VZGGIO3_Alm , (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO3,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO4 			= { LogicalNodeModelType,   "VZGGIO4",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod};

DataObject iedModel_PROT_VZGGIO4_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*)&iedModel_PROT_VZGGIO4_Alm , (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO4,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO5 			= { LogicalNodeModelType,   "VZGGIO5",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod};

DataObject iedModel_PROT_VZGGIO5_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*)&iedModel_PROT_VZGGIO5_Alm , (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO5,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO6 			= { LogicalNodeModelType,   "VZGGIO6",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod};

DataObject iedModel_PROT_VZGGIO6_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*)&iedModel_PROT_VZGGIO6_Alm , (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO6,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO7 			= { LogicalNodeModelType,   "VZGGIO7",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod};

DataObject iedModel_PROT_VZGGIO7_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*)&iedModel_PROT_VZGGIO7_Alm , (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO7,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO8 			= { LogicalNodeModelType,   "VZGGIO8",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod};

DataObject iedModel_PROT_VZGGIO8_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*)&iedModel_PROT_VZGGIO8_Alm , (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO8,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO9 			= { LogicalNodeModelType,   "VZGGIO9",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod};

DataObject iedModel_PROT_VZGGIO9_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO9_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*)&iedModel_PROT_VZGGIO9_Alm , (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO9,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO10 			= { LogicalNodeModelType,   "VZGGIO10",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod};

DataObject iedModel_PROT_VZGGIO10_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO10_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*)&iedModel_PROT_VZGGIO10_Alm , (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO10,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO11 			= { LogicalNodeModelType,   "VZGGIO11",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod};

DataObject iedModel_PROT_VZGGIO11_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO11_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*)&iedModel_PROT_VZGGIO11_Alm , (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO11,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO12 			= { LogicalNodeModelType,   "VZGGIO12",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod};

DataObject iedModel_PROT_VZGGIO12_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO12_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*)&iedModel_PROT_VZGGIO12_Alm , (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO12,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO13 			= { LogicalNodeModelType,   "VZGGIO13",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod};

DataObject iedModel_PROT_VZGGIO13_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO13_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*)&iedModel_PROT_VZGGIO13_Alm , (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO13,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO14 			= { LogicalNodeModelType,   "VZGGIO14",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod};

DataObject iedModel_PROT_VZGGIO14_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO14_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*)&iedModel_PROT_VZGGIO14_Alm , (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO14,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO15 			= { LogicalNodeModelType,   "VZGGIO15",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod};

DataObject iedModel_PROT_VZGGIO15_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO15_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*)&iedModel_PROT_VZGGIO15_Alm , (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO15,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO16 			= { LogicalNodeModelType,   "VZGGIO16",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_BUSRBRF1,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod};

DataObject iedModel_PROT_VZGGIO16_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*)&iedModel_PROT_VZGGIO16_Alm , (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO16,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_NO,NULL,0};


/*******************************************************
 * BUSRBRF1
 *******************************************************/
LogicalNode iedModel_PROT_BUSRBRF1 = {    LogicalNodeModelType,    "BUSRBRF1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_BUSRBRF2,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod};

DataObject iedModel_PROT_BUSRBRF1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_BUSRBRF1,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod_q,0};
DataAttribute iedModel_PROT_BUSRBRF1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_BUSRBRF1,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh_stVal,0};
DataAttribute iedModel_PROT_BUSRBRF1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_BUSRBRF1,    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health_stVal,0};
DataAttribute iedModel_PROT_BUSRBRF1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_BUSRBRF1,    (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx, (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_BUSRBRF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_BUSRBRF1_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_BUSRBRF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx_general,0};
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF1_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_BUSRBRF1_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*******************************************************
 * BUSRBRF2
 *******************************************************/
LogicalNode iedModel_PROT_BUSRBRF2 = {    LogicalNodeModelType,    "BUSRBRF2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FRBRF1,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod};

DataObject iedModel_PROT_BUSRBRF2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_BUSRBRF2,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod_q,0};
DataAttribute iedModel_PROT_BUSRBRF2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_BUSRBRF2,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh_stVal,0};
DataAttribute iedModel_PROT_BUSRBRF2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_BUSRBRF2,    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health_stVal,0};
DataAttribute iedModel_PROT_BUSRBRF2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health,    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_BUSRBRF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BUSRBRF2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_BUSRBRF2,    (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx, (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_BUSRBRF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_BUSRBRF2_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_BUSRBRF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx_general,0};
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx,  (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx,  (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BUSRBRF2_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_BUSRBRF2_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*******************************************************
 * FRBRF1
 *******************************************************/
LogicalNode iedModel_PROT_FRBRF1 = {    LogicalNodeModelType,    "FRBRF1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FRBRF2,    (ModelNode*) &iedModel_PROT_FRBRF1_Mod};

DataObject iedModel_PROT_FRBRF1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FRBRF1,    (ModelNode*) &iedModel_PROT_FRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FRBRF1_Mod_q,0};
DataAttribute iedModel_PROT_FRBRF1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF1_Mod,    (ModelNode*) &iedModel_PROT_FRBRF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF1_Mod,    (ModelNode*) &iedModel_PROT_FRBRF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FRBRF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FRBRF1,    (ModelNode*) &iedModel_PROT_FRBRF1_Health,    (ModelNode*) &iedModel_PROT_FRBRF1_Beh_stVal,0};
DataAttribute iedModel_PROT_FRBRF1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FRBRF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FRBRF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FRBRF1,    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF1_Health_stVal,0};
DataAttribute iedModel_PROT_FRBRF1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF1_Health,    (ModelNode*) &iedModel_PROT_FRBRF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF1_Health,    (ModelNode*) &iedModel_PROT_FRBRF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FRBRF1,    (ModelNode*) &iedModel_PROT_FRBRF1_OpEx, (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FRBRF1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FRBRF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FRBRF1_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FRBRF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FRBRF1_OpEx_general,0};
DataAttribute iedModel_PROT_FRBRF1_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF1_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF1_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF1_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FRBRF1_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*******************************************************
 * FRBRF2
 *******************************************************/
LogicalNode iedModel_PROT_FRBRF2 = {    LogicalNodeModelType,    "FRBRF2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FRBRF3,    (ModelNode*) &iedModel_PROT_FRBRF2_Mod};

DataObject iedModel_PROT_FRBRF2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FRBRF2,    (ModelNode*) &iedModel_PROT_FRBRF2_Beh,    (ModelNode*) &iedModel_PROT_FRBRF2_Mod_q,0};
DataAttribute iedModel_PROT_FRBRF2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF2_Mod,    (ModelNode*) &iedModel_PROT_FRBRF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF2_Mod,    (ModelNode*) &iedModel_PROT_FRBRF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FRBRF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FRBRF2,    (ModelNode*) &iedModel_PROT_FRBRF2_Health,    (ModelNode*) &iedModel_PROT_FRBRF2_Beh_stVal,0};
DataAttribute iedModel_PROT_FRBRF2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF2_Beh,    (ModelNode*) &iedModel_PROT_FRBRF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF2_Beh,    (ModelNode*) &iedModel_PROT_FRBRF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FRBRF2,    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF2_Health_stVal,0};
DataAttribute iedModel_PROT_FRBRF2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF2_Health,    (ModelNode*) &iedModel_PROT_FRBRF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF2_Health,    (ModelNode*) &iedModel_PROT_FRBRF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FRBRF2,    (ModelNode*) &iedModel_PROT_FRBRF2_OpEx, (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FRBRF2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FRBRF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FRBRF2_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FRBRF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FRBRF2_OpEx_general,0};
DataAttribute iedModel_PROT_FRBRF2_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FRBRF2_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF2_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FRBRF2_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF2_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF2_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FRBRF2_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
/*******************************************************
 * FRBRF3
 *******************************************************/
LogicalNode iedModel_PROT_FRBRF3 = {    LogicalNodeModelType,    "FRBRF3",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FRBRF4,    (ModelNode*) &iedModel_PROT_FRBRF3_Mod};

DataObject iedModel_PROT_FRBRF3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FRBRF3,    (ModelNode*) &iedModel_PROT_FRBRF3_Beh,    (ModelNode*) &iedModel_PROT_FRBRF3_Mod_q,0};
DataAttribute iedModel_PROT_FRBRF3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF3_Mod,    (ModelNode*) &iedModel_PROT_FRBRF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF3_Mod,    (ModelNode*) &iedModel_PROT_FRBRF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FRBRF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FRBRF3,    (ModelNode*) &iedModel_PROT_FRBRF3_Health,    (ModelNode*) &iedModel_PROT_FRBRF3_Beh_stVal,0};
DataAttribute iedModel_PROT_FRBRF3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF3_Beh,    (ModelNode*) &iedModel_PROT_FRBRF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF3_Beh,    (ModelNode*) &iedModel_PROT_FRBRF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FRBRF3,    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF3_Health_stVal,0};
DataAttribute iedModel_PROT_FRBRF3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF3_Health,    (ModelNode*) &iedModel_PROT_FRBRF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF3_Health,    (ModelNode*) &iedModel_PROT_FRBRF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FRBRF3,    (ModelNode*) &iedModel_PROT_FRBRF3_OpEx, (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FRBRF3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FRBRF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FRBRF3_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FRBRF3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FRBRF3_OpEx_general,0};
DataAttribute iedModel_PROT_FRBRF3_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FRBRF3_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF3_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FRBRF3_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF3_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF3_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FRBRF3_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
/*******************************************************
 * FRBRF4
 *******************************************************/
LogicalNode iedModel_PROT_FRBRF4 = {    LogicalNodeModelType,    "FRBRF4",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FRBRF5,    (ModelNode*) &iedModel_PROT_FRBRF4_Mod};

DataObject iedModel_PROT_FRBRF4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FRBRF4,    (ModelNode*) &iedModel_PROT_FRBRF4_Beh,    (ModelNode*) &iedModel_PROT_FRBRF4_Mod_q,0};
DataAttribute iedModel_PROT_FRBRF4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF4_Mod,    (ModelNode*) &iedModel_PROT_FRBRF4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF4_Mod,    (ModelNode*) &iedModel_PROT_FRBRF4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FRBRF4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FRBRF4,    (ModelNode*) &iedModel_PROT_FRBRF4_Health,    (ModelNode*) &iedModel_PROT_FRBRF4_Beh_stVal,0};
DataAttribute iedModel_PROT_FRBRF4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF4_Beh,    (ModelNode*) &iedModel_PROT_FRBRF4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF4_Beh,    (ModelNode*) &iedModel_PROT_FRBRF4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FRBRF4,    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF4_Health_stVal,0};
DataAttribute iedModel_PROT_FRBRF4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF4_Health,    (ModelNode*) &iedModel_PROT_FRBRF4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF4_Health,    (ModelNode*) &iedModel_PROT_FRBRF4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FRBRF4,    (ModelNode*) &iedModel_PROT_FRBRF4_OpEx, (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FRBRF4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FRBRF4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FRBRF4_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FRBRF4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FRBRF4_OpEx_general,0};
DataAttribute iedModel_PROT_FRBRF4_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FRBRF4_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF4_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FRBRF4_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF4_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF4_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FRBRF4_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
/*******************************************************
 * FRBRF5
 *******************************************************/
LogicalNode iedModel_PROT_FRBRF5 = {    LogicalNodeModelType,    "FRBRF5",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_FINRBRF1,    (ModelNode*) &iedModel_PROT_FRBRF5_Mod};

DataObject iedModel_PROT_FRBRF5_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FRBRF5,    (ModelNode*) &iedModel_PROT_FRBRF5_Beh,    (ModelNode*) &iedModel_PROT_FRBRF5_Mod_q,0};
DataAttribute iedModel_PROT_FRBRF5_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF5_Mod,    (ModelNode*) &iedModel_PROT_FRBRF5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF5_Mod,    (ModelNode*) &iedModel_PROT_FRBRF5_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FRBRF5_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF5_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FRBRF5,    (ModelNode*) &iedModel_PROT_FRBRF5_Health,    (ModelNode*) &iedModel_PROT_FRBRF5_Beh_stVal,0};
DataAttribute iedModel_PROT_FRBRF5_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF5_Beh,    (ModelNode*) &iedModel_PROT_FRBRF5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF5_Beh,    (ModelNode*) &iedModel_PROT_FRBRF5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF5_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF5_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FRBRF5,    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF5_Health_stVal,0};
DataAttribute iedModel_PROT_FRBRF5_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FRBRF5_Health,    (ModelNode*) &iedModel_PROT_FRBRF5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FRBRF5_Health,    (ModelNode*) &iedModel_PROT_FRBRF5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FRBRF5_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FRBRF5_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FRBRF5,    (ModelNode*) &iedModel_PROT_FRBRF5_OpEx, (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FRBRF5_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt,    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FRBRF5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FRBRF5_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FRBRF5,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FRBRF5_OpEx_general,0};
DataAttribute iedModel_PROT_FRBRF5_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FRBRF5_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF5_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FRBRF5_OpEx,  (ModelNode*) &iedModel_PROT_FRBRF5_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FRBRF5_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FRBRF5_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*******************************************************
 * FINRBRF1
 *******************************************************/
LogicalNode iedModel_PROT_FINRBRF1 = {    LogicalNodeModelType,    "FINRBRF1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)NULL,    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod};

DataObject iedModel_PROT_FINRBRF1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_FINRBRF1,    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod_q,0};
DataAttribute iedModel_PROT_FINRBRF1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod,    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod,    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_FINRBRF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FINRBRF1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_FINRBRF1,    (ModelNode*) &iedModel_PROT_FINRBRF1_Health,    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh_stVal,0};
DataAttribute iedModel_PROT_FINRBRF1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh,    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FINRBRF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FINRBRF1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_FINRBRF1,    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FINRBRF1_Health_stVal,0};
DataAttribute iedModel_PROT_FINRBRF1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_FINRBRF1_Health,    (ModelNode*) &iedModel_PROT_FINRBRF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_FINRBRF1_Health,    (ModelNode*) &iedModel_PROT_FINRBRF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_FINRBRF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_FINRBRF1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_FINRBRF1,    (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx, (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_FINRBRF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_FINRBRF1_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_FINRBRF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx_general,0};
DataAttribute iedModel_PROT_FINRBRF1_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx,  (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_FINRBRF1_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_FINRBRF1_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


/*************************************************************************
 * PTRC
 *
 *************************************************************************/
LogicalNode iedModel_CTRL_PTRC 					= {    LogicalNodeModelType,    "PTRC1",    (ModelNode*)&iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_PTRC_Mod};

DataObject iedModel_CTRL_PTRC_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_q,0};
DataAttribute iedModel_CTRL_PTRC_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_Health_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Op, (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_CTRL_PTRC,  	NULL, (ModelNode*) &iedModel_CTRL_PTRC_Op_general,0};
DataAttribute iedModel_CTRL_PTRC_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


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
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda0 = {"GGIO",false,"IN24GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda1 = {"GGIO",false,"IN24GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda2 = {"GGIO",false,"IN24GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda3 = {"GGIO",false,"IN24GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda4 = {"GGIO",false,"IN24GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda5 = {"GGIO",false,"IN24GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda6 = {"GGIO",false,"IN24GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda7 = {"GGIO",false,"IN24GGIO1$ST$Ind8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda8 = {"GGIO",false,"IN24GGIO1$ST$Ind9", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda9 = {"GGIO",false,"IN24GGIO1$ST$Ind10", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda10 = {"GGIO",false,"IN24GGIO1$ST$Ind11", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda11 = {"GGIO",false,"IN24GGIO1$ST$Ind12", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda12 = {"GGIO",false,"IN24GGIO1$ST$Ind13", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda13 = {"GGIO",false,"IN24GGIO1$ST$Ind14", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda14 = {"GGIO",false,"IN24GGIO1$ST$Ind15", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda15 = {"GGIO",false,"IN24GGIO1$ST$Ind16", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda16 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda16 = {"GGIO",false,"IN24GGIO1$ST$Ind17", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda17 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda17 = {"GGIO",false,"IN24GGIO1$ST$Ind18", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda18 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda18 = {"GGIO",false,"IN24GGIO1$ST$Ind19", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda19 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda19 = {"GGIO",false,"IN24GGIO1$ST$Ind20", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda20 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda20 = {"GGIO",false,"IN24GGIO1$ST$Ind21", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda21 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda21 = {"GGIO",false,"IN24GGIO1$ST$Ind22", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda22 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda22 = {"GGIO",false,"IN24GGIO1$ST$Ind23", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_fcda23 };
DataSetEntry iedModelds_LD0_LLN0_dataset_fcda23 = {"GGIO",false,"IN24GGIO1$ST$Ind24", -1, NULL, NULL, NULL };


/***********************************************************************
 * DataSet
 ***********************************************************************/

DataSetEntry iedModelds_LD0_MMXU1_fcda0 = {"MES",false, "MMXU1$MX$A$phsA",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda1};
DataSetEntry iedModelds_LD0_MMXU1_fcda1 = {"MES",false, "MMXU1$MX$A$phsB",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda2};
DataSetEntry iedModelds_LD0_MMXU1_fcda2 = {"MES",false, "MMXU1$MX$A$phsC",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda3};
DataSetEntry iedModelds_LD0_MMXU1_fcda3 = {"MES",false, "MMXU1$MX$A$neut",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda4};
DataSetEntry iedModelds_LD0_MMXU1_fcda4 = {"MES",false, "MSQI1$MX$SeqA$I0",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda5};
DataSetEntry iedModelds_LD0_MMXU1_fcda5 = {"MES",false, "MSQI1$MX$SeqA$I2",-1,NULL,NULL,NULL};

DataSetEntry iedModelds_LD0_MMXU2_fcda0 = {"MES",false, "MMXU2$MX$A$phsA",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda1};
DataSetEntry iedModelds_LD0_MMXU2_fcda1 = {"MES",false, "MMXU2$MX$A$phsB",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda2};
DataSetEntry iedModelds_LD0_MMXU2_fcda2 = {"MES",false, "MMXU2$MX$A$phsC",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda3};
DataSetEntry iedModelds_LD0_MMXU2_fcda3 = {"MES",false, "MMXU2$MX$A$neut",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda4};
DataSetEntry iedModelds_LD0_MMXU2_fcda4 = {"MES",false, "MSQI2$MX$SeqA$I0",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda5};
DataSetEntry iedModelds_LD0_MMXU2_fcda5 = {"MES",false, "MSQI2$MX$SeqA$I2",-1,NULL,NULL,NULL};

DataSetEntry iedModelds_LD0_MMXU3_fcda0 = {"MES",false, "MMXU3$MX$A$phsA",-1,NULL,NULL,&iedModelds_LD0_MMXU3_fcda1};
DataSetEntry iedModelds_LD0_MMXU3_fcda1 = {"MES",false, "MMXU3$MX$A$phsB",-1,NULL,NULL,&iedModelds_LD0_MMXU3_fcda2};
DataSetEntry iedModelds_LD0_MMXU3_fcda2 = {"MES",false, "MMXU3$MX$A$phsC",-1,NULL,NULL,&iedModelds_LD0_MMXU3_fcda3};
DataSetEntry iedModelds_LD0_MMXU3_fcda3 = {"MES",false, "MMXU3$MX$A$neut",-1,NULL,NULL,&iedModelds_LD0_MMXU3_fcda4};
DataSetEntry iedModelds_LD0_MMXU3_fcda4 = {"MES",false, "MSQI3$MX$SeqA$I0",-1,NULL,NULL,&iedModelds_LD0_MMXU3_fcda5};
DataSetEntry iedModelds_LD0_MMXU3_fcda5 = {"MES",false, "MSQI3$MX$SeqA$I2",-1,NULL,NULL,NULL};

DataSetEntry iedModelds_LD0_MMXU4_fcda0 = {"MES",false, "MMXU4$MX$PhV$phsA",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda1};
DataSetEntry iedModelds_LD0_MMXU4_fcda1 = {"MES",false, "MMXU4$MX$PhV$phsB",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda2};
DataSetEntry iedModelds_LD0_MMXU4_fcda2 = {"MES",false, "MMXU4$MX$PhV$phsC",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda3};
DataSetEntry iedModelds_LD0_MMXU4_fcda3 = {"MES",false, "MMXU4$MX$PhV$res",-1, NULL,NULL,	&iedModelds_LD0_MMXU4_fcda4};
DataSetEntry iedModelds_LD0_MMXU4_fcda4 = {"MES",false, "MMXU4$MX$PPV$phsAB",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda5};
DataSetEntry iedModelds_LD0_MMXU4_fcda5 = {"MES",false, "MMXU4$MX$PPV$phsBC",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda6};
DataSetEntry iedModelds_LD0_MMXU4_fcda6 = {"MES",false, "MMXU4$MX$PPV$phsCA",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda7};
DataSetEntry iedModelds_LD0_MMXU4_fcda7 = {"MES",false, "MSQI4$MX$SeqU$U0",-1,NULL,NULL,	&iedModelds_LD0_MMXU4_fcda8};
DataSetEntry iedModelds_LD0_MMXU4_fcda8 = {"MES",false, "MSQI4$MX$SeqU$U2",-1,NULL,NULL,NULL};

DataSetEntry iedModelds_LD0_MMXU5_fcda0 = {"MES",false, "MMXU5$MX$TotW",-1,NULL,NULL,&iedModelds_LD0_MMXU5_fcda1};
DataSetEntry iedModelds_LD0_MMXU5_fcda1 = {"MES",false, "MMXU5$MX$TotVAr",-1,NULL,NULL,&iedModelds_LD0_MMXU5_fcda2};
DataSetEntry iedModelds_LD0_MMXU5_fcda2 = {"MES",false, "MMXU5$MX$TotPF",-1,NULL,NULL,&iedModelds_LD0_MMXU5_fcda3};
DataSetEntry iedModelds_LD0_MMXU5_fcda3 = {"MES",false, "MMXU5$MX$Hz",-1,NULL,NULL,NULL};

//LED12
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda0 = {"GGIO",false,"LED16GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda1 = {"GGIO",false,"LED16GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda2 = {"GGIO",false,"LED16GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda3 = {"GGIO",false,"LED16GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda4 = {"GGIO",false,"LED16GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda5 = {"GGIO",false,"LED16GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda6 = {"GGIO",false,"LED16GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda7 = {"GGIO",false,"LED16GGIO1$ST$Ind8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda8 = {"GGIO",false,"LED16GGIO1$ST$Ind9", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda9 = {"GGIO",false,"LED16GGIO1$ST$Ind10", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda10 = {"GGIO",false,"LED16GGIO1$ST$Ind11", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda11 = {"GGIO",false,"LED16GGIO1$ST$Ind12", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda12 = {"GGIO",false,"LED16GGIO1$ST$Ind13", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda13 = {"GGIO",false,"LED16GGIO1$ST$Ind14", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda14 = {"GGIO",false,"LED16GGIO1$ST$Ind15", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D3_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D3_fcda15 = {"GGIO",false,"LED16GGIO1$ST$Ind16", -1, NULL, NULL, NULL };

DataSetEntry iedModelds_LD0_LLN0_dataset_D4_fcda0 = {"CTRL",false,"XCBR1$ST$Pos", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D4_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D4_fcda1 = {"CTRL",false,"XCBR1$ST$BlkCls", -1, NULL, NULL, NULL };

DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda0 = {"CTRL",false,"GGIO1$ST$SPCSO1$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D5_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda1 = {"CTRL",false,"GGIO1$ST$SPCSO2$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset_D5_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset_D5_fcda2 = {"CTRL",false,"GGIO1$ST$SPCSO3$stVal", -1, NULL, NULL, NULL };

/***********************************************************************
 * DataSet
 ***********************************************************************/
DataSet iedModelds_LD0_LLN0_dataset0 = {"LD0", "LLN0$DS0", 24, &iedModelds_LD0_LLN0_dataset_fcda0, 		&iedModelds_LD0_LLN0_dataset1};		//дискреты
DataSet iedModelds_LD0_LLN0_dataset1 = {"LD0", "LLN0$DS1", 16, &iedModelds_LD0_LLN0_dataset_D3_fcda0, 	&iedModelds_LD0_LLN0_dataset2};		//аналоги
DataSet iedModelds_LD0_LLN0_dataset2 = {"LD0", "LLN0$DS2",  2, &iedModelds_LD0_LLN0_dataset_D4_fcda0, 	&iedModelds_LD0_LLN0_dataset3};		//аналоги
DataSet iedModelds_LD0_LLN0_dataset3 = {"LD0", "LLN0$DS3",  3, &iedModelds_LD0_LLN0_dataset_D5_fcda0 ,	&iedModelds_LD0_LLN0_dataset4};		//индикация
DataSet iedModelds_LD0_LLN0_dataset4 = {"LD0", "LLN0$DS4",  0, NULL ,									&iedModelds_LD0_LLN0_dataset5};		//XCBR
DataSet iedModelds_LD0_LLN0_dataset5 = {"LD0", "LLN0$DS5",  0, NULL ,									&iedModelds_LD0_LLN0_dataset6};		//ошибки в жкрнале
DataSet iedModelds_LD0_LLN0_dataset6 = {"LD0", "LLN0$DS6",  6, &iedModelds_LD0_MMXU1_fcda0 ,			&iedModelds_LD0_LLN0_dataset7};		// мощности
DataSet iedModelds_LD0_LLN0_dataset7 = {"LD0", "LLN0$DS7",  6, &iedModelds_LD0_MMXU2_fcda0 ,			&iedModelds_LD0_LLN0_dataset8};
DataSet iedModelds_LD0_LLN0_dataset8 = {"LD0", "LLN0$DS8",  6, &iedModelds_LD0_MMXU3_fcda0 ,			&iedModelds_LD0_LLN0_dataset9};
DataSet iedModelds_LD0_LLN0_dataset9 = {"LD0", "LLN0$DS9",  9, &iedModelds_LD0_MMXU4_fcda0 ,			&iedModelds_LD0_LLN0_dataset10};
DataSet iedModelds_LD0_LLN0_dataset10 ={"LD0", "LLN0$DS10", 6, &iedModelds_LD0_MMXU5_fcda0 ,			NULL};


ReportControlBlock iedModel_LD0_LLN0_report0 = {
	&iedModel_LD0_LLN0,
	"URCB_101",
	"LLN0$BR$URCB_101",
	false,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS0",				// ссылка на набор данных для отчета
	0,					// ревизия конфигурации
	TRG_OPT_DATA_CHANGED,// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	50,					// BufTm буферное время мс
	0,					// IntPrd - период целостности в мс (1000)
	&iedModel_LD0_LLN0_report1
};

ReportControlBlock iedModel_LD0_LLN0_report1 = { &iedModel_LD0_LLN0, 	"URCB_201", "LLN0$BR$URCB_102",	false,"DS1", 0, TRG_OPT_INTEGRITY, 111, 100, 5000,	&iedModel_LD0_LLN0_report2};

ReportControlBlock iedModel_LD0_LLN0_report2 = { &iedModel_LD0_LLN0, 	"BRCB_101", "LLN0$BR$BRCB_101", true, "DS0", 0, TRG_OPT_INTEGRITY, 111,	3000, 5000,	&iedModel_LD0_LLN0_report3};
ReportControlBlock iedModel_LD0_LLN0_report3 = { &iedModel_LD0_LLN0, 	"BRCB_201", "LLN0$BR$BRCB_201", true, "DS1", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report4};
ReportControlBlock iedModel_LD0_LLN0_report4 = { &iedModel_LD0_LLN0, 	"BRCB_301", "LLN0$BR$BRCB_301", true, "DS2", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report5};
ReportControlBlock iedModel_LD0_LLN0_report5 = { &iedModel_LD0_LLN0, 	"BRCB_401", "LLN0$BR$BRCB_401", true, "DS3", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report6};
ReportControlBlock iedModel_LD0_LLN0_report6 = { &iedModel_LD0_LLN0, 	"BRCB_501", "LLN0$BR$BRCB_501", true, "DS4", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report7};
ReportControlBlock iedModel_LD0_LLN0_report7 = { &iedModel_LD0_LLN0, 	"BRCB_601", "LLN0$BR$BRCB_601", true, "DS5", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report8};
ReportControlBlock iedModel_LD0_LLN0_report8 = { &iedModel_LD0_LLN0, 	"BRCB_701", "LLN0$BR$BRCB_701", true, "DS6", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report9};
ReportControlBlock iedModel_LD0_LLN0_report9 = { &iedModel_LD0_LLN0, 	"BRCB_801", "LLN0$BR$BRCB_801", true, "DS7", 0, TRG_OPT_NO, 111, 3000, 5000, &iedModel_LD0_LLN0_report10};
ReportControlBlock iedModel_LD0_LLN0_report10 = { &iedModel_LD0_LLN0, 	"BRCB_901", "LLN0$BR$BRCB_901", true, "DS8", 0, TRG_OPT_NO, 111, 3000, 5000, NULL};


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
	NULL
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

#define Dir_not		0

static void		initializeValues()
{
	uint64_t currentTime;

USART_TRACE("\n");
USART_TRACE("initializeValues -------------------------------------------\n");

currentTime = Hal_getTimeInMs();

/******************************************************************************
 * LD0
 ******************************************************************************/
iedModel_LD0_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_LD0_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_LD0_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
iedModel_LD0_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//USART_TRACE("LD0_LLN0\n");
/******************************************************************************
 * PROT
 ******************************************************************************/
iedModel_PROT_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);				// PROT LLN0
iedModel_PROT_LLN0_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_LLN0_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_LLN0_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_PROT_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString("0");

iedModel_PROT_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_PROT_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);// не будет прокси
iedModel_PROT_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// IPTOC1...8
iedModel_PROT_IPTOC1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC7_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC7_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC7_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC8_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC8_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC8_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC9_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC9_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC9_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC10_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC10_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC10_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC11_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC11_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC11_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC12_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC12_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC12_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC13_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC13_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC13_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC14_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC14_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC14_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC15_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC15_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC15_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC16_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC16_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC16_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC17_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC17_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC17_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC18_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC18_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC18_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC19_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC19_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC19_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC20_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC20_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC20_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC21_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC21_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC21_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC22_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC22_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC22_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC23_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC23_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC23_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC24_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC24_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC24_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC25_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC25_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC25_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC26_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC26_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC26_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC27_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC27_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC27_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC28_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC28_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC28_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC29_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC29_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC29_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC30_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC30_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC30_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC31_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC31_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC31_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC32_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC32_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IPTOC32_Health_q.mmsValue = MmsValue_newBitString(0);


iedModel_PROT_IPTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC5_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC5_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC6_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC6_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC7_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC7_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC8_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC8_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC9_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC9_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC10_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC10_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC11_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC11_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC12_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC12_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC13_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC13_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC14_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC14_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC15_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC15_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC16_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC16_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC17_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC17_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC18_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC18_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC19_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC19_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC20_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC20_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC21_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC21_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC22_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC22_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC23_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC23_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC24_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC24_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC25_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC25_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC26_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC26_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC27_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC27_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC28_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC28_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC29_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC29_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC30_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC30_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC31_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC31_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC32_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC32_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);


//VZGGIO
iedModel_PROT_VZGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO5_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO5_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO6_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO6_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO7_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO7_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO8_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO8_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO9_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO9_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO10_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO10_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO11_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO11_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO12_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO12_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO13_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO13_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO14_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO14_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO15_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO15_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO16_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO16_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_VZGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);


#if defined (MR901)
//IDPDIF1
iedModel_PROT_IDPDIF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF1_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//IDPDIF2
iedModel_PROT_IDPDIF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF2_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//IDPDIF3
iedModel_PROT_IDPDIF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF3_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
#endif
#if defined (MR902)
//IDPDIF1
iedModel_PROT_IDPDIF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF1_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_RstA_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_RstA_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_DifACIc_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF1_DifACIc_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//IDPDIF2
iedModel_PROT_IDPDIF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF2_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_RstA_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_RstA_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_DifACIc_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF2_DifACIc_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//IDPDIF3
iedModel_PROT_IDPDIF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF3_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_RstA_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_RstA_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_DifACIc_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF3_DifACIc_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

#endif

//IDMPDIF1
iedModel_PROT_IDMPDIF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDMPDIF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDMPDIF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
//IDMPDIF2
iedModel_PROT_IDMPDIF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDMPDIF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDMPDIF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
//IDMPDIF3
iedModel_PROT_IDMPDIF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDMPDIF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDMPDIF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

//BUSRBRF1
iedModel_PROT_BUSRBRF1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_BUSRBRF1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_BUSRBRF1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BUSRBRF1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_BUSRBRF1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_BUSRBRF1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//BUSRBRF2
iedModel_PROT_BUSRBRF2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_BUSRBRF2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_BUSRBRF2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BUSRBRF2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_BUSRBRF2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_BUSRBRF2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//FRBRF1
iedModel_PROT_FRBRF1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_FRBRF1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//FRBRF2
iedModel_PROT_FRBRF2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_FRBRF2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//FRBRF3
iedModel_PROT_FRBRF3_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF3_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_FRBRF3_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF3_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//FRBRF4
iedModel_PROT_FRBRF4_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF4_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_FRBRF4_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF4_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//FRBRF5
iedModel_PROT_FRBRF5_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF5_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF5_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_FRBRF5_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_FRBRF5_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_FRBRF5_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//USART_TRACE("PROT\n");
/******************************************************************************
 * CTRL
 ******************************************************************************/
iedModel_CTRL_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_CTRL_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
//USART_TRACE("CTRL_LLN0\n");

iedModel_CTRL_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_CTRL_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);					// не будет прокси
iedModel_CTRL_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
//USART_TRACE("CTRL_LPHD1\n");

iedModel_CTRL_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//PTRC --------------------------------------------------------------------------------
iedModel_CTRL_PTRC_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_PTRC_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_PTRC_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_CTRL_PTRC_Op_q.mmsValue = MmsValue_newBitString(QUALITY_DETAIL_OLD_DATA);
iedModel_CTRL_PTRC_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_PTRC_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_PTRC_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_CTRL_PTRC_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_PTRC_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_PTRC_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_PTRC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_PTRC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//USART_TRACE("CTRL_PTRC\n");

//GGIO1 --------------------------------------------------------------------------------
iedModel_CTRL_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the alarm log");//Сброс флага новой записи в журнале аварий

//USART_TRACE("CTRL_GGIO1\n");
/******************************************************************************
 * GGIO
 ******************************************************************************/
iedModel_GGIO_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_GGIO_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_GGIO_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_GGIO_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

iedModel_GGIO_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
iedModel_GGIO_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//INGGIO1
iedModel_GGIO_INGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_INGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_INGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_GGIO_INGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_INGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//OUTGGIO1
iedModel_GGIO_OUTGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_GGIO_OUTGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_OUTGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_OUTGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//LEDGGIO1
iedModel_GGIO_LEDGGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);

iedModel_GGIO_LEDGGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Resetting the LEDs");//Сброс индикации

iedModel_GGIO_LEDGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_GGIO_LEDGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_GGIO_LEDGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);

iedModel_GGIO_LEDGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LEDGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_GGIO_LEDGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_q,0);
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_q,0);
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Health_q,0);

//SSL
iedModel_GGIO_SSLGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_SSLGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
//VLS
iedModel_GGIO_VLSGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_VLSGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
//LS
iedModel_GGIO_LSGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LSGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

/******************************************************************************
 * MES
 ******************************************************************************/
// MES LLN0
iedModel_MES_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_MES_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_MES_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_MES_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_MES_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_MES_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);

iedModel_MES_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_MES_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_MES_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);




USART_TRACE("------------------------------------------------------------\n");
}

#endif
