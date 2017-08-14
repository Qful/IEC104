/*
 * datatoCSWI.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"
/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];

/*******************************************************
 * Set_RREC наполняем оперативными данными
 *******************************************************/
void	Set_CSWI	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal,ctlVal;
	uint32_t	Health = STVALINT32_OK;

	// Health

				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Health_t, currentTime);

	//  Mod Beh
				if (ucMConfigBufSW[MB_offset_ConfigSW] & MB_bControlSW_SDTU) {				// если отключено управление от СДТУ
					Mod = STVALINT32_ON;
					ctlModel = CTLMODELEDENUM_DirectWithNormalSecurity;
				} else {
					Mod = STVALINT32_OFF;
					ctlModel = CTLMODELEDENUM_statusOnly;
				}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Beh_t, currentTime);


	//  Quality (Mod Beh)
				{
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Beh_q,Qual);

				}

	// Pos
				IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_ctlModel, ctlModel);
				IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_ctlModel, ctlModel);



				stVal = STVALCODEDENUM_INTERMEDIATE;
				if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
				if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
				//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

				if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, stVal))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);

	//  Quality (Pos)
				{
					int	Qual = QUALITY_VALIDITY_GOOD;
					int	Module	=	0;
					// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 17)			Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetModule2;

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 49)			Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 49)		Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 49)	Module |= MB_bOffsetModule3;


					if ((Module & MB_bOffsetModule2) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((Module & MB_bOffsetModule3) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}


					IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,Qual);

				}


}

/*******************************************************
 * Set_XCBR наполняем оперативными данными
 *******************************************************/
void	Set_XCBR	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal,ctlVal;
	uint32_t	Health = STVALINT32_OK;


	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Health_stVal, Health))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_Health_t, currentTime);

	//pos
	stVal = STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
	//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

	if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, stVal))
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);

	//  Quality (Pos)
				{
					int	Qual = QUALITY_VALIDITY_GOOD;
					int	Module	=	0;
					// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 17)			Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetModule2;

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 49)			Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 49)		Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 49)	Module |= MB_bOffsetModule3;


					if ((Module & MB_bOffsetModule2) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((Module & MB_bOffsetModule3) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,Qual);
				}

	//BlkOpn
	bool bolVal = true;
	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl1) {bolVal = false;}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_t, currentTime);

	//BlkCIs
	bolVal = true;
	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl2) {bolVal = false;}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_t, currentTime);

	//OpCnt
		if (IedServer_updateUnsignedAttributeValue(iedServer, &iedModel_CTRL_XCBR1_OpCnt_stVal, ucSWCNTBuf[MB_offset_Oper_cnt]))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_OpCnt_t, currentTime);


}
#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763)

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];
extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];
extern uint16_t   ucSWCNTBuf[MB_NumbSw_CNT];
/*******************************************************
 * Set_RREC наполняем оперативными данными
 *******************************************************/
void	Set_CSWI	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal,ctlVal;
	uint32_t	Health = STVALINT32_OK;

	// Health

				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Health_t, currentTime);

	//  Mod Beh
				if (ucMConfigBufSW[MB_rOffsetControlSW] & MB_bControlSW_SDTU) {				// если отключено управление от СДТУ
					Mod = STVALINT32_ON;
					ctlModel = CTLMODELEDENUM_DirectWithNormalSecurity;
				} else {
					Mod = STVALINT32_OFF;
					ctlModel = CTLMODELEDENUM_statusOnly;
				}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Beh_t, currentTime);


	//  Quality (Mod Beh)
				{
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Beh_q,Qual);

				}

	// Pos
				IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_ctlModel, ctlModel);
				IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_ctlModel, ctlModel);



				stVal = STVALCODEDENUM_INTERMEDIATE;
				if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
				if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
				//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

				if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, stVal))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);

	//  Quality (Pos)
				{
					int	Qual = QUALITY_VALIDITY_GOOD;
					int	Module	=	0;
					// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 17)			Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetModule2;

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 49)			Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 49)		Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 49)	Module |= MB_bOffsetModule3;


					if ((Module & MB_bOffsetModule2) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((Module & MB_bOffsetModule3) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}


					IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,Qual);

				}


}

