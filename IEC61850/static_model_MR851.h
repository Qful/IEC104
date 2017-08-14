/*
 * static_model_xxx.h
 *
 * automatically generated from simpleIO_direct_control.scd
 *
 * Классы данных для каждого из атрибутов описаны в главе МЭК 61850-7-3.
 *
 * Общая информация для логических узлов (наследуются из класса Common Logical Node Class)
 * Mod			INC			Режим											обязательный параметр
 * Beh			INS			Поведение										обязательный параметр
 * Health		INS			Состояние										обязательный параметр
 * NamPlt		LPL			Паспортные данные								обязательный параметр
 * OpCntRs		INC			Сбрасываемый счётчик срабатываний				обязательный параметр
 *
 * Информация о состоянии
 * Str			ACD			Пуск											обязательный параметр
 * Op			ACT			Срабатывание									обязательный параметр
 * TmASt		CSD			Активная время-токовая характеристика			необязательный параметр
 *
 * Уставки
 * TmACrv		CURVE		Тип время-токовой характеристики				необязательный параметр
 * StrVal		ASG			Уставка по току
 * TmMult					Мультипликатор уставки по времени
 * MinOpTmms	ING			Минимальное время срабатывания
 * MaxOpTmms	ING			Максимальное время срабатывания
 * OpDlTmms		ING			Уставка по времени
 * TypRsCrv		ING			Тип характеристики возрвата
 * RsDlTmms		ING			Уставка времени возврата
 * DirMod		ING			Направленный режим
 *
 *
 *
 *
 *
 *
 */

#ifndef STATIC_MODEL_MR851_H_
#define STATIC_MODEL_MR851_H_

#include <stdlib.h>
#include "model.h"
#include "iec61850_server.h"
#include "iec61850_common.h"

extern IedServer iedServer;

extern IedModel 	iedModel;
extern LogicalDevice iedModel_Generic_LD0;
extern LogicalDevice iedModel_Generic_RPN;
extern LogicalDevice iedModel_Generic_CTRL;
extern LogicalDevice iedModel_Generic_GGIO;

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
extern LogicalNode   iedModel_LD0_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_LD0_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_LD0_LLN0_Mod_q;
extern DataAttribute iedModel_LD0_LLN0_Mod_t;
extern DataAttribute iedModel_LD0_LLN0_Mod_stVal;
extern DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;

extern DataObject    iedModel_LD0_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_LD0_LLN0_Beh_stVal;
extern DataAttribute iedModel_LD0_LLN0_Beh_q;
extern DataAttribute iedModel_LD0_LLN0_Beh_t;

extern DataObject    iedModel_LD0_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_LD0_LLN0_Health_stVal;
extern DataAttribute iedModel_LD0_LLN0_Health_q;
extern DataAttribute iedModel_LD0_LLN0_Health_t;

extern DataObject    iedModel_LD0_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_d;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

// LPHD ----------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

extern DataObject    iedModel_LD0_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
extern DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_LD0_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_t;

extern DataObject    iedModel_LD0_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
extern DataAttribute iedModel_LD0_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_q;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------
// 000   000    00   00000
// 0  0  0  0  0  0    0
// 0  0  0  0  0  0    0
// 000   000   0  0    0
// 0     0 0   0  0    0
// 0     0  0   00     0
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_RPN_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_RPN_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_RPN_LLN0_Mod_q;
extern DataAttribute iedModel_RPN_LLN0_Mod_t;
extern DataAttribute iedModel_RPN_LLN0_Mod_stVal;
extern DataAttribute iedModel_RPN_LLN0_Mod_ctlModel;

extern DataObject    iedModel_RPN_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_RPN_LLN0_Beh_stVal;
extern DataAttribute iedModel_RPN_LLN0_Beh_q;
extern DataAttribute iedModel_RPN_LLN0_Beh_t;

extern DataObject    iedModel_RPN_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_RPN_LLN0_Health_stVal;
extern DataAttribute iedModel_RPN_LLN0_Health_q;
extern DataAttribute iedModel_RPN_LLN0_Health_t;

extern DataObject    iedModel_RPN_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_RPN_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_RPN_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_RPN_LLN0_NamPlt_d;
extern DataAttribute iedModel_RPN_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_RPN_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_RPN_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_RPN_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_RPN_LLN0_SGCB_q;
extern DataAttribute iedModel_RPN_LLN0_SGCB_t;
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_RPN_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

extern DataObject    iedModel_RPN_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
extern DataAttribute iedModel_RPN_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_RPN_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
extern DataAttribute iedModel_RPN_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_RPN_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_RPN_LPHD1_PhyHealth_t;

extern DataObject    iedModel_RPN_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
extern DataAttribute iedModel_RPN_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_RPN_LPHD1_Proxy_q;
extern DataAttribute iedModel_RPN_LPHD1_Proxy_t;


