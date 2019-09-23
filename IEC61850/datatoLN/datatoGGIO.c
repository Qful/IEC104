/*
 * datatoGGIO.c
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
/*******************************************************
 * VZGGIO
 *******************************************************/
uint16_t VZBuf[MB_MaxNumbVZ][2] ={
		(uint16_t)MB_offset_SRAB_ext_1,		(uint16_t)MB_b_SRAB_ext_1,
		(uint16_t)MB_offset_SRAB_ext_2,		(uint16_t)MB_b_SRAB_ext_2,
		(uint16_t)MB_offset_SRAB_ext_3,		(uint16_t)MB_b_SRAB_ext_3,
		(uint16_t)MB_offset_SRAB_ext_4,		(uint16_t)MB_b_SRAB_ext_4,
		(uint16_t)MB_offset_SRAB_ext_5,		(uint16_t)MB_b_SRAB_ext_5,
		(uint16_t)MB_offset_SRAB_ext_6,		(uint16_t)MB_b_SRAB_ext_6,
		(uint16_t)MB_offset_SRAB_ext_7,		(uint16_t)MB_b_SRAB_ext_7,
		(uint16_t)MB_offset_SRAB_ext_8,		(uint16_t)MB_b_SRAB_ext_8,
		(uint16_t)MB_offset_SRAB_ext_9,		(uint16_t)MB_b_SRAB_ext_9,
		(uint16_t)MB_offset_SRAB_ext_10,	(uint16_t)MB_b_SRAB_ext_10,
		(uint16_t)MB_offset_SRAB_ext_11,	(uint16_t)MB_b_SRAB_ext_11,
		(uint16_t)MB_offset_SRAB_ext_12,	(uint16_t)MB_b_SRAB_ext_12,
		(uint16_t)MB_offset_SRAB_ext_13,	(uint16_t)MB_b_SRAB_ext_13,
		(uint16_t)MB_offset_SRAB_ext_14,	(uint16_t)MB_b_SRAB_ext_14,
		(uint16_t)MB_offset_SRAB_ext_15,	(uint16_t)MB_b_SRAB_ext_15,
		(uint16_t)MB_offset_SRAB_ext_16,	(uint16_t)MB_b_SRAB_ext_16,
};

uint16_t VZCFGBuf[MB_MaxNumbVZ] ={
		(uint16_t)MB_offset_Ext_1,		(uint16_t)MB_offset_Ext_2,
		(uint16_t)MB_offset_Ext_3,		(uint16_t)MB_offset_Ext_4,
		(uint16_t)MB_offset_Ext_5,		(uint16_t)MB_offset_Ext_6,
		(uint16_t)MB_offset_Ext_7,		(uint16_t)MB_offset_Ext_8,
		(uint16_t)MB_offset_Ext_9,		(uint16_t)MB_offset_Ext_10,
		(uint16_t)MB_offset_Ext_11,		(uint16_t)MB_offset_Ext_12,
		(uint16_t)MB_offset_Ext_13,		(uint16_t)MB_offset_Ext_14,
		(uint16_t)MB_offset_Ext_15,		(uint16_t)MB_offset_Ext_16,
};

DataAttribute* iedModel_VZGGIO_Ind_q[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_q,		&iedModel_PROT_VZGGIO2_Alm_q,
		&iedModel_PROT_VZGGIO3_Alm_q,		&iedModel_PROT_VZGGIO4_Alm_q,
		&iedModel_PROT_VZGGIO5_Alm_q,		&iedModel_PROT_VZGGIO6_Alm_q,
		&iedModel_PROT_VZGGIO7_Alm_q,		&iedModel_PROT_VZGGIO8_Alm_q,
		&iedModel_PROT_VZGGIO9_Alm_q,		&iedModel_PROT_VZGGIO10_Alm_q,
		&iedModel_PROT_VZGGIO11_Alm_q,		&iedModel_PROT_VZGGIO12_Alm_q,
		&iedModel_PROT_VZGGIO13_Alm_q,		&iedModel_PROT_VZGGIO14_Alm_q,
		&iedModel_PROT_VZGGIO15_Alm_q,		&iedModel_PROT_VZGGIO16_Alm_q,
};

DataAttribute* iedModel_VZGGIO_Ind_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_t,		&iedModel_PROT_VZGGIO2_Alm_t,
		&iedModel_PROT_VZGGIO3_Alm_t,		&iedModel_PROT_VZGGIO4_Alm_t,
		&iedModel_PROT_VZGGIO5_Alm_t,		&iedModel_PROT_VZGGIO6_Alm_t,
		&iedModel_PROT_VZGGIO7_Alm_t,		&iedModel_PROT_VZGGIO8_Alm_t,
		&iedModel_PROT_VZGGIO9_Alm_t,		&iedModel_PROT_VZGGIO10_Alm_t,
		&iedModel_PROT_VZGGIO11_Alm_t,		&iedModel_PROT_VZGGIO12_Alm_t,
		&iedModel_PROT_VZGGIO13_Alm_t,		&iedModel_PROT_VZGGIO14_Alm_t,
		&iedModel_PROT_VZGGIO15_Alm_t,		&iedModel_PROT_VZGGIO16_Alm_t,

};

DataAttribute* iedModel_VZGGIO_Alm_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_stVal,		&iedModel_PROT_VZGGIO2_Alm_stVal,
		&iedModel_PROT_VZGGIO3_Alm_stVal,		&iedModel_PROT_VZGGIO4_Alm_stVal,
		&iedModel_PROT_VZGGIO5_Alm_stVal,		&iedModel_PROT_VZGGIO6_Alm_stVal,
		&iedModel_PROT_VZGGIO7_Alm_stVal,		&iedModel_PROT_VZGGIO8_Alm_stVal,
		&iedModel_PROT_VZGGIO9_Alm_stVal,		&iedModel_PROT_VZGGIO10_Alm_stVal,
		&iedModel_PROT_VZGGIO11_Alm_stVal,		&iedModel_PROT_VZGGIO12_Alm_stVal,
		&iedModel_PROT_VZGGIO13_Alm_stVal,		&iedModel_PROT_VZGGIO14_Alm_stVal,
		&iedModel_PROT_VZGGIO15_Alm_stVal,		&iedModel_PROT_VZGGIO16_Alm_stVal,
};

DataAttribute* iedModel_VZGGIO_Health_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Health_stVal,		&iedModel_PROT_VZGGIO2_Health_stVal,
		&iedModel_PROT_VZGGIO3_Health_stVal,		&iedModel_PROT_VZGGIO4_Health_stVal,
		&iedModel_PROT_VZGGIO5_Health_stVal,		&iedModel_PROT_VZGGIO6_Health_stVal,
		&iedModel_PROT_VZGGIO7_Health_stVal,		&iedModel_PROT_VZGGIO8_Health_stVal,
		&iedModel_PROT_VZGGIO9_Health_stVal,		&iedModel_PROT_VZGGIO10_Health_stVal,
		&iedModel_PROT_VZGGIO11_Health_stVal,		&iedModel_PROT_VZGGIO12_Health_stVal,
		&iedModel_PROT_VZGGIO13_Health_stVal,		&iedModel_PROT_VZGGIO14_Health_stVal,
		&iedModel_PROT_VZGGIO15_Health_stVal,		&iedModel_PROT_VZGGIO16_Health_stVal,
};
DataAttribute* iedModel_VZGGIO_Health_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Health_t,		&iedModel_PROT_VZGGIO2_Health_t,
		&iedModel_PROT_VZGGIO3_Health_t,		&iedModel_PROT_VZGGIO4_Health_t,
		&iedModel_PROT_VZGGIO5_Health_t,		&iedModel_PROT_VZGGIO6_Health_t,
		&iedModel_PROT_VZGGIO7_Health_t,		&iedModel_PROT_VZGGIO8_Health_t,
		&iedModel_PROT_VZGGIO9_Health_t,		&iedModel_PROT_VZGGIO10_Health_t,
		&iedModel_PROT_VZGGIO11_Health_t,		&iedModel_PROT_VZGGIO12_Health_t,
		&iedModel_PROT_VZGGIO13_Health_t,		&iedModel_PROT_VZGGIO14_Health_t,
		&iedModel_PROT_VZGGIO15_Health_t,		&iedModel_PROT_VZGGIO16_Health_t,
};

DataAttribute* iedModel_VZGGIO_Mod_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Mod_stVal,		&iedModel_PROT_VZGGIO2_Mod_stVal,
		&iedModel_PROT_VZGGIO3_Mod_stVal,		&iedModel_PROT_VZGGIO4_Mod_stVal,
		&iedModel_PROT_VZGGIO5_Mod_stVal,		&iedModel_PROT_VZGGIO6_Mod_stVal,
		&iedModel_PROT_VZGGIO7_Mod_stVal,		&iedModel_PROT_VZGGIO8_Mod_stVal,
		&iedModel_PROT_VZGGIO9_Mod_stVal,		&iedModel_PROT_VZGGIO10_Mod_stVal,
		&iedModel_PROT_VZGGIO11_Mod_stVal,		&iedModel_PROT_VZGGIO12_Mod_stVal,
		&iedModel_PROT_VZGGIO13_Mod_stVal,		&iedModel_PROT_VZGGIO14_Mod_stVal,
		&iedModel_PROT_VZGGIO15_Mod_stVal,		&iedModel_PROT_VZGGIO16_Mod_stVal,
};
DataAttribute* iedModel_VZGGIO_Mod_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Mod_t,		&iedModel_PROT_VZGGIO2_Mod_t,
		&iedModel_PROT_VZGGIO3_Mod_t,		&iedModel_PROT_VZGGIO4_Mod_t,
		&iedModel_PROT_VZGGIO5_Mod_t,		&iedModel_PROT_VZGGIO6_Mod_t,
		&iedModel_PROT_VZGGIO7_Mod_t,		&iedModel_PROT_VZGGIO8_Mod_t,
		&iedModel_PROT_VZGGIO9_Mod_t,		&iedModel_PROT_VZGGIO10_Mod_t,
		&iedModel_PROT_VZGGIO11_Mod_t,		&iedModel_PROT_VZGGIO12_Mod_t,
		&iedModel_PROT_VZGGIO13_Mod_t,		&iedModel_PROT_VZGGIO14_Mod_t,
		&iedModel_PROT_VZGGIO15_Mod_t,		&iedModel_PROT_VZGGIO16_Mod_t,
};
DataAttribute* iedModel_VZGGIO_Mod_q[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Mod_q,		&iedModel_PROT_VZGGIO2_Mod_q,
		&iedModel_PROT_VZGGIO3_Mod_q,		&iedModel_PROT_VZGGIO4_Mod_q,
		&iedModel_PROT_VZGGIO5_Mod_q,		&iedModel_PROT_VZGGIO6_Mod_q,
		&iedModel_PROT_VZGGIO7_Mod_q,		&iedModel_PROT_VZGGIO8_Mod_q,
		&iedModel_PROT_VZGGIO9_Mod_q,		&iedModel_PROT_VZGGIO10_Mod_q,
		&iedModel_PROT_VZGGIO11_Mod_q,		&iedModel_PROT_VZGGIO12_Mod_q,
		&iedModel_PROT_VZGGIO13_Mod_q,		&iedModel_PROT_VZGGIO14_Mod_q,
		&iedModel_PROT_VZGGIO15_Mod_q,		&iedModel_PROT_VZGGIO16_Mod_q,
};
DataAttribute* iedModel_VZGGIO_Beh_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Beh_stVal,		&iedModel_PROT_VZGGIO2_Beh_stVal,
		&iedModel_PROT_VZGGIO3_Beh_stVal,		&iedModel_PROT_VZGGIO4_Beh_stVal,
		&iedModel_PROT_VZGGIO5_Beh_stVal,		&iedModel_PROT_VZGGIO6_Beh_stVal,
		&iedModel_PROT_VZGGIO7_Beh_stVal,		&iedModel_PROT_VZGGIO8_Beh_stVal,
		&iedModel_PROT_VZGGIO9_Beh_stVal,		&iedModel_PROT_VZGGIO10_Beh_stVal,
		&iedModel_PROT_VZGGIO11_Beh_stVal,		&iedModel_PROT_VZGGIO12_Beh_stVal,
		&iedModel_PROT_VZGGIO13_Beh_stVal,		&iedModel_PROT_VZGGIO14_Beh_stVal,
		&iedModel_PROT_VZGGIO15_Beh_stVal,		&iedModel_PROT_VZGGIO16_Beh_stVal,
};
DataAttribute* iedModel_VZGGIO_Beh_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Beh_t,		&iedModel_PROT_VZGGIO2_Beh_t,
		&iedModel_PROT_VZGGIO3_Beh_t,		&iedModel_PROT_VZGGIO4_Beh_t,
		&iedModel_PROT_VZGGIO5_Beh_t,		&iedModel_PROT_VZGGIO6_Beh_t,
		&iedModel_PROT_VZGGIO7_Beh_t,		&iedModel_PROT_VZGGIO8_Beh_t,
		&iedModel_PROT_VZGGIO9_Beh_t,		&iedModel_PROT_VZGGIO10_Beh_t,
		&iedModel_PROT_VZGGIO11_Beh_t,		&iedModel_PROT_VZGGIO12_Beh_t,
		&iedModel_PROT_VZGGIO13_Beh_t,		&iedModel_PROT_VZGGIO14_Beh_t,
		&iedModel_PROT_VZGGIO15_Beh_t,		&iedModel_PROT_VZGGIO16_Beh_t,
};
DataAttribute* iedModel_VZGGIO_Beh_q[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Beh_q,		&iedModel_PROT_VZGGIO2_Beh_q,
		&iedModel_PROT_VZGGIO3_Beh_q,		&iedModel_PROT_VZGGIO4_Beh_q,
		&iedModel_PROT_VZGGIO5_Beh_q,		&iedModel_PROT_VZGGIO6_Beh_q,
		&iedModel_PROT_VZGGIO7_Beh_q,		&iedModel_PROT_VZGGIO8_Beh_q,
		&iedModel_PROT_VZGGIO9_Beh_q,		&iedModel_PROT_VZGGIO10_Beh_q,
		&iedModel_PROT_VZGGIO11_Beh_q,		&iedModel_PROT_VZGGIO12_Beh_q,
		&iedModel_PROT_VZGGIO13_Beh_q,		&iedModel_PROT_VZGGIO14_Beh_q,
		&iedModel_PROT_VZGGIO15_Beh_q,		&iedModel_PROT_VZGGIO16_Beh_q,
};

/*******************************************************
 * INGGIO
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={
		(uint16_t)MB_offsetDiscreet_1,		(uint16_t)MB_bOffset_Discreet_1,
		(uint16_t)MB_offsetDiscreet_2,		(uint16_t)MB_bOffset_Discreet_2,
		(uint16_t)MB_offsetDiscreet_3,		(uint16_t)MB_bOffset_Discreet_3,
		(uint16_t)MB_offsetDiscreet_4,		(uint16_t)MB_bOffset_Discreet_4,
		(uint16_t)MB_offsetDiscreet_5,		(uint16_t)MB_bOffset_Discreet_5,
		(uint16_t)MB_offsetDiscreet_6,		(uint16_t)MB_bOffset_Discreet_6,
		(uint16_t)MB_offsetDiscreet_7,		(uint16_t)MB_bOffset_Discreet_7,
		(uint16_t)MB_offsetDiscreet_8,		(uint16_t)MB_bOffset_Discreet_8,
		(uint16_t)MB_offsetDiscreet_9,		(uint16_t)MB_bOffset_Discreet_9,
		(uint16_t)MB_offsetDiscreet_10,		(uint16_t)MB_bOffset_Discreet_10,
		(uint16_t)MB_offsetDiscreet_11,		(uint16_t)MB_bOffset_Discreet_11,
		(uint16_t)MB_offsetDiscreet_12,		(uint16_t)MB_bOffset_Discreet_12,
		(uint16_t)MB_offsetDiscreet_13,		(uint16_t)MB_bOffset_Discreet_13,
		(uint16_t)MB_offsetDiscreet_14,		(uint16_t)MB_bOffset_Discreet_14,
		(uint16_t)MB_offsetDiscreet_15,		(uint16_t)MB_bOffset_Discreet_15,
		(uint16_t)MB_offsetDiscreet_16,		(uint16_t)MB_bOffset_Discreet_16,
		(uint16_t)MB_offsetDiscreet_17,		(uint16_t)MB_bOffset_Discreet_17,
		(uint16_t)MB_offsetDiscreet_18,		(uint16_t)MB_bOffset_Discreet_18,
		(uint16_t)MB_offsetDiscreet_19,		(uint16_t)MB_bOffset_Discreet_19,
		(uint16_t)MB_offsetDiscreet_20,		(uint16_t)MB_bOffset_Discreet_20,
		(uint16_t)MB_offsetDiscreet_21,		(uint16_t)MB_bOffset_Discreet_21,
		(uint16_t)MB_offsetDiscreet_22,		(uint16_t)MB_bOffset_Discreet_22,
		(uint16_t)MB_offsetDiscreet_23,		(uint16_t)MB_bOffset_Discreet_23,
		(uint16_t)MB_offsetDiscreet_24,		(uint16_t)MB_bOffset_Discreet_24,
		(uint16_t)MB_offsetDiscreet_25,		(uint16_t)MB_bOffset_Discreet_25,
		(uint16_t)MB_offsetDiscreet_26,		(uint16_t)MB_bOffset_Discreet_26,
		(uint16_t)MB_offsetDiscreet_27,		(uint16_t)MB_bOffset_Discreet_27,
		(uint16_t)MB_offsetDiscreet_28,		(uint16_t)MB_bOffset_Discreet_28,
		(uint16_t)MB_offsetDiscreet_29,		(uint16_t)MB_bOffset_Discreet_29,
		(uint16_t)MB_offsetDiscreet_30,		(uint16_t)MB_bOffset_Discreet_30,
		(uint16_t)MB_offsetDiscreet_31,		(uint16_t)MB_bOffset_Discreet_31,
		(uint16_t)MB_offsetDiscreet_32,		(uint16_t)MB_bOffset_Discreet_32,
		(uint16_t)MB_offsetDiscreet_33,		(uint16_t)MB_bOffset_Discreet_33,
		(uint16_t)MB_offsetDiscreet_34,		(uint16_t)MB_bOffset_Discreet_34,
		(uint16_t)MB_offsetDiscreet_35,		(uint16_t)MB_bOffset_Discreet_35,
		(uint16_t)MB_offsetDiscreet_36,		(uint16_t)MB_bOffset_Discreet_36,
		(uint16_t)MB_offsetDiscreet_37,		(uint16_t)MB_bOffset_Discreet_37,
		(uint16_t)MB_offsetDiscreet_38,		(uint16_t)MB_bOffset_Discreet_38,
		(uint16_t)MB_offsetDiscreet_39,		(uint16_t)MB_bOffset_Discreet_39,
		(uint16_t)MB_offsetDiscreet_40,		(uint16_t)MB_bOffset_Discreet_40,
		(uint16_t)MB_offsetDiscreet_41,		(uint16_t)MB_bOffset_Discreet_41,
		(uint16_t)MB_offsetDiscreet_42,		(uint16_t)MB_bOffset_Discreet_42,
		(uint16_t)MB_offsetDiscreet_43,		(uint16_t)MB_bOffset_Discreet_43,
		(uint16_t)MB_offsetDiscreet_44,		(uint16_t)MB_bOffset_Discreet_44,
		(uint16_t)MB_offsetDiscreet_45,		(uint16_t)MB_bOffset_Discreet_45,
		(uint16_t)MB_offsetDiscreet_46,		(uint16_t)MB_bOffset_Discreet_46,
		(uint16_t)MB_offsetDiscreet_47,		(uint16_t)MB_bOffset_Discreet_47,
		(uint16_t)MB_offsetDiscreet_48,		(uint16_t)MB_bOffset_Discreet_48,
		(uint16_t)MB_offsetDiscreet_49,		(uint16_t)MB_bOffset_Discreet_49,
		(uint16_t)MB_offsetDiscreet_50,		(uint16_t)MB_bOffset_Discreet_50,
		(uint16_t)MB_offsetDiscreet_51,		(uint16_t)MB_bOffset_Discreet_51,
		(uint16_t)MB_offsetDiscreet_52,		(uint16_t)MB_bOffset_Discreet_52,
		(uint16_t)MB_offsetDiscreet_53,		(uint16_t)MB_bOffset_Discreet_53,
		(uint16_t)MB_offsetDiscreet_54,		(uint16_t)MB_bOffset_Discreet_54,
		(uint16_t)MB_offsetDiscreet_55,		(uint16_t)MB_bOffset_Discreet_55,
		(uint16_t)MB_offsetDiscreet_56,		(uint16_t)MB_bOffset_Discreet_56,
		(uint16_t)MB_offsetDiscreet_57,		(uint16_t)MB_bOffset_Discreet_57,
		(uint16_t)MB_offsetDiscreet_58,		(uint16_t)MB_bOffset_Discreet_58,
};

DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,		&iedModel_GGIO_INGGIO1_Ind8_q,
		&iedModel_GGIO_INGGIO1_Ind9_q,		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,		&iedModel_GGIO_INGGIO1_Ind16_q,
		&iedModel_GGIO_INGGIO1_Ind17_q,		&iedModel_GGIO_INGGIO1_Ind18_q,
		&iedModel_GGIO_INGGIO1_Ind19_q,		&iedModel_GGIO_INGGIO1_Ind20_q,
		&iedModel_GGIO_INGGIO1_Ind21_q,		&iedModel_GGIO_INGGIO1_Ind22_q,
		&iedModel_GGIO_INGGIO1_Ind23_q,		&iedModel_GGIO_INGGIO1_Ind24_q,
		&iedModel_GGIO_INGGIO1_Ind25_q,		&iedModel_GGIO_INGGIO1_Ind26_q,
		&iedModel_GGIO_INGGIO1_Ind27_q,		&iedModel_GGIO_INGGIO1_Ind28_q,
		&iedModel_GGIO_INGGIO1_Ind29_q,		&iedModel_GGIO_INGGIO1_Ind30_q,
		&iedModel_GGIO_INGGIO1_Ind31_q,		&iedModel_GGIO_INGGIO1_Ind32_q,
		&iedModel_GGIO_INGGIO1_Ind33_q,		&iedModel_GGIO_INGGIO1_Ind34_q,
		&iedModel_GGIO_INGGIO1_Ind35_q,		&iedModel_GGIO_INGGIO1_Ind36_q,
		&iedModel_GGIO_INGGIO1_Ind37_q,		&iedModel_GGIO_INGGIO1_Ind38_q,
		&iedModel_GGIO_INGGIO1_Ind39_q,		&iedModel_GGIO_INGGIO1_Ind40_q,
		&iedModel_GGIO_INGGIO1_Ind41_q,		&iedModel_GGIO_INGGIO1_Ind42_q,
		&iedModel_GGIO_INGGIO1_Ind43_q,		&iedModel_GGIO_INGGIO1_Ind44_q,
		&iedModel_GGIO_INGGIO1_Ind45_q,		&iedModel_GGIO_INGGIO1_Ind46_q,
		&iedModel_GGIO_INGGIO1_Ind47_q,		&iedModel_GGIO_INGGIO1_Ind48_q,
		&iedModel_GGIO_INGGIO1_Ind49_q,		&iedModel_GGIO_INGGIO1_Ind50_q,
		&iedModel_GGIO_INGGIO1_Ind51_q,		&iedModel_GGIO_INGGIO1_Ind52_q,
		&iedModel_GGIO_INGGIO1_Ind53_q,		&iedModel_GGIO_INGGIO1_Ind54_q,
		&iedModel_GGIO_INGGIO1_Ind55_q,		&iedModel_GGIO_INGGIO1_Ind56_q,
		&iedModel_GGIO_INGGIO1_Ind57_q,		&iedModel_GGIO_INGGIO1_Ind58_q,
};

DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,		&iedModel_GGIO_INGGIO1_Ind8_t,
		&iedModel_GGIO_INGGIO1_Ind9_t,		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,		&iedModel_GGIO_INGGIO1_Ind16_t,
		&iedModel_GGIO_INGGIO1_Ind17_t,		&iedModel_GGIO_INGGIO1_Ind18_t,
		&iedModel_GGIO_INGGIO1_Ind19_t,		&iedModel_GGIO_INGGIO1_Ind20_t,
		&iedModel_GGIO_INGGIO1_Ind21_t,		&iedModel_GGIO_INGGIO1_Ind22_t,
		&iedModel_GGIO_INGGIO1_Ind23_t,		&iedModel_GGIO_INGGIO1_Ind24_t,
		&iedModel_GGIO_INGGIO1_Ind25_t,		&iedModel_GGIO_INGGIO1_Ind26_t,
		&iedModel_GGIO_INGGIO1_Ind27_t,		&iedModel_GGIO_INGGIO1_Ind28_t,
		&iedModel_GGIO_INGGIO1_Ind29_t,		&iedModel_GGIO_INGGIO1_Ind30_t,
		&iedModel_GGIO_INGGIO1_Ind31_t,		&iedModel_GGIO_INGGIO1_Ind32_t,
		&iedModel_GGIO_INGGIO1_Ind33_t,		&iedModel_GGIO_INGGIO1_Ind34_t,
		&iedModel_GGIO_INGGIO1_Ind35_t,		&iedModel_GGIO_INGGIO1_Ind36_t,
		&iedModel_GGIO_INGGIO1_Ind37_t,		&iedModel_GGIO_INGGIO1_Ind38_t,
		&iedModel_GGIO_INGGIO1_Ind39_t,		&iedModel_GGIO_INGGIO1_Ind40_t,
		&iedModel_GGIO_INGGIO1_Ind41_t,		&iedModel_GGIO_INGGIO1_Ind42_t,
		&iedModel_GGIO_INGGIO1_Ind43_t,		&iedModel_GGIO_INGGIO1_Ind44_t,
		&iedModel_GGIO_INGGIO1_Ind45_t,		&iedModel_GGIO_INGGIO1_Ind46_t,
		&iedModel_GGIO_INGGIO1_Ind47_t,		&iedModel_GGIO_INGGIO1_Ind48_t,
		&iedModel_GGIO_INGGIO1_Ind49_t,		&iedModel_GGIO_INGGIO1_Ind50_t,
		&iedModel_GGIO_INGGIO1_Ind51_t,		&iedModel_GGIO_INGGIO1_Ind52_t,
		&iedModel_GGIO_INGGIO1_Ind53_t,		&iedModel_GGIO_INGGIO1_Ind54_t,
		&iedModel_GGIO_INGGIO1_Ind55_t,		&iedModel_GGIO_INGGIO1_Ind56_t,
		&iedModel_GGIO_INGGIO1_Ind57_t,		&iedModel_GGIO_INGGIO1_Ind58_t,

};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,		&iedModel_GGIO_INGGIO1_Ind8_stVal,
		&iedModel_GGIO_INGGIO1_Ind9_stVal,		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,		&iedModel_GGIO_INGGIO1_Ind16_stVal,
		&iedModel_GGIO_INGGIO1_Ind17_stVal,		&iedModel_GGIO_INGGIO1_Ind18_stVal,
		&iedModel_GGIO_INGGIO1_Ind19_stVal,		&iedModel_GGIO_INGGIO1_Ind20_stVal,
		&iedModel_GGIO_INGGIO1_Ind21_stVal,		&iedModel_GGIO_INGGIO1_Ind22_stVal,
		&iedModel_GGIO_INGGIO1_Ind23_stVal,		&iedModel_GGIO_INGGIO1_Ind24_stVal,
		&iedModel_GGIO_INGGIO1_Ind25_stVal,		&iedModel_GGIO_INGGIO1_Ind26_stVal,
		&iedModel_GGIO_INGGIO1_Ind27_stVal,		&iedModel_GGIO_INGGIO1_Ind28_stVal,
		&iedModel_GGIO_INGGIO1_Ind29_stVal,		&iedModel_GGIO_INGGIO1_Ind30_stVal,
		&iedModel_GGIO_INGGIO1_Ind31_stVal,		&iedModel_GGIO_INGGIO1_Ind32_stVal,
		&iedModel_GGIO_INGGIO1_Ind33_stVal,		&iedModel_GGIO_INGGIO1_Ind34_stVal,
		&iedModel_GGIO_INGGIO1_Ind35_stVal,		&iedModel_GGIO_INGGIO1_Ind36_stVal,
		&iedModel_GGIO_INGGIO1_Ind37_stVal,		&iedModel_GGIO_INGGIO1_Ind38_stVal,
		&iedModel_GGIO_INGGIO1_Ind39_stVal,		&iedModel_GGIO_INGGIO1_Ind40_stVal,
		&iedModel_GGIO_INGGIO1_Ind41_stVal,		&iedModel_GGIO_INGGIO1_Ind42_stVal,
		&iedModel_GGIO_INGGIO1_Ind43_stVal,		&iedModel_GGIO_INGGIO1_Ind44_stVal,
		&iedModel_GGIO_INGGIO1_Ind45_stVal,		&iedModel_GGIO_INGGIO1_Ind46_stVal,
		&iedModel_GGIO_INGGIO1_Ind47_stVal,		&iedModel_GGIO_INGGIO1_Ind48_stVal,
		&iedModel_GGIO_INGGIO1_Ind49_stVal,		&iedModel_GGIO_INGGIO1_Ind50_stVal,
		&iedModel_GGIO_INGGIO1_Ind51_stVal,		&iedModel_GGIO_INGGIO1_Ind52_stVal,
		&iedModel_GGIO_INGGIO1_Ind53_stVal,		&iedModel_GGIO_INGGIO1_Ind54_stVal,
		&iedModel_GGIO_INGGIO1_Ind55_stVal,		&iedModel_GGIO_INGGIO1_Ind56_stVal,
		&iedModel_GGIO_INGGIO1_Ind57_stVal,		&iedModel_GGIO_INGGIO1_Ind58_stVal,
};
/*******************************************************
 * OUTGGIO
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8,
		MB_offsetRelay_9,		MB_bOffset_Relay_9,
		MB_offsetRelay_10,		MB_bOffset_Relay_10,
		MB_offsetRelay_11,		MB_bOffset_Relay_11,
		MB_offsetRelay_12,		MB_bOffset_Relay_12,
		MB_offsetRelay_13,		MB_bOffset_Relay_13,
		MB_offsetRelay_14,		MB_bOffset_Relay_14,
		MB_offsetRelay_15,		MB_bOffset_Relay_15,
		MB_offsetRelay_16,		MB_bOffset_Relay_16,
		MB_offsetRelay_17,		MB_bOffset_Relay_17,
		MB_offsetRelay_18,		MB_bOffset_Relay_18,
		MB_offsetRelay_19,		MB_bOffset_Relay_19,
		MB_offsetRelay_20,		MB_bOffset_Relay_20,
		MB_offsetRelay_21,		MB_bOffset_Relay_21,
		MB_offsetRelay_22,		MB_bOffset_Relay_22,
		MB_offsetRelay_23,		MB_bOffset_Relay_23,
		MB_offsetRelay_24,		MB_bOffset_Relay_24,
		MB_offsetRelay_25,		MB_bOffset_Relay_25,
		MB_offsetRelay_26,		MB_bOffset_Relay_26,
		MB_offsetRelay_27,		MB_bOffset_Relay_27,
		MB_offsetRelay_28,		MB_bOffset_Relay_28,
		MB_offsetRelay_29,		MB_bOffset_Relay_29,
		MB_offsetRelay_30,		MB_bOffset_Relay_30,
		MB_offsetRelay_31,		MB_bOffset_Relay_31,
		MB_offsetRelay_32,		MB_bOffset_Relay_32,
		MB_offsetRelay_33,		MB_bOffset_Relay_33,
		MB_offsetRelay_34,		MB_bOffset_Relay_34,
		MB_offsetRelay_35,		MB_bOffset_Relay_35,
		MB_offsetRelay_36,		MB_bOffset_Relay_36,
		MB_offsetRelay_37,		MB_bOffset_Relay_37,
		MB_offsetRelay_38,		MB_bOffset_Relay_38,
		MB_offsetRelay_39,		MB_bOffset_Relay_39,
		MB_offsetRelay_40,		MB_bOffset_Relay_40,
		MB_offsetRelay_41,		MB_bOffset_Relay_41,
		MB_offsetRelay_42,		MB_bOffset_Relay_42,
		MB_offsetRelay_43,		MB_bOffset_Relay_43,
		MB_offsetRelay_44,		MB_bOffset_Relay_44,
		MB_offsetRelay_45,		MB_bOffset_Relay_45,
		MB_offsetRelay_46,		MB_bOffset_Relay_46,
		MB_offsetRelay_47,		MB_bOffset_Relay_47,
		MB_offsetRelay_48,		MB_bOffset_Relay_48,
		MB_offsetRelay_49,		MB_bOffset_Relay_49,
		MB_offsetRelay_50,		MB_bOffset_Relay_50,
};

DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,		&iedModel_GGIO_OUTGGIO1_SPCSO8_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_q,		&iedModel_GGIO_OUTGGIO1_SPCSO10_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_q,		&iedModel_GGIO_OUTGGIO1_SPCSO12_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_q,		&iedModel_GGIO_OUTGGIO1_SPCSO14_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_q,		&iedModel_GGIO_OUTGGIO1_SPCSO16_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_q,		&iedModel_GGIO_OUTGGIO1_SPCSO18_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_q,		&iedModel_GGIO_OUTGGIO1_SPCSO20_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_q,		&iedModel_GGIO_OUTGGIO1_SPCSO22_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_q,		&iedModel_GGIO_OUTGGIO1_SPCSO24_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_q,		&iedModel_GGIO_OUTGGIO1_SPCSO26_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_q,		&iedModel_GGIO_OUTGGIO1_SPCSO28_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_q,		&iedModel_GGIO_OUTGGIO1_SPCSO30_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_q,		&iedModel_GGIO_OUTGGIO1_SPCSO32_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_q,		&iedModel_GGIO_OUTGGIO1_SPCSO34_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO35_q,		&iedModel_GGIO_OUTGGIO1_SPCSO36_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_q,		&iedModel_GGIO_OUTGGIO1_SPCSO38_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_q,		&iedModel_GGIO_OUTGGIO1_SPCSO40_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_q,		&iedModel_GGIO_OUTGGIO1_SPCSO42_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_q,		&iedModel_GGIO_OUTGGIO1_SPCSO44_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_q,		&iedModel_GGIO_OUTGGIO1_SPCSO46_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_q,		&iedModel_GGIO_OUTGGIO1_SPCSO48_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_q,		&iedModel_GGIO_OUTGGIO1_SPCSO50_q,
};

DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,		&iedModel_GGIO_OUTGGIO1_SPCSO8_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_t,		&iedModel_GGIO_OUTGGIO1_SPCSO10_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_t,		&iedModel_GGIO_OUTGGIO1_SPCSO12_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_t,		&iedModel_GGIO_OUTGGIO1_SPCSO14_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_t,		&iedModel_GGIO_OUTGGIO1_SPCSO16_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_t,		&iedModel_GGIO_OUTGGIO1_SPCSO18_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_t,		&iedModel_GGIO_OUTGGIO1_SPCSO20_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_t,		&iedModel_GGIO_OUTGGIO1_SPCSO22_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_t,		&iedModel_GGIO_OUTGGIO1_SPCSO24_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_t,		&iedModel_GGIO_OUTGGIO1_SPCSO26_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_t,		&iedModel_GGIO_OUTGGIO1_SPCSO28_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_t,		&iedModel_GGIO_OUTGGIO1_SPCSO30_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_t,		&iedModel_GGIO_OUTGGIO1_SPCSO32_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_t,		&iedModel_GGIO_OUTGGIO1_SPCSO34_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO35_t,		&iedModel_GGIO_OUTGGIO1_SPCSO36_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_t,		&iedModel_GGIO_OUTGGIO1_SPCSO38_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_t,		&iedModel_GGIO_OUTGGIO1_SPCSO40_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_t,		&iedModel_GGIO_OUTGGIO1_SPCSO42_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_t,		&iedModel_GGIO_OUTGGIO1_SPCSO44_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_t,		&iedModel_GGIO_OUTGGIO1_SPCSO46_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_t,		&iedModel_GGIO_OUTGGIO1_SPCSO48_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_t,		&iedModel_GGIO_OUTGGIO1_SPCSO50_t,
};

DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO35_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO36_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO38_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO40_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO42_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO44_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO46_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO48_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO50_stVal,
};

/*******************************************************
 * LEDGGIO1
 *******************************************************/
