/*************************************************************************
 * файловая система
*************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"

#include "fsdata.h" 
#include "stddef.h"

#include "filesystem.h"

/* Variables -----------------------------------------------------------------*/
//osMutexId xFileSystemStartMutex;		// мьютекс доступа к файлам
//osMutexDef(xFileSystemStartMutex);

xQueueHandle 	FileSystemQueue;		// очередь для файлов

/*************************************************************************
 * StartFSTask
 *
 * //osMutexRelease(xFileSystemStartMutex);	//разрешаем
 *
 * в таск будем передавать след. параметры 						_OneOscTmp,(uint8_t*)ucOscBlockBuf,0,0,FA_CREATE_ALWAYS | FA_WRITE
 * 1. имя файла
 * 2. указатель на буфер
 * 3. размер буфера в байтах
 * 4. режим доступа к файлу
 * 5. указатель на функцию для выполнения, после работы с файлом.
 *
 * после работы с файлом может понадобиться выполнить какието действия,
 * например прочитать из модбаса следующий блок данных.
 * osFileRW(
 *         IedServer self,
 *         DataObject* node,
 *         ControlHandler listener,
 *         void* parameter)
{
 *************************************************************************/
void StartFSTask(void const * argument){

	FSQueueMessage 	FSMessage;
	portBASE_TYPE 	xStatus;

	FileSystemQueue	= xQueueCreate( _FileSystemQueueSize, sizeof(FSQueueMessage));


	for(;;) {

		xStatus = xQueueReceive( FileSystemQueue, &(FSMessage), 0 );
		if( xStatus == pdPASS ){
			AddToFileMessageWord(FSMessage.file,FSMessage.Data,FSMessage.numb,0,FSMessage.mode);
			if (FSMessage.handler != NULL){
				FSMessage.handler(FSMessage.parameter);
			}
			USART_TRACE_Yellow("Записали в файл '%s'. размер:%u\n",FSMessage.file,FSMessage.numb);

		}
	}

}
