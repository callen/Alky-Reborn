/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_INTERNAL_INTERNAL_H__
#define __NUCLEUS_INTERNAL_INTERNAL_H__

#ifdef __APPLE__
#define MAC
#define SHARED_SUFFIX "dylib"
#elif __linux__
#define LINUX
#define SHARED_SUFFIX "so"
#elif WIN32
#define WINDOWS
#define SHARED_SUFFIX "dll"
#endif

#include <Nucleus/Internal/Types.h>

#endif
