/*
 * libiec61850_platform_includes.h
 */

#ifndef LIBIEC61850_PLATFORM_INCLUDES_H_
#define LIBIEC61850_PLATFORM_INCLUDES_H_

#include "libiec61850_common_api.h"

#include "string_utilities.h"
#include "stdlib.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"

#include "main.h"


#include "platform_endian.h"

#define LIBIEC61850_VERSION "0.9.2"

#ifdef __GNUC__
#define ATTRIBUTE_PACKED __attribute__ ((__packed__))
#else
#define ATTRIBUTE_PACKED
#endif


#ifndef CONFIG_DEFAULT_MMS_VENDOR_NAME
#define CONFIG_DEFAULT_MMS_VENDOR_NAME "libiec61850.com"
#endif

#ifndef CONFIG_DEFAULT_MMS_MODEL_NAME
#define CONFIG_DEFAULT_MMS_MODEL_NAME "LIBIEC61850"
#endif

#ifndef CONFIG_DEFAULT_MMS_REVISION
#define CONFIG_DEFAULT_MMS_REVISION LIBIEC61850_VERSION
#endif

#ifndef CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT
#define CONFIG_IEC61850_SAMPLED_VALUES_SUPPORT 0
#endif

#if (DEBUG != 1)
#define NDEBUG 1
#endif


#define API
#define STDCALL

#include <assert.h>

#include "lib_memory.h"

#endif /* LIBIEC61850_PLATFORM_INCLUDES_H_ */
