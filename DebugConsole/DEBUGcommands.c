
/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "queue.h"
#include "cmsis_os.h"

/* Standard includes. */
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "lwip/api.h"

#include "cmdinterpreter.h"


// ls - команда, отображающая список файлов и подкатологов, находящихся в конкретном каталоге
static BaseType_t prvlsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );

// reboot - перезапуск
static BaseType_t prvrebootCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );

// freemem - свободная память в куче Freertos
static BaseType_t prvfreememCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );

// Implements the run-time-stats command.
static BaseType_t prvTaskStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );

// Implements the task-stats command.
static BaseType_t prvRunTimeStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
//Implements the echo-three-parameters command.
static BaseType_t prvThreeParameterEchoCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
//Implements the echo-parameters command.
static BaseType_t prvParameterEchoCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
// Defines a command that prints out IP address information.
static BaseType_t prvDisplayIPConfig( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
//Defines a command that prints out the gathered demo debug stats.
static BaseType_t prvDisplayIPDebugStats( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );


/* Structure that defines the "ip-config" command line command. */
static const CLI_Command_Definition_t xIPConfig =
{
	"ip-config",
	"ip-config:\r\n Displays IP address configuration \r\n\r\n          ",
	prvDisplayIPConfig,
	0
};

/* Structure that defines the "ip-debug-stats" command line command. */
static const CLI_Command_Definition_t xIPDebugStats =
{
	"ip-debug-stats",
	"ip-debug-stats:\r\n Shows some IP stack stats useful for debug - an example only. \r\n\r\n",
	prvDisplayIPDebugStats,
	0
};

/* Structure that defines the "run-time-stats" command line command.   This generates a table that shows how much run time each task has */
static const CLI_Command_Definition_t xRunTimeStats =
{
	"runtime", /* The command string to type. */
	"runtime:\r\n сколько времени обработки использовал каждую задачу FreeRTOS \r\n\r\n",
	prvRunTimeStatsCommand, /* The function to run. */
	0 /* No parameters are expected. */
};


static const CLI_Command_Definition_t xls =
{
	"ls",
	"ls:\r\n  список файлов и подкатологов, находящихся в конкретном каталоге \r\n\r\n",
	prvlsCommand,
	0
};

static const CLI_Command_Definition_t xreboot =
{
	"reboot",
	"reboot:\r\n  перезапуск системы \r\n\r\n",
	prvrebootCommand,
	0
};

static const CLI_Command_Definition_t xFreeMem =
{
	"freemem",
	"freemem:\r\n читать свободную память в куче \r\n\r\n",
	prvfreememCommand,
	0
};
/* Structure that defines the "task-stats" command line command.  This generates a table that gives information on each task in the system. */
static const CLI_Command_Definition_t xTaskStats =
{
	"tasks",
	"tasks:\r\n Отображает таблицу, показывающую состояние каждой задачи \r\n\r\n",
	prvTaskStatsCommand,
	0
};

/* Structure that defines the "echo_3_parameters" command line command.  This takes exactly three parameters that the command simply echos back one at a time. */
static const CLI_Command_Definition_t xThreeParameterEcho =
{
	"echo-3-parameters",
	"echo-3-parameters <param1> <param2> <param3>:\r\n Expects three parameters, echos each in turn \r\n\r\n",
	prvThreeParameterEchoCommand,
	3
};

/* Structure that defines the "echo_parameters" command line command.  This
takes a variable number of parameters that the command simply echos back one at
a time. */
static const CLI_Command_Definition_t xParameterEcho =
{
	"echo-parameters",
	"echo-parameters <...>:\r\n Take variable number of parameters, echos each in turn \r\n\r\n",
	prvParameterEchoCommand,
	-1 /* The user can enter any number of commands. */
};

/*-----------------------------------------------------------*/

void vRegisterDEBUGCommands( void )
{
	// регистрируем команды консоли
	FreeRTOS_CLIRegisterCommand( &xls );					//отображающая список файлов и подкатологов, находящихся в конкретном каталоге
	FreeRTOS_CLIRegisterCommand( &xreboot );					//отображающая список файлов и подкатологов, находящихся в конкретном каталоге

	FreeRTOS_CLIRegisterCommand( &xFreeMem );
	FreeRTOS_CLIRegisterCommand( &xTaskStats );
	FreeRTOS_CLIRegisterCommand( &xRunTimeStats );
	FreeRTOS_CLIRegisterCommand( &xThreeParameterEcho );
	FreeRTOS_CLIRegisterCommand( &xParameterEcho );
	FreeRTOS_CLIRegisterCommand( &xIPDebugStats );
	FreeRTOS_CLIRegisterCommand( &xIPConfig );

}
/*-----------------------------------------------------------*/

static BaseType_t prvTaskStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
const char *const pcHeader = "Task          State  Priority  Stack	#\r\n\r\n";
	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	UBaseType_t fre;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );
	// в разделе STACK указан фактический используемый объем памяти задачи.(максимальная величина за время использования)
	vTaskList( pcWriteBuffer + strlen( pcHeader ) );

	return pdFALSE;
}
/*-----------------------------------------------------------*/
static BaseType_t prvDisplayIPDebugStats( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
	const char * const pcHeader = "prvDisplayIPDebugStats\r\n\r\n";
	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );

	return pdFALSE;
}
/*-----------------------------------------------------------*/

