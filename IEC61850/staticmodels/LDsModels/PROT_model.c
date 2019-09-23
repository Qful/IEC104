/*
 * PROT_model.c
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 *
 * *************************************************************************
 * Логический узел LN
 *
 * 5.4.18 LN: измерения Имя: PTOC
 *
 * Описание данного логического узла (LN) приведено в МЭК 61850-5.
 * Данный логический узел используется для моделирования направленной макс.
 * токовой защиты с выдержкой вренени.
 *
 * ************************************************************************
 * Конфигурация файла:
 * 1. указать следующий узел после этого
 * 2. в следующей последовательности узлы с указанием количества (пример #define IPTOC1=0 или IPTOC1=4):
 * 		- IPTOC1 : #define		IPTOC1		6
 */


#include "stdlib.h"
#include "model.h"

#include "PROT_model.h"

extern 	IedModel 		iedModel;

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)

extern LogicalDevice iedModel_Generic_CTRL;

#define PROT_Next_Node &iedModel_Generic_CTRL			// следующий узел после этого


/*************************************************************************
 * Логическое устройство
 *************************************************************************/
LogicalDevice iedModel_Generic_PROT 				= { LogicalDeviceModelType, "PROT",		(ModelNode*) &iedModel,  					(ModelNode*)PROT_Next_Node, (ModelNode*)&iedModel_PROT_LLN0	};

/*************************************************************************
 * LLN0 Информация о логическом устройстве
 *************************************************************************/
LogicalNode iedModel_PROT_LLN0 						= { LogicalNodeModelType,	"LLN0",	    (ModelNode*) &iedModel_Generic_PROT,	   		(ModelNode*) &iedModel_PROT_LPHD1,    			(ModelNode*) &iedModel_PROT_LLN0_Mod};