uint16_t LED_G_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1g,		MB_bOffset_LED_1g,
		MB_offsetLED_2g,		MB_bOffset_LED_2g,
		MB_offsetLED_3g,		MB_bOffset_LED_3g,
		MB_offsetLED_4g,		MB_bOffset_LED_4g,
		MB_offsetLED_5g,		MB_bOffset_LED_5g,
		MB_offsetLED_6g,		MB_bOffset_LED_6g,
		MB_offsetLED_7g,		MB_bOffset_LED_7g,
		MB_offsetLED_8g,		MB_bOffset_LED_8g,
		MB_offsetLED_9g,		MB_bOffset_LED_9g,
		MB_offsetLED_10g,		MB_bOffset_LED_10g,
		MB_offsetLED_11g,		MB_bOffset_LED_11g,
		MB_offsetLED_12g,		MB_bOffset_LED_12g,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};
uint16_t LED_R_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1r,		MB_bOffset_LED_1r,
		MB_offsetLED_2r,		MB_bOffset_LED_2r,
		MB_offsetLED_3r,		MB_bOffset_LED_3r,
		MB_offsetLED_4r,		MB_bOffset_LED_4r,
		MB_offsetLED_5r,		MB_bOffset_LED_5r,
		MB_offsetLED_6r,		MB_bOffset_LED_6r,
		MB_offsetLED_7r,		MB_bOffset_LED_7r,
		MB_offsetLED_8r,		MB_bOffset_LED_8r,
		MB_offsetLED_9r,		MB_bOffset_LED_9r,
		MB_offsetLED_10r,		MB_bOffset_LED_10r,
		MB_offsetLED_11r,		MB_bOffset_LED_11r,
		MB_offsetLED_12r,		MB_bOffset_LED_12r,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};

DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_q[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_q,
		&iedModel_GGIO_LEDGGIO1_Ind2_q,
		&iedModel_GGIO_LEDGGIO1_Ind3_q,
		&iedModel_GGIO_LEDGGIO1_Ind4_q,
		&iedModel_GGIO_LEDGGIO1_Ind5_q,
		&iedModel_GGIO_LEDGGIO1_Ind6_q,
		&iedModel_GGIO_LEDGGIO1_Ind7_q,
		&iedModel_GGIO_LEDGGIO1_Ind8_q,
		&iedModel_GGIO_LEDGGIO1_Ind9_q,
		&iedModel_GGIO_LEDGGIO1_Ind10_q,
		&iedModel_GGIO_LEDGGIO1_Ind11_q,
		&iedModel_GGIO_LEDGGIO1_Ind12_q,
		&iedModel_GGIO_LEDGGIO1_Ind13_q,
		&iedModel_GGIO_LEDGGIO1_Ind14_q,
		&iedModel_GGIO_LEDGGIO1_Ind15_q,
		&iedModel_GGIO_LEDGGIO1_Ind16_q
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_t[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_t,
		&iedModel_GGIO_LEDGGIO1_Ind2_t,
		&iedModel_GGIO_LEDGGIO1_Ind3_t,
		&iedModel_GGIO_LEDGGIO1_Ind4_t,
		&iedModel_GGIO_LEDGGIO1_Ind5_t,
		&iedModel_GGIO_LEDGGIO1_Ind6_t,
		&iedModel_GGIO_LEDGGIO1_Ind7_t,
		&iedModel_GGIO_LEDGGIO1_Ind8_t,
		&iedModel_GGIO_LEDGGIO1_Ind9_t,
		&iedModel_GGIO_LEDGGIO1_Ind10_t,
		&iedModel_GGIO_LEDGGIO1_Ind11_t,
		&iedModel_GGIO_LEDGGIO1_Ind12_t,
		&iedModel_GGIO_LEDGGIO1_Ind13_t,
		&iedModel_GGIO_LEDGGIO1_Ind14_t,
		&iedModel_GGIO_LEDGGIO1_Ind15_t,
		&iedModel_GGIO_LEDGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_stVal[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind2_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind3_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind4_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind5_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind6_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind7_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind8_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind9_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind10_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind11_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind12_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind13_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind14_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind15_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind16_stVal
};
/*******************************************************
 * VLSGGIO
 *******************************************************/
uint16_t VLSBuf[MB_MaxNumbVLS][2] ={
		MB_offsetVLS_1,		MB_bOffset_VLS_1,
		MB_offsetVLS_2,		MB_bOffset_VLS_2,
		MB_offsetVLS_3,		MB_bOffset_VLS_3,
		MB_offsetVLS_4,		MB_bOffset_VLS_4,
		MB_offsetVLS_5,		MB_bOffset_VLS_5,
		MB_offsetVLS_6,		MB_bOffset_VLS_6,
		MB_offsetVLS_7,		MB_bOffset_VLS_7,
		MB_offsetVLS_8,		MB_bOffset_VLS_8,
		MB_offsetVLS_9,		MB_bOffset_VLS_9,
		MB_offsetVLS_10,	MB_bOffset_VLS_10,
		MB_offsetVLS_11,	MB_bOffset_VLS_11,
		MB_offsetVLS_12,	MB_bOffset_VLS_12,
		MB_offsetVLS_13,	MB_bOffset_VLS_13,
		MB_offsetVLS_14,	MB_bOffset_VLS_14,
		MB_offsetVLS_15,	MB_bOffset_VLS_15,
		MB_offsetVLS_16,	MB_bOffset_VLS_16,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_q[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_q,		&iedModel_GGIO_VLSGGIO1_Ind2_q,
		&iedModel_GGIO_VLSGGIO1_Ind3_q,		&iedModel_GGIO_VLSGGIO1_Ind4_q,
		&iedModel_GGIO_VLSGGIO1_Ind5_q,		&iedModel_GGIO_VLSGGIO1_Ind6_q,
		&iedModel_GGIO_VLSGGIO1_Ind7_q,		&iedModel_GGIO_VLSGGIO1_Ind8_q,
		&iedModel_GGIO_VLSGGIO1_Ind9_q,		&iedModel_GGIO_VLSGGIO1_Ind10_q,
		&iedModel_GGIO_VLSGGIO1_Ind11_q,	&iedModel_GGIO_VLSGGIO1_Ind12_q,
		&iedModel_GGIO_VLSGGIO1_Ind13_q,	&iedModel_GGIO_VLSGGIO1_Ind14_q,
		&iedModel_GGIO_VLSGGIO1_Ind15_q,	&iedModel_GGIO_VLSGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_t[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_t,		&iedModel_GGIO_VLSGGIO1_Ind2_t,
		&iedModel_GGIO_VLSGGIO1_Ind3_t,		&iedModel_GGIO_VLSGGIO1_Ind4_t,
		&iedModel_GGIO_VLSGGIO1_Ind5_t,		&iedModel_GGIO_VLSGGIO1_Ind6_t,
		&iedModel_GGIO_VLSGGIO1_Ind7_t,		&iedModel_GGIO_VLSGGIO1_Ind8_t,
		&iedModel_GGIO_VLSGGIO1_Ind9_t,		&iedModel_GGIO_VLSGGIO1_Ind10_t,
		&iedModel_GGIO_VLSGGIO1_Ind11_t,	&iedModel_GGIO_VLSGGIO1_Ind12_t,
		&iedModel_GGIO_VLSGGIO1_Ind13_t,	&iedModel_GGIO_VLSGGIO1_Ind14_t,
		&iedModel_GGIO_VLSGGIO1_Ind15_t,	&iedModel_GGIO_VLSGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_stVal[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_stVal,		&iedModel_GGIO_VLSGGIO1_Ind2_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind3_stVal,		&iedModel_GGIO_VLSGGIO1_Ind4_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind5_stVal,		&iedModel_GGIO_VLSGGIO1_Ind6_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind7_stVal,		&iedModel_GGIO_VLSGGIO1_Ind8_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind9_stVal,		&iedModel_GGIO_VLSGGIO1_Ind10_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind11_stVal,	&iedModel_GGIO_VLSGGIO1_Ind12_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind13_stVal,	&iedModel_GGIO_VLSGGIO1_Ind14_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind15_stVal,	&iedModel_GGIO_VLSGGIO1_Ind16_stVal,
};

/*******************************************************
 * LSGGIO
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,	MB_bOffset_LS_1,
		MB_offsetLS_2,	MB_bOffset_LS_2,
		MB_offsetLS_3,	MB_bOffset_LS_3,
		MB_offsetLS_4,	MB_bOffset_LS_4,
		MB_offsetLS_5,	MB_bOffset_LS_5,
		MB_offsetLS_6,	MB_bOffset_LS_6,
		MB_offsetLS_7,	MB_bOffset_LS_7,
		MB_offsetLS_8,	MB_bOffset_LS_8,
		MB_offsetLS_9,	MB_bOffset_LS_9,
		MB_offsetLS_10,	MB_bOffset_LS_10,
		MB_offsetLS_11,	MB_bOffset_LS_11,
		MB_offsetLS_12,	MB_bOffset_LS_12,
		MB_offsetLS_13,	MB_bOffset_LS_13,
		MB_offsetLS_14,	MB_bOffset_LS_14,
		MB_offsetLS_15,	MB_bOffset_LS_15,
		MB_offsetLS_16,	MB_bOffset_LS_16,
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,		&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,		&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,		&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,		&iedModel_GGIO_LSGGIO1_Ind8_q,
		&iedModel_GGIO_LSGGIO1_Ind9_q,		&iedModel_GGIO_LSGGIO1_Ind10_q,
		&iedModel_GGIO_LSGGIO1_Ind11_q,		&iedModel_GGIO_LSGGIO1_Ind12_q,
		&iedModel_GGIO_LSGGIO1_Ind13_q,		&iedModel_GGIO_LSGGIO1_Ind14_q,
		&iedModel_GGIO_LSGGIO1_Ind15_q,		&iedModel_GGIO_LSGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,		&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,		&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,		&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,		&iedModel_GGIO_LSGGIO1_Ind8_t,
		&iedModel_GGIO_LSGGIO1_Ind9_t,		&iedModel_GGIO_LSGGIO1_Ind10_t,
		&iedModel_GGIO_LSGGIO1_Ind11_t,		&iedModel_GGIO_LSGGIO1_Ind12_t,
		&iedModel_GGIO_LSGGIO1_Ind13_t,		&iedModel_GGIO_LSGGIO1_Ind14_t,
		&iedModel_GGIO_LSGGIO1_Ind15_t,		&iedModel_GGIO_LSGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,	&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,	&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,	&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,	&iedModel_GGIO_LSGGIO1_Ind8_stVal,
		&iedModel_GGIO_LSGGIO1_Ind9_stVal,	&iedModel_GGIO_LSGGIO1_Ind10_stVal,
		&iedModel_GGIO_LSGGIO1_Ind11_stVal,	&iedModel_GGIO_LSGGIO1_Ind12_stVal,
		&iedModel_GGIO_LSGGIO1_Ind13_stVal,	&iedModel_GGIO_LSGGIO1_Ind14_stVal,
		&iedModel_GGIO_LSGGIO1_Ind15_stVal,	&iedModel_GGIO_LSGGIO1_Ind16_stVal,
};
/*******************************************************
 * SSLGGIO
 *******************************************************/
uint16_t SSLBuf[MB_MaxNumbSSL][2] ={
		MB_offsetSSL_1,		MB_bOffset_SSL_1,
		MB_offsetSSL_2,		MB_bOffset_SSL_2,
		MB_offsetSSL_3,		MB_bOffset_SSL_3,
		MB_offsetSSL_4,		MB_bOffset_SSL_4,
		MB_offsetSSL_5,		MB_bOffset_SSL_5,
		MB_offsetSSL_6,		MB_bOffset_SSL_6,
		MB_offsetSSL_7,		MB_bOffset_SSL_7,
		MB_offsetSSL_8,		MB_bOffset_SSL_8,
		MB_offsetSSL_9,		MB_bOffset_SSL_9,
		MB_offsetSSL_10,	MB_bOffset_SSL_10,
		MB_offsetSSL_11,	MB_bOffset_SSL_11,
		MB_offsetSSL_12,	MB_bOffset_SSL_12,
		MB_offsetSSL_13,	MB_bOffset_SSL_13,
		MB_offsetSSL_14,	MB_bOffset_SSL_14,
		MB_offsetSSL_15,	MB_bOffset_SSL_15,
		MB_offsetSSL_16,	MB_bOffset_SSL_16,
		MB_offsetSSL_17,	MB_bOffset_SSL_17,
		MB_offsetSSL_18,	MB_bOffset_SSL_18,
		MB_offsetSSL_19,	MB_bOffset_SSL_19,
		MB_offsetSSL_20,	MB_bOffset_SSL_20,
		MB_offsetSSL_21,	MB_bOffset_SSL_21,
		MB_offsetSSL_22,	MB_bOffset_SSL_22,
		MB_offsetSSL_23,	MB_bOffset_SSL_23,
		MB_offsetSSL_24,	MB_bOffset_SSL_24,
		MB_offsetSSL_25,	MB_bOffset_SSL_25,
		MB_offsetSSL_26,	MB_bOffset_SSL_26,
		MB_offsetSSL_27,	MB_bOffset_SSL_27,
		MB_offsetSSL_28,	MB_bOffset_SSL_28,
		MB_offsetSSL_29,	MB_bOffset_SSL_29,
		MB_offsetSSL_30,	MB_bOffset_SSL_30,
		MB_offsetSSL_31,	MB_bOffset_SSL_31,
		MB_offsetSSL_32,	MB_bOffset_SSL_32,
		MB_offsetSSL_33,	MB_bOffset_SSL_33,
		MB_offsetSSL_34,	MB_bOffset_SSL_34,
		MB_offsetSSL_35,	MB_bOffset_SSL_35,
		MB_offsetSSL_36,	MB_bOffset_SSL_36,
		MB_offsetSSL_37,	MB_bOffset_SSL_37,
		MB_offsetSSL_38,	MB_bOffset_SSL_38,
		MB_offsetSSL_39,	MB_bOffset_SSL_39,
		MB_offsetSSL_40,	MB_bOffset_SSL_40,
		MB_offsetSSL_41,	MB_bOffset_SSL_41,
		MB_offsetSSL_42,	MB_bOffset_SSL_42,
		MB_offsetSSL_43,	MB_bOffset_SSL_43,
		MB_offsetSSL_44,	MB_bOffset_SSL_44,
		MB_offsetSSL_45,	MB_bOffset_SSL_45,
		MB_offsetSSL_46,	MB_bOffset_SSL_46,
		MB_offsetSSL_47,	MB_bOffset_SSL_47,
		MB_offsetSSL_48,	MB_bOffset_SSL_48,

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_q[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_q,		&iedModel_GGIO_SSLGGIO1_Ind2_q,
		&iedModel_GGIO_SSLGGIO1_Ind3_q,		&iedModel_GGIO_SSLGGIO1_Ind4_q,
		&iedModel_GGIO_SSLGGIO1_Ind5_q,		&iedModel_GGIO_SSLGGIO1_Ind6_q,
		&iedModel_GGIO_SSLGGIO1_Ind7_q,		&iedModel_GGIO_SSLGGIO1_Ind8_q,
		&iedModel_GGIO_SSLGGIO1_Ind9_q,		&iedModel_GGIO_SSLGGIO1_Ind10_q,
		&iedModel_GGIO_SSLGGIO1_Ind11_q,	&iedModel_GGIO_SSLGGIO1_Ind12_q,
		&iedModel_GGIO_SSLGGIO1_Ind13_q,	&iedModel_GGIO_SSLGGIO1_Ind14_q,
		&iedModel_GGIO_SSLGGIO1_Ind15_q,	&iedModel_GGIO_SSLGGIO1_Ind16_q,
		&iedModel_GGIO_SSLGGIO1_Ind17_q,	&iedModel_GGIO_SSLGGIO1_Ind18_q,
		&iedModel_GGIO_SSLGGIO1_Ind19_q,	&iedModel_GGIO_SSLGGIO1_Ind20_q,
		&iedModel_GGIO_SSLGGIO1_Ind21_q,	&iedModel_GGIO_SSLGGIO1_Ind22_q,
		&iedModel_GGIO_SSLGGIO1_Ind23_q,	&iedModel_GGIO_SSLGGIO1_Ind24_q,
		&iedModel_GGIO_SSLGGIO1_Ind25_q,	&iedModel_GGIO_SSLGGIO1_Ind26_q,
		&iedModel_GGIO_SSLGGIO1_Ind27_q,	&iedModel_GGIO_SSLGGIO1_Ind28_q,
		&iedModel_GGIO_SSLGGIO1_Ind29_q,	&iedModel_GGIO_SSLGGIO1_Ind30_q,
		&iedModel_GGIO_SSLGGIO1_Ind31_q,	&iedModel_GGIO_SSLGGIO1_Ind32_q,
		&iedModel_GGIO_SSLGGIO1_Ind33_q,	&iedModel_GGIO_SSLGGIO1_Ind34_q,
		&iedModel_GGIO_SSLGGIO1_Ind35_q,	&iedModel_GGIO_SSLGGIO1_Ind36_q,
		&iedModel_GGIO_SSLGGIO1_Ind37_q,	&iedModel_GGIO_SSLGGIO1_Ind38_q,
		&iedModel_GGIO_SSLGGIO1_Ind39_q,	&iedModel_GGIO_SSLGGIO1_Ind40_q,
		&iedModel_GGIO_SSLGGIO1_Ind41_q,	&iedModel_GGIO_SSLGGIO1_Ind42_q,
		&iedModel_GGIO_SSLGGIO1_Ind43_q,	&iedModel_GGIO_SSLGGIO1_Ind44_q,
		&iedModel_GGIO_SSLGGIO1_Ind45_q,	&iedModel_GGIO_SSLGGIO1_Ind46_q,
		&iedModel_GGIO_SSLGGIO1_Ind47_q,	&iedModel_GGIO_SSLGGIO1_Ind48_q,

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_t[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_t,		&iedModel_GGIO_SSLGGIO1_Ind2_t,
		&iedModel_GGIO_SSLGGIO1_Ind3_t,		&iedModel_GGIO_SSLGGIO1_Ind4_t,
		&iedModel_GGIO_SSLGGIO1_Ind5_t,		&iedModel_GGIO_SSLGGIO1_Ind6_t,
		&iedModel_GGIO_SSLGGIO1_Ind7_t,		&iedModel_GGIO_SSLGGIO1_Ind8_t,
		&iedModel_GGIO_SSLGGIO1_Ind9_t,		&iedModel_GGIO_SSLGGIO1_Ind10_t,
		&iedModel_GGIO_SSLGGIO1_Ind11_t,	&iedModel_GGIO_SSLGGIO1_Ind12_t,
		&iedModel_GGIO_SSLGGIO1_Ind13_t,	&iedModel_GGIO_SSLGGIO1_Ind14_t,
		&iedModel_GGIO_SSLGGIO1_Ind15_t,	&iedModel_GGIO_SSLGGIO1_Ind16_t,
		&iedModel_GGIO_SSLGGIO1_Ind17_t,	&iedModel_GGIO_SSLGGIO1_Ind18_t,
		&iedModel_GGIO_SSLGGIO1_Ind19_t,	&iedModel_GGIO_SSLGGIO1_Ind20_t,
		&iedModel_GGIO_SSLGGIO1_Ind21_t,	&iedModel_GGIO_SSLGGIO1_Ind22_t,
		&iedModel_GGIO_SSLGGIO1_Ind23_t,	&iedModel_GGIO_SSLGGIO1_Ind24_t,
		&iedModel_GGIO_SSLGGIO1_Ind25_t,	&iedModel_GGIO_SSLGGIO1_Ind26_t,
		&iedModel_GGIO_SSLGGIO1_Ind27_t,	&iedModel_GGIO_SSLGGIO1_Ind28_t,
		&iedModel_GGIO_SSLGGIO1_Ind29_t,	&iedModel_GGIO_SSLGGIO1_Ind30_t,
		&iedModel_GGIO_SSLGGIO1_Ind31_t,	&iedModel_GGIO_SSLGGIO1_Ind32_t,
		&iedModel_GGIO_SSLGGIO1_Ind33_t,	&iedModel_GGIO_SSLGGIO1_Ind34_t,
		&iedModel_GGIO_SSLGGIO1_Ind35_t,	&iedModel_GGIO_SSLGGIO1_Ind36_t,
		&iedModel_GGIO_SSLGGIO1_Ind37_t,	&iedModel_GGIO_SSLGGIO1_Ind38_t,
		&iedModel_GGIO_SSLGGIO1_Ind39_t,	&iedModel_GGIO_SSLGGIO1_Ind40_t,
		&iedModel_GGIO_SSLGGIO1_Ind41_t,	&iedModel_GGIO_SSLGGIO1_Ind42_t,
		&iedModel_GGIO_SSLGGIO1_Ind43_t,	&iedModel_GGIO_SSLGGIO1_Ind44_t,
		&iedModel_GGIO_SSLGGIO1_Ind45_t,	&iedModel_GGIO_SSLGGIO1_Ind46_t,
		&iedModel_GGIO_SSLGGIO1_Ind47_t,	&iedModel_GGIO_SSLGGIO1_Ind48_t,

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_stVal[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_stVal,		&iedModel_GGIO_SSLGGIO1_Ind2_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind3_stVal,		&iedModel_GGIO_SSLGGIO1_Ind4_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind5_stVal,		&iedModel_GGIO_SSLGGIO1_Ind6_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind7_stVal,		&iedModel_GGIO_SSLGGIO1_Ind8_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind9_stVal,		&iedModel_GGIO_SSLGGIO1_Ind10_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind11_stVal,	&iedModel_GGIO_SSLGGIO1_Ind12_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind13_stVal,	&iedModel_GGIO_SSLGGIO1_Ind14_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind15_stVal,	&iedModel_GGIO_SSLGGIO1_Ind16_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind17_stVal,	&iedModel_GGIO_SSLGGIO1_Ind18_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind19_stVal,	&iedModel_GGIO_SSLGGIO1_Ind20_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind21_stVal,	&iedModel_GGIO_SSLGGIO1_Ind22_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind23_stVal,	&iedModel_GGIO_SSLGGIO1_Ind24_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind25_stVal,	&iedModel_GGIO_SSLGGIO1_Ind26_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind27_stVal,	&iedModel_GGIO_SSLGGIO1_Ind28_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind29_stVal,	&iedModel_GGIO_SSLGGIO1_Ind30_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind31_stVal,	&iedModel_GGIO_SSLGGIO1_Ind32_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind33_stVal,	&iedModel_GGIO_SSLGGIO1_Ind34_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind35_stVal,	&iedModel_GGIO_SSLGGIO1_Ind36_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind37_stVal,	&iedModel_GGIO_SSLGGIO1_Ind38_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind39_stVal,	&iedModel_GGIO_SSLGGIO1_Ind40_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind41_stVal,	&iedModel_GGIO_SSLGGIO1_Ind42_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind43_stVal,	&iedModel_GGIO_SSLGGIO1_Ind44_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind45_stVal,	&iedModel_GGIO_SSLGGIO1_Ind46_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind47_stVal,	&iedModel_GGIO_SSLGGIO1_Ind48_stVal,
};

/*******************************************************
 * RSTGGIO
 *******************************************************/
uint16_t RSTBuf[MB_MaxNumbRST][2] ={
		MB_offsetRST_1,	MB_bOffset_RST_1,
		MB_offsetRST_2,	MB_bOffset_RST_2,
		MB_offsetRST_3,	MB_bOffset_RST_3,
		MB_offsetRST_4,	MB_bOffset_RST_4,
		MB_offsetRST_5,	MB_bOffset_RST_5,
		MB_offsetRST_6,	MB_bOffset_RST_6,
		MB_offsetRST_7,	MB_bOffset_RST_7,
		MB_offsetRST_8,	MB_bOffset_RST_8,
		MB_offsetRST_9,	MB_bOffset_RST_9,
		MB_offsetRST_10,MB_bOffset_RST_10,
		MB_offsetRST_11,MB_bOffset_RST_11,
		MB_offsetRST_12,MB_bOffset_RST_12,
		MB_offsetRST_13,MB_bOffset_RST_13,
		MB_offsetRST_14,MB_bOffset_RST_14,
		MB_offsetRST_15,MB_bOffset_RST_15,
		MB_offsetRST_16,MB_bOffset_RST_16,
};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_q[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_q,			&iedModel_GGIO_RSTGGIO1_Ind2_q,
		&iedModel_GGIO_RSTGGIO1_Ind3_q,			&iedModel_GGIO_RSTGGIO1_Ind4_q,
		&iedModel_GGIO_RSTGGIO1_Ind5_q,			&iedModel_GGIO_RSTGGIO1_Ind6_q,
		&iedModel_GGIO_RSTGGIO1_Ind7_q,			&iedModel_GGIO_RSTGGIO1_Ind8_q,
		&iedModel_GGIO_RSTGGIO1_Ind9_q,			&iedModel_GGIO_RSTGGIO1_Ind10_q,
		&iedModel_GGIO_RSTGGIO1_Ind11_q,		&iedModel_GGIO_RSTGGIO1_Ind12_q,
		&iedModel_GGIO_RSTGGIO1_Ind13_q,		&iedModel_GGIO_RSTGGIO1_Ind14_q,
		&iedModel_GGIO_RSTGGIO1_Ind15_q,		&iedModel_GGIO_RSTGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_t[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_t,			&iedModel_GGIO_RSTGGIO1_Ind2_t,
		&iedModel_GGIO_RSTGGIO1_Ind3_t,			&iedModel_GGIO_RSTGGIO1_Ind4_t,
		&iedModel_GGIO_RSTGGIO1_Ind5_t,			&iedModel_GGIO_RSTGGIO1_Ind6_t,
		&iedModel_GGIO_RSTGGIO1_Ind7_t,			&iedModel_GGIO_RSTGGIO1_Ind8_t,
		&iedModel_GGIO_RSTGGIO1_Ind9_t,			&iedModel_GGIO_RSTGGIO1_Ind10_t,
		&iedModel_GGIO_RSTGGIO1_Ind11_t,		&iedModel_GGIO_RSTGGIO1_Ind12_t,
		&iedModel_GGIO_RSTGGIO1_Ind13_t,		&iedModel_GGIO_RSTGGIO1_Ind14_t,
		&iedModel_GGIO_RSTGGIO1_Ind15_t,		&iedModel_GGIO_RSTGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_stVal[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_stVal,		&iedModel_GGIO_RSTGGIO1_Ind2_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind3_stVal,		&iedModel_GGIO_RSTGGIO1_Ind4_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind5_stVal,		&iedModel_GGIO_RSTGGIO1_Ind6_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind7_stVal,		&iedModel_GGIO_RSTGGIO1_Ind8_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind9_stVal,		&iedModel_GGIO_RSTGGIO1_Ind10_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind11_stVal,	&iedModel_GGIO_RSTGGIO1_Ind12_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind13_stVal,	&iedModel_GGIO_RSTGGIO1_Ind14_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind15_stVal,	&iedModel_GGIO_RSTGGIO1_Ind16_stVal,
};
#endif
/*******************************************************
 * MR801 T12N5D58R51
 *******************************************************/
#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"

extern 	uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];
#if (MB_Size_ConfigAWR > 0)
extern	uint16_t   ucConfigAWRBuf[MB_Size_ConfigAWR];
#endif
/*******************************************************
 * ��������
 *******************************************************/

int	Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}


/*******************************************************
 * Set_AVRGGIO ��������� ������������ �������
 *******************************************************/
int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;

	uint64_t 	diskreet;
	uint32_t 	BLKAVR,BLKAVR1;
	uint32_t	Mod;
	uint32_t	Health;

	//  Mod Beh

		if ((ucMUstavkiInBuf[MB_Addr_ConfigAWR + MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

		BLKAVR = ucMUstavkiInBuf[MB_Addr_ConfigAWR + MB_offset_InBlok];						// ����� ��������
		if (BLKAVR) {

			diskreet = (uint64_t)ucMDiscInBuf[0] | (uint64_t)ucMDiscInBuf[1]<<16 | (uint64_t)ucMDiscInBuf[2]<<32 | (uint64_t)ucMDiscInBuf[3]<<48;

			BLKAVR1 = (BLKAVR - 1)%2;
			BLKAVR = (BLKAVR - 1)/2;

			if (BLKAVR1 > 0) {							// ���� �� ����� ��������� �� ��������� ���������
				if ((diskreet & 1<<BLKAVR) == 0) Mod = STVALINT32_BLOCKED;
			} else{
				if ((diskreet & 1<<BLKAVR)>0) Mod = STVALINT32_BLOCKED;
			}
		}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
		}
//Health
Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

		uint8_t	awr=0;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
			ret = true;
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,Qual);
return ret;
}
/*******************************************************
 * Set_NBLKGGIO ��������� ������������ �������
 *******************************************************/
int	Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint64_t diskreet;
	uint32_t BLKAVR,BLKAVR1;
	uint32_t	Mod = STVALINT32_OFF;


	//  Mod Beh

		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Hot] >0) {Mod = STVALINT32_ON;}
		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Cold] >0) {Mod = STVALINT32_ON;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_t, currentTime);
		}

		//Health
		uint32_t	Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_q,Qual);

		uint8_t	nblk=0;
			if(ucMDiscInBuf[MB_offset_BlkN] & MB_b_BlkN)  nblk = 1;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_stVal, nblk)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_t, currentTime);
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_IntIn_q,Qual);
}
/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 * �������� ������: 1( 2��) - Ind57-58
 * 					2(24��) - Ind1-24
 * 					3(16��) - Ind25-Ind40
 * 					4(16��) - Ind41-Ind56
 *******************************************************/
