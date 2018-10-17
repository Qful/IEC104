/*
 * httpServer.c
 *
 *  Created on: 14.01.2017
 *      Author: sagok
 */
#include "main.h"

#include "hal_socket.h"

#include "httpServer.h"


#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "lwip/inet.h"
#include "lwip/sockets.h"

#include "string.h"

#include "ExtSPImem.h"
#include "inflash.h"

#include "ethernetif.h"


#include "cmsis_os.h"

#include "lwip/err.h"

#include "iec61850_server.h"

#include "http/time.c"
//#include "http/index.c"
#include "http/styles.c"
//#include "http/uploadboot.c"
//#include "http/fwupdate.c"

extern IedServer 	iedServer;
extern	errMB_data	cntErrorMD;

extern uint32_t	GLOBALMemoryUsedLim;							//максимально использованной памяти


HAL_StatusTypeDef BOOTFLASH_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
void	SetNTPconfig(char *inbuff);

static const char Favicon[1150] = {
	0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x00, 0x00, 0x01, 0x00,
	0x20, 0x00, 0x68, 0x04, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00,
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFD, 0xFD, 0xFD, 0x50, 0xFD, 0xFD, 0xFE, 0x50, 0xFD, 0xFD,
	0xFE, 0x50, 0xFE, 0xFD, 0xFC, 0x50, 0xF9, 0xF5, 0xF4, 0x50, 0xFD, 0xFA,
	0xFA, 0x50, 0xFE, 0xFD, 0xFE, 0x50, 0xFD, 0xFD, 0xFE, 0x50, 0xFE, 0xFE,
	0xFE, 0x50, 0xFD, 0xFD, 0xFD, 0x50, 0xFD, 0xFB, 0xFB, 0x50, 0xFA, 0xF5,
	0xF5, 0x50, 0xFE, 0xFC, 0xFD, 0x50, 0xFD, 0xFD, 0xFD, 0x50, 0xFD, 0xFD,
	0xFD, 0x50, 0xFD, 0xFD, 0xFD, 0x50, 0xFD, 0xFE, 0xFE, 0xFF, 0xFD, 0xFE,
	0xFE, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFA, 0xFA, 0xF7, 0xFF, 0xF2, 0xED,
	0xE8, 0xFF, 0xF8, 0xF4, 0xF3, 0xFF, 0xFA, 0xFA, 0xF9, 0xFF, 0xFC, 0xFB,
	0xFB, 0xFF, 0xFD, 0xFB, 0xFB, 0xFF, 0xFB, 0xFB, 0xFA, 0xFF, 0xF9, 0xF5,
	0xF3, 0xFF, 0xF4, 0xEE, 0xE9, 0xFF, 0xFA, 0xF7, 0xF6, 0xFF, 0xFD, 0xFD,
	0xFD, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFD, 0xFD,
	0xFD, 0xFF, 0xFE, 0xFD, 0xFD, 0xFF, 0xFB, 0xFC, 0xFC, 0xFF, 0xFB, 0xF7,
	0xF4, 0xFF, 0xE5, 0xDB, 0xD4, 0xFF, 0xDF, 0xD4, 0xCB, 0xFF, 0xF3, 0xF1,
	0xED, 0xFF, 0xF2, 0xEB, 0xE4, 0xFF, 0xF1, 0xEC, 0xE6, 0xFF, 0xF5, 0xF1,
	0xEF, 0xFF, 0xE4, 0xDC, 0xD4, 0xFF, 0xE0, 0xD3, 0xCA, 0xFF, 0xF8, 0xF5,
	0xF2, 0xFF, 0xFD, 0xFD, 0xFD, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFD, 0xFD,
	0xFD, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFD, 0xFC, 0xFC, 0xFF, 0xF8, 0xF5,
	0xF3, 0xFF, 0xF0, 0xEC, 0xE6, 0xFF, 0xE2, 0xD9, 0xD2, 0xFF, 0xC9, 0xB2,
	0xA1, 0xFF, 0xC3, 0xB0, 0xA0, 0xFF, 0xE1, 0xD8, 0xD0, 0xFF, 0xE0, 0xDA,
	0xD4, 0xFF, 0xC5, 0xB0, 0x9F, 0xFF, 0xD1, 0xBA, 0xAD, 0xFF, 0xD9, 0xCD,
	0xC2, 0xFF, 0xF0, 0xEC, 0xE6, 0xFF, 0xF9, 0xF6, 0xF5, 0xFF, 0xFD, 0xFC,
	0xFC, 0xFF, 0xFD, 0xFD, 0xFD, 0xFF, 0xFB, 0xFC, 0xFB, 0xFF, 0xF7, 0xF5,
	0xF2, 0xFF, 0xE3, 0xDB, 0xD3, 0xFF, 0xD7, 0xCA, 0xBF, 0xFF, 0xE5, 0xDD,
	0xD3, 0xFF, 0xE1, 0xD6, 0xCC, 0xFF, 0xF9, 0xF5, 0xF4, 0xFF, 0xDF, 0xD7,
	0xCF, 0xFF, 0xDF, 0xD6, 0xCD, 0xFF, 0xF5, 0xF3, 0xEF, 0xFF, 0xE1, 0xD7,
	0xCF, 0xFF, 0xE8, 0xDD, 0xD2, 0xFF, 0xD6, 0xCB, 0xBF, 0xFF, 0xE4, 0xDB,
	0xD2, 0xFF, 0xF8, 0xF4, 0xF3, 0xFF, 0xFB, 0xFC, 0xFB, 0xFF, 0xF8, 0xF4,
	0xF3, 0xFF, 0xDB, 0xD2, 0xC9, 0xFF, 0xE5, 0xDE, 0xD8, 0xFF, 0xE6, 0xE0,
	0xD9, 0xFF, 0xCB, 0xBC, 0xB1, 0xFF, 0xC9, 0xB7, 0xA8, 0xFF, 0xD5, 0xCA,
	0xC0, 0xFF, 0xC7, 0xB3, 0xA3, 0xFF, 0xC6, 0xB1, 0xA2, 0xFF, 0xD3, 0xC6,
	0xBE, 0xFF, 0xCB, 0xB7, 0xA9, 0xFF, 0xC9, 0xBD, 0xB0, 0xFF, 0xE7, 0xDF,
	0xD9, 0xFF, 0xE4, 0xDE, 0xDA, 0xFF, 0xDE, 0xD1, 0xC8, 0xFF, 0xF9, 0xF5,
	0xF3, 0xFF, 0xF8, 0xF6, 0xF3, 0xFF, 0xD1, 0xC0, 0xB2, 0xFF, 0xC4, 0xA5,
	0x8C, 0xFF, 0xC4, 0xA5, 0x90, 0xFF, 0xCE, 0xB8, 0xA5, 0xFF, 0xCD, 0xB2,
	0xA1, 0xFF, 0xC7, 0xAA, 0x94, 0xFF, 0xDA, 0xC8, 0xB8, 0xFF, 0xCE, 0xB4,
	0xA3, 0xFF, 0xB9, 0x99, 0x7F, 0xFF, 0xD0, 0xB7, 0xA5, 0xFF, 0xD4, 0xBD,
	0xAC, 0xFF, 0xDF, 0xCC, 0xBE, 0xFF, 0xE8, 0xD9, 0xCC, 0xFF, 0xC6, 0xAB,
	0x97, 0xFF, 0xF9, 0xF5, 0xF5, 0xFF, 0xF9, 0xF6, 0xF2, 0xFF, 0xCE, 0xBE,
	0xB1, 0xFF, 0xAB, 0x8A, 0x71, 0xFF, 0xBA, 0xA0, 0x8C, 0xFF, 0xE1, 0xD5,
	0xCC, 0xFF, 0xC9, 0xB3, 0xA3, 0xFF, 0xB1, 0x90, 0x79, 0xFF, 0xCD, 0xB8,
	0xA8, 0xFF, 0xA2, 0x7A, 0x5D, 0xFF, 0xEB, 0xE4, 0xDD, 0xFF, 0xA8, 0x80,
	0x66, 0xFF, 0xCC, 0xB7, 0xA4, 0xFF, 0xC2, 0xAB, 0x9A, 0xFF, 0xC8, 0xB7,
	0xA8, 0xFF, 0xBD, 0xA3, 0x90, 0xFF, 0xF8, 0xF6, 0xF4, 0xFF, 0xF7, 0xF6,
	0xF2, 0xFF, 0xD7, 0xC5, 0xBA, 0xFF, 0xE1, 0xD3, 0xCB, 0xFF, 0xDA, 0xCC,
	0xC1, 0xFF, 0xE2, 0xD6, 0xCB, 0xFF, 0xDF, 0xD2, 0xCA, 0xFF, 0xD1, 0xC0,
	0xB3, 0xFF, 0xD0, 0xC0, 0xB1, 0xFF, 0xCD, 0xB7, 0xA7, 0xFF, 0xD5, 0xC6,
	0xB9, 0xFF, 0xE3, 0xD6, 0xCA, 0xFF, 0xDF, 0xD2, 0xC9, 0xFF, 0xE0, 0xD2,
	0xC8, 0xFF, 0xE5, 0xDC, 0xD1, 0xFF, 0xD5, 0xC2, 0xB7, 0xFF, 0xF8, 0xF5,
	0xF5, 0xFF, 0xFB, 0xF8, 0xF9, 0xFF, 0xF4, 0xF0, 0xEE, 0xFF, 0xE1, 0xD7,
	0xCE, 0xFF, 0xE2, 0xDA, 0xD2, 0xFF, 0xD1, 0xC2, 0xB6, 0xFF, 0xE7, 0xDF,
	0xD7, 0xFF, 0xDA, 0xCA, 0xBD, 0xFF, 0xDC, 0xCE, 0xC5, 0xFF, 0xDE, 0xD4,
	0xC7, 0xFF, 0xD4, 0xC5, 0xB8, 0xFF, 0xE7, 0xE0, 0xD9, 0xFF, 0xD0, 0xC2,
	0xB4, 0xFF, 0xE2, 0xDA, 0xD3, 0xFF, 0xE0, 0xD6, 0xCF, 0xFF, 0xF5, 0xF0,
	0xED, 0xFF, 0xFB, 0xF9, 0xF8, 0xFF, 0xFD, 0xFD, 0xFD, 0xFF, 0xFC, 0xF9,
	0xF8, 0xFF, 0xF7, 0xF3, 0xF1, 0xFF, 0xE5, 0xDD, 0xD4, 0xFF, 0xDF, 0xD4,
	0xCC, 0xFF, 0xDD, 0xCF, 0xC5, 0xFF, 0xE3, 0xD9, 0xD1, 0xFF, 0xDF, 0xD6,
	0xCD, 0xFF, 0xEB, 0xE5, 0xE0, 0xFF, 0xDB, 0xCE, 0xC3, 0xFF, 0xDC, 0xCF,
	0xC6, 0xFF, 0xDE, 0xD4, 0xCB, 0xFF, 0xE5, 0xDD, 0xD3, 0xFF, 0xF5, 0xF3,
	0xF0, 0xFF, 0xFA, 0xF9, 0xF9, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFE, 0xFD,
	0xFE, 0xFF, 0xFD, 0xFE, 0xFD, 0xFF, 0xFC, 0xFC, 0xF9, 0xFF, 0xF9, 0xF4,
	0xF6, 0xFF, 0xF7, 0xF4, 0xF1, 0xFF, 0xE6, 0xDE, 0xD9, 0xFF, 0xDF, 0xD1,
	0xC7, 0xFF, 0xC2, 0xAC, 0x98, 0xFF, 0xCA, 0xB0, 0x9E, 0xFF, 0xD6, 0xC6,
	0xBC, 0xFF, 0xE7, 0xE0, 0xD8, 0xFF, 0xF8, 0xF5, 0xF1, 0xFF, 0xF7, 0xF6,
	0xF2, 0xFF, 0xFD, 0xFC, 0xFB, 0xFF, 0xFE, 0xFE, 0xFD, 0xFF, 0xFC, 0xFE,
	0xFD, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFD, 0xFD,
	0xFE, 0xFF, 0xFC, 0xFB, 0xFB, 0xFF, 0xF7, 0xF1, 0xEF, 0xFF, 0xDA, 0xCC,
	0xC0, 0xFF, 0xE8, 0xE1, 0xDD, 0xFF, 0xC8, 0xB3, 0x9F, 0xFF, 0xC4, 0xAD,
	0x9C, 0xFF, 0xE8, 0xE0, 0xD9, 0xFF, 0xD9, 0xCD, 0xC2, 0xFF, 0xF5, 0xF2,
	0xEE, 0xFF, 0xFA, 0xFB, 0xFB, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFE, 0xFD,
	0xFE, 0xFF, 0xFE, 0xFD, 0xFD, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFD,
	0xFE, 0xFF, 0xFE, 0xFD, 0xFE, 0xFF, 0xFD, 0xFC, 0xFC, 0xFF, 0xF8, 0xF4,
	0xF3, 0xFF, 0xF7, 0xF2, 0xF0, 0xFF, 0xF8, 0xF2, 0xEF, 0xFF, 0xD8, 0xC7,
	0xBC, 0xFF, 0xD0, 0xBD, 0xAC, 0xFF, 0xF8, 0xF3, 0xEE, 0xFF, 0xF7, 0xF3,
	0xEF, 0xFF, 0xF8, 0xF4, 0xF3, 0xFF, 0xFC, 0xFC, 0xFC, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFD, 0xFD, 0xFC, 0xFF, 0xFC, 0xFC, 0xFC, 0xFF, 0xFB, 0xF9,
	0xF7, 0xFF, 0xE8, 0xE0, 0xD8, 0xFF, 0xE3, 0xD6, 0xCC, 0xFF, 0xFA, 0xF5,
	0xF4, 0xFF, 0xFB, 0xFB, 0xFA, 0xFF, 0xFC, 0xFD, 0xFC, 0xFF, 0xFD, 0xFD,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFD, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFD, 0xFD, 0xFE, 0xFF, 0xFD, 0xFD,
	0xFE, 0xFF, 0xFD, 0xFC, 0xFC, 0xFF, 0xF5, 0xF1, 0xEF, 0xFF, 0xEE, 0xE9,
	0xE7, 0xFF, 0xFB, 0xFA, 0xF9, 0xFF, 0xFD, 0xFD, 0xFD, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFD, 0xFD, 0xFD, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
	0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
/***************************************************************************
 *
 */

const struct fsdata_file file_stylecss_html[] = {{NULL, data_stylecss_html, data_stylecss_html + 12, sizeof(data_stylecss_html) - 12}};
const struct fsdata_file file_time_html[] = {{file_stylecss_html, data_time_html, data_time_html + 11, sizeof(data_time_html) - 11}};

#define FS_ROOT file_time_html//file_uploaddone_html
#define FS_NUMFILES 2


/* -----------------------------------------------------------*/
static __IO uint32_t size =0;
static __IO uint32_t DataFlag=0;
static __IO uint8_t resetpage=0;
static uint32_t ContentLengthOffset =0,BrowserFlag=0;
static uint32_t TotalReceived=0;
static __IO uint32_t TotalData=0, checklogin=0;
static char LeftBytesTab[4];
static uint8_t LeftBytes=0;
static __IO uint32_t FlashWriteAddress;
/* -----------------------------------------------------------*/

struct http_state
{
  char *file;
  u32_t left;
};
typedef enum
{
  LoginPage = 0,
  FileUploadPage,
  UploadDonePage,
  ResetDonePage
}htmlpageState;

htmlpageState htmlpage;
/* -----------------------------------------------------------*/
static const char http_crnl_2[4] = {0xd,0xa,0x2d,0x2d};	/* "\r\n--" */
static const char http_crnl_1[4] = {0x2d,0x2d,0xd,0xa};	/* "\r\n--" */

static const char octet_stream[14] = {0x6f, 0x63, 0x74, 0x65, 0x74, 0x2d, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6d,0x0d, };/* "octet-stream" */
static const char Content_Length[17] ={0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x4c, 0x65, 0x6e, 0x67,0x74, 0x68, 0x3a, 0x20, };/* Content Length */




extern uint16_t   	ucMRevBuf[MB_NumbWordRev];
extern uint8_t		IP_ADDR[4];
extern uint8_t		SNTP_IP_ADDR[4];
extern uint16_t		SNTP_Period;
extern int8_t		TimeZone_my;

extern RTC_HandleTypeDef 	hrtc;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#define	httpsize	2048

u32_t nPageHits = 0;
portCHAR PAGE_BODY[httpsize];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static int fs_open(char *name, struct fs_file *file);
static uint32_t Parse_Content_Length(char *data, uint32_t len);
static void IAP_HTTP_writedata(char * ptr, uint32_t len);
int8_t FLASH_If_Init(void);

int8_t BootFLASH_If_Erase(uint32_t StartSector,uint8_t Numb);
int8_t FLASH_If_Erase(uint32_t StartSector);
uint32_t FLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint16_t DataLength);
uint32_t BootFLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint16_t DataLength,uint32_t TypeProgram);

