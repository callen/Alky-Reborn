/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Core/Core.h>

#define NUMODULE_NAME "NuCore"

#ifndef WINDOWS
inline void *NuCore_Import(char *module, char *method, void *dest) {
	NuCore *_Context;
	
	char *module_lower;
	void *mod_handle, *addr = None;
	char path[1024];
	char method_temp[256];
	unsigned char i;
	bool found = False;
	
	void *RTLD_DEFAULT_ = RTLD_DEFAULT;
	
#ifdef LINUX
 	RTLD_DEFAULT_ = dlopen(RTLD_DEFAULT, RTLD_NOW|RTLD_GLOBAL);
#endif
	
	void *(*ImportOverride)(char *method);
	
	NuLog("Importing %s::%s", module, method);
	
	if(strcmp(method, "GetGameAPI") == 0) {
		void (*DllInit)() = 0x08060f78;
		
		NuLog("Calling DllInit");
		DllInit();
		NuLog("DllInit returned");
		
		return 0x1003dd70;
	}
	
	_Context = NuCore_GetContext();
	
	if(dest != None) {
		snprintf(method_temp, 256, "%s::%s", module, method);
	
		_Context->method_names[_Context->method_count] = strdup(method_temp);
		_Context->method_addrs[_Context->method_count] = dest;
		_Context->method_count++;
	}
	
	for(i = 0; i < _Context->module_count; ++i) {
		if(strcmp(_Context->module_names[i], module) == 0) {
			mod_handle = _Context->module_handles[i];
			found = True;
		}
	}
	
	if(!found) {
		if(module[0] != '/')
			snprintf(path, 1024, "%s/lib%s.%s", _Context->lib_path, module, SHARED_SUFFIX);
		else
			snprintf(path, 1024, "%s.%s", module, SHARED_SUFFIX);
			
		mod_handle = dlopen(path, RTLD_NOW|RTLD_GLOBAL);
		if(mod_handle == None) {
			module_lower = strtolower(module);
			if(module_lower[0] != '/')
				snprintf(path, 1024, "%s/lib%s.%s", _Context->lib_path, module_lower, SHARED_SUFFIX);
			else
				snprintf(path, 1024, "%s.%s", module_lower, SHARED_SUFFIX);
			free(module_lower);
			
			mod_handle = dlopen(path, RTLD_NOW|RTLD_GLOBAL);
			if(mod_handle == None) {
				if(module[0] == '/') {
					mod_handle = RTLD_DEFAULT_;
				}
				else {
					NuCore_SetError(dlerror());
					return None;
				}
			}
		}
		
		if(mod_handle != RTLD_DEFAULT_) {
			void (*VTable_Setup)();
			
			VTable_Setup = dlsym(mod_handle, "VTable_Setup");
			
			if(VTable_Setup != None)
				VTable_Setup();
		}
		
		_Context->module_names[_Context->module_count] = module;
		_Context->module_handles[_Context->module_count] = mod_handle;
		_Context->module_count++;
	}
	
	ImportOverride = dlsym(mod_handle, "ImportOverride");
	if(mod_handle != RTLD_DEFAULT_ && ImportOverride != None)
		addr = ImportOverride(method);
	
	if(addr != None)
		goto ret;
	
	snprintf(method_temp, 256, "%s_", method);
	
	addr = dlsym(mod_handle, method_temp);
	if(addr != None)
		goto ret;
	
	addr = dlsym(mod_handle, method);
	if(addr != None)
		goto ret;
	NuCore_SetError(dlerror());
	
	return None;
	
ret:
	if(mod_handle == RTLD_DEFAULT_) {
		void (*DllInit)() = dlsym(RTLD_DEFAULT_, "DllInit");
		
		if(DllInit != None) {
			NuLog("Calling DllInit");
			DllInit();
			NuLog("DllInit returned");
		}
	}
	
	NuCore_SetError(None);
	
	if(dest != None) {
		*((void **) dest) = addr;
	}
	
	return addr;
}
#endif

