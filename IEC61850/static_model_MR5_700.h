/*
 * static_model.h
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

#ifndef STATIC_MODEL_MR5_700_H_
#define STATIC_MODEL_MR5_700_H_


#include <stdlib.h>
#include "model.h"
#include "iec61850_server.h"
#include "iec61850_common.h"

extern IedServer iedServer;

extern IedModel 	iedModel;
extern LogicalDevice iedModel_Generic_LD0;
extern LogicalDevice iedModel_Generic_PROT;
extern LogicalDevice iedModel_Generic_CTRL;
extern LogicalDevice iedModel_Generic_MES;
extern LogicalDevice iedModel_Generic_GGIO;

extern SettingGroupControlBlock iedModel_LD0_LLN0_sgcb0;
// -----------------------------------------------------------------------------
// LN LLN0 - Логический нуль узла. см. 61850-7-4 п.5.3.4
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LLN0;

// Mod см. 61850-7-3 п.7.5.4
extern DataObject    iedModel_LD0_LLN0_Mod;					// РЕЖИМ
extern DataAttribute iedModel_LD0_LLN0_Mod_q;					// 		признака качества
extern DataAttribute iedModel_LD0_LLN0_Mod_t;					// 		метки времени
extern DataAttribute iedModel_LD0_LLN0_Mod_stVal;				// 		значение состояния данных INT32
extern DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;			//		модель управления

// Beh см. 61850-7-3 п.7.3.4
extern DataObject    iedModel_LD0_LLN0_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_LD0_LLN0_Beh_stVal;				// 		значение состояния данных INT32
extern DataAttribute iedModel_LD0_LLN0_Beh_q;					// 		признака качества
extern DataAttribute iedModel_LD0_LLN0_Beh_t;					// 		метки времени

// Health см. 61850-7-3 п.7.3.4
extern DataObject    iedModel_LD0_LLN0_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_LD0_LLN0_Health_stVal;			// 		значение состояния данных INT32
extern DataAttribute iedModel_LD0_LLN0_Health_q;				// 		признака качества
extern DataAttribute iedModel_LD0_LLN0_Health_t;				// 		метки времени

// NamPlt см. 61850-7-3 п.7.9.3
extern DataObject    iedModel_LD0_LLN0_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;			// 		Имя поставщика
extern DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_LD0_LLN0_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN.
extern DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;		//		Однозначно определяет конфигурацию экземпляра логического устройства LD. (должен менятся при любом изменении семантики модели LD)
extern DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;			//		Пространство имен логического устройства. См. 61850-7-1

extern DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

// -----------------------------------------------------------------------------
// LN LLN0 - Логический нуль узла. см. 61850-7-4 п.5.3.4
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_LLN0;

// Mod см. 61850-7-3 п.7.5.4
extern DataObject    iedModel_PROT_LLN0_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_LLN0_Mod_q;					// 		признака качества
extern DataAttribute iedModel_PROT_LLN0_Mod_t;					// 		метки времени
extern DataAttribute iedModel_PROT_LLN0_Mod_stVal;				// 		значение состояния данных INT32
extern DataAttribute iedModel_PROT_LLN0_Mod_ctlModel;			//		модель управления

// Beh см. 61850-7-3 п.7.3.4
extern DataObject    iedModel_PROT_LLN0_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_LLN0_Beh_stVal;				// 		значение состояния данных INT32
extern DataAttribute iedModel_PROT_LLN0_Beh_q;					// 		признака качества
extern DataAttribute iedModel_PROT_LLN0_Beh_t;					// 		метки времени

// Health см. 61850-7-3 п.7.3.4
extern DataObject    iedModel_PROT_LLN0_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_LLN0_Health_stVal;			// 		значение состояния данных INT32
extern DataAttribute iedModel_PROT_LLN0_Health_q;				// 		признака качества
extern DataAttribute iedModel_PROT_LLN0_Health_t;				// 		метки времени

// NamPlt см. 61850-7-3 п.7.9.3
extern DataObject    iedModel_PROT_LLN0_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_LLN0_NamPlt_vendor;			// 		Имя поставщика
extern DataAttribute iedModel_PROT_LLN0_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_LLN0_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN.
extern DataAttribute iedModel_PROT_LLN0_NamPlt_configRev;		//		Однозначно определяет конфигурацию экземпляра логического устройства LD. (должен менятся при любом изменении семантики модели LD)
extern DataAttribute iedModel_PROT_LLN0_NamPlt_ldNs;			//		Пространство имен логического устройства. См. 61850-7-1

extern DataObject    iedModel_PROT_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_PROT_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_PROT_LLN0_SGCB_q;
extern DataAttribute iedModel_PROT_LLN0_SGCB_t;
// -----------------------------------------------------------------------------
// LN LPHD1 - Информация о физическом устройстве. см. 61850-7-4 п.5.3.2
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_LD0_LPHD1;

extern DataObject    iedModel_LD0_LPHD1_PhyNam;
extern DataAttribute iedModel_LD0_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_LD0_LPHD1_PhyHealth;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LD0_LPHD1_PhyHealth_t;
extern DataObject    iedModel_LD0_LPHD1_Proxy;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_q;
extern DataAttribute iedModel_LD0_LPHD1_Proxy_t;
// -----------------------------------------------------------------------------

extern LogicalNode   iedModel_PROT_LPHD1;

// PhyNam см. 61850-7-3 п.7.9.2
extern DataObject    iedModel_PROT_LPHD1_PhyNam;				// ПАСПОРТНАЯ ТАБЛИЧКА ФИЗИЧЕСКОГО УСТРОЙСТВА
extern DataAttribute iedModel_PROT_LPHD1_PhyNam_vendor;		// 		Имя поставщика

// PhyHealth см. 61850-7-3 п.7.3.4
extern DataObject    iedModel_PROT_LPHD1_PhyHealth;			// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ ФИЗИЧЕСКОГО УСТРОЙСТВА
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_stVal;		// 		значение состояния данных INT32
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_q;			// 		признака качества
extern DataAttribute iedModel_PROT_LPHD1_PhyHealth_t;			// 		метки времени

// Proxy см. 61850-7-3 п.7.3.2
extern DataObject    iedModel_PROT_LPHD1_Proxy;				// СЛУЖИТ ЛИ ДАННЫЙ УЗЕЛ ПОСРЕДНИКОМ
extern DataAttribute iedModel_PROT_LPHD1_Proxy_stVal;			// 		значение состояния данных Boolean (ДА/НЕТ)
extern DataAttribute iedModel_PROT_LPHD1_Proxy_q;				// 		признака качества
extern DataAttribute iedModel_PROT_LPHD1_Proxy_t;				// 		метки времени
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_LPHD1;

extern DataObject    iedModel_CTRL_LPHD1_PhyNam;
extern DataAttribute iedModel_CTRL_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_CTRL_LPHD1_PhyHealth;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_CTRL_LPHD1_PhyHealth_t;
extern DataObject    iedModel_CTRL_LPHD1_Proxy;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_q;
extern DataAttribute iedModel_CTRL_LPHD1_Proxy_t;
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LPHD1;

extern DataObject    iedModel_MES_LPHD1_PhyNam;
extern DataAttribute iedModel_MES_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_MES_LPHD1_PhyHealth;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_MES_LPHD1_PhyHealth_t;
extern DataObject    iedModel_MES_LPHD1_Proxy;
extern DataAttribute iedModel_MES_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_MES_LPHD1_Proxy_q;
extern DataAttribute iedModel_MES_LPHD1_Proxy_t;
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_LPHD1;

extern DataObject    iedModel_GGIO_LPHD1_PhyNam;
extern DataAttribute iedModel_GGIO_LPHD1_PhyNam_vendor;
extern DataObject    iedModel_GGIO_LPHD1_PhyHealth;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_GGIO_LPHD1_PhyHealth_t;
extern DataObject    iedModel_GGIO_LPHD1_Proxy;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_q;
extern DataAttribute iedModel_GGIO_LPHD1_Proxy_t;


// ---------------------------------------------------------------------------------------------------------
LogicalNode   iedModel_GGIO_OUTGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

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
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO1;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;
//SPCSO2
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
//SPCSO3
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
//SPCSO4
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
//SPCSO5
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
//SPCSO6
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
//SPCSO7
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
//SPCSO8
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;

LogicalNode   iedModel_GGIO_LEDGGIO1;								// GGIO - Вход/выход для общих процессов. Имя: GGIO

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
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind1_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind2_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind3_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind4_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind5_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind6_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind7_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind8_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind9_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind10_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind11_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind12_dU;


// ------------------------------------------------------------ SPC8GGIO
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


//----------------------------------------------------------------------------
extern LogicalNode iedModel_GGIO_SSLGGIO1;

extern DataObject iedModel_GGIO_SSLGGIO1_Mod;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_SSLGGIO1_Beh;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Beh_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Health;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Health_t;

extern DataObject iedModel_GGIO_SSLGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_SSLGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind1_t;


extern DataObject iedModel_GGIO_SSLGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind8_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind16_t;


extern DataObject iedModel_GGIO_SSLGGIO1_Ind17;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind17_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind18;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind18_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind19;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind19_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind20;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind20_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind21;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind21_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind22;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind22_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind23;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind23_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind24;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind24_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_GGIO_VLSGGIO1;

extern DataObject iedModel_GGIO_VLSGGIO1_Mod;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_VLSGGIO1_Beh;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Beh_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Health;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Health_t;

extern DataObject iedModel_GGIO_VLSGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_VLSGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind1_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind8_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_GGIO_LSGGIO1;

extern DataObject iedModel_GGIO_LSGGIO1_Mod;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Mod_ctlModel;

extern DataObject iedModel_GGIO_LSGGIO1_Beh;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Beh_t;

extern DataObject iedModel_GGIO_LSGGIO1_Health;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Health_t;

extern DataObject iedModel_GGIO_LSGGIO1_NamPlt;

extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_GGIO_LSGGIO1_NamPlt_d;

extern DataObject iedModel_GGIO_LSGGIO1_Ind1;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind1_t;


extern DataObject iedModel_GGIO_LSGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind2_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind3_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind4_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind5_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind6_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind7_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind8_t;

// -----------------------------------------------------------------------------
// LN MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU1;

// Mod																// обязательные элементы -------------------------------------
extern DataObject    iedModel_MES_MMXU1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_MES_MMXU1_Mod_q;
extern DataAttribute iedModel_MES_MMXU1_Mod_t;
extern DataAttribute iedModel_MES_MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU1_Mod_ctlModel;

// Beh
extern DataObject    iedModel_MES_MMXU1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_MES_MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU1_Beh_q;
extern DataAttribute iedModel_MES_MMXU1_Beh_t;

// Health
extern DataObject    iedModel_MES_MMXU1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_MES_MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_MMXU1_Health_q;
extern DataAttribute iedModel_MES_MMXU1_Health_t;

// NamPlt
extern DataObject    iedModel_MES_MMXU1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_MES_MMXU1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_MES_MMXU1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_MES_MMXU1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN MMXU1.

extern DataObject iedModel_MES_MMXU1_A;
extern DataObject iedModel_MES_MMXU1_A_phsA;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsA_zeroDb;


extern DataObject iedModel_MES_MMXU1_A_phsB;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsB_zeroDb;

extern DataObject iedModel_MES_MMXU1_A_phsC;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_A_phsC_zeroDb;

extern DataObject iedModel_MES_MMXU1_A_neut;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_A_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_A_neut_q;
extern DataAttribute iedModel_MES_MMXU1_A_neut_t;
extern DataAttribute iedModel_MES_MMXU1_A_neut_db;
extern DataAttribute iedModel_MES_MMXU1_A_neut_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV;
extern DataObject iedModel_MES_MMXU1_phV_phsA;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsA_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_phsB;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsB_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_phsC;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_phV_phsC_zeroDb;

extern DataObject iedModel_MES_MMXU1_phV_neut;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_q;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_t;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_db;
extern DataAttribute iedModel_MES_MMXU1_phV_neut_zeroDb;
//
extern DataObject iedModel_MES_MMXU1_PPV;
extern DataObject iedModel_MES_MMXU1_PPV_phsA;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsA_zeroDb;

extern DataObject iedModel_MES_MMXU1_PPV_phsB;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsB_zeroDb;

extern DataObject iedModel_MES_MMXU1_PPV_phsC;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_q;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_t;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_db;
extern DataAttribute iedModel_MES_MMXU1_PPV_phsC_zeroDb;

//
extern DataObject    iedModel_MES_MMXU1_totW;
extern DataAttribute iedModel_MES_MMXU1_totW_mag;
extern DataAttribute iedModel_MES_MMXU1_totW_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totW_instMag;
extern DataAttribute iedModel_MES_MMXU1_totW_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totW_q;
extern DataAttribute iedModel_MES_MMXU1_totW_t;
extern DataAttribute iedModel_MES_MMXU1_totW_db;
extern DataAttribute iedModel_MES_MMXU1_totW_zeroDb;

extern DataObject    iedModel_MES_MMXU1_totVAr;
extern DataAttribute iedModel_MES_MMXU1_totVAr_mag;
extern DataAttribute iedModel_MES_MMXU1_totVAr_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totVAr_instMag;
extern DataAttribute iedModel_MES_MMXU1_totVAr_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totVAr_q;
extern DataAttribute iedModel_MES_MMXU1_totVAr_t;
extern DataAttribute iedModel_MES_MMXU1_totVAr_db;
extern DataAttribute iedModel_MES_MMXU1_totVAr_zeroDb;

extern DataObject    iedModel_MES_MMXU1_totPF;
extern DataAttribute iedModel_MES_MMXU1_totPF_mag;
extern DataAttribute iedModel_MES_MMXU1_totPF_mag_f;
extern DataAttribute iedModel_MES_MMXU1_totPF_instMag;
extern DataAttribute iedModel_MES_MMXU1_totPF_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_totPF_q;
extern DataAttribute iedModel_MES_MMXU1_totPF_t;
extern DataAttribute iedModel_MES_MMXU1_totPF_db;
extern DataAttribute iedModel_MES_MMXU1_totPF_zeroDb;

extern DataObject    iedModel_MES_MMXU1_Hz;
extern DataAttribute iedModel_MES_MMXU1_Hz_mag;
extern DataAttribute iedModel_MES_MMXU1_Hz_mag_f;
extern DataAttribute iedModel_MES_MMXU1_Hz_instMag;
extern DataAttribute iedModel_MES_MMXU1_Hz_instMag_f;
extern DataAttribute iedModel_MES_MMXU1_Hz_q;
extern DataAttribute iedModel_MES_MMXU1_Hz_t;
extern DataAttribute iedModel_MES_MMXU1_Hz_db;
extern DataAttribute iedModel_MES_MMXU1_Hz_zeroDb;

//--------------------------------------
extern LogicalNode iedModel_MES_MSQI1;

extern DataObject iedModel_MES_MSQI1_Mod;
extern DataAttribute iedModel_MES_MSQI1_Mod_q;
extern DataAttribute iedModel_MES_MSQI1_Mod_t;
extern DataAttribute iedModel_MES_MSQI1_Mod_stVal;
extern DataAttribute iedModel_MES_MSQI1_Mod_ctlModel;

extern DataObject iedModel_MES_MSQI1_Beh;
extern DataAttribute iedModel_MES_MSQI1_Beh_stVal;
extern DataAttribute iedModel_MES_MSQI1_Beh_q;
extern DataAttribute iedModel_MES_MSQI1_Beh_t;

extern DataObject iedModel_MES_MSQI1_Health;
extern DataAttribute iedModel_MES_MSQI1_Health_stVal;
extern DataAttribute iedModel_MES_MSQI1_Health_q;
extern DataAttribute iedModel_MES_MSQI1_Health_t;

extern DataObject iedModel_MES_MSQI1_NamPlt;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_vendor;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_swRev;
extern DataAttribute iedModel_MES_MSQI1_NamPlt_d;

// SeqA
extern DataObject iedModel_MES_MSQI1_SeqA;
extern DataObject iedModel_MES_MSQI1_SeqA_c1;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c1_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqA_c2;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c2_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqA_c3;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_q;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_t;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_db;
extern DataAttribute iedModel_MES_MSQI1_SeqA_c3_zeroDb;

extern DataAttribute iedModel_MES_MSQI1_SeqA_SeqT;
// SeqU
extern DataObject iedModel_MES_MSQI1_SeqU;
extern DataObject iedModel_MES_MSQI1_SeqU_c1;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c1_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqU_c2;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c2_zeroDb;

extern DataObject iedModel_MES_MSQI1_SeqU_c3;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_instCVal_mag_f;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_q;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_t;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_db;
extern DataAttribute iedModel_MES_MSQI1_SeqU_c3_zeroDb;
extern DataAttribute iedModel_MES_MSQI1_SeqU_SeqT;

//--------------------------------------
extern LogicalNode iedModel_MES_RFLO1;
extern DataObject iedModel_MES_RFLO1_Mod;
extern DataAttribute iedModel_MES_RFLO1_Mod_q;
extern DataAttribute iedModel_MES_RFLO1_Mod_t;
extern DataAttribute iedModel_MES_RFLO1_Mod_stVal;
extern DataAttribute iedModel_MES_RFLO1_Mod_ctlModel;

extern DataObject iedModel_MES_RFLO1_Beh;
extern DataAttribute iedModel_MES_RFLO1_Beh_stVal;
extern DataAttribute iedModel_MES_RFLO1_Beh_q;
extern DataAttribute iedModel_MES_RFLO1_Beh_t;

extern DataObject iedModel_MES_RFLO1_Health;
extern DataAttribute iedModel_MES_RFLO1_Health_stVal;
extern DataAttribute iedModel_MES_RFLO1_Health_q;
extern DataAttribute iedModel_MES_RFLO1_Health_t;

extern DataObject iedModel_MES_RFLO1_NamPlt;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_vendor;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_swRev;
extern DataAttribute iedModel_MES_RFLO1_NamPlt_d;

extern DataObject    iedModel_MES_RFLO1_Fltz;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal_mag;
extern DataAttribute iedModel_MES_RFLO1_Fltz_cVal_mag_f;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal_mag;
extern DataAttribute iedModel_MES_RFLO1_Fltz_instCVal_mag_f;
extern DataAttribute iedModel_MES_RFLO1_Fltz_q;
extern DataAttribute iedModel_MES_RFLO1_Fltz_t;
extern DataAttribute iedModel_MES_RFLO1_Fltz_db;
extern DataAttribute iedModel_MES_RFLO1_Fltz_zeroDb;

extern DataObject    iedModel_MES_RFLO1_FltDiskm;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_mag;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_mag_f;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_instMag;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_instMag_f;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_q;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_t;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_db;
extern DataAttribute iedModel_MES_RFLO1_FltDiskm_zeroDb;

// -----------------------------------------------------------
/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC1;

extern DataObject    iedModel_PROT_IPTOC1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC1_Beh_t;

extern DataObject    iedModel_PROT_IPTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC1_Health_q;
extern DataAttribute iedModel_PROT_IPTOC1_Health_t;

extern DataObject    iedModel_PROT_IPTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC1_Str;
extern DataAttribute iedModel_PROT_IPTOC1_Str_general;
extern DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC1_Str_q;
extern DataAttribute iedModel_PROT_IPTOC1_Str_t;

extern DataObject    iedModel_PROT_IPTOC1_Op;
extern DataAttribute iedModel_PROT_IPTOC1_Op_general;
extern DataAttribute iedModel_PROT_IPTOC1_Op_q;
extern DataAttribute iedModel_PROT_IPTOC1_Op_t;

/****************************************************************
* LN iPTOC2
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC2;

extern DataObject    iedModel_PROT_IPTOC2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC2_Beh_t;

extern DataObject    iedModel_PROT_IPTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC2_Health_q;
extern DataAttribute iedModel_PROT_IPTOC2_Health_t;

extern DataObject    iedModel_PROT_IPTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC2_Str;
extern DataAttribute iedModel_PROT_IPTOC2_Str_general;
extern DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC2_Str_q;
extern DataAttribute iedModel_PROT_IPTOC2_Str_t;

extern DataObject    iedModel_PROT_IPTOC2_Op;
extern DataAttribute iedModel_PROT_IPTOC2_Op_general;
extern DataAttribute iedModel_PROT_IPTOC2_Op_q;
extern DataAttribute iedModel_PROT_IPTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC3;

extern DataObject    iedModel_PROT_IPTOC3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC3_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC3_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC3_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC3_Beh_t;

extern DataObject    iedModel_PROT_IPTOC3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC3_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC3_Health_q;
extern DataAttribute iedModel_PROT_IPTOC3_Health_t;

extern DataObject    iedModel_PROT_IPTOC3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC3_Str;
extern DataAttribute iedModel_PROT_IPTOC3_Str_general;
extern DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC3_Str_q;
extern DataAttribute iedModel_PROT_IPTOC3_Str_t;

extern DataObject    iedModel_PROT_IPTOC3_Op;
extern DataAttribute iedModel_PROT_IPTOC3_Op_general;
extern DataAttribute iedModel_PROT_IPTOC3_Op_q;
extern DataAttribute iedModel_PROT_IPTOC3_Op_t;

/****************************************************************
* LN IPTOC4
*****************************************************************/
extern LogicalNode   iedModel_PROT_IPTOC4;

