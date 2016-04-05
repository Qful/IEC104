/*
 * static_model.c
 *
 * automatically generated from simpleIO_direct_control.scd
 */
#include "stdlib.h"
#include "model.h"
#include "main.h"

IedModel iedModel;
static DataSet* datasets[];
static ReportControlBlock* reportControlBlocks[];
static GSEControlBlock* gseControlBlocks[];
static void initializeValues();

LogicalDevice iedModel_GenericIO;

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
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO3;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q;
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
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t;

DataObject    iedModel_GenericIO_GGIO1_SPCSO4;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q;
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
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t;

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

IedModel iedModel = {
    "MR801",						// имя электронного устройства
    &iedModel_GenericIO,				// первое логическое устройство LD в IED
    datasets,
    reportControlBlocks,				// блок отчетов
    gseControlBlocks,
    initializeValues
};


/*************************************************************************
 * Логическое устройство LD
 *
 *************************************************************************/
LogicalDevice iedModel_GenericIO = {
    "MR801",								// имя нашего логического устройства		//"simpleIOGenericIO"
    NULL,									// одноранговый следующий узел				// родитель
    &iedModel_GenericIO_LLN0				// первый LN(логический узел)
};
/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_GenericIO_LLN0 = {
    LogicalNodeModelType,						// тип модели : LogicalNode,DataObject,DataAttribute
    "LLN0",										// имя узла
    &iedModel_GenericIO,						// родитель узла (LD (logical device))
    (ModelNode*) &iedModel_GenericIO_LPHD1,		// одноранговый следующий узел
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,	// первый наследник
};

DataObject iedModel_GenericIO_LLN0_Mod = {
    DataObjectModelType,
    "Mod",										// Режим
    (ModelNode*) &iedModel_GenericIO_LLN0,		// Родитель
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,	// одноранговый
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_q,// первый наследник
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_stVal,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};


DataAttribute iedModel_GenericIO_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_ctlModel,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    NULL,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataObject iedModel_GenericIO_LLN0_Beh = {
    DataObjectModelType,
    "Beh",												// Режим работы
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LLN0_Health = {
    DataObjectModelType,
    "Health",												// Состояние работоспособности
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",													// 	Паспортная табличка
    (ModelNode*) &iedModel_GenericIO_LLN0,
    NULL,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_swRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_d,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_configRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_ldNs,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    0,
    EX,
    VISIBLE_STRING_255,
    NULL
};
/*************************************************************************
 * Логический узел LN
 *
 *************************************************************************/
LogicalNode iedModel_GenericIO_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",											// Информация о физическом устройстве LPHD
    &iedModel_GenericIO,
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
};

DataObject iedModel_GenericIO_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",												//Паспортная табличка физического устройства
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataObject iedModel_GenericIO_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",											// Состояние работоспособности физического устройства
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",													//Означает, служит ли данный LN посредником
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    NULL,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
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
LogicalNode iedModel_GenericIO_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    &iedModel_GenericIO,
    NULL,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
};

