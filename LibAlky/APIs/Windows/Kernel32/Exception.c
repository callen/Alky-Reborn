/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI void RaiseException(
  DWORD dwExceptionCode,
  DWORD dwExceptionFlags,
  DWORD nNumberOfArguments,
  const ULONG_PTR* lpArguments
) {
	NuWarn("RaiseException not yet implemented");
}