/*************************************************************************
 * TOPBAR
 *************************************************************************/
void TOPBAR(portCHAR *pagehits, portCHAR *PAGE_BODY,uint8_t	pos)
{
	  sprintf(pagehits,"<div id=\"top_bar_black\">");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<div id=\"logo_header\"><h2>БЭМН. Конфигуратор сервера МЭК-61850</h2></div>");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<div id=\"procontainer_blue\">");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<div id=\"pronav_blue\">");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<ul>");strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<li><a href=\"index.html\" title=\"css menus\"");strcat(PAGE_BODY, pagehits);
	  if(pos==0)	sprintf(pagehits," class=\"current\"><span>Главная</span></a></li>");
	  else	  		sprintf(pagehits,"><span>Главная</span></a></li>");
	  strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<li><a href=\"info.html\" title=\"css menus\"");strcat(PAGE_BODY, pagehits);
	  if(pos==1)	sprintf(pagehits," class=\"current\"><span>Инфо о защите</span></a></li>");
	  else			sprintf(pagehits,"><span>Инфо о защите</span></a></li>");
	  strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<li><a href=\"time.html\" title=\"css menus\"");strcat(PAGE_BODY, pagehits);
	  if(pos==2)	sprintf(pagehits," class=\"current\"><span>Настройка времени</span></a></li>");
	  else			sprintf(pagehits,"><span>Настройка времени</span></a></li>");
	  strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<li><a href=\"system.html\" title=\"css menus\"");strcat(PAGE_BODY, pagehits);
	  if(pos==3)	sprintf(pagehits," class=\"current\"><span>Системная информация</span></a></li>");
	  else			sprintf(pagehits,"><span>Системная информация</span></a></li>");
	  strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<li><a href=\"fwupdate.html\" title=\"css menus\"");strcat(PAGE_BODY, pagehits);
	  if(pos==4)	sprintf(pagehits," class=\"current\"><span>Обновление прошивки</span></a></li>");
	  else			sprintf(pagehits,"><span>Обновление прошивки</span></a></li>");
	  strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"</ul>");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"</div></div></div>");strcat(PAGE_BODY, pagehits);
}
/*************************************************************************
 * HEAD
 *************************************************************************/