DataObject iedModel_PROT_LLN0_Mod 					= { DataObjectModelType,	"Mod",	    (ModelNode*) &iedModel_PROT_LLN0,	    		(ModelNode*) &iedModel_PROT_LLN0_Beh,    		(ModelNode*) &iedModel_PROT_LLN0_Mod_q,    0};
DataAttribute iedModel_PROT_LLN0_Mod_q 				= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_LLN0_Mod,    		(ModelNode*) &iedModel_PROT_LLN0_Mod_t,    		NULL,	0,    IEC61850_FC_ST,	IEC61850_QUALITY,    	TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_t 				= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_LLN0_Mod,    		(ModelNode*) &iedModel_PROT_LLN0_Mod_stVal,   	NULL,	0,    IEC61850_FC_ST,	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    		(ModelNode*) &iedModel_PROT_LLN0_Mod_ctlModel,	NULL,	0,    IEC61850_FC_ST,	IEC61850_INT32,    		TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel 		= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_PROT_LLN0_Mod,    		NULL,    										NULL,	0,    IEC61850_FC_CF,	IEC61850_ENUMERATED,	TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Beh 					= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_PROT_LLN0,    			(ModelNode*) &iedModel_PROT_LLN0_Health,    	(ModelNode*) &iedModel_PROT_LLN0_Beh_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Beh_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    		(ModelNode*) &iedModel_PROT_LLN0_Beh_q,    		NULL,	0,    IEC61850_FC_ST,	IEC61850_INT32,    		TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_q 				= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_LLN0_Beh,    		(ModelNode*) &iedModel_PROT_LLN0_Beh_t,    		NULL,	0,    IEC61850_FC_ST,	IEC61850_QUALITY,    	TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_t 				= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_LLN0_Beh,   		NULL,    										NULL,	0,    IEC61850_FC_ST,	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_Health 				= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_PROT_LLN0,    			(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	(ModelNode*) &iedModel_PROT_LLN0_Health_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Health_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_LLN0_Health,    	(ModelNode*) &iedModel_PROT_LLN0_Health_q,    	NULL,	0,    IEC61850_FC_ST,	IEC61850_INT32,    		TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_LLN0_Health,    	(ModelNode*) &iedModel_PROT_LLN0_Health_t,    	NULL,	0,    IEC61850_FC_ST,	IEC61850_QUALITY,    	TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_t			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_LLN0_Health,   		NULL,    										NULL,	0,    IEC61850_FC_ST,	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_NamPlt 				= { DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_PROT_LLN0,    			NULL,    										(ModelNode*) &iedModel_PROT_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor 		= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt_swRev,	NULL,	0,    IEC61850_FC_DC,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev 		= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt_d,    	NULL,	0,    IEC61850_FC_DC,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_d 			= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt_configRev,NULL,	0,    IEC61850_FC_DC,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev	= { DataAttributeModelType,	"configRev",(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt_ldNs,	NULL,	0,    IEC61850_FC_DC,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs 		= { DataAttributeModelType,	"ldNs",    	(ModelNode*) &iedModel_PROT_LLN0_NamPlt,    	NULL,    										NULL,	0,    IEC61850_FC_EX,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * LPHD1 Информация о физическом устройстве
 *************************************************************************/
LogicalNode iedModel_PROT_LPHD1 					= { LogicalNodeModelType,	"LPHD1",	(ModelNode*) &iedModel_Generic_PROT,    		(ModelNode*) &iedModel_PROT_IPTOC1,    			(ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

DataObject iedModel_PROT_LPHD1_PhyNam 				= { DataObjectModelType,	"PhyNam",	(ModelNode*) &iedModel_PROT_LPHD1,    			(ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor		= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_PROT_LPHD1_PhyNam,		NULL,    										NULL,	0,    	IEC61850_FC_DC,	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_PhyHealth			= { DataObjectModelType,	"PhyHealth",(ModelNode*) &iedModel_PROT_LPHD1,    			(ModelNode*) &iedModel_PROT_LPHD1_Proxy,		(ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,	(ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_q,	NULL,	0,    	IEC61850_FC_ST,	IEC61850_INT32,    		TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_t,	NULL,	0,    	IEC61850_FC_ST,	IEC61850_QUALITY,    	TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    NULL,    										NULL,	0,    	IEC61850_FC_ST,	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LPHD1_Proxy 				= { DataObjectModelType,	"Proxy",    (ModelNode*) &iedModel_PROT_LPHD1,    			NULL,    										(ModelNode*) &iedModel_PROT_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal 		= { DataAttributeModelType,	"stVal", 	(ModelNode*) &iedModel_PROT_LPHD1_Proxy, 		(ModelNode*) &iedModel_PROT_LPHD1_Proxy_q, 		NULL,	0, 		IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_PROT_LPHD1_Proxy_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_LPHD1_Proxy,    	(ModelNode*) &iedModel_PROT_LPHD1_Proxy_t,    	NULL,	0,    	IEC61850_FC_ST,	IEC61850_QUALITY,    	TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_LPHD1_Proxy,    	NULL,    										NULL,	0,    	IEC61850_FC_ST,	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,    NULL,    0};

/*******************************************************
 * IPTOC1 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC1 					= { LogicalNodeModelType,    "IPTOC1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod};

DataObject iedModel_PROT_IPTOC1_Mod 				= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) &iedModel_PROT_IPTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Mod_stVal		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC1_Beh 				= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_stVal		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IPTOC1_Beh,    (ModelNode*) &iedModel_PROT_IPTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Beh_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IPTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC1_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    (ModelNode*) &iedModel_PROT_IPTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Health_t	 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC1,    (ModelNode*) &iedModel_PROT_IPTOC1_Str, (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC1_Str 	 			= { DataObjectModelType,    "Str",  	(ModelNode*) &iedModel_PROT_IPTOC1,  		(ModelNode*)&iedModel_PROT_IPTOC1_Op, (ModelNode*) &iedModel_PROT_IPTOC1_Str_general,0};
DataAttribute iedModel_PROT_IPTOC1_Str_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_IPTOC1_Str,  	(ModelNode*) &iedModel_PROT_IPTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral	= { DataAttributeModelType,	"dirGeneral",(ModelNode*) &iedModel_PROT_IPTOC1_Str, 	(ModelNode*) &iedModel_PROT_IPTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IPTOC1_Str,  	(ModelNode*) &iedModel_PROT_IPTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Str_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IPTOC1_Str,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC1_Op 	 				= { DataObjectModelType,	"Op",  		(ModelNode*) &iedModel_PROT_IPTOC1,  		(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC1_Op_general,0};
DataAttribute iedModel_PROT_IPTOC1_Op_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_IPTOC1_Op,  	(ModelNode*) &iedModel_PROT_IPTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_IPTOC1_Op,  	(ModelNode*) &iedModel_PROT_IPTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC1_Op_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_IPTOC1_Op,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * IPTOC2 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC2 					= { LogicalNodeModelType,    "IPTOC2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod};

DataObject iedModel_PROT_IPTOC2_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) &iedModel_PROT_IPTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC2_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    (ModelNode*) &iedModel_PROT_IPTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC2_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    (ModelNode*) &iedModel_PROT_IPTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC2,    (ModelNode*) &iedModel_PROT_IPTOC2_Str, (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC2_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)&iedModel_PROT_IPTOC2_Op, (ModelNode*) &iedModel_PROT_IPTOC2_Str_general,0};
DataAttribute iedModel_PROT_IPTOC2_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  (ModelNode*) &iedModel_PROT_IPTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC2_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC2_Op_general,0};
DataAttribute iedModel_PROT_IPTOC2_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  (ModelNode*) &iedModel_PROT_IPTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC2_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * IPTOC3 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC3 					= { LogicalNodeModelType,    "IPTOC3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod};

DataObject iedModel_PROT_IPTOC3_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) &iedModel_PROT_IPTOC3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC3_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    (ModelNode*) &iedModel_PROT_IPTOC3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC3_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC3_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    (ModelNode*) &iedModel_PROT_IPTOC3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC3_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC3,    (ModelNode*) &iedModel_PROT_IPTOC3_Str, (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC3_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)&iedModel_PROT_IPTOC3_Op, (ModelNode*) &iedModel_PROT_IPTOC3_Str_general,0};
DataAttribute iedModel_PROT_IPTOC3_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  (ModelNode*) &iedModel_PROT_IPTOC3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC3_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC3_Op_general,0};
DataAttribute iedModel_PROT_IPTOC3_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  (ModelNode*) &iedModel_PROT_IPTOC3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC3_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * IPTOC4 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC4 					= { LogicalNodeModelType,    "IPTOC4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod};

DataObject iedModel_PROT_IPTOC4_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) &iedModel_PROT_IPTOC4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC4_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    (ModelNode*) &iedModel_PROT_IPTOC4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC4_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC4_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    (ModelNode*) &iedModel_PROT_IPTOC4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC4_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC4,    (ModelNode*) &iedModel_PROT_IPTOC4_Str, (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC4_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)&iedModel_PROT_IPTOC4_Op, (ModelNode*) &iedModel_PROT_IPTOC4_Str_general,0};
DataAttribute iedModel_PROT_IPTOC4_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral	={ DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  (ModelNode*) &iedModel_PROT_IPTOC4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC4_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC4_Op_general,0};
DataAttribute iedModel_PROT_IPTOC4_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  (ModelNode*) &iedModel_PROT_IPTOC4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC4_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * IPTOC5 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC5 					= { LogicalNodeModelType,    "IPTOC5",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod};

DataObject iedModel_PROT_IPTOC5_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) &iedModel_PROT_IPTOC5_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Mod_stVal		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC5_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_stVal		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    (ModelNode*) &iedModel_PROT_IPTOC5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Beh_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC5_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC5_Health_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Health_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    (ModelNode*) &iedModel_PROT_IPTOC5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Health_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IPTOC5_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC5_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC5,    (ModelNode*) &iedModel_PROT_IPTOC5_Str, (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_vendor 	= { DataAttributeModelType, "vendor",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev 	= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_NamPlt_d 		= { DataAttributeModelType, "d",    (ModelNode*) &iedModel_PROT_IPTOC5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC5_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC5,  	(ModelNode*)&iedModel_PROT_IPTOC5_Op, (ModelNode*) &iedModel_PROT_IPTOC5_Str_general,0};
DataAttribute iedModel_PROT_IPTOC5_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC5_Str,  (ModelNode*) &iedModel_PROT_IPTOC5_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC5_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC5_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC5,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC5_Op_general,0};
DataAttribute iedModel_PROT_IPTOC5_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC5_Op,  (ModelNode*) &iedModel_PROT_IPTOC5_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC5_Op,  (ModelNode*) &iedModel_PROT_IPTOC5_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC5_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC5_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * IPTOC6 Защита по повышению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTOC6 					= { LogicalNodeModelType,    "IPTOC6",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_IPTUC1,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod};

DataObject iedModel_PROT_IPTOC6_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_q,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) &iedModel_PROT_IPTOC6_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTOC6_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    (ModelNode*) &iedModel_PROT_IPTOC6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC6_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_stVal,0};
DataAttribute iedModel_PROT_IPTOC6_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    (ModelNode*) &iedModel_PROT_IPTOC6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTOC6_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTOC6_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTOC6,    (ModelNode*) &iedModel_PROT_IPTOC6_Str, (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTOC6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTOC6_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTOC6,  	(ModelNode*)&iedModel_PROT_IPTOC6_Op, (ModelNode*) &iedModel_PROT_IPTOC6_Str_general,0};
DataAttribute iedModel_PROT_IPTOC6_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC6_Str,  (ModelNode*) &iedModel_PROT_IPTOC6_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC6_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTOC6_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTOC6,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTOC6_Op_general,0};
DataAttribute iedModel_PROT_IPTOC6_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTOC6_Op,  (ModelNode*) &iedModel_PROT_IPTOC6_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTOC6_Op,  (ModelNode*) &iedModel_PROT_IPTOC6_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTOC6_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTOC6_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * IPTUC1 Защита по понинижению тока
 *******************************************************/
LogicalNode iedModel_PROT_IPTUC1 					= { LogicalNodeModelType,    "IPTUC1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_I20PTOC1,    (ModelNode*) &iedModel_PROT_IPTUC1_Mod};

DataObject iedModel_PROT_IPTUC1_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IPTUC1,    (ModelNode*) &iedModel_PROT_IPTUC1_Beh,    (ModelNode*) &iedModel_PROT_IPTUC1_Mod_q,0};
DataAttribute iedModel_PROT_IPTUC1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTUC1_Mod,    (ModelNode*) &iedModel_PROT_IPTUC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTUC1_Mod,    (ModelNode*) &iedModel_PROT_IPTUC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IPTUC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IPTUC1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IPTUC1,    (ModelNode*) &iedModel_PROT_IPTUC1_Health,    (ModelNode*) &iedModel_PROT_IPTUC1_Beh_stVal,0};
DataAttribute iedModel_PROT_IPTUC1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTUC1_Beh,    (ModelNode*) &iedModel_PROT_IPTUC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTUC1_Beh,    (ModelNode*) &iedModel_PROT_IPTUC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTUC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTUC1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IPTUC1,    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTUC1_Health_stVal,0};
DataAttribute iedModel_PROT_IPTUC1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IPTUC1_Health,    (ModelNode*) &iedModel_PROT_IPTUC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IPTUC1_Health,    (ModelNode*) &iedModel_PROT_IPTUC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IPTUC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IPTUC1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IPTUC1,    (ModelNode*) &iedModel_PROT_IPTUC1_Str, (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IPTUC1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt,    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IPTUC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IPTUC1_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IPTUC1,  	(ModelNode*)&iedModel_PROT_IPTUC1_Op, (ModelNode*) &iedModel_PROT_IPTUC1_Str_general,0};
DataAttribute iedModel_PROT_IPTUC1_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTUC1_Str,  (ModelNode*) &iedModel_PROT_IPTUC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IPTUC1_Str,  (ModelNode*) &iedModel_PROT_IPTUC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTUC1_Str,  (ModelNode*) &iedModel_PROT_IPTUC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTUC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IPTUC1_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IPTUC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IPTUC1_Op_general,0};
DataAttribute iedModel_PROT_IPTUC1_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IPTUC1_Op,  (ModelNode*) &iedModel_PROT_IPTUC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IPTUC1_Op,  (ModelNode*) &iedModel_PROT_IPTUC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IPTUC1_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IPTUC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * I20PTOC1 Защита от замыканий на землю и
 * от повышения тока обратной последовательности
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC1 					= { LogicalNodeModelType,    "I20PTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC2,    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod};

DataObject iedModel_PROT_I20PTOC1_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC1,    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I20PTOC1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC1,    (ModelNode*) &iedModel_PROT_I20PTOC1_Health,    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC1_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC1,    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC1_Health,    (ModelNode*) &iedModel_PROT_I20PTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC1_Health,    (ModelNode*) &iedModel_PROT_I20PTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC1_NamPlt	 		= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC1,    (ModelNode*) &iedModel_PROT_I20PTOC1_Str, (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC1_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC1,  	(ModelNode*)&iedModel_PROT_I20PTOC1_Op, (ModelNode*) &iedModel_PROT_I20PTOC1_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC1_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC1_Str,  (ModelNode*) &iedModel_PROT_I20PTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC1_Str,  (ModelNode*) &iedModel_PROT_I20PTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC1_Str,  (ModelNode*) &iedModel_PROT_I20PTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC1_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC1_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC1_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC1_Op,  (ModelNode*) &iedModel_PROT_I20PTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC1_Op,  (ModelNode*) &iedModel_PROT_I20PTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC1_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC2
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC2 					= { LogicalNodeModelType,    "I20PTOC2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC3,    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod};

DataObject iedModel_PROT_I20PTOC2_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC2,    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_I20PTOC2_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I20PTOC2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC2_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC2,    (ModelNode*) &iedModel_PROT_I20PTOC2_Health,    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC2_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC2,    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC2_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC2_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC2_Health,    (ModelNode*) &iedModel_PROT_I20PTOC2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC2_Health,    (ModelNode*) &iedModel_PROT_I20PTOC2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC2_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC2,    (ModelNode*) &iedModel_PROT_I20PTOC2_Str, (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC2_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC2,  	(ModelNode*)&iedModel_PROT_I20PTOC2_Op, (ModelNode*) &iedModel_PROT_I20PTOC2_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC2_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC2_Str,  (ModelNode*) &iedModel_PROT_I20PTOC2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC2_Str,  (ModelNode*) &iedModel_PROT_I20PTOC2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC2_Str,  (ModelNode*) &iedModel_PROT_I20PTOC2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC2_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC2_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC2_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC2_Op,  (ModelNode*) &iedModel_PROT_I20PTOC2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC2_Op,  (ModelNode*) &iedModel_PROT_I20PTOC2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC2_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC3
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC3 					= { LogicalNodeModelType,    "I20PTOC3",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC4,    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod};

DataObject iedModel_PROT_I20PTOC3_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC3,    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I20PTOC3_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC3,    (ModelNode*) &iedModel_PROT_I20PTOC3_Health,    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC3_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC3,    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC3_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC3_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC3_Health,    (ModelNode*) &iedModel_PROT_I20PTOC3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC3_Health,    (ModelNode*) &iedModel_PROT_I20PTOC3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC3_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC3,    (ModelNode*) &iedModel_PROT_I20PTOC3_Str, (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC3_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC3_Str 		 		= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC3,  	(ModelNode*)&iedModel_PROT_I20PTOC3_Op, (ModelNode*) &iedModel_PROT_I20PTOC3_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC3_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC3_Str,  (ModelNode*) &iedModel_PROT_I20PTOC3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC3_Str,  (ModelNode*) &iedModel_PROT_I20PTOC3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC3_Str,  (ModelNode*) &iedModel_PROT_I20PTOC3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC3_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC3_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC3_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC3_Op,  (ModelNode*) &iedModel_PROT_I20PTOC3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC3_Op,  (ModelNode*) &iedModel_PROT_I20PTOC3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC3_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC4
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC4 					= { LogicalNodeModelType,    "I20PTOC4",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC5,    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod};

DataObject iedModel_PROT_I20PTOC4_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC4,    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_I20PTOC4_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I20PTOC4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC4_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC4,    (ModelNode*) &iedModel_PROT_I20PTOC4_Health,    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC4_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC4_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC4,    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC4_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC4_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC4_Health,    (ModelNode*) &iedModel_PROT_I20PTOC4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC4_Health,    (ModelNode*) &iedModel_PROT_I20PTOC4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC4_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC4,    (ModelNode*) &iedModel_PROT_I20PTOC4_Str, (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC4_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC4_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC4,  	(ModelNode*)&iedModel_PROT_I20PTOC4_Op, (ModelNode*) &iedModel_PROT_I20PTOC4_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC4_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC4_Str,  (ModelNode*) &iedModel_PROT_I20PTOC4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC4_Str,  (ModelNode*) &iedModel_PROT_I20PTOC4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC4_Str,  (ModelNode*) &iedModel_PROT_I20PTOC4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC4_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC4_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC4_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC4_Op,  (ModelNode*) &iedModel_PROT_I20PTOC4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC4_Op,  (ModelNode*) &iedModel_PROT_I20PTOC4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC4_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC5
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC5 					= { LogicalNodeModelType,    "I20PTOC5",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC6,    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod};

DataObject iedModel_PROT_I20PTOC5_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC5,    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC5_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC5_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I20PTOC5_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC5,    (ModelNode*) &iedModel_PROT_I20PTOC5_Health,    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC5_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC5_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC5_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC5,    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC5_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC5_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC5_Health,    (ModelNode*) &iedModel_PROT_I20PTOC5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC5_Health,    (ModelNode*) &iedModel_PROT_I20PTOC5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC5_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC5_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC5,    (ModelNode*) &iedModel_PROT_I20PTOC5_Str, (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC5_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC5_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC5,  	(ModelNode*)&iedModel_PROT_I20PTOC5_Op, (ModelNode*) &iedModel_PROT_I20PTOC5_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC5_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC5_Str,  (ModelNode*) &iedModel_PROT_I20PTOC5_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC5_Str,  (ModelNode*) &iedModel_PROT_I20PTOC5_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC5_Str,  (ModelNode*) &iedModel_PROT_I20PTOC5_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC5_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC5_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC5,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC5_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC5_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC5_Op,  (ModelNode*) &iedModel_PROT_I20PTOC5_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC5_Op,  (ModelNode*) &iedModel_PROT_I20PTOC5_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC5_Op_t	 		= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC5_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC6
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC6 					= { LogicalNodeModelType,    "I20PTOC6",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC7,    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod};

DataObject iedModel_PROT_I20PTOC6_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC6,    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC6_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_I20PTOC6_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I20PTOC6_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC6_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC6,    (ModelNode*) &iedModel_PROT_I20PTOC6_Health,    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC6_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC6_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC6_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC6,    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC6_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC6_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC6_Health,    (ModelNode*) &iedModel_PROT_I20PTOC6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC6_Health,    (ModelNode*) &iedModel_PROT_I20PTOC6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC6_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC6_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC6,    (ModelNode*) &iedModel_PROT_I20PTOC6_Str, (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC6_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC6_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC6,  	(ModelNode*)&iedModel_PROT_I20PTOC6_Op, (ModelNode*) &iedModel_PROT_I20PTOC6_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC6_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC6_Str,  (ModelNode*) &iedModel_PROT_I20PTOC6_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC6_Str,  (ModelNode*) &iedModel_PROT_I20PTOC6_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC6_Str,  (ModelNode*) &iedModel_PROT_I20PTOC6_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC6_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC6_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC6,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC6_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC6_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC6_Op,  (ModelNode*) &iedModel_PROT_I20PTOC6_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC6_Op,  (ModelNode*) &iedModel_PROT_I20PTOC6_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC6_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC6_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC7
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC7 					= { LogicalNodeModelType,    "I20PTOC7",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I20PTOC8,    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod};

DataObject iedModel_PROT_I20PTOC7_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC7,    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC7_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Mod_stVal	 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_I20PTOC7_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_I20PTOC7_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC7_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC7,    (ModelNode*) &iedModel_PROT_I20PTOC7_Health,    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC7_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC7_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC7_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC7,    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC7_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC7_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC7_Health,    (ModelNode*) &iedModel_PROT_I20PTOC7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC7_Health,    (ModelNode*) &iedModel_PROT_I20PTOC7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC7_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC7_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC7,    (ModelNode*) &iedModel_PROT_I20PTOC7_Str, (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC7_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC7_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC7,  	(ModelNode*)&iedModel_PROT_I20PTOC7_Op, (ModelNode*) &iedModel_PROT_I20PTOC7_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC7_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC7_Str,  (ModelNode*) &iedModel_PROT_I20PTOC7_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC7_Str,  (ModelNode*) &iedModel_PROT_I20PTOC7_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC7_Str,  (ModelNode*) &iedModel_PROT_I20PTOC7_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC7_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC7_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC7,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC7_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC7_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC7_Op,  (ModelNode*) &iedModel_PROT_I20PTOC7_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC7_Op,  (ModelNode*) &iedModel_PROT_I20PTOC7_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC7_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC7_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * I20PTOC8
 *******************************************************/
LogicalNode iedModel_PROT_I20PTOC8 					= { LogicalNodeModelType,    "I20PTOC8",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_I2I1PTOC1,    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod};

DataObject iedModel_PROT_I20PTOC8_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I20PTOC8,    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod_q,0};
DataAttribute iedModel_PROT_I20PTOC8_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod,    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I20PTOC8_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I20PTOC8_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I20PTOC8,    (ModelNode*) &iedModel_PROT_I20PTOC8_Health,    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh_stVal,0};
DataAttribute iedModel_PROT_I20PTOC8_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh,    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC8_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC8_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I20PTOC8,    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC8_Health_stVal,0};
DataAttribute iedModel_PROT_I20PTOC8_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I20PTOC8_Health,    (ModelNode*) &iedModel_PROT_I20PTOC8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I20PTOC8_Health,    (ModelNode*) &iedModel_PROT_I20PTOC8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I20PTOC8_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I20PTOC8_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I20PTOC8,    (ModelNode*) &iedModel_PROT_I20PTOC8_Str, (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I20PTOC8_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt,    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I20PTOC8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I20PTOC8_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I20PTOC8,  	(ModelNode*)&iedModel_PROT_I20PTOC8_Op, (ModelNode*) &iedModel_PROT_I20PTOC8_Str_general,0};
DataAttribute iedModel_PROT_I20PTOC8_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC8_Str,  (ModelNode*) &iedModel_PROT_I20PTOC8_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I20PTOC8_Str,  (ModelNode*) &iedModel_PROT_I20PTOC8_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC8_Str,  (ModelNode*) &iedModel_PROT_I20PTOC8_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC8_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I20PTOC8_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I20PTOC8,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I20PTOC8_Op_general,0};
DataAttribute iedModel_PROT_I20PTOC8_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I20PTOC8_Op,  (ModelNode*) &iedModel_PROT_I20PTOC8_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I20PTOC8_Op,  (ModelNode*) &iedModel_PROT_I20PTOC8_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I20PTOC8_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I20PTOC8_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * I2I1PTOC1
 *******************************************************/
LogicalNode iedModel_PROT_I2I1PTOC1 				= { LogicalNodeModelType,    "I2I1PTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_IARCPTOC,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod};

DataObject iedModel_PROT_I2I1PTOC1_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_I2I1PTOC1,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod_q,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Mod_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Mod_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Mod_stVal 	= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_I2I1PTOC1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_I2I1PTOC1,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh_stVal,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Beh_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Beh_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Beh_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2I1PTOC1_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_I2I1PTOC1,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health_stVal,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_I2I1PTOC1_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_I2I1PTOC1,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str, (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt,    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_I2I1PTOC1_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_I2I1PTOC1,  	(ModelNode*)&iedModel_PROT_I2I1PTOC1_Op, (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str_general,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Str_dirGeneral= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Str_q 		= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str,  (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Str_t 		= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_I2I1PTOC1_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_I2I1PTOC1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op_general,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op,  (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op,  (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_I2I1PTOC1_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_I2I1PTOC1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * IARCPTOC
 *******************************************************/
LogicalNode iedModel_PROT_IARCPTOC 					= { LogicalNodeModelType,    "IARCPTOC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod};

DataObject iedModel_PROT_IARCPTOC_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IARCPTOC,    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh,    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod_q,0};
DataAttribute iedModel_PROT_IARCPTOC_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod,    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod,    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IARCPTOC_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IARCPTOC_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IARCPTOC,    (ModelNode*) &iedModel_PROT_IARCPTOC_Health,    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh_stVal,0};
DataAttribute iedModel_PROT_IARCPTOC_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh,    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh,    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IARCPTOC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IARCPTOC_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IARCPTOC,    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IARCPTOC_Health_stVal,0};
DataAttribute iedModel_PROT_IARCPTOC_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IARCPTOC_Health,    (ModelNode*) &iedModel_PROT_IARCPTOC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IARCPTOC_Health,    (ModelNode*) &iedModel_PROT_IARCPTOC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IARCPTOC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_IARCPTOC_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IARCPTOC,    (ModelNode*) &iedModel_PROT_IARCPTOC_Str, (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IARCPTOC_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt,    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IARCPTOC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_IARCPTOC_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IARCPTOC,  	(ModelNode*)&iedModel_PROT_IARCPTOC_Op, (ModelNode*) &iedModel_PROT_IARCPTOC_Str_general,0};
DataAttribute iedModel_PROT_IARCPTOC_Str_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IARCPTOC_Str,  (ModelNode*) &iedModel_PROT_IARCPTOC_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IARCPTOC_Str,  (ModelNode*) &iedModel_PROT_IARCPTOC_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IARCPTOC_Str,  (ModelNode*) &iedModel_PROT_IARCPTOC_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IARCPTOC_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_IARCPTOC_Op 	 			= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_IARCPTOC,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IARCPTOC_Op_general,0};
DataAttribute iedModel_PROT_IARCPTOC_Op_general 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IARCPTOC_Op,  (ModelNode*) &iedModel_PROT_IARCPTOC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IARCPTOC_Op,  (ModelNode*) &iedModel_PROT_IARCPTOC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IARCPTOC_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IARCPTOC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * iedModel_PROT_VZGGIO1
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO1 					= { LogicalNodeModelType,   "VZGGIO1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod};

DataObject iedModel_PROT_VZGGIO1_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*)&iedModel_PROT_VZGGIO1_Alm , (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO1,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO2
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO2 					= { LogicalNodeModelType,   "VZGGIO2",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod};

DataObject iedModel_PROT_VZGGIO2_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*)&iedModel_PROT_VZGGIO2_Alm , (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO2,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * iedModel_PROT_VZGGIO3
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO3 					= { LogicalNodeModelType,   "VZGGIO3",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod};

DataObject iedModel_PROT_VZGGIO3_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*)&iedModel_PROT_VZGGIO3_Alm , (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO3,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO4
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO4 					= { LogicalNodeModelType,   "VZGGIO4",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod};

DataObject iedModel_PROT_VZGGIO4_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*)&iedModel_PROT_VZGGIO4_Alm , (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO4,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO5
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO5 					= { LogicalNodeModelType,   "VZGGIO5",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod};

DataObject iedModel_PROT_VZGGIO5_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*)&iedModel_PROT_VZGGIO5_Alm , (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO5,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * iedModel_PROT_VZGGIO6
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO6 					= { LogicalNodeModelType,   "VZGGIO6",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod};

DataObject iedModel_PROT_VZGGIO6_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*)&iedModel_PROT_VZGGIO6_Alm , (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO6,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO7
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO7 					= { LogicalNodeModelType,   "VZGGIO7",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod};

DataObject iedModel_PROT_VZGGIO7_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*)&iedModel_PROT_VZGGIO7_Alm , (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO7,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO8
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO8 					= { LogicalNodeModelType,   "VZGGIO8",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod};

DataObject iedModel_PROT_VZGGIO8_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*)&iedModel_PROT_VZGGIO8_Alm , (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO8,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO9
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO9 					= { LogicalNodeModelType,   "VZGGIO9",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod};

DataObject iedModel_PROT_VZGGIO9_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO9_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*)&iedModel_PROT_VZGGIO9_Alm , (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO9,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO10
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO10 					= { LogicalNodeModelType,   "VZGGIO10",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod};

DataObject iedModel_PROT_VZGGIO10_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO10_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*)&iedModel_PROT_VZGGIO10_Alm , (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO10,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO11
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO11 					= { LogicalNodeModelType,   "VZGGIO11",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod};

DataObject iedModel_PROT_VZGGIO11_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO11_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*)&iedModel_PROT_VZGGIO11_Alm , (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO11,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO12
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO12 					= { LogicalNodeModelType,   "VZGGIO12",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod};

DataObject iedModel_PROT_VZGGIO12_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO12_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*)&iedModel_PROT_VZGGIO12_Alm , (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO12,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO13
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO13 					= { LogicalNodeModelType,   "VZGGIO13",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod};

DataObject iedModel_PROT_VZGGIO13_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO13_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*)&iedModel_PROT_VZGGIO13_Alm , (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Alm				= { DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO13,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal		= { DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_q			= { DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_t			= { DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO14
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO14 					= { LogicalNodeModelType,   "VZGGIO14",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod};

DataObject iedModel_PROT_VZGGIO14_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO14_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*)&iedModel_PROT_VZGGIO14_Alm , (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Alm 				= {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO14,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal 		= {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_q 			= {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_t 			= {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO15
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO15 					= { LogicalNodeModelType,   "VZGGIO15",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod};

DataObject iedModel_PROT_VZGGIO15_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Beh				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Health			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_stVal	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO15_NamPlt			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*)&iedModel_PROT_VZGGIO15_Alm , (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Alm 				= {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO15,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal 		= {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_q 			= {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_t 			= {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO16
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO16 					= { LogicalNodeModelType,   "VZGGIO16",    	(ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod};

DataObject iedModel_PROT_VZGGIO16_Mod 				= { DataObjectModelType,	"Mod",    		(ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_q 			= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_t 			= { DataAttributeModelType,	"t",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal 		= { DataAttributeModelType,"stVal",   		(ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Beh 				= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal 		= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_q 			= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_t 			= { DataAttributeModelType,	"t",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Health 			= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_stVal 	= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_q 		= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_t 		= { DataAttributeModelType,	"t",    		(ModelNode*) &iedModel_PROT_VZGGIO16_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO16_NamPlt 			= { DataObjectModelType,	"NamPlt",    	(ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*)&iedModel_PROT_VZGGIO16_Alm , (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_vendor,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",    	(ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    	(ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d 		= { DataAttributeModelType,	"d",   	 		(ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Alm 				= { DataObjectModelType,	"Alm",			(ModelNode*) &iedModel_PROT_VZGGIO16,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal 		= { DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_q 			= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_t 			= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * UPTOV1
 *******************************************************/
LogicalNode iedModel_PROT_UPTOV1 					= { LogicalNodeModelType,    "UPTOV1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod};

DataObject iedModel_PROT_UPTOV1_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) &iedModel_PROT_UPTOV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    (ModelNode*) &iedModel_PROT_UPTOV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    (ModelNode*) &iedModel_PROT_UPTOV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV1,    (ModelNode*) &iedModel_PROT_UPTOV1_Str, (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV1_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV1,  	(ModelNode*)&iedModel_PROT_UPTOV1_Op, (ModelNode*) &iedModel_PROT_UPTOV1_Str_general,0};
DataAttribute iedModel_PROT_UPTOV1_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_q	 		= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV1_Str,  (ModelNode*) &iedModel_PROT_UPTOV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV1_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV1_Op_general,0};
DataAttribute iedModel_PROT_UPTOV1_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV1_Op,  (ModelNode*) &iedModel_PROT_UPTOV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV1_Op,  (ModelNode*) &iedModel_PROT_UPTOV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV1_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTOV2
 *******************************************************/
LogicalNode iedModel_PROT_UPTOV2 					= { LogicalNodeModelType,    "UPTOV2",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod};

DataObject iedModel_PROT_UPTOV2_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) &iedModel_PROT_UPTOV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV2_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    (ModelNode*) &iedModel_PROT_UPTOV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV2_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    (ModelNode*) &iedModel_PROT_UPTOV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV2,    (ModelNode*) &iedModel_PROT_UPTOV2_Str, (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_swRev	 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV2_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV2,  	(ModelNode*)&iedModel_PROT_UPTOV2_Op, (ModelNode*) &iedModel_PROT_UPTOV2_Str_general,0};
DataAttribute iedModel_PROT_UPTOV2_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV2_Str,  (ModelNode*) &iedModel_PROT_UPTOV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV2_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV2_Op_general,0};
DataAttribute iedModel_PROT_UPTOV2_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV2_Op,  (ModelNode*) &iedModel_PROT_UPTOV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV2_Op,  (ModelNode*) &iedModel_PROT_UPTOV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV2_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTOV3
 *******************************************************/
LogicalNode iedModel_PROT_UPTOV3 					= { LogicalNodeModelType,    "UPTOV3",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod};

DataObject iedModel_PROT_UPTOV3_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) &iedModel_PROT_UPTOV3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTOV3_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    (ModelNode*) &iedModel_PROT_UPTOV3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV3_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV3_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    (ModelNode*) &iedModel_PROT_UPTOV3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV3_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV3,    (ModelNode*) &iedModel_PROT_UPTOV3_Str, (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV3_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV3,  	(ModelNode*)&iedModel_PROT_UPTOV3_Op, (ModelNode*) &iedModel_PROT_UPTOV3_Str_general,0};
DataAttribute iedModel_PROT_UPTOV3_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV3_Str,  (ModelNode*) &iedModel_PROT_UPTOV3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV3_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV3_Op_general,0};
DataAttribute iedModel_PROT_UPTOV3_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV3_Op,  (ModelNode*) &iedModel_PROT_UPTOV3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV3_Op,  (ModelNode*) &iedModel_PROT_UPTOV3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV3_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTOV4
 *******************************************************/
LogicalNode iedModel_PROT_UPTOV4 					= { LogicalNodeModelType,    "UPTOV4",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod};

DataObject iedModel_PROT_UPTOV4_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_q,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) &iedModel_PROT_UPTOV4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_UPTOV4_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_UPTOV4_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV4_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    (ModelNode*) &iedModel_PROT_UPTOV4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV4_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_stVal,0};
DataAttribute iedModel_PROT_UPTOV4_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    (ModelNode*) &iedModel_PROT_UPTOV4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTOV4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTOV4_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTOV4,    (ModelNode*) &iedModel_PROT_UPTOV4_Str, (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTOV4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTOV4_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTOV4,  	(ModelNode*)&iedModel_PROT_UPTOV4_Op, (ModelNode*) &iedModel_PROT_UPTOV4_Str_general,0};
DataAttribute iedModel_PROT_UPTOV4_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV4_Str,  (ModelNode*) &iedModel_PROT_UPTOV4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTOV4_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTOV4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTOV4_Op_general,0};
DataAttribute iedModel_PROT_UPTOV4_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTOV4_Op,  (ModelNode*) &iedModel_PROT_UPTOV4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTOV4_Op,  (ModelNode*) &iedModel_PROT_UPTOV4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTOV4_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTOV4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * UPTUV1
 *******************************************************/
LogicalNode iedModel_PROT_UPTUV1 					= { LogicalNodeModelType,    "UPTUV1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod};

DataObject iedModel_PROT_UPTUV1_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) &iedModel_PROT_UPTUV1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    (ModelNode*) &iedModel_PROT_UPTUV1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    (ModelNode*) &iedModel_PROT_UPTUV1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV1,    (ModelNode*) &iedModel_PROT_UPTUV1_Str, (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV1_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV1,  	(ModelNode*)&iedModel_PROT_UPTUV1_Op, (ModelNode*) &iedModel_PROT_UPTUV1_Str_general,0};
DataAttribute iedModel_PROT_UPTUV1_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV1_Str,  (ModelNode*) &iedModel_PROT_UPTUV1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV1_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV1_Op_general,0};
DataAttribute iedModel_PROT_UPTUV1_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV1_Op,  (ModelNode*) &iedModel_PROT_UPTUV1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV1_Op,  (ModelNode*) &iedModel_PROT_UPTUV1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV1_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTUV2
 *******************************************************/
LogicalNode iedModel_PROT_UPTUV2 					= { LogicalNodeModelType,    "UPTUV2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod};

DataObject iedModel_PROT_UPTUV2_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) &iedModel_PROT_UPTUV2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV2_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    (ModelNode*) &iedModel_PROT_UPTUV2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV2_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    (ModelNode*) &iedModel_PROT_UPTUV2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV2,    (ModelNode*) &iedModel_PROT_UPTUV2_Str, (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV2_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV2,  	(ModelNode*)&iedModel_PROT_UPTUV2_Op, (ModelNode*) &iedModel_PROT_UPTUV2_Str_general,0};
DataAttribute iedModel_PROT_UPTUV2_Str_general	 	= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV2_Str,  (ModelNode*) &iedModel_PROT_UPTUV2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV2_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV2_Op_general,0};
DataAttribute iedModel_PROT_UPTUV2_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV2_Op,  (ModelNode*) &iedModel_PROT_UPTUV2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV2_Op,  (ModelNode*) &iedModel_PROT_UPTUV2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV2_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTUV3
 *******************************************************/
LogicalNode iedModel_PROT_UPTUV3 					= { LogicalNodeModelType,    "UPTUV3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod};

DataObject iedModel_PROT_UPTUV3_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) &iedModel_PROT_UPTUV3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV3_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    (ModelNode*) &iedModel_PROT_UPTUV3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV3_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV3_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    (ModelNode*) &iedModel_PROT_UPTUV3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV3_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV3,    (ModelNode*) &iedModel_PROT_UPTUV3_Str, (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV3_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV3,  	(ModelNode*)&iedModel_PROT_UPTUV3_Op, (ModelNode*) &iedModel_PROT_UPTUV3_Str_general,0};
DataAttribute iedModel_PROT_UPTUV3_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV3_Str,  (ModelNode*) &iedModel_PROT_UPTUV3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV3_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV3_Op_general,0};
DataAttribute iedModel_PROT_UPTUV3_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV3_Op,  (ModelNode*) &iedModel_PROT_UPTUV3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV3_Op,  (ModelNode*) &iedModel_PROT_UPTUV3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV3_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * UPTUV4
 *******************************************************/
LogicalNode iedModel_PROT_UPTUV4 					= { LogicalNodeModelType,    "UPTUV4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod};

DataObject iedModel_PROT_UPTUV4_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_q,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) &iedModel_PROT_UPTUV4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_UPTUV4_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_stVal,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    (ModelNode*) &iedModel_PROT_UPTUV4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV4_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_stVal,0};
DataAttribute iedModel_PROT_UPTUV4_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    (ModelNode*) &iedModel_PROT_UPTUV4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_UPTUV4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_UPTUV4_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_UPTUV4,    (ModelNode*) &iedModel_PROT_UPTUV4_Str, (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_UPTUV4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_UPTUV4_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_UPTUV4,  	(ModelNode*)&iedModel_PROT_UPTUV4_Op, (ModelNode*) &iedModel_PROT_UPTUV4_Str_general,0};
DataAttribute iedModel_PROT_UPTUV4_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV4_Str,  (ModelNode*) &iedModel_PROT_UPTUV4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_UPTUV4_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_UPTUV4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_UPTUV4_Op_general,0};
DataAttribute iedModel_PROT_UPTUV4_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_UPTUV4_Op,  (ModelNode*) &iedModel_PROT_UPTUV4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Op_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_UPTUV4_Op,  (ModelNode*) &iedModel_PROT_UPTUV4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_UPTUV4_Op_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_UPTUV4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * PTOF1
 *******************************************************/
LogicalNode iedModel_PROT_PTOF1 					= { LogicalNodeModelType,    "PTOF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF1_Mod};

DataObject iedModel_PROT_PTOF1_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_q,0};
DataAttribute iedModel_PROT_PTOF1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) &iedModel_PROT_PTOF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF1_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF1_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    (ModelNode*) &iedModel_PROT_PTOF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF1_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF1_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    (ModelNode*) &iedModel_PROT_PTOF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF1_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF1,    (ModelNode*) &iedModel_PROT_PTOF1_Str, (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF1_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF1_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF1,  	(ModelNode*)&iedModel_PROT_PTOF1_Op, (ModelNode*) &iedModel_PROT_PTOF1_Str_general,0};
DataAttribute iedModel_PROT_PTOF1_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF1_Str,  (ModelNode*) &iedModel_PROT_PTOF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF1_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF1_Op_general,0};
DataAttribute iedModel_PROT_PTOF1_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF1_Op,  (ModelNode*) &iedModel_PROT_PTOF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF1_Op,  (ModelNode*) &iedModel_PROT_PTOF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF1_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTOF2
 *******************************************************/
LogicalNode iedModel_PROT_PTOF2						= { LogicalNodeModelType,    "PTOF2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF2_Mod};

DataObject iedModel_PROT_PTOF2_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_q,0};
DataAttribute iedModel_PROT_PTOF2_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) &iedModel_PROT_PTOF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF2_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF2_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    (ModelNode*) &iedModel_PROT_PTOF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF2_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF2_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    (ModelNode*) &iedModel_PROT_PTOF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF2_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF2,    (ModelNode*) &iedModel_PROT_PTOF2_Str, (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF2_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF2_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF2,  	(ModelNode*)&iedModel_PROT_PTOF2_Op, (ModelNode*) &iedModel_PROT_PTOF2_Str_general,0};
DataAttribute iedModel_PROT_PTOF2_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF2_Str,  (ModelNode*) &iedModel_PROT_PTOF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF2_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF2_Op_general,0};
DataAttribute iedModel_PROT_PTOF2_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF2_Op,  (ModelNode*) &iedModel_PROT_PTOF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF2_Op,  (ModelNode*) &iedModel_PROT_PTOF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF2_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTOF3
 *******************************************************/
LogicalNode iedModel_PROT_PTOF3						= { LogicalNodeModelType,    "PTOF3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF3_Mod};

DataObject iedModel_PROT_PTOF3_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_q,0};
DataAttribute iedModel_PROT_PTOF3_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) &iedModel_PROT_PTOF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF3_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF3_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    (ModelNode*) &iedModel_PROT_PTOF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF3_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF3_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    (ModelNode*) &iedModel_PROT_PTOF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF3_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF3,    (ModelNode*) &iedModel_PROT_PTOF3_Str, (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF3_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF3_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF3,  	(ModelNode*)&iedModel_PROT_PTOF3_Op, (ModelNode*) &iedModel_PROT_PTOF3_Str_general,0};
DataAttribute iedModel_PROT_PTOF3_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF3_Str,  (ModelNode*) &iedModel_PROT_PTOF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF3_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF3_Op_general,0};
DataAttribute iedModel_PROT_PTOF3_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF3_Op,  (ModelNode*) &iedModel_PROT_PTOF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF3_Op,  (ModelNode*) &iedModel_PROT_PTOF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF3_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTOF4
 *******************************************************/
LogicalNode iedModel_PROT_PTOF4						= { LogicalNodeModelType,    "PTOF4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTOF4_Mod};

DataObject iedModel_PROT_PTOF4_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_q,0};
DataAttribute iedModel_PROT_PTOF4_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) &iedModel_PROT_PTOF4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTOF4_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_stVal,0};
DataAttribute iedModel_PROT_PTOF4_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    (ModelNode*) &iedModel_PROT_PTOF4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF4_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_Health_stVal,0};
DataAttribute iedModel_PROT_PTOF4_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    (ModelNode*) &iedModel_PROT_PTOF4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTOF4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTOF4_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTOF4,    (ModelNode*) &iedModel_PROT_PTOF4_Str, (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTOF4_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTOF4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTOF4_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTOF4,  	(ModelNode*)&iedModel_PROT_PTOF4_Op, (ModelNode*) &iedModel_PROT_PTOF4_Str_general,0};
DataAttribute iedModel_PROT_PTOF4_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF4_Str,  (ModelNode*) &iedModel_PROT_PTOF4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTOF4_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTOF4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTOF4_Op_general,0};
DataAttribute iedModel_PROT_PTOF4_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTOF4_Op,  (ModelNode*) &iedModel_PROT_PTOF4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTOF4_Op,  (ModelNode*) &iedModel_PROT_PTOF4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTOF4_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTOF4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTUF1
 *******************************************************/
LogicalNode iedModel_PROT_PTUF1						= { LogicalNodeModelType,    "PTUF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF1_Mod};

DataObject iedModel_PROT_PTUF1_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_q,0};
DataAttribute iedModel_PROT_PTUF1_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) &iedModel_PROT_PTUF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF1_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF1_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    (ModelNode*) &iedModel_PROT_PTUF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF1_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF1_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    (ModelNode*) &iedModel_PROT_PTUF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF1_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF1,    (ModelNode*) &iedModel_PROT_PTUF1_Str, (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF1_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF1_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF1,  	(ModelNode*)&iedModel_PROT_PTUF1_Op, (ModelNode*) &iedModel_PROT_PTUF1_Str_general,0};
DataAttribute iedModel_PROT_PTUF1_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF1_Str,  (ModelNode*) &iedModel_PROT_PTUF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF1_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF1_Op_general,0};
DataAttribute iedModel_PROT_PTUF1_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF1_Op,  (ModelNode*) &iedModel_PROT_PTUF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF1_Op,  (ModelNode*) &iedModel_PROT_PTUF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF1_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTUF2
 *******************************************************/
LogicalNode iedModel_PROT_PTUF2						= { LogicalNodeModelType,    "PTUF2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF2_Mod};

DataObject iedModel_PROT_PTUF2_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_q,0};
DataAttribute iedModel_PROT_PTUF2_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) &iedModel_PROT_PTUF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF2_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF2_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    (ModelNode*) &iedModel_PROT_PTUF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF2_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF2_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    (ModelNode*) &iedModel_PROT_PTUF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF2_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF2,    (ModelNode*) &iedModel_PROT_PTUF2_Str, (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF2_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF2_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF2,  	(ModelNode*)&iedModel_PROT_PTUF2_Op, (ModelNode*) &iedModel_PROT_PTUF2_Str_general,0};
DataAttribute iedModel_PROT_PTUF2_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF2_Str,  (ModelNode*) &iedModel_PROT_PTUF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF2_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF2_Op_general,0};
DataAttribute iedModel_PROT_PTUF2_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF2_Op,  (ModelNode*) &iedModel_PROT_PTUF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF2_Op,  (ModelNode*) &iedModel_PROT_PTUF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF2_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTUF3
 *******************************************************/
LogicalNode iedModel_PROT_PTUF3						= { LogicalNodeModelType,    "PTUF3",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF3_Mod};

DataObject iedModel_PROT_PTUF3_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_q,0};
DataAttribute iedModel_PROT_PTUF3_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) &iedModel_PROT_PTUF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF3_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF3_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    (ModelNode*) &iedModel_PROT_PTUF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF3_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF3_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    (ModelNode*) &iedModel_PROT_PTUF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF3_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF3,    (ModelNode*) &iedModel_PROT_PTUF3_Str, (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF3_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF3_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF3,  	(ModelNode*)&iedModel_PROT_PTUF3_Op, (ModelNode*) &iedModel_PROT_PTUF3_Str_general,0};
DataAttribute iedModel_PROT_PTUF3_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF3_Str,  (ModelNode*) &iedModel_PROT_PTUF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF3_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF3,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF3_Op_general,0};
DataAttribute iedModel_PROT_PTUF3_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF3_Op,  (ModelNode*) &iedModel_PROT_PTUF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF3_Op,  (ModelNode*) &iedModel_PROT_PTUF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF3_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PTUF4
 *******************************************************/
LogicalNode iedModel_PROT_PTUF4						= { LogicalNodeModelType,    "PTUF4",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PDPR1,    (ModelNode*) &iedModel_PROT_PTUF4_Mod};

DataObject iedModel_PROT_PTUF4_Mod					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_q,0};
DataAttribute iedModel_PROT_PTUF4_Mod_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Mod_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) &iedModel_PROT_PTUF4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Mod_stVal			= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PTUF4_Beh					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_stVal,0};
DataAttribute iedModel_PROT_PTUF4_Beh_stVal			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Beh_q				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    (ModelNode*) &iedModel_PROT_PTUF4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Beh_t				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF4_Health				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_Health_stVal,0};
DataAttribute iedModel_PROT_PTUF4_Health_stVal		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Health_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    (ModelNode*) &iedModel_PROT_PTUF4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Health_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PTUF4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PTUF4_NamPlt				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PTUF4,    (ModelNode*) &iedModel_PROT_PTUF4_Str, (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_swRev		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PTUF4_NamPlt_d			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PTUF4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PTUF4_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PTUF4,  	(ModelNode*)&iedModel_PROT_PTUF4_Op, (ModelNode*) &iedModel_PROT_PTUF4_Str_general,0};
DataAttribute iedModel_PROT_PTUF4_Str_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_dirGeneral	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF4_Str,  (ModelNode*) &iedModel_PROT_PTUF4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Str_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PTUF4_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PTUF4,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PTUF4_Op_general,0};
DataAttribute iedModel_PROT_PTUF4_Op_general		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PTUF4_Op,  (ModelNode*) &iedModel_PROT_PTUF4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Op_q				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PTUF4_Op,  (ModelNode*) &iedModel_PROT_PTUF4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PTUF4_Op_t				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PTUF4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * PDPR1
 *******************************************************/
LogicalNode iedModel_PROT_PDPR1 					= { LogicalNodeModelType,    "PDPR1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_PDPR2,    (ModelNode*) &iedModel_PROT_PDPR1_Mod};

DataObject iedModel_PROT_PDPR1_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDPR1,    (ModelNode*) &iedModel_PROT_PDPR1_Beh,    (ModelNode*) &iedModel_PROT_PDPR1_Mod_q,0};
DataAttribute iedModel_PROT_PDPR1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR1_Mod,    (ModelNode*) &iedModel_PROT_PDPR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR1_Mod,    (ModelNode*) &iedModel_PROT_PDPR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Mod_stVal	 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDPR1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDPR1_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDPR1,    (ModelNode*) &iedModel_PROT_PDPR1_Health,    (ModelNode*) &iedModel_PROT_PDPR1_Beh_stVal,0};
DataAttribute iedModel_PROT_PDPR1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDPR1_Beh,    (ModelNode*) &iedModel_PROT_PDPR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR1_Beh,    (ModelNode*) &iedModel_PROT_PDPR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDPR1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDPR1,    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR1_Health_stVal,0};
DataAttribute iedModel_PROT_PDPR1_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDPR1_Health,    (ModelNode*) &iedModel_PROT_PDPR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR1_Health,    (ModelNode*) &iedModel_PROT_PDPR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDPR1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDPR1,    (ModelNode*) &iedModel_PROT_PDPR1_Str, (ModelNode*) &iedModel_PROT_PDPR1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDPR1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR1_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR1_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDPR1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PDPR1_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDPR1,  	(ModelNode*)&iedModel_PROT_PDPR1_Op, (ModelNode*) &iedModel_PROT_PDPR1_Str_general,0};
DataAttribute iedModel_PROT_PDPR1_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDPR1_Str,  (ModelNode*) &iedModel_PROT_PDPR1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDPR1_Str,  (ModelNode*) &iedModel_PROT_PDPR1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDPR1_Str,  (ModelNode*) &iedModel_PROT_PDPR1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDPR1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PDPR1_Op 	 				= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PDPR1,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PDPR1_Op_general,0};
DataAttribute iedModel_PROT_PDPR1_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDPR1_Op,  (ModelNode*) &iedModel_PROT_PDPR1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Op_q 				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDPR1_Op,  (ModelNode*) &iedModel_PROT_PDPR1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR1_Op_t 				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDPR1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PDPR2
 *******************************************************/
LogicalNode iedModel_PROT_PDPR2 					= { LogicalNodeModelType,    "PDPR2",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_BLKPTTR1,    (ModelNode*) &iedModel_PROT_PDPR2_Mod};

DataObject iedModel_PROT_PDPR2_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDPR2,    (ModelNode*) &iedModel_PROT_PDPR2_Beh,    (ModelNode*) &iedModel_PROT_PDPR2_Mod_q,0};
DataAttribute iedModel_PROT_PDPR2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR2_Mod,    (ModelNode*) &iedModel_PROT_PDPR2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR2_Mod,    (ModelNode*) &iedModel_PROT_PDPR2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDPR2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDPR2_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDPR2,    (ModelNode*) &iedModel_PROT_PDPR2_Health,    (ModelNode*) &iedModel_PROT_PDPR2_Beh_stVal,0};
DataAttribute iedModel_PROT_PDPR2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDPR2_Beh,    (ModelNode*) &iedModel_PROT_PDPR2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR2_Beh,    (ModelNode*) &iedModel_PROT_PDPR2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDPR2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDPR2,    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR2_Health_stVal,0};
DataAttribute iedModel_PROT_PDPR2_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDPR2_Health,    (ModelNode*) &iedModel_PROT_PDPR2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDPR2_Health,    (ModelNode*) &iedModel_PROT_PDPR2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDPR2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDPR2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDPR2,    (ModelNode*) &iedModel_PROT_PDPR2_Str, (ModelNode*) &iedModel_PROT_PDPR2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDPR2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR2_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt,    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDPR2_NamPlt_d	 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDPR2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_PDPR2_Str					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDPR2,  	(ModelNode*)&iedModel_PROT_PDPR2_Op, (ModelNode*) &iedModel_PROT_PDPR2_Str_general,0};
DataAttribute iedModel_PROT_PDPR2_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDPR2_Str,  (ModelNode*) &iedModel_PROT_PDPR2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDPR2_Str,  (ModelNode*) &iedModel_PROT_PDPR2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDPR2_Str,  (ModelNode*) &iedModel_PROT_PDPR2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDPR2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_PDPR2_Op					= { DataObjectModelType,    		"Op",  (ModelNode*) &iedModel_PROT_PDPR2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_PDPR2_Op_general,0};
DataAttribute iedModel_PROT_PDPR2_Op_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDPR2_Op,  (ModelNode*) &iedModel_PROT_PDPR2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Op_q 				= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDPR2_Op,  (ModelNode*) &iedModel_PROT_PDPR2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDPR2_Op_t 				= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDPR2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * BLKPTTR1
 *******************************************************/