DataObject iedModel_GenericIO_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",													// Режим
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_q,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_ctlModel,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    NULL,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,						// следующий
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_swRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_d,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1, //iedModel_GenericIO_GGIO1_SPCSO1,//(ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn2 = {
    DataObjectModelType,
    "AnIn2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    NULL,//(ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn3 = {
    DataObjectModelType,
    "AnIn3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn4 = {
    DataObjectModelType,
    "AnIn4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,//(ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO2 = {
    DataObjectModelType,
    "SPCSO2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO3 = {
    DataObjectModelType,
    "SPCSO3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO4 = {
    DataObjectModelType,
    "SPCSO4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind1 = {
    DataObjectModelType,
    "Discreet D1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind2 = {
    DataObjectModelType,
    "Discreet D2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind3 = {
    DataObjectModelType,
    "Discreet D3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind4 = {
    DataObjectModelType,
    "Discreet D4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind5 = {
    DataObjectModelType,
    "Discreet D5",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind5_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind5_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind5_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind5,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind6 = {
    DataObjectModelType,
    "Discreet D6",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind6_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind6_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind6_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind6,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind7 = {
    DataObjectModelType,
    "Discreet D7",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind7_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind7_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind7_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind7,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind8 = {
    DataObjectModelType,
    "Discreet D8",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9,						// следующий
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind8_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind8_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind8_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind8,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind9 = { DataObjectModelType, "Discreet D9", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind9_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind9, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind10 = { DataObjectModelType, "Discreet D10", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind10_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind10, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind11 = { DataObjectModelType, "Discreet D11", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind11_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind11, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind12 = { DataObjectModelType, "Discreet D12", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind12_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind12, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind13 = { DataObjectModelType, "Discreet D13", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind13_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind13, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind14 = { DataObjectModelType, "Discreet D14", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind14_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind14, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind15 = { DataObjectModelType, "Discreet D15", (ModelNode*) &iedModel_GenericIO_GGIO1, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind15_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind15, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};
// --------------------------------------------------------
DataObject iedModel_GenericIO_GGIO1_Ind16 = { DataObjectModelType, "Discreet D16", (ModelNode*) &iedModel_GenericIO_GGIO1,NULL /*(ModelNode*) &iedModel_GenericIO_GGIO1_Ind16*/, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_stVal, 0, 0};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_q, NULL, 0, 0, ST, BOOLEAN, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16_t, NULL, 0, 0, ST, QUALITY, NULL};
DataAttribute iedModel_GenericIO_GGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GenericIO_GGIO1_Ind16, NULL, NULL, 0, 0, ST, TIMESTAMP, NULL};

// --------------------------------------------------------
static DataSetEntry ds_GenericIO_LLN0_Events_fcda0 = {
  "MR801",														// имя LD
  "GGIO1$ST$SPCSO1$stVal",										// имя переменной
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda1 = {
  "MR801",
  "GGIO1$ST$SPCSO2$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda2 = {
  "MR801",
  "GGIO1$ST$SPCSO3$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda3 = {
  "MR801",
  "GGIO1$ST$SPCSO4$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry* ds_GenericIO_LLN0_Events_elements[1] = {
  &ds_GenericIO_LLN0_Events_fcda0//,
//  &ds_GenericIO_LLN0_Events_fcda1,
//  &ds_GenericIO_LLN0_Events_fcda2,
//  &ds_GenericIO_LLN0_Events_fcda3
};

static DataSet ds_GenericIO_LLN0_Events = {
  "MR801",
  "LLN0$Events",
  1,//4,
  ds_GenericIO_LLN0_Events_elements
};

// datasets
static DataSet* datasets[] = {
  &ds_GenericIO_LLN0_Events,
  NULL,
};

// iedModel_GenericIO_LLN0_report0
static ReportControlBlock iedModel_GenericIO_LLN0_report0 = {
	&iedModel_GenericIO_LLN0,
	"EventsRCB",
	"Events",
	false,				// UNBUFFERED REPORT CONTROL BLOCK(URCB)
	"Events",
	1,					// ревизия конфигурации
	16,					// условия включения
	111,				// OptFlds
	50,					// BufTm буферное время
	1000				// IntPrd - период целостности
};

// reportControlBlocks
static ReportControlBlock* reportControlBlocks[] = {
	&iedModel_GenericIO_LLN0_report0,
    NULL
};


static GSEControlBlock* gseControlBlocks[] = {
    NULL
};


/*************************************************************************
 * DataObject_hasFCData
 *
 *************************************************************************/
static void		initializeValues()
{

USART_TRACE("\n");
USART_TRACE("------------------------------------------------------------\n");
USART_TRACE("initializeValues:\n");

iedModel_GenericIO_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(12);			// создадим переменную LLN0_Mod_ctl (int32_t) = 0

iedModel_GenericIO_LLN0_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt32(72);

iedModel_GenericIO_LLN0_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt32(4352);			// создадим переменную

iedModel_GenericIO_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);					// не будет прокси

iedModel_GenericIO_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("BEMN");
iedModel_GenericIO_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("00.00");
iedModel_GenericIO_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("00.00");
iedModel_GenericIO_LLN0_NamPlt_configRev.mmsValue = MmsValue_newVisibleString("Config Rev.00");

iedModel_GenericIO_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString("ОАО 'Белэлектромонтажналадка'");


//iedModel_GenericIO_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(34);

//iedModel_GenericIO_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(56);

//iedModel_GenericIO_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(78);

//iedModel_GenericIO_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(910);

//iedModel_GenericIO_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1112);

USART_TRACE("------------------------------------------------------------\n");

}
