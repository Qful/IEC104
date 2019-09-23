/*
 * static_model_MR801_T12N5D58R51.c
 */

#if  defined (MR801) && defined (T12N5D58R51)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR801_T12N5D58R51.h"
#include "IEC850.h"

#include "dataUpdateFromBase.h"
#include "dataDbzeroDB.h"

static void initializeValues();

/*************************************************************************
 * группы уставок
 *************************************************************************/
SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0 = {
	&iedModel_LD0_LLN0,									// родитель
	1,													// активная группа настроек
	2,													// число групп настроек
	0,													// editSG
	false,												// cnfEdit
	0,													// timestamp
	0,													// resvTms
	NULL												// следующий в списке
};

/*************************************************************************
 * Log выборки
 *************************************************************************/
extern LogControlBlock iedModel_LD0_LLN0_lcb0;
extern LogControlBlock iedModel_LD0_LLN0_lcb1;

LogControlBlock iedModel_LD0_LLN0_lcb0 = {&iedModel_LD0_LLN0, "EventLog", 	"NewGoose1",		"LD0/LLN0$EventLog", 	TRG_OPT_INTEGRITY, 1000, true, true, &iedModel_LD0_LLN0_lcb1};
LogControlBlock iedModel_LD0_LLN0_lcb1 = {&iedModel_LD0_LLN0, "GeneralLog", NULL, 		NULL, 					TRG_OPT_INTEGRITY, 1000, true, true, NULL};

extern Log iedModel_LD0_LLN0_log0;
extern Log iedModel_LD0_LLN0_log1;

Log iedModel_LD0_LLN0_log0 = {&iedModel_LD0_LLN0, "GeneralLog", 	&iedModel_LD0_LLN0_log1};
Log iedModel_LD0_LLN0_log1 = {&iedModel_LD0_LLN0, "EventLog", 		NULL};

/*************************************************************************
 * Информационная модель устройства
 *************************************************************************/
IedModel iedModel = {
	_swREV,//"MR771",
	&iedModel_Generic_LD0,
	NULL,//&iedModelds_LD0_LLN0_dataset0,				// DataSet
    NULL,//&iedModel_LD0_LLN0_report0,					// ReportControlBlock
    NULL,//&iedModel_LD0_LLN0_gse0,						// GSEControlBlock
    NULL,												// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,							// SettingGroupControlBlock
    &iedModel_LD0_LLN0_lcb0,							// LogControlBlock
    &iedModel_LD0_LLN0_log0,							// Log
    initializeValues
};
/*************************************************************************
 * стартовые величины при включении
 *************************************************************************/
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
// ----------------------------------------------------------------------------
// LLN0
// ----------------------------------------------------------------------------
iedModel_LD0_LLN0_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LLN0_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);

iedModel_LD0_LLN0_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LLN0_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LLN0_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LLN0_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LLN0_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_LD0_LLN0_NamPlt_d.mmsValue 			= MmsValue_newVisibleString(_SWRevision);
iedModel_LD0_LLN0_NamPlt_ldNs.mmsValue 			= MmsValue_newVisibleString(_LDNS);

// ----------------------------------------------------------------------------
// LPHD1
// ----------------------------------------------------------------------------
iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_PhyHealth_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LPHD1_Proxy_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_Proxy_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LPHD1_PhyNam_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);

// ----------------------------------------------------------------------------
// RDRE
// ----------------------------------------------------------------------------
iedModel_LD0_RDRE1_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_RDRE1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);

iedModel_LD0_RDRE1_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_LD0_RDRE1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_LD0_RDRE1_NamPlt_d.mmsValue 			= MmsValue_newVisibleString(_SWRevision);

iedModel_LD0_RDRE1_RCBMade_stVal.mmsValue 		= MmsValue_newBoolean(0);
iedModel_LD0_RDRE1_RCBMade_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_FltNum_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(0);
iedModel_LD0_RDRE1_FltNum_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);


/******************************************************************************
 * PROT
 ******************************************************************************/
// ----------------------------------------------------------------------------
// LLN0
// ----------------------------------------------------------------------------
iedModel_PROT_LLN0_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_LLN0_Mod_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_LLN0_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LLN0_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);

iedModel_PROT_LLN0_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_LLN0_Beh_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_LLN0_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_LLN0_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_LLN0_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LLN0_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LLN0_NamPlt_ldNs.mmsValue 		= MmsValue_newVisibleString(_LDNS);
iedModel_PROT_LLN0_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_LLN0_NamPlt_d.mmsValue 			= MmsValue_newVisibleString(_SWRevision);

// ----------------------------------------------------------------------------
// LPHD1
// ----------------------------------------------------------------------------
iedModel_PROT_LPHD1_PhyHealth_stVal.mmsValue 	= MmsValue_newIntegerFromInt32(1);
iedModel_PROT_LPHD1_PhyHealth_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_PROT_LPHD1_PhyHealth_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LPHD1_Proxy_stVal.mmsValue 		= MmsValue_newBoolean(false);
iedModel_PROT_LPHD1_Proxy_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LPHD1_PhyNam_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);

// ----------------------------------------------------------------------------
// IPTOC
// ----------------------------------------------------------------------------
iedModel_PROT_IPTOC1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC2_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC3_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC4_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC5_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC6_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_IPTOC1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC2_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC3_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC4_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC5_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC6_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_IPTOC1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC5_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTOC6_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_IPTOC1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC1_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC2_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC3_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC4_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC5_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IPTOC6_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_PROT_IPTOC1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC2_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC3_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC4_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC5_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC5_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC6_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTOC6_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_IPTOC1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC2_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC3_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC4_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC5_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC5_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTOC6_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTOC6_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
// IPTUС1
// ----------------------------------------------------------------------------
iedModel_PROT_IPTUC1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTUC1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IPTUC1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_IPTUC1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTUC1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IPTUC1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IPTUC1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_IPTUC1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// I20PTOC1
// ----------------------------------------------------------------------------
iedModel_PROT_I20PTOC1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC2_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC3_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC4_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC5_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC6_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC7_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC8_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_I20PTOC1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC2_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC3_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC4_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC5_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC6_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC7_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC8_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_I20PTOC1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC5_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC6_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC7_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I20PTOC8_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_I20PTOC1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC1_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC2_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC2_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC3_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC3_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC4_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC4_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC5_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC5_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC6_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC6_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC7_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC7_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC8_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I20PTOC8_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_I20PTOC1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC2_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC2_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC3_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC3_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC4_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC4_NamPlt_swRev.mmsValue	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC5_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC5_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC6_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC6_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC7_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC7_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_I20PTOC8_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I20PTOC8_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);


