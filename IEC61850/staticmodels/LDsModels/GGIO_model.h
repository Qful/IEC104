/*
 * GGIO_model.h
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#ifndef GGIO_MODEL_H_
#define GGIO_MODEL_H_

#include "LDsModels/Defs_model.h"


extern LogicalDevice iedModel_Generic_GGIO;

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
ExternLogicalNode(GGIO, OUTGGIO1);

ExternDataObjectSPCSO(1, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(2, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(3, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(4, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(5, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(6, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(7, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(8, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(9, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(10, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(11, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(12, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(13, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(14, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(15, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(16, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(17, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(18, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(19, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(20, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(21, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(22, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(23, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(24, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(25, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(26, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(27, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(28, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(29, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(30, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(31, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(32, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(33, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(34, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(35, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(36, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(37, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(38, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(39, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(40, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(41, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(42, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(43, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(44, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(45, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(46, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(47, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(48, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(49, GGIO, OUTGGIO1);
ExternDataObjectSPCSO(50, GGIO, OUTGGIO1);
// ---------------------------------------------------------------------------------------------------------
// LED
// ---------------------------------------------------------------------------------------------------------
ExternLogicalNode(GGIO, LEDGGIO1);

ExternDataObjectInd(1, GGIO, LEDGGIO1);
ExternDataObjectInd(2, GGIO, LEDGGIO1);
ExternDataObjectInd(3, GGIO, LEDGGIO1);
ExternDataObjectInd(4, GGIO, LEDGGIO1);
ExternDataObjectInd(5, GGIO, LEDGGIO1);
ExternDataObjectInd(6, GGIO, LEDGGIO1);
ExternDataObjectInd(7, GGIO, LEDGGIO1);
ExternDataObjectInd(8, GGIO, LEDGGIO1);
ExternDataObjectInd(9, GGIO, LEDGGIO1);
ExternDataObjectInd(10, GGIO, LEDGGIO1);
ExternDataObjectInd(11, GGIO, LEDGGIO1);
ExternDataObjectInd(12, GGIO, LEDGGIO1);
ExternDataObjectInd_dU(13, GGIO, LEDGGIO1);
ExternDataObjectInd_dU(14, GGIO, LEDGGIO1);
ExternDataObjectInd_dU(15, GGIO, LEDGGIO1);
ExternDataObjectInd_dU(16, GGIO, LEDGGIO1);

// ------------------------------------------------------------
// IN
// ------------------------------------------------------------
ExternLogicalNode(GGIO, INGGIO1);

ExternDataObjectInd(1, GGIO, INGGIO1);
ExternDataObjectInd(2, GGIO, INGGIO1);
ExternDataObjectInd(3, GGIO, INGGIO1);
ExternDataObjectInd(4, GGIO, INGGIO1);
ExternDataObjectInd(5, GGIO, INGGIO1);
ExternDataObjectInd(6, GGIO, INGGIO1);
ExternDataObjectInd(7, GGIO, INGGIO1);
ExternDataObjectInd(8, GGIO, INGGIO1);
ExternDataObjectInd(9, GGIO, INGGIO1);
ExternDataObjectInd(10, GGIO, INGGIO1);
ExternDataObjectInd(11, GGIO, INGGIO1);
ExternDataObjectInd(12, GGIO, INGGIO1);
ExternDataObjectInd(13, GGIO, INGGIO1);
ExternDataObjectInd(14, GGIO, INGGIO1);
ExternDataObjectInd(15, GGIO, INGGIO1);
ExternDataObjectInd(16, GGIO, INGGIO1);
ExternDataObjectInd(17, GGIO, INGGIO1);
ExternDataObjectInd(18, GGIO, INGGIO1);
ExternDataObjectInd(19, GGIO, INGGIO1);
ExternDataObjectInd(20, GGIO, INGGIO1);
ExternDataObjectInd(21, GGIO, INGGIO1);
ExternDataObjectInd(22, GGIO, INGGIO1);
ExternDataObjectInd(23, GGIO, INGGIO1);
ExternDataObjectInd(24, GGIO, INGGIO1);
ExternDataObjectInd(25, GGIO, INGGIO1);
ExternDataObjectInd(26, GGIO, INGGIO1);
ExternDataObjectInd(27, GGIO, INGGIO1);
ExternDataObjectInd(28, GGIO, INGGIO1);
ExternDataObjectInd(29, GGIO, INGGIO1);
ExternDataObjectInd(30, GGIO, INGGIO1);
ExternDataObjectInd(31, GGIO, INGGIO1);
ExternDataObjectInd(32, GGIO, INGGIO1);
ExternDataObjectInd(33, GGIO, INGGIO1);
ExternDataObjectInd(34, GGIO, INGGIO1);
ExternDataObjectInd(35, GGIO, INGGIO1);
ExternDataObjectInd(36, GGIO, INGGIO1);
ExternDataObjectInd(37, GGIO, INGGIO1);
ExternDataObjectInd(38, GGIO, INGGIO1);
ExternDataObjectInd(39, GGIO, INGGIO1);
ExternDataObjectInd(40, GGIO, INGGIO1);
ExternDataObjectInd(41, GGIO, INGGIO1);
ExternDataObjectInd(42, GGIO, INGGIO1);
ExternDataObjectInd(43, GGIO, INGGIO1);
ExternDataObjectInd(44, GGIO, INGGIO1);
ExternDataObjectInd(45, GGIO, INGGIO1);
ExternDataObjectInd(46, GGIO, INGGIO1);
ExternDataObjectInd(47, GGIO, INGGIO1);
ExternDataObjectInd(48, GGIO, INGGIO1);
ExternDataObjectInd(49, GGIO, INGGIO1);
ExternDataObjectInd(50, GGIO, INGGIO1);
ExternDataObjectInd(51, GGIO, INGGIO1);
ExternDataObjectInd(52, GGIO, INGGIO1);
ExternDataObjectInd(53, GGIO, INGGIO1);
ExternDataObjectInd(54, GGIO, INGGIO1);
ExternDataObjectInd(55, GGIO, INGGIO1);
ExternDataObjectInd(56, GGIO, INGGIO1);
ExternDataObjectInd(57, GGIO, INGGIO1);
ExternDataObjectInd(58, GGIO, INGGIO1);

//----------------------------------------------------------------------------
// SSL
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, SSLGGIO1);

ExternDataObjectInd(1, GGIO, SSLGGIO1);
ExternDataObjectInd(2, GGIO, SSLGGIO1);
ExternDataObjectInd(3, GGIO, SSLGGIO1);
ExternDataObjectInd(4, GGIO, SSLGGIO1);
ExternDataObjectInd(5, GGIO, SSLGGIO1);
ExternDataObjectInd(6, GGIO, SSLGGIO1);
ExternDataObjectInd(7, GGIO, SSLGGIO1);
ExternDataObjectInd(8, GGIO, SSLGGIO1);
ExternDataObjectInd(9, GGIO, SSLGGIO1);
ExternDataObjectInd(10, GGIO, SSLGGIO1);
ExternDataObjectInd(11, GGIO, SSLGGIO1);
ExternDataObjectInd(12, GGIO, SSLGGIO1);
ExternDataObjectInd(13, GGIO, SSLGGIO1);
ExternDataObjectInd(14, GGIO, SSLGGIO1);
ExternDataObjectInd(15, GGIO, SSLGGIO1);
ExternDataObjectInd(16, GGIO, SSLGGIO1);
ExternDataObjectInd(17, GGIO, SSLGGIO1);
ExternDataObjectInd(18, GGIO, SSLGGIO1);
ExternDataObjectInd(19, GGIO, SSLGGIO1);
ExternDataObjectInd(20, GGIO, SSLGGIO1);
ExternDataObjectInd(21, GGIO, SSLGGIO1);
ExternDataObjectInd(22, GGIO, SSLGGIO1);
ExternDataObjectInd(23, GGIO, SSLGGIO1);
ExternDataObjectInd(24, GGIO, SSLGGIO1);
ExternDataObjectInd(25, GGIO, SSLGGIO1);
ExternDataObjectInd(26, GGIO, SSLGGIO1);
ExternDataObjectInd(27, GGIO, SSLGGIO1);
ExternDataObjectInd(28, GGIO, SSLGGIO1);
ExternDataObjectInd(29, GGIO, SSLGGIO1);
ExternDataObjectInd(30, GGIO, SSLGGIO1);
ExternDataObjectInd(31, GGIO, SSLGGIO1);
ExternDataObjectInd(32, GGIO, SSLGGIO1);
ExternDataObjectInd(33, GGIO, SSLGGIO1);
ExternDataObjectInd(34, GGIO, SSLGGIO1);
ExternDataObjectInd(35, GGIO, SSLGGIO1);
ExternDataObjectInd(36, GGIO, SSLGGIO1);
ExternDataObjectInd(37, GGIO, SSLGGIO1);
ExternDataObjectInd(38, GGIO, SSLGGIO1);
ExternDataObjectInd(39, GGIO, SSLGGIO1);
ExternDataObjectInd(40, GGIO, SSLGGIO1);
ExternDataObjectInd(41, GGIO, SSLGGIO1);
ExternDataObjectInd(42, GGIO, SSLGGIO1);
ExternDataObjectInd(43, GGIO, SSLGGIO1);
ExternDataObjectInd(44, GGIO, SSLGGIO1);
ExternDataObjectInd(45, GGIO, SSLGGIO1);
ExternDataObjectInd(46, GGIO, SSLGGIO1);
ExternDataObjectInd(47, GGIO, SSLGGIO1);
ExternDataObjectInd(48, GGIO, SSLGGIO1);

//----------------------------------------------------------------------------
// VLS
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, VLSGGIO1);

ExternDataObjectInd(1, GGIO, VLSGGIO1);
ExternDataObjectInd(2, GGIO, VLSGGIO1);
ExternDataObjectInd(3, GGIO, VLSGGIO1);
ExternDataObjectInd(4, GGIO, VLSGGIO1);
ExternDataObjectInd(5, GGIO, VLSGGIO1);
ExternDataObjectInd(6, GGIO, VLSGGIO1);
ExternDataObjectInd(7, GGIO, VLSGGIO1);
ExternDataObjectInd(8, GGIO, VLSGGIO1);
ExternDataObjectInd(9, GGIO, VLSGGIO1);
ExternDataObjectInd(10, GGIO, VLSGGIO1);
ExternDataObjectInd(11, GGIO, VLSGGIO1);
ExternDataObjectInd(12, GGIO, VLSGGIO1);
ExternDataObjectInd(13, GGIO, VLSGGIO1);
ExternDataObjectInd(14, GGIO, VLSGGIO1);
ExternDataObjectInd(15, GGIO, VLSGGIO1);
ExternDataObjectInd(16, GGIO, VLSGGIO1);

//----------------------------------------------------------------------------
// LS
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, LSGGIO1);

ExternDataObjectInd(1, GGIO, LSGGIO1);
ExternDataObjectInd(2, GGIO, LSGGIO1);
ExternDataObjectInd(3, GGIO, LSGGIO1);
ExternDataObjectInd(4, GGIO, LSGGIO1);
ExternDataObjectInd(5, GGIO, LSGGIO1);
ExternDataObjectInd(6, GGIO, LSGGIO1);
ExternDataObjectInd(7, GGIO, LSGGIO1);
ExternDataObjectInd(8, GGIO, LSGGIO1);
ExternDataObjectInd(9, GGIO, LSGGIO1);
ExternDataObjectInd(10, GGIO, LSGGIO1);
ExternDataObjectInd(11, GGIO, LSGGIO1);
ExternDataObjectInd(12, GGIO, LSGGIO1);
ExternDataObjectInd(13, GGIO, LSGGIO1);
ExternDataObjectInd(14, GGIO, LSGGIO1);
ExternDataObjectInd(15, GGIO, LSGGIO1);
ExternDataObjectInd(16, GGIO, LSGGIO1);

//----------------------------------------------------------------------------
// RST
//----------------------------------------------------------------------------
ExternLogicalNode(GGIO, RSTGGIO1);

ExternDataObjectInd(1, GGIO, RSTGGIO1);
ExternDataObjectInd(2, GGIO, RSTGGIO1);
ExternDataObjectInd(3, GGIO, RSTGGIO1);
ExternDataObjectInd(4, GGIO, RSTGGIO1);
ExternDataObjectInd(5, GGIO, RSTGGIO1);
ExternDataObjectInd(6, GGIO, RSTGGIO1);
ExternDataObjectInd(7, GGIO, RSTGGIO1);
ExternDataObjectInd(8, GGIO, RSTGGIO1);
ExternDataObjectInd(9, GGIO, RSTGGIO1);
ExternDataObjectInd(10, GGIO, RSTGGIO1);
ExternDataObjectInd(11, GGIO, RSTGGIO1);
ExternDataObjectInd(12, GGIO, RSTGGIO1);
ExternDataObjectInd(13, GGIO, RSTGGIO1);
ExternDataObjectInd(14, GGIO, RSTGGIO1);
ExternDataObjectInd(15, GGIO, RSTGGIO1);
ExternDataObjectInd(16, GGIO, RSTGGIO1);

#endif /* GGIO_MODEL_H_ */
