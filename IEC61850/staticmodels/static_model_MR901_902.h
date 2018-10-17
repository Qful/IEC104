/*
 * static_model_901.h
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

#ifndef STATIC_MODEL_MR901_H_
#define STATIC_MODEL_MR901_H_

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

//extern DataObject    iedModel_LD0_LLN0_SGCB;							// SGCB - Управление группами уставок
//extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
//extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
//extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

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

// RDRE ----------------------------------------------------------------------------------------------------
extern LogicalNode iedModel_LD0_RDRE1;

extern DataObject iedModel_LD0_RDRE1_Mod;
extern DataAttribute iedModel_LD0_RDRE1_Mod_q;
extern DataAttribute iedModel_LD0_RDRE1_Mod_t;
extern DataAttribute iedModel_LD0_RDRE1_Mod_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Mod_ctlModel;
extern DataObject iedModel_LD0_RDRE1_Beh;
extern DataAttribute iedModel_LD0_RDRE1_Beh_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Beh_q;
extern DataAttribute iedModel_LD0_RDRE1_Beh_t;
extern DataObject iedModel_LD0_RDRE1_Health;
extern DataAttribute iedModel_LD0_RDRE1_Health_stVal;
extern DataAttribute iedModel_LD0_RDRE1_Health_q;
extern DataAttribute iedModel_LD0_RDRE1_Health_t;
extern DataObject iedModel_LD0_RDRE1_NamPlt;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_vendor;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_swRev;
extern DataAttribute iedModel_LD0_RDRE1_NamPlt_d;

extern DataObject iedModel_LD0_RDRE1_RCBMade;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_stVal;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_q;
extern DataAttribute iedModel_LD0_RDRE1_RCBMade_t;

extern DataObject iedModel_LD0_RDRE1_FltNum;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_stVal;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_q;
extern DataAttribute iedModel_LD0_RDRE1_FltNum_t;
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

extern DataObject    iedModel_CTRL_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_CTRL_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_CTRL_LLN0_SGCB_q;
extern DataAttribute iedModel_CTRL_LLN0_SGCB_t;

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

// ---------------------------------------------------------------------------------------------------------
// 0     0  0000   000
// 00   00  0     0
// 0 0 0 0  0     0
// 0  0  0  0000   000
// 0     0  0         0
// 0     0  0         0
// 0     0  0000   000
// ---------------------------------------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_LLN0;								// Логический нуль узла. Имя: LLN0
extern DataObject    iedModel_MES_LLN0_Mod;							// Mod - Режим
extern DataAttribute iedModel_MES_LLN0_Mod_q;
extern DataAttribute iedModel_MES_LLN0_Mod_t;
extern DataAttribute iedModel_MES_LLN0_Mod_stVal;
extern DataAttribute iedModel_MES_LLN0_Mod_ctlModel;

extern DataObject    iedModel_MES_LLN0_Beh;							// Beh - Режим работы
extern DataAttribute iedModel_MES_LLN0_Beh_stVal;
extern DataAttribute iedModel_MES_LLN0_Beh_q;
extern DataAttribute iedModel_MES_LLN0_Beh_t;

extern DataObject    iedModel_MES_LLN0_Health;						// Health - Состояние работоспособности
extern DataAttribute iedModel_MES_LLN0_Health_stVal;
extern DataAttribute iedModel_MES_LLN0_Health_q;
extern DataAttribute iedModel_MES_LLN0_Health_t;

extern DataObject    iedModel_MES_LLN0_NamPlt;						// NamPIt - Паспортная табличка
extern DataAttribute iedModel_MES_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_MES_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_d;
extern DataAttribute iedModel_MES_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_MES_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_MES_LLN0_SGCB;							// SGCB - Управление группами уставок
extern DataAttribute iedModel_MES_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_MES_LLN0_SGCB_q;
extern DataAttribute iedModel_MES_LLN0_SGCB_t;

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

// -----------------------------------------------------------------------------
// LN GGIO1 - Вход/выход для общих процессов см. 61850-7-4 п.5.7.2
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_GGIO_OUTGGIO1;

// Mod																// обязательные элементы -------------------------------------
extern DataObject    iedModel_GGIO_OUTGGIO1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Mod_ctlModel;

// Beh
extern DataObject    iedModel_GGIO_OUTGGIO1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Beh_t;

// Health
extern DataObject    iedModel_GGIO_OUTGGIO1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Health_t;

// NamPlt
extern DataObject    iedModel_GGIO_OUTGGIO1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_GGIO_OUTGGIO1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN GGIO1.
																	// -----------------------------------------------------------
// ---------------------------------

// AnIn1 см. 61850-7-3 п.7.4.2
extern DataObject    iedModel_GGIO_OUTGGIO1_AnIn1;				// АНАЛОГОВЫЙ ВХОД				(не обязательные данные)
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_mag;			// 		Измеренное значение (конструкция)
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_mag_f;			// 		->		Измеренное значение Float32
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_q;				// 		признака качества
extern DataAttribute iedModel_GGIO_OUTGGIO1_AnIn1_t;				// 		метки времени

// SPCSO1 см. 61850-7-3 п.7.5.2
extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO1;						// КОНТРОЛИРУЕМЫЙ ВЫХОД СТАТУСА НЕДУБЛИРОВАННОГО УПРАВЛЕНИЯ				(не обязательные данные)
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_stVal;					// 		значение состояния данных
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_q;						// 		признака качества
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO1_t;						// 		метки времени.

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO2_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO3_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO4_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO5_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO6_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO7_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_SPCSO8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO8_t;

//SPCSO9
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO9_stVal;

//SPCSO10
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO10_stVal;

//SPCSO11
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO11_stVal;

//SPCSO12
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO12_stVal;

//SPCSO13
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO13_stVal;

//SPCSO14
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO14_stVal;

//SPCSO15
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO15_stVal;

//SPCSO16
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO16;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO16_stVal;

//SPCSO17
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO17;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO17_stVal;

//SPCSO18
extern DataObject iedModel_GGIO_OUTGGIO1_SPCSO18;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_t;
extern DataAttribute iedModel_GGIO_OUTGGIO1_SPCSO18_stVal;

// ------------- Дискретные входы ------------------------------
// Ind1 см. 61850-7-3 п.7.3.2
extern DataObject    iedModel_GGIO_OUTGGIO1_Ind1;								// ОБЩАЯ ИНДИКАЦИЯ(вход двоичных сигналов)				(не обязательные данные)
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_stVal;						// 			значение состояния данных BOOLEAN
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_q;							// 			признака качества
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind1_t;							// 			метки времени.

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind2;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind2_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind3;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind3_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind4;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind4_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind5;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind5_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind6;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind6_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind7;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind7_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind8;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind8_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind9_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind10_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind11_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind12_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind13_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind14_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind15_t;

extern DataObject    iedModel_GGIO_OUTGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_OUTGGIO1_Ind16_t;

//-----------------------------------------------------
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
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind13_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind14_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind15_dU;

extern DataObject    iedModel_GGIO_LEDGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_t;
extern DataAttribute iedModel_GGIO_LEDGGIO1_Ind16_dU;

//-----------------------------------------------------
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

extern DataObject    iedModel_GGIO_INGGIO1_Ind1;								// ОБЩАЯ ИНДИКАЦИЯ(вход двоичных сигналов)				(не обязательные данные)
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_stVal;						// 			значение состояния данных BOOLEAN
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_q;							// 			признака качества
extern DataAttribute iedModel_GGIO_INGGIO1_Ind1_t;							// 			метки времени.

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

extern DataObject    iedModel_GGIO_INGGIO1_Ind17;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind17_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind18;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind18_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind19;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind19_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind20;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind20_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind21;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind21_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind22;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind22_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind23;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind23_t;

extern DataObject    iedModel_GGIO_INGGIO1_Ind24;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_stVal;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_q;
extern DataAttribute iedModel_GGIO_INGGIO1_Ind24_t;

//-SSLGGIO1 -------------------------------------------------------
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

extern DataObject iedModel_GGIO_SSLGGIO1_Ind25;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind25_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind26;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind26_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind27;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind27_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind28;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind28_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind29;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind29_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind30;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind30_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind31;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind31_t;

extern DataObject iedModel_GGIO_SSLGGIO1_Ind32;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_stVal;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_q;
extern DataAttribute iedModel_GGIO_SSLGGIO1_Ind32_t;

//----------------------------------------------------------------------------

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

extern DataObject iedModel_GGIO_VLSGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_VLSGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_VLSGGIO1_Ind16_t;

//----------------------------------------------------------------------------

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

extern DataObject iedModel_GGIO_LSGGIO1_Ind9;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind9_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind10;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind10_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind11;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind11_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind12;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind12_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind13;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind13_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind14;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind14_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind15;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind15_t;

extern DataObject iedModel_GGIO_LSGGIO1_Ind16;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_stVal;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_q;
extern DataAttribute iedModel_GGIO_LSGGIO1_Ind16_t;
#if defined (MR901)
// -----------------------------------------------------------------------------
// LN MMXN1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXN1;
extern DataObject    iedModel_MES_MMXN1_Mod;
extern DataAttribute iedModel_MES_MMXN1_Mod_q;
extern DataAttribute iedModel_MES_MMXN1_Mod_t;
extern DataAttribute iedModel_MES_MMXN1_Mod_stVal;
extern DataAttribute iedModel_MES_MMXN1_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXN1_Beh;
extern DataAttribute iedModel_MES_MMXN1_Beh_stVal;
extern DataAttribute iedModel_MES_MMXN1_Beh_q;
extern DataAttribute iedModel_MES_MMXN1_Beh_t;
extern DataObject    iedModel_MES_MMXN1_Health;
extern DataAttribute iedModel_MES_MMXN1_Health_stVal;
extern DataAttribute iedModel_MES_MMXN1_Health_q;
extern DataAttribute iedModel_MES_MMXN1_Health_t;
extern DataObject    iedModel_MES_MMXN1_NamPlt;
extern DataAttribute iedModel_MES_MMXN1_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXN1_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXN1_NamPlt_d;

// Amp1
extern DataObject    iedModel_MES_MMXN1_Amp1;
extern DataAttribute iedModel_MES_MMXN1_Amp1_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp1_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp1_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp1_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp1_q;
extern DataAttribute iedModel_MES_MMXN1_Amp1_t;
extern DataAttribute iedModel_MES_MMXN1_Amp1_db;
extern DataAttribute iedModel_MES_MMXN1_Amp1_zeroDb;
// Amp2
extern DataObject    iedModel_MES_MMXN1_Amp2;
extern DataAttribute iedModel_MES_MMXN1_Amp2_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp2_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp2_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp2_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp2_q;
extern DataAttribute iedModel_MES_MMXN1_Amp2_t;
extern DataAttribute iedModel_MES_MMXN1_Amp2_db;
extern DataAttribute iedModel_MES_MMXN1_Amp2_zeroDb;
// Amp3
extern DataObject    iedModel_MES_MMXN1_Amp3;
extern DataAttribute iedModel_MES_MMXN1_Amp3_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp3_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp3_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp3_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp3_q;
extern DataAttribute iedModel_MES_MMXN1_Amp3_t;
extern DataAttribute iedModel_MES_MMXN1_Amp3_db;
extern DataAttribute iedModel_MES_MMXN1_Amp3_zeroDb;
// Amp4
extern DataObject    iedModel_MES_MMXN1_Amp4;
extern DataAttribute iedModel_MES_MMXN1_Amp4_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp4_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp4_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp4_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp4_q;
extern DataAttribute iedModel_MES_MMXN1_Amp4_t;
extern DataAttribute iedModel_MES_MMXN1_Amp4_db;
extern DataAttribute iedModel_MES_MMXN1_Amp4_zeroDb;
// Amp5
extern DataObject    iedModel_MES_MMXN1_Amp5;
extern DataAttribute iedModel_MES_MMXN1_Amp5_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp5_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp5_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp5_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp5_q;
extern DataAttribute iedModel_MES_MMXN1_Amp5_t;
extern DataAttribute iedModel_MES_MMXN1_Amp5_db;
extern DataAttribute iedModel_MES_MMXN1_Amp5_zeroDb;
// Amp6
extern DataObject    iedModel_MES_MMXN1_Amp6;
extern DataAttribute iedModel_MES_MMXN1_Amp6_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp6_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp6_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp6_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp6_q;
extern DataAttribute iedModel_MES_MMXN1_Amp6_t;
extern DataAttribute iedModel_MES_MMXN1_Amp6_db;
extern DataAttribute iedModel_MES_MMXN1_Amp6_zeroDb;
// Amp7
extern DataObject    iedModel_MES_MMXN1_Amp7;
extern DataAttribute iedModel_MES_MMXN1_Amp7_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp7_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp7_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp7_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp7_q;
extern DataAttribute iedModel_MES_MMXN1_Amp7_t;
extern DataAttribute iedModel_MES_MMXN1_Amp7_db;
extern DataAttribute iedModel_MES_MMXN1_Amp7_zeroDb;
// Amp8
extern DataObject    iedModel_MES_MMXN1_Amp8;
extern DataAttribute iedModel_MES_MMXN1_Amp8_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp8_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp8_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp8_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp8_q;
extern DataAttribute iedModel_MES_MMXN1_Amp8_t;
extern DataAttribute iedModel_MES_MMXN1_Amp8_db;
extern DataAttribute iedModel_MES_MMXN1_Amp8_zeroDb;
// Amp9
extern DataObject    iedModel_MES_MMXN1_Amp9;
extern DataAttribute iedModel_MES_MMXN1_Amp9_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp9_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp9_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp9_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp9_q;
extern DataAttribute iedModel_MES_MMXN1_Amp9_t;
extern DataAttribute iedModel_MES_MMXN1_Amp9_db;
extern DataAttribute iedModel_MES_MMXN1_Amp9_zeroDb;
// Amp10
extern DataObject    iedModel_MES_MMXN1_Amp10;
extern DataAttribute iedModel_MES_MMXN1_Amp10_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp10_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp10_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp10_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp10_q;
extern DataAttribute iedModel_MES_MMXN1_Amp10_t;
extern DataAttribute iedModel_MES_MMXN1_Amp10_db;
extern DataAttribute iedModel_MES_MMXN1_Amp10_zeroDb;
// Amp11
extern DataObject    iedModel_MES_MMXN1_Amp11;
extern DataAttribute iedModel_MES_MMXN1_Amp11_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp11_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp11_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp11_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp11_q;
extern DataAttribute iedModel_MES_MMXN1_Amp11_t;
extern DataAttribute iedModel_MES_MMXN1_Amp11_db;
extern DataAttribute iedModel_MES_MMXN1_Amp11_zeroDb;
// Amp12
extern DataObject    iedModel_MES_MMXN1_Amp12;
extern DataAttribute iedModel_MES_MMXN1_Amp12_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp12_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp12_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp12_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp12_q;
extern DataAttribute iedModel_MES_MMXN1_Amp12_t;
extern DataAttribute iedModel_MES_MMXN1_Amp12_db;
extern DataAttribute iedModel_MES_MMXN1_Amp12_zeroDb;
// Amp13
extern DataObject    iedModel_MES_MMXN1_Amp13;
extern DataAttribute iedModel_MES_MMXN1_Amp13_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp13_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp13_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp13_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp13_q;
extern DataAttribute iedModel_MES_MMXN1_Amp13_t;
extern DataAttribute iedModel_MES_MMXN1_Amp13_db;
extern DataAttribute iedModel_MES_MMXN1_Amp13_zeroDb;
// Amp14
extern DataObject    iedModel_MES_MMXN1_Amp14;
extern DataAttribute iedModel_MES_MMXN1_Amp14_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp14_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp14_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp14_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp14_q;
extern DataAttribute iedModel_MES_MMXN1_Amp14_t;
extern DataAttribute iedModel_MES_MMXN1_Amp14_db;
extern DataAttribute iedModel_MES_MMXN1_Amp14_zeroDb;
// Amp15
extern DataObject    iedModel_MES_MMXN1_Amp15;
extern DataAttribute iedModel_MES_MMXN1_Amp15_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp15_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp15_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp15_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp15_q;
extern DataAttribute iedModel_MES_MMXN1_Amp15_t;
extern DataAttribute iedModel_MES_MMXN1_Amp15_db;
extern DataAttribute iedModel_MES_MMXN1_Amp15_zeroDb;
// Amp16
extern DataObject    iedModel_MES_MMXN1_Amp16;
extern DataAttribute iedModel_MES_MMXN1_Amp16_mag;
extern DataAttribute iedModel_MES_MMXN1_Amp16_mag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp16_instMag;
extern DataAttribute iedModel_MES_MMXN1_Amp16_instMag_f;
extern DataAttribute iedModel_MES_MMXN1_Amp16_q;
extern DataAttribute iedModel_MES_MMXN1_Amp16_t;
extern DataAttribute iedModel_MES_MMXN1_Amp16_db;
extern DataAttribute iedModel_MES_MMXN1_Amp16_zeroDb;
#endif

#if defined (MR902)
// -----------------------------------------------------------------------------
// LN MMXU1
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU1;
extern DataObject    iedModel_MES_MMXU1_Mod;
extern DataAttribute iedModel_MES_MMXU1_Mod_q;
extern DataAttribute iedModel_MES_MMXU1_Mod_t;
extern DataAttribute iedModel_MES_MMXU1_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU1_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU1_Beh;
extern DataAttribute iedModel_MES_MMXU1_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU1_Beh_q;
extern DataAttribute iedModel_MES_MMXU1_Beh_t;
extern DataObject    iedModel_MES_MMXU1_Health;
extern DataAttribute iedModel_MES_MMXU1_Health_stVal;
extern DataAttribute iedModel_MES_MMXU1_Health_q;
extern DataAttribute iedModel_MES_MMXU1_Health_t;
extern DataObject    iedModel_MES_MMXU1_NamPlt;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU1_NamPlt_d;

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

// -----------------------------------------------------------------------------
// LN MMXU2
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU2;
extern DataObject    iedModel_MES_MMXU2_Mod;
extern DataAttribute iedModel_MES_MMXU2_Mod_q;
extern DataAttribute iedModel_MES_MMXU2_Mod_t;
extern DataAttribute iedModel_MES_MMXU2_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU2_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU2_Beh;
extern DataAttribute iedModel_MES_MMXU2_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU2_Beh_q;
extern DataAttribute iedModel_MES_MMXU2_Beh_t;
extern DataObject    iedModel_MES_MMXU2_Health;
extern DataAttribute iedModel_MES_MMXU2_Health_stVal;
extern DataAttribute iedModel_MES_MMXU2_Health_q;
extern DataAttribute iedModel_MES_MMXU2_Health_t;
extern DataObject    iedModel_MES_MMXU2_NamPlt;
extern DataAttribute iedModel_MES_MMXU2_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU2_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU2_NamPlt_d;

extern DataObject iedModel_MES_MMXU2_A;
extern DataObject iedModel_MES_MMXU2_A_phsA;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU2_A_phsA_zeroDb;
extern DataObject iedModel_MES_MMXU2_A_phsB;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU2_A_phsB_zeroDb;
extern DataObject iedModel_MES_MMXU2_A_phsC;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU2_A_phsC_zeroDb;
// -----------------------------------------------------------------------------
// LN MMXU3
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU3;
extern DataObject    iedModel_MES_MMXU3_Mod;
extern DataAttribute iedModel_MES_MMXU3_Mod_q;
extern DataAttribute iedModel_MES_MMXU3_Mod_t;
extern DataAttribute iedModel_MES_MMXU3_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU3_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU3_Beh;
extern DataAttribute iedModel_MES_MMXU3_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU3_Beh_q;
extern DataAttribute iedModel_MES_MMXU3_Beh_t;
extern DataObject    iedModel_MES_MMXU3_Health;
extern DataAttribute iedModel_MES_MMXU3_Health_stVal;
extern DataAttribute iedModel_MES_MMXU3_Health_q;
extern DataAttribute iedModel_MES_MMXU3_Health_t;
extern DataObject    iedModel_MES_MMXU3_NamPlt;
extern DataAttribute iedModel_MES_MMXU3_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU3_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU3_NamPlt_d;

extern DataObject iedModel_MES_MMXU3_A;
extern DataObject iedModel_MES_MMXU3_A_phsA;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU3_A_phsA_zeroDb;
extern DataObject iedModel_MES_MMXU3_A_phsB;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU3_A_phsB_zeroDb;
extern DataObject iedModel_MES_MMXU3_A_phsC;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU3_A_phsC_zeroDb;
// -----------------------------------------------------------------------------
// LN MMXU4
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU4;
extern DataObject    iedModel_MES_MMXU4_Mod;
extern DataAttribute iedModel_MES_MMXU4_Mod_q;
extern DataAttribute iedModel_MES_MMXU4_Mod_t;
extern DataAttribute iedModel_MES_MMXU4_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU4_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU4_Beh;
extern DataAttribute iedModel_MES_MMXU4_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU4_Beh_q;
extern DataAttribute iedModel_MES_MMXU4_Beh_t;
extern DataObject    iedModel_MES_MMXU4_Health;
extern DataAttribute iedModel_MES_MMXU4_Health_stVal;
extern DataAttribute iedModel_MES_MMXU4_Health_q;
extern DataAttribute iedModel_MES_MMXU4_Health_t;
extern DataObject    iedModel_MES_MMXU4_NamPlt;
extern DataAttribute iedModel_MES_MMXU4_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU4_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU4_NamPlt_d;

extern DataObject iedModel_MES_MMXU4_A;
extern DataObject iedModel_MES_MMXU4_A_phsA;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU4_A_phsA_zeroDb;
extern DataObject iedModel_MES_MMXU4_A_phsB;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU4_A_phsB_zeroDb;
extern DataObject iedModel_MES_MMXU4_A_phsC;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU4_A_phsC_zeroDb;

// -----------------------------------------------------------------------------
// LN MMXU5
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU5;
extern DataObject    iedModel_MES_MMXU5_Mod;
extern DataAttribute iedModel_MES_MMXU5_Mod_q;
extern DataAttribute iedModel_MES_MMXU5_Mod_t;
extern DataAttribute iedModel_MES_MMXU5_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU5_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU5_Beh;
extern DataAttribute iedModel_MES_MMXU5_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU5_Beh_q;
extern DataAttribute iedModel_MES_MMXU5_Beh_t;
extern DataObject    iedModel_MES_MMXU5_Health;
extern DataAttribute iedModel_MES_MMXU5_Health_stVal;
extern DataAttribute iedModel_MES_MMXU5_Health_q;
extern DataAttribute iedModel_MES_MMXU5_Health_t;
extern DataObject    iedModel_MES_MMXU5_NamPlt;
extern DataAttribute iedModel_MES_MMXU5_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU5_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU5_NamPlt_d;

extern DataObject iedModel_MES_MMXU5_A;
extern DataObject iedModel_MES_MMXU5_A_phsA;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_cVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_cVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_instCVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_q;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_t;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_db;
extern DataAttribute iedModel_MES_MMXU5_A_phsA_zeroDb;
extern DataObject iedModel_MES_MMXU5_A_phsB;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_cVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_cVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_instCVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_q;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_t;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_db;
extern DataAttribute iedModel_MES_MMXU5_A_phsB_zeroDb;
extern DataObject iedModel_MES_MMXU5_A_phsC;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_cVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_cVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_instCVal;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_q;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_t;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_db;
extern DataAttribute iedModel_MES_MMXU5_A_phsC_zeroDb;


extern LogicalNode iedModel_MES_INMMXN1;

extern DataObject iedModel_MES_INMMXN1_Mod;
extern DataAttribute iedModel_MES_INMMXN1_Mod_q;
extern DataAttribute iedModel_MES_INMMXN1_Mod_t;
extern DataAttribute iedModel_MES_INMMXN1_Mod_stVal;
extern DataAttribute iedModel_MES_INMMXN1_Mod_ctlModel;

extern DataObject iedModel_MES_INMMXN1_Beh;
extern DataAttribute iedModel_MES_INMMXN1_Beh_stVal;
extern DataAttribute iedModel_MES_INMMXN1_Beh_q;
extern DataAttribute iedModel_MES_INMMXN1_Beh_t;

extern DataObject iedModel_MES_INMMXN1_Health;
extern DataAttribute iedModel_MES_INMMXN1_Health_stVal;
extern DataAttribute iedModel_MES_INMMXN1_Health_q;
extern DataAttribute iedModel_MES_INMMXN1_Health_t;

extern DataObject iedModel_MES_INMMXN1_NamPlt;
extern DataAttribute iedModel_MES_INMMXN1_NamPlt_vendor;
extern DataAttribute iedModel_MES_INMMXN1_NamPlt_swRev;
extern DataAttribute iedModel_MES_INMMXN1_NamPlt_d;

// Amp1
extern DataObject    iedModel_MES_INMMXN1_Amp1;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_mag;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_mag_f;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_instMag;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_instMag_f;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_q;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_t;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_db;
extern DataAttribute iedModel_MES_INMMXN1_Amp1_zeroDb;

/*
// -----------------------------------------------------------------------------
// LN MMXU6
// -----------------------------------------------------------------------------
extern LogicalNode   iedModel_MES_MMXU6;
extern DataObject    iedModel_MES_MMXU6_Mod;
extern DataAttribute iedModel_MES_MMXU6_Mod_q;
extern DataAttribute iedModel_MES_MMXU6_Mod_t;
extern DataAttribute iedModel_MES_MMXU6_Mod_stVal;
extern DataAttribute iedModel_MES_MMXU6_Mod_ctlModel;
extern DataObject    iedModel_MES_MMXU6_Beh;
extern DataAttribute iedModel_MES_MMXU6_Beh_stVal;
extern DataAttribute iedModel_MES_MMXU6_Beh_q;
extern DataAttribute iedModel_MES_MMXU6_Beh_t;
extern DataObject    iedModel_MES_MMXU6_Health;
extern DataAttribute iedModel_MES_MMXU6_Health_stVal;
extern DataAttribute iedModel_MES_MMXU6_Health_q;
extern DataAttribute iedModel_MES_MMXU6_Health_t;
extern DataObject    iedModel_MES_MMXU6_NamPlt;
extern DataAttribute iedModel_MES_MMXU6_NamPlt_vendor;
extern DataAttribute iedModel_MES_MMXU6_NamPlt_swRev;
extern DataAttribute iedModel_MES_MMXU6_NamPlt_d;

extern DataObject 	iedModel_MES_MMXU6_A;
extern DataObject 	iedModel_MES_MMXU6_A_In;
extern DataAttribute iedModel_MES_MMXU6_A_In_cVal;
extern DataAttribute iedModel_MES_MMXU6_A_In_cVal_mag;
extern DataAttribute iedModel_MES_MMXU6_A_In_cVal_mag_f;
extern DataAttribute iedModel_MES_MMXU6_A_In_instCVal;
extern DataAttribute iedModel_MES_MMXU6_A_In_instCVal_mag;
extern DataAttribute iedModel_MES_MMXU6_A_In_instCVal_mag_f;
extern DataAttribute iedModel_MES_MMXU6_A_In_q;
extern DataAttribute iedModel_MES_MMXU6_A_In_t;
extern DataAttribute iedModel_MES_MMXU6_A_In_db;
extern DataAttribute iedModel_MES_MMXU6_A_In_zeroDb;
*/
#endif
//****************************************************************************
// LN iPTOC1
extern LogicalNode   iedModel_PROT_IPTOC1;

