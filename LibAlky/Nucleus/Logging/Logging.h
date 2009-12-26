/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_LOGGING_LOGGING_H__
#define __NUCLEUS_LOGGING_LOGGING_H__

#include <Nucleus/Nucleus.h>
#include <stdio.h>
#include <stdlib.h>

#define NULOG_DEBUG

#ifdef WINDOWS

inline FILE *NuCore_GetLog();
#define NULOG_OUTPUT NuCore_GetLog()

#else
#define NULOG_OUTPUT stdout
#endif

#define NULOG_ERROR   1
#define NULOG_WARNING 2
#define NULOG_VERBOSE 4

#define NULOG_LEVEL NULOG_ERROR

#if NULOG_LEVEL >= NULOG_VERBOSE
#define NuLog(str, args...) {\
    fprintf(NULOG_OUTPUT, "Log (" NUMODULE_NAME "): " str "\n", ##args); \
    fflush(NULOG_OUTPUT); \
}
#else
#define NuLog(...)
#endif

#define NuTrace(str, args...) fprintf(NULOG_OUTPUT, "Trace (" NUMODULE_NAME "): " str "\n", ##args)

#if NULOG_LEVEL >= NULOG_WARNING
#define NuWarn(str, args...) {\
     fprintf(NULOG_OUTPUT, "Warning (" NUMODULE_NAME "): " str "\n", ##args); \
     fflush(NULOG_OUTPUT); \
}
#else
#define NuWarn(...)
#endif

#define NuError(str, args...) \
do { \
	fprintf(NULOG_OUTPUT, "Error (" NUMODULE_NAME "): " str "\n", ##args); \
	fflush(NULOG_OUTPUT); \
	_exit(1); \
} while(0)

#define NuAssert(assertion) \
do { \
	if(!(assertion)) {\
		NuError("NuAssert(" #assertion ") failed at %s (%i)", __FILE__, __LINE__); \
	} \
} while(0)

#ifdef NULOG_DEBUG
#define NuDebug() \
do { __asm__("int $3"); } while(0)
#else
#define NuDebug()
#endif

#endif
