/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_INTERNAL_TYPES_H__
#define __NUCLEUS_INTERNAL_TYPES_H__

// #include <string.h>

#ifndef NOBOOL
typedef _Bool bool;
#endif

#ifdef WINDOWS
typedef unsigned int uint;
#endif

#define True  1
#define False 0
#define None  0

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) < (b)) ? (b) : (a))

#endif
