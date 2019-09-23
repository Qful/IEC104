/*
 * MES_model.c
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */


#include "stdlib.h"
#include "model.h"

#include "MES_model.h"

extern 	IedModel 		iedModel;

/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)

extern LogicalDevice iedModel_Generic_GGIO;

#define MES_Next_Node &iedModel_Generic_GGIO			// следующий узел после этого


/*************************************************************************
 * Ћогическое устройство
 *************************************************************************/
LogicalDevice iedModel_Generic_MES 					= { LogicalDeviceModelType, "MES",		(ModelNode*)&iedModel,						(ModelNode*)MES_Next_Node,	(ModelNode*)&iedModel_MES_LLN0	};

/*************************************************************************
 * LLN0 »нформаци€ о логическом устройстве
 *************************************************************************/
LogicalNode iedModel_MES_LLN0 						= { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_MES,	   (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LLN0_Mod,};

DataObject iedModel_MES_LLN0_Mod 					= { DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_MES_LLN0,	    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Mod_q,    0};
DataAttribute iedModel_MES_LLN0_Mod_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Mod,    (ModelNode*) &iedModel_MES_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Mod_ctlModel 		= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LLN0_Beh 					= { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Beh_stVal,    0};
DataAttribute iedModel_MES_LLN0_Beh_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Beh,    (ModelNode*) &iedModel_MES_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Beh_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_Health 				= { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_MES_LLN0,    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_Health_stVal,    0};
DataAttribute iedModel_MES_LLN0_Health_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LLN0_Health,    (ModelNode*) &iedModel_MES_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_Health_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LLN0_NamPlt 				= { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_MES_LLN0,    NULL,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_vendor 		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_swRev 		= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_d 			= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_configRev 	= { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    (ModelNode*) &iedModel_MES_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LLN0_NamPlt_ldNs 		= { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_MES_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

/*************************************************************************
 * LPHD1 »нформаци€ о физическом устройстве
 *************************************************************************/																	// iedModel_MES_S1MMXU1
LogicalNode iedModel_MES_LPHD1 						= { LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_MES,    (ModelNode*) &iedModel_MES_PQS1MMXU1,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,};

DataObject iedModel_MES_LPHD1_PhyNam 				= { DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_MES_LPHD1_PhyNam_vendor		= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_MES_LPHD1_PhyHealth 			= { DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_MES_LPHD1,    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_PhyHealth_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_MES_LPHD1_Proxy 				= { DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_MES_LPHD1,    NULL,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_stVal		= {	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_MES_LPHD1_Proxy, (ModelNode*) &iedModel_MES_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_MES_LPHD1_Proxy_q			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    (ModelNode*) &iedModel_MES_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_MES_LPHD1_Proxy_t			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

/*************************************************************************
 * PQS1MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_PQS1MMXU1 							= { LogicalNodeModelType,	"PQS1MMXU1",(ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_S1MMXU1,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod};

DataObject iedModel_MES_PQS1MMXU1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_PQS1MMXU1,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Beh,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod_q,0};
DataAttribute iedModel_MES_PQS1MMXU1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Mod,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Mod,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Mod_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_MES_PQS1MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_PQS1MMXU1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_PQS1MMXU1,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Health,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_PQS1MMXU1_Beh_stVal		 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_PQS1MMXU1_Beh,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Beh_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Beh,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Beh_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_PQS1MMXU1_Health 					= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_PQS1MMXU1,    (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_PQS1MMXU1_Health_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_PQS1MMXU1_Health,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Health_q 				= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Health,    (ModelNode*) &iedModel_MES_PQS1MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_Health_t 				= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_PQS1MMXU1_NamPlt 					= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_PQS1MMXU1,    (ModelNode*) &iedModel_MES_PQS1MMXU1_totW, (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",   (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_swRev 			= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_NamPlt_d 				= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_MES_PQS1MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_MES_PQS1MMXU1_totW 					= { DataObjectModelType, 	"TotW", 	(ModelNode*) &iedModel_MES_PQS1MMXU1, (ModelNode*)&iedModel_MES_PQS1MMXU1_totVAr, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_mag, 0 };
DataAttribute iedModel_MES_PQS1MMXU1_totW_mag 				= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW,(ModelNode*)&iedModel_MES_PQS1MMXU1_totW_instMag, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_mag_f 			= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_instMag 			= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totW,(ModelNode*)&iedModel_MES_PQS1MMXU1_totW_q, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_instMag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totW, (ModelNode*) &iedModel_MES_PQS1MMXU1_totW_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totW_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totW, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

DataObject    iedModel_MES_PQS1MMXU1_totVAr 				= { DataObjectModelType, 	"TotVAr", 	(ModelNode*) &iedModel_MES_PQS1MMXU1, (ModelNode*)&iedModel_MES_PQS1MMXU1_totPF, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_mag, 0 };
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr,(ModelNode*)&iedModel_MES_PQS1MMXU1_totVAr_instMag, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_mag_f 			= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_instMag 		= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr,(ModelNode*)&iedModel_MES_PQS1MMXU1_totVAr_q, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_instMag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr, (ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totVAr_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totVAr, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

DataObject    iedModel_MES_PQS1MMXU1_totPF 					= { DataObjectModelType, 	"TotPF", 	(ModelNode*) &iedModel_MES_PQS1MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_mag, 0 };
DataAttribute iedModel_MES_PQS1MMXU1_totPF_mag 				= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF,(ModelNode*)&iedModel_MES_PQS1MMXU1_totPF_instMag, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_mag_f 			= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_instMag 			= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF,(ModelNode*)&iedModel_MES_PQS1MMXU1_totPF_q, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_instMag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF, (ModelNode*) &iedModel_MES_PQS1MMXU1_totPF_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};
DataAttribute iedModel_MES_PQS1MMXU1_totPF_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_PQS1MMXU1_totPF, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0};

/*************************************************************************
 * S1MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_S1MMXU1 							= { LogicalNodeModelType,	"S1MMXU1",	(ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_S2MMXU1,    (ModelNode*) &iedModel_MES_S1MMXU1_Mod};

DataObject iedModel_MES_S1MMXU1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S1MMXU1,    (ModelNode*) &iedModel_MES_S1MMXU1_Beh,    (ModelNode*) &iedModel_MES_S1MMXU1_Mod_q,0};
DataAttribute iedModel_MES_S1MMXU1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S1MMXU1_Mod,    (ModelNode*) &iedModel_MES_S1MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S1MMXU1_Mod,    (ModelNode*) &iedModel_MES_S1MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S1MMXU1_Mod,    (ModelNode*) &iedModel_MES_S1MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Mod_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_MES_S1MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S1MMXU1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S1MMXU1,    (ModelNode*) &iedModel_MES_S1MMXU1_Health,    (ModelNode*) &iedModel_MES_S1MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_S1MMXU1_Beh_stVal		 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S1MMXU1_Beh,    (ModelNode*) &iedModel_MES_S1MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Beh_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S1MMXU1_Beh,    (ModelNode*) &iedModel_MES_S1MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Beh_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S1MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S1MMXU1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_S1MMXU1,    (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S1MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_S1MMXU1_Health_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S1MMXU1_Health,    (ModelNode*) &iedModel_MES_S1MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Health_q 				= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S1MMXU1_Health,    (ModelNode*) &iedModel_MES_S1MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_S1MMXU1_Health_t 				= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S1MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S1MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_S1MMXU1,    (ModelNode*) &iedModel_MES_S1MMXU1_A, (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S1MMXU1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",   (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S1MMXU1_NamPlt_swRev 			= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S1MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S1MMXU1_NamPlt_d 				= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_MES_S1MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// MMXU1 A
DataObject iedModel_MES_S1MMXU1_A 							= { DataObjectModelType, "A", 			(ModelNode*) &iedModel_MES_S1MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, 0 };

DataObject iedModel_MES_S1MMXU1_A_phsA 						= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_S1MMXU1_A, (ModelNode*)&iedModel_MES_S1MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_instCVal, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S1MMXU1_A_phsB 						= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_S1MMXU1_A, (ModelNode*)&iedModel_MES_S1MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_instCVal, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, (ModelNode*)&iedModel_MES_S1MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S1MMXU1_A_phsC 						= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_S1MMXU1_A, (ModelNode*)&iedModel_MES_S1MMXU1_A_neut, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC, 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_instCVal, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC, 				(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_q,  (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S1MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S1MMXU1_A_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S1MMXU1_A_neut 						= { DataObjectModelType, 	"neut", 	(ModelNode*) &iedModel_MES_S1MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_cVal, 0 };
DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_neut, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_instCVal, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_cVal, NULL, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MMXU1_A_neut, 				(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_q,  (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut,  (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S1MMXU1_A_neut_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MMXU1_A_neut, (ModelNode*) &iedModel_MES_S1MMXU1_A_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S1MMXU1_A_neut_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MMXU1_A_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * S2MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_S2MMXU1 							= { LogicalNodeModelType,	"S2MMXU1",	(ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_S3MMXU1,    (ModelNode*) &iedModel_MES_S2MMXU1_Mod};

DataObject iedModel_MES_S2MMXU1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S2MMXU1,    (ModelNode*) &iedModel_MES_S2MMXU1_Beh,    (ModelNode*) &iedModel_MES_S2MMXU1_Mod_q,0};
DataAttribute iedModel_MES_S2MMXU1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S2MMXU1_Mod,    (ModelNode*) &iedModel_MES_S2MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S2MMXU1_Mod,    (ModelNode*) &iedModel_MES_S2MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S2MMXU1_Mod,    (ModelNode*) &iedModel_MES_S2MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Mod_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_MES_S2MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S2MMXU1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S2MMXU1,    (ModelNode*) &iedModel_MES_S2MMXU1_Health,    (ModelNode*) &iedModel_MES_S2MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_S2MMXU1_Beh_stVal		 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S2MMXU1_Beh,    (ModelNode*) &iedModel_MES_S2MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Beh_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S2MMXU1_Beh,    (ModelNode*) &iedModel_MES_S2MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Beh_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S2MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S2MMXU1_Health 						= { DataObjectModelType,    "Health",	(ModelNode*) &iedModel_MES_S2MMXU1,    (ModelNode*) &iedModel_MES_S2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S2MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_S2MMXU1_Health_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S2MMXU1_Health,    (ModelNode*) &iedModel_MES_S2MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Health_q 				= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_MES_S2MMXU1_Health,    (ModelNode*) &iedModel_MES_S2MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_S2MMXU1_Health_t 				= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_MES_S2MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S2MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_MES_S2MMXU1,    (ModelNode*) &iedModel_MES_S2MMXU1_A, (ModelNode*) &iedModel_MES_S2MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S2MMXU1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_MES_S2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S2MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S2MMXU1_NamPlt_swRev 			= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_MES_S2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S2MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S2MMXU1_NamPlt_d 				= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_MES_S2MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// MMXU1 A
DataObject iedModel_MES_S2MMXU1_A 							= { DataObjectModelType, 	"A", 		(ModelNode*) &iedModel_MES_S2MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, 0 };

DataObject iedModel_MES_S2MMXU1_A_phsA 						= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_S2MMXU1_A, (ModelNode*)&iedModel_MES_S2MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_instCVal, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S2MMXU1_A_phsB 						= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_S2MMXU1_A, (ModelNode*)&iedModel_MES_S2MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_instCVal, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, (ModelNode*)&iedModel_MES_S2MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S2MMXU1_A_phsC 						= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_S2MMXU1_A, (ModelNode*)&iedModel_MES_S2MMXU1_A_neut, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC, 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_instCVal, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC, 				(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_q,  (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S2MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S2MMXU1_A_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S2MMXU1_A_neut 						= { DataObjectModelType, 	"neut", 	(ModelNode*) &iedModel_MES_S2MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_cVal, 0 };
DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_neut, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_instCVal, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_cVal, NULL, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MMXU1_A_neut, 				(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_q,  (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut,  (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S2MMXU1_A_neut_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MMXU1_A_neut, (ModelNode*) &iedModel_MES_S2MMXU1_A_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S2MMXU1_A_neut_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MMXU1_A_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * S3MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_S3MMXU1 							= { LogicalNodeModelType,	"S3MMXU1",	(ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_S4MMXU1,    (ModelNode*) &iedModel_MES_S3MMXU1_Mod};

DataObject iedModel_MES_S3MMXU1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S3MMXU1,    (ModelNode*) &iedModel_MES_S3MMXU1_Beh,    (ModelNode*) &iedModel_MES_S3MMXU1_Mod_q,0};
DataAttribute iedModel_MES_S3MMXU1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S3MMXU1_Mod,    (ModelNode*) &iedModel_MES_S3MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S3MMXU1_Mod,    (ModelNode*) &iedModel_MES_S3MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S3MMXU1_Mod,    (ModelNode*) &iedModel_MES_S3MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Mod_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_MES_S3MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S3MMXU1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S3MMXU1,    (ModelNode*) &iedModel_MES_S3MMXU1_Health,    (ModelNode*) &iedModel_MES_S3MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_S3MMXU1_Beh_stVal		 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S3MMXU1_Beh,    (ModelNode*) &iedModel_MES_S3MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Beh_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S3MMXU1_Beh,    (ModelNode*) &iedModel_MES_S3MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Beh_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S3MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S3MMXU1_Health 						= { DataObjectModelType,    "Health",	(ModelNode*) &iedModel_MES_S3MMXU1,    (ModelNode*) &iedModel_MES_S3MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S3MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_S3MMXU1_Health_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S3MMXU1_Health,    (ModelNode*) &iedModel_MES_S3MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Health_q 				= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_MES_S3MMXU1_Health,    (ModelNode*) &iedModel_MES_S3MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_S3MMXU1_Health_t 				= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_MES_S3MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S3MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_MES_S3MMXU1,    (ModelNode*) &iedModel_MES_S3MMXU1_A, (ModelNode*) &iedModel_MES_S3MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S3MMXU1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_MES_S3MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S3MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S3MMXU1_NamPlt_swRev 			= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_MES_S3MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S3MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S3MMXU1_NamPlt_d 				= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_MES_S3MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

// MMXU1 A
DataObject iedModel_MES_S3MMXU1_A 							= { DataObjectModelType, 	"A", 		(ModelNode*) &iedModel_MES_S3MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, 0 };

DataObject iedModel_MES_S3MMXU1_A_phsA 						= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_S3MMXU1_A, (ModelNode*)&iedModel_MES_S3MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_instCVal, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S3MMXU1_A_phsB 						= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_S3MMXU1_A, (ModelNode*)&iedModel_MES_S3MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_instCVal, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, (ModelNode*)&iedModel_MES_S3MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S3MMXU1_A_phsC 						= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_S3MMXU1_A, (ModelNode*)&iedModel_MES_S3MMXU1_A_neut, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC, 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_instCVal, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC, 				(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_q,  (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S3MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S3MMXU1_A_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S3MMXU1_A_neut 						= { DataObjectModelType, 	"neut", 	(ModelNode*) &iedModel_MES_S3MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_cVal, 0 };
DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_neut, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_instCVal, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_cVal, NULL, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MMXU1_A_neut, 				(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_q,  (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut,  (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S3MMXU1_A_neut_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MMXU1_A_neut, (ModelNode*) &iedModel_MES_S3MMXU1_A_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S3MMXU1_A_neut_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MMXU1_A_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * S4MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_S4MMXU1 							= { LogicalNodeModelType,	"S4MMXU1",	(ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_U1MMXU1,    (ModelNode*) &iedModel_MES_S4MMXU1_Mod};

DataObject iedModel_MES_S4MMXU1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S4MMXU1,    (ModelNode*) &iedModel_MES_S4MMXU1_Beh,    (ModelNode*) &iedModel_MES_S4MMXU1_Mod_q,0};
DataAttribute iedModel_MES_S4MMXU1_Mod_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S4MMXU1_Mod,    (ModelNode*) &iedModel_MES_S4MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Mod_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S4MMXU1_Mod,    (ModelNode*) &iedModel_MES_S4MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S4MMXU1_Mod,    (ModelNode*) &iedModel_MES_S4MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Mod_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_MES_S4MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S4MMXU1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S4MMXU1,    (ModelNode*) &iedModel_MES_S4MMXU1_Health,    (ModelNode*) &iedModel_MES_S4MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_S4MMXU1_Beh_stVal		 		= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S4MMXU1_Beh,    (ModelNode*) &iedModel_MES_S4MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Beh_q 					= { DataAttributeModelType,	"q",    	(ModelNode*) &iedModel_MES_S4MMXU1_Beh,    (ModelNode*) &iedModel_MES_S4MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Beh_t 					= { DataAttributeModelType,	"t",    	(ModelNode*) &iedModel_MES_S4MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S4MMXU1_Health 						= { DataObjectModelType,    "Health",	(ModelNode*) &iedModel_MES_S4MMXU1,    (ModelNode*) &iedModel_MES_S4MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S4MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_S4MMXU1_Health_stVal 			= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_MES_S4MMXU1_Health,    (ModelNode*) &iedModel_MES_S4MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Health_q 				= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_MES_S4MMXU1_Health,    (ModelNode*) &iedModel_MES_S4MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_S4MMXU1_Health_t 				= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_MES_S4MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_S4MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",	(ModelNode*) &iedModel_MES_S4MMXU1,    (ModelNode*) &iedModel_MES_S4MMXU1_A, (ModelNode*) &iedModel_MES_S4MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S4MMXU1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_MES_S4MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S4MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S4MMXU1_NamPlt_swRev 			= { DataAttributeModelType,	"swRev",    (ModelNode*) &iedModel_MES_S4MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_S4MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_S4MMXU1_NamPlt_d 				= { DataAttributeModelType,	"d",    	(ModelNode*) &iedModel_MES_S4MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_MES_S4MMXU1_A 							= { DataObjectModelType, 	"A", 		(ModelNode*) &iedModel_MES_S4MMXU1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, 0 };

DataObject iedModel_MES_S4MMXU1_A_phsA 						= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_S4MMXU1_A, (ModelNode*)&iedModel_MES_S4MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_cVal, 0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_instCVal, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_cVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_q, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S4MMXU1_A_phsB 						= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_S4MMXU1_A, (ModelNode*)&iedModel_MES_S4MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_cVal, 0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_instCVal, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_q, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_instCVal_mag, (ModelNode*) NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, (ModelNode*)&iedModel_MES_S4MMXU1_A_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S4MMXU1_A_phsC 						= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_S4MMXU1_A, (ModelNode*)&iedModel_MES_S4MMXU1_A_neut, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_cVal, 0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC, 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_instCVal, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC, 				(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_q,  (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC,  (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC, (ModelNode*) &iedModel_MES_S4MMXU1_A_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S4MMXU1_A_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_S4MMXU1_A_neut 						= { DataObjectModelType, 	"neut", 	(ModelNode*) &iedModel_MES_S4MMXU1_A, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_cVal, 0 };
DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_neut, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_instCVal, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal_mag 			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_cVal, NULL, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MMXU1_A_neut, 				(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_q,  (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_instCVal, 		NULL, 										(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut_instCVal_mag, 	(ModelNode*) NULL, 							 NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut,  (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_S4MMXU1_A_neut_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MMXU1_A_neut, (ModelNode*) &iedModel_MES_S4MMXU1_A_neut_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_S4MMXU1_A_neut_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MMXU1_A_neut, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };


/*************************************************************************
 * U1MMXU1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_U1MMXU1 							= { LogicalNodeModelType,    "U1MMXU1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_U2MMXU1,    (ModelNode*) &iedModel_MES_U1MMXU1_Mod};

DataObject iedModel_MES_U1MMXU1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_U1MMXU1,    (ModelNode*) &iedModel_MES_U1MMXU1_Beh,    (ModelNode*) &iedModel_MES_U1MMXU1_Mod_q,0};
DataAttribute iedModel_MES_U1MMXU1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U1MMXU1_Mod,    (ModelNode*) &iedModel_MES_U1MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U1MMXU1_Mod,    (ModelNode*) &iedModel_MES_U1MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_U1MMXU1_Mod,    (ModelNode*) &iedModel_MES_U1MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_U1MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U1MMXU1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_U1MMXU1,    (ModelNode*) &iedModel_MES_U1MMXU1_Health,    (ModelNode*) &iedModel_MES_U1MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_U1MMXU1_Beh_stVal		 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_U1MMXU1_Beh,    (ModelNode*) &iedModel_MES_U1MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U1MMXU1_Beh,    (ModelNode*) &iedModel_MES_U1MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U1MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U1MMXU1_Health 						= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_U1MMXU1,    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U1MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_U1MMXU1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_U1MMXU1_Health,    (ModelNode*) &iedModel_MES_U1MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U1MMXU1_Health,    (ModelNode*) &iedModel_MES_U1MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_U1MMXU1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U1MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U1MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_U1MMXU1,    (ModelNode*) &iedModel_MES_U1MMXU1_phV, (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_U1MMXU1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U1MMXU1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U1MMXU1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_U1MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_U1MMXU1_phV 						= { DataObjectModelType, 	"PhV", 		(ModelNode*) &iedModel_MES_U1MMXU1, (ModelNode*) &iedModel_MES_U1MMXU1_PPV, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, 0 };
DataObject iedModel_MES_U1MMXU1_phV_phsA 					= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV, (ModelNode*)&iedModel_MES_U1MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_q, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag_f	= { DataAttributeModelType, "f",		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA,  (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U1MMXU1_phV_phsB 					= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV, (ModelNode*)&iedModel_MES_U1MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_q, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB,  (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U1MMXU1_phV_phsC 					= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal_mag		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_q, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC,  (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_phV_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_phV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// PPV
DataObject iedModel_MES_U1MMXU1_PPV 						= { DataObjectModelType, 	"PPV", 		(ModelNode*) &iedModel_MES_U1MMXU1, (ModelNode*) NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, 0 };
DataObject iedModel_MES_U1MMXU1_PPV_phsA 					= { DataObjectModelType, 	"phsAB", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV, (ModelNode*)&iedModel_MES_U1MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_q, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA,  (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U1MMXU1_PPV_phsB 					= { DataObjectModelType, 	"phsBC", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV, (ModelNode*)&iedModel_MES_U1MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_q, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB,  (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U1MMXU1_PPV_phsC 					= { DataObjectModelType, 	"phsCA", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV, (ModelNode*)NULL /*&iedModel_MES_U1MMXU1_PPV_phsC*/, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_cVal, 0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_instCVal, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_q, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC,  (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U1MMXU1_PPV_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MMXU1_PPV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * U2MMXU2 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_U2MMXU1 							= { LogicalNodeModelType,    "U2MMXU1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_UNMMXN1,    (ModelNode*) &iedModel_MES_U2MMXU1_Mod};

DataObject iedModel_MES_U2MMXU1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_U2MMXU1,    (ModelNode*) &iedModel_MES_U2MMXU1_Beh,    (ModelNode*) &iedModel_MES_U2MMXU1_Mod_q,0};
DataAttribute iedModel_MES_U2MMXU1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U2MMXU1_Mod,    (ModelNode*) &iedModel_MES_U2MMXU1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U2MMXU1_Mod,    (ModelNode*) &iedModel_MES_U2MMXU1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_U2MMXU1_Mod,    (ModelNode*) &iedModel_MES_U2MMXU1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_U2MMXU1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U2MMXU1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_U2MMXU1,    (ModelNode*) &iedModel_MES_U2MMXU1_Health,    (ModelNode*) &iedModel_MES_U2MMXU1_Beh_stVal,0};
DataAttribute iedModel_MES_U2MMXU1_Beh_stVal		 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_U2MMXU1_Beh,    (ModelNode*) &iedModel_MES_U2MMXU1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U2MMXU1_Beh,    (ModelNode*) &iedModel_MES_U2MMXU1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U2MMXU1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U2MMXU1_Health 						= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_U2MMXU1,    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U2MMXU1_Health_stVal,0};
DataAttribute iedModel_MES_U2MMXU1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_U2MMXU1_Health,    (ModelNode*) &iedModel_MES_U2MMXU1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_U2MMXU1_Health,    (ModelNode*) &iedModel_MES_U2MMXU1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_U2MMXU1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_U2MMXU1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_U2MMXU1_NamPlt 						= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_U2MMXU1,    (ModelNode*) &iedModel_MES_U2MMXU1_phV, (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt_vendor,0};
DataAttribute iedModel_MES_U2MMXU1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U2MMXU1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt,    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_U2MMXU1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_U2MMXU1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_U2MMXU1_phV 						= { DataObjectModelType, 	"PhV", 		(ModelNode*) &iedModel_MES_U2MMXU1, (ModelNode*) &iedModel_MES_U2MMXU1_PPV, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, 0 };
DataObject iedModel_MES_U2MMXU1_phV_phsA 					= { DataObjectModelType, 	"phsA", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV, (ModelNode*)&iedModel_MES_U2MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_q, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag_f	= { DataAttributeModelType, "f",		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA,  (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U2MMXU1_phV_phsB 					= { DataObjectModelType, 	"phsB", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV, (ModelNode*)&iedModel_MES_U2MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_q, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB,  (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U2MMXU1_phV_phsC 					= { DataObjectModelType, 	"phsC", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal_mag		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_q, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC,  (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_phV_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_phV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

// PPV
DataObject iedModel_MES_U2MMXU1_PPV 						= { DataObjectModelType, 	"PPV", 		(ModelNode*) &iedModel_MES_U2MMXU1, (ModelNode*) NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, 0 };
DataObject iedModel_MES_U2MMXU1_PPV_phsA 					= { DataObjectModelType, 	"phsAB", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV, (ModelNode*)&iedModel_MES_U2MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_q, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA,  (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsA_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsA, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U2MMXU1_PPV_phsB 					= { DataObjectModelType, 	"phsBC", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV, (ModelNode*)&iedModel_MES_U2MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_q, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB,  (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsB_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsB, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

DataObject iedModel_MES_U2MMXU1_PPV_phsC 					= { DataObjectModelType, 	"phsCA", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV, (ModelNode*)NULL /*&iedModel_MES_U2MMXU1_PPV_phsC*/, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_cVal, 0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_instCVal, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_cVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_q, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_instCVal, NULL, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC,  (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC, (ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_U2MMXU1_PPV_phsC_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MMXU1_PPV_phsC, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * UNMMXUN1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_UNMMXN1 							= { LogicalNodeModelType,    "UNMMXN1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_FMMXN1,    (ModelNode*) &iedModel_MES_UNMMXN1_Mod};

DataObject iedModel_MES_UNMMXN1_Mod 						= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_UNMMXN1,    (ModelNode*) &iedModel_MES_UNMMXN1_Beh,    (ModelNode*) &iedModel_MES_UNMMXN1_Mod_q,0};
DataAttribute iedModel_MES_UNMMXN1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_UNMMXN1_Mod,    (ModelNode*) &iedModel_MES_UNMMXN1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_UNMMXN1_Mod,    (ModelNode*) &iedModel_MES_UNMMXN1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_UNMMXN1_Mod,    (ModelNode*) &iedModel_MES_UNMMXN1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Mod_ctlModel 			= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_UNMMXN1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_UNMMXN1_Beh 						= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_UNMMXN1,    (ModelNode*) &iedModel_MES_UNMMXN1_Health,    (ModelNode*) &iedModel_MES_UNMMXN1_Beh_stVal,0};
DataAttribute iedModel_MES_UNMMXN1_Beh_stVal		 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_UNMMXN1_Beh,    (ModelNode*) &iedModel_MES_UNMMXN1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_UNMMXN1_Beh,    (ModelNode*) &iedModel_MES_UNMMXN1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_UNMMXN1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_UNMMXN1_Health 						= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_UNMMXN1,    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_UNMMXN1_Health_stVal,0};
DataAttribute iedModel_MES_UNMMXN1_Health_stVal 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_UNMMXN1_Health,    (ModelNode*) &iedModel_MES_UNMMXN1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Health_q 				= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_UNMMXN1_Health,    (ModelNode*) &iedModel_MES_UNMMXN1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Health_t 				= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_UNMMXN1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_UNMMXN1_NamPlt 						= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_UNMMXN1,    (ModelNode*) &iedModel_MES_UNMMXN1_Vol, (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt_vendor,0};
DataAttribute iedModel_MES_UNMMXN1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_UNMMXN1_NamPlt_swRev 			= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_UNMMXN1_NamPlt_d 				= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_UNMMXN1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_MES_UNMMXN1_Vol 						= { DataObjectModelType, 	"Vol", 	(ModelNode*) &iedModel_MES_UNMMXN1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_cVal, 0 };
DataAttribute iedModel_MES_UNMMXN1_Vol_cVal 				= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_UNMMXN1_Vol, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_instCVal, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_cVal_mag				= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol_cVal, NULL, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_cVal_mag_f 			= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol_cVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal 			= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_UNMMXN1_Vol, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_q, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_instCVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal_mag			= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol_instCVal, NULL, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_instCVal_mag_f		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol_instCVal_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_q 					= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_t 					= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol,  (ModelNode*) &iedModel_MES_UNMMXN1_Vol_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0};
DataAttribute iedModel_MES_UNMMXN1_Vol_db 					= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_UNMMXN1_Vol, (ModelNode*) &iedModel_MES_UNMMXN1_Vol_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_UNMMXN1_Vol_zeroDb 				= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_UNMMXN1_Vol, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*************************************************************************
 * FMMXN1 измерени€
 *************************************************************************/
LogicalNode iedModel_MES_FMMXN1 							= { LogicalNodeModelType,    "FMMXN1",    (ModelNode*)&iedModel_Generic_MES,   (ModelNode*)&iedModel_MES_S1MSQI1,    (ModelNode*) &iedModel_MES_FMMXN1_Mod};

DataObject iedModel_MES_FMMXN1_Mod 							= { DataObjectModelType,    "Mod",    (ModelNode*) &iedModel_MES_FMMXN1,    (ModelNode*) &iedModel_MES_FMMXN1_Beh,    (ModelNode*) &iedModel_MES_FMMXN1_Mod_q,0};
DataAttribute iedModel_MES_FMMXN1_Mod_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_FMMXN1_Mod,    (ModelNode*) &iedModel_MES_FMMXN1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_MES_FMMXN1_Mod_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_FMMXN1_Mod,    (ModelNode*) &iedModel_MES_FMMXN1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_FMMXN1_Mod_stVal 				= { DataAttributeModelType,"stVal",    (ModelNode*) &iedModel_MES_FMMXN1_Mod,    (ModelNode*) &iedModel_MES_FMMXN1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_FMMXN1_Mod_ctlModel 				= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_MES_FMMXN1_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_FMMXN1_Beh 							= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_MES_FMMXN1,    (ModelNode*) &iedModel_MES_FMMXN1_Health,    (ModelNode*) &iedModel_MES_FMMXN1_Beh_stVal,0};
DataAttribute iedModel_MES_FMMXN1_Beh_stVal		 			= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_FMMXN1_Beh,    (ModelNode*) &iedModel_MES_FMMXN1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_FMMXN1_Beh_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_FMMXN1_Beh,    (ModelNode*) &iedModel_MES_FMMXN1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_FMMXN1_Beh_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_FMMXN1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_FMMXN1_Health 						= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_MES_FMMXN1,    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_FMMXN1_Health_stVal,0};
DataAttribute iedModel_MES_FMMXN1_Health_stVal 				= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_MES_FMMXN1_Health,    (ModelNode*) &iedModel_MES_FMMXN1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_FMMXN1_Health_q 					= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_MES_FMMXN1_Health,    (ModelNode*) &iedModel_MES_FMMXN1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_MES_FMMXN1_Health_t 					= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_MES_FMMXN1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_MES_FMMXN1_NamPlt 						= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_MES_FMMXN1,    (ModelNode*) &iedModel_MES_FMMXN1_Hz, (ModelNode*) &iedModel_MES_FMMXN1_NamPlt_vendor,0};
DataAttribute iedModel_MES_FMMXN1_NamPlt_vendor 			= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_FMMXN1_NamPlt_swRev 				= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt,    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_MES_FMMXN1_NamPlt_d 					= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_MES_FMMXN1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject    iedModel_MES_FMMXN1_Hz 						= { DataObjectModelType, 	"Hz", 		(ModelNode*) &iedModel_MES_FMMXN1, (ModelNode*)NULL, (ModelNode*) &iedModel_MES_FMMXN1_Hz_mag, 0 };
DataAttribute iedModel_MES_FMMXN1_Hz_mag 					= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz,(ModelNode*)&iedModel_MES_FMMXN1_Hz_instMag, (ModelNode*) &iedModel_MES_FMMXN1_Hz_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_mag_f 					= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz_mag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,TRG_OPT_DATA_CHANGED, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_instMag 				= { DataAttributeModelType, "instMag", 	(ModelNode*) &iedModel_MES_FMMXN1_Hz,(ModelNode*)&iedModel_MES_FMMXN1_Hz_q, (ModelNode*) &iedModel_MES_FMMXN1_Hz_instMag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_instMag_f 				= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz_instMag, NULL, NULL, 0,  IEC61850_FC_MX, IEC61850_FLOAT32,0, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_q 						= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz, (ModelNode*) &iedModel_MES_FMMXN1_Hz_t, NULL, 0,  IEC61850_FC_MX, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_FMMXN1_Hz_t 						= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz, (ModelNode*) &iedModel_MES_FMMXN1_Hz_db, NULL, 0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 0, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_db 					= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_FMMXN1_Hz, (ModelNode*) &iedModel_MES_FMMXN1_Hz_zeroDb, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };
DataAttribute iedModel_MES_FMMXN1_Hz_zeroDb 				= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_FMMXN1_Hz, NULL, NULL, 0, IEC61850_FC_CF, IEC61850_INT32U, 0, NULL,0 };

/*******************************************************
 * S1MSQI1
 *******************************************************/
LogicalNode iedModel_MES_S1MSQI1 							= { LogicalNodeModelType,    "S1MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)&iedModel_MES_S2MSQI1,    (ModelNode*) &iedModel_MES_S1MSQI1_Mod};

DataObject iedModel_MES_S1MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S1MSQI1,    					(ModelNode*) &iedModel_MES_S1MSQI1_Beh,    			(ModelNode*) &iedModel_MES_S1MSQI1_Mod_q,0};
DataAttribute iedModel_MES_S1MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S1MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S1MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S1MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_S1MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S1MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S1MSQI1,    					(ModelNode*) &iedModel_MES_S1MSQI1_Health,    		(ModelNode*) &iedModel_MES_S1MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_S1MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S1MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S1MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S1MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S1MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S1MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S1MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_S1MSQI1,    					(ModelNode*) &iedModel_MES_S1MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_S1MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_S1MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S1MSQI1_Health,				(ModelNode*) &iedModel_MES_S1MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S1MSQI1_Health,				(ModelNode*) &iedModel_MES_S1MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S1MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S1MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S1MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_S1MSQI1,    					(ModelNode*) &iedModel_MES_S1MSQI1_SeqA, (ModelNode*) &iedModel_MES_S1MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S1MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_S1MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S1MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S1MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_S1MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S1MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S1MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_S1MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqA
DataObject iedModel_MES_S1MSQI1_SeqA 						= { DataObjectModelType, 	"SeqA", 	(ModelNode*) &iedModel_MES_S1MSQI1, 					(ModelNode*) NULL, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 0 };

DataObject iedModel_MES_S1MSQI1_SeqA_I1 					= { DataObjectModelType,    "c1", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_cVal, 0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_instCVal,(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag_f, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_cVal_mag, 	NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_q, 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag_f,	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_instCVal_mag,NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_t, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_db, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I1, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S1MSQI1_SeqA_I2 					= { DataObjectModelType,    "c2", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S1MSQI1_SeqA_I0, (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_cVal, 0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_instCVal,(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_q, (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag, 		0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_db, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I2, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S1MSQI1_SeqA_I0 					= { DataObjectModelType,    "c3", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S1MSQI1_SeqA_SeqT, (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_cVal, 0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_instCVal, (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_q, (ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0_zeroDb, NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S1MSQI1_SeqA_I0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA_I0, 			NULL, 												NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataAttribute iedModel_MES_S1MSQI1_SeqA_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_S1MSQI1_SeqA, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};

/*******************************************************
 * S2MSQI1
 *******************************************************/
LogicalNode iedModel_MES_S2MSQI1 							= { LogicalNodeModelType,    "S2MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)&iedModel_MES_S3MSQI1,    (ModelNode*) &iedModel_MES_S2MSQI1_Mod};

DataObject iedModel_MES_S2MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S2MSQI1,    					(ModelNode*) &iedModel_MES_S2MSQI1_Beh,    			(ModelNode*) &iedModel_MES_S2MSQI1_Mod_q,0};
DataAttribute iedModel_MES_S2MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S2MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S2MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S2MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_S2MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S2MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S2MSQI1,    					(ModelNode*) &iedModel_MES_S2MSQI1_Health,    		(ModelNode*) &iedModel_MES_S2MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_S2MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S2MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S2MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S2MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S2MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S2MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S2MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_S2MSQI1,    					(ModelNode*) &iedModel_MES_S2MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_S2MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_S2MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S2MSQI1_Health,				(ModelNode*) &iedModel_MES_S2MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S2MSQI1_Health,				(ModelNode*) &iedModel_MES_S2MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S2MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S2MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S2MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_S2MSQI1,    					(ModelNode*) &iedModel_MES_S2MSQI1_SeqA, (ModelNode*) &iedModel_MES_S2MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S2MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_S2MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S2MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S2MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_S2MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S2MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S2MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_S2MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqA
DataObject iedModel_MES_S2MSQI1_SeqA 						= { DataObjectModelType, 	"SeqA", 	(ModelNode*) &iedModel_MES_S2MSQI1, 					(ModelNode*) NULL, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 0 };

DataObject iedModel_MES_S2MSQI1_SeqA_I1 					= { DataObjectModelType,    "c1", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_cVal, 0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_instCVal,(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag_f, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_cVal_mag, 	NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_q, 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag_f,	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_instCVal_mag,NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_t, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_db, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I1, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S2MSQI1_SeqA_I2 					= { DataObjectModelType,    "c2", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S2MSQI1_SeqA_I0, (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_cVal, 0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_instCVal,(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_q, (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag, 		0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_db, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I2, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S2MSQI1_SeqA_I0 					= { DataObjectModelType,    "c3", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S2MSQI1_SeqA_SeqT, (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_cVal, 0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_instCVal, (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_q, (ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0_zeroDb, NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S2MSQI1_SeqA_I0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA_I0, 			NULL, 												NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataAttribute iedModel_MES_S2MSQI1_SeqA_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_S2MSQI1_SeqA, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};

/*******************************************************
 * S3MSQI1
 *******************************************************/
LogicalNode iedModel_MES_S3MSQI1 							= { LogicalNodeModelType,    "S3MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)&iedModel_MES_S4MSQI1,    (ModelNode*) &iedModel_MES_S3MSQI1_Mod};

DataObject iedModel_MES_S3MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S3MSQI1,    					(ModelNode*) &iedModel_MES_S3MSQI1_Beh,    			(ModelNode*) &iedModel_MES_S3MSQI1_Mod_q,0};
DataAttribute iedModel_MES_S3MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S3MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S3MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S3MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S3MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S3MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S3MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_S3MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S3MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S3MSQI1,    					(ModelNode*) &iedModel_MES_S3MSQI1_Health,    		(ModelNode*) &iedModel_MES_S3MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_S3MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S3MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S3MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S3MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S3MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S3MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S3MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_S3MSQI1,    					(ModelNode*) &iedModel_MES_S3MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_S3MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_S3MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S3MSQI1_Health,				(ModelNode*) &iedModel_MES_S3MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S3MSQI1_Health,				(ModelNode*) &iedModel_MES_S3MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S3MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S3MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S3MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_S3MSQI1,    					(ModelNode*) &iedModel_MES_S3MSQI1_SeqA, (ModelNode*) &iedModel_MES_S3MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S3MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_S3MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S3MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S3MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_S3MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S3MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S3MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_S3MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqA
DataObject iedModel_MES_S3MSQI1_SeqA 						= { DataObjectModelType, 	"SeqA", 	(ModelNode*) &iedModel_MES_S3MSQI1, 					(ModelNode*) NULL, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 0 };

DataObject iedModel_MES_S3MSQI1_SeqA_I1 					= { DataObjectModelType,    "c1", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_cVal, 0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_instCVal,(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag_f, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_cVal_mag, 	NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_q, 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag_f,	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_instCVal_mag,NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_t, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_db, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I1, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S3MSQI1_SeqA_I2 					= { DataObjectModelType,    "c2", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S3MSQI1_SeqA_I0, (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_cVal, 0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_instCVal,(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_q, (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag, 		0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_db, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I2, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S3MSQI1_SeqA_I0 					= { DataObjectModelType,    "c3", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S3MSQI1_SeqA_SeqT, (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_cVal, 0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_instCVal, (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_q, (ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0_zeroDb, NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S3MSQI1_SeqA_I0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA_I0, 			NULL, 												NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataAttribute iedModel_MES_S3MSQI1_SeqA_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_S3MSQI1_SeqA, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};


/*******************************************************
 * S4MSQI1
 *******************************************************/
LogicalNode iedModel_MES_S4MSQI1 							= { LogicalNodeModelType,    "S4MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)&iedModel_MES_U1MSQI1,    (ModelNode*) &iedModel_MES_S4MSQI1_Mod};

DataObject iedModel_MES_S4MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_S4MSQI1,    					(ModelNode*) &iedModel_MES_S4MSQI1_Beh,    			(ModelNode*) &iedModel_MES_S4MSQI1_Mod_q,0};
DataAttribute iedModel_MES_S4MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S4MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S4MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S4MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S4MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S4MSQI1_Mod,   				(ModelNode*) &iedModel_MES_S4MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_S4MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S4MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_S4MSQI1,    					(ModelNode*) &iedModel_MES_S4MSQI1_Health,    		(ModelNode*) &iedModel_MES_S4MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_S4MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S4MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S4MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S4MSQI1_Beh,   				(ModelNode*) &iedModel_MES_S4MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S4MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S4MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_S4MSQI1,    					(ModelNode*) &iedModel_MES_S4MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_S4MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_S4MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_S4MSQI1_Health,				(ModelNode*) &iedModel_MES_S4MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_S4MSQI1_Health,				(ModelNode*) &iedModel_MES_S4MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_S4MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_S4MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_S4MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_S4MSQI1,    					(ModelNode*) &iedModel_MES_S4MSQI1_SeqA, (ModelNode*) &iedModel_MES_S4MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_S4MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_S4MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S4MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S4MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_S4MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_S4MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_S4MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_S4MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqA
DataObject iedModel_MES_S4MSQI1_SeqA 						= { DataObjectModelType, 	"SeqA", 	(ModelNode*) &iedModel_MES_S4MSQI1, 					(ModelNode*) NULL, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 0 };

DataObject iedModel_MES_S4MSQI1_SeqA_I1 					= { DataObjectModelType,    "c1", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_cVal, 0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_instCVal,(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag_f, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_cVal_mag, 	NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_q, 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag_f,	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_instCVal_mag,NULL, 												NULL, 													0,	IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_t, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_db, 		NULL, 													0,	IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I1, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S4MSQI1_SeqA_I2 					= { DataObjectModelType,    "c2", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S4MSQI1_SeqA_I0, (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_cVal, 0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_instCVal,(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag, 	0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_q, (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag, 		0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag_f, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_db, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2_zeroDb, 	NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I2, 			NULL, 												NULL, 													0,	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataObject iedModel_MES_S4MSQI1_SeqA_I0 					= { DataObjectModelType,    "c3", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA, 				(ModelNode*)&iedModel_MES_S4MSQI1_SeqA_SeqT, (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_cVal, 0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_instCVal, (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_cVal_mag, 	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_q, (ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag, 	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag_f, 0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag_f	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_instCVal_mag,NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_t, 		NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, NULL,0};
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0_zeroDb, NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };
DataAttribute iedModel_MES_S4MSQI1_SeqA_I0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA_I0, 			NULL, 												NULL, 													0, 	IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, NULL,0 };

DataAttribute iedModel_MES_S4MSQI1_SeqA_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_S4MSQI1_SeqA, NULL , NULL, 0,  IEC61850_FC_MX, IEC61850_ENUMERATED,TRG_OPT_NO, NULL,0};

/*******************************************************
 * U1MSQI1
 *******************************************************/
LogicalNode iedModel_MES_U1MSQI1 							= { LogicalNodeModelType,    "U1MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)&iedModel_MES_U2MSQI1,    (ModelNode*) &iedModel_MES_U1MSQI1_Mod};

DataObject iedModel_MES_U1MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_U1MSQI1,    					(ModelNode*) &iedModel_MES_U1MSQI1_Beh,    			(ModelNode*) &iedModel_MES_U1MSQI1_Mod_q,0};
DataAttribute iedModel_MES_U1MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U1MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U1MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U1MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U1MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_U1MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U1MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_U1MSQI1,    					(ModelNode*) &iedModel_MES_U1MSQI1_Health,    		(ModelNode*) &iedModel_MES_U1MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_U1MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U1MSQI1_Beh,   				(ModelNode*) &iedModel_MES_U1MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U1MSQI1_Beh,   				(ModelNode*) &iedModel_MES_U1MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U1MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U1MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_U1MSQI1,    					(ModelNode*) &iedModel_MES_U1MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_U1MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_U1MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U1MSQI1_Health,				(ModelNode*) &iedModel_MES_U1MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U1MSQI1_Health,				(ModelNode*) &iedModel_MES_U1MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U1MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U1MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_U1MSQI1,    					(ModelNode*) &iedModel_MES_U1MSQI1_SeqU, (ModelNode*) &iedModel_MES_U1MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_U1MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_U1MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_U1MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_U1MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_U1MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_U1MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_U1MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_U1MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqU
DataObject iedModel_MES_U1MSQI1_SeqU 						= { DataObjectModelType, 	"SeqV", 	(ModelNode*) &iedModel_MES_U1MSQI1, 					NULL, 												(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 0 };

DataObject iedModel_MES_U1MSQI1_SeqU_U1 					= { DataObjectModelType, 	"c1", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU, 				(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_cVal, 0 };
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_instCVal,(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_cVal, 		(ModelNode*) NULL,									(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_cVal_mag, 	(ModelNode*) NULL, 									NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_q, 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag,0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_instCVal, 	(ModelNode*) NULL, 								(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag_f,	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_instCVal_mag,NULL, 												(ModelNode*) NULL, 										0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_t, 		NULL, 													0, IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_db, 		NULL, 													0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1_zeroDb, 	NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U1, 			NULL, 												NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};

DataObject iedModel_MES_U1MSQI1_SeqU_U2 					= { DataObjectModelType, 	"c2", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU, 				(ModelNode*)&iedModel_MES_U1MSQI1_SeqU_U0, 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_cVal, 0 };
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_instCVal,(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_cVal_mag, 	NULL, 												NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED,	NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_q, 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag,0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag_f,	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_instCVal_mag,NULL, 												NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_t, 		NULL, 													0, IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_db, 		NULL, 													0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2_zeroDb, 	NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO,				NULL,0 };
DataAttribute iedModel_MES_U1MSQI1_SeqU_U2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U2, 			NULL, 												NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO,				NULL,0 };

DataObject iedModel_MES_U1MSQI1_SeqU_U0 					= { DataObjectModelType, 	"c3", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU, 				(ModelNode*)&iedModel_MES_U1MSQI1_SeqU_SeqT, 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_cVal, 		0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_instCVal,(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag_f,0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_cVal_mag,	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_q, (ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag,	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_instCVal,	NULL, 											(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag_f,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_instCVal_mag, NULL, 											NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_t, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0_zeroDb,NULL, 													0,  IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U1MSQI1_SeqU_U0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU_U0, 			NULL, 												NULL, 													0,  IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};

DataAttribute iedModel_MES_U1MSQI1_SeqU_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_U1MSQI1_SeqU, 				NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_ENUMERATED,	TRG_OPT_NO, 			NULL,0};

/*******************************************************
 * U2MSQI1
 *******************************************************/
LogicalNode iedModel_MES_U2MSQI1 							= { LogicalNodeModelType,    "U2MSQI1",	(ModelNode*)&iedModel_Generic_MES,   					(ModelNode*)NULL,    (ModelNode*) &iedModel_MES_U2MSQI1_Mod};

DataObject iedModel_MES_U2MSQI1_Mod 						= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_MES_U2MSQI1,    					(ModelNode*) &iedModel_MES_U2MSQI1_Beh,    			(ModelNode*) &iedModel_MES_U2MSQI1_Mod_q,0};
DataAttribute iedModel_MES_U2MSQI1_Mod_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U2MSQI1_Mod_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Mod_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U2MSQI1_Mod_stVal,		NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Mod_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U2MSQI1_Mod,   				(ModelNode*) &iedModel_MES_U2MSQI1_Mod_ctlModel,	NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32,     		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Mod_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_MES_U2MSQI1_Mod,   				NULL,    											NULL,    												0,  IEC61850_FC_CF, IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U2MSQI1_Beh 						= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_MES_U2MSQI1,    					(ModelNode*) &iedModel_MES_U2MSQI1_Health,    		(ModelNode*) &iedModel_MES_U2MSQI1_Beh_stVal,0};
DataAttribute iedModel_MES_U2MSQI1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U2MSQI1_Beh,   				(ModelNode*) &iedModel_MES_U2MSQI1_Beh_q,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U2MSQI1_Beh,   				(ModelNode*) &iedModel_MES_U2MSQI1_Beh_t,    		NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U2MSQI1_Beh,  				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U2MSQI1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_MES_U2MSQI1,    					(ModelNode*) &iedModel_MES_U2MSQI1_NamPlt,    		(ModelNode*) &iedModel_MES_U2MSQI1_Health_stVal,0};
DataAttribute iedModel_MES_U2MSQI1_Health_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_MES_U2MSQI1_Health,				(ModelNode*) &iedModel_MES_U2MSQI1_Health_q,    	NULL,   	 											0,  IEC61850_FC_ST, IEC61850_INT32, 			TRG_OPT_NO,    			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Health_q		 			= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_MES_U2MSQI1_Health,				(ModelNode*) &iedModel_MES_U2MSQI1_Health_t,    	NULL,    												0,  IEC61850_FC_ST, IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_Health_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_MES_U2MSQI1_Health,				NULL,    											NULL,    												0,  IEC61850_FC_ST, IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED, 	NULL,0};

DataObject iedModel_MES_U2MSQI1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_MES_U2MSQI1,    					(ModelNode*) &iedModel_MES_U2MSQI1_SeqU, (ModelNode*) &iedModel_MES_U2MSQI1_NamPlt_vendor,0};
DataAttribute iedModel_MES_U2MSQI1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_MES_U2MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_U2MSQI1_NamPlt_swRev,	NULL,    												0,  IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_U2MSQI1_NamPlt_swRev	 			= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_MES_U2MSQI1_NamPlt,				(ModelNode*) &iedModel_MES_U2MSQI1_NamPlt_d,    	NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};
DataAttribute iedModel_MES_U2MSQI1_NamPlt_d 				= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_MES_U2MSQI1_NamPlt,				NULL,    											NULL,    												0,	IEC61850_FC_DC, IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,	NULL,0};

// SeqU
DataObject iedModel_MES_U2MSQI1_SeqU 						= { DataObjectModelType, 	"SeqV", 	(ModelNode*) &iedModel_MES_U2MSQI1, 					NULL, 												(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 0 };

DataObject iedModel_MES_U2MSQI1_SeqU_U1 					= { DataObjectModelType, 	"c1", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU, 				(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_cVal, 0 };
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_instCVal,(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_cVal, 		(ModelNode*) NULL,									(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_cVal_mag, 	(ModelNode*) NULL, 									NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_q, 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag,0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_instCVal, 	(ModelNode*) NULL, 								(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag_f,	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_instCVal_mag,NULL, 												(ModelNode*) NULL, 										0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_t, 		NULL, 													0, IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_db, 		NULL, 													0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1_zeroDb, 	NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U1_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U1, 			NULL, 												NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};

DataObject iedModel_MES_U2MSQI1_SeqU_U2 					= { DataObjectModelType, 	"c2", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU, 				(ModelNode*)&iedModel_MES_U2MSQI1_SeqU_U0, 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_cVal, 0 };
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_instCVal,(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag_f, 	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_cVal_mag, 	NULL, 												NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED,	NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_q, 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag,0, IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_instCVal, 	NULL, 											(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag_f,	0, IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_instCVal_mag,NULL, 												NULL, 													0, IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_t, 		NULL, 													0, IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_db, 		NULL, 													0, IEC61850_FC_MX, IEC61850_TIMESTAMP, 		TRG_OPT_NO,				NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2_zeroDb, 	NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO,				NULL,0 };
DataAttribute iedModel_MES_U2MSQI1_SeqU_U2_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U2, 			NULL, 												NULL, 													0, IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO,				NULL,0 };

DataObject iedModel_MES_U2MSQI1_SeqU_U0 					= { DataObjectModelType, 	"c3", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU, 				(ModelNode*)&iedModel_MES_U2MSQI1_SeqU_SeqT, 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_cVal, 		0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal 			= { DataAttributeModelType, "cVal", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_instCVal,(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag 		= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_cVal, 		NULL, 												(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag_f,0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag_f 		= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_cVal_mag,	NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_DATA_CHANGED, 	NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal 		= { DataAttributeModelType, "instCVal", (ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_q, (ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag,	0,  IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag 	= { DataAttributeModelType, "mag", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_instCVal,	NULL, 											(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag_f,0,	IEC61850_FC_MX, IEC61850_CONSTRUCTED,	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag_f 	= { DataAttributeModelType, "f", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_instCVal_mag, NULL, 											NULL, 													0,  IEC61850_FC_MX, IEC61850_FLOAT32,		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_q 				= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_t, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_t 				= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_db, 	NULL, 													0,  IEC61850_FC_MX, IEC61850_TIMESTAMP, 	TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_db 				= { DataAttributeModelType, "db", 		(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0_zeroDb,NULL, 													0,  IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};
DataAttribute iedModel_MES_U2MSQI1_SeqU_U0_zeroDb 			= { DataAttributeModelType, "zeroDb", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU_U0, 			NULL, 												NULL, 													0,  IEC61850_FC_CF, IEC61850_INT32U, 		TRG_OPT_NO, 			NULL,0};

DataAttribute iedModel_MES_U2MSQI1_SeqU_SeqT 				= { DataAttributeModelType, "seqT", 	(ModelNode*) &iedModel_MES_U2MSQI1_SeqU, 				NULL, 												NULL, 													0,  IEC61850_FC_MX, IEC61850_ENUMERATED,	TRG_OPT_NO, 			NULL,0};

#endif
