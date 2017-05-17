
#ifndef DEBUG_CONSOLE_H
#define DEBUG_CONSOLE_H

/*
 * Создаём задачу, которая реализует консоль с помощью USART порта.
 */
//void DEBUGConsoleTask( void *pvParameters );
void DEBUGConsoleTask(void const * argument);
void DEBUGUSARTOUTTask(void const * argument);

void	xDEBUGRTUReceiveFSM( void );			// колбэк прерывания по приему
void	xDEBUGRTUTransmitFSM( void );			// колбэк прерывания по передаче

void vOutputString( const char * const pcMessage );
void vOutputTime (void);

#endif /* DEBUG_CONSOLE_H */