extern DataObject    iedModel_PROT_IPTOC4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC4_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_ctlModel;

extern DataObject    iedModel_PROT_IPTOC4_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC4_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC4_Beh_t;

extern DataObject    iedModel_PROT_IPTOC4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC4_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC4_Health_q;
extern DataAttribute iedModel_PROT_IPTOC4_Health_t;

extern DataObject    iedModel_PROT_IPTOC4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC4_Str;
extern DataAttribute iedModel_PROT_IPTOC4_Str_general;
extern DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC4_Str_q;
extern DataAttribute iedModel_PROT_IPTOC4_Str_t;

extern DataObject    iedModel_PROT_IPTOC4_Op;
extern DataAttribute iedModel_PROT_IPTOC4_Op_general;
extern DataAttribute iedModel_PROT_IPTOC4_Op_q;
extern DataAttribute iedModel_PROT_IPTOC4_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I2PTOC1;

extern DataObject    iedModel_PROT_I2PTOC1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_I2PTOC1_Mod_q;
extern DataAttribute iedModel_PROT_I2PTOC1_Mod_t;
extern DataAttribute iedModel_PROT_I2PTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_I2PTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_I2PTOC1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_I2PTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_I2PTOC1_Beh_q;
extern DataAttribute iedModel_PROT_I2PTOC1_Beh_t;

extern DataObject    iedModel_PROT_I2PTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_I2PTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_I2PTOC1_Health_q;
extern DataAttribute iedModel_PROT_I2PTOC1_Health_t;

extern DataObject    iedModel_PROT_I2PTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_I2PTOC1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_I2PTOC1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_I2PTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_I2PTOC1_Str;
extern DataAttribute iedModel_PROT_I2PTOC1_Str_general;
extern DataAttribute iedModel_PROT_I2PTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I2PTOC1_Str_q;
extern DataAttribute iedModel_PROT_I2PTOC1_Str_t;

extern DataObject    iedModel_PROT_I2PTOC1_Op;
extern DataAttribute iedModel_PROT_I2PTOC1_Op_general;
extern DataAttribute iedModel_PROT_I2PTOC1_Op_q;
extern DataAttribute iedModel_PROT_I2PTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I2PTOC2;

extern DataObject    iedModel_PROT_I2PTOC2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_I2PTOC2_Mod_q;
extern DataAttribute iedModel_PROT_I2PTOC2_Mod_t;
extern DataAttribute iedModel_PROT_I2PTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_I2PTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_I2PTOC2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_I2PTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_I2PTOC2_Beh_q;
extern DataAttribute iedModel_PROT_I2PTOC2_Beh_t;

extern DataObject    iedModel_PROT_I2PTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_I2PTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_I2PTOC2_Health_q;
extern DataAttribute iedModel_PROT_I2PTOC2_Health_t;

extern DataObject    iedModel_PROT_I2PTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_I2PTOC2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_I2PTOC2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_I2PTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_I2PTOC2_Str;
extern DataAttribute iedModel_PROT_I2PTOC2_Str_general;
extern DataAttribute iedModel_PROT_I2PTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I2PTOC2_Str_q;
extern DataAttribute iedModel_PROT_I2PTOC2_Str_t;

extern DataObject    iedModel_PROT_I2PTOC2_Op;
extern DataAttribute iedModel_PROT_I2PTOC2_Op_general;
extern DataAttribute iedModel_PROT_I2PTOC2_Op_q;
extern DataAttribute iedModel_PROT_I2PTOC2_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I0PTOC1;

extern DataObject    iedModel_PROT_I0PTOC1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_I0PTOC1_Mod_q;
extern DataAttribute iedModel_PROT_I0PTOC1_Mod_t;
extern DataAttribute iedModel_PROT_I0PTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_I0PTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_I0PTOC1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_I0PTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_I0PTOC1_Beh_q;
extern DataAttribute iedModel_PROT_I0PTOC1_Beh_t;

extern DataObject    iedModel_PROT_I0PTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_I0PTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_I0PTOC1_Health_q;
extern DataAttribute iedModel_PROT_I0PTOC1_Health_t;

extern DataObject    iedModel_PROT_I0PTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_I0PTOC1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_I0PTOC1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_I0PTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_I0PTOC1_Str;
extern DataAttribute iedModel_PROT_I0PTOC1_Str_general;
extern DataAttribute iedModel_PROT_I0PTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I0PTOC1_Str_q;
extern DataAttribute iedModel_PROT_I0PTOC1_Str_t;

extern DataObject    iedModel_PROT_I0PTOC1_Op;
extern DataAttribute iedModel_PROT_I0PTOC1_Op_general;
extern DataAttribute iedModel_PROT_I0PTOC1_Op_q;
extern DataAttribute iedModel_PROT_I0PTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I0PTOC2;

extern DataObject    iedModel_PROT_I0PTOC2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_I0PTOC2_Mod_q;
extern DataAttribute iedModel_PROT_I0PTOC2_Mod_t;
extern DataAttribute iedModel_PROT_I0PTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_I0PTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_I0PTOC2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_I0PTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_I0PTOC2_Beh_q;
extern DataAttribute iedModel_PROT_I0PTOC2_Beh_t;

extern DataObject    iedModel_PROT_I0PTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_I0PTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_I0PTOC2_Health_q;
extern DataAttribute iedModel_PROT_I0PTOC2_Health_t;

extern DataObject    iedModel_PROT_I0PTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_I0PTOC2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_I0PTOC2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_I0PTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_I0PTOC2_Str;
extern DataAttribute iedModel_PROT_I0PTOC2_Str_general;
extern DataAttribute iedModel_PROT_I0PTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I0PTOC2_Str_q;
extern DataAttribute iedModel_PROT_I0PTOC2_Str_t;

extern DataObject    iedModel_PROT_I0PTOC2_Op;
extern DataAttribute iedModel_PROT_I0PTOC2_Op_general;
extern DataAttribute iedModel_PROT_I0PTOC2_Op_q;
extern DataAttribute iedModel_PROT_I0PTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_INPTOC1;

extern DataObject    iedModel_PROT_INPTOC1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_INPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Mod_ctlModel;

extern DataObject    iedModel_PROT_INPTOC1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_INPTOC1_Beh_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Beh_q;
extern DataAttribute iedModel_PROT_INPTOC1_Beh_t;

extern DataObject    iedModel_PROT_INPTOC1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_INPTOC1_Health_stVal;
extern DataAttribute iedModel_PROT_INPTOC1_Health_q;
extern DataAttribute iedModel_PROT_INPTOC1_Health_t;

extern DataObject    iedModel_PROT_INPTOC1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_INPTOC1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_INPTOC1_Str;
extern DataAttribute iedModel_PROT_INPTOC1_Str_general;
extern DataAttribute iedModel_PROT_INPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_INPTOC1_Str_q;
extern DataAttribute iedModel_PROT_INPTOC1_Str_t;

extern DataObject    iedModel_PROT_INPTOC1_Op;
extern DataAttribute iedModel_PROT_INPTOC1_Op_general;
extern DataAttribute iedModel_PROT_INPTOC1_Op_q;
extern DataAttribute iedModel_PROT_INPTOC1_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_INPTOC2;

extern DataObject    iedModel_PROT_INPTOC2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_INPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Mod_ctlModel;

extern DataObject    iedModel_PROT_INPTOC2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_INPTOC2_Beh_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Beh_q;
extern DataAttribute iedModel_PROT_INPTOC2_Beh_t;

extern DataObject    iedModel_PROT_INPTOC2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_INPTOC2_Health_stVal;
extern DataAttribute iedModel_PROT_INPTOC2_Health_q;
extern DataAttribute iedModel_PROT_INPTOC2_Health_t;

extern DataObject    iedModel_PROT_INPTOC2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_INPTOC2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_INPTOC2_Str;
extern DataAttribute iedModel_PROT_INPTOC2_Str_general;
extern DataAttribute iedModel_PROT_INPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_INPTOC2_Str_q;
extern DataAttribute iedModel_PROT_INPTOC2_Str_t;

extern DataObject    iedModel_PROT_INPTOC2_Op;
extern DataAttribute iedModel_PROT_INPTOC2_Op_general;
extern DataAttribute iedModel_PROT_INPTOC2_Op_q;
extern DataAttribute iedModel_PROT_INPTOC2_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_IGPTOC;

extern DataObject    iedModel_PROT_IGPTOC_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IGPTOC_Mod_q;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_t;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Mod_ctlModel;

extern DataObject    iedModel_PROT_IGPTOC_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IGPTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Beh_q;
extern DataAttribute iedModel_PROT_IGPTOC_Beh_t;

extern DataObject    iedModel_PROT_IGPTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IGPTOC_Health_stVal;
extern DataAttribute iedModel_PROT_IGPTOC_Health_q;
extern DataAttribute iedModel_PROT_IGPTOC_Health_t;

extern DataObject    iedModel_PROT_IGPTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IGPTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IGPTOC_Str;
extern DataAttribute iedModel_PROT_IGPTOC_Str_general;
//extern DataAttribute iedModel_PROT_IGPTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IGPTOC_Str_q;
extern DataAttribute iedModel_PROT_IGPTOC_Str_t;

extern DataObject    iedModel_PROT_IGPTOC_Op;
extern DataAttribute iedModel_PROT_IGPTOC_Op_general;
extern DataAttribute iedModel_PROT_IGPTOC_Op_q;
extern DataAttribute iedModel_PROT_IGPTOC_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_I2I1PTOC;

extern DataObject    iedModel_PROT_I2I1PTOC_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_t;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Mod_ctlModel;

extern DataObject    iedModel_PROT_I2I1PTOC_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Beh_t;

extern DataObject    iedModel_PROT_I2I1PTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_stVal;
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Health_t;

extern DataObject    iedModel_PROT_I2I1PTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_I2I1PTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_I2I1PTOC_Str;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_general;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Str_t;

extern DataObject    iedModel_PROT_I2I1PTOC_Op;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_general;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_q;
extern DataAttribute iedModel_PROT_I2I1PTOC_Op_t;

/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV1;

extern DataObject    iedModel_PROT_UPTOV1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTOV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTOV1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTOV1_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV1_Beh_t;