void HEAD(portCHAR *pagehits, portCHAR *PAGE_BODY,char *pos)
{
// <head>
	  sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
	  sprintf(pagehits,"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\"/>"); strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<title>%s</title>",pos); strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<link href=\"styles.css\" rel=\"stylesheet\" type=\"text/css\"/>"); strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
}
/*************************************************************************
 * infoPage
 *************************************************************************/
//#define	httpsize	2048
void indexPage(struct netconn *conn)
{

		  portCHAR PAGE_BODY[httpsize];
		  portCHAR pagehits[150];


		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);

		  HEAD(pagehits,PAGE_BODY,"БЭМН. Конфигуратор сервера МЭК-61850");
		  /*
// <head>
		  sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
		  sprintf(pagehits,"<meta http-equiv=""Content-Type"" content=""text/html; charset=windows-1251"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<title>БЭМН. Конфигуратор сервера МЭК-61850</title>"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<link href=""styles.css"" rel=""stylesheet"" type=""text/css"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
// </head>
 */
  		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
  		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);

		  TOPBAR(pagehits,PAGE_BODY,0);
//<div>
		  sprintf(pagehits,"<div id=\"content_container\">");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<h2>Информация об управлении в веб-интерфейсе</h2> <hr>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br><br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<p><h3>Информация о защите:</h3> <h4>вся информация о текущей защите: модель, IP, MAC адрес, версия прошивки.</h4></p>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<p><h3>Настройка времени:</h3> <h4>настройка протокола сетевого времени NTP</h4></p>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<p><h3>Системная информация:</h3> <h4>чтение системной информации устройства</h4></p>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<p><h3>Обновление прошивки:</h3> <h4>обновление текущей прошивки устройства</h4></p>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
//</div>

		  sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<div id=\"main_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

		  write(conn, PAGE_BODY, strlen(PAGE_BODY));

}
/*************************************************************************
 * infoPage
 *************************************************************************/
//#define	httpsize	1024
void infoPage(struct netconn *conn)
{
	extern RTC_TimeTypeDef StartsTime;
	extern RTC_DateTypeDef StartsDate;

	extern	RTC_TimeTypeDef lastSynchTime;
	extern	RTC_DateTypeDef lastSynchDate;

	extern int16_t		ppm;
	extern int16_t		lostSNTPPackets;

		  portCHAR PAGE_BODY[httpsize];
		  portCHAR pagehits[100];
		  RTC_TimeTypeDef sTime;
		  RTC_DateTypeDef sDate;

		  HAL_RTC_GetTime((RTC_HandleTypeDef *)&hrtc, &sTime, FORMAT_BIN);
		  HAL_RTC_GetDate((RTC_HandleTypeDef *)&hrtc, &sDate, FORMAT_BIN);


		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);

		  HEAD(pagehits,PAGE_BODY,"БЭМН. Конфигуратор сервера МЭК-61850");
/*
// <head>
		  sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
		  sprintf(pagehits,"<meta http-equiv=""Content-Type"" content=""text/html; charset=windows-1251"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<title>БЭМН. Конфигуратор сервера МЭК-61850</title>"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<link href=""styles.css"" rel=""stylesheet"" type=""text/css"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
// </head>
 */
		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);

		  TOPBAR(pagehits,PAGE_BODY,1);

		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

//<div>
		  sprintf(pagehits,"<div id=\"content_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<h2>инфо о защите.</h2><hr>");strcat(PAGE_BODY, pagehits);


		  //<div>
		  sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Изделие: %s</label><br>",(char *)ucMRevBuf);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>связной модуль: %s %s</label><br>",(char *)_swREV,(char *)_swREVverify);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Версия прошивки связного модуля: '%s'</label><br>",_SWRevision);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>IP адрес устройства:%d.%d.%d.%d</label><br>", IP_ADDR[0], IP_ADDR[1], IP_ADDR[2], IP_ADDR[3]);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Время включения: %02d.%02d.%04d - %02d:%02d:%02d.%03u</label><br>",StartsDate.Date,StartsDate.Month,2000+StartsDate.Year,StartsTime.Hours,StartsTime.Minutes,StartsTime.Seconds,(uint16_t)(3999-StartsTime.SubSeconds/2));strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

//		  sprintf(pagehits,"<label>Line D:%u A:%u CRC:%u</label><br>",(unsigned int)cntErrorMD.errDiscreet,(unsigned int)cntErrorMD.errAnalog,(unsigned int)cntErrorMD.errALLCRC);strcat(PAGE_BODY, pagehits);
//		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<label>Время 61850: %02d.%02d.%04d - %02d:%02d:%02d.%03u</label><br>",sDate.Date,sDate.Month,2000+sDate.Year,sTime.Hours,sTime.Minutes,sTime.Seconds,(uint16_t)(3999-sTime.SubSeconds/2));strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Часовой пояс: %i</label><br>",TimeZone_my);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>NTP IP адрес сервера:%d.%d.%d.%d</label><br>",SNTP_IP_ADDR[0],SNTP_IP_ADDR[1],SNTP_IP_ADDR[2],SNTP_IP_ADDR[3]);strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>NTP период обновления:%u мин.</label><br>",SNTP_Period);strcat(PAGE_BODY, pagehits);
		  //lastSynchTime
		  if (lastSynchDate.Date) {
			  sprintf(pagehits,"<label>Последняя синхронизация с сервером времени: %02d.%02d.%04d - %02d:%02d:%02d.%03u (%i ppm)</label><br>",lastSynchDate.Date,lastSynchDate.Month,2000+lastSynchDate.Year,lastSynchTime.Hours,lastSynchTime.Minutes,lastSynchTime.Seconds,(uint16_t)(3999-lastSynchTime.SubSeconds/2),ppm);strcat(PAGE_BODY, pagehits);
		  }
		  else {
			  sprintf(pagehits,"<label>нет синхронизации с сервером времени.</label><br>");strcat(PAGE_BODY, pagehits);
		  }
	//	  sprintf(pagehits,"<label>Пропусков синхронизации: %d периодов</label><br>",lostSNTPPackets);strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
		  //</div>

		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

		  //<div>
		  sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Приборы в сети:</label><hr>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>");strcat(PAGE_BODY, pagehits);
		  PHY_ReadDynamicMACTable((uint8_t *)(PAGE_BODY + strlen(PAGE_BODY)));
		  sprintf(pagehits,"</label>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
		  //</div>

		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

		  //<div>
		  sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>Подключены клиенты:</label><hr>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label>");strcat(PAGE_BODY, pagehits);
		  IedServer_getClientconections((uint8_t *)(PAGE_BODY + strlen(PAGE_BODY)), iedServer);
		  sprintf(pagehits,"</label>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
		  //</div>

		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);




//</div>
		  sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<div id=\"main_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));

}
/*************************************************************************
 * UploaddonePage
 *************************************************************************/