// ----------------------------------------------------------------------------
// I2I1PTOC1
// ----------------------------------------------------------------------------
iedModel_PROT_I2I1PTOC1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I2I1PTOC1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_I2I1PTOC1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_I2I1PTOC1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_I2I1PTOC1_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_I2I1PTOC1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_I2I1PTOC1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
// UPTOV1
// ----------------------------------------------------------------------------
iedModel_PROT_UPTOV1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTOV2_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV2_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTOV3_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV3_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTOV4_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV4_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTOV4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTOV1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV2_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV3_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTOV4_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTOV4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_UPTOV1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV2_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV3_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV4_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTOV4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_UPTOV1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV2_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV3_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTOV4_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// UPTUV1
// ----------------------------------------------------------------------------
iedModel_PROT_UPTUV1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTUV2_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV2_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTUV3_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV3_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTUV4_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV4_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_UPTUV4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_UPTUV1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV2_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV3_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_UPTUV4_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_UPTUV4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_UPTUV1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV2_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV3_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV4_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_UPTUV4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_UPTUV1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV2_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV3_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_UPTUV4_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// PTOF1
// ----------------------------------------------------------------------------
iedModel_PROT_PTOF1_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF1_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTOF2_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF2_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTOF3_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF3_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTOF4_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF4_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTOF4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTOF1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF2_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF3_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTOF4_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTOF4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_PTOF1_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF2_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF3_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF4_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTOF4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PTOF1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF2_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF3_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTOF4_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// PTUF1
// ----------------------------------------------------------------------------
iedModel_PROT_PTUF1_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF1_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTUF2_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF2_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTUF3_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF3_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTUF4_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF4_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PTUF4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);

iedModel_PROT_PTUF1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF2_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF3_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PTUF4_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PTUF4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_PTUF1_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF2_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF3_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF4_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PTUF4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PTUF1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF2_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF3_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_PTUF4_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// PDPR
// ----------------------------------------------------------------------------
iedModel_PROT_PDPR1_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR1_Mod_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_PDPR1_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR1_Beh_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_PDPR1_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDPR1_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_PDPR1_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDPR1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_PDPR1_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_PDPR2_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR2_Mod_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_PDPR2_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR2_Beh_q.mmsValue 				= MmsValue_newBitString(0);
iedModel_PROT_PDPR2_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDPR2_Health_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_PDPR2_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR2_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDPR2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_PROT_PDPR2_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// IARCPTOC
// ----------------------------------------------------------------------------
iedModel_PROT_IARCPTOC_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IARCPTOC_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IARCPTOC_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IARCPTOC_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_IARCPTOC_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_IARCPTOC_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IARCPTOC_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_IARCPTOC_Health_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_PROT_IARCPTOC_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_IARCPTOC_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IARCPTOC_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

iedModel_PROT_IARCPTOC_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IARCPTOC_Op_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IARCPTOC_Str_dirGeneral.mmsValue 	= MmsValue_newIntegerFromInt16(Dir_not);

// ----------------------------------------------------------------------------
// VZGGIO
// ----------------------------------------------------------------------------
iedModel_PROT_VZGGIO1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO2_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO2_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO3_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO3_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO4_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO4_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO5_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO5_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO6_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO6_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO7_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO7_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO8_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO8_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO9_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO9_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO10_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO10_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO11_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO11_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO12_NamPlt_vendor.mmsValue	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO12_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO13_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO13_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO14_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO14_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO15_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO15_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO16_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO16_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

iedModel_PROT_VZGGIO1_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Alm_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Health_t.mmsValue	 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Mod_t.mmsValue	 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Beh_t.mmsValue	 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_PROT_VZGGIO1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_PROT_VZGGIO1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_PROT_VZGGIO1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);

// ----------------------------------------------------------------------------
// PDIS
// ----------------------------------------------------------------------------
//PDIS1
iedModel_PROT_PDIS1_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS1_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS1_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS1_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS1_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);


//PDIS2
iedModel_PROT_PDIS2_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS2_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS2_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS2_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS2_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS2_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS2_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS2_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS2_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS2_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

//PDIS3
iedModel_PROT_PDIS3_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS3_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS3_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS3_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS3_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS3_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS3_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS3_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS3_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS3_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

//PDIS4
iedModel_PROT_PDIS4_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS4_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS4_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS4_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS4_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS4_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS4_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS4_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS4_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS4_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

//PDIS5
iedModel_PROT_PDIS5_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS5_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS5_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS5_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS5_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS5_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS5_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS5_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS5_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS5_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

//PDIS6
iedModel_PROT_PDIS6_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS6_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS6_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS6_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDIS6_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDIS6_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS6_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDIS6_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_PROT_PDIS6_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDIS6_Str_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
// BLKPTTR1
// ----------------------------------------------------------------------------
iedModel_PROT_BLKPTTR1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BLKPTTR1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BLKPTTR1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BLKPTTR1_TmpRI_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BLKPTTR1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_BLKPTTR1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_BLKPTTR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_BLKPTTR1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_BLKPTTR1_TmpRI_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_PROT_BLKPTTR1_TmpRI_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
// QPTTR
// ----------------------------------------------------------------------------
iedModel_PROT_QPTTR1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_TmpRI_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_QPTTR1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_QPTTR1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_QPTTR1_TmpRI_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_PROT_QPTTR1_TmpRI_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

//QPTTR2
iedModel_PROT_QPTTR2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_TmpRI_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_QPTTR2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_QPTTR2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_QPTTR2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_QPTTR2_TmpRI_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_PROT_QPTTR2_TmpRI_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
// RPSB1
// ----------------------------------------------------------------------------
iedModel_PROT_RPSB1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RPSB1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_RPSB1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RPSB1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RPSB1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_PROT_RPSB1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RPSB1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_RPSB1_Health_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_PROT_RPSB1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RPSB1_Str_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn3_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn4_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn5_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RPSB1_BlkZn6_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_PROT_RPSB1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RPSB1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
// RREC1
// ----------------------------------------------------------------------------
iedModel_PROT_RREC1_AutoRecSt_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(1);		//всегда должно равняться единице
iedModel_PROT_RREC1_AutoRecSt_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_PROT_RREC1_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC1_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC1_Op_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC1_AutoRecSt_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RREC1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_RREC1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RREC1_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RREC1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
// AVRGGIO
// ----------------------------------------------------------------------------
iedModel_PROT_AVRGGIO_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_AVRGGIO_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_AVRGGIO_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_AVRGGIO_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_AVRGGIO_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_AVRGGIO_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_AVRGGIO_IntIn_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
//NBLKGGIO1
// ----------------------------------------------------------------------------
iedModel_PROT_NBLKGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_NBLKGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_NBLKGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_NBLKGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_NBLKGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_NBLKGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_NBLKGGIO1_IntIn_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
//RBRF1
// ----------------------------------------------------------------------------
iedModel_PROT_RBRF1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RBRF1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RBRF1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RBRF1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RBRF1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RBRF1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RBRF1_OpEx_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RBRF1_OpIn_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RBRF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RBRF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
//RSYN1
// ----------------------------------------------------------------------------
iedModel_PROT_RSYN1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RSYN1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RSYN1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RSYN1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_RSYN1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_RSYN1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_RSYN1_Rel_q.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RSYN1_DifVCIc_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RSYN1_DifHzCIc_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RSYN1_DifAngCIc_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_PROT_RSYN1_DifVCIc_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_PROT_RSYN1_DifVCIc_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_PROT_RSYN1_DifHzCIc_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db_difHZ);
iedModel_PROT_RSYN1_DifHzCIc_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb_difHZ);
iedModel_PROT_RSYN1_DifAngCIc_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_DifAngCIc_db);
iedModel_PROT_RSYN1_DifAngCIc_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_DifAngCIc_Zerodb);


