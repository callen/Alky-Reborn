/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

#define DDS_MAGIC "DDS "

typedef struct DDSPixelFormat {
	unsigned int size, flags;
	unsigned char fourCC[4];
	
	unsigned int bitCount;
	unsigned int redMask, greenMask;
	unsigned int blueMask, alphaMask;
} DDSPixelFormat;

typedef struct DDSCapabilities {
	unsigned int caps, caps2;
	unsigned int reserved[2];
} DDSCapabilities;

typedef struct DDSHeader {
	unsigned int headerSize, headerFlags;
	unsigned int height, width, pitch, depth;
	unsigned int mipmapCount;
	unsigned int reserved[11];
	
	DDSPixelFormat pixelFormat;
	DDSCapabilities caps;
	
	unsigned int reserved2;
} DDSHeader;

WINAPI DDS *DDS_Read(unsigned char *buffer, unsigned int size) {
	DDS *dds = (DDS *) malloc(sizeof(DDS));
	DDSHeader *header;
	
	unsigned int levelSize, width, height, pitch;
	
	NuAssert(size >= 4);
	NuAssert(strcmp((char *) buffer, DDS_MAGIC));
	size -= 4;
	buffer += 4;
	
	header = (DDSHeader *) buffer;
	
	NuAssert(header->headerSize == sizeof(DDSHeader));
	NuAssert(header->pixelFormat.size == sizeof(DDSPixelFormat));
	
	size -= sizeof(DDSHeader);
	buffer += sizeof(DDSHeader);
	
	height = dds->height = header->height;
	width = dds->width = header->width;
	dds->depth = header->depth;
	dds->mipmapCount = header->mipmapCount;
	
	dds->bufferCount = 0;
	
	if((header->pixelFormat.flags & 0x00000040) != 0) {
		switch(header->pixelFormat.bitCount) {
			case 32:
				pitch = dds->pitch = 4 * header->width;
				dds->format = URGBA32;
				break;
			default:
				NuError("Unsupported uncompressed format");
		}
	} else if((header->pixelFormat.flags & 0x00000004) != 0){
		switch(header->pixelFormat.fourCC[3]) {
			case '1':
				dds->format = DXT1;
				break;
			case '2':
				dds->format = DXT2;
				break;
			case '3':
				dds->format = DXT3;
				break;
			case '4':
				dds->format = DXT4;
				break;
			case '5':
				dds->format = DXT5;
				break;
			default:
				NuError("Unsupported DDS format");
				break;
		}
	} else {
		NuError("Unsupported DDS flags: 0x%08X", header->pixelFormat.flags);
	}
		
	if((header->pixelFormat.flags & 0x00000040) == 0) {
		pitch = dds->pitch = header->width >> 2 >> 2;
		// Twice since the height is supposed to be divided by two as well -- 
		// this is evil and dirty
		
		if(dds->format == DXT1) {
			dds->pitch <<= 3;
			pitch <<= 3;
		}
		else {
			dds->pitch <<= 4;
			pitch <<= 4;
		}
	}
	
	while(width > 0 && height > 0 && dds->bufferCount < 32) {
		if((header->pixelFormat.flags & 0x00000040) != 0) {
			levelSize = height * pitch;
		}
		else {
			levelSize = (height >> 2) * (width >> 2);
			
			if(levelSize == 0)
				levelSize = 1;
			
			if(header->pixelFormat.fourCC[3] == '1')
				levelSize *= 8;
			else
				levelSize *= 16;
		}
		
		if(size < levelSize)
			break;
		
		dds->bufferSizes[dds->bufferCount] = levelSize;
		dds->buffers[dds->bufferCount] = (void *) malloc(levelSize);
		memcpy(dds->buffers[dds->bufferCount], buffer, levelSize);
		size -= levelSize;
		buffer += levelSize;
		
		pitch >>= 1;
		width >>= 1;
		height >>= 1;
		++dds->bufferCount;
		
		if((header->caps.caps & 0x00400000) == 0)
			break;
	}
	
	return dds;
}

WINAPI void DDS_Free(DDS *dds) 
{
	while(dds->bufferCount > 0)
		free(dds->buffers[--dds->bufferCount]);
	
	free(dds);
}
