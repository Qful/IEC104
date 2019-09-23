/*
 * GGIO_model.c
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#include "stdlib.h"
#include "model.h"

#include "GGIO_model.h"

extern 	IedModel 		iedModel;

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)

#define GGIO_Next_Node 	NULL			// следующий узел после этого


/*************************************************************************
 * Логические устройства LD
 *************************************************************************/
LogicalDevice iedModel_Generic_GGIO 				= { LogicalDeviceModelType, "GGIO",		(ModelNode*)&iedModel,						(ModelNode*)GGIO_Next_Node,	(ModelNode*)&iedModel_GGIO_LLN0	};

/*************************************************************************
 * LLN0 Информация о логическом устройстве
 *************************************************************************/
LogicalNode iedModel_GGIO_LLN0 = { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_GGIO,	 (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LLN0_Mod,};

DataObject iedModel_GGIO_LLN0_Mod = { DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_GGIO_LLN0,	    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_q,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    (ModelNode*) &iedModel_GGIO_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel = { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Beh = { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    (ModelNode*) &iedModel_GGIO_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_Health = { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_GGIO_LLN0,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_Health_stVal,    0};
DataAttribute iedModel_GGIO_LLN0_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    (ModelNode*) &iedModel_GGIO_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LLN0_NamPlt = { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_GGIO_LLN0,    NULL,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev = { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs = { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_GGIO_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * LPHD1 Информация о физическом устройстве
 *************************************************************************/
LogicalNode iedModel_GGIO_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,};

DataObject iedModel_GGIO_LPHD1_PhyNam = 			{ DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor = 	{ DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_PhyHealth = 			{ DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_GGIO_LPHD1,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q = 	{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t = 	{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_GGIO_LPHD1_Proxy = 				{ DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_GGIO_LPHD1,    NULL,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LPHD1_Proxy, (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_GGIO_LPHD1_Proxy_q = 		{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_GGIO_LPHD1_Proxy_t = 		{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

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
LogicalNode iedModel_GGIO_INGGIO1 					= { LogicalNodeModelType,	"IN58GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};

DataObject iedModel_GGIO_INGGIO1_Mod 				= { DataObjectModelType,	"Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 			= { DataAttributeModelType,	"q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 			= { DataAttributeModelType,	"t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal 		= { DataAttributeModelType,	"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh 				= { DataObjectModelType,	"Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q 			= { DataAttributeModelType,	"q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t 			= { DataAttributeModelType,	"t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health 			= { DataObjectModelType,	"Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1, (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 ****************************************************************************************************************************************************************/
DataObject iedModel_GGIO_INGGIO1_Ind1 				= { DataObjectModelType,	"Ind1",	(ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal 		= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 				= { DataObjectModelType,	"Ind2",	(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 				= { DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 				= { DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 				= { DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 				= { DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q	 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 				= { DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 				= { DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind9	 			= { DataObjectModelType, "Ind9", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal 		= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_q 			= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind9_t 			= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind10 				= { DataObjectModelType, "Ind10", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind10_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind11 				= { DataObjectModelType, "Ind11", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind11_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind12 				= { DataObjectModelType, "Ind12", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind12_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind13 				= { DataObjectModelType, "Ind13", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind13_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind13, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind14 				= { DataObjectModelType, "Ind14", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind14_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind14, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind15 				= { DataObjectModelType, "Ind15", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind15_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind15, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind16 				= { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind17 , (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind17 				= { DataObjectModelType, "Ind17", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind18 				= { DataObjectModelType, "Ind18", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind19 				= { DataObjectModelType, "Ind19", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind20 				= { DataObjectModelType, "Ind20", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind21 				= { DataObjectModelType, "Ind21", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind22 				= { DataObjectModelType, "Ind22", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind23 				= { DataObjectModelType, "Ind23", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind24 				= { DataObjectModelType, "Ind24", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind25 				= { DataObjectModelType, "Ind25", (ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*)&iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind26 				= { DataObjectModelType, "Ind26", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind27 				= { DataObjectModelType, "Ind27", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind28 				= { DataObjectModelType, "Ind28", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind29 				= { DataObjectModelType, "Ind29", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal		= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind30 				= { DataObjectModelType, "Ind30", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind31	 			= { DataObjectModelType, "Ind31", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind32 				= { DataObjectModelType, "Ind32", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind33 				= { DataObjectModelType, "Ind33", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind34 				= { DataObjectModelType, "Ind34", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind35 				= { DataObjectModelType, "Ind35", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind36 				= { DataObjectModelType, "Ind36", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind37 				= { DataObjectModelType, "Ind37", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind38 				= { DataObjectModelType, "Ind38", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind39 				= { DataObjectModelType, "Ind39", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind40 				= { DataObjectModelType, "Ind40", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind41 				= { DataObjectModelType, "Ind41", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind42 				= { DataObjectModelType,	"Ind42",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind43 				= { DataObjectModelType,	"Ind43",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind44 				= { DataObjectModelType,	"Ind44",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind45 				= { DataObjectModelType,	"Ind45",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind46 				= { DataObjectModelType,	"Ind46",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind47 				= { DataObjectModelType,	"Ind47",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind48 				= { DataObjectModelType,	"Ind48",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind49 				= { DataObjectModelType,	"Ind49",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind50 				= { DataObjectModelType,	"Ind50",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind51 				= { DataObjectModelType,	"Ind51",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind52 				= { DataObjectModelType,	"Ind52",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind53 				= { DataObjectModelType,	"Ind53",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind54 				= { DataObjectModelType,	"Ind54",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind55 				= { DataObjectModelType,	"Ind55",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind56 				= { DataObjectModelType,	"Ind56",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind57 				= { DataObjectModelType,	"Ind57",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind58 				= { DataObjectModelType,	"Ind58",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) NULL, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_stVal 	= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED | TRG_OPT_GI, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 			NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 				NULL,0};

/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/

LogicalNode(Generic, GGIO, OUTGGIO1, OUT50GGIO1, LEDGGIO1, SPCSO1);

DataObjectSPCSO(1,2,GGIO, OUTGGIO1);
DataObjectSPCSO(2,3,GGIO, OUTGGIO1);
DataObjectSPCSO(3,4,GGIO, OUTGGIO1);
DataObjectSPCSO(4,5,GGIO, OUTGGIO1);
DataObjectSPCSO(5,6,GGIO, OUTGGIO1);
DataObjectSPCSO(6,7,GGIO, OUTGGIO1);
DataObjectSPCSO(7,8,GGIO, OUTGGIO1);
DataObjectSPCSO(8,9,GGIO, OUTGGIO1);
DataObjectSPCSO(9,10,GGIO, OUTGGIO1);
DataObjectSPCSO(10,11,GGIO, OUTGGIO1);
DataObjectSPCSO(11,12,GGIO, OUTGGIO1);
DataObjectSPCSO(12,13,GGIO, OUTGGIO1);
DataObjectSPCSO(13,14,GGIO, OUTGGIO1);
DataObjectSPCSO(14,15,GGIO, OUTGGIO1);
DataObjectSPCSO(15,16,GGIO, OUTGGIO1);
DataObjectSPCSO(16,17,GGIO, OUTGGIO1);
DataObjectSPCSO(17,18,GGIO, OUTGGIO1);
DataObjectSPCSO(18,19,GGIO, OUTGGIO1);
DataObjectSPCSO(19,20,GGIO, OUTGGIO1);
DataObjectSPCSO(20,21,GGIO, OUTGGIO1);
DataObjectSPCSO(21,22,GGIO, OUTGGIO1);
DataObjectSPCSO(22,23,GGIO, OUTGGIO1);
DataObjectSPCSO(23,24,GGIO, OUTGGIO1);
DataObjectSPCSO(24,25,GGIO, OUTGGIO1);
DataObjectSPCSO(25,26,GGIO, OUTGGIO1);
DataObjectSPCSO(26,27,GGIO, OUTGGIO1);
DataObjectSPCSO(27,28,GGIO, OUTGGIO1);
DataObjectSPCSO(28,29,GGIO, OUTGGIO1);
DataObjectSPCSO(29,30,GGIO, OUTGGIO1);
DataObjectSPCSO(30,31,GGIO, OUTGGIO1);
DataObjectSPCSO(31,32,GGIO, OUTGGIO1);
DataObjectSPCSO(32,33,GGIO, OUTGGIO1);
DataObjectSPCSO(33,34,GGIO, OUTGGIO1);
DataObjectSPCSO(34,35,GGIO, OUTGGIO1);
DataObjectSPCSO(35,36,GGIO, OUTGGIO1);
DataObjectSPCSO(36,37,GGIO, OUTGGIO1);
DataObjectSPCSO(37,38,GGIO, OUTGGIO1);
DataObjectSPCSO(38,39,GGIO, OUTGGIO1);
DataObjectSPCSO(39,40,GGIO, OUTGGIO1);
DataObjectSPCSO(40,41,GGIO, OUTGGIO1);
DataObjectSPCSO(41,42,GGIO, OUTGGIO1);
DataObjectSPCSO(42,43,GGIO, OUTGGIO1);
DataObjectSPCSO(43,44,GGIO, OUTGGIO1);
DataObjectSPCSO(44,45,GGIO, OUTGGIO1);
DataObjectSPCSO(45,46,GGIO, OUTGGIO1);
DataObjectSPCSO(46,47,GGIO, OUTGGIO1);
DataObjectSPCSO(47,48,GGIO, OUTGGIO1);
DataObjectSPCSO(48,49,GGIO, OUTGGIO1);
DataObjectSPCSO(49,50,GGIO, OUTGGIO1);
DataObjectSPCSO_end(50,GGIO, OUTGGIO1);

/*************************************************************************
 * LED16GGIO1
 ************************************************************************/
LogicalNode(Generic, GGIO, LEDGGIO1,LED16GGIO1, SSLGGIO1, Ind1);

DataObjectInd(1,2,GGIO, LEDGGIO1);
DataObjectInd(2,3,GGIO, LEDGGIO1);
DataObjectInd(3,4,GGIO, LEDGGIO1);
DataObjectInd(4,5,GGIO, LEDGGIO1);
DataObjectInd(5,6,GGIO, LEDGGIO1);
DataObjectInd(6,7,GGIO, LEDGGIO1);
DataObjectInd(7,8,GGIO, LEDGGIO1);
DataObjectInd(8,9,GGIO, LEDGGIO1);
DataObjectInd(9,10,GGIO, LEDGGIO1);
DataObjectInd(10,11,GGIO, LEDGGIO1);
DataObjectInd(11,12,GGIO, LEDGGIO1);
DataObjectInd(12,13,GGIO, LEDGGIO1);
DataObjectInd_dU(13,14,GGIO, LEDGGIO1);
DataObjectInd_dU(14,15,GGIO, LEDGGIO1);
DataObjectInd_dU(15,16,GGIO, LEDGGIO1);
DataObjectInd_dU_end(16,GGIO, LEDGGIO1);

/*************************************************************************
 * SSL48GGIO1
 ************************************************************************/
LogicalNode(Generic, GGIO, SSLGGIO1, SSL48GGIO1, VLSGGIO1, Ind1);

DataObjectInd(1,2,GGIO, SSLGGIO1);
DataObjectInd(2,3,GGIO, SSLGGIO1);
DataObjectInd(3,4,GGIO, SSLGGIO1);
DataObjectInd(4,5,GGIO, SSLGGIO1);
DataObjectInd(5,6,GGIO, SSLGGIO1);
DataObjectInd(6,7,GGIO, SSLGGIO1);
DataObjectInd(7,8,GGIO, SSLGGIO1);
DataObjectInd(8,9,GGIO, SSLGGIO1);
DataObjectInd(9,10,GGIO, SSLGGIO1);
DataObjectInd(10,11,GGIO, SSLGGIO1);
DataObjectInd(11,12,GGIO, SSLGGIO1);
DataObjectInd(12,13,GGIO, SSLGGIO1);
DataObjectInd(13,14,GGIO, SSLGGIO1);
DataObjectInd(14,15,GGIO, SSLGGIO1);
DataObjectInd(15,16,GGIO, SSLGGIO1);
DataObjectInd(16,17,GGIO, SSLGGIO1);
DataObjectInd(17,18,GGIO, SSLGGIO1);
DataObjectInd(18,19,GGIO, SSLGGIO1);
DataObjectInd(19,20,GGIO, SSLGGIO1);
DataObjectInd(20,21,GGIO, SSLGGIO1);
DataObjectInd(21,22,GGIO, SSLGGIO1);
DataObjectInd(22,23,GGIO, SSLGGIO1);
DataObjectInd(23,24,GGIO, SSLGGIO1);
DataObjectInd(24,25,GGIO, SSLGGIO1);
DataObjectInd(25,26,GGIO, SSLGGIO1);
DataObjectInd(26,27,GGIO, SSLGGIO1);
DataObjectInd(27,28,GGIO, SSLGGIO1);
DataObjectInd(28,29,GGIO, SSLGGIO1);
DataObjectInd(29,30,GGIO, SSLGGIO1);
DataObjectInd(30,31,GGIO, SSLGGIO1);
DataObjectInd(31,32,GGIO, SSLGGIO1);
DataObjectInd(32,33,GGIO, SSLGGIO1);
DataObjectInd(33,34,GGIO, SSLGGIO1);
DataObjectInd(34,35,GGIO, SSLGGIO1);
DataObjectInd(35,36,GGIO, SSLGGIO1);
DataObjectInd(36,37,GGIO, SSLGGIO1);
DataObjectInd(37,38,GGIO, SSLGGIO1);
DataObjectInd(38,39,GGIO, SSLGGIO1);
DataObjectInd(39,40,GGIO, SSLGGIO1);
DataObjectInd(40,41,GGIO, SSLGGIO1);
DataObjectInd(41,42,GGIO, SSLGGIO1);
DataObjectInd(42,43,GGIO, SSLGGIO1);
DataObjectInd(43,44,GGIO, SSLGGIO1);
DataObjectInd(44,45,GGIO, SSLGGIO1);
DataObjectInd(45,46,GGIO, SSLGGIO1);
DataObjectInd(46,47,GGIO, SSLGGIO1);
DataObjectInd(47,48,GGIO, SSLGGIO1);
DataObjectInd_end(48,GGIO, SSLGGIO1);

/*************************************************************************
 * VLS16GGIO1
 ************************************************************************/
LogicalNode(Generic, GGIO, VLSGGIO1,VLS16GGIO1, LSGGIO1, Ind1);

DataObjectInd(1,2,GGIO, VLSGGIO1);
DataObjectInd(2,3,GGIO, VLSGGIO1);
DataObjectInd(3,4,GGIO, VLSGGIO1);
DataObjectInd(4,5,GGIO, VLSGGIO1);
DataObjectInd(5,6,GGIO, VLSGGIO1);
DataObjectInd(6,7,GGIO, VLSGGIO1);
DataObjectInd(7,8,GGIO, VLSGGIO1);
DataObjectInd(8,9,GGIO, VLSGGIO1);
DataObjectInd(9,10,GGIO, VLSGGIO1);
DataObjectInd(10,11,GGIO, VLSGGIO1);
DataObjectInd(11,12,GGIO, VLSGGIO1);
DataObjectInd(12,13,GGIO, VLSGGIO1);
DataObjectInd(13,14,GGIO, VLSGGIO1);
DataObjectInd(14,15,GGIO, VLSGGIO1);
DataObjectInd(15,16,GGIO, VLSGGIO1);
DataObjectInd_end(16,GGIO, VLSGGIO1);

/*************************************************************************
 * LS16GGIO1
 ************************************************************************/
LogicalNode(Generic, GGIO, LSGGIO1,LS16GGIO1, RSTGGIO1, Ind1);

DataObjectInd(1,2,GGIO, LSGGIO1);
DataObjectInd(2,3,GGIO, LSGGIO1);
DataObjectInd(3,4,GGIO, LSGGIO1);
DataObjectInd(4,5,GGIO, LSGGIO1);
DataObjectInd(5,6,GGIO, LSGGIO1);
DataObjectInd(6,7,GGIO, LSGGIO1);
DataObjectInd(7,8,GGIO, LSGGIO1);
DataObjectInd(8,9,GGIO, LSGGIO1);
DataObjectInd(9,10,GGIO, LSGGIO1);
DataObjectInd(10,11,GGIO, LSGGIO1);
DataObjectInd(11,12,GGIO, LSGGIO1);
DataObjectInd(12,13,GGIO, LSGGIO1);
DataObjectInd(13,14,GGIO, LSGGIO1);
DataObjectInd(14,15,GGIO, LSGGIO1);
DataObjectInd(15,16,GGIO, LSGGIO1);
DataObjectInd_end(16,GGIO, LSGGIO1);

/*************************************************************************
 * RST16GGIO1
 ************************************************************************/
LogicalNode_end(Generic, GGIO, RSTGGIO1, RST16GGIO1, RSTGGIO1, Ind1);

DataObjectInd(1,2,GGIO, RSTGGIO1);
DataObjectInd(2,3,GGIO, RSTGGIO1);
DataObjectInd(3,4,GGIO, RSTGGIO1);
DataObjectInd(4,5,GGIO, RSTGGIO1);
DataObjectInd(5,6,GGIO, RSTGGIO1);
DataObjectInd(6,7,GGIO, RSTGGIO1);
DataObjectInd(7,8,GGIO, RSTGGIO1);
DataObjectInd(8,9,GGIO, RSTGGIO1);
DataObjectInd(9,10,GGIO, RSTGGIO1);
DataObjectInd(10,11,GGIO, RSTGGIO1);
DataObjectInd(11,12,GGIO, RSTGGIO1);
DataObjectInd(12,13,GGIO, RSTGGIO1);
DataObjectInd(13,14,GGIO, RSTGGIO1);
DataObjectInd(14,15,GGIO, RSTGGIO1);
DataObjectInd(15,16,GGIO, RSTGGIO1);
DataObjectInd_end(16,GGIO, RSTGGIO1);

/*
LogicalNode iedModel_GGIO_RSTGGIO1 					= { LogicalNodeModelType,   "RST16GGIO1",(ModelNode*)&iedModel_Generic_GGIO,   NULL,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod};

DataObject iedModel_GGIO_RSTGGIO1_Mod 				= { DataObjectModelType,	"Mod",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Mod_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod_t,    				NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Mod_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod_stVal,    			NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Mod_stVal 		= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod_ctlModel,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Mod,    NULL,    												NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_RSTGGIO1_Beh 				= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh_q,    			NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Beh_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh_t,    			NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Beh_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Beh,    NULL,    												NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_RSTGGIO1_Health 			= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_GGIO_RSTGGIO1,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Health_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Health_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_Health_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Health_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Health,    NULL,    											NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_RSTGGIO1_NamPlt 			= { DataObjectModelType,	"NamPlt",   (ModelNode*) &iedModel_GGIO_RSTGGIO1,    (ModelNode*)&iedModel_GGIO_RSTGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_RSTGGIO1_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",   (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt_d,    	NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_NamPlt_d 		= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_GGIO_RSTGGIO1_NamPlt,    NULL,    											NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind1 				= { DataObjectModelType,	"Ind1",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind1_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind1_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind1_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind1,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind2 				= { DataObjectModelType,	"Ind2",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind2_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind2_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind2_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind2,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind3 				= { DataObjectModelType,	"Ind3",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind3_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind3_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind3_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind3,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind4 				= { DataObjectModelType,	"Ind4",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind4_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind4_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind4_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind4,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind5 				= { DataObjectModelType,	"Ind5",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind5_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind5_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind5_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind5,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind6 				= { DataObjectModelType,	"Ind6",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind6_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind6_q	 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind6_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind6,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind7 				= { DataObjectModelType,	"Ind7",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind7_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind7_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind7_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind7,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind8 				= { DataObjectModelType,	"Ind8",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind8_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind8_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind8_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind8,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind9 				= { DataObjectModelType,	"Ind9",		(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind9_stVal	 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind9_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind9_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind9,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind10 			= { DataObjectModelType,	"Ind10",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind10_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind10_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind10_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind10,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind11 			= { DataObjectModelType,	"Ind11",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind11_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN,		TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind11_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind11_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind11,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind12 			= { DataObjectModelType,	"Ind12",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind12_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind12_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY,	 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind12_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind12,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind13 			= { DataObjectModelType,	"Ind13",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind13_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind13_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind13_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind13,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind14 			= { DataObjectModelType,	"Ind14",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind14_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind14_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind14_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind14,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind15 			= { DataObjectModelType,	"Ind15",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind15_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind15_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind15_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind15,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_RSTGGIO1_Ind16 			= { DataObjectModelType,	"Ind16",	(ModelNode*) &iedModel_GGIO_RSTGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind16_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16_q,	NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind16_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16_t,	NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_RSTGGIO1_Ind16_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_RSTGGIO1_Ind16,NULL,											NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,NULL,0};

*/

#endif
