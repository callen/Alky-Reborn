/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <dlfcn.h>
#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Linkwrapper"

#define IMPORT(module, method, addr) \
do { \
	if(NuCore_Import(module, method, (void *) addr) == None) { \
		NuWarn("Could not resolve symbol %s::%s: %s", \
		       module, method, NuCore_Error()); \
		*((void **) addr) = NuCore_CreateUnsupportedWrapper(addr); \
	} \
} while(0)

#define SHARED(module, image_base, entry_point) \
do { \
	NuLog("Initializing %s", #module); \
	\
	bool (__attribute ((stdcall)) *DllMain)(void *hModule, unsigned int reason, void *reserved); \
	\
	DllMain = entry_point; \
	\
	NuLog("Calling DllMain"); \
	DllMain((void *) image_base, 1, None); \
	NuLog("DllMain returned"); \
} while(0);

bool imports_initialized = False;

int main(int argc, char **argv) {
	char *path, load[256];
	
	void (*entry)() = (void *) %ENTRY_POINT%;
	
	void *nucore;
	void (*NuCore_Setup)();
	void *(*NuCore_Import)(char *module_name, char *function_name, void *dest);
	char *(*NuCore_Error)();
	void *(*NuCore_CreateUnsupportedWrapper)(unsigned int addr);
	
	void (*WinCore_Setup)();
	void (*WinCore_ReplaceStackAndRun)(void *entry, void *param, bool use_param);
	void (*NuGUI_Setup)();

	NuLog("Opening NuCore");
	
	if((path = getenv("ALKY_LIB_PATH")) == None)
		path = "Build";
	
	snprintf(load, 256, "%s/libNuCore.so", path);
	nucore = dlopen(load, RTLD_NOW|RTLD_GLOBAL);
	
	if(nucore == None)
		NuError("NuCore could not be loaded: %s", dlerror());
	
	NuCore_Setup = dlsym(nucore, "NuCore_Setup");
	if(NuCore_Setup == None)
		NuError("NuCore_Setup could not be resolved: %s", dlerror());
		
	NuCore_Import = dlsym(nucore, "NuCore_Import");
	if(NuCore_Import == None)
		NuError("NuCore_Import could not be resolved: %s", dlerror());
	
	NuCore_CreateUnsupportedWrapper = dlsym(nucore, "NuCore_CreateUnsupportedWrapper");
	if(NuCore_CreateUnsupportedWrapper == None)
		NuError("NuCore_CreateUnsupportedWrapper could not be resolved: %s", dlerror());
	
	NuCore_Error = dlsym(nucore, "NuCore_Error");
	if(NuCore_Error == None)
		NuError("NuCore_Error could not be resolved: %s", dlerror());
	
	NuCore_Setup();
	
	WinCore_Setup = NuCore_Import("WinCore", "WinCore_Setup", None);
	if(WinCore_Setup == None)
		NuError("WinCore_Setup could not be resolved: %s", NuCore_Error());
	
	WinCore_ReplaceStackAndRun = NuCore_Import("WinCore", "WinCore_ReplaceStackAndRun", None);
	if(WinCore_ReplaceStackAndRun == None)
		NuError("WinCore_ReplaceStackAndRun could not be resolved: %s", NuCore_Error());
	
	NuGUI_Setup = NuCore_Import("NuGUI", "NuGUI_Setup", None);
	if(NuGUI_Setup == None)
		NuError("NuGUI_Setup could not be resolved: %s", NuCore_Error());

	WinCore_Setup();
	
	NuLog("Setting up imports");
	
#include "%IMPORT_PATH%"

	NuLog("Set up imports");
	
	imports_initialized = True;

#ifdef LINUX
	WinCore_ReplaceStackAndRun(entry, None, False);
#else
	__asm ("call *%%ecx\n" : : "c" (entry));
#endif
}

void DllInit() {
	static initialized = False;
	
	if(!imports_initialized || initialized)
		return;
	
	NuLog("Initializing built-in shared objects");
%SHARED%
	NuLog("Initialized built-in shared objects");	

	initialized = True;
}
