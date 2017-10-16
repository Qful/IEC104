/*
 * datatoPTRC.c
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


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = 0;

	// Op
	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,QUALITY_VALIDITY_GOOD);
	}


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


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = 0;


	// Op
	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,QUALITY_VALIDITY_GOOD);
	}


}
#endif

/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined	(MR901) || defined	(MR902)
#include "static_model_MR901_902.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = false;


	// Op
//	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = true;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op1_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op1_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op1_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op2_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op2_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op2_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op3_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op3_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op3_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op4_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op4_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op4_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op5_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op5_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op5_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op6_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op6_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op6_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op7_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op7_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op7_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op8_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op8_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op8_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op9_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op9_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op9_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op10_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op10_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op10_q,QUALITY_VALIDITY_GOOD);
	}
#if defined	(MR901)
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op11_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op11_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op11_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op12_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op12_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op12_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op13_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op13_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op13_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op14_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op14_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op14_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op15_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op15_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op15_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op16_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op16_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op16_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op17_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op17_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op17_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op18_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op18_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op18_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op19_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op19_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op19_q,QUALITY_VALIDITY_GOOD);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op20_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op20_t, currentTime);
		{}			   IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op20_q,QUALITY_VALIDITY_GOOD);
	}
#endif


}
#endif
/*******************************************************
 * MR5_700, MR5_500
 *******************************************************/
#if defined (MR5_700) || defined (MR5_500)

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = 0;

	// Op
	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,QUALITY_VALIDITY_GOOD);
	}


}
#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = 0;

	// Op
	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,QUALITY_VALIDITY_GOOD);
	}


}
#endif