extern DataObject    iedModel_PROT_UPTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTOV1_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV1_Health_q;
extern DataAttribute iedModel_PROT_UPTOV1_Health_t;

extern DataObject    iedModel_PROT_UPTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV1_Str;
extern DataAttribute iedModel_PROT_UPTOV1_Str_general;
extern DataAttribute iedModel_PROT_UPTOV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV1_Str_q;
extern DataAttribute iedModel_PROT_UPTOV1_Str_t;

extern DataObject    iedModel_PROT_UPTOV1_Op;
extern DataAttribute iedModel_PROT_UPTOV1_Op_general;
extern DataAttribute iedModel_PROT_UPTOV1_Op_q;
extern DataAttribute iedModel_PROT_UPTOV1_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV2;

extern DataObject    iedModel_PROT_UPTOV2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTOV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTOV2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTOV2_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV2_Beh_t;

extern DataObject    iedModel_PROT_UPTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTOV2_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV2_Health_q;
extern DataAttribute iedModel_PROT_UPTOV2_Health_t;

extern DataObject    iedModel_PROT_UPTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV2_Str;
extern DataAttribute iedModel_PROT_UPTOV2_Str_general;
extern DataAttribute iedModel_PROT_UPTOV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV2_Str_q;
extern DataAttribute iedModel_PROT_UPTOV2_Str_t;

extern DataObject    iedModel_PROT_UPTOV2_Op;
extern DataAttribute iedModel_PROT_UPTOV2_Op_general;
extern DataAttribute iedModel_PROT_UPTOV2_Op_q;
extern DataAttribute iedModel_PROT_UPTOV2_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV1;

extern DataObject    iedModel_PROT_UPTUV1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTUV1_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTUV1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTUV1_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV1_Beh_t;

extern DataObject    iedModel_PROT_UPTUV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTUV1_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV1_Health_q;
extern DataAttribute iedModel_PROT_UPTUV1_Health_t;

extern DataObject    iedModel_PROT_UPTUV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTUV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV1_Str;
extern DataAttribute iedModel_PROT_UPTUV1_Str_general;
extern DataAttribute iedModel_PROT_UPTUV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV1_Str_q;
extern DataAttribute iedModel_PROT_UPTUV1_Str_t;

extern DataObject    iedModel_PROT_UPTUV1_Op;
extern DataAttribute iedModel_PROT_UPTUV1_Op_general;
extern DataAttribute iedModel_PROT_UPTUV1_Op_q;
extern DataAttribute iedModel_PROT_UPTUV1_Op_t;


/****************************************************************
* LN iPTOC1
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV2;

extern DataObject    iedModel_PROT_UPTUV2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTUV2_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTUV2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTUV2_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV2_Beh_t;

extern DataObject    iedModel_PROT_UPTUV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTUV2_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV2_Health_q;
extern DataAttribute iedModel_PROT_UPTUV2_Health_t;

extern DataObject    iedModel_PROT_UPTUV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTUV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV2_Str;
extern DataAttribute iedModel_PROT_UPTUV2_Str_general;
extern DataAttribute iedModel_PROT_UPTUV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV2_Str_q;
extern DataAttribute iedModel_PROT_UPTUV2_Str_t;

extern DataObject    iedModel_PROT_UPTUV2_Op;
extern DataAttribute iedModel_PROT_UPTUV2_Op_general;
extern DataAttribute iedModel_PROT_UPTUV2_Op_q;
extern DataAttribute iedModel_PROT_UPTUV2_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_U2PTOV1;

extern DataObject    iedModel_PROT_U2PTOV1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_U2PTOV1_Mod_q;
extern DataAttribute iedModel_PROT_U2PTOV1_Mod_t;
extern DataAttribute iedModel_PROT_U2PTOV1_Mod_stVal;
extern DataAttribute iedModel_PROT_U2PTOV1_Mod_ctlModel;

extern DataObject    iedModel_PROT_U2PTOV1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_U2PTOV1_Beh_stVal;
extern DataAttribute iedModel_PROT_U2PTOV1_Beh_q;
extern DataAttribute iedModel_PROT_U2PTOV1_Beh_t;

extern DataObject    iedModel_PROT_U2PTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_U2PTOV1_Health_stVal;
extern DataAttribute iedModel_PROT_U2PTOV1_Health_q;
extern DataAttribute iedModel_PROT_U2PTOV1_Health_t;

extern DataObject    iedModel_PROT_U2PTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_U2PTOV1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_U2PTOV1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_U2PTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_U2PTOV1_Str;
extern DataAttribute iedModel_PROT_U2PTOV1_Str_general;
extern DataAttribute iedModel_PROT_U2PTOV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_U2PTOV1_Str_q;
extern DataAttribute iedModel_PROT_U2PTOV1_Str_t;

extern DataObject    iedModel_PROT_U2PTOV1_Op;
extern DataAttribute iedModel_PROT_U2PTOV1_Op_general;
extern DataAttribute iedModel_PROT_U2PTOV1_Op_q;
extern DataAttribute iedModel_PROT_U2PTOV1_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_U2PTOV2;

extern DataObject    iedModel_PROT_U2PTOV2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_U2PTOV2_Mod_q;
extern DataAttribute iedModel_PROT_U2PTOV2_Mod_t;
extern DataAttribute iedModel_PROT_U2PTOV2_Mod_stVal;
extern DataAttribute iedModel_PROT_U2PTOV2_Mod_ctlModel;

extern DataObject    iedModel_PROT_U2PTOV2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_U2PTOV2_Beh_stVal;
extern DataAttribute iedModel_PROT_U2PTOV2_Beh_q;
extern DataAttribute iedModel_PROT_U2PTOV2_Beh_t;

extern DataObject    iedModel_PROT_U2PTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_U2PTOV2_Health_stVal;
extern DataAttribute iedModel_PROT_U2PTOV2_Health_q;
extern DataAttribute iedModel_PROT_U2PTOV2_Health_t;

extern DataObject    iedModel_PROT_U2PTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_U2PTOV2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_U2PTOV2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_U2PTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_U2PTOV2_Str;
extern DataAttribute iedModel_PROT_U2PTOV2_Str_general;
extern DataAttribute iedModel_PROT_U2PTOV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_U2PTOV2_Str_q;
extern DataAttribute iedModel_PROT_U2PTOV2_Str_t;

extern DataObject    iedModel_PROT_U2PTOV2_Op;
extern DataAttribute iedModel_PROT_U2PTOV2_Op_general;
extern DataAttribute iedModel_PROT_U2PTOV2_Op_q;
extern DataAttribute iedModel_PROT_U2PTOV2_Op_t;

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_U0PTOV1;

extern DataObject    iedModel_PROT_U0PTOV1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_U0PTOV1_Mod_q;
extern DataAttribute iedModel_PROT_U0PTOV1_Mod_t;
extern DataAttribute iedModel_PROT_U0PTOV1_Mod_stVal;
extern DataAttribute iedModel_PROT_U0PTOV1_Mod_ctlModel;

extern DataObject    iedModel_PROT_U0PTOV1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_U0PTOV1_Beh_stVal;
extern DataAttribute iedModel_PROT_U0PTOV1_Beh_q;
extern DataAttribute iedModel_PROT_U0PTOV1_Beh_t;

extern DataObject    iedModel_PROT_U0PTOV1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_U0PTOV1_Health_stVal;
extern DataAttribute iedModel_PROT_U0PTOV1_Health_q;
extern DataAttribute iedModel_PROT_U0PTOV1_Health_t;

extern DataObject    iedModel_PROT_U0PTOV1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_U0PTOV1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_U0PTOV1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_U0PTOV1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_U0PTOV1_Str;
extern DataAttribute iedModel_PROT_U0PTOV1_Str_general;
extern DataAttribute iedModel_PROT_U0PTOV1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_U0PTOV1_Str_q;
extern DataAttribute iedModel_PROT_U0PTOV1_Str_t;

extern DataObject    iedModel_PROT_U0PTOV1_Op;
extern DataAttribute iedModel_PROT_U0PTOV1_Op_general;
extern DataAttribute iedModel_PROT_U0PTOV1_Op_q;
extern DataAttribute iedModel_PROT_U0PTOV1_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_U0PTOV2;

extern DataObject    iedModel_PROT_U0PTOV2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_U0PTOV2_Mod_q;
extern DataAttribute iedModel_PROT_U0PTOV2_Mod_t;
extern DataAttribute iedModel_PROT_U0PTOV2_Mod_stVal;
extern DataAttribute iedModel_PROT_U0PTOV2_Mod_ctlModel;

extern DataObject    iedModel_PROT_U0PTOV2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_U0PTOV2_Beh_stVal;
extern DataAttribute iedModel_PROT_U0PTOV2_Beh_q;
extern DataAttribute iedModel_PROT_U0PTOV2_Beh_t;

extern DataObject    iedModel_PROT_U0PTOV2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_U0PTOV2_Health_stVal;
extern DataAttribute iedModel_PROT_U0PTOV2_Health_q;
extern DataAttribute iedModel_PROT_U0PTOV2_Health_t;

extern DataObject    iedModel_PROT_U0PTOV2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_U0PTOV2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_U0PTOV2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_U0PTOV2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_U0PTOV2_Str;
extern DataAttribute iedModel_PROT_U0PTOV2_Str_general;
extern DataAttribute iedModel_PROT_U0PTOV2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_U0PTOV2_Str_q;
extern DataAttribute iedModel_PROT_U0PTOV2_Str_t;

extern DataObject    iedModel_PROT_U0PTOV2_Op;
extern DataAttribute iedModel_PROT_U0PTOV2_Op_general;
extern DataAttribute iedModel_PROT_U0PTOV2_Op_q;
extern DataAttribute iedModel_PROT_U0PTOV2_Op_t;

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF1;

extern DataObject    iedModel_PROT_PTOF1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTOF1_Mod_q;
extern DataAttribute iedModel_PROT_PTOF1_Mod_t;
extern DataAttribute iedModel_PROT_PTOF1_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTOF1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTOF1_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Beh_q;
extern DataAttribute iedModel_PROT_PTOF1_Beh_t;

extern DataObject    iedModel_PROT_PTOF1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTOF1_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF1_Health_q;
extern DataAttribute iedModel_PROT_PTOF1_Health_t;

extern DataObject    iedModel_PROT_PTOF1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTOF1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTOF1_Str;
extern DataAttribute iedModel_PROT_PTOF1_Str_general;
extern DataAttribute iedModel_PROT_PTOF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF1_Str_q;
extern DataAttribute iedModel_PROT_PTOF1_Str_t;

extern DataObject    iedModel_PROT_PTOF1_Op;
extern DataAttribute iedModel_PROT_PTOF1_Op_general;
extern DataAttribute iedModel_PROT_PTOF1_Op_q;
extern DataAttribute iedModel_PROT_PTOF1_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF2;

extern DataObject    iedModel_PROT_PTOF2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTOF2_Mod_q;
extern DataAttribute iedModel_PROT_PTOF2_Mod_t;
extern DataAttribute iedModel_PROT_PTOF2_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTOF2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTOF2_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Beh_q;
extern DataAttribute iedModel_PROT_PTOF2_Beh_t;

extern DataObject    iedModel_PROT_PTOF2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTOF2_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF2_Health_q;
extern DataAttribute iedModel_PROT_PTOF2_Health_t;

extern DataObject    iedModel_PROT_PTOF2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTOF2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTOF2_Str;
extern DataAttribute iedModel_PROT_PTOF2_Str_general;
extern DataAttribute iedModel_PROT_PTOF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF2_Str_q;
extern DataAttribute iedModel_PROT_PTOF2_Str_t;

extern DataObject    iedModel_PROT_PTOF2_Op;
extern DataAttribute iedModel_PROT_PTOF2_Op_general;
extern DataAttribute iedModel_PROT_PTOF2_Op_q;
extern DataAttribute iedModel_PROT_PTOF2_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF1;

extern DataObject    iedModel_PROT_PTUF1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTUF1_Mod_q;
extern DataAttribute iedModel_PROT_PTUF1_Mod_t;
extern DataAttribute iedModel_PROT_PTUF1_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTUF1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTUF1_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Beh_q;
extern DataAttribute iedModel_PROT_PTUF1_Beh_t;

extern DataObject    iedModel_PROT_PTUF1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTUF1_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF1_Health_q;
extern DataAttribute iedModel_PROT_PTUF1_Health_t;

extern DataObject    iedModel_PROT_PTUF1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTUF1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTUF1_Str;
extern DataAttribute iedModel_PROT_PTUF1_Str_general;
extern DataAttribute iedModel_PROT_PTUF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF1_Str_q;
extern DataAttribute iedModel_PROT_PTUF1_Str_t;

extern DataObject    iedModel_PROT_PTUF1_Op;
extern DataAttribute iedModel_PROT_PTUF1_Op_general;
extern DataAttribute iedModel_PROT_PTUF1_Op_q;
extern DataAttribute iedModel_PROT_PTUF1_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF2;

extern DataObject    iedModel_PROT_PTUF2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTUF2_Mod_q;
extern DataAttribute iedModel_PROT_PTUF2_Mod_t;
extern DataAttribute iedModel_PROT_PTUF2_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTUF2_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTUF2_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Beh_q;
extern DataAttribute iedModel_PROT_PTUF2_Beh_t;

extern DataObject    iedModel_PROT_PTUF2_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTUF2_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF2_Health_q;
extern DataAttribute iedModel_PROT_PTUF2_Health_t;

extern DataObject    iedModel_PROT_PTUF2_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTUF2_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTUF2_Str;
extern DataAttribute iedModel_PROT_PTUF2_Str_general;
extern DataAttribute iedModel_PROT_PTUF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF2_Str_q;
extern DataAttribute iedModel_PROT_PTUF2_Str_t;

extern DataObject    iedModel_PROT_PTUF2_Op;
extern DataAttribute iedModel_PROT_PTUF2_Op_general;
extern DataAttribute iedModel_PROT_PTUF2_Op_q;
extern DataAttribute iedModel_PROT_PTUF2_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_LZSHPTOC;

extern DataObject    iedModel_PROT_LZSHPTOC_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_t;
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_stVal;
extern DataAttribute iedModel_PROT_LZSHPTOC_Mod_ctlModel;

extern DataObject    iedModel_PROT_LZSHPTOC_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_stVal;
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Beh_t;

extern DataObject    iedModel_PROT_LZSHPTOC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_stVal;
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Health_t;

extern DataObject    iedModel_PROT_LZSHPTOC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_LZSHPTOC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_LZSHPTOC_Str;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_general;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_dirGeneral;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Str_t;

extern DataObject    iedModel_PROT_LZSHPTOC_Op;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_general;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_q;
extern DataAttribute iedModel_PROT_LZSHPTOC_Op_t;


/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_RREC;

extern DataObject    iedModel_PROT_RREC_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_RREC_Mod_q;
extern DataAttribute iedModel_PROT_RREC_Mod_t;
extern DataAttribute iedModel_PROT_RREC_Mod_stVal;
extern DataAttribute iedModel_PROT_RREC_Mod_ctlModel;

extern DataObject    iedModel_PROT_RREC_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_RREC_Beh_stVal;
extern DataAttribute iedModel_PROT_RREC_Beh_q;
extern DataAttribute iedModel_PROT_RREC_Beh_t;

extern DataObject    iedModel_PROT_RREC_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_RREC_Health_stVal;
extern DataAttribute iedModel_PROT_RREC_Health_q;
extern DataAttribute iedModel_PROT_RREC_Health_t;

extern DataObject    iedModel_PROT_RREC_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_RREC_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_RREC_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_RREC_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject 	  iedModel_PROT_RREC_AutoRecSt;
extern DataAttribute iedModel_PROT_RREC_AutoRecSt_stVal;

extern DataObject    iedModel_PROT_RREC_Op;
extern DataAttribute iedModel_PROT_RREC_Op_general;
extern DataAttribute iedModel_PROT_RREC_Op_q;
extern DataAttribute iedModel_PROT_RREC_Op_t;

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_RBRF;

extern DataObject    iedModel_PROT_RBRF_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_RBRF_Mod_q;
extern DataAttribute iedModel_PROT_RBRF_Mod_t;
extern DataAttribute iedModel_PROT_RBRF_Mod_stVal;
extern DataAttribute iedModel_PROT_RBRF_Mod_ctlModel;

extern DataObject    iedModel_PROT_RBRF_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_RBRF_Beh_stVal;
extern DataAttribute iedModel_PROT_RBRF_Beh_q;
extern DataAttribute iedModel_PROT_RBRF_Beh_t;

extern DataObject    iedModel_PROT_RBRF_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_RBRF_Health_stVal;
extern DataAttribute iedModel_PROT_RBRF_Health_q;
extern DataAttribute iedModel_PROT_RBRF_Health_t;

extern DataObject    iedModel_PROT_RBRF_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_RBRF_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_RBRF_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_RBRF_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_RBRF_OpEx;
extern DataAttribute iedModel_PROT_RBRF_OpEx_general;
extern DataAttribute iedModel_PROT_RBRF_OpEx_q;
extern DataAttribute iedModel_PROT_RBRF_OpEx_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_AVRGGIO;

extern DataObject iedModel_PROT_AVRGGIO_Mod;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_t;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Mod_ctlModel;


extern DataObject iedModel_PROT_AVRGGIO_Beh;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Beh_t;

extern DataObject iedModel_PROT_AVRGGIO_Health;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Health_t;

extern DataObject iedModel_PROT_AVRGGIO_NamPlt;

extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_vendor;
extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_swRev;
extern DataAttribute iedModel_PROT_AVRGGIO_NamPlt_d;

extern DataObject iedModel_PROT_AVRGGIO_IntIn;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_q;
extern DataAttribute iedModel_PROT_AVRGGIO_IntIn_t;

/*
extern DataObject iedModel_PROT_AVRGGIO_Ind1;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind1_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind1_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind1_t;

extern DataObject iedModel_PROT_AVRGGIO_Ind2;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind2_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind2_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind2_t;

extern DataObject iedModel_PROT_AVRGGIO_Ind3;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind3_stVal;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind3_q;
extern DataAttribute iedModel_PROT_AVRGGIO_Ind3_t;
*/

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO1;

