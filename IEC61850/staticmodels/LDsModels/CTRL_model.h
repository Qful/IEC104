/*
 * CTRL_model.h
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#ifndef CTRL_MODEL_H_
#define CTRL_MODEL_H_

#include "LDsModels/Defs_model.h"

extern LogicalDevice iedModel_Generic_CTRL;
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
// CSWI1
//----------------------------------------------------------------------------
extern LogicalNode   iedModel_CTRL_CSWI1;
extern DataObject    iedModel_CTRL_CSWI1_Mod;
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
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_swRev;		// 		Ревизия программной части
extern DataAttribute iedModel_CTRL_CSWI1_NamPlt_d;			//		Текстовое описание данных сдесь относится к логическому узлу LN CSWI1.

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

//----------------------------------------------------------------------------
// XCBR1
//----------------------------------------------------------------------------
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
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlVal;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orCat;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_origin_orIdent;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_ctlNum;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_T;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Test;
extern DataAttribute iedModel_CTRL_XCBR1_BlkCls_Oper_Check;

//----------------------------------------------------------------------------
// PTRC
//----------------------------------------------------------------------------
ExternLogicalNode(CTRL, PTRC);

extern DataObject iedModel_CTRL_PTRC_Op;
extern DataAttribute iedModel_CTRL_PTRC_Op_general;
extern DataAttribute iedModel_CTRL_PTRC_Op_q;
extern DataAttribute iedModel_CTRL_PTRC_Op_t;

//----------------------------------------------------------------------------
// GGIO1
//----------------------------------------------------------------------------
ExternLogicalNode(CTRL, GGIO1);

ExternDataObject_CTRL_SPCSO(1,CTRL, GGIO1);
ExternDataObject_CTRL_SPCSO(2,CTRL, GGIO1);
ExternDataObject_CTRL_SPCSO(3,CTRL, GGIO1);
ExternDataObject_CTRL_SPCSO(4,CTRL, GGIO1);

//----------------------------------------------------------------------------
// CMD24GGIO1
//----------------------------------------------------------------------------
ExternLogicalNode(CTRL, CMD24GGIO1);

ExternDataObject_CTRL_SPCSO(1,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(2,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(3,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(4,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(5,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(6,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(7,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(8,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(9,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(10,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(11,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(12,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(13,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(14,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(15,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(16,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(17,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(18,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(19,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(20,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(21,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(22,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(23,CTRL, CMD24GGIO1);
ExternDataObject_CTRL_SPCSO(24,CTRL, CMD24GGIO1);

#endif /* CTRL_MODEL_H_ */
