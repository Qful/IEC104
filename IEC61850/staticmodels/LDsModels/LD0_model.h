/*
 * LD0_model.h
 *
 *  Created on: 14.05.2019
 *      Author: sagok
 */

#ifndef LD0_MODEL_H_
#define LD0_MODEL_H_

extern LogicalDevice iedModel_Generic_LD0;

// ---------------------------------------------------------------------------------------------------------
// 0    000    00
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 0    0  0  0  0
// 000  000    00
// ---------------------------------------------------------------------------------------------------------

extern LogicalNode   iedModel_LD0_LLN0;
extern DataObject    iedModel_LD0_LLN0_Mod;
extern DataAttribute iedModel_LD0_LLN0_Mod_q;
extern DataAttribute iedModel_LD0_LLN0_Mod_t;
extern DataAttribute iedModel_LD0_LLN0_Mod_stVal;
extern DataAttribute iedModel_LD0_LLN0_Mod_ctlModel;

extern DataObject    iedModel_LD0_LLN0_Beh;
extern DataAttribute iedModel_LD0_LLN0_Beh_stVal;
extern DataAttribute iedModel_LD0_LLN0_Beh_q;
extern DataAttribute iedModel_LD0_LLN0_Beh_t;

extern DataObject    iedModel_LD0_LLN0_Health;
extern DataAttribute iedModel_LD0_LLN0_Health_stVal;
extern DataAttribute iedModel_LD0_LLN0_Health_q;
extern DataAttribute iedModel_LD0_LLN0_Health_t;

extern DataObject    iedModel_LD0_LLN0_NamPlt;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_d;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_configRev;
extern DataAttribute iedModel_LD0_LLN0_NamPlt_ldNs;

extern DataObject    iedModel_LD0_LLN0_SGCB;
extern DataAttribute iedModel_LD0_LLN0_SGCB_ActSG;
extern DataAttribute iedModel_LD0_LLN0_SGCB_q;
extern DataAttribute iedModel_LD0_LLN0_SGCB_t;

// LPHD ----------------------------------------------------------------------------------------------------
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


#endif /* LD0_MODEL_H_ */
