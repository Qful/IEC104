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
extern GSEControlBlock iedModel_LD0_LLN0_gse2;
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
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda16;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda17;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda18;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda19;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda20;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda21;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda22;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda23;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda24;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda25;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda26;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda27;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda28;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda29;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda30;
extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda31;


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

extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda10;

extern DataSetEntry iedModelds_LD0_LLN0_dataset16_fcda0;

//LLN0.DS20
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda15;

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

DataObject iedModel_MES_MMXU1_phV;
DataObject iedModel_MES_MMXU1_phV_phsA;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal;
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsA_q;
DataAttribute iedModel_MES_MMXU1_phV_phsA_t;
DataAttribute iedModel_MES_MMXU1_phV_phsA_db;
DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_phV_phsB;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal;
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsB_q;
DataAttribute iedModel_MES_MMXU1_phV_phsB_t;
DataAttribute iedModel_MES_MMXU1_phV_phsB_db;
DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_phV_phsC;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal;
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_phsC_q;
DataAttribute iedModel_MES_MMXU1_phV_phsC_t;
DataAttribute iedModel_MES_MMXU1_phV_phsC_db;
DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb;

DataObject iedModel_MES_MMXU1_phV_neut;
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal;
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal;
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_phV_neut_q;
DataAttribute iedModel_MES_MMXU1_phV_neut_t;
DataAttribute iedModel_MES_MMXU1_phV_neut_db;
DataAttribute iedModel_MES_MMXU1_phV_neut_zeroDb;

//-
DataObject iedModel_MES_MMXU1_PPV;
DataObject iedModel_MES_MMXU1_PPV_phsA;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb;

DataObject iedModel_MES_MMXU1_PPV_phsB;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb;

DataObject iedModel_MES_MMXU1_PPV_phsC;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_q;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_t;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_db;
DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb;

DataObject    iedModel_MES_MMXU1_Hz;
DataAttribute iedModel_MES_MMXU1_Hz_mag;
DataAttribute iedModel_MES_MMXU1_Hz_mag_f;
DataAttribute iedModel_MES_MMXU1_Hz_instMag;
DataAttribute iedModel_MES_MMXU1_Hz_instMag_f;
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

// SeqU
DataObject iedModel_MES_MSQI1_SeqU;
DataObject iedModel_MES_MSQI1_SeqU_c1;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_t;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_db;
DataAttribute iedModel_MES_MSQI1_SeqU_c1_zeroDb;

DataObject iedModel_MES_MSQI1_SeqU_c2;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_t;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_db;
DataAttribute iedModel_MES_MSQI1_SeqU_c2_zeroDb;

DataObject iedModel_MES_MSQI1_SeqU_c3;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag_f;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_q;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_t;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_db;
DataAttribute iedModel_MES_MSQI1_SeqU_c3_zeroDb;
DataAttribute iedModel_MES_MSQI1_SeqU_SeqT;

/****************************************************************
* LN
*****************************************************************/
LogicalNode   iedModel_PROT_UPTOV1;

DataObject    iedModel_PROT_UPTOV1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTOV1_Mod_q;
DataAttribute iedModel_PROT_UPTOV1_Mod_t;
DataAttribute iedModel_PROT_UPTOV1_Mod_stVal;
DataAttribute iedModel_PROT_UPTOV1_Mod_ctlModel;

DataObject    iedModel_PROT_UPTOV1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTOV1_Beh_stVal;
DataAttribute iedModel_PROT_UPTOV1_Beh_q;
DataAttribute iedModel_PROT_UPTOV1_Beh_t;

DataObject    iedModel_PROT_UPTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTOV1_Health_stVal;
DataAttribute iedModel_PROT_UPTOV1_Health_q;
DataAttribute iedModel_PROT_UPTOV1_Health_t;

DataObject    iedModel_PROT_UPTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTOV1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTOV1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTOV1_Str;
DataAttribute iedModel_PROT_UPTOV1_Str_general;
DataAttribute iedModel_PROT_UPTOV1_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTOV1_Str_q;
DataAttribute iedModel_PROT_UPTOV1_Str_t;

DataObject    iedModel_PROT_UPTOV1_Op;
DataAttribute iedModel_PROT_UPTOV1_Op_general;
DataAttribute iedModel_PROT_UPTOV1_Op_q;
DataAttribute iedModel_PROT_UPTOV1_Op_t;


/****************************************************************
* LN UPTOV2
*****************************************************************/
LogicalNode   iedModel_PROT_UPTOV2;

DataObject    iedModel_PROT_UPTOV2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTOV2_Mod_q;
DataAttribute iedModel_PROT_UPTOV2_Mod_t;
DataAttribute iedModel_PROT_UPTOV2_Mod_stVal;
DataAttribute iedModel_PROT_UPTOV2_Mod_ctlModel;

DataObject    iedModel_PROT_UPTOV2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTOV2_Beh_stVal;
DataAttribute iedModel_PROT_UPTOV2_Beh_q;
DataAttribute iedModel_PROT_UPTOV2_Beh_t;

DataObject    iedModel_PROT_UPTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTOV2_Health_stVal;
DataAttribute iedModel_PROT_UPTOV2_Health_q;
DataAttribute iedModel_PROT_UPTOV2_Health_t;

DataObject    iedModel_PROT_UPTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTOV2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTOV2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTOV2_Str;
DataAttribute iedModel_PROT_UPTOV2_Str_general;
DataAttribute iedModel_PROT_UPTOV2_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTOV2_Str_q;
DataAttribute iedModel_PROT_UPTOV2_Str_t;

DataObject    iedModel_PROT_UPTOV2_Op;
DataAttribute iedModel_PROT_UPTOV2_Op_general;
DataAttribute iedModel_PROT_UPTOV2_Op_q;
DataAttribute iedModel_PROT_UPTOV2_Op_t;
/****************************************************************
* LN UPTOV3
*****************************************************************/
LogicalNode   iedModel_PROT_UPTOV3;

DataObject    iedModel_PROT_UPTOV3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTOV3_Mod_q;
DataAttribute iedModel_PROT_UPTOV3_Mod_t;
DataAttribute iedModel_PROT_UPTOV3_Mod_stVal;
DataAttribute iedModel_PROT_UPTOV3_Mod_ctlModel;

DataObject    iedModel_PROT_UPTOV3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTOV3_Beh_stVal;
DataAttribute iedModel_PROT_UPTOV3_Beh_q;
DataAttribute iedModel_PROT_UPTOV3_Beh_t;

DataObject    iedModel_PROT_UPTOV3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTOV3_Health_stVal;
DataAttribute iedModel_PROT_UPTOV3_Health_q;
DataAttribute iedModel_PROT_UPTOV3_Health_t;

DataObject    iedModel_PROT_UPTOV3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTOV3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTOV3_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTOV3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTOV3_Str;
DataAttribute iedModel_PROT_UPTOV3_Str_general;
DataAttribute iedModel_PROT_UPTOV3_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTOV3_Str_q;
DataAttribute iedModel_PROT_UPTOV3_Str_t;

DataObject    iedModel_PROT_UPTOV3_Op;
DataAttribute iedModel_PROT_UPTOV3_Op_general;
DataAttribute iedModel_PROT_UPTOV3_Op_q;
DataAttribute iedModel_PROT_UPTOV3_Op_t;

/****************************************************************
* LN UPTOV4
*****************************************************************/
LogicalNode   iedModel_PROT_UPTOV4;

DataObject    iedModel_PROT_UPTOV4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTOV4_Mod_q;
DataAttribute iedModel_PROT_UPTOV4_Mod_t;
DataAttribute iedModel_PROT_UPTOV4_Mod_stVal;
DataAttribute iedModel_PROT_UPTOV4_Mod_ctlModel;

DataObject    iedModel_PROT_UPTOV4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTOV4_Beh_stVal;
DataAttribute iedModel_PROT_UPTOV4_Beh_q;
DataAttribute iedModel_PROT_UPTOV4_Beh_t;

DataObject    iedModel_PROT_UPTOV4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTOV4_Health_stVal;
DataAttribute iedModel_PROT_UPTOV4_Health_q;
DataAttribute iedModel_PROT_UPTOV4_Health_t;

DataObject    iedModel_PROT_UPTOV4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTOV4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTOV4_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTOV4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTOV4_Str;
DataAttribute iedModel_PROT_UPTOV4_Str_general;
DataAttribute iedModel_PROT_UPTOV4_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTOV4_Str_q;
DataAttribute iedModel_PROT_UPTOV4_Str_t;

DataObject    iedModel_PROT_UPTOV4_Op;
DataAttribute iedModel_PROT_UPTOV4_Op_general;
DataAttribute iedModel_PROT_UPTOV4_Op_q;
DataAttribute iedModel_PROT_UPTOV4_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
LogicalNode   iedModel_PROT_UPTUV1;

DataObject    iedModel_PROT_UPTUV1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTUV1_Mod_q;
DataAttribute iedModel_PROT_UPTUV1_Mod_t;
DataAttribute iedModel_PROT_UPTUV1_Mod_stVal;
DataAttribute iedModel_PROT_UPTUV1_Mod_ctlModel;

DataObject    iedModel_PROT_UPTUV1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTUV1_Beh_stVal;
DataAttribute iedModel_PROT_UPTUV1_Beh_q;
DataAttribute iedModel_PROT_UPTUV1_Beh_t;

DataObject    iedModel_PROT_UPTUV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTUV1_Health_stVal;
DataAttribute iedModel_PROT_UPTUV1_Health_q;
DataAttribute iedModel_PROT_UPTUV1_Health_t;

DataObject    iedModel_PROT_UPTUV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTUV1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTUV1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTUV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTUV1_Str;
DataAttribute iedModel_PROT_UPTUV1_Str_general;
DataAttribute iedModel_PROT_UPTUV1_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTUV1_Str_q;
DataAttribute iedModel_PROT_UPTUV1_Str_t;

DataObject    iedModel_PROT_UPTUV1_Op;
DataAttribute iedModel_PROT_UPTUV1_Op_general;
DataAttribute iedModel_PROT_UPTUV1_Op_q;
DataAttribute iedModel_PROT_UPTUV1_Op_t;


/****************************************************************
* LN UPTUV2
*****************************************************************/
LogicalNode   iedModel_PROT_UPTUV2;

DataObject    iedModel_PROT_UPTUV2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTUV2_Mod_q;
DataAttribute iedModel_PROT_UPTUV2_Mod_t;
DataAttribute iedModel_PROT_UPTUV2_Mod_stVal;
DataAttribute iedModel_PROT_UPTUV2_Mod_ctlModel;

DataObject    iedModel_PROT_UPTUV2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTUV2_Beh_stVal;
DataAttribute iedModel_PROT_UPTUV2_Beh_q;
DataAttribute iedModel_PROT_UPTUV2_Beh_t;

DataObject    iedModel_PROT_UPTUV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTUV2_Health_stVal;
DataAttribute iedModel_PROT_UPTUV2_Health_q;
DataAttribute iedModel_PROT_UPTUV2_Health_t;

DataObject    iedModel_PROT_UPTUV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTUV2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTUV2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTUV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTUV2_Str;
DataAttribute iedModel_PROT_UPTUV2_Str_general;
DataAttribute iedModel_PROT_UPTUV2_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTUV2_Str_q;
DataAttribute iedModel_PROT_UPTUV2_Str_t;

DataObject    iedModel_PROT_UPTUV2_Op;
DataAttribute iedModel_PROT_UPTUV2_Op_general;
DataAttribute iedModel_PROT_UPTUV2_Op_q;
DataAttribute iedModel_PROT_UPTUV2_Op_t;

/****************************************************************
* LN UPTUV3
*****************************************************************/
LogicalNode   iedModel_PROT_UPTUV3;

DataObject    iedModel_PROT_UPTUV3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTUV3_Mod_q;
DataAttribute iedModel_PROT_UPTUV3_Mod_t;
DataAttribute iedModel_PROT_UPTUV3_Mod_stVal;
DataAttribute iedModel_PROT_UPTUV3_Mod_ctlModel;

DataObject    iedModel_PROT_UPTUV3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTUV3_Beh_stVal;
DataAttribute iedModel_PROT_UPTUV3_Beh_q;
DataAttribute iedModel_PROT_UPTUV3_Beh_t;

