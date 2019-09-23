/*
 * dataUpdateFromBase.h
 *
 *  Created on: 29.11.2017
 *      Author: sagok
 */

#ifndef DATAUPDATEFROMBASE_H_
#define DATAUPDATEFROMBASE_H_

#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif

// если сделать по порядку, то можно не лазить по массиву а вызывать конкретный номер функции
/* ----------------------- Defines ------------------------------------------*/
#define IDU_FUNC_NONE                   (   0 )
#define IDU_FUNC_LLN0LPHD	            (   1 )
#define IDU_FUNC_IPTOC          		(   2 )
#define IDU_FUNC_IPTUC          		(   3 )
#define IDU_FUNC_I2PTOC          		(   4 )
#define IDU_FUNC_I0PTOC          		(   5 )
#define IDU_FUNC_I20PTOC				(   6 )
#define IDU_FUNC_INPTOC          		(   7 )
#define IDU_FUNC_IGPTOC          		(   8 )
#define IDU_FUNC_I2I1PTOC          		(   9 )
#define IDU_FUNC_LZSHPTOC          		(  10 )
#define IDU_FUNC_IARCPTOC          		(  11 )
#define IDU_FUNC_UPTOV          		(  12 )
#define IDU_FUNC_UPTUV          		(  13 )
#define IDU_FUNC_U0PTOV         		(  14 )
#define IDU_FUNC_U1PTUV         		(  15 )
#define IDU_FUNC_U2PTOV         		(  16 )

#define IDU_FUNC_PTOF          			(  17 )
#define IDU_FUNC_PTUF          			(  18 )

#define IDU_FUNC_IDPDIF         		(  19 )
#define IDU_FUNC_IDDPDIF         		(  20 )
#define IDU_FUNC_IDDMPDIF         		(  21 )
#define IDU_FUNC_IDMPDIF           		(  22 )
#define IDU_FUNC_ID0PDIF         		(  23 )
#define IDU_FUNC_PDIS         			(  24 )

#define IDU_FUNC_RREC	          		(  25 )
#define IDU_FUNC_FRREC          		(  26 )
#define IDU_FUNC_RBRF	          		(  27 )
#define IDU_FUNC_RSYN	          		(  28 )
#define IDU_FUNC_RPSB	          		(  29 )
#define IDU_FUNC_RFLO	          		(  30 )

#define IDU_FUNC_VZGGIO          		(  31 )
#define IDU_FUNC_AVRGGIO          		(  32 )
#define IDU_FUNC_XCBRGGIO	         	(  33 )		// полностью идентична IDU_FUNC_SPCSO нужно удалить

#define IDU_FUNC_CSWI	          		(  34 )
#define IDU_FUNC_XCBR	          		(  35 )
#define IDU_FUNC_MMXU		         	(  36 )
#define IDU_FUNC_MMXN		         	(  37 )
#define IDU_FUNC_MSQI		         	(  38 )
#define IDU_FUNC_PTRC	          		(  39 )
#define IDU_FUNC_QPTTR         			(  40 )
#define IDU_FUNC_BLKPTTR         		(  41 )
#define IDU_FUNC_PDPR         			(  42 )

#define IDU_FUNC_INGGIO		         	(  43 )
#define IDU_FUNC_OUTGGIO	         	(  44 )
#define IDU_FUNC_LEDGGIO	         	(  45 )
#define IDU_FUNC_SSLGGIO	         	(  46 )
#define IDU_FUNC_VLSGGIO	         	(  47 )
#define IDU_FUNC_LSGGIO		         	(  48 )
#define IDU_FUNC_NBLKGGIO				(  49 )
#define IDU_FUNC_FLSGGIO				(  50 )
#define IDU_FUNC_RSTGGIO				(  51 )

#define IDU_FUNC_SPCSO		         	(  52 )		// полностью идентична IDU_FUNC_XCBRGGIO

#define IDU_FUNC_ATCC		         	(  53 )

#define IDU_FUNC_RDRE		         	(  54 )

#define IDU_FUNC_SG			         	(  55 )
#define IDU_FUNC_HANDLERS_MAX           (  IDU_FUNC_SG + 1 )			// макс число функций

/* ----------------------- Type definitions ---------------------------------*/

typedef enum
{
    IED_NONE = 0x00,
    IED_ILLEGAL_FUNCTION = 0x01,
    IED_ILLEGAL_DATA_ADDRESS = 0x02,
    IED_ILLEGAL_DATA_VALUE = 0x03,
    IED_MEMORY_PARITY_ERROR = 0x04,
} iedDataUpdateException;


typedef         int( *pIedDataUpdateFunctionHandler ) ( uint16_t num, uint64_t currentTime );

typedef struct
{
	uint16_t           				usFunctionCode;				// код функции
    pIedDataUpdateFunctionHandler 	pxHandler;					// указатель на саму функцию обработчик
} IedDataUpdateHandler;



int	IedDataUpdateFuncRun(uint16_t FunctionCode, uint16_t num);


#ifdef __cplusplus
PR_END_EXTERN_C
#endif
#endif /* DATAUPDATEFROMBASE_H_ */
