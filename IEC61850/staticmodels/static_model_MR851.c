/*
 * static_model_MRxxx.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */

#if defined (MR851)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR851.h"
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
extern DataSet iedModelds_LD0_LLN0_dataset11;
extern DataSet iedModelds_LD0_LLN0_dataset12;
extern DataSet iedModelds_LD0_LLN0_dataset13;
extern DataSet iedModelds_LD0_LLN0_dataset14;
extern DataSet iedModelds_LD0_LLN0_dataset15;
extern DataSet iedModelds_LD0_LLN0_dataset16;
extern DataSet iedModelds_LD0_LLN0_dataset17;
extern DataSet iedModelds_LD0_LLN0_dataset18;
extern DataSet iedModelds_LD0_LLN0_dataset19;

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

extern DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda3;

extern DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda0;

extern DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda0;


extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda11;

extern DataSetEntry iedModelds_LD0_LLN0_dataset13_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset14_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset16_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset17_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset18_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_dataset19_fcda0;
/***********************************************************************
 * логические устройства
 ***********************************************************************/

LogicalDevice iedModel_Generic_LD0;
LogicalDevice iedModel_Generic_RPN;
LogicalDevice iedModel_Generic_CTRL;
LogicalDevice iedModel_Generic_GGIO;


/***********************************************************************
 * логические узлы
 ***********************************************************************/
// ---------------------------------------------------------------------------------------------------------
// 0    000    00
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 000  000    00
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

// LPHD ----------------------------------------------------------------------------------------------------
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
// 000   000    00   00000
// 0  0  0  0  0  0    0
// 0  0  0  0  0  0    0
// 000   000   0  0    0
// 0     0 0   0  0    0
// 0     0  0   00     0
// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_RPN_LLN0;								// Логический нуль узла. Имя: LLN0
DataObject    iedModel_RPN_LLN0_Mod;							// Mod - Режим
DataAttribute iedModel_RPN_LLN0_Mod_q;
DataAttribute iedModel_RPN_LLN0_Mod_t;
DataAttribute iedModel_RPN_LLN0_Mod_stVal;
DataAttribute iedModel_RPN_LLN0_Mod_ctlModel;

DataObject    iedModel_RPN_LLN0_Beh;							// Beh - Режим работы
DataAttribute iedModel_RPN_LLN0_Beh_stVal;
DataAttribute iedModel_RPN_LLN0_Beh_q;
DataAttribute iedModel_RPN_LLN0_Beh_t;

DataObject    iedModel_RPN_LLN0_Health;						// Health - Состояние работоспособности
DataAttribute iedModel_RPN_LLN0_Health_stVal;
DataAttribute iedModel_RPN_LLN0_Health_q;
DataAttribute iedModel_RPN_LLN0_Health_t;

DataObject    iedModel_RPN_LLN0_NamPlt;						// NamPIt - Паспортная табличка
DataAttribute iedModel_RPN_LLN0_NamPlt_vendor;
DataAttribute iedModel_RPN_LLN0_NamPlt_swRev;
DataAttribute iedModel_RPN_LLN0_NamPlt_d;
DataAttribute iedModel_RPN_LLN0_NamPlt_configRev;
DataAttribute iedModel_RPN_LLN0_NamPlt_ldNs;

// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_RPN_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

DataObject    iedModel_RPN_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
DataAttribute iedModel_RPN_LPHD1_PhyNam_vendor;

DataObject    iedModel_RPN_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
DataAttribute iedModel_RPN_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_RPN_LPHD1_PhyHealth_q;
DataAttribute iedModel_RPN_LPHD1_PhyHealth_t;

DataObject    iedModel_RPN_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
DataAttribute iedModel_RPN_LPHD1_Proxy_stVal;
DataAttribute iedModel_RPN_LPHD1_Proxy_q;
DataAttribute iedModel_RPN_LPHD1_Proxy_t;


LogicalNode iedModel_RPN_ATCC1;
DataObject iedModel_RPN_ATCC1_Mod;
DataAttribute iedModel_RPN_ATCC1_Mod_q;
DataAttribute iedModel_RPN_ATCC1_Mod_t;
DataAttribute iedModel_RPN_ATCC1_Mod_stVal;

DataObject iedModel_RPN_ATCC1_Beh;
DataAttribute iedModel_RPN_ATCC1_Beh_stVal;
DataAttribute iedModel_RPN_ATCC1_Beh_q;
DataAttribute iedModel_RPN_ATCC1_Beh_t;

DataObject iedModel_RPN_ATCC1_Health;
DataAttribute iedModel_RPN_ATCC1_Health_stVal;
DataAttribute iedModel_RPN_ATCC1_Health_q;
DataAttribute iedModel_RPN_ATCC1_Health_t;

DataObject iedModel_RPN_ATCC1_NamPlt;
DataAttribute iedModel_RPN_ATCC1_NamPlt_vendor;
DataAttribute iedModel_RPN_ATCC1_NamPlt_swRev;
DataAttribute iedModel_RPN_ATCC1_NamPlt_d;


DataObject iedModel_RPN_ATCC1_Loc;
DataAttribute iedModel_RPN_ATCC1_Loc_stVal;
DataAttribute iedModel_RPN_ATCC1_Loc_q;
DataAttribute iedModel_RPN_ATCC1_Loc_t;

/*
//TapChg
DataObject iedModel_RPN_ATCC1_TapChg;
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlVal;
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlNum;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent;
DataAttribute iedModel_RPN_ATCC1_TapChg_q;
DataAttribute iedModel_RPN_ATCC1_TapChg_t;
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel;
*/
//TapChg
DataObject iedModel_RPN_ATCC1_TapChg;
DataAttribute iedModel_RPN_ATCC1_TapChg_q;
DataAttribute iedModel_RPN_ATCC1_TapChg_t;
DataAttribute iedModel_RPN_ATCC1_TapChg_d;
DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr;
DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr_posVal;
DataAttribute iedModel_RPN_ATCC1_TapChg_persistent;
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_T;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Test;
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Check;

//ParOp
DataObject iedModel_RPN_ATCC1_ParOp;
DataAttribute iedModel_RPN_ATCC1_ParOp_q;
DataAttribute iedModel_RPN_ATCC1_ParOp_t;
DataAttribute iedModel_RPN_ATCC1_ParOp_d;
DataAttribute iedModel_RPN_ATCC1_ParOp_stVal;
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlVal;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orCat;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orIdent;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlNum;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_T;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Test;
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Check;
/*
//ParOp
DataObject iedModel_RPN_ATCC1_ParOp;
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlVal;
DataAttribute iedModel_RPN_ATCC1_ParOp_stVal;
DataAttribute iedModel_RPN_ATCC1_ParOp_q;
DataAttribute iedModel_RPN_ATCC1_ParOp_t;
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel;
*/

//CtlV1
DataObject    iedModel_RPN_ATCC1_CtlV1;
DataAttribute iedModel_RPN_ATCC1_CtlV1_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV1_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV1_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV1_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV1_q;
DataAttribute iedModel_RPN_ATCC1_CtlV1_t;
DataAttribute iedModel_RPN_ATCC1_CtlV1_db;
DataAttribute iedModel_RPN_ATCC1_CtlV1_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV1_dU;

//CtlV2
DataObject    iedModel_RPN_ATCC1_CtlV2;
DataAttribute iedModel_RPN_ATCC1_CtlV2_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV2_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV2_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV2_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV2_q;
DataAttribute iedModel_RPN_ATCC1_CtlV2_t;
DataAttribute iedModel_RPN_ATCC1_CtlV2_db;
DataAttribute iedModel_RPN_ATCC1_CtlV2_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV2_dU;

//CtlV3
DataObject    iedModel_RPN_ATCC1_CtlV3;
DataAttribute iedModel_RPN_ATCC1_CtlV3_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV3_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV3_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV3_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV3_q;
DataAttribute iedModel_RPN_ATCC1_CtlV3_t;
DataAttribute iedModel_RPN_ATCC1_CtlV3_db;
DataAttribute iedModel_RPN_ATCC1_CtlV3_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV3_dU;

//CtlV4
DataObject    iedModel_RPN_ATCC1_CtlV4;
DataAttribute iedModel_RPN_ATCC1_CtlV4_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV4_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV4_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV4_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV4_q;
DataAttribute iedModel_RPN_ATCC1_CtlV4_t;
DataAttribute iedModel_RPN_ATCC1_CtlV4_db;
DataAttribute iedModel_RPN_ATCC1_CtlV4_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV4_dU;

