/*
 * tftpServer.c
 *
 *  Created on: 04.01.2018
 *      Author: sagok
 */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "port.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
//#include "stdbool.h"
#include "string.h"
#include "stdio.h"
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/tcp.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"

#include "vfs.h"

#include "ftpServer.h"
#include "httpServer.h"

//#include "tftputils.h"
#include "ff.h"
#include "stm32f4xx_hal.h"
#include <string.h>

#include "iso_server.h"
#include "iec61850_server.h"

#include "hal_socket.h"

/*************************************************************************
 * define
 *************************************************************************/
//#define EINVAL 1
//#define ENOMEM 2
//#define ENODEV 3

#define msg110 		"110 MARK %s = %s."
#define msg120 		"120 Service ready in nnn minutes."
#define msg125 		"125 Data connection already open; transfer starting."
#define msg150 		"150 File status okay; about to open data connection."
#define msg150recv 	"150 Opening BINARY mode data connection for %s (%i bytes)."
#define msg150stor 	"150 Opening BINARY mode data connection for %s."
#define msg200 		"200 Command okay."
#define msg202 		"202 Command not implemented, superfluous at this site."
#define msg211 		"211 System status, or system help reply."
#define msg212 		"212 Directory status."
#define msg213	 	"213 File status."
#define msg214 		"214 %s."
#define msg214SYST 	"214 %s system type."
#define msg220 		"220 FTP Server ready."
#define msg221 		"221 Goodbye."
#define msg225 		"225 Data connection open; no transfer in progress."
#define msg226 		"226 Closing data connection."
#define msg227 		"227 Entering Passive Mode (%i,%i,%i,%i,%i,%i)."
#define msg230 		"230 User logged in, proceed."
#define msg250 		"250 Requested file action okay, completed."
#define msg257PWD 	"257 \"%s\" is current directory."
#define msg257 		"257 \"%s\" created."
#define msg331 		"331 User name okay, need password."
#define msg332 		"332 Need account for login."
#define msg350 		"350 Requested file action pending further information."
#define msg421 		"421 Service not available, closing control connection."
#define msg425 		"425 Can't open data connection."
#define msg426 		"426 Connection closed; transfer aborted."
#define msg450 		"450 Requested file action not taken."
#define msg451 		"451 Requested action aborted: local error in processing."
#define msg452 		"452 Requested action not taken."
#define msg500 		"500 Syntax error, command unrecognized."
#define msg501 		"501 Syntax error in parameters or arguments."
#define msg502 		"502 Command not implemented."
#define msg503 		"503 Bad sequence of commands."
#define msg504 		"504 Command not implemented for that parameter."
#define msg530 		"530 Not logged in."
#define msg532 		"532 Need account for storing files."
#define msg550 		"550 Requested action not taken."
#define msg551 		"551 Requested action aborted: page type unknown."
#define msg552 		"552 Requested file action aborted."
#define msg553 		"553 Requested action not taken."

#define	SFIFO_MAX_BUFFER_SIZE	0x7fff

/** Copy IP address - faster than ip4_addr_set: no NULL check */
//#define ip4_addr_copy(dest, src) ((dest).addr = (src).addr)
//#define ip_2_ip4(ipaddr)   (&((ipaddr)->u_addr.ip4))
//#define IP_SET_TYPE_VAL(ipaddr, iptype) do { (ipaddr).type = (iptype); }while(0)
/*************************************************************************
 * struct
 *************************************************************************/
enum ftpd_state_e {
	FTPD_USER,
	FTPD_PASS,
	FTPD_IDLE,
	FTPD_NLST,
	FTPD_LIST,
	FTPD_RETR,
	FTPD_RNFR,
	FTPD_STOR,
	FTPD_QUIT,
	FTPD_REST
};

static const char *month_table[12] = {
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dez"
};

typedef int sfifo_atomic_t;

typedef struct sfifo_t
{
	char 			*buffer;
	int 			size;			/* Number of bytes */
	sfifo_atomic_t 	readpos;		/* Read position */
	sfifo_atomic_t 	writepos;		/* Write position */
} sfifo_t;

#define SFIFO_SIZEMASK(x)	((x)->size - 1)

#define sfifo_used(x)	(((x)->writepos - (x)->readpos) & SFIFO_SIZEMASK(x))
#define sfifo_space(x)	((x)->size - 1 - sfifo_used(x))

struct ip4_addr {
  u32_t addr;
};

struct ftpd_datastate {
	int 					connected;
	vfs_dir_t 				*vfs_dir;
	vfs_dirent_t 			*vfs_dirent;
	vfs_file_t 				*vfs_file;
	sfifo_t 				fifo;
	struct tcp_pcb 			*msgpcb;
	struct ftpd_msgstate 	*msgfs;
};

struct ftpd_msgstate {
	enum ftpd_state_e 		state;
	sfifo_t 				fifo;
	vfs_t 					*vfs;
	struct ip4_addr 		dataip;
	u16_t 					dataport;
	struct tcp_pcb 			*datapcb;
	struct ftpd_datastate 	*datafs;
	int 					passive;
	char 					*renamefrom;
};

#define ip_2_ip4(ipaddr)   (&((ipaddr)->addr))

/*************************************************************************
 * var
 *************************************************************************/
  Socket 	SocketSSH = NULL;
/*************************************************************************
 * extern
 *************************************************************************/
extern IedServer 	iedServer;
extern osMutexId 	xFTPStartMutex;				// мьютекс готовности к запуску FTP

/*************************************************************************
 * functions
 *************************************************************************/
static void send_msg(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm, char *msg, ...);

static void ftpd_msgclose(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm);

void ftp_server_serve(Socket self);

/*************************************************************************
 * Alloc buffer, init FIFO etc...
 *************************************************************************/
static int sfifo_init(sfifo_t *f, int size)
{
	memset(f, 0, sizeof(sfifo_t));

	if(size > SFIFO_MAX_BUFFER_SIZE)
		return -EINVAL;

	/*
	 * Set sufficient power-of-2 size.
	 *
	 * No, there's no bug. If you need
	 * room for N bytes, the buffer must
	 * be at least N+1 bytes. (The fifo
	 * can't tell 'empty' from 'full'
	 * without unsafe index manipulations
	 * otherwise.)
	 */
	f->size = 1;
	for(; f->size <= size; f->size <<= 1)
		;

	/* Get buffer */
	if( 0 == (f->buffer = (void *)malloc(f->size)) )
		return -ENOMEM;

	return 0;
}
/*************************************************************************
 * Dealloc buffer etc...
 *************************************************************************/
