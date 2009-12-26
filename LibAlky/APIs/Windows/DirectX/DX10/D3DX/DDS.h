/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DDS_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DDS_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

typedef enum {
	DXT1,
	DXT2,
	DXT3,
	DXT4,
	DXT5,
	
	FRGBA,
	URGBA32,
	IRGBA32,
	
	FRGB24,
	URGB24,
	IRGB24
} DDSFormat;

typedef struct DDS {
	unsigned int width, height, depth;
	unsigned int mipmapCount, pitch;
	
	DDSFormat format;
	
	unsigned int bufferCount;
	unsigned int bufferSizes[32];
	void *buffers[32];
} DDS;

WINAPI DDS *DDS_Read(unsigned char *buffer, unsigned int size);
WINAPI void DDS_Free(DDS *dds);

#endif