//CtlV5
DataObject    iedModel_RPN_ATCC1_CtlV5;
DataAttribute iedModel_RPN_ATCC1_CtlV5_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV5_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV5_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV5_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV5_q;
DataAttribute iedModel_RPN_ATCC1_CtlV5_t;
DataAttribute iedModel_RPN_ATCC1_CtlV5_db;
DataAttribute iedModel_RPN_ATCC1_CtlV5_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV5_dU;

//CtlV6
DataObject    iedModel_RPN_ATCC1_CtlV6;
DataAttribute iedModel_RPN_ATCC1_CtlV6_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV6_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV6_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV6_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV6_q;
DataAttribute iedModel_RPN_ATCC1_CtlV6_t;
DataAttribute iedModel_RPN_ATCC1_CtlV6_db;
DataAttribute iedModel_RPN_ATCC1_CtlV6_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV6_dU;

//CtlV7
DataObject    iedModel_RPN_ATCC1_CtlV7;
DataAttribute iedModel_RPN_ATCC1_CtlV7_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV7_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV7_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV7_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV7_q;
DataAttribute iedModel_RPN_ATCC1_CtlV7_t;
DataAttribute iedModel_RPN_ATCC1_CtlV7_db;
DataAttribute iedModel_RPN_ATCC1_CtlV7_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV7_dU;

//CtlV8
DataObject    iedModel_RPN_ATCC1_CtlV8;
DataAttribute iedModel_RPN_ATCC1_CtlV8_mag;
DataAttribute iedModel_RPN_ATCC1_CtlV8_mag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV8_instMag;
DataAttribute iedModel_RPN_ATCC1_CtlV8_instMag_f;
DataAttribute iedModel_RPN_ATCC1_CtlV8_q;
DataAttribute iedModel_RPN_ATCC1_CtlV8_t;
DataAttribute iedModel_RPN_ATCC1_CtlV8_db;
DataAttribute iedModel_RPN_ATCC1_CtlV8_zeroDb;
DataAttribute iedModel_RPN_ATCC1_CtlV8_dU;


//LodA1
DataObject    iedModel_RPN_ATCC1_LodA1;
DataAttribute iedModel_RPN_ATCC1_LodA1_mag;
DataAttribute iedModel_RPN_ATCC1_LodA1_mag_f;
DataAttribute iedModel_RPN_ATCC1_LodA1_instMag;
DataAttribute iedModel_RPN_ATCC1_LodA1_instMag_f;
DataAttribute iedModel_RPN_ATCC1_LodA1_q;
DataAttribute iedModel_RPN_ATCC1_LodA1_t;
DataAttribute iedModel_RPN_ATCC1_LodA1_db;
DataAttribute iedModel_RPN_ATCC1_LodA1_zeroDb;
DataAttribute iedModel_RPN_ATCC1_LodA1_dU;

//LodA2
DataObject    iedModel_RPN_ATCC1_LodA2;
DataAttribute iedModel_RPN_ATCC1_LodA2_mag;
DataAttribute iedModel_RPN_ATCC1_LodA2_mag_f;
DataAttribute iedModel_RPN_ATCC1_LodA2_instMag;
DataAttribute iedModel_RPN_ATCC1_LodA2_instMag_f;
DataAttribute iedModel_RPN_ATCC1_LodA2_q;
DataAttribute iedModel_RPN_ATCC1_LodA2_t;
DataAttribute iedModel_RPN_ATCC1_LodA2_db;
DataAttribute iedModel_RPN_ATCC1_LodA2_zeroDb;
DataAttribute iedModel_RPN_ATCC1_LodA2_dU;

//LodA3
DataObject    iedModel_RPN_ATCC1_LodA3;
DataAttribute iedModel_RPN_ATCC1_LodA3_mag;
DataAttribute iedModel_RPN_ATCC1_LodA3_mag_f;
DataAttribute iedModel_RPN_ATCC1_LodA3_instMag;
DataAttribute iedModel_RPN_ATCC1_LodA3_instMag_f;
DataAttribute iedModel_RPN_ATCC1_LodA3_q;
DataAttribute iedModel_RPN_ATCC1_LodA3_t;
DataAttribute iedModel_RPN_ATCC1_LodA3_db;
DataAttribute iedModel_RPN_ATCC1_LodA3_zeroDb;
DataAttribute iedModel_RPN_ATCC1_LodA3_dU;

//LodA4
DataObject    iedModel_RPN_ATCC1_LodA4;
DataAttribute iedModel_RPN_ATCC1_LodA4_mag;
DataAttribute iedModel_RPN_ATCC1_LodA4_mag_f;
DataAttribute iedModel_RPN_ATCC1_LodA4_instMag;
DataAttribute iedModel_RPN_ATCC1_LodA4_instMag_f;
DataAttribute iedModel_RPN_ATCC1_LodA4_q;
DataAttribute iedModel_RPN_ATCC1_LodA4_t;
DataAttribute iedModel_RPN_ATCC1_LodA4_db;
DataAttribute iedModel_RPN_ATCC1_LodA4_zeroDb;
DataAttribute iedModel_RPN_ATCC1_LodA4_dU;

// ---------------------------------------------------------------------------------------------------------
//  00  00000  000    0
// 0      0    0  0   0
// 0      0    0  0   0
// 0      0    000    0
// 0      0    0 0    0
//  00    0    0  0   0000
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

// ---------------------------------------------------------------------------------------------------------
//   000   000  000   00
//  0     0      0   0  0
//  0     0      0   0  0
//  0     0      0   0  0
//  0  0  0  0   0   0  0
//   000   000  000   00
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

// ---------------------------------------------------------------------------------------------------------
// LPHD1
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
// OUT
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
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_dU;
//SPCSO2
DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_dU;
//SPCSO3
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_dU;
//SPCSO4
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_dU;
//SPCSO5
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_dU;
//SPCSO6
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_dU;
//SPCSO7
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_dU;
//SPCSO8
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_dU;
//SPCSO9
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO9;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_dU;
//SPCSO10
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO10;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_dU;
//SPCSO11
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO11;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_dU;
//SPCSO12
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO12;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_dU;
//SPCSO13
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO13;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_dU;
//SPCSO14
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO14;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_dU;
//SPCSO15
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO15;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_dU;

// ---------------------------------------------------------------------------------------------------------
// LED
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
// ------------------------------------------------------------
// IN
// ------------------------------------------------------------
LogicalNode iedModel_GGIO_INGGIO1;

DataObject iedModel_GGIO_INGGIO1_Mod;
DataAttribute iedModel_GGIO_INGGIO1_Mod_q;
DataAttribute iedModel_GGIO_INGGIO1_Mod_t;
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel;
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
DataAttribute iedModel_GGIO_INGGIO1_Ind1_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind2;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind2_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind3;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind3_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind4;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind4_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind5;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind5_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind6;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind6_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind7;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind7_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind8;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind8_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind9;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind9_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind10;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind10_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind11;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind11_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind12;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind12_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind13;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind13_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind14;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind14_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind15;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind15_dU;

DataObject    iedModel_GGIO_INGGIO1_Ind16;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t;
DataAttribute iedModel_GGIO_INGGIO1_Ind16_dU;

/*************************************************************************
 *
 *************************************************************************/

IedModel iedModel = {
	_swREV,//"MR771",
    &iedModel_Generic_LD0,
    &iedModelds_LD0_LLN0_dataset0,			// DataSet
    &iedModel_LD0_LLN0_report0,				// ReportControlBlock
    NULL,//&iedModel_RPN_LLN0_gse0,			// GSEControlBlock
    NULL,									// SVControlBlock
    NULL,//&iedModel_LD0_LLN0_sgcb0,				// SettingGroupControlBlock
    NULL,									// lcbs
    NULL,									// log
    initializeValues
};

/*************************************************************************
 * Логические устройства LD
 *************************************************************************/

