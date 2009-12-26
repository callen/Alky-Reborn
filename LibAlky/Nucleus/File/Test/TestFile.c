/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "TestFile"

int main(int argc, char **argv) {
	NuFile *file;
	char buf[5];
	
	file = NuFile_Open("/tmp/nufile.test", "w");
	
	if(file == None)
		goto failed;
	
	if(NuFile_Write(file, "test", 5) != 5)
		goto failed;
	
	NuFile_Close(file);
	
	file = NuFile_Open("/tmp/nufile.test", "r");
	
	if(file == None)
		goto failed;
	
	if(NuFile_Read(file, buf, 5) != 5)
		goto failed;
	
	if(strcmp(buf, "test") != 0)
		goto failed;
	
	NuLog("Succeeded");
	
	return 0;

failed:
	NuError("Failed");
}
