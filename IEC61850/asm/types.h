#ifndef __ASM_ARM_TYPES_H
#define __ASM_ARM_TYPES_H

#define __bitwise

#include <stdint.h>
#include <sys/types.h>


#define BITS_PER_LONG 32

/*
#ifndef __ASSEMBLY__
typedef unsigned short umode_t;
#if defined(__GNUC__)
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
#endif
#endif
*/

typedef int8_t __s8;
typedef uint8_t __u8;
typedef int16_t __s16;
typedef uint16_t __u16;
typedef int32_t __s32;
typedef uint32_t __u32;
typedef int64_t __s64;
typedef uint64_t __u64;

typedef uint16_t  __le16;
typedef uint16_t  __be16;
typedef uint32_t  __le32;
typedef uint32_t  __be32;
typedef uint64_t  __le64;
typedef uint64_t  __be64;

typedef uint16_t  __sum16;
typedef uint32_t  __wsum;

typedef uint64_t u64;
typedef int64_t s64;

typedef __u32 u32;
typedef __s32 s32;

typedef __u16 u16;
typedef __s16 s16;

typedef __u8  u8;
typedef __s8  s8;

typedef unsigned short		umode_t;

typedef struct {
	uid_t val;
} kuid_t;

typedef struct {
	gid_t val;
} kgid_t;

typedef unsigned __bitwise gfp_t;

#define spinlock_t					osMutexId				/* в линуксе Спин-блокировка это мьютексы в фриртосе */


/*
 * These aren't exported outside the kernel to avoid name space clashes
 */

//-----------------------------------------------------------------

struct timer_list {
	struct timer_list *next, *prev;
};

struct list_head {
	struct list_head *next, *prev;
};

struct callback_head {
	struct callback_head *next;
	void (*func)(struct callback_head *head);
} __attribute__((aligned(sizeof(void *))));
#define rcu_head 	callback_head

typedef void (*rcu_callback_t)(struct rcu_head *head);
typedef void (*call_rcu_func_t)(struct rcu_head *head, rcu_callback_t func);
//-----------------------------------------------------------------

#ifndef __aligned_u64
# define __aligned_u64 __u64 __attribute__((aligned(8)))
#endif

typedef struct {
	int counter;
} atomic_t;

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#endif

