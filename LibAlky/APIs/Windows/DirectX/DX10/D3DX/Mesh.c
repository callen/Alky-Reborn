/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI HRESULT D3DX10CreateMesh(
  /* ID3D10Device */ void *pDevice,
  CONST D3D10_INPUT_ELEMENT_DESC *pDeclaration,
  UINT DeclCount,
  LPCSTR pPositionSemantic,
  UINT VertexCount,
  UINT FaceCount,
  UINT Options,
  /* ID3DX10Mesh */ void **ppMesh
) {
	NuWarn("D3DX10CreateMesh not yet implemented");
	
	if(ppMesh) *ppMesh = None;
	
	return S_OK;
}
