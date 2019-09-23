/*
 * static_model_MR76x.c
 *
 * automatically generated from simpleIO_direct_control.scd
 *
 *      МР761ОБР
 *      Заменить IN42GGIO на IN74GGIO.
 *      Удалить:
 *      все IPTOC IPTUC IARC PTOV PTUV PTOF PTUF PDPR PTTR RREC RSYN RBRF AVRGGIO NBLKGGIO RPSB PDIS.
 *      Добавить в логическое устройство CTRL узел GGIO2 с возможностью формирования 32-х команд управления (Команда 1 – Команда 32) с использованием SPCSO1… SPCSO32.
 *      Удалить логическое устройство MES
 *      в версии МР761ОБР с подпиской на гус будет как минимум одно отличие: SSL32GGIO заменится на SSL48GGIO.
 *
 *
 */

#if  defined (MR761OBR)

#include "stdlib.h"
#include "model.h"
#include "main.h"
#include "static_model_MR761OBR.h"
#include "IEC850.h"

#include "dataUpdateFromBase.h"

#include "dataDbzeroDB.h"

#include "ld_startvalue.h"

//IedModel iedModel;

extern 	xQueueHandle 	ModbusSentQueue;		// очередь для отправки в модбас


static void initializeValues();

/***********************************************************************
 * логические устройства
 ***********************************************************************/

LogicalDevice iedModel_Generic_LD0;
LogicalDevice iedModel_Generic_PROT;
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

DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
DataAttribute iedModel_LD0_LLN0_SGCB_q;
DataAttribute iedModel_LD0_LLN0_SGCB_t;

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

LogicalNode iedModel_LD0_RDRE1;

DataObject iedModel_LD0_RDRE1_Mod;
DataAttribute iedModel_LD0_RDRE1_Mod_q;
DataAttribute iedModel_LD0_RDRE1_Mod_t;
DataAttribute iedModel_LD0_RDRE1_Mod_stVal;
DataAttribute iedModel_LD0_RDRE1_Mod_ctlModel;
DataObject iedModel_LD0_RDRE1_Beh;
DataAttribute iedModel_LD0_RDRE1_Beh_stVal;
DataAttribute iedModel_LD0_RDRE1_Beh_q;
DataAttribute iedModel_LD0_RDRE1_Beh_t;
DataObject iedModel_LD0_RDRE1_Health;
DataAttribute iedModel_LD0_RDRE1_Health_stVal;
DataAttribute iedModel_LD0_RDRE1_Health_q;
DataAttribute iedModel_LD0_RDRE1_Health_t;
DataObject iedModel_LD0_RDRE1_NamPlt;
DataAttribute iedModel_LD0_RDRE1_NamPlt_vendor;
DataAttribute iedModel_LD0_RDRE1_NamPlt_swRev;
DataAttribute iedModel_LD0_RDRE1_NamPlt_d;

DataObject iedModel_LD0_RDRE1_RCBMade;
DataAttribute iedModel_LD0_RDRE1_RCBMade_stVal;
DataAttribute iedModel_LD0_RDRE1_RCBMade_q;
DataAttribute iedModel_LD0_RDRE1_RCBMade_t;

DataObject iedModel_LD0_RDRE1_FltNum;
DataAttribute iedModel_LD0_RDRE1_FltNum_stVal;
DataAttribute iedModel_LD0_RDRE1_FltNum_q;
DataAttribute iedModel_LD0_RDRE1_FltNum_t;

// ---------------------------------------------------------------------------------------------------------
// 000   000    00   00000
// 0  0  0  0  0  0    0
// 0  0  0  0  0  0    0
// 000   000   0  0    0
// 0     0 0   0  0    0
// 0     0  0   00     0
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

//----------------------------------------------------------------------------
// VZGGIO1
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO1;

DataObject iedModel_PROT_VZGGIO1_Mod;
DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;

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
// VZGGIO2
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO2;
DataObject iedModel_PROT_VZGGIO2_Mod;
DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;

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
// VZGGIO3
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO3;

DataObject iedModel_PROT_VZGGIO3_Mod;
DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;

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
// VZGGIO4
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO4;
DataObject iedModel_PROT_VZGGIO4_Mod;
DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;

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
// VZGGIO5
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO5;
DataObject iedModel_PROT_VZGGIO5_Mod;
DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;

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
// VZGGIO6
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO6;
DataObject iedModel_PROT_VZGGIO6_Mod;
DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;

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
// VZGGIO7
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO7;
DataObject iedModel_PROT_VZGGIO7_Mod;
DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;

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
// VZGGIO8
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO8;
DataObject iedModel_PROT_VZGGIO8_Mod;
DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;

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

//----------------------------------------------------------------------------
// VZGGIO9
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO9;

DataObject iedModel_PROT_VZGGIO9_Mod;
DataAttribute iedModel_PROT_VZGGIO9_Mod_q;
DataAttribute iedModel_PROT_VZGGIO9_Mod_t;
DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal;

DataObject iedModel_PROT_VZGGIO9_Beh;
DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Beh_q;
DataAttribute iedModel_PROT_VZGGIO9_Beh_t;

DataObject iedModel_PROT_VZGGIO9_Health;
DataAttribute iedModel_PROT_VZGGIO9_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Health_q;
DataAttribute iedModel_PROT_VZGGIO9_Health_t;

DataObject iedModel_PROT_VZGGIO9_NamPlt;
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d;

DataObject iedModel_PROT_VZGGIO9_Alm;
DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO9_Alm_q;
DataAttribute iedModel_PROT_VZGGIO9_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO10
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO10;

DataObject iedModel_PROT_VZGGIO10_Mod;
DataAttribute iedModel_PROT_VZGGIO10_Mod_q;
DataAttribute iedModel_PROT_VZGGIO10_Mod_t;
DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal;

DataObject iedModel_PROT_VZGGIO10_Beh;
DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Beh_q;
DataAttribute iedModel_PROT_VZGGIO10_Beh_t;

DataObject iedModel_PROT_VZGGIO10_Health;
DataAttribute iedModel_PROT_VZGGIO10_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Health_q;
DataAttribute iedModel_PROT_VZGGIO10_Health_t;

DataObject iedModel_PROT_VZGGIO10_NamPlt;
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d;

DataObject iedModel_PROT_VZGGIO10_Alm;
DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO10_Alm_q;
DataAttribute iedModel_PROT_VZGGIO10_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO11
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO11;

DataObject iedModel_PROT_VZGGIO11_Mod;
DataAttribute iedModel_PROT_VZGGIO11_Mod_q;
DataAttribute iedModel_PROT_VZGGIO11_Mod_t;
DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal;

DataObject iedModel_PROT_VZGGIO11_Beh;
DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Beh_q;
DataAttribute iedModel_PROT_VZGGIO11_Beh_t;

DataObject iedModel_PROT_VZGGIO11_Health;
DataAttribute iedModel_PROT_VZGGIO11_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Health_q;
DataAttribute iedModel_PROT_VZGGIO11_Health_t;

DataObject iedModel_PROT_VZGGIO11_NamPlt;

DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d;

DataObject iedModel_PROT_VZGGIO11_Alm;
DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO11_Alm_q;
DataAttribute iedModel_PROT_VZGGIO11_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO12
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO12;

DataObject iedModel_PROT_VZGGIO12_Mod;
DataAttribute iedModel_PROT_VZGGIO12_Mod_q;
DataAttribute iedModel_PROT_VZGGIO12_Mod_t;
DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal;

DataObject iedModel_PROT_VZGGIO12_Beh;
DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Beh_q;
DataAttribute iedModel_PROT_VZGGIO12_Beh_t;

DataObject iedModel_PROT_VZGGIO12_Health;
DataAttribute iedModel_PROT_VZGGIO12_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Health_q;
DataAttribute iedModel_PROT_VZGGIO12_Health_t;

DataObject iedModel_PROT_VZGGIO12_NamPlt;
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d;

DataObject iedModel_PROT_VZGGIO12_Alm;
DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO12_Alm_q;
DataAttribute iedModel_PROT_VZGGIO12_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO13
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO13;

DataObject iedModel_PROT_VZGGIO13_Mod;
DataAttribute iedModel_PROT_VZGGIO13_Mod_q;
DataAttribute iedModel_PROT_VZGGIO13_Mod_t;
DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal;

DataObject iedModel_PROT_VZGGIO13_Beh;
DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Beh_q;
DataAttribute iedModel_PROT_VZGGIO13_Beh_t;

DataObject iedModel_PROT_VZGGIO13_Health;
DataAttribute iedModel_PROT_VZGGIO13_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Health_q;
DataAttribute iedModel_PROT_VZGGIO13_Health_t;

DataObject iedModel_PROT_VZGGIO13_NamPlt;
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d;

DataObject iedModel_PROT_VZGGIO13_Alm;
DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO13_Alm_q;
DataAttribute iedModel_PROT_VZGGIO13_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO14
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO14;

DataObject iedModel_PROT_VZGGIO14_Mod;
DataAttribute iedModel_PROT_VZGGIO14_Mod_q;
DataAttribute iedModel_PROT_VZGGIO14_Mod_t;
DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal;

DataObject iedModel_PROT_VZGGIO14_Beh;
DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Beh_q;
DataAttribute iedModel_PROT_VZGGIO14_Beh_t;

DataObject iedModel_PROT_VZGGIO14_Health;
DataAttribute iedModel_PROT_VZGGIO14_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Health_q;
DataAttribute iedModel_PROT_VZGGIO14_Health_t;

DataObject iedModel_PROT_VZGGIO14_NamPlt;
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d;

DataObject iedModel_PROT_VZGGIO14_Alm;
DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO14_Alm_q;
DataAttribute iedModel_PROT_VZGGIO14_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO15
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO15;

DataObject iedModel_PROT_VZGGIO15_Mod;
DataAttribute iedModel_PROT_VZGGIO15_Mod_q;
DataAttribute iedModel_PROT_VZGGIO15_Mod_t;
DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal;

DataObject iedModel_PROT_VZGGIO15_Beh;
DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Beh_q;
DataAttribute iedModel_PROT_VZGGIO15_Beh_t;

DataObject iedModel_PROT_VZGGIO15_Health;
DataAttribute iedModel_PROT_VZGGIO15_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Health_q;
DataAttribute iedModel_PROT_VZGGIO15_Health_t;

DataObject iedModel_PROT_VZGGIO15_NamPlt;
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d;

DataObject iedModel_PROT_VZGGIO15_Alm;
DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO15_Alm_q;
DataAttribute iedModel_PROT_VZGGIO15_Alm_t;

//----------------------------------------------------------------------------
// VZGGIO16
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_VZGGIO16;

DataObject iedModel_PROT_VZGGIO16_Mod;
DataAttribute iedModel_PROT_VZGGIO16_Mod_q;
DataAttribute iedModel_PROT_VZGGIO16_Mod_t;
DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal;

DataObject iedModel_PROT_VZGGIO16_Beh;
DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Beh_q;
DataAttribute iedModel_PROT_VZGGIO16_Beh_t;

DataObject iedModel_PROT_VZGGIO16_Health;
DataAttribute iedModel_PROT_VZGGIO16_Health_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Health_q;
DataAttribute iedModel_PROT_VZGGIO16_Health_t;

DataObject iedModel_PROT_VZGGIO16_NamPlt;
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor;
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev;
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d;

DataObject iedModel_PROT_VZGGIO16_Alm;
DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal;
DataAttribute iedModel_PROT_VZGGIO16_Alm_q;
DataAttribute iedModel_PROT_VZGGIO16_Alm_t;

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

DataObject    iedModel_CTRL_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG;
DataAttribute iedModel_CTRL_LLN0_SGCB_q;
DataAttribute iedModel_CTRL_LLN0_SGCB_t;

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
// CSWI1
//----------------------------------------------------------------------------
LogicalNode   iedModel_CTRL_CSWI1;
DataObject    iedModel_CTRL_CSWI1_Mod;
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

//----------------------------------------------------------------------------
// XCBR1
//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
// PTRC
//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
// GGIO2
//----------------------------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO2;

DataObject iedModel_CTRL_GGIO2_Mod;
DataAttribute iedModel_CTRL_GGIO2_Mod_q;
DataAttribute iedModel_CTRL_GGIO2_Mod_t;
DataAttribute iedModel_CTRL_GGIO2_Mod_stVal;
DataAttribute iedModel_CTRL_GGIO2_Mod_ctlModel;

DataObject iedModel_CTRL_GGIO2_Beh;
DataAttribute iedModel_CTRL_GGIO2_Beh_stVal;
DataAttribute iedModel_CTRL_GGIO2_Beh_q;
DataAttribute iedModel_CTRL_GGIO2_Beh_t;

DataObject iedModel_CTRL_GGIO2_Health;
DataAttribute iedModel_CTRL_GGIO2_Health_stVal;
DataAttribute iedModel_CTRL_GGIO2_Health_q;
DataAttribute iedModel_CTRL_GGIO2_Health_t;

DataObject iedModel_CTRL_GGIO2_NamPlt;
DataAttribute iedModel_CTRL_GGIO2_NamPlt_vendor;
DataAttribute iedModel_CTRL_GGIO2_NamPlt_swRev;
DataAttribute iedModel_CTRL_GGIO2_NamPlt_d;

DataObject iedModel_CTRL_GGIO2_SPCSO1;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Check;

//SPCSO2
DataObject iedModel_CTRL_GGIO2_SPCSO2;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Check;
//SPCSO3
DataObject iedModel_CTRL_GGIO2_SPCSO3;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO4;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO5;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO6;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO7;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO8;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO9;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO10;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO11;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Check;

//SPCSO12
DataObject iedModel_CTRL_GGIO2_SPCSO12;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Check;
//SPCSO13
DataObject iedModel_CTRL_GGIO2_SPCSO13;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO14;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO15;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO16;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO17;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO18;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO19;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO20;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Check;


DataObject iedModel_CTRL_GGIO2_SPCSO21;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Check;

//SPCSO22
DataObject iedModel_CTRL_GGIO2_SPCSO22;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Check;
//SPCSO23
DataObject iedModel_CTRL_GGIO2_SPCSO23;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO24;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO25;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO26;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO27;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO28;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO29;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO30;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO31;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Check;

DataObject iedModel_CTRL_GGIO2_SPCSO32;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_q;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_t;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_d;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_stVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_ctlModel;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlVal;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orCat;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orIdent;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlNum;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_T;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Test;
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Check;

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

DataObject    iedModel_GGIO_LLN0_SGCB;							// SGCB - Управление группами уставок
DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG;
DataAttribute iedModel_GGIO_LLN0_SGCB_q;
DataAttribute iedModel_GGIO_LLN0_SGCB_t;

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
//SPCSO2
DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO2;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
//SPCSO3
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
//SPCSO4
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
//SPCSO5
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
//SPCSO6
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
//SPCSO7
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
//SPCSO8
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
//SPCSO9
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO9;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;
//SPCSO10
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO10;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;
//SPCSO11
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO11;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;
//SPCSO12
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO12;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;
//SPCSO13
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO13;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;
//SPCSO14
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO14;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;
//SPCSO15
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO15;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;
//SPCSO16
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO16;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal;
//SPCSO17
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO17;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal;
//SPCSO18
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO18;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal;
//SPCSO19
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO19;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_stVal;
//SPCSO20
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO20;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_stVal;
//SPCSO21
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO21;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_stVal;
//SPCSO22
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO22;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_stVal;
//SPCSO23
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO23;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_stVal;
//SPCSO24
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO24;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_stVal;
//SPCSO25
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO25;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_stVal;
//SPCSO26
DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO26;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_stVal;
//SPCSO27
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO27;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_stVal;
//SPCSO28
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO28;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_stVal;
//SPCSO29
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO29;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_stVal;
//SPCSO30
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO30;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_stVal;
//SPCSO31
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO31;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_stVal;
//SPCSO32
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO32;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_stVal;
//SPCSO33
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO33;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_stVal;
//SPCSO34
DataObject    iedModel_GGIO_OUTGGIO1_SPCSO34;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_q;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_t;
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_stVal;

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

DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;

DataObject    iedModel_GGIO_LEDGGIO1_Ind13;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind14;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind15;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_dU;

DataObject    iedModel_GGIO_LEDGGIO1_Ind16;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t;
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_dU;

// ------------------------------------------------------------
// IN
// ------------------------------------------------------------

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

DataObject    iedModel_GGIO_INGGIO1_Ind17;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind17_t;

DataObject    iedModel_GGIO_INGGIO1_Ind18;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind18_t;

DataObject    iedModel_GGIO_INGGIO1_Ind19;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind19_t;

DataObject    iedModel_GGIO_INGGIO1_Ind20;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind20_t;

DataObject    iedModel_GGIO_INGGIO1_Ind21;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind21_t;

DataObject    iedModel_GGIO_INGGIO1_Ind22;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind22_t;

DataObject    iedModel_GGIO_INGGIO1_Ind23;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind23_t;

DataObject    iedModel_GGIO_INGGIO1_Ind24;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind24_t;

DataObject    iedModel_GGIO_INGGIO1_Ind25;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind25_t;

DataObject    iedModel_GGIO_INGGIO1_Ind26;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind26_t;

DataObject    iedModel_GGIO_INGGIO1_Ind27;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind27_t;

DataObject    iedModel_GGIO_INGGIO1_Ind28;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind28_t;

DataObject    iedModel_GGIO_INGGIO1_Ind29;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind29_t;

DataObject    iedModel_GGIO_INGGIO1_Ind30;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind30_t;

DataObject    iedModel_GGIO_INGGIO1_Ind31;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind31_t;

DataObject    iedModel_GGIO_INGGIO1_Ind32;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind32_t;

DataObject    iedModel_GGIO_INGGIO1_Ind33;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind33_t;

DataObject    iedModel_GGIO_INGGIO1_Ind34;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind34_t;

DataObject    iedModel_GGIO_INGGIO1_Ind35;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind35_t;

DataObject    iedModel_GGIO_INGGIO1_Ind36;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind36_t;

DataObject    iedModel_GGIO_INGGIO1_Ind37;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind37_t;

DataObject    iedModel_GGIO_INGGIO1_Ind38;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind38_t;

DataObject    iedModel_GGIO_INGGIO1_Ind39;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind39_t;

DataObject    iedModel_GGIO_INGGIO1_Ind40;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind40_t;

DataObject    iedModel_GGIO_INGGIO1_Ind41;
DataAttribute iedModel_GGIO_INGGIO1_Ind41_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind41_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind41_t;

DataObject    iedModel_GGIO_INGGIO1_Ind42;
DataAttribute iedModel_GGIO_INGGIO1_Ind42_stVal;
DataAttribute iedModel_GGIO_INGGIO1_Ind42_q;
DataAttribute iedModel_GGIO_INGGIO1_Ind42_t;

//----------------------------------------------------------------------------
// SSL
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

DataObject iedModel_GGIO_SSLGGIO1_Ind25;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind26;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind27;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind28;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind29;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind30;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind31;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t;

DataObject iedModel_GGIO_SSLGGIO1_Ind32;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q;
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t;

//----------------------------------------------------------------------------
// VLS
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

DataObject iedModel_GGIO_VLSGGIO1_Ind9;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind10;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind11;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind12;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind13;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind14;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind15;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t;

DataObject iedModel_GGIO_VLSGGIO1_Ind16;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t;

//----------------------------------------------------------------------------
// LS
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

DataObject iedModel_GGIO_LSGGIO1_Ind9;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t;

DataObject iedModel_GGIO_LSGGIO1_Ind10;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t;

DataObject iedModel_GGIO_LSGGIO1_Ind11;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t;

DataObject iedModel_GGIO_LSGGIO1_Ind12;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t;

DataObject iedModel_GGIO_LSGGIO1_Ind13;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t;

DataObject iedModel_GGIO_LSGGIO1_Ind14;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t;

DataObject iedModel_GGIO_LSGGIO1_Ind15;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t;

DataObject iedModel_GGIO_LSGGIO1_Ind16;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q;
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t;


IedModel iedModel = {
	_swREV,//"MR771",
	&iedModel_Generic_LD0,
	NULL,//&iedModelds_LD0_LLN0_dataset0,				// DataSet
    NULL,//&iedModel_LD0_LLN0_report0,					// ReportControlBlock
    NULL,//&iedModel_LD0_LLN0_gse0,						// GSEControlBlock
    NULL,												// SVControlBlock
    &iedModel_LD0_LLN0_sgcb0,							// SettingGroupControlBlock
    NULL,//&iedModel_LD0_LLN0_lcb0,						// LogControlBlock
    NULL,//&iedModel_LD0_LLN0_log0,						// Log
    initializeValues
};
// если убираем статические узлы, не нужно их в памяти держать
#define DataSetNULL
#define ReportControlBlockNULL
#define GSEControlBlockNULL
#define SVControlBlockNULL
#define LogControlBlockNULL

/*************************************************************************
 * Логические устройства LD
 *************************************************************************/
//iedModel_Generic_PROT
LogicalDevice iedModel_Generic_LD0 		= { LogicalDeviceModelType, "LD0",	(ModelNode*)&iedModel,	(ModelNode*)&iedModel_Generic_PROT, (ModelNode*)&iedModel_LD0_LLN0	};
LogicalDevice iedModel_Generic_PROT 	= { LogicalDeviceModelType, "PROT",	(ModelNode*)&iedModel,  (ModelNode*)&iedModel_Generic_CTRL, (ModelNode*)&iedModel_PROT_LLN0	};
LogicalDevice iedModel_Generic_CTRL 	= {	LogicalDeviceModelType, "CTRL",	(ModelNode*)&iedModel, 	(ModelNode*)&iedModel_Generic_GGIO, (ModelNode*)&iedModel_CTRL_LLN0	};
LogicalDevice iedModel_Generic_GGIO 	= { LogicalDeviceModelType, "GGIO",	(ModelNode*)&iedModel,	NULL,								(ModelNode*)&iedModel_GGIO_LLN0	};

/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/

LogicalNode iedModel_LD0_LLN0 					= { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_LD0,	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LLN0_Mod};