extern DataObject    iedModel_PROT_IPTOC1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC1_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC1_Mod_stVal;

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
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC1_Str;
extern DataAttribute iedModel_PROT_IPTOC1_Str_general;
extern DataAttribute iedModel_PROT_IPTOC1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC1_Str_q;
extern DataAttribute iedModel_PROT_IPTOC1_Str_t;

extern DataObject    iedModel_PROT_IPTOC1_Op;
extern DataAttribute iedModel_PROT_IPTOC1_Op_general;
extern DataAttribute iedModel_PROT_IPTOC1_Op_q;
extern DataAttribute iedModel_PROT_IPTOC1_Op_t;

// LN iPTOC1
extern LogicalNode   iedModel_PROT_IPTOC2;

extern DataObject    iedModel_PROT_IPTOC2_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC2_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC2_Mod_stVal;

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
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC2_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC2_Str;
extern DataAttribute iedModel_PROT_IPTOC2_Str_general;
extern DataAttribute iedModel_PROT_IPTOC2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC2_Str_q;
extern DataAttribute iedModel_PROT_IPTOC2_Str_t;

extern DataObject    iedModel_PROT_IPTOC2_Op;
extern DataAttribute iedModel_PROT_IPTOC2_Op_general;
extern DataAttribute iedModel_PROT_IPTOC2_Op_q;
extern DataAttribute iedModel_PROT_IPTOC2_Op_t;