extern DataObject iedModel_PROT_VZGGIO1_Mod;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO1_Beh;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Beh_t;

extern DataObject iedModel_PROT_VZGGIO1_Health;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Health_t;

extern DataObject iedModel_PROT_VZGGIO1_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO1_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO1_Alm;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO1_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO2;

extern DataObject iedModel_PROT_VZGGIO2_Mod;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO2_Beh;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Beh_t;

extern DataObject iedModel_PROT_VZGGIO2_Health;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Health_t;

extern DataObject iedModel_PROT_VZGGIO2_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO2_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO2_Alm;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO2_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO3;

extern DataObject iedModel_PROT_VZGGIO3_Mod;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO3_Beh;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Beh_t;

extern DataObject iedModel_PROT_VZGGIO3_Health;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Health_t;

extern DataObject iedModel_PROT_VZGGIO3_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO3_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO3_Alm;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO3_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO4;

extern DataObject iedModel_PROT_VZGGIO4_Mod;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO4_Beh;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Beh_t;

extern DataObject iedModel_PROT_VZGGIO4_Health;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Health_t;

extern DataObject iedModel_PROT_VZGGIO4_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO4_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO4_Alm;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO4_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO5;

extern DataObject iedModel_PROT_VZGGIO5_Mod;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO5_Beh;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Beh_t;

extern DataObject iedModel_PROT_VZGGIO5_Health;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Health_t;

extern DataObject iedModel_PROT_VZGGIO5_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO5_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO5_Alm;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO5_Alm_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO6;

extern DataObject iedModel_PROT_VZGGIO6_Mod;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO6_Beh;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Beh_t;

extern DataObject iedModel_PROT_VZGGIO6_Health;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Health_t;

extern DataObject iedModel_PROT_VZGGIO6_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO6_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO6_Alm;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO6_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO7;

extern DataObject iedModel_PROT_VZGGIO7_Mod;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO7_Beh;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Beh_t;

extern DataObject iedModel_PROT_VZGGIO7_Health;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Health_t;

extern DataObject iedModel_PROT_VZGGIO7_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO7_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO7_Alm;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO7_Alm_t;


//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO8;

extern DataObject iedModel_PROT_VZGGIO8_Mod;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO8_Beh;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Beh_t;

extern DataObject iedModel_PROT_VZGGIO8_Health;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Health_t;

extern DataObject iedModel_PROT_VZGGIO8_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO8_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO8_Alm;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO8_Alm_t;

// -----------------------------------------------------------------------------
// LN CSWI
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_CSWI1;

// Mod																// обязательные элементы -------------------------------------
extern DataObject    iedModel_CTRL_CSWI1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_CTRL_CSWI1_Mod_q;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_t;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_ctlModel;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_T;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Test;
extern DataAttribute iedModel_CTRL_CSWI1_Mod_Oper_Check;

// Beh
extern DataObject    iedModel_CTRL_CSWI1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_CTRL_CSWI1_Beh_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Beh_q;
extern DataAttribute iedModel_CTRL_CSWI1_Beh_t;

// Health
extern DataObject    iedModel_CTRL_CSWI1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_CTRL_CSWI1_Health_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Health_q;
extern DataAttribute iedModel_CTRL_CSWI1_Health_t;

// NamPlt
extern DataObject    iedModel_CTRL_CSWI1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN CSWI1.

extern DataObject iedModel_CTRL_CSWI1_Pos;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_stVal;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_q;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_t;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_ctlModel;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_T;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Test;
extern DataAttribute iedModel_CTRL_CSWI1_Pos_Oper_Check;
// -----------------------------------------------------------------------------
// LN XCBR1
// -----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_XCBR1;
extern DataObject iedModel_CTRL_XCBR1_Mod;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_q;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_t;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_Mod_Oper_Check;

extern DataObject iedModel_CTRL_XCBR1_Beh;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_q;
extern DataAttribute iedModel_CTRL_XCBR1_Beh_t;

extern DataObject iedModel_CTRL_XCBR1_Health;
extern DataAttribute iedModel_CTRL_XCBR1_Health_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Health_q;
extern DataAttribute iedModel_CTRL_XCBR1_Health_t;

extern DataObject iedModel_CTRL_XCBR1_NamPlt;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_XCBR1_NamPlt_d;

extern DataObject iedModel_CTRL_XCBR1_Pos;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_q;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_t;
extern DataAttribute iedModel_CTRL_XCBR1_Pos_ctlModel;

extern DataObject iedModel_CTRL_XCBR1_Loc;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_q;
extern DataAttribute iedModel_CTRL_XCBR1_Loc_t;

extern DataObject iedModel_CTRL_XCBR1_OpCnt;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_q;
extern DataAttribute iedModel_CTRL_XCBR1_OpCnt_t;

extern DataObject iedModel_CTRL_XCBR1_CBOpCap;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_q;
extern DataAttribute iedModel_CTRL_XCBR1_CBOpCap_t;

extern DataObject iedModel_CTRL_XCBR1_BlkOpn;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_q;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_t;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_BlkOpn_Oper_Check;


extern DataObject iedModel_CTRL_XCBR1_BlkCls;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_stVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_q;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_t;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_ctlModel;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper;

//-PTRC --------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_PTRC;

extern DataObject iedModel_CTRL_PTRC_Mod;
extern DataAttribute iedModel_CTRL_PTRC_Mod_q;
extern DataAttribute iedModel_CTRL_PTRC_Mod_t;
extern DataAttribute iedModel_CTRL_PTRC_Mod_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Mod_ctlModel;

extern DataObject iedModel_CTRL_PTRC_Beh;
extern DataAttribute iedModel_CTRL_PTRC_Beh_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Beh_q;
extern DataAttribute iedModel_CTRL_PTRC_Beh_t;

extern DataObject iedModel_CTRL_PTRC_Health;
extern DataAttribute iedModel_CTRL_PTRC_Health_stVal;
extern DataAttribute iedModel_CTRL_PTRC_Health_q;
extern DataAttribute iedModel_CTRL_PTRC_Health_t;

extern DataObject iedModel_CTRL_PTRC_NamPlt;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_PTRC_NamPlt_d;

extern DataObject iedModel_CTRL_PTRC_Op;
extern DataAttribute iedModel_CTRL_PTRC_Op_general;
extern DataAttribute iedModel_CTRL_PTRC_Op_q;
extern DataAttribute iedModel_CTRL_PTRC_Op_t;

//----------------------------------------------------------------------------
// GGIO1
//----------------------------------------------------------------------------
extern LogicalNode iedModel_CTRL_GGIO1;

extern DataObject iedModel_CTRL_GGIO1_Mod;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_q;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_t;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Mod_ctlModel;

extern DataObject iedModel_CTRL_GGIO1_Beh;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_q;
extern DataAttribute iedModel_CTRL_GGIO1_Beh_t;

extern DataObject iedModel_CTRL_GGIO1_Health;
extern DataAttribute iedModel_CTRL_GGIO1_Health_stVal;
extern DataAttribute iedModel_CTRL_GGIO1_Health_q;
extern DataAttribute iedModel_CTRL_GGIO1_Health_t;

extern DataObject iedModel_CTRL_GGIO1_NamPlt;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_vendor;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_swRev;
extern DataAttribute iedModel_CTRL_GGIO1_NamPlt_d;

//SPCSO1
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

//SPCSO4
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
//****************************************************************************
// LN PDIF1
// -----------------------------------------------------------------------------
extern LogicalNode iedModel_GenericIO_PDIF1;
extern DataObject iedModel_GenericIO_PDIF1_Mod;
extern DataAttribute iedModel_GenericIO_PDIF1_Mod_q;
extern DataAttribute iedModel_GenericIO_PDIF1_Mod_t;
extern DataAttribute iedModel_GenericIO_PDIF1_Mod_stVal;
extern DataAttribute iedModel_GenericIO_PDIF1_Mod_ctlModel;

extern DataObject iedModel_GenericIO_PDIF1_Beh;
extern DataAttribute iedModel_GenericIO_PDIF1_Beh_stVal;
extern DataAttribute iedModel_GenericIO_PDIF1_Beh_q;
extern DataAttribute iedModel_GenericIO_PDIF1_Beh_t;

extern DataObject iedModel_GenericIO_PDIF1_Health;
extern DataAttribute iedModel_GenericIO_PDIF1_Health_stVal;
extern DataAttribute iedModel_GenericIO_PDIF1_Health_q;
extern DataAttribute iedModel_GenericIO_PDIF1_Health_t;

extern DataObject iedModel_GenericIO_PDIF1_NamPlt;
extern DataAttribute iedModel_GenericIO_PDIF1_NamPlt_vendor;
extern DataAttribute iedModel_GenericIO_PDIF1_NamPlt_swRev;
extern DataAttribute iedModel_GenericIO_PDIF1_NamPlt_d;

extern DataObject iedModel_GenericIO_PDIF1_Op;
extern DataAttribute iedModel_GenericIO_PDIF1_Op_general;
extern DataAttribute iedModel_GenericIO_PDIF1_Op_q;
extern DataAttribute iedModel_GenericIO_PDIF1_Op_t;

extern DataObject iedModel_GenericIO_PDIF1_DifACIc;
extern DataObject iedModel_GenericIO_PDIF1_DifACIc_phsA;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_q;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_t;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_db;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsA_zeroDb;

extern DataObject iedModel_GenericIO_PDIF1_DifACIc_phsB;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_q;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_t;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_db;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsB_zeroDb;

extern DataObject iedModel_GenericIO_PDIF1_DifACIc_phsC;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_q;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_t;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_db;
extern DataAttribute iedModel_GenericIO_PDIF1_DifACIc_phsC_zeroDb;

extern DataObject iedModel_GenericIO_PDIF1_RstA;
extern DataObject iedModel_GenericIO_PDIF1_RstA_phsA;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_q;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_t;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_db;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsA_zeroDb;

extern DataObject iedModel_GenericIO_PDIF1_RstA_phsB;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_q;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_t;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_db;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsB_zeroDb;

extern DataObject iedModel_GenericIO_PDIF1_RstA_phsC;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_cVal_mag_f;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_q;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_t;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_db;
extern DataAttribute iedModel_GenericIO_PDIF1_RstA_phsC_zeroDb;

// -----------------------------------------------------------

#define IEDMODEL_Generic_LD0 (&iedModel_Generic_LD0)
#define IEDMODEL_Generic_PROT (&iedModel_Generic_PROT)
#define IEDMODEL_Generic_CTRL (&iedModel_Generic_CTRL)
#define IEDMODEL_Generic_MES (&iedModel_Generic_MES)
#define IEDMODEL_Generic_GGIO (&iedModel_Generic_GGIO)


#define IEDMODEL_PROT_LLN0 (&iedModel_PROT_LLN0)
#define IEDMODEL_PROT_LLN0_Mod (&iedModel_PROT_LLN0_Mod)
#define IEDMODEL_PROT_LLN0_Mod_q (&iedModel_PROT_LLN0_Mod_q)
#define IEDMODEL_PROT_LLN0_Mod_t (&iedModel_PROT_LLN0_Mod_t)
#define IEDMODEL_PROT_LLN0_Mod_ctlModel (&iedModel_PROT_LLN0_Mod_ctlModel)
#define IEDMODEL_PROT_LLN0_Beh (&iedModel_PROT_LLN0_Beh)
#define IEDMODEL_PROT_LLN0_Beh_stVal (&iedModel_PROT_LLN0_Beh_stVal)
#define IEDMODEL_PROT_LLN0_Beh_q (&iedModel_PROT_LLN0_Beh_q)
#define IEDMODEL_PROT_LLN0_Beh_t (&iedModel_PROT_LLN0_Beh_t)
#define IEDMODEL_PROT_LLN0_Health (&iedModel_PROT_LLN0_Health)
#define IEDMODEL_PROT_LLN0_Health_stVal (&iedModel_PROT_LLN0_Health_stVal)
#define IEDMODEL_PROT_LLN0_Health_q (&iedModel_PROT_LLN0_Health_q)
#define IEDMODEL_PROT_LLN0_Health_t (&iedModel_PROT_LLN0_Health_t)
#define IEDMODEL_PROT_LLN0_NamPlt (&iedModel_PROT_LLN0_NamPlt)
#define IEDMODEL_PROT_LLN0_NamPlt_vendor (&iedModel_PROT_LLN0_NamPlt_vendor)
#define IEDMODEL_PROT_LLN0_NamPlt_swRev (&iedModel_PROT_LLN0_NamPlt_swRev)
#define IEDMODEL_PROT_LLN0_NamPlt_d (&iedModel_PROT_LLN0_NamPlt_d)
#define IEDMODEL_PROT_LLN0_NamPlt_configRev (&iedModel_PROT_LLN0_NamPlt_configRev)
#define IEDMODEL_PROT_LLN0_NamPlt_ldNs (&iedModel_PROT_LLN0_NamPlt_ldNs)