/*******************************************************
 * Set_XCBR наполняем оперативными данными
 *******************************************************/
void	Set_XCBR	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal,ctlVal;
	uint32_t	Health = STVALINT32_OK;


	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Health_stVal, Health))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_Health_t, currentTime);

	//pos
	stVal = STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
	//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

	if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, stVal))
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);

	//  Quality (Pos)
				{
					int	Qual = QUALITY_VALIDITY_GOOD;
					int	Module	=	0;
					// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 17)			Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetModule2;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetModule2;

					if (ucMConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ON] < 49)			Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_OFF] < 49)		Module |= MB_bOffsetModule3;
					if (ucMConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucMConfigBufSW[MB_rOffsetControlSW_ERROR] < 49)	Module |= MB_bOffsetModule3;


					if ((Module & MB_bOffsetModule2) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((Module & MB_bOffsetModule3) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,Qual);
				}

	//BlkOpn
	bool bolVal = true;
	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl1) {bolVal = false;}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_t, currentTime);

	//BlkCIs
	bolVal = true;
	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl2) {bolVal = false;}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_t, currentTime);

//OpCnt
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_OpCnt_stVal, ucSWCNTBuf[MB_offset_Oper_cnt]))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_OpCnt_t, currentTime);


}
#endif
/*******************************************************
 * MR5_700
 *******************************************************/
#if defined (MR5_700)
#include "static_model_MR5_700.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucConfigBufSW[MB_NumbConfigSW];
extern uint16_t   ucSWCrash[MB_NumbSWCrash];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];

/*******************************************************
 * Set_RREC наполняем оперативными данными
 *******************************************************/
void	Set_CSWI	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal;
	uint32_t	Health = STVALINT32_OK;

// Health

			if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Health_t, currentTime);

//  Mod Beh
			if (ucConfigBufSW[MB_offset_ConfigSW] & MB_bControlSW_SDTU) {				// если отключено управление от СДТУ
				Mod = STVALINT32_ON;
				ctlModel = CTLMODELEDENUM_DirectWithNormalSecurity;
			} else {
				Mod = STVALINT32_OFF;
				ctlModel = CTLMODELEDENUM_statusOnly;
			}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_CSWI1_Beh_t, currentTime);


//  Quality (Mod Beh)
			{
			int	Qual = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Mod_q,Qual);
			IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Beh_q,Qual);
			}

// Pos
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Mod_ctlModel, ctlModel);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_ctlModel, ctlModel);


			stVal = STVALCODEDENUM_INTERMEDIATE;
			if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
			if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
			//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

			if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_stVal, stVal))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_CSWI1_Pos_t, currentTime);

//  Quality (Pos)
			{
				int	Qual = QUALITY_VALIDITY_GOOD;
				int	Module	=	0;
				// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

				if (ucConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucConfigBufSW[MB_rOffsetControlSW_ON] < 17)		Module |= MB_bOffsetErrModule3a;
				if (ucConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetErrModule3a;
				if (ucConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetErrModule3a;

				if (ucConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucConfigBufSW[MB_rOffsetControlSW_ON] < 34)		Module |= MB_bOffsetErrModule3b;
				if (ucConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucConfigBufSW[MB_rOffsetControlSW_OFF] < 34)		Module |= MB_bOffsetErrModule3b;
				if (ucConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucConfigBufSW[MB_rOffsetControlSW_ERROR] < 34)	Module |= MB_bOffsetErrModule3b;


				if ((Module & MB_bOffsetErrModule3a) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetErrModule3a)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if ((Module & MB_bOffsetErrModule3b) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetErrModule3b)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_CTRL_CSWI1_Pos_q,Qual);
			}
}

/*******************************************************
 * Set_XCBR наполняем оперативными данными
 *******************************************************/