// LN iPTOC1
extern LogicalNode   iedModel_PROT_IPTOC3;

extern DataObject    iedModel_PROT_IPTOC3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC3_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC3_Mod_stVal;

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
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC3_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC3_Str;
extern DataAttribute iedModel_PROT_IPTOC3_Str_general;
extern DataAttribute iedModel_PROT_IPTOC3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC3_Str_q;
extern DataAttribute iedModel_PROT_IPTOC3_Str_t;

extern DataObject    iedModel_PROT_IPTOC3_Op;
extern DataAttribute iedModel_PROT_IPTOC3_Op_general;
extern DataAttribute iedModel_PROT_IPTOC3_Op_q;
extern DataAttribute iedModel_PROT_IPTOC3_Op_t;

// LN IPTOC4
extern LogicalNode   iedModel_PROT_IPTOC4;

extern DataObject    iedModel_PROT_IPTOC4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC4_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC4_Mod_stVal;

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
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC4_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC4_Str;
extern DataAttribute iedModel_PROT_IPTOC4_Str_general;
extern DataAttribute iedModel_PROT_IPTOC4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC4_Str_q;
extern DataAttribute iedModel_PROT_IPTOC4_Str_t;

extern DataObject    iedModel_PROT_IPTOC4_Op;
extern DataAttribute iedModel_PROT_IPTOC4_Op_general;
extern DataAttribute iedModel_PROT_IPTOC4_Op_q;
extern DataAttribute iedModel_PROT_IPTOC4_Op_t;


// LN IPTOC5
extern LogicalNode   iedModel_PROT_IPTOC5;

extern DataObject    iedModel_PROT_IPTOC5_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC5_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC5_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC5_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC5_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC5_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC5_Beh_t;

extern DataObject    iedModel_PROT_IPTOC5_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC5_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC5_Health_q;
extern DataAttribute iedModel_PROT_IPTOC5_Health_t;

extern DataObject    iedModel_PROT_IPTOC5_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC5_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC5_Str;
extern DataAttribute iedModel_PROT_IPTOC5_Str_general;
extern DataAttribute iedModel_PROT_IPTOC5_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC5_Str_q;
extern DataAttribute iedModel_PROT_IPTOC5_Str_t;

extern DataObject    iedModel_PROT_IPTOC5_Op;
extern DataAttribute iedModel_PROT_IPTOC5_Op_general;
extern DataAttribute iedModel_PROT_IPTOC5_Op_q;
extern DataAttribute iedModel_PROT_IPTOC5_Op_t;


// LN IPTOC6
extern LogicalNode   iedModel_PROT_IPTOC6;

extern DataObject    iedModel_PROT_IPTOC6_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC6_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC6_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC6_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC6_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC6_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC6_Beh_t;

extern DataObject    iedModel_PROT_IPTOC6_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC6_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC6_Health_q;
extern DataAttribute iedModel_PROT_IPTOC6_Health_t;

extern DataObject    iedModel_PROT_IPTOC6_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC6_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC6_Str;
extern DataAttribute iedModel_PROT_IPTOC6_Str_general;
extern DataAttribute iedModel_PROT_IPTOC6_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC6_Str_q;
extern DataAttribute iedModel_PROT_IPTOC6_Str_t;

extern DataObject    iedModel_PROT_IPTOC6_Op;
extern DataAttribute iedModel_PROT_IPTOC6_Op_general;
extern DataAttribute iedModel_PROT_IPTOC6_Op_q;
extern DataAttribute iedModel_PROT_IPTOC6_Op_t;


// LN IPTOC7
extern LogicalNode   iedModel_PROT_IPTOC7;

extern DataObject    iedModel_PROT_IPTOC7_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC7_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC7_Mod_stVal;

extern DataObject    iedModel_PROT_IPTOC7_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC7_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC7_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC7_Beh_t;

extern DataObject    iedModel_PROT_IPTOC7_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC7_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC7_Health_q;
extern DataAttribute iedModel_PROT_IPTOC7_Health_t;

extern DataObject    iedModel_PROT_IPTOC7_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC7_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC7_Str;
extern DataAttribute iedModel_PROT_IPTOC7_Str_general;
extern DataAttribute iedModel_PROT_IPTOC7_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC7_Str_q;
extern DataAttribute iedModel_PROT_IPTOC7_Str_t;

extern DataObject    iedModel_PROT_IPTOC7_Op;
extern DataAttribute iedModel_PROT_IPTOC7_Op_general;
extern DataAttribute iedModel_PROT_IPTOC7_Op_q;
extern DataAttribute iedModel_PROT_IPTOC7_Op_t;


