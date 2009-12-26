/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Core/Core.h>
#include <string.h>

#define NUMODULE_NAME "NuCore"

NuContext_Singleton(NuCore_GetContext, NuCore, NUMODULE_NAME);

inline bool NuCore_Setup() {
	static bool initialized = False; 
	NuCore *_Context;
	
	char *path;
	
	if(initialized)
		return True;
	initialized = True;
	
	NuLog("Setup");
	
	_Context = NuCore_GetContext();
	
	_Context->error = None;
	
	_Context->module_count = 0;
	memset(_Context->module_names, 0, 256 * sizeof(char *));
	memset(_Context->module_handles, 0, 256 * sizeof(void *));
	
	_Context->method_count = 0;
	memset(_Context->method_names, 0, 1024 * sizeof(char *));
	memset(_Context->method_addrs, 0, 1024 * sizeof(void *));
	
	if((path = getenv("ALKY_LIB_PATH")) == NULL)
		strncpy(_Context->lib_path, "Build", 256);
	else
		strncpy(_Context->lib_path, path, 256);
	
	return True;
}

inline bool NuCore_Teardown() {
	NuCore *_Context;
	
	NuLog("Teardown");
	
	_Context = NuCore_GetContext();

	if(_Context->error != None)
		free(_Context->error);
	
	free(_Context);
	_Context = None;
	
	return True;
}

inline FILE *NuCore_GetLog() {
	static FILE *log = None;
	
	if(log != None)
		return log;
	
	log = fopen("alkylog.txt", "wb");
	NuCore_Setup();
	
	return log;
}

inline char *NuCore_Error() {
	NuCore *_Context;
	
	NuLog("Returning error");
	
	_Context = NuCore_GetContext();
	
	return _Context->error;
}

inline bool NuCore_SetError(char *error) {
	NuCore *_Context;
	
	NuLog("Setting error");
	
	_Context = NuCore_GetContext();
	
	if(_Context->error != None) {
		NuLog("Freeing old error");
		free(_Context->error);
	}
	
	if(error != None)
		_Context->error = strdup(error);
	else
		_Context->error = None;
	
	return True;
}

char *strtolower(char *str) {
	char *out;
	out = str = strdup(str);
	for(; *str; ++str) {
		if(*str >= 'A' && *str <= 'Z') {
			*str = *str - 'A' + 'a';
		}
	}
	return out;
}