LogicalNode iedModel_PROT_BLKPTTR1 					= { LogicalNodeModelType,   "BLKPTTR1",    (ModelNode*)&iedModel_Generic_PROT,  		(ModelNode*)&iedModel_PROT_QPTTR1,    (ModelNode*) &iedModel_PROT_BLKPTTR1_Mod};

DataObject iedModel_PROT_BLKPTTR1_Mod 				= { DataObjectModelType,    "Mod",    		(ModelNode*) &iedModel_PROT_BLKPTTR1,    	(ModelNode*) &iedModel_PROT_BLKPTTR1_Beh,    (ModelNode*) &iedModel_PROT_BLKPTTR1_Mod_q,0};
DataAttribute iedModel_PROT_BLKPTTR1_Mod_q 			= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Mod,   (ModelNode*) &iedModel_PROT_BLKPTTR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Mod_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Mod,   (ModelNode*) &iedModel_PROT_BLKPTTR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Mod_stVal 		= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_PROT_BLKPTTR1_Mod,   (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BLKPTTR1_Beh 				= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_PROT_BLKPTTR1,    	(ModelNode*) &iedModel_PROT_BLKPTTR1_Health,    (ModelNode*) &iedModel_PROT_BLKPTTR1_Beh_stVal,0};
DataAttribute iedModel_PROT_BLKPTTR1_Beh_stVal 		= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_BLKPTTR1_Beh,   (ModelNode*) &iedModel_PROT_BLKPTTR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Beh_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Beh,   (ModelNode*) &iedModel_PROT_BLKPTTR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Beh_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Beh,   NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_BLKPTTR1_Health 			= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_PROT_BLKPTTR1,    	(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt,    (ModelNode*) &iedModel_PROT_BLKPTTR1_Health_stVal,0};
DataAttribute iedModel_PROT_BLKPTTR1_Health_stVal 	= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_BLKPTTR1_Health,(ModelNode*) &iedModel_PROT_BLKPTTR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Health_q 		= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Health,(ModelNode*) &iedModel_PROT_BLKPTTR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Health_t 		= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Health,NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_BLKPTTR1_NamPlt 			= { DataObjectModelType,    "NamPlt",    	(ModelNode*) &iedModel_PROT_BLKPTTR1,    	(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",    	(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt,(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_swRev 	= { DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt,(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_NamPlt_d 		= { DataAttributeModelType, "d",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_NamPlt,NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_BLKPTTR1_TmpRI 			= { DataObjectModelType, 	"TmpRI", 		(ModelNode*) &iedModel_PROT_BLKPTTR1, 		(ModelNode*) &iedModel_PROT_BLKPTTR1_Op, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_mag, 0 };
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_mag 		= { DataAttributeModelType, "mag", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_instMag, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_mag_f 	= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_instMag 	= { DataAttributeModelType, "instMag", 		(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI,(ModelNode*)&iedModel_PROT_BLKPTTR1_TmpRI_q, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_instMag_f= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_q 		= { DataAttributeModelType, "q", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_t 		= { DataAttributeModelType, "t", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_db 		= { DataAttributeModelType, "db", 			(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_BLKPTTR1_TmpRI_zeroDb 	= { DataAttributeModelType, "zeroDb", 		(ModelNode*) &iedModel_PROT_BLKPTTR1_TmpRI, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_BLKPTTR1_Op 	 			= { DataObjectModelType,    "Op",  			(ModelNode*) &iedModel_PROT_BLKPTTR1,  		(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_BLKPTTR1_Op_general,0};
DataAttribute iedModel_PROT_BLKPTTR1_Op_general 	= { DataAttributeModelType,	"general", 		(ModelNode*) &iedModel_PROT_BLKPTTR1_Op,  	(ModelNode*) &iedModel_PROT_BLKPTTR1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Op_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Op,  	(ModelNode*) &iedModel_PROT_BLKPTTR1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_BLKPTTR1_Op_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_BLKPTTR1_Op,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * QPTTR1
 *******************************************************/
LogicalNode iedModel_PROT_QPTTR1 					= { LogicalNodeModelType,   "QPTTR1",    	(ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_QPTTR2,    (ModelNode*) &iedModel_PROT_QPTTR1_Mod};

DataObject iedModel_PROT_QPTTR1_Mod 				= { DataObjectModelType,    "Mod",    		(ModelNode*) &iedModel_PROT_QPTTR1,    (ModelNode*) &iedModel_PROT_QPTTR1_Beh,    (ModelNode*) &iedModel_PROT_QPTTR1_Mod_q,0};
DataAttribute iedModel_PROT_QPTTR1_Mod_q 			= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_PROT_QPTTR1_Mod,    (ModelNode*) &iedModel_PROT_QPTTR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Mod_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR1_Mod,    (ModelNode*) &iedModel_PROT_QPTTR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Mod_stVal 		= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_PROT_QPTTR1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_QPTTR1_Beh 				= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_PROT_QPTTR1,    (ModelNode*) &iedModel_PROT_QPTTR1_Health,    (ModelNode*) &iedModel_PROT_QPTTR1_Beh_stVal,0};
DataAttribute iedModel_PROT_QPTTR1_Beh_stVal 		= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_QPTTR1_Beh,    (ModelNode*) &iedModel_PROT_QPTTR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Beh_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR1_Beh,    (ModelNode*) &iedModel_PROT_QPTTR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Beh_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_QPTTR1_Health 				= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_PROT_QPTTR1,    (ModelNode*) &iedModel_PROT_QPTTR1_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR1_Health_stVal,0};
DataAttribute iedModel_PROT_QPTTR1_Health_stVal 	= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_QPTTR1_Health,    (ModelNode*) &iedModel_PROT_QPTTR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Health_q 		= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR1_Health,    (ModelNode*) &iedModel_PROT_QPTTR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Health_t 		= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_QPTTR1_NamPlt 				= { DataObjectModelType,    "NamPlt",    	(ModelNode*) &iedModel_PROT_QPTTR1,    (ModelNode*) &iedModel_PROT_QPTTR1_TmpRI, (ModelNode*) &iedModel_PROT_QPTTR1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_QPTTR1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",    	(ModelNode*) &iedModel_PROT_QPTTR1_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_NamPlt_swRev 	= { DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_PROT_QPTTR1_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_NamPlt_d 		= { DataAttributeModelType, "d",    		(ModelNode*) &iedModel_PROT_QPTTR1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_QPTTR1_TmpRI 				= { DataObjectModelType, 	"TmpRI", 		(ModelNode*) &iedModel_PROT_QPTTR1, 			(ModelNode*) &iedModel_PROT_QPTTR1_Str, (ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_mag, 0 };
DataAttribute iedModel_PROT_QPTTR1_TmpRI_mag 		= { DataAttributeModelType, "mag", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI, 		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_instMag, (ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_mag_f 		= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_mag, 	NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_instMag 	= { DataAttributeModelType, "instMag", 		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI,		(ModelNode*)&iedModel_PROT_QPTTR1_TmpRI_q, (ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_instMag_f	= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_q 			= { DataAttributeModelType, "q", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI, 		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_t 			= { DataAttributeModelType, "t", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI,  		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_TmpRI_db 		= { DataAttributeModelType, "db", 			(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI, 		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_QPTTR1_TmpRI_zeroDb 	= { DataAttributeModelType, "zeroDb", 		(ModelNode*) &iedModel_PROT_QPTTR1_TmpRI, 		NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// информация о статусе ПУСК
DataObject iedModel_PROT_QPTTR1_Str 	 			= { DataObjectModelType,    "Str",  		(ModelNode*) &iedModel_PROT_QPTTR1,  		(ModelNode*)&iedModel_PROT_QPTTR1_Op, (ModelNode*) &iedModel_PROT_QPTTR1_Str_general,0};
DataAttribute iedModel_PROT_QPTTR1_Str_general 		= { DataAttributeModelType,	"general", 		(ModelNode*) &iedModel_PROT_QPTTR1_Str,  	(ModelNode*) &iedModel_PROT_QPTTR1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Str_dirGeneral 	= { DataAttributeModelType,	"dirGeneral", 	(ModelNode*) &iedModel_PROT_QPTTR1_Str,  	(ModelNode*) &iedModel_PROT_QPTTR1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Str_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR1_Str,  	(ModelNode*) &iedModel_PROT_QPTTR1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Str_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR1_Str,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_QPTTR1_Op 	 				= { DataObjectModelType,    "Op",  			(ModelNode*) &iedModel_PROT_QPTTR1,  		(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_QPTTR1_Op_general,0};
DataAttribute iedModel_PROT_QPTTR1_Op_general 		= { DataAttributeModelType,	"general", 		(ModelNode*) &iedModel_PROT_QPTTR1_Op,  	(ModelNode*) &iedModel_PROT_QPTTR1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Op_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR1_Op,  	(ModelNode*) &iedModel_PROT_QPTTR1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR1_Op_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR1_Op, 	 	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * QPTTR2
 *******************************************************/
LogicalNode iedModel_PROT_QPTTR2 					= { LogicalNodeModelType,   "QPTTR2",    	(ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_RREC1,    (ModelNode*) &iedModel_PROT_QPTTR2_Mod};

DataObject iedModel_PROT_QPTTR2_Mod 				= { DataObjectModelType,    "Mod",    		(ModelNode*) &iedModel_PROT_QPTTR2,    (ModelNode*) &iedModel_PROT_QPTTR2_Beh,    (ModelNode*) &iedModel_PROT_QPTTR2_Mod_q,0};
DataAttribute iedModel_PROT_QPTTR2_Mod_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR2_Mod,    (ModelNode*) &iedModel_PROT_QPTTR2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Mod_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR2_Mod,    (ModelNode*) &iedModel_PROT_QPTTR2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Mod_stVal 		= { DataAttributeModelType,	"stVal",    	(ModelNode*) &iedModel_PROT_QPTTR2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_QPTTR2_Beh 				= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_PROT_QPTTR2,    (ModelNode*) &iedModel_PROT_QPTTR2_Health,    (ModelNode*) &iedModel_PROT_QPTTR2_Beh_stVal,0};
DataAttribute iedModel_PROT_QPTTR2_Beh_stVal 		= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_QPTTR2_Beh,    (ModelNode*) &iedModel_PROT_QPTTR2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Beh_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR2_Beh,    (ModelNode*) &iedModel_PROT_QPTTR2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Beh_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_QPTTR2_Health 				= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_PROT_QPTTR2,    (ModelNode*) &iedModel_PROT_QPTTR2_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR2_Health_stVal,0};
DataAttribute iedModel_PROT_QPTTR2_Health_stVal 	= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_PROT_QPTTR2_Health,    (ModelNode*) &iedModel_PROT_QPTTR2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Health_q 		= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR2_Health,    (ModelNode*) &iedModel_PROT_QPTTR2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Health_t 		= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_QPTTR2_NamPlt 				= { DataObjectModelType,    "NamPlt",    	(ModelNode*) &iedModel_PROT_QPTTR2,    (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI, (ModelNode*) &iedModel_PROT_QPTTR2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_QPTTR2_NamPlt_vendor 	= { DataAttributeModelType, "vendor",    	(ModelNode*) &iedModel_PROT_QPTTR2_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_NamPlt_swRev 	= { DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_PROT_QPTTR2_NamPlt,    (ModelNode*) &iedModel_PROT_QPTTR2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_NamPlt_d 		= { DataAttributeModelType, "d",    		(ModelNode*) &iedModel_PROT_QPTTR2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_QPTTR2_TmpRI 				= { DataObjectModelType, 	"TmpRI", 		(ModelNode*) &iedModel_PROT_QPTTR2, (ModelNode*) &iedModel_PROT_QPTTR2_Str, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_mag, 0 };
DataAttribute iedModel_PROT_QPTTR2_TmpRI_mag 		= { DataAttributeModelType, "mag", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_instMag, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_mag_f 		= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_instMag 	= { DataAttributeModelType, "instMag", 		(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI,(ModelNode*)&iedModel_PROT_QPTTR2_TmpRI_q, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_instMag_f	= { DataAttributeModelType, "f", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_q 			= { DataAttributeModelType, "q", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_t 			= { DataAttributeModelType, "t", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI,  (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_TmpRI_db 		= { DataAttributeModelType, "db", 			(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI, (ModelNode*) &iedModel_PROT_QPTTR2_TmpRI_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_QPTTR2_TmpRI_zeroDb 	= { DataAttributeModelType, "zeroDb", 		(ModelNode*) &iedModel_PROT_QPTTR2_TmpRI, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// информация о статусе ПУСК
DataObject iedModel_PROT_QPTTR2_Str 	 			= { DataObjectModelType,  	"Str",  		(ModelNode*) &iedModel_PROT_QPTTR2,  	(ModelNode*)&iedModel_PROT_QPTTR2_Op, (ModelNode*) &iedModel_PROT_QPTTR2_Str_general,0};
DataAttribute iedModel_PROT_QPTTR2_Str_general 		= { DataAttributeModelType,	"general", 		(ModelNode*) &iedModel_PROT_QPTTR2_Str,  (ModelNode*) &iedModel_PROT_QPTTR2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Str_dirGeneral 	= { DataAttributeModelType,	"dirGeneral", 	(ModelNode*) &iedModel_PROT_QPTTR2_Str,  (ModelNode*) &iedModel_PROT_QPTTR2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Str_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR2_Str,  (ModelNode*) &iedModel_PROT_QPTTR2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Str_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_QPTTR2_Op 	 				= { DataObjectModelType,    "Op",  			(ModelNode*) &iedModel_PROT_QPTTR2,  	(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_QPTTR2_Op_general,0};
DataAttribute iedModel_PROT_QPTTR2_Op_general 		= { DataAttributeModelType,	"general", 		(ModelNode*) &iedModel_PROT_QPTTR2_Op,  (ModelNode*) &iedModel_PROT_QPTTR2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Op_q 			= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_PROT_QPTTR2_Op,  (ModelNode*) &iedModel_PROT_QPTTR2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_QPTTR2_Op_t 			= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_PROT_QPTTR2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * RREC1
 *******************************************************/
LogicalNode iedModel_PROT_RREC1 					= { LogicalNodeModelType,    "RREC1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_RSYN1,    (ModelNode*) &iedModel_PROT_RREC1_Mod};

DataObject iedModel_PROT_RREC1_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_RREC1,    (ModelNode*) &iedModel_PROT_RREC1_Beh,    (ModelNode*) &iedModel_PROT_RREC1_Mod_q,0};
DataAttribute iedModel_PROT_RREC1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC1_Mod,    (ModelNode*) &iedModel_PROT_RREC1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC1_Mod,    (ModelNode*) &iedModel_PROT_RREC1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_RREC1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RREC1_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_RREC1,    (ModelNode*) &iedModel_PROT_RREC1_Health,    (ModelNode*) &iedModel_PROT_RREC1_Beh_stVal,0};
DataAttribute iedModel_PROT_RREC1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RREC1_Beh,    (ModelNode*) &iedModel_PROT_RREC1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC1_Beh,    (ModelNode*) &iedModel_PROT_RREC1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RREC1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_RREC1,    (ModelNode*) &iedModel_PROT_RREC1_NamPlt,    (ModelNode*) &iedModel_PROT_RREC1_Health_stVal,0};
DataAttribute iedModel_PROT_RREC1_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_RREC1_Health,    (ModelNode*) &iedModel_PROT_RREC1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC1_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_RREC1_Health,    (ModelNode*) &iedModel_PROT_RREC1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_RREC1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RREC1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_RREC1,    (ModelNode*) &iedModel_PROT_RREC1_AutoRecSt, (ModelNode*) &iedModel_PROT_RREC1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RREC1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_RREC1_NamPlt,    (ModelNode*) &iedModel_PROT_RREC1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC1_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_RREC1_NamPlt,    (ModelNode*) &iedModel_PROT_RREC1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC1_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_RREC1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_RREC1_AutoRecSt 	 		= { DataObjectModelType,    "AutoRecSt",(ModelNode*) &iedModel_PROT_RREC1,  		(ModelNode*) &iedModel_PROT_RREC1_Op, (ModelNode*) &iedModel_PROT_RREC1_AutoRecSt_stVal,0};
DataAttribute iedModel_PROT_RREC1_AutoRecSt_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_RREC1_AutoRecSt,(ModelNode*) &iedModel_PROT_RREC1_AutoRecSt_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RREC1_AutoRecSt_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_RREC1_AutoRecSt,(ModelNode*) &iedModel_PROT_RREC1_AutoRecSt_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_AutoRecSt_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_RREC1_AutoRecSt,NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_RREC1_Op 	 				= { DataObjectModelType,  	"Op",  		(ModelNode*) &iedModel_PROT_RREC1,  		(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_RREC1_Op_general,0};
DataAttribute iedModel_PROT_RREC1_Op_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RREC1_Op,  		(ModelNode*) &iedModel_PROT_RREC1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Op_q 				= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_RREC1_Op,  		(ModelNode*) &iedModel_PROT_RREC1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RREC1_Op_t 				= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_RREC1_Op,  		NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * RSYN1
 *******************************************************/
LogicalNode iedModel_PROT_RSYN1 					= { LogicalNodeModelType,   "RSYN1",    (ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_PROT_RBRF1,    (ModelNode*) &iedModel_PROT_RSYN1_Mod};

DataObject iedModel_PROT_RSYN1_Mod 					= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_PROT_RSYN1,    (ModelNode*) &iedModel_PROT_RSYN1_Beh,    (ModelNode*) &iedModel_PROT_RSYN1_Mod_q,0};
DataAttribute iedModel_PROT_RSYN1_Mod_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RSYN1_Mod,    (ModelNode*) &iedModel_PROT_RSYN1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Mod_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RSYN1_Mod,    (ModelNode*) &iedModel_PROT_RSYN1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_RSYN1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RSYN1_Beh 					= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_RSYN1,    (ModelNode*) &iedModel_PROT_RSYN1_Health,    (ModelNode*) &iedModel_PROT_RSYN1_Beh_stVal,0};
DataAttribute iedModel_PROT_RSYN1_Beh_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RSYN1_Beh,    (ModelNode*) &iedModel_PROT_RSYN1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Beh_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RSYN1_Beh,    (ModelNode*) &iedModel_PROT_RSYN1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Beh_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RSYN1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RSYN1_Health 				= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_PROT_RSYN1,    (ModelNode*) &iedModel_PROT_RSYN1_NamPlt,    (ModelNode*) &iedModel_PROT_RSYN1_Health_stVal,0};
DataAttribute iedModel_PROT_RSYN1_Health_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RSYN1_Health,    (ModelNode*) &iedModel_PROT_RSYN1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Health_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RSYN1_Health,    (ModelNode*) &iedModel_PROT_RSYN1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Health_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RSYN1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RSYN1_NamPlt 				= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_PROT_RSYN1,    (ModelNode*) &iedModel_PROT_RSYN1_Rel, (ModelNode*) &iedModel_PROT_RSYN1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RSYN1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_PROT_RSYN1_NamPlt,    (ModelNode*) &iedModel_PROT_RSYN1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_NamPlt_swRev 		= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_PROT_RSYN1_NamPlt,    (ModelNode*) &iedModel_PROT_RSYN1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_NamPlt_d 			= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_PROT_RSYN1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе ПУСК
DataObject iedModel_PROT_RSYN1_Rel 	 				= { DataObjectModelType,    "Rel",  	(ModelNode*) &iedModel_PROT_RSYN1,  	(ModelNode*)&iedModel_PROT_RSYN1_DifVCIc, (ModelNode*) &iedModel_PROT_RSYN1_Rel_stVal,0};
DataAttribute iedModel_PROT_RSYN1_Rel_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RSYN1_Rel, 	(ModelNode*) &iedModel_PROT_RSYN1_Rel_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Rel_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RSYN1_Rel,  (ModelNode*) &iedModel_PROT_RSYN1_Rel_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_Rel_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RSYN1_Rel,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// DifVCIc
DataObject iedModel_PROT_RSYN1_DifVCIc 				= { DataObjectModelType, 	"DifVCIc", 	(ModelNode*) &iedModel_PROT_RSYN1, 				(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc, (ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_mag, 0 };
DataAttribute iedModel_PROT_RSYN1_DifVCIc_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc, 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_instMag, (ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_mag, 	NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc,		(ModelNode*)&iedModel_PROT_RSYN1_DifVCIc_q, (ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_instMag_f = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc, 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc,  	(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifVCIc_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc, 		(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_RSYN1_DifVCIc_zeroDb 	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_PROT_RSYN1_DifVCIc, 		NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// DifHzCIc
DataObject iedModel_PROT_RSYN1_DifHzCIc 			= { DataObjectModelType,	"DifHzCIc", (ModelNode*) &iedModel_PROT_RSYN1, 				(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc, (ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_mag, 0 };
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_instMag, (ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_instMag 	= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc,		(ModelNode*)&iedModel_PROT_RSYN1_DifHzCIc_q, (ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc,  	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_RSYN1_DifHzCIc_zeroDb 	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_PROT_RSYN1_DifHzCIc, 	NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

//DifAngCIc
DataObject iedModel_PROT_RSYN1_DifAngCIc 			= { DataObjectModelType, 	"DifAngCIc",(ModelNode*) &iedModel_PROT_RSYN1, 				(ModelNode*) NULL, (ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_mag, 0 };
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_instMag, (ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_mag,NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_instMag = { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc,	(ModelNode*)&iedModel_PROT_RSYN1_DifAngCIc_q, (ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_instMag_f= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc,  	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_db 		= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc, 	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_RSYN1_DifAngCIc_zeroDb 	= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_PROT_RSYN1_DifAngCIc, 	NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


/*******************************************************
 * RBRF1
 *******************************************************/
LogicalNode iedModel_PROT_RBRF1 					= { LogicalNodeModelType,   "RBRF1",    (ModelNode*)&iedModel_Generic_PROT, 		(ModelNode*)&iedModel_PROT_AVRGGIO,    (ModelNode*) &iedModel_PROT_RBRF1_Mod};

DataObject iedModel_PROT_RBRF1_Mod 					= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_PROT_RBRF1,    		(ModelNode*) &iedModel_PROT_RBRF1_Beh,    (ModelNode*) &iedModel_PROT_RBRF1_Mod_q,0};
DataAttribute iedModel_PROT_RBRF1_Mod_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RBRF1_Mod,    	(ModelNode*) &iedModel_PROT_RBRF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Mod_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RBRF1_Mod,    	(ModelNode*) &iedModel_PROT_RBRF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_RBRF1_Mod,    	(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RBRF1_Beh 					= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_RBRF1,    		(ModelNode*) &iedModel_PROT_RBRF1_Health,    (ModelNode*) &iedModel_PROT_RBRF1_Beh_stVal,0};
DataAttribute iedModel_PROT_RBRF1_Beh_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RBRF1_Beh,    	(ModelNode*) &iedModel_PROT_RBRF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Beh_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RBRF1_Beh,    	(ModelNode*) &iedModel_PROT_RBRF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Beh_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RBRF1_Beh,    	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RBRF1_Health 				= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_PROT_RBRF1,    		(ModelNode*) &iedModel_PROT_RBRF1_NamPlt,    (ModelNode*) &iedModel_PROT_RBRF1_Health_stVal,0};
DataAttribute iedModel_PROT_RBRF1_Health_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RBRF1_Health,   (ModelNode*) &iedModel_PROT_RBRF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Health_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RBRF1_Health,   (ModelNode*) &iedModel_PROT_RBRF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_Health_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RBRF1_Health,   NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RBRF1_NamPlt 				= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_PROT_RBRF1,    		(ModelNode*) &iedModel_PROT_RBRF1_OpEx, (ModelNode*) &iedModel_PROT_RBRF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RBRF1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_PROT_RBRF1_NamPlt,   (ModelNode*) &iedModel_PROT_RBRF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF1_NamPlt_swRev 		= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_PROT_RBRF1_NamPlt,   (ModelNode*) &iedModel_PROT_RBRF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RBRF1_NamPlt_d 			= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_PROT_RBRF1_NamPlt,   NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// информация о статусе СРАБАТЫВАНИЕ
DataObject iedModel_PROT_RBRF1_OpEx 	 			= { DataObjectModelType,    "OpEx",  	(ModelNode*) &iedModel_PROT_RBRF1,  		(ModelNode*) &iedModel_PROT_RBRF1_OpIn, (ModelNode*) &iedModel_PROT_RBRF1_OpEx_general,0};
DataAttribute iedModel_PROT_RBRF1_OpEx_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RBRF1_OpEx,  	(ModelNode*) &iedModel_PROT_RBRF1_OpEx_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_OpEx_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RBRF1_OpEx,  	(ModelNode*) &iedModel_PROT_RBRF1_OpEx_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_OpEx_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RBRF1_OpEx,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RBRF1_OpIn 	 			= { DataObjectModelType,    "OpIn",  	(ModelNode*) &iedModel_PROT_RBRF1,  		(ModelNode*) NULL, (ModelNode*) &iedModel_PROT_RBRF1_OpIn_general,0};
DataAttribute iedModel_PROT_RBRF1_OpIn_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RBRF1_OpIn,  	(ModelNode*) &iedModel_PROT_RBRF1_OpIn_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_OpIn_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RBRF1_OpIn,  	(ModelNode*) &iedModel_PROT_RBRF1_OpIn_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RBRF1_OpIn_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RBRF1_OpIn,  	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


/*******************************************************
 * AVRGGIO1
 *******************************************************/
LogicalNode iedModel_PROT_AVRGGIO 					= { LogicalNodeModelType,   "AVRGGIO1", (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_NBLKGGIO1,    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod};

DataObject iedModel_PROT_AVRGGIO_Mod 				= { DataObjectModelType,  	"Mod",    	(ModelNode*) &iedModel_PROT_AVRGGIO,    	(ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod_q,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Mod,	(ModelNode*) &iedModel_PROT_AVRGGIO_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Mod,	(ModelNode*) &iedModel_PROT_AVRGGIO_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Mod_stVal 		= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_PROT_AVRGGIO_Mod,	(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_AVRGGIO_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_AVRGGIO_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_AVRGGIO_Beh 				= { DataObjectModelType,	"Beh",    	(ModelNode*) &iedModel_PROT_AVRGGIO,    	(ModelNode*) &iedModel_PROT_AVRGGIO_Health,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    (ModelNode*) &iedModel_PROT_AVRGGIO_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Beh_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_AVRGGIO_Health 			= { DataObjectModelType,    "Health",	(ModelNode*) &iedModel_PROT_AVRGGIO,    	(ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,    (ModelNode*) &iedModel_PROT_AVRGGIO_Health_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_AVRGGIO_Health, (ModelNode*) &iedModel_PROT_AVRGGIO_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Health, (ModelNode*) &iedModel_PROT_AVRGGIO_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_Health_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_AVRGGIO_Health, NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_AVRGGIO_NamPlt 			= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_PROT_AVRGGIO,    	(ModelNode*)&iedModel_PROT_AVRGGIO_IntIn , (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_vendor,0};

DataAttribute iedModel_PROT_AVRGGIO_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",   (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,	(ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,	(ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_NamPlt_d 		= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_PROT_AVRGGIO_NamPlt,	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_AVRGGIO_IntIn 				= {DataObjectModelType,		"IntIn",	(ModelNode*) &iedModel_PROT_AVRGGIO, 		NULL ,(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_stVal,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_stVal 	= {DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,	(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_q,NULL,0,IEC61850_FC_ST,IEC61850_INT32, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_q 		= {DataAttributeModelType,	"q",		(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,	(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_AVRGGIO_IntIn_t 		= {DataAttributeModelType,	"t",		(ModelNode*) &iedModel_PROT_AVRGGIO_IntIn,	NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * NBLKGGIO1
 *******************************************************/
LogicalNode iedModel_PROT_NBLKGGIO1 				= { LogicalNodeModelType,   "NBLKGGIO1",(ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_RPSB1,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod};

DataObject iedModel_PROT_NBLKGGIO1_Mod 				= { DataObjectModelType,	"Mod",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Mod_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod,(ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Mod_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod,(ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Mod_stVal 	= { DataAttributeModelType,"stVal",   	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_NBLKGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_NBLKGGIO1_Beh 				= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Health,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Beh_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Beh_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Beh_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_NBLKGGIO1_Health 			= { DataObjectModelType,    "Health",	(ModelNode*) &iedModel_PROT_NBLKGGIO1,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Health,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Health_q 		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Health,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_Health_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_NBLKGGIO1_NamPlt 			= { DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_PROT_NBLKGGIO1,    (ModelNode*)&iedModel_PROT_NBLKGGIO1_IntIn , (ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_vendor = { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_NamPlt_d 		= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_PROT_NBLKGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_NBLKGGIO1_IntIn 			= { DataObjectModelType,	"IntIn",	(ModelNode*) &iedModel_PROT_NBLKGGIO1, NULL ,(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn_stVal,0};
DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn,(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn_q,NULL,0,IEC61850_FC_ST,IEC61850_INT32, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn,(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_NBLKGGIO1_IntIn_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_PROT_NBLKGGIO1_IntIn,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * RPSB1
 *******************************************************/
LogicalNode iedModel_PROT_RPSB1 					= { LogicalNodeModelType,	"RPSB1",    (ModelNode*)&iedModel_Generic_PROT,  		(ModelNode*)&iedModel_PROT_PDIS1,    (ModelNode*) &iedModel_PROT_RPSB1_Mod};

DataObject iedModel_PROT_RPSB1_Mod	 				= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_PROT_RPSB1,    		(ModelNode*) &iedModel_PROT_RPSB1_Beh,    		(ModelNode*) &iedModel_PROT_RPSB1_Mod_q,0};
DataAttribute iedModel_PROT_RPSB1_Mod_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_Mod,    	(ModelNode*) &iedModel_PROT_RPSB1_Mod_t,   	 	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Mod_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_Mod,    	(ModelNode*) &iedModel_PROT_RPSB1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_PROT_RPSB1_Mod,    	(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_Beh 					= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_RPSB1,    		(ModelNode*) &iedModel_PROT_RPSB1_Health,    	(ModelNode*) &iedModel_PROT_RPSB1_Beh_stVal,0};
DataAttribute iedModel_PROT_RPSB1_Beh_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RPSB1_Beh,    	(ModelNode*) &iedModel_PROT_RPSB1_Beh_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, 		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Beh_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_Beh,    	(ModelNode*) &iedModel_PROT_RPSB1_Beh_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Beh_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_Beh,    	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RPSB1_Health 				= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_PROT_RPSB1,    		(ModelNode*) &iedModel_PROT_RPSB1_NamPlt,    	(ModelNode*) &iedModel_PROT_RPSB1_Health_stVal,0};
DataAttribute iedModel_PROT_RPSB1_Health_stVal 		= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_RPSB1_Health,   (ModelNode*) &iedModel_PROT_RPSB1_Health_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, 		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Health_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_Health,   (ModelNode*) &iedModel_PROT_RPSB1_Health_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Health_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_Health,   NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_RPSB1_NamPlt 				= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_PROT_RPSB1,    		(ModelNode*) &iedModel_PROT_RPSB1_Str, 			(ModelNode*) &iedModel_PROT_RPSB1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_RPSB1_NamPlt_vendor 	= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_PROT_RPSB1_NamPlt,   (ModelNode*) &iedModel_PROT_RPSB1_NamPlt_swRev, NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_NamPlt_swRev 		= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_PROT_RPSB1_NamPlt,   (ModelNode*) &iedModel_PROT_RPSB1_NamPlt_d,    	NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_RPSB1_NamPlt_d 			= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_PROT_RPSB1_NamPlt,   NULL,    										NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_Str 	 				= { DataObjectModelType,    "Str",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn1, 		(ModelNode*) &iedModel_PROT_RPSB1_Str_general,0};
DataAttribute iedModel_PROT_RPSB1_Str_general 		= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_Str,  	(ModelNode*) &iedModel_PROT_RPSB1_Str_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Str_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_Str,  	(ModelNode*) &iedModel_PROT_RPSB1_Str_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_Str_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_Str,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn1 	 			= { DataObjectModelType,    "BlkZn1",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn2, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn1_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn1_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn1,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn1_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED , NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn1_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn1,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn1_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn1_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn1,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn2 	 			= { DataObjectModelType,    "BlkZn2",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn3, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn2_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn2_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn2,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn2_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn2_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn2,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn2_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn2_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn2,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn3 	 			= { DataObjectModelType,    "BlkZn3",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn4, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn3_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn3_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn3,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn3_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn3_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn3,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn3_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn3_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn3,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn4 	 			= { DataObjectModelType,    "BlkZn4",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn5, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn4_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn4_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn4,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn4_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn4_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn4,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn4_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn4_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn4, 	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn5 	 			= { DataObjectModelType,    "BlkZn5",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)&iedModel_PROT_RPSB1_BlkZn6, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn5_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn5_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn5,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn5_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn5_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn5,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn5_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn5_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn5,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_RPSB1_BlkZn6 	 			= { DataObjectModelType,  	"BlkZn6",  	(ModelNode*) &iedModel_PROT_RPSB1,  		(ModelNode*)NULL, (ModelNode*) &iedModel_PROT_RPSB1_BlkZn6_general,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn6_general	= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn6,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn6_q,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn6_q 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn6,  	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn6_t,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_RPSB1_BlkZn6_t 			= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_RPSB1_BlkZn6,  	NULL,    										NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};

/*******************************************************
 * PDIS1
 *******************************************************/
LogicalNode iedModel_PROT_PDIS1 					= { LogicalNodeModelType,    "PDIS1",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_PDIS2,    (ModelNode*) &iedModel_PROT_PDIS1_Mod};

DataObject iedModel_PROT_PDIS1_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS1,    (ModelNode*) &iedModel_PROT_PDIS1_Beh,    (ModelNode*) &iedModel_PROT_PDIS1_Mod_q,0};
DataAttribute iedModel_PROT_PDIS1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS1_Mod,    (ModelNode*) &iedModel_PROT_PDIS1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS1_Mod,    (ModelNode*) &iedModel_PROT_PDIS1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS1_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS1_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS1_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS1,    (ModelNode*) &iedModel_PROT_PDIS1_Health,    (ModelNode*) &iedModel_PROT_PDIS1_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS1_Beh,    (ModelNode*) &iedModel_PROT_PDIS1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS1_Beh,    (ModelNode*) &iedModel_PROT_PDIS1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS1_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS1,    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS1_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS1_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS1_Health,    (ModelNode*) &iedModel_PROT_PDIS1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS1_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS1_Health,    (ModelNode*) &iedModel_PROT_PDIS1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS1_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS1_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS1,    (ModelNode*) &iedModel_PROT_PDIS1_Op, (ModelNode*) &iedModel_PROT_PDIS1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS1_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS1_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS1_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS1,  	(ModelNode*)&iedModel_PROT_PDIS1_Str, (ModelNode*) &iedModel_PROT_PDIS1_Op_general,0};
DataAttribute iedModel_PROT_PDIS1_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS1_Op,  (ModelNode*) &iedModel_PROT_PDIS1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS1_Op,  (ModelNode*) &iedModel_PROT_PDIS1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS1_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS1,  NULL, (ModelNode*) &iedModel_PROT_PDIS1_Str_general,0};
DataAttribute iedModel_PROT_PDIS1_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS1_Str,  (ModelNode*) &iedModel_PROT_PDIS1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS1_Str,  (ModelNode*) &iedModel_PROT_PDIS1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS1_Str,  (ModelNode*) &iedModel_PROT_PDIS1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS1_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PDIS2
 *******************************************************/
LogicalNode iedModel_PROT_PDIS2 					= { LogicalNodeModelType,    "PDIS2",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_PDIS3,    (ModelNode*) &iedModel_PROT_PDIS2_Mod};

DataObject iedModel_PROT_PDIS2_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS2,    (ModelNode*) &iedModel_PROT_PDIS2_Beh,    (ModelNode*) &iedModel_PROT_PDIS2_Mod_q,0};
DataAttribute iedModel_PROT_PDIS2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS2_Mod,    (ModelNode*) &iedModel_PROT_PDIS2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS2_Mod,    (ModelNode*) &iedModel_PROT_PDIS2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS2_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS2_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS2,    (ModelNode*) &iedModel_PROT_PDIS2_Health,    (ModelNode*) &iedModel_PROT_PDIS2_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS2_Beh,    (ModelNode*) &iedModel_PROT_PDIS2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS2_Beh,    (ModelNode*) &iedModel_PROT_PDIS2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS2,    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS2_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS2_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS2_Health,    (ModelNode*) &iedModel_PROT_PDIS2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS2_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS2_Health,    (ModelNode*) &iedModel_PROT_PDIS2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS2_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS2,    (ModelNode*) &iedModel_PROT_PDIS2_Op, (ModelNode*) &iedModel_PROT_PDIS2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS2_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS2_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS2_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS2,  	(ModelNode*)&iedModel_PROT_PDIS2_Str, (ModelNode*) &iedModel_PROT_PDIS2_Op_general,0};
DataAttribute iedModel_PROT_PDIS2_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS2_Op,  (ModelNode*) &iedModel_PROT_PDIS2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS2_Op,  (ModelNode*) &iedModel_PROT_PDIS2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS2_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS2,  NULL, (ModelNode*) &iedModel_PROT_PDIS2_Str_general,0};
DataAttribute iedModel_PROT_PDIS2_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS2_Str,  (ModelNode*) &iedModel_PROT_PDIS2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS2_Str,  (ModelNode*) &iedModel_PROT_PDIS2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS2_Str,  (ModelNode*) &iedModel_PROT_PDIS2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PDIS3
 *******************************************************/
LogicalNode iedModel_PROT_PDIS3 					= { LogicalNodeModelType,    "PDIS3",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_PDIS4,    (ModelNode*) &iedModel_PROT_PDIS3_Mod};

DataObject iedModel_PROT_PDIS3_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS3,    (ModelNode*) &iedModel_PROT_PDIS3_Beh,    (ModelNode*) &iedModel_PROT_PDIS3_Mod_q,0};
DataAttribute iedModel_PROT_PDIS3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS3_Mod,    (ModelNode*) &iedModel_PROT_PDIS3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS3_Mod,    (ModelNode*) &iedModel_PROT_PDIS3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS3_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS3_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS3,    (ModelNode*) &iedModel_PROT_PDIS3_Health,    (ModelNode*) &iedModel_PROT_PDIS3_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS3_Beh,    (ModelNode*) &iedModel_PROT_PDIS3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS3_Beh,    (ModelNode*) &iedModel_PROT_PDIS3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS3_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS3,    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS3_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS3_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS3_Health,    (ModelNode*) &iedModel_PROT_PDIS3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS3_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS3_Health,    (ModelNode*) &iedModel_PROT_PDIS3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS3_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS3_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS3,    (ModelNode*) &iedModel_PROT_PDIS3_Op, (ModelNode*) &iedModel_PROT_PDIS3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS3_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS3_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS3_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS3_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS3,  	(ModelNode*)&iedModel_PROT_PDIS3_Str, (ModelNode*) &iedModel_PROT_PDIS3_Op_general,0};
DataAttribute iedModel_PROT_PDIS3_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS3_Op,  (ModelNode*) &iedModel_PROT_PDIS3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS3_Op,  (ModelNode*) &iedModel_PROT_PDIS3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS3_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS3,  NULL, (ModelNode*) &iedModel_PROT_PDIS3_Str_general,0};
DataAttribute iedModel_PROT_PDIS3_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS3_Str,  (ModelNode*) &iedModel_PROT_PDIS3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS3_Str,  (ModelNode*) &iedModel_PROT_PDIS3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS3_Str,  (ModelNode*) &iedModel_PROT_PDIS3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PDIS4
 *******************************************************/
LogicalNode iedModel_PROT_PDIS4 					= { LogicalNodeModelType,    "PDIS4",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_PDIS5,    (ModelNode*) &iedModel_PROT_PDIS4_Mod};
DataObject iedModel_PROT_PDIS4_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS4,    (ModelNode*) &iedModel_PROT_PDIS4_Beh,    (ModelNode*) &iedModel_PROT_PDIS4_Mod_q,0};
DataAttribute iedModel_PROT_PDIS4_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS4_Mod,    (ModelNode*) &iedModel_PROT_PDIS4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS4_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS4_Mod,    (ModelNode*) &iedModel_PROT_PDIS4_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS4_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS4_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS4_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS4,    (ModelNode*) &iedModel_PROT_PDIS4_Health,    (ModelNode*) &iedModel_PROT_PDIS4_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS4_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS4_Beh,    (ModelNode*) &iedModel_PROT_PDIS4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS4_Beh,    (ModelNode*) &iedModel_PROT_PDIS4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS4_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS4_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS4,    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS4_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS4_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS4_Health,    (ModelNode*) &iedModel_PROT_PDIS4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS4_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS4_Health,    (ModelNode*) &iedModel_PROT_PDIS4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS4_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS4_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS4_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS4,    (ModelNode*) &iedModel_PROT_PDIS4_Op, (ModelNode*) &iedModel_PROT_PDIS4_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS4_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS4_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS4_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS4_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS4,  	(ModelNode*)&iedModel_PROT_PDIS4_Str, (ModelNode*) &iedModel_PROT_PDIS4_Op_general,0};
DataAttribute iedModel_PROT_PDIS4_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS4_Op,  (ModelNode*) &iedModel_PROT_PDIS4_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS4_Op,  (ModelNode*) &iedModel_PROT_PDIS4_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS4_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS4_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS4,  NULL, (ModelNode*) &iedModel_PROT_PDIS4_Str_general,0};
DataAttribute iedModel_PROT_PDIS4_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS4_Str,  (ModelNode*) &iedModel_PROT_PDIS4_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS4_Str,  (ModelNode*) &iedModel_PROT_PDIS4_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS4_Str,  (ModelNode*) &iedModel_PROT_PDIS4_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS4_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS4_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*******************************************************
 * PDIS5
 *******************************************************/
LogicalNode iedModel_PROT_PDIS5 					= { LogicalNodeModelType,    "PDIS5",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_PDIS6,    (ModelNode*) &iedModel_PROT_PDIS5_Mod};
DataObject iedModel_PROT_PDIS5_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS5,    (ModelNode*) &iedModel_PROT_PDIS5_Beh,    (ModelNode*) &iedModel_PROT_PDIS5_Mod_q,0};
DataAttribute iedModel_PROT_PDIS5_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS5_Mod,    (ModelNode*) &iedModel_PROT_PDIS5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS5_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS5_Mod,    (ModelNode*) &iedModel_PROT_PDIS5_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS5_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS5_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS5_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS5,    (ModelNode*) &iedModel_PROT_PDIS5_Health,    (ModelNode*) &iedModel_PROT_PDIS5_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS5_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS5_Beh,    (ModelNode*) &iedModel_PROT_PDIS5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS5_Beh,    (ModelNode*) &iedModel_PROT_PDIS5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS5_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS5_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS5,    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS5_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS5_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS5_Health,    (ModelNode*) &iedModel_PROT_PDIS5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS5_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS5_Health,    (ModelNode*) &iedModel_PROT_PDIS5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS5_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS5_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS5_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS5,    (ModelNode*) &iedModel_PROT_PDIS5_Op, (ModelNode*) &iedModel_PROT_PDIS5_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS5_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS5_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS5_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS5_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS5,  	(ModelNode*)&iedModel_PROT_PDIS5_Str, (ModelNode*) &iedModel_PROT_PDIS5_Op_general,0};
DataAttribute iedModel_PROT_PDIS5_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS5_Op,  (ModelNode*) &iedModel_PROT_PDIS5_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS5_Op,  (ModelNode*) &iedModel_PROT_PDIS5_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS5_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS5_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS5,  NULL, (ModelNode*) &iedModel_PROT_PDIS5_Str_general,0};
DataAttribute iedModel_PROT_PDIS5_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS5_Str,  (ModelNode*) &iedModel_PROT_PDIS5_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS5_Str,  (ModelNode*) &iedModel_PROT_PDIS5_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS5_Str,  (ModelNode*) &iedModel_PROT_PDIS5_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS5_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS5_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
/*******************************************************
 * PDIS6
 *******************************************************/
LogicalNode iedModel_PROT_PDIS6 					= { LogicalNodeModelType,    "PDIS6",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDPDIF,    (ModelNode*) &iedModel_PROT_PDIS6_Mod};
DataObject iedModel_PROT_PDIS6_Mod 					= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_PDIS6,    (ModelNode*) &iedModel_PROT_PDIS6_Beh,    (ModelNode*) &iedModel_PROT_PDIS6_Mod_q,0};
DataAttribute iedModel_PROT_PDIS6_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS6_Mod,    (ModelNode*) &iedModel_PROT_PDIS6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS6_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS6_Mod,    (ModelNode*) &iedModel_PROT_PDIS6_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_PDIS6_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_PDIS6_Mod,    (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS6_Beh 					= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_PDIS6,    (ModelNode*) &iedModel_PROT_PDIS6_Health,    (ModelNode*) &iedModel_PROT_PDIS6_Beh_stVal,0};
DataAttribute iedModel_PROT_PDIS6_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS6_Beh,    (ModelNode*) &iedModel_PROT_PDIS6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS6_Beh,    (ModelNode*) &iedModel_PROT_PDIS6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS6_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS6_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_PDIS6,    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS6_Health_stVal,0};
DataAttribute iedModel_PROT_PDIS6_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_PDIS6_Health,    (ModelNode*) &iedModel_PROT_PDIS6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS6_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_PDIS6_Health,    (ModelNode*) &iedModel_PROT_PDIS6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_PDIS6_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_PDIS6_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS6_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_PDIS6,    (ModelNode*) &iedModel_PROT_PDIS6_Op, (ModelNode*) &iedModel_PROT_PDIS6_NamPlt_vendor,0};
DataAttribute iedModel_PROT_PDIS6_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS6_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt,    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_PDIS6_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_PDIS6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_PDIS6_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_PDIS6,  	(ModelNode*)&iedModel_PROT_PDIS6_Str, (ModelNode*) &iedModel_PROT_PDIS6_Op_general,0};
DataAttribute iedModel_PROT_PDIS6_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_PDIS6_Op,  (ModelNode*) &iedModel_PROT_PDIS6_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Op_q 				= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_PDIS6_Op,  (ModelNode*) &iedModel_PROT_PDIS6_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Op_t 				= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_PDIS6_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_PDIS6_Str 	 				= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_PDIS6,  NULL, (ModelNode*) &iedModel_PROT_PDIS6_Str_general,0};
DataAttribute iedModel_PROT_PDIS6_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_PDIS6_Str,  (ModelNode*) &iedModel_PROT_PDIS6_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_PDIS6_Str,  (ModelNode*) &iedModel_PROT_PDIS6_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_PDIS6_Str,  (ModelNode*) &iedModel_PROT_PDIS6_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_PDIS6_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_PDIS6_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

/*************************************************************************
 * IDPDIF Дифференциальная защита
 *************************************************************************/
LogicalNode iedModel_PROT_IDPDIF 					= { LogicalNodeModelType,   	"IDPDIF1",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDDPDIF,    (ModelNode*) &iedModel_PROT_IDPDIF_Mod};

DataObject iedModel_PROT_IDPDIF_Mod 				= { DataObjectModelType,    	"Mod",    (ModelNode*) &iedModel_PROT_IDPDIF,    (ModelNode*) &iedModel_PROT_IDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF_Mod_q,0};
DataAttribute iedModel_PROT_IDPDIF_Mod_q 			= { DataAttributeModelType, 	"q",    (ModelNode*) &iedModel_PROT_IDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Mod_t 			= { DataAttributeModelType, 	"t",    (ModelNode*) &iedModel_PROT_IDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Mod_stVal 		= { DataAttributeModelType,		"stVal",    (ModelNode*) &iedModel_PROT_IDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDPDIF_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Mod_ctlModel 	= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_PROT_IDPDIF_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDPDIF,    (ModelNode*) &iedModel_PROT_IDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDPDIF_Beh_stVal,0};
DataAttribute iedModel_PROT_IDPDIF_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDPDIF_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDPDIF,    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF_Health_stVal,0};
DataAttribute iedModel_PROT_IDPDIF_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDPDIF_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDPDIF_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDPDIF_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDPDIF,    (ModelNode*) &iedModel_PROT_IDPDIF_Op, (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDPDIF_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDPDIF_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDPDIF_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDPDIF,  	(ModelNode*)&iedModel_PROT_IDPDIF_Str, (ModelNode*) &iedModel_PROT_IDPDIF_Op_general,0};
DataAttribute iedModel_PROT_IDPDIF_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDPDIF_Op,  (ModelNode*) &iedModel_PROT_IDPDIF_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDPDIF_Op,  (ModelNode*) &iedModel_PROT_IDPDIF_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDPDIF_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDPDIF_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDPDIF,  (ModelNode*)&iedModel_PROT_IDPDIF_RstA, (ModelNode*) &iedModel_PROT_IDPDIF_Str_general,0};
DataAttribute iedModel_PROT_IDPDIF_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDPDIF_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDPDIF_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDPDIF_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDPDIF_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};


DataObject iedModel_PROT_IDPDIF_RstA 						= { DataObjectModelType, 	"RstA", (ModelNode*) &iedModel_PROT_IDPDIF, (ModelNode*)&iedModel_PROT_IDPDIF_DifACIc, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, 0 };

DataObject iedModel_PROT_IDPDIF_RstA_phsA 					= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA, (ModelNode*)&iedModel_PROT_IDPDIF_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag_f = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_db 			= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsA_zeroDb 		= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF_RstA_phsB 					= { DataObjectModelType, 	"phsB", (ModelNode*) &iedModel_PROT_IDPDIF_RstA, (ModelNode*)&iedModel_PROT_IDPDIF_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag_f = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, (ModelNode*)&iedModel_PROT_IDPDIF_RstA_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsB_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF_RstA_phsC 					= { DataObjectModelType, 	"phsC", (ModelNode*) &iedModel_PROT_IDPDIF_RstA, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag_f 	= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC, 	(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag_f = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_db 			= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_RstA_phsC_zeroDb 		= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF_RstA_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF_DifACIc 					= { DataObjectModelType, 	"DifAClc", (ModelNode*) &iedModel_PROT_IDPDIF, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, 0 };

DataObject iedModel_PROT_IDPDIF_DifACIc_phsA 					= { DataObjectModelType, 	"phsA", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, 	(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_q, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag_f  = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF_DifACIc_phsB 					= { DataObjectModelType, 	"phsB", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc, (ModelNode*)&iedModel_PROT_IDPDIF_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, 	(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_q, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag_f  = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, (ModelNode*)&iedModel_PROT_IDPDIF_DifACIc_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_PROT_IDPDIF_DifACIc_phsC 					= { DataObjectModelType, 	"phsC", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc, (ModelNode*)NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_cVal, 0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal 			= { DataAttributeModelType, "cVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag 		= { DataAttributeModelType, "mag", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_cVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC, 	(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_q, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal, NULL, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag_f  = { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_q 				= { DataAttributeModelType, "q", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_t 				= { DataAttributeModelType, "t", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC,  (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_db 				= { DataAttributeModelType, "db", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC, (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_PROT_IDPDIF_DifACIc_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", (ModelNode*) &iedModel_PROT_IDPDIF_DifACIc_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * IDDPDIF Дифференциальная токовая отсечка
 *************************************************************************/
LogicalNode iedModel_PROT_IDDPDIF 							= { LogicalNodeModelType,   "IDDPDIF1",	(ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_IDDMPDIF,    (ModelNode*) &iedModel_PROT_IDDPDIF_Mod};

DataObject iedModel_PROT_IDDPDIF_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_PROT_IDDPDIF,    (ModelNode*) &iedModel_PROT_IDDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDPDIF_Mod_q,0};
DataAttribute iedModel_PROT_IDDPDIF_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDPDIF_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDPDIF_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Mod_stVal 				= { DataAttributeModelType, "stVal",   	(ModelNode*) &iedModel_PROT_IDDPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDPDIF_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_PROT_IDDPDIF_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDPDIF_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_PROT_IDDPDIF,    (ModelNode*) &iedModel_PROT_IDDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDPDIF_Beh_stVal,0};
DataAttribute iedModel_PROT_IDDPDIF_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IDDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDPDIF_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDPDIF_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDPDIF_Health 					= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_PROT_IDDPDIF,    (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDPDIF_Health_stVal,0};
DataAttribute iedModel_PROT_IDDPDIF_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_PROT_IDDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDPDIF_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Health_q 				= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDPDIF_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDPDIF_NamPlt 					= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_PROT_IDDPDIF,    (ModelNode*) &iedModel_PROT_IDDPDIF_Op, (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDDPDIF_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_NamPlt_swRev 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_PROT_IDDPDIF_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDPDIF_Op 	 					= { DataObjectModelType,    "Op",  		(ModelNode*) &iedModel_PROT_IDDPDIF,  	(ModelNode*)&iedModel_PROT_IDDPDIF_Str, (ModelNode*) &iedModel_PROT_IDDPDIF_Op_general,0};
DataAttribute iedModel_PROT_IDDPDIF_Op_general 				= { DataAttributeModelType, "general", 	(ModelNode*) &iedModel_PROT_IDDPDIF_Op,  (ModelNode*) &iedModel_PROT_IDDPDIF_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Op_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Op,  (ModelNode*) &iedModel_PROT_IDDPDIF_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Op_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDPDIF_Str 	 					= { DataObjectModelType,    "Str",  	(ModelNode*) &iedModel_PROT_IDDPDIF,  NULL, (ModelNode*) &iedModel_PROT_IDDPDIF_Str_general,0};
DataAttribute iedModel_PROT_IDDPDIF_Str_general 			= { DataAttributeModelType,	"general", 	(ModelNode*) &iedModel_PROT_IDDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDPDIF_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Str_dirGeneral 			= { DataAttributeModelType,	"dirGeneral", (ModelNode*) &iedModel_PROT_IDDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDPDIF_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Str_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDPDIF_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDPDIF_Str_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_PROT_IDDPDIF_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * IDDMPDIF Дифференциальная токовая отсечка по мгнов. значениям
 *************************************************************************/
LogicalNode iedModel_PROT_IDDMPDIF 							= {    LogicalNodeModelType,    "IDDMPDIF1",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_ID0PDIF1,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod};

DataObject iedModel_PROT_IDDMPDIF_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_IDDMPDIF,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod_q,0};
DataAttribute iedModel_PROT_IDDMPDIF_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDMPDIF_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_IDDMPDIF,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh_stVal,0};
DataAttribute iedModel_PROT_IDDMPDIF_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDMPDIF_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_IDDMPDIF,    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health_stVal,0};
DataAttribute iedModel_PROT_IDDMPDIF_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDMPDIF_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_IDDMPDIF,    (ModelNode*) &iedModel_PROT_IDDMPDIF_Op, (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt_vendor,0};
DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt,    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_IDDMPDIF_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDMPDIF_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_IDDMPDIF,  	(ModelNode*)&iedModel_PROT_IDDMPDIF_Str, (ModelNode*) &iedModel_PROT_IDDMPDIF_Op_general,0};
DataAttribute iedModel_PROT_IDDMPDIF_Op_general 			= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_IDDMPDIF_Op,  (ModelNode*) &iedModel_PROT_IDDMPDIF_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Op,  (ModelNode*) &iedModel_PROT_IDDMPDIF_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_IDDMPDIF_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_IDDMPDIF,  NULL, (ModelNode*) &iedModel_PROT_IDDMPDIF_Str_general,0};
DataAttribute iedModel_PROT_IDDMPDIF_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_IDDMPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDMPDIF_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Str_dirGeneral 		= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_IDDMPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDMPDIF_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Str,  (ModelNode*) &iedModel_PROT_IDDMPDIF_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_IDDMPDIF_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_IDDMPDIF_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * ID0PDIF Дифференциальная токовая защита нулевой последовательности
 *************************************************************************/
LogicalNode iedModel_PROT_ID0PDIF1 							= {    LogicalNodeModelType,    "ID0PDIF1",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_ID0PDIF2,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod};

DataObject iedModel_PROT_ID0PDIF1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_ID0PDIF1,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod_q,0};
DataAttribute iedModel_PROT_ID0PDIF1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Mod_ctlModel 		= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_ID0PDIF1,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF1_Beh_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF1_Health 					= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_ID0PDIF1,    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF1_NamPlt 					= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_ID0PDIF1,    (ModelNode*) &iedModel_PROT_ID0PDIF1_Op, (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt_vendor,0};
DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_ID0PDIF1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF1_Op 	 					= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_ID0PDIF1,  	(ModelNode*)&iedModel_PROT_ID0PDIF1_Str, (ModelNode*) &iedModel_PROT_ID0PDIF1_Op_general,0};
DataAttribute iedModel_PROT_ID0PDIF1_Op_general 			= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_ID0PDIF1_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF1_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Op_q 					= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF1_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Op_t 					= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF1_Str 	 					= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_ID0PDIF1,  NULL, (ModelNode*) &iedModel_PROT_ID0PDIF1_Str_general,0};
DataAttribute iedModel_PROT_ID0PDIF1_Str_general 			= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_ID0PDIF1_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF1_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Str_dirGeneral 		= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_ID0PDIF1_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF1_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Str_q 					= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF1_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF1_Str_t 					= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_ID0PDIF1_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//-ID0PDIF2--------------------------------------------------------------------------
LogicalNode iedModel_PROT_ID0PDIF2 					= {    LogicalNodeModelType,    "ID0PDIF2",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_ID0PDIF3,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod};

DataObject iedModel_PROT_ID0PDIF2_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_ID0PDIF2,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod_q,0};
DataAttribute iedModel_PROT_ID0PDIF2_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF2_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_ID0PDIF2,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF2_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF2_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_ID0PDIF2,    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF2_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF2_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_ID0PDIF2,    (ModelNode*) &iedModel_PROT_ID0PDIF2_Op, (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt_vendor,0};
DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_ID0PDIF2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF2_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_ID0PDIF2,  	(ModelNode*)&iedModel_PROT_ID0PDIF2_Str, (ModelNode*) &iedModel_PROT_ID0PDIF2_Op_general,0};
DataAttribute iedModel_PROT_ID0PDIF2_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_ID0PDIF2_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF2_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF2_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF2_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_ID0PDIF2,  NULL, (ModelNode*) &iedModel_PROT_ID0PDIF2_Str_general,0};
DataAttribute iedModel_PROT_ID0PDIF2_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_ID0PDIF2_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF2_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_ID0PDIF2_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF2_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF2_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF2_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_ID0PDIF2_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

//-ID0PDIF3--------------------------------------------------------------------------
LogicalNode iedModel_PROT_ID0PDIF3 					= {    LogicalNodeModelType,    "ID0PDIF3",    (ModelNode*)&iedModel_Generic_PROT,   NULL,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod};

DataObject iedModel_PROT_ID0PDIF3_Mod 				= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_PROT_ID0PDIF3,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod_q,0};
DataAttribute iedModel_PROT_ID0PDIF3_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO,   NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Mod_stVal 		= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF3_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_ID0PDIF3,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF3_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF3_Health 				= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_ID0PDIF3,    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health_stVal,0};
DataAttribute iedModel_PROT_ID0PDIF3_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF3_NamPlt 				= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_ID0PDIF3,    (ModelNode*) &iedModel_PROT_ID0PDIF3_Op, (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt_vendor,0};
DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt,    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_ID0PDIF3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF3_Op 	 				= { DataObjectModelType,    "Op",  (ModelNode*) &iedModel_PROT_ID0PDIF3,  	(ModelNode*)&iedModel_PROT_ID0PDIF3_Str, (ModelNode*) &iedModel_PROT_ID0PDIF3_Op_general,0};
DataAttribute iedModel_PROT_ID0PDIF3_Op_general 		= { DataAttributeModelType, "general", (ModelNode*) &iedModel_PROT_ID0PDIF3_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF3_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Op_q 			= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Op,  (ModelNode*) &iedModel_PROT_ID0PDIF3_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Op_t 			= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_ID0PDIF3_Str 	 			= { DataObjectModelType,    		"Str",  (ModelNode*) &iedModel_PROT_ID0PDIF3,  NULL, (ModelNode*) &iedModel_PROT_ID0PDIF3_Str_general,0};
DataAttribute iedModel_PROT_ID0PDIF3_Str_general 		= { DataAttributeModelType,"general", (ModelNode*) &iedModel_PROT_ID0PDIF3_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF3_Str_dirGeneral,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Str_dirGeneral 	= { DataAttributeModelType,"dirGeneral", (ModelNode*) &iedModel_PROT_ID0PDIF3_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF3_Str_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Str_q 			= { DataAttributeModelType,    		"q",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Str,  (ModelNode*) &iedModel_PROT_ID0PDIF3_Str_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_ID0PDIF3_Str_t 			= { DataAttributeModelType,    		"t",    (ModelNode*) &iedModel_PROT_ID0PDIF3_Str,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_NO, NULL,0};

#endif