iedModel_PROT_RSYN1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_RSYN1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_RSYN1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_RSYN1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
//PDPR1
// ----------------------------------------------------------------------------
iedModel_PROT_PDPR1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PDPR1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PDPR1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDPR1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDPR1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//PDPR2
iedModel_PROT_PDPR2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PDPR2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_PROT_PDPR2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_PDPR2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_PDPR2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_PDPR2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_PDPR2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_PDPR2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

// ----------------------------------------------------------------------------
//ID0PDIF1
// ----------------------------------------------------------------------------
iedModel_PROT_ID0PDIF1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_ID0PDIF1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_ID0PDIF1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_ID0PDIF1_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_ID0PDIF1_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF1_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//ID0PDIF2
iedModel_PROT_ID0PDIF2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_ID0PDIF2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_ID0PDIF2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_ID0PDIF2_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_ID0PDIF2_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF2_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//ID0PDIF3
iedModel_PROT_ID0PDIF3_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF3_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF3_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_ID0PDIF3_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF3_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF3_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_ID0PDIF3_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_ID0PDIF3_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_ID0PDIF3_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_ID0PDIF3_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_ID0PDIF3_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
//IDPDIF
// ----------------------------------------------------------------------------
iedModel_PROT_IDPDIF_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDPDIF_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDPDIF_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);
iedModel_PROT_IDPDIF_RstA_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_RstA_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_RstA_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_DifACIc_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_DifACIc_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_DifACIc_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_IDPDIF_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDPDIF_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
//IDDPDIF
// ----------------------------------------------------------------------------
iedModel_PROT_IDDPDIF_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDDPDIF_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDDPDIF_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_IDDPDIF_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDDPDIF_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------
//IDDMPDIF
// ----------------------------------------------------------------------------
iedModel_PROT_IDDMPDIF_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_IDDMPDIF_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_IDDMPDIF_Str_dirGeneral.mmsValue = MmsValue_newIntegerFromInt16(Dir_not);

iedModel_PROT_IDDMPDIF_Str_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_IDDMPDIF_Op_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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
iedModel_CTRL_LLN0_NamPlt_d.mmsValue 		= MmsValue_newVisibleString(_SWRevision);

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


//CSWI1 --------------------------------------------------------------------------------
iedModel_CTRL_CSWI1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Pos_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Health_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CSWI1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Pos_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CSWI1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//iedModel_CTRL_CSWI1_Mod_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
//iedModel_CTRL_CSWI1_Pos_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);

iedModel_CTRL_CSWI1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_CSWI1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);


//XCBR1 --------------------------------------------------------------------------------
iedModel_CTRL_XCBR1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_CTRL_XCBR1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_XCBR1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//USART_TRACE("CTRL_XCBR1_Mod\n");

iedModel_CTRL_XCBR1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_XCBR1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
//USART_TRACE("CTRL_XCBR1_Beh\n");

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
iedModel_CTRL_XCBR1_BlkCls_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_CTRL_XCBR1_BlkCls_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


iedModel_CTRL_XCBR1_CBOpCap_stVal.mmsValue = MmsValue_newUnsignedFromUint32(1);
iedModel_CTRL_XCBR1_CBOpCap_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_XCBR1_CBOpCap_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_XCBR1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_XCBR1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

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
iedModel_CTRL_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
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

/*
iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the alarm log");//Сброс флага новой записи в журнале аварий
iedModel_CTRL_GGIO1_SPCSO4_d.mmsValue = MmsValue_newVisibleString("Reset the LEDs and Relays");//Сброс индикации
*/

iedModel_CTRL_GGIO1_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
/*
iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
*/
// ----------------------------------------------------------------------------
//СCMD24GGIO1 -----------------------------------------------------------------
// ----------------------------------------------------------------------------
iedModel_CTRL_CMD24GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_CMD24GGIO1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CMD24GGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_CMD24GGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_CMD24GGIO1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_CMD24GGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_CMD24GGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_CTRL_CMD24GGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_CMD24GGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_CMD24GGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_CTRL_CMD24GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO5_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO6_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO7_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO8_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO9_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO10_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO11_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO12_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO13_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO14_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO15_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO16_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO17_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO18_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO19_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO20_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO21_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO22_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO23_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_CMD24GGIO1_SPCSO24_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
/*
iedModel_CTRL_CMD24GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("CMD1");
iedModel_CTRL_CMD24GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("CMD2");
iedModel_CTRL_CMD24GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("CMD3");
iedModel_CTRL_CMD24GGIO1_SPCSO4_d.mmsValue = MmsValue_newVisibleString("CMD4");
iedModel_CTRL_CMD24GGIO1_SPCSO5_d.mmsValue = MmsValue_newVisibleString("CMD5");
iedModel_CTRL_CMD24GGIO1_SPCSO6_d.mmsValue = MmsValue_newVisibleString("CMD6");
iedModel_CTRL_CMD24GGIO1_SPCSO7_d.mmsValue = MmsValue_newVisibleString("CMD7");
iedModel_CTRL_CMD24GGIO1_SPCSO8_d.mmsValue = MmsValue_newVisibleString("CMD8");
iedModel_CTRL_CMD24GGIO1_SPCSO9_d.mmsValue = MmsValue_newVisibleString("CMD9");
iedModel_CTRL_CMD24GGIO1_SPCSO10_d.mmsValue = MmsValue_newVisibleString("CMD10");
iedModel_CTRL_CMD24GGIO1_SPCSO11_d.mmsValue = MmsValue_newVisibleString("CMD11");
iedModel_CTRL_CMD24GGIO1_SPCSO12_d.mmsValue = MmsValue_newVisibleString("CMD12");
iedModel_CTRL_CMD24GGIO1_SPCSO13_d.mmsValue = MmsValue_newVisibleString("CMD13");
iedModel_CTRL_CMD24GGIO1_SPCSO14_d.mmsValue = MmsValue_newVisibleString("CMD14");
iedModel_CTRL_CMD24GGIO1_SPCSO15_d.mmsValue = MmsValue_newVisibleString("CMD15");
iedModel_CTRL_CMD24GGIO1_SPCSO16_d.mmsValue = MmsValue_newVisibleString("CMD16");
iedModel_CTRL_CMD24GGIO1_SPCSO17_d.mmsValue = MmsValue_newVisibleString("CMD17");
iedModel_CTRL_CMD24GGIO1_SPCSO18_d.mmsValue = MmsValue_newVisibleString("CMD18");
iedModel_CTRL_CMD24GGIO1_SPCSO19_d.mmsValue = MmsValue_newVisibleString("CMD19");
iedModel_CTRL_CMD24GGIO1_SPCSO20_d.mmsValue = MmsValue_newVisibleString("CMD20");
iedModel_CTRL_CMD24GGIO1_SPCSO21_d.mmsValue = MmsValue_newVisibleString("CMD21");
iedModel_CTRL_CMD24GGIO1_SPCSO22_d.mmsValue = MmsValue_newVisibleString("CMD22");
iedModel_CTRL_CMD24GGIO1_SPCSO23_d.mmsValue = MmsValue_newVisibleString("CMD23");
iedModel_CTRL_CMD24GGIO1_SPCSO24_d.mmsValue = MmsValue_newVisibleString("CMD24");
*/
iedModel_CTRL_CMD24GGIO1_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO17_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO18_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO19_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO20_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO21_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO22_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO23_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_CMD24GGIO1_SPCSO24_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