static void sfifo_close(sfifo_t *f)
{
	if(f->buffer)
		free(f->buffer);
}
/*************************************************************************
 * Write bytes to a FIFO
 * Return number of bytes written, or an error code
 *************************************************************************/

static int sfifo_write(sfifo_t *f, const void *_buf, int len)
{
	int total;
	int i;
	const char *buf = (const char *)_buf;

	if(!f->buffer)
		return -ENODEV;	/* No buffer! */

	/* total = len = min(space, len) */
	total = sfifo_space(f);
//	USART_TRACE("sfifo_space() = %d\n",total);
	if(len > total)
		len = total;
	else
		total = len;

	i = f->writepos;
	if(i + len > f->size)
	{
		memcpy(f->buffer + i, buf, f->size - i);
		buf += f->size - i;
		len -= f->size - i;
		i = 0;
	}
	memcpy(f->buffer + i, buf, len);
	f->writepos = i + len;

	return total;
}
// -----------------------------------------------
static void ftpd_dataerr(void *arg, err_t err)
{
	struct ftpd_datastate *fsd = arg;

	USART_TRACE("ftpd_dataerr: %s (%i)\n", lwip_strerr(err), err);

	if (fsd == NULL) return;

	fsd->msgfs->datafs = NULL;
	fsd->msgfs->state = FTPD_IDLE;
	free(fsd);
}
// -----------------------------------------------
static void ftpd_dataclose(struct tcp_pcb *pcb, struct ftpd_datastate *fsd)
{
	tcp_arg(pcb, NULL);
	tcp_sent(pcb, NULL);
	tcp_recv(pcb, NULL);
	fsd->msgfs->datafs = NULL;
	sfifo_close(&fsd->fifo);
	free(fsd);
	tcp_arg(pcb, NULL);
	tcp_close(pcb);
}
/*************************************************************************
 * send_data
 *************************************************************************/
static void send_data(struct tcp_pcb *pcb, struct ftpd_datastate *fsd)
{
	err_t err;
	u16_t len;

	if (sfifo_used(&fsd->fifo) > 0) {
		int i;

		/* We cannot send more data than space available in the send buffer. */
		if (tcp_sndbuf(pcb) < sfifo_used(&fsd->fifo)) {
			len = tcp_sndbuf(pcb);
		} else {
			len = (u16_t) sfifo_used(&fsd->fifo);
		}

		i = fsd->fifo.readpos;
		if ((i + len) > fsd->fifo.size) {
			err = tcp_write(pcb, fsd->fifo.buffer + i, (u16_t)(fsd->fifo.size - i), 1);
			if (err != ERR_OK) {
				USART_TRACE("send_data: error writing!\n");
				return;
			}
			len -= fsd->fifo.size - i;
			fsd->fifo.readpos = 0;
			i = 0;
		}

		err = tcp_write(pcb, fsd->fifo.buffer + i, len, 1);
		if (err != ERR_OK) {
			USART_TRACE("send_data: error writing!\n");
			return;
		}
		fsd->fifo.readpos += len;
	}
}
/*************************************************************************
 * send_file
 *************************************************************************/
static void send_file(struct ftpd_datastate *fsd, struct tcp_pcb *pcb)
{
	if (!fsd->connected)
		return;

	if (fsd->vfs_file) {
		char buffer[2048];
		int len;

		len = sfifo_space(&fsd->fifo);
		if (len == 0) {
			send_data(pcb, fsd);
			return;
		}
		if (len > 2048)
			len = 2048;
		len = vfs_read(buffer, 1, len, fsd->vfs_file);
		if (len == 0) {
			if (vfs_eof(fsd->vfs_file) == 0)
				return;
			vfs_close(fsd->vfs_file);
			fsd->vfs_file = NULL;
			return;
		}
		sfifo_write(&fsd->fifo, buffer, len);
		send_data(pcb, fsd);
	} else {
		struct ftpd_msgstate *fsm;
		struct tcp_pcb *msgpcb;

		if (sfifo_used(&fsd->fifo) > 0) {
			send_data(pcb, fsd);
			return;
		}
		fsm = fsd->msgfs;
		msgpcb = fsd->msgpcb;

		ftpd_dataclose(pcb, fsd);
		fsm->datapcb 	= NULL;
		fsm->datafs 	= NULL;
		fsm->state 		= FTPD_IDLE;
		send_msg(msgpcb, fsm, msg226);
		return;
	}
}
/*************************************************************************
 * send_next_directory
 *************************************************************************/
static void send_next_directory(struct ftpd_datastate *fsd, struct tcp_pcb *pcb, int shortlist)
{
	char buffer[1024];
	int len;

	while (1) {
	if (fsd->vfs_dirent == NULL)
		fsd->vfs_dirent = vfs_readdir(fsd->vfs_dir);

	if (fsd->vfs_dirent) {
		if (shortlist) {
			len = sprintf(buffer, "%s\r\n", fsd->vfs_dirent->name);
			if (sfifo_space(&fsd->fifo) < len) {
				send_data(pcb, fsd);
				return;
			}
			sfifo_write(&fsd->fifo, buffer, len);
			fsd->vfs_dirent = NULL;
		} else {
			vfs_stat_t st;
			time_t current_time;
			int current_year;
			struct tm *s_time;

			time(&current_time);
			s_time = gmtime(&current_time);
			current_year = s_time->tm_year;

			vfs_stat(fsd->msgfs->vfs, fsd->vfs_dirent->name, &st);
			s_time = gmtime(&st.st_mtime);
			if (s_time->tm_year == current_year)
				len = sprintf(buffer, "-rw-rw-rw-   1 user     ftp  %11ld %s %02i %02i:%02i %s\r\n", st.st_size, month_table[s_time->tm_mon], s_time->tm_mday, s_time->tm_hour, s_time->tm_min, fsd->vfs_dirent->name);
			else
				len = sprintf(buffer, "-rw-rw-rw-   1 user     ftp  %11ld %s %02i %5i %s\r\n", st.st_size, month_table[s_time->tm_mon], s_time->tm_mday, s_time->tm_year + 1900, fsd->vfs_dirent->name);
			if (VFS_ISDIR(st.st_mode))
				buffer[0] = 'd';
			if (sfifo_space(&fsd->fifo) < len) {
				send_data(pcb, fsd);
				return;
			}
			sfifo_write(&fsd->fifo, buffer, len);
			fsd->vfs_dirent = NULL;
		}
	} else {
		struct ftpd_msgstate *fsm;
		struct tcp_pcb *msgpcb;

		if (sfifo_used(&fsd->fifo) > 0) {
			send_data(pcb, fsd);
			return;
		}
		fsm = fsd->msgfs;
		msgpcb = fsd->msgpcb;

		vfs_closedir(fsd->vfs_dir);
		fsd->vfs_dir = NULL;
		ftpd_dataclose(pcb, fsd);
		fsm->datapcb = NULL;
		fsm->datafs = NULL;
		fsm->state = FTPD_IDLE;
		send_msg(msgpcb, fsm, msg226);
		return;
	}
	}
}
/*************************************************************************
 * ftpd_datasent
 *************************************************************************/
