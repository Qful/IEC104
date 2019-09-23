/*
 * CTRL_model.c
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */
#include "stdlib.h"
#include "model.h"

#include "CTRL_model.h"

extern 	IedModel 		iedModel;

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)

extern LogicalDevice iedModel_Generic_MES;

#define CTRL_Next_Node &iedModel_Generic_MES			// следующий узел после LD0




/*************************************************************************
 * Логическое устройство
 *************************************************************************/
LogicalDevice iedModel_Generic_CTRL 						= {	LogicalDeviceModelType, "CTRL",			(ModelNode*)&iedModel, 	(ModelNode*)CTRL_Next_Node, 	(ModelNode*)&iedModel_CTRL_LLN0	};


/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 								= { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,	   (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod 							= { DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q 						= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t 						= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal 					= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel 				= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,	IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh 							= { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal 					= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q 						= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t 						= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health 						= { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt 						= { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_CTRL_LLN0,    NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor 				= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev 				= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d 					= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev 			= { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs 				= { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    NULL,    NULL,    0,	IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * LPHD1 Информация о физическом устройстве
 *************************************************************************/
LogicalNode iedModel_CTRL_LPHD1 							= { LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam 						= { DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth 					= { DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    NULL,    NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy 						= { DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal 				= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_CTRL_LPHD1_Proxy, (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

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

LogicalNode iedModel_CTRL_CSWI1 							= { LogicalNodeModelType,	"CSWI1",   	(ModelNode*) &iedModel_Generic_CTRL,   		(ModelNode*)&iedModel_CTRL_XCBR1,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod};
//Mod
DataObject iedModel_CTRL_CSWI1_Mod 							= { DataObjectModelType,	"Mod",    	(ModelNode*) &iedModel_CTRL_CSWI1,    		(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_q,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod,    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_t,    						NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod,    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_stVal,    					NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod,    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_ctlModel,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel 				= { DataAttributeModelType,	"ctlModel", (ModelNode*) &iedModel_CTRL_CSWI1_Mod, 		(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    				NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper 					= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod,   	NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlVal,    		0,	IEC61850_FC_CO,    IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal 			= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin 			= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent 	= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum 			= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_T,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_INT8U, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T 				= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Test,    			NULL,   0,	IEC61850_FC_CO,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Check,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check 			= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,	NULL,    													NULL,   0,	IEC61850_FC_CO,    IEC61850_CHECK, 			TRG_OPT_NO, 			NULL,0};

//Beh
DataObject iedModel_CTRL_CSWI1_Beh 							= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_CTRL_CSWI1,    		(ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    	(ModelNode*) &iedModel_CTRL_CSWI1_Beh_q,    					NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32, 			TRG_OPT_DATA_CHANGED,	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_q 					= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    	(ModelNode*) &iedModel_CTRL_CSWI1_Beh_t,    						NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_t 					= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    	NULL,    															NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

//Health
DataObject iedModel_CTRL_CSWI1_Health 						= { DataObjectModelType,       "Health",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Health_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_t,    					NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    NULL,    														NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//NamPlt
DataObject iedModel_CTRL_CSWI1_NamPlt 						= { DataObjectModelType,       "NamPlt",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_swRev,    		NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev 				= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_d,    				NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_d 					= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    NULL,    														NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
//Pos
DataObject iedModel_CTRL_CSWI1_Pos 							= { DataObjectModelType,       "Pos",    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_q,    					NULL,   0,	IEC61850_FC_ST,    IEC61850_CODEDENUM, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_t,    						NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_ctlModel,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel 				= { DataAttributeModelType,     "ctlModel",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    				NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper 					= { DataAttributeModelType,    "Oper",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,   NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal,    			0,	IEC61850_FC_CO,    IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal 			= { DataAttributeModelType,    "ctlVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin 			= { DataAttributeModelType,	"origin",   (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent 	= { DataAttributeModelType,	"orIdent",  (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum 			= { DataAttributeModelType,    "ctlNum",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_T,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_INT8U, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T 				= { DataAttributeModelType,    "T",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Test,    			NULL,   0,	IEC61850_FC_CO,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test 			= { DataAttributeModelType,    "Test",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Check,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check 			= { DataAttributeModelType,    "Check",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    NULL,    													NULL,   0,	IEC61850_FC_CO,    IEC61850_CHECK, 			TRG_OPT_NO, 			NULL,0};


/*************************************************************************
 * XCBR Выключатель
 *************************************************************************/
LogicalNode iedModel_CTRL_XCBR1 							= { LogicalNodeModelType,  	"XCBR1",    (ModelNode*) &iedModel_Generic_CTRL,  (ModelNode*) &iedModel_CTRL_PTRC ,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod};
//Mod
DataObject iedModel_CTRL_XCBR1_Mod 							= { DataObjectModelType,    "Mod",     	(ModelNode*) &iedModel_CTRL_XCBR1,     			(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_q,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_t,    				NULL,	0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_stVal,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_ctlModel,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel 				= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper, 				NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper 					= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod,         	NULL,(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlVal,    			0,	IEC61850_FC_CO,    IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal 			= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin 			= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent,NULL,	0,	IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent 	= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,NULL,    													NULL,	0,	IEC61850_FC_CO,    IEC61850_OCTET_STRING_64,TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum 			= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_T,    			NULL,   0,	IEC61850_FC_CO,    IEC61850_INT8U, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T 				= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Test,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Check,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check 			= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	NULL,    													NULL,   0,	IEC61850_FC_CO,    IEC61850_CHECK, 			TRG_OPT_NO, 			NULL,0};
//Beh
DataObject iedModel_CTRL_XCBR1_Beh 							= { DataObjectModelType,    "Beh",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Health,    (ModelNode*) &iedModel_CTRL_XCBR1_Beh_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32, 			TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh, 			NULL, 														NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//Health
DataObject iedModel_CTRL_XCBR1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    (ModelNode*) &iedModel_CTRL_XCBR1_Health_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Health_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    	NULL,    													NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//NamPlt
DataObject iedModel_CTRL_XCBR1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Pos, (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_swRev,    			NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev 				= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_d,    				NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_d 					= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	NULL,    													NULL,   0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 		NULL,0};
//Pos
DataObject iedModel_CTRL_XCBR1_Pos 							= { DataObjectModelType,    "Pos",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*)&iedModel_CTRL_XCBR1_Loc, (ModelNode*) &iedModel_CTRL_XCBR1_Pos_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_CODEDENUM, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_ctlModel,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel 				= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		NULL,    													NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
//Loc
DataObject iedModel_CTRL_XCBR1_Loc 							= { DataObjectModelType,    "Loc",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt, (ModelNode*) &iedModel_CTRL_XCBR1_Loc_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*)NULL,    										NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//OpCnt
DataObject iedModel_CTRL_XCBR1_OpCnt 						= { DataObjectModelType,    "OpCnt",    (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap, (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32U, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*)NULL,    										NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//CBOpCap
DataObject iedModel_CTRL_XCBR1_CBOpCap 						= { DataObjectModelType,    "CBOpCap",  (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn, (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_q,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_INT32U, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q 				= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_t,    			NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*)NULL,    										NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
//BlkOpn
DataObject iedModel_CTRL_XCBR1_BlkOpn 						= { DataObjectModelType,    "BlkOpn",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls, 			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_ctlModel,			NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper, 				NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,   	NULL,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal,   0,	IEC61850_FC_CO,    IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_T,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_INT8U, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Test, 		NULL,   0,	IEC61850_FC_CO,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Check,		NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  NULL,    													NULL,   0,	IEC61850_FC_CO,    IEC61850_CHECK, 			TRG_OPT_NO, 			NULL,0};

//BlkCls
DataObject iedModel_CTRL_XCBR1_BlkCls 						= { DataObjectModelType,    "BlkCls",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_q,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_t,    				NULL,   0,	IEC61850_FC_ST,    IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_ctlModel,    		NULL,   0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    			NULL,   0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 	TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,   	NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal,    		0,	IEC61850_FC_CO,    IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_T,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_INT8U, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Test,    		NULL,   0,	IEC61850_FC_CO,    IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Check,    	NULL,   0,	IEC61850_FC_CO,    IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED,	NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  NULL,    													NULL,   0,	IEC61850_FC_CO,    IEC61850_CHECK, 			TRG_OPT_NO, 			NULL,0};


/*************************************************************************
 * PTRC Условия для отключения при защите
 *************************************************************************/

LogicalNode(Generic, CTRL, PTRC, PTRC1, GGIO1, Op);

DataObject iedModel_CTRL_PTRC_Op 	 						= { DataObjectModelType,    "Op",  		(ModelNode*) &iedModel_CTRL_PTRC,  				NULL, (ModelNode*) &iedModel_CTRL_PTRC_Op_general,0};
DataAttribute iedModel_CTRL_PTRC_Op_general 				= { DataAttributeModelType, "general", 	(ModelNode*) &iedModel_CTRL_PTRC_Op,  			(ModelNode*) &iedModel_CTRL_PTRC_Op_q,    						NULL,    0,	IEC61850_FC_ST,    IEC61850_BOOLEAN, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_q 						= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_PTRC_Op,  			(ModelNode*) &iedModel_CTRL_PTRC_Op_t,    						NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_t 						= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_PTRC_Op,  			NULL,    														NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};


/*************************************************************************
 * GGIO1 управление сигналами
 *************************************************************************/
//LogicalNode_end(Generic, CTRL, GGIO1, GGIO1, NULL, SPCSO1);
LogicalNode(Generic, CTRL, GGIO1, GGIO1, CMD24GGIO1, SPCSO1);
DataObject_CTRL_SPCSO(1,2,CTRL, GGIO1);
DataObject_CTRL_SPCSO(2,3,CTRL, GGIO1);
DataObject_CTRL_SPCSO(3,4,CTRL, GGIO1);
DataObject_CTRL_SPCSO_end(4,CTRL, GGIO1);

/*************************************************************************
 * CMD24GGIO1 управление сигналами
 *************************************************************************/
LogicalNode_end(Generic, CTRL, CMD24GGIO1, CMD24GGIO1, NULL, SPCSO1);
DataObject_CTRL_SPCSO(1,2,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(2,3,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(3,4,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(4,5,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(5,6,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(6,7,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(7,8,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(8,9,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(9,10,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(10,11,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(11,12,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(12,13,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(13,14,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(14,15,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(15,16,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(16,17,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(17,18,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(18,19,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(19,20,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(20,21,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(21,22,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(22,23,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO(23,24,CTRL, CMD24GGIO1);
DataObject_CTRL_SPCSO_end(24,CTRL, CMD24GGIO1);
#endif
