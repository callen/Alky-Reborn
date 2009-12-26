/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"


WINAPI HRESULT IDirect3DDevice9_Release(
    void *this_
) {
	NuWarn("IDirect3DDevice9::Release not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_GetDeviceCaps(
    void *this_,
    D3DCAPS9 *pCaps
) {
	NuWarn("IDirect3DDevice9::GetDeviceCaps not yet implemented");
	
	return IDirect3D9_GetDeviceCaps(None, 0, 0, pCaps);
}

WINAPI HRESULT IDirect3DDevice9_Present(
	void *this_,
	RECT *pSourceRect,
	RECT *pDestRect,
	HWND hDestWindowOverride,
	RGNDATA *pDirtyRegion
) {
	NuLog("IDirect3DDevice9::Present");
	
	if(pSourceRect || pDestRect || hDestWindowOverride || pDirtyRegion)
		NuWarn("Region presentation not supported");
	
	NuGUI_SwapBuffers(NULL);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_CreateTexture(
	void *this_,
	UINT Width,
	UINT Height,
	UINT Levels,
	DWORD Usage,
	D3DFORMAT Format,
	D3DPOOL Pool,
	void **ppTexture,
	HANDLE *pSharedHandle
) {
	CSTRUCT(IDirect3DDevice9) *_Device;
	
	NuLog("IDirect3DDevice9::CreateTexture(%p)", this_);
	
	_Device = GET_CLASS_STRUCT(IDirect3DDevice9, this_);
	
	NuLog("%p", _Device);
	
	INIT_CLASS(IDirect3DTexture9, *ppTexture);
	IDirect3DTexture9_Init(
		*ppTexture,
		Width,
		Height,
		Levels,
		Format
	);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_CreateCubeTexture(
	void *this_,
	UINT EdgeLength,
	UINT Levels,
	DWORD Usage,
	D3DFORMAT Format,
	D3DPOOL Pool,
	void **ppCubeTexture,
	HANDLE *pSharedHandle
) {
	NuLog("IDirect3DDevice9::CreateCubeTexture");
	
	INIT_CLASS(IDirect3DCubeTexture9, *ppCubeTexture);
	IDirect3DCubeTexture9_Init(
		*ppCubeTexture,
		EdgeLength,
		Levels,
		Format
	);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_CreateVertexBuffer(
	void *this_,
	UINT Length,
	DWORD Usage,
	DWORD FVF,
	D3DPOOL Pool,
	void** ppVertexBuffer,
	HANDLE* pSharedHandle
) {
	CSTRUCT(IDirect3DVertexBuffer9) *_Context;
	
	NuLog("IDirect3DDevice9::CreateVertexBuffer");
	
	INIT_CLASS(IDirect3DVertexBuffer9, *ppVertexBuffer);
	
	_Context = GET_CLASS_STRUCT(IDirect3DVertexBuffer9, *ppVertexBuffer);
	
	_Context->length = 0;
	
	if(FVF & D3DFVF_XYZ)
		_Context->length += 12;
	if(FVF & D3DFVF_DIFFUSE)
		_Context->length += 4;
	
	_Context->vertexCount = Length;
	
	_Context->fvf = FVF;
	_Context->vertexBuffer = NuMemory_Alloc(_Context->length * Length);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_GetRenderTarget(
	void *this_,
	DWORD RenderTargetIndex,
	void **ppRenderTarget
) {
	CSTRUCT(IDirect3DDevice9) *_Device;
	
	NuWarn("IDirect3DDevice9::GetRenderTarget not yet implemented");
	
	_Device = GET_CLASS_STRUCT(IDirect3DDevice9, this_);
	
	INIT_CLASS(IDirect3DSurface9, *ppRenderTarget);
	
	IDirect3DSurface9_Init(
		*ppRenderTarget,
		1024,
		768,
		D3DFMT_X8R8G8B8
	);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_GetDepthStencilSurface(
	void *this_,
	void **ppZStencilSurface
) {
	NuWarn("IDirect3DDevice9::GetDepthStencilSurface not yet implemented");
	
	INIT_CLASS(IDirect3DSurface9, *ppZStencilSurface);
	
	IDirect3DSurface9_Init(
		*ppZStencilSurface,
		1024,
		768,
		D3DFMT_X8R8G8B8
	);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_BeginScene(
	void *this_
) {
	NuLog("IDirect3DDevice9::BeginScene");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_EndScene(
	void *this_
) {
	NuLog("IDirect3DDevice9::EndScene");
	
	return S_OK;
}

#define D3DToRed(d3d)   ((float) ((d3d & 0x00FF0000) >> 16) / 255.0f)
#define D3DToGreen(d3d) ((float) ((d3d & 0x0000FF00) >>  8) / 255.0f)
#define D3DToBlue(d3d)  ((float) ((d3d & 0x000000FF)      ) / 255.0f)
#define D3DToAlpha(d3d) ((float) ((d3d & 0xFF000000) >> 24) / 255.0f)

WINAPI HRESULT IDirect3DDevice9_Clear(
	void *this_,
	DWORD Count,
	const D3DRECT *pRects,
	DWORD Flags,
	D3DCOLOR Color,
	float Z,
	DWORD Stencil
) {
	GLbitfield mask = 0;
	
	GLfloat glcolor[4];
	
	if(pRects != None) {
		NuWarn("IDirect3DDevice9::Clear ignores pRects and redraws the whole screen");
	}
	
	if(Flags & D3DCLEAR_STENCIL)
		mask |= GL_STENCIL_BUFFER_BIT;
	if(Flags & D3DCLEAR_TARGET)
		mask |= GL_COLOR_BUFFER_BIT;
	if(Flags & D3DCLEAR_ZBUFFER)
		mask |= GL_DEPTH_BUFFER_BIT;
	
	glClearColor(D3DToRed(Color), D3DToGreen(Color), D3DToBlue(Color), D3DToAlpha(Color));
	
	glClear(mask);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetTransform(
	void *this_,
	D3DTRANSFORMSTATETYPE State,
	D3DMATRIX* pMatrix
) {
	NuLog("IDirect3DDevice9::SetTransform");
	
	switch(State) {
		case D3DTS_WORLD:
		case D3DTS_VIEW:
			glMatrixMode(GL_MODELVIEW);
			break;
		case D3DTS_PROJECTION:
			glMatrixMode(GL_PROJECTION);
			break;
		default:
			NuError("Unsupported state %i to IDirect3DDevice9::SetTransform", State);
	}
	
	glMultMatrixf(pMatrix->oglMatrix);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetViewport(
    void *this_,
    CONST D3DVIEWPORT9 *pViewport
) {
	NuLog("IDirect3DDevice9::SetViewport");
	
	if(
		pViewport->X != 0 ||
		pViewport->Y != 0
	)
		NuError("Rendering subsets is not supported");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetMaterial(
	void *this_,
	CONST D3DMATERIAL9 *pMaterial
) {
	bool useDiffuse = D3DCOLORVALUE_NONZERO(pMaterial->Diffuse.value);
	bool useAmbient = D3DCOLORVALUE_NONZERO(pMaterial->Ambient.value);
	bool useSpecular = D3DCOLORVALUE_NONZERO(pMaterial->Specular.value);
	bool useEmissive = D3DCOLORVALUE_NONZERO(pMaterial->Emissive.value);
	
	if(useDiffuse && useAmbient && D3DCOLORVALUE_EQUAL(pMaterial->Diffuse, pMaterial->Ambient)) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, pMaterial->Diffuse.value);
		
		useDiffuse = False;
		useAmbient = False;
	}
	
	if(useDiffuse)
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pMaterial->Diffuse.value);
	
	if(useAmbient)
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pMaterial->Ambient.value);
	
	if(useSpecular)
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, pMaterial->Specular.value);
	
	if(useEmissive)
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, pMaterial->Emissive.value);
	
	if(pMaterial->Power != 0.0f)
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, pMaterial->Power);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetLight(
	void *this_,
	DWORD Index,
	CONST D3DLIGHT9 *pLight
) {
	GLfloat vec4[4];
	
	Index += GL_LIGHT0;
	
	if(D3DCOLORVALUE_NONZERO(pLight->Diffuse.value))
		glLightfv(Index, GL_DIFFUSE, pLight->Diffuse.value);
	
	if(D3DCOLORVALUE_NONZERO(pLight->Specular.value))
		glLightfv(Index, GL_SPECULAR, pLight->Specular.value);
	
	if(D3DCOLORVALUE_NONZERO(pLight->Ambient.value))
		glLightfv(Index, GL_AMBIENT, pLight->Ambient.value);
	
	if(
		pLight->Position.vec[0] != 0.0f ||
		pLight->Position.vec[1] != 0.0f || 
		pLight->Position.vec[2] != 0.0f
	) {
		memcpy(vec4, pLight->Position.vec, sizeof(float) * 3);
		vec4[3] = 1.0f;
		
		glLightfv(Index, GL_POSITION, vec4);
	}
	
	if(
		pLight->Direction.vec[0] != 0.0f ||
		pLight->Direction.vec[1] != 0.0f || 
		pLight->Direction.vec[2] != 0.0f
	) {
		if(pLight->Type == D3DLIGHT_DIRECTIONAL) {
			memcpy(vec4, pLight->Direction.vec, sizeof(float) * 3);
			vec4[3] = 0.0f;
			
			glLightfv(Index, GL_POSITION, vec4);
		}
		else
			glLightfv(Index, GL_SPOT_DIRECTION, pLight->Direction.vec);
	}
	
	if(pLight->Attenuation0 != 0.0f)
		glLightf(Index, GL_CONSTANT_ATTENUATION, pLight->Attenuation0);
	
	if(pLight->Attenuation1 != 0.0f)
		glLightf(Index, GL_LINEAR_ATTENUATION, pLight->Attenuation1);
	
	if(pLight->Attenuation2 != 0.0f)
		glLightf(Index, GL_QUADRATIC_ATTENUATION, pLight->Attenuation2);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_LightEnable(
	void *this_,
	DWORD Index,
	BOOL Enable
) {
	if(Enable)
		glEnable(GL_LIGHT0 + Index);
	else
		glDisable(GL_LIGHT0 + Index);
	
	return S_OK;
}

#define SETGLFLAG(flag) \
if(Value) \
	glEnable(flag); \
else \
	glDisable(flag);

WINAPI HRESULT IDirect3DDevice9_SetRenderState(
	void *this_,
	D3DRENDERSTATETYPE State,
	DWORD Value
) {
	GLclampf clamp_temp;
	GLenum enum_temp;
	GLfloat color_temp[4];
	
	NuLog("IDirect3DDevice9::SetRenderState");
	
	switch(State) {
		case D3DRS_ALPHABLENDENABLE:
			SETGLFLAG(GL_BLEND);
			break;
		case D3DRS_ALPHAFUNC:
			glGetFloatv(GL_ALPHA_TEST_REF, &clamp_temp);
			
			switch(Value) {
				case D3DCMP_NEVER:
					glAlphaFunc(GL_NEVER, clamp_temp);
					break;
				case D3DCMP_LESS:
					glAlphaFunc(GL_LESS, clamp_temp);
					break;
				case D3DCMP_EQUAL:
					glAlphaFunc(GL_EQUAL, clamp_temp);
					break;
				case D3DCMP_LESSEQUAL:
					glAlphaFunc(GL_LEQUAL, clamp_temp);
					break;
				case D3DCMP_GREATER:
					glAlphaFunc(GL_GREATER, clamp_temp);
					break;
				case D3DCMP_NOTEQUAL:
					glAlphaFunc(GL_NOTEQUAL, clamp_temp);
					break;
				case D3DCMP_GREATEREQUAL:
					glAlphaFunc(GL_GEQUAL, clamp_temp);
					break;
				case D3DCMP_ALWAYS:
					glAlphaFunc(GL_ALWAYS, clamp_temp);
					break;
			}
			break;
		case D3DRS_ALPHAREF:
			glGetIntegerv(GL_ALPHA_TEST_FUNC, &enum_temp);
			clamp_temp = (float) (Value & 0xFF) / 255.0f;
			glAlphaFunc(enum_temp, clamp_temp);
			break;
		case D3DRS_ALPHATESTENABLE:
			SETGLFLAG(GL_ALPHA_TEST);
			break;
		case D3DRS_AMBIENT:
			color_temp[0] = D3DToRed(Value);
			color_temp[1] = D3DToGreen(Value);
			color_temp[2] = D3DToBlue(Value);
			color_temp[3] = D3DToAlpha(Value);
			
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, color_temp);
			
			break;
		case D3DRS_CULLMODE:
			switch(Value) {
				case D3DCULL_NONE:
					glDisable(GL_CULL_FACE);
					break;
				case D3DCULL_CW:
					glCullFace(GL_FRONT);
					glEnable(GL_CULL_FACE);
					break;
				case D3DCULL_CCW:
					glCullFace(GL_BACK);
					glEnable(GL_CULL_FACE);
					break;
			}
			break;
		case D3DRS_DESTBLEND:
			NuWarn("D3DRS_DESTBLEND ignored");
			break;
		case D3DRS_DITHERENABLE:
			SETGLFLAG(GL_DITHER);
			break;
		case D3DRS_FILLMODE:
			switch(Value) {
				case D3DFILL_POINT:
					glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
					break;
				case D3DFILL_WIREFRAME:
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
					break;
				case D3DFILL_SOLID:
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					break;
			}
			break;
		case D3DRS_FOGCOLOR:
			color_temp[0] = (float) (Value & 0xFF) / 255.0f;
			color_temp[1] = (float) ((Value & 0xFF00) >> 8) / 255.0f;
			color_temp[2] = (float) ((Value & 0xFF0000) >> 16) / 255.0f;
			color_temp[3] = (float) ((Value & 0xFF000000) >> 24) / 255.0f;
			glFogfv(GL_FOG_COLOR, color_temp);
			break;
		case D3DRS_FOGENABLE:
			SETGLFLAG(GL_FOG);
			break;
		case D3DRS_FOGTABLEMODE:
			switch(Value) {
				case D3DFOG_NONE:
					glDisable(GL_FOG);
					break;
				case D3DFOG_EXP:
					glFogi(GL_FOG_MODE, GL_EXP);
					break;
				case D3DFOG_EXP2:
					glFogi(GL_FOG_MODE, GL_EXP2);
					break;
				case D3DFOG_LINEAR:
					glFogi(GL_FOG_MODE, GL_LINEAR);
					break;
			}
			break;
		case D3DRS_LASTPIXEL:
			NuWarn("D3DRS_LASTPIXEL ignored");
			break;
		case D3DRS_LIGHTING:
			SETGLFLAG(GL_LIGHTING);
			break;
		case D3DRS_SHADEMODE:
			switch(Value) {
				case D3DSHADE_FLAT:
					glShadeModel(GL_FLAT);
					break;
				case D3DSHADE_GOURAUD:
					glShadeModel(GL_SMOOTH);
					break;
			}
			break;
		case D3DRS_SPECULARENABLE:
			SETGLFLAG(GL_SPECULAR);
			break;
		case D3DRS_SRCBLEND:
			NuWarn("D3DRS_SRCBLEND ignored");
			break;
		case D3DRS_ZENABLE:
			SETGLFLAG(GL_DEPTH_TEST);
			break;
		case D3DRS_ZFUNC:
			NuWarn("D3DRS_ZFUNC ignored");
			break;
		case D3DRS_ZWRITEENABLE:
			NuWarn("D3DRS_ZWRITEENABLE ignored");
			break;
		default:
			NuWarn("Unsupported state %i to IDirect3DDevice9::SetRenderState", State);
	}
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetTexture(
	void *this_,
	DWORD Stage,
	void *pTexture
) {
	void *pSurface;
	CSTRUCT(IDirect3DSurface9) *_Surface;
	
	NuLog("IDirect3DDevice9::SetTexture");
	
	IDirect3DTexture9_GetSurfaceLevel(pTexture, 0, &pSurface);
	_Surface = GET_CLASS_STRUCT(IDirect3DSurface9, pSurface);
	
	glEnable(GL_TEXTURE_2D);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glBindTexture(GL_TEXTURE_2D, _Surface->glTexture);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetTextureStageState(
    void *this_,
    DWORD Stage,
    D3DTEXTURESTAGESTATETYPE Type,
    DWORD Value
) {
	NuWarn("IDirect3DDevice9::SetTextureStageState not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetSamplerState(
    void *this_,
    DWORD Sampler,
    D3DSAMPLERSTATETYPE Type,
    DWORD Value
) {
	NuWarn("IDirect3DDevice9::SetSamplerState not yet implemented");
	
	NuLog("%i %i %i", Sampler, Type, Value);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_DrawPrimitive(
	void *this_,
	D3DPRIMITIVETYPE PrimitiveType,
	UINT StartVertex,
	UINT PrimitiveCount
) {
	CSTRUCT(IDirect3DDevice9) *_Context = GET_CLASS_STRUCT(IDirect3DDevice9, this_);
	CSTRUCT(IDirect3DVertexBuffer9) *buffer;
	
	int i, j;
	unsigned char *vert;
	
	GLenum glmode;
	int vert_count;
	
	GLfloat *vertex;
	GLfloat *vertex_color;
	GLfloat *vertex_normal;
	GLfloat *vertex_texcoords;
	
	GLfloat *fan_origin;
	GLfloat *fan_color;
	
	NuLog("IDirect3DDevice9::DrawPrimitive(%i)", PrimitiveType);
	
	switch(PrimitiveType) {
		case D3DPT_TRIANGLELIST:
			glmode = GL_TRIANGLES;
			
			PrimitiveCount /= 3;
			vert_count = 3;
			PrimitiveCount += vert_count;
			break;
		case D3DPT_TRIANGLESTRIP:
			glmode = GL_TRIANGLE_STRIP;
			
			PrimitiveCount >>= 1;
			vert_count = 2;
			PrimitiveCount += vert_count;
			break;
		case D3DPT_TRIANGLEFAN:
			glmode = GL_TRIANGLE_STRIP;
			
			PrimitiveCount >>= 1;
			vert_count = 2;
			PrimitiveCount += vert_count;
			break;
		default:
			NuError("Unsupported primitive type %i", PrimitiveType);
	}
	
	buffer = GET_CLASS_STRUCT(IDirect3DVertexBuffer9, _Context->stream[_Context->currentStream]);
	vert = buffer->vertexBuffer;
	
	vert += buffer->length * StartVertex;
	
	glBegin(glmode);
	
	switch(PrimitiveType) {
		case D3DPT_TRIANGLEFAN:
			if(_Context->fvf & D3DFVF_XYZ) {
				fan_origin[0] = *((GLfloat *) vert);
				vert += 4;
				fan_origin[1] = *((GLfloat *) vert);
				vert += 4;
				fan_origin[2] = *((GLfloat *) vert);
				vert += 4;
			}
			
			if(_Context->fvf & D3DFVF_DIFFUSE) {
				fan_color[0] = *vert / 255.0f;
				vert += 1;
				fan_color[1] = *vert / 255.0f;
				vert += 1;
				fan_color[2] = *vert / 255.0f;
				vert += 1;
				fan_color[3] = *vert / 255.0f;
				vert += 1;
			}
			
			for(i = 0; i < PrimitiveCount - 1; ++i) {
				if(_Context->fvf & D3DFVF_DIFFUSE)
					glColor4fv(fan_color);
				if(_Context->fvf & D3DFVF_XYZ)
					glVertex3fv(fan_origin);
				
				for(j = 0; j < 2; ++j) {
					if(_Context->fvf & D3DFVF_XYZ) {
						vertex[0] = *((GLfloat *) vert);
						vert += 4;
						vertex[1] = *((GLfloat *) vert);
						vert += 4;
						vertex[2] = *((GLfloat *) vert);
						vert += 4;
					}
					
					if(_Context->fvf & D3DFVF_DIFFUSE) {
						vertex_color[0] = *vert / 255.0f;
						vert += 1;
						vertex_color[1] = *vert / 255.0f;
						vert += 1;
						vertex_color[2] = *vert / 255.0f;
						vert += 1;
						vertex_color[3] = *vert / 255.0f;
						vert += 1;
						
						glColor4fv(vertex_color);
					}
					
					if(_Context->fvf & D3DFVF_XYZ) {
						glVertex3fv(vertex);
					}
				}
			}
			break;
		default:
			for(i = 0; i < PrimitiveCount; ++i) {
				for(j = 0; j < vert_count; ++j) {
					if((_Context->fvf & D3DFVF_XYZ) || (_Context->fvf & D3DFVF_XYZRHW)) {
						vertex = (GLfloat *) vert;
						vert += 12;
						
						if(_Context->fvf & D3DFVF_XYZRHW)
							vert += 4;
					}
					
					if(_Context->fvf & D3DFVF_DIFFUSE) {
						vertex_color = (GLbyte *) vert;
						vert += 4;
						
						glColor4bv(vertex_color);
					}
					
					if(_Context->fvf & D3DFVF_NORMAL) {
						vertex_normal = (GLfloat *) vert;
						vert += 12;
						
						glNormal3fv(vertex_normal);
					}
					
					if(_Context->fvf & D3DFVF_TEX1) {
						vertex_texcoords = (GLfloat *) vert;
						vert += 8;
						
						glTexCoord2fv(vertex_texcoords);
					}
					
					if((_Context->fvf & D3DFVF_XYZ) || (_Context->fvf & D3DFVF_XYZRHW)) {
						glVertex3fv(vertex);
					}
				}
			}
			break;
	}
	
	glEnd();
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetFVF(
	void *this_,
	DWORD fvf
) {
	CSTRUCT(IDirect3DDevice9) *_Context = GET_CLASS_STRUCT(IDirect3DDevice9, this_);
	
	NuLog("IDirect3DDevice9::SetFVF");
	
	_Context->fvf = fvf;
	
	fvf &= ~D3DFVF_DIFFUSE;
	fvf &= ~D3DFVF_XYZ;
	fvf &= ~D3DFVF_XYZRHW;
	fvf &= ~D3DFVF_NORMAL;
	fvf &= ~D3DFVF_TEX1;
	
	if(fvf != 0)
		NuError("Unsupported FVF: %i %p", fvf, fvf);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_CreateVertexShader(
	void *this_,
	CONST DWORD *pFunction,
	void **ppShader
) {
	NuWarn("IDirect3DDevice9::CreateVertexShader not yet implemented");
	
	*ppShader = 0xDEADBEEF;
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_SetStreamSource(
	void *this_,
	UINT StreamNumber,
	void *pStreamData,
	UINT OffsetInBytes,
	UINT Stride
) {
	CSTRUCT(IDirect3DDevice9) *_Context = GET_CLASS_STRUCT(IDirect3DDevice9, this_);
	
	NuLog("IDirect3DDevice9::SetStreamSource");
	
	_Context->currentStream = StreamNumber;
	_Context->stream[StreamNumber] = pStreamData;
	
	return S_OK;
}

WINAPI HRESULT IDirect3DDevice9_CreatePixelShader(
	void *this_,
	CONST DWORD *pFunction,
	void **ppShader
) {
	NuWarn("IDirect3DDevice9::CreatePixelShader not yet implemented");
	
	*ppShader = 0xDEADBEEF;
	
	return S_OK;
}