static err_t ftpd_datasent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	struct ftpd_datastate *fsd = arg;

	switch (fsd->msgfs->state) {
	case FTPD_LIST:
		send_next_directory(fsd, pcb, 0);
		break;
	case FTPD_NLST:
		send_next_directory(fsd, pcb, 1);
		break;
	case FTPD_RETR:
		send_file(fsd, pcb);
		break;
	default:
		break;
	}

	return ERR_OK;
}
/*************************************************************************
 * ftpd_datarecv
 *************************************************************************/
static err_t ftpd_datarecv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	struct ftpd_datastate *fsd = arg;

	if (err == ERR_OK && p != NULL) {
		struct pbuf *q;
		u16_t tot_len = 0;

		for (q = p; q != NULL; q = q->next) {
			int len;

			len = vfs_write(q->payload, 1, q->len, fsd->vfs_file);
			tot_len += len;
			if (len != q->len)
				break;
		}

		/* Inform TCP that we have taken the data. */
		tcp_recved(pcb, tot_len);

		pbuf_free(p);
	}
	if (err == ERR_OK && p == NULL) {
		struct ftpd_msgstate *fsm;
		struct tcp_pcb *msgpcb;

		fsm = fsd->msgfs;
		msgpcb = fsd->msgpcb;

		vfs_close(fsd->vfs_file);
		fsd->vfs_file = NULL;
		ftpd_dataclose(pcb, fsd);
		fsm->datapcb = NULL;
		fsm->datafs = NULL;
		fsm->state = FTPD_IDLE;
		send_msg(msgpcb, fsm, msg226);
	}

	return ERR_OK;
}
/*************************************************************************
 * ftpd_dataconnected
 *************************************************************************/
static err_t ftpd_dataconnected(void *arg, struct tcp_pcb *pcb, err_t err)
{
	struct ftpd_datastate *fsd = arg;

	fsd->msgfs->datapcb = pcb;
	fsd->connected = 1;

	/* Tell TCP that we wish to be informed of incoming data by a call to the http_recv() function. */
	tcp_recv(pcb, ftpd_datarecv);

	/* Tell TCP that we wish be to informed of data that has been successfully sent by a call to the ftpd_sent() function. */
	tcp_sent(pcb, ftpd_datasent);

	tcp_err(pcb, ftpd_dataerr);

	switch (fsd->msgfs->state) {
	case FTPD_LIST:
		send_next_directory(fsd, pcb, 0);
		break;
	case FTPD_NLST:
		send_next_directory(fsd, pcb, 1);
		break;
	case FTPD_RETR:
		send_file(fsd, pcb);
		break;
	default:
		break;
	}

	return ERR_OK;
}
/*************************************************************************
 * ftpd_dataaccept
 *************************************************************************/
static err_t ftpd_dataaccept(void *arg, struct tcp_pcb *pcb, err_t err)
{
	struct ftpd_datastate *fsd = arg;

	fsd->msgfs->datapcb = pcb;
	fsd->connected = 1;

//	memcpy(fsd->vfs_dirent->name,SPIFLASHDISKPath,3);

	/* Tell TCP that we wish to be informed of incoming data by a call to the http_recv() function. */
	tcp_recv(pcb, ftpd_datarecv);

	/* Tell TCP that we wish be to informed of data that has been successfully sent by a call to the ftpd_sent() function. */
	tcp_sent(pcb, ftpd_datasent);

	tcp_err(pcb, ftpd_dataerr);

	switch (fsd->msgfs->state) {
	case FTPD_LIST:
		send_next_directory(fsd, pcb, 0);
		break;
	case FTPD_NLST:
		send_next_directory(fsd, pcb, 1);
		break;
	case FTPD_RETR:
		send_file(fsd, pcb);
		break;
	default:
		break;
	}

	return ERR_OK;
}
/*************************************************************************
 * open_dataconnection
 * создаём соединение на другой порт с клиентом для передачи данных
 *************************************************************************/
static int open_dataconnection(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (fsm->passive)	return 0;

	/* Allocate memory for the structure that holds the state of the connection. */
	fsm->datafs = malloc(sizeof(struct ftpd_datastate));

	if (fsm->datafs == NULL) {
		send_msg(pcb, fsm, msg451);
		return 1;
	}
	memset(fsm->datafs, 0, sizeof(struct ftpd_datastate));
	fsm->datafs->msgfs = fsm;
	fsm->datafs->msgpcb = pcb;
	sfifo_init(&fsm->datafs->fifo, 2000);

	fsm->datapcb = tcp_new();
	/* Tell TCP that this is the structure we wish to be passed for our callbacks. */
	tcp_arg(fsm->datapcb, fsm->datafs);

	ip_addr_t dataip;									// IP адалённой машины

	//IP_SET_TYPE_VAL(dataip, IPADDR_TYPE_V4);			// установим V4 соединение
	//ip4_addr_copy(*ip_2_ip4(&dataip), fsm->dataip);	// скопируем IP клиента для соединения

	dataip.addr = fsm->dataip.addr;

	tcp_connect(fsm->datapcb, &dataip, fsm->dataport, ftpd_dataconnected);

	return 0;
}
/*************************************************************************
 * cmd_size
 *************************************************************************/