void SystemPage(struct netconn *conn){

  portCHAR PAGE_BODY[httpsize];
  portCHAR pagehits[100];

  memset(PAGE_BODY, 0,httpsize);

  sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);
  HEAD(pagehits,PAGE_BODY,"Системная информация.");

  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
  memset(PAGE_BODY, 0,httpsize);

  sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);

  TOPBAR(pagehits,PAGE_BODY,3);

  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
  memset(PAGE_BODY, 0,httpsize);

//<div>
  sprintf(pagehits,"<div id=\"content_container\">");strcat(PAGE_BODY, pagehits);
  sprintf(pagehits,"<h2>Системная информация.</h2><hr>");strcat(PAGE_BODY, pagehits);


  {
	  sprintf(pagehits,"<label>Техинфо:</label><hr>");strcat(PAGE_BODY, pagehits);

	  sprintf(pagehits,"<label>Line D:%u A:%u U:%u J:%u CRC:%u Timeout:%u</label><br>",
			  (unsigned int)cntErrorMD.errDiscreet,
			  (unsigned int)cntErrorMD.errAnalog,
			  (unsigned int)cntErrorMD.errUstavki,
			  (unsigned int)cntErrorMD.errJurnal,
			  (unsigned int)cntErrorMD.errALLCRC,
			  (unsigned int)cntErrorMD.errTimeOut);
	  strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

	  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
	  memset(PAGE_BODY, 0,httpsize);

	  GetRunTimeStats((char *)PAGE_BODY);
	  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
	  memset(PAGE_BODY, 0,httpsize);
	  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<label>свободно памяти:%u </label><br>", xPortGetFreeHeapSize());strcat(PAGE_BODY, pagehits);
	  sprintf(pagehits,"<label>предел выделения:0x%X </label><br>", GLOBALMemoryUsedLim);strcat(PAGE_BODY, pagehits);
  }


  sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
  sprintf(pagehits,"<div id=\"main_container\">");strcat(PAGE_BODY, pagehits);
  sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
  sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
  sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

  sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
}
/*************************************************************************
 * UploaddonePage
 *************************************************************************/
//#define	httpsize	1024
void UploaddonePage(struct netconn *conn)
{

		  portCHAR PAGE_BODY[httpsize];
		  portCHAR pagehits[100];

		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);

		  HEAD(pagehits,PAGE_BODY,"Обновление загрузчика.");
/*
// <head>
		  sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
		  sprintf(pagehits,"<meta http-equiv=""Content-Type"" content=""text/html; charset=windows-1251"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<title>Обновление загрузчика.</title>"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<link href=""styles.css"" rel=""stylesheet"" type=""text/css"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
// </head>
 */
		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);

		  sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);

 		  TOPBAR(pagehits,PAGE_BODY,4);

		  sprintf(pagehits,"<div id=\"content_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<h2>Обновление загрузчика.</h2><hr>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<label for=\"InFile\">Прошит успешно.</label><br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<div>\n<div>");strcat(PAGE_BODY, pagehits);

		  //sprintf(pagehits,"<form action=""index.html"">");strcat(PAGE_BODY, pagehits);
		 // sprintf(pagehits,"<button type=""submit"">На главную</button>");strcat(PAGE_BODY, pagehits);
		  //sprintf(pagehits,"</form>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</div></div></div>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<div id=\"main_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

		  write(conn, PAGE_BODY, strlen(PAGE_BODY));
}
/*************************************************************************
 * checkloginPage
 *************************************************************************/
//#define	httpsize	2048
void checkloginPage(struct netconn *conn)
{

	 portCHAR PAGE_BODY[httpsize];
	 portCHAR pagehits[100];

	 memset(PAGE_BODY, 0,httpsize);

	 sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);

	  HEAD(pagehits,PAGE_BODY,"Обновление загрузчика.");
	  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
	  memset(PAGE_BODY, 0,httpsize);

/*
	 sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
	 sprintf(pagehits,"<meta http-equiv=""Content-Type"" content=""text/html; charset=windows-1251"" />"); strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<title>Обновление загрузчика</title>"); strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<link href=""styles.css"" rel=""stylesheet"" type=""text/css"" />"); strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
*/
	 sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);

     TOPBAR(pagehits,PAGE_BODY,4);

	 sprintf(pagehits,"<form action =\"/uploadboot.cgi\" enctype=\"multipart/form-data\" method=\"post\">");strcat(PAGE_BODY, pagehits);


	 sprintf(pagehits,"<div id=\"content_container\">");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<h2>Обновление загрузчика.</h2><hr>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<label for=\"InFile\">Выберите Файл прошивки загрузчика *.bin</label><br>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<input accept =\".bin\" type=\"file\" name=\"datafile\" size=\"40\">");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"<div><div>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"<button type=\"submit\" value=\"Upload\">Обновить</button>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"</form>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"</div>\n</div>\n</div>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<div id=\"main_container\">\n");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
	 sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

	 sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

	 write(conn, PAGE_BODY, strlen(PAGE_BODY));
}
/*************************************************************************
 * fwUpdatePage
 *************************************************************************/
//#define	httpsize	2048
void fwUpdatePage(struct netconn *conn)
{
		  portCHAR PAGE_BODY[httpsize];
		  portCHAR pagehits[100];

		  memset(PAGE_BODY, 0,httpsize);
		  sprintf(pagehits,"<html>");strcat(PAGE_BODY, pagehits);

		  HEAD(pagehits,PAGE_BODY,"Обновление ПО модуля МЭК 61850");
		  write((int)conn, PAGE_BODY, strlen(PAGE_BODY));
		  memset(PAGE_BODY, 0,httpsize);
/*
		  sprintf(pagehits,"<head>");strcat(PAGE_BODY, pagehits);//UTF-8
		  sprintf(pagehits,"<meta http-equiv=""Content-Type"" content=""text/html; charset=windows-1251"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<title>Обновление ПО модуля МЭК 61850</title>"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<link href=""styles.css"" rel=""stylesheet"" type=""text/css"" />"); strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</head>");strcat(PAGE_BODY, pagehits);
*/

		  TOPBAR(pagehits,PAGE_BODY,4);

		  //sprintf(pagehits,"<body>");strcat(PAGE_BODY, pagehits);
		  //sprintf(pagehits,"<div id=""top_bar_black"">");strcat(PAGE_BODY, pagehits);
			//  sprintf(pagehits,"<div id=""logo_header""><h2>БЭМН загрузчик.</h2></div>");strcat(PAGE_BODY, pagehits);
		  //sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
//форма
		  sprintf(pagehits,"<form action =\"/checklogin.cgi\" method=\"post\">");strcat(PAGE_BODY, pagehits);
//<div
		  sprintf(pagehits,"<h2>Обновление ПО модуля МЭК 61850</h2><hr>");strcat(PAGE_BODY, pagehits);
		 // -------------------
//<div
		  sprintf(pagehits,"<div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<h2> Введите логин и пароль </h2>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<b>Логин &#160&#160&#160</b> <input type=\"text\" size=\"20\" name=\"username\"><br><br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<b>Пароль&#160</b> <input type=\"password\" size=\"20\" name=\"password\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<br>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div>");strcat(PAGE_BODY, pagehits);
//!<div
		  sprintf(pagehits,"<input type=\"submit\" name=\"login\" value=\"Войти\">");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</form>");strcat(PAGE_BODY, pagehits);
//!форма
		  sprintf(pagehits,"<div id=\"bottom_bar_black\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<div id=\"main_container\">");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"<a class=\"bemn\" href=\"http://www.bemn.by/\">ОАО \"БЭМН\"</a>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</div></div>");strcat(PAGE_BODY, pagehits);
		  sprintf(pagehits,"</body>");strcat(PAGE_BODY, pagehits);

		  sprintf(pagehits,"</html>");strcat(PAGE_BODY, pagehits);

		  write(conn, PAGE_BODY, strlen(PAGE_BODY));

}
/*************************************************************************
 *
 *************************************************************************/
void SSH_Transmit(Socket self, uint8_t *pData, uint16_t Size){

	if (self == NULL) return;

	int conn = GetSocket_num(self);

	if (conn){
	  if (write(conn, pData, Size) == ERR_ABRT){
//#define ERR_ABRT       -10   /* Connection aborted.      */
//#define ERR_RST        -11   /* Connection reset.        */
//#define ERR_CLSD       -12   /* Connection closed.       */
//#define ERR_CONN       -13   /* Not connected.           */
		Socket_destroy(self);
	  }
	}
}
/*************************************************************************
 *
 *************************************************************************/
