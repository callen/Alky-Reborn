/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX"

#define sq(a) ((a) * (a))

WINAPI inline D3DXMATRIX *D3DXMatrixRotationX(
	D3DXMATRIX *pOut,
	FLOAT Angle
) {
	FLOAT cos_a, sin_a;
	Angle = 0.0f;
	cos_a = cos(-Angle);
	sin_a = sin(-Angle);

	pOut->_11 = 1; pOut->_12 =  0;     pOut->_13 =  0;     pOut->_14 = 0;
	pOut->_21 = 0; pOut->_22 =  cos_a; pOut->_23 = -sin_a; pOut->_24 = 0;
	pOut->_31 = 0; pOut->_32 =  sin_a; pOut->_33 =  cos_a; pOut->_34 = 0;
	pOut->_41 = 0; pOut->_42 =  0;     pOut->_43 =  0;     pOut->_44 = 1;

	return pOut;
}

WINAPI inline D3DXMATRIX *D3DXMatrixLookAtLH(
    D3DXMATRIX *pOut,
    CONST D3DXVECTOR3 *pEye,
    CONST D3DXVECTOR3 *pAt,
    CONST D3DXVECTOR3 *pUp
) {
	D3DXVECTOR3 zaxis, xaxis, yaxis;
	
	// zaxis = normal(At - Eye)
	D3DXVec3Subtract(&zaxis, pAt, pEye);
	D3DXVec3Normalize(&zaxis, &zaxis);

	// xaxis = normal(cross(Up, zaxis))
	D3DXVec3Cross(&xaxis, pUp, &zaxis);
	D3DXVec3Normalize(&xaxis, &xaxis);

	// yaxis = cross(zaxis, xaxis)
	D3DXVec3Cross(&yaxis, &zaxis, &xaxis);

	pOut->_11 = xaxis.x;
	pOut->_12 = yaxis.x;
	pOut->_13 = zaxis.x;
	pOut->_14 = 0.0f;

	pOut->_21 = xaxis.y;
	pOut->_22 = yaxis.y;
	pOut->_23 = zaxis.y;
	pOut->_24 = 0.0f;

	pOut->_31 = xaxis.z;
	pOut->_32 = yaxis.z;
	pOut->_33 = zaxis.z;
	pOut->_34 = 0.0f;

	pOut->_41 = -D3DXVec3Dot(&xaxis, pEye);
	pOut->_42 = -D3DXVec3Dot(&yaxis, pEye);
	pOut->_43 = -D3DXVec3Dot(&zaxis, pEye);
	pOut->_44 = 1.0f;
	
	return pOut;
}

WINAPI inline D3DXMATRIX *D3DXMatrixPerspectiveFovLH(
	D3DXMATRIX *pOut,
	FLOAT fovY,
	FLOAT Aspect,
	FLOAT zn,
	FLOAT zf
) {
	FLOAT zf_min_zn = 1.0f / (zf - zn);
	FLOAT yScale = 1.0f / tanf(fovY / 2.0f);
	
	pOut->_11 = yScale / Aspect;
	pOut->_12 = 0.0f;
	pOut->_13 = 0.0f;
	pOut->_14 = 0.0f;
	
	pOut->_21 = 0.0f;
	pOut->_22 = yScale;
	pOut->_23 = 0.0f;
	pOut->_24 = 0.0f;
	
	pOut->_31 = 0.0f;
	pOut->_32 = 0.0f;
	pOut->_33 = zf * zf_min_zn;
	pOut->_34 = 1.0f;
	
	pOut->_41 = 0.0f;
	pOut->_42 = 0.0f;
	pOut->_43 = -zn * zf * zf_min_zn;
	pOut->_44 = 0.0f;
	
	return pOut;
}

WINAPI inline D3DXVECTOR3 *D3DXVec3Cross(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
) {
	pOut->x = pV1->y * pV2->z - pV1->z * pV2->y;
	pOut->y = pV1->z * pV2->x - pV1->x * pV2->z;
	pOut->z = pV1->x * pV2->y - pV1->y * pV2->x;
	
	return pOut;
}

WINAPI inline FLOAT D3DXVec3Dot(
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
) {
	return (pV1->x * pV2->x) + (pV1->y * pV2->y) + (pV1->z * pV2->z);
}

WINAPI inline D3DXVECTOR3 *D3DXVec3Subtract(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV1,
	CONST D3DXVECTOR3 *pV2
) {
	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;
	
	return pOut;
}

WINAPI inline D3DXVECTOR3 *D3DXVec3Normalize(
	D3DXVECTOR3 *pOut,
	CONST D3DXVECTOR3 *pV
) {
	FLOAT len = 1.0f / sqrt(sq(pV->x) + sq(pV->y) + sq(pV->z));
	
	pOut->x = pV->x * len;
	pOut->y = pV->y * len;
	pOut->z = pV->z * len;
	
	return pOut;
}