static void cmd_size(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
/*
	vfs_stat_t st;
	vfs_stat(fsm->vfs, arg, &st);
	if (!VFS_ISREG(st.st_mode)) {
		send_msg(pcb, fsm, msg150recv, st.st_size,sizeof(st.st_size));
		return;
	}
*/
	send_msg(pcb, fsm, msg550);
}


/*************************************************************************
 * cmd_user
 *************************************************************************/
static void cmd_user(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg331);
	fsm->state = FTPD_PASS;
	/*
	   send_msg(pcb, fs, msgLoginFailed);
	   fs->state = FTPD_QUIT;
	 */
}
/*************************************************************************
 * cmd_pass
 *************************************************************************/
static void cmd_pass(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg230);
	fsm->state = FTPD_IDLE;
	/*
	   send_msg(pcb, fs, msgLoginFailed);
	   fs->state = FTPD_QUIT;
	 */
}
/*************************************************************************
 * cmd_port
 *************************************************************************/
static void cmd_port(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	int nr;
	unsigned pHi, pLo;
	unsigned ip[4];

	nr = sscanf(arg, "%u,%u,%u,%u,%u,%u", &(ip[0]), &(ip[1]), &(ip[2]), &(ip[3]), &pHi, &pLo);
	if (nr != 6) {
		send_msg(pcb, fsm, msg501);
	} else {
		IP4_ADDR(&fsm->dataip, (u8_t) ip[0], (u8_t) ip[1], (u8_t) ip[2], (u8_t) ip[3]);
		fsm->dataport = ((u16_t) pHi << 8) | (u16_t) pLo;
		send_msg(pcb, fsm, msg200);
	}
}
/*************************************************************************
 * cmd_quit
 *************************************************************************/
static void cmd_restart(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg221);
	fsm->state = FTPD_REST;
}
/*************************************************************************
 * cmd_quit
 *************************************************************************/
static void cmd_quit(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg221);
	fsm->state = FTPD_QUIT;
//	ftpd_msgclose(pcb,fsm);
}
/*************************************************************************
 * cmd_cwd
 *************************************************************************/
static void cmd_cwd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (!vfs_chdir(fsm->vfs, arg)) {
		send_msg(pcb, fsm, msg250);
	} else {
		send_msg(pcb, fsm, msg550);
	}
}
/*************************************************************************
 * cmd_cdup
 *************************************************************************/
static void cmd_cdup(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (!vfs_chdir(fsm->vfs, "..")) {
		send_msg(pcb, fsm, msg250);
	} else {
		send_msg(pcb, fsm, msg550);
	}
}
/*************************************************************************
 * cmd_pwd
 *************************************************************************/
static void cmd_pwd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	char *path;

	if ((path = vfs_getcwd(fsm->vfs, NULL, 0))) {
		send_msg(pcb, fsm, msg257PWD, path);
		free(path);
	}
}
/*************************************************************************
 * cmd_list_common
 *************************************************************************/
static void cmd_list_common(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm, int shortlist)
{
	vfs_dir_t *vfs_dir;
	char *cwd;

	cwd = vfs_getcwd(fsm->vfs, NULL, 0);
	if ((!cwd)) {
		send_msg(pcb, fsm, msg451);
		return;
	}
	vfs_dir = vfs_opendir(fsm->vfs, cwd);
	free(cwd);
	if (!vfs_dir) {
		send_msg(pcb, fsm, msg451);
		return;
	}

	if (open_dataconnection(pcb, fsm) != 0) {
		vfs_closedir(vfs_dir);
		return;
	}

	fsm->datafs->vfs_dir = vfs_dir;
	fsm->datafs->vfs_dirent = NULL;
	if (shortlist != 0)
		fsm->state = FTPD_NLST;
	else
		fsm->state = FTPD_LIST;

	send_msg(pcb, fsm, msg150);
}
/*************************************************************************
 * cmd_nlst / cmd_list
 *************************************************************************/
static void cmd_nlst(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	cmd_list_common(arg, pcb, fsm, 1);
}
static void cmd_list(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	cmd_list_common(arg, pcb, fsm, 0);
}
/*************************************************************************
 * cmd_retr
 * команда чтения
 *************************************************************************/
static void cmd_retr(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	vfs_file_t *vfs_file;
	vfs_stat_t st;

	vfs_stat(fsm->vfs, arg, &st);
	if (!VFS_ISREG(st.st_mode)) {
		send_msg(pcb, fsm, msg550);
		return;
	}
	vfs_file = vfs_open(fsm->vfs, arg, "rb");
	if (!vfs_file) {
		send_msg(pcb, fsm, msg550);
		return;
	}

	send_msg(pcb, fsm, msg150recv, arg, st.st_size);

	if (open_dataconnection(pcb, fsm) != 0) {
		vfs_close(vfs_file);
		return;
	}

	fsm->datafs->vfs_file = vfs_file;
	fsm->state = FTPD_RETR;
}
/*************************************************************************
 * cmd_stor
 * сохраняем файл
 *************************************************************************/
static void cmd_stor(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	vfs_file_t *vfs_file;

	vfs_file = vfs_open(fsm->vfs, arg, "wb");
	if (!vfs_file) {
		send_msg(pcb, fsm, msg550);
		return;
	}

	send_msg(pcb, fsm, msg150stor, arg);

	if (open_dataconnection(pcb, fsm) != 0) {
		vfs_close(vfs_file);
		return;
	}

	fsm->datafs->vfs_file = vfs_file;
	fsm->state = FTPD_STOR;
}
/*************************************************************************
 * cmd_noop / cmd_syst
 *************************************************************************/
static void cmd_noop(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg200);
}

static void cmd_syst(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	send_msg(pcb, fsm, msg214SYST, "UNIX");
}
/*************************************************************************
 * cmd_pasv
 *************************************************************************/
