/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_TYPES_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_TYPES_H__

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_H__
#define DTHREEDX_HACK
#endif

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Types.h>
#include <APIs/Windows/DirectX/DX10/D3DX/DDS.h>
#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

#ifdef DTHREEDX_HACK
#undef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_H__
#undef DTHREEDX_HACK
#endif

typedef enum D3DX10_IMAGE_FILE_FORMAT
{
    D3DX10_IFF_BMP = 0,
    D3DX10_IFF_JPG = 1,
    D3DX10_IFF_PNG = 3,
    D3DX10_IFF_DDS = 4,
    D3DX10_IFF_TIFF = 10,
    D3DX10_IFF_GIF = 11,
    D3DX10_IFF_WMP = 12,
    D3DX10_IFF_FORCE_DWORD = 0x7fffffff,
} D3DX10_IMAGE_FILE_FORMAT, *LPD3DX10_IMAGE_FILE_FORMAT;

typedef struct D3DX10_IMAGE_INFO {
	UINT Width;
	UINT Height;
	UINT Depth;
	UINT ArraySize;
	UINT MipLevels;
	UINT MiscFlags;
	DXGI_FORMAT Format;
	D3D10_RESOURCE_DIMENSION ResourceDimension;
	D3DX10_IMAGE_FILE_FORMAT ImageFileFormat;
} D3DX10_IMAGE_INFO, *LPD3DX10_IMAGE_INFO;

typedef struct D3DX10_IMAGE_LOAD_INFO {
	UINT Width;
	UINT Height;
	UINT Depth;
	UINT FirstMipLevel;
	UINT MipLevels;
	D3D10_USAGE Usage;
	UINT BindFlags;
	UINT CpuAccessFlags;
	UINT MiscFlags;
	DXGI_FORMAT Format;
	UINT Filter;
	UINT MipFilter;
	D3DX10_IMAGE_INFO *pSrcInfo;
} D3DX10_IMAGE_LOAD_INFO, *LPD3DX10_IMAGE_LOAD_INFO;

typedef struct D3DXMATRIX { 
	union {
    	struct { 
			FLOAT _11; FLOAT _12; FLOAT _13; FLOAT _14;
		    FLOAT _21; FLOAT _22; FLOAT _23; FLOAT _24;
		    FLOAT _31; FLOAT _32; FLOAT _33; FLOAT _34;
		    FLOAT _41; FLOAT _42; FLOAT _43; FLOAT _44;
		} dx;
		
		FLOAT gl[16];
	};
} D3DXMATRIX;

typedef struct D3DXVECTOR2 {
	union {
		struct {
		    FLOAT x;
		    FLOAT y;
		};
		
		FLOAT vec[2];
	};
} D3DXVECTOR2, *LPD3DXVECTOR2;

typedef struct D3DXVECTOR3 {
	union {
		struct {
		    FLOAT x;
		    FLOAT y;
		    FLOAT z;
		};
		
		FLOAT vec[3];
	};
} D3DXVECTOR3, *LPD3DXVECTOR3;

typedef struct D3DXVECTOR4 {
	union {
		struct {
		    FLOAT x;
		    FLOAT y;
		    FLOAT z;
		    FLOAT w;
		};
		
		FLOAT vec[4];
	};
} D3DXVECTOR4, *LPD3DXVECTOR4;

typedef struct D3DXCOLOR {
    FLOAT r;
    FLOAT g;
    FLOAT b;
    FLOAT a;
} D3DXCOLOR, *LPD3DXCOLOR;

typedef struct D3DX10_SPRITE {
    D3DXMATRIX matWorld;
    D3DXVECTOR2 TexCoord;
    D3DXVECTOR2 TexSize;
    D3DXCOLOR ColorModulate;
    /* ID3D10ShaderResourceView */ void *pTexture;
    UINT TextureIndex;
} D3DX10_SPRITE;

#define LF_FACESIZE 32

typedef struct D3DX10_FONT_DESCA {
    INT Height;
    UINT Width;
    UINT Weight;
    UINT MipLevels;
    BOOL Italic;
    BYTE CharSet;
    BYTE OutputPrecision;
    BYTE Quality;
    BYTE PitchAndFamily;
    CHAR FaceName[LF_FACESIZE];
} D3DX10_FONT_DESCA, *LPD3DX10_FONT_DESCA;

typedef struct D3DX10_FONT_DESCW {
    INT Height;
    UINT Width;
    UINT Weight;
    UINT MipLevels;
    BOOL Italic;
    BYTE CharSet;
    BYTE OutputPrecision;
    BYTE Quality;
    BYTE PitchAndFamily;
    WCHAR FaceName[LF_FACESIZE];
} D3DX10_FONT_DESCW, *LPD3DX10_FONT_DESCW;

#endif