void SSH_server_serve(Socket self)
{
  HandleSet handles;

  int buflen = 1500;
  int ret;
  int result;
  unsigned char recv_buffer[1500];

  int conn = GetSocket_num(self);

  handles = Handleset_new();
  Handleset_addSocket(handles, self);

   result = Handleset_waitReady(handles, 20);			// проверка состояния сокетов ждем таймаут
  Handleset_destroy(handles);

  if (result < 1){
	  USART_TRACE_RED("Соединение без данных. Закрываем.\n");

	  Socket_destroy(self);
      return;
  }
  // читаем из сокета запрос от клиента
  ret = read(conn, recv_buffer, buflen);

  if(ret == 0) {
	  USART_TRACE_RED("Разорвали соединение со стороны клиента. Закрываем.\n");
	  Socket_destroy(self);
	  return;
  }else
  if(ret < 0) {
	  USART_TRACE_RED("Из буфера ничего не прочитали. Закрываем. %i\n",ret);
	  Socket_destroy(self);
	  return;
  }
}
/*************************************************************************
 *
 *************************************************************************/
void http_server_serve(Socket self)
{
  struct fs_file file = {0, 0};
  struct http_state *hs;
  int32_t i,len=0;
  uint32_t DataOffset, FilenameOffset;
  //char *data;
  char *ptr, filename[13], login[LOGIN_SIZE];

  HandleSet handles;

  handles = Handleset_new();
  Handleset_addSocket(handles, self);

  int result;
  result = Handleset_waitReady(handles, 20);			// проверка состояния сокетов ждем таймаут 20мс иногда были таймауты
  Handleset_destroy(handles);

  if (result < 1){
	  USART_TRACE_RED("Соединение без данных. Закрываем.\n");

	  Socket_destroy(self);
      return;
  }

  int buflen = 1500;
  int ret;
  unsigned char recv_buffer[1500];

  int conn = GetSocket_num(self);

nextbuf:

  // читаем из сокета запрос от клиента
  ret = read(conn, recv_buffer, buflen);

  len = ret;//buflen;

  if(ret == 0) {
	  USART_TRACE_RED("Разорвали соединение со стороны клиента. Закрываем.\n");
	  Socket_destroy(self);
	  return;
  }else
  if(ret < 0) {
	  USART_TRACE_RED("Из буфера ничего не прочитали. Закрываем. %i\n",ret);
	  Socket_destroy(self);
	  return;
  }
//  USART_TRACE_GREEN("Приняли данные какието.....\n");

  //--------------------------------------------------------------------------------------
  if(strncmp((char *)recv_buffer, "GET /info.html", 14) == 0)
  {
	  USART_TRACE("GET /info.html\n");
	  infoPage(conn);
  }
  else if(strncmp((char *)recv_buffer, "GET /system.html", 16) == 0)
    {
      //fs_open("/index.html", &file);
	  //write(conn, (const unsigned char*)file.data, (size_t)file.len);
	  USART_TRACE("GET /system.html\n");
	  SystemPage(conn);
    }
  else if(strncmp((char *)recv_buffer, "GET /favicon.ico", 16) == 0)
    {
	  USART_TRACE("GET /favicon.ico\n");
	  write(conn, (const unsigned char*)Favicon, (size_t)1150);

    }
//  else if(strncmp((char *)recv_buffer, "GET /style.css", 14) == 0)
    else if(strncmp((char *)recv_buffer, "GET /styles.css",15 ) == 0)
    {
	  USART_TRACE("GET /styles.css\n");
      fs_open("/styles.css", &file);
	   write(conn, (const unsigned char*)file.data, (size_t)file.len);
    }

  else if(strncmp((char *)recv_buffer, "GET /restart", 12) == 0)
  {
	  write(conn, "restarting.\n", strlen("restarting.\n"));
	  USART_TRACE("GET /restart\n");
     Socket_destroy(self);
     vTaskDelay(500);

	 NVIC_SystemReset();
  }
 /*
  else if(strncmp((char *)recv_buffer, "GET /deleteDD", 13) == 0)
  {
	  write(conn, "Удалил Сохранённые переменные.\n", strlen("Удалил Сохранённые переменные.\n"));
	  USART_TRACE("GET /deleteDD\n");

	  filesystem_Delete(_DataListWrites);
  }
*/
  else
  if(strncmp((char *)recv_buffer, "GET /upload.html", 16) == 0)
  {
	  write(conn, "upload page.\n", strlen("upload page.\n"));
  }
  else if (strncmp((char *)recv_buffer, "GET /time.html",14) == 0)
 {
	  if (strncmp((char *)recv_buffer, "GET /time.html?",15) == 0){
		  SetNTPconfig((char *)recv_buffer);
		  fs_open("/time.html", &file);
		  write(conn, (const unsigned char*)file.data, (size_t)file.len);

	  } else{
		  USART_TRACE("GET /time.html\n");
		  fs_open("/time.html", &file);
		  write(conn, (const unsigned char*)file.data, (size_t)file.len);
	  }
 }
  else if(strncmp((char *)recv_buffer, "GET /", 5) == 0)
  {
	  if ((strncmp((char *)recv_buffer, "GET /resetmcu.cgi", 17) ==0)&&(htmlpage == UploadDonePage))
		 {
		  /* send reset.html page */
		   htmlpage = ResetDonePage;
		   fs_open("/reset.html", &file);
		   write(conn, (const unsigned char*)file.data, (size_t)file.len);
		   resetpage = 1;
		 }
	  else
		 if(strncmp((char *)recv_buffer, "GET /fwupdate.html", 18) == 0)
		  {
		   htmlpage = LoginPage;
		   fwUpdatePage(conn);
		  }
		 else
		  if((strncmp((char *)recv_buffer, "GET / ", 6) == 0) || (strncmp((char *)recv_buffer, "GET /index.html", 15) == 0))
		  {
	//		    		  USART_TRACE("GET / \n");
			  //fs_open("/index.html", &file);
			  //write(conn, (const unsigned char*)file.data, (size_t)file.len);
	// из памяти программы
			  indexPage(conn);
		  }
		  else
  // из 1:/http папки диска
		  {
			FIL 		_File;
			FRESULT		RES;


			char* gets = strstr((char *)recv_buffer,"GET /");
			if (gets == NULL) goto GotoOUT;
			uint8_t pos = (uint8_t)(gets-(char *)recv_buffer) + 4;
			strcpy(filename,_httpServer);

			char* geth = strstr((char *)recv_buffer,"HTTP/");
			uint8_t posend = (uint8_t)(geth-(char *)recv_buffer);

			strncat(filename,(char *)&recv_buffer[pos],posend - pos - 1);

			RES =  f_open(&_File,filename, FA_READ);
			if(RES != FR_OK){
				USART_TRACE_RED("ошибка файла %s код %u\n",filename, RES);
				goto GotoOUT;
			}
			USART_TRACE_MAGENTA("читаем %s\n",filename);

			uint8_t BuffFntRead[255];
			while (f_eof(&_File) == 0) {			//читаем и парсим содержимое
				//f_gets((TCHAR*)BuffFntRead,255,&_File);
				uint16_t nm;
				if (f_read(&_File,(TCHAR*)BuffFntRead,255,(UINT*)&nm) == FR_OK){
					write(conn, BuffFntRead, (size_t)nm);
				} else{
					f_close(&_File);
					goto GotoOUT;
				}
			}
			f_close(&_File);
		  }
  }
  else if ((strncmp((char *)recv_buffer, "POST /checklogin.cgi",20)==0)&&(htmlpage== LoginPage))
  {
//		USART_TRACE("POST /checklogin.cgi\n");

	          for (i=0;i<len;i++)
	          {
	             if (strncmp ((char*)(recv_buffer+i), "username=", 9)==0)
	             {
	               sprintf((char *)login,"username=%s&password=%s",USERID,PASSWORD);
	               if (strncmp((char*)(recv_buffer+i), (char *)login ,LOGIN_SIZE)==0)					//проверили логин и пароль
	               {
	           		// подождать 3 секунды наверное войдёт в закрузчик
	           		//fs_open("/fwupdate.html", &file);
	           		//write(conn, (const unsigned char*)file.data, (size_t)file.len);
	            	fwUpdatePage(conn);

	           		uint8_t	resetpage = _startboot;										// ставим признак ухода в бутлоадер (0xFF)
	           		memory_write_to_mem((uint8_t *)&resetpage,_Ifboot,1);
//	           		USART_TRACE_BLUE("cтавим признак готовности к работе проги. рестарт\n");
	           		Socket_destroy(self);
	           		NVIC_SystemReset();

	               }
		           sprintf((char *)login,"username=%s&password=%s",USERIDboot,PASSWORDboot);
		           if (strncmp((char*)(recv_buffer+i), (char *)login ,LOGIN_SIZE)==0)				// режим перепрошивки загрузчика
		           {
		        	   USART_TRACE_RED("режим перепрошивки загрузчика !!!!! очень опасно.\n");

		               htmlpage = FileUploadPage;
		               checkloginPage(conn);
	               }
	               else
	               {
	                 htmlpage = LoginPage;
	                 fwUpdatePage(conn);
	               }


	               break;
	             }
	          }

  }
  // загрузчик бутлодера --------------------------------------------------
  else if (((strncmp((char *)recv_buffer, "POST /uploadboot.cgi",20)==0)||(DataFlag >=1))&&(htmlpage == FileUploadPage))
  {
	USART_TRACE("POST /uploadboot.cgi DataFlag:%u\n",DataFlag);
	DataOffset = 0;
	// принимаем пакет
	if (DataFlag == 0)
	{
		BrowserFlag= 0;
		TotalReceived = 0;

		// читаем размер файла
		size = Parse_Content_Length((char *)recv_buffer, (uint32_t)buflen);
		USART_TRACE_BLUE("размер файла %u\n",(unsigned int)size);

		// parse packet for the octet-stream field
		for (i=0;i<len;i++)
		{
		   if (strncmp ((char *)&recv_buffer[i], octet_stream, 13)==0)
		   {
//			 USART_TRACE_BLUE("octet_stream: %u\n",(unsigned int)i);
			 DataOffset = i+16;
			 break;
		   }
		}
		// case of MSIE8 : we do not receive data in the POST packet
		if (DataOffset==0)
		{
//		   USART_TRACE_BLUE("DataOffset = 0\n");
		   // не нашли octet_stream
		   DataFlag++;
		   BrowserFlag = 1;
		   //return ERR_OK;
		   //goto GotoOUT;
		   goto nextbuf;			// переходим к следующему принятому блоку
		}
		// case of Mozilla Firefox : we receive data in the POST packet
		else
		{
		 TotalReceived = len - (ContentLengthOffset + 4);
		}
	}//! if (DataFlag == 0)
	if (((DataFlag ==1)&&(BrowserFlag==1)) || ((DataFlag ==0)&&(BrowserFlag==0)))
	{
		if ((DataFlag ==0)&&(BrowserFlag==0))
		{
		  DataFlag++;
		}
		else if ((DataFlag ==1)&&(BrowserFlag==1))							// ищем octet-stream
		{
		  // parse packet for the octet-stream field
		  for (i=0;i<len;i++)
		  {
			if (strncmp ((char *)&recv_buffer[i], octet_stream, 13)==0)
			{
//			 USART_TRACE_BLUE("octet_stream: %u\n",(unsigned int)i);
			  DataOffset = i+16;
			  break;
			}
		  }
		  TotalReceived+=len;
		  DataFlag++;
		}
		// parse packet for the filename field
		FilenameOffset = 0;

		for (i=0;i<len;i++)
		{
		  if (strncmp ((char *)&recv_buffer[i], "filename=", 9)==0)
		  {
			 FilenameOffset = i+10;
			 break;
		  }
		}
		i =0;
		if (FilenameOffset)
		{
		 while(((recv_buffer[FilenameOffset + i])!=0x22 )&&(i<13))
		 {
		   filename[i] = recv_buffer[FilenameOffset + i];
		   i++;
		 }
		 filename[i] = 0x0;
		}
		if (i==0)
		{
		 htmlpage = FileUploadPage;
		 // нету файла, переоткроем стартовую страницу

		 DataFlag=0;

		 //fs_open("/index.html", &file);
		 //write(conn, (const unsigned char*)file.data, (size_t)file.len);
		 indexPage(conn);

		 goto GotoOUT;	// уходим и закрываем соединение
		}

		TotalData = 0;


		// сначала проверим наша хоть прошивка или нет. Должна по крайней мере в нашу страницу памяти
		// filename[i] можно в имя файла ложить ключ с зашифрованным размером файла.

		if ((recv_buffer[DataOffset+3] & 0x6F ) != 0x20)
			{
				 USART_TRACE_RED("Это не наша прошивка.\n");
				 htmlpage = UploadDonePage;
				 BrowserFlag = 0;
				 DataFlag = 0;
				 size = 0;
				 goto GotoOUT;	// уходим и закрываем соединение
			} else{
				FLASH_If_Init();															// СТИРАЕМ ПАМЯТЬ
				BootFLASH_If_Erase(BOOT_FLASH_FIRST_PAGE_ADDRESS,BOOT_FLASH_NUMB);
				USART_TRACE("Стрираем память.\n");
				FlashWriteAddress = BOOT_FLASH_FIRST_PAGE_ADDRESS;
			}

	}//! if (((DataFlag ==1)&&(BrowserFlag==1)) || ((DataFlag ==0)&&(BrowserFlag==0)))
	// DataFlag >1 => the packet is data only
	else
	{
		TotalReceived +=len;
	}

	ptr = (char *)&recv_buffer[DataOffset];
	len-= DataOffset;

	// обновим счетчик принятых данных
	TotalData +=len;
	// проверим закончился ли файл
	if (TotalReceived == size)
	{
		USART_TRACE_RED("прошили всё: %u\n",size);
		// if last packet need to remove the http boundary tag
		// parse packet for "\r\n--" starting from end of data
		i=4;
		while (strncmp ((char*)&recv_buffer[buflen-i],http_crnl_2 , 4))
		{
			i++;
		}
		if (i>len){
		  i=4;
		  while (strncmp ((char*)&recv_buffer[buflen-i],http_crnl_1 , 4))
		  {
			i++;
		  }
		}

		len-=i;
		TotalData-=i;

		// write data in Flash
		if (len>0){
//		  USART_TRACE_RED("write data in Flash. %u: %u ok\n",TotalReceived,len);
		  IAP_HTTP_writedata(ptr,len);											// тут проверка конца участка. нужно исправить на конец загрузочной области
		}
		DataFlag=0;

		htmlpage = UploadDonePage;

		// send uploaddone.html page
		 //fs_open("/uploaddone.html", &file);
		 //fs_open("/index.html", &file);
		 //write(conn, (const unsigned char*)file.data, (size_t)file.len);
		 UploaddonePage(conn);
	}//!if (TotalReceived == size)
	else
	{
	   // write data in flash
	   if(len){
//		   USART_TRACE("Пишем в память. FlashWriteAddress: 0x%x TotalReceived: %u\n",FlashWriteAddress ,TotalReceived);
		   IAP_HTTP_writedata(ptr,len);
		   USART_TRACE("Записали. ptr,len: 0x%x len: %u\n",ptr ,len);

	   }
	}//! else if (TotalReceived == size)

	if (DataFlag){	// читаем дальше, пока не придёт весь файл. ОБЯЗАТЕЛЬНО зашить весь загрузчик, иначе хана борду, не запустится
	goto nextbuf;
	}

  }
  // !загрузчик бутлодера --------------------------------------------------
  else
  {
	  USART_TRACE_Yellow("404 - Page not found\n");
	  memset(PAGE_BODY, 0,httpsize);
	  strcat((char *) PAGE_BODY, "404 - Page not found\n");
	  strcat((char *) PAGE_BODY, "Sorry, the page you are requesting was not found on this server.\n");

	  write(conn, PAGE_BODY, strlen(PAGE_BODY));

  }

GotoOUT:
  /* Close connection socket */
//  close(conn);
  USART_TRACE_GREEN("откл. от 80 порта.0x%x\n",self);
  Socket_destroy(self);
}