/*
iedModel_CTRL_CMD24GGIO1_SPCSO1_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO2_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO3_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO4_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO5_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO6_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO7_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO8_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO9_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO10_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO11_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO12_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO13_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO14_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO15_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO16_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO17_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO18_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO19_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO20_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO21_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO22_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO23_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
iedModel_CTRL_CMD24GGIO1_SPCSO24_Oper_ctlVal.mmsValue = MmsValue_newBoolean(false);
*/
/******************************************************************************
 * GGIO
 ******************************************************************************/
iedModel_GGIO_LLN0_Mod_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Mod_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LLN0_Beh_stVal.mmsValue 			= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Beh_t.mmsValue 				= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LLN0_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LLN0_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_GGIO_LLN0_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LLN0_NamPlt_ldNs.mmsValue 		= MmsValue_newVisibleString(_LDNS);
iedModel_GGIO_LLN0_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
iedModel_GGIO_LLN0_NamPlt_d.mmsValue 			= MmsValue_newVisibleString(_SWRevision);

iedModel_GGIO_LPHD1_PhyHealth_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(1);
iedModel_GGIO_LPHD1_PhyNam_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_LPHD1_Proxy_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LPHD1_Proxy_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LPHD1_PhyHealth_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_GGIO_LPHD1_PhyHealth_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

//INGGIO1
iedModel_GGIO_INGGIO1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_INGGIO1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_INGGIO1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_INGGIO1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_INGGIO1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_INGGIO1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

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
iedModel_GGIO_INGGIO1_Ind17_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind18_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind19_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind20_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind21_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind22_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind23_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind24_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind25_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind26_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind27_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind28_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind29_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind30_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind31_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind32_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind33_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind34_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind35_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind36_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind37_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind38_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind39_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind40_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind41_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind42_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind43_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind44_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind45_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind46_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind47_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind48_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind49_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind50_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind51_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind52_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind53_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind54_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind55_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind56_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind57_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind58_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

// ----------------------------------------------------------------------------

//OUTGGIO1
iedModel_GGIO_OUTGGIO1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_OUTGGIO1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_OUTGGIO1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_OUTGGIO1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

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
iedModel_GGIO_OUTGGIO1_SPCSO17_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO18_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO19_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO20_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO21_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO22_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO23_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO24_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO25_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO26_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO27_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO28_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO29_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO30_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO31_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO32_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO33_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO34_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO35_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO36_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO37_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO38_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO39_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO40_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO41_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO42_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO43_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO44_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO45_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO46_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO47_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO48_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO49_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO50_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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
iedModel_GGIO_LEDGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LEDGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

/*
iedModel_GGIO_LEDGGIO1_Ind1_dU.mmsValue = MmsValue_newMmsString("LED1");
iedModel_GGIO_LEDGGIO1_Ind2_dU.mmsValue = MmsValue_newMmsString("LED2");
iedModel_GGIO_LEDGGIO1_Ind3_dU.mmsValue = MmsValue_newMmsString("LED3");
iedModel_GGIO_LEDGGIO1_Ind4_dU.mmsValue = MmsValue_newMmsString("LED4");
iedModel_GGIO_LEDGGIO1_Ind5_dU.mmsValue = MmsValue_newMmsString("LED5");
iedModel_GGIO_LEDGGIO1_Ind6_dU.mmsValue = MmsValue_newMmsString("LED6");
iedModel_GGIO_LEDGGIO1_Ind7_dU.mmsValue = MmsValue_newMmsString("LED7");
iedModel_GGIO_LEDGGIO1_Ind8_dU.mmsValue = MmsValue_newMmsString("LED8");
iedModel_GGIO_LEDGGIO1_Ind9_dU.mmsValue = MmsValue_newMmsString("LED9");
iedModel_GGIO_LEDGGIO1_Ind10_dU.mmsValue = MmsValue_newMmsString("LED10");
iedModel_GGIO_LEDGGIO1_Ind11_dU.mmsValue = MmsValue_newMmsString("LED11");
iedModel_GGIO_LEDGGIO1_Ind12_dU.mmsValue = MmsValue_newMmsString("LED12");
*/
iedModel_GGIO_LEDGGIO1_Ind13_dU.mmsValue = MmsValue_newMmsString("LED System Log");
iedModel_GGIO_LEDGGIO1_Ind14_dU.mmsValue = MmsValue_newMmsString("LED Alarm Log");
iedModel_GGIO_LEDGGIO1_Ind15_dU.mmsValue = MmsValue_newMmsString("LED CB is opened");
iedModel_GGIO_LEDGGIO1_Ind16_dU.mmsValue = MmsValue_newMmsString("LED CB is closed");


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
iedModel_GGIO_SSLGGIO1_Ind25_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind26_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind27_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind28_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind29_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind30_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind31_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind32_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind33_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind34_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind35_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind36_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind37_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind38_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind39_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind40_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind41_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind42_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind43_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind44_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind45_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind46_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind47_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Ind48_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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
iedModel_GGIO_VLSGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_VLSGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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
iedModel_GGIO_LSGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_LSGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//RST
iedModel_GGIO_RSTGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_RSTGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_RSTGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_RSTGGIO1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_RSTGGIO1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_RSTGGIO1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_GGIO_RSTGGIO1_Ind1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_RSTGGIO1_Ind16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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