int		Set_INGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	uint8_t 	i;
	int			ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 = QUALITY_VALIDITY_GOOD;
	bool		Q,T;
	uint16_t	num = QTnum & 0b0000111111111111;			// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����

// Health -----------------------------------------------------------------------
	if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0)		{Health = STVALINT32_Warning;}
//	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}
// Mod Beh -----------------------------------------------------------------------
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)	qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)	qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)	qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0)	qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	for (i = 0; i < MB_MaxNumbDiscreet; i++) {
		if ((num == 0) || (num == i+1)){
			// GOOSE ���������� �����, ���� �� ��������� ���� ������� ������� ������� ������� �� �������� ���� �� �������
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}

			if (Q) {
				int nm = i+1;
				if (nm>=_begin_Discreet_M1 && nm<=_end_Discreet_M1) quality = qualityM1; else
				if (nm>=_begin_Discreet_M2 && nm<=_end_Discreet_M2) quality = qualityM2; else
				if (nm>=_begin_Discreet_M3 && nm<=_end_Discreet_M3) quality = qualityM3; else
				if (nm>=_begin_Discreet_M4 && nm<=_end_Discreet_M4) quality = qualityM4; else {}

				if (IedServer_updateQuality(iedServer, iedModel_GGIO_INGGIO1_Ind_q[i],quality)){
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}
			}//! if (Q)...
		}//!if ((num...
	}//!for (i...

return	ret;
}

/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
int		Set_OUTGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality  = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbRelay)	return ret;
// -----------------------------------------------------------------------------

	if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)	qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)	qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)	qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)>0)	qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// ~2K ������������ ���� ������ ��� ������ ����������
	// �������� �� ����
	for (i = 0; i < MB_MaxNumbRelay; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}

			if (Q) {
				int nm = i+1;
				if (nm>=_begin_Relay_M1 && nm<=_end_Relay_M1) quality = qualityM1; else
				if (nm>=_begin_Relay_M2 && nm<=_end_Relay_M2) quality = qualityM2; else
				if (nm>=_begin_Relay_M3 && nm<=_end_Relay_M3) quality = qualityM3; else
				if (nm>=_begin_Relay_M4 && nm<=_end_Relay_M4) quality = qualityM4; else {}

				if (IedServer_updateQuality(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_q[i],quality)) {
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
			}//!if (Q)
		}
	}//!for (i...
return	ret;
}
/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *******************************************************/
int		Set_LEDGGIO		(uint16_t QTnum, uint64_t currentTime ){
	bool value;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbLED)	return ret;
// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	for (i = 0; i < MB_MaxNumbLED; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LEDGGIO1_Ind_q[i],quality)) ret = true;

			value = ((ucMDiscInBuf[LED_G_Buf[i][0]] & LED_G_Buf[i][1]) || (ucMDiscInBuf[LED_R_Buf[i][0]] & LED_R_Buf[i][1]));
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],iedModel_GGIO_LEDGGIO1_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],  value);}

		}
	}
return	ret;
}

/*******************************************************
 * Set_SSLGGIO ��������� ������������ �������
 *******************************************************/
int		Set_SSLGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint8_t	i;
		int	ret = false;
		// �������� � ����� ������ �� ���������� ---------------------------------------
			Quality		quality = QUALITY_VALIDITY_GOOD;
			bool		Q;
			bool		T;
			uint16_t	num;
			num = QTnum & 0b0000111111111111;						// ����� ��������
			if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
			if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
			if(num > MB_MaxNumbSSL)	return ret;
		// -----------------------------------------------------------------------------
		uint32_t	Mod 	= STVALINT32_OFF;
		uint32_t	Health 	= STVALINT32_OK;

		if ((ucMDiscInBuf[MB_offset_errorALLLogic] & MB_bOffset_errorALLLogic)>0) 	{Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)>0)			Mod	= STVALINT32_ON;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
		}

		// �������� �� ����
		for (i = 0; i < MB_MaxNumbSSL; i++) {
			if (num == 0 || num == i+1){
				if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_SSLGGIO_Ind_q[i],quality)) ret = true;

				bool value = ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1];
				// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
				if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],iedModel_GGIO_SSLGGIO_Ind_t[i],currentTime,  value);}
				// ���� ����� �� ����� (��� �����) �� ������ ������ ������
				else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  value);}
			}
		}
	return ret;
}

/*******************************************************
 * Set_VLSGGIO ��������� ������������ �������
 *******************************************************/
int		Set_VLSGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbVLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbVLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VLSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[VLSBuf[i][0]] & VLSBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],iedModel_GGIO_VLSGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}

/*******************************************************
 * Set_LSGGIO ��������� ������������ �������
 *******************************************************/
int		Set_LSGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[LSBuf[i][0]] & LSBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],iedModel_GGIO_LSGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}

/*******************************************************
 * Set_RSTGGIO ��������� ������������ �������
 *******************************************************/
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbRST)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbRST; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_RSTGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[RSTBuf[i][0]] & RSTBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_RSTGGIO_Ind_stVal[i],iedModel_GGIO_RSTGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_RSTGGIO_Ind_stVal[i],  value);}

		}
	}//!for (i...
return ret;
}

/*******************************************************
 * Set_VZGGIO ��������� ������������ �������
 *******************************************************/
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	int			i;
	int			ret = false;

// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbVZ)	return ret;
// -----------------------------------------------------------------------------

// Alm -----------------------------------------------------------------------
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorHard] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){

			if (Q){
				if (T) {ret |= IedServer_updateQualityWithTime	(iedServer, iedModel_VZGGIO_Ind_q[i],iedModel_VZGGIO_Ind_t[i],currentTime,  quality);}
				else   {ret |= IedServer_updateQuality			(iedServer, iedModel_VZGGIO_Ind_q[i],  quality);}
			}

			bool value = ucMDiscInBuf[VZBuf[i][0]] & VZBuf[i][1];
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_VZGGIO_Alm_stVal[i],iedModel_VZGGIO_Ind_t[i],currentTime,  value);}
			else   {ret |= IedServer_updateBooleanAttributeValue		(iedServer, iedModel_VZGGIO_Alm_stVal[i],  value);}
		}
	}//!for (i...
// -----------------------------------------------------------------------------

// Health ----------------------------------------------------------------------
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){
			if (T) {ret |= IedServer_updateInt32AttributeValueWithTime(iedServer, iedModel_VZGGIO_Health_stVal[i],iedModel_VZGGIO_Health_t[i],currentTime,  Health);}
			else   {ret |= IedServer_updateInt32AttributeValue(iedServer, iedModel_VZGGIO_Health_stVal[i], Health);}
		}
	}//!for (i...
// -----------------------------------------------------------------------------

//  Mod Beh --------------------------------------------------------------------
	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){

			if ((ucMUstavkiInBuf[VZCFGBuf[i] + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

			if (T) {ret |= IedServer_updateInt32AttributeValueWithTime	(iedServer, iedModel_VZGGIO_Mod_stVal[i],iedModel_VZGGIO_Mod_t[i],currentTime,  Mod);}
			else   {ret |= IedServer_updateInt32AttributeValue			(iedServer, iedModel_VZGGIO_Mod_stVal[i], Mod);}
			if (T) {ret |= IedServer_updateInt32AttributeValueWithTime	(iedServer, iedModel_VZGGIO_Beh_stVal[i],iedModel_VZGGIO_Beh_t[i],currentTime,  Mod);}
			else   {ret |= IedServer_updateInt32AttributeValue			(iedServer, iedModel_VZGGIO_Beh_stVal[i], Mod);}

		}
	}//!for (i...
// -----------------------------------------------------------------------------

//  Quality (Mod Beh) ----------------------------------------------------------
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorHard] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){

			if (T) {ret |= IedServer_updateQualityWithTime	(iedServer, iedModel_VZGGIO_Mod_q[i],iedModel_VZGGIO_Mod_t[i],currentTime,  quality);}
			else   {ret |= IedServer_updateQuality			(iedServer, iedModel_VZGGIO_Mod_q[i], quality);}
			if (T) {ret |= IedServer_updateQualityWithTime	(iedServer, iedModel_VZGGIO_Beh_q[i],iedModel_VZGGIO_Beh_t[i],currentTime,  quality);}
			else   {ret |= IedServer_updateQuality			(iedServer, iedModel_VZGGIO_Beh_q[i], quality);}

		}
	}//!for (i...
// -----------------------------------------------------------------------------
return ret;
}
#endif
/*******************************************************
 * MR801 OLD
 *******************************************************/
#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"

extern 	uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern	uint16_t   ucConfigAWRBuf[MB_Size_ConfigAWR];


/*******************************************************
 * ��������
 *******************************************************/

int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_VZGGIO ��������� ������������ �������
 *******************************************************/

int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;

			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
			}

//  Mod Beh

			if ((ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,quality);
			}

//				uint32_t	Alm;

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// ���� >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// ����
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);

			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);

			}
}

/*******************************************************
 * Set_AVRGGIO ��������� ������������ �������
 *******************************************************/

int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;
	uint8_t		awr;

			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
			}

//  Mod Beh

			if ((ucConfigAWRBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_t, currentTime);
			}

			awr=0;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);

			quality = QUALITY_VALIDITY_GOOD;
			if (STVALINT32_Warning == Health) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			 if (IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,quality)){
				 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
			 }
}
/*******************************************************
 * Set_XCBRGGIO ��������� ������������ �������
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// ����� ������
/*
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
*/
}

/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={
		(uint16_t)MB_offsetDiscreet_1,		(uint16_t)MB_bOffset_Discreet_1,
		(uint16_t)MB_offsetDiscreet_2,		(uint16_t)MB_bOffset_Discreet_2,
		(uint16_t)MB_offsetDiscreet_3,		(uint16_t)MB_bOffset_Discreet_3,
		(uint16_t)MB_offsetDiscreet_4,		(uint16_t)MB_bOffset_Discreet_4,
		(uint16_t)MB_offsetDiscreet_5,		(uint16_t)MB_bOffset_Discreet_5,
		(uint16_t)MB_offsetDiscreet_6,		(uint16_t)MB_bOffset_Discreet_6,
		(uint16_t)MB_offsetDiscreet_7,		(uint16_t)MB_bOffset_Discreet_7,
		(uint16_t)MB_offsetDiscreet_8,		(uint16_t)MB_bOffset_Discreet_8,
		(uint16_t)MB_offsetDiscreet_9,		(uint16_t)MB_bOffset_Discreet_9,
		(uint16_t)MB_offsetDiscreet_10,		(uint16_t)MB_bOffset_Discreet_10,
		(uint16_t)MB_offsetDiscreet_11,		(uint16_t)MB_bOffset_Discreet_11,
		(uint16_t)MB_offsetDiscreet_12,		(uint16_t)MB_bOffset_Discreet_12,
		(uint16_t)MB_offsetDiscreet_13,		(uint16_t)MB_bOffset_Discreet_13,
		(uint16_t)MB_offsetDiscreet_14,		(uint16_t)MB_bOffset_Discreet_14,
		(uint16_t)MB_offsetDiscreet_15,		(uint16_t)MB_bOffset_Discreet_15,
		(uint16_t)MB_offsetDiscreet_16,		(uint16_t)MB_bOffset_Discreet_16,
		(uint16_t)MB_offsetDiscreet_17,		(uint16_t)MB_bOffset_Discreet_17,
		(uint16_t)MB_offsetDiscreet_18,		(uint16_t)MB_bOffset_Discreet_18,
		(uint16_t)MB_offsetDiscreet_19,		(uint16_t)MB_bOffset_Discreet_19,
		(uint16_t)MB_offsetDiscreet_20,		(uint16_t)MB_bOffset_Discreet_20,
		(uint16_t)MB_offsetDiscreet_21,		(uint16_t)MB_bOffset_Discreet_21,
		(uint16_t)MB_offsetDiscreet_22,		(uint16_t)MB_bOffset_Discreet_22,
		(uint16_t)MB_offsetDiscreet_23,		(uint16_t)MB_bOffset_Discreet_23,
		(uint16_t)MB_offsetDiscreet_24,		(uint16_t)MB_bOffset_Discreet_24,
#if (_REVISION_DEVICE>=	208)
		(uint16_t)MB_offsetDiscreet_25,		(uint16_t)MB_bOffset_Discreet_25,
		(uint16_t)MB_offsetDiscreet_26,		(uint16_t)MB_bOffset_Discreet_26,
#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,		&iedModel_GGIO_INGGIO1_Ind8_q,
		&iedModel_GGIO_INGGIO1_Ind9_q,		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,		&iedModel_GGIO_INGGIO1_Ind16_q,
		&iedModel_GGIO_INGGIO1_Ind17_q,		&iedModel_GGIO_INGGIO1_Ind18_q,
		&iedModel_GGIO_INGGIO1_Ind19_q,		&iedModel_GGIO_INGGIO1_Ind20_q,
		&iedModel_GGIO_INGGIO1_Ind21_q,		&iedModel_GGIO_INGGIO1_Ind22_q,
		&iedModel_GGIO_INGGIO1_Ind23_q,		&iedModel_GGIO_INGGIO1_Ind24_q,
		&iedModel_GGIO_INGGIO1_Ind25_q,		&iedModel_GGIO_INGGIO1_Ind26_q,
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,		&iedModel_GGIO_INGGIO1_Ind8_t,
		&iedModel_GGIO_INGGIO1_Ind9_t,		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,		&iedModel_GGIO_INGGIO1_Ind16_t,
		&iedModel_GGIO_INGGIO1_Ind17_t,		&iedModel_GGIO_INGGIO1_Ind18_t,
		&iedModel_GGIO_INGGIO1_Ind19_t,		&iedModel_GGIO_INGGIO1_Ind20_t,
		&iedModel_GGIO_INGGIO1_Ind21_t,		&iedModel_GGIO_INGGIO1_Ind22_t,
		&iedModel_GGIO_INGGIO1_Ind23_t,		&iedModel_GGIO_INGGIO1_Ind24_t,
		&iedModel_GGIO_INGGIO1_Ind25_t,		&iedModel_GGIO_INGGIO1_Ind26_t,
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,		&iedModel_GGIO_INGGIO1_Ind8_stVal,
		&iedModel_GGIO_INGGIO1_Ind9_stVal,		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,		&iedModel_GGIO_INGGIO1_Ind16_stVal,
		&iedModel_GGIO_INGGIO1_Ind17_stVal,		&iedModel_GGIO_INGGIO1_Ind18_stVal,
		&iedModel_GGIO_INGGIO1_Ind19_stVal,		&iedModel_GGIO_INGGIO1_Ind20_stVal,
		&iedModel_GGIO_INGGIO1_Ind21_stVal,		&iedModel_GGIO_INGGIO1_Ind22_stVal,
		&iedModel_GGIO_INGGIO1_Ind23_stVal,		&iedModel_GGIO_INGGIO1_Ind24_stVal,
		&iedModel_GGIO_INGGIO1_Ind25_stVal,		&iedModel_GGIO_INGGIO1_Ind26_stVal

};
// --------------------------------------------------------------------------
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	uint8_t 	i;
	int			ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	bool		Q,T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
