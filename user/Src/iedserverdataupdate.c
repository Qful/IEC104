/*
 * iedserverdataupdate.c
 *
 *  Created on: 16.10.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPTOC.h"					// ����������� ������ � PTOC
#include "datatoPTOV.h"					// ����������� ������ � PTOV PTUV
#include "datatoPTOF.h"					// ����������� ������ � PTOF PTUF
#include "datatoGGIO.h"					// ����������� ������ �
#include "datatoPDIF.h"					// ����������� ������ �
#include "datatoPDIS.h"
#include "datatoPTTR.h"
#include "datatoRREC.h"					// ����������� ������ �
#include "datatoCSWI.h"					// ����������� ������ �
#include "datatoPTRC.h"					// ����������� ������ �
#include "datatoMMXU.h"
#include "datatoMSQI.h"
#include "datatoRFLO.h"
#include "datatoPDPR.h"
#include "datatoATTC.h"
#include "datatoLLN0LPHD.h"
#include "datatoSG.h"					// ��������� ������ �������


uint64_t 				currentTime;
extern	osThreadId 		IEC850TaskHandle;
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{

	/*******************************************************
	* ��������� ������������ ������� ���������
	*******************************************************/

	if(IEC850TaskHandle && (iedServer != NULL)){

	IedServer_lockDataModel(iedServer);																	// ����������� ���������� mmsServer'��

	currentTime = Hal_getTimeInMs();


	//			vTaskDelay(15);
	// PROT_UPTOV ------
						Set_UPTOV(4,currentTime);
	// PROT_UPTUV ------
						Set_UPTUV(4,currentTime);
	// PROT_U2PTOV ------
						Set_U2PTOV(2,currentTime);
	// PROT_U0PTOV ------
						Set_U0PTOV(4,currentTime);
	// PROT_U1PTUV ------
						Set_U1PTUV(2,currentTime);
	// PROT_UPTOF ------
						Set_PTOF(4,currentTime);
	// PROT_UPTUF ------
						Set_PTUF(4,currentTime);
	// PROT_VZGGIO1..8 ------
						Set_VZGGIO(8,currentTime);

	// CTRL_PTRC ------
						Set_PTRC(1,currentTime);

	// CTRL_GGIO ------
						Set_XCBRGGIO(1,currentTime);
	// MES_MMXU ------
						Set_MMXU(1,currentTime);
	// MES_MSQI ------
						Set_MSQI(1,currentTime);

	// GGIO_IN24GGIO ------

						Set_INGGIO(8,currentTime);
						Set_OUTGGIO(16,currentTime);
						Set_LEDGGIO(12,currentTime);
						Set_SSLGGIO(24,currentTime);
						Set_VLSGGIO(8,currentTime);
						Set_LSGGIO(8,currentTime);

	// LD0 SG
						Set_SG(0,currentTime);

		IedServer_unlockDataModel(iedServer);																// ����� ���������� mmsServer'��
	}
}
#endif

/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_700)
#include "static_model_MR5_700.h"

#endif
