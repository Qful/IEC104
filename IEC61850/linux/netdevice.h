/*
 * netdevice.h
 *
 *  Created on: 15.10.2018
 *      Author: sagok
 */

#ifndef NETDEVICE_H_
#define NETDEVICE_H_

#include "kernel.h"
#include "limits.h"
#include <sys/cdefs.h>
#include <string.h>
#include <sys/time.h>
#include <asm/types.h>

#define	IFNAMSIZ			16

#define	NETDEV_ALIGN		32

/* Backlog congestion levels */
#define NET_RX_SUCCESS			0	/* keep 'em coming, baby */
#define NET_RX_DROP				1	/* packet dropped */


enum netdev_tx {
	__NETDEV_TX_MIN	 = INT_MIN,	/* make sure enum is signed */
	NETDEV_TX_OK	 = 0x00,	/* driver took care of packet */
	NETDEV_TX_BUSY	 = 0x10,	/* driver tx path was busy*/
};
typedef enum netdev_tx netdev_tx_t;

/*
 *	Old network device statistics. Fields are native words (unsigned long) so they can be read and written atomically.
 */
struct net_device_stats {
	unsigned long	rx_packets;
	unsigned long	tx_packets;
	unsigned long	rx_bytes;
	unsigned long	tx_bytes;
	unsigned long	rx_errors;
	unsigned long	tx_errors;
	unsigned long	rx_dropped;
	unsigned long	tx_dropped;
	unsigned long	multicast;
	unsigned long	collisions;
	unsigned long	rx_length_errors;
	unsigned long	rx_over_errors;
	unsigned long	rx_crc_errors;
	unsigned long	rx_frame_errors;
	unsigned long	rx_fifo_errors;
	unsigned long	rx_missed_errors;
	unsigned long	tx_aborted_errors;
	unsigned long	tx_carrier_errors;
	unsigned long	tx_fifo_errors;
	unsigned long	tx_heartbeat_errors;
	unsigned long	tx_window_errors;
	unsigned long	rx_compressed;
	unsigned long	tx_compressed;
};

/************************************************
 * struct net_device - The DEVICE structure.
 * В линуксе это мощная структура, нам это всё не нужно
 * начнём с имени интерфейса (eth0)
 *
 * возможно нужно перейти к структуре netconn для фриртоса
 ************************************************/
struct net_device {
	char				name[IFNAMSIZ];

//	unsigned int		flags;						// net_device flags: /sys/class/net/<dev>/flags.

//	unsigned char		operstate;  				// RFC2863 operstate OPER_UP/IF_OPER_UNKNOWN
//	unsigned char  		link_mode; 					// mapping policy to operstate

	int					ifindex;					// interface index

	struct net_device_stats	stats;					// статистика сетевого устройства.
};

/**
 *	netdev_priv - access network device private data
 *	@dev: network device
 *
 * Get network device private data
 */
static inline void *netdev_priv(const struct net_device *dev)
{
	return (char *)dev + ALIGN(sizeof(struct net_device), NETDEV_ALIGN);
}

static inline const char *netdev_name(const struct net_device *dev)
{
	if (!dev->name[0] || strchr(dev->name, '%')) return "(unnamed net_device)";
	return dev->name;
}

//#define netdev_warn(dev, format, args...)	printk("KERN_WARNING %s%s: %pV",dev, netdev_name(dev), ##args); //netdev_printk(KERN_WARNING, dev, format, ##args)

#define __READ_ONCE_SIZE						\
({									\
	switch (size) {							\
	case 1: *(uint8_t *)res = *(volatile uint8_t *)p; break;		\
	case 2: *(uint16_t *)res = *(volatile uint16_t *)p; break;		\
	case 4: *(uint32_t *)res = *(volatile uint32_t *)p; break;		\
	case 8: *(uint64_t *)res = *(volatile uint64_t *)p; break;		\
	default:							\
		memcpy((void *)res, (const void *)p, size);	\
	}								\
})

static inline
void __read_once_size_nocheck(const volatile void *p, void *res, int size)
{
	__READ_ONCE_SIZE;
}


static inline
void __read_once_size(const volatile void *p, void *res, int size)
{
	__READ_ONCE_SIZE;
}