// ----------------------------------------------------------------------------
// PQS1MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_PQS1MMXU1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_PQS1MMXU1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_PQS1MMXU1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_PQS1MMXU1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_PQS1MMXU1_Mod_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_PQS1MMXU1_Beh_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_PQS1MMXU1_Health_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_MES_PQS1MMXU1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_PQS1MMXU1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

//MMXU1 TotVAr
iedModel_MES_PQS1MMXU1_totVAr_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_totVAr_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// TotVAr db,zeroDb
iedModel_MES_PQS1MMXU1_totVAr_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db_W);
iedModel_MES_PQS1MMXU1_totVAr_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb_W);

//MMXU1 TotW
iedModel_MES_PQS1MMXU1_totW_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_totW_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// TotW db,zeroDb
iedModel_MES_PQS1MMXU1_totW_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db_W);
iedModel_MES_PQS1MMXU1_totW_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb_W);

//MMXU1 TotPF
iedModel_MES_PQS1MMXU1_totPF_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_PQS1MMXU1_totPF_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// TotPF db,zeroDb
iedModel_MES_PQS1MMXU1_totPF_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_totPF_db);
iedModel_MES_PQS1MMXU1_totPF_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_totPF_Zerodb);

// ----------------------------------------------------------------------------
// S1MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_S1MMXU1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S1MMXU1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MMXU1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MMXU1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MMXU1_Mod_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S1MMXU1_Beh_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S1MMXU1_Health_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_MES_S1MMXU1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_S1MMXU1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

//MMXU1 A
iedModel_MES_S1MMXU1_A_phsA_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_A_phsB_t.mmsValue	 	= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_A_phsC_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_A_phsA_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MMXU1_A_phsB_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MMXU1_A_phsC_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// A db,zeroDb
iedModel_MES_S1MMXU1_A_phsA_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MMXU1_A_phsA_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S1MMXU1_A_phsB_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MMXU1_A_phsB_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S1MMXU1_A_phsC_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MMXU1_A_phsC_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);

iedModel_MES_S1MMXU1_A_neut_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MMXU1_A_neut_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MMXU1_A_neut_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db_In);
iedModel_MES_S1MMXU1_A_neut_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb_In);

// ----------------------------------------------------------------------------
// S2MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_S2MMXU1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S2MMXU1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MMXU1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MMXU1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MMXU1_Mod_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S2MMXU1_Beh_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S2MMXU1_Health_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_MES_S2MMXU1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_S2MMXU1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

//MMXU1 A
iedModel_MES_S2MMXU1_A_phsA_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_A_phsB_t.mmsValue	 	= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_A_phsC_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_A_phsA_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MMXU1_A_phsB_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MMXU1_A_phsC_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// A db,zeroDb
iedModel_MES_S2MMXU1_A_phsA_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MMXU1_A_phsA_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S2MMXU1_A_phsB_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MMXU1_A_phsB_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S2MMXU1_A_phsC_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MMXU1_A_phsC_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);

iedModel_MES_S2MMXU1_A_neut_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MMXU1_A_neut_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MMXU1_A_neut_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db_In);
iedModel_MES_S2MMXU1_A_neut_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb_In);

// ----------------------------------------------------------------------------
// S3MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_S3MMXU1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S3MMXU1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MMXU1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MMXU1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MMXU1_Mod_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S3MMXU1_Beh_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S3MMXU1_Health_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_MES_S3MMXU1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_S3MMXU1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

//MMXU1 A
iedModel_MES_S3MMXU1_A_phsA_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_A_phsB_t.mmsValue	 	= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_A_phsC_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_A_phsA_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MMXU1_A_phsB_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MMXU1_A_phsC_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// A db,zeroDb
iedModel_MES_S3MMXU1_A_phsA_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MMXU1_A_phsA_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S3MMXU1_A_phsB_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MMXU1_A_phsB_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S3MMXU1_A_phsC_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MMXU1_A_phsC_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);

iedModel_MES_S3MMXU1_A_neut_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MMXU1_A_neut_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MMXU1_A_neut_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db_In);
iedModel_MES_S3MMXU1_A_neut_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb_In);

// ----------------------------------------------------------------------------
// S4MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_S4MMXU1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S4MMXU1_Mod_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MMXU1_Beh_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MMXU1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MMXU1_Mod_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S4MMXU1_Beh_q.mmsValue 		= MmsValue_newBitString(0);
iedModel_MES_S4MMXU1_Health_q.mmsValue 		= MmsValue_newBitString(0);

iedModel_MES_S4MMXU1_Mod_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_Beh_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_S4MMXU1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

//MMXU1 A
iedModel_MES_S4MMXU1_A_phsA_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_A_phsB_t.mmsValue	 	= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_A_phsC_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_A_phsA_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MMXU1_A_phsB_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MMXU1_A_phsC_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
// A db,zeroDb
iedModel_MES_S4MMXU1_A_phsA_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MMXU1_A_phsA_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S4MMXU1_A_phsB_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MMXU1_A_phsB_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S4MMXU1_A_phsC_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MMXU1_A_phsC_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb);

iedModel_MES_S4MMXU1_A_neut_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MMXU1_A_neut_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MMXU1_A_neut_db.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_db_In);
iedModel_MES_S4MMXU1_A_neut_zeroDb.mmsValue = MmsValue_newUnsignedFromUint32(_Default_Zerodb_In);

// ----------------------------------------------------------------------------
//U1MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_U1MMXU1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_U1MMXU1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U1MMXU1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U1MMXU1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_MES_U1MMXU1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_U1MMXU1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_U1MMXU1_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_MES_U1MMXU1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_U1MMXU1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//U1MMXU1 phV
iedModel_MES_U1MMXU1_phV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_phV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_phV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_MES_U1MMXU1_phV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MMXU1_phV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MMXU1_phV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

//U1MMXU1 PPV
iedModel_MES_U1MMXU1_PPV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_PPV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_PPV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MMXU1_PPV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MMXU1_PPV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MMXU1_PPV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

