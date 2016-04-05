

/* Standard includes. */
#include "string.h"
#include "stdio.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

#include "main.h"
#include "DebugConsole.h"
#include "cmdinterpreter.h"
#include "usart.h"

// размер буфера команд в символах принятых из консоли
#define cmdMAX_INPUT_SIZE					20

// максимальное время для ожидания доступа мьютекса
#define cmdMAX_MUTEX_WAIT					( 200 / portTICK_RATE_MS )			// мс/portTICK_RATE_MS

/*-----------------------------------------------------------*/

// Задача, которая реализует обработку командной консоли.
//static void DEBUGConsoleTask( void *pvParameters );

/*-----------------------------------------------------------*/

// разблокировка задачи для приема новых данных (инфа приходит от обработчика прерываний)
static xSemaphoreHandle 	xNewDataSemaphore;

// защита доступа к аппаратноиу USART если он используется более одной задачей.
static xSemaphoreHandle 	xDEBUGbusMutex;		//xCDCMutex

/* Const messages output by the command console. */
static const char * const pcWelcomeMessage = "Режим отладки IEC61850.\r\n\r\n>";
static const char * const pcEndOfOutputMessage = "\r\nENTER\r\n>";
static const char * const pcNewLine = "\r\n";


UART_HandleTypeDef 	BOOT_UART;			//USART1

/*-----------------------------------------------------------*/

char cGetChar( void );

/*-----------------------------------------------------------*/

void DEBUGConsoleTask(void const * argument)//( void *pvParameters )
{
char 		cRxedChar;
uint8_t 	ucInputIndex = 0;
char 		*pcOutputString;					// указатель на выходной буфер
static char cInputString[ cmdMAX_INPUT_SIZE ], cLastInputString[ cmdMAX_INPUT_SIZE ];
BaseType_t 	xReturned;

//	( void ) pvParameters;

	// создадим семафоры и мьютексы используемые задачей
	xDEBUGbusMutex = xSemaphoreCreateMutex();			// блокировка доступа к USART
	vSemaphoreCreateBinary( xNewDataSemaphore );		// сигнал о принятии новых данных
	// проверим создались правильно или нет ?
	configASSERT( xDEBUGbusMutex );
	configASSERT( xNewDataSemaphore );

	// добавим семафоры и мьютексы в очередь для просмотра ЯДРОМ (стейтмашиной)
	//  API-функция vQueueAddToRegistry() не имеет другого предназначения, кроме как для целей отладки. Причем до-
	// бавлять в реестр следует только те очереди, поведение которых необходимо выяснить в ходе отладки.
	vQueueAddToRegistry( xDEBUGbusMutex, "DEBUGMu" );
	vQueueAddToRegistry( xNewDataSemaphore, "DEBUGDat" );


	// Получим адрес выходного буфера.
	pcOutputString = DEBUG_GetOutputBuffer();

	// Инит выходного драйвера
	BOOT_UART_Init(115200);

	// отправим привет
	HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)pcWelcomeMessage, strlen( pcWelcomeMessage ));

	for( ;; )
	{
		// обнулим счетчик принятых данных
		cRxedChar = 0;

		// читаем по одному принятому символу за раз
		cRxedChar = cGetChar();
		if( xSemaphoreTake( xDEBUGbusMutex, cmdMAX_MUTEX_WAIT ) == pdPASS )							// подождем семафор освобождения порта cmdMAX_MUTEX_WAIT время
		{
			// возвращаем ЭХО.
//			HAL_UART_Transmit(&BOOT_UART, (uint8_t *)&cRxedChar, 1, 0xFFFF);
			HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)&cRxedChar, 1);

			// Был ли это конец строки?
			if( cRxedChar == '\n' || cRxedChar == '\r' )
			{
				// Переводим каретку на следующую строку
//				HAL_UART_Transmit(&BOOT_UART, (uint8_t *)pcNewLine, strlen( pcNewLine ), 0xFFFF);
				HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)pcNewLine, strlen( pcNewLine ));

				//если команда пуста, то последняя команда должна быть выполнена повторно.
				if( ucInputIndex == 0 )
				{
					// Скопируем последнюю команду обратно в строку ввода.
					strcpy( cInputString, cLastInputString );
				}

				// прогоняем полученную команду через интерпретатора команд. Вызываем его многократно, пока он не вернёт pdFALSE
				// т.к. он может генерировать более одной строки.
				do
				{
					// получаем строку для вывода из интерпретатора команд.
					xReturned = DEBUG_ProcessCommand( cInputString, pcOutputString, BOOT_BUF_MAX_OUTPUT_SIZE );
					vTaskDelay( 1 );
					// передадим ответ в порт
					HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)pcOutputString, strlen( pcOutputString ));
					vTaskDelay( 10 );

				} while( xReturned != pdFALSE );

				// Очистить строку ввода для приема следующей команды. Запомним
				// команду, которая была, на случай если она должна быть
				// обрабатывается снова.
				strcpy( cLastInputString, cInputString );
				ucInputIndex = 0;
				memset( cInputString, 0x00, cmdMAX_INPUT_SIZE );

				HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)pcEndOfOutputMessage, strlen( pcEndOfOutputMessage ));

			}
			else
			{
				if( cRxedChar == '\r' )
				{
					// игнорируем символ
				}
				else if( cRxedChar == '\b' )
				{
					// Backspace - удаление последнего символа в командной строке
					if( ucInputIndex > 0 )
					{
						ucInputIndex--;
						cInputString[ ucInputIndex ] = '\0';
					}
				}
				else
				{
					// добавляем символ в строку введённую до этого. Если введена \n то команду отправляем на выполнение.
					if( ( cRxedChar >= ' ' ) && ( cRxedChar <= '~' ) )
					{
						if( ucInputIndex < cmdMAX_INPUT_SIZE )
						{
							cInputString[ ucInputIndex ] = cRxedChar;
							ucInputIndex++;
						}
					}
				}
			}

			// Вернём мьютекс.
			xSemaphoreGive( xDEBUGbusMutex );
		}
	}
}
/*-----------------------------------------------------------*/