#define IEDMODEL_PROT_LPHD1 (&iedModel_PROT_LPHD1)
#define IEDMODEL_PROT_LPHD1_PhyNam (&iedModel_PROT_LPHD1_PhyNam)
#define IEDMODEL_PROT_LPHD1_PhyNam_vendor (&iedModel_PROT_LPHD1_PhyNam_vendor)
#define IEDMODEL_PROT_LPHD1_PhyHealth (&iedModel_PROT_LPHD1_PhyHealth)
#define IEDMODEL_PROT_LPHD1_PhyHealth_stVal (&iedModel_PROT_LPHD1_PhyHealth_stVal)
#define IEDMODEL_PROT_LPHD1_PhyHealth_q (&iedModel_PROT_LPHD1_PhyHealth_q)
#define IEDMODEL_PROT_LPHD1_PhyHealth_t (&iedModel_PROT_LPHD1_PhyHealth_t)
#define IEDMODEL_PROT_LPHD1_Proxy (&iedModel_PROT_LPHD1_Proxy)
#define IEDMODEL_PROT_LPHD1_Proxy_stVal (&iedModel_PROT_LPHD1_Proxy_stVal)
#define IEDMODEL_PROT_LPHD1_Proxy_q (&iedModel_PROT_LPHD1_Proxy_q)
#define IEDMODEL_PROT_LPHD1_Proxy_t (&iedModel_PROT_LPHD1_Proxy_t)

#define IEDMODEL_GGIO_OUTGGIO1 (&iedModel_GGIO_OUTGGIO1)
#define IEDMODEL_GGIO_OUTGGIO1_Mod (&iedModel_GGIO_OUTGGIO1_Mod)
#define IEDMODEL_GGIO_OUTGGIO1_Mod_q (&iedModel_GGIO_OUTGGIO1_Mod_q)
#define IEDMODEL_GGIO_OUTGGIO1_Mod_t (&iedModel_GGIO_OUTGGIO1_Mod_t)
#define IEDMODEL_GGIO_OUTGGIO1_Mod_ctlModel (&iedModel_GGIO_OUTGGIO1_Mod_ctlModel)
#define IEDMODEL_GGIO_OUTGGIO1_Beh (&iedModel_GGIO_OUTGGIO1_Beh)
#define IEDMODEL_GGIO_OUTGGIO1_Beh_stVal (&iedModel_GGIO_OUTGGIO1_Beh_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Beh_q (&iedModel_GGIO_OUTGGIO1_Beh_q)
#define IEDMODEL_GGIO_OUTGGIO1_Beh_t (&iedModel_GGIO_OUTGGIO1_Beh_t)
#define IEDMODEL_GGIO_OUTGGIO1_Health (&iedModel_GGIO_OUTGGIO1_Health)
#define IEDMODEL_GGIO_OUTGGIO1_Health_stVal (&iedModel_GGIO_OUTGGIO1_Health_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Health_q (&iedModel_GGIO_OUTGGIO1_Health_q)
#define IEDMODEL_GGIO_OUTGGIO1_Health_t (&iedModel_GGIO_OUTGGIO1_Health_t)
#define IEDMODEL_GGIO_OUTGGIO1_NamPlt (&iedModel_GGIO_OUTGGIO1_NamPlt)
#define IEDMODEL_GGIO_OUTGGIO1_NamPlt_vendor (&iedModel_GGIO_OUTGGIO1_NamPlt_vendor)
#define IEDMODEL_GGIO_OUTGGIO1_NamPlt_swRev (&iedModel_GGIO_OUTGGIO1_NamPlt_swRev)
#define IEDMODEL_GGIO_OUTGGIO1_NamPlt_d (&iedModel_GGIO_OUTGGIO1_NamPlt_d)

#define IEDMODEL_GGIO_OUTGGIO1_AnIn1 (&iedModel_GGIO_OUTGGIO1_AnIn1)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn1_mag (&iedModel_GGIO_OUTGGIO1_AnIn1_mag)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn1_mag_f (&iedModel_GGIO_OUTGGIO1_AnIn1_mag_f)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn1_q (&iedModel_GGIO_OUTGGIO1_AnIn1_q)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn1_t (&iedModel_GGIO_OUTGGIO1_AnIn1_t)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn2 (&iedModel_GGIO_OUTGGIO1_AnIn2)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn2_mag (&iedModel_GGIO_OUTGGIO1_AnIn2_mag)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn2_mag_f (&iedModel_GGIO_OUTGGIO1_AnIn2_mag_f)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn2_q (&iedModel_GGIO_OUTGGIO1_AnIn2_q)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn2_t (&iedModel_GGIO_OUTGGIO1_AnIn2_t)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn3 (&iedModel_GGIO_OUTGGIO1_AnIn3)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn3_mag (&iedModel_GGIO_OUTGGIO1_AnIn3_mag)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn3_mag_f (&iedModel_GGIO_OUTGGIO1_AnIn3_mag_f)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn3_q (&iedModel_GGIO_OUTGGIO1_AnIn3_q)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn3_t (&iedModel_GGIO_OUTGGIO1_AnIn3_t)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn4 (&iedModel_GGIO_OUTGGIO1_AnIn4)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn4_mag (&iedModel_GGIO_OUTGGIO1_AnIn4_mag)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn4_mag_f (&iedModel_GGIO_OUTGGIO1_AnIn4_mag_f)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn4_q (&iedModel_GGIO_OUTGGIO1_AnIn4_q)
#define IEDMODEL_GGIO_OUTGGIO1_AnIn4_t (&iedModel_GGIO_OUTGGIO1_AnIn4_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1 (&iedModel_GGIO_OUTGGIO1_SPCSO1)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_q (&iedModel_GGIO_OUTGGIO1_SPCSO1_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_ctlVal (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_ctlVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_origin (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orCat (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orCat)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orIdent (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_origin_orIdent)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_ctlNum (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_ctlNum)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_T (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_T)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_Test (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_Test)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_Oper_Check (&iedModel_GGIO_OUTGGIO1_SPCSO1_Oper_Check)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_ctlModel (&iedModel_GGIO_OUTGGIO1_SPCSO1_ctlModel)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO1_t (&iedModel_GGIO_OUTGGIO1_SPCSO1_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2 (&iedModel_GGIO_OUTGGIO1_SPCSO2)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_q (&iedModel_GGIO_OUTGGIO1_SPCSO2_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_ctlVal (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_ctlVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_origin (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_origin)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_origin_orCat (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_origin_orCat)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_origin_orIdent (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_origin_orIdent)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_ctlNum (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_ctlNum)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_T (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_T)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_Test (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_Test)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_Oper_Check (&iedModel_GGIO_OUTGGIO1_SPCSO2_Oper_Check)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_ctlModel (&iedModel_GGIO_OUTGGIO1_SPCSO2_ctlModel)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO2_t (&iedModel_GGIO_OUTGGIO1_SPCSO2_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3 (&iedModel_GGIO_OUTGGIO1_SPCSO3)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_q (&iedModel_GGIO_OUTGGIO1_SPCSO3_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_ctlVal (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_ctlVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_origin (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_origin)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_origin_orCat (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_origin_orCat)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_origin_orIdent (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_origin_orIdent)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_ctlNum (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_ctlNum)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_T (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_T)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_Test (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_Test)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_Oper_Check (&iedModel_GGIO_OUTGGIO1_SPCSO3_Oper_Check)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_ctlModel (&iedModel_GGIO_OUTGGIO1_SPCSO3_ctlModel)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO3_t (&iedModel_GGIO_OUTGGIO1_SPCSO3_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4 (&iedModel_GGIO_OUTGGIO1_SPCSO4)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_q (&iedModel_GGIO_OUTGGIO1_SPCSO4_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_ctlVal (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_ctlVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_origin (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_origin)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_origin_orCat (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_origin_orCat)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_origin_orIdent (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_origin_orIdent)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_ctlNum (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_ctlNum)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_T (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_T)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_Test (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_Test)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_Oper_Check (&iedModel_GGIO_OUTGGIO1_SPCSO4_Oper_Check)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_ctlModel (&iedModel_GGIO_OUTGGIO1_SPCSO4_ctlModel)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO4_t (&iedModel_GGIO_OUTGGIO1_SPCSO4_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO5 (&iedModel_GGIO_OUTGGIO1_SPCSO5)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO5_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO5_q (&iedModel_GGIO_OUTGGIO1_SPCSO5_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO5_t (&iedModel_GGIO_OUTGGIO1_SPCSO5_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO6 (&iedModel_GGIO_OUTGGIO1_SPCSO6)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO6_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO6_q (&iedModel_GGIO_OUTGGIO1_SPCSO6_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO6_t (&iedModel_GGIO_OUTGGIO1_SPCSO6_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO7 (&iedModel_GGIO_OUTGGIO1_SPCSO7)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO7_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO7_q (&iedModel_GGIO_OUTGGIO1_SPCSO7_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO7_t (&iedModel_GGIO_OUTGGIO1_SPCSO7_t)

#define IEDMODEL_GGIO_OUTGGIO1_SPCSO8 (&iedModel_GGIO_OUTGGIO1_SPCSO8)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO8_stVal (&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO8_q (&iedModel_GGIO_OUTGGIO1_SPCSO8_q)
#define IEDMODEL_GGIO_OUTGGIO1_SPCSO8_t (&iedModel_GGIO_OUTGGIO1_SPCSO8_t)

//-- GGIO2_SPCSO1
#define IEDMODEL_GGIO_INGGIO1_SPCSO1 (&iedModel_GGIO_INGGIO1_SPCSO1)
#define IEDMODEL_GGIO_INGGIO1_SPCSO1_stVal (&iedModel_GGIO_INGGIO1_SPCSO1_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO1_q (&iedModel_GGIO_INGGIO1_SPCSO1_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO1_t (&iedModel_GGIO_INGGIO1_SPCSO1_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO1_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO1_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO2 (&iedModel_GGIO_INGGIO1_SPCSO2)
#define IEDMODEL_GGIO_INGGIO1_SPCSO2_stVal (&iedModel_GGIO_INGGIO1_SPCSO2_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO2_q (&iedModel_GGIO_INGGIO1_SPCSO2_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO2_t (&iedModel_GGIO_INGGIO1_SPCSO2_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO2_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO2_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO3 (&iedModel_GGIO_INGGIO1_SPCSO3)
#define IEDMODEL_GGIO_INGGIO1_SPCSO3_stVal (&iedModel_GGIO_INGGIO1_SPCSO3_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO3_q (&iedModel_GGIO_INGGIO1_SPCSO3_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO3_t (&iedModel_GGIO_INGGIO1_SPCSO3_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO3_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO3_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO4 (&iedModel_GGIO_INGGIO1_SPCSO4)
#define IEDMODEL_GGIO_INGGIO1_SPCSO4_stVal (&iedModel_GGIO_INGGIO1_SPCSO4_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO4_q (&iedModel_GGIO_INGGIO1_SPCSO4_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO4_t (&iedModel_GGIO_INGGIO1_SPCSO4_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO4_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO4_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO5_stVal (&iedModel_GGIO_INGGIO1_SPCSO5_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO5_q (&iedModel_GGIO_INGGIO1_SPCSO5_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO5_t (&iedModel_GGIO_INGGIO1_SPCSO5_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO5_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO5_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO6_stVal (&iedModel_GGIO_INGGIO1_SPCSO6_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO6_q (&iedModel_GGIO_INGGIO1_SPCSO6_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO6_t (&iedModel_GGIO_INGGIO1_SPCSO6_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO6_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO6_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO7_stVal (&iedModel_GGIO_INGGIO1_SPCSO7_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO7_q (&iedModel_GGIO_INGGIO1_SPCSO7_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO7_t (&iedModel_GGIO_INGGIO1_SPCSO7_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO7_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO7_Oper_ctlVal)

#define IEDMODEL_GGIO_INGGIO1_SPCSO8_stVal (&iedModel_GGIO_INGGIO1_SPCSO8_stVal)
#define IEDMODEL_GGIO_INGGIO1_SPCSO8_q (&iedModel_GGIO_INGGIO1_SPCSO8_q)
#define IEDMODEL_GGIO_INGGIO1_SPCSO8_t (&iedModel_GGIO_INGGIO1_SPCSO8_t)
#define IEDMODEL_GGIO_INGGIO1_SPCSO8_Oper_ctlVal (&iedModel_GGIO_INGGIO1_SPCSO8_Oper_ctlVal)

/***********************************************************************************************************
 *
 *
 *
 ***********************************************************************************************************/
#define IEDMODEL_GGIO_OUTGGIO1_Ind1 (&iedModel_GGIO_OUTGGIO1_Ind1)
#define IEDMODEL_GGIO_OUTGGIO1_Ind1_stVal (&iedModel_GGIO_OUTGGIO1_Ind1_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind1_q (&iedModel_GGIO_OUTGGIO1_Ind1_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind1_t (&iedModel_GGIO_OUTGGIO1_Ind1_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind2 (&iedModel_GGIO_OUTGGIO1_Ind2)
#define IEDMODEL_GGIO_OUTGGIO1_Ind2_stVal (&iedModel_GGIO_OUTGGIO1_Ind2_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind2_q (&iedModel_GGIO_OUTGGIO1_Ind2_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind2_t (&iedModel_GGIO_OUTGGIO1_Ind2_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind3 (&iedModel_GGIO_OUTGGIO1_Ind3)
#define IEDMODEL_GGIO_OUTGGIO1_Ind3_stVal (&iedModel_GGIO_OUTGGIO1_Ind3_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind3_q (&iedModel_GGIO_OUTGGIO1_Ind3_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind3_t (&iedModel_GGIO_OUTGGIO1_Ind3_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind4 (&iedModel_GGIO_OUTGGIO1_Ind4)
#define IEDMODEL_GGIO_OUTGGIO1_Ind4_stVal (&iedModel_GGIO_OUTGGIO1_Ind4_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind4_q (&iedModel_GGIO_OUTGGIO1_Ind4_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind4_t (&iedModel_GGIO_OUTGGIO1_Ind4_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind5 (&iedModel_GGIO_OUTGGIO1_Ind5)
#define IEDMODEL_GGIO_OUTGGIO1_Ind5_stVal (&iedModel_GGIO_OUTGGIO1_Ind5_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind5_q (&iedModel_GGIO_OUTGGIO1_Ind5_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind5_t (&iedModel_GGIO_OUTGGIO1_Ind5_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind6 (&iedModel_GGIO_OUTGGIO1_Ind6)
#define IEDMODEL_GGIO_OUTGGIO1_Ind6_stVal (&iedModel_GGIO_OUTGGIO1_Ind6_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind6_q (&iedModel_GGIO_OUTGGIO1_Ind6_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind6_t (&iedModel_GGIO_OUTGGIO1_Ind6_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind7 (&iedModel_GGIO_OUTGGIO1_Ind7)
#define IEDMODEL_GGIO_OUTGGIO1_Ind7_stVal (&iedModel_GGIO_OUTGGIO1_Ind7_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind7_q (&iedModel_GGIO_OUTGGIO1_Ind7_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind7_t (&iedModel_GGIO_OUTGGIO1_Ind7_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind8 (&iedModel_GGIO_OUTGGIO1_Ind8)
#define IEDMODEL_GGIO_OUTGGIO1_Ind8_stVal (&iedModel_GGIO_OUTGGIO1_Ind8_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind8_q (&iedModel_GGIO_OUTGGIO1_Ind8_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind8_t (&iedModel_GGIO_OUTGGIO1_Ind8_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind9 (&iedModel_GGIO_OUTGGIO1_Ind9)
#define IEDMODEL_GGIO_OUTGGIO1_Ind9_stVal (&iedModel_GGIO_OUTGGIO1_Ind9_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind9_q (&iedModel_GGIO_OUTGGIO1_Ind9_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind9_t (&iedModel_GGIO_OUTGGIO1_Ind9_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind10 (&iedModel_GGIO_OUTGGIO1_Ind10)
#define IEDMODEL_GGIO_OUTGGIO1_Ind10_stVal (&iedModel_GGIO_OUTGGIO1_Ind10_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind10_q (&iedModel_GGIO_OUTGGIO1_Ind10_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind10_t (&iedModel_GGIO_OUTGGIO1_Ind10_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind11 (&iedModel_GGIO_OUTGGIO1_Ind11)
#define IEDMODEL_GGIO_OUTGGIO1_Ind11_stVal (&iedModel_GGIO_OUTGGIO1_Ind11_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind11_q (&iedModel_GGIO_OUTGGIO1_Ind11_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind11_t (&iedModel_GGIO_OUTGGIO1_Ind11_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind12 (&iedModel_GGIO_OUTGGIO1_Ind12)
#define IEDMODEL_GGIO_OUTGGIO1_Ind12_stVal (&iedModel_GGIO_OUTGGIO1_Ind12_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind12_q (&iedModel_GGIO_OUTGGIO1_Ind12_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind12_t (&iedModel_GGIO_OUTGGIO1_Ind12_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind13 (&iedModel_GGIO_OUTGGIO1_Ind13)
#define IEDMODEL_GGIO_OUTGGIO1_Ind13_stVal (&iedModel_GGIO_OUTGGIO1_Ind13_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind13_q (&iedModel_GGIO_OUTGGIO1_Ind13_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind13_t (&iedModel_GGIO_OUTGGIO1_Ind13_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind14 (&iedModel_GGIO_OUTGGIO1_Ind14)
#define IEDMODEL_GGIO_OUTGGIO1_Ind14_stVal (&iedModel_GGIO_OUTGGIO1_Ind14_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind14_q (&iedModel_GGIO_OUTGGIO1_Ind14_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind14_t (&iedModel_GGIO_OUTGGIO1_Ind14_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind15 (&iedModel_GGIO_OUTGGIO1_Ind15)
#define IEDMODEL_GGIO_OUTGGIO1_Ind15_stVal (&iedModel_GGIO_OUTGGIO1_Ind15_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind15_q (&iedModel_GGIO_OUTGGIO1_Ind15_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind15_t (&iedModel_GGIO_OUTGGIO1_Ind15_t)