/***********************************************************************
 * voidSetNTPconfig
 ***********************************************************************/
void	SetNTPconfig(char *inbuff){
extern uint64_t lastSynchTimeNTP;
	uint8_t	*pos;
	uint8_t	*end;
	uint8_t	sizeText;
	{
		// ищем все параметры и сохраняем их
		pos =(uint8_t *) strstr((const char *)inbuff,(const char *)"timeZoneId=");
		if (pos > 0){
			end = (uint8_t *) strstr((const char *)pos,(const char *)"&");
			sizeText =1 + end - pos - sizeof("timeZoneId=");
			// далее число корректировки времени часового пояса
				USART_TRACE_GREEN("timeZoneId= %u\n",sizeText);
				pos = pos + sizeof("timeZoneId=") - 1;
				TimeZone_my = atol((const char *)pos);
				memory_write_to_mem((uint8_t *)&TimeZone_my,_IfNTP_TimeZone,1);
				USART_TRACE_BLUE("сохранили во flash Часовой пояс:%i \n", TimeZone_my);

			  //pos + sizeof("timeZoneId=");
			  //Timezone =
			  // сохраняем на флешку
		}
		pos =(uint8_t *) strstr((const char *)inbuff,(const char *)"inputIPtime=");
		if (pos > 0){
			end = (uint8_t *) strstr((const char *)pos,(const char *)"&");
			sizeText = 1 + end - pos - sizeof("inputIPtime=");
			if (sizeText){
				USART_TRACE_GREEN("inputIPtime= %u\n",sizeText);

				//htonl(INADDR_ANY);
				pos = pos + sizeof("inputIPtime=") - 1;
				SNTP_IP_ADDR[0] = atol((const char *)pos);

				end = (uint8_t *) strstr((const char *)pos,(const char *)".");
				pos = end+1;
				SNTP_IP_ADDR[1] = atol((const char *)pos);
				end = (uint8_t *) strstr((const char *)pos,(const char *)".");
				pos = end+1;
				SNTP_IP_ADDR[2] = atol((const char *)pos);
				end = (uint8_t *) strstr((const char *)pos,(const char *)".");
				pos = end+1;
				SNTP_IP_ADDR[3] = atol((const char *)pos);

				memory_write_to_mem((uint8_t *)&SNTP_IP_ADDR[0],_IfNTP_IP,4);
				USART_TRACE_BLUE("сохраним во flash NTP_IP:%d.%d.%d.%d \n", SNTP_IP_ADDR[0], SNTP_IP_ADDR[1], SNTP_IP_ADDR[2], SNTP_IP_ADDR[3]);
				//sprintf((char *)&NTP_IP,"%d.%d.%d.%d", SNTP_IP_ADDR[0], SNTP_IP_ADDR[1], SNTP_IP_ADDR[2], SNTP_IP_ADDR[3]);

			}
			//NTP_IP =
			// сохраняем на флешку
		}

		pos =(uint8_t *) strstr((const char *)inbuff,(const char *)"timeReload=");
		if (pos > 0){
			end = (uint8_t *) strstr((const char *)pos,(const char *)" ");
			sizeText =1 + end - pos - sizeof("timeReload=");
			if (sizeText){
				pos = pos + sizeof("timeReload=") - 1;
				SNTP_Period = atol((const char *)pos);

				USART_TRACE_GREEN("timeReload= %u\n",sizeText);
				// далее период синхронизации в секундах
 				memory_write_to_mem((uint8_t *)&SNTP_Period,_IfNTP_Period,2);
				USART_TRACE_BLUE("сохранили во flash период синхронизации:%u \n", SNTP_Period);
				lastSynchTimeNTP = Hal_getTimeInMs();// + 5000;//SNTP_Period*60*1000;
			  // сохраняем на флешку
			}
		}
	}

}