// ----------------------------------------------------------------------------
//U2MMXU1
// ----------------------------------------------------------------------------
iedModel_MES_U2MMXU1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_U2MMXU1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U2MMXU1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U2MMXU1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_MES_U2MMXU1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_U2MMXU1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_U2MMXU1_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_MES_U2MMXU1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_U2MMXU1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//U2MMXU1 phV
iedModel_MES_U2MMXU1_phV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_phV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_phV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_MES_U2MMXU1_phV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MMXU1_phV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MMXU1_phV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

//U2MMXU1 PPV
iedModel_MES_U2MMXU1_PPV_phsA_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_PPV_phsB_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_PPV_phsC_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MMXU1_PPV_phsA_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MMXU1_PPV_phsB_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MMXU1_PPV_phsC_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

// ----------------------------------------------------------------------------
//UNMMXN1
// ----------------------------------------------------------------------------
iedModel_MES_UNMMXN1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_UNMMXN1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_UNMMXN1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_UNMMXN1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_MES_UNMMXN1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_UNMMXN1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_UNMMXN1_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_MES_UNMMXN1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_UNMMXN1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_UNMMXN1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_UNMMXN1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_UNMMXN1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//UNMMXN1 Vol
iedModel_MES_UNMMXN1_Vol_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_UNMMXN1_Vol_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

// ----------------------------------------------------------------------------
//FMMXN1
// ----------------------------------------------------------------------------
iedModel_MES_FMMXN1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_FMMXN1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_FMMXN1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_FMMXN1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_MES_FMMXN1_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_FMMXN1_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_MES_FMMXN1_Health_q.mmsValue = MmsValue_newBitString(0);

iedModel_MES_FMMXN1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_FMMXN1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_FMMXN1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_FMMXN1_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_MES_FMMXN1_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

//FMMXN1 Hz
iedModel_MES_FMMXN1_Hz_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_FMMXN1_Hz_q.mmsValue = MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);

// ----------------------------------------------------------------------------
//S1MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_S1MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S1MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S1MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S1MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S1MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_S1MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_S1MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_S1MSQI1_SeqA_I1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_SeqA_I1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MSQI1_SeqA_I2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_SeqA_I2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MSQI1_SeqA_I0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S1MSQI1_SeqA_I0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S1MSQI1_SeqA_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqA db,zeroDb
iedModel_MES_S1MSQI1_SeqA_I1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MSQI1_SeqA_I1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S1MSQI1_SeqA_I2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MSQI1_SeqA_I2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S1MSQI1_SeqA_I0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S1MSQI1_SeqA_I0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
//S2MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_S2MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S2MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S2MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S2MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S2MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_S2MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_S2MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_S2MSQI1_SeqA_I1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_SeqA_I1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MSQI1_SeqA_I2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_SeqA_I2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MSQI1_SeqA_I0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S2MSQI1_SeqA_I0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S2MSQI1_SeqA_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqA db,zeroDb
iedModel_MES_S2MSQI1_SeqA_I1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MSQI1_SeqA_I1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S2MSQI1_SeqA_I2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MSQI1_SeqA_I2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S2MSQI1_SeqA_I0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S2MSQI1_SeqA_I0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
//S3MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_S3MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S3MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S3MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S3MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S3MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_S3MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_S3MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_S3MSQI1_SeqA_I1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_SeqA_I1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MSQI1_SeqA_I2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_SeqA_I2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MSQI1_SeqA_I0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S3MSQI1_SeqA_I0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S3MSQI1_SeqA_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqA db,zeroDb
iedModel_MES_S3MSQI1_SeqA_I1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MSQI1_SeqA_I1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S3MSQI1_SeqA_I2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MSQI1_SeqA_I2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S3MSQI1_SeqA_I0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S3MSQI1_SeqA_I0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
//S4MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_S4MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_S4MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_S4MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S4MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_S4MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_S4MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_S4MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_S4MSQI1_SeqA_I1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_SeqA_I1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MSQI1_SeqA_I2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_SeqA_I2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MSQI1_SeqA_I0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_S4MSQI1_SeqA_I0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_S4MSQI1_SeqA_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqA db,zeroDb
iedModel_MES_S4MSQI1_SeqA_I1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MSQI1_SeqA_I1_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S4MSQI1_SeqA_I2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MSQI1_SeqA_I2_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_S4MSQI1_SeqA_I0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_S4MSQI1_SeqA_I0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
//U1MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_U1MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_U1MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U1MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U1MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U1MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_U1MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_U1MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_U1MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_U1MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_U1MSQI1_SeqU_U1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_SeqU_U1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MSQI1_SeqU_U2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_SeqU_U2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MSQI1_SeqU_U0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U1MSQI1_SeqU_U0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U1MSQI1_SeqU_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqU db,zeroDb
iedModel_MES_U1MSQI1_SeqU_U1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U1MSQI1_SeqU_U1_zeroDb.mmsValue	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_U1MSQI1_SeqU_U2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U1MSQI1_SeqU_U2_zeroDb.mmsValue	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_U1MSQI1_SeqU_U0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U1MSQI1_SeqU_U0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
//U2MSQI1
// ----------------------------------------------------------------------------
iedModel_MES_U2MSQI1_Mod_ctlModel.mmsValue 		= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_MES_U2MSQI1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U2MSQI1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U2MSQI1_Health_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_MES_U2MSQI1_Mod_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_U2MSQI1_Beh_q.mmsValue 			= MmsValue_newBitString(0);
iedModel_MES_U2MSQI1_Health_q.mmsValue 			= MmsValue_newBitString(0);

iedModel_MES_U2MSQI1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_Health_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_MES_U2MSQI1_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);

iedModel_MES_U2MSQI1_SeqU_U1_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_SeqU_U1_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MSQI1_SeqU_U2_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_SeqU_U2_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MSQI1_SeqU_U0_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_MES_U2MSQI1_SeqU_U0_q.mmsValue 		= MmsValue_newBitString(QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_OLD_DATA);
iedModel_MES_U2MSQI1_SeqU_SeqT.mmsValue 		= MmsValue_newIntegerFromInt32(STVALCODEDENUM_POS_NEG_ZERO);

// SeqU db,zeroDb
iedModel_MES_U2MSQI1_SeqU_U1_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U2MSQI1_SeqU_U1_zeroDb.mmsValue	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_U2MSQI1_SeqU_U2_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U2MSQI1_SeqU_U2_zeroDb.mmsValue	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);
iedModel_MES_U2MSQI1_SeqU_U0_db.mmsValue 		= MmsValue_newUnsignedFromUint32(_Default_db);
iedModel_MES_U2MSQI1_SeqU_U0_zeroDb.mmsValue 	= MmsValue_newUnsignedFromUint32(_Default_Zerodb);