//----------------------------------------------------------------------------
// IPTOC8
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC8;
extern DataObject    iedModel_PROT_IPTOC8_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC8_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC8_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC8_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC8_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC8_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC8_Beh_t;
extern DataObject    iedModel_PROT_IPTOC8_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC8_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC8_Health_q;
extern DataAttribute iedModel_PROT_IPTOC8_Health_t;
extern DataObject    iedModel_PROT_IPTOC8_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC8_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC8_Str;
extern DataAttribute iedModel_PROT_IPTOC8_Str_general;
extern DataAttribute iedModel_PROT_IPTOC8_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC8_Str_q;
extern DataAttribute iedModel_PROT_IPTOC8_Str_t;
extern DataObject    iedModel_PROT_IPTOC8_Op;
extern DataAttribute iedModel_PROT_IPTOC8_Op_general;
extern DataAttribute iedModel_PROT_IPTOC8_Op_q;
extern DataAttribute iedModel_PROT_IPTOC8_Op_t;
//----------------------------------------------------------------------------
// IPTOC9
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC9;
extern DataObject    iedModel_PROT_IPTOC9_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC9_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC9_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC9_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC9_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC9_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC9_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC9_Beh_t;
extern DataObject    iedModel_PROT_IPTOC9_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC9_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC9_Health_q;
extern DataAttribute iedModel_PROT_IPTOC9_Health_t;
extern DataObject    iedModel_PROT_IPTOC9_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC9_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC9_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC9_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC9_Str;
extern DataAttribute iedModel_PROT_IPTOC9_Str_general;
extern DataAttribute iedModel_PROT_IPTOC9_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC9_Str_q;
extern DataAttribute iedModel_PROT_IPTOC9_Str_t;
extern DataObject    iedModel_PROT_IPTOC9_Op;
extern DataAttribute iedModel_PROT_IPTOC9_Op_general;
extern DataAttribute iedModel_PROT_IPTOC9_Op_q;
extern DataAttribute iedModel_PROT_IPTOC9_Op_t;
//----------------------------------------------------------------------------
// IPTOC10
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC10;
extern DataObject    iedModel_PROT_IPTOC10_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC10_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC10_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC10_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC10_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC10_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC10_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC10_Beh_t;
extern DataObject    iedModel_PROT_IPTOC10_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC10_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC10_Health_q;
extern DataAttribute iedModel_PROT_IPTOC10_Health_t;
extern DataObject    iedModel_PROT_IPTOC10_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC10_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC10_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC10_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC10_Str;
extern DataAttribute iedModel_PROT_IPTOC10_Str_general;
extern DataAttribute iedModel_PROT_IPTOC10_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC10_Str_q;
extern DataAttribute iedModel_PROT_IPTOC10_Str_t;
extern DataObject    iedModel_PROT_IPTOC10_Op;
extern DataAttribute iedModel_PROT_IPTOC10_Op_general;
extern DataAttribute iedModel_PROT_IPTOC10_Op_q;
extern DataAttribute iedModel_PROT_IPTOC10_Op_t;
//----------------------------------------------------------------------------
// IPTOC11
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC11;
extern DataObject    iedModel_PROT_IPTOC11_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC11_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC11_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC11_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC11_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC11_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC11_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC11_Beh_t;
extern DataObject    iedModel_PROT_IPTOC11_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC11_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC11_Health_q;
extern DataAttribute iedModel_PROT_IPTOC11_Health_t;
extern DataObject    iedModel_PROT_IPTOC11_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC11_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC11_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC11_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC11_Str;
extern DataAttribute iedModel_PROT_IPTOC11_Str_general;
extern DataAttribute iedModel_PROT_IPTOC11_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC11_Str_q;
extern DataAttribute iedModel_PROT_IPTOC11_Str_t;
extern DataObject    iedModel_PROT_IPTOC11_Op;
extern DataAttribute iedModel_PROT_IPTOC11_Op_general;
extern DataAttribute iedModel_PROT_IPTOC11_Op_q;
extern DataAttribute iedModel_PROT_IPTOC11_Op_t;
//----------------------------------------------------------------------------
// IPTOC12
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC12;
extern DataObject    iedModel_PROT_IPTOC12_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC12_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC12_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC12_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC12_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC12_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC12_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC12_Beh_t;
extern DataObject    iedModel_PROT_IPTOC12_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC12_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC12_Health_q;
extern DataAttribute iedModel_PROT_IPTOC12_Health_t;
extern DataObject    iedModel_PROT_IPTOC12_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC12_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC12_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC12_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC12_Str;
extern DataAttribute iedModel_PROT_IPTOC12_Str_general;
extern DataAttribute iedModel_PROT_IPTOC12_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC12_Str_q;
extern DataAttribute iedModel_PROT_IPTOC12_Str_t;
extern DataObject    iedModel_PROT_IPTOC12_Op;
extern DataAttribute iedModel_PROT_IPTOC12_Op_general;
extern DataAttribute iedModel_PROT_IPTOC12_Op_q;
extern DataAttribute iedModel_PROT_IPTOC12_Op_t;
//----------------------------------------------------------------------------
// IPTOC13
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC13;
extern DataObject    iedModel_PROT_IPTOC13_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC13_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC13_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC13_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC13_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC13_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC13_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC13_Beh_t;
extern DataObject    iedModel_PROT_IPTOC13_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC13_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC13_Health_q;
extern DataAttribute iedModel_PROT_IPTOC13_Health_t;
extern DataObject    iedModel_PROT_IPTOC13_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC13_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC13_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC13_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC13_Str;
extern DataAttribute iedModel_PROT_IPTOC13_Str_general;
extern DataAttribute iedModel_PROT_IPTOC13_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC13_Str_q;
extern DataAttribute iedModel_PROT_IPTOC13_Str_t;
extern DataObject    iedModel_PROT_IPTOC13_Op;
extern DataAttribute iedModel_PROT_IPTOC13_Op_general;
extern DataAttribute iedModel_PROT_IPTOC13_Op_q;
extern DataAttribute iedModel_PROT_IPTOC13_Op_t;
//----------------------------------------------------------------------------
// IPTOC14
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC14;
extern DataObject    iedModel_PROT_IPTOC14_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC14_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC14_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC14_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC14_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC14_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC14_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC14_Beh_t;
extern DataObject    iedModel_PROT_IPTOC14_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC14_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC14_Health_q;
extern DataAttribute iedModel_PROT_IPTOC14_Health_t;
extern DataObject    iedModel_PROT_IPTOC14_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC14_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC14_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC14_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC14_Str;
extern DataAttribute iedModel_PROT_IPTOC14_Str_general;
extern DataAttribute iedModel_PROT_IPTOC14_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC14_Str_q;
extern DataAttribute iedModel_PROT_IPTOC14_Str_t;
extern DataObject    iedModel_PROT_IPTOC14_Op;
extern DataAttribute iedModel_PROT_IPTOC14_Op_general;
extern DataAttribute iedModel_PROT_IPTOC14_Op_q;
extern DataAttribute iedModel_PROT_IPTOC14_Op_t;
//----------------------------------------------------------------------------
// IPTOC15
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC15;
extern DataObject    iedModel_PROT_IPTOC15_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC15_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC15_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC15_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC15_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC15_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC15_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC15_Beh_t;
extern DataObject    iedModel_PROT_IPTOC15_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC15_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC15_Health_q;
extern DataAttribute iedModel_PROT_IPTOC15_Health_t;
extern DataObject    iedModel_PROT_IPTOC15_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC15_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC15_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC15_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC15_Str;
extern DataAttribute iedModel_PROT_IPTOC15_Str_general;
extern DataAttribute iedModel_PROT_IPTOC15_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC15_Str_q;
extern DataAttribute iedModel_PROT_IPTOC15_Str_t;
extern DataObject    iedModel_PROT_IPTOC15_Op;
extern DataAttribute iedModel_PROT_IPTOC15_Op_general;
extern DataAttribute iedModel_PROT_IPTOC15_Op_q;
extern DataAttribute iedModel_PROT_IPTOC15_Op_t;
//----------------------------------------------------------------------------
// IPTOC16
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC16;
extern DataObject    iedModel_PROT_IPTOC16_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC16_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC16_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC16_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC16_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC16_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC16_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC16_Beh_t;
extern DataObject    iedModel_PROT_IPTOC16_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC16_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC16_Health_q;
extern DataAttribute iedModel_PROT_IPTOC16_Health_t;
extern DataObject    iedModel_PROT_IPTOC16_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC16_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC16_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC16_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC16_Str;
extern DataAttribute iedModel_PROT_IPTOC16_Str_general;
extern DataAttribute iedModel_PROT_IPTOC16_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC16_Str_q;
extern DataAttribute iedModel_PROT_IPTOC16_Str_t;
extern DataObject    iedModel_PROT_IPTOC16_Op;
extern DataAttribute iedModel_PROT_IPTOC16_Op_general;
extern DataAttribute iedModel_PROT_IPTOC16_Op_q;
extern DataAttribute iedModel_PROT_IPTOC16_Op_t;
//----------------------------------------------------------------------------
// IPTOC17
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC17;
extern DataObject    iedModel_PROT_IPTOC17_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC17_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC17_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC17_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC17_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC17_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC17_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC17_Beh_t;
extern DataObject    iedModel_PROT_IPTOC17_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC17_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC17_Health_q;
extern DataAttribute iedModel_PROT_IPTOC17_Health_t;
extern DataObject    iedModel_PROT_IPTOC17_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC17_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC17_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC17_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC17_Str;
extern DataAttribute iedModel_PROT_IPTOC17_Str_general;
extern DataAttribute iedModel_PROT_IPTOC17_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC17_Str_q;
extern DataAttribute iedModel_PROT_IPTOC17_Str_t;
extern DataObject    iedModel_PROT_IPTOC17_Op;
extern DataAttribute iedModel_PROT_IPTOC17_Op_general;
extern DataAttribute iedModel_PROT_IPTOC17_Op_q;
extern DataAttribute iedModel_PROT_IPTOC17_Op_t;
//----------------------------------------------------------------------------
// IPTOC18
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC18;
extern DataObject    iedModel_PROT_IPTOC18_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC18_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC18_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC18_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC18_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC18_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC18_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC18_Beh_t;
extern DataObject    iedModel_PROT_IPTOC18_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC18_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC18_Health_q;
extern DataAttribute iedModel_PROT_IPTOC18_Health_t;
extern DataObject    iedModel_PROT_IPTOC18_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC18_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC18_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC18_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC18_Str;
extern DataAttribute iedModel_PROT_IPTOC18_Str_general;
extern DataAttribute iedModel_PROT_IPTOC18_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC18_Str_q;
extern DataAttribute iedModel_PROT_IPTOC18_Str_t;
extern DataObject    iedModel_PROT_IPTOC18_Op;
extern DataAttribute iedModel_PROT_IPTOC18_Op_general;
extern DataAttribute iedModel_PROT_IPTOC18_Op_q;
extern DataAttribute iedModel_PROT_IPTOC18_Op_t;
//----------------------------------------------------------------------------
// IPTOC19
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC19;
extern DataObject    iedModel_PROT_IPTOC19_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC19_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC19_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC19_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC19_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC19_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC19_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC19_Beh_t;
extern DataObject    iedModel_PROT_IPTOC19_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC19_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC19_Health_q;
extern DataAttribute iedModel_PROT_IPTOC19_Health_t;
extern DataObject    iedModel_PROT_IPTOC19_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC19_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC19_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC19_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC19_Str;
extern DataAttribute iedModel_PROT_IPTOC19_Str_general;
extern DataAttribute iedModel_PROT_IPTOC19_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC19_Str_q;
extern DataAttribute iedModel_PROT_IPTOC19_Str_t;
extern DataObject    iedModel_PROT_IPTOC19_Op;
extern DataAttribute iedModel_PROT_IPTOC19_Op_general;
extern DataAttribute iedModel_PROT_IPTOC19_Op_q;
extern DataAttribute iedModel_PROT_IPTOC19_Op_t;
//----------------------------------------------------------------------------
// IPTOC20
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC20;
extern DataObject    iedModel_PROT_IPTOC20_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC20_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC20_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC20_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC20_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC20_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC20_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC20_Beh_t;
extern DataObject    iedModel_PROT_IPTOC20_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC20_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC20_Health_q;
extern DataAttribute iedModel_PROT_IPTOC20_Health_t;
extern DataObject    iedModel_PROT_IPTOC20_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC20_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC20_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC20_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC20_Str;
extern DataAttribute iedModel_PROT_IPTOC20_Str_general;
extern DataAttribute iedModel_PROT_IPTOC20_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC20_Str_q;
extern DataAttribute iedModel_PROT_IPTOC20_Str_t;
extern DataObject    iedModel_PROT_IPTOC20_Op;
extern DataAttribute iedModel_PROT_IPTOC20_Op_general;
extern DataAttribute iedModel_PROT_IPTOC20_Op_q;
extern DataAttribute iedModel_PROT_IPTOC20_Op_t;
//----------------------------------------------------------------------------
// IPTOC21
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC21;
extern DataObject    iedModel_PROT_IPTOC21_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC21_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC21_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC21_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC21_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC21_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC21_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC21_Beh_t;
extern DataObject    iedModel_PROT_IPTOC21_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC21_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC21_Health_q;
extern DataAttribute iedModel_PROT_IPTOC21_Health_t;
extern DataObject    iedModel_PROT_IPTOC21_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC21_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC21_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC21_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC21_Str;
extern DataAttribute iedModel_PROT_IPTOC21_Str_general;
extern DataAttribute iedModel_PROT_IPTOC21_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC21_Str_q;
extern DataAttribute iedModel_PROT_IPTOC21_Str_t;
extern DataObject    iedModel_PROT_IPTOC21_Op;
extern DataAttribute iedModel_PROT_IPTOC21_Op_general;
extern DataAttribute iedModel_PROT_IPTOC21_Op_q;
extern DataAttribute iedModel_PROT_IPTOC21_Op_t;
//----------------------------------------------------------------------------
// IPTOC22
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC22;
extern DataObject    iedModel_PROT_IPTOC22_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC22_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC22_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC22_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC22_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC22_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC22_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC22_Beh_t;
extern DataObject    iedModel_PROT_IPTOC22_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC22_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC22_Health_q;
extern DataAttribute iedModel_PROT_IPTOC22_Health_t;
extern DataObject    iedModel_PROT_IPTOC22_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC22_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC22_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC22_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC22_Str;
extern DataAttribute iedModel_PROT_IPTOC22_Str_general;
extern DataAttribute iedModel_PROT_IPTOC22_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC22_Str_q;
extern DataAttribute iedModel_PROT_IPTOC22_Str_t;
extern DataObject    iedModel_PROT_IPTOC22_Op;
extern DataAttribute iedModel_PROT_IPTOC22_Op_general;
extern DataAttribute iedModel_PROT_IPTOC22_Op_q;
extern DataAttribute iedModel_PROT_IPTOC22_Op_t;
//----------------------------------------------------------------------------
// IPTOC23
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC23;
extern DataObject    iedModel_PROT_IPTOC23_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC23_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC23_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC23_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC23_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC23_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC23_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC23_Beh_t;
extern DataObject    iedModel_PROT_IPTOC23_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC23_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC23_Health_q;
extern DataAttribute iedModel_PROT_IPTOC23_Health_t;
extern DataObject    iedModel_PROT_IPTOC23_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC23_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC23_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC23_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC23_Str;
extern DataAttribute iedModel_PROT_IPTOC23_Str_general;
extern DataAttribute iedModel_PROT_IPTOC23_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC23_Str_q;
extern DataAttribute iedModel_PROT_IPTOC23_Str_t;
extern DataObject    iedModel_PROT_IPTOC23_Op;
extern DataAttribute iedModel_PROT_IPTOC23_Op_general;
extern DataAttribute iedModel_PROT_IPTOC23_Op_q;
extern DataAttribute iedModel_PROT_IPTOC23_Op_t;
//----------------------------------------------------------------------------
// IPTOC24
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC24;
extern DataObject    iedModel_PROT_IPTOC24_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC24_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC24_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC24_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC24_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC24_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC24_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC24_Beh_t;
extern DataObject    iedModel_PROT_IPTOC24_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC24_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC24_Health_q;
extern DataAttribute iedModel_PROT_IPTOC24_Health_t;
extern DataObject    iedModel_PROT_IPTOC24_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC24_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC24_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC24_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC24_Str;
extern DataAttribute iedModel_PROT_IPTOC24_Str_general;
extern DataAttribute iedModel_PROT_IPTOC24_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC24_Str_q;
extern DataAttribute iedModel_PROT_IPTOC24_Str_t;
extern DataObject    iedModel_PROT_IPTOC24_Op;
extern DataAttribute iedModel_PROT_IPTOC24_Op_general;
extern DataAttribute iedModel_PROT_IPTOC24_Op_q;
extern DataAttribute iedModel_PROT_IPTOC24_Op_t;
//----------------------------------------------------------------------------
// IPTOC25
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC25;
extern DataObject    iedModel_PROT_IPTOC25_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC25_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC25_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC25_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC25_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC25_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC25_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC25_Beh_t;
extern DataObject    iedModel_PROT_IPTOC25_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC25_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC25_Health_q;
extern DataAttribute iedModel_PROT_IPTOC25_Health_t;
extern DataObject    iedModel_PROT_IPTOC25_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC25_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC25_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC25_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC25_Str;
extern DataAttribute iedModel_PROT_IPTOC25_Str_general;
extern DataAttribute iedModel_PROT_IPTOC25_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC25_Str_q;
extern DataAttribute iedModel_PROT_IPTOC25_Str_t;
extern DataObject    iedModel_PROT_IPTOC25_Op;
extern DataAttribute iedModel_PROT_IPTOC25_Op_general;
extern DataAttribute iedModel_PROT_IPTOC25_Op_q;
extern DataAttribute iedModel_PROT_IPTOC25_Op_t;
//----------------------------------------------------------------------------
// IPTOC26
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC26;
extern DataObject    iedModel_PROT_IPTOC26_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC26_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC26_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC26_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC26_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC26_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC26_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC26_Beh_t;
extern DataObject    iedModel_PROT_IPTOC26_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC26_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC26_Health_q;
extern DataAttribute iedModel_PROT_IPTOC26_Health_t;
extern DataObject    iedModel_PROT_IPTOC26_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC26_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC26_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC26_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC26_Str;
extern DataAttribute iedModel_PROT_IPTOC26_Str_general;
extern DataAttribute iedModel_PROT_IPTOC26_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC26_Str_q;
extern DataAttribute iedModel_PROT_IPTOC26_Str_t;
extern DataObject    iedModel_PROT_IPTOC26_Op;
extern DataAttribute iedModel_PROT_IPTOC26_Op_general;
extern DataAttribute iedModel_PROT_IPTOC26_Op_q;
extern DataAttribute iedModel_PROT_IPTOC26_Op_t;
//----------------------------------------------------------------------------
// IPTOC27
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC27;
extern DataObject    iedModel_PROT_IPTOC27_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC27_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC27_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC27_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC27_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC27_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC27_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC27_Beh_t;
extern DataObject    iedModel_PROT_IPTOC27_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC27_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC27_Health_q;
extern DataAttribute iedModel_PROT_IPTOC27_Health_t;
extern DataObject    iedModel_PROT_IPTOC27_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC27_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC27_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC27_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC27_Str;
extern DataAttribute iedModel_PROT_IPTOC27_Str_general;
extern DataAttribute iedModel_PROT_IPTOC27_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC27_Str_q;
extern DataAttribute iedModel_PROT_IPTOC27_Str_t;
extern DataObject    iedModel_PROT_IPTOC27_Op;
extern DataAttribute iedModel_PROT_IPTOC27_Op_general;
extern DataAttribute iedModel_PROT_IPTOC27_Op_q;
extern DataAttribute iedModel_PROT_IPTOC27_Op_t;
//----------------------------------------------------------------------------
// IPTOC28
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC28;
extern DataObject    iedModel_PROT_IPTOC28_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC28_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC28_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC28_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC28_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC28_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC28_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC28_Beh_t;
extern DataObject    iedModel_PROT_IPTOC28_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC28_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC28_Health_q;
extern DataAttribute iedModel_PROT_IPTOC28_Health_t;
extern DataObject    iedModel_PROT_IPTOC28_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC28_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC28_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC28_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC28_Str;
extern DataAttribute iedModel_PROT_IPTOC28_Str_general;
extern DataAttribute iedModel_PROT_IPTOC28_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC28_Str_q;
extern DataAttribute iedModel_PROT_IPTOC28_Str_t;
extern DataObject    iedModel_PROT_IPTOC28_Op;
extern DataAttribute iedModel_PROT_IPTOC28_Op_general;
extern DataAttribute iedModel_PROT_IPTOC28_Op_q;
extern DataAttribute iedModel_PROT_IPTOC28_Op_t;
//----------------------------------------------------------------------------
// IPTOC29
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC29;
extern DataObject    iedModel_PROT_IPTOC29_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC29_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC29_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC29_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC29_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC29_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC29_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC29_Beh_t;
extern DataObject    iedModel_PROT_IPTOC29_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC29_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC29_Health_q;
extern DataAttribute iedModel_PROT_IPTOC29_Health_t;
extern DataObject    iedModel_PROT_IPTOC29_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC29_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC29_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC29_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC29_Str;
extern DataAttribute iedModel_PROT_IPTOC29_Str_general;
extern DataAttribute iedModel_PROT_IPTOC29_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC29_Str_q;
extern DataAttribute iedModel_PROT_IPTOC29_Str_t;
extern DataObject    iedModel_PROT_IPTOC29_Op;
extern DataAttribute iedModel_PROT_IPTOC29_Op_general;
extern DataAttribute iedModel_PROT_IPTOC29_Op_q;
extern DataAttribute iedModel_PROT_IPTOC29_Op_t;
//----------------------------------------------------------------------------
// IPTOC30
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC30;
extern DataObject    iedModel_PROT_IPTOC30_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC30_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC30_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC30_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC30_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC30_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC30_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC30_Beh_t;
extern DataObject    iedModel_PROT_IPTOC30_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC30_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC30_Health_q;
extern DataAttribute iedModel_PROT_IPTOC30_Health_t;
extern DataObject    iedModel_PROT_IPTOC30_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC30_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC30_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC30_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC30_Str;
extern DataAttribute iedModel_PROT_IPTOC30_Str_general;
extern DataAttribute iedModel_PROT_IPTOC30_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC30_Str_q;
extern DataAttribute iedModel_PROT_IPTOC30_Str_t;
extern DataObject    iedModel_PROT_IPTOC30_Op;
extern DataAttribute iedModel_PROT_IPTOC30_Op_general;
extern DataAttribute iedModel_PROT_IPTOC30_Op_q;
extern DataAttribute iedModel_PROT_IPTOC30_Op_t;
//----------------------------------------------------------------------------
// IPTOC31
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC31;
extern DataObject    iedModel_PROT_IPTOC31_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC31_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC31_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC31_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC31_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC31_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC31_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC31_Beh_t;
extern DataObject    iedModel_PROT_IPTOC31_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC31_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC31_Health_q;
extern DataAttribute iedModel_PROT_IPTOC31_Health_t;
extern DataObject    iedModel_PROT_IPTOC31_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC31_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC31_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC31_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC31_Str;
extern DataAttribute iedModel_PROT_IPTOC31_Str_general;
extern DataAttribute iedModel_PROT_IPTOC31_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC31_Str_q;
extern DataAttribute iedModel_PROT_IPTOC31_Str_t;
extern DataObject    iedModel_PROT_IPTOC31_Op;
extern DataAttribute iedModel_PROT_IPTOC31_Op_general;
extern DataAttribute iedModel_PROT_IPTOC31_Op_q;
extern DataAttribute iedModel_PROT_IPTOC31_Op_t;
//----------------------------------------------------------------------------
// IPTOC32
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_PROT_IPTOC32;
extern DataObject    iedModel_PROT_IPTOC32_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_IPTOC32_Mod_q;
extern DataAttribute iedModel_PROT_IPTOC32_Mod_t;
extern DataAttribute iedModel_PROT_IPTOC32_Mod_stVal;
extern DataObject    iedModel_PROT_IPTOC32_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_IPTOC32_Beh_stVal;
extern DataAttribute iedModel_PROT_IPTOC32_Beh_q;
extern DataAttribute iedModel_PROT_IPTOC32_Beh_t;
extern DataObject    iedModel_PROT_IPTOC32_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_IPTOC32_Health_stVal;
extern DataAttribute iedModel_PROT_IPTOC32_Health_q;
extern DataAttribute iedModel_PROT_IPTOC32_Health_t;
extern DataObject    iedModel_PROT_IPTOC32_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_IPTOC32_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_IPTOC32_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_PROT_IPTOC32_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_IPTOC32_Str;
extern DataAttribute iedModel_PROT_IPTOC32_Str_general;
extern DataAttribute iedModel_PROT_IPTOC32_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IPTOC32_Str_q;
extern DataAttribute iedModel_PROT_IPTOC32_Str_t;
extern DataObject    iedModel_PROT_IPTOC32_Op;
extern DataAttribute iedModel_PROT_IPTOC32_Op_general;
extern DataAttribute iedModel_PROT_IPTOC32_Op_q;
extern DataAttribute iedModel_PROT_IPTOC32_Op_t;

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
extern DataAttribute iedModel_PROT_IGPTOC_Str_dirGeneral;
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
* LN
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
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV3;