//	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------

	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0) 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	// ���������� ������ ���� �� ��������� �� ������� ��������� ������ ����
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0)		qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	for (i = 0; i < MB_MaxNumbDiscreet; i++) {
		if ((num == 0) || (num == i+1)){
			// GOOSE ���������� �����, ���� �� ��������� ���� ������� �������
			// ������� ������� �� �������� ���� �� �������
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}

			if (Q) {
				if (i>=0 && i<8)  quality = qualityM2; else
				if (i>7 && i<24)  quality = qualityM3; else
				if (i>23 && i<26) quality = qualityM1;
				if (IedServer_updateQuality(iedServer, iedModel_GGIO_INGGIO1_Ind_q[i],quality)){
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}
			}
		}
	}

return	ret;
}

/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8,
		MB_offsetRelay_9,		MB_bOffset_Relay_9,
		MB_offsetRelay_10,		MB_bOffset_Relay_10,
		MB_offsetRelay_11,		MB_bOffset_Relay_11,
		MB_offsetRelay_12,		MB_bOffset_Relay_12,
		MB_offsetRelay_13,		MB_bOffset_Relay_13,
		MB_offsetRelay_14,		MB_bOffset_Relay_14,
		MB_offsetRelay_15,		MB_bOffset_Relay_15,
		MB_offsetRelay_16,		MB_bOffset_Relay_16,
		MB_offsetRelay_17,		MB_bOffset_Relay_17,
		MB_offsetRelay_18,		MB_bOffset_Relay_18
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,		&iedModel_GGIO_OUTGGIO1_SPCSO8_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_q,		&iedModel_GGIO_OUTGGIO1_SPCSO10_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_q,		&iedModel_GGIO_OUTGGIO1_SPCSO12_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_q,		&iedModel_GGIO_OUTGGIO1_SPCSO14_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_q,		&iedModel_GGIO_OUTGGIO1_SPCSO16_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_q,		&iedModel_GGIO_OUTGGIO1_SPCSO18_q
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,		&iedModel_GGIO_OUTGGIO1_SPCSO8_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_t,		&iedModel_GGIO_OUTGGIO1_SPCSO10_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_t,		&iedModel_GGIO_OUTGGIO1_SPCSO12_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_t,		&iedModel_GGIO_OUTGGIO1_SPCSO14_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_t,		&iedModel_GGIO_OUTGGIO1_SPCSO16_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_t,		&iedModel_GGIO_OUTGGIO1_SPCSO18_t
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO18_stVal
};
//------------------------------------------------------------------------
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality  = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbRelay)	return ret;
// -----------------------------------------------------------------------------

	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM1)>0)  {Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM2)>0)  {Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// ~2K ������������ ���� ������ ��� ������ ����������
	// �������� �� ����
	for (i = 0; i < MB_MaxNumbRelay; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
			if (Q) {
				if (i>=0 && i<10)  quality = qualityM1; else
				if (i>9  && i<19) quality = qualityM2;
				if (IedServer_updateQuality(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_q[i],quality)) {
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
			}
		}
	}
return	ret;
}

/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{


	bool value;
	uint32_t	Mod = STVALINT32_ON;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbLED)	return ret;
// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}


	if (num == 0 || num == 1){
		value = ((ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
			}
	}
	if (num == 0 || num == 2){
		value = ((ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
			}
	}
	if (num == 0 || num == 3){
		value = ((ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
			}
	}
	if (num == 0 || num == 4){
		value = ((ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
			}
	}
	if (num == 0 || num == 5){
		value = ((ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
			}
	}
	if (num == 0 || num == 6){
		value = ((ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
			}
	}
	if (num == 0 || num == 7){
		value = ((ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  value) > 0)
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	}
	if (num == 0 || num == 8){
		value = ((ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
			}
	}
	if (num == 0 || num == 9){
		value = ((ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
			}
	}
	if (num == 0 || num == 10){
		value = ((ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
			}
	}
	if (num == 0 || num == 11){
		value = ((ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
			}
	}
	if (num == 0 || num == 12){
		value = ((ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
			}
	}
	if (num == 0 || num == 13){
		value = ((ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
			}
	}
	if (num == 0 || num == 14){
		value = ((ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
			}
	}
	if (num == 0 || num == 15){
		value = ((ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
			}
	}
	if (num == 0 || num == 16){
		value = ((ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);
			}
	}

	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// ������� �� ��������, ����� ��� ��������� ���������
	if (Q) {
		if (num == 0 || num == 1)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q, quality);
		if (num == 0 || num == 2)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q, quality);
		if (num == 0 || num == 3)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q, quality);
		if (num == 0 || num == 4)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q, quality);
		if (num == 0 || num == 5)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q, quality);
		if (num == 0 || num == 6)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q, quality);
		if (num == 0 || num == 7)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q, quality);
		if (num == 0 || num == 8)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q, quality);
		if (num == 0 || num == 9)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q, quality);
		if (num == 0 || num == 10)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);
		if (num == 0 || num == 11)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality);
		if (num == 0 || num == 12)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);
		if (num == 0 || num == 13)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,quality);
		if (num == 0 || num == 14)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,quality);
		//if (num == 0 || num == 15)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,quality);
		//if (num == 0 || num == 16)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,quality);

		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
		//if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
		//if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);

	}

return	ret;
}
/*******************************************************
 * Set_SSLGGIO ��������� ������������ �������
 *******************************************************/
uint16_t SSLBuf[MB_MaxNumbSSL][2] ={
		MB_offsetSSL_1,		MB_bOffset_SSL_1,
		MB_offsetSSL_2,		MB_bOffset_SSL_2,
		MB_offsetSSL_3,		MB_bOffset_SSL_3,
		MB_offsetSSL_4,		MB_bOffset_SSL_4,
		MB_offsetSSL_5,		MB_bOffset_SSL_5,
		MB_offsetSSL_6,		MB_bOffset_SSL_6,
		MB_offsetSSL_7,		MB_bOffset_SSL_7,
		MB_offsetSSL_8,		MB_bOffset_SSL_8,
		MB_offsetSSL_9,		MB_bOffset_SSL_9,
		MB_offsetSSL_10,	MB_bOffset_SSL_10,
		MB_offsetSSL_11,	MB_bOffset_SSL_11,
		MB_offsetSSL_12,	MB_bOffset_SSL_12,
		MB_offsetSSL_13,	MB_bOffset_SSL_13,
		MB_offsetSSL_14,	MB_bOffset_SSL_14,
		MB_offsetSSL_15,	MB_bOffset_SSL_15,
		MB_offsetSSL_16,	MB_bOffset_SSL_16,
		MB_offsetSSL_17,	MB_bOffset_SSL_17,
		MB_offsetSSL_18,	MB_bOffset_SSL_18,
		MB_offsetSSL_19,	MB_bOffset_SSL_19,
		MB_offsetSSL_20,	MB_bOffset_SSL_20,
		MB_offsetSSL_21,	MB_bOffset_SSL_21,
		MB_offsetSSL_22,	MB_bOffset_SSL_22,
		MB_offsetSSL_23,	MB_bOffset_SSL_23,
		MB_offsetSSL_24,	MB_bOffset_SSL_24,
		MB_offsetSSL_25,	MB_bOffset_SSL_25,
		MB_offsetSSL_26,	MB_bOffset_SSL_26,
		MB_offsetSSL_27,	MB_bOffset_SSL_27,
		MB_offsetSSL_28,	MB_bOffset_SSL_28,
		MB_offsetSSL_29,	MB_bOffset_SSL_29,
		MB_offsetSSL_30,	MB_bOffset_SSL_30,
		MB_offsetSSL_31,	MB_bOffset_SSL_31,
		MB_offsetSSL_32,	MB_bOffset_SSL_32
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_q[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_q,		&iedModel_GGIO_SSLGGIO1_Ind2_q,
		&iedModel_GGIO_SSLGGIO1_Ind3_q,		&iedModel_GGIO_SSLGGIO1_Ind4_q,
		&iedModel_GGIO_SSLGGIO1_Ind5_q,		&iedModel_GGIO_SSLGGIO1_Ind6_q,
		&iedModel_GGIO_SSLGGIO1_Ind7_q,		&iedModel_GGIO_SSLGGIO1_Ind8_q,
		&iedModel_GGIO_SSLGGIO1_Ind9_q,		&iedModel_GGIO_SSLGGIO1_Ind10_q,
		&iedModel_GGIO_SSLGGIO1_Ind11_q,	&iedModel_GGIO_SSLGGIO1_Ind12_q,
		&iedModel_GGIO_SSLGGIO1_Ind13_q,	&iedModel_GGIO_SSLGGIO1_Ind14_q,
		&iedModel_GGIO_SSLGGIO1_Ind15_q,	&iedModel_GGIO_SSLGGIO1_Ind16_q,
		&iedModel_GGIO_SSLGGIO1_Ind17_q,	&iedModel_GGIO_SSLGGIO1_Ind18_q,
		&iedModel_GGIO_SSLGGIO1_Ind19_q,	&iedModel_GGIO_SSLGGIO1_Ind20_q,
		&iedModel_GGIO_SSLGGIO1_Ind21_q,	&iedModel_GGIO_SSLGGIO1_Ind22_q,
		&iedModel_GGIO_SSLGGIO1_Ind23_q,	&iedModel_GGIO_SSLGGIO1_Ind24_q,
		&iedModel_GGIO_SSLGGIO1_Ind25_q,	&iedModel_GGIO_SSLGGIO1_Ind26_q,
		&iedModel_GGIO_SSLGGIO1_Ind27_q,	&iedModel_GGIO_SSLGGIO1_Ind28_q,
		&iedModel_GGIO_SSLGGIO1_Ind29_q,	&iedModel_GGIO_SSLGGIO1_Ind30_q,
		&iedModel_GGIO_SSLGGIO1_Ind31_q,	&iedModel_GGIO_SSLGGIO1_Ind32_q

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_t[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_t,		&iedModel_GGIO_SSLGGIO1_Ind2_t,
		&iedModel_GGIO_SSLGGIO1_Ind3_t,		&iedModel_GGIO_SSLGGIO1_Ind4_t,
		&iedModel_GGIO_SSLGGIO1_Ind5_t,		&iedModel_GGIO_SSLGGIO1_Ind6_t,
		&iedModel_GGIO_SSLGGIO1_Ind7_t,		&iedModel_GGIO_SSLGGIO1_Ind8_t,
		&iedModel_GGIO_SSLGGIO1_Ind9_t,		&iedModel_GGIO_SSLGGIO1_Ind10_t,
		&iedModel_GGIO_SSLGGIO1_Ind11_t,	&iedModel_GGIO_SSLGGIO1_Ind12_t,
		&iedModel_GGIO_SSLGGIO1_Ind13_t,	&iedModel_GGIO_SSLGGIO1_Ind14_t,
		&iedModel_GGIO_SSLGGIO1_Ind15_t,	&iedModel_GGIO_SSLGGIO1_Ind16_t,
		&iedModel_GGIO_SSLGGIO1_Ind17_t,	&iedModel_GGIO_SSLGGIO1_Ind18_t,
		&iedModel_GGIO_SSLGGIO1_Ind19_t,	&iedModel_GGIO_SSLGGIO1_Ind20_t,
		&iedModel_GGIO_SSLGGIO1_Ind21_t,	&iedModel_GGIO_SSLGGIO1_Ind22_t,
		&iedModel_GGIO_SSLGGIO1_Ind23_t,	&iedModel_GGIO_SSLGGIO1_Ind24_t,
		&iedModel_GGIO_SSLGGIO1_Ind25_t,	&iedModel_GGIO_SSLGGIO1_Ind26_t,
		&iedModel_GGIO_SSLGGIO1_Ind27_t,	&iedModel_GGIO_SSLGGIO1_Ind28_t,
		&iedModel_GGIO_SSLGGIO1_Ind29_t,	&iedModel_GGIO_SSLGGIO1_Ind30_t,
		&iedModel_GGIO_SSLGGIO1_Ind31_t,	&iedModel_GGIO_SSLGGIO1_Ind32_t
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_stVal[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_stVal,		&iedModel_GGIO_SSLGGIO1_Ind2_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind3_stVal,		&iedModel_GGIO_SSLGGIO1_Ind4_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind5_stVal,		&iedModel_GGIO_SSLGGIO1_Ind6_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind7_stVal,		&iedModel_GGIO_SSLGGIO1_Ind8_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind9_stVal,		&iedModel_GGIO_SSLGGIO1_Ind10_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind11_stVal,	&iedModel_GGIO_SSLGGIO1_Ind12_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind13_stVal,	&iedModel_GGIO_SSLGGIO1_Ind14_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind15_stVal,	&iedModel_GGIO_SSLGGIO1_Ind16_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind17_stVal,	&iedModel_GGIO_SSLGGIO1_Ind18_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind19_stVal,	&iedModel_GGIO_SSLGGIO1_Ind20_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind21_stVal,	&iedModel_GGIO_SSLGGIO1_Ind22_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind23_stVal,	&iedModel_GGIO_SSLGGIO1_Ind24_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind25_stVal,	&iedModel_GGIO_SSLGGIO1_Ind26_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind27_stVal,	&iedModel_GGIO_SSLGGIO1_Ind28_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind29_stVal,	&iedModel_GGIO_SSLGGIO1_Ind30_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind31_stVal,	&iedModel_GGIO_SSLGGIO1_Ind32_stVal
};
/*******************************************************
 *******************************************************/
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint8_t	i;
	int	ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbSSL)	return ret;
	// -----------------------------------------------------------------------------
		uint32_t	Mod 	= STVALINT32_OFF;
		uint32_t	Health 	= STVALINT32_OK;

		if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError) 	{Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

//Health
/*
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);
		}
*/

#if defined (MR801) && (_REVISION_DEVICE<=299)		//2.07		������ � �������. �� ����� ���������� ���� ����
		Mod	= STVALINT32_ON;
#endif

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
		}


	// �������� �� ����
	for (i = 0; i < MB_MaxNumbSSL; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_SSLGGIO_Ind_q[i],quality))
					{
						if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
						ret = true;
					}
		}
	}
return ret;
}
/*******************************************************
 * Set_VLSGGIO ��������� ������������ �������
 *******************************************************/
uint16_t VLSBuf[MB_MaxNumbVLS][2] ={
		MB_offsetVLS_1,		MB_bOffset_VLS_1,
		MB_offsetVLS_2,		MB_bOffset_VLS_2,
		MB_offsetVLS_3,		MB_bOffset_VLS_3,
		MB_offsetVLS_4,		MB_bOffset_VLS_4,
		MB_offsetVLS_5,		MB_bOffset_VLS_5,
		MB_offsetVLS_6,		MB_bOffset_VLS_6,
		MB_offsetVLS_7,		MB_bOffset_VLS_7,
		MB_offsetVLS_8,		MB_bOffset_VLS_8,
		MB_offsetVLS_9,		MB_bOffset_VLS_9,
		MB_offsetVLS_10,	MB_bOffset_VLS_10,
		MB_offsetVLS_11,	MB_bOffset_VLS_11,
		MB_offsetVLS_12,	MB_bOffset_VLS_12,
		MB_offsetVLS_13,	MB_bOffset_VLS_13,
		MB_offsetVLS_14,	MB_bOffset_VLS_14,
		MB_offsetVLS_15,	MB_bOffset_VLS_15,
		MB_offsetVLS_16,	MB_bOffset_VLS_16,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_q[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_q,		&iedModel_GGIO_VLSGGIO1_Ind2_q,
		&iedModel_GGIO_VLSGGIO1_Ind3_q,		&iedModel_GGIO_VLSGGIO1_Ind4_q,
		&iedModel_GGIO_VLSGGIO1_Ind5_q,		&iedModel_GGIO_VLSGGIO1_Ind6_q,
		&iedModel_GGIO_VLSGGIO1_Ind7_q,		&iedModel_GGIO_VLSGGIO1_Ind8_q,
		&iedModel_GGIO_VLSGGIO1_Ind9_q,		&iedModel_GGIO_VLSGGIO1_Ind10_q,
		&iedModel_GGIO_VLSGGIO1_Ind11_q,	&iedModel_GGIO_VLSGGIO1_Ind12_q,
		&iedModel_GGIO_VLSGGIO1_Ind13_q,	&iedModel_GGIO_VLSGGIO1_Ind14_q,
		&iedModel_GGIO_VLSGGIO1_Ind15_q,	&iedModel_GGIO_VLSGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_t[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_t,		&iedModel_GGIO_VLSGGIO1_Ind2_t,
		&iedModel_GGIO_VLSGGIO1_Ind3_t,		&iedModel_GGIO_VLSGGIO1_Ind4_t,
		&iedModel_GGIO_VLSGGIO1_Ind5_t,		&iedModel_GGIO_VLSGGIO1_Ind6_t,
		&iedModel_GGIO_VLSGGIO1_Ind7_t,		&iedModel_GGIO_VLSGGIO1_Ind8_t,
		&iedModel_GGIO_VLSGGIO1_Ind9_t,		&iedModel_GGIO_VLSGGIO1_Ind10_t,
		&iedModel_GGIO_VLSGGIO1_Ind11_t,	&iedModel_GGIO_VLSGGIO1_Ind12_t,
		&iedModel_GGIO_VLSGGIO1_Ind13_t,	&iedModel_GGIO_VLSGGIO1_Ind14_t,
		&iedModel_GGIO_VLSGGIO1_Ind15_t,	&iedModel_GGIO_VLSGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_stVal[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_stVal,		&iedModel_GGIO_VLSGGIO1_Ind2_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind3_stVal,		&iedModel_GGIO_VLSGGIO1_Ind4_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind5_stVal,		&iedModel_GGIO_VLSGGIO1_Ind6_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind7_stVal,		&iedModel_GGIO_VLSGGIO1_Ind8_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind9_stVal,		&iedModel_GGIO_VLSGGIO1_Ind10_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind11_stVal,	&iedModel_GGIO_VLSGGIO1_Ind12_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind13_stVal,	&iedModel_GGIO_VLSGGIO1_Ind14_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind15_stVal,	&iedModel_GGIO_VLSGGIO1_Ind16_stVal,
};
/*******************************************************
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint8_t	i;
	int	ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbVLS)	return ret;
	// -----------------------------------------------------------------------------
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;

//Mod
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}
//Health
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}

//quality
	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// �������� �� ����
	for (i = 0; i < MB_MaxNumbVLS; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],  ucMDiscInBuf[VLSBuf[i][0]] & VLSBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VLSGGIO_Ind_q[i],quality))
					{
						if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_t[i], currentTime);
						ret = true;
					}
		}
	}

return ret;
}

/*******************************************************
 * Set_LSGGIO ��������� ������������ �������
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,		MB_bOffset_LS_1,
		MB_offsetLS_2,		MB_bOffset_LS_2,
		MB_offsetLS_3,		MB_bOffset_LS_3,
		MB_offsetLS_4,		MB_bOffset_LS_4,
		MB_offsetLS_5,		MB_bOffset_LS_5,
		MB_offsetLS_6,		MB_bOffset_LS_6,
		MB_offsetLS_7,		MB_bOffset_LS_7,
		MB_offsetLS_8,		MB_bOffset_LS_8,
		MB_offsetLS_9,		MB_bOffset_LS_9,
		MB_offsetLS_10,		MB_bOffset_LS_10,
		MB_offsetLS_11,		MB_bOffset_LS_11,
		MB_offsetLS_12,		MB_bOffset_LS_12,
		MB_offsetLS_13,		MB_bOffset_LS_13,
		MB_offsetLS_14,		MB_bOffset_LS_14,
		MB_offsetLS_15,		MB_bOffset_LS_15,
		MB_offsetLS_16,		MB_bOffset_LS_16
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,		&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,		&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,		&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,		&iedModel_GGIO_LSGGIO1_Ind8_q,
		&iedModel_GGIO_LSGGIO1_Ind9_q,		&iedModel_GGIO_LSGGIO1_Ind10_q,
		&iedModel_GGIO_LSGGIO1_Ind11_q,		&iedModel_GGIO_LSGGIO1_Ind12_q,
		&iedModel_GGIO_LSGGIO1_Ind13_q,		&iedModel_GGIO_LSGGIO1_Ind14_q,
		&iedModel_GGIO_LSGGIO1_Ind15_q,		&iedModel_GGIO_LSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,		&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,		&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,		&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,		&iedModel_GGIO_LSGGIO1_Ind8_t,
		&iedModel_GGIO_LSGGIO1_Ind9_t,		&iedModel_GGIO_LSGGIO1_Ind10_t,
		&iedModel_GGIO_LSGGIO1_Ind11_t,		&iedModel_GGIO_LSGGIO1_Ind12_t,
		&iedModel_GGIO_LSGGIO1_Ind13_t,		&iedModel_GGIO_LSGGIO1_Ind14_t,
		&iedModel_GGIO_LSGGIO1_Ind15_t,		&iedModel_GGIO_LSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,		&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,		&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,		&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,		&iedModel_GGIO_LSGGIO1_Ind8_stVal,
		&iedModel_GGIO_LSGGIO1_Ind9_stVal,		&iedModel_GGIO_LSGGIO1_Ind10_stVal,
		&iedModel_GGIO_LSGGIO1_Ind11_stVal,		&iedModel_GGIO_LSGGIO1_Ind12_stVal,
		&iedModel_GGIO_LSGGIO1_Ind13_stVal,		&iedModel_GGIO_LSGGIO1_Ind14_stVal,
		&iedModel_GGIO_LSGGIO1_Ind15_stVal,		&iedModel_GGIO_LSGGIO1_Ind16_stVal
};
/*******************************************************
 *******************************************************/
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
uint8_t	i;
int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbLS)	return ret;
// -----------------------------------------------------------------------------
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}
//Health
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}

//quality
	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// �������� �� ����
	for (i = 0; i < MB_MaxNumbLS; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],  ucMDiscInBuf[LSBuf[i][0]] & LSBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_t[i], currentTime);
					ret = true;
				}

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LSGGIO_Ind_q[i],quality)) {
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_t[i], currentTime);
				ret = true;
			}
		}
	}

return ret;
}
#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) || defined (MR761OBR)

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif
#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif
extern 	uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

/*******************************************************
 * ��������
 *******************************************************/
#if defined	(MR771)
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif
#if defined	(MR771) || (defined	(MR801) && defined (OLD))
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif
#if  !defined (MR761OBR)
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#if defined	(MR761OBR)
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

#if  defined (MR761OBR)
/*******************************************************
 * RSTGGIO
 *******************************************************/
uint16_t RSTBuf[MB_MaxNumbRST][2] ={
		MB_offsetRST_1,	MB_bOffset_RST_1,
		MB_offsetRST_2,	MB_bOffset_RST_2,
		MB_offsetRST_3,	MB_bOffset_RST_3,
		MB_offsetRST_4,	MB_bOffset_RST_4,
		MB_offsetRST_5,	MB_bOffset_RST_5,
		MB_offsetRST_6,	MB_bOffset_RST_6,
		MB_offsetRST_7,	MB_bOffset_RST_7,
		MB_offsetRST_8,	MB_bOffset_RST_8,
		MB_offsetRST_9,	MB_bOffset_RST_9,
		MB_offsetRST_10,MB_bOffset_RST_10,
		MB_offsetRST_11,MB_bOffset_RST_11,
		MB_offsetRST_12,MB_bOffset_RST_12,
		MB_offsetRST_13,MB_bOffset_RST_13,
		MB_offsetRST_14,MB_bOffset_RST_14,
		MB_offsetRST_15,MB_bOffset_RST_15,
		MB_offsetRST_16,MB_bOffset_RST_16,
};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_q[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_q,			&iedModel_GGIO_RSTGGIO1_Ind2_q,
		&iedModel_GGIO_RSTGGIO1_Ind3_q,			&iedModel_GGIO_RSTGGIO1_Ind4_q,
		&iedModel_GGIO_RSTGGIO1_Ind5_q,			&iedModel_GGIO_RSTGGIO1_Ind6_q,
		&iedModel_GGIO_RSTGGIO1_Ind7_q,			&iedModel_GGIO_RSTGGIO1_Ind8_q,
		&iedModel_GGIO_RSTGGIO1_Ind9_q,			&iedModel_GGIO_RSTGGIO1_Ind10_q,
		&iedModel_GGIO_RSTGGIO1_Ind11_q,		&iedModel_GGIO_RSTGGIO1_Ind12_q,
		&iedModel_GGIO_RSTGGIO1_Ind13_q,		&iedModel_GGIO_RSTGGIO1_Ind14_q,
		&iedModel_GGIO_RSTGGIO1_Ind15_q,		&iedModel_GGIO_RSTGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_t[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_t,			&iedModel_GGIO_RSTGGIO1_Ind2_t,
		&iedModel_GGIO_RSTGGIO1_Ind3_t,			&iedModel_GGIO_RSTGGIO1_Ind4_t,
		&iedModel_GGIO_RSTGGIO1_Ind5_t,			&iedModel_GGIO_RSTGGIO1_Ind6_t,
		&iedModel_GGIO_RSTGGIO1_Ind7_t,			&iedModel_GGIO_RSTGGIO1_Ind8_t,
		&iedModel_GGIO_RSTGGIO1_Ind9_t,			&iedModel_GGIO_RSTGGIO1_Ind10_t,
		&iedModel_GGIO_RSTGGIO1_Ind11_t,		&iedModel_GGIO_RSTGGIO1_Ind12_t,
		&iedModel_GGIO_RSTGGIO1_Ind13_t,		&iedModel_GGIO_RSTGGIO1_Ind14_t,
		&iedModel_GGIO_RSTGGIO1_Ind15_t,		&iedModel_GGIO_RSTGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_RSTGGIO_Ind_stVal[MB_MaxNumbRST] = {
		&iedModel_GGIO_RSTGGIO1_Ind1_stVal,		&iedModel_GGIO_RSTGGIO1_Ind2_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind3_stVal,		&iedModel_GGIO_RSTGGIO1_Ind4_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind5_stVal,		&iedModel_GGIO_RSTGGIO1_Ind6_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind7_stVal,		&iedModel_GGIO_RSTGGIO1_Ind8_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind9_stVal,		&iedModel_GGIO_RSTGGIO1_Ind10_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind11_stVal,	&iedModel_GGIO_RSTGGIO1_Ind12_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind13_stVal,	&iedModel_GGIO_RSTGGIO1_Ind14_stVal,
		&iedModel_GGIO_RSTGGIO1_Ind15_stVal,	&iedModel_GGIO_RSTGGIO1_Ind16_stVal,
};

int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbRST)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_RSTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_RSTGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbRST; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_RSTGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[RSTBuf[i][0]] & RSTBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_RSTGGIO_Ind_stVal[i],iedModel_GGIO_RSTGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_RSTGGIO_Ind_stVal[i],  value);}

		}
	}//!for (i...
return ret;
}
#endif
/*******************************************************
 * Set_VZGGIO ��������� ������������ �������
 *******************************************************/