static void cmd_pasv(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	static u16_t port = 4096;
	static u16_t start_port = 4096;
	struct tcp_pcb *temppcb;

	/* Allocate memory for the structure that holds the state of the
	   connection. */
	fsm->datafs = malloc(sizeof(struct ftpd_datastate));

	if (fsm->datafs == NULL) {
		send_msg(pcb, fsm, msg451);
		return;
	}
	memset(fsm->datafs, 0, sizeof(struct ftpd_datastate));

	fsm->datapcb = tcp_new();
	if (!fsm->datapcb) {
		free(fsm->datafs);
		send_msg(pcb, fsm, msg451);
		return;
	}

	sfifo_init(&fsm->datafs->fifo, 2000);

	start_port = port;

	while (1) {
		err_t err;

		if(++port > 0x7fff)
			port = 4096;

		fsm->dataport = port;
		err = tcp_bind(fsm->datapcb, (ip_addr_t*)&pcb->local_ip, fsm->dataport);
		if (err == ERR_OK)
			break;
		if (start_port == port)
			err = ERR_CLSD;
		if (err == ERR_USE) {
			continue;
		} else {
			ftpd_dataclose(fsm->datapcb, fsm->datafs);
			fsm->datapcb = NULL;
			fsm->datafs = NULL;
			return;
		}
	}

	fsm->datafs->msgfs = fsm;

	temppcb = tcp_listen(fsm->datapcb);
	if (!temppcb) {
		ftpd_dataclose(fsm->datapcb, fsm->datafs);
		fsm->datapcb = NULL;
		fsm->datafs = NULL;
		return;
	}
	fsm->datapcb = temppcb;

	fsm->passive = 1;
	fsm->datafs->connected = 0;
	fsm->datafs->msgpcb = pcb;

	/* Tell TCP that this is the structure we wish to be passed for our
	   callbacks. */
	tcp_arg(fsm->datapcb, fsm->datafs);

	tcp_accept(fsm->datapcb, ftpd_dataaccept);
	send_msg(pcb, fsm, msg227,
			ip4_addr1(ip_2_ip4(&pcb->local_ip)),
			ip4_addr2(ip_2_ip4(&pcb->local_ip)),
			ip4_addr3(ip_2_ip4(&pcb->local_ip)),
			ip4_addr4(ip_2_ip4(&pcb->local_ip)),
			(fsm->dataport >> 8) & 0xff,
			(fsm->dataport) & 0xff);
}
/*************************************************************************
 * cmd_abrt / cmd_type
 *************************************************************************/
static void cmd_abrt(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (fsm->datafs != NULL) {
		tcp_arg(fsm->datapcb, NULL);
		tcp_sent(fsm->datapcb, NULL);
		tcp_recv(fsm->datapcb, NULL);
		tcp_arg(fsm->datapcb, NULL);
		tcp_abort(pcb);
		sfifo_close(&fsm->datafs->fifo);
		free(fsm->datafs);
		fsm->datafs = NULL;
	}
	fsm->state = FTPD_IDLE;
}

static void cmd_type(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	USART_TRACE("Got TYPE -%s-\n", arg);

	if(strcmp(arg, "I") != 0) {
		send_msg(pcb, fsm, msg502);
		return;
	}
	send_msg(pcb, fsm, msg200);
}
/*************************************************************************
 * cmd_mode
 *************************************************************************/
static void cmd_mode(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	USART_TRACE("Got MODE -%s-\n", arg);
	send_msg(pcb, fsm, msg502);
}
/*************************************************************************
 * cmd_rnfr
 *************************************************************************/