void NuCore_Unsupported_f(uint addr, uint orig);

#ifdef LINUX
__asm__ (
	".globl NuCore_UnsupportedTemplate\n"
	"NuCore_UnsupportedTemplate:\n"
	"	push 0xDEADBEEF\n"
	".globl NuCore_UnsupportedTemplate2\n"
	"NuCore_UnsupportedTemplate2:\n"
	"	call *0xDEADBEEF\n"
	".globl NuCore_UnsupportedTemplate3\n"
	"NuCore_UnsupportedTemplate3:\n"
	"	ret\n"
	".globl NuCore_UnsupportedTemplate4\n"
	"NuCore_UnsupportedTemplate4:\n"
	"	nop\n"
);
#else
__asm__ (
	".globl _NuCore_UnsupportedTemplate\n"
	"_NuCore_UnsupportedTemplate:\n"
	"	push 0xDEADBEEF\n"
	".globl _NuCore_UnsupportedTemplate2\n"
	"_NuCore_UnsupportedTemplate2:\n"
	"	call *0xDEADBEEF\n"
	".globl _NuCore_UnsupportedTemplate3\n"
	"_NuCore_UnsupportedTemplate3:\n"
	"	ret\n"
	".globl _NuCore_UnsupportedTemplate4\n"
	"_NuCore_UnsupportedTemplate4:\n"
	"	nop\n"
);
#endif

void NuCore_UnsupportedTemplate();
void NuCore_UnsupportedTemplate2();
void NuCore_UnsupportedTemplate3();
void NuCore_UnsupportedTemplate4();

void *NuCore_CreateUnsupportedWrapper(void *addr) {
	unsigned int *patch_check = (unsigned char *) NuCore_UnsupportedTemplate2 - 4;
	unsigned int *patch_loc;
	unsigned int length = (unsigned int) NuCore_UnsupportedTemplate4;
	unsigned char *new_func;
	
	void **addr_p;
	
	static void **func_p = None;
	
	int i;
	
	if(func_p == None)
		func_p = malloc(sizeof(void *));
	
	*func_p = NuCore_Unsupported_f;
	
	length -= (unsigned int) NuCore_UnsupportedTemplate;
	
	if(*patch_check != 0xDEADBEEF)
		NuError("Bad ASM in NuCore_UnsupportedTemplate");
	
	new_func = (unsigned int *) malloc(length);
	
	memcpy(new_func, NuCore_UnsupportedTemplate, length);
	
	patch_loc = (int) new_func + ((int) NuCore_UnsupportedTemplate2 - (int) NuCore_UnsupportedTemplate) - 4;
	
	addr_p = malloc(sizeof(void *));
	*addr_p = addr;
	
	*patch_loc = addr_p;
	
	patch_loc = (int) new_func + ((int) NuCore_UnsupportedTemplate3 - (int) NuCore_UnsupportedTemplate) - 4;
	
	*patch_loc = func_p;
	
	return new_func;
}

void NuCore_Unsupported_f(
	uint addr,
	uint orig // MAGIC!
) {
	// This is magic.  Seriously, don't question it.

	NuCore *_Context = NuCore_GetContext();
	
	int i;
	
	void *possible;
	
	possible = *((unsigned int *) (orig - 4));
	
	for(i = 0; i < _Context->method_count; ++i) {
		if(
			_Context->method_addrs[i] == possible ||
			_Context->method_addrs[i] == addr
		)
			NuError("Unsupported function called from %p: %s",
					orig, _Context->method_names[i]);
	}
	
	addr = *((unsigned int *) (((unsigned char *) &addr) - 4));
	
	NuError("Unsupported function hit from location %p", addr);
}

void NuCore_AddImportAddr(void *addr, char *name) {
	NuCore *_Context = NuCore_GetContext();
	
	_Context->method_addrs[_Context->method_count] = addr;
	_Context->method_names[_Context->method_count] = name;
	_Context->method_count++;
}