#define IEDMODEL_GGIO_OUTGGIO1_Ind16 (&iedModel_GGIO_OUTGGIO1_Ind16)
#define IEDMODEL_GGIO_OUTGGIO1_Ind16_stVal (&iedModel_GGIO_OUTGGIO1_Ind16_stVal)
#define IEDMODEL_GGIO_OUTGGIO1_Ind16_q (&iedModel_GGIO_OUTGGIO1_Ind16_q)
#define IEDMODEL_GGIO_OUTGGIO1_Ind16_t (&iedModel_GGIO_OUTGGIO1_Ind16_t)

/***********************************************************************************************************
 *
 *
 *
 ***********************************************************************************************************/
#define IEDMODEL_GGIO_LEDGGIO1 (&iedModel_GGIO_LEDGGIO1)
#define IEDMODEL_GGIO_LEDGGIO1_Mod (&iedModel_GGIO_LEDGGIO1_Mod)
#define IEDMODEL_GGIO_LEDGGIO1_Mod_q (&iedModel_GGIO_LEDGGIO1_Mod_q)
#define IEDMODEL_GGIO_LEDGGIO1_Mod_t (&iedModel_GGIO_LEDGGIO1_Mod_t)
#define IEDMODEL_GGIO_LEDGGIO1_Mod_ctlModel (&iedModel_GGIO_LEDGGIO1_Mod_ctlModel)
#define IEDMODEL_GGIO_LEDGGIO1_Beh (&iedModel_GGIO_LEDGGIO1_Beh)
#define IEDMODEL_GGIO_LEDGGIO1_Beh_stVal (&iedModel_GGIO_LEDGGIO1_Beh_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Beh_q (&iedModel_GGIO_LEDGGIO1_Beh_q)
#define IEDMODEL_GGIO_LEDGGIO1_Beh_t (&iedModel_GGIO_LEDGGIO1_Beh_t)
#define IEDMODEL_GGIO_LEDGGIO1_Health (&iedModel_GGIO_LEDGGIO1_Health)
#define IEDMODEL_GGIO_LEDGGIO1_Health_stVal (&iedModel_GGIO_LEDGGIO1_Health_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Health_q (&iedModel_GGIO_LEDGGIO1_Health_q)
#define IEDMODEL_GGIO_LEDGGIO1_Health_t (&iedModel_GGIO_LEDGGIO1_Health_t)
#define IEDMODEL_GGIO_LEDGGIO1_NamPlt (&iedModel_GGIO_LEDGGIO1_NamPlt)
#define IEDMODEL_GGIO_LEDGGIO1_NamPlt_vendor (&iedModel_GGIO_LEDGGIO1_NamPlt_vendor)
#define IEDMODEL_GGIO_LEDGGIO1_NamPlt_swRev (&iedModel_GGIO_LEDGGIO1_NamPlt_swRev)
#define IEDMODEL_GGIO_LEDGGIO1_NamPlt_d (&iedModel_GGIO_LEDGGIO1_NamPlt_d)

#define IEDMODEL_GGIO_LEDGGIO1_Ind1 (&iedModel_GGIO_LEDGGIO1_Ind1)
#define IEDMODEL_GGIO_LEDGGIO1_Ind1_stVal (&iedModel_GGIO_LEDGGIO1_Ind1_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind1_q (&iedModel_GGIO_LEDGGIO1_Ind1_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind1_t (&iedModel_GGIO_LEDGGIO1_Ind1_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind2 (&iedModel_GGIO_LEDGGIO1_Ind2)
#define IEDMODEL_GGIO_LEDGGIO1_Ind2_stVal (&iedModel_GGIO_LEDGGIO1_Ind2_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind2_q (&iedModel_GGIO_LEDGGIO1_Ind2_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind2_t (&iedModel_GGIO_LEDGGIO1_Ind2_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind3 (&iedModel_GGIO_LEDGGIO1_Ind3)
#define IEDMODEL_GGIO_LEDGGIO1_Ind3_stVal (&iedModel_GGIO_LEDGGIO1_Ind3_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind3_q (&iedModel_GGIO_LEDGGIO1_Ind3_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind3_t (&iedModel_GGIO_LEDGGIO1_Ind3_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind4 (&iedModel_GGIO_LEDGGIO1_Ind4)
#define IEDMODEL_GGIO_LEDGGIO1_Ind4_stVal (&iedModel_GGIO_LEDGGIO1_Ind4_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind4_q (&iedModel_GGIO_LEDGGIO1_Ind4_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind4_t (&iedModel_GGIO_LEDGGIO1_Ind4_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind5 (&iedModel_GGIO_LEDGGIO1_Ind5)
#define IEDMODEL_GGIO_LEDGGIO1_Ind5_stVal (&iedModel_GGIO_LEDGGIO1_Ind5_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind5_q (&iedModel_GGIO_LEDGGIO1_Ind5_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind5_t (&iedModel_GGIO_LEDGGIO1_Ind5_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind6 (&iedModel_GGIO_LEDGGIO1_Ind6)
#define IEDMODEL_GGIO_LEDGGIO1_Ind6_stVal (&iedModel_GGIO_LEDGGIO1_Ind6_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind6_q (&iedModel_GGIO_LEDGGIO1_Ind6_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind6_t (&iedModel_GGIO_LEDGGIO1_Ind6_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind7 (&iedModel_GGIO_LEDGGIO1_Ind7)
#define IEDMODEL_GGIO_LEDGGIO1_Ind7_stVal (&iedModel_GGIO_LEDGGIO1_Ind7_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind7_q (&iedModel_GGIO_LEDGGIO1_Ind7_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind7_t (&iedModel_GGIO_LEDGGIO1_Ind7_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind8 (&iedModel_GGIO_LEDGGIO1_Ind8)
#define IEDMODEL_GGIO_LEDGGIO1_Ind8_stVal (&iedModel_GGIO_LEDGGIO1_Ind8_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind8_q (&iedModel_GGIO_LEDGGIO1_Ind8_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind8_t (&iedModel_GGIO_LEDGGIO1_Ind8_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind9 (&iedModel_GGIO_LEDGGIO1_Ind9)
#define IEDMODEL_GGIO_LEDGGIO1_Ind9_stVal (&iedModel_GGIO_LEDGGIO1_Ind9_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind9_q (&iedModel_GGIO_LEDGGIO1_Ind9_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind9_t (&iedModel_GGIO_LEDGGIO1_Ind9_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind10 (&iedModel_GGIO_LEDGGIO1_Ind10)
#define IEDMODEL_GGIO_LEDGGIO1_Ind10_stVal (&iedModel_GGIO_LEDGGIO1_Ind10_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind10_q (&iedModel_GGIO_LEDGGIO1_Ind10_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind10_t (&iedModel_GGIO_LEDGGIO1_Ind10_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind11 (&iedModel_GGIO_LEDGGIO1_Ind11)
#define IEDMODEL_GGIO_LEDGGIO1_Ind11_stVal (&iedModel_GGIO_LEDGGIO1_Ind11_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind11_q (&iedModel_GGIO_LEDGGIO1_Ind11_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind11_t (&iedModel_GGIO_LEDGGIO1_Ind11_t)

#define IEDMODEL_GGIO_LEDGGIO1_Ind12 (&iedModel_GGIO_LEDGGIO1_Ind12)
#define IEDMODEL_GGIO_LEDGGIO1_Ind12_stVal (&iedModel_GGIO_LEDGGIO1_Ind12_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_Ind12_q (&iedModel_GGIO_LEDGGIO1_Ind12_q)
#define IEDMODEL_GGIO_LEDGGIO1_Ind12_t (&iedModel_GGIO_LEDGGIO1_Ind12_t)

/****************************************************************************************************
 * CTRL_GGIO    iedModel_CTRL_GGIO1_SPCSO1_Oper
 ****************************************************************************************************/
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1				(&iedModel_GGIO_LEDGGIO1_SPCSO1)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper 			(&iedModel_GGIO_LEDGGIO1_SPCSO1_Oper)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper_T		(&iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_T)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal	(&iedModel_GGIO_LEDGGIO1_SPCSO1_Oper_ctlVal)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_stVal			(&iedModel_GGIO_LEDGGIO1_SPCSO1_stVal)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_q				(&iedModel_GGIO_LEDGGIO1_SPCSO1_q)
#define IEDMODEL_GGIO_LEDGGIO1_SPCSO1_t				(&iedModel_GGIO_LEDGGIO1_SPCSO1_t)

/****************************************************************************************************
 *
 ****************************************************************************************************/
#define IEDMODEL_MES_MMXU1 (&iedModel_MES_MMXU1)
#define IEDMODEL_MES_MMXU1_Mod (&iedModel_MES_MMXU1_Mod)
#define IEDMODEL_MES_MMXU1_Mod_q (&iedModel_MES_MMXU1_Mod_q)
#define IEDMODEL_MES_MMXU1_Mod_t (&iedModel_MES_MMXU1_Mod_t)
#define IEDMODEL_MES_MMXU1_Mod_ctlModel (&iedModel_MES_MMXU1_Mod_ctlModel)

#define IEDMODEL_MES_MMXU1_Beh (&iedModel_MES_MMXU1_Beh)
#define IEDMODEL_MES_MMXU1_Beh_q (&iedModel_MES_MMXU1_Beh_q)
#define IEDMODEL_MES_MMXU1_Beh_t (&iedModel_MES_MMXU1_Beh_t)
#define IEDMODEL_MES_MMXU1_Beh_stVal (&iedModel_MES_MMXU1_Beh_stVal)

#define IEDMODEL_MES_MMXU1_Health (&iedModel_MES_MMXU1_Health)
#define IEDMODEL_MES_MMXU1_Health_q (&iedModel_MES_MMXU1_Health_q)
#define IEDMODEL_MES_MMXU1_Health_t (&iedModel_MES_MMXU1_Health_t)
#define IEDMODEL_MES_MMXU1_Health_stVal (&iedModel_MES_MMXU1_Health_stVal)

#define IEDMODEL_MES_MMXU1_NamPlt (&iedModel_MES_MMXU1_NamPlt)
#define IEDMODEL_MES_MMXU1_NamPlt_d (&iedModel_MES_MMXU1_NamPlt_d)
#define IEDMODEL_MES_MMXU1_NamPlt_swRev (&iedModel_MES_MMXU1_NamPlt_swRev)
#define IEDMODEL_MES_MMXU1_NamPlt_vendor (&iedModel_MES_MMXU1_NamPlt_vendor)

#define IEDMODEL_MES_MMXU1_A (&iedModel_MES_MMXU1_A)
#define IEDMODEL_MES_MMXU1_A_phsA (&iedModel_MES_MMXU1_A_phsA)
#define IEDMODEL_MES_MMXU1_A_phsA_cVal (&iedModel_MES_MMXU1_A_phsA_cVal)
#define IEDMODEL_MES_MMXU1_A_phsA_cVal_mag (&iedModel_MES_MMXU1_A_phsA_cVal_mag)
#define IEDMODEL_MES_MMXU1_A_phsA_cVal_mag_f (&iedModel_MES_MMXU1_A_phsA_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_A_phsA_q (&iedModel_MES_MMXU1_A_phsA_q)
#define IEDMODEL_MES_MMXU1_A_phsA_t (&iedModel_MES_MMXU1_A_phsA_t)

#define IEDMODEL_MES_MMXU1_A_phsB (&iedModel_MES_MMXU1_A_phsB)
#define IEDMODEL_MES_MMXU1_A_phsB_cVal (&iedModel_MES_MMXU1_A_phsB_cVal)
#define IEDMODEL_MES_MMXU1_A_phsB_cVal_mag (&iedModel_MES_MMXU1_A_phsB_cVal_mag)
#define IEDMODEL_MES_MMXU1_A_phsB_cVal_mag_f (&iedModel_MES_MMXU1_A_phsB_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_A_phsB_q (&iedModel_MES_MMXU1_A_phsB_q)
#define IEDMODEL_MES_MMXU1_A_phsB_t (&iedModel_MES_MMXU1_A_phsB_t)

#define IEDMODEL_MES_MMXU1_A_phsC (&iedModel_MES_MMXU1_A_phsC)
#define IEDMODEL_MES_MMXU1_A_phsC_cVal (&iedModel_MES_MMXU1_A_phsC_cVal)
#define IEDMODEL_MES_MMXU1_A_phsC_cVal_mag (&iedModel_MES_MMXU1_A_phsC_cVal_mag)
#define IEDMODEL_MES_MMXU1_A_phsC_cVal_mag_f (&iedModel_MES_MMXU1_A_phsC_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_A_phsC_q (&iedModel_MES_MMXU1_A_phsC_q)
#define IEDMODEL_MES_MMXU1_A_phsC_t (&iedModel_MES_MMXU1_A_phsC_t)

#define IEDMODEL_MES_MMXU1_A_neut (&iedModel_MES_MMXU1_A_neut)
#define IEDMODEL_MES_MMXU1_A_neut_cVal (&iedModel_MES_MMXU1_A_neut_cVal)
#define IEDMODEL_MES_MMXU1_A_neut_cVal_mag (&iedModel_MES_MMXU1_A_neut_cVal_mag)
#define IEDMODEL_MES_MMXU1_A_neut_cVal_mag_f (&iedModel_MES_MMXU1_A_neut_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_A_neut_q (&iedModel_MES_MMXU1_A_neut_q)
#define IEDMODEL_MES_MMXU1_A_neut_t (&iedModel_MES_MMXU1_A_neut_t)

