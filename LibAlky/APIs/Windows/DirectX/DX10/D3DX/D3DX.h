/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_H__

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Types.h>
#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

#include <APIs/Windows/DirectX/DX10/D3DX/DDS.h>

typedef struct _D3D10_SHADER_MACRO {
	LPCSTR Name;
	LPCSTR Definition;
} D3D10_SHADER_MACRO, *LPD3D10_SHADER_MACRO;

/* Effect.c */

WINAPI HRESULT D3DX10CreateEffectFromFileA(
	LPCSTR pFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
 	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
);

WINAPI HRESULT D3DX10CreateEffectFromFileW(
	LPWSTR pFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
 	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
);

WINAPI HRESULT D3DX10CreateEffectFromMemory(
	LPCVOID pData, 
	SIZE_T DataLength, 
	LPCSTR pSrcFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
);

/* Font.c */

WINAPI HRESULT D3DX10CreateFontA(
  /* ID3D10Device */ void *pDevice,
  INT Height,
  UINT Width,
  UINT Weight,
  UINT MipLevels,
  BOOL Italic,
  UINT CharSet,
  UINT OutputPrecision,
  UINT Quality,
  UINT PitchAndFamily,
  LPCSTR pFaceName,
  /* ID3DX10FONT */ void **ppFont
);

WINAPI HRESULT D3DX10CreateFontW(
  /* ID3D10Device */ void *pDevice,
  INT Height,
  UINT Width,
  UINT Weight,
  UINT MipLevels,
  BOOL Italic,
  UINT CharSet,
  UINT OutputPrecision,
  UINT Quality,
  UINT PitchAndFamily,
  LPCWSTR pFaceName,
  /* ID3DX10FONT */ void **ppFont
);

WINAPI HRESULT ID3DX10Font_QueryInterface(/* ID3DX10Font */ void *this, REFIID iid, LPVOID *ppv);
WINAPI ULONG ID3DX10Font_AddRef(/* ID3DX10Font */ void *this);
WINAPI ULONG ID3DX10Font_Release(/* ID3DX10Font */ void *this);
WINAPI HRESULT ID3DX10Font_GetDevice(/* ID3DX10Font */ void *this, /* ID3D10Device */ void ** ppDevice);
WINAPI void ID3DX10Font_GetDescA(/* ID3DX10Font */ void *this, D3DX10_FONT_DESCA *pDesc);
WINAPI void ID3DX10Font_GetDescW(/* ID3DX10Font */ void *this, D3DX10_FONT_DESCW *pDesc);
WINAPI BOOL ID3DX10Font_GetTextMetricsA(/* ID3DX10Font */ void *this, TEXTMETRICA *pTextMetrics);
WINAPI BOOL ID3DX10Font_GetTextMetricsW(/* ID3DX10Font */ void *this, TEXTMETRICW *pTextMetrics);
WINAPI HDC ID3DX10Font_GetDC(/* ID3DX10Font */ void *this);
WINAPI void ID3DX10Font_GetGlyphData(/* ID3DX10Font */ void *this, UINT Glyph, /* ID3D10ShaderResourceView */ void ** ppTexture, RECT *pBlackBox, POINT *pCellInc);
WINAPI void ID3DX10Font_PreloadCharacters(/* ID3DX10Font */ void *this, UINT First, UINT Last);
WINAPI void ID3DX10Font_PreloadGlyphs(/* ID3DX10Font */ void *this, UINT First, UINT Last);
WINAPI void ID3DX10Font_PreloadTextA(/* ID3DX10Font */ void *this, LPCSTR pString, INT Count);
WINAPI void ID3DX10Font_PreloadTextW(/* ID3DX10Font */ void *this, LPCWSTR pString, INT Count);
WINAPI INT ID3DX10Font_DrawTextA(/* ID3DX10Font */ void *this, /* ID3DX10SPRITE */ void *pSprite, LPCSTR pString, INT Count, LPRECT pRect, UINT Format, D3DXCOLOR Color);
WINAPI INT ID3DX10Font_DrawTextW(/* ID3DX10Font */ void *this, /* ID3DX10SPRITE */ void *pSprite, LPCWSTR pString, INT Count, LPRECT pRect, UINT Format, D3DXCOLOR Color);

/* Matrix.c */

WINAPI D3DXMATRIX * D3DXMatrixLookAtLH(
  D3DXMATRIX *pOut,
  CONST D3DXVECTOR3 *pEye,
  CONST D3DXVECTOR3 *pAt,
  CONST D3DXVECTOR3 *pUp
);

WINAPI D3DXMATRIX * D3DXMatrixMultiply(
  D3DXMATRIX * pOut,
  CONST D3DXMATRIX *pM1,
  CONST D3DXMATRIX *pM2
);

WINAPI D3DXMATRIX * D3DXMatrixPerspectiveFovLH(
  D3DXMATRIX * pOut,
  FLOAT fovy,
  FLOAT Aspect,
  FLOAT zn,
  FLOAT zf
);

WINAPI D3DXMATRIX * D3DXMatrixRotationY(
  D3DXMATRIX * pOut,
  FLOAT Angle
);