//#define read_barrier_depends() __asm__ __volatile__("mb": : :"memory")
#define smp_read_barrier_depends()	__asm__ __volatile__("mb": : :"memory")

#define __READ_ONCE(x, check)						\
({									\
	union { typeof(x) __val; char __c[1]; } __u;			\
	if (check)							\
		__read_once_size(&(x), __u.__c, sizeof(x));		\
	else								\
		__read_once_size_nocheck(&(x), __u.__c, sizeof(x));	\
	smp_read_barrier_depends(); /* Enforce dependency ordering from x */ \
	__u.__val;							\
})
#define READ_ONCE(x) __READ_ONCE(x, 1)

#define WARN_ONCE(condition, format...)

#define rcu_dereference_raw(p) ({	/* Dependency order vs. p above. */ typeof(p) ________p1 = READ_ONCE(p);((typeof(*p) *)(________p1)); })

#define container_of(ptr, type, member) ({ const typeof( ((type *)0)->member ) *__mptr = (ptr); (type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry_rcu(ptr, type, member) ({ typeof(*ptr) *__ptr = (typeof(*ptr) *)ptr; container_of((typeof(ptr))rcu_dereference_raw(__ptr), type, member); })

#define list_for_each_entry_rcu(pos, head, member)	for (pos = list_entry_rcu((head)->next, typeof(*pos), member); 	&pos->member != (head); pos = list_entry_rcu(pos->member.next, typeof(*pos), member))


#define typecheck(type,x) ({	type __dummy; 	typeof(x) __dummy2; 	(void)(&__dummy == &__dummy2); 	1; })

#define time_after(a,b)		(typecheck(unsigned long, a) && typecheck(unsigned long, b) && ((long)((b) - (a)) < 0))
#define time_before(a,b)	time_after(b,a)

//-----------------------------
#undef  HZ
#define HZ 1000
static inline uint32_t raid6_jiffies(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec*1000 + tv.tv_usec/1000;
}

# define jiffies	raid6_jiffies()

#define MAX_JIFFY_OFFSET ((LONG_MAX >> 1)-1)
#define MSEC_PER_SEC	1000L

static inline
unsigned long _msecs_to_jiffies(const unsigned int m)
{
	return (m + (MSEC_PER_SEC / HZ) - 1) / (MSEC_PER_SEC / HZ);
}

unsigned long __msecs_to_jiffies(const unsigned int m)
{
	/*
	 * Negative value, means infinite timeout:
	 */
	if ((int)m < 0)
		return MAX_JIFFY_OFFSET;
	return _msecs_to_jiffies(m);
}


static inline
unsigned long msecs_to_jiffies(const unsigned int m)
{
	if (__builtin_constant_p(m)) {
		if ((int)m < 0)
			return MAX_JIFFY_OFFSET;
		return _msecs_to_jiffies(m);
	} else {
		return __msecs_to_jiffies(m);
	}
}
//-----------------------------
static inline void kfree_call_rcu(struct rcu_head *head,  rcu_callback_t func)
{
	call_rcu(head, func);
}

#define __kfree_rcu(head, offset) \
	do { \
		kfree_call_rcu(head, (rcu_callback_t)(unsigned long)(offset)); \
	} while (0)

#define kfree_rcu(ptr, rcu_head)					\
	__kfree_rcu(&((ptr)->rcu_head), offsetof(typeof(*(ptr)), rcu_head))

//-----------------------------
#define unlikely(cond) (cond)

#define __WARN_printf(arg...)	do { fprintf(stderr, arg); } while (0)

#define WARN_ON(condition) ({					\
		int __ret_warn_on = !!(condition);			\
		if (unlikely(__ret_warn_on))				\
			__WARN_printf("assertion failed at %s:%d\n",	\
					__FILE__, __LINE__);		\
		unlikely(__ret_warn_on);				\
})


#define WARN_ON_ONCE(condition) ({			\
		static int __warned;				\
		int __ret_warn_once = !!(condition);		\
								\
		if (unlikely(__ret_warn_once && !__warned)) {	\
			__warned = true;			\
			WARN_ON(1);				\
		}						\
		unlikely(__ret_warn_once);			\
})

//-----------------------------

#endif /* NETDEVICE_H_ */