LogicalNode iedModel_RPN_ATCC1;
extern DataObject iedModel_RPN_ATCC1_Mod;
extern DataAttribute iedModel_RPN_ATCC1_Mod_q;
extern DataAttribute iedModel_RPN_ATCC1_Mod_t;
extern DataAttribute iedModel_RPN_ATCC1_Mod_stVal;

extern DataObject iedModel_RPN_ATCC1_Beh;
extern DataAttribute iedModel_RPN_ATCC1_Beh_stVal;
extern DataAttribute iedModel_RPN_ATCC1_Beh_q;
extern DataAttribute iedModel_RPN_ATCC1_Beh_t;

extern DataObject iedModel_RPN_ATCC1_Health;
extern DataAttribute iedModel_RPN_ATCC1_Health_stVal;
extern DataAttribute iedModel_RPN_ATCC1_Health_q;
extern DataAttribute iedModel_RPN_ATCC1_Health_t;

extern DataObject iedModel_RPN_ATCC1_NamPlt;
extern DataAttribute iedModel_RPN_ATCC1_NamPlt_vendor;
extern DataAttribute iedModel_RPN_ATCC1_NamPlt_swRev;
extern DataAttribute iedModel_RPN_ATCC1_NamPlt_d;


extern DataObject iedModel_RPN_ATCC1_Loc;
extern DataAttribute iedModel_RPN_ATCC1_Loc_stVal;
extern DataAttribute iedModel_RPN_ATCC1_Loc_q;
extern DataAttribute iedModel_RPN_ATCC1_Loc_t;

/*
//TapChg
extern DataObject iedModel_RPN_ATCC1_TapChg;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_ctlNum;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_q;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_t;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel;
*/
//TapChg
extern DataObject iedModel_RPN_ATCC1_TapChg;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_q;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_t;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_d;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr_posVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_persistent;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_T;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Test;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Check;

//ParOp
extern DataObject iedModel_RPN_ATCC1_ParOp;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_q;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_t;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_d;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_stVal;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orCat;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_origin_orIdent;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_ctlNum;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_T;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Test;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_Oper_Check;
/*
//ParOp
extern DataObject iedModel_RPN_ATCC1_ParOp;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_stVal;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_q;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_t;
extern DataAttribute iedModel_RPN_ATCC1_ParOp_ctlModel;
*/

//CtlV1
extern DataObject    iedModel_RPN_ATCC1_CtlV1;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV1_dU;

//CtlV2
extern DataObject    iedModel_RPN_ATCC1_CtlV2;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV2_dU;

//CtlV3
extern DataObject    iedModel_RPN_ATCC1_CtlV3;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV3_dU;

//CtlV4
extern DataObject    iedModel_RPN_ATCC1_CtlV4;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV4_dU;

//CtlV5
extern DataObject    iedModel_RPN_ATCC1_CtlV5;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV5_dU;

//CtlV6
extern DataObject    iedModel_RPN_ATCC1_CtlV6;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV6_dU;

//CtlV7
extern DataObject    iedModel_RPN_ATCC1_CtlV7;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV7_dU;

//CtlV8
extern DataObject    iedModel_RPN_ATCC1_CtlV8;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_mag;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_q;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_t;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_db;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_CtlV8_dU;


//LodA1
extern DataObject    iedModel_RPN_ATCC1_LodA1;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_mag;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_q;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_t;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_db;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_LodA1_dU;

//LodA2
extern DataObject    iedModel_RPN_ATCC1_LodA2;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_mag;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_q;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_t;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_db;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_LodA2_dU;

//LodA3
extern DataObject    iedModel_RPN_ATCC1_LodA3;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_mag;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_q;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_t;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_db;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_LodA3_dU;

//LodA4
extern DataObject    iedModel_RPN_ATCC1_LodA4;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_mag;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_mag_f;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_q;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_t;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_db;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_zeroDb;
extern DataAttribute iedModel_RPN_ATCC1_LodA4_dU;

// ---------------------------------------------------------------------------------------------------------
//  00  00000  000    0
// 0      0    0  0   0
// 0      0    0  0   0
// 0      0    000    0
// 0      0    0 0    0
//  00    0    0  0   0000
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_CTRL_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_CTRL_LLN0_Mod_q;
extern DataAttribute iedModel_CTRL_LLN0_Mod_t;
extern DataAttribute iedModel_CTRL_LLN0_Mod_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Mod_ctlModel;

extern DataObject    iedModel_CTRL_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_CTRL_LLN0_Beh_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Beh_q;
extern DataAttribute iedModel_CTRL_LLN0_Beh_t;

extern DataObject    iedModel_CTRL_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_CTRL_LLN0_Health_stVal;
extern DataAttribute iedModel_CTRL_LLN0_Health_q;
extern DataAttribute iedModel_CTRL_LLN0_Health_t;

extern DataObject    iedModel_CTRL_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_d;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_CTRL_LLN0_NamPlt_ldNs;

// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