WINAPI D3DXMATRIX * D3DXMatrixScaling(
  D3DXMATRIX * pOut,
  FLOAT sx,
  FLOAT sy,
  FLOAT sz
);

WINAPI D3DXMATRIX *D3DXMatrixTranslation(
	D3DXMATRIX *pOut,
	FLOAT x,
	FLOAT y,
	FLOAT z
);

/* Mesh.c */

WINAPI HRESULT D3DX10CreateMesh(
  /* ID3D10Device */ void *pDevice,
  CONST D3D10_INPUT_ELEMENT_DESC *pDeclaration,
  UINT DeclCount,
  LPCSTR pPositionSemantic,
  UINT VertexCount,
  UINT FaceCount,
  UINT Options,
  /* ID3DX10Mesh */ void **ppMesh
);

/* Sprite.c */

WINAPI HRESULT ID3DX10Sprite_QueryInterface(/* ID3DX10Sprite */ void *this, REFIID iid, LPVOID *ppv);
WINAPI ULONG ID3DX10Sprite_AddRef(/* ID3DX10Sprite */ void *this);
WINAPI ULONG ID3DX10Sprite_Release(/* ID3DX10Sprite */ void *this);
WINAPI HRESULT ID3DX10Sprite_Begin(/* ID3DX10Sprite */ void *this, UINT flags);
WINAPI HRESULT ID3DX10Sprite_DrawSpritesBuffered(/* ID3DX10Sprite */ void *this, D3DX10_SPRITE *pSprites, UINT cSprites);
WINAPI void ID3DX10Sprite_Flush(/* ID3DX10Sprite */ void *this);
WINAPI void ID3DX10Sprite_DrawSpritesImmediate(/* ID3DX10Sprite */ void *this, D3DX10_SPRITE *pSprites, UINT cSprites, UINT cbSprite, UINT flags);
WINAPI HRESULT ID3DX10Sprite_End(/* ID3DX10Sprite */ void *this);
WINAPI void ID3DX10Sprite_GetViewTransform(/* ID3DX10Sprite */ void *this, D3DXMATRIX *pViewTransform);
WINAPI void ID3DX10Sprite_SetViewTransform(/* ID3DX10Sprite */ void *this, D3DXMATRIX *pViewTransform);
WINAPI void ID3DX10Sprite_GetProjectionTransform(/* ID3DX10Sprite */ void *this, D3DXMATRIX *pProjectionTransform);
WINAPI HRESULT ID3DX10Sprite_SetProjectionTransform(/* ID3DX10Sprite */ void *this, D3DXMATRIX *pProjectionTransform);
WINAPI HRESULT ID3DX10Sprite_GetDevice(/* ID3DX10Sprite */ void *this, /* ID3D10Device */ void ** ppDevice);

/* ResourceView.c */

WINAPI HRESULT D3DX10CreateShaderResourceViewFromFileW(
  /* ID3D10Device */ void *pDevice,
  LPCWSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10ShaderResourceView */ void **ppShaderResourceView,
  HRESULT* pHResult
);

/* Sprite.c */

WINAPI HRESULT D3DX10CreateSprite(
  /* ID3D10Device */ void *pDevice,
  UINT cDeviceBufferSize,
  /* ID3DX10SPRITE */ void **ppSprite
);

/* Texture.c */

WINAPI HRESULT D3DX10CreateTextureFromFileA(
  /* ID3D10Device */ void *pDevice,
  LPSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
);

WINAPI HRESULT D3DX10CreateTextureFromFileW(
  /* ID3D10Device */ void *pDevice,
  LPWSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
);

WINAPI HRESULT D3DX10CreateTextureFromMemory(
  /* ID3D10Device */ void *pDevice,
  LPCVOID pSrcData,
  SIZE_T SrcDataSize,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
);

WINAPI HRESULT D3DX10CreateTextureFromResourceW(
  /* ID3D10Device */ void *pDevice,
  HMODULE hSrcModule,
  LPCWSTR pSrcResource,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
);

/* Vector.c */

WINAPI D3DXVECTOR3 * D3DXVec3Cross(
  D3DXVECTOR3 * pOut,
  CONST D3DXVECTOR3 * pV1,
  CONST D3DXVECTOR3 * pV2
);

WINAPI FLOAT D3DXVec3Dot(      
    CONST D3DXVECTOR3 *pV1,
    CONST D3DXVECTOR3 *pV2
);

WINAPI D3DXVECTOR3 * D3DXVec3Normalize(
  D3DXVECTOR3 *pOut,
  CONST D3DXVECTOR3 *pV
);

WINAPI D3DXVECTOR3 * D3DXVec3Subtract(
  D3DXVECTOR3 * pOut,
  CONST D3DXVECTOR3 * pV1,
  CONST D3DXVECTOR3 * pV2
);

WINAPI D3DXVECTOR4 *D3DXVec3Transform(
  D3DXVECTOR4 *pOut,
  CONST D3DXVECTOR3 *pV,
  CONST D3DXMATRIX *pM
);

#endif