DataObject iedModel_LD0_LLN0_Mod 				= { DataObjectModelType,    "Mod",	    	(ModelNode*) &iedModel_LD0_LLN0,	    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,    0};
DataAttribute iedModel_LD0_LLN0_Mod_q 			= { DataAttributeModelType,    "q",    	(ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    (ModelNode*) &iedModel_LD0_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Mod_ctlModel 	= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_LD0_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LLN0_Beh 				= { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_Health 			= { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_LD0_LLN0,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_Health_stVal,    0};
DataAttribute iedModel_LD0_LLN0_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LLN0_Health,    (ModelNode*) &iedModel_LD0_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LLN0_NamPlt 			= { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_LD0_LLN0,    NULL,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_configRev = { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    (ModelNode*) &iedModel_LD0_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_LD0_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};


//----------------------------------------------------------------------------
// LD0_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_LD0_LPHD1 					= { LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_LD0,  (ModelNode*) &iedModel_LD0_RDRE1,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam};

DataObject iedModel_LD0_LPHD1_PhyNam 			= { DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_LD0_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_LD0_LPHD1_PhyHealth 		= { DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_LD0_LPHD1,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_PhyHealth_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_LD0_LPHD1_Proxy 			= { DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_LD0_LPHD1,    NULL,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_stVal 	= { 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_LD0_LPHD1_Proxy, (ModelNode*) &iedModel_LD0_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_LD0_LPHD1_Proxy_q		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    (ModelNode*) &iedModel_LD0_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_LD0_LPHD1_Proxy_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_LD0_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


/*************************************************************************
 * Логический узел LN
 * Логический нуль узла LLN0
 *************************************************************************/
LogicalNode iedModel_PROT_LLN0 					= { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_PROT,	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LLN0_Mod};

DataObject iedModel_PROT_LLN0_Mod 				= { DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_PROT_LLN0,	    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Mod_q,    0};
DataAttribute iedModel_PROT_LLN0_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    (ModelNode*) &iedModel_PROT_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Mod_ctlModel 	= { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LLN0_Beh 				= { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Beh_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    (ModelNode*) &iedModel_PROT_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_Health = { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_PROT_LLN0,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_Health_stVal,    0};
DataAttribute iedModel_PROT_LLN0_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LLN0_Health,    (ModelNode*) &iedModel_PROT_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_Health_t		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LLN0_NamPlt 			= { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_PROT_LLN0,    NULL,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_configRev = { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    (ModelNode*) &iedModel_PROT_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs 	= { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_PROT_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//----------------------------------------------------------------------------
// PROT_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_PROT_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam};

DataObject iedModel_PROT_LPHD1_PhyNam = 			{ DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor = 	{ DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_PROT_LPHD1_PhyHealth = 			{ DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_PROT_LPHD1,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_q = 	{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_PhyHealth_t = 	{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_PROT_LPHD1_Proxy = 				{ DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_PROT_LPHD1,    NULL,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_PROT_LPHD1_Proxy, (ModelNode*) &iedModel_PROT_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_PROT_LPHD1_Proxy_q = 		{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    (ModelNode*) &iedModel_PROT_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_PROT_LPHD1_Proxy_t = 		{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


/************************************************************************
 * CTRL_LLN0
 *************************************************************************/
LogicalNode iedModel_CTRL_LLN0 = { LogicalNodeModelType,    "LLN0",	    (ModelNode*)&iedModel_Generic_CTRL,	   (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LLN0_Mod,};

DataObject iedModel_CTRL_LLN0_Mod = { DataObjectModelType,    "Mod",	    (ModelNode*) &iedModel_CTRL_LLN0,	    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_q,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_stVal,   NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    (ModelNode*) &iedModel_CTRL_LLN0_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel = { DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_CTRL_LLN0_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Beh = { DataObjectModelType,    "Beh",	    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    (ModelNode*) &iedModel_CTRL_LLN0_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_Health = { DataObjectModelType,    "Health",			    (ModelNode*) &iedModel_CTRL_LLN0,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_Health_stVal,    0};
DataAttribute iedModel_CTRL_LLN0_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    (ModelNode*) &iedModel_CTRL_LLN0_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LLN0_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LLN0_NamPlt = { DataObjectModelType,    "NamPlt",								    (ModelNode*) &iedModel_CTRL_LLN0,    NULL,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_vendor,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_configRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev = { DataAttributeModelType,    "configRev",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt_ldNs,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs = { DataAttributeModelType,    "ldNs",    (ModelNode*) &iedModel_CTRL_LLN0_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_EX,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

//----------------------------------------------------------------------------
// CTRL_LPHD1
//----------------------------------------------------------------------------
LogicalNode iedModel_CTRL_LPHD1 = 					{    LogicalNodeModelType,    "LPHD1",    (ModelNode*)&iedModel_Generic_CTRL,    (ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,};

DataObject iedModel_CTRL_LPHD1_PhyNam = 			{ DataObjectModelType,    "PhyNam",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam_vendor,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor = 	{ DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyNam,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255,    TRG_OPT_NO,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_PhyHealth = 			{ DataObjectModelType,    "PhyHealth",	    (ModelNode*) &iedModel_CTRL_LPHD1,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q = 	{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t = 	{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_PhyHealth,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};

DataObject iedModel_CTRL_LPHD1_Proxy = 				{ DataObjectModelType,    "Proxy",    (ModelNode*) &iedModel_CTRL_LPHD1,    NULL,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_stVal,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal = 	{ 	DataAttributeModelType, "stVal", (ModelNode*) &iedModel_CTRL_LPHD1_Proxy, (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL };
DataAttribute iedModel_CTRL_LPHD1_Proxy_q = 		{ DataAttributeModelType,    "q",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY,    TRG_OPT_NO,    NULL,    0};
DataAttribute iedModel_CTRL_LPHD1_Proxy_t = 		{ DataAttributeModelType,    "t",    (ModelNode*) &iedModel_CTRL_LPHD1_Proxy,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,    NULL,    0};


/************************************************************************
 * GGIO_LLN0
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

//----------------------------------------------------------------------------
// GGIO_LPHD1
//----------------------------------------------------------------------------
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
 * RDRE
 *************************************************************************/
LogicalNode iedModel_LD0_RDRE1 						= { LogicalNodeModelType,   "RDRE1",		(ModelNode*) &iedModel_Generic_LD0,			(ModelNode*)NULL,    							(ModelNode*) &iedModel_LD0_RDRE1_Mod};

DataObject iedModel_LD0_RDRE1_Mod 					= { DataObjectModelType,	"Mod",			(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_Beh,    		(ModelNode*) &iedModel_LD0_RDRE1_Mod_q,0};
DataAttribute iedModel_LD0_RDRE1_Mod_q 				= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_t,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_t 				= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_stVal,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_stVal 			= { DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_LD0_RDRE1_Mod,		(ModelNode*) &iedModel_LD0_RDRE1_Mod_ctlModel,	NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32,     			TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Mod_ctlModel 		= { DataAttributeModelType,	"ctlModel",		(ModelNode*) &iedModel_LD0_RDRE1_Mod,		NULL,    										NULL,    0,	IEC61850_FC_CF,    IEC61850_ENUMERATED, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_Beh 					= { DataObjectModelType,	"Beh",			(ModelNode*) &iedModel_LD0_RDRE1,    		(ModelNode*) &iedModel_LD0_RDRE1_Health,    	(ModelNode*) &iedModel_LD0_RDRE1_Beh_stVal,0};
DataAttribute iedModel_LD0_RDRE1_Beh_stVal 			= { DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_LD0_RDRE1_Beh,		(ModelNode*) &iedModel_LD0_RDRE1_Beh_q,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32, 				TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Beh_q 				= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_LD0_RDRE1_Beh,		(ModelNode*) &iedModel_LD0_RDRE1_Beh_t,    		NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Beh_t 				= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_LD0_RDRE1_Beh,		NULL,    										NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_Health 				= { DataObjectModelType,	"Health",		(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,    	(ModelNode*) &iedModel_LD0_RDRE1_Health_stVal,0};
DataAttribute iedModel_LD0_RDRE1_Health_stVal 		= { DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_LD0_RDRE1_Health,    (ModelNode*) &iedModel_LD0_RDRE1_Health_q,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_INT32, 				TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_Health_q		 	= { DataAttributeModelType,	"q",			(ModelNode*) &iedModel_LD0_RDRE1_Health,    (ModelNode*) &iedModel_LD0_RDRE1_Health_t,    	NULL,    0,	IEC61850_FC_ST,    IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_LD0_RDRE1_Health_t 			= { DataAttributeModelType,	"t",			(ModelNode*) &iedModel_LD0_RDRE1_Health,	NULL,    										NULL,    0,	IEC61850_FC_ST,    IEC61850_TIMESTAMP, 			TRG_OPT_DATA_CHANGED, 		NULL,0};
DataObject iedModel_LD0_RDRE1_NamPlt 				= { DataObjectModelType,	"NamPlt",		(ModelNode*) &iedModel_LD0_RDRE1,    		(ModelNode*)&iedModel_LD0_RDRE1_RCBMade,   		(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_vendor,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_vendor 		= { DataAttributeModelType,	"vendor",		(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_swRev,	NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_swRev 		= { DataAttributeModelType,	"swRev",		(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	(ModelNode*) &iedModel_LD0_RDRE1_NamPlt_d,		NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};
DataAttribute iedModel_LD0_RDRE1_NamPlt_d 			= { DataAttributeModelType,	"d",			(ModelNode*) &iedModel_LD0_RDRE1_NamPlt,	NULL,    										NULL,    0,	IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, 				NULL,0};

DataObject iedModel_LD0_RDRE1_RCBMade 				= {DataObjectModelType,		"RcdMade",		(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) &iedModel_LD0_RDRE1_FltNum,		(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_stVal,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_stVal 		= {DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_q,		NULL,	0,	IEC61850_FC_ST,		IEC61850_BOOLEAN, 			TRG_OPT_DATA_CHANGED,		NULL,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_q 			= {DataAttributeModelType,	"q",			(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	(ModelNode*) &iedModel_LD0_RDRE1_RCBMade_t,		NULL,	0,	IEC61850_FC_ST,		IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,	NULL,0};
DataAttribute iedModel_LD0_RDRE1_RCBMade_t 			= {DataAttributeModelType,	"t",			(ModelNode*) &iedModel_LD0_RDRE1_RCBMade,	NULL,											NULL,	0,	IEC61850_FC_ST,		IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,		NULL,0};

DataObject iedModel_LD0_RDRE1_FltNum 				= {DataObjectModelType,		"FltNum",		(ModelNode*) &iedModel_LD0_RDRE1,			(ModelNode*) NULL,								(ModelNode*) &iedModel_LD0_RDRE1_FltNum_stVal,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_stVal 		= {DataAttributeModelType,	"stVal",		(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	(ModelNode*) &iedModel_LD0_RDRE1_FltNum_q,		NULL,	0,	IEC61850_FC_ST,		IEC61850_INT32, 			TRG_OPT_DATA_CHANGED,		NULL,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_q 			= {DataAttributeModelType,	"q",			(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	(ModelNode*) &iedModel_LD0_RDRE1_FltNum_t,		NULL,	0,	IEC61850_FC_ST,		IEC61850_QUALITY, 			TRG_OPT_QUALITY_CHANGED,	NULL,0};
DataAttribute iedModel_LD0_RDRE1_FltNum_t 			= {DataAttributeModelType,	"t",			(ModelNode*) &iedModel_LD0_RDRE1_FltNum,	NULL,											NULL,	0,	IEC61850_FC_ST,		IEC61850_TIMESTAMP, 		TRG_OPT_DATA_CHANGED,		NULL,0};


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

#if defined (T0N0D74R35)
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN74GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};
#endif
#if defined (T0N0D106R67)
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN106GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};
#endif
#if defined (T0N0D114R59)
LogicalNode iedModel_GGIO_INGGIO1 			= { LogicalNodeModelType,   "IN114GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod};
#endif


DataObject iedModel_GGIO_INGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,(ModelNode*) &iedModel_GGIO_INGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_INGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    (ModelNode*) &iedModel_GGIO_INGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_INGGIO1_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind1 /* &iedModel_GGIO_INGGIO1_SPCSO1*/,															// следующий !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_INGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

/***************************************************************************************************************************************************************
 * Входы двоичных сигналов(дискреты) ОБЩИХ ПРОЦЕССОВ
 ****************************************************************************************************************************************************************/
DataObject iedModel_GGIO_INGGIO1_Ind1 = {DataObjectModelType,"Ind1",(ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind1_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_INGGIO1_Ind1,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

DataObject iedModel_GGIO_INGGIO1_Ind2 = {DataObjectModelType,"Ind2",(ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind2_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind3 = { DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind3_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind4 = { DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind4_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind5 = { DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind5_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind6 = { DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind6_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind7 = { DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind7_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind8 = { DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_INGGIO1,    (ModelNode*)&iedModel_GGIO_INGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind8_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_INGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

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
DataObject iedModel_GGIO_INGGIO1_Ind16 = { DataObjectModelType, "Ind16", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind17 , (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind16_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind16, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind17 = { DataObjectModelType, "Ind17", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind17_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind17, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind18 = { DataObjectModelType, "Ind18", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind18_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind18, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind19 = { DataObjectModelType, "Ind19", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind19_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind19, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind20 = { DataObjectModelType, "Ind20", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind20_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind20, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind21 = { DataObjectModelType, "Ind21", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind21_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind21, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind22 = { DataObjectModelType, "Ind22", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind22_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind22, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind23 = { DataObjectModelType, "Ind23", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind23_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind23, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind24 = { DataObjectModelType, "Ind24", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind24_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind24, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind25 = { DataObjectModelType, "Ind25", (ModelNode*) &iedModel_GGIO_INGGIO1,(ModelNode*)&iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind25_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind25, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind26 = { DataObjectModelType, "Ind26", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind26_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind26, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind27 = { DataObjectModelType, "Ind27", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind27_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind27, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind28 = { DataObjectModelType, "Ind28", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind28_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind28, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind29 = { DataObjectModelType, "Ind29", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind29_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind29, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind30 = { DataObjectModelType, "Ind30", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind30_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind30, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind31 = { DataObjectModelType, "Ind31", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind31_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind31, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind32 = { DataObjectModelType, "Ind32", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind32_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind32, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind33 = { DataObjectModelType, "Ind33", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind33_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind33, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind34 = { DataObjectModelType, "Ind34", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind34_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind34, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind35 = { DataObjectModelType, "Ind35", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind35_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind35, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind36 = { DataObjectModelType, "Ind36", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind36_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind36, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind37 = { DataObjectModelType, "Ind37", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind37_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind37, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind38 = { DataObjectModelType, "Ind38", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind38_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind38, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind39 = { DataObjectModelType, "Ind39", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*)&iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind39_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind39, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind40 = { DataObjectModelType, "Ind40", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind40_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind40, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind41 = { DataObjectModelType, "Ind41", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind41_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind41, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind42 = { DataObjectModelType, "Ind42", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind42_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind42, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind43 = { DataObjectModelType, "Ind43", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind43_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind43, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind44 = { DataObjectModelType, "Ind44", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind44_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind44, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind45 = { DataObjectModelType, "Ind45", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind45_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind45, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind46 = { DataObjectModelType, "Ind46", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind46_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind46, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind47 = { DataObjectModelType, "Ind47", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind47_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind47, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind48 = { DataObjectModelType, "Ind48", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind48_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind48, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind49 = { DataObjectModelType, "Ind49", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind49_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind49, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind50 = { DataObjectModelType, "Ind50", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind50_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind50, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind51 = { DataObjectModelType, "Ind51", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind51_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind51, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind52 = { DataObjectModelType, "Ind52", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind52_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind52, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind53 = { DataObjectModelType, "Ind53", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind53_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind53, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind54 = { DataObjectModelType, "Ind54", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind54_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind54, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind55 = { DataObjectModelType, "Ind55", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind55_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind55, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind56 = { DataObjectModelType, "Ind56", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind56_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind56, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind57 = { DataObjectModelType, "Ind57", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind57_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind57, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind58 = { DataObjectModelType, "Ind58", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind58_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind58, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind59 = { DataObjectModelType, "Ind59", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind59_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind59_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind59_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind59, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind60 = { DataObjectModelType, "Ind60", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind60_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind60_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind60_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind60, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind61 = { DataObjectModelType, "Ind61", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind61_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind61_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind61_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind61, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind62 = { DataObjectModelType, "Ind62", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind62_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind62_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind62_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind62, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind63 = { DataObjectModelType, "Ind63", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind63_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind63_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind63_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind63, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind64 = { DataObjectModelType, "Ind64", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind64_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind64_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind64_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind64, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind65 = { DataObjectModelType, "Ind65", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind65_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind65_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind65_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind65, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind66 = { DataObjectModelType, "Ind66", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind66_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind66_q = { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind66_t = { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind66, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind67 			= { DataObjectModelType, "Ind67", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind67_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind67_q 	= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind67_t 	= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind67, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind68 			= { DataObjectModelType, "Ind68", (ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind69, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind68_stVal = { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind68_q 	= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind68_t 	= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_INGGIO1_Ind68, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind69 			= { DataObjectModelType, "Ind69", 		(ModelNode*) &iedModel_GGIO_INGGIO1, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind70, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind69_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind69_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind69, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind69_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind69_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind69, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind69_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind69_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind69, NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// Ind70 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind70 			= { DataObjectModelType, 	"Ind70", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind70_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind70_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind70, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind70_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind70_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind70, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind70_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind70_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind70, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind71 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind71 			= { DataObjectModelType, 	"Ind71", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind71_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind71_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind71_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind71_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind71, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind72 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind72 			= { DataObjectModelType, 	"Ind72", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind72_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind72_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind72_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind72_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind72, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind73 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind73 			= { DataObjectModelType, 	"Ind73", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind73_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind73_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind73_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind73_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind73, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};

// Ind74 --------------------------------------------------------
#if defined (T0N0D74R35)
DataObject iedModel_GGIO_INGGIO1_Ind74 			= { DataObjectModelType,	"Ind74",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind74_stVal, 0};
#endif
#if  defined (T0N0D106R67) || defined (T0N0D114R59)
DataObject iedModel_GGIO_INGGIO1_Ind74 			= { DataObjectModelType,	"Ind74",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind74_stVal, 0};
#endif

DataAttribute iedModel_GGIO_INGGIO1_Ind74_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind74_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind74_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind74, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind75 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind75 			= { DataObjectModelType,	"Ind75",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind75_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind75_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind75_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind75_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind75, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind76 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind76 			= { DataObjectModelType,	"Ind76",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind76_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind76_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind76_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind76_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind76, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind77 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind77 			= { DataObjectModelType,	"Ind77",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind77_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind77_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind77_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind77_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind77, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind78 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind78 			= { DataObjectModelType,	"Ind78",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind78_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind78_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind78_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind78_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind78, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind79 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind79 			= { DataObjectModelType,	"Ind79",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind79_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind79_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind79_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind79_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind79, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind80 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind80 			= { DataObjectModelType, 	"Ind80", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind80_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind80_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind80_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind80_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind80, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind81 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind81 			= { DataObjectModelType, 	"Ind81", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind81_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind81_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind81_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind81_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind81, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind82 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind82 			= { DataObjectModelType, 	"Ind82", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind82_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind82_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind82_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind82_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind82, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind83 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind83 			= { DataObjectModelType, 	"Ind83", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind83_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind83_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind83_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind83_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind83, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind84 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind84 			= { DataObjectModelType,	"Ind84",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind84_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind84_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind84_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind84_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind84, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind85 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind85 			= { DataObjectModelType,	"Ind85",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind85_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind85_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind85_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind85_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind85, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind86 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind86 			= { DataObjectModelType,	"Ind86",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind86_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind86_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind86_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind86_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind86, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind87 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind87 			= { DataObjectModelType,	"Ind87",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind87_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind87_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind87_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind87_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind87, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind88 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind88 			= { DataObjectModelType,	"Ind88",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind88_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind88_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind88_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind88_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind88, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind89 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind89 			= { DataObjectModelType,	"Ind89",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind89_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind89_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind89_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind89_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind89, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind90 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind90 			= { DataObjectModelType, 	"Ind90", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind90_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind90_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind90_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind90_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind90, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind91 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind91 			= { DataObjectModelType, 	"Ind91", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind91_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind91_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind91_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind91_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind91, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind92 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind92 			= { DataObjectModelType, 	"Ind92", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind92_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind92_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind92_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind92_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind92, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind93 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind93 			= { DataObjectModelType, 	"Ind93", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind93_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind93_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind93_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind93_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind93, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind94 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind94 			= { DataObjectModelType,	"Ind94",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind94_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind94_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind94_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind94_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind94, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind95 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind95 			= { DataObjectModelType,	"Ind95",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind95_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind95_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind95_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind95_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind95, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind96 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind96 			= { DataObjectModelType,	"Ind96",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind96_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind96_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind96_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind96_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind96, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind97 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind97 			= { DataObjectModelType,	"Ind97",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind97_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind97_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind97_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind97_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind97, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind98 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind98 			= { DataObjectModelType,	"Ind98",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind98_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind98_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind98_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind98_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind98, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind99 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind99 			= { DataObjectModelType,	"Ind99",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind99_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind99_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind99_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind99_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind99, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind100 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind100 			= { DataObjectModelType, 	"Ind100", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind100_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind100_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind100_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind100_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind100, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind101 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind101 			= { DataObjectModelType, 	"Ind101", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind101_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind101_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind101_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind101_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind101, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind102 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind102 			= { DataObjectModelType, 	"Ind102", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind102_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind102_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind102_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind102_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind102, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind103 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind103 			= { DataObjectModelType, 	"Ind103", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind103_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind103_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind103_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind103_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind103, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind104 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind104 			= { DataObjectModelType,	"Ind104",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind104_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind104_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind104_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind104_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind104, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind105 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind105 			= { DataObjectModelType,	"Ind105",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind105_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind105_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind105_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind105_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind105, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};

// Ind106 --------------------------------------------------------
#if defined (T0N0D106R67)
DataObject iedModel_GGIO_INGGIO1_Ind106 			= { DataObjectModelType,	"Ind106",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind106_stVal, 0};
#endif
#if defined (T0N0D114R59)
DataObject iedModel_GGIO_INGGIO1_Ind106 			= { DataObjectModelType,	"Ind106",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind106_stVal, 0};
#endif

DataAttribute iedModel_GGIO_INGGIO1_Ind106_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind106_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind106_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind106, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind107 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind107 			= { DataObjectModelType,	"Ind107",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind107_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind107_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind107_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind107_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind107, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind108 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind108 			= { DataObjectModelType,	"Ind108",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind108_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind108_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind108_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind108_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind108, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind109 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind109 			= { DataObjectModelType,	"Ind109",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind109_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind109_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind109_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind109_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind109, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind110 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind110 			= { DataObjectModelType, 	"Ind110", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind110_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind110_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind110_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind110_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind110, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind111 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind111 			= { DataObjectModelType, 	"Ind111", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind111_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind111_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind111_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind111_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind111, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind112 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind112 			= { DataObjectModelType, 	"Ind112", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind112_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind112_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind112_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind112_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind112, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind113 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind113 			= { DataObjectModelType, 	"Ind113", 	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind113_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind113_stVal = { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind113_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind113_t 	= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind113, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};
// Ind114 --------------------------------------------------------
DataObject iedModel_GGIO_INGGIO1_Ind114 			= { DataObjectModelType,	"Ind114",	(ModelNode*) &iedModel_GGIO_INGGIO1, 		(ModelNode*) NULL, (ModelNode*) &iedModel_GGIO_INGGIO1_Ind114_stVal, 0};
DataAttribute iedModel_GGIO_INGGIO1_Ind114_stVal = { DataAttributeModelType, "stVal",	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, 		TRG_OPT_DATA_CHANGED, 		NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind114_q 	= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114, 	(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, 		TRG_OPT_QUALITY_CHANGED, 	NULL,0};
DataAttribute iedModel_GGIO_INGGIO1_Ind114_t		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_INGGIO1_Ind114, 	NULL, 											NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, 		NULL,0};

/*************************************************************************
 * OUTGGIO1 без управления.
 ************************************************************************/

LogicalNode iedModel_GGIO_OUTGGIO1 						= { LogicalNodeModelType,   	"OUT80GGIO1",   (ModelNode*) &iedModel_Generic_GGIO,   (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod};
DataObject iedModel_GGIO_OUTGGIO1_Mod 					= { DataObjectModelType,     	"Mod",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q 				= { DataAttributeModelType,    	"q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t 				= { DataAttributeModelType,    	"t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal 			= { DataAttributeModelType,		"stVal",   (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod,(ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel 		= {   DataAttributeModelType,   "ctlModel",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Mod, (ModelNode*) NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
//Beh
DataObject iedModel_GGIO_OUTGGIO1_Beh 					= { DataObjectModelType,    	"Beh",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal 			= { DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q 				= { DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t 				= { DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_GGIO_OUTGGIO1_Health 					= { DataObjectModelType,    	"Health",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal 		= { DataAttributeModelType,  "stVal",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_q 			= { DataAttributeModelType,  "q",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_Health_t 			= { DataAttributeModelType,  "t",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_GGIO_OUTGGIO1_NamPlt 					= { DataObjectModelType,    	"NamPlt",    (ModelNode*) &iedModel_GGIO_OUTGGIO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor 		= { DataAttributeModelType,  "vendor",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev 		= { DataAttributeModelType,  "swRev",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d 			= { DataAttributeModelType,  "d",    (ModelNode*) &iedModel_GGIO_OUTGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_OUTGGIO1_SPCSO1 					= { DataObjectModelType,	"SPCSO1",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO1, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO2 					= { DataObjectModelType,	"SPCSO2",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*)  &iedModel_GGIO_OUTGGIO1_SPCSO3,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO2, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO3 					= { DataObjectModelType,	"SPCSO3",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO3, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO4 					= { DataObjectModelType,	"SPCSO4",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO4, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO5 					= { DataObjectModelType,	"SPCSO5",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO5, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO6 					= { DataObjectModelType,	"SPCSO6",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO6, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO7 					= { DataObjectModelType,	"SPCSO7",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO7, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO8 					= { DataObjectModelType,	"SPCSO8",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO8, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO9 					= { DataObjectModelType,	"SPCSO9",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO9, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO10 					= { DataObjectModelType,	"SPCSO10",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO10, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO11 					= { DataObjectModelType,	"SPCSO11",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO11, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO12 					= { DataObjectModelType,	"SPCSO12",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO12, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO13 					= { DataObjectModelType,	"SPCSO13",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO13, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO14 					= { DataObjectModelType,	"SPCSO14",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO14, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO15 					= { DataObjectModelType,	"SPCSO15",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO15, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO16 					= { DataObjectModelType,	"SPCSO16",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO16, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO17 					= { DataObjectModelType,	"SPCSO17",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO17, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO18 					= { DataObjectModelType,	"SPCSO18",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO18, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO19 					= { DataObjectModelType,	"SPCSO19",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO19_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO19, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO20 					= { DataObjectModelType,	"SPCSO20",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO20_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO20, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO21 					= { DataObjectModelType,	"SPCSO21",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO21_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO21, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO22 					= { DataObjectModelType,	"SPCSO22",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO22_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO22, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO23 					= { DataObjectModelType,	"SPCSO23",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO23_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO23, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO24 					= { DataObjectModelType,	"SPCSO24",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO24_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO24, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO25 					= { DataObjectModelType,	"SPCSO25",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO25_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO25, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO26 					= { DataObjectModelType,	"SPCSO26",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO26_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO26, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO27 					= { DataObjectModelType,	"SPCSO27",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO27_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO27, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO28 					= { DataObjectModelType,	"SPCSO28",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO28_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO28, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO29 					= { DataObjectModelType,	"SPCSO29",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO29_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO29, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO30 					= { DataObjectModelType,	"SPCSO30",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO30_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO30, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO31 					= { DataObjectModelType,	"SPCSO31",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO31_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO31, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO32 					= { DataObjectModelType,	"SPCSO32",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO32_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO32, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO33 					= { DataObjectModelType,	"SPCSO33",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,					(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_q 				= { DataAttributeModelType,	"q",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_t 				= { DataAttributeModelType,	"t",				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO33_stVal 			= { DataAttributeModelType,	"stVal",			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO33, 			(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO34 					= { DataObjectModelType,	"SPCSO34",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO34_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO34, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO35 					= { DataObjectModelType,	"SPCSO35",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO35_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO35, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO36 					= { DataObjectModelType,	"SPCSO36",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO36_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO36, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO37 					= { DataObjectModelType,	"SPCSO37",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO37_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO37, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO38 					= { DataObjectModelType,	"SPCSO38",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO38_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO38, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO39 					= { DataObjectModelType,	"SPCSO39",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO39_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO39, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO40 					= { DataObjectModelType,	"SPCSO40",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO40_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO40, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO41 					= { DataObjectModelType,	"SPCSO41",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO41_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO41, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO42 					= { DataObjectModelType,	"SPCSO42",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO42_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO42, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO43 					= { DataObjectModelType,	"SPCSO43",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO43_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO43, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO44 					= { DataObjectModelType,	"SPCSO44",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO44_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO44, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO45 					= { DataObjectModelType,	"SPCSO45",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO45_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO45, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO46 					= { DataObjectModelType,	"SPCSO46",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO46_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO46, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO47 					= { DataObjectModelType,	"SPCSO47",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO47_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO47, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO48 					= { DataObjectModelType,	"SPCSO48",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO48_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO48, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO49 					= { DataObjectModelType,	"SPCSO49",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO49_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO49, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO50 					= { DataObjectModelType,	"SPCSO50",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO50_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO50, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO51 					= { DataObjectModelType,	"SPCSO51",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO51_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO51, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO52 					= { DataObjectModelType,	"SPCSO52",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO52_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO52, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO53 					= { DataObjectModelType,	"SPCSO53",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO53_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO53, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO54 					= { DataObjectModelType,	"SPCSO54",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO54_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO54, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO55 					= { DataObjectModelType,	"SPCSO55",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO55_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO55, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO56 					= { DataObjectModelType,	"SPCSO56",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO56_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO56, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO57 					= { DataObjectModelType,	"SPCSO57",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO57_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO57, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO58 					= { DataObjectModelType,	"SPCSO58",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO58_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO58, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO59 					= { DataObjectModelType,	"SPCSO59",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO59_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO59, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO60 					= { DataObjectModelType,	"SPCSO60",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO60_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO60, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO61 					= { DataObjectModelType,	"SPCSO61",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO61_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO61, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO62 					= { DataObjectModelType,	"SPCSO62",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO62_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO62, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO63 					= { DataObjectModelType,	"SPCSO63",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO63_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO63, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO64 					= { DataObjectModelType,	"SPCSO64",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO64_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO64, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO65 					= { DataObjectModelType,	"SPCSO65",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO65_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO65, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO66 					= { DataObjectModelType,	"SPCSO66",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO66_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO66, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO67 					= { DataObjectModelType,	"SPCSO67",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO67_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO67, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO68 					= { DataObjectModelType,	"SPCSO68",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO68_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO68, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO69 					= { DataObjectModelType,	"SPCSO69",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO69_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO69, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO70 					= { DataObjectModelType,	"SPCSO70",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO70_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO70, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO71 					= { DataObjectModelType,	"SPCSO71",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO71_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO71, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO72 					= { DataObjectModelType,	"SPCSO72",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO72_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO72, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO73 					= { DataObjectModelType,	"SPCSO73",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO73_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO73, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO74 					= { DataObjectModelType,	"SPCSO74",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO74_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO74, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO75 					= { DataObjectModelType,	"SPCSO75",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO75_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO75, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO76 					= { DataObjectModelType,	"SPCSO76",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO76_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO76, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO77 					= { DataObjectModelType,	"SPCSO77",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO77_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO77, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO78 					= { DataObjectModelType,	"SPCSO78",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO78_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO78, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO79 					= { DataObjectModelType,	"SPCSO79",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO79_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO79, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_OUTGGIO1_SPCSO80 					= { DataObjectModelType,	"SPCSO80",     		(ModelNode*) &iedModel_GGIO_OUTGGIO1,     				(ModelNode*) NULL,    (ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80_q,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_q 				= { DataAttributeModelType,	"q",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, 	TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_t 				= { DataAttributeModelType,	"t",       			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80, 			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80_stVal,    	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, 	TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO80_stVal 			= { DataAttributeModelType,	"stVal",   			(ModelNode*) &iedModel_GGIO_OUTGGIO1_SPCSO80, 			(ModelNode*) NULL,    									NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, 	TRG_OPT_DATA_CHANGED, NULL,0};


/*************************************************************************
 * LED16GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_LEDGGIO1 					= { LogicalNodeModelType,   "LED16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod};

DataObject iedModel_GGIO_LEDGGIO1_Mod 				= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal 		= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel 	= {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Beh 				= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal 		= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q 			= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t 			= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_Health 			= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Health_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LEDGGIO1_NamPlt 			= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind1,  (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_vendor,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor 	= { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};


DataObject iedModel_GGIO_LEDGGIO1_Ind1 				= { DataObjectModelType,	"Ind1",		(ModelNode*) &iedModel_GGIO_LEDGGIO1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal 	= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q 		= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t 		= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,(ModelNode*) NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU 		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind1,	NULL,    NULL, 	0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind2 				= { DataObjectModelType,	"Ind2",		(ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q 		= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t 		= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind2,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind3 				= { DataObjectModelType,    "Ind3",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind3,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind4 				= { DataObjectModelType,    "Ind4",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind4,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind5 				= { DataObjectModelType,    "Ind5",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind5,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind6 				= { DataObjectModelType,    "Ind6",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind6,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind7 				= { DataObjectModelType,    "Ind7",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind7,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind8 				= { DataObjectModelType,    "Ind8",    (ModelNode*) &iedModel_GGIO_LEDGGIO1,    (ModelNode*)&iedModel_GGIO_LEDGGIO1_Ind9,   (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal 	= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q 		= { DataAttributeModelType, "q",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t 		= { DataAttributeModelType, "t",    (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind8,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind9 				= { DataObjectModelType, 	"Ind9", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind9, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind10 			= { DataObjectModelType, 	"Ind10", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind10, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind11 			= { DataObjectModelType, 	"Ind11", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind11, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind12 			= { DataObjectModelType, 	"Ind12", (ModelNode*) &iedModel_GGIO_LEDGGIO1, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal 	= { DataAttributeModelType, "stVal", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_q, NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q 		= { DataAttributeModelType, "q", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12_t, NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t 		= { DataAttributeModelType, "t", (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind12, NULL, NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind13 			= { DataObjectModelType, 	"Ind13", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13_dU, 	NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_dU 		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind13,	NULL,    										NULL, 0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind14 			= { DataObjectModelType, 	"Ind14", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14_dU, 	NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_dU 		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind14,	NULL,    										NULL, 0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind15 			= { DataObjectModelType, 	"Ind15", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1, 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15_dU, 	NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_dU 		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind15,	NULL,    										NULL, 0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_GGIO_LEDGGIO1_Ind16 			= { DataObjectModelType, 	"Ind16", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1, 		(ModelNode*) NULL, 								(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_stVal, 0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal 	= { DataAttributeModelType, "stVal", 	(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_q, 	NULL, 0, IEC61850_FC_ST, IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q 		= { DataAttributeModelType, "q", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_t, 	NULL, 0, IEC61850_FC_ST, IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t 		= { DataAttributeModelType, "t", 		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16, (ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16_dU, 	NULL, 0, IEC61850_FC_ST, IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_dU 		= { DataAttributeModelType, "dU",  		(ModelNode*) &iedModel_GGIO_LEDGGIO1_Ind16,	(ModelNode*) NULL,    							NULL, 0, IEC61850_FC_DC, IEC61850_UNICODE_STRING_255, TRG_OPT_NO, NULL,0};

/*************************************************************************
 * SSL32GGIO1
 ************************************************************************/
#if (_REVISION_DEVICE < 300)
LogicalNode iedModel_GGIO_SSLGGIO1 				= { LogicalNodeModelType,   "SSL32GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod};
#else
LogicalNode iedModel_GGIO_SSLGGIO1 				= { LogicalNodeModelType,   "SSL48GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod};
#endif

DataObject iedModel_GGIO_SSLGGIO1_Mod 			= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal 	= { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Beh 			= { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal 	= { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q 		= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t 		= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_Health 		= { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Health_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_SSLGGIO1_NamPlt 		= { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_SSLGGIO1,    (ModelNode*)&iedModel_GGIO_SSLGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev 	= { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d 		= { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_SSLGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

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
DataObject iedModel_GGIO_SSLGGIO1_Ind24 = {DataObjectModelType,"Ind24",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind24,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind25 = {DataObjectModelType,"Ind25",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind25,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind26 = {DataObjectModelType,"Ind26",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind26,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind27 = {DataObjectModelType,"Ind27",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind27,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind28 = {DataObjectModelType,"Ind28",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind28,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind29 = {DataObjectModelType,"Ind29",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind29,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind30 = {DataObjectModelType,"Ind30",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind30,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind31 = {DataObjectModelType,"Ind31",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind31,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
#if (_REVISION_DEVICE < 300)
DataObject iedModel_GGIO_SSLGGIO1_Ind32 = {DataObjectModelType,"Ind32",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_stVal,0};
#else
DataObject iedModel_GGIO_SSLGGIO1_Ind32 = {DataObjectModelType,"Ind32",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_stVal,0};
#endif
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind32,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
#if (_REVISION_DEVICE >= 300)
DataObject iedModel_GGIO_SSLGGIO1_Ind33 = {DataObjectModelType,"Ind33",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind33_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind33,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind34 = {DataObjectModelType,"Ind34",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind34_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind34,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind35 = {DataObjectModelType,"Ind35",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind35_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind35,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind36 = {DataObjectModelType,"Ind36",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind36_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind36,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind37 = {DataObjectModelType,"Ind37",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind37_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind37,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind38 = {DataObjectModelType,"Ind38",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind38_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind38,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind39 = {DataObjectModelType,"Ind39",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind39_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind39,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind40 = {DataObjectModelType,"Ind40",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind40_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind40,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind41 = {DataObjectModelType,"Ind41",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind41_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind41,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind42 = {DataObjectModelType,"Ind42",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind42_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind42,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind43 = {DataObjectModelType,"Ind43",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind43_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind43,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind44 = {DataObjectModelType,"Ind44",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind44_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind44,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind45 = {DataObjectModelType,"Ind45",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind45_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind45,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind46 = {DataObjectModelType,"Ind46",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind46_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind46,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind47 = {DataObjectModelType,"Ind47",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48 ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind47_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind47,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_SSLGGIO1_Ind48 = {DataObjectModelType,"Ind48",(ModelNode*) &iedModel_GGIO_SSLGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48_stVal,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48,(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_SSLGGIO1_Ind48_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_SSLGGIO1_Ind48,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------

#endif
/*************************************************************************
 * VLS16GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_VLSGGIO1 			= { LogicalNodeModelType,   "VLS16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod};

DataObject iedModel_GGIO_VLSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_VLSGGIO1_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_VLSGGIO1,    (ModelNode*)&iedModel_GGIO_VLSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_VLSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

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
DataObject iedModel_GGIO_VLSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_VLSGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_VLSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_VLSGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*************************************************************************
 * LS16GGIO1
 ************************************************************************/
LogicalNode iedModel_GGIO_LSGGIO1 			= { LogicalNodeModelType,   "LS16GGIO1",    (ModelNode*)&iedModel_Generic_GGIO,   (ModelNode*)&iedModel_GGIO_RSTGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod};

DataObject iedModel_GGIO_LSGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_q,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,(ModelNode*) &iedModel_GGIO_LSGGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_GGIO_LSGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_GGIO_LSGGIO1_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_GGIO_LSGGIO1,    (ModelNode*)&iedModel_GGIO_LSGGIO1_Ind1 , (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_GGIO_LSGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

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
DataObject iedModel_GGIO_LSGGIO1_Ind8 = {DataObjectModelType,"Ind8",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind8,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind9 = {DataObjectModelType,"Ind9",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind9,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind10 = {DataObjectModelType,"Ind10",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind10,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind11 = {DataObjectModelType,"Ind11",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind11,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind12 = {DataObjectModelType,"Ind12",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind12,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind13 = {DataObjectModelType,"Ind13",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind13,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind14 = {DataObjectModelType,"Ind14",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind14,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind15 = {DataObjectModelType,"Ind15",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16 ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind15,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};
//----------------------------------------------------------------------------
DataObject iedModel_GGIO_LSGGIO1_Ind16 = {DataObjectModelType,"Ind16",(ModelNode*) &iedModel_GGIO_LSGGIO1,(ModelNode*) NULL ,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_stVal,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_GGIO_LSGGIO1_Ind16,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


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

/*******************************************************
 * iedModel_PROT_VZGGIO1
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO1 			= { LogicalNodeModelType,   "VZGGIO1",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod};

DataObject iedModel_PROT_VZGGIO1_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) &iedModel_PROT_VZGGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO1_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    (ModelNode*) &iedModel_PROT_VZGGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO1_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO1,    (ModelNode*)&iedModel_PROT_VZGGIO1_Alm , (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO1_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO1,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,(ModelNode*) &iedModel_PROT_VZGGIO1_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO1_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO1_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO2
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO2 			= { LogicalNodeModelType,   "VZGGIO2",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod};

DataObject iedModel_PROT_VZGGIO2_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) &iedModel_PROT_VZGGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO2_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    (ModelNode*) &iedModel_PROT_VZGGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO2_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO2,    (ModelNode*)&iedModel_PROT_VZGGIO2_Alm , (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO2_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO2,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,(ModelNode*) &iedModel_PROT_VZGGIO2_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO2_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO2_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * iedModel_PROT_VZGGIO3
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO3 			= { LogicalNodeModelType,   "VZGGIO3",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod};

DataObject iedModel_PROT_VZGGIO3_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) &iedModel_PROT_VZGGIO3_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO3_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    (ModelNode*) &iedModel_PROT_VZGGIO3_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO3_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO3_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO3,    (ModelNode*)&iedModel_PROT_VZGGIO3_Alm , (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO3_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO3_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO3,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,(ModelNode*) &iedModel_PROT_VZGGIO3_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO3_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO3_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO4
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO4 			= { LogicalNodeModelType,   "VZGGIO4",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod};

DataObject iedModel_PROT_VZGGIO4_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) &iedModel_PROT_VZGGIO4_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO4_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    (ModelNode*) &iedModel_PROT_VZGGIO4_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO4_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO4_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO4,    (ModelNode*)&iedModel_PROT_VZGGIO4_Alm , (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO4_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO4_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO4,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,(ModelNode*) &iedModel_PROT_VZGGIO4_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO4_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO4_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO5
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO5 			= { LogicalNodeModelType,   "VZGGIO5",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod};

DataObject iedModel_PROT_VZGGIO5_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) &iedModel_PROT_VZGGIO5_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
//DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel = {   DataAttributeModelType,    "ctlModel",    (ModelNode*) &iedModel_PROT_VZGGIO5_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    (ModelNode*) &iedModel_PROT_VZGGIO5_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO5_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO5_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO5,    (ModelNode*)&iedModel_PROT_VZGGIO5_Alm , (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO5_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO5_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO5,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,(ModelNode*) &iedModel_PROT_VZGGIO5_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO5_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO5_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};


/*******************************************************
 * iedModel_PROT_VZGGIO6
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO6 			= { LogicalNodeModelType,   "VZGGIO6",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod};

DataObject iedModel_PROT_VZGGIO6_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) &iedModel_PROT_VZGGIO6_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO6_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    (ModelNode*) &iedModel_PROT_VZGGIO6_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO6_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO6_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO6,    (ModelNode*)&iedModel_PROT_VZGGIO6_Alm , (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO6_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO6_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO6,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,(ModelNode*) &iedModel_PROT_VZGGIO6_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO6_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO6_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO7
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO7 			= { LogicalNodeModelType,   "VZGGIO7",    (ModelNode*)&iedModel_Generic_PROT,    (ModelNode*)&iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod};

DataObject iedModel_PROT_VZGGIO7_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) &iedModel_PROT_VZGGIO7_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO7_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    (ModelNode*) &iedModel_PROT_VZGGIO7_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO7_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO7_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO7,    (ModelNode*)&iedModel_PROT_VZGGIO7_Alm , (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO7_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO7_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO7,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,(ModelNode*) &iedModel_PROT_VZGGIO7_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO7_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO7_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO8
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO8 			= { LogicalNodeModelType,   "VZGGIO8",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod};

DataObject iedModel_PROT_VZGGIO8_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) &iedModel_PROT_VZGGIO8_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO8_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    (ModelNode*) &iedModel_PROT_VZGGIO8_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO8_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO8_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO8,    (ModelNode*)&iedModel_PROT_VZGGIO8_Alm , (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO8_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO8_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO8,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,(ModelNode*) &iedModel_PROT_VZGGIO8_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO8_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO8_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO9
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO9 			= { LogicalNodeModelType,   "VZGGIO9",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod};

DataObject iedModel_PROT_VZGGIO9_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) &iedModel_PROT_VZGGIO9_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO9_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    (ModelNode*) &iedModel_PROT_VZGGIO9_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO9_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO9_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO9,    (ModelNode*)&iedModel_PROT_VZGGIO9_Alm , (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO9_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO9_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO9,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,(ModelNode*) &iedModel_PROT_VZGGIO9_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO9_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO9_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO10
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO10 			= { LogicalNodeModelType,   "VZGGIO10",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod};

DataObject iedModel_PROT_VZGGIO10_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) &iedModel_PROT_VZGGIO10_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO10_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    (ModelNode*) &iedModel_PROT_VZGGIO10_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO10_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO10_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO10,    (ModelNode*)&iedModel_PROT_VZGGIO10_Alm , (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO10_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO10_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO10,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,(ModelNode*) &iedModel_PROT_VZGGIO10_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO10_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO10_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO11
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO11 			= { LogicalNodeModelType,   "VZGGIO11",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod};

DataObject iedModel_PROT_VZGGIO11_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) &iedModel_PROT_VZGGIO11_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO11_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    (ModelNode*) &iedModel_PROT_VZGGIO11_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO11_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO11_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO11,    (ModelNode*)&iedModel_PROT_VZGGIO11_Alm , (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO11_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO11_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO11,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,(ModelNode*) &iedModel_PROT_VZGGIO11_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO11_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO11_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO12
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO12 			= { LogicalNodeModelType,   "VZGGIO12",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod};

DataObject iedModel_PROT_VZGGIO12_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) &iedModel_PROT_VZGGIO12_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO12_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    (ModelNode*) &iedModel_PROT_VZGGIO12_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO12_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO12_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO12,    (ModelNode*)&iedModel_PROT_VZGGIO12_Alm , (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO12_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO12_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO12,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,(ModelNode*) &iedModel_PROT_VZGGIO12_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO12_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO12_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO13
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO13 			= { LogicalNodeModelType,   "VZGGIO13",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod};

DataObject iedModel_PROT_VZGGIO13_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) &iedModel_PROT_VZGGIO13_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO13_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    (ModelNode*) &iedModel_PROT_VZGGIO13_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO13_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO13_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO13,    (ModelNode*)&iedModel_PROT_VZGGIO13_Alm , (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO13_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO13_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO13,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,(ModelNode*) &iedModel_PROT_VZGGIO13_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO13_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO13_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO14
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO14 			= { LogicalNodeModelType,   "VZGGIO14",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*)&iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod};

DataObject iedModel_PROT_VZGGIO14_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) &iedModel_PROT_VZGGIO14_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO14_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    (ModelNode*) &iedModel_PROT_VZGGIO14_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO14_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO14_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO14,    (ModelNode*)&iedModel_PROT_VZGGIO14_Alm , (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO14_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO14_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO14,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,(ModelNode*) &iedModel_PROT_VZGGIO14_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO14_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO14_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO15
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO15 			= { LogicalNodeModelType,   "VZGGIO15",    (ModelNode*)&iedModel_Generic_PROT,  (ModelNode*)&iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod};

DataObject iedModel_PROT_VZGGIO15_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) &iedModel_PROT_VZGGIO15_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO15_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    (ModelNode*) &iedModel_PROT_VZGGIO15_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO15_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO15_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO15,    (ModelNode*)&iedModel_PROT_VZGGIO15_Alm , (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO15_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO15_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO15,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,(ModelNode*) &iedModel_PROT_VZGGIO15_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO15_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO15_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

/*******************************************************
 * iedModel_PROT_VZGGIO16
 *******************************************************/
LogicalNode iedModel_PROT_VZGGIO16 			= { LogicalNodeModelType,   "VZGGIO16",    (ModelNode*)&iedModel_Generic_PROT,   (ModelNode*) NULL,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod};

DataObject iedModel_PROT_VZGGIO16_Mod 		= { DataObjectModelType,     "Mod",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod_q,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_q 	= { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_t 	= { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) &iedModel_PROT_VZGGIO16_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal = { DataAttributeModelType,"stVal",   (ModelNode*) &iedModel_PROT_VZGGIO16_Mod,(ModelNode*) NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Beh = { DataObjectModelType,    "Beh",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Beh_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Health = { DataObjectModelType,    "Health",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_stVal = { DataAttributeModelType,    "stVal",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_q = { DataAttributeModelType,    "q",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    (ModelNode*) &iedModel_PROT_VZGGIO16_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Health_t = { DataAttributeModelType,    "t",    (ModelNode*) &iedModel_PROT_VZGGIO16_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_PROT_VZGGIO16_NamPlt = { DataObjectModelType,    "NamPlt",    (ModelNode*) &iedModel_PROT_VZGGIO16,    (ModelNode*)&iedModel_PROT_VZGGIO16_Alm , (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_vendor,0};

DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor = { DataAttributeModelType,    "vendor",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev = { DataAttributeModelType,    "swRev",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d = { DataAttributeModelType,    "d",    (ModelNode*) &iedModel_PROT_VZGGIO16_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_PROT_VZGGIO16_Alm = {DataObjectModelType,"Alm",(ModelNode*) &iedModel_PROT_VZGGIO16,NULL ,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_stVal,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal = {DataAttributeModelType,"stVal",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_q,NULL,0,IEC61850_FC_ST,IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED | TRG_OPT_GI,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_q = {DataAttributeModelType,"q",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,(ModelNode*) &iedModel_PROT_VZGGIO16_Alm_t,NULL,0,IEC61850_FC_ST,IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,NULL,0};
DataAttribute iedModel_PROT_VZGGIO16_Alm_t = {DataAttributeModelType,"t",(ModelNode*) &iedModel_PROT_VZGGIO16_Alm,NULL,NULL,0,IEC61850_FC_ST,IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,NULL,0};

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

LogicalNode iedModel_CTRL_CSWI1 							= { LogicalNodeModelType,	"CSWI1",	(ModelNode*) &iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_XCBR1,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod};
//Mod
DataObject iedModel_CTRL_CSWI1_Mod 							= { DataObjectModelType,	"Mod",		(ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_q,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_q 					= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_t 					= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel 				= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_CSWI1_Mod, (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper 					= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod,   NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal 			= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin 			= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent 	= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum 			= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T 				= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check 			= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_CSWI1_Mod_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//Beh
DataObject iedModel_CTRL_CSWI1_Beh 							= { DataObjectModelType,	"Beh",		(ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_stVal 				= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED,NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_q 					= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    (ModelNode*) &iedModel_CTRL_CSWI1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Beh_t 					= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_CSWI1_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

//Health
DataObject iedModel_CTRL_CSWI1_Health 						= { DataObjectModelType,	"Health",	(ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Health_stVal 				= { DataAttributeModelType,	"stVal",	(ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_q 					= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_CSWI1_Health,    (ModelNode*) &iedModel_CTRL_CSWI1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Health_t 					= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_CSWI1_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_CTRL_CSWI1_NamPlt 						= { DataObjectModelType,	"NamPlt",	(ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor 			= { DataAttributeModelType,	"vendor",	(ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev 				= { DataAttributeModelType,	"swRev",	(ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    (ModelNode*) &iedModel_CTRL_CSWI1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_NamPlt_d 					= { DataAttributeModelType,	"d",		(ModelNode*) &iedModel_CTRL_CSWI1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_CTRL_CSWI1_Pos 							= { DataObjectModelType,	"Pos",		(ModelNode*) &iedModel_CTRL_CSWI1,    (ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_stVal,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_stVal 				= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};//GENERIC_BITSTRING
DataAttribute iedModel_CTRL_CSWI1_Pos_q 					= { DataAttributeModelType,	"q",		(ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_t 					= { DataAttributeModelType,	"t",		(ModelNode*) &iedModel_CTRL_CSWI1_Pos,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel 				= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos, (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper 					= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_CSWI1_Pos,   NULL,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal 			= { DataAttributeModelType,	"ctlVal",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin 			= { DataAttributeModelType,	"origin",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent 	= { DataAttributeModelType, "orIdent",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum 			= { DataAttributeModelType,	"ctlNum",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T 				= { DataAttributeModelType,	"T",		(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test 			= { DataAttributeModelType,	"Test",		(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    (ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check 			= { DataAttributeModelType,	"Check",	(ModelNode*) &iedModel_CTRL_CSWI1_Pos_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


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
LogicalNode iedModel_CTRL_XCBR1 							= { LogicalNodeModelType,  	"XCBR1",    (ModelNode*) &iedModel_Generic_CTRL,  (ModelNode*) &iedModel_CTRL_PTRC ,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod};
//Mod
DataObject iedModel_CTRL_XCBR1_Mod 							= { DataObjectModelType,    "Mod",     	(ModelNode*) &iedModel_CTRL_XCBR1,     			(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_q,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel 				= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_XCBR1_Mod, 			(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper 					= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod,         	NULL,(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal 			= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin 			= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent 	= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum 			= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T 				= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	(ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check 			= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_Mod_Oper,    	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
//Beh
DataObject iedModel_CTRL_XCBR1_Beh 							= { DataObjectModelType,    "Beh",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Health,    (ModelNode*) &iedModel_CTRL_XCBR1_Beh_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh,    		(ModelNode*) &iedModel_CTRL_XCBR1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Beh_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Beh, 			NULL, NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//Health
DataObject iedModel_CTRL_XCBR1_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    (ModelNode*) &iedModel_CTRL_XCBR1_Health_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Health_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    	(ModelNode*) &iedModel_CTRL_XCBR1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Health_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Health,    	NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//NamPlt
DataObject iedModel_CTRL_XCBR1_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_Pos, (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev 				= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_NamPlt_d 					= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_CTRL_XCBR1_NamPlt,    	NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
//Pos
DataObject iedModel_CTRL_XCBR1_Pos 							= { DataObjectModelType,    "Pos",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*)&iedModel_CTRL_XCBR1_Loc, (ModelNode*) &iedModel_CTRL_XCBR1_Pos_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_CODEDENUM, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		(ModelNode*) &iedModel_CTRL_XCBR1_Pos_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel 				= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_Pos,    		NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
//Loc
DataObject iedModel_CTRL_XCBR1_Loc 							= { DataObjectModelType,    "Loc",      (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt, (ModelNode*) &iedModel_CTRL_XCBR1_Loc_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*) &iedModel_CTRL_XCBR1_Loc_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_Loc_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_Loc,    		(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//OpCnt
DataObject iedModel_CTRL_XCBR1_OpCnt 						= { DataObjectModelType,    "OpCnt",    (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap, (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_OpCnt_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_OpCnt,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//CBOpCap
DataObject iedModel_CTRL_XCBR1_CBOpCap 						= { DataObjectModelType,    "CBOpCap",  (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn, (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal 			= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32U, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q 				= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t 				= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_CBOpCap,    	(ModelNode*)NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
//BlkOpn
DataObject iedModel_CTRL_XCBR1_BlkOpn 						= { DataObjectModelType,    "BlkOpn",   (ModelNode*) &iedModel_CTRL_XCBR1,    					(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls, 			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_q,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_t,    		NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_ctlModel,	NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,    			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper, 		NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn,   			NULL,    										(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  		(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  		(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_origin,	NULL,    											NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,			(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  		(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Test, NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  		(ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper_Check,NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkOpn_Oper,  		NULL,    											NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//BlkCls
DataObject iedModel_CTRL_XCBR1_BlkCls 						= { DataObjectModelType,    "BlkCls",   (ModelNode*) &iedModel_CTRL_XCBR1,    			(ModelNode*) NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_stVal,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel 			= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls,   	NULL, (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_XCBR1_BlkCls_Oper,  NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

//-PTRC --------------------------------------------------------------------------
LogicalNode iedModel_CTRL_PTRC 								= { LogicalNodeModelType,   "PTRC1",    (ModelNode*)&iedModel_Generic_CTRL,   (ModelNode*)&iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_PTRC_Mod};

DataObject iedModel_CTRL_PTRC_Mod 							= { DataObjectModelType,    "Mod",    	(ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_q,0};
DataAttribute iedModel_CTRL_PTRC_Mod_q 						= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_t 						= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_stVal,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED,   NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_stVal 					= { DataAttributeModelType,	"stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Mod,    (ModelNode*) &iedModel_CTRL_PTRC_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel 				= { DataAttributeModelType, "ctlModel", (ModelNode*) &iedModel_CTRL_PTRC_Mod,    NULL,    NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_Beh 							= { DataObjectModelType,    "Beh",    	(ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Beh_stVal 					= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_q 						= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_PTRC_Beh,    (ModelNode*) &iedModel_CTRL_PTRC_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Beh_t 						= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_PTRC_Beh,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_Health 						= { DataObjectModelType,    "Health",   (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_Health_stVal,0};
DataAttribute iedModel_CTRL_PTRC_Health_stVal 				= { DataAttributeModelType, "stVal",    (ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_q 					= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_PTRC_Health,    (ModelNode*) &iedModel_CTRL_PTRC_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_Health_t 					= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_PTRC_Health,    NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_PTRC_NamPlt 						= { DataObjectModelType,    "NamPlt",   (ModelNode*) &iedModel_CTRL_PTRC,    (ModelNode*) &iedModel_CTRL_PTRC_Op, (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor 				= { DataAttributeModelType, "vendor",   (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev 				= { DataAttributeModelType, "swRev",    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    (ModelNode*) &iedModel_CTRL_PTRC_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO,    NULL,0};
DataAttribute iedModel_CTRL_PTRC_NamPlt_d 					= { DataAttributeModelType, "d",    	(ModelNode*) &iedModel_CTRL_PTRC_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_PTRC_Op 	 						= { DataObjectModelType,    "Op",  		(ModelNode*) &iedModel_CTRL_PTRC,  	NULL, (ModelNode*) &iedModel_CTRL_PTRC_Op_general,0};
DataAttribute iedModel_CTRL_PTRC_Op_general 				= { DataAttributeModelType, "general", 	(ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_q 						= { DataAttributeModelType, "q",    	(ModelNode*) &iedModel_CTRL_PTRC_Op,  (ModelNode*) &iedModel_CTRL_PTRC_Op_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_PTRC_Op_t 						= { DataAttributeModelType, "t",    	(ModelNode*) &iedModel_CTRL_PTRC_Op,  NULL,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};


// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO1 							= { LogicalNodeModelType,   "GGIO1",    	(ModelNode*) &iedModel_Generic_CTRL,  (ModelNode*) &iedModel_CTRL_GGIO2 ,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod};

DataObject iedModel_CTRL_GGIO1_Mod 							= { DataObjectModelType,    "Mod",    		(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Mod_q,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_q 					= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_stVal 				= { DataAttributeModelType,	"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO1_Mod,(ModelNode*) &iedModel_CTRL_GGIO1_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel 				= { DataAttributeModelType, "ctlModel",    	(ModelNode*) &iedModel_CTRL_GGIO1_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_Beh 							= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_stVal 				= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_q 					= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_CTRL_GGIO1_Beh,    (ModelNode*) &iedModel_CTRL_GGIO1_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Beh_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO1_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_Health 						= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_stVal,0};
DataAttribute iedModel_CTRL_GGIO1_Health_stVal 				= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_q 					= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_GGIO1_Health,    (ModelNode*) &iedModel_CTRL_GGIO1_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_Health_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO1_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO1_NamPlt 						= { DataObjectModelType,    "NamPlt",    	(ModelNode*) &iedModel_CTRL_GGIO1,    (ModelNode*)&iedModel_CTRL_GGIO1_SPCSO1 , (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor 			= { DataAttributeModelType, "vendor",    	(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev 				= { DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO1_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_NamPlt_d 					= { DataAttributeModelType, "d",    		(ModelNode*) &iedModel_CTRL_GGIO1_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO1 						= { DataObjectModelType,    "SPCSO1",   (ModelNode*) &iedModel_CTRL_GGIO1,     		(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO2 						= { DataObjectModelType,    "SPCSO2",   (ModelNode*) &iedModel_CTRL_GGIO1,     			(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO1_SPCSO3 						= { DataObjectModelType,    "SPCSO3",   (ModelNode*) &iedModel_CTRL_GGIO1,     	(ModelNode*)  &iedModel_CTRL_GGIO1_SPCSO4,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};


// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO1_SPCSO4 						= { DataObjectModelType,  	"SPCSO4",   (ModelNode*) &iedModel_CTRL_GGIO1,     		NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_q,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO1_SPCSO4_Oper, NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------

//Добавить в логическое устройство CTRL узел GGIO2 с возможностью формирования 32-х команд управления (Команда 1 – Команда 32) с использованием SPCSO1… SPCSO32.
// --------------------------------------------------------
LogicalNode iedModel_CTRL_GGIO2 							= { LogicalNodeModelType,   "GGIO2",    	(ModelNode*) &iedModel_Generic_CTRL,  NULL ,    (ModelNode*) &iedModel_CTRL_GGIO2_Mod};

DataObject iedModel_CTRL_GGIO2_Mod 							= { DataObjectModelType,    "Mod",    		(ModelNode*) &iedModel_CTRL_GGIO2,    (ModelNode*) &iedModel_CTRL_GGIO2_Beh,    (ModelNode*) &iedModel_CTRL_GGIO2_Mod_q,0};
DataAttribute iedModel_CTRL_GGIO2_Mod_q 					= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_GGIO2_Mod,(ModelNode*) &iedModel_CTRL_GGIO2_Mod_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Mod_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO2_Mod,(ModelNode*) &iedModel_CTRL_GGIO2_Mod_stVal,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Mod_stVal 				= { DataAttributeModelType,	"stVal",   		(ModelNode*) &iedModel_CTRL_GGIO2_Mod,(ModelNode*) &iedModel_CTRL_GGIO2_Mod_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32,     TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Mod_ctlModel 				= { DataAttributeModelType, "ctlModel",    	(ModelNode*) &iedModel_CTRL_GGIO2_Mod,    NULL,    NULL,    0,   IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO2_Beh 							= { DataObjectModelType,    "Beh",    		(ModelNode*) &iedModel_CTRL_GGIO2,    (ModelNode*) &iedModel_CTRL_GGIO2_Health,    (ModelNode*) &iedModel_CTRL_GGIO2_Beh_stVal,0};
DataAttribute iedModel_CTRL_GGIO2_Beh_stVal 				= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_GGIO2_Beh,    (ModelNode*) &iedModel_CTRL_GGIO2_Beh_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Beh_q 					= { DataAttributeModelType,	"q",    		(ModelNode*) &iedModel_CTRL_GGIO2_Beh,    (ModelNode*) &iedModel_CTRL_GGIO2_Beh_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Beh_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO2_Beh,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO2_Health 						= { DataObjectModelType,    "Health",    	(ModelNode*) &iedModel_CTRL_GGIO2,    (ModelNode*) &iedModel_CTRL_GGIO2_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO2_Health_stVal,0};
DataAttribute iedModel_CTRL_GGIO2_Health_stVal 				= { DataAttributeModelType, "stVal",    	(ModelNode*) &iedModel_CTRL_GGIO2_Health,    (ModelNode*) &iedModel_CTRL_GGIO2_Health_q,    NULL,    0,    IEC61850_FC_ST,    IEC61850_INT32, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Health_q 					= { DataAttributeModelType, "q",    		(ModelNode*) &iedModel_CTRL_GGIO2_Health,    (ModelNode*) &iedModel_CTRL_GGIO2_Health_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_Health_t 					= { DataAttributeModelType, "t",    		(ModelNode*) &iedModel_CTRL_GGIO2_Health,    NULL,    NULL,    0,   IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};

DataObject iedModel_CTRL_GGIO2_NamPlt 						= { DataObjectModelType,    "NamPlt",    	(ModelNode*) &iedModel_CTRL_GGIO2,    (ModelNode*)&iedModel_CTRL_GGIO2_SPCSO1 , (ModelNode*) &iedModel_CTRL_GGIO2_NamPlt_vendor,0};
DataAttribute iedModel_CTRL_GGIO2_NamPlt_vendor 			= { DataAttributeModelType, "vendor",    	(ModelNode*) &iedModel_CTRL_GGIO2_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO2_NamPlt_swRev,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_NamPlt_swRev 				= { DataAttributeModelType, "swRev",    	(ModelNode*) &iedModel_CTRL_GGIO2_NamPlt,    (ModelNode*) &iedModel_CTRL_GGIO2_NamPlt_d,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_NamPlt_d 					= { DataAttributeModelType, "d",    		(ModelNode*) &iedModel_CTRL_GGIO2_NamPlt,    NULL,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO2_SPCSO1 						= { DataObjectModelType,    "SPCSO1",   (ModelNode*) &iedModel_CTRL_GGIO2,     		(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO2,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO1_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO1_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO2_SPCSO2 						= { DataObjectModelType,    "SPCSO2",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO3,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO2_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO2_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

DataObject iedModel_CTRL_GGIO2_SPCSO3 						= { DataObjectModelType,    "SPCSO3",   (ModelNode*) &iedModel_CTRL_GGIO2,     	(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO4,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_q 					= { DataAttributeModelType, "q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_t 					= { DataAttributeModelType, "t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_d 					= { DataAttributeModelType, "d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_ctlModel 			= { DataAttributeModelType, "ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3, 			(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper 				= { DataAttributeModelType, "Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3,   		NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlVal 		= { DataAttributeModelType, "ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin 		= { DataAttributeModelType, "origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orCat 	= { DataAttributeModelType, "orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_origin_orIdent= { DataAttributeModelType, "orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_ctlNum 		= { DataAttributeModelType, "ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_T 			= { DataAttributeModelType, "T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Test 			= { DataAttributeModelType, "Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO3_Oper_Check 		= { DataAttributeModelType, "Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO3_Oper,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};

// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO4 						= { DataObjectModelType,  	"SPCSO4",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO5,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO4_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO4_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO5 						= { DataObjectModelType,  	"SPCSO5",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO6,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO5_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO5_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO6 						= { DataObjectModelType,  	"SPCSO6",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO7,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO6_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO6_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO7 						= { DataObjectModelType,  	"SPCSO7",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO8,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO7_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO7_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO8 						= { DataObjectModelType,  	"SPCSO8",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO9,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO8_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO8_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO9 						= { DataObjectModelType,  	"SPCSO9",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO10,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO9_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO9_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO10 						= { DataObjectModelType,  	"SPCSO10",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO11,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO10_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO10_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO11 						= { DataObjectModelType,  	"SPCSO11",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO12,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO11_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO11_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO12 						= { DataObjectModelType,  	"SPCSO12",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO13,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO12_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO12_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO13 						= { DataObjectModelType,  	"SPCSO13",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO14,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO13_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO13_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO14 						= { DataObjectModelType,  	"SPCSO14",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO15,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO14_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO14_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO15 						= { DataObjectModelType,  	"SPCSO15",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO16,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO15_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO15_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO16 						= { DataObjectModelType,  	"SPCSO16",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO17,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO16_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO16_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO17 						= { DataObjectModelType,  	"SPCSO17",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO18,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO17_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO17_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO18 						= { DataObjectModelType,  	"SPCSO18",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO19,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO18_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO18_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO19 						= { DataObjectModelType,  	"SPCSO19",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO20,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO19_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO19_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO20 						= { DataObjectModelType,  	"SPCSO20",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO21,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO20_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO20_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO21 						= { DataObjectModelType,  	"SPCSO21",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO22,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO21_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO21_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO22 						= { DataObjectModelType,  	"SPCSO22",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO23,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO22_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO22_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO23 						= { DataObjectModelType,  	"SPCSO23",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO24,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO23_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO23_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO24 						= { DataObjectModelType,  	"SPCSO24",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO25,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO24_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO24_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO25 						= { DataObjectModelType,  	"SPCSO25",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO26,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO25_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO25_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO26 						= { DataObjectModelType,  	"SPCSO26",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO27,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO26_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO26_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO27 						= { DataObjectModelType,  	"SPCSO27",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO28,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO27_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO27_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO28 						= { DataObjectModelType,  	"SPCSO28",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO29,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO28_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO28_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO29 						= { DataObjectModelType,  	"SPCSO29",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO30,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO29_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO29_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO30 						= { DataObjectModelType,  	"SPCSO30",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO31,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO30_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO30_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO31 						= { DataObjectModelType,  	"SPCSO31",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  &iedModel_CTRL_GGIO2_SPCSO32,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO31_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO31_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------
DataObject iedModel_CTRL_GGIO2_SPCSO32 						= { DataObjectModelType,  	"SPCSO32",   (ModelNode*) &iedModel_CTRL_GGIO2,     			(ModelNode*)  NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_q,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_q 					= { DataAttributeModelType,	"q",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_t,    NULL,    0,    IEC61850_FC_ST,    IEC61850_QUALITY, TRG_OPT_QUALITY_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_t 					= { DataAttributeModelType,	"t",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_d,    NULL,    0,    IEC61850_FC_ST,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_d 					= { DataAttributeModelType,	"d",       	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_stVal,    NULL,    0,    IEC61850_FC_DC,    IEC61850_VISIBLE_STRING_255, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_stVal 				= { DataAttributeModelType,	"stVal",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_ctlModel,    NULL,    0,    IEC61850_FC_ST,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_ctlModel 			= { DataAttributeModelType,	"ctlModel",	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32, 		(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, NULL,    0,    IEC61850_FC_CF,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper 				= { DataAttributeModelType,	"Oper",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32,   	NULL,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlVal,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlVal 		= { DataAttributeModelType,	"ctlVal",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_origin,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin 		= { DataAttributeModelType,	"origin",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlNum,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orCat,    0,    IEC61850_FC_CO,    IEC61850_CONSTRUCTED, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orCat 	= { DataAttributeModelType,	"orCat",   	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_origin,    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orIdent,    NULL,    0,    IEC61850_FC_CO,    IEC61850_ENUMERATED, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_origin_orIdent= { DataAttributeModelType,	"orIdent", 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_origin,    NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_OCTET_STRING_64, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_ctlNum 		= { DataAttributeModelType,	"ctlNum",  	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_T,    NULL,    0,    IEC61850_FC_CO,    IEC61850_INT8U, TRG_OPT_NO, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_T 			= { DataAttributeModelType,	"T",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_Test,    NULL,    0,    IEC61850_FC_CO,    IEC61850_TIMESTAMP, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Test 			= { DataAttributeModelType,	"Test",    	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper, 	(ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper_Check,    NULL,    0,    IEC61850_FC_CO,    IEC61850_BOOLEAN, TRG_OPT_DATA_CHANGED, NULL,0};
DataAttribute iedModel_CTRL_GGIO2_SPCSO32_Oper_Check 		= { DataAttributeModelType,	"Check",    (ModelNode*) &iedModel_CTRL_GGIO2_SPCSO32_Oper,	NULL,    NULL,    0,    IEC61850_FC_CO,    IEC61850_CHECK, TRG_OPT_NO, NULL,0};
// --------------------------------------------------------

// ------------ SV выборки ---------------------------------
// ---------------------------------------------------------
#ifndef SVControlBlockNULL
//extern SVControlBlock iedModel_MUnn_LLN0_smv0;

#endif

// ------------ группы уставок -----------------------------
// ---------------------------------------------------------
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

// ------------ Log выборки ---------------------------------
// ---------------------------------------------------------
#ifndef LogControlBlockNULL

LogControlBlock iedModel_LD0_LLN0_lcb0 = {&iedModel_LD0_LLN0, "EventLog", 	"DS0", 		"LD0/LLN0$EventLog", 	TRG_OPT_INTEGRITY, 1000, true, true, &iedModel_LD0_LLN0_lcb1};
LogControlBlock iedModel_LD0_LLN0_lcb1 = {&iedModel_LD0_LLN0, "GeneralLog", NULL, 		NULL, 					TRG_OPT_INTEGRITY, 1000, true, true, NULL};

Log iedModel_LD0_LLN0_log0 = {&iedModel_LD0_LLN0, "GeneralLog", 	&iedModel_LD0_LLN0_log1};
Log iedModel_LD0_LLN0_log1 = {&iedModel_LD0_LLN0, "EventLog", 		NULL};
#endif
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

//----------------------------------------------------------------------------
// нужно для каждого узла не создавать новую строку, а просто указать адрес
// головной таблички. Места в память колосально увеличим
iedModel_LD0_LLN0_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_LD0_LLN0_NamPlt_ldNs.mmsValue 		= MmsValue_newVisibleString(_LDNS);
iedModel_LD0_LLN0_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_LD0_LLN0_NamPlt_d.mmsValue 		= MmsValue_newVisibleString(_SWRevision);
//----------------------------------------------------------------------------

iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(1);
iedModel_LD0_LPHD1_Proxy_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);

// RDRE
iedModel_LD0_RDRE1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_LD0_RDRE1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_LD0_RDRE1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);
iedModel_LD0_RDRE1_NamPlt_d.mmsValue 		= MmsValue_newVisibleString(_SWRevision);


iedModel_LD0_RDRE1_RCBMade_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_LD0_RDRE1_FltNum_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_LD0_RDRE1_RCBMade_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_LD0_RDRE1_FltNum_stVal.mmsValue = MmsValue_newIntegerFromInt16(0);


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

iedModel_PROT_LLN0_NamPlt_vendor.mmsValue 		= MmsValue_newVisibleString(_Vendor);
iedModel_PROT_LLN0_NamPlt_ldNs.mmsValue 		= MmsValue_newVisibleString(_LDNS);
iedModel_PROT_LLN0_NamPlt_swRev.mmsValue 		= MmsValue_newVisibleString(_swREV);
//iedModel_PROT_LLN0_NamPlt_configRev.mmsValue 	= MmsValue_newVisibleString("0");
iedModel_PROT_LLN0_NamPlt_d.mmsValue 		= MmsValue_newVisibleString(_SWRevision);

iedModel_PROT_LPHD1_PhyHealth_stVal.mmsValue = MmsValue_newIntegerFromInt32(1);
iedModel_PROT_LPHD1_PhyHealth_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_stVal.mmsValue = MmsValue_newBoolean(false);// не будет прокси
iedModel_PROT_LPHD1_Proxy_q.mmsValue = MmsValue_newBitString(0);
iedModel_PROT_LPHD1_Proxy_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_LPHD1_PhyHealth_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_LPHD1_PhyNam_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);

//VZGGIO
iedModel_PROT_VZGGIO1_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_PROT_VZGGIO1_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

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
iedModel_PROT_VZGGIO9_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO9_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO10_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO10_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO11_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO11_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO12_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO12_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO13_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO13_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO14_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO14_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO15_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO15_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);
iedModel_PROT_VZGGIO16_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_PROT_VZGGIO16_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_PROT_VZGGIO1_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Alm_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_PROT_VZGGIO1_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO3_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO4_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO5_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO6_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO7_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO8_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO9_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO10_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO11_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO12_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO13_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO14_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO15_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO16_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_PROT_VZGGIO1_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO3_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO4_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO5_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO6_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO7_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO8_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO9_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO10_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO11_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO12_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO13_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO14_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO15_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_PROT_VZGGIO16_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);

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

iedModel_CTRL_GGIO1_SPCSO1_d.mmsValue = MmsValue_newVisibleString("Reset the new fault flag");//Сброс флага новой неисправности
iedModel_CTRL_GGIO1_SPCSO2_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the system log");//Сброс флага новой записи в журнале системы
iedModel_CTRL_GGIO1_SPCSO3_d.mmsValue = MmsValue_newVisibleString("Reset the flag of the new record in the alarm log");//Сброс флага новой записи в журнале аварий
iedModel_CTRL_GGIO1_SPCSO4_d.mmsValue = MmsValue_newVisibleString("Reset the LEDs and Relays");//Сброс индикации

// CTRL_GGIO1
iedModel_CTRL_GGIO1_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO1_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

//GGIO2 --------------------------------------------------------------------------------
iedModel_CTRL_GGIO2_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_Mod_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_GGIO2_Mod_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_GGIO2_Mod_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO2_Beh_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_CTRL_GGIO2_Beh_q.mmsValue = MmsValue_newBitString(0);
iedModel_CTRL_GGIO2_Beh_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO2_Health_stVal.mmsValue = MmsValue_newIntegerFromInt16(STVALINT32_ON);
iedModel_CTRL_GGIO2_Health_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_CTRL_GGIO2_NamPlt_vendor.mmsValue = MmsValue_newVisibleString(_Vendor);
iedModel_CTRL_GGIO2_NamPlt_swRev.mmsValue = MmsValue_newVisibleString(_swREV);

iedModel_CTRL_GGIO2_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO5_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO6_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO7_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO8_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO9_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO10_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO11_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO12_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO13_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO14_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO15_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO16_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO17_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO18_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO19_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO20_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO21_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO22_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO23_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO24_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO25_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO26_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO27_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO28_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO29_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO30_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO31_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);
iedModel_CTRL_GGIO2_SPCSO32_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(CTLMODELEDENUM_DirectWithNormalSecurity);

iedModel_CTRL_GGIO2_SPCSO1_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO2_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO3_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO4_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO5_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO6_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO7_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO8_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO9_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO10_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO11_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO12_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO13_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO14_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO15_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO16_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO17_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO18_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO19_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO20_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO21_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO22_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO23_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO24_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO25_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO26_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO27_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO28_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO29_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO30_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO31_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_CTRL_GGIO2_SPCSO32_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

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
iedModel_GGIO_INGGIO1_Ind59_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind60_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind61_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind62_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind63_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind64_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind65_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind66_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind67_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind68_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind69_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind70_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind71_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind72_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind73_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind74_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);

#if  defined (T0N0D106R67) || defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind75_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind76_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind77_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind78_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind79_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind80_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind81_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind82_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind83_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind84_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind85_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind86_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind87_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind88_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind89_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind90_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind91_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind92_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind93_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind94_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind95_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind96_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind97_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind98_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind99_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind100_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind101_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind102_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind103_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind104_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind105_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind106_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
#endif
#if  defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind107_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind108_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind109_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind110_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind111_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind112_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind113_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_INGGIO1_Ind114_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
#endif
// ----------------------------------------------------------------------------
// Указываем какие данные нужно анализировать для ускорения гусов
// ----------------------------------------------------------------------------
// Обновление данных в структуре чеpеp функции
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
iedModel_GGIO_INGGIO1_Ind17_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind18_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind19_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind20_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind21_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind22_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind23_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind24_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind25_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind26_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind27_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind28_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind29_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind30_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind31_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind32_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind33_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind34_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind35_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind36_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind37_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind38_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind39_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind40_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind41_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind42_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind43_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind44_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind45_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind46_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind47_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind48_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind49_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind50_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind51_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind52_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind53_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind54_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind55_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind56_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind57_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind58_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind59_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind60_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind61_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind62_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind63_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind64_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind65_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind66_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind67_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind68_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind69_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind70_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind71_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind72_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind73_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind74_stVal.mmsValue = MmsValue_newBoolean(0);

#if  defined (T0N0D106R67) || defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind75_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind76_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind77_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind78_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind79_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind80_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind81_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind82_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind83_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind84_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind85_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind86_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind87_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind88_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind89_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind90_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind91_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind92_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind93_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind94_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind95_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind96_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind97_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind98_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind99_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind100_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind101_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind102_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind103_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind104_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind105_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind106_stVal.mmsValue = MmsValue_newBoolean(0);
#endif
#if  defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind107_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind108_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind109_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind110_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind111_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind112_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind113_stVal.mmsValue = MmsValue_newBoolean(0);
iedModel_GGIO_INGGIO1_Ind114_stVal.mmsValue = MmsValue_newBoolean(0);
#endif

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
iedModel_GGIO_INGGIO1_Ind17_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind18_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind19_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind20_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind21_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind22_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind23_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind24_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind25_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind26_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind27_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind28_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind29_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind30_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind31_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind32_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind33_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind34_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind35_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind36_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind37_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind38_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind39_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind40_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind41_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind42_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind43_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind44_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind45_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind46_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind47_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind48_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind49_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind50_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind51_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind52_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind53_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind54_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind55_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind56_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind57_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind58_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind59_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind60_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind61_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind62_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind63_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind64_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind65_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind66_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind67_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind68_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind69_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind70_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind71_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind72_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind73_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind74_q.mmsValue = MmsValue_newBitString(0);

#if  defined (T0N0D106R67) || defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind75_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind76_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind77_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind78_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind79_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind80_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind81_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind82_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind83_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind84_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind85_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind86_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind87_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind88_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind89_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind90_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind91_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind92_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind93_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind94_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind95_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind96_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind97_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind98_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind99_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind100_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind101_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind102_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind103_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind104_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind105_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind106_q.mmsValue = MmsValue_newBitString(0);
#endif
#if  defined (T0N0D114R59)
iedModel_GGIO_INGGIO1_Ind107_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind108_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind109_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind110_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind111_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind112_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind113_q.mmsValue = MmsValue_newBitString(0);
iedModel_GGIO_INGGIO1_Ind114_q.mmsValue = MmsValue_newBitString(0);
#endif

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
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind17_stVal.mmsValue, IDU_FUNC_INGGIO, 17 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind18_stVal.mmsValue, IDU_FUNC_INGGIO, 18 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind19_stVal.mmsValue, IDU_FUNC_INGGIO, 19 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind20_stVal.mmsValue, IDU_FUNC_INGGIO, 20 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind21_stVal.mmsValue, IDU_FUNC_INGGIO, 21 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind22_stVal.mmsValue, IDU_FUNC_INGGIO, 22 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind23_stVal.mmsValue, IDU_FUNC_INGGIO, 23 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind24_stVal.mmsValue, IDU_FUNC_INGGIO, 24 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind25_stVal.mmsValue, IDU_FUNC_INGGIO, 25 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind26_stVal.mmsValue, IDU_FUNC_INGGIO, 26 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind27_stVal.mmsValue, IDU_FUNC_INGGIO, 27 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind28_stVal.mmsValue, IDU_FUNC_INGGIO, 28 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind29_stVal.mmsValue, IDU_FUNC_INGGIO, 29 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind30_stVal.mmsValue, IDU_FUNC_INGGIO, 30 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind31_stVal.mmsValue, IDU_FUNC_INGGIO, 31 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind32_stVal.mmsValue, IDU_FUNC_INGGIO, 32 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind33_stVal.mmsValue, IDU_FUNC_INGGIO, 33 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind34_stVal.mmsValue, IDU_FUNC_INGGIO, 34 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind35_stVal.mmsValue, IDU_FUNC_INGGIO, 35 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind36_stVal.mmsValue, IDU_FUNC_INGGIO, 36 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind37_stVal.mmsValue, IDU_FUNC_INGGIO, 37 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind38_stVal.mmsValue, IDU_FUNC_INGGIO, 38 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind39_stVal.mmsValue, IDU_FUNC_INGGIO, 39 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind40_stVal.mmsValue, IDU_FUNC_INGGIO, 40 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind41_stVal.mmsValue, IDU_FUNC_INGGIO, 41 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind42_stVal.mmsValue, IDU_FUNC_INGGIO, 42 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind43_stVal.mmsValue, IDU_FUNC_INGGIO, 43 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind44_stVal.mmsValue, IDU_FUNC_INGGIO, 44 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind45_stVal.mmsValue, IDU_FUNC_INGGIO, 45 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind46_stVal.mmsValue, IDU_FUNC_INGGIO, 46 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind47_stVal.mmsValue, IDU_FUNC_INGGIO, 47 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind48_stVal.mmsValue, IDU_FUNC_INGGIO, 48 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind49_stVal.mmsValue, IDU_FUNC_INGGIO, 49 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind50_stVal.mmsValue, IDU_FUNC_INGGIO, 50 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind51_stVal.mmsValue, IDU_FUNC_INGGIO, 51 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind52_stVal.mmsValue, IDU_FUNC_INGGIO, 52 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind53_stVal.mmsValue, IDU_FUNC_INGGIO, 53 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind54_stVal.mmsValue, IDU_FUNC_INGGIO, 54 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind55_stVal.mmsValue, IDU_FUNC_INGGIO, 55 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind56_stVal.mmsValue, IDU_FUNC_INGGIO, 56 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind57_stVal.mmsValue, IDU_FUNC_INGGIO, 57 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind58_stVal.mmsValue, IDU_FUNC_INGGIO, 58 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind59_stVal.mmsValue, IDU_FUNC_INGGIO, 59 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind60_stVal.mmsValue, IDU_FUNC_INGGIO, 60 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind61_stVal.mmsValue, IDU_FUNC_INGGIO, 61 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind62_stVal.mmsValue, IDU_FUNC_INGGIO, 62 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind63_stVal.mmsValue, IDU_FUNC_INGGIO, 63 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind64_stVal.mmsValue, IDU_FUNC_INGGIO, 64 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind65_stVal.mmsValue, IDU_FUNC_INGGIO, 65 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind66_stVal.mmsValue, IDU_FUNC_INGGIO, 66 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind67_stVal.mmsValue, IDU_FUNC_INGGIO, 67 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind68_stVal.mmsValue, IDU_FUNC_INGGIO, 68 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind69_stVal.mmsValue, IDU_FUNC_INGGIO, 69 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind70_stVal.mmsValue, IDU_FUNC_INGGIO, 70 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind71_stVal.mmsValue, IDU_FUNC_INGGIO, 71 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind72_stVal.mmsValue, IDU_FUNC_INGGIO, 72 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind73_stVal.mmsValue, IDU_FUNC_INGGIO, 73 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind74_stVal.mmsValue, IDU_FUNC_INGGIO, 74 | TIME_mask);
#if  defined (T0N0D106R67) || defined (T0N0D114R59)
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind75_stVal.mmsValue, IDU_FUNC_INGGIO, 75 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind76_stVal.mmsValue, IDU_FUNC_INGGIO, 76 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind77_stVal.mmsValue, IDU_FUNC_INGGIO, 77 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind78_stVal.mmsValue, IDU_FUNC_INGGIO, 78 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind79_stVal.mmsValue, IDU_FUNC_INGGIO, 79 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind80_stVal.mmsValue, IDU_FUNC_INGGIO, 80 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind81_stVal.mmsValue, IDU_FUNC_INGGIO, 81 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind82_stVal.mmsValue, IDU_FUNC_INGGIO, 82 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind83_stVal.mmsValue, IDU_FUNC_INGGIO, 83 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind84_stVal.mmsValue, IDU_FUNC_INGGIO, 84 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind85_stVal.mmsValue, IDU_FUNC_INGGIO, 85 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind86_stVal.mmsValue, IDU_FUNC_INGGIO, 86 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind87_stVal.mmsValue, IDU_FUNC_INGGIO, 87 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind88_stVal.mmsValue, IDU_FUNC_INGGIO, 88 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind89_stVal.mmsValue, IDU_FUNC_INGGIO, 89 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind90_stVal.mmsValue, IDU_FUNC_INGGIO, 90 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind91_stVal.mmsValue, IDU_FUNC_INGGIO, 91 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind92_stVal.mmsValue, IDU_FUNC_INGGIO, 92 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind93_stVal.mmsValue, IDU_FUNC_INGGIO, 93 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind94_stVal.mmsValue, IDU_FUNC_INGGIO, 94 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind95_stVal.mmsValue, IDU_FUNC_INGGIO, 95 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind96_stVal.mmsValue, IDU_FUNC_INGGIO, 96 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind97_stVal.mmsValue, IDU_FUNC_INGGIO, 97 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind98_stVal.mmsValue, IDU_FUNC_INGGIO, 98 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind99_stVal.mmsValue, IDU_FUNC_INGGIO, 99 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind100_stVal.mmsValue, IDU_FUNC_INGGIO, 100 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind101_stVal.mmsValue, IDU_FUNC_INGGIO, 101 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind102_stVal.mmsValue, IDU_FUNC_INGGIO, 102 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind103_stVal.mmsValue, IDU_FUNC_INGGIO, 103 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind104_stVal.mmsValue, IDU_FUNC_INGGIO, 104 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind105_stVal.mmsValue, IDU_FUNC_INGGIO, 105 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind106_stVal.mmsValue, IDU_FUNC_INGGIO, 106 | TIME_mask);
#endif
#if  defined (T0N0D114R59)
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind107_stVal.mmsValue, IDU_FUNC_INGGIO, 107 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind108_stVal.mmsValue, IDU_FUNC_INGGIO, 108 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind109_stVal.mmsValue, IDU_FUNC_INGGIO, 109 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind110_stVal.mmsValue, IDU_FUNC_INGGIO, 110 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind111_stVal.mmsValue, IDU_FUNC_INGGIO, 111 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind112_stVal.mmsValue, IDU_FUNC_INGGIO, 112 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind113_stVal.mmsValue, IDU_FUNC_INGGIO, 113 | TIME_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind114_stVal.mmsValue, IDU_FUNC_INGGIO, 114 | TIME_mask);
#endif

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

MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind17_q.mmsValue, IDU_FUNC_INGGIO, 17 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind18_q.mmsValue, IDU_FUNC_INGGIO, 18 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind19_q.mmsValue, IDU_FUNC_INGGIO, 19 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind20_q.mmsValue, IDU_FUNC_INGGIO, 20 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind21_q.mmsValue, IDU_FUNC_INGGIO, 21 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind22_q.mmsValue, IDU_FUNC_INGGIO, 22 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind23_q.mmsValue, IDU_FUNC_INGGIO, 23 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind24_q.mmsValue, IDU_FUNC_INGGIO, 24 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind25_q.mmsValue, IDU_FUNC_INGGIO, 25 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind26_q.mmsValue, IDU_FUNC_INGGIO, 26 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind27_q.mmsValue, IDU_FUNC_INGGIO, 27 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind28_q.mmsValue, IDU_FUNC_INGGIO, 28 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind29_q.mmsValue, IDU_FUNC_INGGIO, 29 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind30_q.mmsValue, IDU_FUNC_INGGIO, 30 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind31_q.mmsValue, IDU_FUNC_INGGIO, 31 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind32_q.mmsValue, IDU_FUNC_INGGIO, 32 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind33_q.mmsValue, IDU_FUNC_INGGIO, 33 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind34_q.mmsValue, IDU_FUNC_INGGIO, 34 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind35_q.mmsValue, IDU_FUNC_INGGIO, 35 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind36_q.mmsValue, IDU_FUNC_INGGIO, 36 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind37_q.mmsValue, IDU_FUNC_INGGIO, 37 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind38_q.mmsValue, IDU_FUNC_INGGIO, 38 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind39_q.mmsValue, IDU_FUNC_INGGIO, 39 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind40_q.mmsValue, IDU_FUNC_INGGIO, 40 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind41_q.mmsValue, IDU_FUNC_INGGIO, 41 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind42_q.mmsValue, IDU_FUNC_INGGIO, 42 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind43_q.mmsValue, IDU_FUNC_INGGIO, 43 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind44_q.mmsValue, IDU_FUNC_INGGIO, 44 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind45_q.mmsValue, IDU_FUNC_INGGIO, 45 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind46_q.mmsValue, IDU_FUNC_INGGIO, 46 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind47_q.mmsValue, IDU_FUNC_INGGIO, 47 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind48_q.mmsValue, IDU_FUNC_INGGIO, 48 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind49_q.mmsValue, IDU_FUNC_INGGIO, 49 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind50_q.mmsValue, IDU_FUNC_INGGIO, 50 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind51_q.mmsValue, IDU_FUNC_INGGIO, 51 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind52_q.mmsValue, IDU_FUNC_INGGIO, 52 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind53_q.mmsValue, IDU_FUNC_INGGIO, 53 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind54_q.mmsValue, IDU_FUNC_INGGIO, 54 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind55_q.mmsValue, IDU_FUNC_INGGIO, 55 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind56_q.mmsValue, IDU_FUNC_INGGIO, 56 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind57_q.mmsValue, IDU_FUNC_INGGIO, 57 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind58_q.mmsValue, IDU_FUNC_INGGIO, 58 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind59_q.mmsValue, IDU_FUNC_INGGIO, 59 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind60_q.mmsValue, IDU_FUNC_INGGIO, 60 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind61_q.mmsValue, IDU_FUNC_INGGIO, 61 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind62_q.mmsValue, IDU_FUNC_INGGIO, 62 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind63_q.mmsValue, IDU_FUNC_INGGIO, 63 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind64_q.mmsValue, IDU_FUNC_INGGIO, 64 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind65_q.mmsValue, IDU_FUNC_INGGIO, 65 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind66_q.mmsValue, IDU_FUNC_INGGIO, 66 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind67_q.mmsValue, IDU_FUNC_INGGIO, 67 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind68_q.mmsValue, IDU_FUNC_INGGIO, 68 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind69_q.mmsValue, IDU_FUNC_INGGIO, 69 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind70_q.mmsValue, IDU_FUNC_INGGIO, 70 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind71_q.mmsValue, IDU_FUNC_INGGIO, 71 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind72_q.mmsValue, IDU_FUNC_INGGIO, 72 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind73_q.mmsValue, IDU_FUNC_INGGIO, 73 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind74_q.mmsValue, IDU_FUNC_INGGIO, 74 | QUALITY_mask);
#if  defined (T0N0D106R67) || defined (T0N0D114R59)
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind75_q.mmsValue, IDU_FUNC_INGGIO, 75 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind76_q.mmsValue, IDU_FUNC_INGGIO, 76 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind77_q.mmsValue, IDU_FUNC_INGGIO, 77 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind78_q.mmsValue, IDU_FUNC_INGGIO, 78 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind79_q.mmsValue, IDU_FUNC_INGGIO, 79 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind80_q.mmsValue, IDU_FUNC_INGGIO, 80 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind81_q.mmsValue, IDU_FUNC_INGGIO, 81 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind82_q.mmsValue, IDU_FUNC_INGGIO, 82 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind83_q.mmsValue, IDU_FUNC_INGGIO, 83 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind84_q.mmsValue, IDU_FUNC_INGGIO, 84 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind85_q.mmsValue, IDU_FUNC_INGGIO, 85 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind86_q.mmsValue, IDU_FUNC_INGGIO, 86 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind87_q.mmsValue, IDU_FUNC_INGGIO, 87 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind88_q.mmsValue, IDU_FUNC_INGGIO, 88 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind89_q.mmsValue, IDU_FUNC_INGGIO, 89 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind90_q.mmsValue, IDU_FUNC_INGGIO, 90 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind91_q.mmsValue, IDU_FUNC_INGGIO, 91 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind92_q.mmsValue, IDU_FUNC_INGGIO, 92 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind93_q.mmsValue, IDU_FUNC_INGGIO, 93 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind94_q.mmsValue, IDU_FUNC_INGGIO, 94 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind95_q.mmsValue, IDU_FUNC_INGGIO, 95 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind96_q.mmsValue, IDU_FUNC_INGGIO, 96 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind97_q.mmsValue, IDU_FUNC_INGGIO, 97 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind98_q.mmsValue, IDU_FUNC_INGGIO, 98 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind99_q.mmsValue, IDU_FUNC_INGGIO, 99 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind100_q.mmsValue, IDU_FUNC_INGGIO, 100 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind101_q.mmsValue, IDU_FUNC_INGGIO, 101 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind102_q.mmsValue, IDU_FUNC_INGGIO, 102 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind103_q.mmsValue, IDU_FUNC_INGGIO, 103 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind104_q.mmsValue, IDU_FUNC_INGGIO, 104 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind105_q.mmsValue, IDU_FUNC_INGGIO, 105 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind106_q.mmsValue, IDU_FUNC_INGGIO, 106 | QUALITY_mask);
#endif
#if  defined (T0N0D114R59)
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind107_q.mmsValue, IDU_FUNC_INGGIO, 107 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind108_q.mmsValue, IDU_FUNC_INGGIO, 108 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind109_q.mmsValue, IDU_FUNC_INGGIO, 109 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind110_q.mmsValue, IDU_FUNC_INGGIO, 110 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind111_q.mmsValue, IDU_FUNC_INGGIO, 111 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind112_q.mmsValue, IDU_FUNC_INGGIO, 112 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind113_q.mmsValue, IDU_FUNC_INGGIO, 113 | QUALITY_mask);
MmsValue_setFunctionDataUpdate(iedModel_GGIO_INGGIO1_Ind114_q.mmsValue, IDU_FUNC_INGGIO, 114 | QUALITY_mask);
#endif

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
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
iedModel_GGIO_OUTGGIO1_SPCSO51_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO52_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO53_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO54_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO55_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO56_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO57_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO58_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO59_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO60_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO61_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO62_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO63_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO64_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO65_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO66_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO67_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO68_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO69_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO70_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO71_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO72_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO73_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO74_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO75_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO76_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO77_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO78_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO79_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_OUTGGIO1_SPCSO80_t.mmsValue = MmsValue_newUtcTimeByMsTime(currentTime);


//SSL
iedModel_GGIO_SSLGGIO1_Mod_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_SSLGGIO1_Beh_stVal.mmsValue 		= MmsValue_newIntegerFromInt16(STVALINT32_OK);
iedModel_GGIO_SSLGGIO1_Health_stVal.mmsValue 	= MmsValue_newIntegerFromInt16(STVALINT32_OK);

iedModel_GGIO_SSLGGIO1_Mod_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Beh_t.mmsValue 			= MmsValue_newUtcTimeByMsTime(currentTime);
iedModel_GGIO_SSLGGIO1_Health_t.mmsValue 		= MmsValue_newUtcTimeByMsTime(currentTime);

iedModel_GGIO_SSLGGIO1_Mod_ctlModel.mmsValue 	= MmsValue_newIntegerFromInt32(CTLMODELEDENUM_statusOnly);
iedModel_GGIO_SSLGGIO1_NamPlt_vendor.mmsValue 	= MmsValue_newVisibleString(_Vendor);
iedModel_GGIO_SSLGGIO1_NamPlt_swRev.mmsValue 	= MmsValue_newVisibleString(_swREV);

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

CSWICTRL_StartValue(currentTime);
XCBRCTRL_StartValue(currentTime);

LEDGGIO_StartValue(currentTime);
VLSGGIO_StartValue(currentTime);
LSGGIO_StartValue(currentTime);
RSTGGIO_StartValue(currentTime);

USART_TRACE("------------------------------------------------------------\n");
}
#endif 