uint16_t VZBufCFG[MB_MaxNumbVZ] ={
		MB_offset_Ext_1,
		MB_offset_Ext_2,
		MB_offset_Ext_3,
		MB_offset_Ext_4,
		MB_offset_Ext_5,
		MB_offset_Ext_6,
		MB_offset_Ext_7,
		MB_offset_Ext_8,
		MB_offset_Ext_9,
		MB_offset_Ext_10,
		MB_offset_Ext_11,
		MB_offset_Ext_12,
		MB_offset_Ext_13,
		MB_offset_Ext_14,
		MB_offset_Ext_15,
		MB_offset_Ext_16
};

uint16_t VZBuf[MB_MaxNumbVZ][2] ={
		MB_offset_SRAB_ext_1,	MB_b_SRAB_ext_1,
		MB_offset_SRAB_ext_2,	MB_b_SRAB_ext_2,
		MB_offset_SRAB_ext_3,	MB_b_SRAB_ext_3,
		MB_offset_SRAB_ext_4,	MB_b_SRAB_ext_4,
		MB_offset_SRAB_ext_5,	MB_b_SRAB_ext_5,
		MB_offset_SRAB_ext_6,	MB_b_SRAB_ext_6,
		MB_offset_SRAB_ext_7,	MB_b_SRAB_ext_7,
		MB_offset_SRAB_ext_8,	MB_b_SRAB_ext_8,
		MB_offset_SRAB_ext_9,	MB_b_SRAB_ext_9,
		MB_offset_SRAB_ext_10,	MB_b_SRAB_ext_10,
		MB_offset_SRAB_ext_11,	MB_b_SRAB_ext_11,
		MB_offset_SRAB_ext_12,	MB_b_SRAB_ext_12,
		MB_offset_SRAB_ext_13,	MB_b_SRAB_ext_13,
		MB_offset_SRAB_ext_14,	MB_b_SRAB_ext_14,
		MB_offset_SRAB_ext_15,	MB_b_SRAB_ext_15,
		MB_offset_SRAB_ext_16,	MB_b_SRAB_ext_16
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_q[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_q,	&iedModel_PROT_VZGGIO2_Alm_q,
		&iedModel_PROT_VZGGIO3_Alm_q,	&iedModel_PROT_VZGGIO4_Alm_q,
		&iedModel_PROT_VZGGIO5_Alm_q,	&iedModel_PROT_VZGGIO6_Alm_q,
		&iedModel_PROT_VZGGIO7_Alm_q,	&iedModel_PROT_VZGGIO8_Alm_q,
		&iedModel_PROT_VZGGIO9_Alm_q,	&iedModel_PROT_VZGGIO10_Alm_q,
		&iedModel_PROT_VZGGIO11_Alm_q,	&iedModel_PROT_VZGGIO12_Alm_q,
		&iedModel_PROT_VZGGIO13_Alm_q,	&iedModel_PROT_VZGGIO14_Alm_q,
		&iedModel_PROT_VZGGIO15_Alm_q,	&iedModel_PROT_VZGGIO16_Alm_q
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_t,	&iedModel_PROT_VZGGIO2_Alm_t,
		&iedModel_PROT_VZGGIO3_Alm_t,	&iedModel_PROT_VZGGIO4_Alm_t,
		&iedModel_PROT_VZGGIO5_Alm_t,	&iedModel_PROT_VZGGIO6_Alm_t,
		&iedModel_PROT_VZGGIO7_Alm_t,	&iedModel_PROT_VZGGIO8_Alm_t,
		&iedModel_PROT_VZGGIO9_Alm_t,	&iedModel_PROT_VZGGIO10_Alm_t,
		&iedModel_PROT_VZGGIO11_Alm_t,	&iedModel_PROT_VZGGIO12_Alm_t,
		&iedModel_PROT_VZGGIO13_Alm_t,	&iedModel_PROT_VZGGIO14_Alm_t,
		&iedModel_PROT_VZGGIO15_Alm_t,	&iedModel_PROT_VZGGIO16_Alm_t
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_stVal,	&iedModel_PROT_VZGGIO2_Alm_stVal,
		&iedModel_PROT_VZGGIO3_Alm_stVal,	&iedModel_PROT_VZGGIO4_Alm_stVal,
		&iedModel_PROT_VZGGIO5_Alm_stVal,	&iedModel_PROT_VZGGIO6_Alm_stVal,
		&iedModel_PROT_VZGGIO7_Alm_stVal,	&iedModel_PROT_VZGGIO8_Alm_stVal,
		&iedModel_PROT_VZGGIO9_Alm_stVal,	&iedModel_PROT_VZGGIO10_Alm_stVal,
		&iedModel_PROT_VZGGIO11_Alm_stVal,	&iedModel_PROT_VZGGIO12_Alm_stVal,
		&iedModel_PROT_VZGGIO13_Alm_stVal,	&iedModel_PROT_VZGGIO14_Alm_stVal,
		&iedModel_PROT_VZGGIO15_Alm_stVal,	&iedModel_PROT_VZGGIO16_Alm_stVal
};
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbVZ)	return ret;
// -----------------------------------------------------------------------------

uint32_t	Mod = STVALINT32_OFF;


	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}


	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VZGGIO_Ind_q[i],quality)) ret = true;

			bool value= false;
			if ((ucMDiscInBuf[VZBuf[i][0]] & VZBuf[i][1])>0) value = true;
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_VZGGIO_Ind_stVal[i],iedModel_GGIO_VZGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VZGGIO_Ind_stVal[i],  value);}

		}
	}

//  Mod Beh
	if (num == 0 || num == 1){
			if ((ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
			}

			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// ���� >1
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)) 	ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality)) 	ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);
	}
	if (num == 0 || num == 2){
			if ((ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);
	}
	if (num == 0 || num == 3){
			if ((ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);
	}
	if (num == 0 || num == 4){
			if ((ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);
	}
	if (num == 0 || num == 5){
			if ((ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);
	}
	if (num == 0 || num == 6){
			if ((ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);
	}
	if (num == 0 || num == 7){
			if ((ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);
	}
	if (num == 0 || num == 8){
			if ((ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);
	}
	if (num == 0 || num == 9){
			if ((ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,0);
	}
	if (num == 0 || num == 10){
			if ((ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Health_t, currentTime);
			}

			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,0);
	}
	if (num == 0 || num == 11){
			if ((ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,0);
	}
	if (num == 0 || num == 12){
			if ((ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,0);
	}
	if (num == 0 || num == 13){
			if ((ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,0);
	}
	if (num == 0 || num == 14){
			if ((ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,0);
	}
	if (num == 0 || num == 15){
			if ((ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Health_t, currentTime);
			}
/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				}
*/

			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,0);
	}
	if (num == 0 || num == 16){
			if ((ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Health_t, currentTime);
			}
/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// ����
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);
				}
*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,0);
	}

	return ret;
}
/*******************************************************
 * Set_AVRGGIO ��������� ������������ �������
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR801)
int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;

	uint64_t 	diskreet;
	uint32_t 	BLKAVR,BLKAVR1;
	uint32_t	Mod;
	uint32_t	Health;

	//  Mod Beh

		if ((ucMUstavkiInBuf[MB_Addr_ConfigAWR + MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

		BLKAVR = ucMUstavkiInBuf[MB_Addr_ConfigAWR + MB_offset_InBlok];						// ����� ��������
		if (BLKAVR) {

			diskreet = (uint64_t)ucMDiscInBuf[0] | (uint64_t)ucMDiscInBuf[1]<<16 | (uint64_t)ucMDiscInBuf[2]<<32 | (uint64_t)ucMDiscInBuf[3]<<48;

			BLKAVR1 = (BLKAVR - 1)%2;
			BLKAVR = (BLKAVR - 1)/2;

			if (BLKAVR1 > 0) {							// ���� �� ����� ��������� �� ��������� ���������
				if ((diskreet & 1<<BLKAVR) == 0) Mod = STVALINT32_BLOCKED;
			} else{
				if ((diskreet & 1<<BLKAVR)>0) Mod = STVALINT32_BLOCKED;
			}
		}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
		}
//Health
Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

		uint8_t	awr=0;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
			ret = true;
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,Qual);
return ret;
}
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
int	Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint64_t diskreet;
	uint32_t BLKAVR,BLKAVR1;
	uint32_t	Mod = STVALINT32_OFF;


	//  Mod Beh

		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Hot] >0) {Mod = STVALINT32_ON;}
		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Cold] >0) {Mod = STVALINT32_ON;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_t, currentTime);
		}

		//Health
		uint32_t	Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_q,Qual);

		uint8_t	nblk=0;
			if(ucMDiscInBuf[MB_offset_BlkN] & MB_b_BlkN)  nblk = 1;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_stVal, nblk)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_t, currentTime);
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_IntIn_q,Qual);
}
#endif
/*******************************************************
 * Set_XCBRGGIO ��������� ������������ �������
 * ��������� Set_SPCSO
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
}

/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 *
 * ���� ��������.(�����)
 * MR761	-	12.01.2018	 - ��
 *
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={	//42
		MB_offsetDiscreet_1,		MB_bOffset_Discreet_1,
		MB_offsetDiscreet_2,		MB_bOffset_Discreet_2,
		MB_offsetDiscreet_3,		MB_bOffset_Discreet_3,
		MB_offsetDiscreet_4,		MB_bOffset_Discreet_4,
		MB_offsetDiscreet_5,		MB_bOffset_Discreet_5,
		MB_offsetDiscreet_6,		MB_bOffset_Discreet_6,
		MB_offsetDiscreet_7,		MB_bOffset_Discreet_7,
		MB_offsetDiscreet_8,		MB_bOffset_Discreet_8,
		MB_offsetDiscreet_9,		MB_bOffset_Discreet_9,
		MB_offsetDiscreet_10,		MB_bOffset_Discreet_10,
		MB_offsetDiscreet_11,		MB_bOffset_Discreet_11,
		MB_offsetDiscreet_12,		MB_bOffset_Discreet_12,
		MB_offsetDiscreet_13,		MB_bOffset_Discreet_13,
		MB_offsetDiscreet_14,		MB_bOffset_Discreet_14,
		MB_offsetDiscreet_15,		MB_bOffset_Discreet_15,
		MB_offsetDiscreet_16,		MB_bOffset_Discreet_16,
		MB_offsetDiscreet_17,		MB_bOffset_Discreet_17,
		MB_offsetDiscreet_18,		MB_bOffset_Discreet_18,
		MB_offsetDiscreet_19,		MB_bOffset_Discreet_19,
		MB_offsetDiscreet_20,		MB_bOffset_Discreet_20,
		MB_offsetDiscreet_21,		MB_bOffset_Discreet_21,
		MB_offsetDiscreet_22,		MB_bOffset_Discreet_22,
		MB_offsetDiscreet_23,		MB_bOffset_Discreet_23,
		MB_offsetDiscreet_24,		MB_bOffset_Discreet_24,
		MB_offsetDiscreet_25,		MB_bOffset_Discreet_25,
		MB_offsetDiscreet_26,		MB_bOffset_Discreet_26,
		MB_offsetDiscreet_27,		MB_bOffset_Discreet_27,
		MB_offsetDiscreet_28,		MB_bOffset_Discreet_28,
		MB_offsetDiscreet_29,		MB_bOffset_Discreet_29,
		MB_offsetDiscreet_30,		MB_bOffset_Discreet_30,
		MB_offsetDiscreet_31,		MB_bOffset_Discreet_31,
		MB_offsetDiscreet_32,		MB_bOffset_Discreet_32,
		MB_offsetDiscreet_33,		MB_bOffset_Discreet_33,
		MB_offsetDiscreet_34,		MB_bOffset_Discreet_34,
		MB_offsetDiscreet_35,		MB_bOffset_Discreet_35,
		MB_offsetDiscreet_36,		MB_bOffset_Discreet_36,
		MB_offsetDiscreet_37,		MB_bOffset_Discreet_37,
		MB_offsetDiscreet_38,		MB_bOffset_Discreet_38,
		MB_offsetDiscreet_39,		MB_bOffset_Discreet_39,
		MB_offsetDiscreet_40,		MB_bOffset_Discreet_40,
		MB_offsetDiscreet_41,		MB_bOffset_Discreet_41,
		MB_offsetDiscreet_42,		MB_bOffset_Discreet_42,
#if defined	(MR761OBR)
		MB_offsetDiscreet_43,		MB_bOffset_Discreet_43,
		MB_offsetDiscreet_44,		MB_bOffset_Discreet_44,
		MB_offsetDiscreet_45,		MB_bOffset_Discreet_45,
		MB_offsetDiscreet_46,		MB_bOffset_Discreet_46,
		MB_offsetDiscreet_47,		MB_bOffset_Discreet_47,
		MB_offsetDiscreet_48,		MB_bOffset_Discreet_48,
		MB_offsetDiscreet_49,		MB_bOffset_Discreet_49,
		MB_offsetDiscreet_50,		MB_bOffset_Discreet_50,
		MB_offsetDiscreet_51,		MB_bOffset_Discreet_51,
		MB_offsetDiscreet_52,		MB_bOffset_Discreet_52,
		MB_offsetDiscreet_53,		MB_bOffset_Discreet_53,
		MB_offsetDiscreet_54,		MB_bOffset_Discreet_54,
		MB_offsetDiscreet_55,		MB_bOffset_Discreet_55,
		MB_offsetDiscreet_56,		MB_bOffset_Discreet_56,
		MB_offsetDiscreet_57,		MB_bOffset_Discreet_57,
		MB_offsetDiscreet_58,		MB_bOffset_Discreet_58,
		MB_offsetDiscreet_59,		MB_bOffset_Discreet_59,
		MB_offsetDiscreet_60,		MB_bOffset_Discreet_60,
		MB_offsetDiscreet_61,		MB_bOffset_Discreet_61,
		MB_offsetDiscreet_62,		MB_bOffset_Discreet_62,
		MB_offsetDiscreet_63,		MB_bOffset_Discreet_63,
		MB_offsetDiscreet_64,		MB_bOffset_Discreet_64,
		MB_offsetDiscreet_65,		MB_bOffset_Discreet_65,
		MB_offsetDiscreet_66,		MB_bOffset_Discreet_66,
		MB_offsetDiscreet_67,		MB_bOffset_Discreet_67,
		MB_offsetDiscreet_68,		MB_bOffset_Discreet_68,
		MB_offsetDiscreet_69,		MB_bOffset_Discreet_69,
		MB_offsetDiscreet_70,		MB_bOffset_Discreet_70,
		MB_offsetDiscreet_71,		MB_bOffset_Discreet_71,
		MB_offsetDiscreet_72,		MB_bOffset_Discreet_72,
		MB_offsetDiscreet_73,		MB_bOffset_Discreet_73,
		MB_offsetDiscreet_74,		MB_bOffset_Discreet_74,
#if (MB_MaxNumbDiscreet>74)
		MB_offsetDiscreet_75,		MB_bOffset_Discreet_75,
		MB_offsetDiscreet_76,		MB_bOffset_Discreet_76,
		MB_offsetDiscreet_77,		MB_bOffset_Discreet_77,
		MB_offsetDiscreet_78,		MB_bOffset_Discreet_78,
		MB_offsetDiscreet_79,		MB_bOffset_Discreet_79,
		MB_offsetDiscreet_80,		MB_bOffset_Discreet_80,
		MB_offsetDiscreet_81,		MB_bOffset_Discreet_81,
		MB_offsetDiscreet_82,		MB_bOffset_Discreet_82,
		MB_offsetDiscreet_83,		MB_bOffset_Discreet_83,
		MB_offsetDiscreet_84,		MB_bOffset_Discreet_84,
		MB_offsetDiscreet_85,		MB_bOffset_Discreet_85,
		MB_offsetDiscreet_86,		MB_bOffset_Discreet_86,
		MB_offsetDiscreet_87,		MB_bOffset_Discreet_87,
		MB_offsetDiscreet_88,		MB_bOffset_Discreet_88,
		MB_offsetDiscreet_89,		MB_bOffset_Discreet_89,
		MB_offsetDiscreet_90,		MB_bOffset_Discreet_90,
		MB_offsetDiscreet_91,		MB_bOffset_Discreet_91,
		MB_offsetDiscreet_92,		MB_bOffset_Discreet_92,
		MB_offsetDiscreet_93,		MB_bOffset_Discreet_93,
		MB_offsetDiscreet_94,		MB_bOffset_Discreet_94,
		MB_offsetDiscreet_95,		MB_bOffset_Discreet_95,
		MB_offsetDiscreet_96,		MB_bOffset_Discreet_96,
		MB_offsetDiscreet_97,		MB_bOffset_Discreet_97,
		MB_offsetDiscreet_98,		MB_bOffset_Discreet_98,
		MB_offsetDiscreet_99,		MB_bOffset_Discreet_99,
		MB_offsetDiscreet_100,		MB_bOffset_Discreet_100,
		MB_offsetDiscreet_101,		MB_bOffset_Discreet_101,
		MB_offsetDiscreet_102,		MB_bOffset_Discreet_102,
		MB_offsetDiscreet_103,		MB_bOffset_Discreet_103,
		MB_offsetDiscreet_104,		MB_bOffset_Discreet_104,
		MB_offsetDiscreet_105,		MB_bOffset_Discreet_105,
		MB_offsetDiscreet_106,		MB_bOffset_Discreet_106,
#if (MB_MaxNumbDiscreet>106)
		MB_offsetDiscreet_107,		MB_bOffset_Discreet_107,
		MB_offsetDiscreet_108,		MB_bOffset_Discreet_108,
		MB_offsetDiscreet_109,		MB_bOffset_Discreet_109,
		MB_offsetDiscreet_110,		MB_bOffset_Discreet_110,
		MB_offsetDiscreet_111,		MB_bOffset_Discreet_111,
		MB_offsetDiscreet_112,		MB_bOffset_Discreet_112,
		MB_offsetDiscreet_113,		MB_bOffset_Discreet_113,
		MB_offsetDiscreet_114,		MB_bOffset_Discreet_114,
#endif//!#if (MB_MaxNumbDiscreet>106)
#endif//!#if (MB_MaxNumbDiscreet>74)

#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,
		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,
		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,
		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,
		&iedModel_GGIO_INGGIO1_Ind8_q,
		&iedModel_GGIO_INGGIO1_Ind9_q,
		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,
		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,
		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,
		&iedModel_GGIO_INGGIO1_Ind16_q,
		&iedModel_GGIO_INGGIO1_Ind17_q,
		&iedModel_GGIO_INGGIO1_Ind18_q,
		&iedModel_GGIO_INGGIO1_Ind19_q,
		&iedModel_GGIO_INGGIO1_Ind20_q,
		&iedModel_GGIO_INGGIO1_Ind21_q,
		&iedModel_GGIO_INGGIO1_Ind22_q,
		&iedModel_GGIO_INGGIO1_Ind23_q,
		&iedModel_GGIO_INGGIO1_Ind24_q,
		&iedModel_GGIO_INGGIO1_Ind25_q,
		&iedModel_GGIO_INGGIO1_Ind26_q,
		&iedModel_GGIO_INGGIO1_Ind27_q,
		&iedModel_GGIO_INGGIO1_Ind28_q,
		&iedModel_GGIO_INGGIO1_Ind29_q,
		&iedModel_GGIO_INGGIO1_Ind30_q,
		&iedModel_GGIO_INGGIO1_Ind31_q,
		&iedModel_GGIO_INGGIO1_Ind32_q,
		&iedModel_GGIO_INGGIO1_Ind33_q,
		&iedModel_GGIO_INGGIO1_Ind34_q,
		&iedModel_GGIO_INGGIO1_Ind35_q,
		&iedModel_GGIO_INGGIO1_Ind36_q,
		&iedModel_GGIO_INGGIO1_Ind37_q,
		&iedModel_GGIO_INGGIO1_Ind38_q,
		&iedModel_GGIO_INGGIO1_Ind39_q,
		&iedModel_GGIO_INGGIO1_Ind40_q,
		&iedModel_GGIO_INGGIO1_Ind41_q,
		&iedModel_GGIO_INGGIO1_Ind42_q,
#if defined	(MR761OBR)
		&iedModel_GGIO_INGGIO1_Ind43_q,
		&iedModel_GGIO_INGGIO1_Ind44_q,
		&iedModel_GGIO_INGGIO1_Ind45_q,
		&iedModel_GGIO_INGGIO1_Ind46_q,
		&iedModel_GGIO_INGGIO1_Ind47_q,
		&iedModel_GGIO_INGGIO1_Ind48_q,
		&iedModel_GGIO_INGGIO1_Ind49_q,
		&iedModel_GGIO_INGGIO1_Ind50_q,
		&iedModel_GGIO_INGGIO1_Ind51_q,
		&iedModel_GGIO_INGGIO1_Ind52_q,
		&iedModel_GGIO_INGGIO1_Ind53_q,
		&iedModel_GGIO_INGGIO1_Ind54_q,
		&iedModel_GGIO_INGGIO1_Ind55_q,
		&iedModel_GGIO_INGGIO1_Ind56_q,
		&iedModel_GGIO_INGGIO1_Ind57_q,
		&iedModel_GGIO_INGGIO1_Ind58_q,
		&iedModel_GGIO_INGGIO1_Ind59_q,
		&iedModel_GGIO_INGGIO1_Ind60_q,
		&iedModel_GGIO_INGGIO1_Ind61_q,
		&iedModel_GGIO_INGGIO1_Ind62_q,
		&iedModel_GGIO_INGGIO1_Ind63_q,
		&iedModel_GGIO_INGGIO1_Ind64_q,
		&iedModel_GGIO_INGGIO1_Ind65_q,
		&iedModel_GGIO_INGGIO1_Ind66_q,
		&iedModel_GGIO_INGGIO1_Ind67_q,
		&iedModel_GGIO_INGGIO1_Ind68_q,
		&iedModel_GGIO_INGGIO1_Ind69_q,
		&iedModel_GGIO_INGGIO1_Ind70_q,
		&iedModel_GGIO_INGGIO1_Ind71_q,
		&iedModel_GGIO_INGGIO1_Ind72_q,
		&iedModel_GGIO_INGGIO1_Ind73_q,
		&iedModel_GGIO_INGGIO1_Ind74_q,
#if (MB_MaxNumbDiscreet>74)
		&iedModel_GGIO_INGGIO1_Ind75_q,
		&iedModel_GGIO_INGGIO1_Ind76_q,
		&iedModel_GGIO_INGGIO1_Ind77_q,
		&iedModel_GGIO_INGGIO1_Ind78_q,
		&iedModel_GGIO_INGGIO1_Ind79_q,
		&iedModel_GGIO_INGGIO1_Ind80_q,
		&iedModel_GGIO_INGGIO1_Ind81_q,
		&iedModel_GGIO_INGGIO1_Ind82_q,
		&iedModel_GGIO_INGGIO1_Ind83_q,
		&iedModel_GGIO_INGGIO1_Ind84_q,
		&iedModel_GGIO_INGGIO1_Ind85_q,
		&iedModel_GGIO_INGGIO1_Ind86_q,
		&iedModel_GGIO_INGGIO1_Ind87_q,
		&iedModel_GGIO_INGGIO1_Ind88_q,
		&iedModel_GGIO_INGGIO1_Ind89_q,
		&iedModel_GGIO_INGGIO1_Ind90_q,
		&iedModel_GGIO_INGGIO1_Ind91_q,
		&iedModel_GGIO_INGGIO1_Ind92_q,
		&iedModel_GGIO_INGGIO1_Ind93_q,
		&iedModel_GGIO_INGGIO1_Ind94_q,
		&iedModel_GGIO_INGGIO1_Ind95_q,
		&iedModel_GGIO_INGGIO1_Ind96_q,
		&iedModel_GGIO_INGGIO1_Ind97_q,
		&iedModel_GGIO_INGGIO1_Ind98_q,
		&iedModel_GGIO_INGGIO1_Ind99_q,
		&iedModel_GGIO_INGGIO1_Ind100_q,
		&iedModel_GGIO_INGGIO1_Ind101_q,
		&iedModel_GGIO_INGGIO1_Ind102_q,
		&iedModel_GGIO_INGGIO1_Ind103_q,
		&iedModel_GGIO_INGGIO1_Ind104_q,
		&iedModel_GGIO_INGGIO1_Ind105_q,
		&iedModel_GGIO_INGGIO1_Ind106_q,
#if (MB_MaxNumbDiscreet>106)
		&iedModel_GGIO_INGGIO1_Ind107_q,
		&iedModel_GGIO_INGGIO1_Ind108_q,
		&iedModel_GGIO_INGGIO1_Ind109_q,
		&iedModel_GGIO_INGGIO1_Ind110_q,
		&iedModel_GGIO_INGGIO1_Ind111_q,
		&iedModel_GGIO_INGGIO1_Ind112_q,
		&iedModel_GGIO_INGGIO1_Ind113_q,
		&iedModel_GGIO_INGGIO1_Ind114_q,
#endif//!#if (MB_MaxNumbDiscreet>106)
#endif//!#if (MB_MaxNumbDiscreet>74)

#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,
		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,
		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,
		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,
		&iedModel_GGIO_INGGIO1_Ind8_t,
		&iedModel_GGIO_INGGIO1_Ind9_t,
		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,
		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,
		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,
		&iedModel_GGIO_INGGIO1_Ind16_t,
		&iedModel_GGIO_INGGIO1_Ind17_t,
		&iedModel_GGIO_INGGIO1_Ind18_t,
		&iedModel_GGIO_INGGIO1_Ind19_t,
		&iedModel_GGIO_INGGIO1_Ind20_t,
		&iedModel_GGIO_INGGIO1_Ind21_t,
		&iedModel_GGIO_INGGIO1_Ind22_t,
		&iedModel_GGIO_INGGIO1_Ind23_t,
		&iedModel_GGIO_INGGIO1_Ind24_t,
		&iedModel_GGIO_INGGIO1_Ind25_t,
		&iedModel_GGIO_INGGIO1_Ind26_t,
		&iedModel_GGIO_INGGIO1_Ind27_t,
		&iedModel_GGIO_INGGIO1_Ind28_t,
		&iedModel_GGIO_INGGIO1_Ind29_t,
		&iedModel_GGIO_INGGIO1_Ind30_t,
		&iedModel_GGIO_INGGIO1_Ind31_t,
		&iedModel_GGIO_INGGIO1_Ind32_t,
		&iedModel_GGIO_INGGIO1_Ind33_t,
		&iedModel_GGIO_INGGIO1_Ind34_t,
		&iedModel_GGIO_INGGIO1_Ind35_t,
		&iedModel_GGIO_INGGIO1_Ind36_t,
		&iedModel_GGIO_INGGIO1_Ind37_t,
		&iedModel_GGIO_INGGIO1_Ind38_t,
		&iedModel_GGIO_INGGIO1_Ind39_t,
		&iedModel_GGIO_INGGIO1_Ind40_t,
		&iedModel_GGIO_INGGIO1_Ind41_t,
		&iedModel_GGIO_INGGIO1_Ind42_t,
#if defined	(MR761OBR)
		&iedModel_GGIO_INGGIO1_Ind43_t,
		&iedModel_GGIO_INGGIO1_Ind44_t,
		&iedModel_GGIO_INGGIO1_Ind45_t,
		&iedModel_GGIO_INGGIO1_Ind46_t,
		&iedModel_GGIO_INGGIO1_Ind47_t,
		&iedModel_GGIO_INGGIO1_Ind48_t,
		&iedModel_GGIO_INGGIO1_Ind49_t,
		&iedModel_GGIO_INGGIO1_Ind50_t,
		&iedModel_GGIO_INGGIO1_Ind51_t,
		&iedModel_GGIO_INGGIO1_Ind52_t,
		&iedModel_GGIO_INGGIO1_Ind53_t,
		&iedModel_GGIO_INGGIO1_Ind54_t,
		&iedModel_GGIO_INGGIO1_Ind55_t,
		&iedModel_GGIO_INGGIO1_Ind56_t,
		&iedModel_GGIO_INGGIO1_Ind57_t,
		&iedModel_GGIO_INGGIO1_Ind58_t,
		&iedModel_GGIO_INGGIO1_Ind59_t,
		&iedModel_GGIO_INGGIO1_Ind60_t,
		&iedModel_GGIO_INGGIO1_Ind61_t,
		&iedModel_GGIO_INGGIO1_Ind62_t,
		&iedModel_GGIO_INGGIO1_Ind63_t,
		&iedModel_GGIO_INGGIO1_Ind64_t,
		&iedModel_GGIO_INGGIO1_Ind65_t,
		&iedModel_GGIO_INGGIO1_Ind66_t,
		&iedModel_GGIO_INGGIO1_Ind67_t,
		&iedModel_GGIO_INGGIO1_Ind68_t,
		&iedModel_GGIO_INGGIO1_Ind69_t,
		&iedModel_GGIO_INGGIO1_Ind70_t,
		&iedModel_GGIO_INGGIO1_Ind71_t,
		&iedModel_GGIO_INGGIO1_Ind72_t,
		&iedModel_GGIO_INGGIO1_Ind73_t,
		&iedModel_GGIO_INGGIO1_Ind74_t,
#if (MB_MaxNumbDiscreet>74)
		&iedModel_GGIO_INGGIO1_Ind75_t,
		&iedModel_GGIO_INGGIO1_Ind76_t,
		&iedModel_GGIO_INGGIO1_Ind77_t,
		&iedModel_GGIO_INGGIO1_Ind78_t,
		&iedModel_GGIO_INGGIO1_Ind79_t,
		&iedModel_GGIO_INGGIO1_Ind80_t,
		&iedModel_GGIO_INGGIO1_Ind81_t,
		&iedModel_GGIO_INGGIO1_Ind82_t,
		&iedModel_GGIO_INGGIO1_Ind83_t,
		&iedModel_GGIO_INGGIO1_Ind84_t,
		&iedModel_GGIO_INGGIO1_Ind85_t,
		&iedModel_GGIO_INGGIO1_Ind86_t,
		&iedModel_GGIO_INGGIO1_Ind87_t,
		&iedModel_GGIO_INGGIO1_Ind88_t,
		&iedModel_GGIO_INGGIO1_Ind89_t,
		&iedModel_GGIO_INGGIO1_Ind90_t,
		&iedModel_GGIO_INGGIO1_Ind91_t,
		&iedModel_GGIO_INGGIO1_Ind92_t,
		&iedModel_GGIO_INGGIO1_Ind93_t,
		&iedModel_GGIO_INGGIO1_Ind94_t,
		&iedModel_GGIO_INGGIO1_Ind95_t,
		&iedModel_GGIO_INGGIO1_Ind96_t,
		&iedModel_GGIO_INGGIO1_Ind97_t,
		&iedModel_GGIO_INGGIO1_Ind98_t,
		&iedModel_GGIO_INGGIO1_Ind99_t,
		&iedModel_GGIO_INGGIO1_Ind100_t,
		&iedModel_GGIO_INGGIO1_Ind101_t,
		&iedModel_GGIO_INGGIO1_Ind102_t,
		&iedModel_GGIO_INGGIO1_Ind103_t,
		&iedModel_GGIO_INGGIO1_Ind104_t,
		&iedModel_GGIO_INGGIO1_Ind105_t,
		&iedModel_GGIO_INGGIO1_Ind106_t,
#if (MB_MaxNumbDiscreet>106)
		&iedModel_GGIO_INGGIO1_Ind107_t,
		&iedModel_GGIO_INGGIO1_Ind108_t,
		&iedModel_GGIO_INGGIO1_Ind109_t,
		&iedModel_GGIO_INGGIO1_Ind110_t,
		&iedModel_GGIO_INGGIO1_Ind111_t,
		&iedModel_GGIO_INGGIO1_Ind112_t,
		&iedModel_GGIO_INGGIO1_Ind113_t,
		&iedModel_GGIO_INGGIO1_Ind114_t,
#endif//!#if (MB_MaxNumbDiscreet>106)
#endif//!#if (MB_MaxNumbDiscreet>74)

#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,
		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,
		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,
		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,
		&iedModel_GGIO_INGGIO1_Ind8_stVal,
		&iedModel_GGIO_INGGIO1_Ind9_stVal,
		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,
		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,
		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,
		&iedModel_GGIO_INGGIO1_Ind16_stVal,
		&iedModel_GGIO_INGGIO1_Ind17_stVal,
		&iedModel_GGIO_INGGIO1_Ind18_stVal,
		&iedModel_GGIO_INGGIO1_Ind19_stVal,
		&iedModel_GGIO_INGGIO1_Ind20_stVal,
		&iedModel_GGIO_INGGIO1_Ind21_stVal,
		&iedModel_GGIO_INGGIO1_Ind22_stVal,
		&iedModel_GGIO_INGGIO1_Ind23_stVal,
		&iedModel_GGIO_INGGIO1_Ind24_stVal,
		&iedModel_GGIO_INGGIO1_Ind25_stVal,
		&iedModel_GGIO_INGGIO1_Ind26_stVal,
		&iedModel_GGIO_INGGIO1_Ind27_stVal,
		&iedModel_GGIO_INGGIO1_Ind28_stVal,
		&iedModel_GGIO_INGGIO1_Ind29_stVal,
		&iedModel_GGIO_INGGIO1_Ind30_stVal,
		&iedModel_GGIO_INGGIO1_Ind31_stVal,
		&iedModel_GGIO_INGGIO1_Ind32_stVal,
		&iedModel_GGIO_INGGIO1_Ind33_stVal,
		&iedModel_GGIO_INGGIO1_Ind34_stVal,
		&iedModel_GGIO_INGGIO1_Ind35_stVal,
		&iedModel_GGIO_INGGIO1_Ind36_stVal,
		&iedModel_GGIO_INGGIO1_Ind37_stVal,
		&iedModel_GGIO_INGGIO1_Ind38_stVal,
		&iedModel_GGIO_INGGIO1_Ind39_stVal,
		&iedModel_GGIO_INGGIO1_Ind40_stVal,
		&iedModel_GGIO_INGGIO1_Ind41_stVal,
		&iedModel_GGIO_INGGIO1_Ind42_stVal,
#if defined	(MR761OBR)
		&iedModel_GGIO_INGGIO1_Ind43_stVal,
		&iedModel_GGIO_INGGIO1_Ind44_stVal,
		&iedModel_GGIO_INGGIO1_Ind45_stVal,
		&iedModel_GGIO_INGGIO1_Ind46_stVal,
		&iedModel_GGIO_INGGIO1_Ind47_stVal,
		&iedModel_GGIO_INGGIO1_Ind48_stVal,
		&iedModel_GGIO_INGGIO1_Ind49_stVal,
		&iedModel_GGIO_INGGIO1_Ind50_stVal,
		&iedModel_GGIO_INGGIO1_Ind51_stVal,
		&iedModel_GGIO_INGGIO1_Ind52_stVal,
		&iedModel_GGIO_INGGIO1_Ind53_stVal,
		&iedModel_GGIO_INGGIO1_Ind54_stVal,
		&iedModel_GGIO_INGGIO1_Ind55_stVal,
		&iedModel_GGIO_INGGIO1_Ind56_stVal,
		&iedModel_GGIO_INGGIO1_Ind57_stVal,
		&iedModel_GGIO_INGGIO1_Ind58_stVal,
		&iedModel_GGIO_INGGIO1_Ind59_stVal,
		&iedModel_GGIO_INGGIO1_Ind60_stVal,
		&iedModel_GGIO_INGGIO1_Ind61_stVal,
		&iedModel_GGIO_INGGIO1_Ind62_stVal,
		&iedModel_GGIO_INGGIO1_Ind63_stVal,
		&iedModel_GGIO_INGGIO1_Ind64_stVal,
		&iedModel_GGIO_INGGIO1_Ind65_stVal,
		&iedModel_GGIO_INGGIO1_Ind66_stVal,
		&iedModel_GGIO_INGGIO1_Ind67_stVal,
		&iedModel_GGIO_INGGIO1_Ind68_stVal,
		&iedModel_GGIO_INGGIO1_Ind69_stVal,
		&iedModel_GGIO_INGGIO1_Ind70_stVal,
		&iedModel_GGIO_INGGIO1_Ind71_stVal,
		&iedModel_GGIO_INGGIO1_Ind72_stVal,
		&iedModel_GGIO_INGGIO1_Ind73_stVal,
		&iedModel_GGIO_INGGIO1_Ind74_stVal,
#if (MB_MaxNumbDiscreet>74)
		&iedModel_GGIO_INGGIO1_Ind75_stVal,
		&iedModel_GGIO_INGGIO1_Ind76_stVal,
		&iedModel_GGIO_INGGIO1_Ind77_stVal,
		&iedModel_GGIO_INGGIO1_Ind78_stVal,
		&iedModel_GGIO_INGGIO1_Ind79_stVal,
		&iedModel_GGIO_INGGIO1_Ind80_stVal,
		&iedModel_GGIO_INGGIO1_Ind81_stVal,
		&iedModel_GGIO_INGGIO1_Ind82_stVal,
		&iedModel_GGIO_INGGIO1_Ind83_stVal,
		&iedModel_GGIO_INGGIO1_Ind84_stVal,
		&iedModel_GGIO_INGGIO1_Ind85_stVal,
		&iedModel_GGIO_INGGIO1_Ind86_stVal,
		&iedModel_GGIO_INGGIO1_Ind87_stVal,
		&iedModel_GGIO_INGGIO1_Ind88_stVal,
		&iedModel_GGIO_INGGIO1_Ind89_stVal,
		&iedModel_GGIO_INGGIO1_Ind90_stVal,
		&iedModel_GGIO_INGGIO1_Ind91_stVal,
		&iedModel_GGIO_INGGIO1_Ind92_stVal,
		&iedModel_GGIO_INGGIO1_Ind93_stVal,
		&iedModel_GGIO_INGGIO1_Ind94_stVal,
		&iedModel_GGIO_INGGIO1_Ind95_stVal,
		&iedModel_GGIO_INGGIO1_Ind96_stVal,
		&iedModel_GGIO_INGGIO1_Ind97_stVal,
		&iedModel_GGIO_INGGIO1_Ind98_stVal,
		&iedModel_GGIO_INGGIO1_Ind99_stVal,
		&iedModel_GGIO_INGGIO1_Ind100_stVal,
		&iedModel_GGIO_INGGIO1_Ind101_stVal,
		&iedModel_GGIO_INGGIO1_Ind102_stVal,
		&iedModel_GGIO_INGGIO1_Ind103_stVal,
		&iedModel_GGIO_INGGIO1_Ind104_stVal,
		&iedModel_GGIO_INGGIO1_Ind105_stVal,
		&iedModel_GGIO_INGGIO1_Ind106_stVal,
#if (MB_MaxNumbDiscreet>106)
		&iedModel_GGIO_INGGIO1_Ind107_stVal,
		&iedModel_GGIO_INGGIO1_Ind108_stVal,
		&iedModel_GGIO_INGGIO1_Ind109_stVal,
		&iedModel_GGIO_INGGIO1_Ind110_stVal,
		&iedModel_GGIO_INGGIO1_Ind111_stVal,
		&iedModel_GGIO_INGGIO1_Ind112_stVal,
		&iedModel_GGIO_INGGIO1_Ind113_stVal,
		&iedModel_GGIO_INGGIO1_Ind114_stVal,
#endif//!#if (MB_MaxNumbDiscreet>106)
#endif//!#if (MB_MaxNumbDiscreet>74)

#endif
};
// --------------------------------------------------------------------------
int		Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
uint32_t	Mod = STVALINT32_ON;
uint32_t	Health = STVALINT32_OK;
uint8_t 	i;
int			ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality   = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM5 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM6 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------

	//  Mod Beh
	if (
			(ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1) ||
			(ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2) ||
			(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3) ||
			(ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)
#if defined	(MR761OBR)
			|| (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)
			|| (ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)
#endif
		) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	if (Q) {
		if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)		qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)		qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
#if defined	(MR761OBR)
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffset_errorM5)		qualityM5 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM6] & MB_bOffset_errorM6)		qualityM6 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
#endif
	}
	// �������� �� ����
	for (i = 0; i < MB_MaxNumbDiscreet; i++) {
		if ((num == 0) || (num == i+1)){
			// GOOSE ���������� �����, ���� �� ��������� ���� ������� �������
			// ������� ������� �� �������� ���� �� �������
/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}
*/
			if (Q) {
#if !defined	(MR761OBR)
				      if (i>=0 && i<8) quality = qualityM2;
				else if (i>7  && i<24) quality = qualityM3;
				else if (i>23 && i<40) quality = qualityM4;

				else if (i>39 && i<41) quality = qualityM1;
#endif
#if defined	(MR761OBR) && defined (T0N0D114R59)
				     if (i>=_begin_Discreet_M1 && i<=_end_Discreet_M1)	quality = qualityM1;
				else if (i>=_begin_Discreet_M2 && i<=_end_Discreet_M2) 	quality = qualityM2;
				else if (i>=_begin_Discreet_M3 && i<=_end_Discreet_M3) 	quality = qualityM3;
				else if (i>=_begin_Discreet_M4 && i<=_end_Discreet_M4)	quality = qualityM4;
				else if (i>=_begin_Discreet_M5 && i<=_end_Discreet_M5)	quality = qualityM5;
				else if (i>=_begin_Discreet_M6 && i<=_end_Discreet_M6)	quality = qualityM6;
#endif

				if (IedServer_updateQuality(iedServer, iedModel_GGIO_INGGIO1_Ind_q[i],quality))
					ret = true;
			}
			bool	value = ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],iedModel_GGIO_INGGIO1_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  value);}

		}
	}