#define IEDMODEL_MES_MMXU1_A1 (&iedModel_MES_MMXU1_A1)
#define IEDMODEL_MES_MMXU1_A1_phsA (&iedModel_MES_MMXU1_A1_phsA)
#define IEDMODEL_MES_MMXU1_A1_phsA_cVal (&iedModel_MES_MMXU1_A1_phsA_cVal)
#define IEDMODEL_MES_MMXU1_A1_phsA_cVal_mag (&iedModel_MES_MMXU1_A1_phsA_cVal_mag)
#define IEDMODEL_MES_MMXU1_A1_phsA_cVal_mag_i (&iedModel_MES_MMXU1_A1_phsA_cVal_mag_i)
#define IEDMODEL_MES_MMXU1_A1_phsA_q (&iedModel_MES_MMXU1_A1_phsA_q)
#define IEDMODEL_MES_MMXU1_A1_phsA_t (&iedModel_MES_MMXU1_A1_phsA_t)

#define IEDMODEL_MES_MMXU1_phV (&iedModel_MES_MMXU1_phV)
#define IEDMODEL_MES_MMXU1_phV_phsA (&iedModel_MES_MMXU1_phV_phsA)
#define IEDMODEL_MES_MMXU1_phV_phsA_cVal (&iedModel_MES_MMXU1_phV_phsA_cVal)
#define IEDMODEL_MES_MMXU1_phV_phsA_cVal_mag (&iedModel_MES_MMXU1_phV_phsA_cVal_mag)
#define IEDMODEL_MES_MMXU1_phV_phsA_cVal_mag_f (&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_phV_phsA_q (&iedModel_MES_MMXU1_phV_phsA_q)
#define IEDMODEL_MES_MMXU1_phV_phsA_t (&iedModel_MES_MMXU1_phV_phsA_t)
#define IEDMODEL_MES_MMXU1_phV_phsB (&iedModel_MES_MMXU1_phV_phsB)
#define IEDMODEL_MES_MMXU1_phV_phsB_cVal (&iedModel_MES_MMXU1_phV_phsB_cVal)
#define IEDMODEL_MES_MMXU1_phV_phsB_cVal_mag (&iedModel_MES_MMXU1_phV_phsB_cVal_mag)
#define IEDMODEL_MES_MMXU1_phV_phsB_cVal_mag_f (&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_phV_phsB_q (&iedModel_MES_MMXU1_phV_phsB_q)
#define IEDMODEL_MES_MMXU1_phV_phsB_t (&iedModel_MES_MMXU1_phV_phsB_t)
#define IEDMODEL_MES_MMXU1_phV_phsC (&iedModel_MES_MMXU1_phV_phsC)
#define IEDMODEL_MES_MMXU1_phV_phsC_cVal (&iedModel_MES_MMXU1_phV_phsC_cVal)
#define IEDMODEL_MES_MMXU1_phV_phsC_cVal_mag (&iedModel_MES_MMXU1_phV_phsC_cVal_mag)
#define IEDMODEL_MES_MMXU1_phV_phsC_cVal_mag_f (&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_phV_phsC_q (&iedModel_MES_MMXU1_phV_phsC_q)
#define IEDMODEL_MES_MMXU1_phV_phsC_t (&iedModel_MES_MMXU1_phV_phsC_t)
#define IEDMODEL_MES_MMXU1_phV_neut (&iedModel_MES_MMXU1_phV_neut)
#define IEDMODEL_MES_MMXU1_phV_neut_cVal (&iedModel_MES_MMXU1_phV_neut_cVal)
#define IEDMODEL_MES_MMXU1_phV_neut_cVal_mag (&iedModel_MES_MMXU1_phV_neut_cVal_mag)
#define IEDMODEL_MES_MMXU1_phV_neut_cVal_mag_f (&iedModel_MES_MMXU1_phV_neut_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_phV_neut_q (&iedModel_MES_MMXU1_phV_neut_q)
#define IEDMODEL_MES_MMXU1_phV_neut_t (&iedModel_MES_MMXU1_phV_neut_t)

#define IEDMODEL_MES_MMXU1_PPV (&iedModel_MES_MMXU1_PPV)
#define IEDMODEL_MES_MMXU1_PPV_phsA (&iedModel_MES_MMXU1_PPV_phsA)
#define IEDMODEL_MES_MMXU1_PPV_phsA_cVal (&iedModel_MES_MMXU1_PPV_phsA_cVal)
#define IEDMODEL_MES_MMXU1_PPV_phsA_cVal_mag (&iedModel_MES_MMXU1_PPV_phsA_cVal_mag)
#define IEDMODEL_MES_MMXU1_PPV_phsA_cVal_mag_f (&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_PPV_phsA_q (&iedModel_MES_MMXU1_PPV_phsA_q)
#define IEDMODEL_MES_MMXU1_PPV_phsA_t (&iedModel_MES_MMXU1_PPV_phsA_t)
#define IEDMODEL_MES_MMXU1_PPV_phsB (&iedModel_MES_MMXU1_PPV_phsB)
#define IEDMODEL_MES_MMXU1_PPV_phsB_cVal (&iedModel_MES_MMXU1_PPV_phsB_cVal)
#define IEDMODEL_MES_MMXU1_PPV_phsB_cVal_mag (&iedModel_MES_MMXU1_PPV_phsB_cVal_mag)
#define IEDMODEL_MES_MMXU1_PPV_phsB_cVal_mag_f (&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_PPV_phsB_q (&iedModel_MES_MMXU1_PPV_phsB_q)
#define IEDMODEL_MES_MMXU1_PPV_phsB_t (&iedModel_MES_MMXU1_PPV_phsB_t)
#define IEDMODEL_MES_MMXU1_PPV_phsC (&iedModel_MES_MMXU1_PPV_phsC)
#define IEDMODEL_MES_MMXU1_PPV_phsC_cVal (&iedModel_MES_MMXU1_PPV_phsC_cVal)
#define IEDMODEL_MES_MMXU1_PPV_phsC_cVal_mag (&iedModel_MES_MMXU1_PPV_phsC_cVal_mag)
#define IEDMODEL_MES_MMXU1_PPV_phsC_cVal_mag_f (&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f)
#define IEDMODEL_MES_MMXU1_PPV_phsC_q (&iedModel_MES_MMXU1_PPV_phsC_q)
#define IEDMODEL_MES_MMXU1_PPV_phsC_t (&iedModel_MES_MMXU1_PPV_phsC_t)

#define IEDMODEL_MES_MMXU1_totW (&iedModel_MES_MMXU1_totW)
#define IEDMODEL_MES_MMXU1_totW_mag (&iedModel_MES_MMXU1_totW_mag)
#define IEDMODEL_MES_MMXU1_totW_mag_f (&iedModel_MES_MMXU1_totW_mag_f)
#define IEDMODEL_MES_MMXU1_totW_q (&iedModel_MES_MMXU1_totW_q)
#define IEDMODEL_MES_MMXU1_totW_t (&iedModel_MES_MMXU1_totW_t)
#define IEDMODEL_MES_MMXU1_totW_db (&iedModel_MES_MMXU1_totW_db)
#define IEDMODEL_MES_MMXU1_totW_zeroDb (&iedModel_MES_MMXU1_totW_zeroDb)

#define IEDMODEL_MES_MMXU1_totVAr (&iedModel_MES_MMXU1_totVAr)
#define IEDMODEL_MES_MMXU1_totVAr_mag (&iedModel_MES_MMXU1_totVAr_mag)
#define IEDMODEL_MES_MMXU1_totVAr_mag_f (&iedModel_MES_MMXU1_totVAr_mag_f)
#define IEDMODEL_MES_MMXU1_totVAr_q (&iedModel_MES_MMXU1_totVAr_q)
#define IEDMODEL_MES_MMXU1_totVAr_t (&iedModel_MES_MMXU1_totVAr_t)
#define IEDMODEL_MES_MMXU1_totVAr_db (&iedModel_MES_MMXU1_totVAr_db)
#define IEDMODEL_MES_MMXU1_totVAr_zeroDb (&iedModel_MES_MMXU1_totVAr_zeroDb)


#define IEDMODEL_MES_MMXU1_totPF (&iedModel_MES_MMXU1_totPF)
#define IEDMODEL_MES_MMXU1_totPF_mag (&iedModel_MES_MMXU1_totPF_mag)
#define IEDMODEL_MES_MMXU1_totPF_mag_f (&iedModel_MES_MMXU1_totPF_mag_f)
#define IEDMODEL_MES_MMXU1_totPF_q (&iedModel_MES_MMXU1_totPF_q)
#define IEDMODEL_MES_MMXU1_totPF_t (&iedModel_MES_MMXU1_totPF_t)
#define IEDMODEL_MES_MMXU1_totPF_db (&iedModel_MES_MMXU1_totPF_db)
#define IEDMODEL_MES_MMXU1_totPF_zeroDb (&iedModel_MES_MMXU1_totPF_zeroDb)

#define IEDMODEL_MES_MMXU1_Hz (&iedModel_MES_MMXU1_Hz)
#define IEDMODEL_MES_MMXU1_Hz_mag (&iedModel_MES_MMXU1_Hz_mag)
#define IEDMODEL_MES_MMXU1_Hz_mag_f (&iedModel_MES_MMXU1_Hz_mag_f)
#define IEDMODEL_MES_MMXU1_Hz_q (&iedModel_MES_MMXU1_Hz_q)
#define IEDMODEL_MES_MMXU1_Hz_t (&iedModel_MES_MMXU1_Hz_t)
#define IEDMODEL_MES_MMXU1_Hz_db (&iedModel_MES_MMXU1_Hz_db)
#define IEDMODEL_MES_MMXU1_Hz_zeroDb (&iedModel_MES_MMXU1_Hz_zeroDb)
//--------------------------------------

#define IEDMODEL_MES_MSQI1_Health_stVal			(&iedModel_MES_MSQI1_Health_stVal)
#define IEDMODEL_MES_MSQI1_Health_t 			(&iedModel_MES_MSQI1_Health_t)
#define IEDMODEL_MES_MSQI1_Health_q 			(&iedModel_MES_MSQI1_Health_q)
// SeqA
#define IEDMODEL_MES_MSQI1_SeqA 				(&iedModel_MES_MSQI1_SeqA)
#define IEDMODEL_MES_MSQI1_SeqA_c1 				(&iedModel_MES_MSQI1_SeqA_c1)
#define IEDMODEL_MES_MSQI1_SeqA_c1_cVal 		(&iedModel_MES_MSQI1_SeqA_c1_cVal)
#define IEDMODEL_MES_MSQI1_SeqA_c1_cVal_mag 	(&iedModel_MES_MSQI1_SeqA_c1_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqA_c1_cVal_mag_f 	(&iedModel_MES_MSQI1_SeqA_c1_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqA_c1_q 			(&iedModel_MES_MSQI1_SeqA_c1_q)
#define IEDMODEL_MES_MSQI1_SeqA_c1_t 			(&iedModel_MES_MSQI1_SeqA_c1_t)

#define IEDMODEL_MES_MSQI1_SeqA_c2 (&iedModel_MES_MSQI1_SeqA_c2)
#define IEDMODEL_MES_MSQI1_SeqA_c2_cVal (&iedModel_MES_MSQI1_SeqA_c2_cVal)
#define IEDMODEL_MES_MSQI1_SeqA_c2_cVal_mag (&iedModel_MES_MSQI1_SeqA_c2_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqA_c2_cVal_mag_f (&iedModel_MES_MSQI1_SeqA_c2_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqA_c2_q (&iedModel_MES_MSQI1_SeqA_c2_q)
#define IEDMODEL_MES_MSQI1_SeqA_c2_t (&iedModel_MES_MSQI1_SeqA_c2_t)

#define IEDMODEL_MES_MSQI1_SeqA_c3 (&iedModel_MES_MSQI1_SeqA_c3)
#define IEDMODEL_MES_MSQI1_SeqA_c3_cVal (&iedModel_MES_MSQI1_SeqA_c3_cVal)
#define IEDMODEL_MES_MSQI1_SeqA_c3_cVal_mag (&iedModel_MES_MSQI1_SeqA_c3_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqA_c3_cVal_mag_f (&iedModel_MES_MSQI1_SeqA_c3_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqA_c3_q (&iedModel_MES_MSQI1_SeqA_c3_q)
#define IEDMODEL_MES_MSQI1_SeqA_c3_t (&iedModel_MES_MSQI1_SeqA_c3_t)
#define IEDMODEL_MES_MSQI1_SeqA_SeqT (&iedModel_MES_MSQI1_SeqA_SeqT)

// SeqU
#define IEDMODEL_MES_MSQI1_SeqU (&iedModel_MES_MSQI1_SeqU)

#define IEDMODEL_MES_MSQI1_SeqU_c1 (&iedModel_MES_MSQI1_SeqU_c1)
#define IEDMODEL_MES_MSQI1_SeqU_c1_cVal (&iedModel_MES_MSQI1_SeqU_c1_cVal)
#define IEDMODEL_MES_MSQI1_SeqU_c1_cVal_mag (&iedModel_MES_MSQI1_SeqU_c1_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqU_c1_cVal_mag_f (&iedModel_MES_MSQI1_SeqU_c1_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqU_c1_q (&iedModel_MES_MSQI1_SeqU_c1_q)
#define IEDMODEL_MES_MSQI1_SeqU_c1_t (&iedModel_MES_MSQI1_SeqU_c1_t)

#define IEDMODEL_MES_MSQI1_SeqU_c2 (&iedModel_MES_MSQI1_SeqU_c2)
#define IEDMODEL_MES_MSQI1_SeqU_c2_cVal (&iedModel_MES_MSQI1_SeqU_c2_cVal)
#define IEDMODEL_MES_MSQI1_SeqU_c2_cVal_mag (&iedModel_MES_MSQI1_SeqU_c2_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqU_c2_cVal_mag_f (&iedModel_MES_MSQI1_SeqU_c2_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqU_c2_q (&iedModel_MES_MSQI1_SeqU_c2_q)
#define IEDMODEL_MES_MSQI1_SeqU_c2_t (&iedModel_MES_MSQI1_SeqU_c2_t)

#define IEDMODEL_MES_MSQI1_SeqU_c3 (&iedModel_MES_MSQI1_SeqU_c3)
#define IEDMODEL_MES_MSQI1_SeqU_c3_cVal (&iedModel_MES_MSQI1_SeqU_c3_cVal)
#define IEDMODEL_MES_MSQI1_SeqU_c3_cVal_mag (&iedModel_MES_MSQI1_SeqU_c3_cVal_mag)
#define IEDMODEL_MES_MSQI1_SeqU_c3_cVal_mag_f (&iedModel_MES_MSQI1_SeqU_c3_cVal_mag_f)
#define IEDMODEL_MES_MSQI1_SeqU_c3_q (&iedModel_MES_MSQI1_SeqU_c3_q)
#define IEDMODEL_MES_MSQI1_SeqU_c3_t (&iedModel_MES_MSQI1_SeqU_c3_t)
#define IEDMODEL_MES_MSQI1_SeqU_SeqT (&iedModel_MES_MSQI1_SeqU_SeqT)
//--------------------------------------
#define IEDMODEL_MES_RFLO1 (&iedModel_MES_RFLO1)
#define IEDMODEL_MES_RFLO1_Mod (&iedModel_MES_RFLO1_Mod)
#define IEDMODEL_MES_RFLO1_Mod_q (&iedModel_MES_RFLO1_Mod_q)
#define IEDMODEL_MES_RFLO1_Mod_t (&iedModel_MES_RFLO1_Mod_t)
#define IEDMODEL_MES_RFLO1_Mod_stVal (&iedModel_MES_RFLO1_Mod_stVal)
#define IEDMODEL_MES_RFLO1_Mod_ctlModel (&iedModel_MES_RFLO1_Mod_ctlModel)

