/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_CLASSES_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREEDX_DTHREEDX_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

CLASS(
	ID3DX10Font,
	STRUCT(),
	VTABLE(
		CSTUB(ID3DX10Font_QueryInterface),
		CSTUB(ID3DX10Font_AddRef),
		CSTUB(ID3DX10Font_Release),
		CSTUB(ID3DX10Font_GetDevice),
		CSTUB(ID3DX10Font_GetDescA),
		CSTUB(ID3DX10Font_GetDescW),
		CSTUB(ID3DX10Font_GetTextMetricsA),
		CSTUB(ID3DX10Font_GetTextMetricsW),
		CSTUB(ID3DX10Font_GetDC),
		CSTUB(ID3DX10Font_GetGlyphData),
		CSTUB(ID3DX10Font_PreloadCharacters),
		CSTUB(ID3DX10Font_PreloadGlyphs),
		CSTUB(ID3DX10Font_PreloadTextA),
		CSTUB(ID3DX10Font_PreloadTextW),
		CSTUB(ID3DX10Font_DrawTextA),
		CMEMBER(ID3DX10Font_DrawTextW)
	)
);

CLASS(
	ID3DX10Sprite,
	STRUCT(
		/* ID3D10Device */ void *device;
	),
	VTABLE(
		CSTUB(ID3DX10Sprite_QueryInterface),
		CSTUB(ID3DX10Sprite_AddRef),
		CSTUB(ID3DX10Sprite_Release),
		CMEMBER(ID3DX10Sprite_Begin),
		CMEMBER(ID3DX10Sprite_DrawSpritesBuffered),
		CSTUB(ID3DX10Sprite_Flush),
		CSTUB(ID3DX10Sprite_DrawSpritesImmediate),
		CMEMBER(ID3DX10Sprite_End),
		CSTUB(ID3DX10Sprite_GetViewTransform),
		CSTUB(ID3DX10Sprite_SetViewTransform),
		CSTUB(ID3DX10Sprite_GetProjectionTransform),
		CMEMBER(ID3DX10Sprite_SetProjectionTransform),
		CMEMBER(ID3DX10Sprite_GetDevice)
	)
);

#endif
