/*
 * datatoLLN0LPHD.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoMMXU.h"

#if defined (MR801)
#include "static_model_MR801.h"
#endif
#if defined (MR851)
#include "static_model_MR851.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif
#if defined (MR771)
#include "static_model_MR771.h"
#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
#include "static_model_MR76x.h"
#endif

#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif

/*******************************************************
 * MR5_500 MR5_600 MR5_700
 *******************************************************/
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) ||  defined (MR741)

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_LLN0 наполняем оперативными данными
 *******************************************************/
int		Set_LLN0	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	bool		T;
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------
	uint32_t	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 	{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetALLFaults)>0) 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LLN0_Health_stVal, Health)){
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LLN0_Health_stVal, Health);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, Health);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_LLN0_Health_stVal,  Health);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LLN0_Health_stVal, Health);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LLN0_Health_t,  currentTime);	ret = true;
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LLN0_Health_t, currentTime);	ret = true;
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);	ret = true;
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_LLN0_Health_t,  currentTime);	ret = true;
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LLN0_Health_t, currentTime);	ret = true;
	}


	//PhyHealth
	uint32_t	LPHD_PhyHealth = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetALLFaults)>0) {LPHD_PhyHealth = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LPHD1_PhyHealth_stVal, LPHD_PhyHealth)){

		IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LPHD1_PhyHealth_stVal, LPHD_PhyHealth);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LPHD1_PhyHealth_stVal, LPHD_PhyHealth);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_LPHD1_PhyHealth_stVal,  LPHD_PhyHealth);
		IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LPHD1_PhyHealth_stVal, LPHD_PhyHealth);

		if (T) {
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LPHD1_PhyHealth_t,  currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LPHD1_PhyHealth_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LPHD1_PhyHealth_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_LPHD1_PhyHealth_t,  currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LPHD1_PhyHealth_t, currentTime);
		}
		ret = true;
	}

return	ret;
}

#endif
/*******************************************************
 * MR761 MR762 MR763 MR771
 *******************************************************/
#if defined (MR761) || defined (MR762) || defined (MR763) || defined (MR771) ||\
	defined (MR801) || \
	defined (MR901) || defined (MR902)

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_LLN0 наполняем оперативными данными
 *******************************************************/
int		Set_LLN0	(uint16_t QTnum, uint64_t currentTime ){

int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	bool		T;
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
// -----------------------------------------------------------------------------

		uint32_t	Health = STVALINT32_OK;
//		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 	{Health = STVALINT32_Warning;}
//		if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4)>0) 		{Health = STVALINT32_Warning;}
//		if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)>0) 		{Health = STVALINT32_Warning;}
		if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetALLFaults) 		{Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LLN0_Health_stVal, Health)){
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LLN0_Health_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_LLN0_Health_stVal,  Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LLN0_Health_stVal, Health);
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LLN0_Health_t,  currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LLN0_Health_t, currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_LLN0_Health_t,  currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LLN0_Health_t, currentTime);	ret = true;
		}

//PhyHealth
		Health = STVALINT32_OK;
		if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetALLFaults) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LPHD1_PhyHealth_stVal, Health)){

			IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LPHD1_PhyHealth_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LPHD1_PhyHealth_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_LPHD1_PhyHealth_stVal,  Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LPHD1_PhyHealth_stVal, Health);

			if (T) {
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LPHD1_PhyHealth_t,  currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LPHD1_PhyHealth_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LPHD1_PhyHealth_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_LPHD1_PhyHealth_t,  currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LPHD1_PhyHealth_t, currentTime);
			}
			ret = true;
		}

	return	ret;
}
#endif

#if defined (MR851)
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_LLN0 наполняем оперативными данными
 *******************************************************/
int		Set_LLN0	(uint16_t QTnum, uint64_t currentTime ){

	int	ret = false;
	uint32_t	Health;
	// Качество и время меняем по надобности ---------------------------------------
		bool		T;
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	// -----------------------------------------------------------------------------

		Health = STVALINT32_OK;
// PROT
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)>0) 	{Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LLN0_Health_stVal, Health)){
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LLN0_Health_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_LLN0_Health_stVal,  Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LLN0_Health_stVal, Health);
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LLN0_Health_t,  currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LLN0_Health_t, currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_LLN0_Health_t,  currentTime);	ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LLN0_Health_t, currentTime);	ret = true;
		}

//PhyHealth
		Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offsetALLFaults] & MB_bOffsetALLFaults)>0) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_LD0_LPHD1_PhyHealth_stVal, Health)){
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_RPN_LPHD1_PhyHealth_stVal,  Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_LPHD1_PhyHealth_stVal, Health);
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LPHD1_PhyHealth_stVal, Health);

			if (T) {
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_LD0_LPHD1_PhyHealth_t,  currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_RPN_LPHD1_PhyHealth_t,  currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_LPHD1_PhyHealth_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LPHD1_PhyHealth_t, currentTime);
			}
			ret = true;
		}
		return	ret;
}
#endif