LogicalDevice iedModel_Generic_LD0 		= { LogicalDeviceModelType, "LD0",	(ModelNode*)&iedModel,	(ModelNode*)&iedModel_Generic_RPN,  (ModelNode*)&iedModel_LD0_LLN0	};
LogicalDevice iedModel_Generic_RPN 		= { LogicalDeviceModelType, "RPN",	(ModelNode*)&iedModel,  (ModelNode*)&iedModel_Generic_CTRL, (ModelNode*)&iedModel_RPN_LLN0	};
LogicalDevice iedModel_Generic_CTRL 	= {	LogicalDeviceModelType, "CTRL",	(ModelNode*)&iedModel, 	(ModelNode*)&iedModel_Generic_GGIO, (ModelNode*)&iedModel_CTRL_LLN0	};
LogicalDevice iedModel_Generic_GGIO 	= { LogicalDeviceModelType, "GGIO",	(ModelNode*)&iedModel,	NULL,								(ModelNode*)&iedModel_GGIO_LLN0	};

/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/

LogicalNode iedModel_LD0_LLN0 					= { LogicalNodeModelType, 	"LLN0",	    (ModelNode*)&iedModel_Generic_LD0,	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod 				= { DataObjectModelType,	"Mod",	    (ModelNode*) &iedModel_LD0_LLN0,	    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LLN0_Mod,	(ModelNode*) &iedModel_LD0_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t 			= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_LD0_LLN0_Mod,	(ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Mod,	(ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel 	= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_LD0_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Beh 				= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    	(ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_LD0_LLN0,    	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,	(ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LLN0_Health, (ModelNode*) &iedModel_LD0_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LLN0_Health, (ModelNode*) &iedModel_LD0_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_LLN0_Health, NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_LD0_LLN0,    	NULL,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,	(ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,	(ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_LD0_LLN0_NamPlt,	(ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev= { DataAttributeModelType,	"configRev",(ModelNode*) &iedModel_LD0_LLN0_NamPlt,	(ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,	"ldNs",    	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};


//----------------------------------------------------------------------------
// LD0_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_LD0_LPHD1 					= { LogicalNodeModelType,	"LPHD1",    (ModelNode*)&iedModel_Generic_LD0,  		NULL,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam 			= { DataObjectModelType,	"PhyNam",	(ModelNode*) &iedModel_LD0_LPHD1,    		(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_LD0_LPHD1_PhyNam,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth 		= { DataObjectModelType,	"PhyHealth",(ModelNode*) &iedModel_LD0_LPHD1,    		(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy 			= { DataObjectModelType,	"Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    		NULL,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_LD0_LPHD1_Proxy, 	(ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    	(ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_RPN_LLN0 					= { LogicalNodeModelType,	"LLN0",	    (ModelNode*)&iedModel_Generic_RPN,	    (ModelNode*) &iedModel_RPN_LPHD1,    (ModelNode*) &iedModel_RPN_LLN0_Mod};

DataObject iedModel_RPN_LLN0_Mod 				= { DataObjectModelType,	"Mod",	    (ModelNode*) &iedModel_RPN_LLN0,	    (ModelNode*) &iedModel_RPN_LLN0_Beh,    (ModelNode*) &iedModel_RPN_LLN0_Mod_q,    0};
DataAttribute iedModel_RPN_LLN0_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_RPN_LLN0_Mod,	(ModelNode*) &iedModel_RPN_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_RPN_LLN0_Mod,	(ModelNode*) &iedModel_RPN_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_RPN_LLN0_Mod,	(ModelNode*) &iedModel_RPN_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_RPN_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_RPN_LLN0_Beh 				= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_RPN_LLN0,    	(ModelNode*) &iedModel_RPN_LLN0_Health,    (ModelNode*) &iedModel_RPN_LLN0_Beh_stVal,    0};
DataAttribute iedModel_RPN_LLN0_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_RPN_LLN0_Beh,    (ModelNode*) &iedModel_RPN_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_RPN_LLN0_Beh,    (ModelNode*) &iedModel_RPN_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_RPN_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_RPN_LLN0_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_RPN_LLN0,    	(ModelNode*) &iedModel_RPN_LLN0_NamPlt,	(ModelNode*) &iedModel_RPN_LLN0_Health_stVal,    0};
DataAttribute iedModel_RPN_LLN0_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_RPN_LLN0_Health,	(ModelNode*) &iedModel_RPN_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_RPN_LLN0_Health,	(ModelNode*) &iedModel_RPN_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_Health_t		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_RPN_LLN0_Health,	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_RPN_LLN0_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_RPN_LLN0,    	NULL,    (ModelNode*) &iedModel_RPN_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_RPN_LLN0_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_RPN_LLN0_NamPlt,	(ModelNode*) &iedModel_RPN_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_RPN_LLN0_NamPlt,	(ModelNode*) &iedModel_RPN_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_RPN_LLN0_NamPlt,	(ModelNode*) &iedModel_RPN_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_NamPlt_configRev= { DataAttributeModelType,	"configRev",(ModelNode*) &iedModel_RPN_LLN0_NamPlt,	(ModelNode*) &iedModel_RPN_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,	"ldNs",    	(ModelNode*) &iedModel_RPN_LLN0_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//----------------------------------------------------------------------------
// RPN_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_RPN_LPHD1 					= { LogicalNodeModelType,	"LPHD1",    (ModelNode*)&iedModel_Generic_RPN,    	(ModelNode*) &iedModel_RPN_ATCC1,    (ModelNode*) &iedModel_RPN_LPHD1_PhyNam};

DataObject iedModel_RPN_LPHD1_PhyNam 			= { DataObjectModelType,	"PhyNam",	(ModelNode*) &iedModel_RPN_LPHD1,    	(ModelNode*) &iedModel_RPN_LPHD1_PhyHealth,    (ModelNode*) &iedModel_RPN_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_RPN_LPHD1_PhyNam_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_RPN_LPHD1_PhyNam,NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_RPN_LPHD1_PhyHealth 		= { DataObjectModelType,	"PhyHealth",(ModelNode*) &iedModel_RPN_LPHD1,    		(ModelNode*) &iedModel_RPN_LPHD1_Proxy,    (ModelNode*) &iedModel_RPN_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_RPN_LPHD1_PhyHealth_stVal= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_RPN_LPHD1_PhyHealth,	(ModelNode*) &iedModel_RPN_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_RPN_LPHD1_PhyHealth_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_RPN_LPHD1_PhyHealth,	(ModelNode*) &iedModel_RPN_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LPHD1_PhyHealth_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_RPN_LPHD1_PhyHealth,	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_RPN_LPHD1_Proxy 			= { DataObjectModelType,	"Proxy",    (ModelNode*) &iedModel_RPN_LPHD1,    	NULL,    (ModelNode*) &iedModel_RPN_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_RPN_LPHD1_Proxy_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_RPN_LPHD1_Proxy, (ModelNode*) &iedModel_RPN_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_RPN_LPHD1_Proxy_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_RPN_LPHD1_Proxy,	(ModelNode*) &iedModel_RPN_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_RPN_LPHD1_Proxy_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_RPN_LPHD1_Proxy,	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 					= { LogicalNodeModelType,	"LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,		(ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod 				= { DataObjectModelType,	"Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_LLN0_Mod,	(ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_LLN0_Mod,	(ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,	(ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel", (ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh 				= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    	(ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_CTRL_LLN0,    		(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	(ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_CTRL_LLN0,    		NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev= { DataAttributeModelType,"configRev",(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,	"ldNs",    	(ModelNode*) &iedModel_CTRL_LLN0_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//----------------------------------------------------------------------------
// CTRL_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_CTRL_LPHD1 				= { LogicalNodeModelType,	"LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    		(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam 			= { DataObjectModelType,	"PhyNam",	(ModelNode*) &iedModel_CTRL_LPHD1,    		(ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor = { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth 		= { DataObjectModelType,	"PhyHealth",(ModelNode*) &iedModel_CTRL_LPHD1,    		(ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal={ DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,(ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,(ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth, NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy 			= { DataObjectModelType,	"Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    		NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_CTRL_LPHD1_Proxy, 	(ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

/************************************************************************
 * GGIO_LLN0
 *************************************************************************/
LogicalNode iedModel_GGIO_LLN0 					= { LogicalNodeModelType,	"LLN0",	    (ModelNode*)&iedModel_Generic_GGIO,	 (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LLN0_Mod,};

DataObject iedModel_GGIO_LLN0_Mod 				= { DataObjectModelType,	"Mod",	    (ModelNode*) &iedModel_GGIO_LLN0,	    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_q,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LLN0_Mod,	(ModelNode*) &iedModel_GGIO_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_CF,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LLN0_Mod,	(ModelNode*) &iedModel_GGIO_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_CF,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,	(ModelNode*) &iedModel_GGIO_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel", (ModelNode*) &iedModel_GGIO_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Beh 				= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	(ModelNode*) &iedModel_GGIO_LLN0_Health_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_GGIO_LLN0,    NULL,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev = { DataAttributeModelType,	"configRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	(ModelNode*) &iedModel_GGIO_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,	"ldNs",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//----------------------------------------------------------------------------
// GGIO_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_GGIO_LPHD1 = 					{ LogicalNodeModelType,		"LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

DataObject iedModel_GGIO_LPHD1_PhyNam = 			{ DataObjectModelType,		"PhyNam",	(ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor = 	{ DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_PhyHealth = 			{ DataObjectModelType,		"PhyHealth",(ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q = 	{ DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t = 	{ DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_Proxy = 				{ DataObjectModelType,		"Proxy",    (ModelNode*) &iedModel_GGIO_LPHD1,    NULL,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LPHD1_Proxy, (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_GGIO_LPHD1_Proxy_q = 		{ DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_t = 		{ DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


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
LogicalNode iedModel_GGIO_INGGIO1 				= { LogicalNodeModelType, 	"IN16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    	(ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 			= { DataObjectModelType,   	"Mod",    		(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 		= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_GGIO_INGGIO1_Mod,	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 		= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_GGIO_INGGIO1_Mod,	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal 	= { DataAttributeModelType,	"stVal",   		(ModelNode*) &iedModel_GGIO_INGGIO1_Mod,	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel= { DataAttributeModelType,	"ctlModel",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh 			= { DataObjectModelType,	"Beh",			(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal 	= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q 		= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t 		= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health			= { DataObjectModelType,	"Health",		(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_GGIO_INGGIO1_Health,	(ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q 	= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_GGIO_INGGIO1_Health,	(ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t 	= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_GGIO_INGGIO1_Health, NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt 		= { DataObjectModelType,	"NamPlt",    	(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor={ DataAttributeModelType,	"vendor",		(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev= { DataAttributeModelType,	"swRev",    	(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d 	= { DataAttributeModelType,	"d",			(ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 ****************************************************************************************************************************************************************/
DataObject iedModel_GGIO_INGGIO1_Ind1 			= { DataObjectModelType,	"Ind1",		(ModelNode*) &iedModel_GGIO_INGGIO1,		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_dU,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 			= { DataObjectModelType,	"Ind2",		(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 			= { DataObjectModelType,	"Ind3",		(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_dU		= { DataAttributeModelType, "dU", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 			= { DataObjectModelType,	"Ind4", 	(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 			= { DataObjectModelType,	"Ind5", 	(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 			= { DataObjectModelType,	"Ind6", 	(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 			= { DataObjectModelType,	"Ind7", 	(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 			= { DataObjectModelType,	"Ind8", 	(ModelNode*) &iedModel_GGIO_INGGIO1,    	(ModelNode*)&iedModel_GGIO_INGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind9 			= { DataObjectModelType, 	"Ind9", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal 	= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q 		= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t 		= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_dU		= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind9,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind10 			= { DataObjectModelType, 	"Ind10",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind10,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind11 			= { DataObjectModelType, 	"Ind11",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind11,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind12 			= { DataObjectModelType, 	"Ind12",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind12,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind13 			= { DataObjectModelType, 	"Ind13",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind13,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind14 			= { DataObjectModelType, 	"Ind14",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind14,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind15 			= { DataObjectModelType, 	"Ind15",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*)&iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind15,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind16 			= { DataObjectModelType, 	"Ind16",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*)NULL , (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q 	= { DataAttributeModelType, "q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t 	= { DataAttributeModelType, "t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_dU	= { DataAttributeModelType, "dU",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind16,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/
LogicalNode iedModel_GGIO_OUTGGIO1 					= { LogicalNodeModelType,	"OUT14GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   		(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};

DataObject iedModel_GGIO_OUTGGIO1_Mod 				= { DataObjectModelType,	"Mod",    	(ModelNode*) &iedModel_GGIO_OUTGGIO1,    		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal 		= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod, 		(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_GGIO_OUTGGIO1_Beh 				= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_GGIO_OUTGGIO1,    		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_GGIO_OUTGGIO1_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_GGIO_OUTGGIO1,    		(ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_GGIO_OUTGGIO1_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_GGIO_OUTGGIO1,    		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_OUTGGIO1_SPCSO1 			= { DataObjectModelType,   	"SPCSO1",	(ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO2 			= { DataObjectModelType,   	"SPCSO2",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*)  &iedModel_GGIO_OUTGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO3 			= { DataObjectModelType,   	"SPCSO3",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO4 			= { DataObjectModelType,   	"SPCSO4",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO5 			= { DataObjectModelType,   	"SPCSO5",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO6 			= { DataObjectModelType,   	"SPCSO6",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO7 			= { DataObjectModelType,   	"SPCSO7",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO8 			= { DataObjectModelType,   	"SPCSO8",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO9 			= { DataObjectModelType,   	"SPCSO9",   (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO10 			= { DataObjectModelType,   	"SPCSO10",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO11 			= { DataObjectModelType,   	"SPCSO11",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO12 			= { DataObjectModelType,   	"SPCSO12",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO13 			= { DataObjectModelType,   	"SPCSO13",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO14 			= { DataObjectModelType,   	"SPCSO14",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
/*
DataObject iedModel_GGIO_OUTGGIO1_SPCSO15 			= { DataObjectModelType,   	"SPCSO15",  (ModelNode*) &iedModel_GGIO_OUTGGIO1,     		(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q 		= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t 		= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 	(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_dU		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
*/
/*************************************************************************
 * LED12GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_LEDGGIO1 					= { LogicalNodeModelType, 	"LED12GGIO1",(ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)NULL,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

DataObject iedModel_GGIO_LEDGGIO1_Mod 				= { DataObjectModelType,   	"Mod",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Beh 				= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_NamPlt 			= { DataObjectModelType,	"NamPlt",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind1,  (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_LEDGGIO1_Ind1 			= {DataObjectModelType,"Ind1",			(ModelNode*) &iedModel_GGIO_LEDGGIO1,		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q 	= {DataAttributeModelType,"q",			(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t 	= {DataAttributeModelType,"t",			(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_dU,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU 	= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Ind2 			= { DataObjectModelType,"Ind2",			(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q 	= { DataAttributeModelType,	"q",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t 	= { DataAttributeModelType,	"t",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_dU 	= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind3 			= { DataObjectModelType,	"Ind3",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_dU 	= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind4 			= { DataObjectModelType,	"Ind4",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_dU 	= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind5 			= { DataObjectModelType,	"Ind5",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind6 			= { DataObjectModelType,	"Ind6",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind7 			= { DataObjectModelType,	"Ind7",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind8 			= { DataObjectModelType,	"Ind8",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal = { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q 	= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t 	= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_dU,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind9 			= { DataObjectModelType, "Ind9", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind10 		= { DataObjectModelType, "Ind10", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind11 		= { DataObjectModelType, "Ind11", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind12 		= { DataObjectModelType, "Ind12", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_dU, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_dU 	= { DataAttributeModelType, "dU",  	  	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

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
LogicalNode iedModel_RPN_ATCC1 					= { LogicalNodeModelType, 	"ATCC1",	(ModelNode*) &iedModel_Generic_RPN,   	(ModelNode*) NULL,    					(ModelNode*) &iedModel_RPN_ATCC1_Mod};
DataObject iedModel_RPN_ATCC1_Mod 				= { DataObjectModelType,	"Mod",  	(ModelNode*) &iedModel_RPN_ATCC1,    	(ModelNode*) &iedModel_RPN_ATCC1_Beh,   (ModelNode*) &iedModel_RPN_ATCC1_Mod_stVal,0};
DataAttribute iedModel_RPN_ATCC1_Mod_stVal 		= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_RPN_ATCC1_Mod,   (ModelNode*) &iedModel_RPN_ATCC1_Mod_q,  NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Mod_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_Mod,   (ModelNode*) &iedModel_RPN_ATCC1_Mod_t,  NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,   TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Mod_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_Mod,   (ModelNode*) NULL,    					 NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_RPN_ATCC1_Beh 				= { DataObjectModelType,	"Beh",  	(ModelNode*) &iedModel_RPN_ATCC1,    	(ModelNode*) &iedModel_RPN_ATCC1_Health,    (ModelNode*) &iedModel_RPN_ATCC1_Beh_stVal,0};
DataAttribute iedModel_RPN_ATCC1_Beh_stVal 		= { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_RPN_ATCC1_Beh,   (ModelNode*) &iedModel_RPN_ATCC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Beh_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_Beh,   (ModelNode*) &iedModel_RPN_ATCC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Beh_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_RPN_ATCC1_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_RPN_ATCC1,    	(ModelNode*) &iedModel_RPN_ATCC1_NamPlt,	(ModelNode*) &iedModel_RPN_ATCC1_Health_stVal,0};
DataAttribute iedModel_RPN_ATCC1_Health_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_RPN_ATCC1_Health,(ModelNode*) &iedModel_RPN_ATCC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_RPN_ATCC1_Health_q 		= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_Health,(ModelNode*) &iedModel_RPN_ATCC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_RPN_ATCC1_Health_t 		= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_Health, NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_RPN_ATCC1_NamPlt 			= { DataObjectModelType,	"NamPlt",   (ModelNode*) &iedModel_RPN_ATCC1,    	(ModelNode*) &iedModel_RPN_ATCC1_Loc, (ModelNode*) &iedModel_RPN_ATCC1_NamPlt_vendor,0};
DataAttribute iedModel_RPN_ATCC1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_RPN_ATCC1_NamPlt,(ModelNode*) &iedModel_RPN_ATCC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_RPN_ATCC1_NamPlt_swRev 	= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_RPN_ATCC1_NamPlt,(ModelNode*) &iedModel_RPN_ATCC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_RPN_ATCC1_NamPlt_d 		= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_RPN_ATCC1_NamPlt, NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_RPN_ATCC1_Loc 	 			= { DataObjectModelType,	"Loc",  	(ModelNode*) &iedModel_RPN_ATCC1,  		(ModelNode*)&iedModel_RPN_ATCC1_TapChg, (ModelNode*) &iedModel_RPN_ATCC1_Loc_stVal,0};
DataAttribute iedModel_RPN_ATCC1_Loc_stVal	 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_RPN_ATCC1_Loc,  	(ModelNode*) &iedModel_RPN_ATCC1_Loc_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Loc_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_Loc,  	(ModelNode*) &iedModel_RPN_ATCC1_Loc_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_Loc_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_Loc, 	 NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

//TapChg
DataObject iedModel_RPN_ATCC1_TapChg 						= { DataObjectModelType,   	"TapChg",     	(ModelNode*) &iedModel_RPN_ATCC1,     				(ModelNode*)  &iedModel_RPN_ATCC1_ParOp,    (ModelNode*) &iedModel_RPN_ATCC1_TapChg_q,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_q 					= { DataAttributeModelType,	"q",       		(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_t 					= { DataAttributeModelType,	"t",       		(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_d 					= { DataAttributeModelType,	"d",       		(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_valWTr,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr 				= { DataAttributeModelType,	"valWTr",   	(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_persistent,  (ModelNode*) &iedModel_RPN_ATCC1_TapChg_valWTr_posVal,    0,    IEC61850_FC_ST,    IEC61850_CONSTRUCTED,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr_posVal 		= { DataAttributeModelType,	"posVal",   	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_valWTr, 	(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT8,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_persistent 			= { DataAttributeModelType,	"persistent",	(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_ctlModel, NULL,    0,    IEC61850_FC_CF,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel 			= { DataAttributeModelType,	"ctlModel",		(ModelNode*) &iedModel_RPN_ATCC1_TapChg, 			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper 				= { DataAttributeModelType,	"Oper",    		(ModelNode*) &iedModel_RPN_ATCC1_TapChg,   			 NULL,    (ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CODEDENUM, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin 		= { DataAttributeModelType,	"origin",  		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_ctlNum,    (ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_origin,(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent	= { DataAttributeModelType,	"orIdent", 		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_origin, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_T 				= { DataAttributeModelType,	"T",    		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Test 			= { DataAttributeModelType,	"Test",    		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Check 			= { DataAttributeModelType,	"Check",    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg_Oper,    	 NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

/*
//TapChg
DataObject iedModel_RPN_ATCC1_TapChg 			= { DataObjectModelType,	"TapChg",   (ModelNode*) &iedModel_RPN_ATCC1,    				(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 						(ModelNode*) &iedModel_RPN_ATCC1_TapChg_ctlVal,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlVal	= { DataAttributeModelType, "ctlVal",   (ModelNode*) &iedModel_RPN_ATCC1_TapChg,		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_ctlNum,	 		NULL,	 0,    IEC61850_FC_CO, IEC61850_CODEDENUM, TRG_OPT_NO, NULL,0}; // значения: вверх...вниз
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlNum	= { DataAttributeModelType, "ctlNum",   (ModelNode*) &iedModel_RPN_ATCC1_TapChg,		(ModelNode*) &iedModel_RPN_ATCC1_TapChg_q, 			NULL,    0,    IEC61850_FC_ST, IEC61850_INT8U, TRG_OPT_NO, NULL,0};// значения: 0...40
DataAttribute iedModel_RPN_ATCC1_TapChg_q 		= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg,			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_t,    					NULL,    0,    IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_t 		= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_TapChg,			(ModelNode*) &iedModel_RPN_ATCC1_TapChg_ctlModel,   			NULL,    0,    IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_RPN_ATCC1_TapChg,			(ModelNode*) NULL,    											NULL,    0,    IEC61850_FC_CF, IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
*/
/*
//ParOp
DataObject iedModel_RPN_ATCC1_ParOp 			= { DataObjectModelType,	"ParOp",   	(ModelNode*) &iedModel_RPN_ATCC1,    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1, (ModelNode*) &iedModel_RPN_ATCC1_ParOp_ctlVal,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlVal 	= { DataAttributeModelType, "ctlVal",   (ModelNode*) &iedModel_RPN_ATCC1_ParOp,	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_stVal,    	NULL,    0,    IEC61850_FC_CO, IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0}; // значения: -1...+1
DataAttribute iedModel_RPN_ATCC1_ParOp_stVal 	= { DataAttributeModelType, "stVal",   	(ModelNode*) &iedModel_RPN_ATCC1_ParOp,	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_q,  			NULL,    0,    IEC61850_FC_ST, IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};// значения: 0...40
DataAttribute iedModel_RPN_ATCC1_ParOp_q 		= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp,	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_t,    		NULL,    0,    IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_t 		= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp,	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_ctlModel,  	NULL,    0,    IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel = { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_RPN_ATCC1_ParOp,	(ModelNode*) NULL,    								NULL,    0,    IEC61850_FC_CF, IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
*/
//ParOp
DataObject iedModel_RPN_ATCC1_ParOp 						= { DataObjectModelType,   	"ParOp",     	(ModelNode*) &iedModel_RPN_ATCC1,     				(ModelNode*)  &iedModel_RPN_ATCC1_CtlV1,    (ModelNode*) &iedModel_RPN_ATCC1_ParOp_q,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_q 					= { DataAttributeModelType,	"q",       		(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 			(ModelNode*) &iedModel_RPN_ATCC1_ParOp_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_t 					= { DataAttributeModelType,	"t",       		(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 			(ModelNode*) &iedModel_RPN_ATCC1_ParOp_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_d 					= { DataAttributeModelType,	"d",       		(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 			(ModelNode*) &iedModel_RPN_ATCC1_ParOp_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_stVal 				= { DataAttributeModelType,	"stVal",   		(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 			(ModelNode*) &iedModel_RPN_ATCC1_ParOp_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel 			= { DataAttributeModelType,	"ctlModel",		(ModelNode*) &iedModel_RPN_ATCC1_ParOp, 			(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper 				= { DataAttributeModelType,	"Oper",    		(ModelNode*) &iedModel_RPN_ATCC1_ParOp,   			 NULL,    (ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlVal 			= { DataAttributeModelType,	"ctlVal",  		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin 			= { DataAttributeModelType,	"origin",  		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_ctlNum,    (ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_origin,(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orIdent	= { DataAttributeModelType,	"orIdent", 		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_origin, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlNum 			= { DataAttributeModelType,	"ctlNum",  		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_T 				= { DataAttributeModelType,	"T",    		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Test 			= { DataAttributeModelType,	"Test",    		(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Check 			= { DataAttributeModelType,	"Check",    	(ModelNode*) &iedModel_RPN_ATCC1_ParOp_Oper,    	 NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV1			= { DataObjectModelType, 	"CtlV1", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV2, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV1_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV1_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV1_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV1_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV1, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV1_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV1_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV1,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV2			= { DataObjectModelType, 	"CtlV2", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV3, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV2_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV2_instMag,	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV2_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV2_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV2, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV2_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV2_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV2,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV3			= { DataObjectModelType, 	"CtlV3", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV4, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV3_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV3_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV3_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV3_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV3, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV3_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV3_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV3,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV4			= { DataObjectModelType, 	"CtlV4", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV5, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV4_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV4_instMag,	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV4_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV4_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV4, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV4_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV4_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV4,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV5			= { DataObjectModelType, 	"CtlV5", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV6, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV5_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV5_instMag,	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV5_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV5_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV5, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV5_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV5_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV5,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV6			= { DataObjectModelType, 	"CtlV6", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV7, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV6_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV6_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV6_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV6_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV6, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV6_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV6_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV6,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV7			= { DataObjectModelType, 	"CtlV7", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_CtlV8, 			(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV7_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV7_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV7_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV7_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV7, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV7_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV7_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV7,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_CtlV8			= { DataObjectModelType, 	"CtlV8", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_LodA1, 								(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_CtlV8_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV8_instMag, (ModelNode*) &iedModel_RPN_ATCC1_CtlV8_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8,  	(ModelNode*)&iedModel_RPN_ATCC1_CtlV8_q, 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_CtlV8_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_CtlV8, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV8_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8, 	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_CtlV8_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_CtlV8,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject    iedModel_RPN_ATCC1_LodA1			= { DataObjectModelType, 	"LodA1", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_LodA2, 			(ModelNode*) &iedModel_RPN_ATCC1_LodA1_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_LodA1_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA1_instMag,	(ModelNode*) &iedModel_RPN_ATCC1_LodA1_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA1_q, 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA1_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA1, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA1_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA1_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA1_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_LodA1,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_LodA2			= { DataObjectModelType, 	"LodA2", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_LodA3, 			(ModelNode*) &iedModel_RPN_ATCC1_LodA2_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_LodA2_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA2_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA2_q, 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA2_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA2, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA2_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA2_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA2_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_LodA2,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_LodA3			= { DataObjectModelType, 	"LodA3", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)&iedModel_RPN_ATCC1_LodA4, 			(ModelNode*) &iedModel_RPN_ATCC1_LodA3_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_LodA3_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA3_instMag,	(ModelNode*) &iedModel_RPN_ATCC1_LodA3_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA3_q, 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA3_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA3, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA3_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA3_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA3_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_LodA3,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_RPN_ATCC1_LodA4			= { DataObjectModelType, 	"LodA4", 	(ModelNode*) &iedModel_RPN_ATCC1, 			(ModelNode*)NULL, 								(ModelNode*) &iedModel_RPN_ATCC1_LodA4_mag, 	0 };
DataAttribute iedModel_RPN_ATCC1_LodA4_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA4_instMag, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4_mag, NULL, 											NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4,  	(ModelNode*)&iedModel_RPN_ATCC1_LodA4_q, 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4_instMag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4_instMag, NULL, 										NULL, 											0, IEC61850_FC_MX, IEC61850_FLOAT32,	0, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4_t, 		NULL, 											0, IEC61850_FC_MX, IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4_db, 		NULL, 											0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_RPN_ATCC1_LodA4_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_RPN_ATCC1_LodA4, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4_zeroDb, 	NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA4_zeroDb	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4, 	(ModelNode*) &iedModel_RPN_ATCC1_LodA4_dU,		NULL, 											0, IEC61850_FC_CF, IEC61850_INT32U, 	0, NULL,0 };
DataAttribute iedModel_RPN_ATCC1_LodA4_dU 		= { DataAttributeModelType, "dU",    	(ModelNode*) &iedModel_RPN_ATCC1_LodA4,   	NULL,    										NULL, 											0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1 					= { LogicalNodeModelType,	"GGIO1",    (ModelNode*) &iedModel_Generic_CTRL,  NULL ,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod};

DataObject iedModel_CTRL_GGIO1_Mod 					= { DataObjectModelType,   	"Mod",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod_q,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel 		= { DataAttributeModelType,	"ctlModel",    (ModelNode*) &iedModel_CTRL_GGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_Beh 					= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_GGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_Health 				= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,	(ModelNode*) &iedModel_CTRL_GGIO1_Health_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Health_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_GGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_NamPlt 				= { DataObjectModelType,	"NamPlt",    (ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*)&iedModel_CTRL_GGIO1_SPCSO1 , (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_vendor,0};

DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,	(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev 		= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,	(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_d 			= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO1_SPCSO1 						= { DataObjectModelType,   	"SPCSO1",   (ModelNode*) &iedModel_CTRL_GGIO1,     		(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO1_SPCSO2 						= { DataObjectModelType,   	"SPCSO2",   (ModelNode*) &iedModel_CTRL_GGIO1,     			(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO1_SPCSO3 						= { DataObjectModelType,   	"SPCSO3",   (ModelNode*) &iedModel_CTRL_GGIO1,     	(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO4,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal 				= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO1_SPCSO4 						= { DataObjectModelType,   	"SPCSO4",	(ModelNode*) &iedModel_CTRL_GGIO1,     				NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q 					= { DataAttributeModelType,	"q",  		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t 					= { DataAttributeModelType,	"t",     	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d 					= { DataAttributeModelType,	"d",      	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal 				= { DataAttributeModelType,	 "stVal",   (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN,     TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check 		= { DataAttributeModelType,	"Check",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, 		NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
/***********************************************************************
 * DataSet
 ***********************************************************************/
// --------------------------------------------------------
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
DataSetEntry iedModelds_LD0_LLN0_dataset0_fcda15 = {"GGIO",false,"IN16GGIO1$ST$Ind16", -1, NULL, NULL, NULL};
#define 	_numDS0		16

//LED12
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
DataSetEntry iedModelds_LD0_LLN0_dataset1_fcda11 = {"GGIO",false,"LED12GGIO1$ST$Ind12", -1, NULL, NULL, NULL  };
#define 	_numDS1		12

DataSetEntry iedModelds_LD0_LLN0_dataset2_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS2		0

DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda0 = {"CTRL",false,"GGIO1$ST$SPCSO1$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda1 = {"CTRL",false,"GGIO1$ST$SPCSO2$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda2 = {"CTRL",false,"GGIO1$ST$SPCSO3$stVal", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset3_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset3_fcda3 = {"CTRL",false,"GGIO1$ST$SPCSO4$stVal", -1, NULL, NULL, NULL };
#define 	_numDS3		4

DataSetEntry iedModelds_LD0_LLN0_dataset4_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS4		0

DataSetEntry iedModelds_LD0_LLN0_dataset5_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS5		0

DataSetEntry iedModelds_LD0_LLN0_dataset6_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS6		0

DataSetEntry iedModelds_LD0_LLN0_dataset7_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS7		0

DataSetEntry iedModelds_LD0_LLN0_dataset8_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS8		0

DataSetEntry iedModelds_LD0_LLN0_dataset9_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS9		0

DataSetEntry iedModelds_LD0_LLN0_dataset10_fcda0 = {"CTRL",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS10	0

DataSetEntry iedModelds_LD0_LLN0_dataset11_fcda0 = {"RPN",false,"ATCC1$ST$Loc", -1, NULL, NULL, NULL };
#define 	_numDS11	1

DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda0 = {"RPN",false,"ATCC1$MX$CtlV1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda1 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda1 = {"RPN",false,"ATCC1$MX$CtlV2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda2 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda2 = {"RPN",false,"ATCC1$MX$CtlV3", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda3 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda3 = {"RPN",false,"ATCC1$MX$CtlV4", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda4 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda4 = {"RPN",false,"ATCC1$MX$CtlV5", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda5 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda5 = {"RPN",false,"ATCC1$MX$CtlV6", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda6 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda6 = {"RPN",false,"ATCC1$MX$CtlV7", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda7 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda7 = {"RPN",false,"ATCC1$MX$CtlV8", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda8 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda8 = {"RPN",false,"ATCC1$MX$LodA1", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda9 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda9 = {"RPN",false,"ATCC1$MX$LodA2", -1, NULL, NULL, &iedModelds_LD0_LLN0_dataset12_fcda10 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda10 = {"RPN",false,"ATCC1$MX$LodA3", -1, NULL, NULL,&iedModelds_LD0_LLN0_dataset12_fcda11 };
DataSetEntry iedModelds_LD0_LLN0_dataset12_fcda11 = {"RPN",false,"ATCC1$MX$LodA4", -1, NULL, NULL, NULL };
#define 	_numDS12		12

DataSetEntry iedModelds_LD0_LLN0_dataset13_fcda0 = {"RPN",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS13		0

DataSetEntry iedModelds_LD0_LLN0_dataset14_fcda0 = {"RPN",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS14		0

DataSetEntry iedModelds_LD0_LLN0_dataset15_fcda0 = {"RPN",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS15		0

DataSetEntry iedModelds_LD0_LLN0_dataset16_fcda0 = {"RPN",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS16		0

DataSetEntry iedModelds_LD0_LLN0_dataset17_fcda0 = {"RPN",false, " ",-1,NULL,NULL,NULL};
#define 	_numDS17		0

#define 	_numDS18		0
#define 	_numDS19		0

/***********************************************************************
 * DataSet
 ***********************************************************************/
DataSet iedModelds_LD0_LLN0_dataset0 = {"LD0", "LLN0$DS0", _numDS0, 	&iedModelds_LD0_LLN0_dataset0_fcda0, 	&iedModelds_LD0_LLN0_dataset1};			// IN42GGIO
DataSet iedModelds_LD0_LLN0_dataset1 = {"LD0", "LLN0$DS1", _numDS1, 	&iedModelds_LD0_LLN0_dataset1_fcda0, 	&iedModelds_LD0_LLN0_dataset2};			// LED16
DataSet iedModelds_LD0_LLN0_dataset2 = {"LD0", "LLN0$DS2", _numDS2, 	NULL, 									&iedModelds_LD0_LLN0_dataset3};			// XCBR1
DataSet iedModelds_LD0_LLN0_dataset3 = {"LD0", "LLN0$DS3", _numDS3, 	&iedModelds_LD0_LLN0_dataset3_fcda0,	&iedModelds_LD0_LLN0_dataset4};			// SPCSO
DataSet iedModelds_LD0_LLN0_dataset4 = {"LD0", "LLN0$DS4", _numDS4, 	&iedModelds_LD0_LLN0_dataset4_fcda0,	&iedModelds_LD0_LLN0_dataset5};			// IPTOC IPTUC
DataSet iedModelds_LD0_LLN0_dataset5 = {"LD0", "LLN0$DS5", _numDS5, 	&iedModelds_LD0_LLN0_dataset5_fcda0,	&iedModelds_LD0_LLN0_dataset6};			// UPTOV UPTUV
DataSet iedModelds_LD0_LLN0_dataset6 = {"LD0", "LLN0$DS6", _numDS6, 	&iedModelds_LD0_LLN0_dataset6_fcda0,	&iedModelds_LD0_LLN0_dataset7};			//
DataSet iedModelds_LD0_LLN0_dataset7 = {"LD0", "LLN0$DS7", _numDS7, 	&iedModelds_LD0_LLN0_dataset7_fcda0,	&iedModelds_LD0_LLN0_dataset8};			//
DataSet iedModelds_LD0_LLN0_dataset8 = {"LD0", "LLN0$DS8", _numDS8, 	&iedModelds_LD0_LLN0_dataset8_fcda0,	&iedModelds_LD0_LLN0_dataset9};			//
DataSet iedModelds_LD0_LLN0_dataset9 = {"LD0", "LLN0$DS9", _numDS9,		&iedModelds_LD0_LLN0_dataset9_fcda0,	&iedModelds_LD0_LLN0_dataset10};		//
DataSet iedModelds_LD0_LLN0_dataset10 ={"LD0", "LLN0$DS10",_numDS10, 	&iedModelds_LD0_LLN0_dataset10_fcda0,	&iedModelds_LD0_LLN0_dataset11};		//
DataSet iedModelds_LD0_LLN0_dataset11 ={"LD0", "LLN0$DS11",_numDS11, 	&iedModelds_LD0_LLN0_dataset11_fcda0 ,	&iedModelds_LD0_LLN0_dataset12};		//
DataSet iedModelds_LD0_LLN0_dataset12 ={"LD0", "LLN0$DS12",_numDS12, 	&iedModelds_LD0_LLN0_dataset12_fcda0 ,	&iedModelds_LD0_LLN0_dataset13};
DataSet iedModelds_LD0_LLN0_dataset13 ={"LD0", "LLN0$DS13",_numDS13, 	&iedModelds_LD0_LLN0_dataset13_fcda0 ,	&iedModelds_LD0_LLN0_dataset14};
DataSet iedModelds_LD0_LLN0_dataset14 ={"LD0", "LLN0$DS14",_numDS14, 	&iedModelds_LD0_LLN0_dataset14_fcda0 ,	&iedModelds_LD0_LLN0_dataset15};
DataSet iedModelds_LD0_LLN0_dataset15 ={"LD0", "LLN0$DS15",_numDS15, 	&iedModelds_LD0_LLN0_dataset15_fcda0 ,	&iedModelds_LD0_LLN0_dataset16};
DataSet iedModelds_LD0_LLN0_dataset16 ={"LD0", "LLN0$DS16",_numDS16, 	&iedModelds_LD0_LLN0_dataset16_fcda0 ,	&iedModelds_LD0_LLN0_dataset17};
DataSet iedModelds_LD0_LLN0_dataset17 ={"LD0", "LLN0$DS17",_numDS17, 	&iedModelds_LD0_LLN0_dataset17_fcda0 ,	&iedModelds_LD0_LLN0_dataset18};
DataSet iedModelds_LD0_LLN0_dataset18 ={"LD0", "LLN0$DS18",_numDS18, 	NULL ,									&iedModelds_LD0_LLN0_dataset19};
DataSet iedModelds_LD0_LLN0_dataset19 ={"LD0", "LLN0$DS19",_numDS19, 	NULL ,									NULL};


ReportControlBlock iedModel_LD0_LLN0_report0 = {
	&iedModel_LD0_LLN0,
	"URCB_101",
	"LLN0$BR$URCB_101",
	false,				// false  UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"DS10",				// ссылка на набор данных для отчета
	0,					// ревизия конфигурации
	TRG_OPT_DATA_CHANGED,// | TRG_OPT_INTEGRITY,// условия включения 16
	111,				// OptFlds
	50,					// BufTm буферное время мс
	0,					// IntPrd - период целостности в мс (1000)
	&iedModel_LD0_LLN0_report1
};

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
//extern SettingGroupControlBlock iedModel_RPN_LLN0_sgcb;
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
iedModel_LD0_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString(_ConfigRevision);

iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
iedModel_LD0_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//USART_TRACE("LD0_LLN0\n");
/******************************************************************************
 * RPN
 ******************************************************************************/
iedModel_RPN_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);				// RPN LLN0
iedModel_RPN_LLN0_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_RPN_LLN0_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_RPN_LLN0_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_RPN_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_RPN_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_RPN_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

//iedModel_RPN_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString("0");

iedModel_RPN_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_RPN_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);// не будет прокси
iedModel_RPN_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_RPN_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//ATCC1
iedModel_RPN_ATCC1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);				// RPN ATCC1
iedModel_RPN_ATCC1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_ATCC1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_ATCC1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_RPN_ATCC1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_ATCC1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_ATCC1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_RPN_ATCC1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_ATCC1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_ATCC1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_RPN_ATCC1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_RPN_ATCC1_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);


iedModel_RPN_ATCC1_TapChg_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_RPN_ATCC1_TapChg_d.mmsValue = MmsValue_newVisibleString("Tap changer control (upravlenie RPN)");
iedModel_RPN_ATCC1_TapChg_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//iedModel_RPN_ATCC1_TapChg_Oper_ctlVal.mmsValue = MmsValue_newBitString(0);
iedModel_RPN_ATCC1_TapChg_persistent.mmsValue = MmsValue_newBoolean(false);

iedModel_RPN_ATCC1_ParOp_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_RPN_ATCC1_ParOp_d.mmsValue = MmsValue_newVisibleString("Remote control mode");
iedModel_RPN_ATCC1_ParOp_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//iedModel_RPN_ATCC1_ParOp_Oper_ctlVal.mmsValue = MmsValue_newBitString(0);

iedModel_RPN_ATCC1_CtlV1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_CtlV8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_ATCC1_LodA1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_LodA2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_LodA3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_RPN_ATCC1_LodA4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_RPN_ATCC1_CtlV1_dU.mmsValue = MmsValue_newMmsString("Uab. Section 1");
iedModel_RPN_ATCC1_CtlV2_dU.mmsValue = MmsValue_newMmsString("Ubс or Un. Section 1");
iedModel_RPN_ATCC1_CtlV3_dU.mmsValue = MmsValue_newMmsString("U2 (neg.seq). Section 1");
iedModel_RPN_ATCC1_CtlV4_dU.mmsValue = MmsValue_newMmsString("Up. Section 1");
iedModel_RPN_ATCC1_CtlV5_dU.mmsValue = MmsValue_newMmsString("Uab. Section 2");
iedModel_RPN_ATCC1_CtlV6_dU.mmsValue = MmsValue_newMmsString("Ubс or Un. Section 2");
iedModel_RPN_ATCC1_CtlV7_dU.mmsValue = MmsValue_newMmsString("U2 (neg.seq). Section 2");
iedModel_RPN_ATCC1_CtlV8_dU.mmsValue = MmsValue_newMmsString("Up. Section 2");

iedModel_RPN_ATCC1_LodA1_dU.mmsValue = MmsValue_newMmsString("Ivv. Section 1");
iedModel_RPN_ATCC1_LodA2_dU.mmsValue = MmsValue_newMmsString("Isv. Section 1");
iedModel_RPN_ATCC1_LodA3_dU.mmsValue = MmsValue_newMmsString("Ivv. Section 2");
iedModel_RPN_ATCC1_LodA4_dU.mmsValue = MmsValue_newMmsString("Isv. Section 2");

USART_TRACE("RPN\n");
/******************************************************************************
 * CTRL
 ******************************************************************************/
iedModel_CTRL_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);

iedModel_CTRL_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_LLN0_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_LLN0_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LLN0_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_LLN0_NamPlt_ldNs.mmsValue = MmsValue_newVisibleString(_LDNS);
iedModel_CTRL_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_CTRL_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);
iedModel_CTRL_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString(_ConfigRevision);


iedModel_CTRL_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(STVALINT32_OK);
iedModel_CTRL_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_CTRL_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);

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
iedModel_CTRL_GGIO1_NamPlt_d.mmsValue = MmsValue_newVisibleString(_SWRevision);

iedModel_CTRL_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);

iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("blocking reset");//Сброс блокировки
iedModel_CTRL_GGIO1_SPCSO4_d.mmsValue = MmsValue_newVisibleString("signaling reset");//and Relays Сброс индикации

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
iedModel_GGIO_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString(_ConfigRevision);

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

iedModel_GGIO_INGGIO1_Ind1_dU.mmsValue = MmsValue_newMmsString("Command 'Higher'");
iedModel_GGIO_INGGIO1_Ind2_dU.mmsValue = MmsValue_newMmsString("Command 'Lower'");
iedModel_GGIO_INGGIO1_Ind3_dU.mmsValue = MmsValue_newMmsString("Forbiddance of Command 'Higher'");
iedModel_GGIO_INGGIO1_Ind4_dU.mmsValue = MmsValue_newMmsString("Forbiddance of Command 'Lower'");
iedModel_GGIO_INGGIO1_Ind5_dU.mmsValue = MmsValue_newMmsString("Switching Operation");
iedModel_GGIO_INGGIO1_Ind6_dU.mmsValue = MmsValue_newMmsString("Automatic Mode");
iedModel_GGIO_INGGIO1_Ind7_dU.mmsValue = MmsValue_newMmsString("Section 1 Selection");
iedModel_GGIO_INGGIO1_Ind8_dU.mmsValue = MmsValue_newMmsString("Section 2 Selection");
iedModel_GGIO_INGGIO1_Ind9_dU.mmsValue = MmsValue_newMmsString("Two sections control");
iedModel_GGIO_INGGIO1_Ind10_dU.mmsValue = MmsValue_newMmsString("Blocking");
iedModel_GGIO_INGGIO1_Ind11_dU.mmsValue = MmsValue_newMmsString("Up1");
iedModel_GGIO_INGGIO1_Ind12_dU.mmsValue = MmsValue_newMmsString("Up2");
iedModel_GGIO_INGGIO1_Ind13_dU.mmsValue = MmsValue_newMmsString("D1");
iedModel_GGIO_INGGIO1_Ind14_dU.mmsValue = MmsValue_newMmsString("D2");
iedModel_GGIO_INGGIO1_Ind15_dU.mmsValue = MmsValue_newMmsString("D3");
iedModel_GGIO_INGGIO1_Ind16_dU.mmsValue = MmsValue_newMmsString("D4");


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
//iedModel_GGIO_OUTGGIO1_SPCSO15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_GGIO_OUTGGIO1_SPCSO1_dU.mmsValue = MmsValue_newMmsString("Relay 1");
iedModel_GGIO_OUTGGIO1_SPCSO2_dU.mmsValue = MmsValue_newMmsString("Relay 2");
iedModel_GGIO_OUTGGIO1_SPCSO3_dU.mmsValue = MmsValue_newMmsString("Relay 3");
iedModel_GGIO_OUTGGIO1_SPCSO4_dU.mmsValue = MmsValue_newMmsString("Relay 4");
iedModel_GGIO_OUTGGIO1_SPCSO5_dU.mmsValue = MmsValue_newMmsString("Relay 5");
iedModel_GGIO_OUTGGIO1_SPCSO6_dU.mmsValue = MmsValue_newMmsString("Relay 6");
iedModel_GGIO_OUTGGIO1_SPCSO7_dU.mmsValue = MmsValue_newMmsString("Relay 7");
iedModel_GGIO_OUTGGIO1_SPCSO8_dU.mmsValue = MmsValue_newMmsString("Relay 8");
iedModel_GGIO_OUTGGIO1_SPCSO9_dU.mmsValue = MmsValue_newMmsString("Relay 9");
iedModel_GGIO_OUTGGIO1_SPCSO10_dU.mmsValue = MmsValue_newMmsString("Relay 10");
iedModel_GGIO_OUTGGIO1_SPCSO11_dU.mmsValue = MmsValue_newMmsString("Relay 11");
iedModel_GGIO_OUTGGIO1_SPCSO12_dU.mmsValue = MmsValue_newMmsString("Relay 12");
iedModel_GGIO_OUTGGIO1_SPCSO13_dU.mmsValue = MmsValue_newMmsString("Relay 'Higher'");
iedModel_GGIO_OUTGGIO1_SPCSO14_dU.mmsValue = MmsValue_newMmsString("Relay 'Lower'");
//iedModel_GGIO_OUTGGIO1_SPCSO15_dU.mmsValue = MmsValue_newMmsString("Relay 'Watchdog'");

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

iedModel_GGIO_LEDGGIO1_Ind6_dU.mmsValue = MmsValue_newMmsString("LED Blocking");
iedModel_GGIO_LEDGGIO1_Ind5_dU.mmsValue = MmsValue_newMmsString("LED Lowest Position");
iedModel_GGIO_LEDGGIO1_Ind4_dU.mmsValue = MmsValue_newMmsString("LED Highest Position");
iedModel_GGIO_LEDGGIO1_Ind3_dU.mmsValue = MmsValue_newMmsString("LED Switching Operation");
iedModel_GGIO_LEDGGIO1_Ind2_dU.mmsValue = MmsValue_newMmsString("LED Command 'Lower'");
iedModel_GGIO_LEDGGIO1_Ind1_dU.mmsValue = MmsValue_newMmsString("LED Command 'Higher'");
iedModel_GGIO_LEDGGIO1_Ind12_dU.mmsValue = MmsValue_newMmsString("LED Automatic Mode (Remote Mode when flashing)");
iedModel_GGIO_LEDGGIO1_Ind11_dU.mmsValue = MmsValue_newMmsString("LED System Log");
iedModel_GGIO_LEDGGIO1_Ind10_dU.mmsValue = MmsValue_newMmsString("LED Section 2");
iedModel_GGIO_LEDGGIO1_Ind9_dU.mmsValue = MmsValue_newMmsString("LED Section 1");
iedModel_GGIO_LEDGGIO1_Ind8_dU.mmsValue = MmsValue_newMmsString("LED U<norm");
iedModel_GGIO_LEDGGIO1_Ind7_dU.mmsValue = MmsValue_newMmsString("LED U>norm");


USART_TRACE("------------------------------------------------------------\n");
}

#endif