return	ret;
}
/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={	//42
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8,
		MB_offsetRelay_9,		MB_bOffset_Relay_9,
		MB_offsetRelay_10,		MB_bOffset_Relay_10,
		MB_offsetRelay_11,		MB_bOffset_Relay_11,
		MB_offsetRelay_12,		MB_bOffset_Relay_12,
		MB_offsetRelay_13,		MB_bOffset_Relay_13,
		MB_offsetRelay_14,		MB_bOffset_Relay_14,
		MB_offsetRelay_15,		MB_bOffset_Relay_15,
		MB_offsetRelay_16,		MB_bOffset_Relay_16,
		MB_offsetRelay_17,		MB_bOffset_Relay_17,
		MB_offsetRelay_18,		MB_bOffset_Relay_18,
		MB_offsetRelay_19,		MB_bOffset_Relay_19,
		MB_offsetRelay_20,		MB_bOffset_Relay_20,
		MB_offsetRelay_21,		MB_bOffset_Relay_21,
		MB_offsetRelay_22,		MB_bOffset_Relay_22,
		MB_offsetRelay_23,		MB_bOffset_Relay_23,
		MB_offsetRelay_24,		MB_bOffset_Relay_24,
		MB_offsetRelay_25,		MB_bOffset_Relay_25,
		MB_offsetRelay_26,		MB_bOffset_Relay_26,
		MB_offsetRelay_27,		MB_bOffset_Relay_27,
		MB_offsetRelay_28,		MB_bOffset_Relay_28,
		MB_offsetRelay_29,		MB_bOffset_Relay_29,
		MB_offsetRelay_30,		MB_bOffset_Relay_30,
		MB_offsetRelay_31,		MB_bOffset_Relay_31,
		MB_offsetRelay_32,		MB_bOffset_Relay_32,
		MB_offsetRelay_33,		MB_bOffset_Relay_33,
		MB_offsetRelay_34,		MB_bOffset_Relay_34,
#if (MB_MaxNumbRelay>34)
		MB_offsetRelay_35,		MB_bOffset_Relay_35,
		MB_offsetRelay_36,		MB_bOffset_Relay_36,
		MB_offsetRelay_37,		MB_bOffset_Relay_37,
		MB_offsetRelay_38,		MB_bOffset_Relay_38,
		MB_offsetRelay_39,		MB_bOffset_Relay_39,
		MB_offsetRelay_40,		MB_bOffset_Relay_40,
		MB_offsetRelay_41,		MB_bOffset_Relay_41,
		MB_offsetRelay_42,		MB_bOffset_Relay_42,
		MB_offsetRelay_43,		MB_bOffset_Relay_43,
		MB_offsetRelay_44,		MB_bOffset_Relay_44,
		MB_offsetRelay_45,		MB_bOffset_Relay_45,
		MB_offsetRelay_46,		MB_bOffset_Relay_46,
		MB_offsetRelay_47,		MB_bOffset_Relay_47,
		MB_offsetRelay_48,		MB_bOffset_Relay_48,
		MB_offsetRelay_49,		MB_bOffset_Relay_49,
		MB_offsetRelay_50,		MB_bOffset_Relay_50,
		MB_offsetRelay_51,		MB_bOffset_Relay_51,
		MB_offsetRelay_52,		MB_bOffset_Relay_52,
		MB_offsetRelay_53,		MB_bOffset_Relay_53,
		MB_offsetRelay_54,		MB_bOffset_Relay_54,
		MB_offsetRelay_55,		MB_bOffset_Relay_55,
		MB_offsetRelay_56,		MB_bOffset_Relay_56,
		MB_offsetRelay_57,		MB_bOffset_Relay_57,
		MB_offsetRelay_58,		MB_bOffset_Relay_58,
#if (MB_MaxNumbRelay>58)
		MB_offsetRelay_59,		MB_bOffset_Relay_59,
		MB_offsetRelay_60,		MB_bOffset_Relay_60,
		MB_offsetRelay_61,		MB_bOffset_Relay_61,
		MB_offsetRelay_62,		MB_bOffset_Relay_62,
		MB_offsetRelay_63,		MB_bOffset_Relay_63,
		MB_offsetRelay_64,		MB_bOffset_Relay_64,
		MB_offsetRelay_65,		MB_bOffset_Relay_65,
		MB_offsetRelay_66,		MB_bOffset_Relay_66,
		MB_offsetRelay_67,		MB_bOffset_Relay_67,
		MB_offsetRelay_68,		MB_bOffset_Relay_68,
		MB_offsetRelay_69,		MB_bOffset_Relay_69,
		MB_offsetRelay_70,		MB_bOffset_Relay_70,
		MB_offsetRelay_71,		MB_bOffset_Relay_71,
		MB_offsetRelay_72,		MB_bOffset_Relay_72,
		MB_offsetRelay_73,		MB_bOffset_Relay_73,
		MB_offsetRelay_74,		MB_bOffset_Relay_74,
		MB_offsetRelay_75,		MB_bOffset_Relay_75,
		MB_offsetRelay_76,		MB_bOffset_Relay_76,
		MB_offsetRelay_77,		MB_bOffset_Relay_77,
		MB_offsetRelay_78,		MB_bOffset_Relay_78,
		MB_offsetRelay_79,		MB_bOffset_Relay_79,
		MB_offsetRelay_80,		MB_bOffset_Relay_80,
#endif//!#if (MB_MaxNumbRelay>58)
#endif//!#if (MB_MaxNumbRelay>34)
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_q,
#if (MB_MaxNumbRelay>34)
		&iedModel_GGIO_OUTGGIO1_SPCSO35_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO36_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO38_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO40_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO42_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO44_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO46_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO48_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO50_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO51_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO52_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO53_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO54_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO55_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO56_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO57_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO58_q,

#if (MB_MaxNumbRelay>58)
		&iedModel_GGIO_OUTGGIO1_SPCSO59_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO60_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO61_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO62_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO63_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO64_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO65_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO66_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO67_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO68_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO69_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO70_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO71_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO72_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO73_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO74_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO75_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO76_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO77_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO78_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO79_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO80_q,

#endif//!#if (MB_MaxNumbRelay>58)
#endif//!#if (MB_MaxNumbRelay>34)
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_t,
#if (MB_MaxNumbRelay>34)
		&iedModel_GGIO_OUTGGIO1_SPCSO35_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO36_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO38_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO40_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO42_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO44_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO46_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO48_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO50_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO51_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO52_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO53_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO54_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO55_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO56_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO57_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO58_t,

#if (MB_MaxNumbRelay>58)
		&iedModel_GGIO_OUTGGIO1_SPCSO59_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO60_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO61_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO62_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO63_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO64_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO65_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO66_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO67_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO68_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO69_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO70_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO71_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO72_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO73_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO74_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO75_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO76_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO77_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO78_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO79_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO80_t,

#endif//!#if (MB_MaxNumbRelay>58)
#endif//!#if (MB_MaxNumbRelay>34)
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,
#if (MB_MaxNumbRelay>34)
		&iedModel_GGIO_OUTGGIO1_SPCSO35_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO36_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO37_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO38_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO39_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO40_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO41_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO42_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO43_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO44_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO45_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO46_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO47_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO48_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO49_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO50_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO51_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO52_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO53_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO54_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO55_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO56_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO57_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO58_stVal,

#if (MB_MaxNumbRelay>58)
		&iedModel_GGIO_OUTGGIO1_SPCSO59_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO60_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO61_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO62_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO63_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO64_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO65_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO66_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO67_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO68_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO69_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO70_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO71_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO72_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO73_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO74_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO75_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO76_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO77_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO78_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO79_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO80_stVal,

#endif//!#if (MB_MaxNumbRelay>58)
#endif//!#if (MB_MaxNumbRelay>34)
};
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality  	= QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 	= QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 	= QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 	= QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 	= QUALITY_VALIDITY_GOOD;
	Quality		qualityVIRT = QUALITY_VALIDITY_GOOD;

	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbRelay)	return ret;
// -----------------------------------------------------------------------------

	if (
			(ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1) ||
			(ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2) ||
			(ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)
#if defined	(MR761OBR)
			|| 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)
#endif
		) {Health = STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}


	if (Q) {
		if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)			qualityM1 	= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)			qualityM2 	= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)			qualityM3 	= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffset_errorM4)			qualityM4 	= QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	qualityVIRT = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{
			qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		}


	}

	// ~2K ������������ ���� ������ ��� ������ ����������
	// �������� �� ����
	for (i = 0; i < MB_MaxNumbRelay; i++) {
		if (num == 0 || num == i+1){
/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
*/
			if (Q) {
#if !defined	(MR761OBR)
				if (i>=0 && i<10) quality = qualityM1; else
				if (i>9  && i<18) quality = qualityM2; else
				if (i>17 && i<34) quality = qualityM4;
#endif
#if defined	(MR761OBR) && defined (T0N0D114R59)
				     if (i>=_begin_Relay_M1 	&& i<=_end_Relay_M1)		quality = qualityM1;
				else if (i>=_begin_Relay_M2 	&& i<=_end_Relay_M2)		quality = qualityM2;
				else if (i>=_begin_Relay_M3 	&& i<=_end_Relay_M3)		quality = qualityM3;
				else if (i>=_begin_Relay_M4 	&& i<=_end_Relay_M4)		quality = qualityM4;
				else if (i>=_begin_Relay_VIRT 	&& i<=_end_Relay_VIRT)		quality = qualityVIRT;

#endif

				if (IedServer_updateQuality(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_q[i],quality)) ret = true;
			}

			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],iedModel_GGIO_OUTGGIO1_SPCSO_t[i],currentTime,  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]);}

		}
	}
	return	ret;
}

/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *
 * ���� ��������.(�����)
 * MR761	-	12.01.2018	 - ��
 *
 *******************************************************/
uint16_t LED_G_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1g,		MB_bOffset_LED_1g,
		MB_offsetLED_2g,		MB_bOffset_LED_2g,
		MB_offsetLED_3g,		MB_bOffset_LED_3g,
		MB_offsetLED_4g,		MB_bOffset_LED_4g,
		MB_offsetLED_5g,		MB_bOffset_LED_5g,
		MB_offsetLED_6g,		MB_bOffset_LED_6g,
		MB_offsetLED_7g,		MB_bOffset_LED_7g,
		MB_offsetLED_8g,		MB_bOffset_LED_8g,
		MB_offsetLED_9g,		MB_bOffset_LED_9g,
		MB_offsetLED_10g,		MB_bOffset_LED_10g,
		MB_offsetLED_11g,		MB_bOffset_LED_11g,
		MB_offsetLED_12g,		MB_bOffset_LED_12g,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};
uint16_t LED_R_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1r,		MB_bOffset_LED_1r,
		MB_offsetLED_2r,		MB_bOffset_LED_2r,
		MB_offsetLED_3r,		MB_bOffset_LED_3r,
		MB_offsetLED_4r,		MB_bOffset_LED_4r,
		MB_offsetLED_5r,		MB_bOffset_LED_5r,
		MB_offsetLED_6r,		MB_bOffset_LED_6r,
		MB_offsetLED_7r,		MB_bOffset_LED_7r,
		MB_offsetLED_8r,		MB_bOffset_LED_8r,
		MB_offsetLED_9r,		MB_bOffset_LED_9r,
		MB_offsetLED_10r,		MB_bOffset_LED_10r,
		MB_offsetLED_11r,		MB_bOffset_LED_11r,
		MB_offsetLED_12r,		MB_bOffset_LED_12r,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};

DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_q[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_q,
		&iedModel_GGIO_LEDGGIO1_Ind2_q,
		&iedModel_GGIO_LEDGGIO1_Ind3_q,
		&iedModel_GGIO_LEDGGIO1_Ind4_q,
		&iedModel_GGIO_LEDGGIO1_Ind5_q,
		&iedModel_GGIO_LEDGGIO1_Ind6_q,
		&iedModel_GGIO_LEDGGIO1_Ind7_q,
		&iedModel_GGIO_LEDGGIO1_Ind8_q,
		&iedModel_GGIO_LEDGGIO1_Ind9_q,
		&iedModel_GGIO_LEDGGIO1_Ind10_q,
		&iedModel_GGIO_LEDGGIO1_Ind11_q,
		&iedModel_GGIO_LEDGGIO1_Ind12_q,
		&iedModel_GGIO_LEDGGIO1_Ind13_q,
		&iedModel_GGIO_LEDGGIO1_Ind14_q,
		&iedModel_GGIO_LEDGGIO1_Ind15_q,
		&iedModel_GGIO_LEDGGIO1_Ind16_q
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_t[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_t,
		&iedModel_GGIO_LEDGGIO1_Ind2_t,
		&iedModel_GGIO_LEDGGIO1_Ind3_t,
		&iedModel_GGIO_LEDGGIO1_Ind4_t,
		&iedModel_GGIO_LEDGGIO1_Ind5_t,
		&iedModel_GGIO_LEDGGIO1_Ind6_t,
		&iedModel_GGIO_LEDGGIO1_Ind7_t,
		&iedModel_GGIO_LEDGGIO1_Ind8_t,
		&iedModel_GGIO_LEDGGIO1_Ind9_t,
		&iedModel_GGIO_LEDGGIO1_Ind10_t,
		&iedModel_GGIO_LEDGGIO1_Ind11_t,
		&iedModel_GGIO_LEDGGIO1_Ind12_t,
		&iedModel_GGIO_LEDGGIO1_Ind13_t,
		&iedModel_GGIO_LEDGGIO1_Ind14_t,
		&iedModel_GGIO_LEDGGIO1_Ind15_t,
		&iedModel_GGIO_LEDGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_stVal[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind2_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind3_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind4_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind5_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind6_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind7_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind8_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind9_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind10_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind11_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind12_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind13_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind14_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind15_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind16_stVal
};
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	bool value;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
	if(num > MB_MaxNumbLED)	return ret;
// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	for (i = 0; i < MB_MaxNumbLED; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LEDGGIO1_Ind_q[i],quality)) ret = true;

			value = ((ucMDiscInBuf[LED_G_Buf[i][0]] & LED_G_Buf[i][1]) || (ucMDiscInBuf[LED_R_Buf[i][0]] & LED_R_Buf[i][1]));
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],iedModel_GGIO_LEDGGIO1_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],  value);}

		}
	}
return	ret;
}

/*******************************************************
 * Set_SSLGGIO ��������� ������������ �������
 *******************************************************/
uint16_t SSLBuf[MB_MaxNumbSSL][2] ={
		MB_offsetSSL_1,		MB_bOffset_SSL_1,
		MB_offsetSSL_2,		MB_bOffset_SSL_2,
		MB_offsetSSL_3,		MB_bOffset_SSL_3,
		MB_offsetSSL_4,		MB_bOffset_SSL_4,
		MB_offsetSSL_5,		MB_bOffset_SSL_5,
		MB_offsetSSL_6,		MB_bOffset_SSL_6,
		MB_offsetSSL_7,		MB_bOffset_SSL_7,
		MB_offsetSSL_8,		MB_bOffset_SSL_8,
		MB_offsetSSL_9,		MB_bOffset_SSL_9,
		MB_offsetSSL_10,	MB_bOffset_SSL_10,
		MB_offsetSSL_11,	MB_bOffset_SSL_11,
		MB_offsetSSL_12,	MB_bOffset_SSL_12,
		MB_offsetSSL_13,	MB_bOffset_SSL_13,
		MB_offsetSSL_14,	MB_bOffset_SSL_14,
		MB_offsetSSL_15,	MB_bOffset_SSL_15,
		MB_offsetSSL_16,	MB_bOffset_SSL_16,
		MB_offsetSSL_17,	MB_bOffset_SSL_17,
		MB_offsetSSL_18,	MB_bOffset_SSL_18,
		MB_offsetSSL_19,	MB_bOffset_SSL_19,
		MB_offsetSSL_20,	MB_bOffset_SSL_20,
		MB_offsetSSL_21,	MB_bOffset_SSL_21,
		MB_offsetSSL_22,	MB_bOffset_SSL_22,
		MB_offsetSSL_23,	MB_bOffset_SSL_23,
		MB_offsetSSL_24,	MB_bOffset_SSL_24,
		MB_offsetSSL_25,	MB_bOffset_SSL_25,
		MB_offsetSSL_26,	MB_bOffset_SSL_26,
		MB_offsetSSL_27,	MB_bOffset_SSL_27,
		MB_offsetSSL_28,	MB_bOffset_SSL_28,
		MB_offsetSSL_29,	MB_bOffset_SSL_29,
		MB_offsetSSL_30,	MB_bOffset_SSL_30,
		MB_offsetSSL_31,	MB_bOffset_SSL_31,
		MB_offsetSSL_32,	MB_bOffset_SSL_32,
#if (MB_MaxNumbSSL>32) 	//defined (MR761) && (defined (T4N4D42R35)||defined (T4N5D42R35))
		MB_offsetSSL_33,	MB_bOffset_SSL_33,
		MB_offsetSSL_34,	MB_bOffset_SSL_34,
		MB_offsetSSL_35,	MB_bOffset_SSL_35,
		MB_offsetSSL_36,	MB_bOffset_SSL_36,
		MB_offsetSSL_37,	MB_bOffset_SSL_37,
		MB_offsetSSL_38,	MB_bOffset_SSL_38,
		MB_offsetSSL_39,	MB_bOffset_SSL_39,
		MB_offsetSSL_40,	MB_bOffset_SSL_40,
		MB_offsetSSL_41,	MB_bOffset_SSL_41,
		MB_offsetSSL_42,	MB_bOffset_SSL_42,
		MB_offsetSSL_43,	MB_bOffset_SSL_43,
		MB_offsetSSL_44,	MB_bOffset_SSL_44,
		MB_offsetSSL_45,	MB_bOffset_SSL_45,
		MB_offsetSSL_46,	MB_bOffset_SSL_46,
		MB_offsetSSL_47,	MB_bOffset_SSL_47,
		MB_offsetSSL_48,	MB_bOffset_SSL_48,
#endif
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_q[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_q,		&iedModel_GGIO_SSLGGIO1_Ind2_q,
		&iedModel_GGIO_SSLGGIO1_Ind3_q,		&iedModel_GGIO_SSLGGIO1_Ind4_q,
		&iedModel_GGIO_SSLGGIO1_Ind5_q,		&iedModel_GGIO_SSLGGIO1_Ind6_q,
		&iedModel_GGIO_SSLGGIO1_Ind7_q,		&iedModel_GGIO_SSLGGIO1_Ind8_q,
		&iedModel_GGIO_SSLGGIO1_Ind9_q,		&iedModel_GGIO_SSLGGIO1_Ind10_q,
		&iedModel_GGIO_SSLGGIO1_Ind11_q,	&iedModel_GGIO_SSLGGIO1_Ind12_q,
		&iedModel_GGIO_SSLGGIO1_Ind13_q,	&iedModel_GGIO_SSLGGIO1_Ind14_q,
		&iedModel_GGIO_SSLGGIO1_Ind15_q,	&iedModel_GGIO_SSLGGIO1_Ind16_q,
		&iedModel_GGIO_SSLGGIO1_Ind17_q,	&iedModel_GGIO_SSLGGIO1_Ind18_q,
		&iedModel_GGIO_SSLGGIO1_Ind19_q,	&iedModel_GGIO_SSLGGIO1_Ind20_q,
		&iedModel_GGIO_SSLGGIO1_Ind21_q,	&iedModel_GGIO_SSLGGIO1_Ind22_q,
		&iedModel_GGIO_SSLGGIO1_Ind23_q,	&iedModel_GGIO_SSLGGIO1_Ind24_q,
		&iedModel_GGIO_SSLGGIO1_Ind25_q,	&iedModel_GGIO_SSLGGIO1_Ind26_q,
		&iedModel_GGIO_SSLGGIO1_Ind27_q,	&iedModel_GGIO_SSLGGIO1_Ind28_q,
		&iedModel_GGIO_SSLGGIO1_Ind29_q,	&iedModel_GGIO_SSLGGIO1_Ind30_q,
		&iedModel_GGIO_SSLGGIO1_Ind31_q,	&iedModel_GGIO_SSLGGIO1_Ind32_q,
#if (MB_MaxNumbSSL>32) 	//defined (MR761) && (defined (T4N4D42R35)||defined (T4N5D42R35))
		&iedModel_GGIO_SSLGGIO1_Ind33_q,	&iedModel_GGIO_SSLGGIO1_Ind34_q,
		&iedModel_GGIO_SSLGGIO1_Ind35_q,	&iedModel_GGIO_SSLGGIO1_Ind36_q,
		&iedModel_GGIO_SSLGGIO1_Ind37_q,	&iedModel_GGIO_SSLGGIO1_Ind38_q,
		&iedModel_GGIO_SSLGGIO1_Ind39_q,	&iedModel_GGIO_SSLGGIO1_Ind40_q,
		&iedModel_GGIO_SSLGGIO1_Ind41_q,	&iedModel_GGIO_SSLGGIO1_Ind42_q,
		&iedModel_GGIO_SSLGGIO1_Ind43_q,	&iedModel_GGIO_SSLGGIO1_Ind44_q,
		&iedModel_GGIO_SSLGGIO1_Ind45_q,	&iedModel_GGIO_SSLGGIO1_Ind46_q,
		&iedModel_GGIO_SSLGGIO1_Ind47_q,	&iedModel_GGIO_SSLGGIO1_Ind48_q,
#endif
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_t[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_t,		&iedModel_GGIO_SSLGGIO1_Ind2_t,
		&iedModel_GGIO_SSLGGIO1_Ind3_t,		&iedModel_GGIO_SSLGGIO1_Ind4_t,
		&iedModel_GGIO_SSLGGIO1_Ind5_t,		&iedModel_GGIO_SSLGGIO1_Ind6_t,
		&iedModel_GGIO_SSLGGIO1_Ind7_t,		&iedModel_GGIO_SSLGGIO1_Ind8_t,
		&iedModel_GGIO_SSLGGIO1_Ind9_t,		&iedModel_GGIO_SSLGGIO1_Ind10_t,
		&iedModel_GGIO_SSLGGIO1_Ind11_t,	&iedModel_GGIO_SSLGGIO1_Ind12_t,
		&iedModel_GGIO_SSLGGIO1_Ind13_t,	&iedModel_GGIO_SSLGGIO1_Ind14_t,
		&iedModel_GGIO_SSLGGIO1_Ind15_t,	&iedModel_GGIO_SSLGGIO1_Ind16_t,
		&iedModel_GGIO_SSLGGIO1_Ind17_t,	&iedModel_GGIO_SSLGGIO1_Ind18_t,
		&iedModel_GGIO_SSLGGIO1_Ind19_t,	&iedModel_GGIO_SSLGGIO1_Ind20_t,
		&iedModel_GGIO_SSLGGIO1_Ind21_t,	&iedModel_GGIO_SSLGGIO1_Ind22_t,
		&iedModel_GGIO_SSLGGIO1_Ind23_t,	&iedModel_GGIO_SSLGGIO1_Ind24_t,
		&iedModel_GGIO_SSLGGIO1_Ind25_t,	&iedModel_GGIO_SSLGGIO1_Ind26_t,
		&iedModel_GGIO_SSLGGIO1_Ind27_t,	&iedModel_GGIO_SSLGGIO1_Ind28_t,
		&iedModel_GGIO_SSLGGIO1_Ind29_t,	&iedModel_GGIO_SSLGGIO1_Ind30_t,
		&iedModel_GGIO_SSLGGIO1_Ind31_t,	&iedModel_GGIO_SSLGGIO1_Ind32_t,
#if (MB_MaxNumbSSL>32) 	//defined (MR761) && (defined (T4N4D42R35)||defined (T4N5D42R35))
		&iedModel_GGIO_SSLGGIO1_Ind33_t,	&iedModel_GGIO_SSLGGIO1_Ind34_t,
		&iedModel_GGIO_SSLGGIO1_Ind35_t,	&iedModel_GGIO_SSLGGIO1_Ind36_t,
		&iedModel_GGIO_SSLGGIO1_Ind37_t,	&iedModel_GGIO_SSLGGIO1_Ind38_t,
		&iedModel_GGIO_SSLGGIO1_Ind39_t,	&iedModel_GGIO_SSLGGIO1_Ind40_t,
		&iedModel_GGIO_SSLGGIO1_Ind41_t,	&iedModel_GGIO_SSLGGIO1_Ind42_t,
		&iedModel_GGIO_SSLGGIO1_Ind43_t,	&iedModel_GGIO_SSLGGIO1_Ind44_t,
		&iedModel_GGIO_SSLGGIO1_Ind45_t,	&iedModel_GGIO_SSLGGIO1_Ind46_t,
		&iedModel_GGIO_SSLGGIO1_Ind47_t,	&iedModel_GGIO_SSLGGIO1_Ind48_t,
#endif
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_stVal[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_stVal,		&iedModel_GGIO_SSLGGIO1_Ind2_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind3_stVal,		&iedModel_GGIO_SSLGGIO1_Ind4_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind5_stVal,		&iedModel_GGIO_SSLGGIO1_Ind6_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind7_stVal,		&iedModel_GGIO_SSLGGIO1_Ind8_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind9_stVal,		&iedModel_GGIO_SSLGGIO1_Ind10_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind11_stVal,	&iedModel_GGIO_SSLGGIO1_Ind12_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind13_stVal,	&iedModel_GGIO_SSLGGIO1_Ind14_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind15_stVal,	&iedModel_GGIO_SSLGGIO1_Ind16_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind17_stVal,	&iedModel_GGIO_SSLGGIO1_Ind18_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind19_stVal,	&iedModel_GGIO_SSLGGIO1_Ind20_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind21_stVal,	&iedModel_GGIO_SSLGGIO1_Ind22_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind23_stVal,	&iedModel_GGIO_SSLGGIO1_Ind24_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind25_stVal,	&iedModel_GGIO_SSLGGIO1_Ind26_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind27_stVal,	&iedModel_GGIO_SSLGGIO1_Ind28_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind29_stVal,	&iedModel_GGIO_SSLGGIO1_Ind30_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind31_stVal,	&iedModel_GGIO_SSLGGIO1_Ind32_stVal,
#if (MB_MaxNumbSSL>32) 	//defined (MR761) && (defined (T4N4D42R35)||defined (T4N5D42R35))
		&iedModel_GGIO_SSLGGIO1_Ind33_stVal,	&iedModel_GGIO_SSLGGIO1_Ind34_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind35_stVal,	&iedModel_GGIO_SSLGGIO1_Ind36_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind37_stVal,	&iedModel_GGIO_SSLGGIO1_Ind38_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind39_stVal,	&iedModel_GGIO_SSLGGIO1_Ind40_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind41_stVal,	&iedModel_GGIO_SSLGGIO1_Ind42_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind43_stVal,	&iedModel_GGIO_SSLGGIO1_Ind44_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind45_stVal,	&iedModel_GGIO_SSLGGIO1_Ind46_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind47_stVal,	&iedModel_GGIO_SSLGGIO1_Ind48_stVal,
#endif
};
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint8_t	i;
	int	ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbSSL)	return ret;
	// -----------------------------------------------------------------------------
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffset_errorALLLogic) 	{Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}

	// �������� �� ����
	for (i = 0; i < MB_MaxNumbSSL; i++) {
		if (num == 0 || num == i+1){

			/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			*/
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_SSLGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],iedModel_GGIO_SSLGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  value);}
		}
	}
return ret;
}
/*******************************************************
 * Set_VLSGGIO ��������� ������������ �������
 *******************************************************/
uint16_t VLSBuf[MB_MaxNumbVLS][2] ={
		MB_offsetVLS_1,		MB_bOffset_VLS_1,
		MB_offsetVLS_2,		MB_bOffset_VLS_2,
		MB_offsetVLS_3,		MB_bOffset_VLS_3,
		MB_offsetVLS_4,		MB_bOffset_VLS_4,
		MB_offsetVLS_5,		MB_bOffset_VLS_5,
		MB_offsetVLS_6,		MB_bOffset_VLS_6,
		MB_offsetVLS_7,		MB_bOffset_VLS_7,
		MB_offsetVLS_8,		MB_bOffset_VLS_8,
		MB_offsetVLS_9,		MB_bOffset_VLS_9,
		MB_offsetVLS_10,	MB_bOffset_VLS_10,
		MB_offsetVLS_11,	MB_bOffset_VLS_11,
		MB_offsetVLS_12,	MB_bOffset_VLS_12,
		MB_offsetVLS_13,	MB_bOffset_VLS_13,
		MB_offsetVLS_14,	MB_bOffset_VLS_14,
		MB_offsetVLS_15,	MB_bOffset_VLS_15,
		MB_offsetVLS_16,	MB_bOffset_VLS_16
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_q[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_q,		&iedModel_GGIO_VLSGGIO1_Ind2_q,
		&iedModel_GGIO_VLSGGIO1_Ind3_q,		&iedModel_GGIO_VLSGGIO1_Ind4_q,
		&iedModel_GGIO_VLSGGIO1_Ind5_q,		&iedModel_GGIO_VLSGGIO1_Ind6_q,
		&iedModel_GGIO_VLSGGIO1_Ind7_q,		&iedModel_GGIO_VLSGGIO1_Ind8_q,
		&iedModel_GGIO_VLSGGIO1_Ind9_q,		&iedModel_GGIO_VLSGGIO1_Ind10_q,
		&iedModel_GGIO_VLSGGIO1_Ind11_q,	&iedModel_GGIO_VLSGGIO1_Ind12_q,
		&iedModel_GGIO_VLSGGIO1_Ind13_q,	&iedModel_GGIO_VLSGGIO1_Ind14_q,
		&iedModel_GGIO_VLSGGIO1_Ind15_q,	&iedModel_GGIO_VLSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_t[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_t,		&iedModel_GGIO_VLSGGIO1_Ind2_t,
		&iedModel_GGIO_VLSGGIO1_Ind3_t,		&iedModel_GGIO_VLSGGIO1_Ind4_t,
		&iedModel_GGIO_VLSGGIO1_Ind5_t,		&iedModel_GGIO_VLSGGIO1_Ind6_t,
		&iedModel_GGIO_VLSGGIO1_Ind7_t,		&iedModel_GGIO_VLSGGIO1_Ind8_t,
		&iedModel_GGIO_VLSGGIO1_Ind9_t,		&iedModel_GGIO_VLSGGIO1_Ind10_t,
		&iedModel_GGIO_VLSGGIO1_Ind11_t,	&iedModel_GGIO_VLSGGIO1_Ind12_t,
		&iedModel_GGIO_VLSGGIO1_Ind13_t,	&iedModel_GGIO_VLSGGIO1_Ind14_t,
		&iedModel_GGIO_VLSGGIO1_Ind15_t,	&iedModel_GGIO_VLSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_stVal[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_stVal,		&iedModel_GGIO_VLSGGIO1_Ind2_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind3_stVal,		&iedModel_GGIO_VLSGGIO1_Ind4_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind5_stVal,		&iedModel_GGIO_VLSGGIO1_Ind6_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind7_stVal,		&iedModel_GGIO_VLSGGIO1_Ind8_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind9_stVal,		&iedModel_GGIO_VLSGGIO1_Ind10_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind11_stVal,	&iedModel_GGIO_VLSGGIO1_Ind12_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind13_stVal,	&iedModel_GGIO_VLSGGIO1_Ind14_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind15_stVal,	&iedModel_GGIO_VLSGGIO1_Ind16_stVal
};
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbVLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbVLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VLSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[VLSBuf[i][0]] & VLSBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],iedModel_GGIO_VLSGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}
/*******************************************************
 * Set_LSGGIO ��������� ������������ �������
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,	MB_bOffset_LS_1,
		MB_offsetLS_2,	MB_bOffset_LS_2,
		MB_offsetLS_3,	MB_bOffset_LS_3,
		MB_offsetLS_4,	MB_bOffset_LS_4,
		MB_offsetLS_5,	MB_bOffset_LS_5,
		MB_offsetLS_6,	MB_bOffset_LS_6,
		MB_offsetLS_7,	MB_bOffset_LS_7,
		MB_offsetLS_8,	MB_bOffset_LS_8,
		MB_offsetLS_9,	MB_bOffset_LS_9,
		MB_offsetLS_10,	MB_bOffset_LS_10,
		MB_offsetLS_11,	MB_bOffset_LS_11,
		MB_offsetLS_12,	MB_bOffset_LS_12,
		MB_offsetLS_13,	MB_bOffset_LS_13,
		MB_offsetLS_14,	MB_bOffset_LS_14,
		MB_offsetLS_15,	MB_bOffset_LS_15,
		MB_offsetLS_16,	MB_bOffset_LS_16
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,	&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,	&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,	&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,	&iedModel_GGIO_LSGGIO1_Ind8_q,
		&iedModel_GGIO_LSGGIO1_Ind9_q,	&iedModel_GGIO_LSGGIO1_Ind10_q,
		&iedModel_GGIO_LSGGIO1_Ind11_q,	&iedModel_GGIO_LSGGIO1_Ind12_q,
		&iedModel_GGIO_LSGGIO1_Ind13_q,	&iedModel_GGIO_LSGGIO1_Ind14_q,
		&iedModel_GGIO_LSGGIO1_Ind15_q,	&iedModel_GGIO_LSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,	&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,	&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,	&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,	&iedModel_GGIO_LSGGIO1_Ind8_t,
		&iedModel_GGIO_LSGGIO1_Ind9_t,	&iedModel_GGIO_LSGGIO1_Ind10_t,
		&iedModel_GGIO_LSGGIO1_Ind11_t,	&iedModel_GGIO_LSGGIO1_Ind12_t,
		&iedModel_GGIO_LSGGIO1_Ind13_t,	&iedModel_GGIO_LSGGIO1_Ind14_t,
		&iedModel_GGIO_LSGGIO1_Ind15_t,	&iedModel_GGIO_LSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,	&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,	&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,	&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,	&iedModel_GGIO_LSGGIO1_Ind8_stVal,
		&iedModel_GGIO_LSGGIO1_Ind9_stVal,	&iedModel_GGIO_LSGGIO1_Ind10_stVal,
		&iedModel_GGIO_LSGGIO1_Ind11_stVal,	&iedModel_GGIO_LSGGIO1_Ind12_stVal,
		&iedModel_GGIO_LSGGIO1_Ind13_stVal,	&iedModel_GGIO_LSGGIO1_Ind14_stVal,
		&iedModel_GGIO_LSGGIO1_Ind15_stVal,	&iedModel_GGIO_LSGGIO1_Ind16_stVal
};
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int	ret = false;
	// �������� � ����� ������ �� ���������� ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// ����� ��������
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
		if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
		if(num > MB_MaxNumbLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// �������� �� ����
	int	i;
	for (i = 0; i < MB_MaxNumbLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[LSBuf[i][0]] & LSBuf[i][1];
			// ���� ����� ����� �������, �� ������� �������� ����� � ����� ������, ����� � ����� ��� ������ �����
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],iedModel_GGIO_LSGGIO_Ind_t[i],currentTime,  value);}
			// ���� ����� �� ����� (��� �����) �� ������ ������ ������
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}
#endif
/*******************************************************
 * MR901 MR901
 *******************************************************/
#if defined	(MR901) ||  defined	(MR902)
#include "static_model_MR901_902.h"


extern 	uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

/*******************************************************
 * ��������
 *******************************************************/
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_VZGGIO ��������� ������������ �������
 *******************************************************/
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	Quality 	quality;
	uint32_t	Health;

				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 					{Health = STVALINT32_Warning;}

				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){

					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Health_stVal, Health);
#if  defined (T20N4D40R35)
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Health_stVal, Health);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO21_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO22_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO23_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO24_Health_stVal, Health);
#endif

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Health_t, currentTime);
#if  defined (T20N4D40R35)
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Health_t, currentTime);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO21_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO22_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO23_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO24_Health_t, currentTime);
#endif
				}

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
				}

#if  defined (T20N4D40R35)
				if (ucMUstavkiInBuf[MB_offset_Ext_17 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_18 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_19 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_20 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Beh_t, currentTime);
				}

#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
				if (ucMUstavkiInBuf[MB_offset_Ext_17 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO17_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_18 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO18_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_19 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO19_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_20 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO20_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_21 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO21_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO21_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO21_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO21_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_22 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO22_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO22_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO22_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO22_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_23 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO23_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO23_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO23_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO23_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_24 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO24_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO24_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO24_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO24_Beh_t, currentTime);
				}

#endif

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,Qual);
#if  defined (T20N4D40R35)
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Beh_q,Qual);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO21_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO21_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO22_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO22_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO23_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO23_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO24_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO24_Beh_q,Qual);
#endif
				}

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// ���� >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);

#if  defined (T20N4D40R35)
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_17] & MB_b_SRAB_ext_17))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_18] & MB_b_SRAB_ext_18))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_19] & MB_b_SRAB_ext_19))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_20] & MB_b_SRAB_ext_20))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Alm_t, currentTime);
#endif

#if  defined (T24N0D24R51) || \
	 defined (T24N0D32R43) || \
	 defined (T24N0D40R35)
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_17] & MB_b_SRAB_ext_17))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO17_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_18] & MB_b_SRAB_ext_18))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO18_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_19] & MB_b_SRAB_ext_19))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO19_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_20] & MB_b_SRAB_ext_20))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO20_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO21_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_21] & MB_b_SRAB_ext_21))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO21_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO22_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_22] & MB_b_SRAB_ext_22))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO22_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO23_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_23] & MB_b_SRAB_ext_23))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO23_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO24_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_24] & MB_b_SRAB_ext_24))		// ����
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO24_Alm_t, currentTime);
#endif

				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,quality);
#if  defined (T20N4D40R35)
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Alm_q,quality);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO17_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO18_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO19_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO20_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO21_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO22_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO23_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO24_Alm_q,quality);
#endif

				}

}

/*******************************************************
 * Set_XCBRGGIO ��������� ������������ �������
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// ����� ������
/*
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
*/
}

/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 *
// ---------------------------------
// ������ 2
// �������			������		�������			����
// 901				�� 2.11 	8				8
// 901T24N0D40R35	2.12 		24				8
// 901T24N0D32R43	2.12 		16				16
// 901T24N0D24R51	2.12 		0				32
// 901T20N4D32R43	2.12 		24				8

// ---------------------------------
// ������ 3
// �������			������		�������			����
// 901				�� 2.11 	16				0
// 901T24N0D40R35	2.12 		16				16
// 901T24N0D32R43	2.12 		16				16
// 901T24N0D24R51	2.12 		16				16
// 901T20N4D32R43	2.12 		16				16
 *
 *******************************************************/
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health	= STVALINT32_OK;
	Quality quality;

// ������ 2
// ������ 3
	if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM2) {Health = STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorM3) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
// ������ 2
// �������			������		�������			����
// 901				�� 2.11 	8(1-8)			8(11-18)
// 901T24N0D40R35	2.12 		24(1-24)		8(11-18)
// 901T24N0D32R43	2.12 		16(1-16)		16(11-16)
// 901T24N0D24R51	2.12 		0				32(11-32)
// 901T20N4D32R35	2.12 		24(1-24)		8(11-18)

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
#if  defined (OLD)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
	}
#endif
// 901T24N0D24R51	2.12 		0
#if  defined (T24N0D24R51)

#endif
// 901T24N0D32R43	2.12 		16(1-16)
#if  defined (T24N0D32R43)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
	}
#endif
// 901T24N0D40R35	2.12 		24(1-24)
// 901T20N4D32R35	2.12 		24(1-24)
#if  defined (T24N0D40R35) || defined (T20N4D40R35)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);
	}