#define IEDMODEL_MES_RFLO1_Beh (&iedModel_MES_RFLO1_Beh)
#define IEDMODEL_MES_RFLO1_Beh_stVal (&iedModel_MES_RFLO1_Beh_stVal)
#define IEDMODEL_MES_RFLO1_Beh_q (&iedModel_MES_RFLO1_Beh_q)
#define IEDMODEL_MES_RFLO1_Beh_t (&iedModel_MES_RFLO1_Beh_t)

#define IEDMODEL_MES_RFLO1_Health (&iedModel_MES_RFLO1_Health)
#define IEDMODEL_MES_RFLO1_Health_stVal (&iedModel_MES_RFLO1_Health_stVal)
#define IEDMODEL_MES_RFLO1_Health_q (&iedModel_MES_RFLO1_Health_q)
#define IEDMODEL_MES_RFLO1_Health_t (&iedModel_MES_RFLO1_Health_t)

#define IEDMODEL_MES_RFLO1_NamPlt (&iedModel_MES_RFLO1_NamPlt)
#define IEDMODEL_MES_RFLO1_NamPlt_vendor (&iedModel_MES_RFLO1_NamPlt_vendor)
#define IEDMODEL_MES_RFLO1_NamPlt_swRev (&iedModel_MES_RFLO1_NamPlt_swRev)
#define IEDMODEL_MES_RFLO1_NamPlt_d (&iedModel_MES_RFLO1_NamPlt_d)

#define IEDMODEL_MES_RFLO1_Fltz (&iedModel_MES_RFLO1_Fltz)
#define IEDMODEL_MES_RFLO1_Fltz_mag (&iedModel_MES_RFLO1_Fltz_mag)
#define IEDMODEL_MES_RFLO1_Fltz_mag_f (&iedModel_MES_RFLO1_Fltz_mag_f)
#define IEDMODEL_MES_RFLO1_Fltz_q (&iedModel_MES_RFLO1_Fltz_q)
#define IEDMODEL_MES_RFLO1_Fltz_t (&iedModel_MES_RFLO1_Fltz_t)
#define IEDMODEL_MES_RFLO1_Fltz_db (&iedModel_MES_RFLO1_Fltz_db)
#define IEDMODEL_MES_RFLO1_Fltz_zeroDb (&iedModel_MES_RFLO1_Fltz_zeroDb)

#define IEDMODEL_MES_RFLO1_FltDiskm (&iedModel_MES_RFLO1_FltDiskm)
#define IEDMODEL_MES_RFLO1_FltDiskm_mag (&iedModel_MES_RFLO1_FltDiskm_mag)
#define IEDMODEL_MES_RFLO1_FltDiskm_mag_f (&iedModel_MES_RFLO1_FltDiskm_mag_f)
#define IEDMODEL_MES_RFLO1_FltDiskm_q (&iedModel_MES_RFLO1_FltDiskm_q)
#define IEDMODEL_MES_RFLO1_FltDiskm_t (&iedModel_MES_RFLO1_FltDiskm_t)
#define IEDMODEL_MES_RFLO1_FltDiskm_db (&iedModel_MES_RFLO1_FltDiskm_db)
#define IEDMODEL_MES_RFLO1_FltDiskm_zeroDb (&iedModel_MES_RFLO1_FltDiskm_zeroDb)

/****************************************************************************************************
 *
 ****************************************************************************************************/
#define IEDMODEL_PROT_IPTOC1 (&iedModel_PROT_IPTOC1)
#define IEDMODEL_PROT_IPTOC1_Mod (&iedModel_PROT_IPTOC1_Mod)
#define IEDMODEL_PROT_IPTOC1_Mod_q (&iedModel_PROT_IPTOC1_Mod_q)
#define IEDMODEL_PROT_IPTOC1_Mod_t (&iedModel_PROT_IPTOC1_Mod_t)
#define IEDMODEL_PROT_IPTOC1_Mod_ctlModel (&iedModel_PROT_IPTOC1_Mod_ctlModel)

#define IEDMODEL_PROT_IPTOC1_Beh (&iedModel_PROT_IPTOC1_Beh)
#define IEDMODEL_PROT_IPTOC1_Beh_q (&iedModel_PROT_IPTOC1_Beh_q)
#define IEDMODEL_PROT_IPTOC1_Beh_t (&iedModel_PROT_IPTOC1_Beh_t)
#define IEDMODEL_PROT_IPTOC1_Beh_stVal (&iedModel_PROT_IPTOC1_Beh_stVal)

#define IEDMODEL_PROT_IPTOC1_Health (&iedModel_PROT_IPTOC1_Health)
#define IEDMODEL_PROT_IPTOC1_Health_q (&iedModel_PROT_IPTOC1_Health_q)
#define IEDMODEL_PROT_IPTOC1_Health_t (&iedModel_PROT_IPTOC1_Health_t)
#define IEDMODEL_PROT_IPTOC1_Health_stVal (&iedModel_PROT_IPTOC1_Health_stVal)

#define IEDMODEL_PROT_IPTOC1_NamPlt (&iedModel_PROT_IPTOC1_NamPlt)
#define IEDMODEL_PROT_IPTOC1_NamPlt_d (&iedModel_PROT_IPTOC1_NamPlt_d)
#define IEDMODEL_PROT_IPTOC1_NamPlt_swRev (&iedModel_PROT_IPTOC1_NamPlt_swRev)
#define IEDMODEL_PROT_IPTOC1_NamPlt_vendor (&iedModel_PROT_IPTOC1_NamPlt_vendor)

#define IEDMODEL_PROT_IPTOC1_Str (&iedModel_PROT_IPTOC1_Str)
#define IEDMODEL_PROT_IPTOC1_Str_general (&iedModel_PROT_IPTOC1_Str_general)
#define IEDMODEL_PROT_IPTOC1_Str_dirGeneral (&iedModel_PROT_IPTOC1_Str_dirGeneral)
#define IEDMODEL_PROT_IPTOC1_Str_q (&iedModel_PROT_IPTOC1_Str_q)
#define IEDMODEL_PROT_IPTOC1_Str_t (&iedModel_PROT_IPTOC1_Str_t)

#define IEDMODEL_PROT_IPTOC1_Op (&iedModel_PROT_IPTOC1_Op)
#define IEDMODEL_PROT_IPTOC1_Op_general (&iedModel_PROT_IPTOC1_Op_general)
#define IEDMODEL_PROT_IPTOC1_Op_q (&iedModel_PROT_IPTOC1_Op_q)
#define IEDMODEL_PROT_IPTOC1_Op_t (&iedModel_PROT_IPTOC1_Op_t)

/****************************************************************************************************
 *
 ****************************************************************************************************/
#define IEDMODEL_CTRL_CSWI1 (&iedModel_CTRL_CSWI1)
#define IEDMODEL_CTRL_CSWI1_Mod (&iedModel_CTRL_CSWI1_Mod)
#define IEDMODEL_CTRL_CSWI1_Mod_q (&iedModel_CTRL_CSWI1_Mod_q)
#define IEDMODEL_CTRL_CSWI1_Mod_t (&iedModel_CTRL_CSWI1_Mod_t)
#define IEDMODEL_CTRL_CSWI1_Mod_stVal (&iedModel_CTRL_CSWI1_Mod_stVal)
#define IEDMODEL_CTRL_CSWI1_Mod_ctlModel (&iedModel_CTRL_CSWI1_Mod_ctlModel)

#define IEDMODEL_CTRL_CSWI1_Beh (&iedModel_CTRL_CSWI1_Beh)
#define IEDMODEL_CTRL_CSWI1_Beh_q (&iedModel_CTRL_CSWI1_Beh_q)
#define IEDMODEL_CTRL_CSWI1_Beh_t (&iedModel_CTRL_CSWI1_Beh_t)
#define IEDMODEL_CTRL_CSWI1_Beh_stVal (&iedModel_CTRL_CSWI1_Beh_stVal)

#define IEDMODEL_CTRL_CSWI1_Health (&iedModel_CTRL_CSWI1_Health)
#define IEDMODEL_CTRL_CSWI1_Health_q (&iedModel_CTRL_CSWI1_Health_q)
#define IEDMODEL_CTRL_CSWI1_Health_t (&iedModel_CTRL_CSWI1_Health_t)
#define IEDMODEL_CTRL_CSWI1_Health_stVal (&iedModel_CTRL_CSWI1_Health_stVal)

#define IEDMODEL_CTRL_CSWI1_NamPlt (&iedModel_CTRL_CSWI1_NamPlt)
#define IEDMODEL_CTRL_CSWI1_NamPlt_d (&iedModel_CTRL_CSWI1_NamPlt_d)
#define IEDMODEL_CTRL_CSWI1_NamPlt_swRev (&iedModel_CTRL_CSWI1_NamPlt_swRev)
#define IEDMODEL_CTRL_CSWI1_NamPlt_vendor (&iedModel_CTRL_CSWI1_NamPlt_vendor)


#define IEDMODEL_CTRL_CSWI1_Pos (&iedModel_CTRL_CSWI1_Pos)
#define IEDMODEL_CTRL_CSWI1_Pos_stVal (&iedModel_CTRL_CSWI1_Pos_stVal)
#define IEDMODEL_CTRL_CSWI1_Pos_q (&iedModel_CTRL_CSWI1_Pos_q)
#define IEDMODEL_CTRL_CSWI1_Pos_t (&iedModel_CTRL_CSWI1_Pos_t)
#define IEDMODEL_CTRL_CSWI1_Pos_ctlModel (&iedModel_CTRL_CSWI1_Pos_ctlModel)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper (&iedModel_CTRL_CSWI1_Pos_Oper)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_ctlVal (&iedModel_CTRL_CSWI1_Pos_Oper_ctlVal)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_origin (&iedModel_CTRL_CSWI1_Pos_Oper_origin)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_origin_orCat (&iedModel_CTRL_CSWI1_Pos_Oper_origin_orCat)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_origin_orIdent (&iedModel_CTRL_CSWI1_Pos_Oper_origin_orIdent)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_ctlNum (&iedModel_CTRL_CSWI1_Pos_Oper_ctlNum)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_T (&iedModel_CTRL_CSWI1_Pos_Oper_T)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_Test (&iedModel_CTRL_CSWI1_Pos_Oper_Test)
#define IEDMODEL_CTRL_CSWI1_Pos_Oper_Check (&iedModel_CTRL_CSWI1_Pos_Oper_Check)

/****************************************************************************************************
 * XCBR1
 ****************************************************************************************************/

#define IEDMODEL_CTRL_XCBR1_Mod_Oper (&iedModel_CTRL_XCBR1_Mod_Oper)

#define IEDMODEL_CTRL_XCBR1 (&iedModel_CTRL_XCBR1)
#define IEDMODEL_CTRL_XCBR1_Mod (&iedModel_CTRL_XCBR1_Mod)
#define IEDMODEL_CTRL_XCBR1_Mod_q (&iedModel_CTRL_XCBR1_Mod_q)
#define IEDMODEL_CTRL_XCBR1_Mod_t (&iedModel_CTRL_XCBR1_Mod_t)
#define IEDMODEL_CTRL_XCBR1_Mod_stVal (&iedModel_CTRL_XCBR1_Mod_stVal)
#define IEDMODEL_CTRL_XCBR1_Mod_ctlModel (&iedModel_CTRL_XCBR1_Mod_ctlModel)

#define IEDMODEL_CTRL_XCBR1_Beh (&iedModel_CTRL_XCBR1_Beh)
#define IEDMODEL_CTRL_XCBR1_Beh_q (&iedModel_CTRL_XCBR1_Beh_q)
#define IEDMODEL_CTRL_XCBR1_Beh_t (&iedModel_CTRL_XCBR1_Beh_t)
#define IEDMODEL_CTRL_XCBR1_Beh_stVal (&iedModel_CTRL_XCBR1_Beh_stVal)

#define IEDMODEL_CTRL_XCBR1_Health (&iedModel_CTRL_XCBR1_Health)
#define IEDMODEL_CTRL_XCBR1_Health_q (&iedModel_CTRL_XCBR1_Health_q)
#define IEDMODEL_CTRL_XCBR1_Health_t (&iedModel_CTRL_XCBR1_Health_t)
#define IEDMODEL_CTRL_XCBR1_Health_stVal (&iedModel_CTRL_XCBR1_Health_stVal)



#define IEDMODEL_CTRL_XCBR1_Pos (&iedModel_CTRL_XCBR1_Pos)
#define IEDMODEL_CTRL_XCBR1_Pos_stVal (&iedModel_CTRL_XCBR1_Pos_stVal)
#define IEDMODEL_CTRL_XCBR1_Pos_q (&iedModel_CTRL_XCBR1_Pos_q)
#define IEDMODEL_CTRL_XCBR1_Pos_t (&iedModel_CTRL_XCBR1_Pos_t)
#define IEDMODEL_CTRL_XCBR1_Pos_ctlModel (&iedModel_CTRL_XCBR1_Pos_ctlModel)

#define IEDMODEL_CTRL_XCBR1_Loc (&iedModel_CTRL_XCBR1_Loc)
#define IEDMODEL_CTRL_XCBR1_Loc_stVal (&iedModel_CTRL_XCBR1_Loc_stVal)
#define IEDMODEL_CTRL_XCBR1_Loc_q (&iedModel_CTRL_XCBR1_Loc_q)
#define IEDMODEL_CTRL_XCBR1_Loc_t (&iedModel_CTRL_XCBR1_Loc_t)

/****************************************************************************************************
 * CTRL_GGIO    iedModel_CTRL_GGIO1_SPCSO1_Oper
 ****************************************************************************************************/
#define IEDMODEL_CTRL_GGIO1_SPCSO1				(&iedModel_CTRL_GGIO1_SPCSO1)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_Oper 		(&iedModel_CTRL_GGIO1_SPCSO1_Oper)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_Oper_T		(&iedModel_CTRL_GGIO1_SPCSO1_Oper_T)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_Oper_ctlVal	(&iedModel_CTRL_GGIO1_SPCSO1_Oper_ctlVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_stVal		(&iedModel_CTRL_GGIO1_SPCSO1_stVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_q			(&iedModel_CTRL_GGIO1_SPCSO1_q)
#define IEDMODEL_CTRL_GGIO1_SPCSO1_t			(&iedModel_CTRL_GGIO1_SPCSO1_t)

#define IEDMODEL_CTRL_GGIO1_SPCSO2				(&iedModel_CTRL_GGIO1_SPCSO2)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_Oper 		(&iedModel_CTRL_GGIO1_SPCSO2_Oper)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_Oper_T		(&iedModel_CTRL_GGIO1_SPCSO2_Oper_T)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_Oper_ctlVal	(&iedModel_CTRL_GGIO1_SPCSO2_Oper_ctlVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_stVal		(&iedModel_CTRL_GGIO1_SPCSO2_stVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_q			(&iedModel_CTRL_GGIO1_SPCSO2_q)
#define IEDMODEL_CTRL_GGIO1_SPCSO2_t			(&iedModel_CTRL_GGIO1_SPCSO2_t)

#define IEDMODEL_CTRL_GGIO1_SPCSO3				(&iedModel_CTRL_GGIO1_SPCSO3)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_Oper 		(&iedModel_CTRL_GGIO1_SPCSO3_Oper)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_Oper_T		(&iedModel_CTRL_GGIO1_SPCSO3_Oper_T)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_Oper_ctlVal	(&iedModel_CTRL_GGIO1_SPCSO3_Oper_ctlVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_stVal		(&iedModel_CTRL_GGIO1_SPCSO3_stVal)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_q			(&iedModel_CTRL_GGIO1_SPCSO3_q)
#define IEDMODEL_CTRL_GGIO1_SPCSO3_t			(&iedModel_CTRL_GGIO1_SPCSO3_t)


#endif /* STATIC_MODEL_H_ */

