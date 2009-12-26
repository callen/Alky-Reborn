/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_CORE_CORE_H__
#define __NUCLEUS_CORE_CORE_H__

#include <Nucleus/Nucleus.h>

#ifndef WINDOWS
#include <dlfcn.h>
#endif

#if !defined(RTLD_DEFAULT)
#define RTLD_DEFAULT ((void *) 0)
#endif

struct NuCore_s {
	char *error;
	
	char lib_path[256];
	
	unsigned char module_count;
	char *module_names[256];
	void *module_handles[256];
	
	unsigned int method_count;
	char *method_names[65536];
	void *method_addrs[65536];
} typedef NuCore;

bool NuCore_Setup();
bool NuCore_Teardown();

char *NuCore_Error();
bool  NuCore_SetError(char *error);

void *NuCore_Import(char *module, char *method, void *dest);

void *NuCore_CreateUnsupportedWrapper(void *addr);
void NuCore_Unsupported_f(unsigned int addr, unsigned int orig);

void NuCore_AddImportAddr(void *addr, char *name);

NuContext_SingletonDecl(NuCore_GetContext, NuCore);

char *strtolower(char *str);

#define NuCore_Interrupt(num) __asm__("int $" #num "\n")

#endif
