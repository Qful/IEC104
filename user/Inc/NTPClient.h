//
//	ntpClient.h
//

#ifndef	__NTPCLIENT_H__

#define __NTPCLIENT_H__

#ifndef	NTP_PORT
#define NTP_PORT	123
#endif

typedef uint32_t quint32;
typedef int32_t qint32;
typedef uint8_t quint8;
typedef int8_t qint8;

#define FreeRTOS_inet_addr_quick( ucOctet0, ucOctet1, ucOctet2, ucOctet3 )				\
									( ( ( ( uint32_t ) ( ucOctet3 ) ) << 24UL ) |		\
									( ( ( uint32_t ) ( ucOctet2 ) ) << 16UL ) |			\
									( ( ( uint32_t ) ( ucOctet1 ) ) <<  8UL ) |			\
									( ( uint32_t ) ( ucOctet0 ) ) )

typedef union _SNtpFlags  SNtpFlags;

typedef struct xTIME_STRUCT
{
	int tm_sec;   /* Seconds */
	int tm_min;   /* Minutes */
	int tm_hour;  /* Hour (0--23) */
	int tm_mday;  /* Day of month (1--31) */
	int tm_mon;   /* Month (0--11) */
	int tm_year;  /* Year (calendar year minus 1900) */
	int tm_wday;  /* Weekday (0--6; Sunday = 0) */
	int tm_yday;  /* Day of year (0--365) */
	int tm_isdst; /* 0 if daylight savings time is not in effect) */
} FF_TimeStruct_t;

/**
 * 64-bit NTP timestamp.
 */
struct __attribute__ ((__packed__)) _SNtpTimestamp {
  /** Number of seconds passed since Jan 1 1900, in big-endian format. */
  quint32 seconds;

  /** Fractional time part, in <tt>1/0xFFFFFFFF</tt>s of a second. */
  quint32 fraction;
};

typedef struct _SNtpTimestamp SNtpTimestamp;
/**
 * Mandatory part of an NTP packet
 */
struct SNtpPacket {
  /** Flags. */
  unsigned char flags;  // value 0xDB : mode 3 (client), version 3, leap indicator unknown 3

  /** Stratum of the clock. */
  quint8 stratum;  // value 0 : unspecified

  /** Maximum interval between successive messages, in log2 seconds. Note that the value is signed. */
  qint8 poll;  // 10 means 1 << 10 = 1024 seconds

  /** Precision of the clock, in log2 seconds. Note that the value is signed. */
  qint8 precision; // 0xFA = 250 = 0.015625 seconds

  /** Round trip time to the primary reference source, in NTP short format. */
  qint32 rootDelay; // 0x5D2E = 23854 or (23854/65535)= 0.3640 sec

  /** Nominal error relative to the primary reference source. */
  qint32 rootDispersion; // 0x0008 CAC8 = 8.7912  seconds

  /** Reference identifier (either a 4 character string or an IP address). */
  qint8 referenceID[4]; // or just 0000

  /** The time at which the clock was last set or corrected. Время, когда часы были установлены или скорректированы в последний раз. */
  SNtpTimestamp referenceTimestamp; // Current time 

  /** The time at which the request departed the client for the server. Время, когда клиент отправил запрос на сервер*/
  SNtpTimestamp originateTimestamp; // Keep 0

  /** The time at which the request arrived at the server. Время, когда запрос пришел на сервер. */
  SNtpTimestamp receiveTimestamp; // Keep 0

  /** The time at which the reply departed the server for client. Время, когда ответ отправлен сервером для клиента. */
  SNtpTimestamp transmitTimestamp;
};

/* Add this number to get secs since 1-1-1900 */
#define TIME1970 2208988800UL

#endif // __NTPCLIENT_H__