static BaseType_t prvRunTimeStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char * const pcHeader = "Task            Abs Time      % Time\r\n\r\n";

	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );
	vTaskGetRunTimeStats( pcWriteBuffer + strlen( pcHeader ) );

	return pdFALSE;
}
/*-----------------------------------------------------------*/
static BaseType_t prvlsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char * const pcHeader = "ls:\r\n\r\n";

	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );
	// тут читаем список файлов и передаём сюда

	return pdFALSE;
}
/*-----------------------------------------------------------*/
static BaseType_t prvrebootCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char * const pcHeader = "перезапуск...\r\n";

	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );

	return pdFALSE;
}

/*-----------------------------------------------------------*/
static BaseType_t prvfreememCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char * const pcHeader = "freemem:\r\n";

	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	strcpy( pcWriteBuffer, pcHeader );

	sprintf(  pcWriteBuffer + strlen( pcHeader ),"%u байт \r\n\r\n",xPortGetFreeHeapSize());

	return pdFALSE;
}


/*-----------------------------------------------------------*/

static BaseType_t prvThreeParameterEchoCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
const char *pcParameter;
BaseType_t xParameterStringLength, xReturn;
static BaseType_t lParameterNumber = 0;

	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	if( lParameterNumber == 0 )
	{
		/* The first time the function is called after the command has been
		entered just a header string is returned. */
		sprintf( pcWriteBuffer, "The three parameters were:\r\n" );

		/* Next time the function is called the first parameter will be echoed
		back. */
		lParameterNumber = 1L;

		/* There is more data to be returned as no parameters have been echoed
		back yet. */
		xReturn = pdPASS;
	}
	else
	{
		/* Obtain the parameter string. */
		pcParameter = FreeRTOS_CLIGetParameter
						(
							pcCommandString,		/* The command string itself. */
							lParameterNumber,		/* Return the next parameter. */
							&xParameterStringLength	/* Store the parameter string length. */
						);

		/* Sanity check something was returned. */
		configASSERT( pcParameter );

		/* Return the parameter string. */
		memset( pcWriteBuffer, 0x00, xWriteBufferLen );
		sprintf( pcWriteBuffer, "%d: ", ( int ) lParameterNumber );
		strncat( pcWriteBuffer, pcParameter, xParameterStringLength );
		strncat( pcWriteBuffer, "\r\n", strlen( "\r\n" ) );

		/* If this is the last of the three parameters then there are no more
		strings to return after this one. */
		if( lParameterNumber == 3L )
		{
			/* If this is the last of the three parameters then there are no more
			strings to return after this one. */
			xReturn = pdFALSE;
			lParameterNumber = 0L;
		}
		else
		{
			/* There are more parameters to return after this one. */
			xReturn = pdTRUE;
			lParameterNumber++;
		}
	}

	return xReturn;
}
/*-----------------------------------------------------------*/

