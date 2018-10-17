/*
 * static_model.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */

#if defined (MR5_500)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR5_500.h"
#include "IEC850.h"

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
extern DataSet iedModelds_LD0_LLN0_dataset11;
extern DataSet iedModelds_LD0_LLN0_dataset12;
extern DataSet iedModelds_LD0_LLN0_dataset13;
extern DataSet iedModelds_LD0_LLN0_dataset14;
extern DataSet iedModelds_LD0_LLN0_dataset15;
extern DataSet iedModelds_LD0_LLN0_dataset16;
extern DataSet iedModelds_LD0_LLN0_dataset17;
extern DataSet iedModelds_LD0_LLN0_dataset18;
extern DataSet iedModelds_LD0_LLN0_dataset19;
extern DataSet iedModelds_LD0_LLN0_dataset20;

// report
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
extern ReportControlBlock iedModel_LD0_LLN0_report11;
extern ReportControlBlock iedModel_LD0_LLN0_report12;
extern ReportControlBlock iedModel_LD0_LLN0_report13;
extern ReportControlBlock iedModel_LD0_LLN0_report14;
extern ReportControlBlock iedModel_LD0_LLN0_report15;
extern ReportControlBlock iedModel_LD0_LLN0_report16;
extern ReportControlBlock iedModel_LD0_LLN0_report17;
extern ReportControlBlock iedModel_LD0_LLN0_report18;
extern ReportControlBlock iedModel_LD0_LLN0_report19;
extern ReportControlBlock iedModel_LD0_LLN0_report20;

// gse
extern GSEControlBlock iedModel_LD0_LLN0_gse0;
extern GSEControlBlock iedModel_LD0_LLN0_gse1;

//-----
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda0;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda1;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda2;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda3;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda4;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda5;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda6;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda7;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda8;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda9;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda10;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda11;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda12;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda13;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda14;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda15;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda16;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda17;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda18;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda19;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda20;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda21;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda22;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda23;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda24;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda25;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda26;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda27;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda28;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda29;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda30;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda31;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda32;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda33;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda34;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda35;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda36;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda37;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda38;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda39;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda40;
extern	DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda41;


extern DataSetEntry iedModelds_LD0_MMXU1_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda5;
extern DataSetEntry iedModelds_LD0_MMXU1_fcda6;

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
extern DataSetEntry iedModelds_LD0_MMXU4_fcda9;
extern DataSetEntry iedModelds_LD0_MMXU4_fcda10;

extern DataSetEntry iedModelds_LD0_MMXU5_fcda0;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda1;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda2;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda3;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda4;
extern DataSetEntry iedModelds_LD0_MMXU5_fcda5;

extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda15;

extern DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda1;

extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda3;

extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda15;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda16;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda17;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda18;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda19;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda20;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda21;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda22;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda23;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda24;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda25;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda26;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda27;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda28;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda29;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda30;
extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda31;

extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda15;

extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda15;


extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda15;

extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda7;


extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda15;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda16;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda17;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda18;
extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda19;

extern DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda3;

extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda15;
extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda16;
/***********************************************************************
 * логические устройства
 ***********************************************************************/
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
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_dU;


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
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal;
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsA_q;
DataAttribute iedModel_MES_MMXU1_A_phsA_t;
DataAttribute iedModel_MES_MMXU1_A_phsA_db;
DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_A_phsB;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal;
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsB_q;
DataAttribute iedModel_MES_MMXU1_A_phsB_t;
DataAttribute iedModel_MES_MMXU1_A_phsB_db;
DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_A_phsC;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal;
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_phsC_q;
DataAttribute iedModel_MES_MMXU1_A_phsC_t;
DataAttribute iedModel_MES_MMXU1_A_phsC_db;
DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb;

DataObject iedModel_MES_MMXU1_A_neut;
DataAttribute iedModel_MES_MMXU1_A_neut_cVal;
DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag;
DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal;
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_A_neut_q;
DataAttribute iedModel_MES_MMXU1_A_neut_t;
DataAttribute iedModel_MES_MMXU1_A_neut_db;
DataAttribute iedModel_MES_MMXU1_A_neut_zeroDb;

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
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_t;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_db;
DataAttribute iedModel_MES_MSQI1_SeqA_c1_zeroDb;

DataObject iedModel_MES_MSQI1_SeqA_c2;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_t;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_db;
DataAttribute iedModel_MES_MSQI1_SeqA_c2_zeroDb;

DataObject iedModel_MES_MSQI1_SeqA_c3;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_q;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_t;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_db;
DataAttribute iedModel_MES_MSQI1_SeqA_c3_zeroDb;

DataAttribute iedModel_MES_MSQI1_SeqA_SeqT;

//****************************************************************************
// LN iPTOC1
LogicalNode   iedModel_PROT_IPTOC1;

DataObject    iedModel_PROT_IPTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC1_Mod_q;
DataAttribute iedModel_PROT_IPTOC1_Mod_t;
DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;
DataAttribute iedModel_PROT_IPTOC1_Mod_ctlModel;

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
DataAttribute iedModel_PROT_IPTOC2_Mod_ctlModel;

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
DataAttribute iedModel_PROT_IPTOC3_Mod_ctlModel;

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

// LN iPTOC1
LogicalNode   iedModel_PROT_IPTOC4;

DataObject    iedModel_PROT_IPTOC4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IPTOC4_Mod_q;
DataAttribute iedModel_PROT_IPTOC4_Mod_t;
DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;
DataAttribute iedModel_PROT_IPTOC4_Mod_ctlModel;

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


// LN iPTOC1
LogicalNode   iedModel_PROT_I2PTOC1;

DataObject    iedModel_PROT_I2PTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_I2PTOC1_Mod_q;
DataAttribute iedModel_PROT_I2PTOC1_Mod_t;
DataAttribute iedModel_PROT_I2PTOC1_Mod_stVal;
DataAttribute iedModel_PROT_I2PTOC1_Mod_ctlModel;

DataObject    iedModel_PROT_I2PTOC1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_I2PTOC1_Beh_stVal;
DataAttribute iedModel_PROT_I2PTOC1_Beh_q;
DataAttribute iedModel_PROT_I2PTOC1_Beh_t;

DataObject    iedModel_PROT_I2PTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_I2PTOC1_Health_stVal;
DataAttribute iedModel_PROT_I2PTOC1_Health_q;
DataAttribute iedModel_PROT_I2PTOC1_Health_t;

DataObject    iedModel_PROT_I2PTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_I2PTOC1_Str;
DataAttribute iedModel_PROT_I2PTOC1_Str_general;
DataAttribute iedModel_PROT_I2PTOC1_Str_dirGeneral;
DataAttribute iedModel_PROT_I2PTOC1_Str_q;
DataAttribute iedModel_PROT_I2PTOC1_Str_t;

DataObject    iedModel_PROT_I2PTOC1_Op;
DataAttribute iedModel_PROT_I2PTOC1_Op_general;
DataAttribute iedModel_PROT_I2PTOC1_Op_q;
DataAttribute iedModel_PROT_I2PTOC1_Op_t;


// LN iPTOC1
LogicalNode   iedModel_PROT_I2PTOC2;

DataObject    iedModel_PROT_I2PTOC2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_I2PTOC2_Mod_q;
DataAttribute iedModel_PROT_I2PTOC2_Mod_t;
DataAttribute iedModel_PROT_I2PTOC2_Mod_stVal;
DataAttribute iedModel_PROT_I2PTOC2_Mod_ctlModel;

DataObject    iedModel_PROT_I2PTOC2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_I2PTOC2_Beh_stVal;
DataAttribute iedModel_PROT_I2PTOC2_Beh_q;
DataAttribute iedModel_PROT_I2PTOC2_Beh_t;

DataObject    iedModel_PROT_I2PTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_I2PTOC2_Health_stVal;
DataAttribute iedModel_PROT_I2PTOC2_Health_q;
DataAttribute iedModel_PROT_I2PTOC2_Health_t;

DataObject    iedModel_PROT_I2PTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_I2PTOC2_Str;
DataAttribute iedModel_PROT_I2PTOC2_Str_general;
DataAttribute iedModel_PROT_I2PTOC2_Str_dirGeneral;
DataAttribute iedModel_PROT_I2PTOC2_Str_q;
DataAttribute iedModel_PROT_I2PTOC2_Str_t;

DataObject    iedModel_PROT_I2PTOC2_Op;
DataAttribute iedModel_PROT_I2PTOC2_Op_general;
DataAttribute iedModel_PROT_I2PTOC2_Op_q;
DataAttribute iedModel_PROT_I2PTOC2_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_I0PTOC1;

DataObject    iedModel_PROT_I0PTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_I0PTOC1_Mod_q;
DataAttribute iedModel_PROT_I0PTOC1_Mod_t;
DataAttribute iedModel_PROT_I0PTOC1_Mod_stVal;
DataAttribute iedModel_PROT_I0PTOC1_Mod_ctlModel;

DataObject    iedModel_PROT_I0PTOC1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_I0PTOC1_Beh_stVal;
DataAttribute iedModel_PROT_I0PTOC1_Beh_q;
DataAttribute iedModel_PROT_I0PTOC1_Beh_t;

DataObject    iedModel_PROT_I0PTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_I0PTOC1_Health_stVal;
DataAttribute iedModel_PROT_I0PTOC1_Health_q;
DataAttribute iedModel_PROT_I0PTOC1_Health_t;

DataObject    iedModel_PROT_I0PTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_I0PTOC1_Str;
DataAttribute iedModel_PROT_I0PTOC1_Str_general;
DataAttribute iedModel_PROT_I0PTOC1_Str_dirGeneral;
DataAttribute iedModel_PROT_I0PTOC1_Str_q;
DataAttribute iedModel_PROT_I0PTOC1_Str_t;

DataObject    iedModel_PROT_I0PTOC1_Op;
DataAttribute iedModel_PROT_I0PTOC1_Op_general;
DataAttribute iedModel_PROT_I0PTOC1_Op_q;
DataAttribute iedModel_PROT_I0PTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_I0PTOC2;

DataObject    iedModel_PROT_I0PTOC2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_I0PTOC2_Mod_q;
DataAttribute iedModel_PROT_I0PTOC2_Mod_t;
DataAttribute iedModel_PROT_I0PTOC2_Mod_stVal;
DataAttribute iedModel_PROT_I0PTOC2_Mod_ctlModel;

DataObject    iedModel_PROT_I0PTOC2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_I0PTOC2_Beh_stVal;
DataAttribute iedModel_PROT_I0PTOC2_Beh_q;
DataAttribute iedModel_PROT_I0PTOC2_Beh_t;

DataObject    iedModel_PROT_I0PTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_I0PTOC2_Health_stVal;
DataAttribute iedModel_PROT_I0PTOC2_Health_q;
DataAttribute iedModel_PROT_I0PTOC2_Health_t;

DataObject    iedModel_PROT_I0PTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_I0PTOC2_Str;
DataAttribute iedModel_PROT_I0PTOC2_Str_general;
DataAttribute iedModel_PROT_I0PTOC2_Str_dirGeneral;
DataAttribute iedModel_PROT_I0PTOC2_Str_q;
DataAttribute iedModel_PROT_I0PTOC2_Str_t;

DataObject    iedModel_PROT_I0PTOC2_Op;
DataAttribute iedModel_PROT_I0PTOC2_Op_general;
DataAttribute iedModel_PROT_I0PTOC2_Op_q;
DataAttribute iedModel_PROT_I0PTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_INPTOC1;

DataObject    iedModel_PROT_INPTOC1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_INPTOC1_Mod_q;
DataAttribute iedModel_PROT_INPTOC1_Mod_t;
DataAttribute iedModel_PROT_INPTOC1_Mod_stVal;
DataAttribute iedModel_PROT_INPTOC1_Mod_ctlModel;

DataObject    iedModel_PROT_INPTOC1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_INPTOC1_Beh_stVal;
DataAttribute iedModel_PROT_INPTOC1_Beh_q;
DataAttribute iedModel_PROT_INPTOC1_Beh_t;

DataObject    iedModel_PROT_INPTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_INPTOC1_Health_stVal;
DataAttribute iedModel_PROT_INPTOC1_Health_q;
DataAttribute iedModel_PROT_INPTOC1_Health_t;

DataObject    iedModel_PROT_INPTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_INPTOC1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_INPTOC1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_INPTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_INPTOC1_Str;
DataAttribute iedModel_PROT_INPTOC1_Str_general;
DataAttribute iedModel_PROT_INPTOC1_Str_dirGeneral;
DataAttribute iedModel_PROT_INPTOC1_Str_q;
DataAttribute iedModel_PROT_INPTOC1_Str_t;

DataObject    iedModel_PROT_INPTOC1_Op;
DataAttribute iedModel_PROT_INPTOC1_Op_general;
DataAttribute iedModel_PROT_INPTOC1_Op_q;
DataAttribute iedModel_PROT_INPTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_INPTOC2;

DataObject    iedModel_PROT_INPTOC2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_INPTOC2_Mod_q;
DataAttribute iedModel_PROT_INPTOC2_Mod_t;
DataAttribute iedModel_PROT_INPTOC2_Mod_stVal;
DataAttribute iedModel_PROT_INPTOC2_Mod_ctlModel;