/**
  * @brief  Opens a file defined in fsdata.c ROM filesystem
  * @param  name : pointer to a file name
  * @param  file : pointer to a fs_file structure
  * @retval  1 if success, 0 if fail
  */
static int fs_open(char *name, struct fs_file *file)
{
  struct fsdata_file_noconst *f;

  for (f = (struct fsdata_file_noconst *)FS_ROOT; f != NULL; f = (struct fsdata_file_noconst *)f->next)
  {
    if (!strcmp(name, f->name))
    {
      file->data = f->data;
      file->len = f->len;
      return 1;
    }
  }
  return 0;
}


/**
  * @brief  Extract the Content_Length data from HTML data
  * @param  data : pointer on receive packet buffer
  * @param  len  : buffer length
  * @retval size : Content_length in numeric format
  */
static uint32_t Parse_Content_Length(char *data, uint32_t len)
{
  uint32_t i=0,size=0, S=1;
  int32_t j=0;
  char sizestring[6], *ptr;

  ContentLengthOffset =0;

  /* find Content-Length data in packet buffer */
  for (i=0;i<len;i++)
  {
    if (strncmp ((char*)(data+i), Content_Length, 16)==0)
    {
      ContentLengthOffset = i+16;
      break;
    }
  }
  /* read Content-Length value */
  if (ContentLengthOffset)
  {
    i=0;
    ptr = (char*)(data + ContentLengthOffset);
    while(*(ptr+i)!=0x0d)
    {
      sizestring[i] = *(ptr+i);
      i++;
      ContentLengthOffset++;
    }
    if (i>0)
    {
      /* transform string data into numeric format */
      for(j=i-1;j>=0;j--)
      {
        size += (sizestring[j]-'0')*S;
        S=S*10;
      }
    }
  }
  return size;
}

/**
  * @brief  writes received data in flash
  * @param  ptr: data pointer
  * @param  len: data length
  * @retval None
  */
//#define _Size	FLASH_TYPEPROGRAM_BYTE
static void IAP_HTTP_writedata(char * ptr, uint32_t len)
{
  uint32_t count, i=0, j=0;

  /* check if any left bytes from previous packet transfer*/
  /* if it is the case do a concat with new data to create a 32-bit word */
  if (LeftBytes)
  {
    while(LeftBytes<=3)
    {
      if(len>(j+1))
      {
        LeftBytesTab[LeftBytes++] = *(ptr+j);
      }
      else
      {
        LeftBytesTab[LeftBytes++] = 0xFF;
      }
      j++;
    }
    if (BootFLASH_If_Write(&FlashWriteAddress, (uint32_t*)(LeftBytesTab),1,FLASH_TYPEPROGRAM_WORD)){
    	USART_TRACE_RED("FLASH_If_Write error\n");
    }
    //BootFLASH_If_Write(&FlashWriteAddress, (uint32_t*)ptr ,count);
    //BootFLASH_If_Write(&FlashWriteAddress, (uint32_t*)ptr ,count,FLASH_TYPEPROGRAM_WORD);
    LeftBytes =0;

    /* update data pointer */
    ptr = (char*)(ptr+j);
    len = len -j;
  }

  /* write received bytes into flash */
  count = len/4;								// получим число 32битных слов
  //	  count = len/(1<<_Size);

  /* check if remaining bytes < 4 */
  i= len%4;										// получим число байт остатка
  //i= len%(1<<_Size);

  if (i>0)
  {
    if (TotalReceived != size)
    {
      /* store bytes in LeftBytesTab */
      LeftBytes=0;
      for(;i>0;i--)
      LeftBytesTab[LeftBytes++] = *(char*)(ptr+ len-i);
    }
    else count++;
  }
  //BootFLASH_If_Write(&FlashWriteAddress, (uint32_t*)ptr ,count);
  BootFLASH_If_Write(&FlashWriteAddress, (uint32_t*)ptr ,count,FLASH_TYPEPROGRAM_WORD);
}

/**
  * @brief  Unlocks Flash for write access
  * @param  None
  * @retval None
  */
int8_t FLASH_If_Init(void)
{
   return HAL_FLASH_Unlock();
}


/*************************************************************************
 * стираем бутлоадер
 *
 *************************************************************************/
int8_t BootFLASH_If_Erase(uint32_t StartSector,uint8_t Numb)
{
	  HAL_StatusTypeDef	res;
	  extern FLASH_ProcessTypeDef pFlash;

	  // Device voltage range supposed to be [2.7V to 3.6V], the operation will  be done by word

	  if (StartSector <= (uint32_t) BOOT_FLASH_LAST_PAGE_ADDRESS)
	  {
	    FLASH_EraseInitTypeDef FLASH_EraseInitStruct;
	    uint32_t sectornb = 0;

	    FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	    FLASH_EraseInitStruct.Sector = StartSector;
	    FLASH_EraseInitStruct.NbSectors = Numb;
	    FLASH_EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

	//    res = HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &sectornb);
	    res = BOOTFLASH_Erase(&FLASH_EraseInitStruct, &sectornb);
	    if (res != HAL_OK){

	  	  USART_TRACE_RED("BootFLASH_If_Erase error:%u сектор:0x%x\n",pFlash.ErrorCode,sectornb);
	      return (1);
	    }
	  }
	  else
	  {
	    return (1);
	  }

	  return (0);
}
/*************************************************************************
 *FLASH_ClearFlag
 *
 *************************************************************************/
void FLASH_ClearFlag(uint32_t FLASH_FLAG)
{
  /* Check the parameters */
  assert_param(IS_FLASH_CLEAR_FLAG(FLASH_FLAG));

  /* Clear the flags */
  FLASH->SR = FLASH_FLAG;
}
/*************************************************************************
 * стираем бутлоадер
 *
 *************************************************************************/
