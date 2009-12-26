/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __APIS_WINDOWS_DIRECTX_DTHREEDX_DTHREEDX_H__
#define __APIS_WINDOWS_DIRECTX_DTHREEDX_DTHREEDX_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

typedef struct D3DXVECTOR3 {
	FLOAT x, y, z;
} D3DXVECTOR3, *LPD3DXVECTOR3;

typedef struct D3DXMACRO {
	LPCSTR Name;
	LPCSTR Definition;
} D3DXMACRO, *LPD3DXMACRO;

typedef struct _D3DXMATRIX {
    union {
        struct {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;

        };
        float m[4][4];
        GLfloat oglMatrix[16];
    };
} D3DXMATRIX;

#pragma pack(1)
typedef struct BMPHeader_s {
   unsigned short int type;
   unsigned int size;
   unsigned short int reserved1, reserved2;
   unsigned int offset;
} BMPHeader;

typedef struct BMPInfo_s {
	unsigned int size;
	int width, height;
	unsigned short planes, bits;
	unsigned int compression;
	unsigned int imagesize;
	int xRes, yRes;
	unsigned int colors;
	unsigned int importantColors;
} BMPInfo;
#pragma pack()

typedef void *LPD3DXBUFFER;
typedef void *LPD3DXCONSTANTTABLE;
typedef void *LPD3DXINCLUDE;

WINAPI inline D3DXMATRIX *D3DXMatrixLookAtLH(
    D3DXMATRIX *pOut,
    CONST D3DXVECTOR3 *pEye,
    CONST D3DXVECTOR3 *pAt,
    CONST D3DXVECTOR3 *pUp
);

WINAPI inline D3DXMATRIX *D3DXMatrixPerspectiveFovLH(
	D3DXMATRIX *pOut,
	FLOAT fovY,
	FLOAT Aspect,
	FLOAT zn,
	FLOAT zf
);

WINAPI inline D3DXMATRIX *D3DXMatrixRotationX(
	D3DXMATRIX *pOut,
	FLOAT Angle
);

WINAPI inline D3DXVECTOR3 *D3DXVec3Cross(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
);

WINAPI inline FLOAT D3DXVec3Dot(
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
);

WINAPI inline D3DXVECTOR3 *D3DXVec3Subtract(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
);

WINAPI inline D3DXVECTOR3 *D3DXVec3Normalize(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV
);

WINAPI HRESULT D3DXCompileShader(
	LPCSTR pSrcData,
	UINT srcDataLen,
	CONST D3DXMACRO *pDefines,
	LPD3DXINCLUDE pInclude,
	LPCSTR pFunctionName,
	LPCSTR pProfile,
	DWORD Flags,
	LPD3DXBUFFER *ppShader,
	LPD3DXBUFFER *ppErrorMsgs,
	LPD3DXCONSTANTTABLE *ppConstantTable
);

WINAPI HRESULT D3DXCreateTextureFromFileA(
	void *pDevice,
	LPCSTR pSrcFile,
	void **ppTexture
);

/*
DECLARE_INTERFACE_(ID3DXConstantTable, IUnknown)
{
    // IUnknown
    STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID *ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // Buffer
    STDMETHOD_(LPVOID, GetBufferPointer)(THIS) PURE;
    STDMETHOD_(DWORD, GetBufferSize)(THIS) PURE;

    // Descs
    STDMETHOD(GetDesc)(THIS_ D3DXCONSTANTTABLE_DESC *pDesc) PURE;
    STDMETHOD(GetConstantDesc)(THIS_ D3DXHANDLE hConstant, D3DXCONSTANT_DESC *pConstantDesc, UINT *pCount) PURE;
    STDMETHOD_(UINT, GetSamplerIndex)(THIS_ D3DXHANDLE hConstant) PURE;

    // Handle operations
    STDMETHOD_(D3DXHANDLE, GetConstant)(THIS_ D3DXHANDLE hConstant, UINT Index) PURE;
    STDMETHOD_(D3DXHANDLE, GetConstantByName)(THIS_ D3DXHANDLE hConstant, LPCSTR pName) PURE;
    STDMETHOD_(D3DXHANDLE, GetConstantElement)(THIS_ D3DXHANDLE hConstant, UINT Index) PURE;

    // Set Constants
    STDMETHOD(SetDefaults)(THIS_ LPDIRECT3DDEVICE9 pDevice) PURE;
    STDMETHOD(SetValue)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, LPCVOID pData, UINT Bytes) PURE;
    STDMETHOD(SetBool)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, BOOL b) PURE;
    STDMETHOD(SetBoolArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST BOOL* pb, UINT Count) PURE;
    STDMETHOD(SetInt)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, INT n) PURE;
    STDMETHOD(SetIntArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST INT* pn, UINT Count) PURE;
    STDMETHOD(SetFloat)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, FLOAT f) PURE;
    STDMETHOD(SetFloatArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST FLOAT* pf, UINT Count) PURE;
    STDMETHOD(SetVector)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXVECTOR4* pVector) PURE;
    STDMETHOD(SetVectorArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXVECTOR4* pVector, UINT Count) PURE;
    STDMETHOD(SetMatrix)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX* pMatrix) PURE;
    STDMETHOD(SetMatrixArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX* pMatrix, UINT Count) PURE;
    STDMETHOD(SetMatrixPointerArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX** ppMatrix, UINT Count) PURE;
    STDMETHOD(SetMatrixTranspose)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX* pMatrix) PURE;
    STDMETHOD(SetMatrixTransposeArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX* pMatrix, UINT Count) PURE;
    STDMETHOD(SetMatrixTransposePointerArray)(THIS_ LPDIRECT3DDEVICE9 pDevice, D3DXHANDLE hConstant, CONST D3DXMATRIX** ppMatrix, UINT Count) PURE;
};
*/

WINAPI HRESULT ID3DXConstantTable_Release(
	void *this_
);

/*
DECLARE_INTERFACE_(ID3DXBuffer, IUnknown)
{
    // IUnknown
    STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID *ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ID3DXBuffer
    STDMETHOD_(LPVOID, GetBufferPointer)(THIS) PURE;
    STDMETHOD_(DWORD, GetBufferSize)(THIS) PURE;
};
*/

WINAPI HRESULT ID3DXBuffer_Init(
	void *this_,
	DWORD bytes,
	void *buffer
);

WINAPI HRESULT ID3DXBuffer_Release(
	void *this_
);

WINAPI LPVOID ID3DXBuffer_GetBufferPointer(
	void *this_
);

WINAPI LPVOID ID3DXBuffer_GetBufferSize(
	void *this_
);

#endif