extern DataObject    iedModel_PROT_UPTOV3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTOV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTOV3_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTOV3_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV3_Beh_t;

extern DataObject    iedModel_PROT_UPTOV3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTOV3_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV3_Health_q;
extern DataAttribute iedModel_PROT_UPTOV3_Health_t;

extern DataObject    iedModel_PROT_UPTOV3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTOV3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV3_Str;
extern DataAttribute iedModel_PROT_UPTOV3_Str_general;
extern DataAttribute iedModel_PROT_UPTOV3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV3_Str_q;
extern DataAttribute iedModel_PROT_UPTOV3_Str_t;

extern DataObject    iedModel_PROT_UPTOV3_Op;
extern DataAttribute iedModel_PROT_UPTOV3_Op_general;
extern DataAttribute iedModel_PROT_UPTOV3_Op_q;
extern DataAttribute iedModel_PROT_UPTOV3_Op_t;


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTOV4;

extern DataObject    iedModel_PROT_UPTOV4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTOV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTOV4_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTOV4_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Beh_q;
extern DataAttribute iedModel_PROT_UPTOV4_Beh_t;

extern DataObject    iedModel_PROT_UPTOV4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTOV4_Health_stVal;
extern DataAttribute iedModel_PROT_UPTOV4_Health_q;
extern DataAttribute iedModel_PROT_UPTOV4_Health_t;