void	Set_XCBR	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	ctlModel,stVal,ctlVal;
	uint32_t	Health = STVALINT32_OK;
	uint32_t 	CtrlD,CtrlD1;
	uint64_t 	diskreet;

	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorSWAll) {Health = STVALINT32_Alarm;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_XCBR1_Health_stVal, Health))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_Health_t, currentTime);

	//pos
	stVal = STVALCODEDENUM_INTERMEDIATE;
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_ON) {stVal |= STVALCODEDENUM_OFF;}
	if (ucMDiscInBuf[MB_offset_SW_status] & MB_b_SW_OFF) {stVal |= STVALCODEDENUM_ON;}
	//if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorBKExt1) {stVal |= STVALCODEDENUM_BADSTATE;}

	if (IedServer_updateBitStringAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_stVal, stVal))
	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Pos_t, currentTime);

	//  Quality (Pos)
				{
					int	Qual = QUALITY_VALIDITY_GOOD;
					int	Module	=	0;
					// проверим куда сконфигурили выключатель, и смотрим исправность того модуля

					if (ucConfigBufSW[MB_rOffsetControlSW_ON] > 0 && ucConfigBufSW[MB_rOffsetControlSW_ON] < 17)		Module |= MB_bOffsetErrModule3a;
					if (ucConfigBufSW[MB_rOffsetControlSW_OFF] > 0 && ucConfigBufSW[MB_rOffsetControlSW_OFF] < 17)		Module |= MB_bOffsetErrModule3a;
					if (ucConfigBufSW[MB_rOffsetControlSW_ERROR] > 0 && ucConfigBufSW[MB_rOffsetControlSW_ERROR] < 17)	Module |= MB_bOffsetErrModule3a;

					if (ucConfigBufSW[MB_rOffsetControlSW_ON] > 16 && ucConfigBufSW[MB_rOffsetControlSW_ON] < 34)		Module |= MB_bOffsetErrModule3b;
					if (ucConfigBufSW[MB_rOffsetControlSW_OFF] > 16 && ucConfigBufSW[MB_rOffsetControlSW_OFF] < 34)		Module |= MB_bOffsetErrModule3b;
					if (ucConfigBufSW[MB_rOffsetControlSW_ERROR] > 16 && ucConfigBufSW[MB_rOffsetControlSW_ERROR] < 34)	Module |= MB_bOffsetErrModule3b;


					if ((Module & MB_bOffsetErrModule3a) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetErrModule3a)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
					if ((Module & MB_bOffsetErrModule3b) && (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetErrModule3b)) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_CTRL_XCBR1_Pos_q,Qual);
				}

	//BlkOpn
//	bool bolVal = true;
//	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl1) {bolVal = false;}
	bool bolVal = false;
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkOpn_t, currentTime);

	//BlkCIs
//	bolVal = true;
//	if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorCtrl2) {bolVal = false;}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_stVal, bolVal))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_BlkCls_t, currentTime);

	//Loc

	Mod = false;

	CtrlD = ucUstavkiInBuf[MB_offset_BlockSDTU];	// номер контролируемого дискрета
	if (CtrlD) {
		diskreet = (uint64_t)ucMDiscInBuf[MB_offsetDiscreet_1];

		CtrlD1 = (CtrlD - 1)%2;
		CtrlD = (CtrlD - 1)/2;

		if (CtrlD1 > 0) {							// если не ровно поделился то инверсное состояние
			if ((diskreet & 1<<CtrlD) == 0) Mod = true;
		} else{
			if ((diskreet & 1<<CtrlD)>0) Mod = true;
		}
	}
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_XCBR1_Loc_t, currentTime);

	//OpCnt
		if (IedServer_updateUnsignedAttributeValue(iedServer, &iedModel_CTRL_XCBR1_OpCnt_stVal, ucSWCrash[MB_offset_Oper_cnt]))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_XCBR1_OpCnt_t, currentTime);


}
#endif