DataObject    iedModel_PROT_INPTOC2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_INPTOC2_Beh_stVal;
DataAttribute iedModel_PROT_INPTOC2_Beh_q;
DataAttribute iedModel_PROT_INPTOC2_Beh_t;

DataObject    iedModel_PROT_INPTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_INPTOC2_Health_stVal;
DataAttribute iedModel_PROT_INPTOC2_Health_q;
DataAttribute iedModel_PROT_INPTOC2_Health_t;

DataObject    iedModel_PROT_INPTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_INPTOC2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_INPTOC2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_INPTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_INPTOC2_Str;
DataAttribute iedModel_PROT_INPTOC2_Str_general;
DataAttribute iedModel_PROT_INPTOC2_Str_dirGeneral;
DataAttribute iedModel_PROT_INPTOC2_Str_q;
DataAttribute iedModel_PROT_INPTOC2_Str_t;

DataObject    iedModel_PROT_INPTOC2_Op;
DataAttribute iedModel_PROT_INPTOC2_Op_general;
DataAttribute iedModel_PROT_INPTOC2_Op_q;
DataAttribute iedModel_PROT_INPTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_IGPTOC;

DataObject    iedModel_PROT_IGPTOC_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_IGPTOC_Mod_q;
DataAttribute iedModel_PROT_IGPTOC_Mod_t;
DataAttribute iedModel_PROT_IGPTOC_Mod_stVal;
DataAttribute iedModel_PROT_IGPTOC_Mod_ctlModel;

DataObject    iedModel_PROT_IGPTOC_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_IGPTOC_Beh_stVal;
DataAttribute iedModel_PROT_IGPTOC_Beh_q;
DataAttribute iedModel_PROT_IGPTOC_Beh_t;

DataObject    iedModel_PROT_IGPTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_IGPTOC_Health_stVal;
DataAttribute iedModel_PROT_IGPTOC_Health_q;
DataAttribute iedModel_PROT_IGPTOC_Health_t;

DataObject    iedModel_PROT_IGPTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_IGPTOC_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_IGPTOC_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_IGPTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_IGPTOC_Str;
DataAttribute iedModel_PROT_IGPTOC_Str_general;
//DataAttribute iedModel_PROT_IGPTOC_Str_dirGeneral;
DataAttribute iedModel_PROT_IGPTOC_Str_q;
DataAttribute iedModel_PROT_IGPTOC_Str_t;

DataObject    iedModel_PROT_IGPTOC_Op;
DataAttribute iedModel_PROT_IGPTOC_Op_general;
DataAttribute iedModel_PROT_IGPTOC_Op_q;
DataAttribute iedModel_PROT_IGPTOC_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_I2I1PTOC;

DataObject    iedModel_PROT_I2I1PTOC_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_I2I1PTOC_Mod_q;
DataAttribute iedModel_PROT_I2I1PTOC_Mod_t;
DataAttribute iedModel_PROT_I2I1PTOC_Mod_stVal;
DataAttribute iedModel_PROT_I2I1PTOC_Mod_ctlModel;

DataObject    iedModel_PROT_I2I1PTOC_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_I2I1PTOC_Beh_stVal;
DataAttribute iedModel_PROT_I2I1PTOC_Beh_q;
DataAttribute iedModel_PROT_I2I1PTOC_Beh_t;

DataObject    iedModel_PROT_I2I1PTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_I2I1PTOC_Health_stVal;
DataAttribute iedModel_PROT_I2I1PTOC_Health_q;
DataAttribute iedModel_PROT_I2I1PTOC_Health_t;

DataObject    iedModel_PROT_I2I1PTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_I2I1PTOC_Str;
DataAttribute iedModel_PROT_I2I1PTOC_Str_general;
DataAttribute iedModel_PROT_I2I1PTOC_Str_dirGeneral;
DataAttribute iedModel_PROT_I2I1PTOC_Str_q;
DataAttribute iedModel_PROT_I2I1PTOC_Str_t;

DataObject    iedModel_PROT_I2I1PTOC_Op;
DataAttribute iedModel_PROT_I2I1PTOC_Op_general;
DataAttribute iedModel_PROT_I2I1PTOC_Op_q;
DataAttribute iedModel_PROT_I2I1PTOC_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_LZSHPTOC;

DataObject    iedModel_PROT_LZSHPTOC_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_LZSHPTOC_Mod_q;
DataAttribute iedModel_PROT_LZSHPTOC_Mod_t;
DataAttribute iedModel_PROT_LZSHPTOC_Mod_stVal;
DataAttribute iedModel_PROT_LZSHPTOC_Mod_ctlModel;

DataObject    iedModel_PROT_LZSHPTOC_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_LZSHPTOC_Beh_stVal;
DataAttribute iedModel_PROT_LZSHPTOC_Beh_q;
DataAttribute iedModel_PROT_LZSHPTOC_Beh_t;

DataObject    iedModel_PROT_LZSHPTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_LZSHPTOC_Health_stVal;
DataAttribute iedModel_PROT_LZSHPTOC_Health_q;
DataAttribute iedModel_PROT_LZSHPTOC_Health_t;

DataObject    iedModel_PROT_LZSHPTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_LZSHPTOC_Str;
DataAttribute iedModel_PROT_LZSHPTOC_Str_general;
DataAttribute iedModel_PROT_LZSHPTOC_Str_dirGeneral;
DataAttribute iedModel_PROT_LZSHPTOC_Str_q;
DataAttribute iedModel_PROT_LZSHPTOC_Str_t;

DataObject    iedModel_PROT_LZSHPTOC_Op;
DataAttribute iedModel_PROT_LZSHPTOC_Op_general;
DataAttribute iedModel_PROT_LZSHPTOC_Op_q;
DataAttribute iedModel_PROT_LZSHPTOC_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_RREC;

DataObject    iedModel_PROT_RREC_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_RREC_Mod_q;
DataAttribute iedModel_PROT_RREC_Mod_t;
DataAttribute iedModel_PROT_RREC_Mod_stVal;
DataAttribute iedModel_PROT_RREC_Mod_ctlModel;

DataObject    iedModel_PROT_RREC_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_RREC_Beh_stVal;
DataAttribute iedModel_PROT_RREC_Beh_q;
DataAttribute iedModel_PROT_RREC_Beh_t;

DataObject    iedModel_PROT_RREC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_RREC_Health_stVal;
DataAttribute iedModel_PROT_RREC_Health_q;
DataAttribute iedModel_PROT_RREC_Health_t;

DataObject    iedModel_PROT_RREC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_RREC_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_RREC_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_RREC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject 	  iedModel_PROT_RREC_AutoRecSt;
DataAttribute iedModel_PROT_RREC_AutoRecSt_stVal;
DataAttribute iedModel_PROT_RREC_AutoRecSt_q;
DataAttribute iedModel_PROT_RREC_AutoRecSt_t;

DataObject    iedModel_PROT_RREC_Op;
DataAttribute iedModel_PROT_RREC_Op_general;
DataAttribute iedModel_PROT_RREC_Op_q;
DataAttribute iedModel_PROT_RREC_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_RBRF;

DataObject    iedModel_PROT_RBRF_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_RBRF_Mod_q;
DataAttribute iedModel_PROT_RBRF_Mod_t;
DataAttribute iedModel_PROT_RBRF_Mod_stVal;
DataAttribute iedModel_PROT_RBRF_Mod_ctlModel;

DataObject    iedModel_PROT_RBRF_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_RBRF_Beh_stVal;
DataAttribute iedModel_PROT_RBRF_Beh_q;
DataAttribute iedModel_PROT_RBRF_Beh_t;

DataObject    iedModel_PROT_RBRF_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_RBRF_Health_stVal;
DataAttribute iedModel_PROT_RBRF_Health_q;
DataAttribute iedModel_PROT_RBRF_Health_t;

DataObject    iedModel_PROT_RBRF_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_RBRF_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_RBRF_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_RBRF_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_RBRF_OpExEx;
DataAttribute iedModel_PROT_RBRF_OpEx_general;
DataAttribute iedModel_PROT_RBRF_OpEx_q;
DataAttribute iedModel_PROT_RBRF_OpEx_t;

//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_AVRGGIO;

DataObject iedModel_PROT_AVRGGIO_Mod;
DataAttribute iedModel_PROT_AVRGGIO_Mod_q;
DataAttribute iedModel_PROT_AVRGGIO_Mod_t;
DataAttribute iedModel_PROT_AVRGGIO_Mod_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Mod_ctlModel;


DataObject iedModel_PROT_AVRGGIO_Beh;
DataAttribute iedModel_PROT_AVRGGIO_Beh_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Beh_q;
DataAttribute iedModel_PROT_AVRGGIO_Beh_t;

DataObject iedModel_PROT_AVRGGIO_Health;
DataAttribute iedModel_PROT_AVRGGIO_Health_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Health_q;
DataAttribute iedModel_PROT_AVRGGIO_Health_t;

DataObject iedModel_PROT_AVRGGIO_NamPlt;

DataAttribute iedModel_PROT_AVRGGIO_NamPlt_vendor;
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_swRev;
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_d;

DataObject iedModel_PROT_AVRGGIO_IntIn;
DataAttribute iedModel_PROT_AVRGGIO_IntIn_stVal;
DataAttribute iedModel_PROT_AVRGGIO_IntIn_q;
DataAttribute iedModel_PROT_AVRGGIO_IntIn_t;

/*
DataObject iedModel_PROT_AVRGGIO_Ind1;
DataAttribute iedModel_PROT_AVRGGIO_Ind1_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Ind1_q;
DataAttribute iedModel_PROT_AVRGGIO_Ind1_t;

DataObject iedModel_PROT_AVRGGIO_Ind2;
DataAttribute iedModel_PROT_AVRGGIO_Ind2_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Ind2_q;
DataAttribute iedModel_PROT_AVRGGIO_Ind2_t;

DataObject iedModel_PROT_AVRGGIO_Ind3;
DataAttribute iedModel_PROT_AVRGGIO_Ind3_stVal;
DataAttribute iedModel_PROT_AVRGGIO_Ind3_q;
DataAttribute iedModel_PROT_AVRGGIO_Ind3_t;
*/
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO1;

DataObject iedModel_PROT_VZGGIO1_Mod;
DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO2;

DataObject iedModel_PROT_VZGGIO2_Mod;
DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO3;

DataObject iedModel_PROT_VZGGIO3_Mod;
DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO4;

DataObject iedModel_PROT_VZGGIO4_Mod;
DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO5;

DataObject iedModel_PROT_VZGGIO5_Mod;
DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel;


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

//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO6;

DataObject iedModel_PROT_VZGGIO6_Mod;
DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO7;

DataObject iedModel_PROT_VZGGIO7_Mod;
DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel;


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


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO8;

DataObject iedModel_PROT_VZGGIO8_Mod;
DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;
DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel;


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


//****************************************************************************
// LN CSWI
// -----------------------------------------------------------------------------


LogicalNode   iedModel_CTRL_CSWI1;

// Mod																// обязательные элементы -------------------------------------
DataObject    iedModel_CTRL_CSWI1_Mod;					// РЕЖИМ
DataAttribute iedModel_CTRL_CSWI1_Mod_q;
DataAttribute iedModel_CTRL_CSWI1_Mod_t;
DataAttribute iedModel_CTRL_CSWI1_Mod_stVal;
DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test;
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check;


// Beh
DataObject    iedModel_CTRL_CSWI1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_CTRL_CSWI1_Beh_stVal;
DataAttribute iedModel_CTRL_CSWI1_Beh_q;
DataAttribute iedModel_CTRL_CSWI1_Beh_t;

// Health
DataObject    iedModel_CTRL_CSWI1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_CTRL_CSWI1_Health_stVal;
DataAttribute iedModel_CTRL_CSWI1_Health_q;
DataAttribute iedModel_CTRL_CSWI1_Health_t;

// NamPlt
DataObject    iedModel_CTRL_CSWI1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev;		// 		Ревизия программной части
DataAttribute iedModel_CTRL_CSWI1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN CSWI1.


DataObject iedModel_CTRL_CSWI1_Pos;
DataAttribute iedModel_CTRL_CSWI1_Pos_stVal;
DataAttribute iedModel_CTRL_CSWI1_Pos_q;
DataAttribute iedModel_CTRL_CSWI1_Pos_t;
DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test;
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check;
//****************************************************************************
// LN XCBR1
// -----------------------------------------------------------------------------
LogicalNode iedModel_CTRL_XCBR1;
DataObject iedModel_CTRL_XCBR1_Mod;
DataAttribute iedModel_CTRL_XCBR1_Mod_q;
DataAttribute iedModel_CTRL_XCBR1_Mod_t;
DataAttribute iedModel_CTRL_XCBR1_Mod_stVal;
DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test;
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check;

DataObject iedModel_CTRL_XCBR1_Beh;
DataAttribute iedModel_CTRL_XCBR1_Beh_stVal;
DataAttribute iedModel_CTRL_XCBR1_Beh_q;
DataAttribute iedModel_CTRL_XCBR1_Beh_t;

DataObject iedModel_CTRL_XCBR1_Health;
DataAttribute iedModel_CTRL_XCBR1_Health_stVal;
DataAttribute iedModel_CTRL_XCBR1_Health_q;
DataAttribute iedModel_CTRL_XCBR1_Health_t;