extern DataObject    iedModel_PROT_UPTOV4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTOV4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTOV4_Str;
extern DataAttribute iedModel_PROT_UPTOV4_Str_general;
extern DataAttribute iedModel_PROT_UPTOV4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTOV4_Str_q;
extern DataAttribute iedModel_PROT_UPTOV4_Str_t;

extern DataObject    iedModel_PROT_UPTOV4_Op;
extern DataAttribute iedModel_PROT_UPTOV4_Op_general;
extern DataAttribute iedModel_PROT_UPTOV4_Op_q;
extern DataAttribute iedModel_PROT_UPTOV4_Op_t;

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
* LN
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
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV3;

extern DataObject    iedModel_PROT_UPTUV3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTUV3_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTUV3_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTUV3_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV3_Beh_t;

extern DataObject    iedModel_PROT_UPTUV3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTUV3_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV3_Health_q;
extern DataAttribute iedModel_PROT_UPTUV3_Health_t;

extern DataObject    iedModel_PROT_UPTUV3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTUV3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV3_Str;
extern DataAttribute iedModel_PROT_UPTUV3_Str_general;
extern DataAttribute iedModel_PROT_UPTUV3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV3_Str_q;
extern DataAttribute iedModel_PROT_UPTUV3_Str_t;

extern DataObject    iedModel_PROT_UPTUV3_Op;
extern DataAttribute iedModel_PROT_UPTUV3_Op_general;
extern DataAttribute iedModel_PROT_UPTUV3_Op_q;
extern DataAttribute iedModel_PROT_UPTUV3_Op_t;


/****************************************************************
* LN
*****************************************************************/
extern LogicalNode   iedModel_PROT_UPTUV4;

extern DataObject    iedModel_PROT_UPTUV4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_UPTUV4_Mod_q;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_t;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Mod_ctlModel;

extern DataObject    iedModel_PROT_UPTUV4_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_UPTUV4_Beh_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Beh_q;
extern DataAttribute iedModel_PROT_UPTUV4_Beh_t;

extern DataObject    iedModel_PROT_UPTUV4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_UPTUV4_Health_stVal;
extern DataAttribute iedModel_PROT_UPTUV4_Health_q;
extern DataAttribute iedModel_PROT_UPTUV4_Health_t;

extern DataObject    iedModel_PROT_UPTUV4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_UPTUV4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_UPTUV4_Str;
extern DataAttribute iedModel_PROT_UPTUV4_Str_general;
extern DataAttribute iedModel_PROT_UPTUV4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_UPTUV4_Str_q;
extern DataAttribute iedModel_PROT_UPTUV4_Str_t;

extern DataObject    iedModel_PROT_UPTUV4_Op;
extern DataAttribute iedModel_PROT_UPTUV4_Op_general;
extern DataAttribute iedModel_PROT_UPTUV4_Op_q;
extern DataAttribute iedModel_PROT_UPTUV4_Op_t;

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
extern LogicalNode   iedModel_PROT_PTOF3;

extern DataObject    iedModel_PROT_PTOF3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTOF3_Mod_q;
extern DataAttribute iedModel_PROT_PTOF3_Mod_t;
extern DataAttribute iedModel_PROT_PTOF3_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTOF3_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTOF3_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Beh_q;
extern DataAttribute iedModel_PROT_PTOF3_Beh_t;

extern DataObject    iedModel_PROT_PTOF3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTOF3_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF3_Health_q;
extern DataAttribute iedModel_PROT_PTOF3_Health_t;

extern DataObject    iedModel_PROT_PTOF3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTOF3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTOF3_Str;
extern DataAttribute iedModel_PROT_PTOF3_Str_general;
extern DataAttribute iedModel_PROT_PTOF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF3_Str_q;
extern DataAttribute iedModel_PROT_PTOF3_Str_t;

extern DataObject    iedModel_PROT_PTOF3_Op;
extern DataAttribute iedModel_PROT_PTOF3_Op_general;
extern DataAttribute iedModel_PROT_PTOF3_Op_q;
extern DataAttribute iedModel_PROT_PTOF3_Op_t;

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTOF4;

extern DataObject    iedModel_PROT_PTOF4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTOF4_Mod_q;
extern DataAttribute iedModel_PROT_PTOF4_Mod_t;
extern DataAttribute iedModel_PROT_PTOF4_Mod_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTOF4_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTOF4_Beh_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Beh_q;
extern DataAttribute iedModel_PROT_PTOF4_Beh_t;

extern DataObject    iedModel_PROT_PTOF4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTOF4_Health_stVal;
extern DataAttribute iedModel_PROT_PTOF4_Health_q;
extern DataAttribute iedModel_PROT_PTOF4_Health_t;

extern DataObject    iedModel_PROT_PTOF4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTOF4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTOF4_Str;
extern DataAttribute iedModel_PROT_PTOF4_Str_general;
extern DataAttribute iedModel_PROT_PTOF4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTOF4_Str_q;
extern DataAttribute iedModel_PROT_PTOF4_Str_t;

extern DataObject    iedModel_PROT_PTOF4_Op;
extern DataAttribute iedModel_PROT_PTOF4_Op_general;
extern DataAttribute iedModel_PROT_PTOF4_Op_q;
extern DataAttribute iedModel_PROT_PTOF4_Op_t;

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
extern LogicalNode   iedModel_PROT_PTUF3;

extern DataObject    iedModel_PROT_PTUF3_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTUF3_Mod_q;
extern DataAttribute iedModel_PROT_PTUF3_Mod_t;
extern DataAttribute iedModel_PROT_PTUF3_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTUF3_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTUF3_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Beh_q;
extern DataAttribute iedModel_PROT_PTUF3_Beh_t;

extern DataObject    iedModel_PROT_PTUF3_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTUF3_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF3_Health_q;
extern DataAttribute iedModel_PROT_PTUF3_Health_t;

extern DataObject    iedModel_PROT_PTUF3_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTUF3_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTUF3_Str;
extern DataAttribute iedModel_PROT_PTUF3_Str_general;
extern DataAttribute iedModel_PROT_PTUF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF3_Str_q;
extern DataAttribute iedModel_PROT_PTUF3_Str_t;

extern DataObject    iedModel_PROT_PTUF3_Op;
extern DataAttribute iedModel_PROT_PTUF3_Op_general;
extern DataAttribute iedModel_PROT_PTUF3_Op_q;
extern DataAttribute iedModel_PROT_PTUF3_Op_t;

/****************************************************************
*
*****************************************************************/
extern LogicalNode   iedModel_PROT_PTUF4;

extern DataObject    iedModel_PROT_PTUF4_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_PTUF4_Mod_q;
extern DataAttribute iedModel_PROT_PTUF4_Mod_t;
extern DataAttribute iedModel_PROT_PTUF4_Mod_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Mod_ctlModel;

extern DataObject    iedModel_PROT_PTUF4_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_PTUF4_Beh_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Beh_q;
extern DataAttribute iedModel_PROT_PTUF4_Beh_t;

extern DataObject    iedModel_PROT_PTUF4_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_PTUF4_Health_stVal;
extern DataAttribute iedModel_PROT_PTUF4_Health_q;
extern DataAttribute iedModel_PROT_PTUF4_Health_t;

extern DataObject    iedModel_PROT_PTUF4_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_PTUF4_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_PTUF4_Str;
extern DataAttribute iedModel_PROT_PTUF4_Str_general;
extern DataAttribute iedModel_PROT_PTUF4_Str_dirGeneral;
extern DataAttribute iedModel_PROT_PTUF4_Str_q;
extern DataAttribute iedModel_PROT_PTUF4_Str_t;

extern DataObject    iedModel_PROT_PTUF4_Op;
extern DataAttribute iedModel_PROT_PTUF4_Op_general;
extern DataAttribute iedModel_PROT_PTUF4_Op_q;
extern DataAttribute iedModel_PROT_PTUF4_Op_t;

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
extern DataAttribute iedModel_PROT_RREC_AutoRecSt_q;
extern DataAttribute iedModel_PROT_RREC_AutoRecSt_t;

extern DataObject    iedModel_PROT_RREC_Op;
extern DataAttribute iedModel_PROT_RREC_Op_general;
extern DataAttribute iedModel_PROT_RREC_Op_q;
extern DataAttribute iedModel_PROT_RREC_Op_t;

/****************************************************************
* RBRF1
*****************************************************************/
extern LogicalNode   iedModel_PROT_RBRF1;

extern DataObject    iedModel_PROT_RBRF1_Mod;					// РЕЖИМ
extern DataAttribute iedModel_PROT_RBRF1_Mod_q;
extern DataAttribute iedModel_PROT_RBRF1_Mod_t;
extern DataAttribute iedModel_PROT_RBRF1_Mod_stVal;
extern DataAttribute iedModel_PROT_RBRF1_Mod_ctlModel;

extern DataObject    iedModel_PROT_RBRF1_Beh;					// РЕЖИМ РАБОТЫ
extern DataAttribute iedModel_PROT_RBRF1_Beh_stVal;
extern DataAttribute iedModel_PROT_RBRF1_Beh_q;
extern DataAttribute iedModel_PROT_RBRF1_Beh_t;

extern DataObject    iedModel_PROT_RBRF1_Health;				// СОСТОЯНИЕ РАБОТОСПОСОБНОСТИ
extern DataAttribute iedModel_PROT_RBRF1_Health_stVal;
extern DataAttribute iedModel_PROT_RBRF1_Health_q;
extern DataAttribute iedModel_PROT_RBRF1_Health_t;

extern DataObject    iedModel_PROT_RBRF1_NamPlt;				// ПАСПОРТНАЯ ТАБЛИЧКА
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_vendor;		// 		Имя поставщика
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_swRev;			// 		Ревизия программной части
extern DataAttribute iedModel_PROT_RBRF1_NamPlt_d;				//		Текстовое описание данных сдесь относится к логическому узлу LN PTOC1.