static void cmd_rnfr(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (arg == NULL) {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (*arg == '\0') {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (fsm->renamefrom)
		free(fsm->renamefrom);
	fsm->renamefrom = malloc(strlen(arg) + 1);
	if (fsm->renamefrom == NULL) {
		send_msg(pcb, fsm, msg451);
		return;
	}
	strcpy(fsm->renamefrom, arg);
	fsm->state = FTPD_RNFR;
	send_msg(pcb, fsm, msg350);
}
/*************************************************************************
 * cmd_rnto
 *************************************************************************/
static void cmd_rnto(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (fsm->state != FTPD_RNFR) {
		send_msg(pcb, fsm, msg503);
		return;
	}
	fsm->state = FTPD_IDLE;
	if (arg == NULL) {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (*arg == '\0') {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (vfs_rename(fsm->vfs, fsm->renamefrom, arg)) {
		send_msg(pcb, fsm, msg450);
	} else {
		send_msg(pcb, fsm, msg250);
	}
}
/*************************************************************************
 * cmd_mkd
 *************************************************************************/
static void cmd_mkd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	if (arg == NULL) {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (*arg == '\0') {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (vfs_mkdir(fsm->vfs, arg, VFS_IRWXU | VFS_IRWXG | VFS_IRWXO) != 0) {
		send_msg(pcb, fsm, msg550);
	} else {
		send_msg(pcb, fsm, msg257, arg);
	}
}
/*************************************************************************
 * cmd_rmd
 *************************************************************************/
static void cmd_rmd(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	vfs_stat_t st;

	if (arg == NULL) {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (*arg == '\0') {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (vfs_stat(fsm->vfs, arg, &st) != 0) {
		send_msg(pcb, fsm, msg550);
		return;
	}
	if (!VFS_ISDIR(st.st_mode)) {
		send_msg(pcb, fsm, msg550);
		return;
	}
	if (vfs_rmdir(fsm->vfs, arg) != 0) {
		send_msg(pcb, fsm, msg550);
	} else {
		send_msg(pcb, fsm, msg250);
	}
}
/*************************************************************************
 * cmd_dele
 *************************************************************************/
static void cmd_dele(const char *arg, struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	vfs_stat_t st;

	if (arg == NULL) {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (*arg == '\0') {
		send_msg(pcb, fsm, msg501);
		return;
	}
	if (vfs_stat(fsm->vfs, arg, &st) != 0) {
		send_msg(pcb, fsm, msg550);
		return;
	}
	if (!VFS_ISREG(st.st_mode)) {
		send_msg(pcb, fsm, msg550);
		return;
	}
	if (vfs_remove(fsm->vfs, arg) != 0) {
		send_msg(pcb, fsm, msg550);
	} else {
		send_msg(pcb, fsm, msg250);
	}
}
/*************************************************************************
 *
 *************************************************************************/
struct ftpd_command {
	char *cmd;
	void (*func) (const char *arg, struct tcp_pcb * pcb, struct ftpd_msgstate * fsm);
};

static struct ftpd_command ftpd_commands[] = {
	{"USER", cmd_user},		// +Имя пользователя для входа на сервер.
	{"PASS", cmd_pass},		// +Пароль.
	{"PORT", cmd_port},		// +Войти в активный режим. Например PORT 12,34,45,56,78,89. В отличие от пассивного режима для передачи данных сервер сам подключается к клиенту.
	{"QUIT", cmd_quit},		// +Отключиться.
	{"CWD",  cmd_cwd},		// +Сменить директорию.
	{"CDUP", cmd_cdup},		// +Сменить директорию на вышестоящую.
	{"PWD",  cmd_pwd},		// +Возвращает текущую директорию.
	{"XPWD", cmd_pwd},		// +Возвращает текущую директорию.
	{"NLST", cmd_nlst},		// +Возвращает список файлов директории в более кратком формате, чем LIST. Список передаётся через соединение данных.
	{"LIST", cmd_list},		// +Возвращает список файлов директории. Список передаётся через соединение данных.
	{"RETR", cmd_retr},		// +Скачать файл. Перед RETR должна быть команда PASV или PORT.
	{"STOR", cmd_stor},		// +Закачать файл. Перед STOR должна быть команда PASV или PORT.
	{"NOOP", cmd_noop},		// +Пустая операция.
	{"SYST", cmd_syst},		// +Возвращает тип системы (UNIX, WIN, …).
	{"ABOR", cmd_abrt},		// Прервать передачу файла
	{"TYPE", cmd_type},		// Установить тип передачи файла (бинарный, текстовый).
	{"MODE", cmd_mode},
	{"RNFR", cmd_rnfr},		// Переименовать файл. RNFR — что переименовывать, RNTO — во что.
	{"RNTO", cmd_rnto},		// Переименовать файл. RNFR — что переименовывать, RNTO — во что.
	{"MKD",  cmd_mkd},		// Создать директорию.
	{"XMKD", cmd_mkd},
	{"RMD",  cmd_rmd},		// Удалить директорию.
	{"XRMD", cmd_rmd},
	{"DELE", cmd_dele},		// Удалить файл (DELE filename).
	{"PASV", cmd_pasv},		// Войти в пассивный режим. Сервер вернёт адрес и порт, к которому нужно подключиться, чтобы забрать данные. Передача начнётся при введении следующих команд: RETR, LIST и т. д.
	{"SIZE", cmd_size},		// Возвращает размер файла.
	{"REST", cmd_restart},// перезапуск модели
	{NULL, NULL}
};

/*************************************************************************
 * send_msgdata
 *************************************************************************/
static void send_msgdata(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	err_t err;
	u16_t len;

	if (sfifo_used(&fsm->fifo) > 0) {
		int i;

		/* We cannot send more data than space available in the send
		   buffer. */
		if (tcp_sndbuf(pcb) < sfifo_used(&fsm->fifo)) {
			len = tcp_sndbuf(pcb);
		} else {
			len = (u16_t) sfifo_used(&fsm->fifo);
		}

		i = fsm->fifo.readpos;
		if ((i + len) > fsm->fifo.size) {
			err = tcp_write(pcb, fsm->fifo.buffer + i, (u16_t)(fsm->fifo.size - i), 1);
			if (err != ERR_OK) {
				USART_TRACE("send_msgdata: error writing!\n");
				return;
			}
			len -= fsm->fifo.size - i;
			fsm->fifo.readpos = 0;
			i = 0;
		}

		err = tcp_write(pcb, fsm->fifo.buffer + i, len, 1);
		if (err != ERR_OK) {
			USART_TRACE("send_msgdata: error writing!\n");
			return;
		}
		fsm->fifo.readpos += len;
	}
}
/*************************************************************************
 * send_msg
 *************************************************************************/
static void send_msg(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm, char *msg, ...)
{
	va_list arg;
	char buffer[1024];
	int len;

	va_start(arg, msg);
	vsprintf(buffer, msg, arg);
	va_end(arg);
	strcat(buffer, "\r\n");
	len = strlen(buffer);
	if (sfifo_space(&fsm->fifo) < len)
		return;
	sfifo_write(&fsm->fifo, buffer, len);
	USART_TRACE("ответ: %s", buffer);
	send_msgdata(pcb, fsm);
}
/*************************************************************************
 * ftpd_msgerr
 *************************************************************************/
static void ftpd_msgerr(void *arg, err_t err)
{
	struct ftpd_msgstate *fsm = arg;

	USART_TRACE("ftpd_msgerr: %s (%i)\n", lwip_strerr(err), err);
	if (fsm == NULL)		return;
	if (fsm->datafs)		ftpd_dataclose(fsm->datapcb, fsm->datafs);
	sfifo_close(&fsm->fifo);
	vfs_close(fsm->vfs);
	fsm->vfs = NULL;
	if (fsm->renamefrom)	free(fsm->renamefrom);
	fsm->renamefrom = NULL;
	free(fsm);
}
/*************************************************************************
 * ftpd_msgclose
 *************************************************************************/
static void ftpd_msgclose(struct tcp_pcb *pcb, struct ftpd_msgstate *fsm)
{
	tcp_arg(pcb, NULL);
	tcp_sent(pcb, NULL);
	tcp_recv(pcb, NULL);
	if (fsm->datafs)			ftpd_dataclose(fsm->datapcb, fsm->datafs);
	sfifo_close(&fsm->fifo);
	vfs_close(fsm->vfs);
	fsm->vfs = NULL;
	if (fsm->renamefrom)		free(fsm->renamefrom);
	fsm->renamefrom = NULL;
	free(fsm);
	tcp_arg(pcb, NULL);
	tcp_close(pcb);

	USART_TRACE("ftpd_msgclose. (tcp_close)\n");

}
/*************************************************************************
 * ftpd_msgsent
 *************************************************************************/
static err_t ftpd_msgsent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	struct ftpd_msgstate *fsm = arg;

	if ((sfifo_used(&fsm->fifo) == 0) && (fsm->state == FTPD_QUIT)) {
		ftpd_msgclose(pcb, fsm);
		return ERR_OK;
	}
	if (fsm->state == FTPD_REST) {
		ftpd_msgclose(pcb, fsm);
		NVIC_SystemReset();				// перезапустимся
	}

	if (pcb->state <= ESTABLISHED) send_msgdata(pcb, fsm);
	return ERR_OK;
}
/*************************************************************************
 * ftpd_msgrecv
 *************************************************************************/
static err_t ftpd_msgrecv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	char *text;
	struct ftpd_msgstate *fsm = arg;

	if (err == ERR_OK && p != NULL) {

		/* Inform TCP that we have taken the data. */
		tcp_recved(pcb, p->tot_len);

		text = malloc(p->tot_len + 1);
		if (text) {
			char cmd[5];
			struct pbuf *q;
			char *pt = text;
			struct ftpd_command *ftpd_cmd;

			for (q = p; q != NULL; q = q->next) {
				bcopy(q->payload, pt, q->len);
				pt += q->len;
			}
			*pt = '\0';

			pt = &text[strlen(text) - 1];
			while (((*pt == '\r') || (*pt == '\n')) && pt >= text)
				*pt-- = '\0';

			USART_TRACE("запрос: %s\n", text);

			strncpy(cmd, text, 4);
			for (pt = cmd; isalpha(*pt) && pt < &cmd[4]; pt++){
				*pt = toupper(*pt);
			}
			*pt = '\0';

			for (ftpd_cmd = ftpd_commands; ftpd_cmd->cmd != NULL; ftpd_cmd++) {
				if (!strcmp(ftpd_cmd->cmd, cmd))
					break;
			}

			if (strlen(text) < (strlen(cmd) + 1))
				pt = "";
			else
				pt = &text[strlen(cmd) + 1];

			if (ftpd_cmd->func)
				ftpd_cmd->func(pt, pcb, fsm);
			else
				send_msg(pcb, fsm, msg502);

			free(text);
		}
		pbuf_free(p);
	} else if (err == ERR_OK && p == NULL) {
	    ftpd_msgclose(pcb, fsm);
	}

	return ERR_OK;
}
/*************************************************************************
 * ftpd_msgpoll
 *************************************************************************/
static err_t ftpd_msgpoll(void *arg, struct tcp_pcb *pcb)
{
	struct ftpd_msgstate *fsm = arg;

	if (fsm == NULL)
		return ERR_OK;

	if (fsm->datafs) {
		if (fsm->datafs->connected) {
			switch (fsm->state) {
			case FTPD_LIST:
				send_next_directory(fsm->datafs, fsm->datapcb, 0);
				break;
			case FTPD_NLST:
				send_next_directory(fsm->datafs, fsm->datapcb, 1);
				break;
			case FTPD_RETR:
				send_file(fsm->datafs, fsm->datapcb);
				break;
			default:
				break;
			}
		}
	}
	return ERR_OK;
}
/*************************************************************************
 * ftpd_msgaccept
 *************************************************************************/
static err_t ftpd_msgaccept(void *arg, struct tcp_pcb *pcb, err_t err)
{
	struct ftpd_msgstate *fsm;

	/* Allocate memory for the structure that holds the state of the connection. */
	// Выделим память для структуры, которая содержит состояние соединения.
	fsm = malloc(sizeof(struct ftpd_msgstate));

	if (fsm == NULL) {
		USART_TRACE("ftpd_msgaccept: Недостаточно памяти.\n");
		return ERR_MEM;
	}
	memset(fsm, 0, sizeof(struct ftpd_msgstate));

	/* Initialize the structure. */
	// инитим структуру
	sfifo_init(&fsm->fifo, 2000);			// размер буфера
	fsm->state = FTPD_IDLE;					// режим FTP
	fsm->vfs = vfs_openfs();				//

	if (!fsm->vfs) {
		free(fsm);
		return ERR_CLSD;
	}

	/* Tell TCP that this is the structure we wish to be passed for our callbacks. */
	// Сообщим TCP, что это структура, которую мы хотим передать для наших обратных вызовов.
	tcp_arg(pcb, fsm);

	/* Tell TCP that we wish to be informed of incoming data by a call to the http_recv() function. */
	// Сообщм TCP, что мы хотим получать информацию о входящих данных путем вызова функции http_recv()
	tcp_recv(pcb, ftpd_msgrecv);

	/* Tell TCP that we wish be to informed of data that has been successfully sent by a call to the ftpd_sent() function. */
	// Сообщим TCP, что мы хотим сообщить о данных, которые будем передавать вызовом функции ftpd_sent ().
	tcp_sent(pcb, ftpd_msgsent);

	tcp_err(pcb, ftpd_msgerr);

	tcp_poll(pcb, ftpd_msgpoll, 1);

	send_msg(pcb, fsm, msg220);

	return ERR_OK;
}

/*************************************************************************
 * ftpd_init
 * инит и старт
 *************************************************************************/
void ftpd_init(void)
{
	struct tcp_pcb *pcb;

	vfs_load_plugin(vfs_default_fs);

	pcb = tcp_new();
	tcp_bind(pcb, IP_ADDR_ANY, 21);
	pcb = tcp_listen(pcb);
	tcp_accept(pcb, ftpd_msgaccept);
}

/*************************************************************************
 * StartFTPTask
 *************************************************************************/
void StartFTPTask(void const * argument){

  uint32_t 	SSHTimer = 0;				// таймер отладочного порта
  IsoServer isoServer = NULL;
  Socket	connectionSocketFTP;
  Socket	connectionSocketHTTP;
  Socket	connectionSocketSSH;

  ServerSocket	tmpHTTP = NULL;

  char*		LocalIP;

  osStatus status = osMutexWait(xFTPStartMutex,TIMEOUT_startServer+1000);		// блокируемся	osWaitForever
  if (status != osOK) {
  	// не запустился, всё нам конец.
		USART_TRACE_RED("не запустился FTP таск\n");
  }else{
	  osMutexRelease(xFTPStartMutex);
  }

restartTask:

  if (iedServer) {
	  isoServer = (IsoServer)IedServer_getIsoServer(iedServer);
	  if (isoServer && tmpHTTP == NULL){
		  IsoServer_SetFTPPort(isoServer,FTP_Port);
		  IsoServer_SetHTTPPort(isoServer,HTTP_Port);
		  IsoServer_SetSSHPort(isoServer,SSH_Port);
		  IsoServer_ClrSSHConnect(isoServer);

		  LocalIP = IsoServer_getLocalIpAddress(isoServer);

		  //---------
		    ftpd_init();			// вот и весь таск FTP
/*
		  	IsoServer_SetFTPServerSocket(isoServer,TcpServerSocket_create(LocalIP, FTP_Port));
		  	USART_TRACE_GREEN("FTP_SERVER: localIpAddress: %s Port: %u\n", LocalIP,(int)FTP_Port);
		  	ServerSocket_setBacklog((ServerSocket) IsoServer_GetFTPServerSocket(isoServer), BACKLOG);		// установим очередь ожидающих
		  	ServerSocket_listen((ServerSocket) IsoServer_GetFTPServerSocket(isoServer));					// Начинаем слушать входящие подключения
*/
		  //---------
		  	IsoServer_SetHTTPServerSocket(isoServer,TcpServerSocket_create(LocalIP, HTTP_Port));
		  	USART_TRACE_GREEN("HTTP_SERVER: localIpAddress: %s tcpPort: %u\n", LocalIP,(int)HTTP_Port);
		  	ServerSocket_setBacklog((ServerSocket) IsoServer_GetHTTPServerSocket(isoServer), 0);		//BACKLOG
		  	ServerSocket_listen((ServerSocket) IsoServer_GetHTTPServerSocket(isoServer));
		  //---------
/*

   	  		IsoServer_SetSSHServerSocket(isoServer,TcpServerSocket_create(LocalIP, SSH_Port));
		    USART_TRACE_GREEN("SSH_SERVER: localIpAddress: %s SSHPort: %u\n", LocalIP,(int)SSH_Port);
		    ServerSocket_setBacklog((ServerSocket) IsoServer_GetSSHServerSocket(isoServer), 0);		//BACKLOG
		    ServerSocket_listen((ServerSocket) IsoServer_GetSSHServerSocket(isoServer));
*/		  //---------

	  }
  } else{
// ХЗ как он тут работать будет
	LocalIP ="192.168.0.254";

	tmpHTTP = TcpServerSocket_create(LocalIP, HTTP_Port);
	if (tmpHTTP){
		USART_TRACE_GREEN("HTTP_SERVER:Временный localIpAddress: %s tcpPort: %u\n", LocalIP,(int)HTTP_Port);
		ServerSocket_setBacklog(tmpHTTP, 0);		//BACKLOG
		ServerSocket_listen(tmpHTTP);
	} else {
		goto restartTask;
	}

  }

	for(;;)
	{
	// не сконфигурился 850 сервер		работаем врененно
	if (!iedServer){

		if ((connectionSocketHTTP = ServerSocket_accept(tmpHTTP)) != NULL) {
			USART_TRACE_GREEN("соединение на HTTP порт.\n");
			http_server_serve(connectionSocketHTTP);
		}
		taskYIELD();
		continue;
	}else{
		//наконец сконфигурился 850
		if (tmpHTTP){
			// закрываем и пересоединяем нормальный коннект
			USART_TRACE_RED("HTTP_SERVER:закрываем временный: tcpPort: %u\n",(int)HTTP_Port);
			ServerSocket_destroy(tmpHTTP);
			tmpHTTP = NULL;
			goto restartTask;
		}
	}



	handleNTPConnectionsThreadless(isoServer);					// Клиент NTP
/***********************************************************************************************************
 * 21
 ***********************************************************************************************************/
/*
	if ((connectionSocketFTP = ServerSocket_accept((ServerSocket) IsoServer_GetFTPServerSocket(isoServer))) != NULL) {
		USART_TRACE_GREEN("соединение на FTP порт.\n");
	    ftp_server_serve(connectionSocketFTP);
	} else{
	}
	taskYIELD();
*/
/***********************************************************************************************************
 * 80
 ***********************************************************************************************************/
	if ((connectionSocketHTTP = ServerSocket_accept((ServerSocket) IsoServer_GetHTTPServerSocket(isoServer))) != NULL) {
		USART_TRACE_GREEN("соединение на HTTP порт.\n");
		http_server_serve(connectionSocketHTTP);
	} else{
	}
	taskYIELD();
/***********************************************************************************************************
 * 23
 ***********************************************************************************************************/
/*	if ((connectionSocketSSH = ServerSocket_accept((ServerSocket) IsoServer_GetSSHServerSocket(isoServer))) != NULL) {
		USART_TRACE_GREEN("соединение на SSH порт.\n");
		IsoServer_SetSSHConnect(isoServer);
		SocketSSH = connectionSocketSSH;
		SSHTimer = HAL_GetTick();
	} else{
		if (SocketSSH){
			if  (HAL_GetTick() > (SSHTimer + (uint32_t)_60min)){			// откроем на 10 минут
				USART_TRACE_RED("закрыли SSH по таймауту.\n");
				Socket_destroy(SocketSSH);
				SocketSSH = 0;
				IsoServer_ClrSSHConnect(isoServer);
			}
			// тут надо проверить активность соединения. И закрыть если нет ответа от порта
		}
	}
	taskYIELD();
*/
/***********************************************************************************************************
* END
***********************************************************************************************************/
								// отпустим задачу.
	}
  vTaskDelete(NULL);
}

/***********************************************************************************************************
* ftp_server_serve
***********************************************************************************************************/
void ftp_server_serve(Socket self){

	HandleSet handles = Handleset_new();
	Handleset_addSocket(handles, self);

	int result = Handleset_waitReady(handles, 1);			// проверка состояния сокетов ждем таймаут 5
	Handleset_destroy(handles);

	if (result < 1){
	  USART_TRACE_RED("FTP без данных. Закрываем.\n");
	  Socket_destroy(self);
	  return;
	}

	int conn = GetSocket_num(self);

	  int buflen = 1500;
	  int ret;
	  unsigned char recv_buffer[1500];

	  // читаем из сокета запрос от клиента
	  ret = read(conn, recv_buffer, buflen);

	  if(ret == 0) {
		  USART_TRACE_RED("Разорвал клиент.\n");
		  Socket_destroy(self);
		  return;
	  }else
	  if(ret < 0) {
		  USART_TRACE_RED("ничего не прочитали. Закрываем. %i\n",ret);
		  Socket_destroy(self);
		  return;
	  }
}
