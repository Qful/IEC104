/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Miscellaneous system-dependent types.
 */
#ifndef	_ASN_SYSTEM_H_
#define	_ASN_SYSTEM_H_

#include "stdio.h"	/* For snprintf(3) */
#include "stdlib.h"	/* For *alloc(3) */
#include "string.h"	/* For memcpy(3) */
#include "sys/types.h"	/* For size_t */
#include "stdarg.h"	/* For va_start */
#include "stddef.h"	/* for offsetof and ptrdiff_t */
#include "inttypes.h"	/* C99 specifies this file */
#include "stdint.h"	/* SUSv2+ and C99 specify this file, for uintXX_t */

#if	__GNUC__ >= 3
#ifndef	GCC_PRINTFLIKE
#define	GCC_PRINTFLIKE(fmt,var)	__attribute__((format(printf,fmt,var)))
#endif
#else
#ifndef	GCC_PRINTFLIKE
#define	GCC_PRINTFLIKE(fmt,var)	/* nothing */
#endif
#endif

#ifndef	offsetof	/* If not defined by <stddef.h> */
#define	offsetof(s, m)	((ptrdiff_t)&(((s *)0)->m) - (ptrdiff_t)((s *)0))
#endif	/* offsetof */

#ifndef	MIN		/* Suitable for comparing primitive types (integers) */
#if defined(__GNUC__)
#define	MIN(a,b)	({ __typeof a _a = a; __typeof b _b = b;	\
	((_a)<(_b)?(_a):(_b)); })
#else	/* !__GNUC__ */
#define	MIN(a,b)	((a)<(b)?(a):(b))	/* Unsafe variant */
#endif /* __GNUC__ */
#endif	/* MIN */

#endif	/* _ASN_SYSTEM_H_ */