extern DataObject    iedModel_PROT_RBRF1_OpEx1;
extern DataAttribute iedModel_PROT_RBRF1_OpEx1_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx1_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx1_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx1_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx2;
extern DataAttribute iedModel_PROT_RBRF1_OpEx2_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx2_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx2_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx2_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx3;
extern DataAttribute iedModel_PROT_RBRF1_OpEx3_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx3_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx3_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx3_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx4;
extern DataAttribute iedModel_PROT_RBRF1_OpEx4_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx4_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx4_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx4_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx5;
extern DataAttribute iedModel_PROT_RBRF1_OpEx5_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx5_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx5_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx5_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx6;
extern DataAttribute iedModel_PROT_RBRF1_OpEx6_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx6_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx6_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx6_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx7;
extern DataAttribute iedModel_PROT_RBRF1_OpEx7_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx7_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx7_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx7_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx8;
extern DataAttribute iedModel_PROT_RBRF1_OpEx8_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx8_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx8_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx8_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx9;
extern DataAttribute iedModel_PROT_RBRF1_OpEx9_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx9_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx9_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx9_dU;

#if defined	(MR901)
extern DataObject    iedModel_PROT_RBRF1_OpEx10;
extern DataAttribute iedModel_PROT_RBRF1_OpEx10_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx10_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx10_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx10_dU;


extern DataObject    iedModel_PROT_RBRF1_OpEx11;
extern DataAttribute iedModel_PROT_RBRF1_OpEx11_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx11_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx11_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx11_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx12;
extern DataAttribute iedModel_PROT_RBRF1_OpEx12_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx12_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx12_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx12_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx13;
extern DataAttribute iedModel_PROT_RBRF1_OpEx13_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx13_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx13_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx13_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx14;
extern DataAttribute iedModel_PROT_RBRF1_OpEx14_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx14_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx14_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx14_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx15;
extern DataAttribute iedModel_PROT_RBRF1_OpEx15_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx15_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx15_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx15_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx16;
extern DataAttribute iedModel_PROT_RBRF1_OpEx16_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx16_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx16_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx16_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx17;
extern DataAttribute iedModel_PROT_RBRF1_OpEx17_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx17_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx17_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx17_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx18;
extern DataAttribute iedModel_PROT_RBRF1_OpEx18_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx18_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx18_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx18_dU;

extern DataObject    iedModel_PROT_RBRF1_OpEx19;
extern DataAttribute iedModel_PROT_RBRF1_OpEx19_general;
extern DataAttribute iedModel_PROT_RBRF1_OpEx19_q;
extern DataAttribute iedModel_PROT_RBRF1_OpEx19_t;
extern DataAttribute iedModel_PROT_RBRF1_OpEx19_dU;
#endif

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

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO9;

extern DataObject iedModel_PROT_VZGGIO9_Mod;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO9_Beh;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Beh_t;

extern DataObject iedModel_PROT_VZGGIO9_Health;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Health_t;

extern DataObject iedModel_PROT_VZGGIO9_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO9_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO9_Alm;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO9_Alm_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO10;

extern DataObject iedModel_PROT_VZGGIO10_Mod;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO10_Beh;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Beh_t;

extern DataObject iedModel_PROT_VZGGIO10_Health;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Health_t;

extern DataObject iedModel_PROT_VZGGIO10_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO10_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO10_Alm;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO10_Alm_t;
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO11;

extern DataObject iedModel_PROT_VZGGIO11_Mod;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO11_Beh;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Beh_t;

extern DataObject iedModel_PROT_VZGGIO11_Health;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Health_t;

extern DataObject iedModel_PROT_VZGGIO11_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO11_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO11_Alm;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO11_Alm_t;
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO12;

extern DataObject iedModel_PROT_VZGGIO12_Mod;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO12_Beh;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Beh_t;

extern DataObject iedModel_PROT_VZGGIO12_Health;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Health_t;

extern DataObject iedModel_PROT_VZGGIO12_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO12_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO12_Alm;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO12_Alm_t;
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO13;

extern DataObject iedModel_PROT_VZGGIO13_Mod;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO13_Beh;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Beh_t;

extern DataObject iedModel_PROT_VZGGIO13_Health;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Health_t;

extern DataObject iedModel_PROT_VZGGIO13_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO13_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO13_Alm;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO13_Alm_t;

//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO14;

extern DataObject iedModel_PROT_VZGGIO14_Mod;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO14_Beh;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Beh_t;

extern DataObject iedModel_PROT_VZGGIO14_Health;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Health_t;

extern DataObject iedModel_PROT_VZGGIO14_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO14_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO14_Alm;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO14_Alm_t;
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO15;

extern DataObject iedModel_PROT_VZGGIO15_Mod;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO15_Beh;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Beh_t;

extern DataObject iedModel_PROT_VZGGIO15_Health;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Health_t;

extern DataObject iedModel_PROT_VZGGIO15_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO15_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO15_Alm;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO15_Alm_t;
//----------------------------------------------------------------------------
extern LogicalNode iedModel_PROT_VZGGIO16;

extern DataObject iedModel_PROT_VZGGIO16_Mod;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_t;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Mod_ctlModel;


extern DataObject iedModel_PROT_VZGGIO16_Beh;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Beh_t;

extern DataObject iedModel_PROT_VZGGIO16_Health;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Health_t;

extern DataObject iedModel_PROT_VZGGIO16_NamPlt;

extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_vendor;
extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_swRev;
extern DataAttribute iedModel_PROT_VZGGIO16_NamPlt_d;

extern DataObject iedModel_PROT_VZGGIO16_Alm;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_stVal;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_q;
extern DataAttribute iedModel_PROT_VZGGIO16_Alm_t;

#if defined (MR902)
//----------------------------------------------------------------------------
// IDPDIF1
extern LogicalNode iedModel_PROT_IDPDIF1;

extern DataObject iedModel_PROT_IDPDIF1_Mod;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal;
//extern DataAttribute iedModel_PROT_IDPDIF1_Mod_ctlModel;

extern DataObject iedModel_PROT_IDPDIF1_Beh;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_t;

extern DataObject iedModel_PROT_IDPDIF1_Health;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_t;

extern DataObject iedModel_PROT_IDPDIF1_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF1_Op;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF1_Str;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_t;

extern DataObject iedModel_PROT_IDPDIF1_RstA;
extern DataObject iedModel_PROT_IDPDIF1_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF1_RstA_phsB;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF1_RstA_phsC;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsC_zeroDb;

extern DataObject iedModel_PROT_IDPDIF1_DifACIc;
extern DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF1_DifACIc_phsB;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF1_DifACIc_phsC;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsC_zeroDb;

//----------------------------------------------------------------------------
// IDPDIF2
extern LogicalNode iedModel_PROT_IDPDIF2;

extern DataObject iedModel_PROT_IDPDIF2_Mod;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal;
//extern DataAttribute iedModel_PROT_IDPDIF2_Mod_ctlModel;

extern DataObject iedModel_PROT_IDPDIF2_Beh;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_t;

extern DataObject iedModel_PROT_IDPDIF2_Health;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_t;

extern DataObject iedModel_PROT_IDPDIF2_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF2_Op;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF2_Str;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_t;

extern DataObject iedModel_PROT_IDPDIF2_RstA;
extern DataObject iedModel_PROT_IDPDIF2_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF2_RstA_phsB;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF2_RstA_phsC;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsC_zeroDb;

extern DataObject iedModel_PROT_IDPDIF2_DifACIc;
extern DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF2_DifACIc_phsB;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF2_DifACIc_phsC;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsC_zeroDb;

//----------------------------------------------------------------------------
// IDPDIF3
extern LogicalNode iedModel_PROT_IDPDIF3;

extern DataObject iedModel_PROT_IDPDIF3_Mod;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal;
//extern DataAttribute iedModel_PROT_IDPDIF3_Mod_ctlModel;

extern DataObject iedModel_PROT_IDPDIF3_Beh;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_t;

extern DataObject iedModel_PROT_IDPDIF3_Health;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_t;

extern DataObject iedModel_PROT_IDPDIF3_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF3_Op;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF3_Str;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_t;

extern DataObject iedModel_PROT_IDPDIF3_RstA;
extern DataObject iedModel_PROT_IDPDIF3_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF3_RstA_phsB;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF3_RstA_phsC;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsC_zeroDb;

extern DataObject iedModel_PROT_IDPDIF3_DifACIc;
extern DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb;
extern DataObject iedModel_PROT_IDPDIF3_DifACIc_phsB;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_q;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_t;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_db;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsB_zeroDb;
extern DataObject iedModel_PROT_IDPDIF3_DifACIc_phsC;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_q;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_t;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_db;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsC_zeroDb;

#endif
#if defined (MR901)
/****************************************************************
* IDPDIF1
*****************************************************************/
extern LogicalNode iedModel_PROT_IDPDIF1;

extern DataObject iedModel_PROT_IDPDIF1_Mod;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF1_Mod_stVal;
extern DataObject iedModel_PROT_IDPDIF1_Beh;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Beh_t;
extern DataObject iedModel_PROT_IDPDIF1_Health;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Health_t;
extern DataObject iedModel_PROT_IDPDIF1_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF1_Op;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF1_Str;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF1_Str_t;

extern DataObject iedModel_PROT_IDPDIF1_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb;

extern DataObject iedModel_PROT_IDPDIF1_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb;

/****************************************************************
* IDPDIF2
*****************************************************************/
extern LogicalNode iedModel_PROT_IDPDIF2;

extern DataObject iedModel_PROT_IDPDIF2_Mod;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF2_Mod_stVal;
extern DataObject iedModel_PROT_IDPDIF2_Beh;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Beh_t;
extern DataObject iedModel_PROT_IDPDIF2_Health;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Health_t;
extern DataObject iedModel_PROT_IDPDIF2_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF2_Op;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF2_Str;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF2_Str_t;

extern DataObject iedModel_PROT_IDPDIF2_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb;

extern DataObject iedModel_PROT_IDPDIF2_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb;

/****************************************************************
* IDPDIF3
*****************************************************************/
extern LogicalNode iedModel_PROT_IDPDIF3;

extern DataObject iedModel_PROT_IDPDIF3_Mod;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_t;
extern DataAttribute iedModel_PROT_IDPDIF3_Mod_stVal;
extern DataObject iedModel_PROT_IDPDIF3_Beh;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_stVal;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Beh_t;
extern DataObject iedModel_PROT_IDPDIF3_Health;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_stVal;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Health_t;
extern DataObject iedModel_PROT_IDPDIF3_NamPlt;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDPDIF3_Op;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_general;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Op_t;

// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDPDIF3_Str;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_general;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_q;
extern DataAttribute iedModel_PROT_IDPDIF3_Str_t;

extern DataObject iedModel_PROT_IDPDIF3_RstA_phsA;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb;

extern DataObject iedModel_PROT_IDPDIF3_DifACIc_phsA;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag_f;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_q;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_t;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_db;
extern DataAttribute iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb;
#endif

/****************************************************************
* IDMPDIF1
*****************************************************************/
extern LogicalNode iedModel_PROT_IDMPDIF1;

extern DataObject iedModel_PROT_IDMPDIF1_Mod;
extern DataAttribute iedModel_PROT_IDMPDIF1_Mod_q;
extern DataAttribute iedModel_PROT_IDMPDIF1_Mod_t;
extern DataAttribute iedModel_PROT_IDMPDIF1_Mod_stVal;

extern DataObject iedModel_PROT_IDMPDIF1_Beh;
extern DataAttribute iedModel_PROT_IDMPDIF1_Beh_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF1_Beh_q;
extern DataAttribute iedModel_PROT_IDMPDIF1_Beh_t;

extern DataObject iedModel_PROT_IDMPDIF1_Health;
extern DataAttribute iedModel_PROT_IDMPDIF1_Health_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF1_Health_q;
extern DataAttribute iedModel_PROT_IDMPDIF1_Health_t;

