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

#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];

extern uint16_t   ucMConfigBufSW[MB_Size_ConfSW];

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


}
#endif