extern DataObject    iedModel_CTRL_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
extern DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_CTRL_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t;

extern DataObject    iedModel_CTRL_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_q;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_t;

//----------------------------------------------------------------------------
// GGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_GGIO1;
extern DataObject iedModel_CTRL_GGIO1_SPCSO1;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO1_Oper_Check;

//SPCSO2
extern DataObject iedModel_CTRL_GGIO1_SPCSO2;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO2_Oper_Check;
//SPCSO3
extern DataObject iedModel_CTRL_GGIO1_SPCSO3;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO3_Oper_Check;

extern DataObject iedModel_CTRL_GGIO1_SPCSO4;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_q;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_t;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_d;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_ctlModel;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_T;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Test;
extern DataAttribute iedModel_CTRL_GGIO1_SPCSO4_Oper_Check;

// ---------------------------------------------------------------------------------------------------------
//   000   000  000   00
//  0     0      0   0  0
//  0     0      0   0  0
//  0     0      0   0  0
//  0  0  0  0   0   0  0
//   000   000  000   00
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_GGIO_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_GGIO_LLN0_Mod_q;
extern DataAttribute iedModel_GGIO_LLN0_Mod_t;
extern DataAttribute iedModel_GGIO_LLN0_Mod_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Mod_ctlModel;

extern DataObject    iedModel_GGIO_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_GGIO_LLN0_Beh_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Beh_q;
extern DataAttribute iedModel_GGIO_LLN0_Beh_t;

extern DataObject    iedModel_GGIO_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_GGIO_LLN0_Health_stVal;
extern DataAttribute iedModel_GGIO_LLN0_Health_q;
extern DataAttribute iedModel_GGIO_LLN0_Health_t;

extern DataObject    iedModel_GGIO_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_d;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_GGIO_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_GGIO_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_GGIO_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_GGIO_LLN0_SGCB_q;
extern DataAttribute iedModel_GGIO_LLN0_SGCB_t;

// ---------------------------------------------------------------------------------------------------------
// LPHD1
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LPHD1;								// LPHD - Информация о физическом устройстве. Наименование: LPHD

extern DataObject    iedModel_GGIO_LPHD1_PhyNam;						// PhyNam - Паспортная табличка физического устройства
extern DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor;

extern DataObject    iedModel_GGIO_LPHD1_PhyHealth;					// PhyHealth - Состояние работоспособности физического устройства
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t;

extern DataObject    iedModel_GGIO_LPHD1_Proxy;						// Proxy - Означает, служит ли данный LN посредником
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_q;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_t;

// ---------------------------------------------------------------------------------------------------------
// OUT
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_OUTGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

extern DataObject    iedModel_GGIO_OUTGGIO1_Mod;							// Mod - Режим
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel;

extern DataObject    iedModel_GGIO_OUTGGIO1_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d;

//SPCSO1
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
//SPCSO2
extern DataObject 	  iedModel_GGIO_OUTGGIO1_SPCSO2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
//SPCSO3
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
//SPCSO4
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
//SPCSO5
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
//SPCSO6
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
//SPCSO7
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
//SPCSO8
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
//SPCSO9
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;
//SPCSO10
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;
//SPCSO11
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;
//SPCSO12
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;
//SPCSO13
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;
//SPCSO14
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;
/*
//SPCSO15
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;
*/


// ---------------------------------------------------------------------------------------------------------
// LED
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LEDGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

extern DataObject    iedModel_GGIO_LEDGGIO1_Mod;							// Mod - Режим
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Mod_ctlModel;

extern DataObject    iedModel_GGIO_LEDGGIO1_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Beh_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Health_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LEDGGIO1_NamPlt_d;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind1;							//Ind Индикация
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t;

// ------------------------------------------------------------
// IN
// ------------------------------------------------------------

extern LogicalNode iedModel_GGIO_INGGIO1;

extern DataObject iedModel_GGIO_INGGIO1_Mod;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_ctlModel;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_T;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Test;
extern DataAttribute iedModel_GGIO_INGGIO1_Mod_Oper_Check;
//Beh
extern DataObject iedModel_GGIO_INGGIO1_Beh;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Beh_t;
//Health
extern DataObject iedModel_GGIO_INGGIO1_Health;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Health_t;
//NamPlt
extern DataObject iedModel_GGIO_INGGIO1_NamPlt;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_INGGIO1_NamPlt_d;
extern DataObject    iedModel_GGIO_INGGIO1_Ind1;							//Ind Индикация
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind13_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind14_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind15_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind16_t;

//TapChg
extern DataObject iedModel_RPN_ATCC1_TapChg;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_q;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_t;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_d;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_valWTr_posVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_persistent;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_ctlModel;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlVal;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orCat;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_origin_orIdent;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_ctlNum;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_T;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Test;
extern DataAttribute iedModel_RPN_ATCC1_TapChg_Oper_Check;


#endif /* STATIC_MODEL_H_ */