DataObject iedModel_CTRL_XCBR1_NamPlt;
DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor;
DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev;
DataAttribute iedModel_CTRL_XCBR1_NamPlt_d;

DataObject iedModel_CTRL_XCBR1_Pos;
DataAttribute iedModel_CTRL_XCBR1_Pos_stVal;
DataAttribute iedModel_CTRL_XCBR1_Pos_q;
DataAttribute iedModel_CTRL_XCBR1_Pos_t;
DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel;

DataObject iedModel_CTRL_XCBR1_Loc;
DataAttribute iedModel_CTRL_XCBR1_Loc_stVal;
DataAttribute iedModel_CTRL_XCBR1_Loc_q;
DataAttribute iedModel_CTRL_XCBR1_Loc_t;

DataObject iedModel_CTRL_XCBR1_OpCnt;
DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal;
DataAttribute iedModel_CTRL_XCBR1_OpCnt_q;
DataAttribute iedModel_CTRL_XCBR1_OpCnt_t;

DataObject iedModel_CTRL_XCBR1_CBOpCap;
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal;
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q;
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t;

DataObject iedModel_CTRL_XCBR1_BlkOpn;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test;
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check;

DataObject iedModel_CTRL_XCBR1_BlkCls;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_q;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_t;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test;
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check;

//-PTRC --------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
// GGIO1
//----------------------------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1;

DataObject iedModel_CTRL_GGIO1_Mod;
DataAttribute iedModel_CTRL_GGIO1_Mod_q;
DataAttribute iedModel_CTRL_GGIO1_Mod_t;
DataAttribute iedModel_CTRL_GGIO1_Mod_stVal;
DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel;

DataObject iedModel_CTRL_GGIO1_Beh;
DataAttribute iedModel_CTRL_GGIO1_Beh_stVal;
DataAttribute iedModel_CTRL_GGIO1_Beh_q;
DataAttribute iedModel_CTRL_GGIO1_Beh_t;

DataObject iedModel_CTRL_GGIO1_Health;
DataAttribute iedModel_CTRL_GGIO1_Health_stVal;
DataAttribute iedModel_CTRL_GGIO1_Health_q;
DataAttribute iedModel_CTRL_GGIO1_Health_t;

DataObject iedModel_CTRL_GGIO1_NamPlt;
DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor;
DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev;
DataAttribute iedModel_CTRL_GGIO1_NamPlt_d;

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

//SPCSO4
DataObject iedModel_CTRL_GGIO1_SPCSO4;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test;
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check;
//****************************************************************************

IedModel iedModel = {
    "MR5PO50",
    &iedModel_Generic_LD0,
    &iedModelds_LD0_LLN0_dataset0,		// DataSet
    &iedModel_LD0_LLN0_report0,			// ReportControlBlock
    NULL,//&iedModel_LD0_LLN0_gse0,			// GSEControlBlock
    NULL,								// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,			// SettingGroupControlBlock
    NULL,								// lcbs
    NULL,								// log
    initializeValues
};

/*************************************************************************
 * Логические устройства LD
 *
 *************************************************************************/

LogicalDevice iedModel_Generic_LD0 = {
    LogicalDeviceModelType,
    "LD0",								// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_PROT,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_LD0_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_PROT = {
    LogicalDeviceModelType,
    "PROT",								// имя нашего логического устройства		//
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_CTRL,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_PROT_LLN0			// первый LN(логический узел)
};