DataObject    iedModel_PROT_UPTUV3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTUV3_Health_stVal;
DataAttribute iedModel_PROT_UPTUV3_Health_q;
DataAttribute iedModel_PROT_UPTUV3_Health_t;

DataObject    iedModel_PROT_UPTUV3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTUV3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTUV3_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTUV3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTUV3_Str;
DataAttribute iedModel_PROT_UPTUV3_Str_general;
DataAttribute iedModel_PROT_UPTUV3_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTUV3_Str_q;
DataAttribute iedModel_PROT_UPTUV3_Str_t;

DataObject    iedModel_PROT_UPTUV3_Op;
DataAttribute iedModel_PROT_UPTUV3_Op_general;
DataAttribute iedModel_PROT_UPTUV3_Op_q;
DataAttribute iedModel_PROT_UPTUV3_Op_t;


/****************************************************************
* LN UPTUV4
*****************************************************************/
LogicalNode   iedModel_PROT_UPTUV4;

DataObject    iedModel_PROT_UPTUV4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_UPTUV4_Mod_q;
DataAttribute iedModel_PROT_UPTUV4_Mod_t;
DataAttribute iedModel_PROT_UPTUV4_Mod_stVal;
DataAttribute iedModel_PROT_UPTUV4_Mod_ctlModel;

DataObject    iedModel_PROT_UPTUV4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_UPTUV4_Beh_stVal;
DataAttribute iedModel_PROT_UPTUV4_Beh_q;
DataAttribute iedModel_PROT_UPTUV4_Beh_t;

DataObject    iedModel_PROT_UPTUV4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_UPTUV4_Health_stVal;
DataAttribute iedModel_PROT_UPTUV4_Health_q;
DataAttribute iedModel_PROT_UPTUV4_Health_t;

DataObject    iedModel_PROT_UPTUV4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_UPTUV4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_UPTUV4_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_UPTUV4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_UPTUV4_Str;
DataAttribute iedModel_PROT_UPTUV4_Str_general;
DataAttribute iedModel_PROT_UPTUV4_Str_dirGeneral;
DataAttribute iedModel_PROT_UPTUV4_Str_q;
DataAttribute iedModel_PROT_UPTUV4_Str_t;

DataObject    iedModel_PROT_UPTUV4_Op;
DataAttribute iedModel_PROT_UPTUV4_Op_general;
DataAttribute iedModel_PROT_UPTUV4_Op_q;
DataAttribute iedModel_PROT_UPTUV4_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U2PTOV1;

DataObject    iedModel_PROT_U2PTOV1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U2PTOV1_Mod_q;
DataAttribute iedModel_PROT_U2PTOV1_Mod_t;
DataAttribute iedModel_PROT_U2PTOV1_Mod_stVal;
DataAttribute iedModel_PROT_U2PTOV1_Mod_ctlModel;

DataObject    iedModel_PROT_U2PTOV1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U2PTOV1_Beh_stVal;
DataAttribute iedModel_PROT_U2PTOV1_Beh_q;
DataAttribute iedModel_PROT_U2PTOV1_Beh_t;

DataObject    iedModel_PROT_U2PTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U2PTOV1_Health_stVal;
DataAttribute iedModel_PROT_U2PTOV1_Health_q;
DataAttribute iedModel_PROT_U2PTOV1_Health_t;

DataObject    iedModel_PROT_U2PTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U2PTOV1_Str;
DataAttribute iedModel_PROT_U2PTOV1_Str_general;
DataAttribute iedModel_PROT_U2PTOV1_Str_dirGeneral;
DataAttribute iedModel_PROT_U2PTOV1_Str_q;
DataAttribute iedModel_PROT_U2PTOV1_Str_t;

DataObject    iedModel_PROT_U2PTOV1_Op;
DataAttribute iedModel_PROT_U2PTOV1_Op_general;
DataAttribute iedModel_PROT_U2PTOV1_Op_q;
DataAttribute iedModel_PROT_U2PTOV1_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U2PTOV2;

DataObject    iedModel_PROT_U2PTOV2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U2PTOV2_Mod_q;
DataAttribute iedModel_PROT_U2PTOV2_Mod_t;
DataAttribute iedModel_PROT_U2PTOV2_Mod_stVal;
DataAttribute iedModel_PROT_U2PTOV2_Mod_ctlModel;

DataObject    iedModel_PROT_U2PTOV2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U2PTOV2_Beh_stVal;
DataAttribute iedModel_PROT_U2PTOV2_Beh_q;
DataAttribute iedModel_PROT_U2PTOV2_Beh_t;

DataObject    iedModel_PROT_U2PTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U2PTOV2_Health_stVal;
DataAttribute iedModel_PROT_U2PTOV2_Health_q;
DataAttribute iedModel_PROT_U2PTOV2_Health_t;

DataObject    iedModel_PROT_U2PTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U2PTOV2_Str;
DataAttribute iedModel_PROT_U2PTOV2_Str_general;
DataAttribute iedModel_PROT_U2PTOV2_Str_dirGeneral;
DataAttribute iedModel_PROT_U2PTOV2_Str_q;
DataAttribute iedModel_PROT_U2PTOV2_Str_t;

DataObject    iedModel_PROT_U2PTOV2_Op;
DataAttribute iedModel_PROT_U2PTOV2_Op_general;
DataAttribute iedModel_PROT_U2PTOV2_Op_q;
DataAttribute iedModel_PROT_U2PTOV2_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U0PTOV1;

DataObject    iedModel_PROT_U0PTOV1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U0PTOV1_Mod_q;
DataAttribute iedModel_PROT_U0PTOV1_Mod_t;
DataAttribute iedModel_PROT_U0PTOV1_Mod_stVal;
DataAttribute iedModel_PROT_U0PTOV1_Mod_ctlModel;

DataObject    iedModel_PROT_U0PTOV1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U0PTOV1_Beh_stVal;
DataAttribute iedModel_PROT_U0PTOV1_Beh_q;
DataAttribute iedModel_PROT_U0PTOV1_Beh_t;

DataObject    iedModel_PROT_U0PTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U0PTOV1_Health_stVal;
DataAttribute iedModel_PROT_U0PTOV1_Health_q;
DataAttribute iedModel_PROT_U0PTOV1_Health_t;

DataObject    iedModel_PROT_U0PTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U0PTOV1_Str;
DataAttribute iedModel_PROT_U0PTOV1_Str_general;
DataAttribute iedModel_PROT_U0PTOV1_Str_dirGeneral;
DataAttribute iedModel_PROT_U0PTOV1_Str_q;
DataAttribute iedModel_PROT_U0PTOV1_Str_t;

DataObject    iedModel_PROT_U0PTOV1_Op;
DataAttribute iedModel_PROT_U0PTOV1_Op_general;
DataAttribute iedModel_PROT_U0PTOV1_Op_q;
DataAttribute iedModel_PROT_U0PTOV1_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U0PTOV2;

DataObject    iedModel_PROT_U0PTOV2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U0PTOV2_Mod_q;
DataAttribute iedModel_PROT_U0PTOV2_Mod_t;
DataAttribute iedModel_PROT_U0PTOV2_Mod_stVal;
DataAttribute iedModel_PROT_U0PTOV2_Mod_ctlModel;

DataObject    iedModel_PROT_U0PTOV2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U0PTOV2_Beh_stVal;
DataAttribute iedModel_PROT_U0PTOV2_Beh_q;
DataAttribute iedModel_PROT_U0PTOV2_Beh_t;

DataObject    iedModel_PROT_U0PTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U0PTOV2_Health_stVal;
DataAttribute iedModel_PROT_U0PTOV2_Health_q;
DataAttribute iedModel_PROT_U0PTOV2_Health_t;

DataObject    iedModel_PROT_U0PTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U0PTOV2_Str;
DataAttribute iedModel_PROT_U0PTOV2_Str_general;
DataAttribute iedModel_PROT_U0PTOV2_Str_dirGeneral;
DataAttribute iedModel_PROT_U0PTOV2_Str_q;
DataAttribute iedModel_PROT_U0PTOV2_Str_t;

DataObject    iedModel_PROT_U0PTOV2_Op;
DataAttribute iedModel_PROT_U0PTOV2_Op_general;
DataAttribute iedModel_PROT_U0PTOV2_Op_q;
DataAttribute iedModel_PROT_U0PTOV2_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U0PTOV3;

DataObject    iedModel_PROT_U0PTOV3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U0PTOV3_Mod_q;
DataAttribute iedModel_PROT_U0PTOV3_Mod_t;
DataAttribute iedModel_PROT_U0PTOV3_Mod_stVal;
DataAttribute iedModel_PROT_U0PTOV3_Mod_ctlModel;

DataObject    iedModel_PROT_U0PTOV3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U0PTOV3_Beh_stVal;
DataAttribute iedModel_PROT_U0PTOV3_Beh_q;
DataAttribute iedModel_PROT_U0PTOV3_Beh_t;

DataObject    iedModel_PROT_U0PTOV3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U0PTOV3_Health_stVal;
DataAttribute iedModel_PROT_U0PTOV3_Health_q;
DataAttribute iedModel_PROT_U0PTOV3_Health_t;

DataObject    iedModel_PROT_U0PTOV3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U0PTOV3_Str;
DataAttribute iedModel_PROT_U0PTOV3_Str_general;
DataAttribute iedModel_PROT_U0PTOV3_Str_dirGeneral;
DataAttribute iedModel_PROT_U0PTOV3_Str_q;
DataAttribute iedModel_PROT_U0PTOV3_Str_t;

DataObject    iedModel_PROT_U0PTOV3_Op;
DataAttribute iedModel_PROT_U0PTOV3_Op_general;
DataAttribute iedModel_PROT_U0PTOV3_Op_q;
DataAttribute iedModel_PROT_U0PTOV3_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U0PTOV4;

DataObject    iedModel_PROT_U0PTOV4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U0PTOV4_Mod_q;
DataAttribute iedModel_PROT_U0PTOV4_Mod_t;
DataAttribute iedModel_PROT_U0PTOV4_Mod_stVal;
DataAttribute iedModel_PROT_U0PTOV4_Mod_ctlModel;

DataObject    iedModel_PROT_U0PTOV4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U0PTOV4_Beh_stVal;
DataAttribute iedModel_PROT_U0PTOV4_Beh_q;
DataAttribute iedModel_PROT_U0PTOV4_Beh_t;

DataObject    iedModel_PROT_U0PTOV4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U0PTOV4_Health_stVal;
DataAttribute iedModel_PROT_U0PTOV4_Health_q;
DataAttribute iedModel_PROT_U0PTOV4_Health_t;

DataObject    iedModel_PROT_U0PTOV4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U0PTOV4_Str;
DataAttribute iedModel_PROT_U0PTOV4_Str_general;
DataAttribute iedModel_PROT_U0PTOV4_Str_dirGeneral;
DataAttribute iedModel_PROT_U0PTOV4_Str_q;
DataAttribute iedModel_PROT_U0PTOV4_Str_t;

DataObject    iedModel_PROT_U0PTOV4_Op;
DataAttribute iedModel_PROT_U0PTOV4_Op_general;
DataAttribute iedModel_PROT_U0PTOV4_Op_q;
DataAttribute iedModel_PROT_U0PTOV4_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U1PTUV1;

DataObject    iedModel_PROT_U1PTUV1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U1PTUV1_Mod_q;
DataAttribute iedModel_PROT_U1PTUV1_Mod_t;
DataAttribute iedModel_PROT_U1PTUV1_Mod_stVal;
DataAttribute iedModel_PROT_U1PTUV1_Mod_ctlModel;

DataObject    iedModel_PROT_U1PTUV1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U1PTUV1_Beh_stVal;
DataAttribute iedModel_PROT_U1PTUV1_Beh_q;
DataAttribute iedModel_PROT_U1PTUV1_Beh_t;

DataObject    iedModel_PROT_U1PTUV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U1PTUV1_Health_stVal;
DataAttribute iedModel_PROT_U1PTUV1_Health_q;
DataAttribute iedModel_PROT_U1PTUV1_Health_t;

DataObject    iedModel_PROT_U1PTUV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U1PTUV1_Str;
DataAttribute iedModel_PROT_U1PTUV1_Str_general;
DataAttribute iedModel_PROT_U1PTUV1_Str_dirGeneral;
DataAttribute iedModel_PROT_U1PTUV1_Str_q;
DataAttribute iedModel_PROT_U1PTUV1_Str_t;

