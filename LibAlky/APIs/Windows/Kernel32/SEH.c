/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(
  LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
) {
	Kernel32 *_Context = Kernel32_GetContext();
	
	_Context->lpTopLevelExceptionFilter = (void *) lpTopLevelExceptionFilter;
}

WINAPI LONG UnhandledExceptionFilter(
  LPEXCEPTION_POINTERS ExceptionInfo
) {
	Kernel32 *_Context = Kernel32_GetContext();
	LPTOP_LEVEL_EXCEPTION_FILTER filter = _Context->lpTopLevelExceptionFilter;
	
	return filter(ExceptionInfo);
}