static BaseType_t prvParameterEchoCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
const char *pcParameter;
BaseType_t xParameterStringLength, xReturn;
static BaseType_t lParameterNumber = 0;

	/* Remove compile time warnings about unused parameters, and check the
	write buffer is not NULL.  NOTE - for simplicity, this example assumes the
	write buffer length is adequate, so does not check for buffer overflows. */
	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	if( lParameterNumber == 0 )
	{
		/* The first time the function is called after the command has been
		entered just a header string is returned. */
		sprintf( pcWriteBuffer, "The parameters were:\r\n" );

		/* Next time the function is called the first parameter will be echoed
		back. */
		lParameterNumber = 1L;

		/* There is more data to be returned as no parameters have been echoed
		back yet. */
		xReturn = pdPASS;
	}
	else
	{
		/* Obtain the parameter string. */
		pcParameter = FreeRTOS_CLIGetParameter
						(
							pcCommandString,		/* The command string itself. */
							lParameterNumber,		/* Return the next parameter. */
							&xParameterStringLength	/* Store the parameter string length. */
						);

		if( pcParameter != NULL )
		{
			/* Return the parameter string. */
			memset( pcWriteBuffer, 0x00, xWriteBufferLen );
			sprintf( pcWriteBuffer, "%d: ", ( int ) lParameterNumber );
			strncat( pcWriteBuffer, pcParameter, xParameterStringLength );
			strncat( pcWriteBuffer, "\r\n", strlen( "\r\n" ) );

			/* There might be more parameters to return after this one. */
			xReturn = pdTRUE;
			lParameterNumber++;
		}
		else
		{
			/* No more parameters were found.  Make sure the write buffer does
			not contain a valid string. */
			pcWriteBuffer[ 0 ] = 0x00;

			/* No more data to return. */
			xReturn = pdFALSE;

			/* Start over the next time this command is executed. */
			lParameterNumber = 0;
		}
	}

	return xReturn;
}
/*-----------------------------------------------------------*/

static BaseType_t prvDisplayIPConfig( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
extern	struct netconn *conn;
static BaseType_t xIndex = 0;
BaseType_t xReturn;
uint32_t ulAddress;

	/* Remove compile time warnings about unused parameters, and check the
	write buffer is not NULL.  NOTE - for simplicity, this example assumes the
	write buffer length is adequate, so does not check for buffer overflows. */
	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	switch( xIndex )
	{
		case 0 :
//			FreeRTOS_GetAddressConfiguration( &ulAddress, NULL, NULL, NULL );
			netconn_getaddr(conn,&ulAddress,NULL,NULL);
			sprintf( pcWriteBuffer, "\r\nIP address " );
			xReturn = pdTRUE;
			xIndex++;
			break;

		case 1 :
//			FreeRTOS_GetAddressConfiguration( NULL, &ulAddress, NULL, NULL );
			sprintf( pcWriteBuffer, "\r\nNet mask " );
			xReturn = pdTRUE;
			xIndex++;
			break;

		case 2 :
//			FreeRTOS_GetAddressConfiguration( NULL, NULL, &ulAddress, NULL );
			sprintf( pcWriteBuffer, "\r\nGateway address " );
			xReturn = pdTRUE;
			xIndex++;
			break;

		case 3 :
//			FreeRTOS_GetAddressConfiguration( NULL, NULL, NULL, &ulAddress );
			sprintf( pcWriteBuffer, "\r\nDNS server address " );
			xReturn = pdTRUE;
			xIndex++;
			break;

		default :
			ulAddress = 0;
			sprintf( pcWriteBuffer, "\r\n\r\n" );
			xReturn = pdFALSE;
			xIndex = 0;
			break;
	}

	if( ulAddress != 0 )
	{
//		FreeRTOS_inet_ntoa( ulAddress,  &( pcWriteBuffer[ strlen( pcWriteBuffer ) ] ) );
	}

	return xReturn;
}
/*-----------------------------------------------------------*/
