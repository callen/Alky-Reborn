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

void __attribute__ ((constructor)) DyLib_main() {
	bool (*DllMain)(
	  void *hinstDLL,
	  unsigned int fdwReason,
	  void *lpvReserved
	) = (void *) %ENTRY_POINT%;
	
	char *path, load[256];
	
	void *nucore;
	void *(*NuCore_Import)(char *module_name, char *function_name, void *dest);
	char *(*NuCore_Error)();
	void *(*NuCore_CreateUnsupportedWrapper)(unsigned int addr);
	
	NuLog("Opening NuCore");
	
	if((path = getenv("ALKY_LIB_PATH")) == None)
		path = "Build";
	
	snprintf(load, 256, "%s/libNuCore.dylib", path);
	
	nucore = dlopen(load, RTLD_NOW|RTLD_GLOBAL);
	
	if(nucore == None)
		NuError("NuCore could not be loaded: %s", dlerror());
	
	NuCore_Import = dlsym(nucore, "NuCore_Import");
	if(NuCore_Import == None)
		NuError("NuCore_Import could not be resolved: %s", dlerror());
	
	NuCore_CreateUnsupportedWrapper = dlsym(nucore, "NuCore_CreateUnsupportedWrapper");
	if(NuCore_CreateUnsupportedWrapper == None)
		NuError("NuCore_CreateUnsupportedWrapper could not be resolved: %s", dlerror());
	
	NuCore_Error = dlsym(nucore, "NuCore_Error");
	if(NuCore_Error == None)
		NuError("NuCore_Error could not be resolved: %s", dlerror());
	
	NuLog("Setting up imports");
	
#include "%IMPORT_PATH%"

	NuLog("Set up imports");
	
	NuLog("%p", *((unsigned int *) DllMain));
	
	NuLog("Running DllMain");
	DllMain(0x10000000, 1, None);
	NuLog("Returned");
}