#include "stm32f4xx_hal_def.h"
#define SECTOR_MASK               ((uint32_t)0xFFFFFF07)
#define FLASH_TIMEOUT_VALUE       ((uint32_t)50000)/* 50 s */

HAL_StatusTypeDef BOOTFLASH_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError)
{
  extern FLASH_ProcessTypeDef pFlash;
  HAL_StatusTypeDef status = HAL_ERROR;
  uint32_t index = 0;

  /* Process Locked */
  __HAL_LOCK(&pFlash);

  /* Clear pending flags (if any) */
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);


  /* Check the parameters */
  assert_param(IS_FLASH_NBSECTORS(pEraseInit->NbSectors + pEraseInit->Sector));

  /* Erase by sector by sector to be done*/
  for(index = pEraseInit->Sector; index < (pEraseInit->NbSectors + pEraseInit->Sector); index++)
  {
    FLASH_Erase_Sector(index, (uint8_t) pEraseInit->VoltageRange);

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* If the erase operation is completed, disable the SER Bit */
    FLASH->CR &= (~FLASH_CR_SER);
    FLASH->CR &= SECTOR_MASK;

    if(status != HAL_OK)
    {
      /* In case of error, stop erase procedure and return the faulty sector*/
      *SectorError = index;
      break;
    }
  }

  /* Process Unlocked */
  __HAL_UNLOCK(&pFlash);

  return status;
}
/**
  * @brief  This function does an erase of all user flash area
  * @param  StartSector: start of user flash area
  * @retval 0: user flash area successfully erased
  *         1: error occured
  */
int8_t FLASH_If_Erase(uint32_t StartSector)
{
  uint32_t FlashAddress;

  FlashAddress = StartSector;

  /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
     be done by word */

  if (FlashAddress <= (uint32_t) USER_FLASH_LAST_PAGE_ADDRESS)
  {
    FLASH_EraseInitTypeDef FLASH_EraseInitStruct;
    uint32_t sectornb = 0;

    FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    FLASH_EraseInitStruct.Sector = FLASH_SECTOR_5;
    FLASH_EraseInitStruct.NbSectors = 19;
    FLASH_EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    if (HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &sectornb) != HAL_OK)
      return (1);
  }
  else
  {
    return (1);
  }

  return (0);
}

/**
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  * @note   After writing data buffer, the flash content is checked.
  * @param  FlashAddress: start address for writing data buffer
  * @param  Data: pointer on data buffer
  * @param  DataLength: length of data buffer (unit is 32-bit word)
  * @retval 0: Data successfully written to Flash memory
  *         1: Error occurred while writing data in Flash memory
  *         2: Written Data in flash memory is different from expected one
  */
uint32_t FLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint16_t DataLength)
{
  uint32_t i = 0;

  for (i = 0; (i < DataLength) && (*FlashAddress <= (USER_FLASH_END_ADDRESS-4)); i++)
  {
    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by word */
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, *FlashAddress, *(uint32_t*)(Data+i)) == HAL_OK)
    {
     /* Check the written value */
      if (*(uint32_t*)*FlashAddress != *(uint32_t*)(Data+i))
      {
        /* Flash content doesn't match SRAM content */
        return(2);
      }
      /* Increment FLASH destination address */
      *FlashAddress += 4;
    }
    else
    {
      /* Error occurred while writing data in Flash memory */
      return (1);
    }
  }

  return (0);
}
/*
 *
 */

uint32_t BootFLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint16_t DataLength, uint32_t TypeProgram)
{
  uint32_t i = 0;
  uint8_t	increment;

  increment = 1 << TypeProgram;

//FLASH_TYPEPROGRAM_WORD
  for (i = 0; (i < DataLength) && (*FlashAddress <= (BOOT_FLASH_END_ADDRESS-increment)); i++)
  {
    // Device voltage range supposed to be [2.7V to 3.6V], the operation will  be done by word
    if (HAL_FLASH_Program(TypeProgram, *FlashAddress, *(uint32_t*)(Data+i)) == HAL_OK)
    {
     // Check the written value
      if (*(uint32_t*)*FlashAddress != *(uint32_t*)(Data+i))
      {
        // Flash content doesn't match SRAM content
        return(2);
      }
      // Increment FLASH destination address
      *FlashAddress += increment;

    }
    else
    {
      // Error occurred while writing data in Flash memory
	  USART_TRACE_RED("BootFLASH_If_Write error\n");
      return (1);
    }
  }

  USART_TRACE_GREEN("BootFLASH_If_Write OK\n");
  return (0);
}
/***************************************************************************************
 * GetRunTimeStats
 *
 ***************************************************************************************/
void GetRunTimeStats( char *pcWriteBuffer )
{
UBaseType_t uxCurrentNumberOfTasks = uxTaskGetNumberOfTasks();

TaskStatus_t *pxTaskStatusArray;
volatile UBaseType_t uxArraySize, x;
uint32_t ulTotalTime, ulStatsAsPercentage;
uint32_t TotalTime;

	// Make sure the write buffer does not contain a string.
	*pcWriteBuffer = 0x00;

	// Take a snapshot of the number of tasks in case it changes while this	function is executing.
	uxArraySize = uxCurrentNumberOfTasks;

	// Allocate an array index for each task.
	pxTaskStatusArray = pvPortMalloc( uxCurrentNumberOfTasks * sizeof( TaskStatus_t ) );

	if( pxTaskStatusArray != NULL )
	{
		// Generate the (binary) data.
		uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, &ulTotalTime );

		TotalTime = ulTotalTime;
		// For percentage calculations.
		ulTotalTime /= 100UL;

		// Avoid divide by zero errors.
		if( ulTotalTime > 0 )
		{
			// Create a human readable table from the binary data.
			sprintf( pcWriteBuffer,"<table border=2 align=center>");
			pcWriteBuffer += strlen( pcWriteBuffer );
			sprintf( pcWriteBuffer,"<tr><th>задача</th><th>Свободно памяти, байт</th><th>Активность из:%u</th><th>Активность %%</th><th>Приоритет</th></tr>",(unsigned int)TotalTime);
			pcWriteBuffer += strlen( pcWriteBuffer );
			for( x = 0; x < uxArraySize; x++ )
			{
				ulStatsAsPercentage = pxTaskStatusArray[ x ].ulRunTimeCounter / ulTotalTime;

				if( ulStatsAsPercentage > 0UL )
				{
					sprintf( pcWriteBuffer, "<tr><td>%s </td><td>%u</td><td>%u</td><td>%u%%</td><td>%u</td></tr>", pxTaskStatusArray[ x ].pcTaskName,pxTaskStatusArray[ x ].usStackHighWaterMark, ( unsigned int ) pxTaskStatusArray[ x ].ulRunTimeCounter, ( unsigned int ) ulStatsAsPercentage,( unsigned int ) pxTaskStatusArray[ x ].uxBasePriority);
				}
				else
				{
					sprintf( pcWriteBuffer, "<tr><td>%s </td><td>%u</td><td>%u</td><td><1%%</td><td>%u</td></tr>", pxTaskStatusArray[ x ].pcTaskName,pxTaskStatusArray[ x ].usStackHighWaterMark, ( unsigned int ) pxTaskStatusArray[ x ].ulRunTimeCounter, ( unsigned int ) pxTaskStatusArray[ x ].uxBasePriority );

				}
				pcWriteBuffer += strlen( pcWriteBuffer );

			}
			sprintf( pcWriteBuffer,"</table>");	pcWriteBuffer += strlen( pcWriteBuffer );

		}
		else
		{
			mtCOVERAGE_TEST_MARKER();
		}

		// Free the array again.
		vPortFree( pxTaskStatusArray );
	}
	else
	{
		mtCOVERAGE_TEST_MARKER();
	}
}

/*
uint32_t BootFLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint16_t DataLength, uint32_t TypeProgram)
{
  uint32_t i = 0;

  for (i = 0; (i < DataLength) && (*FlashAddress <= (BOOT_FLASH_END_ADDRESS-4)); i++)
  {
    // Device voltage range supposed to be [2.7V to 3.6V], the operation will  be done by word
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, *FlashAddress, *(uint32_t*)(Data+i)) == HAL_OK)//FLASH_TYPEPROGRAM_WORD
    {
     // Check the written value
      if (*(uint32_t*)*FlashAddress != *(uint32_t*)(Data+i))
      {
        // Flash content doesn't match SRAM content
        return(2);
      }
      // Increment FLASH destination address
      *FlashAddress += 4;
    }
    else
    {
      // Error occurred while writing data in Flash memory
	  USART_TRACE_RED("BootFLASH_If_Write error\n");
      return (1);
    }
  }

  USART_TRACE_GREEN("BootFLASH_If_Write OK\n");
  return (0);
}
*/