#endif

// ������ 3
// �������			������		�������			����
// 901				�� 2.11 	16(9-24)		0
// 901T24N0D40R35	2.12 		16(25-40)		16(19-35)
// 901T24N0D32R43	2.12 		16(17-32)		16(17-43)
// 901T24N0D24R51	2.12 		24(1-24)		8(33-51)
// 901T20N4D32R35	2.12 		16(25-32)		16(19-35)
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
#if  defined (OLD)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);

		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);
	}
#endif
// 901T24N0D24R51	2.12 		24(1-24)
#if  defined (T24N0D24R51)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);
	}
#endif
// 901T24N0D32R43	2.12 		16(17-32)
#if  defined (T24N0D32R43)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind32_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_t, currentTime);
	}
#endif
// 901T24N0D40R35	2.12 		16(25-40)
// 901T20N4D40R35	2.12 		16(25-40)
#if  defined (T24N0D40R35) || defined (T20N4D40R35)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind25_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind32_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind33_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind34_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind35_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind36_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind37_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind38_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind39_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind40_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind33_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind34_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind35_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind36_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind37_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind38_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind39_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind40_t, currentTime);
	}
#endif

// ����� ��������� ���������

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17] & MB_bOffset_Discreet_17))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetDiscreet_18] & MB_bOffset_Discreet_18))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetDiscreet_19] & MB_bOffset_Discreet_19))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetDiscreet_20] & MB_bOffset_Discreet_20))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetDiscreet_21] & MB_bOffset_Discreet_21))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetDiscreet_22] & MB_bOffset_Discreet_22))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetDiscreet_23] & MB_bOffset_Discreet_23))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetDiscreet_24] & MB_bOffset_Discreet_24))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);

#if  defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetDiscreet_25] & MB_bOffset_Discreet_25))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetDiscreet_26] & MB_bOffset_Discreet_26))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetDiscreet_27] & MB_bOffset_Discreet_27))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetDiscreet_28] & MB_bOffset_Discreet_28))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetDiscreet_29] & MB_bOffset_Discreet_29))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetDiscreet_30] & MB_bOffset_Discreet_30))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetDiscreet_31] & MB_bOffset_Discreet_31))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetDiscreet_32] & MB_bOffset_Discreet_32))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_t, currentTime);
#endif

#if  defined (T24N0D40R35) || defined (T20N4D40R35)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind33_stVal,  ucMDiscInBuf[MB_offsetDiscreet_33] & MB_bOffset_Discreet_33))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind33_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind34_stVal,  ucMDiscInBuf[MB_offsetDiscreet_34] & MB_bOffset_Discreet_34))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind34_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind35_stVal,  ucMDiscInBuf[MB_offsetDiscreet_35] & MB_bOffset_Discreet_35))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind35_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind36_stVal,  ucMDiscInBuf[MB_offsetDiscreet_36] & MB_bOffset_Discreet_36))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind36_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind37_stVal,  ucMDiscInBuf[MB_offsetDiscreet_37] & MB_bOffset_Discreet_37))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind37_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind38_stVal,  ucMDiscInBuf[MB_offsetDiscreet_38] & MB_bOffset_Discreet_38))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind38_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind39_stVal,  ucMDiscInBuf[MB_offsetDiscreet_39] & MB_bOffset_Discreet_39))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind39_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind40_stVal,  ucMDiscInBuf[MB_offsetDiscreet_40] & MB_bOffset_Discreet_40))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind40_t, currentTime);
#endif

return ret;
}

/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	int		ret = false;
	uint32_t	Mod 	= STVALINT32_ON;
	uint32_t	Health	= STVALINT32_OK;
	Quality quality;


	if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)>0) 		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)>0) 		{Health = STVALINT32_Warning;}
#if  !defined (OLD)
	if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)>0) 		{Health = STVALINT32_Warning;}
#endif
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)>0)	{Health = STVALINT32_Warning;}


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

// ------------------------------------
// ������ 1 ����������
// �������			������		�������			����
// 901						 	0				10(1-10)
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffset_errorM1)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
		}

// ------------------------------------
// ������ 2
// �������			������		�������			����
// 901				�� 2.11 	8(1-8)			8(11-18)
// 901T24N0D40R35	2.12 		24(1-24)		8(11-18)
// 901T24N0D32R43	2.12 		16(1-16)		16(11-16)
// 901T24N0D24R51	2.12 		0				32(11-32)
// 901T20N4D32R35	2.12 		24(1-24)		8(11-18)

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

// 901				�� 2.11 	8(1-8)			8(11-18)
// 901T24N0D40R35	2.12 		24(1-24)		8(11-18)
// 901T20N4D32R35	2.12 		24(1-24)		8(11-18)

#if  defined (OLD) || defined (T24N0D40R35) || defined (T20N4D40R35) || defined (T16N0D24R19)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);
	}
#endif
// 901T24N0D32R43	2.12 		16(1-16)		16(11-16)
#if  defined (T24N0D32R43)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
	}
#endif
// 901T24N0D24R51	2.12 		0				32(11-32)
#if  defined (T24N0D24R51)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_t, currentTime);
	}
#endif

// ------------------------------------
// ������ 3
// �������			������		�������			����
// 901				�� 2.11 	16(9-24)		0
// 901T24N0D40R35	2.12 		16(25-40)		16(19-35)
// 901T24N0D32R43	2.12 		16(17-32)		16(17-43)
// 901T24N0D24R51	2.12 		24(1-24)		8(33-51)
// 901T20N4D40R35	2.12 		16(25-40)		16(19-35)

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

// 901T24N0D32R43	2.12 		16(17-32)		16(17-43)
#if  defined (T24N0D32R43)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO36_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO37_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO38_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO39_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO40_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO41_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO42_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO43_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO36_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO37_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO38_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO39_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO40_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO41_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO42_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO43_t, currentTime);
	}
#endif
// 901T24N0D40R35	2.12 		16(25-40)		16(19-35)
// 901T20N4D40R35	2.12 		16(25-40)		16(19-35)
#if  defined (T24N0D40R35) || defined (T20N4D40R35)
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_t, currentTime);
	}
#endif
// ------------------------------------

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);

#if  defined (T24N0D40R35) || defined (T20N4D40R35) || defined (T24N0D32R43) || defined (T24N0D24R51)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,  ucMDiscInBuf[MB_offsetRelay_19] & MB_bOffset_Relay_19))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,  ucMDiscInBuf[MB_offsetRelay_20] & MB_bOffset_Relay_20))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,  ucMDiscInBuf[MB_offsetRelay_21] & MB_bOffset_Relay_21))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,  ucMDiscInBuf[MB_offsetRelay_22] & MB_bOffset_Relay_22))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,  ucMDiscInBuf[MB_offsetRelay_23] & MB_bOffset_Relay_23))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,  ucMDiscInBuf[MB_offsetRelay_24] & MB_bOffset_Relay_24))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,  ucMDiscInBuf[MB_offsetRelay_25] & MB_bOffset_Relay_25))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,  ucMDiscInBuf[MB_offsetRelay_26] & MB_bOffset_Relay_26))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,  ucMDiscInBuf[MB_offsetRelay_27] & MB_bOffset_Relay_27))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,  ucMDiscInBuf[MB_offsetRelay_28] & MB_bOffset_Relay_28))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,  ucMDiscInBuf[MB_offsetRelay_29] & MB_bOffset_Relay_29))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,  ucMDiscInBuf[MB_offsetRelay_30] & MB_bOffset_Relay_30))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,  ucMDiscInBuf[MB_offsetRelay_31] & MB_bOffset_Relay_31))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,  ucMDiscInBuf[MB_offsetRelay_32] & MB_bOffset_Relay_32))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,  ucMDiscInBuf[MB_offsetRelay_33] & MB_bOffset_Relay_33))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,  ucMDiscInBuf[MB_offsetRelay_34] & MB_bOffset_Relay_34))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_stVal,  ucMDiscInBuf[MB_offsetRelay_35] & MB_bOffset_Relay_35))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO35_t, currentTime);
#endif
#if  defined (T24N0D32R43) || defined (T24N0D24R51)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO36_stVal,  ucMDiscInBuf[MB_offsetRelay_36] & MB_bOffset_Relay_36))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO36_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO37_stVal,  ucMDiscInBuf[MB_offsetRelay_37] & MB_bOffset_Relay_37))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO37_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO38_stVal,  ucMDiscInBuf[MB_offsetRelay_38] & MB_bOffset_Relay_38))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO38_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO39_stVal,  ucMDiscInBuf[MB_offsetRelay_39] & MB_bOffset_Relay_39))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO39_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO40_stVal,  ucMDiscInBuf[MB_offsetRelay_40] & MB_bOffset_Relay_40))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO40_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO41_stVal,  ucMDiscInBuf[MB_offsetRelay_41] & MB_bOffset_Relay_41))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO41_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO42_stVal,  ucMDiscInBuf[MB_offsetRelay_42] & MB_bOffset_Relay_42))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO42_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO43_stVal,  ucMDiscInBuf[MB_offsetRelay_43] & MB_bOffset_Relay_43))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO43_t, currentTime);

#endif
#if  defined (T24N0D24R51)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO44_stVal,  ucMDiscInBuf[MB_offsetRelay_44] & MB_bOffset_Relay_44))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO44_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO45_stVal,  ucMDiscInBuf[MB_offsetRelay_45] & MB_bOffset_Relay_45))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO45_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO46_stVal,  ucMDiscInBuf[MB_offsetRelay_46] & MB_bOffset_Relay_46))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO46_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO47_stVal,  ucMDiscInBuf[MB_offsetRelay_47] & MB_bOffset_Relay_47))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO47_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO48_stVal,  ucMDiscInBuf[MB_offsetRelay_48] & MB_bOffset_Relay_48))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO48_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO49_stVal,  ucMDiscInBuf[MB_offsetRelay_49] & MB_bOffset_Relay_49))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO49_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO50_stVal,  ucMDiscInBuf[MB_offsetRelay_50] & MB_bOffset_Relay_50))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO50_t, currentTime);

#endif

return ret;
}

/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;
	uint32_t	Health;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 		{Health = STVALINT32_Warning;}

	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}


	// ������ ������ �����������
	if (
			(ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) ||
			(ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) ||
			(ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) ||
			(ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) ||
			(ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) ||
			(ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) ||
			(ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) ||
			(ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) ||
			(ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) ||
			(ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) ||
			(ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) ||
			(ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12)
			)
	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);

		//IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,quality);
		//IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);

	}

	//--------------------------------
	// ����� ������

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
}

/*******************************************************
 * Set_SSLGGIO ��������� ������������ �������
 *******************************************************/
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	Quality		quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError)   {Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (ucMDiscInBuf[MB_offset_LogicError1] & MB_bOffsetALLLogicError1) {Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

#if defined (MR901) && (_REVISION_DEVICE<=212)		//2.06		������ � �������. �� ����� ���������� ���� ����
	Mod	= STVALINT32_ON;
#endif

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetSSL_25] & MB_bOffset_SSL_25) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetSSL_26] & MB_bOffset_SSL_26) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetSSL_27] & MB_bOffset_SSL_27) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetSSL_28] & MB_bOffset_SSL_28) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetSSL_29] & MB_bOffset_SSL_29) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetSSL_30] & MB_bOffset_SSL_30) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetSSL_31] & MB_bOffset_SSL_31) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetSSL_32] & MB_bOffset_SSL_32) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);

#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind33_stVal,  ucMDiscInBuf[MB_offsetSSL_33] & MB_bOffset_SSL_33) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind33_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind34_stVal,  ucMDiscInBuf[MB_offsetSSL_34] & MB_bOffset_SSL_34) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind34_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind35_stVal,  ucMDiscInBuf[MB_offsetSSL_35] & MB_bOffset_SSL_35) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind35_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind36_stVal,  ucMDiscInBuf[MB_offsetSSL_36] & MB_bOffset_SSL_36) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind36_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind37_stVal,  ucMDiscInBuf[MB_offsetSSL_37] & MB_bOffset_SSL_37) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind37_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind38_stVal,  ucMDiscInBuf[MB_offsetSSL_38] & MB_bOffset_SSL_38) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind38_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind39_stVal,  ucMDiscInBuf[MB_offsetSSL_39] & MB_bOffset_SSL_39) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind39_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind40_stVal,  ucMDiscInBuf[MB_offsetSSL_40] & MB_bOffset_SSL_40) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind40_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind41_stVal,  ucMDiscInBuf[MB_offsetSSL_41] & MB_bOffset_SSL_41) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind41_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind42_stVal,  ucMDiscInBuf[MB_offsetSSL_42] & MB_bOffset_SSL_42) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind42_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind43_stVal,  ucMDiscInBuf[MB_offsetSSL_43] & MB_bOffset_SSL_43) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind43_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind44_stVal,  ucMDiscInBuf[MB_offsetSSL_44] & MB_bOffset_SSL_44) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind44_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind45_stVal,  ucMDiscInBuf[MB_offsetSSL_45] & MB_bOffset_SSL_45) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind45_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind46_stVal,  ucMDiscInBuf[MB_offsetSSL_46] & MB_bOffset_SSL_46) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind46_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind47_stVal,  ucMDiscInBuf[MB_offsetSSL_47] & MB_bOffset_SSL_47) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind47_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind48_stVal,  ucMDiscInBuf[MB_offsetSSL_48] & MB_bOffset_SSL_48) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind48_t, currentTime);
#endif

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_q,quality);
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind33_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind34_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind35_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind36_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind37_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind38_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind39_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind40_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind41_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind42_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind43_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind44_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind45_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind46_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind47_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind48_q,quality);
#endif
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);

#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind33_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind34_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind35_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind36_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind37_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind38_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind39_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind40_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind41_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind42_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind43_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind44_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind45_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind46_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind47_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind48_t, currentTime);
#endif
	}
return ret;
}

/*******************************************************
 * Set_VLSGGIO ��������� ������������ �������
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality quality;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 		{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetVLS_9] & MB_bOffset_VLS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetVLS_10] & MB_bOffset_VLS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetVLS_11] & MB_bOffset_VLS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetVLS_12] & MB_bOffset_VLS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetVLS_13] & MB_bOffset_VLS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetVLS_14] & MB_bOffset_VLS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetVLS_15] & MB_bOffset_VLS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetVLS_16] & MB_bOffset_VLS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);

	}
}

/*******************************************************
 * Set_LSGGIO ��������� ������������ �������
 *******************************************************/
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health;
	Quality 	quality;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 		{Health = STVALINT32_Warning;}

	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLS_9] & MB_bOffset_LS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLS_10] & MB_bOffset_LS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLS_11] & MB_bOffset_LS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLS_12] & MB_bOffset_LS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLS_13] & MB_bOffset_LS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLS_14] & MB_bOffset_LS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLS_15] & MB_bOffset_LS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLS_16] & MB_bOffset_LS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);
	}
}
#endif

/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
#include "static_model_MR851.h"

extern 	uint16_t   ucMUstavkiInBuf[MB_Size_Ustavki];
extern  uint16_t   ucMDiscInBuf[MB_Size_Discreet];

/*******************************************************
 * ��������
 *******************************************************/
int		Set_VZGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_SSLGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_VLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_LSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_XCBRGGIO ��������� ������������ �������
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// ����� ������
/*
		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}

		if (ucMDiscInBuf[MB_offset_BLK] & MB_bOffsetDriveDNTMove){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}


		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffseNewMsJurnalError)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		}

*/
}

/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 *******************************************************/
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//  Mod Beh

	uint32_t	Mod = STVALINT32_ON;
	uint32_t 	Health = STVALINT32_OK;
	Quality quality;

	//Health
		if ((ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3)) 		{Health = STVALINT32_Warning;}

		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3a)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);

		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);

		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
	}


		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
// -----
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
}

/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality quality;

	if 	((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetErrModule2)>0)  {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetErrModule2){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);

	}


		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
}

/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);


	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);
	}

}
#endif


/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined (MR5_500) || defined (MR5_600) ||  defined (MR741)

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined	(MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];
extern uint16_t   ucMAutomatBuf[MB_Size_Automat];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];


/*******************************************************
 * ��������
 *******************************************************/

int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#if defined	(MR5_600)
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

/*******************************************************
 * Set_VZGGIO ��������� ������������ �������
 *******************************************************/
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality 	quality;

	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO2_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO3_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO4_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO5_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO6_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO7_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO8_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
	}
	//  Mod Beh

		if ((ucConfigBufExZ[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
		}

//  Quality (Mod Beh)
		quality = QUALITY_VALIDITY_GOOD;
		if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality);
		}

//				uint32_t	Alm;

		quality = QUALITY_VALIDITY_GOOD;
		if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
		}


		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// ���� >1
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// ����
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);

return ret;
}

/*******************************************************
 * Set_AVRGGIO ��������� ������������ �������
 *******************************************************/
#if !defined	(MR5_600)
int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod;
	uint32_t	Health;

//  Mod Beh
				if ((ucMAutomatBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
				}
//Health
				Health = STVALINT32_OK;
				if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
				}
//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

				uint8_t	awr=0;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);

				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if(IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,Qual)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
				}
return ret;
}
#endif
/*******************************************************
 * Set_XCBRGGIO ��������� ������������ �������
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
/*
	//--------------------------------
	// ����� ������

		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewJurnalMs] & MB_bOffsetNewJurnalMs){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffsetNewMsJurnalError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}


		// ��� ����������
		if ((ucMDiscInBuf[MB_offset_AllLEDs] & MB_bOffsetLedsStats)>0)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
		}
*/
return ret;
}
/*******************************************************
 * Set_INGGIO ��������� ������������ �������
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={
		MB_offsetDiscreet_1,		MB_bOffset_Discreet_1,
		MB_offsetDiscreet_2,		MB_bOffset_Discreet_2,
		MB_offsetDiscreet_3,		MB_bOffset_Discreet_3,
		MB_offsetDiscreet_4,		MB_bOffset_Discreet_4,
		MB_offsetDiscreet_5,		MB_bOffset_Discreet_5,
		MB_offsetDiscreet_6,		MB_bOffset_Discreet_6,
		MB_offsetDiscreet_7,		MB_bOffset_Discreet_7,
		MB_offsetDiscreet_8,		MB_bOffset_Discreet_8,
#if !defined	(MR5_600)
		MB_offsetDiscreet_9,		MB_bOffset_Discreet_9,
		MB_offsetDiscreet_10,		MB_bOffset_Discreet_10,
		MB_offsetDiscreet_11,		MB_bOffset_Discreet_11,
		MB_offsetDiscreet_12,		MB_bOffset_Discreet_12,
		MB_offsetDiscreet_13,		MB_bOffset_Discreet_13,
		MB_offsetDiscreet_14,		MB_bOffset_Discreet_14,
		MB_offsetDiscreet_15,		MB_bOffset_Discreet_15,
		MB_offsetDiscreet_16,		MB_bOffset_Discreet_16,
#if defined	(MR741)
		MB_offsetDiscreet_17,		MB_bOffset_Discreet_17,
		MB_offsetDiscreet_18,		MB_bOffset_Discreet_18
#endif
#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,
		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,
		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,
		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,
		&iedModel_GGIO_INGGIO1_Ind8_q,
#if !defined	(MR5_600)
		&iedModel_GGIO_INGGIO1_Ind9_q,
		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,
		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,
		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,
		&iedModel_GGIO_INGGIO1_Ind16_q,
#if defined	(MR741)
		&iedModel_GGIO_INGGIO1_Ind17_q,
		&iedModel_GGIO_INGGIO1_Ind18_q,
#endif
#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,
		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,
		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,
		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,
		&iedModel_GGIO_INGGIO1_Ind8_t,
#if !defined	(MR5_600)
		&iedModel_GGIO_INGGIO1_Ind9_t,
		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,
		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,
		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,
		&iedModel_GGIO_INGGIO1_Ind16_t,
#if defined	(MR741)
		&iedModel_GGIO_INGGIO1_Ind17_t,
		&iedModel_GGIO_INGGIO1_Ind18_t,
#endif
#endif
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,
		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,
		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,
		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,
		&iedModel_GGIO_INGGIO1_Ind8_stVal,
#if !defined	(MR5_600)
		&iedModel_GGIO_INGGIO1_Ind9_stVal,
		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,
		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,
		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,
		&iedModel_GGIO_INGGIO1_Ind16_stVal,
#if defined	(MR741)
		&iedModel_GGIO_INGGIO1_Ind17_stVal,
		&iedModel_GGIO_INGGIO1_Ind18_stVal,
#endif
#endif
};
// ------------------------------------------

int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health;
	int			ret = false;
// �������� � ����� ������ �� ���������� ---------------------------------------
	Quality		quality   = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// ����� ��������
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// ������ �� ��������
	if (QTnum & TIME_mask) T = true; else T = false;		// ������ �� �����
//	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------


	Health = STVALINT32_OK;
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffset_errorM3)	 			{Health = STVALINT32_Warning;}
	IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal,&iedModel_GGIO_INGGIO1_Health_t,currentTime,Health);
	//  Mod Beh
	if(IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal,&iedModel_GGIO_INGGIO1_Mod_t,currentTime,Mod)){
		IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal,&iedModel_GGIO_INGGIO1_Beh_t,currentTime,Mod);
	}
/*

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}
*/
	quality   = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3a)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,&iedModel_GGIO_INGGIO1_Ind1_t,currentTime,quality)){
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,&iedModel_GGIO_INGGIO1_Ind2_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,&iedModel_GGIO_INGGIO1_Ind3_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,&iedModel_GGIO_INGGIO1_Ind4_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,&iedModel_GGIO_INGGIO1_Ind5_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,&iedModel_GGIO_INGGIO1_Ind6_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,&iedModel_GGIO_INGGIO1_Ind7_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,&iedModel_GGIO_INGGIO1_Ind8_t,currentTime,quality);
	}

		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,&iedModel_GGIO_INGGIO1_Ind1_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,&iedModel_GGIO_INGGIO1_Ind2_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,&iedModel_GGIO_INGGIO1_Ind3_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,&iedModel_GGIO_INGGIO1_Ind4_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,&iedModel_GGIO_INGGIO1_Ind5_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,&iedModel_GGIO_INGGIO1_Ind6_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,&iedModel_GGIO_INGGIO1_Ind7_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,&iedModel_GGIO_INGGIO1_Ind8_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8) > 0);

#if !defined	(MR5_600)

	quality   = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3b)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,&iedModel_GGIO_INGGIO1_Ind9_t,currentTime,quality)){
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,&iedModel_GGIO_INGGIO1_Ind10_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,&iedModel_GGIO_INGGIO1_Ind11_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,&iedModel_GGIO_INGGIO1_Ind12_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,&iedModel_GGIO_INGGIO1_Ind13_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,&iedModel_GGIO_INGGIO1_Ind14_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,&iedModel_GGIO_INGGIO1_Ind15_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,&iedModel_GGIO_INGGIO1_Ind16_t,currentTime,quality);

	}

#if defined	(MR741)
	quality   = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2a)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,&iedModel_GGIO_INGGIO1_Ind17_t,currentTime,quality)){
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,&iedModel_GGIO_INGGIO1_Ind18_t,currentTime,quality);
	}
#endif

	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,&iedModel_GGIO_INGGIO1_Ind9_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,&iedModel_GGIO_INGGIO1_Ind10_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,&iedModel_GGIO_INGGIO1_Ind11_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,&iedModel_GGIO_INGGIO1_Ind12_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,&iedModel_GGIO_INGGIO1_Ind13_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,&iedModel_GGIO_INGGIO1_Ind14_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,&iedModel_GGIO_INGGIO1_Ind15_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,&iedModel_GGIO_INGGIO1_Ind16_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16) > 0);

#if defined	(MR741)
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,&iedModel_GGIO_INGGIO1_Ind17_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_17] & MB_bOffset_Discreet_17) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,&iedModel_GGIO_INGGIO1_Ind18_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_18] & MB_bOffset_Discreet_18) > 0);
#endif

#endif
	return	ret;
}

/*******************************************************
 * Set_OUTGGIO ��������� ������������ �������
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={	//42
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8
};

DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_q
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_t
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal
};
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2)		{Health = STVALINT32_Warning;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}


	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2a)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
#if defined	(MR741)
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
#endif
	}


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);

#if defined	(MR741)
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);

#endif

#if defined	(MR5_600)
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffset_errorM2b)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_16))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
#endif
	return ret;
}

/*******************************************************
 * Set_LEDGGIO ��������� ������������ �������
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}

	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,&iedModel_GGIO_LEDGGIO1_Ind1_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,&iedModel_GGIO_LEDGGIO1_Ind2_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,&iedModel_GGIO_LEDGGIO1_Ind3_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,&iedModel_GGIO_LEDGGIO1_Ind4_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,&iedModel_GGIO_LEDGGIO1_Ind5_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,&iedModel_GGIO_LEDGGIO1_Ind6_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,&iedModel_GGIO_LEDGGIO1_Ind7_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,&iedModel_GGIO_LEDGGIO1_Ind8_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,&iedModel_GGIO_LEDGGIO1_Ind9_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,&iedModel_GGIO_LEDGGIO1_Ind10_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,&iedModel_GGIO_LEDGGIO1_Ind11_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,&iedModel_GGIO_LEDGGIO1_Ind12_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0);

	quality = QUALITY_VALIDITY_GOOD;

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	}

	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);

	}
	return ret;
}
/*******************************************************
 * Set_SSLGGIO ��������� ������������ �������
 *******************************************************/
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	Quality		quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError) 	{Health  = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);

	quality = QUALITY_VALIDITY_GOOD;
	if 	((ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);

	}
	return ret;
}

/*******************************************************
 * Set_VLSGGIO ��������� ������������ �������
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);

	quality = QUALITY_VALIDITY_GOOD;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,quality);
	}
	return ret;
}
/*******************************************************
 * Set_LSGGIO ��������� ������������ �������
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,		MB_bOffset_LS_1,
		MB_offsetLS_2,		MB_bOffset_LS_2,
		MB_offsetLS_3,		MB_bOffset_LS_3,
		MB_offsetLS_4,		MB_bOffset_LS_4,
		MB_offsetLS_5,		MB_bOffset_LS_5,
		MB_offsetLS_6,		MB_bOffset_LS_6,
		MB_offsetLS_7,		MB_bOffset_LS_7,
		MB_offsetLS_8,		MB_bOffset_LS_8
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,		&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,		&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,		&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,		&iedModel_GGIO_LSGGIO1_Ind8_q
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,		&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,		&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,		&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,		&iedModel_GGIO_LSGGIO1_Ind8_t
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,		&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,		&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,		&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,		&iedModel_GGIO_LSGGIO1_Ind8_stVal
};

int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3)		{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);

	quality = QUALITY_VALIDITY_GOOD;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,quality);
	}
	return ret;
}

#endif