LogicalDevice iedModel_Generic_CTRL = {
    LogicalDeviceModelType,
    "CTRL",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_MES,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_CTRL_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_MES = {
    LogicalDeviceModelType,
    "MES",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    (ModelNode*)&iedModel_Generic_GGIO,		// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_MES_LLN0			// первый LN(логический узел)
};
LogicalDevice iedModel_Generic_GGIO = {
    LogicalDeviceModelType,
    "GGIO",								// имя нашего логического устройства		//"simpleIOGenericIO"
    (ModelNode*)&iedModel,					// родитель (IedModel)
    NULL,									// одноранговый следующий узел				// родитель
    (ModelNode*)&iedModel_GGIO_LLN0			// первый LN(логический узел)
};
/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_LD0_LLN0 					= {    LogicalNodeModelType,   "LLN0",	    (ModelNode*)&iedModel_Generic_LD0,	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod 				= {    DataObjectModelType,	   "Mod",	    (ModelNode*) &iedModel_LD0_LLN0,	    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel 	= {    DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_LD0_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Beh 				= {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_LD0_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_Health 			= {    DataObjectModelType,    "Health",	(ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal 	= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q 		= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t 		= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_LD0_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt 			= {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_LD0_LLN0,    NULL,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor 	= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev 	= {    DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d 		= {    DataAttributeModelType, "d",    		(ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev= {    DataAttributeModelType, "configRev",	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs 	= {    DataAttributeModelType, "ldNs",    	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_PROT_LLN0 					= {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_PROT,	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LLN0_Mod};

DataObject iedModel_PROT_LLN0_Mod 				= {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_PROT_LLN0,	    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Mod_q,    0};
DataAttribute iedModel_PROT_LLN0_Mod_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel 	= {    DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_PROT_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Beh 				= {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Beh_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Beh_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_Health 			= {    DataObjectModelType,    "Health",	(ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_Health_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Health_stVal 	= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_q 		= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_t 		= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_NamPlt	 		= {    DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_PROT_LLN0,    NULL,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor 	= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev 	= {    DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_d 		= {    DataAttributeModelType, "d",    		(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev = {  DataAttributeModelType, "configRev",	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs 	= {    DataAttributeModelType, "ldNs",    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 					= {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,	   (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod 				= {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel 	= {    DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh 				= {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health 			= {    DataObjectModelType,    "Health",	(ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal 	= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q 		= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t 		= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt 			= {    DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_CTRL_LLN0,    NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor 	= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev 	= {    DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d 		= {    DataAttributeModelType, "d",    		(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev = {  DataAttributeModelType, "configRev",	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs 	= {    DataAttributeModelType, "ldNs",    	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/************************************************************************
 * MES_LLN0
 *************************************************************************/
LogicalNode iedModel_MES_LLN0 					= {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_MES,	   (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LLN0_Mod,};

DataObject iedModel_MES_LLN0_Mod 				= {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_MES_LLN0,	    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Mod_q,    0};
DataAttribute iedModel_MES_LLN0_Mod_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_ctlModel 	= {    DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_MES_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_Beh 				= {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Beh_stVal,    0};
DataAttribute iedModel_MES_LLN0_Beh_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_MES_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_Health 			= {    DataObjectModelType,    "Health",	(ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_Health_stVal,    0};
DataAttribute iedModel_MES_LLN0_Health_stVal 	= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_q 		= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_t 		= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_MES_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_NamPlt 			= {    DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_MES_LLN0,    NULL,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_vendor 	= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_swRev	= {    DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_d 		= {    DataAttributeModelType, "d",    		(ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_configRev= {    DataAttributeModelType, "configRev",	(ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_ldNs 	= {    DataAttributeModelType, "ldNs",    	(ModelNode*) &iedModel_MES_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/************************************************************************
 * GGIO_LLN0
 *************************************************************************/
LogicalNode iedModel_GGIO_LLN0 					= {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_GGIO,	 (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LLN0_Mod,};

DataObject iedModel_GGIO_LLN0_Mod 				= {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_GGIO_LLN0,	    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_q,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel 	= {    DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_GGIO_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Beh 				= {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_stVal 		= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_q 			= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_t 			= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_GGIO_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Health 			= {    DataObjectModelType,    "Health",	(ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_Health_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Health_stVal 	= {    DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_q 		= {    DataAttributeModelType, "q",    		(ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_t 		= {    DataAttributeModelType, "t",    		(ModelNode*) &iedModel_GGIO_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_NamPlt 			= {    DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_GGIO_LLN0,    NULL,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor 	= {    DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev	= {    DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_d 		= {    DataAttributeModelType, "d",    		(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev= {   DataAttributeModelType, "configRev",	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs 	= {    DataAttributeModelType, "ldNs",    	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_LD0_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,  NULL,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    NULL,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_LD0_LPHD1_Proxy, (ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_PROT_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

DataObject iedModel_PROT_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_PROT_LPHD1,    NULL,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_PROT_LPHD1_Proxy, (ModelNode*) &iedModel_PROT_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_PROT_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел CTRL_LPHD1
 *************************************************************************/
LogicalNode iedModel_CTRL_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_CTRL_LPHD1_Proxy, (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел MES_LPHD1
 *************************************************************************/
LogicalNode iedModel_MES_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};

DataObject iedModel_MES_LPHD1_PhyNam = 				{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_MES_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal = 	{    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_MES_LPHD1,    NULL,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_MES_LPHD1_Proxy, (ModelNode*) &iedModel_MES_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_MES_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел GGIO_LPHD1
 *************************************************************************/
LogicalNode iedModel_GGIO_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

DataObject iedModel_GGIO_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_GGIO_LPHD1,    NULL,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LPHD1_Proxy, (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_GGIO_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


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
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1 /* &iedModel_GGIO_INGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 ****************************************************************************************************************************************************************/
DataObject iedModel_GGIO_INGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind13 = { DataObjectModelType, "Ind13", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind14 = { DataObjectModelType, "Ind14", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind15 = { DataObjectModelType, "Ind15", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind16 = { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)NULL , (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/
LogicalNode iedModel_GGIO_OUTGGIO1 						= { LogicalNodeModelType,   	"OUT8GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};

DataObject iedModel_GGIO_OUTGGIO1_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod, (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GGIO_OUTGGIO1_Beh 					= {    DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q 				= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t 				= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_GGIO_OUTGGIO1_Health 					= {    DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal 		= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q 			= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t 			= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_GGIO_OUTGGIO1_NamPlt 					= {    DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor 		= {    DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev 		= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d 			= {    DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_OUTGGIO1_SPCSO1 					= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO2 					= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*)  &iedModel_GGIO_OUTGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO3 					= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO4 					= {    DataObjectModelType,     "SPCSO4",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO5 					= {    DataObjectModelType,     "SPCSO5",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO6 					= {    DataObjectModelType,     "SPCSO6",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO7 					= {    DataObjectModelType,     "SPCSO7",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO8 					= {    DataObjectModelType,     "SPCSO8",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};


/*************************************************************************
 * LED12GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_LEDGGIO1 					= { LogicalNodeModelType,   "LED12GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

DataObject iedModel_GGIO_LEDGGIO1_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind1,  (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_LEDGGIO1_Ind1 			= {DataObjectModelType,"Ind1",		(ModelNode*) &iedModel_GGIO_LEDGGIO1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q 	= {DataAttributeModelType,"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t 	= {DataAttributeModelType,"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_dU,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q = {    DataAttributeModelType,    "q",  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t = {    DataAttributeModelType,    "t",  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_SSLGGIO1 			= { LogicalNodeModelType,   "SSL24GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod};

DataObject iedModel_GGIO_SSLGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*)&iedModel_GGIO_SSLGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind17 = {DataObjectModelType,"Ind17",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind18 = {DataObjectModelType,"Ind18",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind19 = {DataObjectModelType,"Ind19",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind20 = {DataObjectModelType,"Ind20",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind21 = {DataObjectModelType,"Ind21",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind22 = {DataObjectModelType,"Ind22",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind23 = {DataObjectModelType,"Ind23",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind24 = {DataObjectModelType,"Ind24",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_VLSGGIO1 			= { LogicalNodeModelType,   "VLS8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod};

DataObject iedModel_GGIO_VLSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*)&iedModel_GGIO_VLSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LSGGIO1 			= { LogicalNodeModelType,   "LS8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod};

DataObject iedModel_GGIO_LSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*)&iedModel_GGIO_LSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

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
DataAttribute iedModel_MES_MMXU1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MMXU1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_MMXU1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MMXU1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*) &iedModel_MES_MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_MES_MMXU1_A 						= { DataObjectModelType, "A", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsA, 0 };

DataObject iedModel_MES_MMXU1_A_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_instCVal, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsA, (ModelNode*) &iedModel_MES_MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_A_phsB 					= { DataObjectModelType, "phsB", 		(ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)&iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_instCVal, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*)&iedModel_MES_MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsB, (ModelNode*) &iedModel_MES_MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_A_phsC 					= { DataObjectModelType, "phsC", 		(ModelNode*) &iedModel_MES_MMXU1_A, 		(ModelNode*)&iedModel_MES_MMXU1_A_neut, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsC, 	(ModelNode*) &iedModel_MES_MMXU1_A_phsC_instCVal, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_A_phsC, 				(ModelNode*) &iedModel_MES_MMXU1_A_phsC_q,  (ModelNode*) &iedModel_MES_MMXU1_A_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_MMXU1_A_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_MMXU1_A_phsC, (ModelNode*) &iedModel_MES_MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_A_neut 					= { DataObjectModelType, "neut", (ModelNode*) &iedModel_MES_MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_A_neut_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_A_neut_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_A_neut, (ModelNode*) &iedModel_MES_MMXU1_A_neut_instCVal, (ModelNode*) &iedModel_MES_MMXU1_A_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_A_neut_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_A_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_A_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_A_neut, 				(ModelNode*) &iedModel_MES_MMXU1_A_neut_q,  (ModelNode*) &iedModel_MES_MMXU1_A_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_MMXU1_A_neut_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_MMXU1_A_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_MMXU1_A_neut_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_A_neut, (ModelNode*) &iedModel_MES_MMXU1_A_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_A_neut,  (ModelNode*) &iedModel_MES_MMXU1_A_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_A_neut_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_A_neut, (ModelNode*) &iedModel_MES_MMXU1_A_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_A_neut_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_A_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//--------------------------------------
LogicalNode iedModel_MES_MSQI1 						= {    LogicalNodeModelType,    "MSQI1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)NULL,    (ModelNode*) &iedModel_MES_MSQI1_Mod};

DataObject iedModel_MES_MSQI1_Mod 					= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Mod_q,0};
DataAttribute iedModel_MES_MSQI1_Mod_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_stVal 			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MSQI1_Beh 					= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_MSQI1_Beh_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MSQI1_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_MSQI1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MSQI1_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_SeqA, (ModelNode*) &iedModel_MES_MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_vendor 		= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_swRev	 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// SeqA
DataObject iedModel_MES_MSQI1_SeqA 						= { DataObjectModelType, "SeqA", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*) NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, 0 };

DataObject iedModel_MES_MSQI1_SeqA_c1 					= { DataObjectModelType, "c1", (ModelNode*) &iedModel_MES_MSQI1_SeqA, (ModelNode*)&iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_q, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag_f = { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c1_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c1_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c1, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MSQI1_SeqA_c2 					= { DataObjectModelType, "c2", (ModelNode*) &iedModel_MES_MSQI1_SeqA, (ModelNode*)&iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_q, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag_f	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c2_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c2_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c2, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MSQI1_SeqA_c3 					= { DataObjectModelType, "c3", (ModelNode*) &iedModel_MES_MSQI1_SeqA, (ModelNode*) &iedModel_MES_MSQI1_SeqA_SeqT, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_q, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag_f = { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqA_c3_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqA_c3_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqA_c3, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataAttribute iedModel_MES_MSQI1_SeqA_SeqT 				= { DataAttributeModelType, "seqT", (ModelNode*) &iedModel_MES_MSQI1_SeqA, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};

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
LogicalNode iedModel_PROT_IPTOC1 = {    LogicalNodeModelType,    "IPTOC1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod};

DataObject iedModel_PROT_IPTOC1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Str, (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC1,  	(ModelNode*)&iedModel_PROT_IPTOC1_Op, (ModelNode*) &iedModel_PROT_IPTOC1_Str_general,0};
DataAttribute iedModel_PROT_IPTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC1_Str,  (ModelNode*) &iedModel_PROT_IPTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC1_Op_general,0};
DataAttribute iedModel_PROT_IPTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC1_Op,  (ModelNode*) &iedModel_PROT_IPTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC1_Op,  (ModelNode*) &iedModel_PROT_IPTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

LogicalNode iedModel_PROT_IPTOC2 = {    LogicalNodeModelType,    "IPTOC2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod};

DataObject iedModel_PROT_IPTOC2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Str, (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)&iedModel_PROT_IPTOC2_Op, (ModelNode*) &iedModel_PROT_IPTOC2_Str_general,0};
DataAttribute iedModel_PROT_IPTOC2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC2_Op_general,0};
DataAttribute iedModel_PROT_IPTOC2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

LogicalNode iedModel_PROT_IPTOC3 = {    LogicalNodeModelType,    "IPTOC3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod};

DataObject iedModel_PROT_IPTOC3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Str, (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)&iedModel_PROT_IPTOC3_Op, (ModelNode*) &iedModel_PROT_IPTOC3_Str_general,0};
DataAttribute iedModel_PROT_IPTOC3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC3_Op_general,0};
DataAttribute iedModel_PROT_IPTOC3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_IPTOC4 = {    LogicalNodeModelType,    "IPTOC4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_I2PTOC1,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod};

DataObject iedModel_PROT_IPTOC4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Str, (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)&iedModel_PROT_IPTOC4_Op, (ModelNode*) &iedModel_PROT_IPTOC4_Str_general,0};
DataAttribute iedModel_PROT_IPTOC4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC4_Op_general,0};
DataAttribute iedModel_PROT_IPTOC4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_I2PTOC1 = {    LogicalNodeModelType,    "I2PTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I2PTOC2,    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod};

DataObject iedModel_PROT_I2PTOC1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I2PTOC1,    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod_q,0};
DataAttribute iedModel_PROT_I2PTOC1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I2PTOC1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I2PTOC1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I2PTOC1,    (ModelNode*) &iedModel_PROT_I2PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_I2PTOC1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2PTOC1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I2PTOC1,    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_I2PTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2PTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2PTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2PTOC1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I2PTOC1,    (ModelNode*) &iedModel_PROT_I2PTOC1_Str, (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I2PTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I2PTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I2PTOC1,  	(ModelNode*)&iedModel_PROT_I2PTOC1_Op, (ModelNode*) &iedModel_PROT_I2PTOC1_Str_general,0};
DataAttribute iedModel_PROT_I2PTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2PTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I2PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2PTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2PTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2PTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I2PTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I2PTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I2PTOC1_Op_general,0};
DataAttribute iedModel_PROT_I2PTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2PTOC1_Op,  (ModelNode*) &iedModel_PROT_I2PTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2PTOC1_Op,  (ModelNode*) &iedModel_PROT_I2PTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2PTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_I2PTOC2 = {    LogicalNodeModelType,    "I2PTOC2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I0PTOC1,    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod};

DataObject iedModel_PROT_I2PTOC2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I2PTOC2,    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod_q,0};
DataAttribute iedModel_PROT_I2PTOC2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I2PTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I2PTOC2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I2PTOC2,    (ModelNode*) &iedModel_PROT_I2PTOC2_Health,    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_I2PTOC2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2PTOC2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I2PTOC2,    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_I2PTOC2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2PTOC2_Health,    (ModelNode*) &iedModel_PROT_I2PTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2PTOC2_Health,    (ModelNode*) &iedModel_PROT_I2PTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2PTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2PTOC2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I2PTOC2,    (ModelNode*) &iedModel_PROT_I2PTOC2_Str, (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I2PTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I2PTOC2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I2PTOC2,  	(ModelNode*)&iedModel_PROT_I2PTOC2_Op, (ModelNode*) &iedModel_PROT_I2PTOC2_Str_general,0};
DataAttribute iedModel_PROT_I2PTOC2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2PTOC2_Str,  (ModelNode*) &iedModel_PROT_I2PTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I2PTOC2_Str,  (ModelNode*) &iedModel_PROT_I2PTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2PTOC2_Str,  (ModelNode*) &iedModel_PROT_I2PTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2PTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I2PTOC2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I2PTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I2PTOC2_Op_general,0};
DataAttribute iedModel_PROT_I2PTOC2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2PTOC2_Op,  (ModelNode*) &iedModel_PROT_I2PTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2PTOC2_Op,  (ModelNode*) &iedModel_PROT_I2PTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2PTOC2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2PTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_I0PTOC1 = {    LogicalNodeModelType,    "I0PTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I0PTOC2,    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod};

DataObject iedModel_PROT_I0PTOC1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I0PTOC1,    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod_q,0};
DataAttribute iedModel_PROT_I0PTOC1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I0PTOC1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I0PTOC1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I0PTOC1,    (ModelNode*) &iedModel_PROT_I0PTOC1_Health,    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_I0PTOC1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I0PTOC1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I0PTOC1,    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_I0PTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I0PTOC1_Health,    (ModelNode*) &iedModel_PROT_I0PTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC1_Health,    (ModelNode*) &iedModel_PROT_I0PTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I0PTOC1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I0PTOC1,    (ModelNode*) &iedModel_PROT_I0PTOC1_Str, (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I0PTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I0PTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I0PTOC1,  	(ModelNode*)&iedModel_PROT_I0PTOC1_Op, (ModelNode*) &iedModel_PROT_I0PTOC1_Str_general,0};
DataAttribute iedModel_PROT_I0PTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I0PTOC1_Str,  (ModelNode*) &iedModel_PROT_I0PTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I0PTOC1_Str,  (ModelNode*) &iedModel_PROT_I0PTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I0PTOC1_Str,  (ModelNode*) &iedModel_PROT_I0PTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I0PTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I0PTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I0PTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I0PTOC1_Op_general,0};
DataAttribute iedModel_PROT_I0PTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I0PTOC1_Op,  (ModelNode*) &iedModel_PROT_I0PTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I0PTOC1_Op,  (ModelNode*) &iedModel_PROT_I0PTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I0PTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_I0PTOC2 = {    LogicalNodeModelType,    "I0PTOC2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_INPTOC1,    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod};

DataObject iedModel_PROT_I0PTOC2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I0PTOC2,    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod_q,0};
DataAttribute iedModel_PROT_I0PTOC2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I0PTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I0PTOC2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I0PTOC2,    (ModelNode*) &iedModel_PROT_I0PTOC2_Health,    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_I0PTOC2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I0PTOC2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I0PTOC2,    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_I0PTOC2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I0PTOC2_Health,    (ModelNode*) &iedModel_PROT_I0PTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I0PTOC2_Health,    (ModelNode*) &iedModel_PROT_I0PTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I0PTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I0PTOC2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I0PTOC2,    (ModelNode*) &iedModel_PROT_I0PTOC2_Str, (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I0PTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I0PTOC2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I0PTOC2,  	(ModelNode*)&iedModel_PROT_I0PTOC2_Op, (ModelNode*) &iedModel_PROT_I0PTOC2_Str_general,0};
DataAttribute iedModel_PROT_I0PTOC2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I0PTOC2_Str,  (ModelNode*) &iedModel_PROT_I0PTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I0PTOC2_Str,  (ModelNode*) &iedModel_PROT_I0PTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I0PTOC2_Str,  (ModelNode*) &iedModel_PROT_I0PTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I0PTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I0PTOC2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I0PTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I0PTOC2_Op_general,0};
DataAttribute iedModel_PROT_I0PTOC2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I0PTOC2_Op,  (ModelNode*) &iedModel_PROT_I0PTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I0PTOC2_Op,  (ModelNode*) &iedModel_PROT_I0PTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I0PTOC2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I0PTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};



// -------------------
LogicalNode iedModel_PROT_INPTOC1 = {    LogicalNodeModelType,    "INPTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_INPTOC2,    (ModelNode*) &iedModel_PROT_INPTOC1_Mod};

DataObject iedModel_PROT_INPTOC1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_INPTOC1,    (ModelNode*) &iedModel_PROT_INPTOC1_Beh,    (ModelNode*) &iedModel_PROT_INPTOC1_Mod_q,0};
DataAttribute iedModel_PROT_INPTOC1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC1_Mod,    (ModelNode*) &iedModel_PROT_INPTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC1_Mod,    (ModelNode*) &iedModel_PROT_INPTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_INPTOC1_Mod,    (ModelNode*) &iedModel_PROT_INPTOC1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_INPTOC1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_INPTOC1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_INPTOC1,    (ModelNode*) &iedModel_PROT_INPTOC1_Health,    (ModelNode*) &iedModel_PROT_INPTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_INPTOC1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_INPTOC1_Beh,    (ModelNode*) &iedModel_PROT_INPTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC1_Beh,    (ModelNode*) &iedModel_PROT_INPTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_INPTOC1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_INPTOC1,    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_INPTOC1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_INPTOC1_Health,    (ModelNode*) &iedModel_PROT_INPTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC1_Health,    (ModelNode*) &iedModel_PROT_INPTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_INPTOC1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_INPTOC1,    (ModelNode*) &iedModel_PROT_INPTOC1_Str, (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_INPTOC1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_INPTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_INPTOC1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_INPTOC1,  	(ModelNode*)&iedModel_PROT_INPTOC1_Op, (ModelNode*) &iedModel_PROT_INPTOC1_Str_general,0};
DataAttribute iedModel_PROT_INPTOC1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_INPTOC1_Str,  (ModelNode*) &iedModel_PROT_INPTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_INPTOC1_Str,  (ModelNode*) &iedModel_PROT_INPTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_INPTOC1_Str,  (ModelNode*) &iedModel_PROT_INPTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_INPTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_INPTOC1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_INPTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_INPTOC1_Op_general,0};
DataAttribute iedModel_PROT_INPTOC1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_INPTOC1_Op,  (ModelNode*) &iedModel_PROT_INPTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_INPTOC1_Op,  (ModelNode*) &iedModel_PROT_INPTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_INPTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_INPTOC2 = {    LogicalNodeModelType,    "INPTOC2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IGPTOC,    (ModelNode*) &iedModel_PROT_INPTOC2_Mod};

DataObject iedModel_PROT_INPTOC2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_INPTOC2,    (ModelNode*) &iedModel_PROT_INPTOC2_Beh,    (ModelNode*) &iedModel_PROT_INPTOC2_Mod_q,0};
DataAttribute iedModel_PROT_INPTOC2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC2_Mod,    (ModelNode*) &iedModel_PROT_INPTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC2_Mod,    (ModelNode*) &iedModel_PROT_INPTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_INPTOC2_Mod,    (ModelNode*) &iedModel_PROT_INPTOC2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_INPTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_INPTOC2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_INPTOC2,    (ModelNode*) &iedModel_PROT_INPTOC2_Health,    (ModelNode*) &iedModel_PROT_INPTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_INPTOC2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_INPTOC2_Beh,    (ModelNode*) &iedModel_PROT_INPTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC2_Beh,    (ModelNode*) &iedModel_PROT_INPTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_INPTOC2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_INPTOC2,    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_INPTOC2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_INPTOC2_Health,    (ModelNode*) &iedModel_PROT_INPTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_INPTOC2_Health,    (ModelNode*) &iedModel_PROT_INPTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_INPTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_INPTOC2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_INPTOC2,    (ModelNode*) &iedModel_PROT_INPTOC2_Str, (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_INPTOC2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_INPTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_INPTOC2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_INPTOC2,  	(ModelNode*)&iedModel_PROT_INPTOC2_Op, (ModelNode*) &iedModel_PROT_INPTOC2_Str_general,0};
DataAttribute iedModel_PROT_INPTOC2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_INPTOC2_Str,  (ModelNode*) &iedModel_PROT_INPTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_INPTOC2_Str,  (ModelNode*) &iedModel_PROT_INPTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_INPTOC2_Str,  (ModelNode*) &iedModel_PROT_INPTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_INPTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_INPTOC2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_INPTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_INPTOC2_Op_general,0};
DataAttribute iedModel_PROT_INPTOC2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_INPTOC2_Op,  (ModelNode*) &iedModel_PROT_INPTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_INPTOC2_Op,  (ModelNode*) &iedModel_PROT_INPTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_INPTOC2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_INPTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_IGPTOC = {    LogicalNodeModelType,    "IGPTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I2I1PTOC,    (ModelNode*) &iedModel_PROT_IGPTOC_Mod};

DataObject iedModel_PROT_IGPTOC_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IGPTOC,    (ModelNode*) &iedModel_PROT_IGPTOC_Beh,    (ModelNode*) &iedModel_PROT_IGPTOC_Mod_q,0};
DataAttribute iedModel_PROT_IGPTOC_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IGPTOC_Mod,    (ModelNode*) &iedModel_PROT_IGPTOC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IGPTOC_Mod,    (ModelNode*) &iedModel_PROT_IGPTOC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IGPTOC_Mod,    (ModelNode*) &iedModel_PROT_IGPTOC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IGPTOC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IGPTOC_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IGPTOC,    (ModelNode*) &iedModel_PROT_IGPTOC_Health,    (ModelNode*) &iedModel_PROT_IGPTOC_Beh_stVal,0};
DataAttribute iedModel_PROT_IGPTOC_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IGPTOC_Beh,    (ModelNode*) &iedModel_PROT_IGPTOC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IGPTOC_Beh,    (ModelNode*) &iedModel_PROT_IGPTOC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IGPTOC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IGPTOC_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IGPTOC,    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IGPTOC_Health_stVal,0};
DataAttribute iedModel_PROT_IGPTOC_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IGPTOC_Health,    (ModelNode*) &iedModel_PROT_IGPTOC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IGPTOC_Health,    (ModelNode*) &iedModel_PROT_IGPTOC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IGPTOC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IGPTOC_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IGPTOC,    (ModelNode*) &iedModel_PROT_IGPTOC_Str, (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IGPTOC_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IGPTOC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IGPTOC_Str 	 			= { DataObjectModelType,	"Str",  		(ModelNode*) &iedModel_PROT_IGPTOC,  	 (ModelNode*) &iedModel_PROT_IGPTOC_Op, 			(ModelNode*) &iedModel_PROT_IGPTOC_Str_general,0};
DataAttribute iedModel_PROT_IGPTOC_Str_general 		= { DataAttributeModelType,"general", 		(ModelNode*) &iedModel_PROT_IGPTOC_Str,  (ModelNode*) &iedModel_PROT_IGPTOC_Str_dirGeneral,	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", 	(ModelNode*) &iedModel_PROT_IGPTOC_Str,  (ModelNode*) &iedModel_PROT_IGPTOC_Str_q,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Str_q 			= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_IGPTOC_Str,  (ModelNode*) &iedModel_PROT_IGPTOC_Str_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Str_t 			= { DataAttributeModelType,	"t",    		(ModelNode*) &iedModel_PROT_IGPTOC_Str,  NULL,    											NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IGPTOC_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IGPTOC,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IGPTOC_Op_general,0};
DataAttribute iedModel_PROT_IGPTOC_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IGPTOC_Op,  (ModelNode*) &iedModel_PROT_IGPTOC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IGPTOC_Op,  (ModelNode*) &iedModel_PROT_IGPTOC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IGPTOC_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IGPTOC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_I2I1PTOC = {    LogicalNodeModelType,    "I2I1PTOC1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_LZSHPTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod};

DataObject iedModel_PROT_I2I1PTOC_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I2I1PTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod_q,0};
DataAttribute iedModel_PROT_I2I1PTOC_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I2I1PTOC_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I2I1PTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh_stVal,0};
DataAttribute iedModel_PROT_I2I1PTOC_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2I1PTOC_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I2I1PTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health_stVal,0};
DataAttribute iedModel_PROT_I2I1PTOC_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2I1PTOC_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I2I1PTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC_Str, (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I2I1PTOC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I2I1PTOC_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I2I1PTOC,  	(ModelNode*)&iedModel_PROT_I2I1PTOC_Op, (ModelNode*) &iedModel_PROT_I2I1PTOC_Str_general,0};
DataAttribute iedModel_PROT_I2I1PTOC_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2I1PTOC_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I2I1PTOC_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I2I1PTOC_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I2I1PTOC,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I2I1PTOC_Op_general,0};
DataAttribute iedModel_PROT_I2I1PTOC_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2I1PTOC_Op,  (ModelNode*) &iedModel_PROT_I2I1PTOC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Op,  (ModelNode*) &iedModel_PROT_I2I1PTOC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2I1PTOC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_LZSHPTOC = {    LogicalNodeModelType,    "LZSHPTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_RREC,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod};

DataObject iedModel_PROT_LZSHPTOC_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_LZSHPTOC,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod_q,0};
DataAttribute iedModel_PROT_LZSHPTOC_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_LZSHPTOC_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_LZSHPTOC,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh_stVal,0};
DataAttribute iedModel_PROT_LZSHPTOC_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_LZSHPTOC_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_LZSHPTOC,    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health_stVal,0};
DataAttribute iedModel_PROT_LZSHPTOC_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_LZSHPTOC_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_LZSHPTOC,    (ModelNode*) &iedModel_PROT_LZSHPTOC_Str, (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt_vendor,0};
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_LZSHPTOC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_LZSHPTOC_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_LZSHPTOC,  	(ModelNode*)&iedModel_PROT_LZSHPTOC_Op, (ModelNode*) &iedModel_PROT_LZSHPTOC_Str_general,0};
DataAttribute iedModel_PROT_LZSHPTOC_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_LZSHPTOC_Str,  (ModelNode*) &iedModel_PROT_LZSHPTOC_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_LZSHPTOC_Str,  (ModelNode*) &iedModel_PROT_LZSHPTOC_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Str,  (ModelNode*) &iedModel_PROT_LZSHPTOC_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_LZSHPTOC_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_LZSHPTOC,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_LZSHPTOC_Op_general,0};
DataAttribute iedModel_PROT_LZSHPTOC_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_LZSHPTOC_Op,  (ModelNode*) &iedModel_PROT_LZSHPTOC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Op,  (ModelNode*) &iedModel_PROT_LZSHPTOC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_LZSHPTOC_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_LZSHPTOC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_RREC = {    LogicalNodeModelType,    "RREC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_RBRF,    (ModelNode*) &iedModel_PROT_RREC_Mod};

DataObject iedModel_PROT_RREC_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_RREC,    (ModelNode*) &iedModel_PROT_RREC_Beh,    (ModelNode*) &iedModel_PROT_RREC_Mod_q,0};
DataAttribute iedModel_PROT_RREC_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC_Mod,    (ModelNode*) &iedModel_PROT_RREC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC_Mod,    (ModelNode*) &iedModel_PROT_RREC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_RREC_Mod,    (ModelNode*) &iedModel_PROT_RREC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_RREC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RREC_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_RREC,    (ModelNode*) &iedModel_PROT_RREC_Health,    (ModelNode*) &iedModel_PROT_RREC_Beh_stVal,0};
DataAttribute iedModel_PROT_RREC_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RREC_Beh,    (ModelNode*) &iedModel_PROT_RREC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC_Beh,    (ModelNode*) &iedModel_PROT_RREC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RREC_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_RREC,    (ModelNode*) &iedModel_PROT_RREC_NamPlt,    (ModelNode*) &iedModel_PROT_RREC_Health_stVal,0};
DataAttribute iedModel_PROT_RREC_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RREC_Health,    (ModelNode*) &iedModel_PROT_RREC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC_Health,    (ModelNode*) &iedModel_PROT_RREC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RREC_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_RREC,    (ModelNode*) &iedModel_PROT_RREC_AutoRecSt, (ModelNode*) &iedModel_PROT_RREC_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RREC_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_RREC_NamPlt,    (ModelNode*) &iedModel_PROT_RREC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_RREC_NamPlt,    (ModelNode*) &iedModel_PROT_RREC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_RREC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_RREC_AutoRecSt 	 = {    DataObjectModelType,    "AutoRecSt",  (ModelNode*) &iedModel_PROT_RREC,  	(ModelNode*)&iedModel_PROT_RREC_Op, (ModelNode*) &iedModel_PROT_RREC_AutoRecSt_stVal,0};
DataAttribute iedModel_PROT_RREC_AutoRecSt_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RREC_AutoRecSt,   (ModelNode*) &iedModel_PROT_RREC_AutoRecSt_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC_AutoRecSt_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_RREC_AutoRecSt,  (ModelNode*) &iedModel_PROT_RREC_AutoRecSt_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_AutoRecSt_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_RREC_AutoRecSt,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_RREC_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_RREC,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_RREC_Op_general,0};
DataAttribute iedModel_PROT_RREC_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_RREC_Op,  (ModelNode*) &iedModel_PROT_RREC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_RREC_Op,  (ModelNode*) &iedModel_PROT_RREC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_RREC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_RBRF = {    LogicalNodeModelType,    "RBRF1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_AVRGGIO,    (ModelNode*) &iedModel_PROT_RBRF_Mod};

DataObject iedModel_PROT_RBRF_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_RBRF,    (ModelNode*) &iedModel_PROT_RBRF_Beh,    (ModelNode*) &iedModel_PROT_RBRF_Mod_q,0};
DataAttribute iedModel_PROT_RBRF_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RBRF_Mod,    (ModelNode*) &iedModel_PROT_RBRF_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RBRF_Mod,    (ModelNode*) &iedModel_PROT_RBRF_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_RBRF_Mod,    (ModelNode*) &iedModel_PROT_RBRF_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_RBRF_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RBRF_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_RBRF,    (ModelNode*) &iedModel_PROT_RBRF_Health,    (ModelNode*) &iedModel_PROT_RBRF_Beh_stVal,0};
DataAttribute iedModel_PROT_RBRF_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RBRF_Beh,    (ModelNode*) &iedModel_PROT_RBRF_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RBRF_Beh,    (ModelNode*) &iedModel_PROT_RBRF_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RBRF_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RBRF_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_RBRF,    (ModelNode*) &iedModel_PROT_RBRF_NamPlt,    (ModelNode*) &iedModel_PROT_RBRF_Health_stVal,0};
DataAttribute iedModel_PROT_RBRF_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RBRF_Health,    (ModelNode*) &iedModel_PROT_RBRF_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RBRF_Health,    (ModelNode*) &iedModel_PROT_RBRF_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RBRF_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RBRF_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_RBRF,    (ModelNode*) &iedModel_PROT_RBRF_OpEx, (ModelNode*) &iedModel_PROT_RBRF_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RBRF_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_RBRF_NamPlt,    (ModelNode*) &iedModel_PROT_RBRF_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_RBRF_NamPlt,    (ModelNode*) &iedModel_PROT_RBRF_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_RBRF_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_RBRF_OpEx 	 = {    DataObjectModelType,    		"OpEx",  (ModelNode*) &iedModel_PROT_RBRF,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_RBRF_OpEx_general,0};
DataAttribute iedModel_PROT_RBRF_OpEx_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_RBRF_OpEx,  (ModelNode*) &iedModel_PROT_RBRF_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_OpEx_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_RBRF_OpEx,  (ModelNode*) &iedModel_PROT_RBRF_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF_OpEx_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_RBRF_OpEx,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_AVRGGIO 			= { LogicalNodeModelType,   "AVRGGIO1",    (ModelNode*)&iedModel_Generic_GGIO,  (ModelNode*)&iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod};

DataObject iedModel_PROT_AVRGGIO_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_AVRGGIO,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod_q,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod,(ModelNode*) &iedModel_PROT_AVRGGIO_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod,(ModelNode*) &iedModel_PROT_AVRGGIO_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_AVRGGIO_Mod,(ModelNode*) &iedModel_PROT_AVRGGIO_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_AVRGGIO_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_AVRGGIO,    (ModelNode*) &iedModel_PROT_AVRGGIO_Health,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_AVRGGIO_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_AVRGGIO,    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,    (ModelNode*) &iedModel_PROT_AVRGGIO_Health_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_AVRGGIO_Health,    (ModelNode*) &iedModel_PROT_AVRGGIO_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_AVRGGIO_Health,    (ModelNode*) &iedModel_PROT_AVRGGIO_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_AVRGGIO_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_AVRGGIO_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_AVRGGIO,    (ModelNode*)&iedModel_PROT_AVRGGIO_IntIn , (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_vendor,0};

DataAttribute iedModel_PROT_AVRGGIO_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_AVRGGIO_IntIn = {DataObjectModelType,"IntIn",(ModelNode*) &iedModel_PROT_AVRGGIO, NULL ,(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_q,NULL,0,IEC61850_FC_ST,IEC61850_INT32, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO1 			= { LogicalNodeModelType,   "VZGGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod};

DataObject iedModel_PROT_VZGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*)&iedModel_PROT_VZGGIO1_Alm , (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO1,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO2 			= { LogicalNodeModelType,   "VZGGIO2",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod};

DataObject iedModel_PROT_VZGGIO2_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*)&iedModel_PROT_VZGGIO2_Alm , (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO2,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO3 			= { LogicalNodeModelType,   "VZGGIO3",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod};

DataObject iedModel_PROT_VZGGIO3_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*)&iedModel_PROT_VZGGIO3_Alm , (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO3,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO4 			= { LogicalNodeModelType,   "VZGGIO4",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod};

DataObject iedModel_PROT_VZGGIO4_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*)&iedModel_PROT_VZGGIO4_Alm , (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO4,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO5 			= { LogicalNodeModelType,   "VZGGIO5",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod};

DataObject iedModel_PROT_VZGGIO5_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*)&iedModel_PROT_VZGGIO5_Alm , (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO5,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO6 			= { LogicalNodeModelType,   "VZGGIO6",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod};

DataObject iedModel_PROT_VZGGIO6_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*)&iedModel_PROT_VZGGIO6_Alm , (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO6,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO7 			= { LogicalNodeModelType,   "VZGGIO7",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod};

DataObject iedModel_PROT_VZGGIO7_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*)&iedModel_PROT_VZGGIO7_Alm , (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO7,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO8 			= { LogicalNodeModelType,   "VZGGIO8",    (ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod};

DataObject iedModel_PROT_VZGGIO8_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*)&iedModel_PROT_VZGGIO8_Alm , (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO8,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

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

LogicalNode iedModel_CTRL_CSWI1 						= {    LogicalNodeModelType,    "CSWI1",   (ModelNode*) &iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_XCBR1,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod};
//Mod
DataObject iedModel_CTRL_CSWI1_Mod 					= {    DataObjectModelType,      "Mod",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_q,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_q 				= {    DataAttributeModelType,   "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_t 				= {    DataAttributeModelType,   "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_stVal 			= { DataAttributeModelType,		 "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod, (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod,   NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//Beh
DataObject iedModel_CTRL_CSWI1_Beh 					= {    DataObjectModelType,       "Beh",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

//Health
DataObject iedModel_CTRL_CSWI1_Health 					= {    DataObjectModelType,       "Health",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_CTRL_CSWI1_NamPlt 					= {    DataObjectModelType,       "NamPlt",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor 		= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev 		= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_CTRL_CSWI1_Pos 					= {    DataObjectModelType,       "Pos",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};//GENERIC_BITSTRING
DataAttribute iedModel_CTRL_CSWI1_Pos_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel 		= {   DataAttributeModelType,     "ctlModel",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper 			= {    DataAttributeModelType,    "Oper",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,   NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal 		= {    DataAttributeModelType,    "ctlVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin 		= {    DataAttributeModelType,    "origin",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat = {    DataAttributeModelType,   "orCat",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent = {    DataAttributeModelType, "orIdent",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum 		= {    DataAttributeModelType,    "ctlNum",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T 			= {    DataAttributeModelType,    "T",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test 		= {    DataAttributeModelType,    "Test",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check 		= {    DataAttributeModelType,    "Check",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


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
LogicalNode iedModel_CTRL_XCBR1 							= {    LogicalNodeModelType,    "XCBR1",    (ModelNode*) &iedModel_Generic_CTRL,  (ModelNode*) &iedModel_CTRL_PTRC ,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod};
//Mod
DataObject iedModel_CTRL_XCBR1_Mod 						= {    DataObjectModelType,     "Mod",     (ModelNode*) &iedModel_CTRL_XCBR1,     			(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_q,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_q 					= {    DataAttributeModelType,  "q",       (ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_t 					= {    DataAttributeModelType,  "t",       (ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_stVal 				= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel 			= {   DataAttributeModelType,   "ctlModel",(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod,         NULL,(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_CTRL_XCBR1_Beh 						= {    DataObjectModelType,     "Beh",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Health,    (ModelNode*) &iedModel_CTRL_XCBR1_Beh_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh, NULL, NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_CTRL_XCBR1_Health 						= {    DataObjectModelType,     "Health",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    (ModelNode*) &iedModel_CTRL_XCBR1_Health_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Health_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_CTRL_XCBR1_NamPlt 						= {    DataObjectModelType,     "NamPlt",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Pos, (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor 			= {    DataAttributeModelType,  "vendor",   (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev 			= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_d 				= {    DataAttributeModelType,  "d",    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_CTRL_XCBR1_Pos 						= {    DataObjectModelType,     "Pos",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*)&iedModel_CTRL_XCBR1_Loc, (ModelNode*) &iedModel_CTRL_XCBR1_Pos_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//Loc
DataObject iedModel_CTRL_XCBR1_Loc 						= {    DataObjectModelType,     "Loc",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt, (ModelNode*) &iedModel_CTRL_XCBR1_Loc_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//OpCnt
DataObject iedModel_CTRL_XCBR1_OpCnt 						= {    DataObjectModelType,     "OpCnt",    (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap, (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal 				= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_q 					= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_t 					= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//CBOpCap
DataObject iedModel_CTRL_XCBR1_CBOpCap 					= {    DataObjectModelType,     "CBOpCap",  (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn, (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//BlkOpn
DataObject iedModel_CTRL_XCBR1_BlkOpn 						= {    DataObjectModelType,     "BlkOpn",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls, (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*)&iedModel_CTRL_XCBR1_BlkOpn_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*)&iedModel_CTRL_XCBR1_BlkOpn_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,   NULL,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat = {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent= {   DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test 		= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//BlkCls
DataObject iedModel_CTRL_XCBR1_BlkCls 						= {    DataObjectModelType,     "BlkCls",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_q 				= {    DataAttributeModelType,  "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_t 				= {    DataAttributeModelType,  "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel 			= {   DataAttributeModelType,   "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,   NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat = {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent= {   DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test 		= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//-PTRC --------------------------------------------------------------------------
LogicalNode iedModel_CTRL_PTRC 					= {    LogicalNodeModelType,    "PTRC1",    (ModelNode*)&iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_PTRC_Mod};

DataObject iedModel_CTRL_PTRC_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_q,0};
DataAttribute iedModel_CTRL_PTRC_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_Health_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Op, (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_CTRL_PTRC,  	NULL, (ModelNode*) &iedModel_CTRL_PTRC_Op_general,0};
DataAttribute iedModel_CTRL_PTRC_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1 					= {    LogicalNodeModelType,    "GGIO1",    (ModelNode*) &iedModel_Generic_CTRL,  NULL ,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod};

DataObject iedModel_CTRL_GGIO1_Mod 					= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod_q,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_Beh 					= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*)&iedModel_CTRL_GGIO1_SPCSO1 , (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_vendor,0};

DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev 		= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_CTRL_GGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     		(ModelNode*) &iedModel_CTRL_GGIO1,     		(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_CTRL_GGIO1,     			(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",   (ModelNode*) &iedModel_CTRL_GGIO1,     	(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO4,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q 					= {    DataAttributeModelType,  "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t 					= {    DataAttributeModelType,  "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d 					= {    DataAttributeModelType,  "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,	 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal 				= { DataAttributeModelType,		"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel 			= {   DataAttributeModelType,   "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,NULL,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO4 						= {    DataObjectModelType,     "SPCSO4",   (ModelNode*) &iedModel_CTRL_GGIO1,     	NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q 					= {    DataAttributeModelType,  "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t 					= {    DataAttributeModelType,  "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d 					= {    DataAttributeModelType,  "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,	 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal 				= { DataAttributeModelType,		"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel 			= {   DataAttributeModelType,   "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,NULL,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


/***********************************************************************
 * DataSet
 ***********************************************************************/
//LLN0.DS0
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda0 = {"GGIO",false,"IN16GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda1 = {"GGIO",false,"IN16GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda2 = {"GGIO",false,"IN16GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda3 = {"GGIO",false,"IN16GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda4 = {"GGIO",false,"IN16GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda5 = {"GGIO",false,"IN16GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda6 = {"GGIO",false,"IN16GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda7 = {"GGIO",false,"IN16GGIO1$ST$Ind8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda8 = {"GGIO",false,"IN16GGIO1$ST$Ind9", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda9 = {"GGIO",false,"IN16GGIO1$ST$Ind10", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda10 = {"GGIO",false,"IN16GGIO1$ST$Ind11", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda11 = {"GGIO",false,"IN16GGIO1$ST$Ind12", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda12 = {"GGIO",false,"IN16GGIO1$ST$Ind13", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda13 = {"GGIO",false,"IN16GGIO1$ST$Ind14", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda14 = {"GGIO",false,"IN16GGIO1$ST$Ind15", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda15 = {"GGIO",false,"IN16GGIO1$ST$Ind16", -1, NULL, NULL, NULL };
#define 	_numDS0			16
#define 	linkDS0			&iedModelds_LD0_LLN0_dataset0_fcda0


//LLN0.DS1
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda0 = {"GGIO",false,"LED12GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda1 = {"GGIO",false,"LED12GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda2 = {"GGIO",false,"LED12GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda3 = {"GGIO",false,"LED12GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda4 = {"GGIO",false,"LED12GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda5 = {"GGIO",false,"LED12GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda6 = {"GGIO",false,"LED12GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda7 = {"GGIO",false,"LED12GGIO1$ST$Ind8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda8 = {"GGIO",false,"LED12GGIO1$ST$Ind9", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda9 = {"GGIO",false,"LED12GGIO1$ST$Ind10", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda10 = {"GGIO",false,"LED12GGIO1$ST$Ind11", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset1_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda11 = {"GGIO",false,"LED12GGIO1$ST$Ind12", -1, NULL, NULL, NULL };
#define 	_numDS1			12
#define 	linkDS1			&iedModelds_LD0_LLN0_dataset1_fcda0

//LLN0.DS2
DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda0 = {"CTRL",false,"XCBR1$ST$Pos", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset2_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda1 = {"CTRL",false,"XCBR1$ST$BlkCls", -1, NULL, NULL, NULL };
#define 	_numDS2			2
#define 	linkDS2			&iedModelds_LD0_LLN0_dataset2_fcda0

//LLN0.DS3
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda0 = {"CTRL",false,"GGIO1$ST$SPCSO1$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda1 = {"CTRL",false,"GGIO1$ST$SPCSO2$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda2 = {"CTRL",false,"GGIO1$ST$SPCSO3$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda3 = {"CTRL",false,"GGIO1$ST$SPCSO4$stVal", -1, NULL, NULL, NULL };
#define 	_numDS3			4
#define 	linkDS3			&iedModelds_LD0_LLN0_dataset3_fcda0

//LLN0.DS4
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda0 = {"PROT",false,"IPTOC1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda1 = {"PROT",false,"IPTOC2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda2 = {"PROT",false,"IPTOC3$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda3 = {"PROT",false,"IPTOC4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda4 = {"PROT",false,"IPTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda5 = {"PROT",false,"IPTOC2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda6 = {"PROT",false,"IPTOC3$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda7 = {"PROT",false,"IPTOC4$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda8  ={"PROT",false,"I2PTOC1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda9  ={"PROT",false,"I2PTOC2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda10 ={"PROT",false,"I0PTOC1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda11 ={"PROT",false,"I0PTOC2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda12 ={"PROT",false,"INPTOC1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda13 ={"PROT",false,"INPTOC2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda14 ={"PROT",false,"IGPTOC1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda15 ={"PROT",false,"I2PTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda16 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda16 ={"PROT",false,"I2PTOC2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda17 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda17 ={"PROT",false,"I0PTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda18 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda18 ={"PROT",false,"I0PTOC2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda19 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda19 ={"PROT",false,"INPTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda20 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda20 ={"PROT",false,"INPTOC2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda21 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda21 ={"PROT",false,"IGPTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda22 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda22 ={"PROT",false,"I2I1PTOC1$ST$Str", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset4_fcda23 };
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda23 ={"PROT",false,"I2I1PTOC1$ST$Op", 	-1, NULL, NULL, NULL };
#define 	_numDS4			24
#define 	linkDS4			&iedModelds_LD0_LLN0_dataset4_fcda0

//LLN0.DS5
#define 	_numDS5			0
#define 	linkDS5			NULL

//LLN0.DS6
#define 	_numDS6			0
#define 	linkDS6			NULL

//LLN0.DS7
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda0 = {"PROT",false,"VZGGIO1$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda1 = {"PROT",false,"VZGGIO2$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda2 = {"PROT",false,"VZGGIO3$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda3 = {"PROT",false,"VZGGIO4$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda4 = {"PROT",false,"VZGGIO5$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda5 = {"PROT",false,"VZGGIO6$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda6 = {"PROT",false,"VZGGIO7$ST$Alm", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset7_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda7 = {"PROT",false,"VZGGIO8$ST$Alm", -1, NULL, NULL, NULL };
#define 	_numDS7			8
#define 	linkDS7			&iedModelds_LD0_LLN0_dataset7_fcda0

//LLN0.DS8
#define 	_numDS8			0
#define 	linkDS8			NULL

//LLN0.DS9
#define 	_numDS9			0
#define 	linkDS9			NULL

//LLN0.DS10
#define 	_numDS10		0
#define 	linkDS10		NULL

//LLN0.DS11
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda0 = {"PROT",false,"RREC1$ST$AutoRecSt", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset11_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda1 = {"PROT",false,"RREC1$ST$Op", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset11_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda2 = {"PROT",false,"RBRF1$ST$OpEx", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset11_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda3 = {"PROT",false,"AVRGGIO1$ST$IntIn", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset11_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda4 = {"PROT",false,"LZSHPTOC1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset11_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda5 = {"PROT",false,"LZSHPTOC1$ST$Str", 	-1, NULL, NULL, NULL };
#define 	_numDS11		6
#define 	linkDS11		&iedModelds_LD0_LLN0_dataset11_fcda0

//LLN0.DS12
DataSetEntry iedModelds_LD0_MMXU1_fcda0 = {"MES",false, "MMXU1$MX$A$phsA",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda1};
DataSetEntry iedModelds_LD0_MMXU1_fcda1 = {"MES",false, "MMXU1$MX$A$phsB",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda2};
DataSetEntry iedModelds_LD0_MMXU1_fcda2 = {"MES",false, "MMXU1$MX$A$phsC",-1,NULL,NULL,&iedModelds_LD0_MMXU1_fcda3};
DataSetEntry iedModelds_LD0_MMXU1_fcda3 = {"MES",false, "MMXU1$MX$A$neut",-1,NULL,NULL,NULL};
#define 	_numDS12		4
#define 	linkDS12		&iedModelds_LD0_MMXU1_fcda0

//LLN0.DS13
DataSetEntry iedModelds_LD0_MMXU2_fcda0 = {"MES",false, "MSQI1$MX$SeqA$c1",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda1};
DataSetEntry iedModelds_LD0_MMXU2_fcda1 = {"MES",false, "MSQI1$MX$SeqA$c2",-1,NULL,NULL,&iedModelds_LD0_MMXU2_fcda2};
DataSetEntry iedModelds_LD0_MMXU2_fcda2 = {"MES",false, "MSQI1$MX$SeqA$c3",-1,NULL,NULL,NULL};
#define 	_numDS13		3
#define 	linkDS13		&iedModelds_LD0_MMXU2_fcda0

//LLN0.DS14
#define 	_numDS14		0
#define 	linkDS14		NULL

//LLN0.DS15
#define 	_numDS15		0
#define 	linkDS15		NULL

//LLN0.DS16
#define 	_numDS16		0
#define 	linkDS16		NULL



#define 	_numDS17		0
#define 	_numDS18		0
#define 	_numDS19		0
#define 	_numDS20		0
#define 	linkDS17		NULL
#define 	linkDS18		NULL
#define 	linkDS19		NULL
#define 	linkDS20		NULL
/***********************************************************************
 * DataSet
 ***********************************************************************/
DataSet iedModelds_LD0_LLN0_dataset0 = {"LD0", "LLN0$DS0",	_numDS0, 	linkDS0, 	&iedModelds_LD0_LLN0_dataset1,	false};			// IN42GGIO
DataSet iedModelds_LD0_LLN0_dataset1 = {"LD0", "LLN0$DS1",	_numDS1, 	linkDS1, 	&iedModelds_LD0_LLN0_dataset2,	false};			// LED16
DataSet iedModelds_LD0_LLN0_dataset2 = {"LD0", "LLN0$DS2",	_numDS2, 	linkDS2, 	&iedModelds_LD0_LLN0_dataset3,	false};			// XCBR1
DataSet iedModelds_LD0_LLN0_dataset3 = {"LD0", "LLN0$DS3",	_numDS3, 	linkDS3,	&iedModelds_LD0_LLN0_dataset4,	false};			// SPCSO
DataSet iedModelds_LD0_LLN0_dataset4 = {"LD0", "LLN0$DS4",	_numDS4, 	linkDS4,	&iedModelds_LD0_LLN0_dataset5,	false};			// IPTOC IPTUC
DataSet iedModelds_LD0_LLN0_dataset5 = {"LD0", "LLN0$DS5",	_numDS5, 	linkDS5,	&iedModelds_LD0_LLN0_dataset6,	false};			// UPTOV UPTUV
DataSet iedModelds_LD0_LLN0_dataset6 = {"LD0", "LLN0$DS6",	_numDS6, 	linkDS6,	&iedModelds_LD0_LLN0_dataset7,	false};			//
DataSet iedModelds_LD0_LLN0_dataset7 = {"LD0", "LLN0$DS7",	_numDS7, 	linkDS7,	&iedModelds_LD0_LLN0_dataset8,	false};			//
DataSet iedModelds_LD0_LLN0_dataset8 = {"LD0", "LLN0$DS8",	_numDS8, 	linkDS8,	&iedModelds_LD0_LLN0_dataset9,	false};			//
DataSet iedModelds_LD0_LLN0_dataset9 = {"LD0", "LLN0$DS9",	_numDS9, 	linkDS9,	&iedModelds_LD0_LLN0_dataset10,	false};		//
DataSet iedModelds_LD0_LLN0_dataset10 ={"LD0", "LLN0$DS10",	_numDS10, 	linkDS10,	&iedModelds_LD0_LLN0_dataset11,	false};								//
DataSet iedModelds_LD0_LLN0_dataset11 ={"LD0", "LLN0$DS11",	_numDS11, 	linkDS11 ,	&iedModelds_LD0_LLN0_dataset12,	false};		//
DataSet iedModelds_LD0_LLN0_dataset12 ={"LD0", "LLN0$DS12",	_numDS12, 	linkDS12 ,	&iedModelds_LD0_LLN0_dataset13,	false};
DataSet iedModelds_LD0_LLN0_dataset13 ={"LD0", "LLN0$DS13",	_numDS13, 	linkDS13 ,	&iedModelds_LD0_LLN0_dataset14,	false};
DataSet iedModelds_LD0_LLN0_dataset14 ={"LD0", "LLN0$DS14",	_numDS14, 	linkDS14 ,	&iedModelds_LD0_LLN0_dataset15,	false};
DataSet iedModelds_LD0_LLN0_dataset15 ={"LD0", "LLN0$DS15",	_numDS15, 	linkDS15 ,	&iedModelds_LD0_LLN0_dataset16,	false};
DataSet iedModelds_LD0_LLN0_dataset16 ={"LD0", "LLN0$DS16",	_numDS16, 	linkDS16 ,	&iedModelds_LD0_LLN0_dataset17,	false};
DataSet iedModelds_LD0_LLN0_dataset17 ={"LD0", "LLN0$DS17",	_numDS17, 	linkDS17 ,	&iedModelds_LD0_LLN0_dataset18,	false};
DataSet iedModelds_LD0_LLN0_dataset18 ={"LD0", "LLN0$DS18",	_numDS18, 	linkDS18 ,	&iedModelds_LD0_LLN0_dataset19,	false};
DataSet iedModelds_LD0_LLN0_dataset19 ={"LD0", "LLN0$DS19",	_numDS19, 	linkDS19 ,	&iedModelds_LD0_LLN0_dataset20,	false};
DataSet iedModelds_LD0_LLN0_dataset20 ={"LD0", "LLN0$DS20",	_numDS20, 	linkDS20 ,	NULL,							false};

/*
DataSet iedModelds_LD0_LLN0_dataset0 = {"LD0", "LLN0$DS0", 16, &iedModelds_LD0_LLN0_dataset0_fcda0, 	&iedModelds_LD0_LLN0_dataset1};			// IN42GGIO
DataSet iedModelds_LD0_LLN0_dataset1 = {"LD0", "LLN0$DS1", 12, &iedModelds_LD0_LLN0_dataset1_fcda0, 	&iedModelds_LD0_LLN0_dataset2};			// LED16
DataSet iedModelds_LD0_LLN0_dataset2 = {"LD0", "LLN0$DS2",  2, &iedModelds_LD0_LLN0_dataset2_fcda0, 	&iedModelds_LD0_LLN0_dataset3};			// XCBR1
DataSet iedModelds_LD0_LLN0_dataset3 = {"LD0", "LLN0$DS3",  4, &iedModelds_LD0_LLN0_dataset3_fcda0,		&iedModelds_LD0_LLN0_dataset4};			// SPCSO
DataSet iedModelds_LD0_LLN0_dataset4 = {"LD0", "LLN0$DS4", 24, &iedModelds_LD0_LLN0_dataset4_fcda0,		&iedModelds_LD0_LLN0_dataset5};			// IPTOC IPTUC
DataSet iedModelds_LD0_LLN0_dataset5 = {"LD0", "LLN0$DS5",  8, &iedModelds_LD0_LLN0_dataset5_fcda0,		&iedModelds_LD0_LLN0_dataset6};			// UPTOV UPTUV
DataSet iedModelds_LD0_LLN0_dataset6 = {"LD0", "LLN0$DS6",  8, &iedModelds_LD0_LLN0_dataset6_fcda0,		&iedModelds_LD0_LLN0_dataset7};			//
DataSet iedModelds_LD0_LLN0_dataset7 = {"LD0", "LLN0$DS7",  8, &iedModelds_LD0_LLN0_dataset7_fcda0,		&iedModelds_LD0_LLN0_dataset8};			//
DataSet iedModelds_LD0_LLN0_dataset8 = {"LD0", "LLN0$DS8",  0, &iedModelds_LD0_LLN0_dataset8_fcda0,		&iedModelds_LD0_LLN0_dataset9};			//
DataSet iedModelds_LD0_LLN0_dataset9 = {"LD0", "LLN0$DS9",  0, &iedModelds_LD0_LLN0_dataset9_fcda0,		&iedModelds_LD0_LLN0_dataset10};		//
DataSet iedModelds_LD0_LLN0_dataset10 ={"LD0", "LLN0$DS10", 0, &iedModelds_LD0_LLN0_dataset10_fcda0,	&iedModelds_LD0_LLN0_dataset11};								//
DataSet iedModelds_LD0_LLN0_dataset11 ={"LD0", "LLN0$DS11", 6, &iedModelds_LD0_LLN0_dataset11_fcda0 ,	&iedModelds_LD0_LLN0_dataset12};		//
DataSet iedModelds_LD0_LLN0_dataset12 ={"LD0", "LLN0$DS12", 4, &iedModelds_LD0_MMXU1_fcda0 ,			&iedModelds_LD0_LLN0_dataset13};
DataSet iedModelds_LD0_LLN0_dataset13 ={"LD0", "LLN0$DS13", 0, &iedModelds_LD0_MMXU2_fcda0 ,			&iedModelds_LD0_LLN0_dataset14};
DataSet iedModelds_LD0_LLN0_dataset14 ={"LD0", "LLN0$DS14", 0, &iedModelds_LD0_MMXU3_fcda0 ,			&iedModelds_LD0_LLN0_dataset15};
DataSet iedModelds_LD0_LLN0_dataset15 ={"LD0", "LLN0$DS15", 7, &iedModelds_LD0_MMXU4_fcda0 ,			&iedModelds_LD0_LLN0_dataset16};
DataSet iedModelds_LD0_LLN0_dataset16 ={"LD0", "LLN0$DS16", 5, &iedModelds_LD0_MMXU5_fcda0 ,			&iedModelds_LD0_LLN0_dataset17};
DataSet iedModelds_LD0_LLN0_dataset17 ={"LD0", "LLN0$DS17", 0, NULL ,			&iedModelds_LD0_LLN0_dataset18};
DataSet iedModelds_LD0_LLN0_dataset18 ={"LD0", "LLN0$DS18", 0, NULL ,			&iedModelds_LD0_LLN0_dataset19};
DataSet iedModelds_LD0_LLN0_dataset19 ={"LD0", "LLN0$DS19", 0, NULL ,			&iedModelds_LD0_LLN0_dataset20};
DataSet iedModelds_LD0_LLN0_dataset20 ={"LD0", "LLN0$DS20", 0, NULL ,			NULL};
*/

ReportControlBlock iedModel_LD0_LLN0_report0 = {&iedModel_LD0_LLN0,	"URCB_101",		"LLN0$BR$URCB_101",	false,"DS10",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report1};
ReportControlBlock iedModel_LD0_LLN0_report1 = {&iedModel_LD0_LLN0,	"URCB_201",		"LLN0$BR$URCB_201",	false,"DS11",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report2};
ReportControlBlock iedModel_LD0_LLN0_report2 = {&iedModel_LD0_LLN0,	"URCB_301",		"LLN0$BR$URCB_301",	false,"DS12",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report3};
ReportControlBlock iedModel_LD0_LLN0_report3 = {&iedModel_LD0_LLN0,	"URCB_401",		"LLN0$BR$URCB_401",	false,"DS13",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report4};
ReportControlBlock iedModel_LD0_LLN0_report4 = {&iedModel_LD0_LLN0,	"URCB_501",		"LLN0$BR$URCB_501",	false,"DS14",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report5};
ReportControlBlock iedModel_LD0_LLN0_report5 = {&iedModel_LD0_LLN0,	"URCB_601",		"LLN0$BR$URCB_601",	false,"DS15",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report6};
ReportControlBlock iedModel_LD0_LLN0_report6 = {&iedModel_LD0_LLN0,	"URCB_701",		"LLN0$BR$URCB_701",	false,"DS16",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report7};
ReportControlBlock iedModel_LD0_LLN0_report7 = {&iedModel_LD0_LLN0,	"URCB_801",		"LLN0$BR$URCB_801",	false,"DS17",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report8};
ReportControlBlock iedModel_LD0_LLN0_report8 = {&iedModel_LD0_LLN0,	"URCB_901",		"LLN0$BR$URCB_901",	false,"DS18",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report9};
ReportControlBlock iedModel_LD0_LLN0_report9 = {&iedModel_LD0_LLN0,	"URCB_1001",	"LLN0$BR$URCB_1001",false,"DS19",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report10};
ReportControlBlock iedModel_LD0_LLN0_report10 = {&iedModel_LD0_LLN0,"URCB_1101",	"LLN0$BR$URCB_1101",false,"DS20",0,	TRG_OPT_INTEGRITY,	111,	100,	5000,	&iedModel_LD0_LLN0_report11};

ReportControlBlock iedModel_LD0_LLN0_report11 = { &iedModel_LD0_LLN0, "BRCB_101", 	"LLN0$BR$BRCB_101", true, "DS0", 0, TRG_OPT_NO, 		111,	3000, 	5000,	&iedModel_LD0_LLN0_report12};
ReportControlBlock iedModel_LD0_LLN0_report12 = { &iedModel_LD0_LLN0, "BRCB_201", 	"LLN0$BR$BRCB_201", true, "DS1", 0, TRG_OPT_NO, 		111, 	3000, 	5000,	&iedModel_LD0_LLN0_report13};
ReportControlBlock iedModel_LD0_LLN0_report13 = { &iedModel_LD0_LLN0, "BRCB_301", 	"LLN0$BR$BRCB_301", true, "DS2", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report14};
ReportControlBlock iedModel_LD0_LLN0_report14 = { &iedModel_LD0_LLN0, "BRCB_401", 	"LLN0$BR$BRCB_401", true, "DS3", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report15};
ReportControlBlock iedModel_LD0_LLN0_report15 = { &iedModel_LD0_LLN0, "BRCB_501", 	"LLN0$BR$BRCB_501", true, "DS4", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report16};
ReportControlBlock iedModel_LD0_LLN0_report16 = { &iedModel_LD0_LLN0, "BRCB_601", 	"LLN0$BR$BRCB_601", true, "DS5", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report17};
ReportControlBlock iedModel_LD0_LLN0_report17 = { &iedModel_LD0_LLN0, "BRCB_701", 	"LLN0$BR$BRCB_701", true, "DS6", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report18};
ReportControlBlock iedModel_LD0_LLN0_report18 = { &iedModel_LD0_LLN0, "BRCB_801", 	"LLN0$BR$BRCB_801", true, "DS7", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report19};
ReportControlBlock iedModel_LD0_LLN0_report19 = { &iedModel_LD0_LLN0, "BRCB_901", 	"LLN0$BR$BRCB_901", true, "DS8", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	&iedModel_LD0_LLN0_report20};
ReportControlBlock iedModel_LD0_LLN0_report20 = { &iedModel_LD0_LLN0, "BRCB_1001", 	"LLN0$BR$BRCB_1001",true, "DS9", 0, TRG_OPT_NO, 		111, 	3000, 	5000, 	NULL};


static PhyComAddress iedModel_LD0_LLN0_gse0_address = {  4,  1,  999,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1} };	// 4096, 0x0, 0x1 - ID сообщения
static PhyComAddress iedModel_LD0_LLN0_gse1_address = {  4,  1,  999,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x2} };	// 0x0, 0x2 - ID сообщения


GSEControlBlock iedModel_LD0_LLN0_gse0 = {
	&iedModel_LD0_LLN0,
	"gcbDiscret",
	"discret",
	"DS0",
	1,
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
	1,
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

#define Dir_not		STVALCODEDENUM_UNKNOWN
#define Dir_unknow	3

#define _Default_db			50
#define _Default_Zerodb		50

#define _Default_db_In		400
#define _Default_Zerodb_In	400

#define _Default_db_Hz		200
#define _Default_Zerodb_Hz	200

#define _Default_db_W		50
#define _Default_Zerodb_W	50

static void		initializeValues()
{

USART_TRACE("\n");
USART_TRACE("initializeValues -------------------------------------------\n");

uint64_t currentTime = Hal_getTimeInMs();

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
iedModel_PROT_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_PROT_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

//iedModel_PROT_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString("0");

iedModel_PROT_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_PROT_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);// не будет прокси
iedModel_PROT_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// IPTOC
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

iedModel_PROT_IPTOC1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_IPTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// I2PTOC
iedModel_PROT_I2PTOC1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2PTOC1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2PTOC1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2PTOC2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2PTOC2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2PTOC2_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_I2PTOC1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I2PTOC1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I2PTOC2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I2PTOC2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_I2PTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I2PTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_I2PTOC2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I2PTOC2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// I0PTOC
iedModel_PROT_I0PTOC1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I0PTOC1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I0PTOC1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I0PTOC2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I0PTOC2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I0PTOC2_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_I0PTOC1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I0PTOC1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I0PTOC2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I0PTOC2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_I0PTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I0PTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_I0PTOC2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I0PTOC2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// InPTOC
iedModel_PROT_INPTOC1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_INPTOC1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_INPTOC1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_INPTOC2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_INPTOC2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_INPTOC2_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_INPTOC1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_INPTOC1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_INPTOC2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_INPTOC2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_INPTOC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_INPTOC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_INPTOC2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_INPTOC2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// IGPTOC
iedModel_PROT_IGPTOC_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IGPTOC_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_IGPTOC_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_IGPTOC_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IGPTOC_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_IGPTOC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IGPTOC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// II1PTOC1
iedModel_PROT_I2I1PTOC_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2I1PTOC_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_I2I1PTOC_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_I2I1PTOC_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I2I1PTOC_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_I2I1PTOC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I2I1PTOC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//RREC
iedModel_PROT_RREC_AutoRecSt_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_RREC_AutoRecSt_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RREC_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_RREC_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RREC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_RREC_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


//AVRGGIO
iedModel_PROT_AVRGGIO_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_AVRGGIO_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_AVRGGIO_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_AVRGGIO_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_AVRGGIO_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_AVRGGIO_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_AVRGGIO_IntIn_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//iedModel_PROT_AVRGGIO_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//iedModel_PROT_AVRGGIO_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//iedModel_PROT_AVRGGIO_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//LZSHPTOC
iedModel_PROT_LZSHPTOC_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LZSHPTOC_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LZSHPTOC_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LZSHPTOC_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_LZSHPTOC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LZSHPTOC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_LZSHPTOC_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_LZSHPTOC_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LZSHPTOC_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


//RBRF
iedModel_PROT_RBRF_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RBRF_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RBRF_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RBRF_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RBRF_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RBRF_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RBRF_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RBRF_OpEx_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RBRF_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RBRF_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

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

iedModel_PROT_VZGGIO1_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

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
iedModel_CTRL_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

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


//USART_TRACE("CTRL_CSWI1\n");
//PTRC --------------------------------------------------------------------------------
iedModel_CTRL_PTRC_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_PTRC_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_PTRC_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_CTRL_PTRC_Op_q.mmsValue = MmsValue_newBitString(QUALITY_DETAIL_OLD_DATA);
iedModel_CTRL_PTRC_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_PTRC_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_PTRC_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_CTRL_PTRC_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_PTRC_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_PTRC_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_PTRC_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_PTRC_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_PTRC_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//CSWI1 --------------------------------------------------------------------------------
iedModel_CTRL_CSWI1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Pos_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Pos_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//iedModel_CTRL_CSWI1_Pos_Oper_T.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_CSWI1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_CSWI1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//USART_TRACE("CTRL_PTRC\n");
//XCBR1 --------------------------------------------------------------------------------
iedModel_CTRL_XCBR1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_XCBR1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_XCBR1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//iedModel_CTRL_XCBR1_Mod_Oper_T.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//USART_TRACE("CTRL_XCBR1_Mod\n");

iedModel_CTRL_XCBR1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_XCBR1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//USART_TRACE("CTRL_XCBR1_Beh\n");

iedModel_CTRL_XCBR1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_XCBR1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt16(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_XCBR1_Pos_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//USART_TRACE("CTRL_XCBR1_Pos\n");

iedModel_CTRL_XCBR1_Loc_stVal.mmsValue = MmsValue_newBoolean(true);
iedModel_CTRL_XCBR1_Loc_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_Loc_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//USART_TRACE("CTRL_XCBR1_Loc\n");

iedModel_CTRL_XCBR1_BlkOpn_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_XCBR1_BlkOpn_stVal.mmsValue = MmsValue_newIntegerFromInt16(0);
iedModel_CTRL_XCBR1_BlkOpn_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_BlkOpn_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_XCBR1_OpCnt_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_XCBR1_OpCnt_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

iedModel_CTRL_XCBR1_BlkCls_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_XCBR1_BlkCls_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_BlkCls_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_CTRL_XCBR1_CBOpCap_stVal.mmsValue = MmsValue_newUnsignedFromUint32(1);
iedModel_CTRL_XCBR1_CBOpCap_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_CBOpCap_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_XCBR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_XCBR1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//GGIO1 --------------------------------------------------------------------------------
iedModel_CTRL_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_GGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_GGIO1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_GGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_GGIO1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_GGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_CTRL_GGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_GGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);


iedModel_CTRL_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);

iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the alarm log");//Сброс флага новой записи в журнале аварий
iedModel_CTRL_GGIO1_SPCSO4_d.mmsValue = MmsValue_newVisibleString("Reset the LEDs and Relays");//Сброс индикации

iedModel_CTRL_GGIO1_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


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
iedModel_GGIO_INGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_INGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_INGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//OUTGGIO1
iedModel_GGIO_OUTGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_OUTGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_OUTGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_OUTGGIO1_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//LEDGGIO1
iedModel_GGIO_LEDGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_GGIO_LEDGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_GGIO_LEDGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_GGIO_LEDGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_GGIO_LEDGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LEDGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_LEDGGIO1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_LEDGGIO1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_LEDGGIO1_Health_q.mmsValue = MmsValue_newBitString(0);
/*
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_q,0);
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_q,0);
IedServer_updateQuality(iedServer,&iedModel_GGIO_LEDGGIO1_Health_q,0);
*/

iedModel_GGIO_LEDGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


//SSL
iedModel_GGIO_SSLGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_SSLGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_SSLGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_SSLGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_SSLGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_SSLGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_SSLGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind17_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind18_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind19_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind20_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind21_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind22_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind23_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind24_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//VLS
iedModel_GGIO_VLSGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_VLSGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_VLSGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_VLSGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_VLSGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_VLSGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_VLSGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//LS
iedModel_GGIO_LSGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_LSGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_LSGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_LSGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_LSGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LSGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_LSGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


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
iedModel_MES_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

iedModel_MES_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_MES_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_MES_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);

//MMXU1
iedModel_MES_MMXU1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_MES_MMXU1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_MMXU1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_MMXU1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_MES_MMXU1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_MMXU1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_MMXU1_Health_q.mmsValue = MmsValue_newBitString(0);

/*
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Mod_q,0);
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Beh_q,0);
IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Health_q,0);
*/
iedModel_MES_MMXU1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_MMXU1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//MMXU1 A
iedModel_MES_MMXU1_A_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_A_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_A_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_A_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_A_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_A_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_A_neut_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_A_neut_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// A db,zeroDb
iedModel_MES_MMXU1_A_phsA_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_A_phsA_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_A_phsB_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_A_phsB_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_A_phsC_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_A_phsC_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_A_neut_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db_In);
iedModel_MES_MMXU1_A_neut_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb_In);

//MSQI1
iedModel_MES_MSQI1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_MES_MSQI1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_MSQI1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_MSQI1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_MSQI1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_MSQI1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_MSQI1_Health_q.mmsValue = MmsValue_newBitString(0);

/*
IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Mod_q,0);
IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Beh_q,0);
IedServer_updateQuality(iedServer,&iedModel_MES_MSQI1_Health_q,0);
*/
iedModel_MES_MSQI1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_MSQI1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_MES_MSQI1_SeqA_c1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqA_c1_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MSQI1_SeqA_c2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqA_c2_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MSQI1_SeqA_c3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqA_c3_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// SeqA db,zeroDb
iedModel_MES_MSQI1_SeqA_c1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqA_c1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MSQI1_SeqA_c2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqA_c2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MSQI1_SeqA_c3_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqA_c3_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);


USART_TRACE("------------------------------------------------------------\n");
}

#endif
