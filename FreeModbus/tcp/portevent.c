/*
 * FreeModbus Libary: lwIP Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

/* ----------------------- System includes ----------------------------------*/
#include "assert.h"

/* ----------------------- lwIP ---------------------------------------------*/
#include "lwip/api.h"
#include "lwip/sys.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"

/* ----------------------- Defines ------------------------------------------*/
#define MB_POLL_CYCLETIME       100     /* Poll cycle time is 100ms */
/* ----------------------- Static variables ---------------------------------*/
static sys_mbox_t xMailBox = SYS_MBOX_NULL;
static eMBTCPEventType eMailBoxEvent;

/* ----------------------- Start implementation -----------------------------*/

/*************************************************************************
 * xMBPortEventInit
 *************************************************************************/
BOOL	xMBPortEventInit( void )
{
    eMailBoxEvent = EV_READY;
    if(sys_mbox_new(&xMailBox, TCPIP_MBOX_SIZE) != ERR_OK) {
      LWIP_ASSERT("failed to create tcpip_thread mbox",0);
      return	FALSE;
    }
    return TRUE;
}
/*************************************************************************
 * vMBPortEventClose освободим память очереди событий
 *************************************************************************/
void	vMBPortEventClose( void )
{
    if( xMailBox != SYS_MBOX_NULL )
    {
        sys_mbox_free( &xMailBox );
    }
}
/*************************************************************************
 * xMBPortEventPost
 *************************************************************************/
BOOL	xMBPortEventPost( eMBTCPEventType eEvent )
{
    eMailBoxEvent = eEvent;
    sys_mbox_post( &xMailBox, &eMailBoxEvent );
    return TRUE;
}
/*************************************************************************
 * xMBPortEventGet
 *************************************************************************/
BOOL	xMBPortEventGet( eMBTCPEventType * eEvent )
{
    void           *peMailBoxEvent;
    BOOL            xEventHappend = FALSE;
    u32_t           uiTimeSpent;

    uiTimeSpent = sys_arch_mbox_fetch( &xMailBox, &peMailBoxEvent, MB_POLL_CYCLETIME );
    if( uiTimeSpent != SYS_ARCH_TIMEOUT )
    {
        *eEvent = *( eMBTCPEventType * ) peMailBoxEvent;
        eMailBoxEvent = EV_READY;
        xEventHappend = TRUE;
    }
    return xEventHappend;
}