extern DataObject iedModel_PROT_IDMPDIF1_NamPlt;
extern DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDMPDIF1_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDMPDIF1_Op;
extern DataAttribute iedModel_PROT_IDMPDIF1_Op_general;
extern DataAttribute iedModel_PROT_IDMPDIF1_Op_q;
extern DataAttribute iedModel_PROT_IDMPDIF1_Op_t;
/*
// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDMPDIF1_Str;
extern DataAttribute iedModel_PROT_IDMPDIF1_Str_general;
extern DataAttribute iedModel_PROT_IDMPDIF1_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDMPDIF1_Str_q;
extern DataAttribute iedModel_PROT_IDMPDIF1_Str_t;
*/
/****************************************************************
* IDMPDIF2
*****************************************************************/
extern LogicalNode iedModel_PROT_IDMPDIF2;

extern DataObject iedModel_PROT_IDMPDIF2_Mod;
extern DataAttribute iedModel_PROT_IDMPDIF2_Mod_q;
extern DataAttribute iedModel_PROT_IDMPDIF2_Mod_t;
extern DataAttribute iedModel_PROT_IDMPDIF2_Mod_stVal;

extern DataObject iedModel_PROT_IDMPDIF2_Beh;
extern DataAttribute iedModel_PROT_IDMPDIF2_Beh_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF2_Beh_q;
extern DataAttribute iedModel_PROT_IDMPDIF2_Beh_t;

extern DataObject iedModel_PROT_IDMPDIF2_Health;
extern DataAttribute iedModel_PROT_IDMPDIF2_Health_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF2_Health_q;
extern DataAttribute iedModel_PROT_IDMPDIF2_Health_t;

extern DataObject iedModel_PROT_IDMPDIF2_NamPlt;
extern DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDMPDIF2_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDMPDIF2_Op;
extern DataAttribute iedModel_PROT_IDMPDIF2_Op_general;
extern DataAttribute iedModel_PROT_IDMPDIF2_Op_q;
extern DataAttribute iedModel_PROT_IDMPDIF2_Op_t;
/*
// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDMPDIF2_Str;
extern DataAttribute iedModel_PROT_IDMPDIF2_Str_general;
extern DataAttribute iedModel_PROT_IDMPDIF2_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDMPDIF2_Str_q;
extern DataAttribute iedModel_PROT_IDMPDIF2_Str_t;
*/
/****************************************************************
* IDMPDIF3
*****************************************************************/
extern LogicalNode iedModel_PROT_IDMPDIF3;

extern DataObject iedModel_PROT_IDMPDIF3_Mod;
extern DataAttribute iedModel_PROT_IDMPDIF3_Mod_q;
extern DataAttribute iedModel_PROT_IDMPDIF3_Mod_t;
extern DataAttribute iedModel_PROT_IDMPDIF3_Mod_stVal;

extern DataObject iedModel_PROT_IDMPDIF3_Beh;
extern DataAttribute iedModel_PROT_IDMPDIF3_Beh_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF3_Beh_q;
extern DataAttribute iedModel_PROT_IDMPDIF3_Beh_t;

extern DataObject iedModel_PROT_IDMPDIF3_Health;
extern DataAttribute iedModel_PROT_IDMPDIF3_Health_stVal;
extern DataAttribute iedModel_PROT_IDMPDIF3_Health_q;
extern DataAttribute iedModel_PROT_IDMPDIF3_Health_t;

extern DataObject iedModel_PROT_IDMPDIF3_NamPlt;
extern DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_vendor;
extern DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_swRev;
extern DataAttribute iedModel_PROT_IDMPDIF3_NamPlt_d;

// информация о статусе СРАБАТЫВАНИЕ
extern DataObject iedModel_PROT_IDMPDIF3_Op;
extern DataAttribute iedModel_PROT_IDMPDIF3_Op_general;
extern DataAttribute iedModel_PROT_IDMPDIF3_Op_q;
extern DataAttribute iedModel_PROT_IDMPDIF3_Op_t;
/*
// информация о статусе ПУСК
extern DataObject iedModel_PROT_IDMPDIF3_Str;
extern DataAttribute iedModel_PROT_IDMPDIF3_Str_general;
extern DataAttribute iedModel_PROT_IDMPDIF3_Str_dirGeneral;
extern DataAttribute iedModel_PROT_IDMPDIF3_Str_q;
extern DataAttribute iedModel_PROT_IDMPDIF3_Str_t;
*/
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
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_vendor;			// 		Имя поставщика
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


extern DataObject    iedModel_CTRL_PTRC_Op1;
extern DataAttribute iedModel_CTRL_PTRC_Op1_general;
extern DataAttribute iedModel_CTRL_PTRC_Op1_q;
extern DataAttribute iedModel_CTRL_PTRC_Op1_t;
extern DataAttribute iedModel_CTRL_PTRC_Op1_dU;

extern DataObject    iedModel_CTRL_PTRC_Op2;
extern DataAttribute iedModel_CTRL_PTRC_Op2_general;
extern DataAttribute iedModel_CTRL_PTRC_Op2_q;
extern DataAttribute iedModel_CTRL_PTRC_Op2_t;
extern DataAttribute iedModel_CTRL_PTRC_Op2_dU;

extern DataObject    iedModel_CTRL_PTRC_Op3;
extern DataAttribute iedModel_CTRL_PTRC_Op3_general;
extern DataAttribute iedModel_CTRL_PTRC_Op3_q;
extern DataAttribute iedModel_CTRL_PTRC_Op3_t;
extern DataAttribute iedModel_CTRL_PTRC_Op3_dU;

extern DataObject    iedModel_CTRL_PTRC_Op4;
extern DataAttribute iedModel_CTRL_PTRC_Op4_general;
extern DataAttribute iedModel_CTRL_PTRC_Op4_q;
extern DataAttribute iedModel_CTRL_PTRC_Op4_t;
extern DataAttribute iedModel_CTRL_PTRC_Op4_dU;

extern DataObject    iedModel_CTRL_PTRC_Op5;
extern DataAttribute iedModel_CTRL_PTRC_Op5_general;
extern DataAttribute iedModel_CTRL_PTRC_Op5_q;
extern DataAttribute iedModel_CTRL_PTRC_Op5_t;
extern DataAttribute iedModel_CTRL_PTRC_Op5_dU;

extern DataObject    iedModel_CTRL_PTRC_Op6;
extern DataAttribute iedModel_CTRL_PTRC_Op6_general;
extern DataAttribute iedModel_CTRL_PTRC_Op6_q;
extern DataAttribute iedModel_CTRL_PTRC_Op6_t;
extern DataAttribute iedModel_CTRL_PTRC_Op6_dU;

extern DataObject    iedModel_CTRL_PTRC_Op7;
extern DataAttribute iedModel_CTRL_PTRC_Op7_general;
extern DataAttribute iedModel_CTRL_PTRC_Op7_q;
extern DataAttribute iedModel_CTRL_PTRC_Op7_t;
extern DataAttribute iedModel_CTRL_PTRC_Op7_dU;

extern DataObject    iedModel_CTRL_PTRC_Op8;
extern DataAttribute iedModel_CTRL_PTRC_Op8_general;
extern DataAttribute iedModel_CTRL_PTRC_Op8_q;
extern DataAttribute iedModel_CTRL_PTRC_Op8_t;
extern DataAttribute iedModel_CTRL_PTRC_Op8_dU;

extern DataObject    iedModel_CTRL_PTRC_Op9;
extern DataAttribute iedModel_CTRL_PTRC_Op9_general;
extern DataAttribute iedModel_CTRL_PTRC_Op9_q;
extern DataAttribute iedModel_CTRL_PTRC_Op9_t;
extern DataAttribute iedModel_CTRL_PTRC_Op9_dU;

extern DataObject    iedModel_CTRL_PTRC_Op10;
extern DataAttribute iedModel_CTRL_PTRC_Op10_general;
extern DataAttribute iedModel_CTRL_PTRC_Op10_q;
extern DataAttribute iedModel_CTRL_PTRC_Op10_t;
extern DataAttribute iedModel_CTRL_PTRC_Op10_dU;


extern DataObject    iedModel_CTRL_PTRC_Op11;
extern DataAttribute iedModel_CTRL_PTRC_Op11_general;
extern DataAttribute iedModel_CTRL_PTRC_Op11_q;
extern DataAttribute iedModel_CTRL_PTRC_Op11_t;
extern DataAttribute iedModel_CTRL_PTRC_Op11_dU;

extern DataObject    iedModel_CTRL_PTRC_Op12;
extern DataAttribute iedModel_CTRL_PTRC_Op12_general;
extern DataAttribute iedModel_CTRL_PTRC_Op12_q;
extern DataAttribute iedModel_CTRL_PTRC_Op12_t;
extern DataAttribute iedModel_CTRL_PTRC_Op12_dU;

extern DataObject    iedModel_CTRL_PTRC_Op13;
extern DataAttribute iedModel_CTRL_PTRC_Op13_general;
extern DataAttribute iedModel_CTRL_PTRC_Op13_q;
extern DataAttribute iedModel_CTRL_PTRC_Op13_t;
extern DataAttribute iedModel_CTRL_PTRC_Op13_dU;

extern DataObject    iedModel_CTRL_PTRC_Op14;
extern DataAttribute iedModel_CTRL_PTRC_Op14_general;
extern DataAttribute iedModel_CTRL_PTRC_Op14_q;
extern DataAttribute iedModel_CTRL_PTRC_Op14_t;
extern DataAttribute iedModel_CTRL_PTRC_Op14_dU;

extern DataObject    iedModel_CTRL_PTRC_Op15;
extern DataAttribute iedModel_CTRL_PTRC_Op15_general;
extern DataAttribute iedModel_CTRL_PTRC_Op15_q;
extern DataAttribute iedModel_CTRL_PTRC_Op15_t;
extern DataAttribute iedModel_CTRL_PTRC_Op15_dU;

extern DataObject    iedModel_CTRL_PTRC_Op16;
extern DataAttribute iedModel_CTRL_PTRC_Op16_general;
extern DataAttribute iedModel_CTRL_PTRC_Op16_q;
extern DataAttribute iedModel_CTRL_PTRC_Op16_t;
extern DataAttribute iedModel_CTRL_PTRC_Op16_dU;

extern DataObject    iedModel_CTRL_PTRC_Op17;
extern DataAttribute iedModel_CTRL_PTRC_Op17_general;
extern DataAttribute iedModel_CTRL_PTRC_Op17_q;
extern DataAttribute iedModel_CTRL_PTRC_Op17_t;
extern DataAttribute iedModel_CTRL_PTRC_Op17_dU;

extern DataObject    iedModel_CTRL_PTRC_Op18;
extern DataAttribute iedModel_CTRL_PTRC_Op18_general;
extern DataAttribute iedModel_CTRL_PTRC_Op18_q;
extern DataAttribute iedModel_CTRL_PTRC_Op18_t;
extern DataAttribute iedModel_CTRL_PTRC_Op18_dU;

extern DataObject    iedModel_CTRL_PTRC_Op19;
extern DataAttribute iedModel_CTRL_PTRC_Op19_general;
extern DataAttribute iedModel_CTRL_PTRC_Op19_q;
extern DataAttribute iedModel_CTRL_PTRC_Op19_t;
extern DataAttribute iedModel_CTRL_PTRC_Op19_dU;

extern DataObject    iedModel_CTRL_PTRC_Op20;
extern DataAttribute iedModel_CTRL_PTRC_Op20_general;
extern DataAttribute iedModel_CTRL_PTRC_Op20_q;
extern DataAttribute iedModel_CTRL_PTRC_Op20_t;
extern DataAttribute iedModel_CTRL_PTRC_Op20_dU;


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


#endif /* STATIC_MODEL_H_ */