// ----------------------------------------------------------------------------
// Указываем какие данные нужно анализировать для ускорения гусов
// ----------------------------------------------------------------------------
// Обновление данных в структуре чеpеp функции
#if (1)
iedModel_GGIO_INGGIO1_Ind1_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind2_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind3_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind4_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind5_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind6_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind7_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind8_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind9_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind10_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind11_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind12_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind13_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind14_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind15_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind16_stVal.mmsValue = MmsValue_newBoolean(0);

iedModel_GGIO_INGGIO1_Ind1_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind2_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind3_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind4_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind5_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind6_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind7_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind8_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind9_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind10_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind11_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind12_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind13_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind14_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind15_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind16_q.mmsValue = MmsValue_newBitString(0);

MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind1_stVal.mmsValue, IDU_FUNC_INGGIO, 1 | TIME_mask);	// | QUALITY_mask если надо качество
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind2_stVal.mmsValue, IDU_FUNC_INGGIO, 2 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind3_stVal.mmsValue, IDU_FUNC_INGGIO, 3 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind4_stVal.mmsValue, IDU_FUNC_INGGIO, 4 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind5_stVal.mmsValue, IDU_FUNC_INGGIO, 5 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind6_stVal.mmsValue, IDU_FUNC_INGGIO, 6 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind7_stVal.mmsValue, IDU_FUNC_INGGIO, 7 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind8_stVal.mmsValue, IDU_FUNC_INGGIO, 8 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind9_stVal.mmsValue, IDU_FUNC_INGGIO, 9 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind10_stVal.mmsValue, IDU_FUNC_INGGIO, 10 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind11_stVal.mmsValue, IDU_FUNC_INGGIO, 11 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind12_stVal.mmsValue, IDU_FUNC_INGGIO, 12 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind13_stVal.mmsValue, IDU_FUNC_INGGIO, 13 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind14_stVal.mmsValue, IDU_FUNC_INGGIO, 14 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind15_stVal.mmsValue, IDU_FUNC_INGGIO, 15 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind16_stVal.mmsValue, IDU_FUNC_INGGIO, 16 | TIME_mask);

MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind1_q.mmsValue, IDU_FUNC_INGGIO, 1 | QUALITY_mask);	// | QUALITY_mask если надо качество
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind2_q.mmsValue, IDU_FUNC_INGGIO, 2 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind3_q.mmsValue, IDU_FUNC_INGGIO, 3 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind4_q.mmsValue, IDU_FUNC_INGGIO, 4 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind5_q.mmsValue, IDU_FUNC_INGGIO, 5 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind6_q.mmsValue, IDU_FUNC_INGGIO, 6 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind7_q.mmsValue, IDU_FUNC_INGGIO, 7 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind8_q.mmsValue, IDU_FUNC_INGGIO, 8 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind9_q.mmsValue, IDU_FUNC_INGGIO, 9 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind10_q.mmsValue, IDU_FUNC_INGGIO, 10 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind11_q.mmsValue, IDU_FUNC_INGGIO, 11 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind12_q.mmsValue, IDU_FUNC_INGGIO, 12 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind13_q.mmsValue, IDU_FUNC_INGGIO, 13 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind14_q.mmsValue, IDU_FUNC_INGGIO, 14 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind15_q.mmsValue, IDU_FUNC_INGGIO, 15 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind16_q.mmsValue, IDU_FUNC_INGGIO, 16 | QUALITY_mask);
#endif

#if (1)
iedModel_GGIO_SSLGGIO1_Ind1_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind2_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind3_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind4_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind5_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind6_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind7_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind8_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind9_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind10_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind11_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind12_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind13_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind14_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind15_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind16_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind17_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind18_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind19_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind20_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind21_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind22_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind23_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind24_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind25_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind26_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind27_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind28_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind29_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind30_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind31_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind32_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind33_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind34_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind35_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind36_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind37_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind38_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind39_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind40_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind41_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind42_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind43_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind44_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind45_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind46_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind47_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_SSLGGIO1_Ind48_stVal.mmsValue = MmsValue_newBoolean(0);

iedModel_GGIO_SSLGGIO1_Ind1_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind2_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind3_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind4_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind5_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind6_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind7_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind8_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind9_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind10_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind11_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind12_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind13_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind14_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind15_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind16_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind17_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind18_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind19_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind20_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind21_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind22_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind23_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind24_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind25_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind26_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind27_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind28_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind29_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind30_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind31_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind32_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind33_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind34_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind35_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind36_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind37_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind38_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind39_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind40_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind41_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind42_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind43_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind44_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind45_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind46_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind47_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_SSLGGIO1_Ind48_q.mmsValue = MmsValue_newBitString(0);

MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind1_stVal.mmsValue, IDU_FUNC_SSLGGIO, 1 | TIME_mask);	// | QUALITY_mask если надо качество
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind2_stVal.mmsValue, IDU_FUNC_SSLGGIO, 2 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind3_stVal.mmsValue, IDU_FUNC_SSLGGIO, 3 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind4_stVal.mmsValue, IDU_FUNC_SSLGGIO, 4 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind5_stVal.mmsValue, IDU_FUNC_SSLGGIO, 5 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind6_stVal.mmsValue, IDU_FUNC_SSLGGIO, 6 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind7_stVal.mmsValue, IDU_FUNC_SSLGGIO, 7 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind8_stVal.mmsValue, IDU_FUNC_SSLGGIO, 8 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind9_stVal.mmsValue, IDU_FUNC_SSLGGIO, 9 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind10_stVal.mmsValue, IDU_FUNC_SSLGGIO, 10 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind11_stVal.mmsValue, IDU_FUNC_SSLGGIO, 11 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind12_stVal.mmsValue, IDU_FUNC_SSLGGIO, 12 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind13_stVal.mmsValue, IDU_FUNC_SSLGGIO, 13 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind14_stVal.mmsValue, IDU_FUNC_SSLGGIO, 14 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind15_stVal.mmsValue, IDU_FUNC_SSLGGIO, 15 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind16_stVal.mmsValue, IDU_FUNC_SSLGGIO, 16 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind17_stVal.mmsValue, IDU_FUNC_SSLGGIO, 17 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind18_stVal.mmsValue, IDU_FUNC_SSLGGIO, 18 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind19_stVal.mmsValue, IDU_FUNC_SSLGGIO, 19 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind20_stVal.mmsValue, IDU_FUNC_SSLGGIO, 20 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind21_stVal.mmsValue, IDU_FUNC_SSLGGIO, 21 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind22_stVal.mmsValue, IDU_FUNC_SSLGGIO, 22 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind23_stVal.mmsValue, IDU_FUNC_SSLGGIO, 23 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind24_stVal.mmsValue, IDU_FUNC_SSLGGIO, 24 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind25_stVal.mmsValue, IDU_FUNC_SSLGGIO, 25 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind26_stVal.mmsValue, IDU_FUNC_SSLGGIO, 26 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind27_stVal.mmsValue, IDU_FUNC_SSLGGIO, 27 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind28_stVal.mmsValue, IDU_FUNC_SSLGGIO, 28 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind29_stVal.mmsValue, IDU_FUNC_SSLGGIO, 29 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind30_stVal.mmsValue, IDU_FUNC_SSLGGIO, 30 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind31_stVal.mmsValue, IDU_FUNC_SSLGGIO, 31 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind32_stVal.mmsValue, IDU_FUNC_SSLGGIO, 32 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind33_stVal.mmsValue, IDU_FUNC_SSLGGIO, 33 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind34_stVal.mmsValue, IDU_FUNC_SSLGGIO, 34 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind35_stVal.mmsValue, IDU_FUNC_SSLGGIO, 35 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind36_stVal.mmsValue, IDU_FUNC_SSLGGIO, 36 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind37_stVal.mmsValue, IDU_FUNC_SSLGGIO, 37 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind38_stVal.mmsValue, IDU_FUNC_SSLGGIO, 38 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind39_stVal.mmsValue, IDU_FUNC_SSLGGIO, 39 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind40_stVal.mmsValue, IDU_FUNC_SSLGGIO, 40 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind41_stVal.mmsValue, IDU_FUNC_SSLGGIO, 41 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind42_stVal.mmsValue, IDU_FUNC_SSLGGIO, 42 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind43_stVal.mmsValue, IDU_FUNC_SSLGGIO, 43 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind44_stVal.mmsValue, IDU_FUNC_SSLGGIO, 44 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind45_stVal.mmsValue, IDU_FUNC_SSLGGIO, 45 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind46_stVal.mmsValue, IDU_FUNC_SSLGGIO, 46 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind47_stVal.mmsValue, IDU_FUNC_SSLGGIO, 47 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind48_stVal.mmsValue, IDU_FUNC_SSLGGIO, 48 | TIME_mask);

MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind1_q.mmsValue, IDU_FUNC_SSLGGIO, 1 | QUALITY_mask);	// | QUALITY_mask если надо качество
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind2_q.mmsValue, IDU_FUNC_SSLGGIO, 2 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind3_q.mmsValue, IDU_FUNC_SSLGGIO, 3 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind4_q.mmsValue, IDU_FUNC_SSLGGIO, 4 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind5_q.mmsValue, IDU_FUNC_SSLGGIO, 5 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind6_q.mmsValue, IDU_FUNC_SSLGGIO, 6 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind7_q.mmsValue, IDU_FUNC_SSLGGIO, 7 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind8_q.mmsValue, IDU_FUNC_SSLGGIO, 8 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind9_q.mmsValue, IDU_FUNC_SSLGGIO, 9 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind10_q.mmsValue, IDU_FUNC_SSLGGIO, 10 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind11_q.mmsValue, IDU_FUNC_SSLGGIO, 11 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind12_q.mmsValue, IDU_FUNC_SSLGGIO, 12 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind13_q.mmsValue, IDU_FUNC_SSLGGIO, 13 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind14_q.mmsValue, IDU_FUNC_SSLGGIO, 14 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind15_q.mmsValue, IDU_FUNC_SSLGGIO, 15 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind16_q.mmsValue, IDU_FUNC_SSLGGIO, 16 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind17_q.mmsValue, IDU_FUNC_SSLGGIO, 17 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind18_q.mmsValue, IDU_FUNC_SSLGGIO, 18 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind19_q.mmsValue, IDU_FUNC_SSLGGIO, 19 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind20_q.mmsValue, IDU_FUNC_SSLGGIO, 20 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind21_q.mmsValue, IDU_FUNC_SSLGGIO, 21 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind22_q.mmsValue, IDU_FUNC_SSLGGIO, 22 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind23_q.mmsValue, IDU_FUNC_SSLGGIO, 23 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind24_q.mmsValue, IDU_FUNC_SSLGGIO, 24 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind25_q.mmsValue, IDU_FUNC_SSLGGIO, 25 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind26_q.mmsValue, IDU_FUNC_SSLGGIO, 26 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind27_q.mmsValue, IDU_FUNC_SSLGGIO, 27 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind28_q.mmsValue, IDU_FUNC_SSLGGIO, 28 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind29_q.mmsValue, IDU_FUNC_SSLGGIO, 29 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind30_q.mmsValue, IDU_FUNC_SSLGGIO, 30 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind31_q.mmsValue, IDU_FUNC_SSLGGIO, 31 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind32_q.mmsValue, IDU_FUNC_SSLGGIO, 32 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind33_q.mmsValue, IDU_FUNC_SSLGGIO, 33 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind34_q.mmsValue, IDU_FUNC_SSLGGIO, 34 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind35_q.mmsValue, IDU_FUNC_SSLGGIO, 35 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind36_q.mmsValue, IDU_FUNC_SSLGGIO, 36 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind37_q.mmsValue, IDU_FUNC_SSLGGIO, 37 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind38_q.mmsValue, IDU_FUNC_SSLGGIO, 38 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind39_q.mmsValue, IDU_FUNC_SSLGGIO, 39 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind40_q.mmsValue, IDU_FUNC_SSLGGIO, 40 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind41_q.mmsValue, IDU_FUNC_SSLGGIO, 41 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind42_q.mmsValue, IDU_FUNC_SSLGGIO, 42 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind43_q.mmsValue, IDU_FUNC_SSLGGIO, 43 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind44_q.mmsValue, IDU_FUNC_SSLGGIO, 44 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind45_q.mmsValue, IDU_FUNC_SSLGGIO, 45 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind46_q.mmsValue, IDU_FUNC_SSLGGIO, 46 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind47_q.mmsValue, IDU_FUNC_SSLGGIO, 47 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_SSLGGIO1_Ind48_q.mmsValue, IDU_FUNC_SSLGGIO, 48 | QUALITY_mask);
#endif
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
}
#endif 

