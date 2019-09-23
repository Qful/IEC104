/*
 * LD0_model.c
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */
#include "stdlib.h"
#include "model.h"

#include "LD0_model.h"

extern 	IedModel 		iedModel;

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)

extern LogicalDevice iedModel_Generic_PROT;

#define LD0_Next_Node &iedModel_Generic_PROT			// следующий узел после LD0


/*************************************************************************
 * Логическое устройство
 *************************************************************************/
LogicalDevice iedModel_Generic_LD0 				= { LogicalDeviceModelType,	"LD0",		(ModelNode*) &iedModel,	(ModelNode*)LD0_Next_Node, (ModelNode*)&iedModel_LD0_LLN0 };

/*************************************************************************
 * LLN0 Информация о логическом устройстве
 *************************************************************************/
LogicalNode iedModel_LD0_LLN0 					= { LogicalNodeModelType,	"LLN0",	    (ModelNode*) &iedModel_Generic_LD0,	    	(ModelNode*) &iedModel_LD0_LPHD1,    			(ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod 				= { DataObjectModelType,	"Mod",		(ModelNode*) &iedModel_LD0_LLN0,	    	(ModelNode*) &iedModel_LD0_LLN0_Beh,    		(ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_LD0_LLN0_Mod,    	(ModelNode*) &iedModel_LD0_LLN0_Mod_t,    		NULL,	0,	IEC61850_FC_ST,    	IEC61850_QUALITY,    	TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_LD0_LLN0_Mod,    	(ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,		NULL,	0,	IEC61850_FC_ST,    	IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED,	NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    	(ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,	NULL,	0,	IEC61850_FC_ST,    	IEC61850_INT32,    		TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_LD0_LLN0_Mod,    	NULL,    										NULL,	0,	IEC61850_FC_CF,    	IEC61850_ENUMERATED,	TRG_OPT_NO,    			NULL,    0};

DataObject iedModel_LD0_LLN0_Beh 				= { DataObjectModelType,	"Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    		(ModelNode*) &iedModel_LD0_LLN0_Health,    		(ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    	(ModelNode*) &iedModel_LD0_LLN0_Beh_q,    		NULL,	0,	IEC61850_FC_ST,    	IEC61850_INT32,			TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q 			= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_LD0_LLN0_Beh,    	(ModelNode*) &iedModel_LD0_LLN0_Beh_t,    		NULL,	0,	IEC61850_FC_ST,    	IEC61850_QUALITY,		TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t 			= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_LD0_LLN0_Beh,    	NULL,    										NULL,	0,	IEC61850_FC_ST,    	IEC61850_TIMESTAMP,		TRG_OPT_DATA_CHANGED,	NULL,    0};

DataObject iedModel_LD0_LLN0_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_LD0_LLN0,    		(ModelNode*) &iedModel_LD0_LLN0_NamPlt,    		(ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal 	= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LLN0_Health,		(ModelNode*) &iedModel_LD0_LLN0_Health_q,    	NULL,	0,	IEC61850_FC_ST,    	IEC61850_INT32,			TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_LLN0_Health,		(ModelNode*) &iedModel_LD0_LLN0_Health_t,    	NULL,	0,	IEC61850_FC_ST,    	IEC61850_QUALITY,		TRG_OPT_NO,    			NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_LLN0_Health,		NULL,    										NULL,	0,	IEC61850_FC_ST,    	IEC61850_TIMESTAMP,		TRG_OPT_DATA_CHANGED,	NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_LD0_LLN0,    		NULL,    										(ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_LD0_LLN0_NamPlt,		(ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,	NULL,	0,	IEC61850_FC_DC,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,	NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,		(ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    	NULL,	0,	IEC61850_FC_DC,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,	NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_LD0_LLN0_NamPlt,		(ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,NULL,	0,	IEC61850_FC_DC,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,	NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev= { DataAttributeModelType,	"configRev",(ModelNode*) &iedModel_LD0_LLN0_NamPlt,		(ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,	0,	IEC61850_FC_DC,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,	NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,	"ldNs",		(ModelNode*) &iedModel_LD0_LLN0_NamPlt,		NULL,    										NULL,	0,	IEC61850_FC_EX,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,	NULL,    0};

/*************************************************************************
 * LPHD1 Информация о физическом устройстве
 *************************************************************************/
LogicalNode iedModel_LD0_LPHD1 					= { LogicalNodeModelType,	"LPHD1",    (ModelNode*) &iedModel_Generic_LD0,  		(ModelNode*) &iedModel_LD0_RDRE1,    			(ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam 			= { DataObjectModelType,	"PhyNam",	(ModelNode*) &iedModel_LD0_LPHD1,    		(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    	(ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_LD0_LPHD1_PhyNam, 	NULL,    										NULL,	0,	IEC61850_FC_DC,    	IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth 		= { DataObjectModelType,	"PhyHealth",(ModelNode*) &iedModel_LD0_LPHD1,    		(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    		(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,	NULL,	0,	IEC61850_FC_ST,    	IEC61850_INT32,    			TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q 	= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,	NULL,	0,	IEC61850_FC_ST,    	IEC61850_QUALITY,			TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t 	= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,	NULL,    										NULL,	0,	IEC61850_FC_ST,    	IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy 			= { DataObjectModelType,	"Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    		NULL,    										(ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_LD0_LPHD1_Proxy, 	(ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, 		NULL, 	0, 	IEC61850_FC_ST, 	IEC61850_BOOLEAN, 			TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q		= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    	(ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    	NULL,	0,	IEC61850_FC_ST,    	IEC61850_QUALITY,			TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t 		= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_LD0_LPHD1_Proxy,    	NULL,    										NULL,	0,	IEC61850_FC_ST,    	IEC61850_TIMESTAMP,			TRG_OPT_DATA_CHANGED,    NULL,    0};

/*************************************************************************
 * RDRE Узел осциллографа
 *************************************************************************/
LogicalNode iedModel_LD0_RDRE1 					= { LogicalNodeModelType,   "RDRE1",	(ModelNode*) &iedModel_Generic_LD0,			(ModelNode*)NULL,    							(ModelNode*) &iedModel_LD0_RDRE1_Mod};

DataObject iedModel_LD0_RDRE1_Mod 				= { DataObjectModelType,	"Mod",		(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_Beh,    		(ModelNode*) &iedModel_LD0_RDRE1_Mod_q,0};
DataAttribute iedModel_LD0_RDRE1_Mod_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_t,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_stVal,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_stVal 		= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_ctlModel,	NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,     			TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_ctlModel 	= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_LD0_RDRE1_Mod,		NULL,    										NULL,    0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_Beh 				= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_LD0_RDRE1,    		(ModelNode*) &iedModel_LD0_RDRE1_Health,    	(ModelNode*) &iedModel_LD0_RDRE1_Beh_stVal,0};
DataAttribute iedModel_LD0_RDRE1_Beh_stVal 		= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_LD0_RDRE1_Beh,		(ModelNode*) &iedModel_LD0_RDRE1_Beh_q,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32, 				TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Beh_q 			= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_RDRE1_Beh,		(ModelNode*) &iedModel_LD0_RDRE1_Beh_t,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Beh_t 			= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_RDRE1_Beh,		NULL,    										NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_Health 			= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,    	(ModelNode*) &iedModel_LD0_RDRE1_Health_stVal,0};
DataAttribute iedModel_LD0_RDRE1_Health_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_LD0_RDRE1_Health,    (ModelNode*) &iedModel_LD0_RDRE1_Health_q,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32, 				TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Health_q		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_RDRE1_Health,    (ModelNode*) &iedModel_LD0_RDRE1_Health_t,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Health_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_RDRE1_Health,	NULL,    										NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_NamPlt 			= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_LD0_RDRE1,    		(ModelNode*)&iedModel_LD0_RDRE1_RCBMade,   		(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_vendor,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_vendor 	= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_swRev,	NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_swRev 	= { DataAttributeModelType,	"swRev",	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_d,		NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_d 		= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	NULL,    										NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};

DataObject iedModel_LD0_RDRE1_RCBMade 			= {DataObjectModelType,		"RcdMade",	(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_FltNum,		(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_stVal,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_stVal 	= {DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_q,		NULL,	0,	IEC61850_FC_ST,		IEC61850_BOOLEAN, 			TRG_OPT_DATA_CHANGED,		NULL,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_q 		= {DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_t,		NULL,	0,	IEC61850_FC_ST,		IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,	NULL,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_t 		= {DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	NULL,											NULL,	0,	IEC61850_FC_ST,		IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,		NULL,0};

DataObject iedModel_LD0_RDRE1_FltNum 			= {DataObjectModelType,		"FltNum",	(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) NULL,								(ModelNode*) &iedModel_LD0_RDRE1_FltNum_stVal,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_stVal 	= {DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	(ModelNode*) &iedModel_LD0_RDRE1_FltNum_q,		NULL,	0,	IEC61850_FC_ST,		IEC61850_INT32, 			TRG_OPT_DATA_CHANGED,		NULL,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_q 		= {DataAttributeModelType,	"q",		(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	(ModelNode*) &iedModel_LD0_RDRE1_FltNum_t,		NULL,	0,	IEC61850_FC_ST,		IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,	NULL,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_t 		= {DataAttributeModelType,	"t",		(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	NULL,											NULL,	0,	IEC61850_FC_ST,		IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,		NULL,0};

#endif

