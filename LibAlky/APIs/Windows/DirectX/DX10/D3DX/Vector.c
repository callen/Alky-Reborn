/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI D3DXVECTOR3 * D3DXVec3Cross(
  D3DXVECTOR3 * pOut,
  CONST D3DXVECTOR3 * pV1,
  CONST D3DXVECTOR3 * pV2
) {
	pOut->x = pV1->y * pV2->z - pV1->z * pV2->y;
	pOut->y = pV1->z * pV2->x - pV1->x * pV2->z;
	pOut->z = pV1->x * pV2->y - pV1->y * pV2->x;
	
	return pOut;
}

WINAPI FLOAT D3DXVec3Dot(      
    CONST D3DXVECTOR3 *pV1,
    CONST D3DXVECTOR3 *pV2
) {
	return (pV1->x * pV2->x) + (pV1->y * pV2->y) + (pV1->z * pV2->z);
}

WINAPI D3DXVECTOR3 * D3DXVec3Normalize(
  D3DXVECTOR3 *pOut,
  CONST D3DXVECTOR3 *pV
) {
	float magnitude = sqrt(
		pV->x * pV->x +
		pV->y * pV->y +
		pV->z * pV->z
	);
	
	pOut->x = pV->x / magnitude;
	pOut->y = pV->y / magnitude;
	pOut->z = pV->z / magnitude;
	
	return pOut;
}

WINAPI D3DXVECTOR3 * D3DXVec3Subtract(
  D3DXVECTOR3 * pOut,
  CONST D3DXVECTOR3 * pV1,
  CONST D3DXVECTOR3 * pV2
) {
	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;
	
	return pOut;
}

WINAPI D3DXVECTOR4 *D3DXVec3Transform(
  D3DXVECTOR4 *pOut,
  CONST D3DXVECTOR3 *pV,
  CONST D3DXMATRIX *pM
) {
	pOut->x = pM->gl[ 0] * pV->x + pM->gl[ 1] * pV->y + pM->gl[ 2] * pV->z + pM->gl[ 3];
	pOut->y = pM->gl[ 4] * pV->x + pM->gl[ 5] * pV->y + pM->gl[ 6] * pV->z + pM->gl[ 7];
	pOut->z = pM->gl[ 8] * pV->x + pM->gl[ 9] * pV->y + pM->gl[10] * pV->z + pM->gl[11];
	pOut->w = pM->gl[12] * pV->x + pM->gl[13] * pV->y + pM->gl[14] * pV->z + pM->gl[15];
	
	return pOut;
}