DataObject    iedModel_PROT_U1PTUV1_Op;
DataAttribute iedModel_PROT_U1PTUV1_Op_general;
DataAttribute iedModel_PROT_U1PTUV1_Op_q;
DataAttribute iedModel_PROT_U1PTUV1_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_U1PTUV2;

DataObject    iedModel_PROT_U1PTUV2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_U1PTUV2_Mod_q;
DataAttribute iedModel_PROT_U1PTUV2_Mod_t;
DataAttribute iedModel_PROT_U1PTUV2_Mod_stVal;
DataAttribute iedModel_PROT_U1PTUV2_Mod_ctlModel;

DataObject    iedModel_PROT_U1PTUV2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_U1PTUV2_Beh_stVal;
DataAttribute iedModel_PROT_U1PTUV2_Beh_q;
DataAttribute iedModel_PROT_U1PTUV2_Beh_t;

DataObject    iedModel_PROT_U1PTUV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_U1PTUV2_Health_stVal;
DataAttribute iedModel_PROT_U1PTUV2_Health_q;
DataAttribute iedModel_PROT_U1PTUV2_Health_t;

DataObject    iedModel_PROT_U1PTUV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_U1PTUV2_Str;
DataAttribute iedModel_PROT_U1PTUV2_Str_general;
DataAttribute iedModel_PROT_U1PTUV2_Str_dirGeneral;
DataAttribute iedModel_PROT_U1PTUV2_Str_q;
DataAttribute iedModel_PROT_U1PTUV2_Str_t;

DataObject    iedModel_PROT_U1PTUV2_Op;
DataAttribute iedModel_PROT_U1PTUV2_Op_general;
DataAttribute iedModel_PROT_U1PTUV2_Op_q;
DataAttribute iedModel_PROT_U1PTUV2_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTOF1;

DataObject    iedModel_PROT_PTOF1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTOF1_Mod_q;
DataAttribute iedModel_PROT_PTOF1_Mod_t;
DataAttribute iedModel_PROT_PTOF1_Mod_stVal;
DataAttribute iedModel_PROT_PTOF1_Mod_ctlModel;

DataObject    iedModel_PROT_PTOF1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTOF1_Beh_stVal;
DataAttribute iedModel_PROT_PTOF1_Beh_q;
DataAttribute iedModel_PROT_PTOF1_Beh_t;

DataObject    iedModel_PROT_PTOF1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTOF1_Health_stVal;
DataAttribute iedModel_PROT_PTOF1_Health_q;
DataAttribute iedModel_PROT_PTOF1_Health_t;

DataObject    iedModel_PROT_PTOF1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTOF1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTOF1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTOF1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTOF1_Str;
DataAttribute iedModel_PROT_PTOF1_Str_general;
DataAttribute iedModel_PROT_PTOF1_Str_dirGeneral;
DataAttribute iedModel_PROT_PTOF1_Str_q;
DataAttribute iedModel_PROT_PTOF1_Str_t;

DataObject    iedModel_PROT_PTOF1_Op;
DataAttribute iedModel_PROT_PTOF1_Op_general;
DataAttribute iedModel_PROT_PTOF1_Op_q;
DataAttribute iedModel_PROT_PTOF1_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTOF2;

DataObject    iedModel_PROT_PTOF2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTOF2_Mod_q;
DataAttribute iedModel_PROT_PTOF2_Mod_t;
DataAttribute iedModel_PROT_PTOF2_Mod_stVal;
DataAttribute iedModel_PROT_PTOF2_Mod_ctlModel;

DataObject    iedModel_PROT_PTOF2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTOF2_Beh_stVal;
DataAttribute iedModel_PROT_PTOF2_Beh_q;
DataAttribute iedModel_PROT_PTOF2_Beh_t;

DataObject    iedModel_PROT_PTOF2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTOF2_Health_stVal;
DataAttribute iedModel_PROT_PTOF2_Health_q;
DataAttribute iedModel_PROT_PTOF2_Health_t;

DataObject    iedModel_PROT_PTOF2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTOF2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTOF2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTOF2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTOF2_Str;
DataAttribute iedModel_PROT_PTOF2_Str_general;
DataAttribute iedModel_PROT_PTOF2_Str_dirGeneral;
DataAttribute iedModel_PROT_PTOF2_Str_q;
DataAttribute iedModel_PROT_PTOF2_Str_t;

DataObject    iedModel_PROT_PTOF2_Op;
DataAttribute iedModel_PROT_PTOF2_Op_general;
DataAttribute iedModel_PROT_PTOF2_Op_q;
DataAttribute iedModel_PROT_PTOF2_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTOF3;

DataObject    iedModel_PROT_PTOF3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTOF3_Mod_q;
DataAttribute iedModel_PROT_PTOF3_Mod_t;
DataAttribute iedModel_PROT_PTOF3_Mod_stVal;
DataAttribute iedModel_PROT_PTOF3_Mod_ctlModel;

DataObject    iedModel_PROT_PTOF3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTOF3_Beh_stVal;
DataAttribute iedModel_PROT_PTOF3_Beh_q;
DataAttribute iedModel_PROT_PTOF3_Beh_t;

DataObject    iedModel_PROT_PTOF3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTOF3_Health_stVal;
DataAttribute iedModel_PROT_PTOF3_Health_q;
DataAttribute iedModel_PROT_PTOF3_Health_t;

DataObject    iedModel_PROT_PTOF3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTOF3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTOF3_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTOF3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTOF3_Str;
DataAttribute iedModel_PROT_PTOF3_Str_general;
DataAttribute iedModel_PROT_PTOF3_Str_dirGeneral;
DataAttribute iedModel_PROT_PTOF3_Str_q;
DataAttribute iedModel_PROT_PTOF3_Str_t;

DataObject    iedModel_PROT_PTOF3_Op;
DataAttribute iedModel_PROT_PTOF3_Op_general;
DataAttribute iedModel_PROT_PTOF3_Op_q;
DataAttribute iedModel_PROT_PTOF3_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTOF4;

DataObject    iedModel_PROT_PTOF4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTOF4_Mod_q;
DataAttribute iedModel_PROT_PTOF4_Mod_t;
DataAttribute iedModel_PROT_PTOF4_Mod_stVal;
DataAttribute iedModel_PROT_PTOF4_Mod_ctlModel;

DataObject    iedModel_PROT_PTOF4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTOF4_Beh_stVal;
DataAttribute iedModel_PROT_PTOF4_Beh_q;
DataAttribute iedModel_PROT_PTOF4_Beh_t;

DataObject    iedModel_PROT_PTOF4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTOF4_Health_stVal;
DataAttribute iedModel_PROT_PTOF4_Health_q;
DataAttribute iedModel_PROT_PTOF4_Health_t;

DataObject    iedModel_PROT_PTOF4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTOF4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTOF4_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTOF4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTOF4_Str;
DataAttribute iedModel_PROT_PTOF4_Str_general;
DataAttribute iedModel_PROT_PTOF4_Str_dirGeneral;
DataAttribute iedModel_PROT_PTOF4_Str_q;
DataAttribute iedModel_PROT_PTOF4_Str_t;

DataObject    iedModel_PROT_PTOF4_Op;
DataAttribute iedModel_PROT_PTOF4_Op_general;
DataAttribute iedModel_PROT_PTOF4_Op_q;
DataAttribute iedModel_PROT_PTOF4_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTUF1;

DataObject    iedModel_PROT_PTUF1_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTUF1_Mod_q;
DataAttribute iedModel_PROT_PTUF1_Mod_t;
DataAttribute iedModel_PROT_PTUF1_Mod_stVal;
DataAttribute iedModel_PROT_PTUF1_Mod_ctlModel;

DataObject    iedModel_PROT_PTUF1_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTUF1_Beh_stVal;
DataAttribute iedModel_PROT_PTUF1_Beh_q;
DataAttribute iedModel_PROT_PTUF1_Beh_t;

DataObject    iedModel_PROT_PTUF1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTUF1_Health_stVal;
DataAttribute iedModel_PROT_PTUF1_Health_q;
DataAttribute iedModel_PROT_PTUF1_Health_t;

DataObject    iedModel_PROT_PTUF1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTUF1_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTUF1_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTUF1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTUF1_Str;
DataAttribute iedModel_PROT_PTUF1_Str_general;
DataAttribute iedModel_PROT_PTUF1_Str_dirGeneral;
DataAttribute iedModel_PROT_PTUF1_Str_q;
DataAttribute iedModel_PROT_PTUF1_Str_t;

DataObject    iedModel_PROT_PTUF1_Op;
DataAttribute iedModel_PROT_PTUF1_Op_general;
DataAttribute iedModel_PROT_PTUF1_Op_q;
DataAttribute iedModel_PROT_PTUF1_Op_t;


/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTUF2;

DataObject    iedModel_PROT_PTUF2_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTUF2_Mod_q;
DataAttribute iedModel_PROT_PTUF2_Mod_t;
DataAttribute iedModel_PROT_PTUF2_Mod_stVal;
DataAttribute iedModel_PROT_PTUF2_Mod_ctlModel;

DataObject    iedModel_PROT_PTUF2_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTUF2_Beh_stVal;
DataAttribute iedModel_PROT_PTUF2_Beh_q;
DataAttribute iedModel_PROT_PTUF2_Beh_t;

DataObject    iedModel_PROT_PTUF2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTUF2_Health_stVal;
DataAttribute iedModel_PROT_PTUF2_Health_q;
DataAttribute iedModel_PROT_PTUF2_Health_t;

DataObject    iedModel_PROT_PTUF2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTUF2_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTUF2_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTUF2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTUF2_Str;
DataAttribute iedModel_PROT_PTUF2_Str_general;
DataAttribute iedModel_PROT_PTUF2_Str_dirGeneral;
DataAttribute iedModel_PROT_PTUF2_Str_q;
DataAttribute iedModel_PROT_PTUF2_Str_t;

DataObject    iedModel_PROT_PTUF2_Op;
DataAttribute iedModel_PROT_PTUF2_Op_general;
DataAttribute iedModel_PROT_PTUF2_Op_q;
DataAttribute iedModel_PROT_PTUF2_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTUF3;

DataObject    iedModel_PROT_PTUF3_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTUF3_Mod_q;
DataAttribute iedModel_PROT_PTUF3_Mod_t;
DataAttribute iedModel_PROT_PTUF3_Mod_stVal;
DataAttribute iedModel_PROT_PTUF3_Mod_ctlModel;

DataObject    iedModel_PROT_PTUF3_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTUF3_Beh_stVal;
DataAttribute iedModel_PROT_PTUF3_Beh_q;
DataAttribute iedModel_PROT_PTUF3_Beh_t;

DataObject    iedModel_PROT_PTUF3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTUF3_Health_stVal;
DataAttribute iedModel_PROT_PTUF3_Health_q;
DataAttribute iedModel_PROT_PTUF3_Health_t;

DataObject    iedModel_PROT_PTUF3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTUF3_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTUF3_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTUF3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTUF3_Str;
DataAttribute iedModel_PROT_PTUF3_Str_general;
DataAttribute iedModel_PROT_PTUF3_Str_dirGeneral;
DataAttribute iedModel_PROT_PTUF3_Str_q;
DataAttribute iedModel_PROT_PTUF3_Str_t;

DataObject    iedModel_PROT_PTUF3_Op;
DataAttribute iedModel_PROT_PTUF3_Op_general;
DataAttribute iedModel_PROT_PTUF3_Op_q;
DataAttribute iedModel_PROT_PTUF3_Op_t;

/****************************************************************
*
*****************************************************************/
LogicalNode   iedModel_PROT_PTUF4;

DataObject    iedModel_PROT_PTUF4_Mod;					// РЕЖИМ
DataAttribute iedModel_PROT_PTUF4_Mod_q;
DataAttribute iedModel_PROT_PTUF4_Mod_t;
DataAttribute iedModel_PROT_PTUF4_Mod_stVal;
DataAttribute iedModel_PROT_PTUF4_Mod_ctlModel;

DataObject    iedModel_PROT_PTUF4_Beh;					// РЕЖИМ РАБОТЫ
DataAttribute iedModel_PROT_PTUF4_Beh_stVal;
DataAttribute iedModel_PROT_PTUF4_Beh_q;
DataAttribute iedModel_PROT_PTUF4_Beh_t;