void vOutputString( const char * const pcMessage )
{
	if( xSemaphoreTake( xDEBUGbusMutex, cmdMAX_MUTEX_WAIT ) == pdPASS )						// ждем семафор cmdMAX_MUTEX_WAIT иначе уходим
	{
//		HAL_UART_Transmit(&BOOT_UART, (uint8_t *)pcMessage, strlen( pcMessage ), 0xFFFF);
		HAL_UART_Transmit_DMA(&BOOT_UART, (uint8_t *)pcMessage, strlen( pcMessage ));
		xSemaphoreGive( xDEBUGbusMutex );													// вернём семафор
	}
}
/*-----------------------------------------------------------*/

char cGetChar( void )
{
uint8_t cInputChar;

	if( xSemaphoreTake( xDEBUGbusMutex, cmdMAX_MUTEX_WAIT ) == pdPASS )	{
		 HAL_UART_Receive_DMA(&BOOT_UART,&cInputChar,1);
		xSemaphoreGive( xDEBUGbusMutex );									// вернём

		xSemaphoreTake( xNewDataSemaphore, portMAX_DELAY );					// если не приняли ни одного байта, то захватываем семафор информирующий о приёме новых данных и ждем от прерывания инфы
	}

	return cInputChar;
}
/*-----------------------------------------------------------*/
// колбэк функция приёма данных из USART

/*************************************************************************
 * xMBMasterRTUReceiveFSM
 * приёмник данных из USART
 *************************************************************************/
void	xDEBUGRTUReceiveFSM( void ){

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		// проверим создались правильно или нет ?
		configASSERT( xNewDataSemaphore );

		// сигнализируем о новых данных принятых в порт
//		if( xNewDataSemaphore != NULL )
		xSemaphoreGiveFromISR( xNewDataSemaphore, &xHigherPriorityTaskWoken );										// отдаём семафор информирующий о приёме новых данных

		// pxHigherPriorityTaskWoken — так как «передача» семафора может привести к разблокированию таска,
		// ожидающего данных семафора имеющего большой приоритет, чем текущий таск, то нам необходимо выполнить
		// форсированное переключение контекста (для этого необходимо вызвать макрос taskYIELD()).
		if( xHigherPriorityTaskWoken == pdTRUE) 	taskYIELD();


}
/*************************************************************************
 * xDEBUGRTUTransmitFSM
 * колбэк передачи
 *************************************************************************/
void	xDEBUGRTUTransmitFSM( void ){

	taskYIELD();
}
/*-----------------------------------------------------------*/
