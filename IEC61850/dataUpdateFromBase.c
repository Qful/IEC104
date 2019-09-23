/*
 * dataUpdateFromBase.c
 *
 *  Created on: 29.11.2017
 *      Author: sagok
 */

#include "main.h"
#include "port.h"

#include "dataUpdateFromBase.h"

#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoLLN0LPHD.h"
#include "datatoPTOC.h"					// модификация данных в PTOC
#include "datatoPTOV.h"					// модификация данных в PTOV PTUV
#include "datatoPTOF.h"					// модификация данных в PTOF PTUF
#include "datatoPDIF.h"					// модификация данных в
#include "datatoRREC.h"					// модификация данных в
#include "datatoGGIO.h"					// модификация данных в
#include "datatoSPCS.h"					// модификация данных в SPCS0

#include "datatoCSWI.h"					// модификация данных в
#include "datatoPTRC.h"					// модификация данных в
#include "datatoMMXU.h"
#include "datatoMSQI.h"


#include "datatoPDIS.h"
#include "datatoPTTR.h"
#include "datatoRFLO.h"
#include "datatoPDPR.h"
#include "datatoATTC.h"
#include "datatoRDRE.h"
#include "datatoSG.h"					// изменения группы уставок


// --------------------- Исполнители функций --------------------------
//static
IedDataUpdateHandler IedDataUpdateFuncHandlers[IDU_FUNC_HANDLERS_MAX] = {
    {IDU_FUNC_LLN0LPHD, 		Set_LLN0},
    {IDU_FUNC_IPTOC, 			Set_IPTOC},
    {IDU_FUNC_IPTUC, 			Set_IPTUC},
    {IDU_FUNC_I2PTOC, 			Set_I2PTOC},
    {IDU_FUNC_I0PTOC, 			Set_I0PTOC},
    {IDU_FUNC_I20PTOC, 			Set_I20PTOC},

    {IDU_FUNC_INPTOC, 			Set_INPTOC},
    {IDU_FUNC_IGPTOC, 			Set_IGPTOC},
    {IDU_FUNC_I2I1PTOC, 		Set_I2I1PTOC},
    {IDU_FUNC_LZSHPTOC, 		Set_LZSHPTOC},
    {IDU_FUNC_IARCPTOC, 		Set_IARCPTOC},


    {IDU_FUNC_UPTOV, 			Set_UPTOV},
    {IDU_FUNC_UPTUV, 			Set_UPTUV},
    {IDU_FUNC_U0PTOV, 			Set_U0PTOV},
    {IDU_FUNC_U1PTUV, 			Set_U1PTUV},
    {IDU_FUNC_U2PTOV, 			Set_U2PTOV},

    {IDU_FUNC_PTOF, 			Set_PTOF},
    {IDU_FUNC_PTUF, 			Set_PTUF},

    {IDU_FUNC_IDPDIF, 			Set_IDPDIF},
    {IDU_FUNC_IDDPDIF, 			Set_IDDPDIF},
    {IDU_FUNC_IDDMPDIF, 		Set_IDDMPDIF},
    {IDU_FUNC_IDMPDIF, 			Set_IDMPDIF},
    {IDU_FUNC_ID0PDIF, 			Set_ID0PDIF},
    {IDU_FUNC_PDIS, 			Set_PDIS},

    {IDU_FUNC_RREC, 			Set_RREC},
    {IDU_FUNC_FRREC, 			Set_FRREC},
    {IDU_FUNC_RBRF, 			Set_RBRF},
    {IDU_FUNC_RSYN, 			Set_RSYN},
    {IDU_FUNC_RPSB, 			Set_RPSB},
    {IDU_FUNC_RFLO, 			Set_RFLO},

    {IDU_FUNC_VZGGIO, 			Set_VZGGIO},
    {IDU_FUNC_AVRGGIO, 			Set_AVRGGIO},
    {IDU_FUNC_XCBRGGIO, 		Set_XCBRGGIO},

    {IDU_FUNC_CSWI, 			Set_CSWI},
    {IDU_FUNC_XCBR, 			Set_XCBR},
    {IDU_FUNC_MMXU, 			Set_MMXU},
    {IDU_FUNC_MMXN, 			Set_MMXN},
    {IDU_FUNC_MSQI, 			Set_MSQI},
    {IDU_FUNC_PTRC, 			Set_PTRC},
    {IDU_FUNC_QPTTR, 			Set_QPTTR},
    {IDU_FUNC_BLKPTTR, 			Set_BLKPTTR},
    {IDU_FUNC_PDPR, 			Set_PDPR},

    {IDU_FUNC_INGGIO, 			Set_INGGIO},
    {IDU_FUNC_OUTGGIO, 			Set_OUTGGIO},
    {IDU_FUNC_LEDGGIO, 			Set_LEDGGIO},
    {IDU_FUNC_SSLGGIO, 			Set_SSLGGIO},
    {IDU_FUNC_VLSGGIO, 			Set_VLSGGIO},
    {IDU_FUNC_LSGGIO, 			Set_LSGGIO},
    {IDU_FUNC_NBLKGGIO, 		Set_NBLKGGIO},
    {IDU_FUNC_FLSGGIO, 			Set_FLSGGIO},
    {IDU_FUNC_RSTGGIO, 			Set_RSTGGIO},

    {IDU_FUNC_SPCSO, 			Set_SPCSO},

    {IDU_FUNC_ATCC, 			Set_ATCC},

    {IDU_FUNC_RDRE, 			Set_RDRE},

    {IDU_FUNC_SG, 				Set_SG},

};


int	IedDataUpdateFuncRun(uint16_t FunctionCode, uint16_t num){

USHORT	i;
int	Ret = 0;

for (i = 0; i < IDU_FUNC_HANDLERS_MAX; i++)
	{
		if (IedDataUpdateFuncHandlers[i].usFunctionCode == 0)		break;
		else
		if (IedDataUpdateFuncHandlers[i].usFunctionCode == FunctionCode)
		{
			Ret = IedDataUpdateFuncHandlers[i].pxHandler(num, Hal_getTimeInMs());
			break;
		}
	}
return  Ret;
}