DataObject    iedModel_PROT_PTUF4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
DataAttribute iedModel_PROT_PTUF4_Health_stVal;
DataAttribute iedModel_PROT_PTUF4_Health_q;
DataAttribute iedModel_PROT_PTUF4_Health_t;

DataObject    iedModel_PROT_PTUF4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
DataAttribute iedModel_PROT_PTUF4_NamPlt_vendor;		// 		Имя поставщика
DataAttribute iedModel_PROT_PTUF4_NamPlt_swRev;			// 		Ревизия программной части
DataAttribute iedModel_PROT_PTUF4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

DataObject    iedModel_PROT_PTUF4_Str;
DataAttribute iedModel_PROT_PTUF4_Str_general;
DataAttribute iedModel_PROT_PTUF4_Str_dirGeneral;
DataAttribute iedModel_PROT_PTUF4_Str_q;
DataAttribute iedModel_PROT_PTUF4_Str_t;

DataObject    iedModel_PROT_PTUF4_Op;
DataAttribute iedModel_PROT_PTUF4_Op_general;
DataAttribute iedModel_PROT_PTUF4_Op_q;
DataAttribute iedModel_PROT_PTUF4_Op_t;

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
    "MR5PO60",
    &iedModel_Generic_LD0,
    NULL,//&iedModelds_LD0_LLN0_dataset0,			// DataSet
    NULL,//&iedModel_LD0_LLN0_report0,				// ReportControlBlock
    NULL,//&iedModel_LD0_LLN0_gse0,			// GSEControlBlock
    NULL,									// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,				// SettingGroupControlBlock
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
LogicalNode iedModel_LD0_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_LD0,	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_LD0_LLN0,	    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_LD0_LLN0,    NULL,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_LD0_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_LD0_LLN0,    NULL,  (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_LD0_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_LD0_LLN0_SGCB, (ModelNode*) &iedModel_LD0_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_LD0_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_LD0_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
//DataAttribute iedModel_LD0_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_LD0_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_PROT_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_PROT,	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LLN0_Mod};

DataObject iedModel_PROT_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_PROT_LLN0,	    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Mod_q,    0};
DataAttribute iedModel_PROT_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Beh_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_Health_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_PROT_LLN0,    NULL,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_PROT_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_PROT_LLN0,    NULL,  (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_PROT_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_PROT_LLN0_SGCB, (ModelNode*) &iedModel_PROT_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_PROT_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
//DataAttribute iedModel_PROT_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,	   (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_CTRL_LLN0,    NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_CTRL_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_CTRL_LLN0,    NULL,  (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_CTRL_LLN0_SGCB, (ModelNode*) &iedModel_CTRL_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_CTRL_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
//DataAttribute iedModel_CTRL_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_CTRL_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
/************************************************************************
 * MES_LLN0
 *************************************************************************/
LogicalNode iedModel_MES_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_MES,	   (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LLN0_Mod,};

DataObject iedModel_MES_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_MES_LLN0,	    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Mod_q,    0};
DataAttribute iedModel_MES_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Beh_stVal,    0};
DataAttribute iedModel_MES_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_Health_stVal,    0};
DataAttribute iedModel_MES_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_MES_LLN0,    NULL,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_MES_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_MES_LLN0,    NULL,  (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_MES_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_MES_LLN0_SGCB, (ModelNode*) &iedModel_MES_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_MES_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_MES_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
//DataAttribute iedModel_MES_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_MES_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
/************************************************************************
 * GGIO_LLN0
 *************************************************************************/
LogicalNode iedModel_GGIO_LLN0 = {    LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_GGIO,	 (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LLN0_Mod,};

DataObject iedModel_GGIO_LLN0_Mod = {    DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_GGIO_LLN0,	    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_q,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel = {    DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Beh = {    DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Health = {    DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_Health_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_NamPlt = {    DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_GGIO_LLN0,    NULL,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev = {    DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs = {    DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//DataObject iedModel_GGIO_LLN0_SGCB = 			{ DataObjectModelType,    "SGCB", (ModelNode*) &iedModel_GGIO_LLN0,    NULL,  (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG,     0,    0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG = 	{ DataAttributeModelType, "ActSG",(ModelNode*) &iedModel_GGIO_LLN0_SGCB, (ModelNode*) &iedModel_GGIO_LLN0_SGCB_q,     NULL,    0,    IEC61850_FC_CF,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_q = 		{ DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG, (ModelNode*) &iedModel_GGIO_LLN0_SGCB_t,     NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
//DataAttribute iedModel_GGIO_LLN0_SGCB_t = 		{ DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LLN0_SGCB_ActSG,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_LD0_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,  NULL,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    NULL,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_LD0_LPHD1_Proxy, (ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

/*************************************************************************
 * Логический узел PROT_LPHD1
 *************************************************************************/
LogicalNode iedModel_PROT_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

DataObject iedModel_PROT_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_PROT_LPHD1,    NULL,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_PROT_LPHD1_Proxy, (ModelNode*) &iedModel_PROT_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_PROT_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел CTRL_LPHD1
 *************************************************************************/
LogicalNode iedModel_CTRL_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_CTRL_LPHD1_Proxy, (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел MES_LPHD1
 *************************************************************************/
LogicalNode iedModel_MES_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};

DataObject iedModel_MES_LPHD1_PhyNam = 				{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_MES_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal = 	{    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_MES_LPHD1,    NULL,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_MES_LPHD1_Proxy, (ModelNode*) &iedModel_MES_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_MES_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};
/*************************************************************************
 * Логический узел GGIO_LPHD1
 *************************************************************************/
LogicalNode iedModel_GGIO_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

DataObject iedModel_GGIO_LPHD1_PhyNam = 			{    DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor = 	{    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_PhyHealth = 			{    DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q = 	{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t = 	{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_Proxy = 				{    DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_GGIO_LPHD1,    NULL,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LPHD1_Proxy, (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_GGIO_LPHD1_Proxy_q = 		{    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_t = 		{    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,    NULL,    0};


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
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1 /* &iedModel_GGIO_INGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 ****************************************************************************************************************************************************************/
DataObject iedModel_GGIO_INGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)NULL,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/
LogicalNode iedModel_GGIO_OUTGGIO1 						= { LogicalNodeModelType,   	"OUT16GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};

DataObject iedModel_GGIO_OUTGGIO1_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod, (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GGIO_OUTGGIO1_Beh 					= {    DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal 			= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q 				= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t 				= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_GGIO_OUTGGIO1_Health 				= {    DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal 		= {    DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q 			= {    DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t 			= {    DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_GGIO_OUTGGIO1_NamPlt 				= {    DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor 		= {    DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev 		= {    DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d 			= {    DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_OUTGGIO1_SPCSO1 					= {    DataObjectModelType,     "SPCSO1",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 		(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO2 					= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*)  &iedModel_GGIO_OUTGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO3 					= {    DataObjectModelType,     "SPCSO3",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO4 					= {    DataObjectModelType,     "SPCSO4",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO5 					= {    DataObjectModelType,     "SPCSO5",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO6 					= {    DataObjectModelType,     "SPCSO6",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO7 					= {    DataObjectModelType,     "SPCSO7",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO8 					= {    DataObjectModelType,     "SPCSO8",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO9 					= {    DataObjectModelType,     "SPCSO9",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO10 					= {    DataObjectModelType,     "SPCSO10",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO11 					= {    DataObjectModelType,     "SPCSO11",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO12 					= {    DataObjectModelType,     "SPCSO12",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO13 					= {    DataObjectModelType,     "SPCSO13",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO14 					= {    DataObjectModelType,     "SPCSO14",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO15 					= {    DataObjectModelType,     "SPCSO15",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO16 					= {    DataObjectModelType,     "SPCSO16",     	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};

/*************************************************************************
 * LED12GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_LEDGGIO1 					= { LogicalNodeModelType,   "LED12GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

DataObject iedModel_GGIO_LEDGGIO1_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Health 			= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_NamPlt 			= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind1,  (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_LEDGGIO1_Ind1 			= {DataObjectModelType,"Ind1",		(ModelNode*) &iedModel_GGIO_LEDGGIO1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q 	= {DataAttributeModelType,"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t 	= {DataAttributeModelType,"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_dU,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q = {    DataAttributeModelType,    "q",  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t = {    DataAttributeModelType,    "t",  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind3 = {    DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind4 = {    DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_dU 	= { DataAttributeModelType, "dU",  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind5 = {    DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind6 = {    DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind7 = {    DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind8 = {    DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind9 = { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind10 = { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind11 = { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind12 = { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_dU 	= { DataAttributeModelType, "dU",  	  (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_SSLGGIO1 			= { LogicalNodeModelType,   "SSL24GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod};

DataObject iedModel_GGIO_SSLGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*)&iedModel_GGIO_SSLGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind17 = {DataObjectModelType,"Ind17",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind17,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind18 = {DataObjectModelType,"Ind18",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind18,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind19 = {DataObjectModelType,"Ind19",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind19,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind20 = {DataObjectModelType,"Ind20",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind20,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind21 = {DataObjectModelType,"Ind21",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind21,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind22 = {DataObjectModelType,"Ind22",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind22,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind23 = {DataObjectModelType,"Ind23",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind23,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind24 = {DataObjectModelType,"Ind24",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_VLSGGIO1 			= { LogicalNodeModelType,   "VLS8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod};

DataObject iedModel_GGIO_VLSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*)&iedModel_GGIO_VLSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LSGGIO1 			= { LogicalNodeModelType,   "LS8GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod};

DataObject iedModel_GGIO_LSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*)&iedModel_GGIO_LSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind2,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind3 = {DataObjectModelType,"Ind3",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind3,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind4 = {DataObjectModelType,"Ind4",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind4,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind5 = {DataObjectModelType,"Ind5",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind5,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind6 = {DataObjectModelType,"Ind6",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind6,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind7 = {DataObjectModelType,"Ind7",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind7,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};

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
DataAttribute iedModel_MES_MMXU1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    (ModelNode*) &iedModel_MES_MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MMXU1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_MMXU1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    (ModelNode*) &iedModel_MES_MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MMXU1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_MMXU1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MMXU1_Health,    (ModelNode*) &iedModel_MES_MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_MMXU1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MMXU1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MMXU1,    (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*) &iedModel_MES_MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MMXU1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


/***************************************************************************************************************************************************************
 *
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 *
 ****************************************************************************************************************************************************************/

DataObject iedModel_MES_MMXU1_phV 						= { DataObjectModelType, "PhV", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, 0 };
DataObject iedModel_MES_MMXU1_phV_phsA 					= { DataObjectModelType, "phsA", (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*)&iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_instCVal, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};

DataAttribute iedModel_MES_MMXU1_phV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_MMXU1_phV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_phsB 					= { DataObjectModelType, "phsB", (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*)&iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_instCVal, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_MMXU1_phV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_phsC 					= { DataObjectModelType, "phsC", (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*)&iedModel_MES_MMXU1_phV_neut, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_instCVal, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_q, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC,  (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_MMXU1_phV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_phV_neut 					= { DataObjectModelType, "neut", (ModelNode*) &iedModel_MES_MMXU1_phV, (ModelNode*)NULL /*&iedModel_MES_MMXU1_phV_neut*/, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_phV_neut, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_instCVal, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_neut_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_phV_neut, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_q, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_phV_neut_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_phV_neut_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_phV_neut, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_phV_neut,  (ModelNode*) &iedModel_MES_MMXU1_phV_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_phV_neut_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_phV_neut, (ModelNode*) &iedModel_MES_MMXU1_phV_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_phV_neut_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_phV_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// PPV
DataObject iedModel_MES_MMXU1_PPV 						= { DataObjectModelType, "PPV", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, 0 };
DataObject iedModel_MES_MMXU1_PPV_phsA 					= { DataObjectModelType, "phsAB", (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*)&iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_instCVal, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsA_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_PPV_phsB 					= { DataObjectModelType, "phsBC", (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*)&iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_instCVal, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MMXU1_PPV_phsC 					= { DataObjectModelType, "phsCA", (ModelNode*) &iedModel_MES_MMXU1_PPV, (ModelNode*)NULL /*&iedModel_MES_MMXU1_PPV_phsC*/, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal, 0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_instCVal, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_q, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC,  (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MMXU1_PPV_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_PPV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject    iedModel_MES_MMXU1_Hz 				= { DataObjectModelType, "Hz", (ModelNode*) &iedModel_MES_MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_MMXU1_Hz_mag, 0 };
DataAttribute iedModel_MES_MMXU1_Hz_mag 			= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MMXU1_Hz,(ModelNode*)&iedModel_MES_MMXU1_Hz_instMag, (ModelNode*) &iedModel_MES_MMXU1_Hz_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_mag_f 			= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_Hz_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_instMag 		= { DataAttributeModelType, "instMag", (ModelNode*) &iedModel_MES_MMXU1_Hz,(ModelNode*)&iedModel_MES_MMXU1_Hz_q, (ModelNode*) &iedModel_MES_MMXU1_Hz_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_instMag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MMXU1_Hz_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MMXU1_Hz_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MMXU1_Hz, (ModelNode*) &iedModel_MES_MMXU1_Hz_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MMXU1_Hz_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MMXU1_Hz, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//--------------------------------------
LogicalNode iedModel_MES_MSQI1 						= {    LogicalNodeModelType,    "MSQI1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)NULL,    (ModelNode*) &iedModel_MES_MSQI1_Mod};

DataObject iedModel_MES_MSQI1_Mod 					= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Mod_q,0};
DataAttribute iedModel_MES_MSQI1_Mod_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_stVal 			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    (ModelNode*) &iedModel_MES_MSQI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_MSQI1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_MSQI1_Beh 					= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_MSQI1_Beh_stVal 			= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_q 				= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    (ModelNode*) &iedModel_MES_MSQI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_Beh_t 				= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MSQI1_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_MSQI1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_MSQI1_Health,    (ModelNode*) &iedModel_MES_MSQI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_MSQI1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_MSQI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_MSQI1_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_MSQI1,    (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*) &iedModel_MES_MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_vendor 		= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_swRev	 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    (ModelNode*) &iedModel_MES_MSQI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_MSQI1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_MSQI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// SeqU
#ifdef _SPCECIALSWRevision
DataObject iedModel_MES_MSQI1_SeqU 						= { DataObjectModelType, "SeqU", (ModelNode*) &iedModel_MES_MMXU1, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, 0 };
#else
DataObject iedModel_MES_MSQI1_SeqU 						= { DataObjectModelType, "SeqV", (ModelNode*) &iedModel_MES_MMXU1, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, 0 };
#endif
DataObject iedModel_MES_MSQI1_SeqU_c1 					= { DataObjectModelType, "c1", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*)&iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag_f = { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c1_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c1_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c1, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MSQI1_SeqU_c2 					= { DataObjectModelType, "c2", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*)&iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag_f	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c2_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c2_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c2, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_MSQI1_SeqU_c3 					= { DataObjectModelType, "c3", (ModelNode*) &iedModel_MES_MSQI1_SeqU, (ModelNode*) &iedModel_MES_MSQI1_SeqU_SeqT, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal, 0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_instCVal, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_q, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag 	= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_instCVal, NULL, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag_f = { DataAttributeModelType, "f", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_MSQI1_SeqU_c3_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_MSQI1_SeqU_c3_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_MES_MSQI1_SeqU_c3, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataAttribute iedModel_MES_MSQI1_SeqU_SeqT 		= { DataAttributeModelType, "seqT", (ModelNode*) &iedModel_MES_MSQI1_SeqU, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};


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
LogicalNode iedModel_PROT_UPTOV1 = {    LogicalNodeModelType,    "UPTOV1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod};

DataObject iedModel_PROT_UPTOV1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Str, (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV1,  	(ModelNode*)&iedModel_PROT_UPTOV1_Op, (ModelNode*) &iedModel_PROT_UPTOV1_Str_general,0};
DataAttribute iedModel_PROT_UPTOV1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV1_Op_general,0};
DataAttribute iedModel_PROT_UPTOV1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV1_Op,  (ModelNode*) &iedModel_PROT_UPTOV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV1_Op,  (ModelNode*) &iedModel_PROT_UPTOV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// UPTOV2 -------------------
LogicalNode iedModel_PROT_UPTOV2 = {    LogicalNodeModelType,    "UPTOV2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod};

DataObject iedModel_PROT_UPTOV2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Str, (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV2,  	(ModelNode*)&iedModel_PROT_UPTOV2_Op, (ModelNode*) &iedModel_PROT_UPTOV2_Str_general,0};
DataAttribute iedModel_PROT_UPTOV2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV2_Op_general,0};
DataAttribute iedModel_PROT_UPTOV2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV2_Op,  (ModelNode*) &iedModel_PROT_UPTOV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV2_Op,  (ModelNode*) &iedModel_PROT_UPTOV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// UPTOV3 -------------------
LogicalNode iedModel_PROT_UPTOV3 = {    LogicalNodeModelType,    "UPTOV3",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod};

DataObject iedModel_PROT_UPTOV3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Str, (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV3,  	(ModelNode*)&iedModel_PROT_UPTOV3_Op, (ModelNode*) &iedModel_PROT_UPTOV3_Str_general,0};
DataAttribute iedModel_PROT_UPTOV3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV3_Op_general,0};
DataAttribute iedModel_PROT_UPTOV3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV3_Op,  (ModelNode*) &iedModel_PROT_UPTOV3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV3_Op,  (ModelNode*) &iedModel_PROT_UPTOV3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// UPTOV4 -------------------
LogicalNode iedModel_PROT_UPTOV4 = {    LogicalNodeModelType,    "UPTOV4",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod};

DataObject iedModel_PROT_UPTOV4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Str, (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV4,  	(ModelNode*)&iedModel_PROT_UPTOV4_Op, (ModelNode*) &iedModel_PROT_UPTOV4_Str_general,0};
DataAttribute iedModel_PROT_UPTOV4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV4_Op_general,0};
DataAttribute iedModel_PROT_UPTOV4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV4_Op,  (ModelNode*) &iedModel_PROT_UPTOV4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV4_Op,  (ModelNode*) &iedModel_PROT_UPTOV4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_UPTUV1 = {    LogicalNodeModelType,    "UPTUV1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod};

DataObject iedModel_PROT_UPTUV1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Str, (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV1,  	(ModelNode*)&iedModel_PROT_UPTUV1_Op, (ModelNode*) &iedModel_PROT_UPTUV1_Str_general,0};
DataAttribute iedModel_PROT_UPTUV1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV1_Op_general,0};
DataAttribute iedModel_PROT_UPTUV1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV1_Op,  (ModelNode*) &iedModel_PROT_UPTUV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV1_Op,  (ModelNode*) &iedModel_PROT_UPTUV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// UPTUV2 -------------------
LogicalNode iedModel_PROT_UPTUV2 = {    LogicalNodeModelType,    "UPTUV2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod};

DataObject iedModel_PROT_UPTUV2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Str, (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV2,  	(ModelNode*)&iedModel_PROT_UPTUV2_Op, (ModelNode*) &iedModel_PROT_UPTUV2_Str_general,0};
DataAttribute iedModel_PROT_UPTUV2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV2_Op_general,0};
DataAttribute iedModel_PROT_UPTUV2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV2_Op,  (ModelNode*) &iedModel_PROT_UPTUV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV2_Op,  (ModelNode*) &iedModel_PROT_UPTUV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// UPTUV3 -------------------
LogicalNode iedModel_PROT_UPTUV3 = {    LogicalNodeModelType,    "UPTUV3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod};

DataObject iedModel_PROT_UPTUV3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Str, (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV3,  	(ModelNode*)&iedModel_PROT_UPTUV3_Op, (ModelNode*) &iedModel_PROT_UPTUV3_Str_general,0};
DataAttribute iedModel_PROT_UPTUV3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV3_Op_general,0};
DataAttribute iedModel_PROT_UPTUV3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV3_Op,  (ModelNode*) &iedModel_PROT_UPTUV3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV3_Op,  (ModelNode*) &iedModel_PROT_UPTUV3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// UPTUV4 -------------------
LogicalNode iedModel_PROT_UPTUV4 = {    LogicalNodeModelType,    "UPTUV4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_U2PTOV1,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod};

DataObject iedModel_PROT_UPTUV4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Str, (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV4,  	(ModelNode*)&iedModel_PROT_UPTUV4_Op, (ModelNode*) &iedModel_PROT_UPTUV4_Str_general,0};
DataAttribute iedModel_PROT_UPTUV4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV4_Op_general,0};
DataAttribute iedModel_PROT_UPTUV4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV4_Op,  (ModelNode*) &iedModel_PROT_UPTUV4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV4_Op,  (ModelNode*) &iedModel_PROT_UPTUV4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_U2PTOV1 = {    LogicalNodeModelType,    "U2PTOV1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_U2PTOV2,    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod};

DataObject iedModel_PROT_U2PTOV1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U2PTOV1,    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod_q,0};
DataAttribute iedModel_PROT_U2PTOV1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U2PTOV1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U2PTOV1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U2PTOV1,    (ModelNode*) &iedModel_PROT_U2PTOV1_Health,    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh_stVal,0};
DataAttribute iedModel_PROT_U2PTOV1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U2PTOV1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U2PTOV1,    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV1_Health_stVal,0};
DataAttribute iedModel_PROT_U2PTOV1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U2PTOV1_Health,    (ModelNode*) &iedModel_PROT_U2PTOV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV1_Health,    (ModelNode*) &iedModel_PROT_U2PTOV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U2PTOV1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U2PTOV1,    (ModelNode*) &iedModel_PROT_U2PTOV1_Str, (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U2PTOV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U2PTOV1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U2PTOV1,  	(ModelNode*)&iedModel_PROT_U2PTOV1_Op, (ModelNode*) &iedModel_PROT_U2PTOV1_Str_general,0};
DataAttribute iedModel_PROT_U2PTOV1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U2PTOV1_Str,  (ModelNode*) &iedModel_PROT_U2PTOV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U2PTOV1_Str,  (ModelNode*) &iedModel_PROT_U2PTOV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U2PTOV1_Str,  (ModelNode*) &iedModel_PROT_U2PTOV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U2PTOV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U2PTOV1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U2PTOV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U2PTOV1_Op_general,0};
DataAttribute iedModel_PROT_U2PTOV1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U2PTOV1_Op,  (ModelNode*) &iedModel_PROT_U2PTOV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U2PTOV1_Op,  (ModelNode*) &iedModel_PROT_U2PTOV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U2PTOV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_U2PTOV2 = {    LogicalNodeModelType,    "U2PTOV2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_U0PTOV1,    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod};

DataObject iedModel_PROT_U2PTOV2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U2PTOV2,    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod_q,0};
DataAttribute iedModel_PROT_U2PTOV2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U2PTOV2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U2PTOV2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U2PTOV2,    (ModelNode*) &iedModel_PROT_U2PTOV2_Health,    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh_stVal,0};
DataAttribute iedModel_PROT_U2PTOV2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U2PTOV2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U2PTOV2,    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV2_Health_stVal,0};
DataAttribute iedModel_PROT_U2PTOV2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U2PTOV2_Health,    (ModelNode*) &iedModel_PROT_U2PTOV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U2PTOV2_Health,    (ModelNode*) &iedModel_PROT_U2PTOV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U2PTOV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U2PTOV2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U2PTOV2,    (ModelNode*) &iedModel_PROT_U2PTOV2_Str, (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U2PTOV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U2PTOV2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U2PTOV2,  	(ModelNode*)&iedModel_PROT_U2PTOV2_Op, (ModelNode*) &iedModel_PROT_U2PTOV2_Str_general,0};
DataAttribute iedModel_PROT_U2PTOV2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U2PTOV2_Str,  (ModelNode*) &iedModel_PROT_U2PTOV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U2PTOV2_Str,  (ModelNode*) &iedModel_PROT_U2PTOV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U2PTOV2_Str,  (ModelNode*) &iedModel_PROT_U2PTOV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U2PTOV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U2PTOV2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U2PTOV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U2PTOV2_Op_general,0};
DataAttribute iedModel_PROT_U2PTOV2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U2PTOV2_Op,  (ModelNode*) &iedModel_PROT_U2PTOV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U2PTOV2_Op,  (ModelNode*) &iedModel_PROT_U2PTOV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U2PTOV2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U2PTOV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_U0PTOV1 = {    LogicalNodeModelType,    "U0PTOV1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_U0PTOV2,    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod};

DataObject iedModel_PROT_U0PTOV1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U0PTOV1,    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod_q,0};
DataAttribute iedModel_PROT_U0PTOV1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U0PTOV1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U0PTOV1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U0PTOV1,    (ModelNode*) &iedModel_PROT_U0PTOV1_Health,    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh_stVal,0};
DataAttribute iedModel_PROT_U0PTOV1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U0PTOV1,    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV1_Health_stVal,0};
DataAttribute iedModel_PROT_U0PTOV1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV1_Health,    (ModelNode*) &iedModel_PROT_U0PTOV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV1_Health,    (ModelNode*) &iedModel_PROT_U0PTOV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U0PTOV1,    (ModelNode*) &iedModel_PROT_U0PTOV1_Str, (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U0PTOV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U0PTOV1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U0PTOV1,  	(ModelNode*)&iedModel_PROT_U0PTOV1_Op, (ModelNode*) &iedModel_PROT_U0PTOV1_Str_general,0};
DataAttribute iedModel_PROT_U0PTOV1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV1_Str,  (ModelNode*) &iedModel_PROT_U0PTOV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U0PTOV1_Str,  (ModelNode*) &iedModel_PROT_U0PTOV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV1_Str,  (ModelNode*) &iedModel_PROT_U0PTOV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U0PTOV1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U0PTOV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U0PTOV1_Op_general,0};
DataAttribute iedModel_PROT_U0PTOV1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV1_Op,  (ModelNode*) &iedModel_PROT_U0PTOV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV1_Op,  (ModelNode*) &iedModel_PROT_U0PTOV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_U0PTOV2 = {    LogicalNodeModelType,    "U0PTOV2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_U0PTOV3,    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod};

DataObject iedModel_PROT_U0PTOV2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U0PTOV2,    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod_q,0};
DataAttribute iedModel_PROT_U0PTOV2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U0PTOV2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U0PTOV2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U0PTOV2,    (ModelNode*) &iedModel_PROT_U0PTOV2_Health,    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh_stVal,0};
DataAttribute iedModel_PROT_U0PTOV2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U0PTOV2,    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV2_Health_stVal,0};
DataAttribute iedModel_PROT_U0PTOV2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV2_Health,    (ModelNode*) &iedModel_PROT_U0PTOV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV2_Health,    (ModelNode*) &iedModel_PROT_U0PTOV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U0PTOV2,    (ModelNode*) &iedModel_PROT_U0PTOV2_Str, (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U0PTOV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U0PTOV2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U0PTOV2,  	(ModelNode*)&iedModel_PROT_U0PTOV2_Op, (ModelNode*) &iedModel_PROT_U0PTOV2_Str_general,0};
DataAttribute iedModel_PROT_U0PTOV2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV2_Str,  (ModelNode*) &iedModel_PROT_U0PTOV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U0PTOV2_Str,  (ModelNode*) &iedModel_PROT_U0PTOV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV2_Str,  (ModelNode*) &iedModel_PROT_U0PTOV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U0PTOV2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U0PTOV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U0PTOV2_Op_general,0};
DataAttribute iedModel_PROT_U0PTOV2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV2_Op,  (ModelNode*) &iedModel_PROT_U0PTOV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV2_Op,  (ModelNode*) &iedModel_PROT_U0PTOV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// -------------------
// -------------------
LogicalNode iedModel_PROT_U0PTOV3 = {    LogicalNodeModelType,    "U0PTOV3",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_U0PTOV4,    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod};

DataObject iedModel_PROT_U0PTOV3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U0PTOV3,    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod_q,0};
DataAttribute iedModel_PROT_U0PTOV3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U0PTOV3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U0PTOV3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U0PTOV3,    (ModelNode*) &iedModel_PROT_U0PTOV3_Health,    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh_stVal,0};
DataAttribute iedModel_PROT_U0PTOV3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U0PTOV3,    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV3_Health_stVal,0};
DataAttribute iedModel_PROT_U0PTOV3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV3_Health,    (ModelNode*) &iedModel_PROT_U0PTOV3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV3_Health,    (ModelNode*) &iedModel_PROT_U0PTOV3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U0PTOV3,    (ModelNode*) &iedModel_PROT_U0PTOV3_Str, (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U0PTOV3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U0PTOV3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U0PTOV3,  	(ModelNode*)&iedModel_PROT_U0PTOV3_Op, (ModelNode*) &iedModel_PROT_U0PTOV3_Str_general,0};
DataAttribute iedModel_PROT_U0PTOV3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV3_Str,  (ModelNode*) &iedModel_PROT_U0PTOV3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U0PTOV3_Str,  (ModelNode*) &iedModel_PROT_U0PTOV3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV3_Str,  (ModelNode*) &iedModel_PROT_U0PTOV3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U0PTOV3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U0PTOV3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U0PTOV3_Op_general,0};
DataAttribute iedModel_PROT_U0PTOV3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV3_Op,  (ModelNode*) &iedModel_PROT_U0PTOV3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV3_Op,  (ModelNode*) &iedModel_PROT_U0PTOV3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
// -------------------
LogicalNode iedModel_PROT_U0PTOV4 = {    LogicalNodeModelType,    "U0PTOV4",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_U1PTUV1,    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod};

DataObject iedModel_PROT_U0PTOV4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U0PTOV4,    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod_q,0};
DataAttribute iedModel_PROT_U0PTOV4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod,    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U0PTOV4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U0PTOV4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U0PTOV4,    (ModelNode*) &iedModel_PROT_U0PTOV4_Health,    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh_stVal,0};
DataAttribute iedModel_PROT_U0PTOV4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh,    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U0PTOV4,    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV4_Health_stVal,0};
DataAttribute iedModel_PROT_U0PTOV4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U0PTOV4_Health,    (ModelNode*) &iedModel_PROT_U0PTOV4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U0PTOV4_Health,    (ModelNode*) &iedModel_PROT_U0PTOV4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U0PTOV4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U0PTOV4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U0PTOV4,    (ModelNode*) &iedModel_PROT_U0PTOV4_Str, (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U0PTOV4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U0PTOV4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U0PTOV4,  	(ModelNode*)&iedModel_PROT_U0PTOV4_Op, (ModelNode*) &iedModel_PROT_U0PTOV4_Str_general,0};
DataAttribute iedModel_PROT_U0PTOV4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV4_Str,  (ModelNode*) &iedModel_PROT_U0PTOV4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U0PTOV4_Str,  (ModelNode*) &iedModel_PROT_U0PTOV4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV4_Str,  (ModelNode*) &iedModel_PROT_U0PTOV4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U0PTOV4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U0PTOV4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U0PTOV4_Op_general,0};
DataAttribute iedModel_PROT_U0PTOV4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U0PTOV4_Op,  (ModelNode*) &iedModel_PROT_U0PTOV4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U0PTOV4_Op,  (ModelNode*) &iedModel_PROT_U0PTOV4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U0PTOV4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U0PTOV4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_U1PTUV1 = {    LogicalNodeModelType,    "U1PTUV1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_U1PTUV2,    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod};

DataObject iedModel_PROT_U1PTUV1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U1PTUV1,    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod_q,0};
DataAttribute iedModel_PROT_U1PTUV1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U1PTUV1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U1PTUV1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U1PTUV1,    (ModelNode*) &iedModel_PROT_U1PTUV1_Health,    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh_stVal,0};
DataAttribute iedModel_PROT_U1PTUV1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U1PTUV1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U1PTUV1,    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV1_Health_stVal,0};
DataAttribute iedModel_PROT_U1PTUV1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U1PTUV1_Health,    (ModelNode*) &iedModel_PROT_U1PTUV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV1_Health,    (ModelNode*) &iedModel_PROT_U1PTUV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U1PTUV1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U1PTUV1,    (ModelNode*) &iedModel_PROT_U1PTUV1_Str, (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U1PTUV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U1PTUV1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U1PTUV1,  	(ModelNode*)&iedModel_PROT_U1PTUV1_Op, (ModelNode*) &iedModel_PROT_U1PTUV1_Str_general,0};
DataAttribute iedModel_PROT_U1PTUV1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U1PTUV1_Str,  (ModelNode*) &iedModel_PROT_U1PTUV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U1PTUV1_Str,  (ModelNode*) &iedModel_PROT_U1PTUV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U1PTUV1_Str,  (ModelNode*) &iedModel_PROT_U1PTUV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U1PTUV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U1PTUV1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U1PTUV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U1PTUV1_Op_general,0};
DataAttribute iedModel_PROT_U1PTUV1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U1PTUV1_Op,  (ModelNode*) &iedModel_PROT_U1PTUV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U1PTUV1_Op,  (ModelNode*) &iedModel_PROT_U1PTUV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U1PTUV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// -------------------
LogicalNode iedModel_PROT_U1PTUV2 = {    LogicalNodeModelType,    "U1PTUV2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod};

DataObject iedModel_PROT_U1PTUV2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_U1PTUV2,    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod_q,0};
DataAttribute iedModel_PROT_U1PTUV2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod,    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_U1PTUV2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_U1PTUV2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_U1PTUV2,    (ModelNode*) &iedModel_PROT_U1PTUV2_Health,    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh_stVal,0};
DataAttribute iedModel_PROT_U1PTUV2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh,    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U1PTUV2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_U1PTUV2,    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV2_Health_stVal,0};
DataAttribute iedModel_PROT_U1PTUV2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_U1PTUV2_Health,    (ModelNode*) &iedModel_PROT_U1PTUV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_U1PTUV2_Health,    (ModelNode*) &iedModel_PROT_U1PTUV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_U1PTUV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_U1PTUV2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_U1PTUV2,    (ModelNode*) &iedModel_PROT_U1PTUV2_Str, (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_U1PTUV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_U1PTUV2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_U1PTUV2,  	(ModelNode*)&iedModel_PROT_U1PTUV2_Op, (ModelNode*) &iedModel_PROT_U1PTUV2_Str_general,0};
DataAttribute iedModel_PROT_U1PTUV2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U1PTUV2_Str,  (ModelNode*) &iedModel_PROT_U1PTUV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_U1PTUV2_Str,  (ModelNode*) &iedModel_PROT_U1PTUV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U1PTUV2_Str,  (ModelNode*) &iedModel_PROT_U1PTUV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U1PTUV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_U1PTUV2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_U1PTUV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_U1PTUV2_Op_general,0};
DataAttribute iedModel_PROT_U1PTUV2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_U1PTUV2_Op,  (ModelNode*) &iedModel_PROT_U1PTUV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_U1PTUV2_Op,  (ModelNode*) &iedModel_PROT_U1PTUV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_U1PTUV2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_U1PTUV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_PTOF1 = {    LogicalNodeModelType,    "PTOF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF1_Mod};

DataObject iedModel_PROT_PTOF1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_q,0};
DataAttribute iedModel_PROT_PTOF1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Str, (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF1,  	(ModelNode*)&iedModel_PROT_PTOF1_Op, (ModelNode*) &iedModel_PROT_PTOF1_Str_general,0};
DataAttribute iedModel_PROT_PTOF1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF1_Op_general,0};
DataAttribute iedModel_PROT_PTOF1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF1_Op,  (ModelNode*) &iedModel_PROT_PTOF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF1_Op,  (ModelNode*) &iedModel_PROT_PTOF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// PTOF2-------------------
LogicalNode iedModel_PROT_PTOF2 = {    LogicalNodeModelType,    "PTOF2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF2_Mod};

DataObject iedModel_PROT_PTOF2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_q,0};
DataAttribute iedModel_PROT_PTOF2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Str, (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF2,  	(ModelNode*)&iedModel_PROT_PTOF2_Op, (ModelNode*) &iedModel_PROT_PTOF2_Str_general,0};
DataAttribute iedModel_PROT_PTOF2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF2_Op_general,0};
DataAttribute iedModel_PROT_PTOF2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF2_Op,  (ModelNode*) &iedModel_PROT_PTOF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF2_Op,  (ModelNode*) &iedModel_PROT_PTOF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// PTOF3-------------------
LogicalNode iedModel_PROT_PTOF3 = {    LogicalNodeModelType,    "PTOF3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF3_Mod};

DataObject iedModel_PROT_PTOF3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_q,0};
DataAttribute iedModel_PROT_PTOF3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Str, (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF3,  	(ModelNode*)&iedModel_PROT_PTOF3_Op, (ModelNode*) &iedModel_PROT_PTOF3_Str_general,0};
DataAttribute iedModel_PROT_PTOF3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF3_Op_general,0};
DataAttribute iedModel_PROT_PTOF3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF3_Op,  (ModelNode*) &iedModel_PROT_PTOF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF3_Op,  (ModelNode*) &iedModel_PROT_PTOF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// PTOF4-------------------
LogicalNode iedModel_PROT_PTOF4 = {    LogicalNodeModelType,    "PTOF4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTOF4_Mod};

DataObject iedModel_PROT_PTOF4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_q,0};
DataAttribute iedModel_PROT_PTOF4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Str, (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF4,  	(ModelNode*)&iedModel_PROT_PTOF4_Op, (ModelNode*) &iedModel_PROT_PTOF4_Str_general,0};
DataAttribute iedModel_PROT_PTOF4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF4_Op_general,0};
DataAttribute iedModel_PROT_PTOF4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF4_Op,  (ModelNode*) &iedModel_PROT_PTOF4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF4_Op,  (ModelNode*) &iedModel_PROT_PTOF4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// -------------------
LogicalNode iedModel_PROT_PTUF1 = {    LogicalNodeModelType,    "PTUF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF1_Mod};

DataObject iedModel_PROT_PTUF1_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_q,0};
DataAttribute iedModel_PROT_PTUF1_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Str, (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF1_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF1,  	(ModelNode*)&iedModel_PROT_PTUF1_Op, (ModelNode*) &iedModel_PROT_PTUF1_Str_general,0};
DataAttribute iedModel_PROT_PTUF1_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF1_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF1_Op_general,0};
DataAttribute iedModel_PROT_PTUF1_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF1_Op,  (ModelNode*) &iedModel_PROT_PTUF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF1_Op,  (ModelNode*) &iedModel_PROT_PTUF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// PTUF2 -------------------
LogicalNode iedModel_PROT_PTUF2 = {    LogicalNodeModelType,    "PTUF2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF2_Mod};

DataObject iedModel_PROT_PTUF2_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_q,0};
DataAttribute iedModel_PROT_PTUF2_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Str, (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF2_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF2,  	(ModelNode*)&iedModel_PROT_PTUF2_Op, (ModelNode*) &iedModel_PROT_PTUF2_Str_general,0};
DataAttribute iedModel_PROT_PTUF2_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF2_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF2_Op_general,0};
DataAttribute iedModel_PROT_PTUF2_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF2_Op,  (ModelNode*) &iedModel_PROT_PTUF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF2_Op,  (ModelNode*) &iedModel_PROT_PTUF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// PTUF3 -------------------
LogicalNode iedModel_PROT_PTUF3 = {    LogicalNodeModelType,    "PTUF3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF3_Mod};

DataObject iedModel_PROT_PTUF3_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_q,0};
DataAttribute iedModel_PROT_PTUF3_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Str, (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF3_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF3,  	(ModelNode*)&iedModel_PROT_PTUF3_Op, (ModelNode*) &iedModel_PROT_PTUF3_Str_general,0};
DataAttribute iedModel_PROT_PTUF3_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF3_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF3_Op_general,0};
DataAttribute iedModel_PROT_PTUF3_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF3_Op,  (ModelNode*) &iedModel_PROT_PTUF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF3_Op,  (ModelNode*) &iedModel_PROT_PTUF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};


// PTUF4 -------------------
LogicalNode iedModel_PROT_PTUF4 = {    LogicalNodeModelType,    "PTUF4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_PTUF4_Mod};

DataObject iedModel_PROT_PTUF4_Mod = {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_q,0};
DataAttribute iedModel_PROT_PTUF4_Mod_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Mod_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Mod_stVal = { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Str, (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF4_Str 	 = {    DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF4,  	(ModelNode*)&iedModel_PROT_PTUF4_Op, (ModelNode*) &iedModel_PROT_PTUF4_Str_general,0};
DataAttribute iedModel_PROT_PTUF4_Str_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_dirGeneral = {    DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF4_Op 	 = {    DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF4_Op_general,0};
DataAttribute iedModel_PROT_PTUF4_Op_general = {    DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF4_Op,  (ModelNode*) &iedModel_PROT_PTUF4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Op_q = {    DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF4_Op,  (ModelNode*) &iedModel_PROT_PTUF4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Op_t = {    DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO1 			= { LogicalNodeModelType,   "VZGGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod};

DataObject iedModel_PROT_VZGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*)&iedModel_PROT_VZGGIO1_Alm , (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO1,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO2 			= { LogicalNodeModelType,   "VZGGIO2",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod};

DataObject iedModel_PROT_VZGGIO2_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*)&iedModel_PROT_VZGGIO2_Alm , (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO2,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO3 			= { LogicalNodeModelType,   "VZGGIO3",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod};

DataObject iedModel_PROT_VZGGIO3_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*)&iedModel_PROT_VZGGIO3_Alm , (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO3,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO4 			= { LogicalNodeModelType,   "VZGGIO4",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod};

DataObject iedModel_PROT_VZGGIO4_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*)&iedModel_PROT_VZGGIO4_Alm , (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO4,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO5 			= { LogicalNodeModelType,   "VZGGIO5",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod};

DataObject iedModel_PROT_VZGGIO5_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*)&iedModel_PROT_VZGGIO5_Alm , (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO5,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO6 			= { LogicalNodeModelType,   "VZGGIO6",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod};

DataObject iedModel_PROT_VZGGIO6_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*)&iedModel_PROT_VZGGIO6_Alm , (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO6,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO7 			= { LogicalNodeModelType,   "VZGGIO7",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*)&iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod};

DataObject iedModel_PROT_VZGGIO7_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*)&iedModel_PROT_VZGGIO7_Alm , (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO7,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};


//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO8 			= { LogicalNodeModelType,   "VZGGIO8",    (ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod};

DataObject iedModel_PROT_VZGGIO8_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Beh = {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Health = {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal = {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_q = {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_t = {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_NamPlt = {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*)&iedModel_PROT_VZGGIO8_Alm , (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor = {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev = {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d = {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO8,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,NULL,0};

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

//-PTRC --------------------------------------------------------------------------
LogicalNode iedModel_CTRL_PTRC 					= {    LogicalNodeModelType,    "PTRC1",    (ModelNode*)&iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_PTRC_Mod};

DataObject iedModel_CTRL_PTRC_Mod 				= {    DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_q,0};
DataAttribute iedModel_CTRL_PTRC_Mod_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Beh 				= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_Health_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Health_stVal 	= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_q 		= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_t 		= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Op, (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev 	= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_d 		= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_CTRL_PTRC,  	NULL, (ModelNode*) &iedModel_CTRL_PTRC_Op_general,0};
DataAttribute iedModel_CTRL_PTRC_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_CTRL_PTRC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1 					= {    LogicalNodeModelType,    "GGIO1",    (ModelNode*) &iedModel_Generic_CTRL,  NULL ,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod};

DataObject iedModel_CTRL_GGIO1_Mod 					= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod_q,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_Beh 					= {    DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_Health 				= {    DataObjectModelType,    "Health",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Health_stVal 		= {    DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_q 			= {    DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_t 			= {    DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_NamPlt 				= {    DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*)&iedModel_CTRL_GGIO1_SPCSO1 , (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_vendor,0};

DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor 	= {    DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev 		= {    DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_d 			= {    DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_CTRL_GGIO1_SPCSO1 						= {    DataObjectModelType,     "SPCSO1",     		(ModelNode*) &iedModel_CTRL_GGIO1,     		(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO2 						= {    DataObjectModelType,     "SPCSO2",     		(ModelNode*) &iedModel_CTRL_GGIO1,     			(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q 				= {    DataAttributeModelType,  "q",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t 				= {    DataAttributeModelType,  "t",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d 				= {    DataAttributeModelType,  "d",       		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal 			= { DataAttributeModelType,		"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel 			= {   DataAttributeModelType,   "ctlModel",		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper 				= {    DataAttributeModelType,  "Oper",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal 			= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin 			= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent 	= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum 			= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T 				= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check 			= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO3 						= {    DataObjectModelType,     "SPCSO3",   (ModelNode*) &iedModel_CTRL_GGIO1,     	(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO4,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q 					= {    DataAttributeModelType,  "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t 					= {    DataAttributeModelType,  "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d 					= {    DataAttributeModelType,  "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,	 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal 				= { DataAttributeModelType,		"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel 			= {   DataAttributeModelType,   "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper 				= {    DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,NULL,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal 		= {    DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin 		= {    DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat 	= {    DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent= {    DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum 		= {    DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T 			= {    DataAttributeModelType,  "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test 			= {    DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check 		= {    DataAttributeModelType,  "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO4 						= { DataObjectModelType,     "SPCSO4",   	(ModelNode*) &iedModel_CTRL_GGIO1,     	NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q 					= { DataAttributeModelType,  "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t 					= { DataAttributeModelType,  "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d 					= { DataAttributeModelType,  "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,	 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal 				= { DataAttributeModelType,		"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel 			= { DataAttributeModelType,   "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper 				= { DataAttributeModelType,  "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,NULL,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal 		= { DataAttributeModelType,  "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin 		= { DataAttributeModelType,  "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat 	= { DataAttributeModelType,  "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent= { DataAttributeModelType,  "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum 		= { DataAttributeModelType,  "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T 			= { DataAttributeModelType,  "T",    		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test 			= { DataAttributeModelType,  "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check 		= { DataAttributeModelType,  "Check",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


/***********************************************************************
 * DataSet
 ***********************************************************************/
/*
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda0 = {"GGIO",false,"IN8GGIO1$ST$Ind1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda1 = {"GGIO",false,"IN8GGIO1$ST$Ind2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda2 = {"GGIO",false,"IN8GGIO1$ST$Ind3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda3 = {"GGIO",false,"IN8GGIO1$ST$Ind4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda4 = {"GGIO",false,"IN8GGIO1$ST$Ind5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda5 = {"GGIO",false,"IN8GGIO1$ST$Ind6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda6 = {"GGIO",false,"IN8GGIO1$ST$Ind7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset0_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda7 = {"GGIO",false,"IN8GGIO1$ST$Ind8", -1, NULL, NULL, NULL };
#define 	_numDS0			8
#define 	linkDS0 		&iedModelds_LD0_LLN0_dataset0_fcda0


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
DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda0 = {"CTRL",false," ", -1, NULL, NULL, NULL };
#define 	_numDS2			0
#define 	linkDS2			NULL

//LLN0.DS3
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda0 = {"CTRL",false,"GGIO1$ST$SPCSO1$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda1 = {"CTRL",false,"GGIO1$ST$SPCSO2$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda2 = {"CTRL",false,"GGIO1$ST$SPCSO3$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda3 = {"CTRL",false,"GGIO1$ST$SPCSO4$stVal", -1, NULL, NULL, NULL };
#define 	_numDS3			4
#define 	linkDS3			&iedModelds_LD0_LLN0_dataset3_fcda0

//LLN0.DS4
DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda0 = {"PROT",false," ", 	-1, NULL, NULL, NULL };
#define 	_numDS4			0
#define 	linkDS4			NULL

//LLN0.DS5
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda0 = {"PROT",false,"UPTOV1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda1 = {"PROT",false,"UPTOV2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda2 = {"PROT",false,"UPTOV3$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda3 = {"PROT",false,"UPTOV4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda4 = {"PROT",false,"UPTOV1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda5 = {"PROT",false,"UPTOV2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda6  ={"PROT",false,"UPTOV3$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda7  ={"PROT",false,"UPTOV4$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda8 };

DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda8   ={"PROT",false,"UPTUV1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda9   ={"PROT",false,"UPTUV2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda10  ={"PROT",false,"UPTUV3$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda11  ={"PROT",false,"UPTUV4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda12  ={"PROT",false,"UPTUV1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda13  ={"PROT",false,"UPTUV2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda14  ={"PROT",false,"UPTUV3$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda15  ={"PROT",false,"UPTUV4$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda16 };

DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda16  ={"PROT",false,"U2PTOV1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda17 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda17  ={"PROT",false,"U2PTOV2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda18 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda18  ={"PROT",false,"U2PTOV1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda19 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda19  ={"PROT",false,"U2PTOV2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda20 };

DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda20  ={"PROT",false,"U1PTUV1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda21 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda21  ={"PROT",false,"U1PTUV2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda22 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda22  ={"PROT",false,"U1PTUV1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda23 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda23  ={"PROT",false,"U1PTUV2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda24 };

DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda24  ={"PROT",false,"U0PTOV1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda25 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda25  ={"PROT",false,"U0PTOV2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda26 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda26  ={"PROT",false,"U0PTOV3$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda27 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda27  ={"PROT",false,"U0PTOV4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda28 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda28  ={"PROT",false,"U0PTOV1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda29 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda29  ={"PROT",false,"U0PTOV2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda30 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda30  ={"PROT",false,"U0PTOV3$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset5_fcda31 };
DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda31  ={"PROT",false,"U0PTOV4$ST$Op", 	-1, NULL, NULL, NULL };
#define 	_numDS5			32
#define 	linkDS5			&iedModelds_LD0_LLN0_dataset5_fcda0

//LLN0.DS6
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda0 = {"PROT",false,"PTOF1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda1 = {"PROT",false,"PTOF2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda2 = {"PROT",false,"PTOF3$ST$Str",		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda3 = {"PROT",false,"PTOF4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda4 = {"PROT",false,"PTOF1$ST$Op", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda5 = {"PROT",false,"PTOF2$ST$Op", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda6 = {"PROT",false,"PTOF3$ST$Op", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda7 = {"PROT",false,"PTOF4$ST$Op", 		-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda8 };

DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda8 = {"PROT",false,"PTUF1$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda9 = {"PROT",false,"PTUF2$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda10 = {"PROT",false,"PTUF3$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda11 = {"PROT",false,"PTUF4$ST$Str", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda12 = {"PROT",false,"PTUF1$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda13 = {"PROT",false,"PTUF2$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda14 = {"PROT",false,"PTUF3$ST$Op", 	-1, NULL, NULL, &iedModelds_LD0_LLN0_dataset6_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda15 = {"PROT",false,"PTUF4$ST$Op", 	-1, NULL, NULL, NULL };
#define 	_numDS6			16
#define 	linkDS6			&iedModelds_LD0_LLN0_dataset6_fcda0

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
#define 	_numDS9		 	0
#define 	linkDS9			NULL

//LLN0.DS10
#define 	_numDS10		0
#define 	linkDS10		NULL
//LLN0.DS11
#define 	_numDS11		0
#define 	linkDS11		NULL

//LLN0.DS12
#define 	_numDS12		0
#define 	linkDS12		NULL

//LLN0.DS13
#define 	_numDS13		0
#define 	linkDS13		NULL
//LLN0.DS14
#define 	_numDS14		0
#define 	linkDS14		NULL

//LLN0.DS15
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda0 = {"MES",false, "MMXU1$MX$PhV$phsA",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda1};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda1 = {"MES",false, "MMXU1$MX$PhV$phsB",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda2};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda2 = {"MES",false, "MMXU1$MX$PhV$phsC",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda3};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda3 = {"MES",false, "MMXU1$MX$PhV$neut",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda5};

DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda5 = {"MES",false, "MMXU1$MX$PPV$phsAB",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda6};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda6 = {"MES",false, "MMXU1$MX$PPV$phsBC",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda7};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda7 = {"MES",false, "MMXU1$MX$PPV$phsCA",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda8};
#ifdef _SPCECIALSWRevision
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda8 = {"MES",false, "MSQI1$MX$SeqU$c1",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda9};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda9 = {"MES",false, "MSQI1$MX$SeqU$c2",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda10};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda10= {"MES",false, "MSQI1$MX$SeqU$c3",	-1,NULL,NULL,	NULL};
#else
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda8 = {"MES",false, "MSQI1$MX$SeqV$c1",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda9};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda9 = {"MES",false, "MSQI1$MX$SeqV$c2",	-1,NULL,NULL,	&iedModelds_LD0_LLN0_dataset15_fcda10};
DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda10= {"MES",false, "MSQI1$MX$SeqV$c3",	-1,NULL,NULL,	NULL};
#endif

#define 	_numDS15		10
#define 	linkDS15		&iedModelds_LD0_LLN0_dataset15_fcda0

//LLN0.DS16
DataSetEntry iedModelds_LD0_LLN0_dataset16_fcda0 = {"MES",false,"MMXU1$MX$Hz", 		-1, NULL, NULL, NULL };
#define 	_numDS16		1
#define 	linkDS16		&iedModelds_LD0_LLN0_dataset16_fcda0

#define 	_numDS17		0
#define 	_numDS18		0
#define 	_numDS19		0
#define 	linkDS17		NULL
#define 	linkDS18		NULL
#define 	linkDS19		NULL

//LLN0.DS20
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda0  = {"GGIO",false,"IN8GGIO1$ST$Ind1$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda1  = {"GGIO",false,"IN8GGIO1$ST$Ind1$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda2  = {"GGIO",false,"IN8GGIO1$ST$Ind2$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda3  = {"GGIO",false,"IN8GGIO1$ST$Ind2$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda4  = {"GGIO",false,"IN8GGIO1$ST$Ind3$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda5  = {"GGIO",false,"IN8GGIO1$ST$Ind3$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda6  = {"GGIO",false,"IN8GGIO1$ST$Ind4$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda7  = {"GGIO",false,"IN8GGIO1$ST$Ind4$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda8  = {"GGIO",false,"IN8GGIO1$ST$Ind5$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda9  = {"GGIO",false,"IN8GGIO1$ST$Ind5$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda10 = {"GGIO",false,"IN8GGIO1$ST$Ind6$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda11 = {"GGIO",false,"IN8GGIO1$ST$Ind6$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda12 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda12 = {"GGIO",false,"IN8GGIO1$ST$Ind7$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda13 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda13 = {"GGIO",false,"IN8GGIO1$ST$Ind7$q"		, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda14 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda14 = {"GGIO",false,"IN8GGIO1$ST$Ind8$stVal"	, -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset20_fcda15 };
DataSetEntry iedModelds_LD0_LLN0_dataset20_fcda15 = {"GGIO",false,"IN8GGIO1$ST$Ind8$q"		, -1, NULL, NULL, NULL };
#define 	_numDS20		16
#define 	linkDS20		&iedModelds_LD0_LLN0_dataset20_fcda0


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
*/

static PhyComAddress iedModel_LD0_LLN0_gse0_address = {  4,  1,  999,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1} };//4096
static PhyComAddress iedModel_LD0_LLN0_gse1_address = {  4,  1,  999,  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x2} };


GSEControlBlock iedModel_LD0_LLN0_gse0 = {
		&iedModel_LD0_LLN0,
		"gcbIn",
		"Ind",
		"DS20",				// dataSetName
		300,				// confRev
		false,
		&iedModel_LD0_LLN0_gse0_address,
		10,					// minTime
		3000,				// maxTime
		NULL
};

GSEControlBlock iedModel_LD0_LLN0_gse1 = {
		&iedModel_LD0_LLN0,
		"gcbIn",
		"Ind",
		"DS20",				// dataSetName
		300,				// confRev
		false,
		&iedModel_LD0_LLN0_gse1_address,
		10,					// minTime
		3000,				// maxTime
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

// UPTOV
iedModel_PROT_UPTOV1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTOV4_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_UPTOV1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_UPTOV1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_UPTOV1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV4_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);


// UPTUV1
iedModel_PROT_UPTUV1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_UPTUV4_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_UPTUV1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_UPTUV1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_UPTUV1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV4_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

// U2PTOV
iedModel_PROT_U2PTOV1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U2PTOV1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U2PTOV1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U2PTOV2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U2PTOV2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U2PTOV2_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_U2PTOV1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U2PTOV1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_U2PTOV2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U2PTOV2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_U2PTOV1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U2PTOV1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U2PTOV2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U2PTOV2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_U2PTOV1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_U2PTOV2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

// U0PTOV
iedModel_PROT_U0PTOV1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U0PTOV4_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_U0PTOV1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U0PTOV1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_U0PTOV2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U0PTOV2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_U0PTOV3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U0PTOV3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_U0PTOV4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U0PTOV4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_U0PTOV1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U0PTOV4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_U0PTOV1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_U0PTOV2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_U0PTOV3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_U0PTOV4_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

// U1PTUV
iedModel_PROT_U1PTUV1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U1PTUV1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U1PTUV1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U1PTUV2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U1PTUV2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_U1PTUV2_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_U1PTUV1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U1PTUV1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_U1PTUV2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_U1PTUV2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_U1PTUV1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U1PTUV1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U1PTUV2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_U1PTUV2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_U1PTUV1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_U1PTUV2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);


// PTOF1
iedModel_PROT_PTOF1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTOF4_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_PTOF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_PTOF1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PTOF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF4_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

// PTUF1
iedModel_PROT_PTUF1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF2_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF3_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF3_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF3_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF4_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF4_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PTUF4_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_PROT_PTUF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF4_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF4_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_PTUF1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF4_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF4_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PTUF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF4_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);


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
iedModel_GGIO_OUTGGIO1_SPCSO9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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

/*
iedModel_GGIO_LEDGGIO1_Ind1_dU.mmsValue = MmsValue_newMmsString("LED1");
iedModel_GGIO_LEDGGIO1_Ind2_dU.mmsValue = MmsValue_newMmsString("LED2");
iedModel_GGIO_LEDGGIO1_Ind3_dU.mmsValue = MmsValue_newMmsString("LED3");
iedModel_GGIO_LEDGGIO1_Ind4_dU.mmsValue = MmsValue_newMmsString("LED4");
iedModel_GGIO_LEDGGIO1_Ind5_dU.mmsValue = MmsValue_newMmsString("LED5");
iedModel_GGIO_LEDGGIO1_Ind6_dU.mmsValue = MmsValue_newMmsString("LED6");
iedModel_GGIO_LEDGGIO1_Ind7_dU.mmsValue = MmsValue_newMmsString("LED7");
iedModel_GGIO_LEDGGIO1_Ind8_dU.mmsValue = MmsValue_newMmsString("LED8");
*/
iedModel_GGIO_LEDGGIO1_Ind9_dU.mmsValue = MmsValue_newMmsString("LED CB is closed");
iedModel_GGIO_LEDGGIO1_Ind10_dU.mmsValue = MmsValue_newMmsString("LED CB is opened");
iedModel_GGIO_LEDGGIO1_Ind11_dU.mmsValue = MmsValue_newMmsString("LED System Log");
iedModel_GGIO_LEDGGIO1_Ind12_dU.mmsValue = MmsValue_newMmsString("LED Alarm Log");


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

//MMXU1 phV
iedModel_MES_MMXU1_phV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_phV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_phV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_phV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_phV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_phV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_phV_neut_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_phV_neut_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// phV db,zeroDb
iedModel_MES_MMXU1_phV_phsA_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_phV_phsA_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_phV_phsB_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_phV_phsB_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_phV_phsC_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_phV_phsC_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

iedModel_MES_MMXU1_phV_neut_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_phV_neut_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

//MMXU1 PPV
iedModel_MES_MMXU1_PPV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_PPV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_PPV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_PPV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_PPV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MMXU1_PPV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// PPV db,zeroDb
iedModel_MES_MMXU1_PPV_phsA_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_PPV_phsA_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_PPV_phsB_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_PPV_phsB_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MMXU1_PPV_phsC_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MMXU1_PPV_phsC_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

//MMXU1 Hz
iedModel_MES_MMXU1_Hz_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MMXU1_Hz_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// Hz db,zeroDb
iedModel_MES_MMXU1_Hz_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db_Hz);
iedModel_MES_MMXU1_Hz_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb_Hz);

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

iedModel_MES_MSQI1_SeqU_c1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqU_c1_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MSQI1_SeqU_c2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqU_c2_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_MSQI1_SeqU_c3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_MSQI1_SeqU_c3_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// SeqU db,zeroDb
iedModel_MES_MSQI1_SeqU_c1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqU_c1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MSQI1_SeqU_c2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqU_c2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_MSQI1_SeqU_c3_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_MSQI1_SeqU_c3_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

USART_TRACE("------------------------------------------------------------\n");
}

#endif
