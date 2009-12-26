/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __WINDOWS_CORE_CORE_H__
#define __WINDOWS_CORE_CORE_H__

#include <Nucleus/Nucleus.h>

bool WinCore_Setup();
bool WinCore_Teardown();

#ifdef LINUX
bool WinCore_ReplaceStackAndRun(void *entry, void *param, bool use_param);
#endif
bool WinCore_SetupFS();

#endif
