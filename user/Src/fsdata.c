/*************************************************************************
 * �������� �������
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
//osMutexId xFileSystemStartMutex;		// ������� ������� � ������
//osMutexDef(xFileSystemStartMutex);

xQueueHandle 	FileSystemQueue;		// ������� ��� ������

/*************************************************************************
 * StartFSTask
 *
 * //osMutexRelease(xFileSystemStartMutex);	//���������
 *
 * � ���� ����� ���������� ����. ��������� 						_OneOscTmp,(uint8_t*)ucOscBlockBuf,0,0,FA_CREATE_ALWAYS | FA_WRITE
 * 1. ��� �����
 * 2. ��������� �� �����
 * 3. ������ ������ � ������
 * 4. ����� ������� � �����
 * 5. ��������� �� ������� ��� ����������, ����� ������ � ������.
 *
 * ����� ������ � ������ ����� ������������ ��������� ������� ��������,
 * �������� ��������� �� ������� ��������� ���� ������.
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
			USART_TRACE_Yellow("�������� � ���� '%s'. ������:%u\n",FSMessage.file,FSMessage.numb);

		}
	}

}
