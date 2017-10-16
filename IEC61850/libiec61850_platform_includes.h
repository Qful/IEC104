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

#define LIBIEC61850_VERSION "1.0.0"

#ifdef __GNUC__
#define ATTRIBUTE_PACKED __attribute__ ((__packed__))
#else
#define ATTRIBUTE_PACKED
#endif


#ifndef CONFIG_DEFAULT_MMS_VENDOR_NAME
#define CONFIG_DEFAULT_MMS_VENDOR_NAME _Vendor
#endif

#ifndef CONFIG_DEFAULT_MMS_MODEL_NAME
#define CONFIG_DEFAULT_MMS_MODEL_NAME _swREV//"IEC 8-1 Server"
#endif

#ifndef CONFIG_DEFAULT_MMS_REVISION
#define CONFIG_DEFAULT_MMS_REVISION _SWRevision//LIBIEC61850_VERSION
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
