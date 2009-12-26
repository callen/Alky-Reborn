/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI HRESULT D3DX10CreateShaderResourceViewFromFileW(
  /* ID3D10Device */ void *pDevice,
  LPCWSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10ShaderResourceView */ void **ppShaderResourceView,
  HRESULT* pHResult
) {
	DDS *dds;
	unsigned char *buffer;
	unsigned int size;
	
	char filename[256];
	
	HANDLE file;
	
	WideCharToMultiByte(CP_ACP, 0, pSrcFile, -1, filename, 256, None, None);
	
	NuLog("D3DX10CreateShaderResourceViewFromFileW: %s", filename);
	
	if(ppShaderResourceView) {
		file = CreateFileW(pSrcFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
		NuAssert(file != None);
		
		size = SetFilePointer(file, 0, NULL, FILE_END);
		SetFilePointer(file, 0, NULL, FILE_BEGIN);
		
		buffer = (unsigned char *) malloc(size);
		ReadFile(file, buffer, size, &size, NULL);
		
		CloseHandle(file);
		
		dds = DDS_Read(buffer, size);
		*ppShaderResourceView = D3D10_CreateShaderResourceViewFromDDS(dds);
		DDS_Free(dds);
		
		free(buffer);
	}
	
	return S_OK;
	
}
